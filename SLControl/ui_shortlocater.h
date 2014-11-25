/********************************************************************************
** Form generated from reading UI file 'shortlocater.ui'
**
** Created: Tue Nov 25 11:26:27 2014
**      by: Qt User Interface Compiler version 4.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHORTLOCATER_H
#define UI_SHORTLOCATER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QFrame>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSlider>
#include <QtGui/QSpinBox>
#include <QtGui/QWidget>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_ShortLocaterClass
{
public:
    QFrame *displayPanel;
    QLabel *units;
    QLabel *displayBG;
    QLabel *rangeLabel;
    QLabel *rangeCap;
    QProgressBar *progressBar_2;
    QSlider *horizontalSlider_5;
    QGroupBox *ohmBox;
    QPushButton *microOhms;
    QLabel *uE;
    QFrame *selectFrame;
    QFrame *inputPanel;
    QGroupBox *functionsPanel;
    QPushButton *offset;
    QPushButton *buzzer;
    QPushButton *settings;
    QGroupBox *Ranges;
    QPushButton *r200But;
    QLabel *r200ECap;
    QPushButton *r2EBut;
    QLabel *r2Ecap;
    QPushButton *r200mEBut;
    QLabel *r200mECap;
    QPushButton *but200mE;
    QPushButton *but2E;
    QPushButton *but200E;
    QWidget *splashWidget;
    QLabel *splashLabel;
    QGroupBox *Legends;
    QPushButton *butL;
    QLineEdit *lblLeft;
    QPushButton *butR;
    QLineEdit *lblRight;
    QLineEdit *lblMiddle;
    QPushButton *butM;
    QGroupBox *temp4;
    QPushButton *ohmMeter_3;
    QGroupBox *appBox;
    QPushButton *selectApp;
    QGroupBox *ExitBox;
    QPushButton *exit;
    QGroupBox *graphBox;
    QPushButton *graph;
    QGroupBox *temp3;
    QPushButton *ohmMeter_2;
    QGroupBox *debugPanel;
    QPushButton *pushButton_16;
    QPushButton *pushButton;
    QPushButton *HAADC;
    QCheckBox *calibrateDisplay;
    QGroupBox *haadcFrame;
    QPushButton *haadcClose;
    QLabel *label_22;
    QLabel *label_23;
    QLineEdit *adcRawData;
    QLineEdit *adcConvData;
    QLineEdit *displayInput;
    QLabel *label_25;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QLineEdit *lineEdit;
    QCheckBox *openShortEnable;
    QLineEdit *displayOffset;
    QPushButton *left;
    QPushButton *right;
    QPushButton *down;
    QPushButton *up;
    QCheckBox *checkBox;
    QGroupBox *selectLib;
    QRadioButton *oldLib;
    QRadioButton *newLib;
    QLabel *label_2;
    QSpinBox *SpinSamples;
    QWidget *HAADC_WIDGET;
    QFrame *frontPanel_SHLOC;
    QFrame *framePowerUSB;
    QFrame *fp_usbSocket;
    QFrame *fp_usbSymbol;
    QFrame *fp_powerButton;
    QLabel *fp_powerLabel;
    QFrame *analogHighway;
    QLabel *ah3_label;
    QLabel *ah1_label;
    QFrame *ah1_outer;
    QFrame *ah1_inner;
    QFrame *ah3_outer;
    QFrame *ah3_inner;
    QLabel *ah_label;
    QLabel *ah0_label;
    QFrame *ah0_outer;
    QFrame *ah0_inner;
    QLabel *ah2_label;
    QFrame *ah2_outer;
    QFrame *ah2_inner;
    QFrame *fp_VI_ICM_SL;
    QFrame *fp_Guarding;
    QFrame *fp_VI2_EXT;
    QLabel *fp_VI1_ICM_SL_label;
    QLabel *fp_VI2_EXT_label;
    QFrame *fp_VI1_ICM_SL;
    QLabel *fp_ICM_Guard;
    QFrame *frame_15;
    QLabel *label_74;
    QLabel *label_75;
    QFrame *dso1_outer_9;
    QFrame *dso1_inner_6;
    QFrame *dso_outer_18;
    QFrame *dso_inner_6;
    QLabel *label_76;
    QLabel *label_77;
    QFrame *frame_40;
    QFrame *frame_41;
    QLabel *label_78;
    QFrame *frame_42;
    QFrame *frame_43;
    QFrame *frame_DMM;
    QLabel *fp_A_label;
    QFrame *fp_LO_inner;
    QFrame *fp_mA_inner;
    QFrame *fp_A_outer;
    QFrame *fp_A_inner;
    QFrame *fp_mA_outer;
    QLabel *fp_HI_label;
    QFrame *fp_LO_outer;
    QFrame *fp_HI_outer;
    QLabel *fp_LO_label;
    QFrame *fp_HI_inner;
    QLabel *fp_DMM_label;
    QLabel *fp_fuse_label;
    QFrame *fp_fuse;
    QLabel *fp_mA_label;
    QFrame *fp_REF;
    QLabel *fp_REF_label;
    QLabel *fp_GND_label;
    QFrame *fp_GND;
    QFrame *plottingWindow;
    QCustomPlot *customPlot;
    QPushButton *butZoom;
    QPushButton *External;
    QPushButton *Internal;
    QPushButton *Auto;
    QPushButton *Null;
    QPushButton *hold;
    QLabel *holdCap;
    QLabel *label;

    void setupUi(QWidget *ShortLocaterClass)
    {
        if (ShortLocaterClass->objectName().isEmpty())
            ShortLocaterClass->setObjectName(QString::fromUtf8("ShortLocaterClass"));
        ShortLocaterClass->resize(800, 600);
        QPalette palette;
        QBrush brush(QColor(88, 88, 89, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        ShortLocaterClass->setPalette(palette);
        ShortLocaterClass->setAutoFillBackground(true);
        displayPanel = new QFrame(ShortLocaterClass);
        displayPanel->setObjectName(QString::fromUtf8("displayPanel"));
        displayPanel->setGeometry(QRect(10, 33, 693, 171));
        QFont font;
        font.setPointSize(10);
        font.setBold(false);
        font.setWeight(50);
        displayPanel->setFont(font);
        displayPanel->setStyleSheet(QString::fromUtf8("QFrame {\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #3a5976, stop: 1 #000000);\n"
" }\n"
"QTextEdit{\n"
"	background-color:black;\n"
"	border:1px solid black;\n"
"	border-radius:5px;\n"
"	color:yellow;\n"
"}\n"
"QLineEdit{\n"
"	background-color:black;\n"
"	border:1px solid black;\n"
"	border-radius:5px;\n"
"	color:yellow;\n"
"}\n"
"QLabel{\n"
"	background-color:black;\n"
"	color:yellow;\n"
"}"));
        displayPanel->setFrameShape(QFrame::Box);
        displayPanel->setFrameShadow(QFrame::Raised);
        units = new QLabel(displayPanel);
        units->setObjectName(QString::fromUtf8("units"));
        units->setGeometry(QRect(510, 30, 140, 90));
        QPalette palette1;
        QBrush brush2(QColor(251, 236, 93, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        QBrush brush3(QColor(0, 0, 0, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush3);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush3);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush3);
        units->setPalette(palette1);
        QFont font1;
        font1.setFamily(QString::fromUtf8("DejaVu Sans"));
        font1.setPointSize(48);
        font1.setBold(false);
        font1.setWeight(50);
        units->setFont(font1);
        units->setStyleSheet(QString::fromUtf8("color: #fbec5d;"));
        displayBG = new QLabel(displayPanel);
        displayBG->setObjectName(QString::fromUtf8("displayBG"));
        displayBG->setGeometry(QRect(30, 10, 630, 120));
        QPalette palette2;
        QBrush brush4(QColor(255, 255, 0, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush4);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush3);
        palette2.setBrush(QPalette::Active, QPalette::Light, brush3);
        palette2.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        palette2.setBrush(QPalette::Active, QPalette::Dark, brush3);
        palette2.setBrush(QPalette::Active, QPalette::Mid, brush3);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush4);
        QBrush brush5(QColor(255, 255, 127, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::BrightText, brush5);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush4);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush3);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush3);
        palette2.setBrush(QPalette::Active, QPalette::Highlight, brush3);
        palette2.setBrush(QPalette::Active, QPalette::HighlightedText, brush3);
        palette2.setBrush(QPalette::Active, QPalette::Link, brush3);
        palette2.setBrush(QPalette::Active, QPalette::LinkVisited, brush3);
        palette2.setBrush(QPalette::Active, QPalette::AlternateBase, brush3);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipBase, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush4);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::Light, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::Dark, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::Mid, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush4);
        palette2.setBrush(QPalette::Inactive, QPalette::BrightText, brush5);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush4);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::Highlight, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::Link, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::LinkVisited, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::Light, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::Dark, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::Mid, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::BrightText, brush5);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush3);
        QBrush brush6(QColor(0, 0, 128, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Disabled, QPalette::Highlight, brush6);
        palette2.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::Link, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::LinkVisited, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush3);
        displayBG->setPalette(palette2);
        QFont font2;
        font2.setFamily(QString::fromUtf8("DejaVu Sans"));
        font2.setPointSize(60);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(50);
        displayBG->setFont(font2);
        displayBG->setFocusPolicy(Qt::NoFocus);
        displayBG->setAutoFillBackground(false);
        displayBG->setFrameShape(QFrame::Panel);
        displayBG->setFrameShadow(QFrame::Sunken);
        displayBG->setLineWidth(1);
        displayBG->setMidLineWidth(2);
        displayBG->setMargin(0);
        rangeLabel = new QLabel(displayPanel);
        rangeLabel->setObjectName(QString::fromUtf8("rangeLabel"));
        rangeLabel->setGeometry(QRect(120, 120, 71, 17));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush4);
        palette3.setBrush(QPalette::Active, QPalette::Button, brush3);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush4);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush4);
        palette3.setBrush(QPalette::Active, QPalette::Base, brush3);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush3);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush4);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush4);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush4);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush3);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush3);
        rangeLabel->setPalette(palette3);
        QFont font3;
        font3.setFamily(QString::fromUtf8("DejaVu Sans"));
        font3.setPointSize(14);
        rangeLabel->setFont(font3);
        rangeCap = new QLabel(displayPanel);
        rangeCap->setObjectName(QString::fromUtf8("rangeCap"));
        rangeCap->setGeometry(QRect(40, 120, 80, 17));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette4.setBrush(QPalette::Active, QPalette::Button, brush3);
        palette4.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette4.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette4.setBrush(QPalette::Active, QPalette::Base, brush3);
        palette4.setBrush(QPalette::Active, QPalette::Window, brush3);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette4.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette4.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette4.setBrush(QPalette::Inactive, QPalette::Window, brush3);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        palette4.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette4.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        palette4.setBrush(QPalette::Disabled, QPalette::Window, brush3);
        rangeCap->setPalette(palette4);
        QFont font4;
        font4.setFamily(QString::fromUtf8("DejaVu Sans"));
        font4.setPointSize(14);
        font4.setBold(true);
        font4.setWeight(75);
        rangeCap->setFont(font4);
        rangeCap->setStyleSheet(QString::fromUtf8("color:#fbec5d;"));
        progressBar_2 = new QProgressBar(displayPanel);
        progressBar_2->setObjectName(QString::fromUtf8("progressBar_2"));
        progressBar_2->setGeometry(QRect(30, 140, 630, 16));
        QFont font5;
        font5.setFamily(QString::fromUtf8("DejaVu Sans"));
        font5.setPointSize(14);
        font5.setBold(true);
        font5.setItalic(false);
        font5.setWeight(75);
        progressBar_2->setFont(font5);
        progressBar_2->setAutoFillBackground(false);
        progressBar_2->setStyleSheet(QString::fromUtf8("QProgressBar {\n"
"     border: 1px solid black;\n"
"     border-radius: 4px;\n"
" }\n"
"\n"
" QProgressBar::chunk {\n"
"     background-color: #1874CD;\n"
"     width:10px;\n"
"     border-radius: 10px;\n"
" }"));
        progressBar_2->setMinimum(0);
        progressBar_2->setMaximum(256000);
        progressBar_2->setValue(10000);
        progressBar_2->setTextVisible(false);
        horizontalSlider_5 = new QSlider(displayPanel);
        horizontalSlider_5->setObjectName(QString::fromUtf8("horizontalSlider_5"));
        horizontalSlider_5->setEnabled(true);
        horizontalSlider_5->setGeometry(QRect(30, 140, 630, 20));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette5.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette5.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette5.setBrush(QPalette::Active, QPalette::Shadow, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::Shadow, brush1);
        QBrush brush7(QColor(116, 116, 116, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush7);
        palette5.setBrush(QPalette::Disabled, QPalette::Text, brush7);
        palette5.setBrush(QPalette::Disabled, QPalette::ButtonText, brush7);
        palette5.setBrush(QPalette::Disabled, QPalette::Shadow, brush1);
        horizontalSlider_5->setPalette(palette5);
        horizontalSlider_5->setFont(font5);
        horizontalSlider_5->setFocusPolicy(Qt::NoFocus);
        horizontalSlider_5->setStyleSheet(QString::fromUtf8("QProgressBar {\n"
"     border: 1px solid black;\n"
"     border-radius: 4px;\n"
" }\n"
"\n"
" QProgressBar::chunk {\n"
"     background-color: #1874CD;\n"
"     width:10px;\n"
"     border-radius: 10px;\n"
" }"));
        horizontalSlider_5->setMaximum(90);
        horizontalSlider_5->setTracking(false);
        horizontalSlider_5->setOrientation(Qt::Horizontal);
        horizontalSlider_5->setTickPosition(QSlider::TicksBelow);
        horizontalSlider_5->setTickInterval(1);
        displayBG->raise();
        units->raise();
        rangeLabel->raise();
        rangeCap->raise();
        horizontalSlider_5->raise();
        progressBar_2->raise();
        ohmBox = new QGroupBox(ShortLocaterClass);
        ohmBox->setObjectName(QString::fromUtf8("ohmBox"));
        ohmBox->setGeometry(QRect(710, 33, 80, 100));
        QFont font6;
        font6.setFamily(QString::fromUtf8("DejaVu Sans"));
        ohmBox->setFont(font6);
        ohmBox->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
"border:1px solid white; \n"
"/*background-color: qlineargradient(x1: 0, y1: 0,stop: 0 #f6f7fa, stop: 1 #dadbde);*/\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #3a5976, stop: 1 #000000);\n"
"border-radius:10px;\n"
"border-bottom:1px qlineargradient(x1: 0, y1: 0,stop: 0 #f6f7fa, stop: 1 #dadbde); \n"
"border-bottom-right-radius: 0px;\n"
"border-bottom-left-radius: 0px;\n"
"}\n"
""));
        microOhms = new QPushButton(ohmBox);
        microOhms->setObjectName(QString::fromUtf8("microOhms"));
        microOhms->setGeometry(QRect(8, 20, 64, 64));
        microOhms->setStyleSheet(QString::fromUtf8("QPushButton {border: 1px solid #8f8f91; border-radius: 8px; background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #f6f7fa, stop: 1 #dadbde); color:blue;}\n"
""));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/R1.png"), QSize(), QIcon::Normal, QIcon::Off);
        microOhms->setIcon(icon);
        microOhms->setIconSize(QSize(55, 55));
        uE = new QLabel(ohmBox);
        uE->setObjectName(QString::fromUtf8("uE"));
        uE->setGeometry(QRect(47, 60, 20, 20));
        uE->setFont(font4);
        uE->setStyleSheet(QString::fromUtf8("color:blue;"));
        uE->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        selectFrame = new QFrame(ShortLocaterClass);
        selectFrame->setObjectName(QString::fromUtf8("selectFrame"));
        selectFrame->setGeometry(QRect(701, 54, 10, 60));
        selectFrame->setStyleSheet(QString::fromUtf8("/*background-color: qlineargradient(x1: 0, y1: 0,stop: 0 #f6f7fa, stop: 1 #dadbde);*/\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #3a5976, stop: 1 #000000);\n"
"border-top:1px solid white;\n"
"border-bottom:1px solid white;"));
        selectFrame->setFrameShape(QFrame::Box);
        selectFrame->setFrameShadow(QFrame::Raised);
        inputPanel = new QFrame(ShortLocaterClass);
        inputPanel->setObjectName(QString::fromUtf8("inputPanel"));
        inputPanel->setGeometry(QRect(10, 200, 693, 230));
        inputPanel->setFont(font6);
        inputPanel->setStyleSheet(QString::fromUtf8("QFrame {\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #3a5976, stop: 1 #000000);\n"
"\n"
"\n"
"\n"
" }\n"
"QLabel{\n"
"	background-color:rgba(0,0,0,0);\n"
"	color:white;\n"
"}\n"
"\n"
"QLabel::disabled {\n"
"	background-color:rgba(0,0,0,0);\n"
"	color:gray;\n"
"}"));
        inputPanel->setFrameShape(QFrame::Box);
        inputPanel->setFrameShadow(QFrame::Raised);
        functionsPanel = new QGroupBox(inputPanel);
        functionsPanel->setObjectName(QString::fromUtf8("functionsPanel"));
        functionsPanel->setGeometry(QRect(30, 10, 504, 120));
        QFont font7;
        font7.setBold(true);
        font7.setItalic(false);
        font7.setWeight(75);
        functionsPanel->setFont(font7);
        functionsPanel->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"     background-color: rgba(0,0,0,0);\n"
"     border: 1px solid white;\n"
"     border-radius: 5px;\n"
"     margin-top: 1ex; /* leave space at the top for the title */\n"
"	 font:bold 15px;	\n"
" }\n"
"\n"
" QGroupBox::title {\n"
"	border:1px solid white;\n"
"	border-radius:5px;\n"
"     subcontrol-origin: margin;\n"
"     subcontrol-position: top center; /* position at the top center */\n"
"     padding: 0 3px;\n"
"	 color:white;\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #3a5976, stop: 1 #000000);\n"
" }"));
        offset = new QPushButton(functionsPanel);
        offset->setObjectName(QString::fromUtf8("offset"));
        offset->setGeometry(QRect(202, 32, 100, 60));
        QFont font8;
        font8.setFamily(QString::fromUtf8("DejaVu Sans"));
        font8.setPointSize(13);
        font8.setBold(true);
        font8.setItalic(false);
        font8.setWeight(75);
        offset->setFont(font8);
        offset->setFocusPolicy(Qt::NoFocus);
        offset->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color:white;\n"
"border: 1px solid #2D5059;\n"
"border-radius: 20px;\n"
"background-color: qlineargradient(x1: 0, y1: 1, x2: 1, y2: 0,stop: 0 #1A74DB, stop: 0.6 #5293DE, stop:1 #FFFFFF);\n"
"font:bold;\n"
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
"}\n"
"\n"
"QPushButton:disabled\n"
"{\n"
"color:lightgrey;\n"
"background-color:grey\n"
"}"));
        offset->setIconSize(QSize(64, 64));
        buzzer = new QPushButton(functionsPanel);
        buzzer->setObjectName(QString::fromUtf8("buzzer"));
        buzzer->setGeometry(QRect(34, 30, 100, 60));
        buzzer->setFont(font8);
        buzzer->setFocusPolicy(Qt::NoFocus);
        buzzer->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color:white;\n"
"border: 1px solid #2D5059;\n"
"border-radius: 20px;\n"
"background-color: qlineargradient(x1: 0, y1: 1, x2: 1, y2: 0,stop: 0 #1A74DB, stop: 0.6 #5293DE, stop:1 #FFFFFF);\n"
"font:bold;\n"
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
"}\n"
"\n"
"QPushButton:disabled\n"
"{\n"
"color:lightgrey;\n"
"background-color:grey\n"
"}"));
        buzzer->setIconSize(QSize(64, 64));
        settings = new QPushButton(functionsPanel);
        settings->setObjectName(QString::fromUtf8("settings"));
        settings->setGeometry(QRect(370, 30, 100, 60));
        settings->setFont(font8);
        settings->setFocusPolicy(Qt::NoFocus);
        settings->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color:white;\n"
"border: 1px solid #2D5059;\n"
"border-radius: 20px;\n"
"background-color: qlineargradient(x1: 0, y1: 1, x2: 1, y2: 0,stop: 0 #1A74DB, stop: 0.6 #5293DE, stop:1 #FFFFFF);\n"
"font:bold;\n"
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
"}\n"
"\n"
"QPushButton:disabled\n"
"{\n"
"color:lightgrey;\n"
"background-color:grey\n"
"}"));
        settings->setIconSize(QSize(64, 64));
        Ranges = new QGroupBox(inputPanel);
        Ranges->setObjectName(QString::fromUtf8("Ranges"));
        Ranges->setGeometry(QRect(30, 120, 504, 100));
        Ranges->setFont(font7);
        Ranges->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"     background-color: rgba(0,0,0,0);\n"
"     border: 1px solid white;\n"
"     border-radius: 5px;\n"
"     margin-top: 1ex; /* leave space at the top for the title */\n"
"	 font:bold 15px;	\n"
" }\n"
"\n"
" QGroupBox::title {\n"
"	border:1px solid white;\n"
"	border-radius:5px;\n"
"     subcontrol-origin: margin;\n"
"     subcontrol-position: top center; /* position at the top center */\n"
"     padding: 0 3px;\n"
"	 color:white;\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #3a5976, stop: 1 #000000);\n"
" }"));
        r200But = new QPushButton(Ranges);
        r200But->setObjectName(QString::fromUtf8("r200But"));
        r200But->setGeometry(QRect(31, 37, 40, 40));
        QFont font9;
        font9.setFamily(QString::fromUtf8("DejaVu Sans"));
        font9.setPointSize(18);
        r200But->setFont(font9);
        r200But->setFocusPolicy(Qt::NoFocus);
        r200But->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"         border: 2px solid rgba(0,0,0,0);\n"
"         border-radius: 25px;\n"
"         background-color: rgba(0,0,0,0);\n"
"     }\n"
"\n"
"     QPushButton:pressed {\n"
"		background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"     }\n"
"	QPushButton::enabled{\n"
"	         border: 2px solid rgba(0,0,0,0);\n"
"         border-radius: 25px;\n"
"         background-color: rgba(0,0,0,0);\n"
"	image: url(:/svgbutton/Beryl/normal.svg);\n"
"	}\n"
" \n"
"	QPushButton::disabled{\n"
"	         border: 2px solid rgba(0,0,0,0);\n"
"         border-radius: 25px;\n"
"         background-color: rgba(0,0,0,0);\n"
"	image: url(:/svgbutton/Beryl/hovered.svg);\n"
"	}\n"
"     QPushButton:flat {\n"
"         border: none; /* no border for a flat push button */\n"
"     }\n"
"\n"
"     QPushButton:default {\n"
"         border-color: navy; /* make the default button prominent */\n"
"     }"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/svgbutton/Beryl/pressed.svg"), QSize(), QIcon::Normal, QIcon::Off);
        r200But->setIcon(icon1);
        r200But->setIconSize(QSize(48, 48));
        r200ECap = new QLabel(Ranges);
        r200ECap->setObjectName(QString::fromUtf8("r200ECap"));
        r200ECap->setGeometry(QRect(71, 47, 51, 17));
        r200ECap->setFont(font5);
        r2EBut = new QPushButton(Ranges);
        r2EBut->setObjectName(QString::fromUtf8("r2EBut"));
        r2EBut->setGeometry(QRect(205, 39, 40, 40));
        r2EBut->setFont(font9);
        r2EBut->setFocusPolicy(Qt::NoFocus);
        r2EBut->setStyleSheet(QString::fromUtf8("QPushButton {border: 0px solid rgba(0,0,0,0); border-radius: 8px; background-color: rgba(0,0,0,0);color: rgba(0,0,0,0);\n"
"}\n"
""));
        r2EBut->setIcon(icon1);
        r2EBut->setIconSize(QSize(48, 48));
        r2Ecap = new QLabel(Ranges);
        r2Ecap->setObjectName(QString::fromUtf8("r2Ecap"));
        r2Ecap->setGeometry(QRect(252, 47, 30, 17));
        r2Ecap->setFont(font5);
        r200mEBut = new QPushButton(Ranges);
        r200mEBut->setObjectName(QString::fromUtf8("r200mEBut"));
        r200mEBut->setGeometry(QRect(354, 38, 40, 40));
        r200mEBut->setFont(font9);
        r200mEBut->setFocusPolicy(Qt::NoFocus);
        r200mEBut->setStyleSheet(QString::fromUtf8("QPushButton {border: 0px solid rgba(0,0,0,0); border-radius: 8px; background-color: rgba(0,0,0,0);color: rgba(0,0,0,0);\n"
"}\n"
""));
        r200mEBut->setIcon(icon1);
        r200mEBut->setIconSize(QSize(48, 48));
        r200mECap = new QLabel(Ranges);
        r200mECap->setObjectName(QString::fromUtf8("r200mECap"));
        r200mECap->setGeometry(QRect(400, 45, 71, 17));
        r200mECap->setFont(font5);
        but200mE = new QPushButton(Ranges);
        but200mE->setObjectName(QString::fromUtf8("but200mE"));
        but200mE->setGeometry(QRect(336, 33, 150, 50));
        but200mE->setFocusPolicy(Qt::NoFocus);
        but200mE->setStyleSheet(QString::fromUtf8("QPushButton {border: 1px solid rgba(0,0,0,0); border-radius: 8px; background-color: rgba(0,0,0,0);color:blue;\n"
"}\n"
""));
        but200mE->setIconSize(QSize(70, 70));
        but2E = new QPushButton(Ranges);
        but2E->setObjectName(QString::fromUtf8("but2E"));
        but2E->setGeometry(QRect(170, 33, 150, 50));
        but2E->setFocusPolicy(Qt::NoFocus);
        but2E->setStyleSheet(QString::fromUtf8("QPushButton {border: 0px solid rgba(0,0,0,0); border-radius: 8px; background-color: rgba(0,0,0,0);color: rgba(0,0,0,0);\n"
"}\n"
""));
        but2E->setIconSize(QSize(70, 70));
        but200E = new QPushButton(Ranges);
        but200E->setObjectName(QString::fromUtf8("but200E"));
        but200E->setGeometry(QRect(10, 33, 150, 50));
        but200E->setFocusPolicy(Qt::NoFocus);
        but200E->setStyleSheet(QString::fromUtf8("QPushButton {border: 1px solid rgba(0,0,0,0); border-radius: 8px; background-color: rgba(0,0,0,0);color:blue;\n"
"}\n"
""));
        but200E->setIconSize(QSize(70, 70));
        splashWidget = new QWidget(inputPanel);
        splashWidget->setObjectName(QString::fromUtf8("splashWidget"));
        splashWidget->setGeometry(QRect(170, 110, 210, 40));
        splashWidget->setStyleSheet(QString::fromUtf8("border-radius:20px;\n"
"background-color: qradialgradient(spread:repeat, cx:0.5, cy:0.5, radius:0.077, fx:0.5, fy:0.5, stop:0 rgba(0, 169, 255, 200), stop:0.497326 rgba(0, 0, 0, 200), stop:1 rgba(0, 169, 255, 200));\n"
"border:2px solid white;"));
        splashLabel = new QLabel(splashWidget);
        splashLabel->setObjectName(QString::fromUtf8("splashLabel"));
        splashLabel->setGeometry(QRect(10, 10, 190, 20));
        splashLabel->setFont(font8);
        splashLabel->setStyleSheet(QString::fromUtf8("color:white;\n"
"border: 1px solid #2D5059;\n"
"border-radius: 20px;\n"
"font:bold;\n"
"background-color: rgb(0, 0, 0,0);\n"
"border-color: rgb(0, 0, 0,0);"));
        splashLabel->setAlignment(Qt::AlignCenter);
        Legends = new QGroupBox(inputPanel);
        Legends->setObjectName(QString::fromUtf8("Legends"));
        Legends->setGeometry(QRect(550, 10, 113, 210));
        Legends->setFont(font7);
        Legends->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"     background-color: rgba(0,0,0,0);\n"
"     border: 1px solid white;\n"
"     border-radius: 5px;\n"
"     margin-top: 1ex; /* leave space at the top for the title */\n"
"	 font:bold 15px;	\n"
" }\n"
"\n"
" QGroupBox::title {\n"
"	border:1px solid white;\n"
"	border-radius:5px;\n"
"     subcontrol-origin: margin;\n"
"     subcontrol-position: top center; /* position at the top center */\n"
"     padding: 0 3px;\n"
"	 color:white;\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #3a5976, stop: 1 #000000);\n"
" }"));
        butL = new QPushButton(Legends);
        butL->setObjectName(QString::fromUtf8("butL"));
        butL->setGeometry(QRect(33, 143, 45, 45));
        butL->setFont(font6);
        butL->setFocusPolicy(Qt::NoFocus);
        butL->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color:rgba(0,0,0,0);\n"
"border:1px solid rgba(0,0,0,0);\n"
"}\n"
""));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/48L.png"), QSize(), QIcon::Normal, QIcon::Off);
        butL->setIcon(icon2);
        butL->setIconSize(QSize(40, 40));
        lblLeft = new QLineEdit(Legends);
        lblLeft->setObjectName(QString::fromUtf8("lblLeft"));
        lblLeft->setGeometry(QRect(8, 185, 101, 20));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        QBrush brush8(QColor(89, 109, 163, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette6.setBrush(QPalette::Active, QPalette::Button, brush8);
        QBrush brush9(QColor(132, 132, 131, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette6.setBrush(QPalette::Active, QPalette::Light, brush9);
        QBrush brush10(QColor(110, 110, 109, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette6.setBrush(QPalette::Active, QPalette::Midlight, brush10);
        QBrush brush11(QColor(44, 44, 43, 255));
        brush11.setStyle(Qt::SolidPattern);
        palette6.setBrush(QPalette::Active, QPalette::Dark, brush11);
        QBrush brush12(QColor(58, 58, 58, 255));
        brush12.setStyle(Qt::SolidPattern);
        palette6.setBrush(QPalette::Active, QPalette::Mid, brush12);
        palette6.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette6.setBrush(QPalette::Active, QPalette::BrightText, brush1);
        palette6.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette6.setBrush(QPalette::Active, QPalette::Base, brush8);
        palette6.setBrush(QPalette::Active, QPalette::Window, brush8);
        palette6.setBrush(QPalette::Active, QPalette::Shadow, brush3);
        palette6.setBrush(QPalette::Active, QPalette::AlternateBase, brush11);
        QBrush brush13(QColor(255, 255, 220, 255));
        brush13.setStyle(Qt::SolidPattern);
        palette6.setBrush(QPalette::Active, QPalette::ToolTipBase, brush13);
        palette6.setBrush(QPalette::Active, QPalette::ToolTipText, brush3);
        palette6.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::Button, brush8);
        palette6.setBrush(QPalette::Inactive, QPalette::Light, brush9);
        palette6.setBrush(QPalette::Inactive, QPalette::Midlight, brush10);
        palette6.setBrush(QPalette::Inactive, QPalette::Dark, brush11);
        palette6.setBrush(QPalette::Inactive, QPalette::Mid, brush12);
        palette6.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::BrightText, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::Base, brush8);
        palette6.setBrush(QPalette::Inactive, QPalette::Window, brush8);
        palette6.setBrush(QPalette::Inactive, QPalette::Shadow, brush3);
        palette6.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush11);
        palette6.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush13);
        palette6.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush3);
        palette6.setBrush(QPalette::Disabled, QPalette::WindowText, brush11);
        palette6.setBrush(QPalette::Disabled, QPalette::Button, brush8);
        palette6.setBrush(QPalette::Disabled, QPalette::Light, brush9);
        palette6.setBrush(QPalette::Disabled, QPalette::Midlight, brush10);
        palette6.setBrush(QPalette::Disabled, QPalette::Dark, brush11);
        palette6.setBrush(QPalette::Disabled, QPalette::Mid, brush12);
        palette6.setBrush(QPalette::Disabled, QPalette::Text, brush11);
        palette6.setBrush(QPalette::Disabled, QPalette::BrightText, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::ButtonText, brush11);
        palette6.setBrush(QPalette::Disabled, QPalette::Base, brush8);
        palette6.setBrush(QPalette::Disabled, QPalette::Window, brush8);
        palette6.setBrush(QPalette::Disabled, QPalette::Shadow, brush3);
        QBrush brush14(QColor(88, 88, 87, 255));
        brush14.setStyle(Qt::SolidPattern);
        palette6.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush14);
        palette6.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush13);
        palette6.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush3);
        lblLeft->setPalette(palette6);
        QFont font10;
        font10.setFamily(QString::fromUtf8("DejaVu Sans"));
        font10.setPointSize(10);
        font10.setBold(false);
        font10.setWeight(50);
        lblLeft->setFont(font10);
        lblLeft->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"border:1px solid blue;\n"
"border-radius:10;\n"
"background-color:#596DA3;\n"
"}"));
        lblLeft->setFrame(false);
        lblLeft->setAlignment(Qt::AlignCenter);
        lblLeft->setReadOnly(true);
        butR = new QPushButton(Legends);
        butR->setObjectName(QString::fromUtf8("butR"));
        butR->setGeometry(QRect(33, 18, 45, 45));
        QFont font11;
        font11.setFamily(QString::fromUtf8("DejaVu Sans"));
        font11.setPointSize(12);
        butR->setFont(font11);
        butR->setFocusPolicy(Qt::NoFocus);
        butR->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"\n"
"background-color:rgba(0,0,0,0);\n"
"border:1px solid rgba(0,0,0,0);\n"
"}\n"
""));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/48R.png"), QSize(), QIcon::Normal, QIcon::Off);
        butR->setIcon(icon3);
        butR->setIconSize(QSize(40, 40));
        lblRight = new QLineEdit(Legends);
        lblRight->setObjectName(QString::fromUtf8("lblRight"));
        lblRight->setGeometry(QRect(8, 60, 101, 20));
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette7.setBrush(QPalette::Active, QPalette::Button, brush8);
        palette7.setBrush(QPalette::Active, QPalette::Light, brush9);
        palette7.setBrush(QPalette::Active, QPalette::Midlight, brush10);
        palette7.setBrush(QPalette::Active, QPalette::Dark, brush11);
        palette7.setBrush(QPalette::Active, QPalette::Mid, brush12);
        palette7.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette7.setBrush(QPalette::Active, QPalette::BrightText, brush1);
        palette7.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette7.setBrush(QPalette::Active, QPalette::Base, brush8);
        palette7.setBrush(QPalette::Active, QPalette::Window, brush8);
        palette7.setBrush(QPalette::Active, QPalette::Shadow, brush3);
        palette7.setBrush(QPalette::Active, QPalette::AlternateBase, brush11);
        palette7.setBrush(QPalette::Active, QPalette::ToolTipBase, brush13);
        palette7.setBrush(QPalette::Active, QPalette::ToolTipText, brush3);
        palette7.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette7.setBrush(QPalette::Inactive, QPalette::Button, brush8);
        palette7.setBrush(QPalette::Inactive, QPalette::Light, brush9);
        palette7.setBrush(QPalette::Inactive, QPalette::Midlight, brush10);
        palette7.setBrush(QPalette::Inactive, QPalette::Dark, brush11);
        palette7.setBrush(QPalette::Inactive, QPalette::Mid, brush12);
        palette7.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette7.setBrush(QPalette::Inactive, QPalette::BrightText, brush1);
        palette7.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette7.setBrush(QPalette::Inactive, QPalette::Base, brush8);
        palette7.setBrush(QPalette::Inactive, QPalette::Window, brush8);
        palette7.setBrush(QPalette::Inactive, QPalette::Shadow, brush3);
        palette7.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush11);
        palette7.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush13);
        palette7.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush3);
        palette7.setBrush(QPalette::Disabled, QPalette::WindowText, brush11);
        palette7.setBrush(QPalette::Disabled, QPalette::Button, brush8);
        palette7.setBrush(QPalette::Disabled, QPalette::Light, brush9);
        palette7.setBrush(QPalette::Disabled, QPalette::Midlight, brush10);
        palette7.setBrush(QPalette::Disabled, QPalette::Dark, brush11);
        palette7.setBrush(QPalette::Disabled, QPalette::Mid, brush12);
        palette7.setBrush(QPalette::Disabled, QPalette::Text, brush11);
        palette7.setBrush(QPalette::Disabled, QPalette::BrightText, brush1);
        palette7.setBrush(QPalette::Disabled, QPalette::ButtonText, brush11);
        palette7.setBrush(QPalette::Disabled, QPalette::Base, brush8);
        palette7.setBrush(QPalette::Disabled, QPalette::Window, brush8);
        palette7.setBrush(QPalette::Disabled, QPalette::Shadow, brush3);
        palette7.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush14);
        palette7.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush13);
        palette7.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush3);
        lblRight->setPalette(palette7);
        lblRight->setFont(font10);
        lblRight->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"border:1px solid blue;\n"
"border-radius:10;\n"
"background-color:#596DA3;\n"
"}"));
        lblRight->setFrame(false);
        lblRight->setAlignment(Qt::AlignCenter);
        lblRight->setReadOnly(true);
        lblMiddle = new QLineEdit(Legends);
        lblMiddle->setObjectName(QString::fromUtf8("lblMiddle"));
        lblMiddle->setGeometry(QRect(8, 123, 101, 20));
        QPalette palette8;
        palette8.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette8.setBrush(QPalette::Active, QPalette::Button, brush8);
        palette8.setBrush(QPalette::Active, QPalette::Light, brush9);
        palette8.setBrush(QPalette::Active, QPalette::Midlight, brush10);
        palette8.setBrush(QPalette::Active, QPalette::Dark, brush11);
        palette8.setBrush(QPalette::Active, QPalette::Mid, brush12);
        palette8.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette8.setBrush(QPalette::Active, QPalette::BrightText, brush1);
        palette8.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette8.setBrush(QPalette::Active, QPalette::Base, brush8);
        palette8.setBrush(QPalette::Active, QPalette::Window, brush8);
        palette8.setBrush(QPalette::Active, QPalette::Shadow, brush3);
        palette8.setBrush(QPalette::Active, QPalette::AlternateBase, brush11);
        palette8.setBrush(QPalette::Active, QPalette::ToolTipBase, brush13);
        palette8.setBrush(QPalette::Active, QPalette::ToolTipText, brush3);
        palette8.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette8.setBrush(QPalette::Inactive, QPalette::Button, brush8);
        palette8.setBrush(QPalette::Inactive, QPalette::Light, brush9);
        palette8.setBrush(QPalette::Inactive, QPalette::Midlight, brush10);
        palette8.setBrush(QPalette::Inactive, QPalette::Dark, brush11);
        palette8.setBrush(QPalette::Inactive, QPalette::Mid, brush12);
        palette8.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette8.setBrush(QPalette::Inactive, QPalette::BrightText, brush1);
        palette8.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette8.setBrush(QPalette::Inactive, QPalette::Base, brush8);
        palette8.setBrush(QPalette::Inactive, QPalette::Window, brush8);
        palette8.setBrush(QPalette::Inactive, QPalette::Shadow, brush3);
        palette8.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush11);
        palette8.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush13);
        palette8.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush3);
        palette8.setBrush(QPalette::Disabled, QPalette::WindowText, brush11);
        palette8.setBrush(QPalette::Disabled, QPalette::Button, brush8);
        palette8.setBrush(QPalette::Disabled, QPalette::Light, brush9);
        palette8.setBrush(QPalette::Disabled, QPalette::Midlight, brush10);
        palette8.setBrush(QPalette::Disabled, QPalette::Dark, brush11);
        palette8.setBrush(QPalette::Disabled, QPalette::Mid, brush12);
        palette8.setBrush(QPalette::Disabled, QPalette::Text, brush11);
        palette8.setBrush(QPalette::Disabled, QPalette::BrightText, brush1);
        palette8.setBrush(QPalette::Disabled, QPalette::ButtonText, brush11);
        palette8.setBrush(QPalette::Disabled, QPalette::Base, brush8);
        palette8.setBrush(QPalette::Disabled, QPalette::Window, brush8);
        palette8.setBrush(QPalette::Disabled, QPalette::Shadow, brush3);
        palette8.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush14);
        palette8.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush13);
        palette8.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush3);
        lblMiddle->setPalette(palette8);
        lblMiddle->setFont(font10);
        lblMiddle->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"border:1px solid blue;\n"
"border-radius:10;\n"
"background-color:#596DA3;\n"
"}"));
        lblMiddle->setFrame(false);
        lblMiddle->setAlignment(Qt::AlignCenter);
        lblMiddle->setReadOnly(true);
        butM = new QPushButton(Legends);
        butM->setObjectName(QString::fromUtf8("butM"));
        butM->setGeometry(QRect(33, 81, 45, 45));
        butM->setFont(font11);
        butM->setFocusPolicy(Qt::NoFocus);
        butM->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color:rgba(0,0,0,0);\n"
"border:1px solid rgba(0,0,0,0);\n"
"}\n"
""));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/48M.png"), QSize(), QIcon::Normal, QIcon::Off);
        butM->setIcon(icon4);
        butM->setIconSize(QSize(40, 40));
        temp4 = new QGroupBox(ShortLocaterClass);
        temp4->setObjectName(QString::fromUtf8("temp4"));
        temp4->setGeometry(QRect(710, 432, 80, 100));
        temp4->setFont(font6);
        temp4->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
"border:1px solid white; background-color: #dadbde;border-radius:10px;\n"
"border-top:1px qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #f6f7fa, stop: 1 #dadbde); border-top-right-radius: 0px;\n"
" border-top-left-radius: 0px;\n"
"border-top:1px solid gray;\n"
";border-bottom-right-radius: 0px;\n"
" border-bottom-left-radius: 0px;\n"
"border-top:1px solid gray; border-top-right-radius: 0px;\n"
" border-top-left-radius: 0px;\n"
"}\n"
""));
        ohmMeter_3 = new QPushButton(temp4);
        ohmMeter_3->setObjectName(QString::fromUtf8("ohmMeter_3"));
        ohmMeter_3->setGeometry(QRect(8, 20, 64, 64));
        ohmMeter_3->setStyleSheet(QString::fromUtf8("QPushButton {border: 1px solid #8f8f91; border-radius: 8px; background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #f6f7fa, stop: 1 #dadbde); color:blue;}\n"
""));
        ohmMeter_3->setIconSize(QSize(55, 55));
        appBox = new QGroupBox(ShortLocaterClass);
        appBox->setObjectName(QString::fromUtf8("appBox"));
        appBox->setGeometry(QRect(710, 232, 80, 100));
        appBox->setFont(font6);
        appBox->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
"border:1px solid white; background-color: #dadbde;border-radius:10px;\n"
"border-top:1px qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #f6f7fa, stop: 1 #dadbde); border-top-right-radius: 0px;\n"
" border-top-left-radius: 0px;\n"
"border-top:1px solid gray;\n"
";border-bottom-right-radius: 0px;\n"
" border-bottom-left-radius: 0px;\n"
"border-top:1px solid gray; border-top-right-radius: 0px;\n"
" border-top-left-radius: 0px;\n"
"}\n"
""));
        selectApp = new QPushButton(appBox);
        selectApp->setObjectName(QString::fromUtf8("selectApp"));
        selectApp->setGeometry(QRect(8, 20, 64, 64));
        selectApp->setStyleSheet(QString::fromUtf8("QPushButton {border: 1px solid #8f8f91; border-radius: 8px; background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #f6f7fa, stop: 1 #dadbde); color:blue;}\n"
""));
        selectApp->setIconSize(QSize(80, 60));
        ExitBox = new QGroupBox(ShortLocaterClass);
        ExitBox->setObjectName(QString::fromUtf8("ExitBox"));
        ExitBox->setGeometry(QRect(710, 532, 80, 61));
        ExitBox->setFont(font6);
        ExitBox->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
"border:1px solid white; background-color: #dadbde;border-radius:10px;\n"
"border-top:1px qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #f6f7fa, stop: 1 #dadbde); border-top-right-radius: 0px;\n"
" border-top-left-radius: 0px;\n"
"border-top:1px solid gray;\n"
"}\n"
""));
        exit = new QPushButton(ExitBox);
        exit->setObjectName(QString::fromUtf8("exit"));
        exit->setGeometry(QRect(5, 1, 60, 70));
        exit->setFocusPolicy(Qt::NoFocus);
        exit->setStyleSheet(QString::fromUtf8("QPushButton {border: 1px solid rgba(0,0,0,0); border-radius: 8px; background-color: rgba(0,0,0,0);color:blue;\n"
"image: url(:/logout-icon.png);}\n"
""));
        exit->setIconSize(QSize(70, 70));
        graphBox = new QGroupBox(ShortLocaterClass);
        graphBox->setObjectName(QString::fromUtf8("graphBox"));
        graphBox->setGeometry(QRect(710, 132, 80, 100));
        graphBox->setFont(font6);
        graphBox->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
"border:1px solid white; background-color: #dadbde;border-radius:10px;border-bottom:1px qlineargradient(x1: 0, y1: 0,stop: 0 #f6f7fa, stop: 1 #dadbde);border-bottom-right-radius: 0px;\n"
" border-bottom-left-radius: 0px;\n"
"border-top:1px solid gray; border-top-right-radius: 0px;\n"
" border-top-left-radius: 0px;\n"
"}\n"
""));
        graph = new QPushButton(graphBox);
        graph->setObjectName(QString::fromUtf8("graph"));
        graph->setGeometry(QRect(8, 20, 64, 64));
        graph->setStyleSheet(QString::fromUtf8("QPushButton {border: 1px solid #8f8f91; border-radius: 8px; background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #f6f7fa, stop: 1 #dadbde); color:blue;}\n"
""));
        graph->setIconSize(QSize(80, 90));
        temp3 = new QGroupBox(ShortLocaterClass);
        temp3->setObjectName(QString::fromUtf8("temp3"));
        temp3->setGeometry(QRect(710, 332, 80, 100));
        temp3->setFont(font6);
        temp3->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
"border:1px solid white; background-color: #dadbde;border-radius:10px;\n"
"border-top:1px qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #f6f7fa, stop: 1 #dadbde); border-top-right-radius: 0px;\n"
" border-top-left-radius: 0px;\n"
"border-top:1px solid gray;\n"
";border-bottom-right-radius: 0px;\n"
" border-bottom-left-radius: 0px;\n"
"border-top:1px solid gray; border-top-right-radius: 0px;\n"
" border-top-left-radius: 0px;\n"
"}\n"
""));
        ohmMeter_2 = new QPushButton(temp3);
        ohmMeter_2->setObjectName(QString::fromUtf8("ohmMeter_2"));
        ohmMeter_2->setGeometry(QRect(8, 20, 64, 64));
        ohmMeter_2->setStyleSheet(QString::fromUtf8("QPushButton {border: 1px solid #8f8f91; border-radius: 8px; background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #f6f7fa, stop: 1 #dadbde); color:blue;}\n"
""));
        ohmMeter_2->setIconSize(QSize(55, 55));
        debugPanel = new QGroupBox(ShortLocaterClass);
        debugPanel->setObjectName(QString::fromUtf8("debugPanel"));
        debugPanel->setGeometry(QRect(10, 433, 693, 160));
        QFont font12;
        font12.setBold(true);
        font12.setWeight(75);
        debugPanel->setFont(font12);
        debugPanel->setStyleSheet(QString::fromUtf8("QGroupBox{border:1px solid black; background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #ffffff, stop: 1 #dadbff);border-radius:10px;}\n"
" QGroupBox::title {\n"
"     subcontrol-origin: margin;\n"
"     subcontrol-position: top left; /* position at the top center */\n"
"     padding: 0 3px;\n"
"	 border: 2px solid black;\n"
" }"));
        pushButton_16 = new QPushButton(debugPanel);
        pushButton_16->setObjectName(QString::fromUtf8("pushButton_16"));
        pushButton_16->setGeometry(QRect(580, 0, 50, 49));
        pushButton_16->setStyleSheet(QString::fromUtf8("QPushButton {border: 1px solid #8f8f91; border-radius: 8px; background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #f6f7fa, stop: 1 #dadbde); color:blue;}\n"
""));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/Letter-R-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_16->setIcon(icon5);
        pushButton_16->setIconSize(QSize(48, 48));
        pushButton = new QPushButton(debugPanel);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(640, 0, 50, 49));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton {border: 1px solid #8f8f91; border-radius: 8px; background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #f6f7fa, stop: 1 #dadbde); color:blue;}\n"
""));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/Control-Panel-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon6);
        pushButton->setIconSize(QSize(48, 48));
        HAADC = new QPushButton(debugPanel);
        HAADC->setObjectName(QString::fromUtf8("HAADC"));
        HAADC->setGeometry(QRect(520, 0, 50, 49));
        HAADC->setStyleSheet(QString::fromUtf8("QPushButton {border: 1px solid #8f8f91; border-radius: 8px; background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #f6f7fa, stop: 1 #dadbde); color:blue;}\n"
""));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/Letter-A-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        HAADC->setIcon(icon7);
        HAADC->setIconSize(QSize(48, 48));
        calibrateDisplay = new QCheckBox(debugPanel);
        calibrateDisplay->setObjectName(QString::fromUtf8("calibrateDisplay"));
        calibrateDisplay->setGeometry(QRect(330, 0, 170, 31));
        QFont font13;
        font13.setBold(false);
        font13.setItalic(false);
        font13.setWeight(50);
        calibrateDisplay->setFont(font13);
        calibrateDisplay->setFocusPolicy(Qt::NoFocus);
        calibrateDisplay->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
"font: 14px;\n"
"color:black;\n"
"}\n"
" QCheckBox::indicator {\n"
"     width: 20px;\n"
"     height:20px;\n"
"   border: 2px solid black;\n"
"	 border-radius:10;\n"
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
        haadcFrame = new QGroupBox(debugPanel);
        haadcFrame->setObjectName(QString::fromUtf8("haadcFrame"));
        haadcFrame->setGeometry(QRect(614, 52, 80, 100));
        haadcFrame->setFont(font6);
        haadcFrame->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
"border:1px solid white; background-color: #dadbde;border-radius:10px;\n"
"border-top:1px qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #f6f7fa, stop: 1 #dadbde); border-top-right-radius: 0px;\n"
" border-top-left-radius: 0px;\n"
"border-top:1px solid gray;\n"
";border-bottom-right-radius: 0px;\n"
" border-bottom-left-radius: 0px;\n"
"border-top:1px solid gray; border-top-right-radius: 0px;\n"
" border-top-left-radius: 0px;\n"
"}\n"
""));
        haadcClose = new QPushButton(haadcFrame);
        haadcClose->setObjectName(QString::fromUtf8("haadcClose"));
        haadcClose->setGeometry(QRect(0, 70, 80, 30));
        label_22 = new QLabel(debugPanel);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(280, 64, 110, 17));
        label_22->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_23 = new QLabel(debugPanel);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(270, 128, 120, 30));
        label_23->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        adcRawData = new QLineEdit(debugPanel);
        adcRawData->setObjectName(QString::fromUtf8("adcRawData"));
        adcRawData->setGeometry(QRect(390, 58, 210, 29));
        QFont font14;
        font14.setFamily(QString::fromUtf8("DejaVu Sans"));
        font14.setBold(true);
        font14.setWeight(75);
        adcRawData->setFont(font14);
        adcRawData->setAlignment(Qt::AlignCenter);
        adcConvData = new QLineEdit(debugPanel);
        adcConvData->setObjectName(QString::fromUtf8("adcConvData"));
        adcConvData->setGeometry(QRect(390, 126, 210, 29));
        adcConvData->setFont(font14);
        adcConvData->setAlignment(Qt::AlignCenter);
        displayInput = new QLineEdit(debugPanel);
        displayInput->setObjectName(QString::fromUtf8("displayInput"));
        displayInput->setGeometry(QRect(390, 92, 210, 29));
        displayInput->setFont(font14);
        displayInput->setAlignment(Qt::AlignCenter);
        label_25 = new QLabel(debugPanel);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setGeometry(QRect(270, 95, 120, 30));
        label_25->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        pushButton_2 = new QPushButton(debugPanel);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(210, 32, 71, 30));
        pushButton_3 = new QPushButton(debugPanel);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(210, 68, 71, 30));
        lineEdit = new QLineEdit(debugPanel);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(150, 70, 61, 29));
        openShortEnable = new QCheckBox(debugPanel);
        openShortEnable->setObjectName(QString::fromUtf8("openShortEnable"));
        openShortEnable->setGeometry(QRect(330, 30, 160, 30));
        openShortEnable->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
"font: 14px;\n"
"color:black;\n"
"}\n"
" QCheckBox::indicator {\n"
"     width: 20px;\n"
"     height:20px;\n"
"   border: 2px solid black;\n"
"	 border-radius:10;\n"
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
        openShortEnable->setChecked(false);
        displayOffset = new QLineEdit(debugPanel);
        displayOffset->setObjectName(QString::fromUtf8("displayOffset"));
        displayOffset->setGeometry(QRect(150, 34, 61, 29));
        left = new QPushButton(debugPanel);
        left->setObjectName(QString::fromUtf8("left"));
        left->setGeometry(QRect(10, 125, 40, 33));
        left->setFocusPolicy(Qt::NoFocus);
        left->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"         border: 2px solid rgba(0,0,0,0);\n"
"         border-radius: 15px;\n"
"         background-color: rgba(0,0,0,0);\n"
"     }\n"
"\n"
"     QPushButton:pressed {\n"
"		background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"     }\n"
"\n"
"     QPushButton:flat {\n"
"         border: none; /* no border for a flat push button */\n"
"     }\n"
"\n"
"     QPushButton:default {\n"
"         border-color: navy; /* make the default button prominent */\n"
"     }"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/Button-Previous-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        left->setIcon(icon8);
        left->setIconSize(QSize(32, 32));
        right = new QPushButton(debugPanel);
        right->setObjectName(QString::fromUtf8("right"));
        right->setGeometry(QRect(42, 125, 40, 33));
        right->setFocusPolicy(Qt::NoFocus);
        right->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"         border: 2px solid rgba(0,0,0,0);\n"
"         border-radius: 15px;\n"
"         background-color: rgba(0,0,0,0);\n"
"     }\n"
"\n"
"     QPushButton:pressed {\n"
"		background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"     }\n"
"\n"
"     QPushButton:flat {\n"
"         border: none; /* no border for a flat push button */\n"
"     }\n"
"\n"
"     QPushButton:default {\n"
"         border-color: navy; /* make the default button prominent */\n"
"     }"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/Button-Next-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        right->setIcon(icon9);
        right->setIconSize(QSize(32, 32));
        down = new QPushButton(debugPanel);
        down->setObjectName(QString::fromUtf8("down"));
        down->setGeometry(QRect(106, 125, 40, 33));
        down->setFocusPolicy(Qt::NoFocus);
        down->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"         border: 2px solid rgba(0,0,0,0);\n"
"         border-radius: 15px;\n"
"         background-color: rgba(0,0,0,0);\n"
"     }\n"
"\n"
"     QPushButton:pressed {\n"
"		background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"     }\n"
"\n"
"     QPushButton:flat {\n"
"         border: none; /* no border for a flat push button */\n"
"     }\n"
"\n"
"     QPushButton:default {\n"
"         border-color: navy; /* make the default button prominent */\n"
"     }"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/Button-Download-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        down->setIcon(icon10);
        down->setIconSize(QSize(32, 32));
        up = new QPushButton(debugPanel);
        up->setObjectName(QString::fromUtf8("up"));
        up->setGeometry(QRect(74, 125, 40, 33));
        up->setFocusPolicy(Qt::NoFocus);
        up->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"         border: 2px solid rgba(0,0,0,0);\n"
"         border-radius: 15px;\n"
"         background-color: rgba(0,0,0,0);\n"
"     }\n"
"\n"
"     QPushButton:pressed {\n"
"		background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"     }\n"
"\n"
"     QPushButton:flat {\n"
"         border: none; /* no border for a flat push button */\n"
"     }\n"
"\n"
"     QPushButton:default {\n"
"         border-color: navy; /* make the default button prominent */\n"
"     }"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/Button-Upload-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        up->setIcon(icon11);
        up->setIconSize(QSize(32, 32));
        checkBox = new QCheckBox(debugPanel);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(150, 7, 130, 22));
        selectLib = new QGroupBox(debugPanel);
        selectLib->setObjectName(QString::fromUtf8("selectLib"));
        selectLib->setGeometry(QRect(17, 24, 120, 41));
        oldLib = new QRadioButton(selectLib);
        oldLib->setObjectName(QString::fromUtf8("oldLib"));
        oldLib->setGeometry(QRect(10, 0, 115, 22));
        oldLib->setChecked(false);
        newLib = new QRadioButton(selectLib);
        newLib->setObjectName(QString::fromUtf8("newLib"));
        newLib->setGeometry(QRect(10, 20, 115, 22));
        newLib->setChecked(true);
        label_2 = new QLabel(debugPanel);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(150, 97, 67, 17));
        SpinSamples = new QSpinBox(debugPanel);
        SpinSamples->setObjectName(QString::fromUtf8("SpinSamples"));
        SpinSamples->setGeometry(QRect(180, 109, 96, 48));
        SpinSamples->setStyleSheet(QString::fromUtf8("QSpinBox::up-button {\n"
"     width: 40px; \n"
" }\n"
"QSpinBox::down-button {\n"
"     width: 40px;\n"
" }"));
        pushButton_16->raise();
        pushButton->raise();
        HAADC->raise();
        calibrateDisplay->raise();
        haadcFrame->raise();
        label_22->raise();
        label_23->raise();
        adcRawData->raise();
        adcConvData->raise();
        displayInput->raise();
        label_25->raise();
        pushButton_2->raise();
        pushButton_3->raise();
        lineEdit->raise();
        openShortEnable->raise();
        displayOffset->raise();
        left->raise();
        right->raise();
        down->raise();
        up->raise();
        checkBox->raise();
        selectLib->raise();
        SpinSamples->raise();
        label_2->raise();
        HAADC_WIDGET = new QWidget(ShortLocaterClass);
        HAADC_WIDGET->setObjectName(QString::fromUtf8("HAADC_WIDGET"));
        HAADC_WIDGET->setGeometry(QRect(633, 525, 50, 2));
        HAADC_WIDGET->setStyleSheet(QString::fromUtf8(""));
        frontPanel_SHLOC = new QFrame(ShortLocaterClass);
        frontPanel_SHLOC->setObjectName(QString::fromUtf8("frontPanel_SHLOC"));
        frontPanel_SHLOC->setGeometry(QRect(10, 434, 693, 160));
        frontPanel_SHLOC->setStyleSheet(QString::fromUtf8("/*QFrame{border:1px solid black; background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #ffffff, stop: 1 #dadbff);border-radius:10px;}\n"
"QLabel{border:1px solid rgba(0,0,0,0);}*/\n"
"QFrame {\n"
"      background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 1 #3a5976, stop: 0 #000000);\n"
"     border: 2px solid white;\n"
"     border-radius: 5px;\n"
"     margin-top: 0ex; /* leave space at the top for the title */\n"
" }\n"
""));
        frontPanel_SHLOC->setFrameShape(QFrame::StyledPanel);
        frontPanel_SHLOC->setFrameShadow(QFrame::Raised);
        framePowerUSB = new QFrame(frontPanel_SHLOC);
        framePowerUSB->setObjectName(QString::fromUtf8("framePowerUSB"));
        framePowerUSB->setGeometry(QRect(5, 6, 47, 150));
        framePowerUSB->setStyleSheet(QString::fromUtf8("/*QFrame{border:2px solid black; background-color: rgba(0,0,0,0);border-radius:10px;}\n"
"QLabel{border:1px solid rgba(0,0,0,0);}*/\n"
"QFrame{border:1px solid black; background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #ffffff, stop: 1 #dadbff);border-radius:10px;}\n"
"QLabel{border:1px solid rgba(0,0,0,0);\n"
"background-color: rgb(0, 0, 0,0);\n"
"}\n"
"\n"
""));
        framePowerUSB->setFrameShape(QFrame::StyledPanel);
        framePowerUSB->setFrameShadow(QFrame::Raised);
        fp_usbSocket = new QFrame(framePowerUSB);
        fp_usbSocket->setObjectName(QString::fromUtf8("fp_usbSocket"));
        fp_usbSocket->setGeometry(QRect(2, 96, 43, 23));
        fp_usbSocket->setStyleSheet(QString::fromUtf8("border:1px rgba(0,0,0,0);border-radius:7px;\n"
"background-color: rgb(0, 0, 0,0);\n"
"image: url(:/fp_images/usb.png);"));
        fp_usbSocket->setFrameShape(QFrame::StyledPanel);
        fp_usbSocket->setFrameShadow(QFrame::Raised);
        fp_usbSymbol = new QFrame(framePowerUSB);
        fp_usbSymbol->setObjectName(QString::fromUtf8("fp_usbSymbol"));
        fp_usbSymbol->setGeometry(QRect(5, 120, 38, 19));
        fp_usbSymbol->setStyleSheet(QString::fromUtf8("border:1px rgba(0,0,0,0);border-radius:5px;\n"
"background-color: rgb(0, 0, 0,0);\n"
"image: url(:/fp_images/usb_symbol.png);"));
        fp_usbSymbol->setFrameShape(QFrame::StyledPanel);
        fp_usbSymbol->setFrameShadow(QFrame::Raised);
        fp_powerButton = new QFrame(framePowerUSB);
        fp_powerButton->setObjectName(QString::fromUtf8("fp_powerButton"));
        fp_powerButton->setGeometry(QRect(4, 26, 38, 38));
        fp_powerButton->setStyleSheet(QString::fromUtf8("border:1px solid gray;border-radius:5px;\n"
"image: url(:/fp_images/power.png);"));
        fp_powerButton->setFrameShape(QFrame::StyledPanel);
        fp_powerButton->setFrameShadow(QFrame::Raised);
        fp_powerLabel = new QLabel(framePowerUSB);
        fp_powerLabel->setObjectName(QString::fromUtf8("fp_powerLabel"));
        fp_powerLabel->setGeometry(QRect(-3, 66, 50, 17));
        QFont font15;
        font15.setFamily(QString::fromUtf8("DejaVu Sans"));
        font15.setPointSize(9);
        font15.setBold(false);
        font15.setWeight(50);
        fp_powerLabel->setFont(font15);
        fp_powerLabel->setStyleSheet(QString::fromUtf8("color: rgb(53, 53, 53);"));
        analogHighway = new QFrame(frontPanel_SHLOC);
        analogHighway->setObjectName(QString::fromUtf8("analogHighway"));
        analogHighway->setGeometry(QRect(54, 6, 300, 72));
        analogHighway->setStyleSheet(QString::fromUtf8("/*QFrame{border:2px solid black; background-color: rgba(0,0,0,0);border-radius:10px;}\n"
"QLabel{border:1px solid rgba(0,0,0,0);}*/\n"
"QFrame{border:1px solid black; background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #ffffff, stop: 1 #dadbff);border-radius:10px;}\n"
"QLabel{border:1px solid rgba(0,0,0,0);\n"
"background-color: rgb(0, 0, 0,0);\n"
"}\n"
"\n"
""));
        analogHighway->setFrameShape(QFrame::StyledPanel);
        analogHighway->setFrameShadow(QFrame::Raised);
        ah3_label = new QLabel(analogHighway);
        ah3_label->setObjectName(QString::fromUtf8("ah3_label"));
        ah3_label->setGeometry(QRect(100, 11, 38, 17));
        ah3_label->setFont(font15);
        ah3_label->setStyleSheet(QString::fromUtf8("color: rgb(53, 53, 53);"));
        ah1_label = new QLabel(analogHighway);
        ah1_label->setObjectName(QString::fromUtf8("ah1_label"));
        ah1_label->setGeometry(QRect(26, 11, 38, 17));
        ah1_label->setFont(font15);
        ah1_label->setStyleSheet(QString::fromUtf8("color: rgb(53, 53, 53);"));
        ah1_outer = new QFrame(analogHighway);
        ah1_outer->setObjectName(QString::fromUtf8("ah1_outer"));
        ah1_outer->setGeometry(QRect(22, 26, 41, 41));
        ah1_outer->setStyleSheet(QString::fromUtf8("border:1px solid gray;border-radius:20px;\n"
"image: url(:/new/prefix1/Button-Blank-Gray-icon.png);"));
        ah1_outer->setFrameShape(QFrame::StyledPanel);
        ah1_outer->setFrameShadow(QFrame::Raised);
        ah1_inner = new QFrame(ah1_outer);
        ah1_inner->setObjectName(QString::fromUtf8("ah1_inner"));
        ah1_inner->setGeometry(QRect(15, 15, 10, 10));
        ah1_inner->setStyleSheet(QString::fromUtf8("border:1px solid gray;border-radius:4px;\n"
""));
        ah1_inner->setFrameShape(QFrame::StyledPanel);
        ah1_inner->setFrameShadow(QFrame::Raised);
        ah3_outer = new QFrame(analogHighway);
        ah3_outer->setObjectName(QString::fromUtf8("ah3_outer"));
        ah3_outer->setGeometry(QRect(96, 26, 41, 41));
        ah3_outer->setStyleSheet(QString::fromUtf8("border:1px solid gray;border-radius:20px;\n"
"image: url(:/new/prefix1/Button-Blank-Gray-icon.png);"));
        ah3_outer->setFrameShape(QFrame::StyledPanel);
        ah3_outer->setFrameShadow(QFrame::Raised);
        ah3_inner = new QFrame(ah3_outer);
        ah3_inner->setObjectName(QString::fromUtf8("ah3_inner"));
        ah3_inner->setGeometry(QRect(15, 15, 10, 10));
        ah3_inner->setStyleSheet(QString::fromUtf8("border:1px solid gray;border-radius:4px;\n"
""));
        ah3_inner->setFrameShape(QFrame::StyledPanel);
        ah3_inner->setFrameShadow(QFrame::Raised);
        ah_label = new QLabel(analogHighway);
        ah_label->setObjectName(QString::fromUtf8("ah_label"));
        ah_label->setGeometry(QRect(7, 0, 287, 16));
        ah_label->setFont(font14);
        ah_label->setStyleSheet(QString::fromUtf8("/*background-color:blue;\n"
"color: rgb(0, 85, 255);\n"
"color:white;\n"
"border:1px solid black;\n"
"border-radius:8px;*/\n"
"color: rgb(0, 85, 255);"));
        ah_label->setAlignment(Qt::AlignCenter);
        ah0_label = new QLabel(analogHighway);
        ah0_label->setObjectName(QString::fromUtf8("ah0_label"));
        ah0_label->setGeometry(QRect(240, 11, 43, 17));
        ah0_label->setFont(font15);
        ah0_label->setStyleSheet(QString::fromUtf8("color: rgb(53, 53, 53);\n"
"background-color: rgb(0, 0, 0,0);"));
        ah0_outer = new QFrame(analogHighway);
        ah0_outer->setObjectName(QString::fromUtf8("ah0_outer"));
        ah0_outer->setGeometry(QRect(237, 26, 41, 41));
        ah0_outer->setStyleSheet(QString::fromUtf8("border:1px solid gray;border-radius:20px;\n"
"image: url(:/new/prefix1/Button-Blank-Gray-icon.png);"));
        ah0_outer->setFrameShape(QFrame::StyledPanel);
        ah0_outer->setFrameShadow(QFrame::Raised);
        ah0_inner = new QFrame(ah0_outer);
        ah0_inner->setObjectName(QString::fromUtf8("ah0_inner"));
        ah0_inner->setGeometry(QRect(16, 15, 10, 10));
        ah0_inner->setStyleSheet(QString::fromUtf8("border:1px solid gray;border-radius:4px;\n"
""));
        ah0_inner->setFrameShape(QFrame::StyledPanel);
        ah0_inner->setFrameShadow(QFrame::Raised);
        ah2_label = new QLabel(analogHighway);
        ah2_label->setObjectName(QString::fromUtf8("ah2_label"));
        ah2_label->setGeometry(QRect(170, 11, 35, 17));
        ah2_label->setFont(font15);
        ah2_label->setStyleSheet(QString::fromUtf8("color: rgb(53, 53, 53);"));
        ah2_outer = new QFrame(analogHighway);
        ah2_outer->setObjectName(QString::fromUtf8("ah2_outer"));
        ah2_outer->setGeometry(QRect(167, 26, 41, 41));
        ah2_outer->setStyleSheet(QString::fromUtf8("border:1px solid gray;border-radius:20px;\n"
"image: url(:/new/prefix1/Button-Blank-Gray-icon.png);"));
        ah2_outer->setFrameShape(QFrame::StyledPanel);
        ah2_outer->setFrameShadow(QFrame::Raised);
        ah2_inner = new QFrame(ah2_outer);
        ah2_inner->setObjectName(QString::fromUtf8("ah2_inner"));
        ah2_inner->setGeometry(QRect(16, 15, 10, 10));
        ah2_inner->setStyleSheet(QString::fromUtf8("border:1px solid gray;border-radius:4px;\n"
""));
        ah2_inner->setFrameShape(QFrame::StyledPanel);
        ah2_inner->setFrameShadow(QFrame::Raised);
        fp_VI_ICM_SL = new QFrame(frontPanel_SHLOC);
        fp_VI_ICM_SL->setObjectName(QString::fromUtf8("fp_VI_ICM_SL"));
        fp_VI_ICM_SL->setGeometry(QRect(54, 84, 300, 72));
        fp_VI_ICM_SL->setStyleSheet(QString::fromUtf8("/*QFrame{border:2px solid black; background-color: rgba(0,0,0,0);border-radius:10px;}\n"
"QLabel{border:1px solid rgba(0,0,0,0);}*/\n"
"QFrame{border:1px solid black; background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #ffffff, stop: 1 #dadbff);border-radius:10px;}\n"
"QLabel{border:1px solid rgba(0,0,0,0);\n"
"background-color: rgb(0, 0, 0,0);\n"
"}\n"
"\n"
""));
        fp_VI_ICM_SL->setFrameShape(QFrame::StyledPanel);
        fp_VI_ICM_SL->setFrameShadow(QFrame::Raised);
        fp_Guarding = new QFrame(fp_VI_ICM_SL);
        fp_Guarding->setObjectName(QString::fromUtf8("fp_Guarding"));
        fp_Guarding->setGeometry(QRect(195, 26, 80, 30));
        fp_Guarding->setStyleSheet(QString::fromUtf8("border:1px solid gray;\n"
" border-top-right-radius: 8px;\n"
" border-top-left-radius: 8px;\n"
" border-bottom-right-radius: 15px;\n"
" border-bottom-left-radius: 15px;"));
        fp_Guarding->setFrameShape(QFrame::StyledPanel);
        fp_Guarding->setFrameShadow(QFrame::Raised);
        fp_VI2_EXT = new QFrame(fp_VI_ICM_SL);
        fp_VI2_EXT->setObjectName(QString::fromUtf8("fp_VI2_EXT"));
        fp_VI2_EXT->setGeometry(QRect(110, 20, 41, 41));
        fp_VI2_EXT->setStyleSheet(QString::fromUtf8("border:1px solid gray;border-radius:20px;\n"
"image: url(:/new/prefix1/Button-Blank-Gray-icon.png);"));
        fp_VI2_EXT->setFrameShape(QFrame::StyledPanel);
        fp_VI2_EXT->setFrameShadow(QFrame::Raised);
        fp_VI1_ICM_SL_label = new QLabel(fp_VI_ICM_SL);
        fp_VI1_ICM_SL_label->setObjectName(QString::fromUtf8("fp_VI1_ICM_SL_label"));
        fp_VI1_ICM_SL_label->setGeometry(QRect(11, 1, 74, 17));
        fp_VI1_ICM_SL_label->setFont(font15);
        fp_VI1_ICM_SL_label->setStyleSheet(QString::fromUtf8("color: rgb(53, 53, 53);"));
        fp_VI2_EXT_label = new QLabel(fp_VI_ICM_SL);
        fp_VI2_EXT_label->setObjectName(QString::fromUtf8("fp_VI2_EXT_label"));
        fp_VI2_EXT_label->setGeometry(QRect(106, 1, 60, 17));
        fp_VI2_EXT_label->setFont(font15);
        fp_VI2_EXT_label->setStyleSheet(QString::fromUtf8("color: rgb(53, 53, 53);"));
        fp_VI1_ICM_SL = new QFrame(fp_VI_ICM_SL);
        fp_VI1_ICM_SL->setObjectName(QString::fromUtf8("fp_VI1_ICM_SL"));
        fp_VI1_ICM_SL->setGeometry(QRect(24, 20, 41, 41));
        fp_VI1_ICM_SL->setStyleSheet(QString::fromUtf8("border:1px solid gray;border-radius:20px;\n"
"image: url(:/new/prefix1/Button-Blank-Gray-icon.png);"));
        fp_VI1_ICM_SL->setFrameShape(QFrame::StyledPanel);
        fp_VI1_ICM_SL->setFrameShadow(QFrame::Raised);
        fp_ICM_Guard = new QLabel(fp_VI_ICM_SL);
        fp_ICM_Guard->setObjectName(QString::fromUtf8("fp_ICM_Guard"));
        fp_ICM_Guard->setGeometry(QRect(196, 1, 75, 17));
        fp_ICM_Guard->setFont(font15);
        fp_ICM_Guard->setStyleSheet(QString::fromUtf8("color: rgb(53, 53, 53);"));
        frame_15 = new QFrame(frontPanel_SHLOC);
        frame_15->setObjectName(QString::fromUtf8("frame_15"));
        frame_15->setGeometry(QRect(355, 6, 300, 72));
        frame_15->setStyleSheet(QString::fromUtf8("/*QFrame{border:2px solid black; background-color: rgba(0,0,0,0);border-radius:10px;}\n"
"QLabel{border:1px solid rgba(0,0,0,0);}*/\n"
"QFrame{border:1px solid black; background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #ffffff, stop: 1 #dadbff);border-radius:10px;}\n"
"QLabel{border:1px solid rgba(0,0,0,0);\n"
"background-color: rgb(0, 0, 0,0);\n"
"}\n"
"\n"
""));
        frame_15->setFrameShape(QFrame::StyledPanel);
        frame_15->setFrameShadow(QFrame::Raised);
        label_74 = new QLabel(frame_15);
        label_74->setObjectName(QString::fromUtf8("label_74"));
        label_74->setGeometry(QRect(100, 12, 38, 17));
        label_74->setFont(font15);
        label_74->setStyleSheet(QString::fromUtf8("color: rgb(53, 53, 53);"));
        label_75 = new QLabel(frame_15);
        label_75->setObjectName(QString::fromUtf8("label_75"));
        label_75->setGeometry(QRect(26, 12, 38, 17));
        label_75->setFont(font15);
        label_75->setStyleSheet(QString::fromUtf8("color: rgb(53, 53, 53);"));
        dso1_outer_9 = new QFrame(frame_15);
        dso1_outer_9->setObjectName(QString::fromUtf8("dso1_outer_9"));
        dso1_outer_9->setGeometry(QRect(22, 27, 41, 41));
        dso1_outer_9->setStyleSheet(QString::fromUtf8("border:1px solid gray;border-radius:20px;\n"
"image: url(:/new/prefix1/Button-Blank-Gray-icon.png);"));
        dso1_outer_9->setFrameShape(QFrame::StyledPanel);
        dso1_outer_9->setFrameShadow(QFrame::Raised);
        dso1_inner_6 = new QFrame(dso1_outer_9);
        dso1_inner_6->setObjectName(QString::fromUtf8("dso1_inner_6"));
        dso1_inner_6->setGeometry(QRect(15, 15, 10, 10));
        dso1_inner_6->setStyleSheet(QString::fromUtf8("border:1px solid gray;border-radius:4px;\n"
""));
        dso1_inner_6->setFrameShape(QFrame::StyledPanel);
        dso1_inner_6->setFrameShadow(QFrame::Raised);
        dso_outer_18 = new QFrame(frame_15);
        dso_outer_18->setObjectName(QString::fromUtf8("dso_outer_18"));
        dso_outer_18->setGeometry(QRect(96, 27, 41, 41));
        dso_outer_18->setStyleSheet(QString::fromUtf8("border:1px solid gray;border-radius:20px;\n"
"image: url(:/new/prefix1/Button-Blank-Gray-icon.png);"));
        dso_outer_18->setFrameShape(QFrame::StyledPanel);
        dso_outer_18->setFrameShadow(QFrame::Raised);
        dso_inner_6 = new QFrame(dso_outer_18);
        dso_inner_6->setObjectName(QString::fromUtf8("dso_inner_6"));
        dso_inner_6->setGeometry(QRect(15, 15, 10, 10));
        dso_inner_6->setStyleSheet(QString::fromUtf8("border:1px solid gray;border-radius:4px;\n"
""));
        dso_inner_6->setFrameShape(QFrame::StyledPanel);
        dso_inner_6->setFrameShadow(QFrame::Raised);
        label_76 = new QLabel(frame_15);
        label_76->setObjectName(QString::fromUtf8("label_76"));
        label_76->setGeometry(QRect(7, 1, 287, 16));
        label_76->setFont(font14);
        label_76->setStyleSheet(QString::fromUtf8("/*background-color:blue;\n"
"color: rgb(0, 85, 255);\n"
"color:white;\n"
"border:1px solid black;\n"
"border-radius:8px;*/\n"
"color: rgb(0, 85, 255);"));
        label_76->setAlignment(Qt::AlignCenter);
        label_77 = new QLabel(frame_15);
        label_77->setObjectName(QString::fromUtf8("label_77"));
        label_77->setGeometry(QRect(241, 12, 43, 17));
        label_77->setFont(font15);
        label_77->setStyleSheet(QString::fromUtf8("color: rgb(53, 53, 53);"));
        frame_40 = new QFrame(frame_15);
        frame_40->setObjectName(QString::fromUtf8("frame_40"));
        frame_40->setGeometry(QRect(237, 27, 41, 41));
        frame_40->setStyleSheet(QString::fromUtf8("border:1px solid gray;border-radius:20px;\n"
"image: url(:/new/prefix1/Button-Blank-Gray-icon.png);"));
        frame_40->setFrameShape(QFrame::StyledPanel);
        frame_40->setFrameShadow(QFrame::Raised);
        frame_41 = new QFrame(frame_40);
        frame_41->setObjectName(QString::fromUtf8("frame_41"));
        frame_41->setGeometry(QRect(16, 15, 10, 10));
        frame_41->setStyleSheet(QString::fromUtf8("border:1px solid gray;border-radius:4px;\n"
""));
        frame_41->setFrameShape(QFrame::StyledPanel);
        frame_41->setFrameShadow(QFrame::Raised);
        label_78 = new QLabel(frame_15);
        label_78->setObjectName(QString::fromUtf8("label_78"));
        label_78->setGeometry(QRect(171, 12, 35, 17));
        label_78->setFont(font15);
        label_78->setStyleSheet(QString::fromUtf8("color: rgb(53, 53, 53);"));
        frame_42 = new QFrame(frame_15);
        frame_42->setObjectName(QString::fromUtf8("frame_42"));
        frame_42->setGeometry(QRect(167, 27, 41, 41));
        frame_42->setStyleSheet(QString::fromUtf8("border:1px solid gray;border-radius:20px;\n"
"image: url(:/new/prefix1/Button-Blank-Gray-icon.png);"));
        frame_42->setFrameShape(QFrame::StyledPanel);
        frame_42->setFrameShadow(QFrame::Raised);
        frame_43 = new QFrame(frame_42);
        frame_43->setObjectName(QString::fromUtf8("frame_43"));
        frame_43->setGeometry(QRect(16, 15, 10, 10));
        frame_43->setStyleSheet(QString::fromUtf8("border:1px solid gray;border-radius:4px;\n"
""));
        frame_43->setFrameShape(QFrame::StyledPanel);
        frame_43->setFrameShadow(QFrame::Raised);
        frame_DMM = new QFrame(frontPanel_SHLOC);
        frame_DMM->setObjectName(QString::fromUtf8("frame_DMM"));
        frame_DMM->setGeometry(QRect(355, 84, 300, 72));
        frame_DMM->setStyleSheet(QString::fromUtf8("/*QFrame{border:2px solid black; background-color: rgba(0,0,0,0);border-radius:10px;}\n"
"QLabel{border:1px solid rgba(0,0,0,0);}*/\n"
"QFrame{border:1px solid black; background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #ffffff, stop: 1 #dadbff);border-radius:10px;}\n"
"QLabel{border:1px solid rgba(0,0,0,0);\n"
"background-color: rgb(0, 0, 0,0);\n"
"}\n"
"\n"
""));
        frame_DMM->setFrameShape(QFrame::StyledPanel);
        frame_DMM->setFrameShadow(QFrame::Raised);
        fp_A_label = new QLabel(frame_DMM);
        fp_A_label->setObjectName(QString::fromUtf8("fp_A_label"));
        fp_A_label->setGeometry(QRect(247, 14, 20, 12));
        fp_A_label->setFont(font15);
        fp_A_label->setStyleSheet(QString::fromUtf8("color: rgb(53, 53, 53);"));
        fp_LO_inner = new QFrame(frame_DMM);
        fp_LO_inner->setObjectName(QString::fromUtf8("fp_LO_inner"));
        fp_LO_inner->setGeometry(QRect(80, 32, 31, 31));
        fp_LO_inner->setStyleSheet(QString::fromUtf8("border:1px solid gray;border-radius:15px;\n"
"image: url(:/new/prefix1/Button-Blank-Gray-icon.png);\n"
""));
        fp_LO_inner->setFrameShape(QFrame::StyledPanel);
        fp_LO_inner->setFrameShadow(QFrame::Raised);
        fp_mA_inner = new QFrame(frame_DMM);
        fp_mA_inner->setObjectName(QString::fromUtf8("fp_mA_inner"));
        fp_mA_inner->setGeometry(QRect(130, 32, 31, 31));
        fp_mA_inner->setStyleSheet(QString::fromUtf8("border:1px solid gray;border-radius:15px;\n"
"image: url(:/new/prefix1/Button-Blank-Gray-icon.png);\n"
"\n"
""));
        fp_mA_inner->setFrameShape(QFrame::StyledPanel);
        fp_mA_inner->setFrameShadow(QFrame::Raised);
        fp_A_outer = new QFrame(frame_DMM);
        fp_A_outer->setObjectName(QString::fromUtf8("fp_A_outer"));
        fp_A_outer->setGeometry(QRect(235, 27, 41, 41));
        fp_A_outer->setStyleSheet(QString::fromUtf8("border:1px solid gray;border-radius:20px;image: url(:/new/prefix1/Button-Blank-Gray-icon.png);"));
        fp_A_outer->setFrameShape(QFrame::StyledPanel);
        fp_A_outer->setFrameShadow(QFrame::Raised);
        fp_A_inner = new QFrame(frame_DMM);
        fp_A_inner->setObjectName(QString::fromUtf8("fp_A_inner"));
        fp_A_inner->setGeometry(QRect(240, 32, 31, 31));
        fp_A_inner->setStyleSheet(QString::fromUtf8("border:1px solid gray;border-radius:15px;\n"
"image: url(:/new/prefix1/Button-Blank-Gray-icon.png);"));
        fp_A_inner->setFrameShape(QFrame::StyledPanel);
        fp_A_inner->setFrameShadow(QFrame::Raised);
        fp_mA_outer = new QFrame(frame_DMM);
        fp_mA_outer->setObjectName(QString::fromUtf8("fp_mA_outer"));
        fp_mA_outer->setGeometry(QRect(125, 27, 41, 41));
        fp_mA_outer->setStyleSheet(QString::fromUtf8("border:1px solid gray;border-radius:20px;image: url(:/new/prefix1/Button-Blank-Gray-icon.png);\n"
""));
        fp_mA_outer->setFrameShape(QFrame::StyledPanel);
        fp_mA_outer->setFrameShadow(QFrame::Raised);
        fp_HI_label = new QLabel(frame_DMM);
        fp_HI_label->setObjectName(QString::fromUtf8("fp_HI_label"));
        fp_HI_label->setGeometry(QRect(37, 14, 20, 12));
        fp_HI_label->setFont(font15);
        fp_HI_label->setStyleSheet(QString::fromUtf8("color: rgb(53, 53, 53);"));
        fp_HI_label->setAlignment(Qt::AlignCenter);
        fp_LO_outer = new QFrame(frame_DMM);
        fp_LO_outer->setObjectName(QString::fromUtf8("fp_LO_outer"));
        fp_LO_outer->setGeometry(QRect(75, 27, 41, 41));
        fp_LO_outer->setStyleSheet(QString::fromUtf8("border:1px solid gray;border-radius:20px;image: url(:/new/prefix1/Button-Blank-Gray-icon.png);\n"
""));
        fp_LO_outer->setFrameShape(QFrame::StyledPanel);
        fp_LO_outer->setFrameShadow(QFrame::Raised);
        fp_HI_outer = new QFrame(frame_DMM);
        fp_HI_outer->setObjectName(QString::fromUtf8("fp_HI_outer"));
        fp_HI_outer->setGeometry(QRect(25, 27, 41, 41));
        fp_HI_outer->setStyleSheet(QString::fromUtf8("border:1px solid gray;border-radius:20px;image: url(:/new/prefix1/Button-Blank-Gray-icon.png);\n"
""));
        fp_HI_outer->setFrameShape(QFrame::StyledPanel);
        fp_HI_outer->setFrameShadow(QFrame::Raised);
        fp_LO_label = new QLabel(frame_DMM);
        fp_LO_label->setObjectName(QString::fromUtf8("fp_LO_label"));
        fp_LO_label->setGeometry(QRect(85, 14, 22, 12));
        fp_LO_label->setFont(font15);
        fp_LO_label->setStyleSheet(QString::fromUtf8("color: rgb(53, 53, 53);"));
        fp_HI_inner = new QFrame(frame_DMM);
        fp_HI_inner->setObjectName(QString::fromUtf8("fp_HI_inner"));
        fp_HI_inner->setGeometry(QRect(30, 32, 31, 31));
        fp_HI_inner->setStyleSheet(QString::fromUtf8("border:1px solid gray;border-radius:15px;\n"
"image: url(:/new/prefix1/Button-Blank-Gray-icon.png);\n"
""));
        fp_HI_inner->setFrameShape(QFrame::StyledPanel);
        fp_HI_inner->setFrameShadow(QFrame::Raised);
        fp_DMM_label = new QLabel(frame_DMM);
        fp_DMM_label->setObjectName(QString::fromUtf8("fp_DMM_label"));
        fp_DMM_label->setGeometry(QRect(6, 0, 287, 16));
        fp_DMM_label->setFont(font14);
        fp_DMM_label->setStyleSheet(QString::fromUtf8("/*background-color:blue;\n"
"color: rgb(0, 85, 255);\n"
"color:white;\n"
"border:1px solid black;\n"
"border-radius:8px;*/\n"
"color: rgb(0, 85, 255);"));
        fp_DMM_label->setAlignment(Qt::AlignCenter);
        fp_fuse_label = new QLabel(frame_DMM);
        fp_fuse_label->setObjectName(QString::fromUtf8("fp_fuse_label"));
        fp_fuse_label->setGeometry(QRect(178, 14, 50, 12));
        fp_fuse_label->setFont(font15);
        fp_fuse_label->setStyleSheet(QString::fromUtf8("color: rgb(53, 53, 53);"));
        fp_fuse = new QFrame(frame_DMM);
        fp_fuse->setObjectName(QString::fromUtf8("fp_fuse"));
        fp_fuse->setGeometry(QRect(172, 23, 50, 47));
        fp_fuse->setStyleSheet(QString::fromUtf8("border-radius:20px;\n"
"image: url(:/fp_images/fuse.png);\n"
"border:1px solid rgba(0,0,0,0);\n"
""));
        fp_fuse->setFrameShape(QFrame::StyledPanel);
        fp_fuse->setFrameShadow(QFrame::Raised);
        fp_mA_label = new QLabel(frame_DMM);
        fp_mA_label->setObjectName(QString::fromUtf8("fp_mA_label"));
        fp_mA_label->setGeometry(QRect(133, 15, 35, 12));
        fp_mA_label->setFont(font15);
        fp_mA_label->setStyleSheet(QString::fromUtf8("color: rgb(53, 53, 53);"));
        fp_A_label->raise();
        fp_A_outer->raise();
        fp_A_inner->raise();
        fp_mA_outer->raise();
        fp_HI_label->raise();
        fp_LO_outer->raise();
        fp_HI_outer->raise();
        fp_LO_label->raise();
        fp_HI_inner->raise();
        fp_DMM_label->raise();
        fp_fuse_label->raise();
        fp_fuse->raise();
        fp_mA_label->raise();
        fp_mA_inner->raise();
        fp_LO_inner->raise();
        fp_REF = new QFrame(frontPanel_SHLOC);
        fp_REF->setObjectName(QString::fromUtf8("fp_REF"));
        fp_REF->setGeometry(QRect(655, 21, 31, 31));
        fp_REF->setStyleSheet(QString::fromUtf8("QFrame{\n"
"border:1px rgba(0,0,0,0); \n"
"border-radius:12px;\n"
"image: url(:/fp_images/ref.png);\n"
"background-color: rgb(0, 0, 0,0);\n"
"}"));
        fp_REF->setFrameShape(QFrame::StyledPanel);
        fp_REF->setFrameShadow(QFrame::Raised);
        fp_REF_label = new QLabel(frontPanel_SHLOC);
        fp_REF_label->setObjectName(QString::fromUtf8("fp_REF_label"));
        fp_REF_label->setGeometry(QRect(655, 51, 32, 17));
        fp_REF_label->setFont(font15);
        fp_REF_label->setStyleSheet(QString::fromUtf8("color:white;\n"
"background-color: rgb(0, 0, 0,0);\n"
"border-color:rgb(0, 0, 0,0);"));
        fp_GND_label = new QLabel(frontPanel_SHLOC);
        fp_GND_label->setObjectName(QString::fromUtf8("fp_GND_label"));
        fp_GND_label->setGeometry(QRect(653, 131, 35, 17));
        fp_GND_label->setFont(font15);
        fp_GND_label->setStyleSheet(QString::fromUtf8("color:white;\n"
"background-color: rgb(0, 0, 0,0);\n"
"border-color:rgb(0, 0, 0,0);"));
        fp_GND = new QFrame(frontPanel_SHLOC);
        fp_GND->setObjectName(QString::fromUtf8("fp_GND"));
        fp_GND->setGeometry(QRect(652, 96, 38, 31));
        fp_GND->setStyleSheet(QString::fromUtf8("QFrame{\n"
"border:1px rgba(0,0,0,0); \n"
"border-radius:13px;\n"
"background-color: rgb(0, 0, 0,0);\n"
"	image: url(:/fp_images/gnd.png);\n"
"}"));
        fp_GND->setFrameShape(QFrame::StyledPanel);
        fp_GND->setFrameShadow(QFrame::Raised);
        plottingWindow = new QFrame(ShortLocaterClass);
        plottingWindow->setObjectName(QString::fromUtf8("plottingWindow"));
        plottingWindow->setGeometry(QRect(800, 434, 693, 160));
        plottingWindow->setStyleSheet(QString::fromUtf8("QFrame{border:1px solid black; background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #ffffff, stop: 1 #dadbff);border-radius:10px;}\n"
"QLabel{border:1px solid rgba(0,0,0,0);}\n"
""));
        plottingWindow->setFrameShape(QFrame::StyledPanel);
        plottingWindow->setFrameShadow(QFrame::Raised);
        customPlot = new QCustomPlot(plottingWindow);
        customPlot->setObjectName(QString::fromUtf8("customPlot"));
        customPlot->setGeometry(QRect(2, 7, 690, 147));
        butZoom = new QPushButton(customPlot);
        butZoom->setObjectName(QString::fromUtf8("butZoom"));
        butZoom->setGeometry(QRect(2, 7, 690, 147));
        QPalette palette9;
        QBrush brush15(QColor(0, 0, 0, 0));
        brush15.setStyle(Qt::SolidPattern);
        palette9.setBrush(QPalette::Active, QPalette::WindowText, brush15);
        palette9.setBrush(QPalette::Active, QPalette::Button, brush15);
        palette9.setBrush(QPalette::Active, QPalette::Light, brush15);
        palette9.setBrush(QPalette::Active, QPalette::Midlight, brush15);
        palette9.setBrush(QPalette::Active, QPalette::Dark, brush15);
        palette9.setBrush(QPalette::Active, QPalette::Mid, brush15);
        palette9.setBrush(QPalette::Active, QPalette::Text, brush15);
        palette9.setBrush(QPalette::Active, QPalette::BrightText, brush15);
        palette9.setBrush(QPalette::Active, QPalette::ButtonText, brush15);
        palette9.setBrush(QPalette::Active, QPalette::Base, brush15);
        palette9.setBrush(QPalette::Active, QPalette::Window, brush15);
        palette9.setBrush(QPalette::Active, QPalette::Shadow, brush15);
        palette9.setBrush(QPalette::Active, QPalette::Highlight, brush15);
        palette9.setBrush(QPalette::Active, QPalette::HighlightedText, brush15);
        palette9.setBrush(QPalette::Active, QPalette::Link, brush15);
        palette9.setBrush(QPalette::Active, QPalette::LinkVisited, brush15);
        palette9.setBrush(QPalette::Active, QPalette::AlternateBase, brush15);
        palette9.setBrush(QPalette::Active, QPalette::NoRole, brush15);
        palette9.setBrush(QPalette::Active, QPalette::ToolTipBase, brush15);
        palette9.setBrush(QPalette::Active, QPalette::ToolTipText, brush15);
        palette9.setBrush(QPalette::Inactive, QPalette::WindowText, brush15);
        palette9.setBrush(QPalette::Inactive, QPalette::Button, brush15);
        palette9.setBrush(QPalette::Inactive, QPalette::Light, brush15);
        palette9.setBrush(QPalette::Inactive, QPalette::Midlight, brush15);
        palette9.setBrush(QPalette::Inactive, QPalette::Dark, brush15);
        palette9.setBrush(QPalette::Inactive, QPalette::Mid, brush15);
        palette9.setBrush(QPalette::Inactive, QPalette::Text, brush15);
        palette9.setBrush(QPalette::Inactive, QPalette::BrightText, brush15);
        palette9.setBrush(QPalette::Inactive, QPalette::ButtonText, brush15);
        palette9.setBrush(QPalette::Inactive, QPalette::Base, brush15);
        palette9.setBrush(QPalette::Inactive, QPalette::Window, brush15);
        palette9.setBrush(QPalette::Inactive, QPalette::Shadow, brush15);
        palette9.setBrush(QPalette::Inactive, QPalette::Highlight, brush15);
        palette9.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush15);
        palette9.setBrush(QPalette::Inactive, QPalette::Link, brush15);
        palette9.setBrush(QPalette::Inactive, QPalette::LinkVisited, brush15);
        palette9.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush15);
        palette9.setBrush(QPalette::Inactive, QPalette::NoRole, brush15);
        palette9.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush15);
        palette9.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush15);
        palette9.setBrush(QPalette::Disabled, QPalette::WindowText, brush15);
        palette9.setBrush(QPalette::Disabled, QPalette::Button, brush15);
        palette9.setBrush(QPalette::Disabled, QPalette::Light, brush15);
        palette9.setBrush(QPalette::Disabled, QPalette::Midlight, brush15);
        palette9.setBrush(QPalette::Disabled, QPalette::Dark, brush15);
        palette9.setBrush(QPalette::Disabled, QPalette::Mid, brush15);
        palette9.setBrush(QPalette::Disabled, QPalette::Text, brush15);
        palette9.setBrush(QPalette::Disabled, QPalette::BrightText, brush15);
        palette9.setBrush(QPalette::Disabled, QPalette::ButtonText, brush15);
        palette9.setBrush(QPalette::Disabled, QPalette::Base, brush15);
        palette9.setBrush(QPalette::Disabled, QPalette::Window, brush15);
        palette9.setBrush(QPalette::Disabled, QPalette::Shadow, brush15);
        QBrush brush16(QColor(212, 212, 212, 255));
        brush16.setStyle(Qt::SolidPattern);
        palette9.setBrush(QPalette::Disabled, QPalette::Highlight, brush16);
        palette9.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush15);
        palette9.setBrush(QPalette::Disabled, QPalette::Link, brush15);
        palette9.setBrush(QPalette::Disabled, QPalette::LinkVisited, brush15);
        palette9.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush15);
        palette9.setBrush(QPalette::Disabled, QPalette::NoRole, brush15);
        palette9.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush15);
        palette9.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush15);
        butZoom->setPalette(palette9);
        butZoom->setFocusPolicy(Qt::NoFocus);
        butZoom->setStyleSheet(QString::fromUtf8(" QPushButton {\n"
"background-color: rgb(0, 0, 0,0);\n"
"border:2px solid white:\n"
"color: rgba(0, 0, 0, 0);\n"
" }\n"
"\n"
" QPushButton:pressed {\n"
"background-color: rgb(0, 0, 0,0);\n"
"border:2px solid white:\n"
"color: rgba(0, 0, 0, 0);\n"
" }\n"
"\n"
" QPushButton:flat {\n"
"background-color: rgb(0, 0, 0,0);\n"
"border:2px solid white:\n"
"color: rgba(0, 0, 0, 0); }\n"
"\n"
" QPushButton:default {\n"
"background-color: rgb(0, 0, 0,0);\n"
"border:2px solid white:\n"
"color: rgba(0, 0, 0, 0); }"));
        butZoom->setAutoDefault(true);
        butZoom->setDefault(true);
        butZoom->setFlat(true);
        External = new QPushButton(ShortLocaterClass);
        External->setObjectName(QString::fromUtf8("External"));
        External->setGeometry(QRect(100, 200, 64, 64));
        QFont font16;
        font16.setFamily(QString::fromUtf8("DejaVu Sans"));
        font16.setPointSize(12);
        font16.setBold(true);
        font16.setItalic(false);
        font16.setWeight(75);
        External->setFont(font16);
        External->setFocusPolicy(Qt::NoFocus);
        External->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color:white;\n"
"border: 1px solid #2D5059;\n"
"border-radius: 20px;\n"
"background-color: qlineargradient(x1: 0, y1: 1, x2: 1, y2: 0,stop: 0 #1A74DB, stop: 0.6 #5293DE, stop:1 #FFFFFF);\n"
"font:bold;\n"
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
"}\n"
"\n"
"QPushButton:disabled\n"
"{\n"
"color:lightgrey;\n"
"background-color:grey\n"
"}"));
        External->setIconSize(QSize(64, 64));
        Internal = new QPushButton(ShortLocaterClass);
        Internal->setObjectName(QString::fromUtf8("Internal"));
        Internal->setGeometry(QRect(100, 200, 64, 64));
        Internal->setFont(font16);
        Internal->setFocusPolicy(Qt::NoFocus);
        Internal->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color:white;\n"
"border: 1px solid #2D5059;\n"
"border-radius: 20px;\n"
"background-color: qlineargradient(x1: 0, y1: 1, x2: 1, y2: 0,stop: 0 #1A74DB, stop: 0.6 #5293DE, stop:1 #FFFFFF);\n"
"font:bold;\n"
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
"}\n"
"\n"
"QPushButton:disabled\n"
"{\n"
"color:lightgrey;\n"
"background-color:grey\n"
"}"));
        Internal->setIconSize(QSize(64, 64));
        Auto = new QPushButton(ShortLocaterClass);
        Auto->setObjectName(QString::fromUtf8("Auto"));
        Auto->setGeometry(QRect(100, 200, 64, 64));
        Auto->setFont(font16);
        Auto->setFocusPolicy(Qt::NoFocus);
        Auto->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color:white;\n"
"border: 1px solid #2D5059;\n"
"border-radius: 20px;\n"
"background-color: qlineargradient(x1: 0, y1: 1, x2: 1, y2: 0,stop: 0 #1A74DB, stop: 0.6 #5293DE, stop:1 #FFFFFF);\n"
"font:bold;\n"
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
"}\n"
"\n"
"QPushButton:disabled\n"
"{\n"
"color:lightgrey;\n"
"background-color:grey\n"
"}"));
        Auto->setIconSize(QSize(64, 64));
        Null = new QPushButton(ShortLocaterClass);
        Null->setObjectName(QString::fromUtf8("Null"));
        Null->setGeometry(QRect(100, 200, 64, 64));
        Null->setFont(font16);
        Null->setFocusPolicy(Qt::NoFocus);
        Null->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color:white;\n"
"border: 1px solid #2D5059;\n"
"border-radius: 20px;\n"
"background-color: qlineargradient(x1: 0, y1: 1, x2: 1, y2: 0,stop: 0 #1A74DB, stop: 0.6 #5293DE, stop:1 #FFFFFF);\n"
"font:bold;\n"
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
"}\n"
"\n"
"QPushButton:disabled\n"
"{\n"
"color:lightgrey;\n"
"background-color:grey\n"
"}"));
        Null->setIconSize(QSize(64, 64));
        hold = new QPushButton(ShortLocaterClass);
        hold->setObjectName(QString::fromUtf8("hold"));
        hold->setGeometry(QRect(100, 200, 64, 64));
        hold->setFont(font16);
        hold->setFocusPolicy(Qt::NoFocus);
        hold->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color:white;\n"
"border: 1px solid #2D5059;\n"
"border-radius: 20px;\n"
"background-color: qlineargradient(x1: 0, y1: 1, x2: 1, y2: 0,stop: 0 #1A74DB, stop: 0.6 #5293DE, stop:1 #FFFFFF);\n"
"font:bold;\n"
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
"}\n"
"\n"
"QPushButton:disabled\n"
"{\n"
"color:lightgrey;\n"
"background-color:grey\n"
"}"));
        hold->setIconSize(QSize(64, 64));
        holdCap = new QLabel(ShortLocaterClass);
        holdCap->setObjectName(QString::fromUtf8("holdCap"));
        holdCap->setGeometry(QRect(100, 200, 60, 17));
        QPalette palette10;
        palette10.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette10.setBrush(QPalette::Active, QPalette::Button, brush3);
        palette10.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette10.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette10.setBrush(QPalette::Active, QPalette::Base, brush3);
        palette10.setBrush(QPalette::Active, QPalette::Window, brush3);
        palette10.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette10.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette10.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette10.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette10.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette10.setBrush(QPalette::Inactive, QPalette::Window, brush3);
        palette10.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette10.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        palette10.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette10.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette10.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        palette10.setBrush(QPalette::Disabled, QPalette::Window, brush3);
        holdCap->setPalette(palette10);
        holdCap->setFont(font4);
        holdCap->setStyleSheet(QString::fromUtf8("color:#fbec5d;"));
        label = new QLabel(ShortLocaterClass);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(100, 200, 90, 17));
        QPalette palette11;
        palette11.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette11.setBrush(QPalette::Active, QPalette::Button, brush3);
        palette11.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette11.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette11.setBrush(QPalette::Active, QPalette::Base, brush3);
        palette11.setBrush(QPalette::Active, QPalette::Window, brush3);
        palette11.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette11.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette11.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette11.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette11.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette11.setBrush(QPalette::Inactive, QPalette::Window, brush3);
        palette11.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette11.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        palette11.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette11.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette11.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        palette11.setBrush(QPalette::Disabled, QPalette::Window, brush3);
        label->setPalette(palette11);
        label->setFont(font4);
        label->setStyleSheet(QString::fromUtf8("color:#fbec5d;"));
        holdCap->raise();
        label->raise();
        hold->raise();
        Null->raise();
        Auto->raise();
        External->raise();
        Internal->raise();
        displayPanel->raise();
        ohmBox->raise();
        selectFrame->raise();
        inputPanel->raise();
        temp4->raise();
        appBox->raise();
        ExitBox->raise();
        graphBox->raise();
        temp3->raise();
        debugPanel->raise();
        HAADC_WIDGET->raise();
        frontPanel_SHLOC->raise();
        plottingWindow->raise();

        retranslateUi(ShortLocaterClass);

        QMetaObject::connectSlotsByName(ShortLocaterClass);
    } // setupUi

    void retranslateUi(QWidget *ShortLocaterClass)
    {
        ShortLocaterClass->setWindowTitle(QApplication::translate("ShortLocaterClass", "ShortLocater", 0, QApplication::UnicodeUTF8));
        units->setText(QString());
        displayBG->setText(QString());
        rangeLabel->setText(QString());
        rangeCap->setText(QApplication::translate("ShortLocaterClass", "RANGE:", 0, QApplication::UnicodeUTF8));
        progressBar_2->setFormat(QApplication::translate("ShortLocaterClass", "%vmE", 0, QApplication::UnicodeUTF8));
        ohmBox->setTitle(QString());
        uE->setText(QApplication::translate("ShortLocaterClass", "R", 0, QApplication::UnicodeUTF8));
        functionsPanel->setTitle(QApplication::translate("ShortLocaterClass", "FUNCTIONS", 0, QApplication::UnicodeUTF8));
        offset->setText(QApplication::translate("ShortLocaterClass", "OFFSET", 0, QApplication::UnicodeUTF8));
        buzzer->setText(QApplication::translate("ShortLocaterClass", "BUZZER", 0, QApplication::UnicodeUTF8));
        settings->setText(QApplication::translate("ShortLocaterClass", "SETTINGS", 0, QApplication::UnicodeUTF8));
        Ranges->setTitle(QApplication::translate("ShortLocaterClass", "RANGES", 0, QApplication::UnicodeUTF8));
        r200But->setText(QString());
        r200ECap->setText(QApplication::translate("ShortLocaterClass", "200E", 0, QApplication::UnicodeUTF8));
        r2EBut->setText(QString());
        r2Ecap->setText(QApplication::translate("ShortLocaterClass", "2E", 0, QApplication::UnicodeUTF8));
        r200mEBut->setText(QString());
        r200mECap->setText(QApplication::translate("ShortLocaterClass", "200mE", 0, QApplication::UnicodeUTF8));
        but200mE->setText(QString());
        but2E->setText(QString());
        but200E->setText(QString());
        splashLabel->setText(QApplication::translate("ShortLocaterClass", "OFFSET APPLYING.....", 0, QApplication::UnicodeUTF8));
        Legends->setTitle(QApplication::translate("ShortLocaterClass", "KEYS", 0, QApplication::UnicodeUTF8));
        butL->setText(QString());
        lblLeft->setText(QApplication::translate("ShortLocaterClass", "OFFSET", 0, QApplication::UnicodeUTF8));
        butR->setText(QString());
        lblRight->setText(QApplication::translate("ShortLocaterClass", "BUZZER", 0, QApplication::UnicodeUTF8));
        lblMiddle->setText(QApplication::translate("ShortLocaterClass", "RANGE", 0, QApplication::UnicodeUTF8));
        butM->setText(QString());
        temp4->setTitle(QString());
        ohmMeter_3->setText(QString());
        appBox->setTitle(QString());
        selectApp->setText(QString());
        ExitBox->setTitle(QString());
        exit->setText(QString());
        graphBox->setTitle(QString());
        graph->setText(QString());
        temp3->setTitle(QString());
        ohmMeter_2->setText(QString());
        debugPanel->setTitle(QApplication::translate("ShortLocaterClass", "DEBUG PANEL", 0, QApplication::UnicodeUTF8));
        pushButton_16->setText(QString());
        pushButton->setText(QString());
        HAADC->setText(QString());
        calibrateDisplay->setText(QApplication::translate("ShortLocaterClass", "Screen Calibration", 0, QApplication::UnicodeUTF8));
        haadcFrame->setTitle(QString());
        haadcClose->setText(QApplication::translate("ShortLocaterClass", "&Close", 0, QApplication::UnicodeUTF8));
        label_22->setText(QApplication::translate("ShortLocaterClass", "ADC Raw Data :", 0, QApplication::UnicodeUTF8));
        label_23->setText(QApplication::translate("ShortLocaterClass", "ADC Converted\n"
"Data :", 0, QApplication::UnicodeUTF8));
        label_25->setText(QApplication::translate("ShortLocaterClass", "Display Input : ", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("ShortLocaterClass", "NULL ON", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("ShortLocaterClass", "NULL OFF", 0, QApplication::UnicodeUTF8));
        openShortEnable->setText(QApplication::translate("ShortLocaterClass", "OpenShort Values", 0, QApplication::UnicodeUTF8));
        left->setText(QString());
        right->setText(QString());
        down->setText(QString());
        up->setText(QString());
        checkBox->setText(QApplication::translate("ShortLocaterClass", "DACG/DACF", 0, QApplication::UnicodeUTF8));
        selectLib->setTitle(QString());
        oldLib->setText(QApplication::translate("ShortLocaterClass", "OLD LIB", 0, QApplication::UnicodeUTF8));
        newLib->setText(QApplication::translate("ShortLocaterClass", "NEW LIB", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ShortLocaterClass", "Samples:", 0, QApplication::UnicodeUTF8));
        fp_powerLabel->setText(QApplication::translate("ShortLocaterClass", "POWER", 0, QApplication::UnicodeUTF8));
        ah3_label->setText(QApplication::translate("ShortLocaterClass", "AH3", 0, QApplication::UnicodeUTF8));
        ah1_label->setText(QApplication::translate("ShortLocaterClass", "AH1", 0, QApplication::UnicodeUTF8));
        ah_label->setText(QApplication::translate("ShortLocaterClass", "ANALOG HIGHWAY", 0, QApplication::UnicodeUTF8));
        ah0_label->setText(QApplication::translate("ShortLocaterClass", "AH0", 0, QApplication::UnicodeUTF8));
        ah2_label->setText(QApplication::translate("ShortLocaterClass", "AH2", 0, QApplication::UnicodeUTF8));
        fp_VI1_ICM_SL_label->setText(QApplication::translate("ShortLocaterClass", "VI-1/ICM/SL", 0, QApplication::UnicodeUTF8));
        fp_VI2_EXT_label->setText(QApplication::translate("ShortLocaterClass", "VI-2/EXT", 0, QApplication::UnicodeUTF8));
        fp_ICM_Guard->setText(QApplication::translate("ShortLocaterClass", "ICM GUARD", 0, QApplication::UnicodeUTF8));
        label_74->setText(QApplication::translate("ShortLocaterClass", "CH2", 0, QApplication::UnicodeUTF8));
        label_75->setText(QApplication::translate("ShortLocaterClass", "CH1", 0, QApplication::UnicodeUTF8));
        label_76->setText(QApplication::translate("ShortLocaterClass", "DSO", 0, QApplication::UnicodeUTF8));
        label_77->setText(QApplication::translate("ShortLocaterClass", "AWG", 0, QApplication::UnicodeUTF8));
        label_78->setText(QApplication::translate("ShortLocaterClass", "EXT", 0, QApplication::UnicodeUTF8));
        fp_A_label->setText(QApplication::translate("ShortLocaterClass", "A", 0, QApplication::UnicodeUTF8));
        fp_HI_label->setText(QApplication::translate("ShortLocaterClass", "HI", 0, QApplication::UnicodeUTF8));
        fp_LO_label->setText(QApplication::translate("ShortLocaterClass", "LO", 0, QApplication::UnicodeUTF8));
        fp_DMM_label->setText(QApplication::translate("ShortLocaterClass", "DMM", 0, QApplication::UnicodeUTF8));
        fp_fuse_label->setText(QApplication::translate("ShortLocaterClass", "FUSE", 0, QApplication::UnicodeUTF8));
        fp_mA_label->setText(QApplication::translate("ShortLocaterClass", "mA", 0, QApplication::UnicodeUTF8));
        fp_REF_label->setText(QApplication::translate("ShortLocaterClass", "REF", 0, QApplication::UnicodeUTF8));
        fp_GND_label->setText(QApplication::translate("ShortLocaterClass", "GND", 0, QApplication::UnicodeUTF8));
        butZoom->setText(QString());
        External->setText(QApplication::translate("ShortLocaterClass", "EXT", 0, QApplication::UnicodeUTF8));
        Internal->setText(QApplication::translate("ShortLocaterClass", "INT", 0, QApplication::UnicodeUTF8));
        Auto->setText(QApplication::translate("ShortLocaterClass", "AUTO", 0, QApplication::UnicodeUTF8));
        Null->setText(QApplication::translate("ShortLocaterClass", "Probe\n"
"Calib", 0, QApplication::UnicodeUTF8));
        hold->setText(QApplication::translate("ShortLocaterClass", "HOLD", 0, QApplication::UnicodeUTF8));
        holdCap->setText(QApplication::translate("ShortLocaterClass", "HOLD", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ShortLocaterClass", "AUTO", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ShortLocaterClass: public Ui_ShortLocaterClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHORTLOCATER_H
