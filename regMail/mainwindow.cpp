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
    add_action_about();
    add_table_view();

    database_connection();

}

MainWindow::~MainWindow()
{
    delete ui;
}

//Создание основного меню
void MainWindow::add_menu()
{
    mnb = new QMenuBar(this);

    mnu_db  = new QMenu(tr("База данных"));
    mnu_dir = new QMenu(tr("Справочник"));
    mnu_set = new QMenu(tr("Настройки"));
    mnu_ab  = new QMenu(tr("Информация"));

    mnb->addMenu(mnu_db);
    mnb->addMenu(mnu_dir);
    mnb->addMenu(mnu_set);
    mnb->addMenu(mnu_ab);
}

//Подключение к БД
void MainWindow::database_connection()
{
    QSettings *settings   = new QSettings("settings.ini", QSettings::IniFormat);
    QString db_driver     = settings->value("db_connect/db_driver").toString();
    QString db_drv_string = settings->value("db_connect/db_drv_string").toString();
    QString db_host       = settings->value("db_connect/db_host").toString();
    QString db_name       = settings->value("db_connect/db_name").toString();
    QString db_user       = settings->value("db_connect/db_user").toString();
    QString db_password   = settings->value("db_connect/db_password").toString();
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

/*
 * Отображение таблиц из БД
 * */

void MainWindow::show_directory()
{
    QSqlQuery query = QSqlQuery(db);
    query.exec("select * from directory_view");
    model = new QSqlTableModel(this, db);
    model->setTable("directory_view");
    model->select();
    tbv->setModel(model);
    column_width(1);
}

void MainWindow::show_send_mail()
{
    QSqlQuery query = QSqlQuery(db);
    query.exec("select * from send_view");
    model = new QSqlTableModel(this, db);
    model->setTable("send_view");
    model->select();
    tbv->setModel(model);
    column_width(3);
}

void MainWindow::show_received_mail()
{
    QSqlQuery query = QSqlQuery(db);
    query.exec("select * from received_view");
    model = new QSqlTableModel(this, db);
    model->setTable("received_view");
    model->select();
    tbv->setModel(model);
    column_width(3);
}

//Вызов методов просмотра таблиц
void MainWindow::add_action_database()
{
    QAction* send_mail = mnu_db->addAction(tr("Отправленные сообщения"));
    connect(send_mail, SIGNAL(triggered()), this, SLOT(show_send_mail()));
    QAction* received_mail = mnu_db->addAction(tr("Принятые сообщения"));
    connect(received_mail, SIGNAL(triggered()), this, SLOT(show_received_mail()));
    QAction* directory = mnu_dir->addAction(tr("Справочник адресов"));
    connect(directory, SIGNAL(triggered()), this, SLOT(show_directory()));
}

//Создание контекстного меню
void MainWindow::createContextMenu(QStringList name_menu)
{
    add_record = new QAction(name_menu[0]);
    edit_record = new QAction(name_menu[1]);
    rm_record   = new QAction(name_menu[2]);
}

//Создание таблицы для отображения данных из БД
void MainWindow::add_table_view()
{
    tbv = new QTableView(this);
    tbv->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tbv->setContextMenuPolicy(Qt::ActionsContextMenu);
    //createContextMenu();
    ui->verticalLayout->addWidget(mnb);
    ui->verticalLayout->addWidget(tbv);

    add_record  = new QAction;
    edit_record = new QAction;

    add_record ->setText("Добавить запись");
    edit_record->setText("Редактировать запись");

    add_record ->setEnabled(false);
    edit_record->setEnabled(false);

    tbv->addAction(add_record);
    tbv->addAction(edit_record);
}

//Вызов методов отображения окон меню "О программе..."
void MainWindow::add_action_about()
{
    QAction* ab_app_action = mnu_ab->addAction(tr("О программе..."));
    connect(ab_app_action, SIGNAL(triggered()), this, SLOT(show_about()));
    QAction* ab_qt_action = mnu_ab->addAction(tr("О Qt"));
    connect(ab_qt_action, SIGNAL(triggered()), this, SLOT(show_about_Qt()));
}

/*
 * Отображение окон из меню "О программе..."
 * */
void MainWindow::show_about()
{
    QLabel *lbl = new QLabel;
    lbl->setText("<h3> Учет электронных сообщений АСЗИ Цитрин. </h3><br> <h4> Версия 0.0.1 </h4>");
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

//Указание размеров колонок в таблицах
void MainWindow::column_width(int column_count)
{
    for (int var = 0; var <= column_count; var++) {
        tbv->horizontalHeader()->setSectionResizeMode(var, QHeaderView::Stretch);
    }
}

void MainWindow::show_add_sendmail()
{
    createEdit_db_Widget("Новая запись");
}

void MainWindow::show_add_receivedmail()
{
    createEdit_db_Widget("Редактировать запись");
}

void MainWindow::show_add_directory()
{
    createEdit_db_Widget("Удалить запись");
}

void MainWindow::createEdit_db_Widget(QString title_window)
{
    QWidget *edit_db = new QWidget();
    edit_db->setWindowTitle(title_window);
    edit_db->setWindowModality(Qt::ApplicationModal);
    edit_db->show();
}
