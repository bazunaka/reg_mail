#include "mainwindow.h"

MainWidget::MainWidget(QWidget *parent) : QWidget(parent)
{
    tab             = new QTabWidget(this);
    mnu_bar         = new QMenuBar(this);
    pmnu1           = new QMenu("это меню 1");
    pmnu2           = new QMenu("это меню 2");
    verticalLayout  = new QVBoxLayout(this);

    mnu_bar->addMenu(pmnu1);
    mnu_bar->addMenu(pmnu2);

    tab->addTab(new QTableWidget, "название таба1");
    tab->addTab(new QLabel("тут виджет2"), "название таба2");

    verticalLayout->addWidget(mnu_bar);
    verticalLayout->addWidget(tab);

    setMinimumSize(650, 400);
    resize(650, 400);
    setWindowTitle("Учет электронных сообщений ЭП АСЗИ Цитрин");

    add_tabs();
    //QString db_driver = settings->value("db_connect/db_driver").toString();
    //qDebug() << db_driver;
}

void MainWidget::add_tabs()
{
    settings = new QSettings("settings.ini", QSettings::IniFormat);
    settings->setValue("asd/asd", "qwe");
}

MainWidget::~MainWidget()
{
}

