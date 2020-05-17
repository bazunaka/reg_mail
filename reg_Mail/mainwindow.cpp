#include "mainwindow.h"
#include "connectdatabase.h"
#include "loggingcategories.h"

QString path_dir, filename, dest_dir;
ConnectDatabase cntDb;
QScopedPointer<QFile> m_logFile;

void messageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg);

MainWidget::MainWidget(QWidget *parent) : QWidget(parent)
{
    tab                      = new QTabWidget(this);
    mnu_bar              = new QMenuBar(this);
    pmnu1                 = new QMenu("Работа с БД");
    pmnu2                 = new QMenu("это меню 2");
    verticalLayout      = new QVBoxLayout();
    horizontalLayout  = new QHBoxLayout();
    mainLayout          = new QVBoxLayout(this);
    st_bar                  = new QStatusBar(this);
    tbl1                      = new QTableView;
    tbl2                      = new QTableView;
    tbl3                      = new QTableView;
    submit                  = new QPushButton(this);
    revert                   = new QPushButton(this);

    m_logFile.reset(new QFile(path_dir + "logFile.txt"));
    m_logFile.data()->open(QFile::Append | QFile::Text);
    qInstallMessageHandler(messageHandler);

    add_record    = pmnu1->addAction("Добавить строку");
    delete_record = pmnu1->addAction("Удалить запись");
    pmnu1->addSeparator();
    add_file         = pmnu1->addAction("Добавить файл...");
    open_file       = pmnu1->addAction("Открыть папку с файлом...");

    mnu_bar->addMenu(pmnu1);
    mnu_bar->addMenu(pmnu2);

    submit->setText("Подтвердить");
    revert->setText("Отменить изменения");

    verticalLayout->addWidget(mnu_bar);
    verticalLayout->addWidget(tab);

    horizontalLayout->addWidget(submit);
    horizontalLayout->addSpacing(500);
    horizontalLayout->addWidget(revert);

    mainLayout->addLayout(verticalLayout);
    mainLayout->addLayout(horizontalLayout);
    mainLayout->addWidget(st_bar);

    setMinimumSize(900, 600);
    resize(900, 600);
    setWindowTitle("Учет электронных сообщений ЭП АСЗИ Цитрин");

    cntDb.settings = new QSettings("settings.ini", QSettings::IniFormat);

    cntDb.db_driver = cntDb.settings->value("db_connect/db_driver").toString();
    cntDb.db_driver_string = cntDb.settings->value("db_connect/db_drv_string").toString();
    cntDb.db_host = cntDb.settings->value("db_connect/db_host").toString();
    cntDb.db_name = cntDb.settings->value("db_connect/db_name").toString();
    cntDb.db_user = cntDb.settings->value("db_connect/db_user").toString();
    cntDb.db_password = cntDb.settings->value("db_connect/db_password").toString();

    path_dir = cntDb.settings->value("ftp_connect/ftp_host").toString();
    dest_dir = cntDb.settings->value("last_dir/last_dir").toString();

    QSqlDatabase db = cntDb.connectDB(cntDb.db_driver, cntDb.db_host, cntDb.db_driver_string,
                                      cntDb.db_name,  cntDb.db_user, cntDb.db_password);

    qDebug(logDebug()) << "String database connection" << db;
    qInfo(logInfo()) << "Start parametrs: path_dir = " << path_dir << "and dest_dir = " << dest_dir;

    if (db.open())
        {
            st_bar->showMessage("Подключение успешно!");
        } else {
            st_bar->showMessage("Ошибка подключения!"); //реализовать вывод самой ошибки
            qCritical(logCritical()) << db.lastError();
        }

    QStringList lst = db.tables();
    foreach (QString str, lst)
    {
        qInfo(logInfo()) << "Tables into database" << str;
    }

    srtbl1 = new QSqlRelationalTableModel(0, db);
    srtbl2 = new QSqlRelationalTableModel(0, db);
    sqtbl3 = new QSqlTableModel(0, db);

    srtbl1->setTable("send_mail");
    srtbl1->setRelation(2, QSqlRelation("directory", "id_directory", "directory_name"));
    srtbl1->setEditStrategy(QSqlTableModel::OnManualSubmit);
    srtbl1->select();
    srtbl1->setHeaderData(1, Qt::Horizontal, "Дата отправленного сообщения");
    srtbl1->setHeaderData(2, Qt::Horizontal, "Адрес получателя");
    srtbl1->setHeaderData(3, Qt::Horizontal, "Информация о сообщении");
    srtbl1->setHeaderData(4, Qt::Horizontal, "Файл отправленного сообщения");
    srtbl2->setTable("received_mail");
    srtbl2->setRelation(2, QSqlRelation("directory", "id_directory", "directory_name"));
    srtbl2->setEditStrategy(QSqlTableModel::OnManualSubmit);
    srtbl2->select();
    srtbl2->setHeaderData(1, Qt::Horizontal, "Дата полученного сообщения");
    srtbl2->setHeaderData(2, Qt::Horizontal, "Адрес отправителя");
    srtbl2->setHeaderData(3, Qt::Horizontal, "Информация о сообщении");
    srtbl2->setHeaderData(4, Qt::Horizontal, "Файл полученного сообщения");
    sqtbl3->setTable("directory");
    sqtbl3->select();
    sqtbl3->setEditStrategy(QSqlTableModel::OnManualSubmit);
    sqtbl3->setHeaderData(1, Qt::Horizontal, "Имя адресата");
    sqtbl3->setHeaderData(2, Qt::Horizontal, "Электронный адрес");

    tbl1->setModel(srtbl1);
    tbl1->setColumnHidden(0, true);
    tbl1->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tbl1->setItemDelegate(new QSqlRelationalDelegate(tbl1));
    tbl1->setSortingEnabled(true);
    tbl1->resizeRowsToContents();
    tbl2->setModel(srtbl2);
    tbl2->setColumnHidden(0, true);
    tbl2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tbl2->setItemDelegate(new QSqlRelationalDelegate(tbl2));
    tbl2->setSortingEnabled(true);
    tbl3->setModel(sqtbl3);
    tbl3->setColumnHidden(0, true);
    tbl3->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    tab->addTab(tbl1, "Отправленные сообщения");
    tab->addTab(tbl2, "Принятые сообщения");
    tab->addTab(tbl3, "Список адресов");

    connect(add_record, SIGNAL(triggered()), this, SLOT(insert_db()));
    connect(delete_record, SIGNAL(triggered()), this, SLOT(delete_db()));
    connect(submit, SIGNAL(clicked()), this, SLOT(submit_db()));
    connect(revert, SIGNAL(clicked()), this, SLOT(revert_db()));
    connect(add_file, SIGNAL(triggered()), this, SLOT(name_file()));
}

void MainWidget::insert_db()
{
    int index_tab = tab->currentIndex();
    if (index_tab == 0)
    {   
        tbl1->scrollToBottom();
        qInfo(logInfo()) << "Insert in 1 table" << index_tab << srtbl1->insertRow(srtbl1->rowCount());
    } else if (index_tab == 1)
    {
        tbl2->scrollToBottom();
        qInfo(logInfo()) << "Insert in 2 table" << index_tab << srtbl2->insertRow(srtbl2->rowCount());
    } else if (index_tab == 2)
    {
        tbl3->scrollToBottom();
        qInfo(logInfo()) << "Insert in 3 table" << index_tab << sqtbl3->insertRow(sqtbl3->rowCount());
    }
}

void MainWidget::delete_db()
{
    int index_tab = tab->currentIndex();
    if(index_tab == 0)
    {
        int selectedRow = tbl1->currentIndex().row();
        if (selectedRow >= 0)
        {
           qInfo(logInfo()) << "Deleting row in 1 table" << srtbl1->removeRows(selectedRow, 1);
        }
    } else if(index_tab == 1)
    {
        int selectedRow = tbl2->currentIndex().row();
        if (selectedRow >= 0)
        {
           qInfo(logInfo()) << "Deleting row in 2 table" << srtbl2->removeRows(selectedRow, 1);
        }
    } else if(index_tab == 2)
    {
        int selectedRow = tbl3->currentIndex().row();
        if (selectedRow >= 0)
        {
           qInfo(logInfo()) << "Deleting row in 3 table" << sqtbl3->removeRows(selectedRow, 1);
        }
    } else
    {
        qCritical(logCritical()) << "Error deleting in " << index_tab << " tab";
    }
}

void MainWidget::submit_db()
{
    QFile file(filename);
    QFileInfo inf(file);
    QFile::copy(filename, path_dir + "/" + dest_dir + "/" + inf.fileName());

    int index_tab = tab->currentIndex();
    if (index_tab == 0)
    {        
        srtbl1->submitAll();
        create_folder(path_dir, index_tab);              
        st_bar->showMessage("Успешно!");
        qInfo(logInfo()) << "Source file " << filename << "Destination file " << path_dir + "/" + dest_dir;
        qInfo(logInfo()) << "submit for " << index_tab << " tab";
    } else if (index_tab == 1)
    {
        srtbl2->submitAll();
        create_folder(path_dir, index_tab);
        st_bar->showMessage("Успешно!");
        qInfo(logInfo()) << "Source file " << filename << "Destination file " << path_dir + "/" + dest_dir;
        qInfo(logInfo()) << "submit for " << index_tab << " tab";
    } else if(index_tab == 2)
    {
        sqtbl3->submitAll();
        st_bar->showMessage("Успешно!");
        qInfo(logInfo()) << "submit for " << index_tab << " tab";
    }
}

void MainWidget::revert_db()
{
    int index_tab = tab->currentIndex();
    if (index_tab == 0)
    {
        srtbl1->revertAll();
    } else if (index_tab == 1)
    {
        srtbl2->revertAll();
    }
}

void MainWidget::create_folder(QString path_dir, int index_tab)
{
    QModelIndex index;
    QDir dir(path_dir);
    if (index_tab == 0)
    {
        index = tbl1->model()->index(0, 1);
    } else if (index_tab == 1)
    {
        index = tbl2->model()->index(0, 1);
    }
    if (!dir.exists(index.data().toString()))
    {
        dir.mkdir(index.data().toString());
        cntDb.settings->setValue("last_dir/last_dir", index.data().toString());
        dest_dir =  cntDb.settings->value("last_dir/last_dir").toString();
        qInfo(logInfo()) << "Create directory " << index.data().toString() << " to " << path_dir;
    }
}

QString MainWidget::name_file()
{
    filename = QFileDialog::getOpenFileName();
    QFile file(filename);
    qInfo(logInfo()) << filename;
    QFileInfo inf(file);
    QModelIndex index = srtbl1->index(srtbl1->rowCount() - 1, 4);
    qInfo(logInfo()) << inf.isFile() << inf.fileName();
    tbl1->model()->setData(index, inf.fileName());
    return filename;
}

void messageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    QTextStream out(m_logFile.data());
    out << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss ");

    switch(type)
    {
    case QtInfoMsg:            out << "INF"; break;
    case QtDebugMsg:        out << "DBG"; break;
    case QtWarningMsg:     out << "WRN"; break;
    case QtCriticalMsg:       out << "CRT"; break;
    case QtFatalMsg:          out << "FTL"; break;
    }

    out << context.category << ": " << msg << endl;
    out.flush();
}

MainWidget::~MainWidget()
{
}

