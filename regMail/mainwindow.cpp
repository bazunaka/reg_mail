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

void MainWindow::on_action_Qt_triggered()
{
    QMessageBox::aboutQt(this);
}

void MainWindow::on_action_2_triggered()
{
    QSqlQuery query = QSqlQuery(db);
    query.exec("select * from directory");
    model = new QSqlTableModel(this, db);
    model->setTable("directory");
    model->select();
    ui->tableView->setModel(model);
}
