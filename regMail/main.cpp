#include "mainwindow.h"

#include <QApplication>
#include <QtSql/QSqlDatabase>

static bool createConnection() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
