#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQueryModel>
#include <QtSql/QSqlQuery>
#include <QSqlTableModel>
#include <QtWidgets>
#include <QSettings>
#include <QtGui>
#include <QMenu>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void show_about();

    void add_action_database();

    void add_menu();
    void add_action_about();
    void add_action_directory();
    void show_about_Qt();
    void add_table_view();

    void database_connection();
    void show_directory();
    void show_send_mail();
    void show_received_mail();

    void createContextMenu();

private:
    Ui::MainWindow *ui;

    QTableView *tbv;
    QStatusBar *stb;
    QMenuBar *mnb;
    QMenu *mnu_db;
    QMenu *mnu_dir;
    QMenu *mnu_set;
    QMenu *mnu_ab;

    QAction *aboutAction;

    QSqlDatabase db;
    QSqlTableModel* model;
    QMenu* m_pmnu;
};
#endif // MAINWINDOW_H
