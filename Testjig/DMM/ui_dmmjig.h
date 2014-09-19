/********************************************************************************
** Form generated from reading UI file 'dmmjig.ui'
**
** Created: Thu Aug 14 18:11:26 2014
**      by: Qt User Interface Compiler version 4.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DMMJIG_H
#define UI_DMMJIG_H

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

class Ui_DMMJig
{
public:
    QGroupBox *grpGeneral;
    QLabel *lblAddress;
    QPushButton *butRead;
    QLabel *lblData;
    QPushButton *butWrite;
    QLineEdit *edAddress;
    QLineEdit *edData;
    QLabel *label;
    QGroupBox *grpSettings;
    QComboBox *cmbImpedance;
    QLabel *lblSrcImped_2;
    QLabel *lblSrcImped_3;
    QComboBox *cmbImpedance_2;
    QLabel *lblSrcImped_4;
    QComboBox *cmbImpedance_3;
    QFrame *line_6;
    QGroupBox *groupBox;
    QComboBox *cmbDrvVoltage;
    QLabel *lblDrRanve;
    QLineEdit *edAddress_2;
    QGroupBox *groupBox_8;
    QCheckBox *checkBox_2;
    QComboBox *cmbOffset;
    QGroupBox *groupBox_6;
    QRadioButton *radioButton_4;
    QRadioButton *radioButton_3;
    QGroupBox *groupBox_7;
    QRadioButton *radioButton_6;
    QRadioButton *radioButton_5;
    QGroupBox *groupBox_2;
    QLineEdit *edAddress_3;
    QLabel *lblSrcImped_5;
    QLineEdit *edAddress_4;
    QLineEdit *edAddress_5;
    QLabel *lblSrcImped_6;
    QLabel *lblSrcImped_7;
    QCheckBox *checkBox_3;
    QGroupBox *groupBox_3;
    QLineEdit *edAddress_6;
    QLabel *lblDrRanve_2;
    QGroupBox *groupBox_4;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QFrame *line;
    QFrame *line_4;
    QCheckBox *checkBox;
    QFrame *line_7;
    QFrame *line_8;
    QFrame *line_9;
    QFrame *line_10;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QGroupBox *groupBox_5;

    void setupUi(QWidget *DMMJig)
    {
        if (DMMJig->objectName().isEmpty())
            DMMJig->setObjectName(QString::fromUtf8("DMMJig"));
        DMMJig->setWindowModality(Qt::NonModal);
        DMMJig->resize(800, 600);
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
        DMMJig->setPalette(palette);
        QFont font;
        font.setFamily(QString::fromUtf8("DejaVu Sans"));
        font.setPointSize(13);
        DMMJig->setFont(font);
        grpGeneral = new QGroupBox(DMMJig);
        grpGeneral->setObjectName(QString::fromUtf8("grpGeneral"));
        grpGeneral->setGeometry(QRect(20, 0, 291, 190));
        QFont font1;
        font1.setFamily(QString::fromUtf8("DejaVu Sans"));
        font1.setPointSize(13);
        font1.setBold(false);
        font1.setWeight(50);
        grpGeneral->setFont(font1);
        grpGeneral->setAutoFillBackground(false);
        grpGeneral->setFlat(false);
        lblAddress = new QLabel(grpGeneral);
        lblAddress->setObjectName(QString::fromUtf8("lblAddress"));
        lblAddress->setGeometry(QRect(20, 26, 81, 16));
        lblAddress->setFont(font1);
        butRead = new QPushButton(grpGeneral);
        butRead->setObjectName(QString::fromUtf8("butRead"));
        butRead->setGeometry(QRect(70, 106, 84, 41));
        butRead->setFont(font1);
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
        lblData = new QLabel(grpGeneral);
        lblData->setObjectName(QString::fromUtf8("lblData"));
        lblData->setGeometry(QRect(20, 70, 71, 16));
        lblData->setFont(font1);
        butWrite = new QPushButton(grpGeneral);
        butWrite->setObjectName(QString::fromUtf8("butWrite"));
        butWrite->setGeometry(QRect(160, 107, 84, 41));
        butWrite->setFont(font1);
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
        edAddress = new QLineEdit(grpGeneral);
        edAddress->setObjectName(QString::fromUtf8("edAddress"));
        edAddress->setGeometry(QRect(90, 15, 161, 41));
        edAddress->setFont(font1);
        edData = new QLineEdit(grpGeneral);
        edData->setObjectName(QString::fromUtf8("edData"));
        edData->setGeometry(QRect(90, 60, 161, 41));
        edData->setFont(font1);
        label = new QLabel(grpGeneral);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 155, 71, 17));
        grpSettings = new QGroupBox(DMMJig);
        grpSettings->setObjectName(QString::fromUtf8("grpSettings"));
        grpSettings->setGeometry(QRect(330, 100, 451, 101));
        grpSettings->setFont(font1);
        cmbImpedance = new QComboBox(grpSettings);
        cmbImpedance->setObjectName(QString::fromUtf8("cmbImpedance"));
        cmbImpedance->setGeometry(QRect(30, 40, 111, 51));
        cmbImpedance->setFont(font1);
        cmbImpedance->setFocusPolicy(Qt::NoFocus);
        cmbImpedance->setStyleSheet(QString::fromUtf8("QComboBox{border: 2px solid gray;border-radius: 10px;color:black;}\n"
""));
        lblSrcImped_2 = new QLabel(grpSettings);
        lblSrcImped_2->setObjectName(QString::fromUtf8("lblSrcImped_2"));
        lblSrcImped_2->setGeometry(QRect(50, 20, 71, 20));
        lblSrcImped_2->setFont(font1);
        lblSrcImped_3 = new QLabel(grpSettings);
        lblSrcImped_3->setObjectName(QString::fromUtf8("lblSrcImped_3"));
        lblSrcImped_3->setGeometry(QRect(200, 20, 71, 20));
        lblSrcImped_3->setFont(font1);
        cmbImpedance_2 = new QComboBox(grpSettings);
        cmbImpedance_2->setObjectName(QString::fromUtf8("cmbImpedance_2"));
        cmbImpedance_2->setGeometry(QRect(180, 40, 111, 51));
        cmbImpedance_2->setFont(font1);
        cmbImpedance_2->setFocusPolicy(Qt::NoFocus);
        cmbImpedance_2->setStyleSheet(QString::fromUtf8("QComboBox{border: 2px solid gray;border-radius: 10px;color:black;}\n"
""));
        lblSrcImped_4 = new QLabel(grpSettings);
        lblSrcImped_4->setObjectName(QString::fromUtf8("lblSrcImped_4"));
        lblSrcImped_4->setGeometry(QRect(350, 20, 100, 20));
        lblSrcImped_4->setFont(font1);
        cmbImpedance_3 = new QComboBox(grpSettings);
        cmbImpedance_3->setObjectName(QString::fromUtf8("cmbImpedance_3"));
        cmbImpedance_3->setGeometry(QRect(330, 40, 111, 51));
        cmbImpedance_3->setFont(font1);
        cmbImpedance_3->setFocusPolicy(Qt::NoFocus);
        cmbImpedance_3->setStyleSheet(QString::fromUtf8("QComboBox{border: 2px solid gray;border-radius: 10px;color:black;}\n"
""));
        line_6 = new QFrame(grpSettings);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setGeometry(QRect(0, -10, 451, 16));
        line_6->setFont(font1);
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);
        groupBox = new QGroupBox(DMMJig);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(20, 183, 291, 268));
        groupBox->setFont(font1);
        cmbDrvVoltage = new QComboBox(groupBox);
        cmbDrvVoltage->setObjectName(QString::fromUtf8("cmbDrvVoltage"));
        cmbDrvVoltage->setGeometry(QRect(10, 38, 111, 40));
        cmbDrvVoltage->setFont(font1);
        cmbDrvVoltage->setFocusPolicy(Qt::NoFocus);
        cmbDrvVoltage->setStyleSheet(QString::fromUtf8("QComboBox{border: 2px solid gray;border-radius: 10px;color:black;}\n"
""));
        lblDrRanve = new QLabel(groupBox);
        lblDrRanve->setObjectName(QString::fromUtf8("lblDrRanve"));
        lblDrRanve->setGeometry(QRect(10, 18, 111, 20));
        lblDrRanve->setFont(font1);
        edAddress_2 = new QLineEdit(groupBox);
        edAddress_2->setObjectName(QString::fromUtf8("edAddress_2"));
        edAddress_2->setGeometry(QRect(140, 42, 111, 41));
        edAddress_2->setFont(font1);
        groupBox_8 = new QGroupBox(groupBox);
        groupBox_8->setObjectName(QString::fromUtf8("groupBox_8"));
        groupBox_8->setGeometry(QRect(150, 100, 130, 100));
        checkBox_2 = new QCheckBox(groupBox_8);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setGeometry(QRect(10, 10, 121, 25));
        QFont font2;
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(50);
        checkBox_2->setFont(font2);
        checkBox_2->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
"font: 12px;\n"
"color:yellow\n"
"}\n"
" QCheckBox::indicator {\n"
"     width: 20px;\n"
"     height:20px;\n"
"   border: 2px solid black;\n"
"	 border-radius:1;\n"
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
        cmbOffset = new QComboBox(groupBox_8);
        cmbOffset->setObjectName(QString::fromUtf8("cmbOffset"));
        cmbOffset->setGeometry(QRect(10, 50, 111, 40));
        cmbOffset->setFont(font1);
        cmbOffset->setFocusPolicy(Qt::NoFocus);
        cmbOffset->setStyleSheet(QString::fromUtf8("QComboBox{border: 2px solid gray;border-radius: 10px;color:black;}\n"
""));
        groupBox_6 = new QGroupBox(groupBox);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        groupBox_6->setGeometry(QRect(10, 110, 130, 100));
        radioButton_4 = new QRadioButton(groupBox_6);
        radioButton_4->setObjectName(QString::fromUtf8("radioButton_4"));
        radioButton_4->setGeometry(QRect(10, 40, 101, 61));
        radioButton_4->setFont(font2);
        radioButton_4->setFocusPolicy(Qt::NoFocus);
        radioButton_4->setStyleSheet(QString::fromUtf8("QRadioButton{\n"
"font: 12px;\n"
"color:yellow\n"
"\n"
"\n"
"}\n"
" QRadioButton::indicator {\n"
"     width: 20px;\n"
"     height:20px;\n"
"   border: 2px solid black;\n"
"	 border-radius:10;\n"
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
        radioButton_3 = new QRadioButton(groupBox_6);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));
        radioButton_3->setGeometry(QRect(10, -20, 101, 71));
        radioButton_3->setFont(font2);
        radioButton_3->setFocusPolicy(Qt::NoFocus);
        radioButton_3->setStyleSheet(QString::fromUtf8("QRadioButton{\n"
"font: 12px;\n"
"color:yellow\n"
"\n"
"\n"
"}\n"
" QRadioButton::indicator {\n"
"     width: 20px;\n"
"     height:20px;\n"
"   border: 2px solid black;\n"
"	 border-radius:10;\n"
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
        radioButton_3->setChecked(true);
        groupBox_7 = new QGroupBox(groupBox);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        groupBox_7->setGeometry(QRect(10, 210, 273, 50));
        radioButton_6 = new QRadioButton(groupBox_7);
        radioButton_6->setObjectName(QString::fromUtf8("radioButton_6"));
        radioButton_6->setGeometry(QRect(160, -10, 111, 71));
        radioButton_6->setFont(font2);
        radioButton_6->setFocusPolicy(Qt::NoFocus);
        radioButton_6->setStyleSheet(QString::fromUtf8("QRadioButton{\n"
"font: 12px;\n"
"color:yellow\n"
"\n"
"\n"
"}\n"
" QRadioButton::indicator {\n"
"     width: 20px;\n"
"     height:20px;\n"
"   border: 2px solid black;\n"
"	 border-radius:10;\n"
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
        radioButton_6->setChecked(true);
        radioButton_5 = new QRadioButton(groupBox_7);
        radioButton_5->setObjectName(QString::fromUtf8("radioButton_5"));
        radioButton_5->setGeometry(QRect(10, -10, 121, 71));
        radioButton_5->setFont(font2);
        radioButton_5->setFocusPolicy(Qt::NoFocus);
        radioButton_5->setStyleSheet(QString::fromUtf8("QRadioButton{\n"
"font: 12px;\n"
"color:yellow\n"
"\n"
"\n"
"}\n"
" QRadioButton::indicator {\n"
"     width: 20px;\n"
"     height:20px;\n"
"   border: 2px solid black;\n"
"	 border-radius:10;\n"
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
        radioButton_5->setChecked(false);
        groupBox_2 = new QGroupBox(DMMJig);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(330, 210, 451, 91));
        groupBox_2->setFont(font1);
        edAddress_3 = new QLineEdit(groupBox_2);
        edAddress_3->setObjectName(QString::fromUtf8("edAddress_3"));
        edAddress_3->setGeometry(QRect(10, 40, 131, 41));
        QFont font3;
        font3.setBold(true);
        font3.setItalic(false);
        font3.setWeight(75);
        edAddress_3->setFont(font3);
        edAddress_3->setStyleSheet(QString::fromUtf8("border-width: 2px;border-style: outset;border-color: gray; border-radius: 10px;  padding: 0 8px;     background: black;     selection-background-color: yellow;   color:white;     font: bold 12px;"));
        lblSrcImped_5 = new QLabel(groupBox_2);
        lblSrcImped_5->setObjectName(QString::fromUtf8("lblSrcImped_5"));
        lblSrcImped_5->setGeometry(QRect(41, 22, 71, 20));
        lblSrcImped_5->setFont(font1);
        edAddress_4 = new QLineEdit(groupBox_2);
        edAddress_4->setObjectName(QString::fromUtf8("edAddress_4"));
        edAddress_4->setGeometry(QRect(160, 40, 131, 41));
        edAddress_4->setFont(font3);
        edAddress_4->setStyleSheet(QString::fromUtf8("border-width: 2px;border-style: outset;border-color: gray; border-radius: 10px;  padding: 0 8px;     background: black;     selection-background-color: yellow;   color:white;     font: bold 12px;"));
        edAddress_5 = new QLineEdit(groupBox_2);
        edAddress_5->setObjectName(QString::fromUtf8("edAddress_5"));
        edAddress_5->setGeometry(QRect(310, 40, 131, 41));
        edAddress_5->setFont(font3);
        edAddress_5->setStyleSheet(QString::fromUtf8("border-width: 2px;border-style: outset;border-color: gray; border-radius: 10px;  padding: 0 8px;     background: black;     selection-background-color: yellow;   color:white;     font: bold 12px;"));
        lblSrcImped_6 = new QLabel(groupBox_2);
        lblSrcImped_6->setObjectName(QString::fromUtf8("lblSrcImped_6"));
        lblSrcImped_6->setGeometry(QRect(190, 22, 71, 20));
        lblSrcImped_6->setFont(font1);
        lblSrcImped_7 = new QLabel(groupBox_2);
        lblSrcImped_7->setObjectName(QString::fromUtf8("lblSrcImped_7"));
        lblSrcImped_7->setGeometry(QRect(333, 23, 110, 20));
        lblSrcImped_7->setFont(font1);
        checkBox_3 = new QCheckBox(groupBox_2);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));
        checkBox_3->setGeometry(QRect(376, 7, 96, 22));
        groupBox_3 = new QGroupBox(DMMJig);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(20, 451, 291, 69));
        groupBox_3->setFont(font1);
        edAddress_6 = new QLineEdit(groupBox_3);
        edAddress_6->setObjectName(QString::fromUtf8("edAddress_6"));
        edAddress_6->setGeometry(QRect(140, 20, 111, 41));
        edAddress_6->setFont(font1);
        lblDrRanve_2 = new QLabel(groupBox_3);
        lblDrRanve_2->setObjectName(QString::fromUtf8("lblDrRanve_2"));
        lblDrRanve_2->setGeometry(QRect(5, 29, 134, 20));
        lblDrRanve_2->setFont(font1);
        groupBox_4 = new QGroupBox(DMMJig);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(330, 0, 451, 100));
        groupBox_4->setFont(font1);
        groupBox_4->setCheckable(false);
        radioButton = new QRadioButton(groupBox_4);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(20, 6, 191, 60));
        radioButton->setFont(font2);
        radioButton->setFocusPolicy(Qt::NoFocus);
        radioButton->setStyleSheet(QString::fromUtf8("QRadioButton{\n"
"font: 14px;\n"
"color:yellow\n"
"\n"
"\n"
"}\n"
" QRadioButton::indicator {\n"
"     width: 20px;\n"
"     height:20px;\n"
"   border: 2px solid black;\n"
"	 border-radius:10;\n"
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
        radioButton->setChecked(true);
        radioButton_2 = new QRadioButton(groupBox_4);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setGeometry(QRect(240, 6, 181, 60));
        radioButton_2->setFont(font2);
        radioButton_2->setFocusPolicy(Qt::NoFocus);
        radioButton_2->setStyleSheet(QString::fromUtf8("QRadioButton{\n"
"font: 14px;\n"
"color:yellow\n"
"\n"
"\n"
"}\n"
" QRadioButton::indicator {\n"
"     width: 20px;\n"
"     height:20px;\n"
"   border: 2px solid black;\n"
"	 border-radius:10;\n"
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
        line = new QFrame(groupBox_4);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(211, 10, 16, 46));
        line->setFont(font1);
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        line_4 = new QFrame(groupBox_4);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setGeometry(QRect(0, 52, 451, 10));
        line_4->setFont(font1);
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        checkBox = new QCheckBox(groupBox_4);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(30, 65, 121, 25));
        checkBox->setFont(font2);
        checkBox->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
"font: 12px;\n"
"color:yellow\n"
"}\n"
" QCheckBox::indicator {\n"
"     width: 20px;\n"
"     height:20px;\n"
"   border: 2px solid black;\n"
"	 border-radius:1;\n"
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
        line_7 = new QFrame(groupBox_4);
        line_7->setObjectName(QString::fromUtf8("line_7"));
        line_7->setGeometry(QRect(0, 91, 451, 16));
        line_7->setFont(font1);
        line_7->setFrameShape(QFrame::HLine);
        line_7->setFrameShadow(QFrame::Sunken);
        line_8 = new QFrame(groupBox_4);
        line_8->setObjectName(QString::fromUtf8("line_8"));
        line_8->setGeometry(QRect(-7, 7, 16, 92));
        line_8->setFont(font1);
        line_8->setFrameShape(QFrame::VLine);
        line_8->setFrameShadow(QFrame::Sunken);
        line_9 = new QFrame(groupBox_4);
        line_9->setObjectName(QString::fromUtf8("line_9"));
        line_9->setGeometry(QRect(442, 8, 16, 91));
        line_9->setFont(font1);
        line_9->setFrameShape(QFrame::VLine);
        line_9->setFrameShadow(QFrame::Sunken);
        line_10 = new QFrame(groupBox_4);
        line_10->setObjectName(QString::fromUtf8("line_10"));
        line_10->setGeometry(QRect(65, 0, 386, 16));
        line_10->setFont(font1);
        line_10->setFrameShape(QFrame::HLine);
        line_10->setFrameShadow(QFrame::Sunken);
        pushButton = new QPushButton(groupBox_4);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(190, 64, 97, 27));
        pushButton->setFocusPolicy(Qt::NoFocus);
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
        pushButton_2 = new QPushButton(groupBox_4);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(320, 64, 97, 27));
        pushButton_2->setFocusPolicy(Qt::NoFocus);
        pushButton_2->setStyleSheet(QString::fromUtf8(" QPushButton {\n"
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
        groupBox_5 = new QGroupBox(DMMJig);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(330, 300, 451, 220));
        groupBox_5->setFont(font1);

        retranslateUi(DMMJig);

        QMetaObject::connectSlotsByName(DMMJig);
    } // setupUi

    void retranslateUi(QWidget *DMMJig)
    {
        DMMJig->setWindowTitle(QApplication::translate("DMMJig", "DMM/SL", 0, QApplication::UnicodeUTF8));
        grpGeneral->setTitle(QApplication::translate("DMMJig", "General", 0, QApplication::UnicodeUTF8));
        lblAddress->setText(QApplication::translate("DMMJig", "Address :", 0, QApplication::UnicodeUTF8));
        butRead->setText(QApplication::translate("DMMJig", "Read", 0, QApplication::UnicodeUTF8));
        lblData->setText(QApplication::translate("DMMJig", "Data :", 0, QApplication::UnicodeUTF8));
        butWrite->setText(QApplication::translate("DMMJig", "Write", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("DMMJig", "DAC F :", 0, QApplication::UnicodeUTF8));
        grpSettings->setTitle(QApplication::translate("DMMJig", "Measurment", 0, QApplication::UnicodeUTF8));
        cmbImpedance->clear();
        cmbImpedance->insertItems(0, QStringList()
         << QApplication::translate("DMMJig", "200 mV", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DMMJig", "2 V", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DMMJig", "20 V", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DMMJig", "200 V", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DMMJig", "1000 V", 0, QApplication::UnicodeUTF8)
        );
        lblSrcImped_2->setText(QApplication::translate("DMMJig", "Voltage", 0, QApplication::UnicodeUTF8));
        lblSrcImped_3->setText(QApplication::translate("DMMJig", "Current", 0, QApplication::UnicodeUTF8));
        cmbImpedance_2->clear();
        cmbImpedance_2->insertItems(0, QStringList()
         << QApplication::translate("DMMJig", "2 mA", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DMMJig", "20 mA", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DMMJig", "200 mA", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DMMJig", "3 A", 0, QApplication::UnicodeUTF8)
        );
        lblSrcImped_4->setText(QApplication::translate("DMMJig", "Resistance", 0, QApplication::UnicodeUTF8));
        cmbImpedance_3->clear();
        cmbImpedance_3->insertItems(0, QStringList()
         << QApplication::translate("DMMJig", "200 E", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DMMJig", "2 KE", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DMMJig", "20 KE", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DMMJig", "200 KE", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DMMJig", "2 ME", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DMMJig", "20 ME", 0, QApplication::UnicodeUTF8)
        );
        groupBox->setTitle(QApplication::translate("DMMJig", "Settings", 0, QApplication::UnicodeUTF8));
        cmbDrvVoltage->clear();
        cmbDrvVoltage->insertItems(0, QStringList()
         << QApplication::translate("DMMJig", "50 mA", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DMMJig", "500 uA", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DMMJig", "5 uA", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DMMJig", "X A", 0, QApplication::UnicodeUTF8)
        );
        lblDrRanve->setText(QApplication::translate("DMMJig", "Force Current", 0, QApplication::UnicodeUTF8));
        groupBox_8->setTitle(QString());
        checkBox_2->setText(QApplication::translate("DMMJig", "Apply Offset", 0, QApplication::UnicodeUTF8));
        groupBox_6->setTitle(QString());
        radioButton_4->setText(QApplication::translate("DMMJig", "Receive2", 0, QApplication::UnicodeUTF8));
        radioButton_3->setText(QApplication::translate("DMMJig", "Receive1", 0, QApplication::UnicodeUTF8));
        groupBox_7->setTitle(QString());
        radioButton_6->setText(QApplication::translate("DMMJig", "Pseudo", 0, QApplication::UnicodeUTF8));
        radioButton_5->setText(QApplication::translate("DMMJig", "Differential", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("DMMJig", "Display Segment", 0, QApplication::UnicodeUTF8));
        lblSrcImped_5->setText(QApplication::translate("DMMJig", "Voltage", 0, QApplication::UnicodeUTF8));
        lblSrcImped_6->setText(QApplication::translate("DMMJig", "Current", 0, QApplication::UnicodeUTF8));
        lblSrcImped_7->setText(QApplication::translate("DMMJig", "Resistance", 0, QApplication::UnicodeUTF8));
        checkBox_3->setText(QApplication::translate("DMMJig", "Nullify", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("DMMJig", "Short Locator", 0, QApplication::UnicodeUTF8));
        lblDrRanve_2->setText(QApplication::translate("DMMJig", "Avg Samples", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("DMMJig", "Options", 0, QApplication::UnicodeUTF8));
        radioButton->setText(QApplication::translate("DMMJig", "DMM", 0, QApplication::UnicodeUTF8));
        radioButton_2->setText(QApplication::translate("DMMJig", "SHORT LOCATOR", 0, QApplication::UnicodeUTF8));
        checkBox->setText(QApplication::translate("DMMJig", "Auto/Manual", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("DMMJig", "START", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("DMMJig", "STOP", 0, QApplication::UnicodeUTF8));
        groupBox_5->setTitle(QApplication::translate("DMMJig", "Waveform Noise Analysis", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DMMJig: public Ui_DMMJig {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DMMJIG_H
