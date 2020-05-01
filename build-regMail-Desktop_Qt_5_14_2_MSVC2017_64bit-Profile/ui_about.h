/********************************************************************************
** Form generated from reading UI file 'about.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUT_H
#define UI_ABOUT_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_about
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton;

    void setupUi(QMainWindow *about)
    {
        if (about->objectName().isEmpty())
            about->setObjectName(QString::fromUtf8("about"));
        about->setWindowModality(Qt::ApplicationModal);
        about->resize(450, 250);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(about->sizePolicy().hasHeightForWidth());
        about->setSizePolicy(sizePolicy);
        about->setMinimumSize(QSize(450, 250));
        about->setMaximumSize(QSize(450, 250));
        QFont font;
        font.setFamily(QString::fromUtf8("Times New Roman"));
        font.setPointSize(10);
        about->setFont(font);
        centralwidget = new QWidget(about);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(450, 16777215));
        label->setLayoutDirection(Qt::LeftToRight);
        label->setLocale(QLocale(QLocale::Russian, QLocale::Russia));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);


        verticalLayout->addWidget(widget);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton, 0, Qt::AlignHCenter);

        about->setCentralWidget(centralwidget);

        retranslateUi(about);
        QObject::connect(pushButton, SIGNAL(clicked()), about, SLOT(close()));

        QMetaObject::connectSlotsByName(about);
    } // setupUi

    void retranslateUi(QMainWindow *about)
    {
        about->setWindowTitle(QCoreApplication::translate("about", "\320\236 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\265...", nullptr));
        label->setText(QCoreApplication::translate("about", "\320\243\321\207\320\265\321\202 \321\215\320\273\320\265\320\272\321\202\321\200\320\276\320\275\320\275\321\213\321\205 \321\201\320\276\320\276\320\261\321\211\320\265\320\275\320\270\320\271 \321\215\320\273\320\265\320\272\321\202\321\200\320\276\320\275\320\275\320\276\320\271 \320\277\320\276\321\207\321\202\321\213 \320\220\320\241\320\227\320\230 \"\320\246\320\270\321\202\321\200\320\270\320\275\"", nullptr));
        label_2->setText(QCoreApplication::translate("about", "\320\222\320\265\321\200\321\201\320\270\321\217 0.0.1", nullptr));
        pushButton->setText(QCoreApplication::translate("about", "\320\236\320\272!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class about: public Ui_about {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUT_H
