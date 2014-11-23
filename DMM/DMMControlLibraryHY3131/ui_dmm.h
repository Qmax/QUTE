/********************************************************************************
** Form generated from reading UI file 'dmm.ui'
**
** Created: Sat Nov 22 17:23:30 2014
**      by: Qt User Interface Compiler version 4.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DMM_H
#define UI_DMM_H

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
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DMM
{
public:
    QFrame *inputPanel;
    QPushButton *r4w;
    QPushButton *iac;
    QPushButton *vdc;
    QPushButton *idc;
    QPushButton *manual;
    QPushButton *r2w;
    QPushButton *Auto;
    QPushButton *vac;
    QPushButton *hold;
    QPushButton *Null;
    QFrame *rangeFrame;
    QPushButton *leftArrow;
    QLabel *label_5;
    QFrame *line;
    QLabel *label_6;
    QPushButton *rightArrow;
    QFrame *line_4;
    QLabel *label_4;
    QFrame *line_8;
    QFrame *line_9;
    QLabel *label_8;
    QLabel *label_18;
    QFrame *frame_5;
    QFrame *frame_6;
    QPushButton *Diode;
    QPushButton *Continuity;
    QFrame *displayPanel;
    QTextEdit *textEdit_4;
    QLabel *label_7;
    QLabel *label;
    QLabel *label_2;
    QTextEdit *textEdit_5;
    QLabel *label_3;
    QTextEdit *textEdit_3;
    QTextEdit *textEdit_6;
    QLabel *label_11;
    QLabel *label_12;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLabel *holdLabel;
    QLabel *label_10;
    QLabel *label_14;
    QTextEdit *textEdit;
    QLineEdit *lineEdit;
    QGroupBox *voltBox;
    QPushButton *voltMeter;
    QFrame *selectFrame;
    QGroupBox *AmpBox;
    QPushButton *ampMeter;
    QGroupBox *OhmBox;
    QPushButton *ohmMeter;
    QGroupBox *ExitBox;
    QPushButton *exit;
    QGroupBox *OhmBox_2;
    QPushButton *ohmMeter_2;
    QGroupBox *OhmBox_3;
    QPushButton *ohmMeter_3;
    QGroupBox *debugPanel;
    QPushButton *pushButton_16;
    QPushButton *pushButton_14;
    QPushButton *pushButton;
    QPushButton *pushButton_13;
    QPushButton *pushButton_15;
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
    QFrame *frontPanel_DMM;
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
    QFrame *ah_inner;
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
    QLabel *fp_DMM_label_2;
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
    QFrame *fp_VI_ICM_SL_2;
    QFrame *fp_Guarding_2;
    QLabel *fp_ICM_Guard_2;
    QWidget *graphLegend;
    QLabel *minCap;
    QLabel *maxCap;
    QFrame *line_2;
    QFrame *line_3;
    QFrame *line_5;
    QLineEdit *maxEdit;
    QLineEdit *minEdit;

    void setupUi(QWidget *DMM)
    {
        if (DMM->objectName().isEmpty())
            DMM->setObjectName(QString::fromUtf8("DMM"));
        DMM->resize(800, 600);
        DMM->setMinimumSize(QSize(800, 0));
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
        DMM->setPalette(palette);
        QFont font;
        font.setFamily(QString::fromUtf8("Sans Serif"));
        font.setPointSize(9);
        DMM->setFont(font);
        DMM->setAutoFillBackground(true);
        DMM->setStyleSheet(QString::fromUtf8(""));
        inputPanel = new QFrame(DMM);
        inputPanel->setObjectName(QString::fromUtf8("inputPanel"));
        inputPanel->setGeometry(QRect(10, 200, 693, 230));
        QFont font1;
        font1.setFamily(QString::fromUtf8("DejaVu Sans"));
        inputPanel->setFont(font1);
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
        r4w = new QPushButton(inputPanel);
        r4w->setObjectName(QString::fromUtf8("r4w"));
        r4w->setGeometry(QRect(226, 46, 64, 64));
        QFont font2;
        font2.setFamily(QString::fromUtf8("DejaVu Sans"));
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setItalic(false);
        font2.setWeight(75);
        r4w->setFont(font2);
        r4w->setFocusPolicy(Qt::NoFocus);
        r4w->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        r4w->setIconSize(QSize(64, 64));
        iac = new QPushButton(inputPanel);
        iac->setObjectName(QString::fromUtf8("iac"));
        iac->setGeometry(QRect(138, 46, 64, 64));
        iac->setFont(font2);
        iac->setFocusPolicy(Qt::NoFocus);
        iac->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        iac->setIconSize(QSize(64, 64));
        vdc = new QPushButton(inputPanel);
        vdc->setObjectName(QString::fromUtf8("vdc"));
        vdc->setGeometry(QRect(226, 46, 64, 64));
        vdc->setFont(font2);
        vdc->setFocusPolicy(Qt::NoFocus);
        vdc->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        vdc->setIconSize(QSize(64, 64));
        idc = new QPushButton(inputPanel);
        idc->setObjectName(QString::fromUtf8("idc"));
        idc->setGeometry(QRect(226, 46, 64, 64));
        idc->setFont(font2);
        idc->setFocusPolicy(Qt::NoFocus);
        idc->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        idc->setIconSize(QSize(64, 64));
        manual = new QPushButton(inputPanel);
        manual->setObjectName(QString::fromUtf8("manual"));
        manual->setGeometry(QRect(314, 46, 64, 64));
        manual->setFont(font2);
        manual->setFocusPolicy(Qt::NoFocus);
        manual->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        manual->setIconSize(QSize(64, 64));
        r2w = new QPushButton(inputPanel);
        r2w->setObjectName(QString::fromUtf8("r2w"));
        r2w->setGeometry(QRect(138, 46, 64, 64));
        r2w->setFont(font2);
        r2w->setFocusPolicy(Qt::NoFocus);
        r2w->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        r2w->setIconSize(QSize(64, 64));
        Auto = new QPushButton(inputPanel);
        Auto->setObjectName(QString::fromUtf8("Auto"));
        Auto->setGeometry(QRect(314, 46, 64, 64));
        Auto->setFont(font2);
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
        vac = new QPushButton(inputPanel);
        vac->setObjectName(QString::fromUtf8("vac"));
        vac->setGeometry(QRect(138, 46, 64, 64));
        vac->setFont(font2);
        vac->setFocusPolicy(Qt::NoFocus);
        vac->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        vac->setIconSize(QSize(64, 64));
        hold = new QPushButton(inputPanel);
        hold->setObjectName(QString::fromUtf8("hold"));
        hold->setGeometry(QRect(402, 46, 64, 64));
        hold->setFont(font2);
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
        Null = new QPushButton(inputPanel);
        Null->setObjectName(QString::fromUtf8("Null"));
        Null->setGeometry(QRect(490, 46, 64, 64));
        Null->setFont(font2);
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
        rangeFrame = new QFrame(inputPanel);
        rangeFrame->setObjectName(QString::fromUtf8("rangeFrame"));
        rangeFrame->setEnabled(true);
        rangeFrame->setGeometry(QRect(100, 140, 480, 75));
        rangeFrame->setFont(font1);
        rangeFrame->setStyleSheet(QString::fromUtf8("QFrame{\n"
"color:gray;\n"
"border:1px solid white;\n"
"border-radius:10px;\n"
"}\n"
"QLabel{\n"
"color:gray;\n"
"border:0px solid white;\n"
"border-radius:0px;\n"
"}\n"
"Line{\n"
"	background-color: rgba(0, 0, 0, 0);\n"
"color:gray;\n"
"border:0px solid white;\n"
"border-radius:0px;\n"
"}"));
        rangeFrame->setFrameShape(QFrame::StyledPanel);
        rangeFrame->setFrameShadow(QFrame::Raised);
        leftArrow = new QPushButton(rangeFrame);
        leftArrow->setObjectName(QString::fromUtf8("leftArrow"));
        leftArrow->setGeometry(QRect(120, 10, 50, 60));
        leftArrow->setFocusPolicy(Qt::NoFocus);
        leftArrow->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"         border: 2px solid rgba(0,0,0,0);\n"
"         border-radius: 25px;\n"
"         background-color: rgba(0,0,0,0);\n"
"     }\n"
""));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/prev-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        leftArrow->setIcon(icon);
        leftArrow->setIconSize(QSize(50, 60));
        label_5 = new QLabel(rangeFrame);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setEnabled(true);
        label_5->setGeometry(QRect(177, 19, 121, 41));
        QFont font3;
        font3.setFamily(QString::fromUtf8("12"));
        font3.setBold(false);
        font3.setItalic(false);
        font3.setWeight(50);
        label_5->setFont(font3);
        label_5->setAutoFillBackground(false);
        label_5->setStyleSheet(QString::fromUtf8("font:24px bold;\n"
"color:white;"));
        label_5->setFrameShape(QFrame::NoFrame);
        label_5->setFrameShadow(QFrame::Sunken);
        label_5->setScaledContents(false);
        label_5->setAlignment(Qt::AlignCenter);
        line = new QFrame(rangeFrame);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(94, 59, 292, 10));
        line->setStyleSheet(QString::fromUtf8(""));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        label_6 = new QLabel(rangeFrame);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setEnabled(false);
        label_6->setGeometry(QRect(20, 30, 91, 21));
        QFont font4;
        font4.setFamily(QString::fromUtf8("DejaVu Sans"));
        font4.setPointSize(14);
        font4.setBold(false);
        font4.setWeight(50);
        label_6->setFont(font4);
        label_6->setStyleSheet(QString::fromUtf8("color:#cccccc;"));
        label_6->setScaledContents(false);
        label_6->setAlignment(Qt::AlignCenter);
        rightArrow = new QPushButton(rangeFrame);
        rightArrow->setObjectName(QString::fromUtf8("rightArrow"));
        rightArrow->setGeometry(QRect(310, 9, 50, 60));
        rightArrow->setFocusPolicy(Qt::NoFocus);
        rightArrow->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"         border: 2px solid rgba(0,0,0,0);\n"
"         border-radius: 25px;\n"
"         background-color: rgba(0,0,0,0);\n"
"     }\n"
"\n"
"  "));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/prefix1/next-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        rightArrow->setIcon(icon1);
        rightArrow->setIconSize(QSize(50, 60));
        line_4 = new QFrame(rangeFrame);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setGeometry(QRect(93, 12, 295, 10));
        line_4->setStyleSheet(QString::fromUtf8(""));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        label_4 = new QLabel(rangeFrame);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setEnabled(false);
        label_4->setGeometry(QRect(374, 29, 91, 20));
        label_4->setFont(font4);
        label_4->setStyleSheet(QString::fromUtf8("color:#cccccc;"));
        label_4->setScaledContents(false);
        label_4->setAlignment(Qt::AlignCenter);
        line_8 = new QFrame(rangeFrame);
        line_8->setObjectName(QString::fromUtf8("line_8"));
        line_8->setGeometry(QRect(90, 20, 10, 40));
        line_8->setStyleSheet(QString::fromUtf8(""));
        line_8->setFrameShape(QFrame::VLine);
        line_8->setFrameShadow(QFrame::Sunken);
        line_9 = new QFrame(rangeFrame);
        line_9->setObjectName(QString::fromUtf8("line_9"));
        line_9->setGeometry(QRect(380, 20, 10, 40));
        line_9->setStyleSheet(QString::fromUtf8(""));
        line_9->setFrameShape(QFrame::VLine);
        line_9->setFrameShadow(QFrame::Sunken);
        line->raise();
        line_4->raise();
        label_5->raise();
        label_6->raise();
        label_4->raise();
        line_8->raise();
        line_9->raise();
        leftArrow->raise();
        rightArrow->raise();
        label_8 = new QLabel(inputPanel);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(290, 13, 110, 20));
        QFont font5;
        font5.setFamily(QString::fromUtf8("DejaVu Sans"));
        font5.setBold(true);
        font5.setWeight(75);
        label_8->setFont(font5);
        label_8->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #3a5976, stop: 1 #000000);\n"
""));
        label_8->setAlignment(Qt::AlignCenter);
        label_18 = new QLabel(inputPanel);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(290, 133, 100, 20));
        label_18->setFont(font5);
        label_18->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #3a5976, stop: 1 #000000);"));
        label_18->setAlignment(Qt::AlignCenter);
        frame_5 = new QFrame(inputPanel);
        frame_5->setObjectName(QString::fromUtf8("frame_5"));
        frame_5->setGeometry(QRect(30, 20, 630, 110));
        frame_5->setStyleSheet(QString::fromUtf8("border:1px solid white;\n"
"border-radius:10px;\n"
"background-color:rgba(0,0,0,0);"));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        frame_6 = new QFrame(inputPanel);
        frame_6->setObjectName(QString::fromUtf8("frame_6"));
        frame_6->setEnabled(false);
        frame_6->setGeometry(QRect(30, 129, 630, 92));
        frame_6->setFont(font1);
        frame_6->setStyleSheet(QString::fromUtf8("border:1px solid white;\n"
"border-radius:10px;\n"
"background-color:rgba(0,0,0,0);"));
        frame_6->setFrameShape(QFrame::StyledPanel);
        frame_6->setFrameShadow(QFrame::Raised);
        Diode = new QPushButton(inputPanel);
        Diode->setObjectName(QString::fromUtf8("Diode"));
        Diode->setGeometry(QRect(226, 46, 64, 64));
        Diode->setFont(font2);
        Diode->setFocusPolicy(Qt::NoFocus);
        Diode->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color:white;\n"
"border: 1px solid #2D5059;\n"
"border-radius: 20px;\n"
"background-color: qlineargradient(x1: 0, y1: 1, x2: 1, y2: 0,stop: 0 #1A74DB, stop: 0.6 #5293DE, stop:1 #FFFFFF);\n"
"font:bold;\n"
"}"));
        Diode->setIconSize(QSize(64, 64));
        Continuity = new QPushButton(inputPanel);
        Continuity->setObjectName(QString::fromUtf8("Continuity"));
        Continuity->setGeometry(QRect(138, 46, 64, 64));
        Continuity->setFont(font2);
        Continuity->setFocusPolicy(Qt::NoFocus);
        Continuity->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        Continuity->setIconSize(QSize(64, 64));
        frame_5->raise();
        manual->raise();
        Auto->raise();
        idc->raise();
        frame_6->raise();
        r4w->raise();
        iac->raise();
        vdc->raise();
        r2w->raise();
        vac->raise();
        hold->raise();
        Null->raise();
        rangeFrame->raise();
        label_8->raise();
        label_18->raise();
        Diode->raise();
        Continuity->raise();
        displayPanel = new QFrame(DMM);
        displayPanel->setObjectName(QString::fromUtf8("displayPanel"));
        displayPanel->setGeometry(QRect(10, 33, 693, 171));
        QFont font6;
        font6.setPointSize(10);
        font6.setBold(false);
        font6.setWeight(50);
        displayPanel->setFont(font6);
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
        textEdit_4 = new QTextEdit(displayPanel);
        textEdit_4->setObjectName(QString::fromUtf8("textEdit_4"));
        textEdit_4->setGeometry(QRect(61, 10, 451, 131));
        QPalette palette1;
        QBrush brush8(QColor(255, 255, 0, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush8);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush6);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush6);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush8);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush8);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush6);
        palette1.setBrush(QPalette::Active, QPalette::HighlightedText, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush8);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush8);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush8);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush8);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush8);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush8);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush6);
        textEdit_4->setPalette(palette1);
        textEdit_4->setFrameShape(QFrame::NoFrame);
        textEdit_4->setFrameShadow(QFrame::Plain);
        textEdit_4->setCursorWidth(0);
        label_7 = new QLabel(displayPanel);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(66, 20, 57, 15));
        QPalette palette2;
        QBrush brush9(QColor(251, 236, 93, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush9);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush6);
        palette2.setBrush(QPalette::Active, QPalette::Light, brush6);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush9);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush9);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush9);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::Light, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush9);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush9);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush6);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush9);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush6);
        palette2.setBrush(QPalette::Disabled, QPalette::Light, brush6);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush9);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush9);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush6);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush6);
        label_7->setPalette(palette2);
        QFont font7;
        font7.setFamily(QString::fromUtf8("DejaVu Sans"));
        font7.setPointSize(14);
        font7.setBold(true);
        font7.setWeight(75);
        label_7->setFont(font7);
        label_7->setStyleSheet(QString::fromUtf8("color:#fbec5d;"));
        label = new QLabel(displayPanel);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(138, 120, 61, 16));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush9);
        palette3.setBrush(QPalette::Active, QPalette::Button, brush6);
        palette3.setBrush(QPalette::Active, QPalette::Midlight, brush);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush9);
        QBrush brush10(QColor(255, 255, 127, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::BrightText, brush10);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush9);
        palette3.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush6);
        palette3.setBrush(QPalette::Active, QPalette::HighlightedText, brush10);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush9);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush6);
        palette3.setBrush(QPalette::Inactive, QPalette::Midlight, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush9);
        palette3.setBrush(QPalette::Inactive, QPalette::BrightText, brush10);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush9);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush6);
        palette3.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush10);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush9);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush6);
        palette3.setBrush(QPalette::Disabled, QPalette::Midlight, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush9);
        palette3.setBrush(QPalette::Disabled, QPalette::BrightText, brush10);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush9);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush6);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush6);
        palette3.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush10);
        label->setPalette(palette3);
        label->setFont(font7);
        label->setStyleSheet(QString::fromUtf8("color:#fbec5d;"));
        label_2 = new QLabel(displayPanel);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(66, 120, 81, 16));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush9);
        palette4.setBrush(QPalette::Active, QPalette::Button, brush6);
        palette4.setBrush(QPalette::Active, QPalette::Midlight, brush);
        palette4.setBrush(QPalette::Active, QPalette::Text, brush9);
        palette4.setBrush(QPalette::Active, QPalette::ButtonText, brush9);
        palette4.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette4.setBrush(QPalette::Active, QPalette::Window, brush6);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush9);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush6);
        palette4.setBrush(QPalette::Inactive, QPalette::Midlight, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Text, brush9);
        palette4.setBrush(QPalette::Inactive, QPalette::ButtonText, brush9);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette4.setBrush(QPalette::Inactive, QPalette::Window, brush6);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush9);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush6);
        palette4.setBrush(QPalette::Disabled, QPalette::Midlight, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::Text, brush9);
        palette4.setBrush(QPalette::Disabled, QPalette::ButtonText, brush9);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush6);
        palette4.setBrush(QPalette::Disabled, QPalette::Window, brush6);
        label_2->setPalette(palette4);
        label_2->setFont(font7);
        label_2->setStyleSheet(QString::fromUtf8("color:#fbec5d;"));
        textEdit_5 = new QTextEdit(displayPanel);
        textEdit_5->setObjectName(QString::fromUtf8("textEdit_5"));
        textEdit_5->setEnabled(false);
        textEdit_5->setGeometry(QRect(63, 50, 120, 31));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush9);
        palette5.setBrush(QPalette::Active, QPalette::Button, brush6);
        palette5.setBrush(QPalette::Active, QPalette::Text, brush9);
        palette5.setBrush(QPalette::Active, QPalette::ButtonText, brush9);
        palette5.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette5.setBrush(QPalette::Active, QPalette::Window, brush6);
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush9);
        palette5.setBrush(QPalette::Inactive, QPalette::Button, brush6);
        palette5.setBrush(QPalette::Inactive, QPalette::Text, brush9);
        palette5.setBrush(QPalette::Inactive, QPalette::ButtonText, brush9);
        palette5.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette5.setBrush(QPalette::Inactive, QPalette::Window, brush6);
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush9);
        palette5.setBrush(QPalette::Disabled, QPalette::Button, brush6);
        palette5.setBrush(QPalette::Disabled, QPalette::Text, brush9);
        palette5.setBrush(QPalette::Disabled, QPalette::ButtonText, brush9);
        palette5.setBrush(QPalette::Disabled, QPalette::Base, brush6);
        palette5.setBrush(QPalette::Disabled, QPalette::Window, brush6);
        textEdit_5->setPalette(palette5);
        QFont font8;
        font8.setFamily(QString::fromUtf8("DejaVu Sans"));
        font8.setPointSize(16);
        font8.setBold(true);
        font8.setWeight(75);
        textEdit_5->setFont(font8);
        textEdit_5->setStyleSheet(QString::fromUtf8("color:#fbec5d;"));
        textEdit_5->setFrameShape(QFrame::NoFrame);
        textEdit_5->setFrameShadow(QFrame::Plain);
        textEdit_5->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textEdit_5->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textEdit_5->setCursorWidth(0);
        label_3 = new QLabel(displayPanel);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(610, 30, 33, 31));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::WindowText, brush8);
        palette6.setBrush(QPalette::Active, QPalette::Button, brush6);
        palette6.setBrush(QPalette::Active, QPalette::Text, brush8);
        palette6.setBrush(QPalette::Active, QPalette::ButtonText, brush8);
        palette6.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette6.setBrush(QPalette::Active, QPalette::Window, brush6);
        palette6.setBrush(QPalette::Inactive, QPalette::WindowText, brush8);
        palette6.setBrush(QPalette::Inactive, QPalette::Button, brush6);
        palette6.setBrush(QPalette::Inactive, QPalette::Text, brush8);
        palette6.setBrush(QPalette::Inactive, QPalette::ButtonText, brush8);
        palette6.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette6.setBrush(QPalette::Inactive, QPalette::Window, brush6);
        palette6.setBrush(QPalette::Disabled, QPalette::WindowText, brush8);
        palette6.setBrush(QPalette::Disabled, QPalette::Button, brush6);
        palette6.setBrush(QPalette::Disabled, QPalette::Text, brush8);
        palette6.setBrush(QPalette::Disabled, QPalette::ButtonText, brush8);
        palette6.setBrush(QPalette::Disabled, QPalette::Base, brush6);
        palette6.setBrush(QPalette::Disabled, QPalette::Window, brush6);
        label_3->setPalette(palette6);
        label_3->setAutoFillBackground(false);
        label_3->setStyleSheet(QString::fromUtf8(""));
        textEdit_3 = new QTextEdit(displayPanel);
        textEdit_3->setObjectName(QString::fromUtf8("textEdit_3"));
        textEdit_3->setGeometry(QRect(491, 10, 152, 131));
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::WindowText, brush8);
        palette7.setBrush(QPalette::Active, QPalette::Button, brush6);
        palette7.setBrush(QPalette::Active, QPalette::Light, brush6);
        palette7.setBrush(QPalette::Active, QPalette::Text, brush8);
        palette7.setBrush(QPalette::Active, QPalette::ButtonText, brush8);
        palette7.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette7.setBrush(QPalette::Active, QPalette::Window, brush6);
        palette7.setBrush(QPalette::Active, QPalette::HighlightedText, brush6);
        palette7.setBrush(QPalette::Inactive, QPalette::WindowText, brush8);
        palette7.setBrush(QPalette::Inactive, QPalette::Button, brush6);
        palette7.setBrush(QPalette::Inactive, QPalette::Light, brush6);
        palette7.setBrush(QPalette::Inactive, QPalette::Text, brush8);
        palette7.setBrush(QPalette::Inactive, QPalette::ButtonText, brush8);
        palette7.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette7.setBrush(QPalette::Inactive, QPalette::Window, brush6);
        palette7.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush6);
        palette7.setBrush(QPalette::Disabled, QPalette::WindowText, brush8);
        palette7.setBrush(QPalette::Disabled, QPalette::Button, brush6);
        palette7.setBrush(QPalette::Disabled, QPalette::Light, brush6);
        palette7.setBrush(QPalette::Disabled, QPalette::Text, brush8);
        palette7.setBrush(QPalette::Disabled, QPalette::ButtonText, brush8);
        palette7.setBrush(QPalette::Disabled, QPalette::Base, brush6);
        palette7.setBrush(QPalette::Disabled, QPalette::Window, brush6);
        palette7.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush6);
        textEdit_3->setPalette(palette7);
        textEdit_3->setFrameShape(QFrame::NoFrame);
        textEdit_3->setFrameShadow(QFrame::Plain);
        textEdit_3->setCursorWidth(0);
        textEdit_6 = new QTextEdit(displayPanel);
        textEdit_6->setObjectName(QString::fromUtf8("textEdit_6"));
        textEdit_6->setGeometry(QRect(141, 10, 291, 121));
        QPalette palette8;
        palette8.setBrush(QPalette::Active, QPalette::WindowText, brush8);
        palette8.setBrush(QPalette::Active, QPalette::Button, brush6);
        palette8.setBrush(QPalette::Active, QPalette::Text, brush8);
        palette8.setBrush(QPalette::Active, QPalette::ButtonText, brush8);
        palette8.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette8.setBrush(QPalette::Active, QPalette::Window, brush6);
        palette8.setBrush(QPalette::Inactive, QPalette::WindowText, brush8);
        palette8.setBrush(QPalette::Inactive, QPalette::Button, brush6);
        palette8.setBrush(QPalette::Inactive, QPalette::Text, brush8);
        palette8.setBrush(QPalette::Inactive, QPalette::ButtonText, brush8);
        palette8.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette8.setBrush(QPalette::Inactive, QPalette::Window, brush6);
        palette8.setBrush(QPalette::Disabled, QPalette::WindowText, brush8);
        palette8.setBrush(QPalette::Disabled, QPalette::Button, brush6);
        palette8.setBrush(QPalette::Disabled, QPalette::Text, brush8);
        palette8.setBrush(QPalette::Disabled, QPalette::ButtonText, brush8);
        palette8.setBrush(QPalette::Disabled, QPalette::Base, brush6);
        palette8.setBrush(QPalette::Disabled, QPalette::Window, brush6);
        textEdit_6->setPalette(palette8);
        QFont font9;
        font9.setFamily(QString::fromUtf8("DejaVu Sans"));
        font9.setPointSize(72);
        textEdit_6->setFont(font9);
        textEdit_6->setLayoutDirection(Qt::RightToLeft);
        textEdit_6->setFrameShape(QFrame::NoFrame);
        textEdit_6->setFrameShadow(QFrame::Plain);
        textEdit_6->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textEdit_6->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textEdit_6->setTextInteractionFlags(Qt::NoTextInteraction);
        label_11 = new QLabel(displayPanel);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(66, 85, 57, 15));
        QPalette palette9;
        palette9.setBrush(QPalette::Active, QPalette::WindowText, brush8);
        palette9.setBrush(QPalette::Active, QPalette::Button, brush6);
        palette9.setBrush(QPalette::Active, QPalette::Text, brush8);
        palette9.setBrush(QPalette::Active, QPalette::ButtonText, brush8);
        palette9.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette9.setBrush(QPalette::Active, QPalette::Window, brush6);
        palette9.setBrush(QPalette::Inactive, QPalette::WindowText, brush8);
        palette9.setBrush(QPalette::Inactive, QPalette::Button, brush6);
        palette9.setBrush(QPalette::Inactive, QPalette::Text, brush8);
        palette9.setBrush(QPalette::Inactive, QPalette::ButtonText, brush8);
        palette9.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette9.setBrush(QPalette::Inactive, QPalette::Window, brush6);
        palette9.setBrush(QPalette::Disabled, QPalette::WindowText, brush8);
        palette9.setBrush(QPalette::Disabled, QPalette::Button, brush6);
        palette9.setBrush(QPalette::Disabled, QPalette::Text, brush8);
        palette9.setBrush(QPalette::Disabled, QPalette::ButtonText, brush8);
        palette9.setBrush(QPalette::Disabled, QPalette::Base, brush6);
        palette9.setBrush(QPalette::Disabled, QPalette::Window, brush6);
        label_11->setPalette(palette9);
        QFont font10;
        font10.setPointSize(14);
        font10.setBold(true);
        font10.setWeight(75);
        label_11->setFont(font10);
        label_12 = new QLabel(displayPanel);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(591, 120, 51, 21));
        lineEdit_3 = new QLineEdit(displayPanel);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setEnabled(false);
        lineEdit_3->setGeometry(QRect(141, 11, 331, 121));
        QPalette palette10;
        QBrush brush11(QColor(249, 255, 153, 255));
        brush11.setStyle(Qt::SolidPattern);
        palette10.setBrush(QPalette::Active, QPalette::WindowText, brush11);
        palette10.setBrush(QPalette::Active, QPalette::Button, brush6);
        palette10.setBrush(QPalette::Active, QPalette::Text, brush11);
        palette10.setBrush(QPalette::Active, QPalette::ButtonText, brush11);
        palette10.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette10.setBrush(QPalette::Active, QPalette::Window, brush6);
        palette10.setBrush(QPalette::Inactive, QPalette::WindowText, brush11);
        palette10.setBrush(QPalette::Inactive, QPalette::Button, brush6);
        palette10.setBrush(QPalette::Inactive, QPalette::Text, brush11);
        palette10.setBrush(QPalette::Inactive, QPalette::ButtonText, brush11);
        palette10.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette10.setBrush(QPalette::Inactive, QPalette::Window, brush6);
        palette10.setBrush(QPalette::Disabled, QPalette::WindowText, brush11);
        palette10.setBrush(QPalette::Disabled, QPalette::Button, brush6);
        palette10.setBrush(QPalette::Disabled, QPalette::Text, brush11);
        palette10.setBrush(QPalette::Disabled, QPalette::ButtonText, brush11);
        palette10.setBrush(QPalette::Disabled, QPalette::Base, brush6);
        palette10.setBrush(QPalette::Disabled, QPalette::Window, brush6);
        lineEdit_3->setPalette(palette10);
        QFont font11;
        font11.setFamily(QString::fromUtf8("DejaVu Sans"));
        font11.setPointSize(72);
        font11.setStyleStrategy(QFont::PreferAntialias);
        lineEdit_3->setFont(font11);
        lineEdit_3->setCursor(QCursor(Qt::BlankCursor));
        lineEdit_3->setMouseTracking(false);
        lineEdit_3->setFocusPolicy(Qt::NoFocus);
        lineEdit_3->setAutoFillBackground(false);
        lineEdit_3->setStyleSheet(QString::fromUtf8("color:#f9ff99;"));
        lineEdit_3->setFrame(false);
        lineEdit_3->setEchoMode(QLineEdit::Normal);
        lineEdit_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_3->setReadOnly(true);
        lineEdit_4 = new QLineEdit(displayPanel);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setEnabled(false);
        lineEdit_4->setGeometry(QRect(490, 25, 130, 90));
        QFont font12;
        font12.setFamily(QString::fromUtf8("DejaVu Sans"));
        font12.setPointSize(55);
        lineEdit_4->setFont(font12);
        lineEdit_4->setFocusPolicy(Qt::NoFocus);
        lineEdit_4->setAutoFillBackground(false);
        lineEdit_4->setStyleSheet(QString::fromUtf8("color:#fbec5d;"));
        lineEdit_4->setFrame(false);
        lineEdit_4->setEchoMode(QLineEdit::Normal);
        lineEdit_4->setAlignment(Qt::AlignCenter);
        lineEdit_4->setReadOnly(true);
        holdLabel = new QLabel(displayPanel);
        holdLabel->setObjectName(QString::fromUtf8("holdLabel"));
        holdLabel->setGeometry(QRect(598, 10, 42, 31));
        QPalette palette11;
        palette11.setBrush(QPalette::Active, QPalette::WindowText, brush9);
        palette11.setBrush(QPalette::Active, QPalette::Button, brush6);
        palette11.setBrush(QPalette::Active, QPalette::Text, brush9);
        palette11.setBrush(QPalette::Active, QPalette::ButtonText, brush9);
        palette11.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette11.setBrush(QPalette::Active, QPalette::Window, brush6);
        palette11.setBrush(QPalette::Inactive, QPalette::WindowText, brush9);
        palette11.setBrush(QPalette::Inactive, QPalette::Button, brush6);
        palette11.setBrush(QPalette::Inactive, QPalette::Text, brush9);
        palette11.setBrush(QPalette::Inactive, QPalette::ButtonText, brush9);
        palette11.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette11.setBrush(QPalette::Inactive, QPalette::Window, brush6);
        palette11.setBrush(QPalette::Disabled, QPalette::WindowText, brush9);
        palette11.setBrush(QPalette::Disabled, QPalette::Button, brush6);
        palette11.setBrush(QPalette::Disabled, QPalette::Text, brush9);
        palette11.setBrush(QPalette::Disabled, QPalette::ButtonText, brush9);
        palette11.setBrush(QPalette::Disabled, QPalette::Base, brush6);
        palette11.setBrush(QPalette::Disabled, QPalette::Window, brush6);
        holdLabel->setPalette(palette11);
        holdLabel->setFont(font5);
        holdLabel->setAutoFillBackground(false);
        holdLabel->setStyleSheet(QString::fromUtf8("color:#fbec5d;"));
        holdLabel->setAlignment(Qt::AlignCenter);
        label_10 = new QLabel(displayPanel);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(540, 120, 100, 16));
        QPalette palette12;
        palette12.setBrush(QPalette::Active, QPalette::WindowText, brush9);
        palette12.setBrush(QPalette::Active, QPalette::Button, brush6);
        palette12.setBrush(QPalette::Active, QPalette::Midlight, brush);
        palette12.setBrush(QPalette::Active, QPalette::Text, brush9);
        palette12.setBrush(QPalette::Active, QPalette::BrightText, brush10);
        palette12.setBrush(QPalette::Active, QPalette::ButtonText, brush9);
        palette12.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette12.setBrush(QPalette::Active, QPalette::Window, brush6);
        palette12.setBrush(QPalette::Active, QPalette::HighlightedText, brush10);
        palette12.setBrush(QPalette::Inactive, QPalette::WindowText, brush9);
        palette12.setBrush(QPalette::Inactive, QPalette::Button, brush6);
        palette12.setBrush(QPalette::Inactive, QPalette::Midlight, brush);
        palette12.setBrush(QPalette::Inactive, QPalette::Text, brush9);
        palette12.setBrush(QPalette::Inactive, QPalette::BrightText, brush10);
        palette12.setBrush(QPalette::Inactive, QPalette::ButtonText, brush9);
        palette12.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette12.setBrush(QPalette::Inactive, QPalette::Window, brush6);
        palette12.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush10);
        palette12.setBrush(QPalette::Disabled, QPalette::WindowText, brush9);
        palette12.setBrush(QPalette::Disabled, QPalette::Button, brush6);
        palette12.setBrush(QPalette::Disabled, QPalette::Midlight, brush);
        palette12.setBrush(QPalette::Disabled, QPalette::Text, brush9);
        palette12.setBrush(QPalette::Disabled, QPalette::BrightText, brush10);
        palette12.setBrush(QPalette::Disabled, QPalette::ButtonText, brush9);
        palette12.setBrush(QPalette::Disabled, QPalette::Base, brush6);
        palette12.setBrush(QPalette::Disabled, QPalette::Window, brush6);
        palette12.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush10);
        label_10->setPalette(palette12);
        label_10->setFont(font7);
        label_10->setStyleSheet(QString::fromUtf8("color:#fbec5d;"));
        label_14 = new QLabel(displayPanel);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(492, 120, 45, 16));
        QPalette palette13;
        palette13.setBrush(QPalette::Active, QPalette::WindowText, brush9);
        palette13.setBrush(QPalette::Active, QPalette::Button, brush6);
        palette13.setBrush(QPalette::Active, QPalette::Midlight, brush);
        palette13.setBrush(QPalette::Active, QPalette::Text, brush9);
        palette13.setBrush(QPalette::Active, QPalette::ButtonText, brush9);
        palette13.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette13.setBrush(QPalette::Active, QPalette::Window, brush6);
        palette13.setBrush(QPalette::Inactive, QPalette::WindowText, brush9);
        palette13.setBrush(QPalette::Inactive, QPalette::Button, brush6);
        palette13.setBrush(QPalette::Inactive, QPalette::Midlight, brush);
        palette13.setBrush(QPalette::Inactive, QPalette::Text, brush9);
        palette13.setBrush(QPalette::Inactive, QPalette::ButtonText, brush9);
        palette13.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette13.setBrush(QPalette::Inactive, QPalette::Window, brush6);
        palette13.setBrush(QPalette::Disabled, QPalette::WindowText, brush9);
        palette13.setBrush(QPalette::Disabled, QPalette::Button, brush6);
        palette13.setBrush(QPalette::Disabled, QPalette::Midlight, brush);
        palette13.setBrush(QPalette::Disabled, QPalette::Text, brush9);
        palette13.setBrush(QPalette::Disabled, QPalette::ButtonText, brush9);
        palette13.setBrush(QPalette::Disabled, QPalette::Base, brush6);
        palette13.setBrush(QPalette::Disabled, QPalette::Window, brush6);
        label_14->setPalette(palette13);
        label_14->setFont(font7);
        label_14->setStyleSheet(QString::fromUtf8("color:#fbec5d;"));
        textEdit_4->raise();
        label_7->raise();
        label_2->raise();
        textEdit_5->raise();
        textEdit_3->raise();
        textEdit_6->raise();
        label_11->raise();
        label_12->raise();
        lineEdit_3->raise();
        lineEdit_4->raise();
        holdLabel->raise();
        label_10->raise();
        label_14->raise();
        label->raise();
        label_3->raise();
        textEdit = new QTextEdit(DMM);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setEnabled(false);
        textEdit->setGeometry(QRect(910, 350, 21, 21));
        textEdit->setSizeIncrement(QSize(0, 0));
        QFont font13;
        font13.setFamily(QString::fromUtf8("DejaVu Sans Mono"));
        font13.setPointSize(40);
        font13.setBold(false);
        font13.setItalic(false);
        font13.setWeight(50);
        textEdit->setFont(font13);
        textEdit->setLayoutDirection(Qt::RightToLeft);
        textEdit->setFrameShape(QFrame::NoFrame);
        textEdit->setFrameShadow(QFrame::Plain);
        textEdit->setCursorWidth(0);
        lineEdit = new QLineEdit(DMM);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(932, 160, 41, 21));
        voltBox = new QGroupBox(DMM);
        voltBox->setObjectName(QString::fromUtf8("voltBox"));
        voltBox->setGeometry(QRect(710, 33, 80, 100));
        voltBox->setFont(font1);
        voltBox->setStyleSheet(QString::fromUtf8("QGroupBox{border:1px solid white; background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #3a5976, stop: 1 #000000);border-radius:10px;border-bottom:1px qlineargradient(x1: 0, y1: 0,stop: 0 #f6f7fa, stop: 1 #dadbde); border-bottom-right-radius: 0px;border-bottom-left-radius: 0px;}"));
        voltMeter = new QPushButton(voltBox);
        voltMeter->setObjectName(QString::fromUtf8("voltMeter"));
        voltMeter->setGeometry(QRect(8, 20, 64, 64));
        voltMeter->setStyleSheet(QString::fromUtf8("QPushButton {border: 1px solid #8f8f91; border-radius: 8px; background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #f6f7fa, stop: 1 #dadbde); color:blue;}\n"
""));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/prefix1/voltmeter.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        voltMeter->setIcon(icon2);
        voltMeter->setIconSize(QSize(55, 55));
        selectFrame = new QFrame(DMM);
        selectFrame->setObjectName(QString::fromUtf8("selectFrame"));
        selectFrame->setGeometry(QRect(701, 54, 10, 60));
        selectFrame->setStyleSheet(QString::fromUtf8("/*background-color: qlineargradient(x1: 0, y1: 0,stop: 0 #f6f7fa, stop: 1 #dadbde);*/\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #3a5976, stop: 1 #000000);\n"
"border-top:1px solid white;\n"
"border-bottom:1px solid white;"));
        selectFrame->setFrameShape(QFrame::Box);
        selectFrame->setFrameShadow(QFrame::Raised);
        AmpBox = new QGroupBox(DMM);
        AmpBox->setObjectName(QString::fromUtf8("AmpBox"));
        AmpBox->setGeometry(QRect(710, 132, 80, 100));
        AmpBox->setFont(font1);
        AmpBox->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
"border:1px solid white; background-color: #dadbde;border-radius:10px;border-bottom:1px qlineargradient(x1: 0, y1: 0,stop: 0 #f6f7fa, stop: 1 #dadbde);border- border-top-left-radius: 0px;\n"
"border-top:1px solid gray;\n"
";border-bottom-right-radius: 0px;\n"
" border-bottom-left-radius: 0px;\n"
"border-top:1px solid gray; border-top-right-radius: 0px;\n"
" border-top-left-radius: 0px;\n"
"}\n"
""));
        ampMeter = new QPushButton(AmpBox);
        ampMeter->setObjectName(QString::fromUtf8("ampMeter"));
        ampMeter->setGeometry(QRect(8, 19, 64, 64));
        ampMeter->setStyleSheet(QString::fromUtf8("QPushButton {border: 1px solid #8f8f91; border-radius: 8px; background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #f6f7fa, stop: 1 #dadbde); color:blue;}\n"
""));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/new/prefix1/Ammeter.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        ampMeter->setIcon(icon3);
        ampMeter->setIconSize(QSize(55, 55));
        OhmBox = new QGroupBox(DMM);
        OhmBox->setObjectName(QString::fromUtf8("OhmBox"));
        OhmBox->setGeometry(QRect(710, 232, 80, 100));
        OhmBox->setFont(font1);
        OhmBox->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
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
        ohmMeter = new QPushButton(OhmBox);
        ohmMeter->setObjectName(QString::fromUtf8("ohmMeter"));
        ohmMeter->setGeometry(QRect(8, 20, 64, 64));
        ohmMeter->setStyleSheet(QString::fromUtf8("QPushButton {border: 1px solid #8f8f91; border-radius: 8px; background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #f6f7fa, stop: 1 #dadbde); color:blue;}\n"
""));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/new/prefix1/Ohmmeter.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        ohmMeter->setIcon(icon4);
        ohmMeter->setIconSize(QSize(55, 55));
        ExitBox = new QGroupBox(DMM);
        ExitBox->setObjectName(QString::fromUtf8("ExitBox"));
        ExitBox->setGeometry(QRect(710, 532, 80, 61));
        ExitBox->setFont(font1);
        ExitBox->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
"border:1px solid white; background-color: #dadbde;border-radius:10px;\n"
"border-top:1px qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #f6f7fa, stop: 1 #dadbde); border-top-right-radius: 0px;\n"
" border-top-left-radius: 0px;\n"
"border-top:1px solid gray;\n"
"}\n"
""));
        exit = new QPushButton(ExitBox);
        exit->setObjectName(QString::fromUtf8("exit"));
        exit->setGeometry(QRect(5, 0, 64, 70));
        exit->setFocusPolicy(Qt::NoFocus);
        exit->setStyleSheet(QString::fromUtf8("QPushButton {border: 1px solid rgba(0,0,0,0); border-radius: 8px; background-color: rgba(0,0,0,0);color:blue;\n"
"	image: url(:/logout-icon.png);\n"
"}\n"
""));
        exit->setIconSize(QSize(70, 70));
        OhmBox_2 = new QGroupBox(DMM);
        OhmBox_2->setObjectName(QString::fromUtf8("OhmBox_2"));
        OhmBox_2->setGeometry(QRect(710, 332, 80, 100));
        OhmBox_2->setFont(font1);
        OhmBox_2->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
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
        ohmMeter_2 = new QPushButton(OhmBox_2);
        ohmMeter_2->setObjectName(QString::fromUtf8("ohmMeter_2"));
        ohmMeter_2->setGeometry(QRect(8, 20, 64, 64));
        ohmMeter_2->setStyleSheet(QString::fromUtf8("QPushButton {border: 1px solid #8f8f91; border-radius: 8px; background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #f6f7fa, stop: 1 #dadbde); color:blue;}\n"
""));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/new/prefix1/graph.png"), QSize(), QIcon::Normal, QIcon::Off);
        ohmMeter_2->setIcon(icon5);
        ohmMeter_2->setIconSize(QSize(85, 85));
        OhmBox_3 = new QGroupBox(DMM);
        OhmBox_3->setObjectName(QString::fromUtf8("OhmBox_3"));
        OhmBox_3->setGeometry(QRect(710, 432, 80, 100));
        OhmBox_3->setFont(font1);
        OhmBox_3->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
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
        ohmMeter_3 = new QPushButton(OhmBox_3);
        ohmMeter_3->setObjectName(QString::fromUtf8("ohmMeter_3"));
        ohmMeter_3->setGeometry(QRect(8, 20, 64, 64));
        ohmMeter_3->setStyleSheet(QString::fromUtf8("QPushButton {border: 1px solid #8f8f91; border-radius: 8px; background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #f6f7fa, stop: 1 #dadbde); color:blue;}\n"
""));
        ohmMeter_3->setIconSize(QSize(55, 55));
        debugPanel = new QGroupBox(DMM);
        debugPanel->setObjectName(QString::fromUtf8("debugPanel"));
        debugPanel->setGeometry(QRect(10, 434, 693, 160));
        QFont font14;
        font14.setBold(true);
        font14.setWeight(75);
        debugPanel->setFont(font14);
        debugPanel->setStyleSheet(QString::fromUtf8("QGroupBox{border:1px solid black; background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #ffffff, stop: 1 #dadbff);border-radius:10px;}\n"
" QGroupBox::title {\n"
"     subcontrol-origin: margin;\n"
"     subcontrol-position: top center; /* position at the top center */\n"
"     padding: 0 3px;\n"
"	 border: 2px solid black;\n"
" }"));
        pushButton_16 = new QPushButton(debugPanel);
        pushButton_16->setObjectName(QString::fromUtf8("pushButton_16"));
        pushButton_16->setGeometry(QRect(250, 40, 50, 50));
        pushButton_16->setStyleSheet(QString::fromUtf8("QPushButton {border: 1px solid #8f8f91; border-radius: 8px; background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #f6f7fa, stop: 1 #dadbde); color:blue;}\n"
""));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/Letter-R-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_16->setIcon(icon6);
        pushButton_16->setIconSize(QSize(48, 48));
        pushButton_14 = new QPushButton(debugPanel);
        pushButton_14->setObjectName(QString::fromUtf8("pushButton_14"));
        pushButton_14->setGeometry(QRect(90, 40, 50, 50));
        pushButton_14->setStyleSheet(QString::fromUtf8("QPushButton {border: 1px solid #8f8f91; border-radius: 8px; background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #f6f7fa, stop: 1 #dadbde); color:blue;}\n"
""));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/Letter-C-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_14->setIcon(icon7);
        pushButton_14->setIconSize(QSize(48, 48));
        pushButton = new QPushButton(debugPanel);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(330, 40, 50, 50));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton {border: 1px solid #8f8f91; border-radius: 8px; background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #f6f7fa, stop: 1 #dadbde); color:blue;}\n"
""));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/Control-Panel-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon8);
        pushButton->setIconSize(QSize(48, 48));
        pushButton_13 = new QPushButton(debugPanel);
        pushButton_13->setObjectName(QString::fromUtf8("pushButton_13"));
        pushButton_13->setGeometry(QRect(170, 40, 50, 50));
        pushButton_13->setStyleSheet(QString::fromUtf8("QPushButton {border: 1px solid #8f8f91; border-radius: 8px; background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #f6f7fa, stop: 1 #dadbde); color:blue;}\n"
""));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/Letter-G-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_13->setIcon(icon9);
        pushButton_13->setIconSize(QSize(48, 48));
        pushButton_15 = new QPushButton(debugPanel);
        pushButton_15->setObjectName(QString::fromUtf8("pushButton_15"));
        pushButton_15->setGeometry(QRect(10, 40, 50, 50));
        pushButton_15->setStyleSheet(QString::fromUtf8("QPushButton {border: 1px solid #8f8f91; border-radius: 8px; background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #f6f7fa, stop: 1 #dadbde); color:blue;}\n"
""));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/Letter-A-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_15->setIcon(icon10);
        pushButton_15->setIconSize(QSize(48, 48));
        calibrateDisplay = new QCheckBox(debugPanel);
        calibrateDisplay->setObjectName(QString::fromUtf8("calibrateDisplay"));
        calibrateDisplay->setGeometry(QRect(410, 50, 170, 31));
        QFont font15;
        font15.setBold(false);
        font15.setItalic(false);
        font15.setWeight(50);
        calibrateDisplay->setFont(font15);
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
        haadcFrame->setFont(font1);
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
        label_22->setGeometry(QRect(10, 120, 110, 17));
        label_22->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_23 = new QLabel(debugPanel);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(270, 120, 120, 30));
        label_23->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        adcRawData = new QLineEdit(debugPanel);
        adcRawData->setObjectName(QString::fromUtf8("adcRawData"));
        adcRawData->setGeometry(QRect(120, 114, 140, 29));
        adcRawData->setFont(font5);
        adcRawData->setAlignment(Qt::AlignCenter);
        adcConvData = new QLineEdit(debugPanel);
        adcConvData->setObjectName(QString::fromUtf8("adcConvData"));
        adcConvData->setGeometry(QRect(390, 118, 210, 29));
        adcConvData->setFont(font5);
        adcConvData->setAlignment(Qt::AlignCenter);
        displayInput = new QLineEdit(debugPanel);
        displayInput->setObjectName(QString::fromUtf8("displayInput"));
        displayInput->setGeometry(QRect(370, 84, 230, 29));
        displayInput->setFont(font5);
        displayInput->setAlignment(Qt::AlignCenter);
        label_25 = new QLabel(debugPanel);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setGeometry(QRect(270, 87, 120, 30));
        label_25->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        pushButton_2 = new QPushButton(debugPanel);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(440, 10, 191, 27));
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color:black;\n"
"border: 1px solid #2D5059;\n"
"border-radius: 20px;\n"
"background-color: orange;\n"
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
        frontPanel_DMM = new QFrame(DMM);
        frontPanel_DMM->setObjectName(QString::fromUtf8("frontPanel_DMM"));
        frontPanel_DMM->setGeometry(QRect(10, 434, 693, 160));
        frontPanel_DMM->setStyleSheet(QString::fromUtf8("/*QFrame{border:1px solid black; background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #ffffff, stop: 1 #dadbff);border-radius:10px;}\n"
"QLabel{border:1px solid rgba(0,0,0,0);}*/\n"
"QFrame {\n"
"      background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 1 #3a5976, stop: 0 #000000);\n"
"     border: 2px solid white;\n"
"     border-radius: 5px;\n"
"     margin-top: 0ex; /* leave space at the top for the title */\n"
" }\n"
""));
        frontPanel_DMM->setFrameShape(QFrame::StyledPanel);
        frontPanel_DMM->setFrameShadow(QFrame::Raised);
        framePowerUSB = new QFrame(frontPanel_DMM);
        framePowerUSB->setObjectName(QString::fromUtf8("framePowerUSB"));
        framePowerUSB->setGeometry(QRect(5, 6, 47, 150));
        framePowerUSB->setStyleSheet(QString::fromUtf8("QFrame{border:1px solid black;\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #ffffff, stop: 1 #ffffff);\n"
"border-radius:10px;}\n"
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
        QFont font16;
        font16.setFamily(QString::fromUtf8("DejaVu Sans"));
        font16.setPointSize(9);
        font16.setBold(false);
        font16.setWeight(50);
        fp_powerLabel->setFont(font16);
        fp_powerLabel->setStyleSheet(QString::fromUtf8("color: rgb(53, 53, 53);"));
        analogHighway = new QFrame(frontPanel_DMM);
        analogHighway->setObjectName(QString::fromUtf8("analogHighway"));
        analogHighway->setGeometry(QRect(54, 6, 296, 72));
        analogHighway->setStyleSheet(QString::fromUtf8("QFrame{\n"
"border-top-right-radius:10px;\n"
"border-top-left-radius:10px;\n"
"border-bottom-left-radius:10px;\n"
"border-bottom-right-radius:0px;\n"
"border:1px solid black; background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #a09f9e, stop: 1 #a09f9e);\n"
"}\n"
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
        ah3_label->setFont(font16);
        ah3_label->setStyleSheet(QString::fromUtf8("color: rgb(53, 53, 53);"));
        ah1_label = new QLabel(analogHighway);
        ah1_label->setObjectName(QString::fromUtf8("ah1_label"));
        ah1_label->setGeometry(QRect(26, 11, 38, 17));
        ah1_label->setFont(font16);
        ah1_label->setStyleSheet(QString::fromUtf8("color: rgb(53, 53, 53);"));
        ah1_outer = new QFrame(analogHighway);
        ah1_outer->setObjectName(QString::fromUtf8("ah1_outer"));
        ah1_outer->setGeometry(QRect(22, 26, 41, 41));
        ah1_outer->setStyleSheet(QString::fromUtf8("border:1px solid rgb(53, 53, 53);border-radius:20px;\n"
"image: url(:/new/prefix1/Button-Blank-Gray-icon.png);"));
        ah1_outer->setFrameShape(QFrame::StyledPanel);
        ah1_outer->setFrameShadow(QFrame::Raised);
        ah1_inner = new QFrame(ah1_outer);
        ah1_inner->setObjectName(QString::fromUtf8("ah1_inner"));
        ah1_inner->setGeometry(QRect(15, 15, 10, 10));
        ah1_inner->setStyleSheet(QString::fromUtf8("border:1px solid rgb(53, 53, 53);border-radius:4px;\n"
""));
        ah1_inner->setFrameShape(QFrame::StyledPanel);
        ah1_inner->setFrameShadow(QFrame::Raised);
        ah3_outer = new QFrame(analogHighway);
        ah3_outer->setObjectName(QString::fromUtf8("ah3_outer"));
        ah3_outer->setGeometry(QRect(96, 26, 41, 41));
        ah3_outer->setStyleSheet(QString::fromUtf8("border:1px solid rgb(53, 53, 53);border-radius:20px;\n"
"image: url(:/new/prefix1/Button-Blank-Gray-icon.png);"));
        ah3_outer->setFrameShape(QFrame::StyledPanel);
        ah3_outer->setFrameShadow(QFrame::Raised);
        ah_inner = new QFrame(ah3_outer);
        ah_inner->setObjectName(QString::fromUtf8("ah_inner"));
        ah_inner->setGeometry(QRect(15, 15, 10, 10));
        ah_inner->setStyleSheet(QString::fromUtf8("border:1px solid rgb(53, 53, 53);border-radius:4px;\n"
""));
        ah_inner->setFrameShape(QFrame::StyledPanel);
        ah_inner->setFrameShadow(QFrame::Raised);
        ah_label = new QLabel(analogHighway);
        ah_label->setObjectName(QString::fromUtf8("ah_label"));
        ah_label->setGeometry(QRect(7, 0, 287, 16));
        ah_label->setFont(font5);
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
        ah0_label->setFont(font16);
        ah0_label->setStyleSheet(QString::fromUtf8("color: rgb(53, 53, 53);\n"
"background-color: rgb(0, 0, 0,0);"));
        ah0_outer = new QFrame(analogHighway);
        ah0_outer->setObjectName(QString::fromUtf8("ah0_outer"));
        ah0_outer->setGeometry(QRect(237, 26, 41, 41));
        ah0_outer->setStyleSheet(QString::fromUtf8("border:1px solid rgb(53, 53, 53);border-radius:20px;\n"
"image: url(:/new/prefix1/Button-Blank-Gray-icon.png);"));
        ah0_outer->setFrameShape(QFrame::StyledPanel);
        ah0_outer->setFrameShadow(QFrame::Raised);
        ah0_inner = new QFrame(ah0_outer);
        ah0_inner->setObjectName(QString::fromUtf8("ah0_inner"));
        ah0_inner->setGeometry(QRect(16, 15, 10, 10));
        ah0_inner->setStyleSheet(QString::fromUtf8("border:1px solid rgb(53, 53, 53);border-radius:4px;\n"
""));
        ah0_inner->setFrameShape(QFrame::StyledPanel);
        ah0_inner->setFrameShadow(QFrame::Raised);
        ah2_label = new QLabel(analogHighway);
        ah2_label->setObjectName(QString::fromUtf8("ah2_label"));
        ah2_label->setGeometry(QRect(170, 11, 35, 17));
        ah2_label->setFont(font16);
        ah2_label->setStyleSheet(QString::fromUtf8("color: rgb(53, 53, 53);"));
        ah2_outer = new QFrame(analogHighway);
        ah2_outer->setObjectName(QString::fromUtf8("ah2_outer"));
        ah2_outer->setGeometry(QRect(167, 26, 41, 41));
        ah2_outer->setStyleSheet(QString::fromUtf8("border:1px solid rgb(53, 53, 53);border-radius:20px;\n"
"image: url(:/new/prefix1/Button-Blank-Gray-icon.png);"));
        ah2_outer->setFrameShape(QFrame::StyledPanel);
        ah2_outer->setFrameShadow(QFrame::Raised);
        ah2_inner = new QFrame(ah2_outer);
        ah2_inner->setObjectName(QString::fromUtf8("ah2_inner"));
        ah2_inner->setGeometry(QRect(16, 15, 10, 10));
        ah2_inner->setStyleSheet(QString::fromUtf8("border:1px solid rgb(53, 53, 53);border-radius:4px;\n"
""));
        ah2_inner->setFrameShape(QFrame::StyledPanel);
        ah2_inner->setFrameShadow(QFrame::Raised);
        fp_VI_ICM_SL = new QFrame(frontPanel_DMM);
        fp_VI_ICM_SL->setObjectName(QString::fromUtf8("fp_VI_ICM_SL"));
        fp_VI_ICM_SL->setGeometry(QRect(54, 84, 186, 72));
        fp_VI_ICM_SL->setStyleSheet(QString::fromUtf8("QFrame{border:1px solid black; background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #a09f9e, stop: 1 #a09f9e);border-radius:10px;}\n"
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
        fp_VI2_EXT->setGeometry(QRect(110, 27, 41, 41));
        fp_VI2_EXT->setStyleSheet(QString::fromUtf8("border:1px solid rgb(53, 53, 53);border-radius:20px;\n"
"image: url(:/new/prefix1/Button-Blank-Gray-icon.png);"));
        fp_VI2_EXT->setFrameShape(QFrame::StyledPanel);
        fp_VI2_EXT->setFrameShadow(QFrame::Raised);
        fp_VI1_ICM_SL_label = new QLabel(fp_VI_ICM_SL);
        fp_VI1_ICM_SL_label->setObjectName(QString::fromUtf8("fp_VI1_ICM_SL_label"));
        fp_VI1_ICM_SL_label->setGeometry(QRect(20, 14, 60, 17));
        fp_VI1_ICM_SL_label->setFont(font16);
        fp_VI1_ICM_SL_label->setStyleSheet(QString::fromUtf8("color: rgb(53, 53, 53);"));
        fp_VI2_EXT_label = new QLabel(fp_VI_ICM_SL);
        fp_VI2_EXT_label->setObjectName(QString::fromUtf8("fp_VI2_EXT_label"));
        fp_VI2_EXT_label->setGeometry(QRect(106, 14, 60, 17));
        fp_VI2_EXT_label->setFont(font16);
        fp_VI2_EXT_label->setStyleSheet(QString::fromUtf8("color: rgb(53, 53, 53);"));
        fp_VI1_ICM_SL = new QFrame(fp_VI_ICM_SL);
        fp_VI1_ICM_SL->setObjectName(QString::fromUtf8("fp_VI1_ICM_SL"));
        fp_VI1_ICM_SL->setGeometry(QRect(24, 27, 41, 41));
        fp_VI1_ICM_SL->setStyleSheet(QString::fromUtf8("border:1px solid rgb(53, 53, 53);border-radius:20px;\n"
"image: url(:/new/prefix1/Button-Blank-Gray-icon.png);"));
        fp_VI1_ICM_SL->setFrameShape(QFrame::StyledPanel);
        fp_VI1_ICM_SL->setFrameShadow(QFrame::Raised);
        fp_ICM_Guard = new QLabel(fp_VI_ICM_SL);
        fp_ICM_Guard->setObjectName(QString::fromUtf8("fp_ICM_Guard"));
        fp_ICM_Guard->setGeometry(QRect(196, 1, 75, 17));
        fp_ICM_Guard->setFont(font16);
        fp_ICM_Guard->setStyleSheet(QString::fromUtf8("color: rgb(53, 53, 53);"));
        fp_DMM_label_2 = new QLabel(fp_VI_ICM_SL);
        fp_DMM_label_2->setObjectName(QString::fromUtf8("fp_DMM_label_2"));
        fp_DMM_label_2->setGeometry(QRect(0, 0, 190, 16));
        fp_DMM_label_2->setFont(font5);
        fp_DMM_label_2->setStyleSheet(QString::fromUtf8("/*background-color:blue;\n"
"color: rgb(0, 85, 255);\n"
"color:white;\n"
"border:1px solid black;\n"
"border-radius:8px;*/\n"
"color: rgb(0, 85, 255);"));
        fp_DMM_label_2->setAlignment(Qt::AlignCenter);
        frame_15 = new QFrame(frontPanel_DMM);
        frame_15->setObjectName(QString::fromUtf8("frame_15"));
        frame_15->setGeometry(QRect(355, 6, 300, 72));
        frame_15->setStyleSheet(QString::fromUtf8("QFrame{border:1px solid black; background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #a09f9e, stop: 1 #a09f9e);border-radius:10px;}\n"
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
        label_74->setFont(font16);
        label_74->setStyleSheet(QString::fromUtf8("color: rgb(53, 53, 53);"));
        label_75 = new QLabel(frame_15);
        label_75->setObjectName(QString::fromUtf8("label_75"));
        label_75->setGeometry(QRect(26, 12, 38, 17));
        label_75->setFont(font16);
        label_75->setStyleSheet(QString::fromUtf8("color: rgb(53, 53, 53);"));
        dso1_outer_9 = new QFrame(frame_15);
        dso1_outer_9->setObjectName(QString::fromUtf8("dso1_outer_9"));
        dso1_outer_9->setGeometry(QRect(22, 27, 41, 41));
        dso1_outer_9->setStyleSheet(QString::fromUtf8("border:1px solid rgb(53, 53, 53);border-radius:20px;\n"
"image: url(:/new/prefix1/Button-Blank-Gray-icon.png);"));
        dso1_outer_9->setFrameShape(QFrame::StyledPanel);
        dso1_outer_9->setFrameShadow(QFrame::Raised);
        dso1_inner_6 = new QFrame(dso1_outer_9);
        dso1_inner_6->setObjectName(QString::fromUtf8("dso1_inner_6"));
        dso1_inner_6->setGeometry(QRect(15, 15, 10, 10));
        dso1_inner_6->setStyleSheet(QString::fromUtf8("border:1px solid rgb(53, 53, 53);border-radius:4px;\n"
""));
        dso1_inner_6->setFrameShape(QFrame::StyledPanel);
        dso1_inner_6->setFrameShadow(QFrame::Raised);
        dso_outer_18 = new QFrame(frame_15);
        dso_outer_18->setObjectName(QString::fromUtf8("dso_outer_18"));
        dso_outer_18->setGeometry(QRect(96, 27, 41, 41));
        dso_outer_18->setStyleSheet(QString::fromUtf8("border:1px solid rgb(53, 53, 53);border-radius:20px;\n"
"image: url(:/new/prefix1/Button-Blank-Gray-icon.png);"));
        dso_outer_18->setFrameShape(QFrame::StyledPanel);
        dso_outer_18->setFrameShadow(QFrame::Raised);
        dso_inner_6 = new QFrame(dso_outer_18);
        dso_inner_6->setObjectName(QString::fromUtf8("dso_inner_6"));
        dso_inner_6->setGeometry(QRect(15, 15, 10, 10));
        dso_inner_6->setStyleSheet(QString::fromUtf8("border:1px solid rgb(53, 53, 53);border-radius:4px;\n"
""));
        dso_inner_6->setFrameShape(QFrame::StyledPanel);
        dso_inner_6->setFrameShadow(QFrame::Raised);
        label_76 = new QLabel(frame_15);
        label_76->setObjectName(QString::fromUtf8("label_76"));
        label_76->setGeometry(QRect(7, 1, 287, 16));
        label_76->setFont(font5);
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
        label_77->setFont(font16);
        label_77->setStyleSheet(QString::fromUtf8("color: rgb(53, 53, 53);"));
        frame_40 = new QFrame(frame_15);
        frame_40->setObjectName(QString::fromUtf8("frame_40"));
        frame_40->setGeometry(QRect(237, 27, 41, 41));
        frame_40->setStyleSheet(QString::fromUtf8("border:1px solid rgb(53, 53, 53);border-radius:20px;\n"
"image: url(:/new/prefix1/Button-Blank-Gray-icon.png);"));
        frame_40->setFrameShape(QFrame::StyledPanel);
        frame_40->setFrameShadow(QFrame::Raised);
        frame_41 = new QFrame(frame_40);
        frame_41->setObjectName(QString::fromUtf8("frame_41"));
        frame_41->setGeometry(QRect(16, 15, 10, 10));
        frame_41->setStyleSheet(QString::fromUtf8("border:1px solid rgb(53, 53, 53);border-radius:4px;\n"
""));
        frame_41->setFrameShape(QFrame::StyledPanel);
        frame_41->setFrameShadow(QFrame::Raised);
        label_78 = new QLabel(frame_15);
        label_78->setObjectName(QString::fromUtf8("label_78"));
        label_78->setGeometry(QRect(171, 12, 35, 17));
        label_78->setFont(font16);
        label_78->setStyleSheet(QString::fromUtf8("color: rgb(53, 53, 53);"));
        frame_42 = new QFrame(frame_15);
        frame_42->setObjectName(QString::fromUtf8("frame_42"));
        frame_42->setGeometry(QRect(167, 27, 41, 41));
        frame_42->setStyleSheet(QString::fromUtf8("border:1px solid rgb(53, 53, 53);border-radius:20px;\n"
"image: url(:/new/prefix1/Button-Blank-Gray-icon.png);"));
        frame_42->setFrameShape(QFrame::StyledPanel);
        frame_42->setFrameShadow(QFrame::Raised);
        frame_43 = new QFrame(frame_42);
        frame_43->setObjectName(QString::fromUtf8("frame_43"));
        frame_43->setGeometry(QRect(16, 15, 10, 10));
        frame_43->setStyleSheet(QString::fromUtf8("border:1px solid rgb(53, 53, 53);border-radius:4px;\n"
""));
        frame_43->setFrameShape(QFrame::StyledPanel);
        frame_43->setFrameShadow(QFrame::Raised);
        frame_DMM = new QFrame(frontPanel_DMM);
        frame_DMM->setObjectName(QString::fromUtf8("frame_DMM"));
        frame_DMM->setGeometry(QRect(355, 84, 300, 72));
        frame_DMM->setStyleSheet(QString::fromUtf8("QFrame{border:1px solid black;\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #ffffff, stop: 1 #ffffff);\n"
"border-radius:10px;}\n"
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
        fp_A_label->setFont(font16);
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
        fp_HI_label->setFont(font16);
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
        fp_LO_label->setFont(font16);
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
        fp_DMM_label->setFont(font5);
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
        fp_fuse_label->setFont(font16);
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
        fp_mA_label->setFont(font16);
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
        fp_REF = new QFrame(frontPanel_DMM);
        fp_REF->setObjectName(QString::fromUtf8("fp_REF"));
        fp_REF->setGeometry(QRect(657, 21, 31, 31));
        fp_REF->setStyleSheet(QString::fromUtf8("QFrame{\n"
"border:1px rgba(0,0,0,0); \n"
"border-radius:12px;\n"
"image: url(:/fp_images/ref.png);\n"
"background-color: rgb(0, 0, 0,0);\n"
"}"));
        fp_REF->setFrameShape(QFrame::StyledPanel);
        fp_REF->setFrameShadow(QFrame::Raised);
        fp_REF_label = new QLabel(frontPanel_DMM);
        fp_REF_label->setObjectName(QString::fromUtf8("fp_REF_label"));
        fp_REF_label->setGeometry(QRect(657, 51, 32, 17));
        fp_REF_label->setFont(font16);
        fp_REF_label->setStyleSheet(QString::fromUtf8("color:white;\n"
"background-color: rgb(0, 0, 0,0);\n"
"border-color:rgb(0, 0, 0,0);"));
        fp_GND_label = new QLabel(frontPanel_DMM);
        fp_GND_label->setObjectName(QString::fromUtf8("fp_GND_label"));
        fp_GND_label->setGeometry(QRect(653, 131, 35, 17));
        fp_GND_label->setFont(font16);
        fp_GND_label->setStyleSheet(QString::fromUtf8("color:white;\n"
"background-color: rgb(0, 0, 0,0);\n"
"border-color:rgb(0, 0, 0,0);"));
        fp_GND = new QFrame(frontPanel_DMM);
        fp_GND->setObjectName(QString::fromUtf8("fp_GND"));
        fp_GND->setGeometry(QRect(654, 96, 38, 31));
        fp_GND->setStyleSheet(QString::fromUtf8("QFrame{\n"
"border:1px rgba(0,0,0,0); \n"
"border-radius:13px;\n"
"background-color: rgb(0, 0, 0,0);\n"
"	image: url(:/fp_images/gnd.png);\n"
"}"));
        fp_GND->setFrameShape(QFrame::StyledPanel);
        fp_GND->setFrameShadow(QFrame::Raised);
        fp_VI_ICM_SL_2 = new QFrame(frontPanel_DMM);
        fp_VI_ICM_SL_2->setObjectName(QString::fromUtf8("fp_VI_ICM_SL_2"));
        fp_VI_ICM_SL_2->setGeometry(QRect(244, 77, 106, 79));
        fp_VI_ICM_SL_2->setStyleSheet(QString::fromUtf8("QFrame{\n"
"border-top-right-radius:0px;\n"
"border-top-left-radius:0px;\n"
"border-bottom-left-radius:10px;\n"
"border-bottom-right-radius:10px;\n"
"border-top:qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #a09f9e, stop: 1 #a09f9e);\n"
"border-right:1px solid black;\n"
"border-bottom:1px solid black;\n"
"border-left:1px solid black;\n"
"\n"
" background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #a09f9e, stop: 1 #a09f9e);\n"
"}\n"
"QLabel{border:1px solid rgba(0,0,0,0);\n"
"background-color: rgb(0, 0, 0,0);\n"
"}\n"
"\n"
""));
        fp_VI_ICM_SL_2->setFrameShape(QFrame::StyledPanel);
        fp_VI_ICM_SL_2->setFrameShadow(QFrame::Raised);
        fp_Guarding_2 = new QFrame(fp_VI_ICM_SL_2);
        fp_Guarding_2->setObjectName(QString::fromUtf8("fp_Guarding_2"));
        fp_Guarding_2->setGeometry(QRect(15, 40, 80, 30));
        fp_Guarding_2->setStyleSheet(QString::fromUtf8("border:1px solid rgb(53, 53, 53);\n"
" border-top-right-radius: 8px;\n"
" border-top-left-radius: 8px;\n"
" border-bottom-right-radius: 15px;\n"
" border-bottom-left-radius: 15px;"));
        fp_Guarding_2->setFrameShape(QFrame::StyledPanel);
        fp_Guarding_2->setFrameShadow(QFrame::Raised);
        fp_ICM_Guard_2 = new QLabel(fp_VI_ICM_SL_2);
        fp_ICM_Guard_2->setObjectName(QString::fromUtf8("fp_ICM_Guard_2"));
        fp_ICM_Guard_2->setGeometry(QRect(15, 15, 80, 17));
        fp_ICM_Guard_2->setFont(font16);
        fp_ICM_Guard_2->setStyleSheet(QString::fromUtf8("color: rgb(53, 53, 53);"));
        graphLegend = new QWidget(DMM);
        graphLegend->setObjectName(QString::fromUtf8("graphLegend"));
        graphLegend->setGeometry(QRect(392, 435, 312, 158));
        graphLegend->setStyleSheet(QString::fromUtf8("background-color: rgb(212, 208, 197);"));
        minCap = new QLabel(graphLegend);
        minCap->setObjectName(QString::fromUtf8("minCap"));
        minCap->setGeometry(QRect(260, 100, 60, 60));
        QFont font17;
        font17.setFamily(QString::fromUtf8("DejaVu Sans"));
        font17.setPointSize(18);
        minCap->setFont(font17);
        maxCap = new QLabel(graphLegend);
        maxCap->setObjectName(QString::fromUtf8("maxCap"));
        maxCap->setGeometry(QRect(260, 23, 60, 60));
        maxCap->setFont(font17);
        line_2 = new QFrame(graphLegend);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(4, 76, 307, 3));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(graphLegend);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(2, 0, 3, 160));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);
        line_5 = new QFrame(graphLegend);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setGeometry(QRect(310, 0, 3, 160));
        line_5->setFrameShape(QFrame::VLine);
        line_5->setFrameShadow(QFrame::Sunken);
        maxEdit = new QLineEdit(graphLegend);
        maxEdit->setObjectName(QString::fromUtf8("maxEdit"));
        maxEdit->setGeometry(QRect(20, 10, 240, 60));
        QFont font18;
        font18.setFamily(QString::fromUtf8("DejaVu Sans"));
        font18.setPointSize(45);
        maxEdit->setFont(font18);
        maxEdit->setStyleSheet(QString::fromUtf8("border:1px solid rgba(0,0,0,0);"));
        maxEdit->setMaxLength(6);
        minEdit = new QLineEdit(graphLegend);
        minEdit->setObjectName(QString::fromUtf8("minEdit"));
        minEdit->setGeometry(QRect(20, 87, 240, 60));
        minEdit->setFont(font18);
        minEdit->setStyleSheet(QString::fromUtf8("border:1px solid rgba(0,0,0,0);"));
        minEdit->setMaxLength(6);

        retranslateUi(DMM);

        QMetaObject::connectSlotsByName(DMM);
    } // setupUi

    void retranslateUi(QWidget *DMM)
    {
        DMM->setWindowTitle(QApplication::translate("DMM", "Form", 0, QApplication::UnicodeUTF8));
        r4w->setText(QApplication::translate("DMM", "Beep", 0, QApplication::UnicodeUTF8));
        iac->setText(QApplication::translate("DMM", "AC", 0, QApplication::UnicodeUTF8));
        vdc->setText(QApplication::translate("DMM", "DC", 0, QApplication::UnicodeUTF8));
        idc->setText(QApplication::translate("DMM", "DC", 0, QApplication::UnicodeUTF8));
        manual->setText(QApplication::translate("DMM", "Manual", 0, QApplication::UnicodeUTF8));
        r2w->setText(QApplication::translate("DMM", "R", 0, QApplication::UnicodeUTF8));
        Auto->setText(QApplication::translate("DMM", "AUTO", 0, QApplication::UnicodeUTF8));
        vac->setText(QApplication::translate("DMM", "AC", 0, QApplication::UnicodeUTF8));
        hold->setText(QApplication::translate("DMM", "HOLD", 0, QApplication::UnicodeUTF8));
        Null->setText(QApplication::translate("DMM", "REL", 0, QApplication::UnicodeUTF8));
        leftArrow->setText(QString());
        label_5->setText(QApplication::translate("DMM", "1000V", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("DMM", "200V", 0, QApplication::UnicodeUTF8));
        rightArrow->setText(QString());
        label_4->setText(QApplication::translate("DMM", "1000V", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("DMM", "FUNCTIONS", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("DMM", "RANGES", 0, QApplication::UnicodeUTF8));
        Diode->setText(QApplication::translate("DMM", "DIODE", 0, QApplication::UnicodeUTF8));
        Continuity->setText(QApplication::translate("DMM", "CONT", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("DMM", "AUTO", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        label_2->setText(QApplication::translate("DMM", "Range :", 0, QApplication::UnicodeUTF8));
        textEdit_5->setHtml(QApplication::translate("DMM", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'DejaVu Sans'; font-size:16pt; font-weight:600; font-style:normal;\">\n"
"<table border=\"0\" style=\"-qt-table-type: root; margin-top:4px; margin-bottom:4px; margin-left:4px; margin-right:4px;\">\n"
"<tr>\n"
"<td style=\"border: none;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Sans Serif'; font-size:10pt; color:#ffff7f;\">DC</span></p></td></tr></table></body></html>", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("DMM", ")))))", 0, QApplication::UnicodeUTF8));
        textEdit_6->setHtml(QApplication::translate("DMM", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'DejaVu Sans'; font-size:72pt; font-weight:400; font-style:normal;\">\n"
"<table border=\"0\" style=\"-qt-table-type: root; margin-top:4px; margin-bottom:4px; margin-left:4px; margin-right:4px;\">\n"
"<tr>\n"
"<td style=\"border: none;\">\n"
"<p align=\"right\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Sans Serif';\">0</span></p>\n"
"<p align=\"right\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Sans Serif'; font-size:9pt;\"></p></td></tr></table></body></html>", 0, QApplication::UnicodeUTF8));
        label_11->setText(QString());
        label_12->setText(QString());
        lineEdit_4->setText(QString());
        holdLabel->setText(QApplication::translate("DMM", "HOLD", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("DMM", "0.0", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("DMM", "REL :", 0, QApplication::UnicodeUTF8));
        textEdit->setHtml(QApplication::translate("DMM", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'DejaVu Sans Mono'; font-size:40pt; font-weight:400; font-style:normal;\">\n"
"<table border=\"0\" style=\"-qt-table-type: root; margin-top:4px; margin-bottom:4px; margin-left:4px; margin-right:4px;\">\n"
"<tr>\n"
"<td style=\"border: none;\">\n"
"<p align=\"right\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Sans Serif'; font-size:48pt; color:#000000;\">0</span></p></td></tr></table></body></html>", 0, QApplication::UnicodeUTF8));
        voltBox->setTitle(QString());
        voltMeter->setText(QString());
        AmpBox->setTitle(QString());
        ampMeter->setText(QString());
        OhmBox->setTitle(QString());
        ohmMeter->setText(QString());
        ExitBox->setTitle(QString());
        exit->setText(QString());
        OhmBox_2->setTitle(QString());
        ohmMeter_2->setText(QString());
        OhmBox_3->setTitle(QString());
        ohmMeter_3->setText(QString());
        debugPanel->setTitle(QApplication::translate("DMM", "DEBUG PANEL", 0, QApplication::UnicodeUTF8));
        pushButton_16->setText(QString());
        pushButton_14->setText(QString());
        pushButton->setText(QString());
        pushButton_13->setText(QString());
        pushButton_15->setText(QString());
        calibrateDisplay->setText(QApplication::translate("DMM", "Screen Calibration", 0, QApplication::UnicodeUTF8));
        haadcFrame->setTitle(QString());
        haadcClose->setText(QApplication::translate("DMM", "&Close", 0, QApplication::UnicodeUTF8));
        label_22->setText(QApplication::translate("DMM", "ADC Raw Data :", 0, QApplication::UnicodeUTF8));
        label_23->setText(QApplication::translate("DMM", "ADC Converted\n"
"Data :", 0, QApplication::UnicodeUTF8));
        label_25->setText(QApplication::translate("DMM", "Display Input : ", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("DMM", "Enable Disable ENPKH", 0, QApplication::UnicodeUTF8));
        fp_powerLabel->setText(QApplication::translate("DMM", "POWER", 0, QApplication::UnicodeUTF8));
        ah3_label->setText(QApplication::translate("DMM", "AH3", 0, QApplication::UnicodeUTF8));
        ah1_label->setText(QApplication::translate("DMM", "AH1", 0, QApplication::UnicodeUTF8));
        ah_label->setText(QApplication::translate("DMM", "ICM", 0, QApplication::UnicodeUTF8));
        ah0_label->setText(QApplication::translate("DMM", "AH0", 0, QApplication::UnicodeUTF8));
        ah2_label->setText(QApplication::translate("DMM", "AH2", 0, QApplication::UnicodeUTF8));
        fp_VI1_ICM_SL_label->setText(QApplication::translate("DMM", "VI-1/SL", 0, QApplication::UnicodeUTF8));
        fp_VI2_EXT_label->setText(QApplication::translate("DMM", "VI-2/EXT", 0, QApplication::UnicodeUTF8));
        fp_ICM_Guard->setText(QApplication::translate("DMM", "ICM GUARD", 0, QApplication::UnicodeUTF8));
        fp_DMM_label_2->setText(QApplication::translate("DMM", "VI", 0, QApplication::UnicodeUTF8));
        label_74->setText(QApplication::translate("DMM", "CH2", 0, QApplication::UnicodeUTF8));
        label_75->setText(QApplication::translate("DMM", "CH1", 0, QApplication::UnicodeUTF8));
        label_76->setText(QApplication::translate("DMM", "DSO", 0, QApplication::UnicodeUTF8));
        label_77->setText(QApplication::translate("DMM", "AWG", 0, QApplication::UnicodeUTF8));
        label_78->setText(QApplication::translate("DMM", "EXT", 0, QApplication::UnicodeUTF8));
        fp_A_label->setText(QApplication::translate("DMM", "A", 0, QApplication::UnicodeUTF8));
        fp_HI_label->setText(QApplication::translate("DMM", "HI", 0, QApplication::UnicodeUTF8));
        fp_LO_label->setText(QApplication::translate("DMM", "LO", 0, QApplication::UnicodeUTF8));
        fp_DMM_label->setText(QApplication::translate("DMM", "DMM", 0, QApplication::UnicodeUTF8));
        fp_fuse_label->setText(QApplication::translate("DMM", "FUSE", 0, QApplication::UnicodeUTF8));
        fp_mA_label->setText(QApplication::translate("DMM", "mA", 0, QApplication::UnicodeUTF8));
        fp_REF_label->setText(QApplication::translate("DMM", "REF", 0, QApplication::UnicodeUTF8));
        fp_GND_label->setText(QApplication::translate("DMM", "GND", 0, QApplication::UnicodeUTF8));
        fp_ICM_Guard_2->setText(QApplication::translate("DMM", "ICM GUARD", 0, QApplication::UnicodeUTF8));
        minCap->setText(QApplication::translate("DMM", "Min", 0, QApplication::UnicodeUTF8));
        maxCap->setText(QApplication::translate("DMM", "Max", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DMM: public Ui_DMM {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DMM_H
