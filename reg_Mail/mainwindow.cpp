#include "mainwindow.h"

MainWidget::MainWidget(QWidget *parent) : QWidget(parent)
{
    tab                      = new QTabWidget(this);
    mnu_bar              = new QMenuBar(this);
    pmnu1                 = new QMenu("это меню 1");
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

    add_record    = pmnu1->addAction("Добавить строку");
    delete_record = pmnu1->addAction("Удалить запись");

    mnu_bar->addMenu(pmnu1);
    mnu_bar->addMenu(pmnu2);

    submit->setText("Подтвердить");
    revert->setText("revert");

    verticalLayout->addWidget(mnu_bar);
    verticalLayout->addWidget(tab);

    horizontalLayout->addWidget(submit);
    horizontalLayout->addSpacing(500);
    horizontalLayout->addWidget(revert);

    mainLayout->addLayout(verticalLayout);
    mainLayout->addLayout(horizontalLayout);
    mainLayout->addWidget(st_bar);

    setMinimumSize(850, 450);
    resize(850, 450);
    setWindowTitle("Учет электронных сообщений ЭП АСЗИ Цитрин");

    settings = new QSettings("settings.ini", QSettings::IniFormat);

    QString db_driver        = settings->value("db_connect/db_driver").toString();
    QString db_drv_string  = settings->value("db_connect/db_drv_string").toString();
    QString db_host           = settings->value("db_connect/db_host").toString();
    QString db_name         = settings->value("db_connect/db_name").toString();
    QString db_user           = settings->value("db_connect/db_user").toString();
    QString db_password   = settings->value("db_connect/db_password").toString();

    db = QSqlDatabase::addDatabase(db_driver);
    db.setHostName(db_host);
    db.setDatabaseName("DRIVER={" + db_drv_string + "};DATABASE=" + db_name + ";");
    db.setUserName(db_user);
    db.setPassword(db_password);

    if (db.open())
        {
            st_bar->showMessage("Подключение успешно!");
        } else {
            st_bar->showMessage("Ошибка подключения!"); //реализовать вывод самой ошибки
            qDebug() << db.lastError();
        }

    QStringList lst = db.tables();
    foreach (QString str, lst)
    {
        qDebug() << str;
    }

    sqtbl1 = new QSqlTableModel(0, db);
    sqtbl2 = new QSqlTableModel(0, db);
    sqtbl3 = new QSqlTableModel(0, db);

    sqtbl1->setTable("send_mail");
    sqtbl1->select();
    sqtbl1->setEditStrategy(QSqlTableModel::OnManualSubmit);
    sqtbl1->setHeaderData(1, Qt::Horizontal, "Дата отправленного сообщения");
    sqtbl1->setHeaderData(2, Qt::Horizontal, "Адрес получателя");
    sqtbl1->setHeaderData(3, Qt::Horizontal, "Информация о сообщении");
    sqtbl1->setHeaderData(4, Qt::Horizontal, "Файл отправленного сообщения");
    sqtbl2->setTable("received_mail");
    sqtbl2->select();
    sqtbl2->setEditStrategy(QSqlTableModel::OnManualSubmit);
    sqtbl2->setHeaderData(1, Qt::Horizontal, "Дата полученного сообщения");
    sqtbl2->setHeaderData(2, Qt::Horizontal, "Адрес отправителя");
    sqtbl2->setHeaderData(3, Qt::Horizontal, "Информация о сообщении");
    sqtbl2->setHeaderData(4, Qt::Horizontal, "Файл полученного сообщения");
    sqtbl3->setTable("directory");
    sqtbl3->select();
    sqtbl3->setEditStrategy(QSqlTableModel::OnManualSubmit);
    sqtbl3->setHeaderData(1, Qt::Horizontal, "Имя адресата");
    sqtbl3->setHeaderData(2, Qt::Horizontal, "Электронный адрес");


    tbl1->setModel(sqtbl1);
    tbl1->setColumnHidden(0, true);
    tbl1->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tbl2->setModel(sqtbl2);
    tbl2->setColumnHidden(0, true);
    tbl2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tbl3->setModel(sqtbl3);
    tbl3->setColumnHidden(0, true);
    tbl3->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    tab->addTab(tbl1, "Отправленные сообщения");
    tab->addTab(tbl2, "Принятые сообщения");
    tab->addTab(tbl3, "Список адресов");

    connect(add_record, SIGNAL(triggered()), this, SLOT(insert_db()));
    connect(delete_record, SIGNAL(triggered()), this, SLOT(delete_db()));
    connect(submit, SIGNAL(clicked()), sqtbl1, SLOT(submitAll()));
}

void MainWidget::insert_db()
{
    qDebug() << "insert in 1 table" << sqtbl1->insertRow(sqtbl1->rowCount());
    st_bar->showMessage("Строка добавлена!");
}

void MainWidget::delete_db()
{
    int selectedRow = tbl1->currentIndex().row();
    if (selectedRow >= 0)
    {
        qDebug() << "deleting row in 1 table" << sqtbl1->removeRows(selectedRow, 1);
    }
    st_bar->showMessage("Строка удалена!");
}

MainWidget::~MainWidget()
{
}

