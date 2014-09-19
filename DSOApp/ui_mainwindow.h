/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Tue Apr 8 11:32:17 2014
**      by: Qt User Interface Compiler version 4.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDial>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFrame>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *DSODisplayWidget;
    QWidget *ch2Widget;
    QLabel *ch2Voffset;
    QLabel *channel2No;
    QLabel *ch2VperDiv;
    QLabel *ch2labelVpD;
    QLabel *ch2lblOffset;
    QLabel *ch2Coupling;
    QLabel *lblCH2DelX;
    QLabel *lblCH2DelValue;
    QWidget *CH1widget;
    QLabel *ch1Coupling;
    QLabel *channel1No;
    QLabel *ch1VperDiv;
    QLabel *ch1Voffset;
    QLabel *ch1labelVpD;
    QLabel *ch1lblOffset;
    QLabel *lblCH1DelX;
    QLabel *lblCH1DelValue;
    QFrame *topFrame;
    QToolButton *rootItem;
    QWidget *TriggerWidget;
    QLabel *ch1Coupling_2;
    QLabel *TriggerTitle;
    QLabel *lblHort;
    QLabel *lblVertT;
    QLabel *lblHorTValue;
    QLabel *lblVertTValue;
    QPushButton *pushButton;
    QWidget *Timebase;
    QLabel *ch1Coupling_3;
    QLabel *TimebaseTitle;
    QLabel *labelTimePerDiv;
    QLabel *lblMemory;
    QLabel *lblSamplingRate;
    QPushButton *butRUNSTOP;
    QGroupBox *grpTimeDiv;
    QDial *timebaseDialWheel;
    QLabel *chTperDiv;
    QLabel *label;
    QLabel *label_2;
    QGroupBox *grpVoltDiv;
    QDial *VoltageDialWheel;
    QLabel *chlabel;
    QLabel *chVperDiv;
    QLabel *chVperDiv_2;
    QCheckBox *chk1ShowTrace;
    QCheckBox *chk2ShowTrace;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *butOffset_plus;
    QPushButton *butOffset_minus;
    QLabel *label_5;
    QPushButton *butOffset_zero;
    QGroupBox *grpTriggers;
    QDial *triggerWheel;
    QLabel *chTperDiv_2;
    QDoubleSpinBox *dblHorizontalTrigger;
    QDoubleSpinBox *dblVerticalTrigger;
    QFrame *line;
    QLabel *TimebaseTitle_2;
    QLabel *TimebaseTitle_3;
    QWidget *Cursors;
    QLabel *ch1Coupling_4;
    QLabel *cursorsTitle;
    QLabel *lblX1;
    QLabel *lblX1Value;
    QLabel *lblX2;
    QLabel *lblX2Value;
    QLabel *lblY1;
    QLabel *lblY1Value;
    QLabel *lblY2;
    QLabel *lblY2Value;
    QGroupBox *grpCursors;
    QLabel *chTperDiv_3;
    QPushButton *butUP;
    QPushButton *butDOWN;
    QPushButton *butLEFT;
    QPushButton *butRIGHT;
    QLabel *lblSysFreqValue;
    QRadioButton *optAuto;
    QRadioButton *optNormal;
    QLabel *lblDelY_2;
    QLabel *lblDelFreqValue;
    QLabel *lblDelYValue;
    QLabel *lblDelY;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(0, 0, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(0, 0, 0, 0));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush2);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush2);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush2);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush1);
        QBrush brush3(QColor(0, 0, 0, 127));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush3);
        QBrush brush4(QColor(255, 255, 220, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush4);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush1);
        MainWindow->setPalette(palette);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        DSODisplayWidget = new QWidget(centralWidget);
        DSODisplayWidget->setObjectName(QString::fromUtf8("DSODisplayWidget"));
        DSODisplayWidget->setGeometry(QRect(0, 30, 700, 460));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Midlight, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Dark, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Mid, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Shadow, brush1);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipBase, brush4);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipText, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Dark, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Mid, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Shadow, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush4);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Dark, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Mid, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Shadow, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush1);
        DSODisplayWidget->setPalette(palette1);
        DSODisplayWidget->setCursor(QCursor(Qt::CrossCursor));
        DSODisplayWidget->setStyleSheet(QString::fromUtf8(""));
        ch2Widget = new QWidget(centralWidget);
        ch2Widget->setObjectName(QString::fromUtf8("ch2Widget"));
        ch2Widget->setGeometry(QRect(130, 520, 115, 80));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        QBrush brush5(QColor(143, 143, 142, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush5);
        QBrush brush6(QColor(255, 255, 127, 0));
        brush6.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Light, brush6);
        QBrush brush7(QColor(255, 255, 63, 0));
        brush7.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Midlight, brush7);
        QBrush brush8(QColor(127, 127, 0, 0));
        brush8.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Dark, brush8);
        QBrush brush9(QColor(170, 170, 0, 0));
        brush9.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Mid, brush9);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette2.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush5);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush5);
        palette2.setBrush(QPalette::Active, QPalette::Shadow, brush1);
        QBrush brush10(QColor(255, 255, 127, 127));
        brush10.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::AlternateBase, brush10);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipBase, brush4);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipText, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush5);
        palette2.setBrush(QPalette::Inactive, QPalette::Light, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::Midlight, brush7);
        palette2.setBrush(QPalette::Inactive, QPalette::Dark, brush8);
        palette2.setBrush(QPalette::Inactive, QPalette::Mid, brush9);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush5);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush5);
        palette2.setBrush(QPalette::Inactive, QPalette::Shadow, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush10);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush4);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush8);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush5);
        palette2.setBrush(QPalette::Disabled, QPalette::Light, brush6);
        palette2.setBrush(QPalette::Disabled, QPalette::Midlight, brush7);
        palette2.setBrush(QPalette::Disabled, QPalette::Dark, brush8);
        palette2.setBrush(QPalette::Disabled, QPalette::Mid, brush9);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush8);
        palette2.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush8);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush5);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush5);
        palette2.setBrush(QPalette::Disabled, QPalette::Shadow, brush1);
        QBrush brush11(QColor(255, 255, 0, 0));
        brush11.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush11);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush1);
        ch2Widget->setPalette(palette2);
        ch2Widget->setStyleSheet(QString::fromUtf8("QWidget{\n"
"	background-color: rgb(143, 143, 142);\n"
"	border:2px solid #3a5976;\n"
"    border-radius:8px;	\n"
"}"));
        ch2Voffset = new QLabel(ch2Widget);
        ch2Voffset->setObjectName(QString::fromUtf8("ch2Voffset"));
        ch2Voffset->setGeometry(QRect(8, 48, 40, 16));
        QFont font;
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        ch2Voffset->setFont(font);
        ch2Voffset->setLayoutDirection(Qt::RightToLeft);
        ch2Voffset->setStyleSheet(QString::fromUtf8("QLabel{\n"
"color:black;\n"
"border-radius:0px;\n"
"border:0px solid black;\n"
"background-color:rgba(0,0,0,0);\n"
"font:14px;};"));
        ch2Voffset->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        channel2No = new QLabel(ch2Widget);
        channel2No->setObjectName(QString::fromUtf8("channel2No"));
        channel2No->setGeometry(QRect(7, 7, 101, 21));
        QFont font1;
        font1.setBold(true);
        font1.setItalic(false);
        font1.setWeight(75);
        channel2No->setFont(font1);
        channel2No->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"background-color: rgb(255, 0, 255);\n"
"color:black;\n"
"border:0px solid black;\n"
"border-radius:5px;\n"
"font:bold 14px;\n"
"}"));
        ch2VperDiv = new QLabel(ch2Widget);
        ch2VperDiv->setObjectName(QString::fromUtf8("ch2VperDiv"));
        ch2VperDiv->setGeometry(QRect(8, 28, 40, 19));
        QFont font2;
        font2.setFamily(QString::fromUtf8(",12"));
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(50);
        ch2VperDiv->setFont(font2);
        ch2VperDiv->setLayoutDirection(Qt::RightToLeft);
        ch2VperDiv->setStyleSheet(QString::fromUtf8("QLabel{\n"
"color:black;\n"
"border-radius:0px;\n"
"border:0px solid black;\n"
"background-color:rgba(0,0,0,0);\n"
"font:14px,bold;};"));
        ch2VperDiv->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        ch2labelVpD = new QLabel(ch2Widget);
        ch2labelVpD->setObjectName(QString::fromUtf8("ch2labelVpD"));
        ch2labelVpD->setGeometry(QRect(57, 28, 51, 19));
        ch2labelVpD->setFont(font);
        ch2labelVpD->setLayoutDirection(Qt::RightToLeft);
        ch2labelVpD->setStyleSheet(QString::fromUtf8("QLabel{\n"
"color:black;\n"
"border-radius:0px;\n"
"border:0px solid black;\n"
"background-color:rgba(0,0,0,0);\n"
"font:14px;};"));
        ch2labelVpD->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        ch2lblOffset = new QLabel(ch2Widget);
        ch2lblOffset->setObjectName(QString::fromUtf8("ch2lblOffset"));
        ch2lblOffset->setGeometry(QRect(60, 46, 51, 19));
        ch2lblOffset->setFont(font);
        ch2lblOffset->setLayoutDirection(Qt::RightToLeft);
        ch2lblOffset->setStyleSheet(QString::fromUtf8("QLabel{\n"
"color:black;\n"
"border-radius:0px;\n"
"border:0px solid black;\n"
"background-color:rgba(0,0,0,0);\n"
"font:14px;};"));
        ch2lblOffset->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        ch2Coupling = new QLabel(ch2Widget);
        ch2Coupling->setObjectName(QString::fromUtf8("ch2Coupling"));
        ch2Coupling->setGeometry(QRect(56, 10, 51, 16));
        ch2Coupling->setFont(font1);
        ch2Coupling->setStyleSheet(QString::fromUtf8("QLabel{color:white;border-radius:4px;border:0px solid black;background-color:black;font:bold 14px;}"));
        lblCH2DelX = new QLabel(ch2Widget);
        lblCH2DelX->setObjectName(QString::fromUtf8("lblCH2DelX"));
        lblCH2DelX->setGeometry(QRect(6, 61, 41, 19));
        lblCH2DelX->setFont(font);
        lblCH2DelX->setLayoutDirection(Qt::LeftToRight);
        lblCH2DelX->setStyleSheet(QString::fromUtf8("QLabel{\n"
"color:black;\n"
"border-radius:0px;\n"
"border:0px solid black;\n"
"background-color:rgba(0,0,0,0);\n"
"font:14px;};"));
        lblCH2DelX->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lblCH2DelValue = new QLabel(ch2Widget);
        lblCH2DelValue->setObjectName(QString::fromUtf8("lblCH2DelValue"));
        lblCH2DelValue->setGeometry(QRect(49, 61, 61, 20));
        lblCH2DelValue->setFont(font2);
        lblCH2DelValue->setLayoutDirection(Qt::LeftToRight);
        lblCH2DelValue->setStyleSheet(QString::fromUtf8("QLabel{\n"
"color:white;\n"
"border-radius:0px;\n"
"border:0px solid black;\n"
"background-color:rgba(0,0,0,0);\n"
"font:14px,bold;};"));
        lblCH2DelValue->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        CH1widget = new QWidget(centralWidget);
        CH1widget->setObjectName(QString::fromUtf8("CH1widget"));
        CH1widget->setGeometry(QRect(7, 520, 115, 80));
        CH1widget->setStyleSheet(QString::fromUtf8("QWidget{\n"
"	background-color: rgb(143, 143, 142);\n"
"	border:2px solid #3a5976;\n"
"    border-radius:8px;	\n"
"}\n"
""));
        ch1Coupling = new QLabel(CH1widget);
        ch1Coupling->setObjectName(QString::fromUtf8("ch1Coupling"));
        ch1Coupling->setGeometry(QRect(51, 9, 51, 16));
        ch1Coupling->setFont(font1);
        ch1Coupling->setStyleSheet(QString::fromUtf8("QLabel{color:white;border-radius:4px;border:0px solid black;background-color:black;font:bold 14px;}"));
        channel1No = new QLabel(CH1widget);
        channel1No->setObjectName(QString::fromUtf8("channel1No"));
        channel1No->setGeometry(QRect(6, 6, 101, 21));
        channel1No->setFont(font1);
        channel1No->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	background-color: rgb(255, 255, 0);\n"
"color:black;\n"
"border:0px solid black;\n"
"border-radius:5px;\n"
"font:bold 14px;\n"
"}"));
        ch1VperDiv = new QLabel(CH1widget);
        ch1VperDiv->setObjectName(QString::fromUtf8("ch1VperDiv"));
        ch1VperDiv->setGeometry(QRect(12, 30, 40, 20));
        ch1VperDiv->setFont(font2);
        ch1VperDiv->setLayoutDirection(Qt::RightToLeft);
        ch1VperDiv->setStyleSheet(QString::fromUtf8("QLabel{\n"
"color:black;\n"
"border-radius:0px;\n"
"border:0px solid black;\n"
"background-color:rgba(0,0,0,0);\n"
"font:14px,bold;\n"
"};"));
        ch1VperDiv->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        ch1Voffset = new QLabel(CH1widget);
        ch1Voffset->setObjectName(QString::fromUtf8("ch1Voffset"));
        ch1Voffset->setGeometry(QRect(12, 50, 40, 16));
        ch1Voffset->setFont(font);
        ch1Voffset->setLayoutDirection(Qt::RightToLeft);
        ch1Voffset->setStyleSheet(QString::fromUtf8("QLabel{\n"
"color:black;\n"
"border-radius:0px;\n"
"border:0px solid black;\n"
"background-color:rgba(0,0,0,0);\n"
"font:14px;};"));
        ch1Voffset->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        ch1labelVpD = new QLabel(CH1widget);
        ch1labelVpD->setObjectName(QString::fromUtf8("ch1labelVpD"));
        ch1labelVpD->setGeometry(QRect(58, 30, 51, 19));
        ch1labelVpD->setFont(font);
        ch1labelVpD->setLayoutDirection(Qt::RightToLeft);
        ch1labelVpD->setStyleSheet(QString::fromUtf8("QLabel{\n"
"color:black;\n"
"border-radius:0px;\n"
"border:0px solid black;\n"
"background-color:rgba(0,0,0,0);\n"
"font:14px;};"));
        ch1labelVpD->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        ch1lblOffset = new QLabel(CH1widget);
        ch1lblOffset->setObjectName(QString::fromUtf8("ch1lblOffset"));
        ch1lblOffset->setGeometry(QRect(58, 48, 51, 19));
        ch1lblOffset->setFont(font);
        ch1lblOffset->setLayoutDirection(Qt::RightToLeft);
        ch1lblOffset->setStyleSheet(QString::fromUtf8("QLabel{\n"
"color:black;\n"
"border-radius:0px;\n"
"border:0px solid black;\n"
"background-color:rgba(0,0,0,0);\n"
"font:14px;};"));
        ch1lblOffset->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lblCH1DelX = new QLabel(CH1widget);
        lblCH1DelX->setObjectName(QString::fromUtf8("lblCH1DelX"));
        lblCH1DelX->setGeometry(QRect(6, 61, 41, 19));
        lblCH1DelX->setFont(font);
        lblCH1DelX->setLayoutDirection(Qt::LeftToRight);
        lblCH1DelX->setStyleSheet(QString::fromUtf8("QLabel{\n"
"color:black;\n"
"border-radius:0px;\n"
"border:0px solid black;\n"
"background-color:rgba(0,0,0,0);\n"
"font:14px;};"));
        lblCH1DelX->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lblCH1DelValue = new QLabel(CH1widget);
        lblCH1DelValue->setObjectName(QString::fromUtf8("lblCH1DelValue"));
        lblCH1DelValue->setGeometry(QRect(46, 63, 61, 20));
        lblCH1DelValue->setFont(font2);
        lblCH1DelValue->setLayoutDirection(Qt::LeftToRight);
        lblCH1DelValue->setStyleSheet(QString::fromUtf8("QLabel{\n"
"color:black;\n"
"border-radius:0px;\n"
"border:0px solid black;\n"
"background-color:rgba(0,0,0,0);\n"
"font:14px,bold;};"));
        lblCH1DelValue->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        topFrame = new QFrame(centralWidget);
        topFrame->setObjectName(QString::fromUtf8("topFrame"));
        topFrame->setGeometry(QRect(700, 50, 100, 541));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(topFrame->sizePolicy().hasHeightForWidth());
        topFrame->setSizePolicy(sizePolicy);
        topFrame->setStyleSheet(QString::fromUtf8("#topFrame {\n"
"border: none;\n"
"background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"stop: 0 #a6a6a6, stop: 0.08 #7f7f7f,\n"
"stop: 0.39999 #717171, stop: 0.4 #626262,\n"
"stop: 0.9 #4c4c4c, stop: 1 #333333);\n"
"}\n"
"\n"
"#topFrame QPushButton {\n"
"color: #333;\n"
"border: 0px solid #555;\n"
"border-radius: 0px;\n"
"padding: 5px;\n"
"background: qradialgradient(cx: 0.3, cy: -0.4,\n"
"fx: 0.3, fy: -0.4,\n"
"radius: 1.35, stop: 0 #fff, stop: 1 #888);\n"
"min-width: 80px;\n"
"} \n"
"#topFrame QPushButton:hover {\n"
"background: qradialgradient(cx: 0.3, cy: -0.4,\n"
"fx: 0.3, fy: -0.4,\n"
"radius: 1.35, stop: 0 #fff, stop: 1 #bbb);\n"
"}\n"
"#topFrame QPushButton:pressed {\n"
"background: qradialgradient(cx: 0.4, cy: -0.1,\n"
"fx: 0.4, fy: -0.1,\n"
"radius: 1.35, stop: 0 #fff, stop: 1 #ddd);\n"
"}"));
        topFrame->setFrameShape(QFrame::StyledPanel);
        topFrame->setFrameShadow(QFrame::Raised);
        rootItem = new QToolButton(centralWidget);
        rootItem->setObjectName(QString::fromUtf8("rootItem"));
        rootItem->setGeometry(QRect(700, 20, 100, 30));
        QFont font3;
        font3.setBold(true);
        font3.setWeight(75);
        rootItem->setFont(font3);
        rootItem->setLayoutDirection(Qt::LeftToRight);
        rootItem->setStyleSheet(QString::fromUtf8("QToolButton\n"
"{\n"
"color:black;\n"
"background-color: rgb(255, 255, 0);\n"
"	border:0px solid #3a5976;\n"
"    border-radius:0px;	\n"
"}"));
        TriggerWidget = new QWidget(centralWidget);
        TriggerWidget->setObjectName(QString::fromUtf8("TriggerWidget"));
        TriggerWidget->setGeometry(QRect(573, 526, 116, 72));
        TriggerWidget->setStyleSheet(QString::fromUtf8("QWidget{\n"
"	background-color: rgb(143, 143, 142);\n"
"	border:2px solid #3a5976;\n"
"    border-radius:8px;	\n"
"}\n"
""));
        ch1Coupling_2 = new QLabel(TriggerWidget);
        ch1Coupling_2->setObjectName(QString::fromUtf8("ch1Coupling_2"));
        ch1Coupling_2->setGeometry(QRect(51, 9, 51, 16));
        ch1Coupling_2->setFont(font1);
        ch1Coupling_2->setStyleSheet(QString::fromUtf8("QLabel{color:white;border-radius:4px;border:0px solid black;background-color:black;font:bold 14px;}"));
        TriggerTitle = new QLabel(TriggerWidget);
        TriggerTitle->setObjectName(QString::fromUtf8("TriggerTitle"));
        TriggerTitle->setGeometry(QRect(6, 6, 101, 21));
        TriggerTitle->setFont(font1);
        TriggerTitle->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	background-color: rgb(255, 255, 255);\n"
"color:black;\n"
"border:0px solid black;\n"
"border-radius:5px;\n"
"font:bold 14px;\n"
"}"));
        lblHort = new QLabel(TriggerWidget);
        lblHort->setObjectName(QString::fromUtf8("lblHort"));
        lblHort->setGeometry(QRect(6, 30, 41, 20));
        lblHort->setFont(font2);
        lblHort->setLayoutDirection(Qt::RightToLeft);
        lblHort->setStyleSheet(QString::fromUtf8("QLabel{\n"
"color:white;\n"
"border-radius:0px;\n"
"border:0px solid black;\n"
"background-color:rgba(0,0,0,0);\n"
"font:14px,bold;};"));
        lblHort->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lblVertT = new QLabel(TriggerWidget);
        lblVertT->setObjectName(QString::fromUtf8("lblVertT"));
        lblVertT->setGeometry(QRect(6, 50, 41, 20));
        lblVertT->setFont(font2);
        lblVertT->setLayoutDirection(Qt::RightToLeft);
        lblVertT->setStyleSheet(QString::fromUtf8("QLabel{\n"
"color:white;\n"
"border-radius:0px;\n"
"border:0px solid black;\n"
"background-color:rgba(0,0,0,0);\n"
"font:14px,bold;};"));
        lblVertT->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lblHorTValue = new QLabel(TriggerWidget);
        lblHorTValue->setObjectName(QString::fromUtf8("lblHorTValue"));
        lblHorTValue->setGeometry(QRect(50, 30, 61, 20));
        lblHorTValue->setFont(font2);
        lblHorTValue->setLayoutDirection(Qt::LeftToRight);
        lblHorTValue->setStyleSheet(QString::fromUtf8("QLabel{\n"
"color:white;\n"
"border-radius:0px;\n"
"border:0px solid black;\n"
"background-color:rgba(0,0,0,0);\n"
"font:14px,bold;};"));
        lblHorTValue->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lblVertTValue = new QLabel(TriggerWidget);
        lblVertTValue->setObjectName(QString::fromUtf8("lblVertTValue"));
        lblVertTValue->setGeometry(QRect(50, 50, 61, 20));
        lblVertTValue->setFont(font2);
        lblVertTValue->setLayoutDirection(Qt::LeftToRight);
        lblVertTValue->setStyleSheet(QString::fromUtf8("QLabel{\n"
"color:white;\n"
"border-radius:0px;\n"
"border:0px solid black;\n"
"background-color:rgba(0,0,0,0);\n"
"font:14px,bold;};"));
        lblVertTValue->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(610, 474, 93, 31));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	background-color: rgb(143, 143, 142);\n"
"	border:2px solid #3a5976;\n"
"    border-radius:8px;	\n"
"}"));
        Timebase = new QWidget(centralWidget);
        Timebase->setObjectName(QString::fromUtf8("Timebase"));
        Timebase->setGeometry(QRect(446, 506, 116, 91));
        Timebase->setStyleSheet(QString::fromUtf8("QWidget{\n"
"	background-color: rgb(143, 143, 142);\n"
"	border:2px solid #3a5976;\n"
"    border-radius:8px;	\n"
"}\n"
""));
        ch1Coupling_3 = new QLabel(Timebase);
        ch1Coupling_3->setObjectName(QString::fromUtf8("ch1Coupling_3"));
        ch1Coupling_3->setGeometry(QRect(51, 9, 51, 16));
        ch1Coupling_3->setFont(font1);
        ch1Coupling_3->setStyleSheet(QString::fromUtf8("QLabel{color:white;border-radius:4px;border:0px solid black;background-color:black;font:bold 14px;}"));
        TimebaseTitle = new QLabel(Timebase);
        TimebaseTitle->setObjectName(QString::fromUtf8("TimebaseTitle"));
        TimebaseTitle->setGeometry(QRect(6, 6, 101, 21));
        TimebaseTitle->setFont(font1);
        TimebaseTitle->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	background-color: rgb(255, 255, 255);\n"
"color:black;\n"
"border:0px solid black;\n"
"border-radius:5px;\n"
"font:bold 14px;\n"
"}"));
        labelTimePerDiv = new QLabel(Timebase);
        labelTimePerDiv->setObjectName(QString::fromUtf8("labelTimePerDiv"));
        labelTimePerDiv->setGeometry(QRect(5, 27, 71, 20));
        labelTimePerDiv->setFont(font2);
        labelTimePerDiv->setLayoutDirection(Qt::RightToLeft);
        labelTimePerDiv->setStyleSheet(QString::fromUtf8("QLabel{\n"
"color:white;\n"
"border-radius:0px;\n"
"border:0px solid black;\n"
"background-color:rgba(0,0,0,0);\n"
"font:14px,bold;};"));
        labelTimePerDiv->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lblMemory = new QLabel(Timebase);
        lblMemory->setObjectName(QString::fromUtf8("lblMemory"));
        lblMemory->setGeometry(QRect(6, 48, 71, 19));
        lblMemory->setFont(font);
        lblMemory->setLayoutDirection(Qt::LeftToRight);
        lblMemory->setStyleSheet(QString::fromUtf8("QLabel{\n"
"color:white;\n"
"border-radius:0px;\n"
"border:0px solid black;\n"
"background-color:rgba(0,0,0,0);\n"
"font:14px;};"));
        lblMemory->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lblSamplingRate = new QLabel(Timebase);
        lblSamplingRate->setObjectName(QString::fromUtf8("lblSamplingRate"));
        lblSamplingRate->setGeometry(QRect(6, 68, 81, 20));
        lblSamplingRate->setFont(font);
        lblSamplingRate->setLayoutDirection(Qt::LeftToRight);
        lblSamplingRate->setStyleSheet(QString::fromUtf8("QLabel{\n"
"color:white;\n"
"border-radius:0px;\n"
"border:0px solid black;\n"
"background-color:rgba(0,0,0,0);\n"
"font:14px;};"));
        lblSamplingRate->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        butRUNSTOP = new QPushButton(centralWidget);
        butRUNSTOP->setObjectName(QString::fromUtf8("butRUNSTOP"));
        butRUNSTOP->setGeometry(QRect(517, 474, 93, 31));
        butRUNSTOP->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	background-color: rgb(143, 143, 142);\n"
"	border:2px solid #3a5976;\n"
"    border-radius:8px;	\n"
"}"));
        grpTimeDiv = new QGroupBox(centralWidget);
        grpTimeDiv->setObjectName(QString::fromUtf8("grpTimeDiv"));
        grpTimeDiv->setGeometry(QRect(190, 316, 170, 170));
        grpTimeDiv->setCursor(QCursor(Qt::ArrowCursor));
        grpTimeDiv->setFocusPolicy(Qt::NoFocus);
        grpTimeDiv->setStyleSheet(QString::fromUtf8("QGroupBox\n"
"{\n"
"	background-color: rgb(108, 108, 107);\n"
"	color:white;\n"
"	font:bold\n"
"}"));
        timebaseDialWheel = new QDial(grpTimeDiv);
        timebaseDialWheel->setObjectName(QString::fromUtf8("timebaseDialWheel"));
        timebaseDialWheel->setGeometry(QRect(10, 22, 141, 151));
        timebaseDialWheel->setStyleSheet(QString::fromUtf8("QDial {\n"
"border: none;\n"
"background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"stop: 0 #a6a6a6, stop: 0.08 #878789,\n"
"stop: 0.39999 #212122, stop: 0.4 #626262,\n"
"stop: 0.9 #4c4c4c, stop: 1 #333333);\n"
"}"));
        timebaseDialWheel->setMinimum(1);
        timebaseDialWheel->setMaximum(30);
        timebaseDialWheel->setPageStep(2);
        timebaseDialWheel->setValue(1);
        timebaseDialWheel->setOrientation(Qt::Horizontal);
        timebaseDialWheel->setInvertedAppearance(false);
        timebaseDialWheel->setInvertedControls(false);
        timebaseDialWheel->setWrapping(true);
        timebaseDialWheel->setNotchTarget(9);
        timebaseDialWheel->setNotchesVisible(false);
        chTperDiv = new QLabel(grpTimeDiv);
        chTperDiv->setObjectName(QString::fromUtf8("chTperDiv"));
        chTperDiv->setGeometry(QRect(89, 16, 81, 20));
        chTperDiv->setStyleSheet(QString::fromUtf8("QLabel{\n"
"color:white;\n"
"border-radius:0px;\n"
"border:0px solid black;\n"
"background-color:rgba(0,0,0,0);\n"
"font:12px,bold;\n"
"};"));
        label = new QLabel(grpTimeDiv);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(21, 138, 21, 20));
        label->setFont(font3);
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(108, 108, 107);"));
        label_2 = new QLabel(grpTimeDiv);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(125, 137, 21, 20));
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(108, 108, 107);"));
        grpVoltDiv = new QGroupBox(centralWidget);
        grpVoltDiv->setObjectName(QString::fromUtf8("grpVoltDiv"));
        grpVoltDiv->setGeometry(QRect(-1, 316, 191, 170));
        grpVoltDiv->setCursor(QCursor(Qt::ArrowCursor));
        grpVoltDiv->setFocusPolicy(Qt::NoFocus);
        grpVoltDiv->setStyleSheet(QString::fromUtf8("QGroupBox\n"
"{\n"
"	background-color: rgb(108, 108, 107);\n"
"	color:white;\n"
"	font:bold;\n"
"}"));
        VoltageDialWheel = new QDial(grpVoltDiv);
        VoltageDialWheel->setObjectName(QString::fromUtf8("VoltageDialWheel"));
        VoltageDialWheel->setGeometry(QRect(7, 20, 141, 151));
        VoltageDialWheel->setStyleSheet(QString::fromUtf8("QDial {\n"
"border: none;\n"
"background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"stop: 0 #a6a6a6, stop: 0.08 #878789,\n"
"stop: 0.39999 #212122, stop: 0.4 #626262,\n"
"stop: 0.9 #4c4c4c, stop: 1 #333333);\n"
"}"));
        VoltageDialWheel->setMinimum(1);
        VoltageDialWheel->setMaximum(9);
        VoltageDialWheel->setPageStep(2);
        VoltageDialWheel->setValue(1);
        VoltageDialWheel->setOrientation(Qt::Horizontal);
        VoltageDialWheel->setInvertedAppearance(false);
        VoltageDialWheel->setInvertedControls(false);
        VoltageDialWheel->setWrapping(true);
        VoltageDialWheel->setNotchTarget(9);
        VoltageDialWheel->setNotchesVisible(true);
        chlabel = new QLabel(grpVoltDiv);
        chlabel->setObjectName(QString::fromUtf8("chlabel"));
        chlabel->setGeometry(QRect(10, 20, 41, 20));
        chlabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"color:yellow;\n"
"border-radius:0px;\n"
"border:0px solid black;\n"
"background-color:rgba(0,0,0,0);\n"
"font:14px,bold;\n"
"};"));
        chVperDiv = new QLabel(grpVoltDiv);
        chVperDiv->setObjectName(QString::fromUtf8("chVperDiv"));
        chVperDiv->setGeometry(QRect(69, 14, 81, 20));
        chVperDiv->setStyleSheet(QString::fromUtf8("QLabel{\n"
"color:white;\n"
"border-radius:0px;\n"
"border:0px solid black;\n"
"background-color:rgba(0,0,0,0);\n"
"font:12px,bold;\n"
"};"));
        chVperDiv_2 = new QLabel(grpVoltDiv);
        chVperDiv_2->setObjectName(QString::fromUtf8("chVperDiv_2"));
        chVperDiv_2->setGeometry(QRect(141, 145, 20, 20));
        chVperDiv_2->setStyleSheet(QString::fromUtf8("QLabel{\n"
"color:white;\n"
"border-radius:0px;\n"
"border:0px solid black;\n"
"background-color:rgba(0,0,0,0);\n"
"font:12px,bold;\n"
"};"));
        chk1ShowTrace = new QCheckBox(grpVoltDiv);
        chk1ShowTrace->setObjectName(QString::fromUtf8("chk1ShowTrace"));
        chk1ShowTrace->setGeometry(QRect(116, 147, 71, 25));
        chk1ShowTrace->setStyleSheet(QString::fromUtf8("QCheckBox\n"
"{\n"
"background-color: rgb(108, 108, 107);\n"
"	color:white;\n"
"	font:bold;\n"
"}"));
        chk2ShowTrace = new QCheckBox(grpVoltDiv);
        chk2ShowTrace->setObjectName(QString::fromUtf8("chk2ShowTrace"));
        chk2ShowTrace->setGeometry(QRect(117, 147, 61, 25));
        chk2ShowTrace->setStyleSheet(QString::fromUtf8("QCheckBox\n"
"{\n"
"background-color: rgb(108, 108, 107);\n"
"	color:white;\n"
"	font:bold;\n"
"}"));
        label_3 = new QLabel(grpVoltDiv);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(8, 133, 31, 20));
        label_3->setFont(font3);
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(108, 108, 107);"));
        label_4 = new QLabel(grpVoltDiv);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(122, 131, 21, 20));
        label_4->setFont(font3);
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(108, 108, 107);"));
        butOffset_plus = new QPushButton(grpVoltDiv);
        butOffset_plus->setObjectName(QString::fromUtf8("butOffset_plus"));
        butOffset_plus->setGeometry(QRect(145, 49, 41, 41));
        butOffset_plus->setFocusPolicy(Qt::NoFocus);
        butOffset_plus->setStyleSheet(QString::fromUtf8("background-color: rgb(88, 88, 87);"));
        butOffset_minus = new QPushButton(grpVoltDiv);
        butOffset_minus->setObjectName(QString::fromUtf8("butOffset_minus"));
        butOffset_minus->setGeometry(QRect(145, 109, 41, 41));
        butOffset_minus->setFocusPolicy(Qt::NoFocus);
        butOffset_minus->setStyleSheet(QString::fromUtf8("background-color: rgb(88, 88, 87);"));
        label_5 = new QLabel(grpVoltDiv);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(143, 28, 41, 20));
        label_5->setFont(font3);
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(108, 108, 107);"));
        butOffset_zero = new QPushButton(grpVoltDiv);
        butOffset_zero->setObjectName(QString::fromUtf8("butOffset_zero"));
        butOffset_zero->setGeometry(QRect(145, 90, 41, 21));
        butOffset_zero->setFocusPolicy(Qt::NoFocus);
        butOffset_zero->setStyleSheet(QString::fromUtf8("background-color: rgb(88, 88, 87);"));
        grpTriggers = new QGroupBox(centralWidget);
        grpTriggers->setObjectName(QString::fromUtf8("grpTriggers"));
        grpTriggers->setGeometry(QRect(460, 330, 241, 131));
        grpTriggers->setCursor(QCursor(Qt::ArrowCursor));
        grpTriggers->setFocusPolicy(Qt::NoFocus);
        grpTriggers->setStyleSheet(QString::fromUtf8("QGroupBox\n"
"{\n"
"	background-color: rgb(108, 108, 107);\n"
"	color:white;\n"
"	font:bold\n"
"}"));
        triggerWheel = new QDial(grpTriggers);
        triggerWheel->setObjectName(QString::fromUtf8("triggerWheel"));
        triggerWheel->setGeometry(QRect(10, 40, 141, 71));
        triggerWheel->setStyleSheet(QString::fromUtf8("QDial {\n"
"border: none;\n"
"background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"stop: 0 #a6a6a6, stop: 0.08 #878789,\n"
"stop: 0.39999 #212122, stop: 0.4 #626262,\n"
"stop: 0.9 #4c4c4c, stop: 1 #333333);\n"
"}"));
        triggerWheel->setMinimum(1);
        triggerWheel->setMaximum(30);
        triggerWheel->setPageStep(2);
        triggerWheel->setValue(1);
        triggerWheel->setOrientation(Qt::Horizontal);
        triggerWheel->setInvertedAppearance(false);
        triggerWheel->setInvertedControls(false);
        triggerWheel->setWrapping(true);
        triggerWheel->setNotchTarget(9);
        triggerWheel->setNotchesVisible(false);
        chTperDiv_2 = new QLabel(grpTriggers);
        chTperDiv_2->setObjectName(QString::fromUtf8("chTperDiv_2"));
        chTperDiv_2->setGeometry(QRect(77, 16, 81, 20));
        chTperDiv_2->setStyleSheet(QString::fromUtf8("QLabel{\n"
"color:white;\n"
"border-radius:0px;\n"
"border:0px solid black;\n"
"background-color:rgba(0,0,0,0);\n"
"font:12px,bold;\n"
"};"));
        dblHorizontalTrigger = new QDoubleSpinBox(grpTriggers);
        dblHorizontalTrigger->setObjectName(QString::fromUtf8("dblHorizontalTrigger"));
        dblHorizontalTrigger->setGeometry(QRect(8, 49, 101, 71));
        dblHorizontalTrigger->setStyleSheet(QString::fromUtf8("QDoubleSpinBox\n"
"{\n"
" border: 2px solid  white; \n"
"border-radius: 5px; \n"
"background-color: rgb(108, 108, 107);\n"
"height: 50px; \n"
"width: 50px; \n"
"}\n"
"QDoubleSpinBox::up-arrow \n"
"{\n"
" border-left: 15px solid none;\n"
"border-right: 15px solid none; \n"
"border-bottom: 15px solid blue;\n"
"width: 0px; \n"
"height: 0px; \n"
"}\n"
"QDoubleSpinBox::up-button \n"
"{\n"
" min-width: 45px; \n"
"min-height: 35px; \n"
"background-color: rgb(89, 89, 87); \n"
"}\n"
"\n"
"QDoubleSpinBox::up-button:hover \n"
"{ min-width: 45px; \n"
"min-height: 35px; \n"
"background-color:  rgb(89, 89, 87);\n"
"}\n"
"\n"
"QDoubleSpinBox::up-arrow:hover \n"
"{ border-left: 15px solid none; \n"
"border-right: 15px solid none;\n"
"border-bottom: 15px solid black; \n"
"width: 0px; height: 0px; \n"
"}\n"
"QDoubleSpinBox::down-arrow \n"
"{ border-left: 15px solid none;\n"
"border-right: 15px solid none; \n"
"border-top: 15px solid blue; \n"
"width: 0px; height: 0px; }\n"
"\n"
"QDoubleSpinBox::down-button\n"
"{\n"
" min-width:"
                        "45px; \n"
"min-height: 35px; \n"
"background-color: rgb(89, 89, 87); \n"
"}\n"
"\n"
"QDoubleSpinBox::down-button:hover \n"
"{ min-width: 45px; \n"
"min-height: 35px; \n"
"background-color:  rgb(89, 89, 87);\n"
"}\n"
"\n"
"QDoubleSpinBox::down-arrow:hover\n"
"{ border-left: 15px solid none;\n"
"border-right: 15px solid none; border-top: 15px solid black; width: 0px; height: 0px; }\n"
"\357\277\274"));
        dblVerticalTrigger = new QDoubleSpinBox(grpTriggers);
        dblVerticalTrigger->setObjectName(QString::fromUtf8("dblVerticalTrigger"));
        dblVerticalTrigger->setGeometry(QRect(130, 50, 101, 71));
        dblVerticalTrigger->setStyleSheet(QString::fromUtf8("QDoubleSpinBox\n"
"{\n"
" border: 2px solid  white; \n"
"border-radius: 5px; \n"
"background-color: rgb(108, 108, 107);\n"
"height: 50px; \n"
"width: 50px; \n"
"}\n"
"QDoubleSpinBox::up-arrow \n"
"{\n"
" border-left: 15px solid none;\n"
"border-right: 15px solid none; \n"
"border-bottom: 15px solid blue;\n"
"width: 0px; \n"
"height: 0px; \n"
"}\n"
"QDoubleSpinBox::up-button \n"
"{\n"
" min-width: 45px; \n"
"min-height: 35px; \n"
"background-color: rgb(89, 89, 87); \n"
"}\n"
"\n"
"QDoubleSpinBox::up-button:hover \n"
"{ min-width: 45px; \n"
"min-height: 35px; \n"
"background-color:  rgb(89, 89, 87);\n"
"}\n"
"\n"
"QDoubleSpinBox::up-arrow:hover \n"
"{ border-left: 15px solid none; \n"
"border-right: 15px solid none;\n"
"border-bottom: 15px solid black; \n"
"width: 0px; height: 0px; \n"
"}\n"
"QDoubleSpinBox::down-arrow \n"
"{ border-left: 15px solid none;\n"
"border-right: 15px solid none; \n"
"border-top: 15px solid blue; \n"
"width: 0px; height: 0px; }\n"
"\n"
"QDoubleSpinBox::down-button\n"
"{\n"
" min-width:"
                        "45px; \n"
"min-height: 35px; \n"
"background-color: rgb(89, 89, 87); \n"
"}\n"
"\n"
"QDoubleSpinBox::down-button:hover \n"
"{ min-width: 45px; \n"
"min-height: 35px; \n"
"background-color:  rgb(89, 89, 87);\n"
"}\n"
"\n"
"QDoubleSpinBox::down-arrow:hover\n"
"{ border-left: 15px solid none;\n"
"border-right: 15px solid none; \n"
"border-top: 15px solid black; \n"
"width: 0px; height: 0px;\n"
" }\n"
"\357\277\274"));
        line = new QFrame(grpTriggers);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(110, 12, 20, 118));
        line->setStyleSheet(QString::fromUtf8("background-color: rgb(108, 108, 107);"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        TimebaseTitle_2 = new QLabel(grpTriggers);
        TimebaseTitle_2->setObjectName(QString::fromUtf8("TimebaseTitle_2"));
        TimebaseTitle_2->setGeometry(QRect(10, 20, 101, 21));
        TimebaseTitle_2->setFont(font1);
        TimebaseTitle_2->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"background-color: rgb(88, 88, 87);\n"
"color:black;\n"
"border:0px solid black;\n"
"border-radius:5px;\n"
"font:bold 14px;\n"
"}"));
        TimebaseTitle_3 = new QLabel(grpTriggers);
        TimebaseTitle_3->setObjectName(QString::fromUtf8("TimebaseTitle_3"));
        TimebaseTitle_3->setGeometry(QRect(130, 20, 101, 21));
        TimebaseTitle_3->setFont(font1);
        TimebaseTitle_3->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"background-color: rgb(88, 88, 87);\n"
"color:black;\n"
"border:0px solid black;\n"
"border-radius:5px;\n"
"font:bold 14px;\n"
"}"));
        Cursors = new QWidget(centralWidget);
        Cursors->setObjectName(QString::fromUtf8("Cursors"));
        Cursors->setGeometry(QRect(260, 527, 171, 72));
        Cursors->setStyleSheet(QString::fromUtf8("QWidget{\n"
"	background-color: rgb(143, 143, 142);\n"
"	border:2px solid #3a5976;\n"
"    border-radius:8px;	\n"
"}\n"
""));
        ch1Coupling_4 = new QLabel(Cursors);
        ch1Coupling_4->setObjectName(QString::fromUtf8("ch1Coupling_4"));
        ch1Coupling_4->setGeometry(QRect(51, 9, 51, 16));
        ch1Coupling_4->setFont(font1);
        ch1Coupling_4->setStyleSheet(QString::fromUtf8("QLabel{color:white;border-radius:4px;border:0px solid black;background-color:black;font:bold 14px;}"));
        cursorsTitle = new QLabel(Cursors);
        cursorsTitle->setObjectName(QString::fromUtf8("cursorsTitle"));
        cursorsTitle->setGeometry(QRect(5, 6, 161, 21));
        cursorsTitle->setFont(font1);
        cursorsTitle->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	background-color: rgb(255, 255, 255);\n"
"color:black;\n"
"border:0px solid black;\n"
"border-radius:5px;\n"
"font:bold 14px;\n"
"}"));
        lblX1 = new QLabel(Cursors);
        lblX1->setObjectName(QString::fromUtf8("lblX1"));
        lblX1->setGeometry(QRect(6, 30, 21, 19));
        lblX1->setFont(font);
        lblX1->setLayoutDirection(Qt::LeftToRight);
        lblX1->setStyleSheet(QString::fromUtf8("QLabel{\n"
"color:black;\n"
"border-radius:0px;\n"
"border:0px solid black;\n"
"background-color:rgba(0,0,0,0);\n"
"font:14px;};"));
        lblX1->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lblX1Value = new QLabel(Cursors);
        lblX1Value->setObjectName(QString::fromUtf8("lblX1Value"));
        lblX1Value->setGeometry(QRect(18, 30, 61, 20));
        lblX1Value->setFont(font2);
        lblX1Value->setLayoutDirection(Qt::RightToLeft);
        lblX1Value->setStyleSheet(QString::fromUtf8("QLabel{\n"
"color:white;\n"
"border-radius:0px;\n"
"border:0px solid black;\n"
"background-color:rgba(0,0,0,0);\n"
"font:14px,bold;};"));
        lblX1Value->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lblX2 = new QLabel(Cursors);
        lblX2->setObjectName(QString::fromUtf8("lblX2"));
        lblX2->setGeometry(QRect(90, 31, 21, 19));
        lblX2->setFont(font);
        lblX2->setLayoutDirection(Qt::LeftToRight);
        lblX2->setStyleSheet(QString::fromUtf8("QLabel{\n"
"color:black;\n"
"border-radius:0px;\n"
"border:0px solid black;\n"
"background-color:rgba(0,0,0,0);\n"
"font:14px;};"));
        lblX2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lblX2Value = new QLabel(Cursors);
        lblX2Value->setObjectName(QString::fromUtf8("lblX2Value"));
        lblX2Value->setGeometry(QRect(100, 30, 61, 20));
        lblX2Value->setFont(font2);
        lblX2Value->setLayoutDirection(Qt::RightToLeft);
        lblX2Value->setStyleSheet(QString::fromUtf8("QLabel{\n"
"color:white;\n"
"border-radius:0px;\n"
"border:0px solid black;\n"
"background-color:rgba(0,0,0,0);\n"
"font:14px,bold;};"));
        lblX2Value->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lblY1 = new QLabel(Cursors);
        lblY1->setObjectName(QString::fromUtf8("lblY1"));
        lblY1->setGeometry(QRect(7, 50, 21, 19));
        lblY1->setFont(font);
        lblY1->setLayoutDirection(Qt::LeftToRight);
        lblY1->setStyleSheet(QString::fromUtf8("QLabel{\n"
"color:black;\n"
"border-radius:0px;\n"
"border:0px solid black;\n"
"background-color:rgba(0,0,0,0);\n"
"font:14px;};"));
        lblY1->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lblY1Value = new QLabel(Cursors);
        lblY1Value->setObjectName(QString::fromUtf8("lblY1Value"));
        lblY1Value->setGeometry(QRect(32, 50, 51, 20));
        lblY1Value->setFont(font2);
        lblY1Value->setLayoutDirection(Qt::LeftToRight);
        lblY1Value->setStyleSheet(QString::fromUtf8("QLabel{\n"
"color:white;\n"
"border-radius:0px;\n"
"border:0px solid black;\n"
"background-color:rgba(0,0,0,0);\n"
"font:14px,bold;};"));
        lblY1Value->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lblY2 = new QLabel(Cursors);
        lblY2->setObjectName(QString::fromUtf8("lblY2"));
        lblY2->setGeometry(QRect(90, 50, 21, 19));
        lblY2->setFont(font);
        lblY2->setLayoutDirection(Qt::LeftToRight);
        lblY2->setStyleSheet(QString::fromUtf8("QLabel{\n"
"color:black;\n"
"border-radius:0px;\n"
"border:0px solid black;\n"
"background-color:rgba(0,0,0,0);\n"
"font:14px;};"));
        lblY2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lblY2Value = new QLabel(Cursors);
        lblY2Value->setObjectName(QString::fromUtf8("lblY2Value"));
        lblY2Value->setGeometry(QRect(110, 49, 51, 20));
        lblY2Value->setFont(font2);
        lblY2Value->setLayoutDirection(Qt::LeftToRight);
        lblY2Value->setStyleSheet(QString::fromUtf8("QLabel{\n"
"color:white;\n"
"border-radius:0px;\n"
"border:0px solid black;\n"
"background-color:rgba(0,0,0,0);\n"
"font:14px,bold;};"));
        lblY2Value->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        grpCursors = new QGroupBox(centralWidget);
        grpCursors->setObjectName(QString::fromUtf8("grpCursors"));
        grpCursors->setGeometry(QRect(360, 330, 191, 131));
        grpCursors->setCursor(QCursor(Qt::ArrowCursor));
        grpCursors->setFocusPolicy(Qt::NoFocus);
        grpCursors->setStyleSheet(QString::fromUtf8("QGroupBox\n"
"{\n"
"	background-color: rgb(108, 108, 107);\n"
"	color:white;\n"
"	font:bold\n"
"}"));
        chTperDiv_3 = new QLabel(grpCursors);
        chTperDiv_3->setObjectName(QString::fromUtf8("chTperDiv_3"));
        chTperDiv_3->setGeometry(QRect(77, 16, 81, 20));
        chTperDiv_3->setStyleSheet(QString::fromUtf8("QLabel{\n"
"color:white;\n"
"border-radius:0px;\n"
"border:0px solid black;\n"
"background-color:rgba(0,0,0,0);\n"
"font:12px,bold;\n"
"};"));
        butUP = new QPushButton(grpCursors);
        butUP->setObjectName(QString::fromUtf8("butUP"));
        butUP->setGeometry(QRect(62, 18, 61, 51));
        butUP->setFocusPolicy(Qt::NoFocus);
        butUP->setStyleSheet(QString::fromUtf8("background-color: rgb(88, 88, 87);"));
        butDOWN = new QPushButton(grpCursors);
        butDOWN->setObjectName(QString::fromUtf8("butDOWN"));
        butDOWN->setGeometry(QRect(62, 69, 61, 51));
        butDOWN->setFocusPolicy(Qt::NoFocus);
        butDOWN->setStyleSheet(QString::fromUtf8("background-color: rgb(88, 88, 87);"));
        butLEFT = new QPushButton(grpCursors);
        butLEFT->setObjectName(QString::fromUtf8("butLEFT"));
        butLEFT->setGeometry(QRect(0, 44, 61, 51));
        butLEFT->setFocusPolicy(Qt::NoFocus);
        butLEFT->setStyleSheet(QString::fromUtf8("background-color: rgb(88, 88, 87);"));
        butRIGHT = new QPushButton(grpCursors);
        butRIGHT->setObjectName(QString::fromUtf8("butRIGHT"));
        butRIGHT->setGeometry(QRect(123, 45, 61, 51));
        butRIGHT->setFocusPolicy(Qt::NoFocus);
        butRIGHT->setStyleSheet(QString::fromUtf8("background-color: rgb(88, 88, 87);"));
        lblSysFreqValue = new QLabel(centralWidget);
        lblSysFreqValue->setObjectName(QString::fromUtf8("lblSysFreqValue"));
        lblSysFreqValue->setGeometry(QRect(152, 494, 81, 19));
        lblSysFreqValue->setFont(font);
        lblSysFreqValue->setLayoutDirection(Qt::LeftToRight);
        lblSysFreqValue->setStyleSheet(QString::fromUtf8("QLabel{\n"
"color:white;\n"
"border-radius:0px;\n"
"border:0px solid white;\n"
"background-color:rgba(0,0,0,0);\n"
"font:14px;};"));
        lblSysFreqValue->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        optAuto = new QRadioButton(centralWidget);
        optAuto->setObjectName(QString::fromUtf8("optAuto"));
        optAuto->setGeometry(QRect(2, 489, 71, 30));
        optAuto->setFocusPolicy(Qt::NoFocus);
        optAuto->setStyleSheet(QString::fromUtf8("QRadioButton\n"
"{\n"
"	background-color: rgb(88, 88, 87);\n"
"color:white\n"
"}\n"
" QRadioButton::indicator {\n"
"	\n"
"     width: 20px;\n"
"     height:20px;\n"
" }"));
        optNormal = new QRadioButton(centralWidget);
        optNormal->setObjectName(QString::fromUtf8("optNormal"));
        optNormal->setGeometry(QRect(69, 489, 81, 30));
        optNormal->setFocusPolicy(Qt::NoFocus);
        optNormal->setStyleSheet(QString::fromUtf8("QRadioButton\n"
"{\n"
"background-color: rgb(88, 88, 87);\n"
"color:white\n"
"}\n"
" QRadioButton::indicator {\n"
"	\n"
"     width: 20px;\n"
"     height:20px;\n"
" }"));
        lblDelY_2 = new QLabel(centralWidget);
        lblDelY_2->setObjectName(QString::fromUtf8("lblDelY_2"));
        lblDelY_2->setGeometry(QRect(238, 496, 51, 20));
        lblDelY_2->setFont(font);
        lblDelY_2->setLayoutDirection(Qt::LeftToRight);
        lblDelY_2->setStyleSheet(QString::fromUtf8("QLabel{\n"
"color:white;\n"
"border-radius:0px;\n"
"border:0px solid black;\n"
"background-color:rgba(0,0,0,0);\n"
"font:12px;};"));
        lblDelY_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lblDelFreqValue = new QLabel(centralWidget);
        lblDelFreqValue->setObjectName(QString::fromUtf8("lblDelFreqValue"));
        lblDelFreqValue->setGeometry(QRect(286, 497, 61, 20));
        lblDelFreqValue->setFont(font2);
        lblDelFreqValue->setLayoutDirection(Qt::LeftToRight);
        lblDelFreqValue->setStyleSheet(QString::fromUtf8("QLabel{\n"
"color:white;\n"
"border-radius:0px;\n"
"border:0px solid black;\n"
"background-color:rgba(0,0,0,0);\n"
"font:12px,bold;};"));
        lblDelFreqValue->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lblDelYValue = new QLabel(centralWidget);
        lblDelYValue->setObjectName(QString::fromUtf8("lblDelYValue"));
        lblDelYValue->setGeometry(QRect(392, 496, 51, 20));
        lblDelYValue->setFont(font2);
        lblDelYValue->setLayoutDirection(Qt::LeftToRight);
        lblDelYValue->setStyleSheet(QString::fromUtf8("QLabel{\n"
"color:white;\n"
"border-radius:0px;\n"
"border:0px solid black;\n"
"background-color:rgba(0,0,0,0);\n"
"font:14px,bold;};"));
        lblDelYValue->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lblDelY = new QLabel(centralWidget);
        lblDelY->setObjectName(QString::fromUtf8("lblDelY"));
        lblDelY->setGeometry(QRect(350, 497, 41, 19));
        lblDelY->setFont(font);
        lblDelY->setLayoutDirection(Qt::LeftToRight);
        lblDelY->setStyleSheet(QString::fromUtf8("QLabel{\n"
"color:white;\n"
"border-radius:0px;\n"
"border:0px solid black;\n"
"background-color:rgba(0,0,0,0);\n"
"font:14px;};"));
        lblDelY->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        ch2Voffset->setText(QApplication::translate("MainWindow", "0.00", 0, QApplication::UnicodeUTF8));
        channel2No->setText(QApplication::translate("MainWindow", "C2", 0, QApplication::UnicodeUTF8));
        ch2VperDiv->setText(QApplication::translate("MainWindow", "100.0", 0, QApplication::UnicodeUTF8));
        ch2labelVpD->setText(QApplication::translate("MainWindow", "mV/div", 0, QApplication::UnicodeUTF8));
        ch2lblOffset->setText(QApplication::translate("MainWindow", "mV off", 0, QApplication::UnicodeUTF8));
        ch2Coupling->setText(QApplication::translate("MainWindow", "DC1M", 0, QApplication::UnicodeUTF8));
        lblCH2DelX->setText(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Century Schoolbook L'; font-weight:400; font-style:normal;\">\n"
"<table style=\"-qt-table-type: root; margin-top:4px; margin-bottom:4px; margin-left:4px; margin-right:4px;\">\n"
"<tr>\n"
"<td style=\"border: none;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:11pt;\">delX:</span></p></td></tr></table></body></html>", 0, QApplication::UnicodeUTF8));
        lblCH2DelValue->setText(QString());
        ch1Coupling->setText(QApplication::translate("MainWindow", "DC1M", 0, QApplication::UnicodeUTF8));
        channel1No->setText(QApplication::translate("MainWindow", "C1", 0, QApplication::UnicodeUTF8));
        ch1VperDiv->setText(QApplication::translate("MainWindow", "100.0", 0, QApplication::UnicodeUTF8));
        ch1Voffset->setText(QApplication::translate("MainWindow", "0.00", 0, QApplication::UnicodeUTF8));
        ch1labelVpD->setText(QApplication::translate("MainWindow", "mV/div", 0, QApplication::UnicodeUTF8));
        ch1lblOffset->setText(QApplication::translate("MainWindow", "mV off", 0, QApplication::UnicodeUTF8));
        lblCH1DelX->setText(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Century Schoolbook L'; font-weight:400; font-style:normal;\">\n"
"<table style=\"-qt-table-type: root; margin-top:4px; margin-bottom:4px; margin-left:4px; margin-right:4px;\">\n"
"<tr>\n"
"<td style=\"border: none;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:11pt;\">delX:</span></p></td></tr></table></body></html>", 0, QApplication::UnicodeUTF8));
        lblCH1DelValue->setText(QString());
        rootItem->setText(QString());
        ch1Coupling_2->setText(QApplication::translate("MainWindow", "DC1M", 0, QApplication::UnicodeUTF8));
        TriggerTitle->setText(QApplication::translate("MainWindow", "Trigger", 0, QApplication::UnicodeUTF8));
        lblHort->setText(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:',12'; font-weight:400; font-style:normal;\">\n"
"<table border=\"0\" style=\"-qt-table-type: root; margin-top:4px; margin-bottom:4px; margin-left:4px; margin-right:4px;\">\n"
"<tr>\n"
"<td style=\"border: none;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Hor T:</p></td></tr></table></body></html>", 0, QApplication::UnicodeUTF8));
        lblVertT->setText(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:',12'; font-weight:400; font-style:normal;\">\n"
"<table border=\"0\" style=\"-qt-table-type: root; margin-top:4px; margin-bottom:4px; margin-left:4px; margin-right:4px;\">\n"
"<tr>\n"
"<td style=\"border: none;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Ver T:</p></td></tr></table></body></html>", 0, QApplication::UnicodeUTF8));
        lblHorTValue->setText(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:',12'; font-weight:400; font-style:normal;\">\n"
"<table border=\"0\" style=\"-qt-table-type: root; margin-top:4px; margin-bottom:4px; margin-left:4px; margin-right:4px;\">\n"
"<tr>\n"
"<td style=\"border: none;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"></p></td></tr></table></body></html>", 0, QApplication::UnicodeUTF8));
        lblVertTValue->setText(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:',12'; font-weight:400; font-style:normal;\">\n"
"<table border=\"0\" style=\"-qt-table-type: root; margin-top:4px; margin-bottom:4px; margin-left:4px; margin-right:4px;\">\n"
"<tr>\n"
"<td style=\"border: none;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"></p></td></tr></table></body></html>", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWindow", "Menu", 0, QApplication::UnicodeUTF8));
        ch1Coupling_3->setText(QApplication::translate("MainWindow", "DC1M", 0, QApplication::UnicodeUTF8));
        TimebaseTitle->setText(QApplication::translate("MainWindow", "Timebase", 0, QApplication::UnicodeUTF8));
        labelTimePerDiv->setText(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:',12'; font-weight:400; font-style:normal;\">\n"
"<table style=\"-qt-table-type: root; margin-top:4px; margin-bottom:4px; margin-left:4px; margin-right:4px;\">\n"
"<tr>\n"
"<td style=\"border: none;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:11pt;\">1 ms/div</span></p></td></tr></table></body></html>", 0, QApplication::UnicodeUTF8));
        lblMemory->setText(QString());
        lblSamplingRate->setText(QString());
        butRUNSTOP->setText(QApplication::translate("MainWindow", "RUN/STOP", 0, QApplication::UnicodeUTF8));
        grpTimeDiv->setTitle(QApplication::translate("MainWindow", "Time/Div", 0, QApplication::UnicodeUTF8));
        chTperDiv->setText(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:',12'; font-weight:400; font-style:normal;\">\n"
"<table style=\"-qt-table-type: root; margin-top:4px; margin-bottom:4px; margin-left:4px; margin-right:4px;\">\n"
"<tr>\n"
"<td style=\"border: none;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">1 ms/div</p></td></tr></table></body></html>", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "nS", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "S", 0, QApplication::UnicodeUTF8));
        grpVoltDiv->setTitle(QApplication::translate("MainWindow", "Volt/Div", 0, QApplication::UnicodeUTF8));
        chlabel->setText(QString());
        chVperDiv->setText(QString());
        chVperDiv_2->setText(QString());
        chk1ShowTrace->setText(QApplication::translate("MainWindow", "Trace", 0, QApplication::UnicodeUTF8));
        chk2ShowTrace->setText(QApplication::translate("MainWindow", "Trace", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "mV", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "V", 0, QApplication::UnicodeUTF8));
        butOffset_plus->setText(QApplication::translate("MainWindow", "+", 0, QApplication::UnicodeUTF8));
        butOffset_minus->setText(QApplication::translate("MainWindow", "-", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Century Schoolbook L'; font-size:11pt; font-weight:600; font-style:normal;\">\n"
"<table style=\"-qt-table-type: root; margin-top:4px; margin-bottom:4px; margin-left:4px; margin-right:4px;\">\n"
"<tr>\n"
"<td style=\"border: none;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">offset</p></td></tr></table></body></html>", 0, QApplication::UnicodeUTF8));
        butOffset_zero->setText(QApplication::translate("MainWindow", "Zero", 0, QApplication::UnicodeUTF8));
        grpTriggers->setTitle(QApplication::translate("MainWindow", "Triggers", 0, QApplication::UnicodeUTF8));
        chTperDiv_2->setText(QString());
        TimebaseTitle_2->setText(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Century Schoolbook L'; font-weight:600; font-style:normal;\">\n"
"<table style=\"-qt-table-type: root; margin-top:4px; margin-bottom:4px; margin-left:4px; margin-right:4px;\">\n"
"<tr>\n"
"<td style=\"border: none;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:11pt;\">Horizontal</span></p></td></tr></table></body></html>", 0, QApplication::UnicodeUTF8));
        TimebaseTitle_3->setText(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Century Schoolbook L'; font-weight:600; font-style:normal;\">\n"
"<table border=\"0\" style=\"-qt-table-type: root; margin-top:4px; margin-bottom:4px; margin-left:4px; margin-right:4px;\">\n"
"<tr>\n"
"<td style=\"border: none;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:11pt;\">Vertical</span></p></td></tr></table></body></html>", 0, QApplication::UnicodeUTF8));
        ch1Coupling_4->setText(QApplication::translate("MainWindow", "DC1M", 0, QApplication::UnicodeUTF8));
        cursorsTitle->setText(QApplication::translate("MainWindow", "Cursors", 0, QApplication::UnicodeUTF8));
        lblX1->setText(QApplication::translate("MainWindow", "X1:", 0, QApplication::UnicodeUTF8));
        lblX1Value->setText(QString());
        lblX2->setText(QApplication::translate("MainWindow", "X2:", 0, QApplication::UnicodeUTF8));
        lblX2Value->setText(QString());
        lblY1->setText(QApplication::translate("MainWindow", "Y1:", 0, QApplication::UnicodeUTF8));
        lblY1Value->setText(QString());
        lblY2->setText(QApplication::translate("MainWindow", "Y2:", 0, QApplication::UnicodeUTF8));
        lblY2Value->setText(QString());
        grpCursors->setTitle(QApplication::translate("MainWindow", "Cursors", 0, QApplication::UnicodeUTF8));
        chTperDiv_3->setText(QString());
        butUP->setText(QApplication::translate("MainWindow", "UP", 0, QApplication::UnicodeUTF8));
        butDOWN->setText(QApplication::translate("MainWindow", "DOWN", 0, QApplication::UnicodeUTF8));
        butLEFT->setText(QApplication::translate("MainWindow", "LEFT", 0, QApplication::UnicodeUTF8));
        butRIGHT->setText(QApplication::translate("MainWindow", "RIGHT", 0, QApplication::UnicodeUTF8));
        lblSysFreqValue->setText(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Century Schoolbook L'; font-weight:400; font-style:normal;\">\n"
"<table border=\"0\" style=\"-qt-table-type: root; margin-top:4px; margin-bottom:4px; margin-left:4px; margin-right:4px;\">\n"
"<tr>\n"
"<td style=\"border: none;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"></p></td></tr></table></body></html>", 0, QApplication::UnicodeUTF8));
        optAuto->setText(QApplication::translate("MainWindow", "Auto", 0, QApplication::UnicodeUTF8));
        optNormal->setText(QApplication::translate("MainWindow", "Normal", 0, QApplication::UnicodeUTF8));
        lblDelY_2->setText(QApplication::translate("MainWindow", "del Freq:", 0, QApplication::UnicodeUTF8));
        lblDelFreqValue->setText(QString());
        lblDelYValue->setText(QString());
        lblDelY->setText(QApplication::translate("MainWindow", "delY:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
