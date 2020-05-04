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
    void show_about_Qt();
    void add_table_view();

    void database_connection();
    void show_directory();
    void show_send_mail();
    void show_received_mail();

    void show_add_sendmail();
    void show_add_receivedmail();
    void show_add_directory();

    void deleteContextMenu();

    //void createContextMenu();
    void createContextMenu(QStringList name_menu);
    void createEdit_db_Widget(QString title_window);

    void column_width(int column_count);

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
    QAction *add_record;
    QAction *edit_record;
    QAction *rm_record;

    QSqlDatabase db;
    QSqlTableModel* model;
    QMenu* m_pmnu;

    QWidget *edit_db;
};
#endif // MAINWINDOW_H
