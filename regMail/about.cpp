#include "about.h"
#include "ui_about.h"

about::about(QWidget *parent) :
    QMainWindow(parent),
    uiabout(new Ui::about)
{
    uiabout->setupUi(this);
}

about::~about()
{
    delete uiabout;
}
