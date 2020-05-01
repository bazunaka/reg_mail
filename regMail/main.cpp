#include "mainwindow.h"

#include <QApplication>
#include <QMenuBar>
#include <QStatusBar>

static bool createConnection() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setHostName("localhost");
    db.setDatabaseName("baz_mail");
    db.setUserName("root");
    db.setPassword("root");
    db.open();
    return true;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    createConnection();
    return a.exec();
}
