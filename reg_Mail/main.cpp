#include "mainwindow.h"
#include <QtWidgets>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    MainWidget *wgt = new MainWidget;
    wgt->show();
    return app.exec();
}
