#include <QtWidgets>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    QWidget     wgt;

    QTabWidget  *tab             = new QTabWidget(&wgt);
    QMenuBar    *mnu_bar         = new QMenuBar(&wgt);
    QMenu       *pmnu1           = new QMenu("это меню 1");
    QMenu       *pmnu2           = new QMenu("это меню 2");
    QVBoxLayout *verticalLayout  = new QVBoxLayout;

    mnu_bar->addMenu(pmnu1);
    mnu_bar->addMenu(pmnu2);

    tab->addTab(new QLabel("тут виджет1"), "название таба1");
    tab->addTab(new QLabel("тут виджет2"), "название таба2");

    wgt.setMinimumSize(650, 400);
    wgt.resize(650, 400);
    wgt.setWindowTitle("Учет электронных сообщений ЭП АСЗИ Цитрин");

    verticalLayout->addWidget(mnu_bar);
    verticalLayout->addWidget(tab);

    wgt.setLayout(verticalLayout);
    wgt.show();
    return app.exec();
}
