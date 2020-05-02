#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QTranslator trns;
    trns.load("regMail_en_US", ".");
    a.installTranslator(&trns);
    w.show();
    return a.exec();
}
