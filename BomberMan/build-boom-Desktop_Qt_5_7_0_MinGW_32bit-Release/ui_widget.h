/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>
#include "meadow.h"

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QStackedWidget *stackedWidget;
    QWidget *page;
    QGridLayout *gridLayout;
    QWidget *widget;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QWidget *page_2;
    Meadow *widget_3;
    QWidget *widget_4;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QWidget *widget_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_8;
    QWidget *page_3;
    QWidget *widget_5;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->setEnabled(true);
        Widget->resize(1340, 719);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(4);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Widget->sizePolicy().hasHeightForWidth());
        Widget->setSizePolicy(sizePolicy);
        stackedWidget = new QStackedWidget(Widget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(-10, 0, 1351, 711));
        stackedWidget->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        page->setStyleSheet(QString::fromUtf8("background-image: url(:/\347\264\240\346\235\220/\347\202\270\345\274\271\344\272\272\345\260\201\351\235\242.png);"));
        gridLayout = new QGridLayout(page);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        widget = new QWidget(page);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(200, 200));
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(570, 510, 141, 51));
        pushButton->setStyleSheet(QString::fromUtf8("font: 24pt \"\345\215\216\346\226\207\346\245\267\344\275\223\";\n"
"background-color: rgb(206, 255, 185);\n"
"color: rgb(0, 0, 0);"));
        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(570, 590, 141, 41));
        pushButton_3->setStyleSheet(QString::fromUtf8("font: 24pt \"\345\215\216\346\226\207\346\245\267\344\275\223\";\n"
"color: rgb(0, 0, 0);\n"
"background-color: rgb(206, 255, 185);"));

        gridLayout->addWidget(widget, 0, 0, 1, 1);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        widget_3 = new Meadow(page_2);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setGeometry(QRect(190, 170, 1151, 531));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget_3->sizePolicy().hasHeightForWidth());
        widget_3->setSizePolicy(sizePolicy1);
        widget_3->setFocusPolicy(Qt::StrongFocus);
        widget_3->setStyleSheet(QStringLiteral("background-color: rgb(44, 211, 19);"));
        widget_4 = new QWidget(page_2);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        widget_4->setGeometry(QRect(190, 0, 1151, 171));
        widget_4->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/\347\264\240\346\235\220/up.png);"));
        pushButton_4 = new QPushButton(widget_4);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(50, 120, 93, 28));
        pushButton_4->setStyleSheet(QStringLiteral("background-color: rgb(255, 0, 0);"));
        pushButton_5 = new QPushButton(widget_4);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(800, 120, 101, 41));
        pushButton_6 = new QPushButton(widget_4);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(923, 127, 93, 28));
        pushButton_7 = new QPushButton(widget_4);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(1030, 120, 101, 41));
        label_9 = new QLabel(widget_4);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(20, 10, 35, 35));
        label_9->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/\347\264\240\346\235\220/\345\242\236\345\212\240\347\202\270\345\274\271\351\201\223\345\205\267\345\215\241.png);"));
        label_10 = new QLabel(widget_4);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(90, 10, 35, 35));
        label_10->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/\347\264\240\346\235\220/\345\256\232\346\227\266\347\202\270\345\274\271\351\201\223\345\205\267\345\215\241.png);"));
        label_11 = new QLabel(widget_4);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(160, 10, 35, 35));
        label_11->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/\347\264\240\346\235\220/\351\201\223\345\205\267\345\215\241.png);"));
        label_12 = new QLabel(widget_4);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(10, 60, 72, 15));
        label_12->setStyleSheet(QStringLiteral(""));
        label_13 = new QLabel(widget_4);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(93, 60, 31, 16));
        label_14 = new QLabel(widget_4);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(150, 60, 72, 15));
        label_15 = new QLabel(widget_4);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(1000, 50, 141, 51));
        label_15->setStyleSheet(QString::fromUtf8("font: 14pt \"\346\245\267\344\275\223\";\n"
"color: rgb(255, 0, 0);"));
        widget_2 = new QWidget(page_2);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setGeometry(QRect(30, 0, 161, 701));
        widget_2->setMinimumSize(QSize(100, 0));
        widget_2->setMaximumSize(QSize(1000, 16777215));
        widget_2->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        label = new QLabel(widget_2);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 161, 224));
        label->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/\347\264\240\346\235\220/\350\207\252\345\210\2662.png);"));
        label_2 = new QLabel(widget_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(0, 470, 161, 224));
        label_2->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/\347\264\240\346\235\220/\350\207\252\345\210\2662.png);"));
        label_8 = new QLabel(widget_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(10, 260, 131, 171));
        label_8->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\215\216\346\226\207\350\241\214\346\245\267\";\n"
"font: 14pt \"\346\245\267\344\275\223\";"));
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        widget_5 = new QWidget(page_3);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        widget_5->setGeometry(QRect(0, 0, 1391, 711));
        widget_5->setStyleSheet(QStringLiteral("background-color: rgb(249, 255, 237);"));
        label_3 = new QLabel(widget_5);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(550, 150, 251, 51));
        label_3->setStyleSheet(QString::fromUtf8("font: 28pt \"\345\215\216\346\226\207\346\245\267\344\275\223\";"));
        label_4 = new QLabel(widget_5);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(470, 270, 151, 41));
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);\n"
"background-color: rgb(255, 255, 255);\n"
"font: 22pt \"\345\215\216\346\226\207\346\245\267\344\275\223\";"));
        label_5 = new QLabel(widget_5);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(710, 270, 111, 41));
        label_5->setStyleSheet(QString::fromUtf8("font: 22pt \"\345\215\216\346\226\207\346\245\267\344\275\223\"; \n"
"background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        label_6 = new QLabel(widget_5);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(470, 350, 151, 41));
        label_6->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);\n"
"background-color: rgb(255, 255, 255);\n"
"font: 22pt \"\345\215\216\346\226\207\346\245\267\344\275\223\";"));
        label_7 = new QLabel(widget_5);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(710, 350, 111, 41));
        label_7->setStyleSheet(QString::fromUtf8("font: 22pt \"\345\215\216\346\226\207\346\245\267\344\275\223\"; \n"
"background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        stackedWidget->addWidget(page_3);

        retranslateUi(Widget);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0));
        pushButton->setText(QApplication::translate("Widget", "START", 0));
        pushButton_3->setText(QApplication::translate("Widget", "QUIT", 0));
        pushButton_4->setText(QApplication::translate("Widget", "QUIT", 0));
        pushButton_5->setText(QApplication::translate("Widget", "\344\270\212\344\270\200\351\246\226", 0));
        pushButton_6->setText(QApplication::translate("Widget", "\346\232\202\345\201\234/\346\222\255\346\224\276", 0));
        pushButton_7->setText(QApplication::translate("Widget", "\344\270\213\344\270\200\351\246\226", 0));
        label_9->setText(QString());
        label_10->setText(QString());
        label_11->setText(QString());
        label_12->setText(QApplication::translate("Widget", "\347\202\270\345\274\271\345\242\236\345\212\240", 0));
        label_13->setText(QApplication::translate("Widget", "\345\256\232\346\227\266", 0));
        label_14->setText(QApplication::translate("Widget", "\345\250\201\345\212\233\345\212\240\345\274\272", 0));
        label_15->setText(QApplication::translate("Widget", "Time: 200s", 0));
        label->setText(QString());
        label_2->setText(QString());
        label_8->setText(QApplication::translate("Widget", "w,\342\206\221: \345\220\221\344\270\212\n"
"s,\342\206\223: \345\220\221\344\270\213\n"
"a,\342\206\220: \345\220\221\345\267\246\n"
"d,\342\206\222: \345\220\221\345\217\263\n"
"j: \346\224\276\347\275\256\347\202\270\345\274\271\n"
"k: \345\256\232\346\227\266\345\274\225\347\210\206", 0));
        label_3->setText(QApplication::translate("Widget", "game is over!", 0));
        label_4->setText(QApplication::translate("Widget", " use time:", 0));
        label_5->setText(QApplication::translate("Widget", "  0.0", 0));
        label_6->setText(QApplication::translate("Widget", "    score:", 0));
        label_7->setText(QApplication::translate("Widget", "  0.0", 0));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
