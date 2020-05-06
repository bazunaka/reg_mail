#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQueryModel>
#include <QSqlTableModel>

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = 0);
    ~MainWidget();

private:
    QTabWidget      *tab;
    QTableView       *tbl1;
    QTableView       *tbl2;
    QMenuBar         *mnu_bar;
    QMenu              *pmnu1;
    QMenu              *pmnu2;
    QVBoxLayout   *verticalLayout;
    QSettings          *settings;
    QStatusBar        *st_bar;
    QSqlDatabase      db;  
    QSqlTableModel  *sqtbl1;
    QSqlTableModel  *sqtbl2;
    QSqlQueryModel model1;
    QSqlQueryModel model2;

    QString *db_driver;
    QString *db_drv_string;
    QString *db_host;
    QString *db_name;
    QString *db_user;
    QString *db_password;
};
#endif // MAINWINDOW_H
