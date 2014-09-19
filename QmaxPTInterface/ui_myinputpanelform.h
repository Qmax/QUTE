/********************************************************************************
** Form generated from reading UI file 'myinputpanelform.ui'
**
** Created: Mon Sep 1 11:57:41 2014
**      by: Qt User Interface Compiler version 4.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYINPUTPANELFORM_H
#define UI_MYINPUTPANELFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyInputPanelForm
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QPushButton *panelButton_9;
    QPushButton *panelButton_6;
    QPushButton *panelButton_3;
    QPushButton *panelButton_hash;
    QPushButton *panelButton_star;
    QPushButton *panelButton_8;
    QPushButton *panelButton_2;
    QPushButton *panelButton_7;
    QPushButton *panelButton_4;
    QPushButton *panelButton_0;
    QPushButton *panelButton_5;
    QPushButton *panelButton_1;
    QFrame *line;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QTextEdit *textEdit;
    QPushButton *panelButton_OK;
    QPushButton *panelButton_CANCEL;

    void setupUi(QWidget *MyInputPanelForm)
    {
        if (MyInputPanelForm->objectName().isEmpty())
            MyInputPanelForm->setObjectName(QString::fromUtf8("MyInputPanelForm"));
        MyInputPanelForm->setWindowModality(Qt::WindowModal);
        MyInputPanelForm->resize(450, 399);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(89, 88, 88, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(134, 132, 132, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(111, 110, 110, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(44, 44, 44, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(59, 58, 58, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QBrush brush6(QColor(0, 0, 0, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush6);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush4);
        QBrush brush7(QColor(255, 255, 220, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush6);
        MyInputPanelForm->setPalette(palette);
        layoutWidget = new QWidget(MyInputPanelForm);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(148, 70, 200, 241));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        panelButton_9 = new QPushButton(layoutWidget);
        panelButton_9->setObjectName(QString::fromUtf8("panelButton_9"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(panelButton_9->sizePolicy().hasHeightForWidth());
        panelButton_9->setSizePolicy(sizePolicy);
        panelButton_9->setMinimumSize(QSize(45, 40));
        QFont font;
        font.setPointSize(16);
        panelButton_9->setFont(font);
        panelButton_9->setFocusPolicy(Qt::NoFocus);
        panelButton_9->setProperty("buttonValue", QVariant(QChar(57)));

        gridLayout->addWidget(panelButton_9, 2, 2, 1, 1);

        panelButton_6 = new QPushButton(layoutWidget);
        panelButton_6->setObjectName(QString::fromUtf8("panelButton_6"));
        sizePolicy.setHeightForWidth(panelButton_6->sizePolicy().hasHeightForWidth());
        panelButton_6->setSizePolicy(sizePolicy);
        panelButton_6->setMinimumSize(QSize(45, 40));
        panelButton_6->setFont(font);
        panelButton_6->setFocusPolicy(Qt::NoFocus);
        panelButton_6->setProperty("buttonValue", QVariant(QChar(54)));

        gridLayout->addWidget(panelButton_6, 1, 2, 1, 1);

        panelButton_3 = new QPushButton(layoutWidget);
        panelButton_3->setObjectName(QString::fromUtf8("panelButton_3"));
        sizePolicy.setHeightForWidth(panelButton_3->sizePolicy().hasHeightForWidth());
        panelButton_3->setSizePolicy(sizePolicy);
        panelButton_3->setMinimumSize(QSize(45, 40));
        panelButton_3->setFont(font);
        panelButton_3->setFocusPolicy(Qt::NoFocus);
        panelButton_3->setProperty("buttonValue", QVariant(QChar(51)));

        gridLayout->addWidget(panelButton_3, 0, 2, 1, 1);

        panelButton_hash = new QPushButton(layoutWidget);
        panelButton_hash->setObjectName(QString::fromUtf8("panelButton_hash"));
        sizePolicy.setHeightForWidth(panelButton_hash->sizePolicy().hasHeightForWidth());
        panelButton_hash->setSizePolicy(sizePolicy);
        panelButton_hash->setMinimumSize(QSize(45, 40));
        panelButton_hash->setFont(font);
        panelButton_hash->setFocusPolicy(Qt::NoFocus);
        panelButton_hash->setProperty("buttonValue", QVariant(QChar(35)));

        gridLayout->addWidget(panelButton_hash, 3, 2, 1, 1);

        panelButton_star = new QPushButton(layoutWidget);
        panelButton_star->setObjectName(QString::fromUtf8("panelButton_star"));
        sizePolicy.setHeightForWidth(panelButton_star->sizePolicy().hasHeightForWidth());
        panelButton_star->setSizePolicy(sizePolicy);
        panelButton_star->setMinimumSize(QSize(45, 40));
        panelButton_star->setFont(font);
        panelButton_star->setFocusPolicy(Qt::NoFocus);
        panelButton_star->setProperty("buttonValue", QVariant(QChar(46)));

        gridLayout->addWidget(panelButton_star, 3, 0, 1, 1);

        panelButton_8 = new QPushButton(layoutWidget);
        panelButton_8->setObjectName(QString::fromUtf8("panelButton_8"));
        sizePolicy.setHeightForWidth(panelButton_8->sizePolicy().hasHeightForWidth());
        panelButton_8->setSizePolicy(sizePolicy);
        panelButton_8->setMinimumSize(QSize(45, 40));
        panelButton_8->setFont(font);
        panelButton_8->setFocusPolicy(Qt::NoFocus);
        panelButton_8->setProperty("buttonValue", QVariant(QChar(56)));

        gridLayout->addWidget(panelButton_8, 2, 1, 1, 1);

        panelButton_2 = new QPushButton(layoutWidget);
        panelButton_2->setObjectName(QString::fromUtf8("panelButton_2"));
        sizePolicy.setHeightForWidth(panelButton_2->sizePolicy().hasHeightForWidth());
        panelButton_2->setSizePolicy(sizePolicy);
        panelButton_2->setMinimumSize(QSize(45, 40));
        panelButton_2->setFont(font);
        panelButton_2->setFocusPolicy(Qt::NoFocus);
        panelButton_2->setProperty("buttonValue", QVariant(QChar(50)));

        gridLayout->addWidget(panelButton_2, 0, 1, 1, 1);

        panelButton_7 = new QPushButton(layoutWidget);
        panelButton_7->setObjectName(QString::fromUtf8("panelButton_7"));
        sizePolicy.setHeightForWidth(panelButton_7->sizePolicy().hasHeightForWidth());
        panelButton_7->setSizePolicy(sizePolicy);
        panelButton_7->setMinimumSize(QSize(45, 40));
        panelButton_7->setFont(font);
        panelButton_7->setFocusPolicy(Qt::NoFocus);
        panelButton_7->setProperty("buttonValue", QVariant(QChar(55)));

        gridLayout->addWidget(panelButton_7, 2, 0, 1, 1);

        panelButton_4 = new QPushButton(layoutWidget);
        panelButton_4->setObjectName(QString::fromUtf8("panelButton_4"));
        sizePolicy.setHeightForWidth(panelButton_4->sizePolicy().hasHeightForWidth());
        panelButton_4->setSizePolicy(sizePolicy);
        panelButton_4->setMinimumSize(QSize(45, 40));
        panelButton_4->setFont(font);
        panelButton_4->setFocusPolicy(Qt::NoFocus);
        panelButton_4->setProperty("buttonValue", QVariant(QChar(52)));

        gridLayout->addWidget(panelButton_4, 1, 0, 1, 1);

        panelButton_0 = new QPushButton(layoutWidget);
        panelButton_0->setObjectName(QString::fromUtf8("panelButton_0"));
        sizePolicy.setHeightForWidth(panelButton_0->sizePolicy().hasHeightForWidth());
        panelButton_0->setSizePolicy(sizePolicy);
        panelButton_0->setMinimumSize(QSize(45, 40));
        panelButton_0->setFont(font);
        panelButton_0->setFocusPolicy(Qt::NoFocus);
        panelButton_0->setProperty("buttonValue", QVariant(QChar(48)));

        gridLayout->addWidget(panelButton_0, 3, 1, 1, 1);

        panelButton_5 = new QPushButton(layoutWidget);
        panelButton_5->setObjectName(QString::fromUtf8("panelButton_5"));
        sizePolicy.setHeightForWidth(panelButton_5->sizePolicy().hasHeightForWidth());
        panelButton_5->setSizePolicy(sizePolicy);
        panelButton_5->setMinimumSize(QSize(45, 40));
        panelButton_5->setFont(font);
        panelButton_5->setFocusPolicy(Qt::NoFocus);
        panelButton_5->setProperty("buttonValue", QVariant(QChar(53)));

        gridLayout->addWidget(panelButton_5, 1, 1, 1, 1);

        panelButton_1 = new QPushButton(layoutWidget);
        panelButton_1->setObjectName(QString::fromUtf8("panelButton_1"));
        sizePolicy.setHeightForWidth(panelButton_1->sizePolicy().hasHeightForWidth());
        panelButton_1->setSizePolicy(sizePolicy);
        panelButton_1->setMinimumSize(QSize(45, 40));
        panelButton_1->setFont(font);
        panelButton_1->setFocusPolicy(Qt::NoFocus);
        panelButton_1->setProperty("buttonValue", QVariant(QChar(49)));

        gridLayout->addWidget(panelButton_1, 0, 0, 1, 1);

        line = new QFrame(MyInputPanelForm);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(118, 70, 20, 241));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        pushButton = new QPushButton(MyInputPanelForm);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(20, 240, 93, 51));
        pushButton_2 = new QPushButton(MyInputPanelForm);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(20, 170, 93, 51));
        pushButton_3 = new QPushButton(MyInputPanelForm);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(20, 110, 93, 51));
        textEdit = new QTextEdit(MyInputPanelForm);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(145, 12, 201, 51));
        panelButton_OK = new QPushButton(MyInputPanelForm);
        panelButton_OK->setObjectName(QString::fromUtf8("panelButton_OK"));
        panelButton_OK->setGeometry(QRect(160, 330, 62, 40));
        sizePolicy.setHeightForWidth(panelButton_OK->sizePolicy().hasHeightForWidth());
        panelButton_OK->setSizePolicy(sizePolicy);
        panelButton_OK->setMinimumSize(QSize(45, 40));
        QFont font1;
        font1.setPointSize(10);
        panelButton_OK->setFont(font1);
        panelButton_OK->setFocusPolicy(Qt::NoFocus);
        panelButton_OK->setProperty("buttonValue", QVariant(QChar(89)));
        panelButton_CANCEL = new QPushButton(MyInputPanelForm);
        panelButton_CANCEL->setObjectName(QString::fromUtf8("panelButton_CANCEL"));
        panelButton_CANCEL->setGeometry(QRect(240, 330, 62, 40));
        sizePolicy.setHeightForWidth(panelButton_CANCEL->sizePolicy().hasHeightForWidth());
        panelButton_CANCEL->setSizePolicy(sizePolicy);
        panelButton_CANCEL->setMinimumSize(QSize(45, 40));
        panelButton_CANCEL->setFont(font1);
        panelButton_CANCEL->setFocusPolicy(Qt::NoFocus);
        panelButton_CANCEL->setProperty("buttonValue", QVariant(QChar(78)));

        retranslateUi(MyInputPanelForm);

        QMetaObject::connectSlotsByName(MyInputPanelForm);
    } // setupUi

    void retranslateUi(QWidget *MyInputPanelForm)
    {
        MyInputPanelForm->setWindowTitle(QApplication::translate("MyInputPanelForm", "Input Panel", 0, QApplication::UnicodeUTF8));
        panelButton_9->setText(QApplication::translate("MyInputPanelForm", "9", 0, QApplication::UnicodeUTF8));
        panelButton_6->setText(QApplication::translate("MyInputPanelForm", "6", 0, QApplication::UnicodeUTF8));
        panelButton_3->setText(QApplication::translate("MyInputPanelForm", "3", 0, QApplication::UnicodeUTF8));
        panelButton_hash->setText(QApplication::translate("MyInputPanelForm", "#", 0, QApplication::UnicodeUTF8));
        panelButton_star->setText(QApplication::translate("MyInputPanelForm", ".", 0, QApplication::UnicodeUTF8));
        panelButton_8->setText(QApplication::translate("MyInputPanelForm", "8", 0, QApplication::UnicodeUTF8));
        panelButton_2->setText(QApplication::translate("MyInputPanelForm", "2", 0, QApplication::UnicodeUTF8));
        panelButton_7->setText(QApplication::translate("MyInputPanelForm", "7", 0, QApplication::UnicodeUTF8));
        panelButton_4->setText(QApplication::translate("MyInputPanelForm", "4", 0, QApplication::UnicodeUTF8));
        panelButton_0->setText(QApplication::translate("MyInputPanelForm", "0", 0, QApplication::UnicodeUTF8));
        panelButton_5->setText(QApplication::translate("MyInputPanelForm", "5", 0, QApplication::UnicodeUTF8));
        panelButton_1->setText(QApplication::translate("MyInputPanelForm", "1", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MyInputPanelForm", "Set to Max", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("MyInputPanelForm", "Set to Default", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("MyInputPanelForm", "Set to Min.", 0, QApplication::UnicodeUTF8));
        panelButton_OK->setText(QApplication::translate("MyInputPanelForm", "OK", 0, QApplication::UnicodeUTF8));
        panelButton_CANCEL->setText(QApplication::translate("MyInputPanelForm", "CANCEL", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MyInputPanelForm: public Ui_MyInputPanelForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYINPUTPANELFORM_H
