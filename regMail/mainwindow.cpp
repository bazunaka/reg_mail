#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QCoreApplication::setOrganizationName("company");
    QCoreApplication::setApplicationName("myprogram");

    add_menu();

    add_action_database();
    add_action_directory();
    add_action_about();
    add_table_view();

    database_connection();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::add_menu()
{
    mnb = new QMenuBar(this);

    mnu_db = new QMenu(tr("База данных"));
    mnu_dir = new QMenu(tr("Справочник"));
    mnu_set = new QMenu(tr("Настройки"));
    mnu_ab = new QMenu(tr("Информация"));

    mnb->addMenu(mnu_db);
    mnb->addMenu(mnu_dir);
    mnb->addMenu(mnu_set);
    mnb->addMenu(mnu_ab);
}

void MainWindow::database_connection()
{
    QSettings *settings = new QSettings("settings.ini", QSettings::IniFormat);
    QString db_driver = settings->value("db_connect/db_driver").toString();
    QString db_drv_string = settings->value("db_connect/db_drv_string").toString();
    QString db_host = settings->value("db_connect/db_host").toString();
    QString db_name = settings->value("db_connect/db_name").toString();
    QString db_user = settings->value("db_connect/db_user").toString();
    QString db_password = settings->value("db_connect/db_password").toString();
    //qDebug() << db_driver << db_drv_string << db_host << db_name << db_user << db_password;

    db = QSqlDatabase::addDatabase(db_driver);
    db.setHostName(db_host);
    db.setDatabaseName("DRIVER={" + db_drv_string + "};DATABASE=" + db_name + ";");
    db.setUserName(db_user);
    db.setPassword(db_password);
    if (db.open())
    {
        ui->statusbar->showMessage("Подключение успешно!");
    } else {
        ui->statusbar->showMessage("Ошибка подключения!"); //реализовать вывод самой ошибки
        qDebug() << db.lastError();
    }
}

void MainWindow::show_directory()
{
    QSqlQuery query = QSqlQuery(db);
    query.exec("select * from directory_view");
    model = new QSqlTableModel(this, db);
    model->setTable("directory_view");
    model->select();
    tbv->setModel(model);
}

void MainWindow::show_send_mail()
{
    QSqlQuery query = QSqlQuery(db);
    query.exec("select * from send_view");
    model = new QSqlTableModel(this, db);
    model->setTable("send_view");
    model->select();
    tbv->setModel(model);
}

void MainWindow::show_received_mail()
{
    QSqlQuery query = QSqlQuery(db);
    query.exec("select * from received_view");
    model = new QSqlTableModel(this, db);
    model->setTable("received_view");
    model->select();
    tbv->setModel(model);
}

void MainWindow::add_action_database()
{
    QAction* send_mail = mnu_db->addAction(tr("Отправленные сообщения"));
    connect(send_mail, SIGNAL(triggered()), this, SLOT(show_send_mail()));
    QAction* received_mail = mnu_db->addAction(tr("Принятые сообщения"));
    connect(received_mail, SIGNAL(triggered()), this, SLOT(show_received_mail()));
}

void MainWindow::add_action_directory()
{
    QAction* directory = mnu_dir->addAction(tr("Справочник адресов"));
    connect(directory, SIGNAL(triggered()), this, SLOT(show_directory()));
}

void MainWindow::createContextMenu()
{
    tbv->addAction(new QAction(QObject::tr("Добавить запись")));
    tbv->addAction(new QAction(QObject::tr("Редактировать запись")));
    tbv->addAction(new QAction(QObject::tr("Удалить запись")));
    tbv->setContextMenuPolicy(Qt::ActionsContextMenu);
}

void MainWindow::add_table_view()
{
    tbv = new QTableView(this);
    tbv->setEditTriggers(QAbstractItemView::NoEditTriggers);
    createContextMenu();
    ui->verticalLayout->addWidget(mnb);
    ui->verticalLayout->addWidget(tbv);
    //connect(tbv, SIGNAL(createContextMenu()), this, SLOT(createContextMenu()));
}

void MainWindow::add_action_about()
{
    QAction* ab_app_action = mnu_ab->addAction(tr("О программе..."));
    connect(ab_app_action, SIGNAL(triggered()), this, SLOT(show_about()));
    QAction* ab_qt_action = mnu_ab->addAction(tr("О Qt"));
    connect(ab_qt_action, SIGNAL(triggered()), this, SLOT(show_about_Qt()));
}

void MainWindow::show_about()
{
    QLabel *lbl = new QLabel;
    lbl->setText("<h3> Учет электронных сообщений АСЗИ Цитрин. </h3>");
    lbl->resize(350, 200);
    lbl->setMaximumSize(350, 200);
    lbl->setMinimumSize(350, 200);
    lbl->setAlignment(Qt::AlignTop);
    lbl->setContentsMargins(10,10,10,10);
    lbl->setWindowModality(Qt::ApplicationModal);
    lbl->setWindowFlags(Qt::Dialog);
    lbl->setWindowTitle("Информация о программе");
    lbl->show();
}

void MainWindow::show_about_Qt()
{
    QMessageBox::aboutQt(this);
}
