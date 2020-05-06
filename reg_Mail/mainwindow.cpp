#include "mainwindow.h"

MainWidget::MainWidget(QWidget *parent) : QWidget(parent)
{
    tab                   = new QTabWidget(this);
    mnu_bar           = new QMenuBar(this);
    pmnu1              = new QMenu("это меню 1");
    pmnu2              = new QMenu("это меню 2");
    verticalLayout   = new QVBoxLayout(this);
    st_bar              = new QStatusBar(this);
    tbl1                   = new QTableView;
    tbl2                   = new QTableView;

    mnu_bar->addMenu(pmnu1);
    mnu_bar->addMenu(pmnu2);

    verticalLayout->addWidget(mnu_bar);
    verticalLayout->addWidget(tab);
    verticalLayout->addWidget(st_bar);

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
    qDebug() << db_driver;

    sqtbl1 = new QSqlTableModel(0, db);
    sqtbl2 = new QSqlTableModel(0, db);

    sqtbl1->setTable("send_mail");
    sqtbl1->select();
    sqtbl1->removeColumn(0);
    sqtbl2->setTable("received_mail");
    sqtbl2->select();
    sqtbl2->removeColumn(0);


    tbl1->setModel(sqtbl1);
    tbl1->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tbl2->setModel(sqtbl2);
    tbl2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    tab->addTab(tbl1, "название таба1");
    tab->addTab(tbl2, "название таба2");

    QModelIndexList index = tbl1->selectionModel()->selectedIndexes();
    qDebug() << sqtbl1->select() << index;
}

MainWidget::~MainWidget()
{
}

