#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "about.h"
#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    mnb = new QMenuBar(this);

    mnu_db = new QMenu(tr("База данных"));
    mnu_set = new QMenu(tr("Настройки"));
    mnu_ab = new QMenu(tr("Информация"));

    mnb->addMenu(mnu_db);
    mnb->addMenu(mnu_set);
    mnb->addMenu(mnu_ab);

    add_action_database();
    add_action_about();

    tbv = new QTableView(this);

    ui->verticalLayout->addWidget(mnb);
    ui->verticalLayout->addWidget(tbv);


    db = QSqlDatabase::addDatabase("QODBC");
    db.setHostName("localhost");
    db.setDatabaseName("DRIVER={MySQL ODBC 8.0 Unicode Driver};DATABASE=baz_mail;");
    db.setUserName("root");
    db.setPassword("root");
    if (db.open())
    {
        ui->statusbar->showMessage("Подключение успешно!");
        return;
    } else {
        ui->statusbar->showMessage("Ошибка подключения!"); //реализовать вывод самой ошибки
        qDebug() << db.lastError();
    }   

    createContextMenu();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_action_triggered()
{
    about* ab = new about();
    ab->show();
}

void MainWindow::on_action_2_triggered()
{
    /*QSqlQuery query = QSqlQuery(db);
    query.exec("select * from directory_view");
    model = new QSqlTableModel(this, db);
    model->setTable("directory_view");
    model->select();
    ui->tableView->setModel(model);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);*/
}

void MainWindow::on_action_3_triggered()
{
    /*QSqlQuery query = QSqlQuery(db);
    query.exec("select * from send_view");
    model = new QSqlTableModel(this, db);
    model->setTable("send_view");
    model->select();
    ui->tableView->setModel(model);*/
}

void MainWindow::on_action_4_triggered()
{
    /*QSqlQuery query = QSqlQuery(db);
    query.exec("select * from received_view");
    model = new QSqlTableModel(this, db);
    model->setTable("received_view");
    model->select();
    ui->tableView->setModel(model);*/
}

void MainWindow::createContextMenu()
{

}

void MainWindow::add_action_database()
{
    mnu_db->addAction(tr("Отправленные сообщения"));
    mnu_db->addAction(tr("Принятые сообщения"));
}

void MainWindow::add_action_about()
{
    QAction* ab_app_action = mnu_ab->addAction(tr("О программе..."));
    connect(ab_app_action, SIGNAL(triggered()), this, SLOT(show_about()));
    QAction* ab_qt_action = mnu_ab->addAction(tr("О Qt"));
    connect(ab_qt_action, SIGNAL(triggered()), this, SLOT(on_action_Qt_triggered()));
}

void MainWindow::show_about()
{
    QLabel lbl_about("qwerty!");
    lbl_about.show();
}

void MainWindow::show_about_Qt()
{
    QMessageBox::aboutQt(this);
}
