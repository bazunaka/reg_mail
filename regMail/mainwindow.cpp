#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "about.h"
#include <QMessageBox>

static bool createConnection() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setHostName("localhost");
    db.setDatabaseName("baz_mail");
    db.setUserName("root");
    db.setPassword("root");
    db.open();
    return true;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    if (createConnection())
    {
        ui->statusbar->showMessage("Подключение успешно!");
    } else {
        ui->statusbar->showMessage("Ошибка подключения!"); //реализовать вывод самой ошибки
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
