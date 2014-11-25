/********************************************************************************
** Form generated from reading UI file 'autocurvefittraces.ui'
**
** Created: Mon Nov 24 17:14:29 2014
**      by: Qt User Interface Compiler version 4.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTOCURVEFITTRACES_H
#define UI_AUTOCURVEFITTRACES_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AutoCurveFitTracesClass
{
public:
    QWidget *centralwidget;
    QPushButton *objClose;
    QGroupBox *grpComponens;
    QCheckBox *chkInductance;
    QCheckBox *chkDiode;
    QCheckBox *chkCapacitance;
    QCheckBox *chkResistance;
    QPushButton *print;

    void setupUi(QMainWindow *AutoCurveFitTracesClass)
    {
        if (AutoCurveFitTracesClass->objectName().isEmpty())
            AutoCurveFitTracesClass->setObjectName(QString::fromUtf8("AutoCurveFitTracesClass"));
        AutoCurveFitTracesClass->setWindowModality(Qt::WindowModal);
        AutoCurveFitTracesClass->resize(509, 434);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(AutoCurveFitTracesClass->sizePolicy().hasHeightForWidth());
        AutoCurveFitTracesClass->setSizePolicy(sizePolicy);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(88, 88, 89, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(132, 132, 134, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(110, 110, 111, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(44, 44, 44, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(58, 58, 59, 255));
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
        AutoCurveFitTracesClass->setPalette(palette);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image.png"), QSize(), QIcon::Normal, QIcon::Off);
        AutoCurveFitTracesClass->setWindowIcon(icon);
        AutoCurveFitTracesClass->setIconSize(QSize(0, 0));
        centralwidget = new QWidget(AutoCurveFitTracesClass);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        objClose = new QPushButton(centralwidget);
        objClose->setObjectName(QString::fromUtf8("objClose"));
        objClose->setGeometry(QRect(436, 370, 71, 51));
        QFont font;
        font.setFamily(QString::fromUtf8("DejaVu Sans"));
        font.setPointSize(16);
        objClose->setFont(font);
        objClose->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"border: 2px solid #8f8f91;\n"
"border-radius: 20px;\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"stop: 0 #f6f7fa, stop: 1 #dadbde);\n"
"}\n"
"QPushButton:pressed {\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}\n"
"QPushButton:flat {\n"
"border: none; \n"
"}\n"
"QPushButton:default {\n"
"border-color: navy; \n"
"}"));
        grpComponens = new QGroupBox(centralwidget);
        grpComponens->setObjectName(QString::fromUtf8("grpComponens"));
        grpComponens->setGeometry(QRect(10, 369, 355, 51));
        chkInductance = new QCheckBox(grpComponens);
        chkInductance->setObjectName(QString::fromUtf8("chkInductance"));
        chkInductance->setEnabled(false);
        chkInductance->setGeometry(QRect(260, 10, 91, 25));
        chkInductance->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
"font:14px;\n"
"color:white;\n"
"}\n"
" QCheckBox::indicator {\n"
"     width: 22px;\n"
"     height:22px;\n"
"   border: 2px solid black;\n"
"	 border-radius:12px;\n"
"\n"
" }\n"
" QCheckBox::indicator::unchecked {\n"
"		background-color:yellow;\n"
"     }\n"
"\n"
"     QCheckBox::indicator:unchecked:hover {\n"
"		background-color:white;\n"
"     }\n"
"\n"
"     QCheckBox::indicator:unchecked:pressed {\n"
"		background-color:white;\n"
"     }\n"
"\n"
"     QCheckBox::indicator::checked {\n"
"		background-color:#f2a400;\n"
"     }\n"
"\n"
"     QCheckBox::indicator:checked:hover {\n"
"		background-color:#f2a400;\n"
"     }\n"
"\n"
"     QCheckBox::indicator:checked:pressed {\n"
"		background-color:#f2a400;\n"
"     }"));
        chkDiode = new QCheckBox(grpComponens);
        chkDiode->setObjectName(QString::fromUtf8("chkDiode"));
        chkDiode->setEnabled(false);
        chkDiode->setGeometry(QRect(90, 10, 81, 25));
        chkDiode->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
"font:14px;\n"
"color:white;\n"
"}\n"
" QCheckBox::indicator {\n"
"     width: 22px;\n"
"     height:22px;\n"
"   border: 2px solid black;\n"
"	 border-radius:12px;\n"
"\n"
" }\n"
" QCheckBox::indicator::unchecked {\n"
"		background-color:cyan;\n"
"     }\n"
"\n"
"     QCheckBox::indicator:unchecked:hover {\n"
"		background-color:white;\n"
"     }\n"
"\n"
"     QCheckBox::indicator:unchecked:pressed {\n"
"		background-color:white;\n"
"     }\n"
"\n"
"     QCheckBox::indicator::checked {\n"
"		background-color:#f2a400;\n"
"     }\n"
"\n"
"     QCheckBox::indicator:checked:hover {\n"
"		background-color:#f2a400;\n"
"     }\n"
"\n"
"     QCheckBox::indicator:checked:pressed {\n"
"		background-color:#f2a400;\n"
"     }"));
        chkCapacitance = new QCheckBox(grpComponens);
        chkCapacitance->setObjectName(QString::fromUtf8("chkCapacitance"));
        chkCapacitance->setEnabled(false);
        chkCapacitance->setGeometry(QRect(162, 10, 101, 25));
        chkCapacitance->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
"font:14px;\n"
"color:white;\n"
"}\n"
" QCheckBox::indicator {\n"
"     width: 22px;\n"
"     height:22px;\n"
"   border: 2px solid black;\n"
"	 border-radius:12px;\n"
"\n"
" }\n"
" QCheckBox::indicator::unchecked {\n"
"		background-color:magenta;\n"
"     }\n"
"\n"
"     QCheckBox::indicator:unchecked:hover {\n"
"		background-color:white;\n"
"     }\n"
"\n"
"     QCheckBox::indicator:unchecked:pressed {\n"
"		background-color:white;\n"
"     }\n"
"\n"
"     QCheckBox::indicator::checked {\n"
"		background-color:#f2a400;\n"
"     }\n"
"\n"
"     QCheckBox::indicator:checked:hover {\n"
"		background-color:#f2a400;\n"
"     }\n"
"\n"
"     QCheckBox::indicator:checked:pressed {\n"
"		background-color:#f2a400;\n"
"     }"));
        chkResistance = new QCheckBox(grpComponens);
        chkResistance->setObjectName(QString::fromUtf8("chkResistance"));
        chkResistance->setEnabled(false);
        chkResistance->setGeometry(QRect(2, 10, 91, 25));
        chkResistance->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
"font:14px;\n"
"color:white;\n"
"}\n"
" QCheckBox::indicator {\n"
"     width: 22px;\n"
"     height:22px;\n"
"   border: 2px solid black;\n"
"	 border-radius:12px;\n"
"\n"
" }\n"
" QCheckBox::indicator::unchecked {\n"
"		background-color:green;\n"
"     }\n"
"\n"
"     QCheckBox::indicator:unchecked:hover {\n"
"		background-color:white;\n"
"     }\n"
"\n"
"     QCheckBox::indicator:unchecked:pressed {\n"
"		background-color:white;\n"
"     }\n"
"\n"
"     QCheckBox::indicator::checked {\n"
"		background-color:#f2a400;\n"
"     }\n"
"\n"
"     QCheckBox::indicator:checked:hover {\n"
"		background-color:#f2a400;\n"
"     }\n"
"\n"
"     QCheckBox::indicator:checked:pressed {\n"
"		background-color:#f2a400;\n"
"     }"));
        print = new QPushButton(centralwidget);
        print->setObjectName(QString::fromUtf8("print"));
        print->setGeometry(QRect(370, 370, 61, 51));
        print->setFont(font);
        print->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"border: 2px solid #8f8f91;\n"
"border-radius: 20px;\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"stop: 0 #f6f7fa, stop: 1 #dadbde);\n"
"}\n"
"QPushButton:pressed {\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}\n"
"QPushButton:flat {\n"
"border: none; \n"
"}\n"
"QPushButton:default {\n"
"border-color: navy; \n"
"}"));
        AutoCurveFitTracesClass->setCentralWidget(centralwidget);

        retranslateUi(AutoCurveFitTracesClass);

        QMetaObject::connectSlotsByName(AutoCurveFitTracesClass);
    } // setupUi

    void retranslateUi(QMainWindow *AutoCurveFitTracesClass)
    {
        AutoCurveFitTracesClass->setWindowTitle(QApplication::translate("AutoCurveFitTracesClass", "Best CurveFit", 0, QApplication::UnicodeUTF8));
        objClose->setText(QApplication::translate("AutoCurveFitTracesClass", "Close", 0, QApplication::UnicodeUTF8));
        grpComponens->setTitle(QString());
        chkInductance->setText(QApplication::translate("AutoCurveFitTracesClass", "Inductor", 0, QApplication::UnicodeUTF8));
        chkDiode->setText(QApplication::translate("AutoCurveFitTracesClass", "Diode", 0, QApplication::UnicodeUTF8));
        chkCapacitance->setText(QApplication::translate("AutoCurveFitTracesClass", "Capacitor", 0, QApplication::UnicodeUTF8));
        chkResistance->setText(QApplication::translate("AutoCurveFitTracesClass", "Resistor", 0, QApplication::UnicodeUTF8));
        print->setText(QApplication::translate("AutoCurveFitTracesClass", "Print", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AutoCurveFitTracesClass: public Ui_AutoCurveFitTracesClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTOCURVEFITTRACES_H
