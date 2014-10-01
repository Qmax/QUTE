/********************************************************************************
** Form generated from reading UI file 'fg.ui'
**
** Created: Wed Oct 1 21:04:21 2014
**      by: Qt User Interface Compiler version 4.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FG_H
#define UI_FG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QFrame>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FG
{
public:
    QWidget *centralWidget;
    QGroupBox *ExitBox;
    QPushButton *exit;
    QGroupBox *AWG;
    QPushButton *AWGBox;
    QFrame *selectFrame;
    QGroupBox *triangleBox;
    QPushButton *triangleBut;
    QGroupBox *sineBox;
    QPushButton *sineBut;
    QGroupBox *rampBox;
    QPushButton *rampBut;
    QGroupBox *squareBox;
    QPushButton *squareBut;
    QGroupBox *wavePanel;
    QGroupBox *parameterPanel;
    QFrame *frame_5;
    QPushButton *leftBut;
    QPushButton *upBut;
    QPushButton *rightBut;
    QPushButton *fineCoarse;
    QPushButton *downBut;
    QFrame *sidePanel;
    QGroupBox *sourceImpedance;
    QPushButton *RUNBut;
    QLabel *RUNCap;
    QLabel *hiZCap;
    QPushButton *hiZBut;
    QGroupBox *runMode;
    QLabel *ManCap;
    QPushButton *MANBut;
    QLabel *INTCap;
    QPushButton *INTBut;
    QLabel *EXTCap;
    QPushButton *EXTBut;
    QComboBox *modeBox;
    QLabel *label;
    QGroupBox *burstOptions;
    QGroupBox *debugPanel;
    QPushButton *calibrate;
    QPushButton *appBckPSoC;
    QFrame *frontPanel_FG;
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

    void setupUi(QMainWindow *FG)
    {
        if (FG->objectName().isEmpty())
            FG->setObjectName(QString::fromUtf8("FG"));
        FG->resize(800, 600);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush1(QColor(88, 88, 89, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        FG->setPalette(palette);
        centralWidget = new QWidget(FG);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        ExitBox = new QGroupBox(centralWidget);
        ExitBox->setObjectName(QString::fromUtf8("ExitBox"));
        ExitBox->setGeometry(QRect(710, 532, 80, 61));
        QFont font;
        font.setFamily(QString::fromUtf8("DejaVu Sans"));
        ExitBox->setFont(font);
        ExitBox->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
"border:1px solid white; background-color: #dadbde;border-radius:10px;\n"
"border-top:1px qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #f6f7fa, stop: 1 #dadbde); border-top-right-radius: 0px;\n"
" border-top-left-radius: 0px;\n"
"border-top:1px solid gray;\n"
"}\n"
""));
        exit = new QPushButton(ExitBox);
        exit->setObjectName(QString::fromUtf8("exit"));
        exit->setGeometry(QRect(5, 0, 60, 70));
        exit->setFont(font);
        exit->setFocusPolicy(Qt::NoFocus);
        exit->setStyleSheet(QString::fromUtf8("QPushButton {border: 1px solid rgba(0,0,0,0); border-radius: 8px; background-color: rgba(0,0,0,0);color:blue;\n"
"	image: url(:/res/logout-icon.png);\n"
"}\n"
""));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/logout-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        exit->setIcon(icon);
        exit->setIconSize(QSize(70, 70));
        AWG = new QGroupBox(centralWidget);
        AWG->setObjectName(QString::fromUtf8("AWG"));
        AWG->setGeometry(QRect(710, 432, 80, 100));
        AWG->setFont(font);
        AWG->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
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
        AWGBox = new QPushButton(AWG);
        AWGBox->setObjectName(QString::fromUtf8("AWGBox"));
        AWGBox->setGeometry(QRect(8, 20, 64, 64));
        AWGBox->setFont(font);
        AWGBox->setFocusPolicy(Qt::NoFocus);
        AWGBox->setStyleSheet(QString::fromUtf8("QPushButton {border: 1px solid rgba(0,0,0,0); border-radius: 8px; background-color: rgba(0,0,0,0,);\n"
"	\n"
"	image: url(:/res/awg.png);\n"
"\n"
"}"));
        AWGBox->setIconSize(QSize(55, 55));
        selectFrame = new QFrame(centralWidget);
        selectFrame->setObjectName(QString::fromUtf8("selectFrame"));
        selectFrame->setGeometry(QRect(702, 54, 9, 60));
        selectFrame->setFont(font);
        selectFrame->setStyleSheet(QString::fromUtf8("/*background-color: qlineargradient(x1: 0, y1: 0,stop: 0 #f6f7fa, stop: 1 #dadbde);*/\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #3a5976, stop: 1 #000000);\n"
"border-top:1px solid white;\n"
"border-bottom:1px solid white;"));
        selectFrame->setFrameShape(QFrame::Box);
        selectFrame->setFrameShadow(QFrame::Raised);
        triangleBox = new QGroupBox(centralWidget);
        triangleBox->setObjectName(QString::fromUtf8("triangleBox"));
        triangleBox->setGeometry(QRect(710, 332, 80, 100));
        triangleBox->setFont(font);
        triangleBox->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
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
        triangleBut = new QPushButton(triangleBox);
        triangleBut->setObjectName(QString::fromUtf8("triangleBut"));
        triangleBut->setGeometry(QRect(8, 20, 64, 64));
        triangleBut->setFont(font);
        triangleBut->setFocusPolicy(Qt::NoFocus);
        triangleBut->setStyleSheet(QString::fromUtf8("QPushButton {border: 1px solid rgba(0,0,0,0); border-radius: 8px; background-color: rgba(0,0,0,0,);\n"
"	image: url(:/res/redTriangle.png);}"));
        triangleBut->setIconSize(QSize(55, 55));
        sineBox = new QGroupBox(centralWidget);
        sineBox->setObjectName(QString::fromUtf8("sineBox"));
        sineBox->setGeometry(QRect(710, 33, 80, 100));
        sineBox->setFont(font);
        sineBox->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
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
        sineBut = new QPushButton(sineBox);
        sineBut->setObjectName(QString::fromUtf8("sineBut"));
        sineBut->setGeometry(QRect(8, 20, 64, 64));
        sineBut->setFont(font);
        sineBut->setFocusPolicy(Qt::NoFocus);
        sineBut->setStyleSheet(QString::fromUtf8("QPushButton {border: 1px solid rgba(0,0,0,0); border-radius: 8px; background-color: rgba(0,0,0,0,);image: url(:/res/redSine.png);}\n"
"\n"
""));
        sineBut->setIconSize(QSize(55, 55));
        rampBox = new QGroupBox(centralWidget);
        rampBox->setObjectName(QString::fromUtf8("rampBox"));
        rampBox->setGeometry(QRect(710, 232, 80, 100));
        rampBox->setFont(font);
        rampBox->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
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
        rampBut = new QPushButton(rampBox);
        rampBut->setObjectName(QString::fromUtf8("rampBut"));
        rampBut->setGeometry(QRect(8, 20, 64, 64));
        rampBut->setFont(font);
        rampBut->setFocusPolicy(Qt::NoFocus);
        rampBut->setStyleSheet(QString::fromUtf8("QPushButton {border: 1px solid rgba(0,0,0,0); border-radius: 8px; background-color: rgba(0,0,0,0,);\n"
"image: url(:/res/redRamp.png);}\n"
"\n"
""));
        rampBut->setIconSize(QSize(55, 55));
        squareBox = new QGroupBox(centralWidget);
        squareBox->setObjectName(QString::fromUtf8("squareBox"));
        squareBox->setGeometry(QRect(710, 132, 80, 100));
        squareBox->setFont(font);
        squareBox->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
"border:1px solid white; background-color: #dadbde;border-radius:10px;border-bottom:1px qlineargradient(x1: 0, y1: 0,stop: 0 #f6f7fa, stop: 1 #dadbde);border-bottom-right-radius: 0px;\n"
" border-bottom-left-radius: 0px;\n"
"border-top:1px solid gray; border-top-right-radius: 0px;\n"
" border-top-left-radius: 0px;\n"
"}\n"
""));
        squareBut = new QPushButton(squareBox);
        squareBut->setObjectName(QString::fromUtf8("squareBut"));
        squareBut->setGeometry(QRect(8, 20, 64, 64));
        squareBut->setFont(font);
        squareBut->setFocusPolicy(Qt::NoFocus);
        squareBut->setStyleSheet(QString::fromUtf8("QPushButton {border: 1px solid rgba(0,0,0,0); border-radius: 8px; background-color: rgba(0,0,0,0,);image: url(:/res/redSquare.png);}"));
        squareBut->setIconSize(QSize(55, 55));
        wavePanel = new QGroupBox(centralWidget);
        wavePanel->setObjectName(QString::fromUtf8("wavePanel"));
        wavePanel->setGeometry(QRect(10, 33, 440, 244));
        wavePanel->setFont(font);
        wavePanel->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
"color:white;\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #3a5976, stop: 1 #000000);\n"
"border:1px solid white;\n"
"}\n"
" QGroupBox::title {\n"
"	border:1px solid white;\n"
"	border-radius:5px;\n"
"     subcontrol-origin: margin;\n"
"     subcontrol-position: top center; /* position at the top center */\n"
"     padding: 0 3px;\n"
"	 color:white;\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #3a5976, stop: 1 #000000);\n"
" }"));
        parameterPanel = new QGroupBox(centralWidget);
        parameterPanel->setObjectName(QString::fromUtf8("parameterPanel"));
        parameterPanel->setGeometry(QRect(10, 280, 693, 151));
        parameterPanel->setFont(font);
        parameterPanel->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
"color:white;\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #3a5976, stop: 1 #000000);\n"
"border:1px solid white;\n"
"}\n"
" QGroupBox::title {\n"
"	border:1px solid white;\n"
"	border-radius:5px;\n"
"     subcontrol-origin: margin;\n"
"     subcontrol-position: top center; /* position at the top center */\n"
"     padding: 0 3px;\n"
"	 color:white;\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #3a5976, stop: 1 #000000);\n"
" }"));
        frame_5 = new QFrame(parameterPanel);
        frame_5->setObjectName(QString::fromUtf8("frame_5"));
        frame_5->setGeometry(QRect(550, 2, 140, 140));
        frame_5->setStyleSheet(QString::fromUtf8("border:0px solid black;\n"
"border-radius:65px;\n"
"background-color:rgba(0,0,0,0);"));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        leftBut = new QPushButton(frame_5);
        leftBut->setObjectName(QString::fromUtf8("leftBut"));
        leftBut->setGeometry(QRect(0, 25, 50, 90));
        leftBut->setFont(font);
        leftBut->setFocusPolicy(Qt::NoFocus);
        leftBut->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color:rgba(0,0,0,0);\n"
"border:1px solid rgba(0,0,0,0);\n"
"image: url(:/res/leftButton.png);\n"
"}\n"
"QPushButton::pressed{\n"
"background-color:rgba(0,0,0,0);\n"
"border:1px solid rgba(0,0,0,0);\n"
"image: url(:/res/leftButton.png);\n"
"}\n"
"QPushButton::released{\n"
"background-color:rgba(0,0,0,0);\n"
"border:1px solid rgba(0,0,0,0);\n"
"image: url(:/res/leftButton.png);\n"
"}\n"
""));
        upBut = new QPushButton(frame_5);
        upBut->setObjectName(QString::fromUtf8("upBut"));
        upBut->setGeometry(QRect(25, 0, 90, 50));
        upBut->setFont(font);
        upBut->setFocusPolicy(Qt::NoFocus);
        upBut->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color:rgba(0,0,0,0);\n"
"border:1px solid rgba(0,0,0,0);\n"
"image: url(:/res/upButton.png);\n"
"}\n"
"QPushButton::pressed{\n"
"background-color:rgba(0,0,0,0);\n"
"border:1px solid rgba(0,0,0,0);\n"
"image: url(:/res/upButton.png);\n"
"}\n"
"QPushButton::released{\n"
"background-color:rgba(0,0,0,0);\n"
"border:1px solid rgba(0,0,0,0);\n"
"image: url(:/res/upButton.png);\n"
"}\n"
""));
        rightBut = new QPushButton(frame_5);
        rightBut->setObjectName(QString::fromUtf8("rightBut"));
        rightBut->setGeometry(QRect(92, 25, 50, 90));
        rightBut->setFont(font);
        rightBut->setFocusPolicy(Qt::NoFocus);
        rightBut->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color:rgba(0,0,0,0);\n"
"border:1px solid rgba(0,0,0,0);\n"
"image: url(:/res/rightButton.png);\n"
"}\n"
"QPushButton::pressed{\n"
"background-color:rgba(0,0,0,0);\n"
"border:1px solid rgba(0,0,0,0);\n"
"image: url(:/res/rightButton.png);\n"
"}\n"
"QPushButton::released{\n"
"background-color:rgba(0,0,0,0);\n"
"border:1px solid rgba(0,0,0,0);\n"
"image: url(:/res/rightButton.png);\n"
"}\n"
""));
        fineCoarse = new QPushButton(frame_5);
        fineCoarse->setObjectName(QString::fromUtf8("fineCoarse"));
        fineCoarse->setGeometry(QRect(42, 40, 59, 60));
        fineCoarse->setFont(font);
        fineCoarse->setFocusPolicy(Qt::NoFocus);
        fineCoarse->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color:rgba(0,0,0,0);\n"
"border:1px solid rgba(0,0,0,0);\n"
"border-radius:28px;\n"
"image: url(:/res/coarse.png);\n"
"}"));
        downBut = new QPushButton(frame_5);
        downBut->setObjectName(QString::fromUtf8("downBut"));
        downBut->setGeometry(QRect(27, 92, 90, 50));
        downBut->setFont(font);
        downBut->setFocusPolicy(Qt::NoFocus);
        downBut->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color:rgba(0,0,0,0);\n"
"border:1px solid rgba(0,0,0,0);\n"
"image: url(:/res/downButton.png);\n"
"}\n"
"QPushButton::pressed{\n"
"background-color:rgba(0,0,0,0);\n"
"border:1px solid rgba(0,0,0,0);\n"
"image: url(:/res/downButton.png);\n"
"}\n"
"QPushButton::released{\n"
"background-color:rgba(0,0,0,0);\n"
"border:1px solid rgba(0,0,0,0);\n"
"image: url(:/res/downButton.png);\n"
"}\n"
""));
        sidePanel = new QFrame(centralWidget);
        sidePanel->setObjectName(QString::fromUtf8("sidePanel"));
        sidePanel->setGeometry(QRect(449, 32, 255, 246));
        sidePanel->setFont(font);
        sidePanel->setStyleSheet(QString::fromUtf8("border:1px solid black;"));
        sidePanel->setFrameShape(QFrame::StyledPanel);
        sidePanel->setFrameShadow(QFrame::Raised);
        sourceImpedance = new QGroupBox(sidePanel);
        sourceImpedance->setObjectName(QString::fromUtf8("sourceImpedance"));
        sourceImpedance->setGeometry(QRect(0, 190, 254, 55));
        sourceImpedance->setFont(font);
        sourceImpedance->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
"color:white;\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #3a5976, stop: 1 #000000);\n"
"border:1px solid white;\n"
"}\n"
" QGroupBox::title {\n"
"	border:1px solid white;\n"
"	border-radius:5px;\n"
"     subcontrol-origin: margin;\n"
"     subcontrol-position: top center; /* position at the top center */\n"
"     padding: 0 3px;\n"
"	 color:white;\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #3a5976, stop: 1 #000000);\n"
" }"));
        RUNBut = new QPushButton(sourceImpedance);
        RUNBut->setObjectName(QString::fromUtf8("RUNBut"));
        RUNBut->setGeometry(QRect(136, 1, 50, 50));
        RUNBut->setFont(font);
        RUNBut->setFocusPolicy(Qt::NoFocus);
        RUNBut->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color:rgba(0,0,0,0);\n"
"border:1px solid rgba(0,0,0,0);image: url(:/res/knob_off.svg);\n"
"\n"
"}\n"
"\n"
""));
        RUNCap = new QLabel(sourceImpedance);
        RUNCap->setObjectName(QString::fromUtf8("RUNCap"));
        RUNCap->setGeometry(QRect(180, 8, 50, 30));
        QFont font1;
        font1.setFamily(QString::fromUtf8("DejaVu Sans"));
        font1.setPointSize(12);
        font1.setBold(false);
        font1.setWeight(50);
        RUNCap->setFont(font1);
        RUNCap->setStyleSheet(QString::fromUtf8("QLabel::Enabled{\n"
"/*color:#5293DE;*/\n"
"color:white;\n"
"background-color:rgba(0,0,0,0);\n"
"border:1px solid rgba(0,0,0,0);\n"
"}\n"
"QLabel::Disabled{\n"
"color:black;\n"
"}"));
        hiZCap = new QLabel(sourceImpedance);
        hiZCap->setObjectName(QString::fromUtf8("hiZCap"));
        hiZCap->setGeometry(QRect(70, 8, 50, 30));
        hiZCap->setFont(font1);
        hiZCap->setStyleSheet(QString::fromUtf8("QLabel::Enabled{\n"
"color:white;\n"
"background-color:rgba(0,0,0,0);\n"
"border:1px solid rgba(0,0,0,0);\n"
"}\n"
"QLabel::Disabled{\n"
"color:black;\n"
"}"));
        hiZBut = new QPushButton(sourceImpedance);
        hiZBut->setObjectName(QString::fromUtf8("hiZBut"));
        hiZBut->setGeometry(QRect(20, 0, 50, 50));
        hiZBut->setFont(font);
        hiZBut->setFocusPolicy(Qt::NoFocus);
        hiZBut->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color:rgba(0,0,0,0);\n"
"border:1px solid rgba(0,0,0,0);\n"
"image: url(:/res/pressed.svg);\n"
"}\n"
""));
        runMode = new QGroupBox(sidePanel);
        runMode->setObjectName(QString::fromUtf8("runMode"));
        runMode->setGeometry(QRect(0, 1, 254, 120));
        QFont font2;
        font2.setFamily(QString::fromUtf8("DejaVu Sans"));
        font2.setPointSize(10);
        runMode->setFont(font2);
        runMode->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
"color:white;\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #3a5976, stop: 1 #000000);\n"
"border:1px solid white;\n"
"border-bottom:0px solid white;\n"
"}\n"
" QGroupBox::title {\n"
"	border:1px solid white;\n"
"	border-radius:5px;\n"
"     subcontrol-origin: margin;\n"
"     subcontrol-position: top center; /* position at the top center */\n"
"     padding: 0 3px;\n"
"	 color:white;\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #3a5976, stop: 1 #000000);\n"
" }"));
        ManCap = new QLabel(runMode);
        ManCap->setObjectName(QString::fromUtf8("ManCap"));
        ManCap->setGeometry(QRect(80, 80, 50, 30));
        ManCap->setFont(font1);
        ManCap->setStyleSheet(QString::fromUtf8("QLabel::Enabled{\n"
"color:white;\n"
"background-color:rgba(0,0,0,0);\n"
"border:1px solid rgba(0,0,0,0);\n"
"}\n"
"QLabel::Disabled{\n"
"color:white;\n"
"background-color:rgba(0,0,0,0);\n"
"border:1px solid rgba(0,0,0,0);\n"
"}"));
        MANBut = new QPushButton(runMode);
        MANBut->setObjectName(QString::fromUtf8("MANBut"));
        MANBut->setGeometry(QRect(36, 75, 40, 40));
        MANBut->setFont(font);
        MANBut->setFocusPolicy(Qt::NoFocus);
        MANBut->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color:rgba(0,0,0,0);\n"
"border:1px solid rgba(0,0,0,0);\n"
"	image: url(:/res/pb-red.png);\n"
"}\n"
"QPushButton::pressed{\n"
"background-color:rgba(0,0,0,0);\n"
"border:1px solid rgba(0,0,0,0);\n"
"	image: url(:/res/pb-green.png);\n"
"\n"
"}\n"
"QPushButton::released{\n"
"background-color:rgba(0,0,0,0);\n"
"border:1px solid rgba(0,0,0,0);\n"
"image: url(:/res/pb-red.png);\n"
"\n"
"}\n"
""));
        INTCap = new QLabel(runMode);
        INTCap->setObjectName(QString::fromUtf8("INTCap"));
        INTCap->setGeometry(QRect(194, 80, 50, 30));
        INTCap->setFont(font1);
        INTCap->setStyleSheet(QString::fromUtf8("QLabel::Enabled{\n"
"color:white;\n"
"background-color:rgba(0,0,0,0);\n"
"border:1px solid rgba(0,0,0,0);\n"
"}\n"
"QLabel::Disabled{\n"
"color:white;\n"
"background-color:rgba(0,0,0,0);\n"
"border:1px solid rgba(0,0,0,0);\n"
"}"));
        INTBut = new QPushButton(runMode);
        INTBut->setObjectName(QString::fromUtf8("INTBut"));
        INTBut->setGeometry(QRect(150, 75, 40, 40));
        INTBut->setFont(font);
        INTBut->setFocusPolicy(Qt::NoFocus);
        INTBut->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color:rgba(0,0,0,0);\n"
"border:1px solid rgba(0,0,0,0);\n"
"	image: url(:/res/pb-red.png);\n"
"}\n"
"QPushButton::pressed{\n"
"background-color:rgba(0,0,0,0);\n"
"border:1px solid rgba(0,0,0,0);\n"
"	image: url(:/res/pb-green.png);\n"
"\n"
"}\n"
"QPushButton::released{\n"
"background-color:rgba(0,0,0,0);\n"
"border:1px solid rgba(0,0,0,0);\n"
"image: url(:/res/pb-red.png);\n"
"\n"
"}\n"
""));
        EXTCap = new QLabel(runMode);
        EXTCap->setObjectName(QString::fromUtf8("EXTCap"));
        EXTCap->setGeometry(QRect(197, 80, 50, 30));
        EXTCap->setFont(font1);
        EXTCap->setStyleSheet(QString::fromUtf8("QLabel::Enabled{\n"
"color:white;\n"
"background-color:rgba(0,0,0,0);\n"
"border:1px solid rgba(0,0,0,0);\n"
"}\n"
"QLabel::Disabled{\n"
"color:white;\n"
"background-color:rgba(0,0,0,0);\n"
"border:1px solid rgba(0,0,0,0);\n"
"}"));
        EXTBut = new QPushButton(runMode);
        EXTBut->setObjectName(QString::fromUtf8("EXTBut"));
        EXTBut->setGeometry(QRect(164, 75, 40, 40));
        EXTBut->setFont(font);
        EXTBut->setFocusPolicy(Qt::NoFocus);
        EXTBut->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color:rgba(0,0,0,0);\n"
"border:1px solid rgba(0,0,0,0);\n"
"image: url(:/res/knob_off.svg);\n"
"}\n"
"QPushButton::pressed{\n"
"background-color:rgba(0,0,0,0);\n"
"border:1px solid rgba(0,0,0,0);\n"
"image: url(:/res/knob_on.svg);\n"
"}\n"
"QPushButton::released{\n"
"background-color:rgba(0,0,0,0);\n"
"border:1px solid rgba(0,0,0,0);\n"
"image: url(:/res/knob_off.svg);\n"
"}\n"
""));
        modeBox = new QComboBox(runMode);
        modeBox->setObjectName(QString::fromUtf8("modeBox"));
        modeBox->setGeometry(QRect(80, 34, 150, 30));
        QFont font3;
        font3.setFamily(QString::fromUtf8("DejaVu Sans"));
        font3.setPointSize(12);
        font3.setBold(true);
        font3.setWeight(75);
        font3.setStyleStrategy(QFont::PreferAntialias);
        modeBox->setFont(font3);
        modeBox->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    border: 1px solid rgb(95, 95, 95);\n"
"    border-radius: 5px;\n"
"    padding: 1px 18px 1px 3px;\n"
"    min-width: 6em;\n"
"    color: rgb(220, 220, 220);\n"
"    margin: 0 0 0 0;\n"
"}\n"
"\n"
"QComboBox:editable {\n"
"    background: rgba(80,80,80);\n"
"}\n"
"\n"
"QComboBox:!editable {\n"
"    background: qlineargradient(x1: 0, y1: 1, x2: 1, y2: 0,stop: 0 #1A74DB, stop: 0.6 #5293DE, stop:1 #FFFFFF);\n"
"								/*qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                  stop: 0 rgb(51, 51, 51), stop: 0.4 rgb(39, 39, 39),\n"
"                                  stop: 0.5 rgb(32,32,32), stop: 1.0 rgb(38,38,38));;*/\n"
"}\n"
"\n"
"QComboBox::drop-down:editable {\n"
"}\n"
"\n"
"QComboBox:!editable:on {\n"
"}\n"
"\n"
"QComboBox::drop-down:editable:on {\n"
"}\n"
"\n"
"QComboBox:on { /* shift the text when the popup opens */\n"
"    padding-top: 3px;\n"
"    padding-left: 4px;\n"
"    background-color:qlineargradient(x1: 0, y1: 1, x2: 1, y2: 0,stop: 0 #e59244, stop: 0.6 #"
                        "ffa500 , stop:1 #FFFFFF);\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: center right;\n"
"    width: 15px; \n"
"    right:3px;\n"
"    border-top-right-radius: 3px; /* same radius as the QComboBox */\n"
"    border-bottom-right-radius: 3px;\n"
"	background-color:none;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"	image: url(:/res/down.png);\n"
"    height: 20px;\n"
"	width:20px;\n"
"}\n"
"\n"
"QComboBox::down-arrow:on { /* shift the arrow when popup is open */\n"
"    top: 1px;\n"
"    left: 1px;\n"
"}\n"
""));
        label = new QLabel(runMode);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 40, 70, 17));
        QFont font4;
        font4.setFamily(QString::fromUtf8("DejaVu Sans"));
        font4.setPointSize(12);
        label->setFont(font4);
        label->setStyleSheet(QString::fromUtf8("QLabel::Enabled{\n"
"color:white;\n"
"background-color:rgba(0,0,0,0);\n"
"border:1px solid rgba(0,0,0,0);\n"
"}\n"
"QLabel::Disabled{\n"
"color:black;\n"
"}"));
        burstOptions = new QGroupBox(sidePanel);
        burstOptions->setObjectName(QString::fromUtf8("burstOptions"));
        burstOptions->setGeometry(QRect(0, 121, 254, 70));
        burstOptions->setFont(font2);
        burstOptions->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
"color:white;\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #3a5976, stop: 1 #000000);\n"
"border:1px solid white;\n"
"border-bottom:0px solid white;\n"
"border-top:0px solid white;\n"
"\n"
"}\n"
" QGroupBox::title {\n"
"	border:1px solid white;\n"
"	border-radius:5px;\n"
"     subcontrol-origin: margin;\n"
"     subcontrol-position: top center; /* position at the top center */\n"
"     padding: 0 3px;\n"
"	 color:white;\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #3a5976, stop: 1 #000000);\n"
" }"));
        debugPanel = new QGroupBox(centralWidget);
        debugPanel->setObjectName(QString::fromUtf8("debugPanel"));
        debugPanel->setGeometry(QRect(10, 434, 692, 160));
        QFont font5;
        font5.setBold(true);
        font5.setWeight(75);
        debugPanel->setFont(font5);
        debugPanel->setStyleSheet(QString::fromUtf8("QGroupBox{border:1px solid black; background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #ffffff, stop: 1 #dadbff);border-radius:10px;}\n"
" QGroupBox::title {\n"
"     subcontrol-origin: margin;\n"
"     subcontrol-position: top center; /* position at the top center */\n"
"     padding: 0 3px;\n"
"	 border: 2px solid black;\n"
" }"));
        calibrate = new QPushButton(debugPanel);
        calibrate->setObjectName(QString::fromUtf8("calibrate"));
        calibrate->setGeometry(QRect(90, 40, 50, 50));
        calibrate->setStyleSheet(QString::fromUtf8("QPushButton {border: 1px solid #8f8f91; border-radius: 8px; background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #f6f7fa, stop: 1 #dadbde); color:blue;}\n"
""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/res/Letter-R-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        calibrate->setIcon(icon1);
        calibrate->setIconSize(QSize(48, 48));
        appBckPSoC = new QPushButton(debugPanel);
        appBckPSoC->setObjectName(QString::fromUtf8("appBckPSoC"));
        appBckPSoC->setGeometry(QRect(30, 40, 50, 50));
        appBckPSoC->setStyleSheet(QString::fromUtf8("QPushButton {border: 1px solid #8f8f91; border-radius: 8px; background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #f6f7fa, stop: 1 #dadbde); color:blue;}\n"
""));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/res/Control-Panel-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        appBckPSoC->setIcon(icon2);
        appBckPSoC->setIconSize(QSize(48, 48));
        frontPanel_FG = new QFrame(centralWidget);
        frontPanel_FG->setObjectName(QString::fromUtf8("frontPanel_FG"));
        frontPanel_FG->setGeometry(QRect(9, 434, 695, 160));
        frontPanel_FG->setStyleSheet(QString::fromUtf8("/*QFrame{border:1px solid black; background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #ffffff, stop: 1 #dadbff);border-radius:10px;}\n"
"QLabel{border:1px solid rgba(0,0,0,0);}*/\n"
"QFrame {\n"
"      background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 1 #3a5976, stop: 0 #000000);\n"
"     border: 2px solid white;\n"
"     border-radius: 5px;\n"
"     margin-top: 0ex; /* leave space at the top for the title */\n"
" }\n"
""));
        frontPanel_FG->setFrameShape(QFrame::StyledPanel);
        frontPanel_FG->setFrameShadow(QFrame::Raised);
        framePowerUSB = new QFrame(frontPanel_FG);
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
        QFont font6;
        font6.setFamily(QString::fromUtf8("DejaVu Sans"));
        font6.setPointSize(9);
        font6.setBold(false);
        font6.setWeight(50);
        fp_powerLabel->setFont(font6);
        fp_powerLabel->setStyleSheet(QString::fromUtf8("color: rgb(53, 53, 53);"));
        analogHighway = new QFrame(frontPanel_FG);
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
        ah3_label->setFont(font6);
        ah3_label->setStyleSheet(QString::fromUtf8("color: rgb(53, 53, 53);"));
        ah1_label = new QLabel(analogHighway);
        ah1_label->setObjectName(QString::fromUtf8("ah1_label"));
        ah1_label->setGeometry(QRect(26, 11, 38, 17));
        ah1_label->setFont(font6);
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
        QFont font7;
        font7.setFamily(QString::fromUtf8("DejaVu Sans"));
        font7.setBold(true);
        font7.setWeight(75);
        ah_label->setFont(font7);
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
        ah0_label->setFont(font6);
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
        ah2_label->setFont(font6);
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
        fp_VI_ICM_SL = new QFrame(frontPanel_FG);
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
        fp_VI1_ICM_SL_label->setFont(font6);
        fp_VI1_ICM_SL_label->setStyleSheet(QString::fromUtf8("color: rgb(53, 53, 53);"));
        fp_VI2_EXT_label = new QLabel(fp_VI_ICM_SL);
        fp_VI2_EXT_label->setObjectName(QString::fromUtf8("fp_VI2_EXT_label"));
        fp_VI2_EXT_label->setGeometry(QRect(106, 1, 60, 17));
        fp_VI2_EXT_label->setFont(font6);
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
        fp_ICM_Guard->setFont(font6);
        fp_ICM_Guard->setStyleSheet(QString::fromUtf8("color: rgb(53, 53, 53);"));
        frame_15 = new QFrame(frontPanel_FG);
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
        label_74->setFont(font6);
        label_74->setStyleSheet(QString::fromUtf8("color: rgb(53, 53, 53);"));
        label_75 = new QLabel(frame_15);
        label_75->setObjectName(QString::fromUtf8("label_75"));
        label_75->setGeometry(QRect(26, 12, 38, 17));
        label_75->setFont(font6);
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
        label_76->setFont(font7);
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
        label_77->setFont(font6);
        label_77->setStyleSheet(QString::fromUtf8("color: rgb(53, 53, 53);"));
        frame_40 = new QFrame(frame_15);
        frame_40->setObjectName(QString::fromUtf8("frame_40"));
        frame_40->setGeometry(QRect(237, 27, 41, 41));
        frame_40->setStyleSheet(QString::fromUtf8("border:1px solid gray;border-radius:20px;\n"
"image: url(:/fp_images/bnc.png);"));
        frame_40->setFrameShape(QFrame::StyledPanel);
        frame_40->setFrameShadow(QFrame::Raised);
        frame_41 = new QFrame(frame_40);
        frame_41->setObjectName(QString::fromUtf8("frame_41"));
        frame_41->setGeometry(QRect(16, 15, 0, 0));
        frame_41->setStyleSheet(QString::fromUtf8("border:1px solid gray;border-radius:4px;\n"
""));
        frame_41->setFrameShape(QFrame::StyledPanel);
        frame_41->setFrameShadow(QFrame::Raised);
        label_78 = new QLabel(frame_15);
        label_78->setObjectName(QString::fromUtf8("label_78"));
        label_78->setGeometry(QRect(171, 12, 35, 17));
        label_78->setFont(font6);
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
        frame_DMM = new QFrame(frontPanel_FG);
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
        fp_A_label->setFont(font6);
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
        fp_HI_label->setFont(font6);
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
        fp_LO_label->setFont(font6);
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
        fp_DMM_label->setFont(font7);
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
        fp_fuse_label->setFont(font6);
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
        fp_mA_label->setFont(font6);
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
        fp_REF = new QFrame(frontPanel_FG);
        fp_REF->setObjectName(QString::fromUtf8("fp_REF"));
        fp_REF->setGeometry(QRect(658, 21, 31, 31));
        fp_REF->setStyleSheet(QString::fromUtf8("QFrame{\n"
"border:1px rgba(0,0,0,0); \n"
"border-radius:12px;\n"
"image: url(:/fp_images/ref.png);\n"
"background-color: rgb(0, 0, 0,0);\n"
"}"));
        fp_REF->setFrameShape(QFrame::StyledPanel);
        fp_REF->setFrameShadow(QFrame::Raised);
        fp_REF_label = new QLabel(frontPanel_FG);
        fp_REF_label->setObjectName(QString::fromUtf8("fp_REF_label"));
        fp_REF_label->setGeometry(QRect(658, 51, 32, 17));
        fp_REF_label->setFont(font6);
        fp_REF_label->setStyleSheet(QString::fromUtf8("color:white;\n"
"background-color: rgb(0, 0, 0,0);\n"
"border-color:rgb(0, 0, 0,0);"));
        fp_GND_label = new QLabel(frontPanel_FG);
        fp_GND_label->setObjectName(QString::fromUtf8("fp_GND_label"));
        fp_GND_label->setGeometry(QRect(654, 131, 35, 17));
        fp_GND_label->setFont(font6);
        fp_GND_label->setStyleSheet(QString::fromUtf8("color:white;\n"
"background-color: rgb(0, 0, 0,0);\n"
"border-color:rgb(0, 0, 0,0);"));
        fp_GND = new QFrame(frontPanel_FG);
        fp_GND->setObjectName(QString::fromUtf8("fp_GND"));
        fp_GND->setGeometry(QRect(655, 96, 38, 31));
        fp_GND->setStyleSheet(QString::fromUtf8("QFrame{\n"
"border:1px rgba(0,0,0,0); \n"
"border-radius:13px;\n"
"background-color: rgb(0, 0, 0,0);\n"
"	image: url(:/fp_images/gnd.png);\n"
"}"));
        fp_GND->setFrameShape(QFrame::StyledPanel);
        fp_GND->setFrameShadow(QFrame::Raised);
        FG->setCentralWidget(centralWidget);
        ExitBox->raise();
        AWG->raise();
        triangleBox->raise();
        sineBox->raise();
        rampBox->raise();
        squareBox->raise();
        wavePanel->raise();
        parameterPanel->raise();
        sidePanel->raise();
        debugPanel->raise();
        frontPanel_FG->raise();
        selectFrame->raise();

        retranslateUi(FG);

        QMetaObject::connectSlotsByName(FG);
    } // setupUi

    void retranslateUi(QMainWindow *FG)
    {
        FG->setWindowTitle(QApplication::translate("FG", "FG", 0, QApplication::UnicodeUTF8));
        ExitBox->setTitle(QString());
        exit->setText(QString());
        AWG->setTitle(QString());
        AWGBox->setText(QString());
        triangleBox->setTitle(QString());
        triangleBut->setText(QString());
        sineBox->setTitle(QString());
        sineBut->setText(QString());
        rampBox->setTitle(QString());
        rampBut->setText(QString());
        squareBox->setTitle(QString());
        squareBut->setText(QString());
        leftBut->setText(QString());
        upBut->setText(QString());
        rightBut->setText(QString());
        fineCoarse->setText(QString());
        downBut->setText(QString());
        sourceImpedance->setTitle(QString());
        RUNBut->setText(QString());
        RUNCap->setText(QApplication::translate("FG", "OFF", 0, QApplication::UnicodeUTF8));
        hiZCap->setText(QApplication::translate("FG", "Hi-Z", 0, QApplication::UnicodeUTF8));
        hiZBut->setText(QString());
        runMode->setTitle(QApplication::translate("FG", "Run Mode", 0, QApplication::UnicodeUTF8));
        ManCap->setText(QApplication::translate("FG", "MAN", 0, QApplication::UnicodeUTF8));
        MANBut->setText(QString());
        INTCap->setText(QApplication::translate("FG", "INT", 0, QApplication::UnicodeUTF8));
        INTBut->setText(QString());
        EXTCap->setText(QApplication::translate("FG", "EXT", 0, QApplication::UnicodeUTF8));
        EXTBut->setText(QString());
        modeBox->clear();
        modeBox->insertItems(0, QStringList()
         << QApplication::translate("FG", "Continuous", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("FG", "Trigger", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("FG", "Burst", 0, QApplication::UnicodeUTF8)
        );
        label->setText(QApplication::translate("FG", "Mode :", 0, QApplication::UnicodeUTF8));
        burstOptions->setTitle(QApplication::translate("FG", "Burst Options", 0, QApplication::UnicodeUTF8));
        debugPanel->setTitle(QApplication::translate("FG", "DEBUG PANEL", 0, QApplication::UnicodeUTF8));
        calibrate->setText(QString());
        appBckPSoC->setText(QString());
        fp_powerLabel->setText(QApplication::translate("FG", "POWER", 0, QApplication::UnicodeUTF8));
        ah3_label->setText(QApplication::translate("FG", "AH3", 0, QApplication::UnicodeUTF8));
        ah1_label->setText(QApplication::translate("FG", "AH1", 0, QApplication::UnicodeUTF8));
        ah_label->setText(QApplication::translate("FG", "ANALOG HIGHWAY", 0, QApplication::UnicodeUTF8));
        ah0_label->setText(QApplication::translate("FG", "AH0", 0, QApplication::UnicodeUTF8));
        ah2_label->setText(QApplication::translate("FG", "AH2", 0, QApplication::UnicodeUTF8));
        fp_VI1_ICM_SL_label->setText(QApplication::translate("FG", "VI-1/ICM/SL", 0, QApplication::UnicodeUTF8));
        fp_VI2_EXT_label->setText(QApplication::translate("FG", "VI-2/EXT", 0, QApplication::UnicodeUTF8));
        fp_ICM_Guard->setText(QApplication::translate("FG", "ICM GUARD", 0, QApplication::UnicodeUTF8));
        label_74->setText(QApplication::translate("FG", "CH2", 0, QApplication::UnicodeUTF8));
        label_75->setText(QApplication::translate("FG", "CH1", 0, QApplication::UnicodeUTF8));
        label_76->setText(QApplication::translate("FG", "DSO", 0, QApplication::UnicodeUTF8));
        label_77->setText(QApplication::translate("FG", "AWG", 0, QApplication::UnicodeUTF8));
        label_78->setText(QApplication::translate("FG", "EXT", 0, QApplication::UnicodeUTF8));
        fp_A_label->setText(QApplication::translate("FG", "A", 0, QApplication::UnicodeUTF8));
        fp_HI_label->setText(QApplication::translate("FG", "HI", 0, QApplication::UnicodeUTF8));
        fp_LO_label->setText(QApplication::translate("FG", "LO", 0, QApplication::UnicodeUTF8));
        fp_DMM_label->setText(QApplication::translate("FG", "DMM", 0, QApplication::UnicodeUTF8));
        fp_fuse_label->setText(QApplication::translate("FG", "FUSE", 0, QApplication::UnicodeUTF8));
        fp_mA_label->setText(QApplication::translate("FG", "mA", 0, QApplication::UnicodeUTF8));
        fp_REF_label->setText(QApplication::translate("FG", "REF", 0, QApplication::UnicodeUTF8));
        fp_GND_label->setText(QApplication::translate("FG", "GND", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class FG: public Ui_FG {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FG_H
