/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created: Sat Jul 19 18:08:34 2014
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
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
    QFrame *frontPanel_DMM_2;
    QFrame *framePowerUSB_2;
    QFrame *fp_usbSocket_2;
    QFrame *fp_usbSymbol_2;
    QFrame *fp_powerButton_2;
    QLabel *fp_powerLabel_2;
    QFrame *analogHighway_2;
    QLabel *ah3_label_2;
    QLabel *ah1_label_2;
    QFrame *ah1_outer_2;
    QFrame *ah3_outer_2;
    QLabel *ah_label_2;
    QLabel *ah0_label_2;
    QFrame *ah0_outer_2;
    QLabel *ah2_label_2;
    QFrame *ah2_outer_2;
    QFrame *fp_VI_ICM_SL_2;
    QFrame *fp_Guarding_2;
    QFrame *fp_VI2_EXT_2;
    QLabel *fp_VI1_ICM_SL_label_2;
    QLabel *fp_VI2_EXT_label_2;
    QFrame *fp_VI1_ICM_SL_2;
    QLabel *fp_ICM_Guard_2;
    QFrame *frame_16;
    QLabel *label_79;
    QLabel *label_80;
    QFrame *dso1_outer_10;
    QFrame *dso_outer_19;
    QLabel *label_81;
    QLabel *label_82;
    QFrame *frame_44;
    QLabel *label_83;
    QFrame *frame_46;
    QFrame *frame_DMM_2;
    QLabel *fp_A_label_2;
    QFrame *fp_LO_inner_2;
    QFrame *fp_mA_inner_2;
    QFrame *fp_A_outer_2;
    QFrame *fp_mA_outer_2;
    QLabel *fp_HI_label_2;
    QFrame *fp_LO_outer_2;
    QFrame *fp_HI_outer_2;
    QLabel *fp_LO_label_2;
    QLabel *fp_DMM_label_2;
    QLabel *fp_fuse_label_2;
    QFrame *fp_fuse_2;
    QLabel *fp_mA_label_2;
    QFrame *fp_REF_2;
    QLabel *fp_REF_label_2;
    QLabel *fp_GND_label_2;
    QFrame *fp_GND_2;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(800, 407);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush1(QColor(0, 0, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush);
        Widget->setPalette(palette);
        frontPanel_DMM = new QFrame(Widget);
        frontPanel_DMM->setObjectName(QString::fromUtf8("frontPanel_DMM"));
        frontPanel_DMM->setGeometry(QRect(10, 6, 701, 160));
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
        QFont font;
        font.setFamily(QString::fromUtf8("DejaVu Sans"));
        font.setPointSize(9);
        font.setBold(false);
        font.setWeight(50);
        fp_powerLabel->setFont(font);
        fp_powerLabel->setStyleSheet(QString::fromUtf8("color: rgb(53, 53, 53);"));
        analogHighway = new QFrame(frontPanel_DMM);
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
        ah3_label->setFont(font);
        ah3_label->setStyleSheet(QString::fromUtf8("color: rgb(53, 53, 53);"));
        ah1_label = new QLabel(analogHighway);
        ah1_label->setObjectName(QString::fromUtf8("ah1_label"));
        ah1_label->setGeometry(QRect(26, 11, 38, 17));
        ah1_label->setFont(font);
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
        ah_inner = new QFrame(ah3_outer);
        ah_inner->setObjectName(QString::fromUtf8("ah_inner"));
        ah_inner->setGeometry(QRect(15, 15, 10, 10));
        ah_inner->setStyleSheet(QString::fromUtf8("border:1px solid gray;border-radius:4px;\n"
""));
        ah_inner->setFrameShape(QFrame::StyledPanel);
        ah_inner->setFrameShadow(QFrame::Raised);
        ah_label = new QLabel(analogHighway);
        ah_label->setObjectName(QString::fromUtf8("ah_label"));
        ah_label->setGeometry(QRect(7, 0, 287, 16));
        QFont font1;
        font1.setFamily(QString::fromUtf8("DejaVu Sans"));
        font1.setBold(true);
        font1.setWeight(75);
        ah_label->setFont(font1);
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
        ah0_label->setFont(font);
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
        ah2_label->setFont(font);
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
        fp_VI_ICM_SL = new QFrame(frontPanel_DMM);
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
        fp_VI1_ICM_SL_label->setFont(font);
        fp_VI1_ICM_SL_label->setStyleSheet(QString::fromUtf8("color: rgb(53, 53, 53);"));
        fp_VI2_EXT_label = new QLabel(fp_VI_ICM_SL);
        fp_VI2_EXT_label->setObjectName(QString::fromUtf8("fp_VI2_EXT_label"));
        fp_VI2_EXT_label->setGeometry(QRect(106, 1, 60, 17));
        fp_VI2_EXT_label->setFont(font);
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
        fp_ICM_Guard->setFont(font);
        fp_ICM_Guard->setStyleSheet(QString::fromUtf8("color: rgb(53, 53, 53);"));
        frame_15 = new QFrame(frontPanel_DMM);
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
        label_74->setFont(font);
        label_74->setStyleSheet(QString::fromUtf8("color: rgb(53, 53, 53);"));
        label_75 = new QLabel(frame_15);
        label_75->setObjectName(QString::fromUtf8("label_75"));
        label_75->setGeometry(QRect(26, 12, 38, 17));
        label_75->setFont(font);
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
        label_76->setFont(font1);
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
        label_77->setFont(font);
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
        label_78->setFont(font);
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
        frame_DMM = new QFrame(frontPanel_DMM);
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
        fp_A_label->setFont(font);
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
        fp_HI_label->setFont(font);
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
        fp_LO_label->setFont(font);
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
        fp_DMM_label->setFont(font1);
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
        fp_fuse_label->setFont(font);
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
        fp_mA_label->setFont(font);
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
        fp_REF->setGeometry(QRect(662, 21, 31, 31));
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
        fp_REF_label->setGeometry(QRect(662, 51, 32, 17));
        fp_REF_label->setFont(font);
        fp_REF_label->setStyleSheet(QString::fromUtf8("color:white;\n"
"background-color: rgb(0, 0, 0,0);\n"
"border-color:rgb(0, 0, 0,0);"));
        fp_GND_label = new QLabel(frontPanel_DMM);
        fp_GND_label->setObjectName(QString::fromUtf8("fp_GND_label"));
        fp_GND_label->setGeometry(QRect(658, 131, 35, 17));
        fp_GND_label->setFont(font);
        fp_GND_label->setStyleSheet(QString::fromUtf8("color:white;\n"
"background-color: rgb(0, 0, 0,0);\n"
"border-color:rgb(0, 0, 0,0);"));
        fp_GND = new QFrame(frontPanel_DMM);
        fp_GND->setObjectName(QString::fromUtf8("fp_GND"));
        fp_GND->setGeometry(QRect(659, 96, 38, 31));
        fp_GND->setStyleSheet(QString::fromUtf8("QFrame{\n"
"border:1px rgba(0,0,0,0); \n"
"border-radius:13px;\n"
"background-color: rgb(0, 0, 0,0);\n"
"	image: url(:/fp_images/gnd.png);\n"
"}"));
        fp_GND->setFrameShape(QFrame::StyledPanel);
        fp_GND->setFrameShadow(QFrame::Raised);
        frontPanel_DMM_2 = new QFrame(Widget);
        frontPanel_DMM_2->setObjectName(QString::fromUtf8("frontPanel_DMM_2"));
        frontPanel_DMM_2->setGeometry(QRect(20, 200, 693, 160));
        frontPanel_DMM_2->setStyleSheet(QString::fromUtf8("/*QFrame{border:1px solid black; background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #ffffff, stop: 1 #dadbff);border-radius:10px;}\n"
"QLabel{border:1px solid rgba(0,0,0,0);}*/\n"
"QFrame {\n"
"      background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 1 #3a5976, stop: 0 #000000);\n"
"     border: 2px solid white;\n"
"     border-radius: 5px;\n"
"     margin-top: 0ex; /* leave space at the top for the title */\n"
" }\n"
""));
        frontPanel_DMM_2->setFrameShape(QFrame::StyledPanel);
        frontPanel_DMM_2->setFrameShadow(QFrame::Raised);
        framePowerUSB_2 = new QFrame(frontPanel_DMM_2);
        framePowerUSB_2->setObjectName(QString::fromUtf8("framePowerUSB_2"));
        framePowerUSB_2->setGeometry(QRect(5, 6, 47, 150));
        framePowerUSB_2->setStyleSheet(QString::fromUtf8("/*QFrame{border:2px solid black; background-color: rgba(0,0,0,0);border-radius:10px;}\n"
"QLabel{border:1px solid rgba(0,0,0,0);}*/\n"
"QFrame{border:1px solid black; background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #ffffff, stop: 1 #dadbff);border-radius:10px;}\n"
"QLabel{border:1px solid rgba(0,0,0,0);\n"
"background-color: rgb(0, 0, 0,0);\n"
"}\n"
"\n"
""));
        framePowerUSB_2->setFrameShape(QFrame::StyledPanel);
        framePowerUSB_2->setFrameShadow(QFrame::Raised);
        fp_usbSocket_2 = new QFrame(framePowerUSB_2);
        fp_usbSocket_2->setObjectName(QString::fromUtf8("fp_usbSocket_2"));
        fp_usbSocket_2->setGeometry(QRect(2, 96, 43, 23));
        fp_usbSocket_2->setStyleSheet(QString::fromUtf8("border:1px rgba(0,0,0,0);border-radius:7px;\n"
"background-color: rgb(0, 0, 0,0);\n"
"image: url(:/fp_images/usb.png);"));
        fp_usbSocket_2->setFrameShape(QFrame::StyledPanel);
        fp_usbSocket_2->setFrameShadow(QFrame::Raised);
        fp_usbSymbol_2 = new QFrame(framePowerUSB_2);
        fp_usbSymbol_2->setObjectName(QString::fromUtf8("fp_usbSymbol_2"));
        fp_usbSymbol_2->setGeometry(QRect(5, 120, 38, 19));
        fp_usbSymbol_2->setStyleSheet(QString::fromUtf8("border:1px rgba(0,0,0,0);border-radius:5px;\n"
"background-color: rgb(0, 0, 0,0);\n"
"image: url(:/fp_images/usb_symbol.png);"));
        fp_usbSymbol_2->setFrameShape(QFrame::StyledPanel);
        fp_usbSymbol_2->setFrameShadow(QFrame::Raised);
        fp_powerButton_2 = new QFrame(framePowerUSB_2);
        fp_powerButton_2->setObjectName(QString::fromUtf8("fp_powerButton_2"));
        fp_powerButton_2->setGeometry(QRect(4, 26, 38, 38));
        fp_powerButton_2->setStyleSheet(QString::fromUtf8("border:1px solid gray;border-radius:5px;\n"
"image: url(:/fp_images/power.png);"));
        fp_powerButton_2->setFrameShape(QFrame::StyledPanel);
        fp_powerButton_2->setFrameShadow(QFrame::Raised);
        fp_powerLabel_2 = new QLabel(framePowerUSB_2);
        fp_powerLabel_2->setObjectName(QString::fromUtf8("fp_powerLabel_2"));
        fp_powerLabel_2->setGeometry(QRect(-3, 66, 50, 17));
        fp_powerLabel_2->setFont(font);
        fp_powerLabel_2->setStyleSheet(QString::fromUtf8("color: rgb(53, 53, 53);"));
        analogHighway_2 = new QFrame(frontPanel_DMM_2);
        analogHighway_2->setObjectName(QString::fromUtf8("analogHighway_2"));
        analogHighway_2->setGeometry(QRect(54, 6, 300, 72));
        analogHighway_2->setStyleSheet(QString::fromUtf8("/*QFrame{border:2px solid black; background-color: rgba(0,0,0,0);border-radius:10px;}\n"
"QLabel{border:1px solid rgba(0,0,0,0);}*/\n"
"QFrame{border:1px solid black; background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #ffffff, stop: 1 #dadbff);border-radius:10px;}\n"
"QLabel{border:1px solid rgba(0,0,0,0);\n"
"background-color: rgb(0, 0, 0,0);\n"
"}\n"
"\n"
""));
        analogHighway_2->setFrameShape(QFrame::StyledPanel);
        analogHighway_2->setFrameShadow(QFrame::Raised);
        ah3_label_2 = new QLabel(analogHighway_2);
        ah3_label_2->setObjectName(QString::fromUtf8("ah3_label_2"));
        ah3_label_2->setGeometry(QRect(100, 11, 38, 17));
        ah3_label_2->setFont(font);
        ah3_label_2->setStyleSheet(QString::fromUtf8("color: rgb(53, 53, 53);"));
        ah1_label_2 = new QLabel(analogHighway_2);
        ah1_label_2->setObjectName(QString::fromUtf8("ah1_label_2"));
        ah1_label_2->setGeometry(QRect(26, 11, 38, 17));
        ah1_label_2->setFont(font);
        ah1_label_2->setStyleSheet(QString::fromUtf8("color: rgb(53, 53, 53);"));
        ah1_outer_2 = new QFrame(analogHighway_2);
        ah1_outer_2->setObjectName(QString::fromUtf8("ah1_outer_2"));
        ah1_outer_2->setGeometry(QRect(22, 26, 41, 41));
        ah1_outer_2->setStyleSheet(QString::fromUtf8("border:1px solid gray;border-radius:20px;\n"
"image: url(:/fp_images/bnc.png);"));
        ah1_outer_2->setFrameShape(QFrame::StyledPanel);
        ah1_outer_2->setFrameShadow(QFrame::Raised);
        ah3_outer_2 = new QFrame(analogHighway_2);
        ah3_outer_2->setObjectName(QString::fromUtf8("ah3_outer_2"));
        ah3_outer_2->setGeometry(QRect(96, 26, 41, 41));
        ah3_outer_2->setStyleSheet(QString::fromUtf8("border:1px solid gray;border-radius:20px;\n"
"image: url(:/fp_images/bnc.png);"));
        ah3_outer_2->setFrameShape(QFrame::StyledPanel);
        ah3_outer_2->setFrameShadow(QFrame::Raised);
        ah_label_2 = new QLabel(analogHighway_2);
        ah_label_2->setObjectName(QString::fromUtf8("ah_label_2"));
        ah_label_2->setGeometry(QRect(7, 0, 287, 16));
        ah_label_2->setFont(font1);
        ah_label_2->setStyleSheet(QString::fromUtf8("/*background-color:blue;\n"
"color: rgb(0, 85, 255);\n"
"color:white;\n"
"border:1px solid black;\n"
"border-radius:8px;*/\n"
"color: rgb(0, 85, 255);"));
        ah_label_2->setAlignment(Qt::AlignCenter);
        ah0_label_2 = new QLabel(analogHighway_2);
        ah0_label_2->setObjectName(QString::fromUtf8("ah0_label_2"));
        ah0_label_2->setGeometry(QRect(240, 11, 43, 17));
        ah0_label_2->setFont(font);
        ah0_label_2->setStyleSheet(QString::fromUtf8("color: rgb(53, 53, 53);\n"
"background-color: rgb(0, 0, 0,0);"));
        ah0_outer_2 = new QFrame(analogHighway_2);
        ah0_outer_2->setObjectName(QString::fromUtf8("ah0_outer_2"));
        ah0_outer_2->setGeometry(QRect(237, 26, 41, 41));
        ah0_outer_2->setStyleSheet(QString::fromUtf8("border:1px solid gray;border-radius:20px;\n"
"image: url(:/fp_images/bnc.png);"));
        ah0_outer_2->setFrameShape(QFrame::StyledPanel);
        ah0_outer_2->setFrameShadow(QFrame::Raised);
        ah2_label_2 = new QLabel(analogHighway_2);
        ah2_label_2->setObjectName(QString::fromUtf8("ah2_label_2"));
        ah2_label_2->setGeometry(QRect(170, 11, 35, 17));
        ah2_label_2->setFont(font);
        ah2_label_2->setStyleSheet(QString::fromUtf8("color: rgb(53, 53, 53);"));
        ah2_outer_2 = new QFrame(analogHighway_2);
        ah2_outer_2->setObjectName(QString::fromUtf8("ah2_outer_2"));
        ah2_outer_2->setGeometry(QRect(167, 26, 41, 41));
        ah2_outer_2->setStyleSheet(QString::fromUtf8("border:1px solid gray;border-radius:20px;\n"
"image: url(:/fp_images/bnc.png);"));
        ah2_outer_2->setFrameShape(QFrame::StyledPanel);
        ah2_outer_2->setFrameShadow(QFrame::Raised);
        fp_VI_ICM_SL_2 = new QFrame(frontPanel_DMM_2);
        fp_VI_ICM_SL_2->setObjectName(QString::fromUtf8("fp_VI_ICM_SL_2"));
        fp_VI_ICM_SL_2->setGeometry(QRect(54, 84, 300, 72));
        fp_VI_ICM_SL_2->setStyleSheet(QString::fromUtf8("/*QFrame{border:2px solid black; background-color: rgba(0,0,0,0);border-radius:10px;}\n"
"QLabel{border:1px solid rgba(0,0,0,0);}*/\n"
"QFrame{border:1px solid black; background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #ffffff, stop: 1 #dadbff);border-radius:10px;}\n"
"QLabel{border:1px solid rgba(0,0,0,0);\n"
"background-color: rgb(0, 0, 0,0);\n"
"}\n"
"\n"
""));
        fp_VI_ICM_SL_2->setFrameShape(QFrame::StyledPanel);
        fp_VI_ICM_SL_2->setFrameShadow(QFrame::Raised);
        fp_Guarding_2 = new QFrame(fp_VI_ICM_SL_2);
        fp_Guarding_2->setObjectName(QString::fromUtf8("fp_Guarding_2"));
        fp_Guarding_2->setGeometry(QRect(195, 26, 80, 30));
        fp_Guarding_2->setStyleSheet(QString::fromUtf8("border:1px rgba(0,0,0,0);\n"
" border-top-right-radius: 8px;\n"
" border-top-left-radius: 8px;\n"
" border-bottom-right-radius: 15px;\n"
" border-bottom-left-radius: 15px;\n"
"image: url(:/fp_images/guard.png);"));
        fp_Guarding_2->setFrameShape(QFrame::StyledPanel);
        fp_Guarding_2->setFrameShadow(QFrame::Raised);
        fp_VI2_EXT_2 = new QFrame(fp_VI_ICM_SL_2);
        fp_VI2_EXT_2->setObjectName(QString::fromUtf8("fp_VI2_EXT_2"));
        fp_VI2_EXT_2->setGeometry(QRect(105, 20, 53, 49));
        fp_VI2_EXT_2->setStyleSheet(QString::fromUtf8("border:1px rgba(0,0,0,0);border-radius:20px;\n"
"image: url(:/fp_images/VI_SL_ICM.png);"));
        fp_VI2_EXT_2->setFrameShape(QFrame::StyledPanel);
        fp_VI2_EXT_2->setFrameShadow(QFrame::Raised);
        fp_VI1_ICM_SL_label_2 = new QLabel(fp_VI_ICM_SL_2);
        fp_VI1_ICM_SL_label_2->setObjectName(QString::fromUtf8("fp_VI1_ICM_SL_label_2"));
        fp_VI1_ICM_SL_label_2->setGeometry(QRect(11, 1, 74, 17));
        fp_VI1_ICM_SL_label_2->setFont(font);
        fp_VI1_ICM_SL_label_2->setStyleSheet(QString::fromUtf8("color: rgb(53, 53, 53);"));
        fp_VI2_EXT_label_2 = new QLabel(fp_VI_ICM_SL_2);
        fp_VI2_EXT_label_2->setObjectName(QString::fromUtf8("fp_VI2_EXT_label_2"));
        fp_VI2_EXT_label_2->setGeometry(QRect(106, 1, 60, 17));
        fp_VI2_EXT_label_2->setFont(font);
        fp_VI2_EXT_label_2->setStyleSheet(QString::fromUtf8("color: rgb(53, 53, 53);"));
        fp_VI1_ICM_SL_2 = new QFrame(fp_VI_ICM_SL_2);
        fp_VI1_ICM_SL_2->setObjectName(QString::fromUtf8("fp_VI1_ICM_SL_2"));
        fp_VI1_ICM_SL_2->setGeometry(QRect(24, 20, 53, 49));
        fp_VI1_ICM_SL_2->setStyleSheet(QString::fromUtf8("border:1px rgba(0,0,0,0);border-radius:20px;\n"
"image: url(:/fp_images/VI_SL_ICM.png);"));
        fp_VI1_ICM_SL_2->setFrameShape(QFrame::StyledPanel);
        fp_VI1_ICM_SL_2->setFrameShadow(QFrame::Raised);
        fp_ICM_Guard_2 = new QLabel(fp_VI_ICM_SL_2);
        fp_ICM_Guard_2->setObjectName(QString::fromUtf8("fp_ICM_Guard_2"));
        fp_ICM_Guard_2->setGeometry(QRect(196, 1, 75, 17));
        fp_ICM_Guard_2->setFont(font);
        fp_ICM_Guard_2->setStyleSheet(QString::fromUtf8("color: rgb(53, 53, 53);"));
        frame_16 = new QFrame(frontPanel_DMM_2);
        frame_16->setObjectName(QString::fromUtf8("frame_16"));
        frame_16->setGeometry(QRect(355, 6, 300, 72));
        frame_16->setStyleSheet(QString::fromUtf8("/*QFrame{border:2px solid black; background-color: rgba(0,0,0,0);border-radius:10px;}\n"
"QLabel{border:1px solid rgba(0,0,0,0);}*/\n"
"QFrame{border:1px solid black; background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #ffffff, stop: 1 #dadbff);border-radius:10px;}\n"
"QLabel{border:1px solid rgba(0,0,0,0);\n"
"background-color: rgb(0, 0, 0,0);\n"
"}\n"
"\n"
""));
        frame_16->setFrameShape(QFrame::StyledPanel);
        frame_16->setFrameShadow(QFrame::Raised);
        label_79 = new QLabel(frame_16);
        label_79->setObjectName(QString::fromUtf8("label_79"));
        label_79->setGeometry(QRect(100, 12, 38, 17));
        label_79->setFont(font);
        label_79->setStyleSheet(QString::fromUtf8("color: rgb(53, 53, 53);"));
        label_80 = new QLabel(frame_16);
        label_80->setObjectName(QString::fromUtf8("label_80"));
        label_80->setGeometry(QRect(26, 12, 38, 17));
        label_80->setFont(font);
        label_80->setStyleSheet(QString::fromUtf8("color: rgb(53, 53, 53);"));
        dso1_outer_10 = new QFrame(frame_16);
        dso1_outer_10->setObjectName(QString::fromUtf8("dso1_outer_10"));
        dso1_outer_10->setGeometry(QRect(22, 27, 41, 41));
        dso1_outer_10->setStyleSheet(QString::fromUtf8("border:1px solid gray;border-radius:20px;\n"
"image: url(:/fp_images/bnc.png);"));
        dso1_outer_10->setFrameShape(QFrame::StyledPanel);
        dso1_outer_10->setFrameShadow(QFrame::Raised);
        dso_outer_19 = new QFrame(frame_16);
        dso_outer_19->setObjectName(QString::fromUtf8("dso_outer_19"));
        dso_outer_19->setGeometry(QRect(96, 27, 41, 41));
        dso_outer_19->setStyleSheet(QString::fromUtf8("border:1px solid gray;border-radius:20px;\n"
"image: url(:/fp_images/bnc.png);"));
        dso_outer_19->setFrameShape(QFrame::StyledPanel);
        dso_outer_19->setFrameShadow(QFrame::Raised);
        label_81 = new QLabel(frame_16);
        label_81->setObjectName(QString::fromUtf8("label_81"));
        label_81->setGeometry(QRect(7, 1, 287, 16));
        label_81->setFont(font1);
        label_81->setStyleSheet(QString::fromUtf8("/*background-color:blue;\n"
"color: rgb(0, 85, 255);\n"
"color:white;\n"
"border:1px solid black;\n"
"border-radius:8px;*/\n"
"color: rgb(0, 85, 255);"));
        label_81->setAlignment(Qt::AlignCenter);
        label_82 = new QLabel(frame_16);
        label_82->setObjectName(QString::fromUtf8("label_82"));
        label_82->setGeometry(QRect(241, 12, 43, 17));
        label_82->setFont(font);
        label_82->setStyleSheet(QString::fromUtf8("color: rgb(53, 53, 53);"));
        frame_44 = new QFrame(frame_16);
        frame_44->setObjectName(QString::fromUtf8("frame_44"));
        frame_44->setGeometry(QRect(237, 27, 41, 41));
        frame_44->setStyleSheet(QString::fromUtf8("border:1px solid gray;border-radius:20px;\n"
"image: url(:/fp_images/bnc.png);"));
        frame_44->setFrameShape(QFrame::StyledPanel);
        frame_44->setFrameShadow(QFrame::Raised);
        label_83 = new QLabel(frame_16);
        label_83->setObjectName(QString::fromUtf8("label_83"));
        label_83->setGeometry(QRect(171, 12, 35, 17));
        label_83->setFont(font);
        label_83->setStyleSheet(QString::fromUtf8("color: rgb(53, 53, 53);"));
        frame_46 = new QFrame(frame_16);
        frame_46->setObjectName(QString::fromUtf8("frame_46"));
        frame_46->setGeometry(QRect(167, 27, 41, 41));
        frame_46->setStyleSheet(QString::fromUtf8("border:1px solid gray;border-radius:20px;\n"
"image: url(:/fp_images/bnc.png);"));
        frame_46->setFrameShape(QFrame::StyledPanel);
        frame_46->setFrameShadow(QFrame::Raised);
        frame_DMM_2 = new QFrame(frontPanel_DMM_2);
        frame_DMM_2->setObjectName(QString::fromUtf8("frame_DMM_2"));
        frame_DMM_2->setGeometry(QRect(355, 84, 300, 72));
        frame_DMM_2->setStyleSheet(QString::fromUtf8("/*QFrame{border:2px solid black; background-color: rgba(0,0,0,0);border-radius:10px;}\n"
"QLabel{border:1px solid rgba(0,0,0,0);}*/\n"
"QFrame{border:1px solid black; background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #ffffff, stop: 1 #dadbff);border-radius:10px;}\n"
"QLabel{border:1px solid rgba(0,0,0,0);\n"
"background-color: rgb(0, 0, 0,0);\n"
"}\n"
"\n"
""));
        frame_DMM_2->setFrameShape(QFrame::StyledPanel);
        frame_DMM_2->setFrameShadow(QFrame::Raised);
        fp_A_label_2 = new QLabel(frame_DMM_2);
        fp_A_label_2->setObjectName(QString::fromUtf8("fp_A_label_2"));
        fp_A_label_2->setGeometry(QRect(247, 14, 20, 12));
        fp_A_label_2->setFont(font);
        fp_A_label_2->setStyleSheet(QString::fromUtf8("color: rgb(53, 53, 53);"));
        fp_LO_inner_2 = new QFrame(frame_DMM_2);
        fp_LO_inner_2->setObjectName(QString::fromUtf8("fp_LO_inner_2"));
        fp_LO_inner_2->setGeometry(QRect(80, 32, 31, 31));
        fp_LO_inner_2->setStyleSheet(QString::fromUtf8("border:1px solid gray;border-radius:15px;\n"
"image: url(:/new/prefix1/Button-Blank-Gray-icon.png);\n"
""));
        fp_LO_inner_2->setFrameShape(QFrame::StyledPanel);
        fp_LO_inner_2->setFrameShadow(QFrame::Raised);
        fp_mA_inner_2 = new QFrame(frame_DMM_2);
        fp_mA_inner_2->setObjectName(QString::fromUtf8("fp_mA_inner_2"));
        fp_mA_inner_2->setGeometry(QRect(130, 32, 31, 31));
        fp_mA_inner_2->setStyleSheet(QString::fromUtf8("border:1px solid gray;border-radius:15px;\n"
"image: url(:/new/prefix1/Button-Blank-Gray-icon.png);\n"
"\n"
""));
        fp_mA_inner_2->setFrameShape(QFrame::StyledPanel);
        fp_mA_inner_2->setFrameShadow(QFrame::Raised);
        fp_A_outer_2 = new QFrame(frame_DMM_2);
        fp_A_outer_2->setObjectName(QString::fromUtf8("fp_A_outer_2"));
        fp_A_outer_2->setGeometry(QRect(235, 27, 42, 41));
        fp_A_outer_2->setStyleSheet(QString::fromUtf8("border:1px rgba(0,0,0,0);\n"
"border-radius:20px;\n"
"image: url(:/fp_images/red.png);\n"
""));
        fp_A_outer_2->setFrameShape(QFrame::StyledPanel);
        fp_A_outer_2->setFrameShadow(QFrame::Raised);
        fp_mA_outer_2 = new QFrame(frame_DMM_2);
        fp_mA_outer_2->setObjectName(QString::fromUtf8("fp_mA_outer_2"));
        fp_mA_outer_2->setGeometry(QRect(125, 27, 42, 41));
        fp_mA_outer_2->setStyleSheet(QString::fromUtf8("border:1px rgba(0,0,0,0);\n"
"border-radius:20px;\n"
"image: url(:/fp_images/red.png);\n"
""));
        fp_mA_outer_2->setFrameShape(QFrame::StyledPanel);
        fp_mA_outer_2->setFrameShadow(QFrame::Raised);
        fp_HI_label_2 = new QLabel(frame_DMM_2);
        fp_HI_label_2->setObjectName(QString::fromUtf8("fp_HI_label_2"));
        fp_HI_label_2->setGeometry(QRect(37, 14, 20, 12));
        fp_HI_label_2->setFont(font);
        fp_HI_label_2->setStyleSheet(QString::fromUtf8("color: rgb(53, 53, 53);"));
        fp_HI_label_2->setAlignment(Qt::AlignCenter);
        fp_LO_outer_2 = new QFrame(frame_DMM_2);
        fp_LO_outer_2->setObjectName(QString::fromUtf8("fp_LO_outer_2"));
        fp_LO_outer_2->setGeometry(QRect(75, 27, 42, 41));
        fp_LO_outer_2->setStyleSheet(QString::fromUtf8("border:1px rgba(0,0,0,0);\n"
"border-radius:20px;\n"
"image: url(:/fp_images/black.png);"));
        fp_LO_outer_2->setFrameShape(QFrame::StyledPanel);
        fp_LO_outer_2->setFrameShadow(QFrame::Raised);
        fp_HI_outer_2 = new QFrame(frame_DMM_2);
        fp_HI_outer_2->setObjectName(QString::fromUtf8("fp_HI_outer_2"));
        fp_HI_outer_2->setGeometry(QRect(25, 27, 42, 41));
        fp_HI_outer_2->setStyleSheet(QString::fromUtf8("border:1px rgba(0,0,0,0);\n"
"border-radius:20px;\n"
"image: url(:/fp_images/red.png);"));
        fp_HI_outer_2->setFrameShape(QFrame::StyledPanel);
        fp_HI_outer_2->setFrameShadow(QFrame::Raised);
        fp_LO_label_2 = new QLabel(frame_DMM_2);
        fp_LO_label_2->setObjectName(QString::fromUtf8("fp_LO_label_2"));
        fp_LO_label_2->setGeometry(QRect(85, 14, 22, 12));
        fp_LO_label_2->setFont(font);
        fp_LO_label_2->setStyleSheet(QString::fromUtf8("color: rgb(53, 53, 53);"));
        fp_DMM_label_2 = new QLabel(frame_DMM_2);
        fp_DMM_label_2->setObjectName(QString::fromUtf8("fp_DMM_label_2"));
        fp_DMM_label_2->setGeometry(QRect(6, 0, 287, 16));
        fp_DMM_label_2->setFont(font1);
        fp_DMM_label_2->setStyleSheet(QString::fromUtf8("/*background-color:blue;\n"
"color: rgb(0, 85, 255);\n"
"color:white;\n"
"border:1px solid black;\n"
"border-radius:8px;*/\n"
"color: rgb(0, 85, 255);"));
        fp_DMM_label_2->setAlignment(Qt::AlignCenter);
        fp_fuse_label_2 = new QLabel(frame_DMM_2);
        fp_fuse_label_2->setObjectName(QString::fromUtf8("fp_fuse_label_2"));
        fp_fuse_label_2->setGeometry(QRect(178, 14, 50, 12));
        fp_fuse_label_2->setFont(font);
        fp_fuse_label_2->setStyleSheet(QString::fromUtf8("color: rgb(53, 53, 53);"));
        fp_fuse_2 = new QFrame(frame_DMM_2);
        fp_fuse_2->setObjectName(QString::fromUtf8("fp_fuse_2"));
        fp_fuse_2->setGeometry(QRect(174, 25, 49, 46));
        fp_fuse_2->setStyleSheet(QString::fromUtf8("border-radius:20px;\n"
"image: url(:/fp_images/fuse.png);\n"
"border:1px solid rgba(0,0,0,0);\n"
""));
        fp_fuse_2->setFrameShape(QFrame::StyledPanel);
        fp_fuse_2->setFrameShadow(QFrame::Raised);
        fp_mA_label_2 = new QLabel(frame_DMM_2);
        fp_mA_label_2->setObjectName(QString::fromUtf8("fp_mA_label_2"));
        fp_mA_label_2->setGeometry(QRect(133, 15, 35, 12));
        fp_mA_label_2->setFont(font);
        fp_mA_label_2->setStyleSheet(QString::fromUtf8("color: rgb(53, 53, 53);"));
        fp_REF_2 = new QFrame(frontPanel_DMM_2);
        fp_REF_2->setObjectName(QString::fromUtf8("fp_REF_2"));
        fp_REF_2->setGeometry(QRect(658, 21, 31, 31));
        fp_REF_2->setStyleSheet(QString::fromUtf8("QFrame{\n"
"border:1px rgba(0,0,0,0); \n"
"border-radius:12px;\n"
"image: url(:/fp_images/ref.png);\n"
"background-color: rgb(0, 0, 0,0);\n"
"}"));
        fp_REF_2->setFrameShape(QFrame::StyledPanel);
        fp_REF_2->setFrameShadow(QFrame::Raised);
        fp_REF_label_2 = new QLabel(frontPanel_DMM_2);
        fp_REF_label_2->setObjectName(QString::fromUtf8("fp_REF_label_2"));
        fp_REF_label_2->setGeometry(QRect(658, 51, 32, 17));
        fp_REF_label_2->setFont(font);
        fp_REF_label_2->setStyleSheet(QString::fromUtf8("color:white;\n"
"background-color: rgb(0, 0, 0,0);\n"
"border-color:rgb(0, 0, 0,0);"));
        fp_GND_label_2 = new QLabel(frontPanel_DMM_2);
        fp_GND_label_2->setObjectName(QString::fromUtf8("fp_GND_label_2"));
        fp_GND_label_2->setGeometry(QRect(657, 126, 35, 17));
        fp_GND_label_2->setFont(font);
        fp_GND_label_2->setStyleSheet(QString::fromUtf8("color:white;\n"
"background-color: rgb(0, 0, 0,0);\n"
"border-color:rgb(0, 0, 0,0);"));
        fp_GND_2 = new QFrame(frontPanel_DMM_2);
        fp_GND_2->setObjectName(QString::fromUtf8("fp_GND_2"));
        fp_GND_2->setGeometry(QRect(655, 96, 38, 31));
        fp_GND_2->setStyleSheet(QString::fromUtf8("QFrame{\n"
"border:1px rgba(0,0,0,0); \n"
"border-radius:13px;\n"
"background-color: rgb(0, 0, 0,0);\n"
"	image: url(:/fp_images/gnd.png);\n"
"}"));
        fp_GND_2->setFrameShape(QFrame::StyledPanel);
        fp_GND_2->setFrameShadow(QFrame::Raised);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0, QApplication::UnicodeUTF8));
        fp_powerLabel->setText(QApplication::translate("Widget", "POWER", 0, QApplication::UnicodeUTF8));
        ah3_label->setText(QApplication::translate("Widget", "AH3", 0, QApplication::UnicodeUTF8));
        ah1_label->setText(QApplication::translate("Widget", "AH1", 0, QApplication::UnicodeUTF8));
        ah_label->setText(QApplication::translate("Widget", "ANALOG HIGHWAY", 0, QApplication::UnicodeUTF8));
        ah0_label->setText(QApplication::translate("Widget", "AH0", 0, QApplication::UnicodeUTF8));
        ah2_label->setText(QApplication::translate("Widget", "AH2", 0, QApplication::UnicodeUTF8));
        fp_VI1_ICM_SL_label->setText(QApplication::translate("Widget", "VI-1/ICM/SL", 0, QApplication::UnicodeUTF8));
        fp_VI2_EXT_label->setText(QApplication::translate("Widget", "VI-2/EXT", 0, QApplication::UnicodeUTF8));
        fp_ICM_Guard->setText(QApplication::translate("Widget", "ICM GUARD", 0, QApplication::UnicodeUTF8));
        label_74->setText(QApplication::translate("Widget", "CH2", 0, QApplication::UnicodeUTF8));
        label_75->setText(QApplication::translate("Widget", "CH1", 0, QApplication::UnicodeUTF8));
        label_76->setText(QApplication::translate("Widget", "DSO", 0, QApplication::UnicodeUTF8));
        label_77->setText(QApplication::translate("Widget", "AWG", 0, QApplication::UnicodeUTF8));
        label_78->setText(QApplication::translate("Widget", "EXT", 0, QApplication::UnicodeUTF8));
        fp_A_label->setText(QApplication::translate("Widget", "A", 0, QApplication::UnicodeUTF8));
        fp_HI_label->setText(QApplication::translate("Widget", "HI", 0, QApplication::UnicodeUTF8));
        fp_LO_label->setText(QApplication::translate("Widget", "LO", 0, QApplication::UnicodeUTF8));
        fp_DMM_label->setText(QApplication::translate("Widget", "DMM", 0, QApplication::UnicodeUTF8));
        fp_fuse_label->setText(QApplication::translate("Widget", "FUSE", 0, QApplication::UnicodeUTF8));
        fp_mA_label->setText(QApplication::translate("Widget", "mA", 0, QApplication::UnicodeUTF8));
        fp_REF_label->setText(QApplication::translate("Widget", "REF", 0, QApplication::UnicodeUTF8));
        fp_GND_label->setText(QApplication::translate("Widget", "GND", 0, QApplication::UnicodeUTF8));
        fp_powerLabel_2->setText(QApplication::translate("Widget", "POWER", 0, QApplication::UnicodeUTF8));
        ah3_label_2->setText(QApplication::translate("Widget", "AH3", 0, QApplication::UnicodeUTF8));
        ah1_label_2->setText(QApplication::translate("Widget", "AH1", 0, QApplication::UnicodeUTF8));
        ah_label_2->setText(QApplication::translate("Widget", "ANALOG HIGHWAY", 0, QApplication::UnicodeUTF8));
        ah0_label_2->setText(QApplication::translate("Widget", "AH0", 0, QApplication::UnicodeUTF8));
        ah2_label_2->setText(QApplication::translate("Widget", "AH2", 0, QApplication::UnicodeUTF8));
        fp_VI1_ICM_SL_label_2->setText(QApplication::translate("Widget", "VI-1/ICM/SL", 0, QApplication::UnicodeUTF8));
        fp_VI2_EXT_label_2->setText(QApplication::translate("Widget", "VI-2/EXT", 0, QApplication::UnicodeUTF8));
        fp_ICM_Guard_2->setText(QApplication::translate("Widget", "ICM GUARD", 0, QApplication::UnicodeUTF8));
        label_79->setText(QApplication::translate("Widget", "CH2", 0, QApplication::UnicodeUTF8));
        label_80->setText(QApplication::translate("Widget", "CH1", 0, QApplication::UnicodeUTF8));
        label_81->setText(QApplication::translate("Widget", "DSO", 0, QApplication::UnicodeUTF8));
        label_82->setText(QApplication::translate("Widget", "AWG", 0, QApplication::UnicodeUTF8));
        label_83->setText(QApplication::translate("Widget", "EXT", 0, QApplication::UnicodeUTF8));
        fp_A_label_2->setText(QApplication::translate("Widget", "A", 0, QApplication::UnicodeUTF8));
        fp_HI_label_2->setText(QApplication::translate("Widget", "HI", 0, QApplication::UnicodeUTF8));
        fp_LO_label_2->setText(QApplication::translate("Widget", "LO", 0, QApplication::UnicodeUTF8));
        fp_DMM_label_2->setText(QApplication::translate("Widget", "DMM", 0, QApplication::UnicodeUTF8));
        fp_fuse_label_2->setText(QApplication::translate("Widget", "FUSE", 0, QApplication::UnicodeUTF8));
        fp_mA_label_2->setText(QApplication::translate("Widget", "mA", 0, QApplication::UnicodeUTF8));
        fp_REF_label_2->setText(QApplication::translate("Widget", "REF", 0, QApplication::UnicodeUTF8));
        fp_GND_label_2->setText(QApplication::translate("Widget", "GND", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
