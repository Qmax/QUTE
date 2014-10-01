/********************************************************************************
** Form generated from reading UI file 'offsetwindow.ui'
**
** Created: Tue Sep 30 16:45:47 2014
**      by: Qt User Interface Compiler version 4.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OFFSETWINDOW_H
#define UI_OFFSETWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QRadioButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OffsetWindowClass
{
public:
    QGroupBox *m_tabDAC;
    QDoubleSpinBox *dblDACSpin;
    QWidget *widget;
    QGridLayout *gridLayout;
    QRadioButton *m_rbDACA;
    QRadioButton *m_rbDACC;
    QRadioButton *m_rbDACE;
    QRadioButton *m_rbDACB;
    QRadioButton *m_rbDACD;

    void setupUi(QWidget *OffsetWindowClass)
    {
        if (OffsetWindowClass->objectName().isEmpty())
            OffsetWindowClass->setObjectName(QString::fromUtf8("OffsetWindowClass"));
        OffsetWindowClass->setWindowModality(Qt::WindowModal);
        OffsetWindowClass->resize(529, 117);
        OffsetWindowClass->setStyleSheet(QString::fromUtf8("QLineEdit{border-width: 2px;border-style: outset;border-color: gray; border-radius: 2px;  padding: 0 8px;     background: black;     selection-background-color: yellow;   color:white;     font: 14px;}\n"
"\n"
"QLineEdit:disabled{border-width: 2px;border-style: outset;border-color: gray; border-radius: 2px;  padding: 0 8px;     background: gray;     selection-background-color: yellow;   color:white;     font: 14px;}\n"
"\n"
"QGroupBox{ \n"
"background:qlineargradient(\n"
"x1: 0, y1: 0, x2: 1, y2: 1, \n"
"stop: 0 #a9aa96,stop: 0.2 #bab9a9,\n"
"stop: 0.4 #d8d7c8,stop: 0.6 #a9aa96, \n"
"stop: 0.8 #bab9a9,stop: 1 #717164); \n"
"border:2px solid white;\n"
"border-radius:20px; }\n"
" QGroupBox::title {\n"
"	border:rgba(0,0,0,0);\n"
"	border-radius:8px;\n"
"     subcontrol-origin: margin;\n"
"     subcontrol-position: top middle; \n"
"     padding: 0 20px;\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #d8dff2, stop: 1 #FFFFFF);\n"
" }\n"
"QPus"
                        "hButton{\n"
"color:white;\n"
"border: 1px solid #2D5059;\n"
"background-color: \n"
"qlineargradient(x1: 0, y1: 1, x2: 1, y2: 0,\n"
"stop: 0 #1A74DB, \n"
"stop: 0.6 #5293DE, \n"
"stop:1 #FFFFFF);\n"
"}\n"
"\n"
"QComboBox{border: 2px solid gray;border-radius: 10px;color:black;}\n"
"\n"
"QToolButton {border: 1px solid black; border-radius: 5px;font:18px bold;background-color:rgba(170,170,170,255);}\n"
"\n"
"QSpinBox{border: 2px solid gray;border-radius: 10px;color:black;}\n"
"\n"
"QDoubleSpinBox{border: 2px solid gray;border-radius: 10px;color:black;}\n"
"\n"
"QCheckBox{font: bold 14px;} QCheckBox::indicator {width:20px;height:20px;border: 2px solid black;border-radius:1; } QCheckBox::indicator::unchecked {background-color:white;}QCheckBox::indicator:unchecked:hover {background-color:white; }\n"
"QCheckBox::indicator:unchecked:pressed {	background-color:white; }\n"
"QCheckBox::indicator::checked {background-color:#f2a400;}  QCheckBox::indicator:checked:hover {background-color:#f2a400;}\n"
"QCheckBox::indicator:ch"
                        "ecked:pressed {	background-color:#f2a400;}\n"
"\n"
"QLabel{font:bold 14px;color:black;}\n"
"QRadioButton{\n"
"font:14px;\n"
"color:white;\n"
"}\n"
" QRadioButton::indicator {\n"
"     width: 15px;\n"
"     height:15px;\n"
"   border: 1px solid black;\n"
"	 border-radius:8px;\n"
"\n"
" }\n"
" QRadioButton::indicator::unchecked {\n"
"		background-color:white;\n"
"     }\n"
"\n"
"     QRadioButton::indicator:unchecked:hover {\n"
"		background-color:white;\n"
"     }\n"
"\n"
"     QRadioButton::indicator:unchecked:pressed {\n"
"		background-color:white;\n"
"     }\n"
"\n"
"     QRadioButton::indicator::checked {\n"
"		background-color:#f2a400;\n"
"     }\n"
"\n"
"     QRadioButton::indicator:checked:hover {\n"
"		background-color:#f2a400;\n"
"     }\n"
"\n"
"     QRadioButton::indicator:checked:pressed {\n"
"		background-color:#f2a400;\n"
"     }\n"
"\n"
""));
        m_tabDAC = new QGroupBox(OffsetWindowClass);
        m_tabDAC->setObjectName(QString::fromUtf8("m_tabDAC"));
        m_tabDAC->setGeometry(QRect(1, -6, 531, 125));
        QFont font;
        font.setBold(true);
        font.setItalic(false);
        font.setWeight(75);
        m_tabDAC->setFont(font);
        m_tabDAC->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"   background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #4a79b5, stop: 1 #0f0f0f);\n"
"/*                                       stop: 0 #3a5976, stop: 1 #000000);*/\n"
"     border: 2px solid gray;\n"
"     border-radius: 5px;\n"
"     margin-top: 1ex; /* leave space at the top for the title */\n"
"	 font:bold 12px;	\n"
" }\n"
"\n"
" QGroupBox::title {\n"
"	border:2px solid white;\n"
"	border-radius:5px;\n"
"     subcontrol-origin: margin;\n"
"     subcontrol-position: top left; /* position at the top center */\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #d8dff2, stop: 1 #FFFFFF);\n"
" }\n"
"QLabel{\n"
"	color:white;\n"
"}"));
        dblDACSpin = new QDoubleSpinBox(m_tabDAC);
        dblDACSpin->setObjectName(QString::fromUtf8("dblDACSpin"));
        dblDACSpin->setGeometry(QRect(410, 30, 101, 61));
        dblDACSpin->setDecimals(4);
        widget = new QWidget(m_tabDAC);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(11, 17, 387, 97));
        gridLayout = new QGridLayout(widget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        m_rbDACA = new QRadioButton(widget);
        m_rbDACA->setObjectName(QString::fromUtf8("m_rbDACA"));

        gridLayout->addWidget(m_rbDACA, 0, 0, 1, 1);

        m_rbDACC = new QRadioButton(widget);
        m_rbDACC->setObjectName(QString::fromUtf8("m_rbDACC"));

        gridLayout->addWidget(m_rbDACC, 0, 1, 1, 1);

        m_rbDACE = new QRadioButton(widget);
        m_rbDACE->setObjectName(QString::fromUtf8("m_rbDACE"));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        m_rbDACE->setPalette(palette);

        gridLayout->addWidget(m_rbDACE, 0, 2, 1, 1);

        m_rbDACB = new QRadioButton(widget);
        m_rbDACB->setObjectName(QString::fromUtf8("m_rbDACB"));

        gridLayout->addWidget(m_rbDACB, 1, 0, 1, 1);

        m_rbDACD = new QRadioButton(widget);
        m_rbDACD->setObjectName(QString::fromUtf8("m_rbDACD"));

        gridLayout->addWidget(m_rbDACD, 1, 1, 1, 2);


        retranslateUi(OffsetWindowClass);

        QMetaObject::connectSlotsByName(OffsetWindowClass);
    } // setupUi

    void retranslateUi(QWidget *OffsetWindowClass)
    {
        OffsetWindowClass->setWindowTitle(QApplication::translate("OffsetWindowClass", "Select DAC", 0, QApplication::UnicodeUTF8));
        m_tabDAC->setTitle(QString());
        m_rbDACA->setText(QApplication::translate("OffsetWindowClass", "DAC A\n"
"(DSO1-OFF)", 0, QApplication::UnicodeUTF8));
        m_rbDACC->setText(QApplication::translate("OffsetWindowClass", "DAC C\n"
"(DSO 2-OFF)", 0, QApplication::UnicodeUTF8));
        m_rbDACE->setText(QApplication::translate("OffsetWindowClass", "DAC E\n"
"(DSO-E-T-OFF)", 0, QApplication::UnicodeUTF8));
        m_rbDACB->setText(QApplication::translate("OffsetWindowClass", "DAC B\n"
"(DSO1-T-OFF)", 0, QApplication::UnicodeUTF8));
        m_rbDACD->setText(QApplication::translate("OffsetWindowClass", "DAC D\n"
"(DSO 2-T-OFF)", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class OffsetWindowClass: public Ui_OffsetWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OFFSETWINDOW_H
