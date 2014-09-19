/********************************************************************************
** Form generated from reading UI file 'ddswidget.ui'
**
** Created: Sat Sep 6 10:53:20 2014
**      by: Qt User Interface Compiler version 4.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DDSWIDGET_H
#define UI_DDSWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QFrame>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DDSWidget
{
public:
    QGroupBox *grpTimeBase;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *leTickTime;
    QLabel *label_6;
    QLineEdit *leTickFrequency;
    QLabel *label_7;
    QLabel *lblUnits;
    QLabel *lblTimeUnits;
    QLabel *label_28;
    QFrame *line_8;
    QLabel *label_29;
    QLineEdit *leRamPeriod;
    QLineEdit *leRamFrequency;
    QLabel *lblUnits_2;
    QGroupBox *grpGeneral;
    QLabel *lblAddress;
    QLabel *label;
    QPushButton *butRead;
    QPushButton *butWrite;
    QRadioButton *appSelection;
    QRadioButton *bkpanelSelection;
    QGroupBox *grpDDS;
    QLabel *label_8;
    QLineEdit *leFS;
    QLabel *label_9;
    QLabel *label_10;
    QLineEdit *leOutputTime;
    QLabel *FoUnit;
    QLabel *opUnit;
    QLabel *FsUnit;
    QLabel *label_25;
    QLabel *phaseUnit;
    QComboBox *comboBox;
    QLabel *selectWaveform;
    QLabel *label_26;
    QCheckBox *countLoop;
    QComboBox *comboBox_2;
    QComboBox *comboBox_3;
    QComboBox *comboBox_4;
    QLabel *selectWaveform_2;
    QLabel *selectWaveform_3;
    QLabel *selectWaveform_4;
    QGroupBox *grpPPT;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_20;
    QLabel *label_21;
    QGroupBox *grpBarRep;
    QFrame *line_7;
    QFrame *line;
    QFrame *line_2;
    QFrame *line_3;
    QFrame *line_6;
    QFrame *line_4;
    QFrame *line_5;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *lblSTDLY;
    QLabel *lbl_WDP;
    QLabel *lblSTOPDLY;
    QLabel *label_22;
    QLabel *lblTotalTime;
    QLabel *label_23;
    QLabel *lblTotalFrequency;
    QLabel *lblWDPFreq;
    QCheckBox *chkLoop;
    QCheckBox *checkBox;
    QLabel *label_24;
    QGroupBox *grpDrive;
    QPushButton *butDrive;
    QPushButton *butStop;
    QPushButton *butCalculate;
    QPushButton *butUpdate;
    QPushButton *pushButton;
    QGroupBox *grpAD5293;
    QLabel *label_27;
    QComboBox *cmbVoltRanges;

    void setupUi(QWidget *DDSWidget)
    {
        if (DDSWidget->objectName().isEmpty())
            DDSWidget->setObjectName(QString::fromUtf8("DDSWidget"));
        DDSWidget->resize(800, 600);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(108, 108, 107, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(162, 162, 161, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(135, 135, 134, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(54, 54, 53, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(72, 72, 71, 255));
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
        DDSWidget->setPalette(palette);
        DDSWidget->setStyleSheet(QString::fromUtf8("QLabel{color:white;}\n"
"QGroupBox{color:white;}\n"
""));
        grpTimeBase = new QGroupBox(DDSWidget);
        grpTimeBase->setObjectName(QString::fromUtf8("grpTimeBase"));
        grpTimeBase->setGeometry(QRect(310, 10, 471, 187));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QBrush brush8(QColor(85, 0, 0, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush8);
        palette1.setBrush(QPalette::Active, QPalette::Shadow, brush8);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush8);
        palette1.setBrush(QPalette::Inactive, QPalette::Shadow, brush8);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Shadow, brush8);
        grpTimeBase->setPalette(palette1);
        QFont font;
        font.setFamily(QString::fromUtf8("DejaVu Sans"));
        grpTimeBase->setFont(font);
        label_2 = new QLabel(grpTimeBase);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 40, 81, 31));
        label_3 = new QLabel(grpTimeBase);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 110, 81, 20));
        label_4 = new QLabel(grpTimeBase);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(123, 68, 91, 20));
        QFont font1;
        font1.setPointSize(8);
        label_4->setFont(font1);
        label_5 = new QLabel(grpTimeBase);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(128, 137, 91, 20));
        label_5->setFont(font1);
        leTickTime = new QLineEdit(grpTimeBase);
        leTickTime->setObjectName(QString::fromUtf8("leTickTime"));
        leTickTime->setGeometry(QRect(330, 30, 81, 41));
        leTickTime->setFocusPolicy(Qt::NoFocus);
        leTickTime->setStyleSheet(QString::fromUtf8(" QLineEdit {\n"
"     border: 2px solid gray;\n"
"     border-radius: 23px;\n"
"     padding: 0 8px;\n"
"     background: gray;\n"
"     selection-background-color: darkgray;\n"
"	 color:white;\n"
"     font: bold 12px;\n"
" }"));
        label_6 = new QLabel(grpTimeBase);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(247, 37, 81, 31));
        leTickFrequency = new QLineEdit(grpTimeBase);
        leTickFrequency->setObjectName(QString::fromUtf8("leTickFrequency"));
        leTickFrequency->setGeometry(QRect(330, 100, 81, 41));
        leTickFrequency->setFocusPolicy(Qt::NoFocus);
        leTickFrequency->setStyleSheet(QString::fromUtf8(" QLineEdit {\n"
"     border: 2px solid gray;\n"
"     border-radius: 23px;\n"
"     padding: 0 8px;\n"
"     background: gray;\n"
"     selection-background-color: darkgray;\n"
"	 color:white;\n"
"     font: bold 12px;\n"
" }"));
        label_7 = new QLabel(grpTimeBase);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(250, 100, 71, 41));
        lblUnits = new QLabel(grpTimeBase);
        lblUnits->setObjectName(QString::fromUtf8("lblUnits"));
        lblUnits->setGeometry(QRect(420, 100, 31, 41));
        QFont font2;
        font2.setPointSize(12);
        lblUnits->setFont(font2);
        lblTimeUnits = new QLabel(grpTimeBase);
        lblTimeUnits->setObjectName(QString::fromUtf8("lblTimeUnits"));
        lblTimeUnits->setGeometry(QRect(420, 30, 31, 41));
        lblTimeUnits->setFont(font2);
        lblTimeUnits->setStyleSheet(QString::fromUtf8(""));
        label_28 = new QLabel(grpTimeBase);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setGeometry(QRect(11, 161, 71, 20));
        label_28->setFont(font1);
        line_8 = new QFrame(grpTimeBase);
        line_8->setObjectName(QString::fromUtf8("line_8"));
        line_8->setGeometry(QRect(0, 149, 471, 16));
        line_8->setFrameShape(QFrame::HLine);
        line_8->setFrameShadow(QFrame::Sunken);
        label_29 = new QLabel(grpTimeBase);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setGeometry(QRect(250, 162, 91, 20));
        label_29->setFont(font1);
        leRamPeriod = new QLineEdit(grpTimeBase);
        leRamPeriod->setObjectName(QString::fromUtf8("leRamPeriod"));
        leRamPeriod->setGeometry(QRect(90, 160, 81, 21));
        leRamPeriod->setFocusPolicy(Qt::NoFocus);
        leRamPeriod->setStyleSheet(QString::fromUtf8(" QLineEdit {\n"
"     border: 2px solid gray;\n"
"     border-radius: 23px;\n"
"     padding: 0 8px;\n"
"     background: gray;\n"
"     selection-background-color: darkgray;\n"
"	 color:white;\n"
"     font: bold 12px;\n"
" }"));
        leRamFrequency = new QLineEdit(grpTimeBase);
        leRamFrequency->setObjectName(QString::fromUtf8("leRamFrequency"));
        leRamFrequency->setGeometry(QRect(340, 161, 81, 21));
        leRamFrequency->setFocusPolicy(Qt::NoFocus);
        leRamFrequency->setStyleSheet(QString::fromUtf8(" QLineEdit {\n"
"     border: 2px solid gray;\n"
"     border-radius: 23px;\n"
"     padding: 0 8px;\n"
"     background: gray;\n"
"     selection-background-color: darkgray;\n"
"	 color:white;\n"
"     font: bold 12px;\n"
" }"));
        lblUnits_2 = new QLabel(grpTimeBase);
        lblUnits_2->setObjectName(QString::fromUtf8("lblUnits_2"));
        lblUnits_2->setGeometry(QRect(230, 180, 31, 31));
        lblUnits_2->setFont(font2);
        grpGeneral = new QGroupBox(DDSWidget);
        grpGeneral->setObjectName(QString::fromUtf8("grpGeneral"));
        grpGeneral->setGeometry(QRect(10, 10, 280, 121));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush8);
        palette2.setBrush(QPalette::Active, QPalette::Shadow, brush8);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush8);
        palette2.setBrush(QPalette::Inactive, QPalette::Shadow, brush8);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Shadow, brush8);
        grpGeneral->setPalette(palette2);
        grpGeneral->setFont(font);
        lblAddress = new QLabel(grpGeneral);
        lblAddress->setObjectName(QString::fromUtf8("lblAddress"));
        lblAddress->setGeometry(QRect(20, 20, 69, 20));
        label = new QLabel(grpGeneral);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 60, 41, 20));
        butRead = new QPushButton(grpGeneral);
        butRead->setObjectName(QString::fromUtf8("butRead"));
        butRead->setGeometry(QRect(190, 55, 84, 40));
        butRead->setFont(font);
        butRead->setFocusPolicy(Qt::NoFocus);
        butRead->setStyleSheet(QString::fromUtf8(" QPushButton {\n"
"     border: 2px solid #8f8f91;\n"
"     border-radius: 10px;\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #f6f7fa, stop: 1 #dadbde);\n"
"     min-width: 80px;\n"
" }\n"
"\n"
" QPushButton:pressed {\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
" }\n"
"\n"
" QPushButton:flat {\n"
"     border: none; /* no border for a flat push button */\n"
" }\n"
"\n"
" QPushButton:default {\n"
"     border-color: navy; /* make the default button prominent */\n"
" }"));
        butWrite = new QPushButton(grpGeneral);
        butWrite->setObjectName(QString::fromUtf8("butWrite"));
        butWrite->setGeometry(QRect(190, 16, 84, 40));
        butWrite->setFont(font);
        butWrite->setFocusPolicy(Qt::NoFocus);
        butWrite->setStyleSheet(QString::fromUtf8(" QPushButton {\n"
"     border: 2px solid #8f8f91;\n"
"     border-radius: 10px;\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #f6f7fa, stop: 1 #dadbde);\n"
"     min-width: 80px;\n"
" }\n"
"\n"
" QPushButton:pressed {\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
" }\n"
"\n"
" QPushButton:flat {\n"
"     border: none; /* no border for a flat push button */\n"
" }\n"
"\n"
" QPushButton:default {\n"
"     border-color: navy; /* make the default button prominent */\n"
" }"));
        appSelection = new QRadioButton(grpGeneral);
        appSelection->setObjectName(QString::fromUtf8("appSelection"));
        appSelection->setGeometry(QRect(30, 90, 111, 26));
        QFont font3;
        font3.setBold(false);
        font3.setItalic(false);
        font3.setWeight(50);
        appSelection->setFont(font3);
        appSelection->setStyleSheet(QString::fromUtf8("QRadioButton{\n"
"font: 14px;\n"
"color:white\n"
"}\n"
" QRadioButton::indicator {\n"
"     width: 20px;\n"
"     height:20px;\n"
"   border: 2px solid black;\n"
"	 border-radius:12;\n"
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
"     }"));
        appSelection->setChecked(true);
        bkpanelSelection = new QRadioButton(grpGeneral);
        bkpanelSelection->setObjectName(QString::fromUtf8("bkpanelSelection"));
        bkpanelSelection->setGeometry(QRect(142, 92, 111, 26));
        bkpanelSelection->setFont(font3);
        bkpanelSelection->setStyleSheet(QString::fromUtf8("QRadioButton{\n"
"font: 14px;\n"
"color:white\n"
"}\n"
" QRadioButton::indicator {\n"
"     width: 20px;\n"
"     height:20px;\n"
"   border: 2px solid black;\n"
"	 border-radius:12;\n"
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
"     }"));
        bkpanelSelection->setChecked(false);
        grpDDS = new QGroupBox(DDSWidget);
        grpDDS->setObjectName(QString::fromUtf8("grpDDS"));
        grpDDS->setGeometry(QRect(10, 200, 280, 320));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Active, QPalette::Base, brush8);
        palette3.setBrush(QPalette::Active, QPalette::Shadow, brush8);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush8);
        palette3.setBrush(QPalette::Inactive, QPalette::Shadow, brush8);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Shadow, brush8);
        grpDDS->setPalette(palette3);
        grpDDS->setFont(font);
        label_8 = new QLabel(grpDDS);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(0, 20, 141, 30));
        QFont font4;
        font4.setFamily(QString::fromUtf8("DejaVu Sans"));
        font4.setPointSize(10);
        label_8->setFont(font4);
        leFS = new QLineEdit(grpDDS);
        leFS->setObjectName(QString::fromUtf8("leFS"));
        leFS->setGeometry(QRect(140, 20, 100, 30));
        leFS->setFocusPolicy(Qt::NoFocus);
        leFS->setStyleSheet(QString::fromUtf8(" QLineEdit {\n"
"     border: 2px solid gray;\n"
"     border-radius: 23px;\n"
"     padding: 0 8px;\n"
"     background: gray;\n"
"     selection-background-color: darkgray;\n"
"	 color:white;\n"
"     font: bold 12px;\n"
" }"));
        label_9 = new QLabel(grpDDS);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(0, 60, 141, 30));
        label_9->setFont(font4);
        label_10 = new QLabel(grpDDS);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(0, 140, 141, 30));
        label_10->setFont(font4);
        leOutputTime = new QLineEdit(grpDDS);
        leOutputTime->setObjectName(QString::fromUtf8("leOutputTime"));
        leOutputTime->setGeometry(QRect(140, 140, 100, 29));
        leOutputTime->setFocusPolicy(Qt::NoFocus);
        leOutputTime->setStyleSheet(QString::fromUtf8(" QLineEdit {\n"
"     border: 2px solid gray;\n"
"     border-radius: 23px;\n"
"     padding: 0 8px;\n"
"     background: gray;\n"
"     selection-background-color: darkgray;\n"
"	 color:white;\n"
"     font: bold 12px;\n"
" }"));
        FoUnit = new QLabel(grpDDS);
        FoUnit->setObjectName(QString::fromUtf8("FoUnit"));
        FoUnit->setGeometry(QRect(240, 60, 31, 30));
        QFont font5;
        font5.setBold(true);
        font5.setItalic(false);
        font5.setWeight(75);
        FoUnit->setFont(font5);
        FoUnit->setStyleSheet(QString::fromUtf8(" QLabel {\n"
"      color:white;\n"
"     font: bold 12px;\n"
" }"));
        opUnit = new QLabel(grpDDS);
        opUnit->setObjectName(QString::fromUtf8("opUnit"));
        opUnit->setGeometry(QRect(240, 140, 31, 29));
        opUnit->setFont(font5);
        opUnit->setStyleSheet(QString::fromUtf8(" QLabel {\n"
"     color:white;\n"
"     font: bold 12px;\n"
" }"));
        FsUnit = new QLabel(grpDDS);
        FsUnit->setObjectName(QString::fromUtf8("FsUnit"));
        FsUnit->setGeometry(QRect(240, 20, 31, 30));
        FsUnit->setFont(font5);
        FsUnit->setStyleSheet(QString::fromUtf8(" QLabel {\n"
"   	 color:white;\n"
"     font: bold 12px;\n"
" }"));
        label_25 = new QLabel(grpDDS);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setGeometry(QRect(0, 100, 141, 30));
        label_25->setFont(font4);
        phaseUnit = new QLabel(grpDDS);
        phaseUnit->setObjectName(QString::fromUtf8("phaseUnit"));
        phaseUnit->setGeometry(QRect(240, 100, 31, 29));
        phaseUnit->setFont(font5);
        phaseUnit->setStyleSheet(QString::fromUtf8(" QLabel {\n"
"     color:white;\n"
"     font: bold 12px;\n"
" }"));
        comboBox = new QComboBox(grpDDS);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(10, 240, 120, 26));
        comboBox->setFont(font);
        comboBox->setStyleSheet(QString::fromUtf8("border: 2px solid gray;\n"
"border-radius: 10px;"));
        selectWaveform = new QLabel(grpDDS);
        selectWaveform->setObjectName(QString::fromUtf8("selectWaveform"));
        selectWaveform->setGeometry(QRect(10, 220, 130, 20));
        selectWaveform->setFont(font);
        label_26 = new QLabel(grpDDS);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setGeometry(QRect(10, 190, 91, 17));
        label_26->setFont(font);
        countLoop = new QCheckBox(grpDDS);
        countLoop->setObjectName(QString::fromUtf8("countLoop"));
        countLoop->setGeometry(QRect(210, 187, 61, 25));
        countLoop->setFont(font3);
        countLoop->setFocusPolicy(Qt::NoFocus);
        countLoop->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
"font: 12px;\n"
"color:white\n"
"}\n"
" QCheckBox::indicator {\n"
"     width: 15px;\n"
"     height:15px;\n"
"   border: 2px solid black;\n"
"	 \n"
"\n"
" }\n"
" QCheckBox::indicator::unchecked {\n"
"		background-color:white;\n"
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
        comboBox_2 = new QComboBox(grpDDS);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(150, 240, 120, 26));
        comboBox_2->setFont(font);
        comboBox_2->setStyleSheet(QString::fromUtf8("border: 2px solid gray;\n"
"border-radius: 10px;"));
        comboBox_3 = new QComboBox(grpDDS);
        comboBox_3->setObjectName(QString::fromUtf8("comboBox_3"));
        comboBox_3->setGeometry(QRect(10, 290, 120, 26));
        comboBox_3->setFont(font);
        comboBox_3->setStyleSheet(QString::fromUtf8("border: 2px solid gray;\n"
"border-radius: 10px;"));
        comboBox_4 = new QComboBox(grpDDS);
        comboBox_4->setObjectName(QString::fromUtf8("comboBox_4"));
        comboBox_4->setGeometry(QRect(150, 290, 120, 26));
        comboBox_4->setFont(font);
        comboBox_4->setStyleSheet(QString::fromUtf8("border: 2px solid gray;\n"
"border-radius: 10px;"));
        selectWaveform_2 = new QLabel(grpDDS);
        selectWaveform_2->setObjectName(QString::fromUtf8("selectWaveform_2"));
        selectWaveform_2->setGeometry(QRect(10, 270, 130, 20));
        selectWaveform_2->setFont(font);
        selectWaveform_3 = new QLabel(grpDDS);
        selectWaveform_3->setObjectName(QString::fromUtf8("selectWaveform_3"));
        selectWaveform_3->setGeometry(QRect(150, 270, 130, 20));
        selectWaveform_3->setFont(font);
        selectWaveform_4 = new QLabel(grpDDS);
        selectWaveform_4->setObjectName(QString::fromUtf8("selectWaveform_4"));
        selectWaveform_4->setGeometry(QRect(150, 220, 130, 20));
        selectWaveform_4->setFont(font);
        grpPPT = new QGroupBox(DDSWidget);
        grpPPT->setObjectName(QString::fromUtf8("grpPPT"));
        grpPPT->setGeometry(QRect(310, 200, 470, 130));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Active, QPalette::Text, brush);
        palette4.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette4.setBrush(QPalette::Active, QPalette::Base, brush8);
        palette4.setBrush(QPalette::Active, QPalette::Shadow, brush8);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush8);
        palette4.setBrush(QPalette::Inactive, QPalette::Shadow, brush8);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Shadow, brush8);
        grpPPT->setPalette(palette4);
        grpPPT->setFont(font);
        label_11 = new QLabel(grpPPT);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(20, 20, 71, 41));
        label_12 = new QLabel(grpPPT);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(230, 20, 81, 41));
        label_13 = new QLabel(grpPPT);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(183, 30, 41, 20));
        label_14 = new QLabel(grpPPT);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(418, 30, 31, 20));
        label_15 = new QLabel(grpPPT);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(420, 80, 31, 20));
        label_16 = new QLabel(grpPPT);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(20, 70, 51, 51));
        label_20 = new QLabel(grpPPT);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(411, 80, 31, 20));
        label_21 = new QLabel(grpPPT);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(235, 70, 91, 41));
        grpBarRep = new QGroupBox(DDSWidget);
        grpBarRep->setObjectName(QString::fromUtf8("grpBarRep"));
        grpBarRep->setGeometry(QRect(310, 333, 470, 130));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Active, QPalette::Text, brush);
        palette5.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette5.setBrush(QPalette::Active, QPalette::Base, brush8);
        palette5.setBrush(QPalette::Active, QPalette::Shadow, brush8);
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Base, brush8);
        palette5.setBrush(QPalette::Inactive, QPalette::Shadow, brush8);
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::Shadow, brush8);
        grpBarRep->setPalette(palette5);
        grpBarRep->setFont(font);
        line_7 = new QFrame(grpBarRep);
        line_7->setObjectName(QString::fromUtf8("line_7"));
        line_7->setGeometry(QRect(410, 14, 20, 21));
        line_7->setLineWidth(2);
        line_7->setFrameShape(QFrame::VLine);
        line_7->setFrameShadow(QFrame::Sunken);
        line = new QFrame(grpBarRep);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(30, 8, 101, 31));
        line->setLineWidth(2);
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(grpBarRep);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(120, 13, 20, 21));
        line_2->setLineWidth(2);
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(grpBarRep);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(20, 12, 20, 21));
        line_3->setLineWidth(2);
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);
        line_6 = new QFrame(grpBarRep);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setGeometry(QRect(320, 8, 101, 31));
        line_6->setLineWidth(2);
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);
        line_4 = new QFrame(grpBarRep);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setGeometry(QRect(130, 13, 191, 20));
        line_4->setLineWidth(2);
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        line_5 = new QFrame(grpBarRep);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setGeometry(QRect(310, 14, 20, 21));
        line_5->setLineWidth(2);
        line_5->setFrameShape(QFrame::VLine);
        line_5->setFrameShadow(QFrame::Sunken);
        label_17 = new QLabel(grpBarRep);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(48, 2, 69, 20));
        label_18 = new QLabel(grpBarRep);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(210, 4, 41, 20));
        label_19 = new QLabel(grpBarRep);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(332, 4, 81, 20));
        lblSTDLY = new QLabel(grpBarRep);
        lblSTDLY->setObjectName(QString::fromUtf8("lblSTDLY"));
        lblSTDLY->setGeometry(QRect(30, 22, 101, 20));
        lblSTDLY->setAlignment(Qt::AlignCenter);
        lbl_WDP = new QLabel(grpBarRep);
        lbl_WDP->setObjectName(QString::fromUtf8("lbl_WDP"));
        lbl_WDP->setGeometry(QRect(140, 24, 181, 20));
        lbl_WDP->setAlignment(Qt::AlignCenter);
        lblSTOPDLY = new QLabel(grpBarRep);
        lblSTOPDLY->setObjectName(QString::fromUtf8("lblSTOPDLY"));
        lblSTOPDLY->setGeometry(QRect(320, 24, 101, 20));
        lblSTOPDLY->setAlignment(Qt::AlignCenter);
        label_22 = new QLabel(grpBarRep);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(10, 60, 101, 30));
        QFont font6;
        font6.setPointSize(14);
        label_22->setFont(font6);
        lblTotalTime = new QLabel(grpBarRep);
        lblTotalTime->setObjectName(QString::fromUtf8("lblTotalTime"));
        lblTotalTime->setGeometry(QRect(100, 60, 91, 30));
        lblTotalTime->setFont(font6);
        label_23 = new QLabel(grpBarRep);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(220, 60, 151, 32));
        label_23->setFont(font6);
        lblTotalFrequency = new QLabel(grpBarRep);
        lblTotalFrequency->setObjectName(QString::fromUtf8("lblTotalFrequency"));
        lblTotalFrequency->setGeometry(QRect(320, 60, 91, 30));
        lblTotalFrequency->setFont(font6);
        lblWDPFreq = new QLabel(grpBarRep);
        lblWDPFreq->setObjectName(QString::fromUtf8("lblWDPFreq"));
        lblWDPFreq->setGeometry(QRect(138, 40, 181, 20));
        QFont font7;
        font7.setBold(true);
        font7.setWeight(75);
        lblWDPFreq->setFont(font7);
        lblWDPFreq->setAlignment(Qt::AlignCenter);
        chkLoop = new QCheckBox(grpBarRep);
        chkLoop->setObjectName(QString::fromUtf8("chkLoop"));
        chkLoop->setGeometry(QRect(10, 100, 121, 25));
        chkLoop->setFont(font3);
        chkLoop->setFocusPolicy(Qt::NoFocus);
        chkLoop->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
"font: 12px;\n"
"color:white\n"
"}\n"
" QCheckBox::indicator {\n"
"     width: 20px;\n"
"     height:20px;\n"
"   border: 2px solid black;\n"
"	 \n"
"\n"
" }\n"
" QCheckBox::indicator::unchecked {\n"
"		background-color:white;\n"
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
        checkBox = new QCheckBox(grpBarRep);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(370, 98, 91, 25));
        checkBox->setFont(font3);
        checkBox->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
"font: 12px;\n"
"color:white\n"
"}\n"
" QCheckBox::indicator {\n"
"     width: 20px;\n"
"     height:20px;\n"
"   border: 2px solid black;\n"
"	 \n"
"\n"
" }\n"
" QCheckBox::indicator::unchecked {\n"
"		background-color:red;\n"
"     }\n"
"\n"
"     QCheckBox::indicator:unchecked:hover {\n"
"		background-color:red;\n"
"     }\n"
"\n"
"     QCheckBox::indicator:unchecked:pressed {\n"
"		background-color:red;\n"
"     }\n"
"\n"
"     QCheckBox::indicator::checked {\n"
"		background-color:green;\n"
"     }\n"
"\n"
"     QCheckBox::indicator:checked:hover {\n"
"		background-color:green;\n"
"     }\n"
"\n"
"     QCheckBox::indicator:checked:pressed {\n"
"		background-color:green;\n"
"     }"));
        label_24 = new QLabel(DDSWidget);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(510, 490, 69, 20));
        grpDrive = new QGroupBox(DDSWidget);
        grpDrive->setObjectName(QString::fromUtf8("grpDrive"));
        grpDrive->setGeometry(QRect(310, 460, 470, 60));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette6.setBrush(QPalette::Active, QPalette::Text, brush);
        palette6.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette6.setBrush(QPalette::Active, QPalette::Base, brush8);
        palette6.setBrush(QPalette::Active, QPalette::Shadow, brush8);
        palette6.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::Base, brush8);
        palette6.setBrush(QPalette::Inactive, QPalette::Shadow, brush8);
        palette6.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::Shadow, brush8);
        grpDrive->setPalette(palette6);
        grpDrive->setFont(font);
        butDrive = new QPushButton(grpDrive);
        butDrive->setObjectName(QString::fromUtf8("butDrive"));
        butDrive->setGeometry(QRect(290, 15, 84, 40));
        butDrive->setFont(font);
        butDrive->setFocusPolicy(Qt::NoFocus);
        butDrive->setStyleSheet(QString::fromUtf8(" QPushButton {\n"
"     border: 2px solid #8f8f91;\n"
"     border-radius: 10px;\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #f6f7fa, stop: 1 #dadbde);\n"
"     min-width: 80px;\n"
" }\n"
"\n"
" QPushButton:pressed {\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
" }\n"
"\n"
" QPushButton:flat {\n"
"     border: none; /* no border for a flat push button */\n"
" }\n"
"\n"
" QPushButton:default {\n"
"     border-color: navy; /* make the default button prominent */\n"
" }"));
        butStop = new QPushButton(grpDrive);
        butStop->setObjectName(QString::fromUtf8("butStop"));
        butStop->setGeometry(QRect(380, 15, 84, 40));
        butStop->setFont(font);
        butStop->setFocusPolicy(Qt::NoFocus);
        butStop->setStyleSheet(QString::fromUtf8(" QPushButton {\n"
"     border: 2px solid #8f8f91;\n"
"     border-radius: 10px;\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #f6f7fa, stop: 1 #dadbde);\n"
"     min-width: 80px;\n"
" }\n"
"\n"
" QPushButton:pressed {\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
" }\n"
"\n"
" QPushButton:flat {\n"
"     border: none; /* no border for a flat push button */\n"
" }\n"
"\n"
" QPushButton:default {\n"
"     border-color: navy; /* make the default button prominent */\n"
" }"));
        butCalculate = new QPushButton(grpDrive);
        butCalculate->setObjectName(QString::fromUtf8("butCalculate"));
        butCalculate->setGeometry(QRect(110, 16, 84, 40));
        butCalculate->setFont(font);
        butCalculate->setFocusPolicy(Qt::NoFocus);
        butCalculate->setStyleSheet(QString::fromUtf8(" QPushButton {\n"
"     border: 2px solid #8f8f91;\n"
"     border-radius: 10px;\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #f6f7fa, stop: 1 #dadbde);\n"
"     min-width: 80px;\n"
" }\n"
"\n"
" QPushButton:pressed {\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
" }\n"
"\n"
" QPushButton:flat {\n"
"     border: none; /* no border for a flat push button */\n"
" }\n"
"\n"
" QPushButton:default {\n"
"     border-color: navy; /* make the default button prominent */\n"
" }"));
        butUpdate = new QPushButton(grpDrive);
        butUpdate->setObjectName(QString::fromUtf8("butUpdate"));
        butUpdate->setGeometry(QRect(200, 15, 84, 40));
        butUpdate->setFont(font);
        butUpdate->setFocusPolicy(Qt::NoFocus);
        butUpdate->setStyleSheet(QString::fromUtf8(" QPushButton {\n"
"     border: 2px solid #8f8f91;\n"
"     border-radius: 10px;\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #f6f7fa, stop: 1 #dadbde);\n"
"     min-width: 80px;\n"
" }\n"
"\n"
" QPushButton:pressed {\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
" }\n"
"\n"
" QPushButton:flat {\n"
"     border: none; /* no border for a flat push button */\n"
" }\n"
"\n"
" QPushButton:default {\n"
"     border-color: navy; /* make the default button prominent */\n"
" }"));
        pushButton = new QPushButton(grpDrive);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(12, 16, 90, 40));
        pushButton->setFont(font);
        pushButton->setStyleSheet(QString::fromUtf8(" QPushButton {\n"
"     border: 2px solid #8f8f91;\n"
"     border-radius: 10px;\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #f6f7fa, stop: 1 #dadbde);\n"
"     min-width: 80px;\n"
" }\n"
"\n"
" QPushButton:pressed {\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
" }\n"
"\n"
" QPushButton:flat {\n"
"     border: none; /* no border for a flat push button */\n"
" }\n"
"\n"
" QPushButton:default {\n"
"     border-color: navy; /* make the default button prominent */\n"
" }"));
        grpAD5293 = new QGroupBox(DDSWidget);
        grpAD5293->setObjectName(QString::fromUtf8("grpAD5293"));
        grpAD5293->setGeometry(QRect(10, 130, 281, 71));
        label_27 = new QLabel(grpAD5293);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setGeometry(QRect(10, 30, 61, 20));
        cmbVoltRanges = new QComboBox(grpAD5293);
        cmbVoltRanges->setObjectName(QString::fromUtf8("cmbVoltRanges"));
        cmbVoltRanges->setGeometry(QRect(190, 20, 81, 41));
        cmbVoltRanges->setStyleSheet(QString::fromUtf8("border: 2px solid gray;\n"
"border-radius: 10px;"));

        retranslateUi(DDSWidget);

        QMetaObject::connectSlotsByName(DDSWidget);
    } // setupUi

    void retranslateUi(QWidget *DDSWidget)
    {
        DDSWidget->setWindowTitle(QApplication::translate("DDSWidget", "DDSWidget", 0, QApplication::UnicodeUTF8));
        grpTimeBase->setTitle(QApplication::translate("DDSWidget", "TimeBase Settings", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("DDSWidget", "BTU(0x04):\n"
"   X 10ns", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("DDSWidget", "BD(0x06):", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("DDSWidget", "Basic Time Unit", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("DDSWidget", "Basic Duration", 0, QApplication::UnicodeUTF8));
        leTickTime->setText(QString());
        label_6->setText(QApplication::translate("DDSWidget", "Tick Time:\n"
"     (TT)", 0, QApplication::UnicodeUTF8));
        leTickFrequency->setText(QString());
        label_7->setText(QApplication::translate("DDSWidget", "Tick \n"
"Frequency", 0, QApplication::UnicodeUTF8));
        lblUnits->setText(QString());
        lblTimeUnits->setText(QString());
        label_28->setText(QApplication::translate("DDSWidget", "Ram Period:", 0, QApplication::UnicodeUTF8));
        label_29->setText(QApplication::translate("DDSWidget", "Ram Frequency:", 0, QApplication::UnicodeUTF8));
        leRamPeriod->setText(QString());
        leRamFrequency->setText(QString());
        lblUnits_2->setText(QString());
        grpGeneral->setTitle(QApplication::translate("DDSWidget", "General", 0, QApplication::UnicodeUTF8));
        lblAddress->setText(QApplication::translate("DDSWidget", "Address:", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("DDSWidget", "Data:", 0, QApplication::UnicodeUTF8));
        butRead->setText(QApplication::translate("DDSWidget", "Read", 0, QApplication::UnicodeUTF8));
        butWrite->setText(QApplication::translate("DDSWidget", "Write", 0, QApplication::UnicodeUTF8));
        appSelection->setText(QApplication::translate("DDSWidget", "App Card", 0, QApplication::UnicodeUTF8));
        bkpanelSelection->setText(QApplication::translate("DDSWidget", "Back Panel", 0, QApplication::UnicodeUTF8));
        grpDDS->setTitle(QApplication::translate("DDSWidget", "DDS", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("DDSWidget", "             Fs\n"
" (System Frequency)", 0, QApplication::UnicodeUTF8));
        leFS->setText(QString());
        label_9->setText(QApplication::translate("DDSWidget", "             Fo\n"
" (Output Frequency)", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("DDSWidget", "             To  \n"
"     (Output Time)", 0, QApplication::UnicodeUTF8));
        leOutputTime->setText(QString());
        FoUnit->setText(QString());
        opUnit->setText(QString());
        FsUnit->setText(QString());
        label_25->setText(QApplication::translate("DDSWidget", "             Phase  \n"
"         (Fs Angle)", 0, QApplication::UnicodeUTF8));
        phaseUnit->setText(QString());
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("DDSWidget", "RampUP", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DDSWidget", "RampDown", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DDSWidget", "Triangle", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DDSWidget", "Square", 0, QApplication::UnicodeUTF8)
        );
        selectWaveform->setText(QApplication::translate("DDSWidget", "Predefined(0x74)", 0, QApplication::UnicodeUTF8));
        label_26->setText(QApplication::translate("DDSWidget", "DDS Cycle:", 0, QApplication::UnicodeUTF8));
        countLoop->setText(QApplication::translate("DDSWidget", "Loop", 0, QApplication::UnicodeUTF8));
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("DDSWidget", "DC", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DDSWidget", "Predefined", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DDSWidget", "Pseudo", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DDSWidget", "DDS", 0, QApplication::UnicodeUTF8)
        );
        comboBox_3->clear();
        comboBox_3->insertItems(0, QStringList()
         << QApplication::translate("DDSWidget", "RAM", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DDSWidget", "DDS+", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DDSWidget", "Modulated", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DDSWidget", "Reserved", 0, QApplication::UnicodeUTF8)
        );
        comboBox_4->clear();
        comboBox_4->insertItems(0, QStringList()
         << QApplication::translate("DDSWidget", "RAM", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DDSWidget", "DDS", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DDSWidget", "Modulated", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DDSWidget", "Reserved", 0, QApplication::UnicodeUTF8)
        );
        selectWaveform_2->setText(QApplication::translate("DDSWidget", "Drive Mode(0x72)", 0, QApplication::UnicodeUTF8));
        selectWaveform_3->setText(QApplication::translate("DDSWidget", "Drive Path(0x94)", 0, QApplication::UnicodeUTF8));
        selectWaveform_4->setText(QApplication::translate("DDSWidget", "Waveform(0x72)", 0, QApplication::UnicodeUTF8));
        grpPPT->setTitle(QApplication::translate("DDSWidget", "Pattern Period Time", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("DDSWidget", "ST_DLY\n"
"(0x1C)", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("DDSWidget", "STOP_DLY\n"
"(0x1C)", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("DDSWidget", "xTT", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("DDSWidget", "xTT", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("DDSWidget", "xTT", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("DDSWidget", "Drive\n"
"Count\n"
"(0x1A)", 0, QApplication::UnicodeUTF8));
        label_20->setText(QString());
        label_21->setText(QApplication::translate("DDSWidget", "WDP\n"
"(0x18)", 0, QApplication::UnicodeUTF8));
        grpBarRep->setTitle(QString());
        label_17->setText(QApplication::translate("DDSWidget", "ST_DLY", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("DDSWidget", "WDP", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("DDSWidget", "STOP_DLY", 0, QApplication::UnicodeUTF8));
        lblSTDLY->setText(QApplication::translate("DDSWidget", "1", 0, QApplication::UnicodeUTF8));
        lbl_WDP->setText(QApplication::translate("DDSWidget", "1", 0, QApplication::UnicodeUTF8));
        lblSTOPDLY->setText(QApplication::translate("DDSWidget", "1", 0, QApplication::UnicodeUTF8));
        label_22->setText(QApplication::translate("DDSWidget", "P-Period:", 0, QApplication::UnicodeUTF8));
        lblTotalTime->setText(QString());
        label_23->setText(QApplication::translate("DDSWidget", "P-Frequency:", 0, QApplication::UnicodeUTF8));
        lblTotalFrequency->setText(QString());
        lblWDPFreq->setText(QString());
        chkLoop->setText(QApplication::translate("DDSWidget", "Pattern Loop", 0, QApplication::UnicodeUTF8));
        checkBox->setText(QApplication::translate("DDSWidget", "Loop Drive", 0, QApplication::UnicodeUTF8));
        label_24->setText(QString());
        grpDrive->setTitle(QApplication::translate("DDSWidget", "Drive", 0, QApplication::UnicodeUTF8));
        butDrive->setText(QApplication::translate("DDSWidget", "Start", 0, QApplication::UnicodeUTF8));
        butStop->setText(QApplication::translate("DDSWidget", "Stop", 0, QApplication::UnicodeUTF8));
        butCalculate->setText(QApplication::translate("DDSWidget", "Calculate", 0, QApplication::UnicodeUTF8));
        butUpdate->setText(QApplication::translate("DDSWidget", "Update", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("DDSWidget", "Calibrate", 0, QApplication::UnicodeUTF8));
        grpAD5293->setTitle(QApplication::translate("DDSWidget", "Ref Voltage", 0, QApplication::UnicodeUTF8));
        label_27->setText(QApplication::translate("DDSWidget", "Voltage:", 0, QApplication::UnicodeUTF8));
        cmbVoltRanges->clear();
        cmbVoltRanges->insertItems(0, QStringList()
         << QApplication::translate("DDSWidget", "0.5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DDSWidget", "1.5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DDSWidget", "3.5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DDSWidget", "7.0", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DDSWidget", "13.0", 0, QApplication::UnicodeUTF8)
        );
    } // retranslateUi

};

namespace Ui {
    class DDSWidget: public Ui_DDSWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DDSWIDGET_H
