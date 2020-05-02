/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action;
    QAction *action_Qt;
    QAction *action_2;
    QAction *action_3;
    QAction *action_4;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        MainWindow->setMinimumSize(QSize(800, 600));
        QFont font;
        font.setFamily(QString::fromUtf8("Times New Roman"));
        font.setPointSize(12);
        MainWindow->setFont(font);
        action = new QAction(MainWindow);
        action->setObjectName(QString::fromUtf8("action"));
        action_Qt = new QAction(MainWindow);
        action_Qt->setObjectName(QString::fromUtf8("action_Qt"));
        action_2 = new QAction(MainWindow);
        action_2->setObjectName(QString::fromUtf8("action_2"));
        action_3 = new QAction(MainWindow);
        action_3->setObjectName(QString::fromUtf8("action_3"));
        action_4 = new QAction(MainWindow);
        action_4->setObjectName(QString::fromUtf8("action_4"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetMaximumSize);

        verticalLayout->addLayout(verticalLayout_2);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217 \320\255\320\237 \320\246\320\270\321\202\321\200\320\270\320\275", nullptr));
        action->setText(QCoreApplication::translate("MainWindow", "\320\230\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217 \320\276 \320\277\321\200\320\276\320\264\321\203\320\272\321\202\320\265", nullptr));
        action_Qt->setText(QCoreApplication::translate("MainWindow", "\320\230\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217 \320\276 Qt", nullptr));
        action_2->setText(QCoreApplication::translate("MainWindow", "\320\220\320\264\321\200\320\265\321\201\320\260", nullptr));
        action_3->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\275\321\213\320\265 \321\201\320\276\320\276\320\261\321\211\320\265\320\275\320\270\321\217", nullptr));
        action_4->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\270\320\275\321\217\321\202\321\213\320\265 \321\201\320\276\320\276\320\261\321\211\320\265\320\275\320\270\321\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
