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

    void add_action_about();
    void show_about_Qt();

    void on_action_triggered();  

    void on_action_2_triggered();

    void on_action_3_triggered();

    void on_action_4_triggered();

    void createContextMenu();

private:
    Ui::MainWindow *ui;

    QTableView *tbv;
    QStatusBar *stb;
    QMenuBar *mnb;
    QMenu *mnu_db;
    QMenu *mnu_set;
    QMenu *mnu_ab;

    QAction *aboutAction;

    QSqlDatabase db;
    QSqlTableModel* model;
    QMenu* m_pmnu;
};
#endif // MAINWINDOW_H
