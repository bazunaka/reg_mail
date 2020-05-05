#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include <QDebug>

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = 0);
    ~MainWidget();

private:
    QTabWidget  *tab;
    QMenuBar    *mnu_bar;
    QMenu       *pmnu1;
    QMenu       *pmnu2;
    QVBoxLayout *verticalLayout;
    QSettings   *settings;

    void add_tabs();
};
#endif // MAINWINDOW_H
