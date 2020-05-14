#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QSqlRelationalTableModel>
#include <QSqlRelationalDelegate>


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
    QSqlRelationalTableModel *srtbl1;
    QSqlRelationalTableModel *srtbl2;
    QSqlTableModel  *sqtbl3;
    QAction               *add_record;
    QAction               *delete_record;
    QAction               *add_file;
    QPushButton        *submit;
    QPushButton        *revert;

    /*QString *db_driver;
    QString *db_drv_string;
    QString *db_host;
    QString *db_name;
    QString *db_user;
    QString *db_password;*/

private slots:
    void insert_db();
    void delete_db();

    void submit_db();
    void revert_db();

    void create_folder(QString, int);

    QString name_file();
};

#endif // MAINWINDOW_H
