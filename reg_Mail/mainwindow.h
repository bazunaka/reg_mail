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
    QTabWidget       *tab;
    QTableView        *tbl1;
    QTableView        *tbl2;
    QTableView        *tbl3;
    QMenuBar          *mnu_bar;
    QMenu               *pmnu1;
    QMenu               *pmnu2;
    QHBoxLayout     *horizontalLayout;
    QVBoxLayout     *verticalLayout;
    QVBoxLayout     *mainLayout;
    QSettings             *settings;
    QStatusBar          *st_bar;
    QSqlDatabase      db;  
    QSqlTableModel  *sqtbl1;
    QSqlTableModel  *sqtbl2;
    QSqlTableModel  *sqtbl3;
    QSqlQueryModel model1;
    QSqlQueryModel model2;
    QAction               *add_record;
    QPushButton        *submit;
    QPushButton        *revert;

    QString *db_driver;
    QString *db_drv_string;
    QString *db_host;
    QString *db_name;
    QString *db_user;
    QString *db_password;

private slots:
    void qwe();
    void select_db();

};
#endif // MAINWINDOW_H
