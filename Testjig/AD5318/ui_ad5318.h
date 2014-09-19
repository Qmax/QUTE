/********************************************************************************
** Form generated from reading UI file 'ad5318.ui'
**
** Created: Wed Sep 17 12:44:42 2014
**      by: Qt User Interface Compiler version 4.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AD5318_H
#define UI_AD5318_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AD5318
{
public:
    QGroupBox *grpGeneral;
    QLabel *lblAddress;
    QLabel *label;
    QPushButton *butRead;
    QPushButton *butWrite;
    QPushButton *butStart;
    QCheckBox *chkAddrWrite;
    QGroupBox *grpDACSelection;
    QCheckBox *chkDACA;
    QCheckBox *chkDACB;
    QCheckBox *chkDACC;
    QCheckBox *chkDACD;
    QCheckBox *chkDACE;
    QCheckBox *chkDACF;
    QCheckBox *chkDACG;
    QCheckBox *chkDACH;
    QGroupBox *grpDACSettings;
    QLabel *label_2;
    QPushButton *butUpdateDAC;
    QPushButton *butRstDAC;
    QGroupBox *grpAD7190;
    QPushButton *butStartADC;
    QPushButton *butStopADC;
    QCheckBox *chkADC1;
    QCheckBox *chkADC2;
    QLineEdit *leADC1;
    QLineEdit *leADC2;
    QCheckBox *chkPseudo;
    QGroupBox *grpDCDrive;
    QLabel *label_3;
    QPushButton *butDriveDC;
    QLineEdit *lineEdit;
    QCheckBox *chkP1V;
    QCheckBox *chkP2V;
    QGroupBox *grpGain;
    QRadioButton *butGain1;
    QRadioButton *butGain8;
    QRadioButton *butGain16;
    QRadioButton *butGain32;
    QRadioButton *butGain64;
    QRadioButton *butGain128;
    QPushButton *butSwitchRly;
    QGroupBox *grpAD5293;
    QLabel *label_4;
    QLineEdit *lineEdit_2;
    QPushButton *butAD5293Drive;
    QComboBox *comboBox;
    QLabel *label_5;
    QGroupBox *calibrationBox;
    QPushButton *DriveCurrent;
    QPushButton *DriveVoltage;
    QPushButton *Receiver;
    QPushButton *Reference;
    QPushButton *butCheckDriveDone;
    QPushButton *butFileManager;
    QPushButton *butLMH6518;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *appBck;

    void setupUi(QWidget *AD5318)
    {
        if (AD5318->objectName().isEmpty())
            AD5318->setObjectName(QString::fromUtf8("AD5318"));
        AD5318->resize(800, 600);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush1(QColor(170, 170, 127, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        AD5318->setPalette(palette);
        AD5318->setStyleSheet(QString::fromUtf8("QLineEdit{border-width: 2px;border-style: outset;border-color: gray; border-radius: 1px;  padding: 0 8px;     background: black;     selection-background-color: yellow;   color:white;     font: bold 14px;}\n"
"\n"
"QPushButton {border: 2px solid #8f8f91; border-radius: 8px; background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #f6f7fa, stop: 1 #dadbde); color:blue;} QPushButton:pressed {background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #dadbde, stop: 1 #f6f7fa);} QPushButton:flat {border: none;} QPushButton:default {border-color: navy;}\n"
"\n"
"QComboBox{border: 2px solid gray;border-radius: 10px;color:black;}\n"
"\n"
"QToolButton {border: 1px solid black; border-radius: 5px;font:18px bold;background-color:rgba(170,170,170,255);}\n"
"\n"
"QSpinBox{border: 2px solid gray;border-radius: 10px;color:black;}\n"
"\n"
"QDoubleSpinBox{border: 2px solid gray;border-radius: 10px;color:black;}\n"
"\n"
"QCheckBox{font: 14px;} QCheckBox::indicator {width:20px;height:20px;border: 2px solid"
                        " black;border-radius:1; } QCheckBox::indicator::unchecked {background-color:white;}QCheckBox::indicator:unchecked:hover {background-color:white; }\n"
"QCheckBox::indicator:unchecked:pressed {	background-color:white; }\n"
"QCheckBox::indicator::checked {background-color:#f2a400;}  QCheckBox::indicator:checked:hover {background-color:#f2a400;}\n"
"QCheckBox::indicator:checked:pressed {	background-color:#f2a400;}\n"
"\n"
"QLabel{font:14px;color:yellow;}"));
        grpGeneral = new QGroupBox(AD5318);
        grpGeneral->setObjectName(QString::fromUtf8("grpGeneral"));
        grpGeneral->setEnabled(false);
        grpGeneral->setGeometry(QRect(10, 1, 260, 190));
        QPalette palette1;
        QBrush brush2(QColor(255, 255, 0, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        QBrush brush3(QColor(85, 0, 0, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush3);
        palette1.setBrush(QPalette::Active, QPalette::Shadow, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Shadow, brush3);
        QBrush brush4(QColor(116, 116, 116, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        QBrush brush5(QColor(108, 108, 107, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush5);
        palette1.setBrush(QPalette::Disabled, QPalette::Shadow, brush3);
        grpGeneral->setPalette(palette1);
        QFont font;
        font.setFamily(QString::fromUtf8("DejaVu Sans"));
        grpGeneral->setFont(font);
        lblAddress = new QLabel(grpGeneral);
        lblAddress->setObjectName(QString::fromUtf8("lblAddress"));
        lblAddress->setGeometry(QRect(20, 30, 69, 20));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        lblAddress->setPalette(palette2);
        label = new QLabel(grpGeneral);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 70, 41, 20));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        label->setPalette(palette3);
        butRead = new QPushButton(grpGeneral);
        butRead->setObjectName(QString::fromUtf8("butRead"));
        butRead->setGeometry(QRect(10, 110, 84, 40));
        QPalette palette4;
        QBrush brush6(QColor(0, 0, 255, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        QLinearGradient gradient(0, 0, 0, 1);
        gradient.setSpread(QGradient::PadSpread);
        gradient.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient.setColorAt(0, QColor(246, 247, 250, 255));
        gradient.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush7(gradient);
        palette4.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette4.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette4.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        QLinearGradient gradient1(0, 0, 0, 1);
        gradient1.setSpread(QGradient::PadSpread);
        gradient1.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient1.setColorAt(0, QColor(246, 247, 250, 255));
        gradient1.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush8(gradient1);
        palette4.setBrush(QPalette::Active, QPalette::Base, brush8);
        QLinearGradient gradient2(0, 0, 0, 1);
        gradient2.setSpread(QGradient::PadSpread);
        gradient2.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient2.setColorAt(0, QColor(246, 247, 250, 255));
        gradient2.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush9(gradient2);
        palette4.setBrush(QPalette::Active, QPalette::Window, brush9);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        QLinearGradient gradient3(0, 0, 0, 1);
        gradient3.setSpread(QGradient::PadSpread);
        gradient3.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient3.setColorAt(0, QColor(246, 247, 250, 255));
        gradient3.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush10(gradient3);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush10);
        palette4.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette4.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        QLinearGradient gradient4(0, 0, 0, 1);
        gradient4.setSpread(QGradient::PadSpread);
        gradient4.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient4.setColorAt(0, QColor(246, 247, 250, 255));
        gradient4.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush11(gradient4);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush11);
        QLinearGradient gradient5(0, 0, 0, 1);
        gradient5.setSpread(QGradient::PadSpread);
        gradient5.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient5.setColorAt(0, QColor(246, 247, 250, 255));
        gradient5.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush12(gradient5);
        palette4.setBrush(QPalette::Inactive, QPalette::Window, brush12);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush6);
        QLinearGradient gradient6(0, 0, 0, 1);
        gradient6.setSpread(QGradient::PadSpread);
        gradient6.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient6.setColorAt(0, QColor(246, 247, 250, 255));
        gradient6.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush13(gradient6);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush13);
        palette4.setBrush(QPalette::Disabled, QPalette::Text, brush6);
        palette4.setBrush(QPalette::Disabled, QPalette::ButtonText, brush6);
        QLinearGradient gradient7(0, 0, 0, 1);
        gradient7.setSpread(QGradient::PadSpread);
        gradient7.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient7.setColorAt(0, QColor(246, 247, 250, 255));
        gradient7.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush14(gradient7);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush14);
        QLinearGradient gradient8(0, 0, 0, 1);
        gradient8.setSpread(QGradient::PadSpread);
        gradient8.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient8.setColorAt(0, QColor(246, 247, 250, 255));
        gradient8.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush15(gradient8);
        palette4.setBrush(QPalette::Disabled, QPalette::Window, brush15);
        butRead->setPalette(palette4);
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
        butWrite->setGeometry(QRect(110, 110, 84, 40));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        QLinearGradient gradient9(0, 0, 0, 1);
        gradient9.setSpread(QGradient::PadSpread);
        gradient9.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient9.setColorAt(0, QColor(246, 247, 250, 255));
        gradient9.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush16(gradient9);
        palette5.setBrush(QPalette::Active, QPalette::Button, brush16);
        palette5.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette5.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        QLinearGradient gradient10(0, 0, 0, 1);
        gradient10.setSpread(QGradient::PadSpread);
        gradient10.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient10.setColorAt(0, QColor(246, 247, 250, 255));
        gradient10.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush17(gradient10);
        palette5.setBrush(QPalette::Active, QPalette::Base, brush17);
        QLinearGradient gradient11(0, 0, 0, 1);
        gradient11.setSpread(QGradient::PadSpread);
        gradient11.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient11.setColorAt(0, QColor(246, 247, 250, 255));
        gradient11.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush18(gradient11);
        palette5.setBrush(QPalette::Active, QPalette::Window, brush18);
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        QLinearGradient gradient12(0, 0, 0, 1);
        gradient12.setSpread(QGradient::PadSpread);
        gradient12.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient12.setColorAt(0, QColor(246, 247, 250, 255));
        gradient12.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush19(gradient12);
        palette5.setBrush(QPalette::Inactive, QPalette::Button, brush19);
        palette5.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette5.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        QLinearGradient gradient13(0, 0, 0, 1);
        gradient13.setSpread(QGradient::PadSpread);
        gradient13.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient13.setColorAt(0, QColor(246, 247, 250, 255));
        gradient13.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush20(gradient13);
        palette5.setBrush(QPalette::Inactive, QPalette::Base, brush20);
        QLinearGradient gradient14(0, 0, 0, 1);
        gradient14.setSpread(QGradient::PadSpread);
        gradient14.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient14.setColorAt(0, QColor(246, 247, 250, 255));
        gradient14.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush21(gradient14);
        palette5.setBrush(QPalette::Inactive, QPalette::Window, brush21);
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush6);
        QLinearGradient gradient15(0, 0, 0, 1);
        gradient15.setSpread(QGradient::PadSpread);
        gradient15.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient15.setColorAt(0, QColor(246, 247, 250, 255));
        gradient15.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush22(gradient15);
        palette5.setBrush(QPalette::Disabled, QPalette::Button, brush22);
        palette5.setBrush(QPalette::Disabled, QPalette::Text, brush6);
        palette5.setBrush(QPalette::Disabled, QPalette::ButtonText, brush6);
        QLinearGradient gradient16(0, 0, 0, 1);
        gradient16.setSpread(QGradient::PadSpread);
        gradient16.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient16.setColorAt(0, QColor(246, 247, 250, 255));
        gradient16.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush23(gradient16);
        palette5.setBrush(QPalette::Disabled, QPalette::Base, brush23);
        QLinearGradient gradient17(0, 0, 0, 1);
        gradient17.setSpread(QGradient::PadSpread);
        gradient17.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient17.setColorAt(0, QColor(246, 247, 250, 255));
        gradient17.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush24(gradient17);
        palette5.setBrush(QPalette::Disabled, QPalette::Window, brush24);
        butWrite->setPalette(palette5);
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
        butStart = new QPushButton(grpGeneral);
        butStart->setObjectName(QString::fromUtf8("butStart"));
        butStart->setGeometry(QRect(200, 110, 51, 40));
        chkAddrWrite = new QCheckBox(grpGeneral);
        chkAddrWrite->setObjectName(QString::fromUtf8("chkAddrWrite"));
        chkAddrWrite->setGeometry(QRect(30, 160, 81, 25));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette6.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette6.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette6.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette6.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette6.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette6.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette6.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette6.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        chkAddrWrite->setPalette(palette6);
        chkAddrWrite->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
"font: 14px;\n"
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
        grpDACSelection = new QGroupBox(AD5318);
        grpDACSelection->setObjectName(QString::fromUtf8("grpDACSelection"));
        grpDACSelection->setGeometry(QRect(300, 0, 500, 130));
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette7.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette7.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        grpDACSelection->setPalette(palette7);
        chkDACA = new QCheckBox(grpDACSelection);
        chkDACA->setObjectName(QString::fromUtf8("chkDACA"));
        chkDACA->setGeometry(QRect(3, 20, 120, 40));
        QPalette palette8;
        palette8.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette8.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette8.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette8.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette8.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette8.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette8.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette8.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette8.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        chkDACA->setPalette(palette8);
        chkDACA->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
"font: 14px;\n"
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
        chkDACB = new QCheckBox(grpDACSelection);
        chkDACB->setObjectName(QString::fromUtf8("chkDACB"));
        chkDACB->setGeometry(QRect(120, 20, 130, 40));
        QPalette palette9;
        palette9.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette9.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette9.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette9.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette9.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette9.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette9.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette9.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette9.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        chkDACB->setPalette(palette9);
        chkDACB->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
"font: 14px;\n"
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
        chkDACC = new QCheckBox(grpDACSelection);
        chkDACC->setObjectName(QString::fromUtf8("chkDACC"));
        chkDACC->setGeometry(QRect(250, 20, 120, 40));
        QPalette palette10;
        palette10.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette10.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette10.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette10.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette10.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette10.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette10.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette10.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette10.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        chkDACC->setPalette(palette10);
        chkDACC->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
"font: 14px;\n"
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
        chkDACD = new QCheckBox(grpDACSelection);
        chkDACD->setObjectName(QString::fromUtf8("chkDACD"));
        chkDACD->setGeometry(QRect(370, 20, 130, 40));
        QPalette palette11;
        palette11.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette11.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette11.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette11.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette11.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette11.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette11.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette11.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette11.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        chkDACD->setPalette(palette11);
        chkDACD->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
"font: 14px;\n"
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
        chkDACE = new QCheckBox(grpDACSelection);
        chkDACE->setObjectName(QString::fromUtf8("chkDACE"));
        chkDACE->setGeometry(QRect(3, 70, 120, 40));
        QPalette palette12;
        palette12.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette12.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette12.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette12.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette12.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette12.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette12.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette12.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette12.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        chkDACE->setPalette(palette12);
        chkDACE->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
"font: 14px;\n"
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
        chkDACF = new QCheckBox(grpDACSelection);
        chkDACF->setObjectName(QString::fromUtf8("chkDACF"));
        chkDACF->setGeometry(QRect(120, 70, 130, 40));
        QPalette palette13;
        palette13.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette13.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette13.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette13.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette13.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette13.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette13.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette13.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette13.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        chkDACF->setPalette(palette13);
        chkDACF->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
"font: 14px;\n"
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
        chkDACG = new QCheckBox(grpDACSelection);
        chkDACG->setObjectName(QString::fromUtf8("chkDACG"));
        chkDACG->setGeometry(QRect(250, 70, 120, 40));
        QPalette palette14;
        palette14.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette14.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette14.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette14.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette14.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette14.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette14.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette14.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette14.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        chkDACG->setPalette(palette14);
        chkDACG->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
"font: 14px;\n"
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
        chkDACH = new QCheckBox(grpDACSelection);
        chkDACH->setObjectName(QString::fromUtf8("chkDACH"));
        chkDACH->setGeometry(QRect(370, 70, 130, 40));
        QPalette palette15;
        palette15.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette15.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette15.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette15.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette15.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette15.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette15.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette15.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette15.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        chkDACH->setPalette(palette15);
        chkDACH->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
"font: 14px;\n"
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
        grpDACSettings = new QGroupBox(AD5318);
        grpDACSettings->setObjectName(QString::fromUtf8("grpDACSettings"));
        grpDACSettings->setGeometry(QRect(300, 119, 491, 71));
        QPalette palette16;
        grpDACSettings->setPalette(palette16);
        label_2 = new QLabel(grpDACSettings);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 28, 91, 20));
        QPalette palette17;
        palette17.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette17.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette17.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette17.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette17.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette17.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette17.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette17.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette17.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        label_2->setPalette(palette17);
        butUpdateDAC = new QPushButton(grpDACSettings);
        butUpdateDAC->setObjectName(QString::fromUtf8("butUpdateDAC"));
        butUpdateDAC->setGeometry(QRect(273, 9, 111, 40));
        QPalette palette18;
        palette18.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        QLinearGradient gradient18(0, 0, 0, 1);
        gradient18.setSpread(QGradient::PadSpread);
        gradient18.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient18.setColorAt(0, QColor(246, 247, 250, 255));
        gradient18.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush25(gradient18);
        palette18.setBrush(QPalette::Active, QPalette::Button, brush25);
        palette18.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette18.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        QLinearGradient gradient19(0, 0, 0, 1);
        gradient19.setSpread(QGradient::PadSpread);
        gradient19.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient19.setColorAt(0, QColor(246, 247, 250, 255));
        gradient19.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush26(gradient19);
        palette18.setBrush(QPalette::Active, QPalette::Base, brush26);
        QLinearGradient gradient20(0, 0, 0, 1);
        gradient20.setSpread(QGradient::PadSpread);
        gradient20.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient20.setColorAt(0, QColor(246, 247, 250, 255));
        gradient20.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush27(gradient20);
        palette18.setBrush(QPalette::Active, QPalette::Window, brush27);
        palette18.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        QLinearGradient gradient21(0, 0, 0, 1);
        gradient21.setSpread(QGradient::PadSpread);
        gradient21.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient21.setColorAt(0, QColor(246, 247, 250, 255));
        gradient21.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush28(gradient21);
        palette18.setBrush(QPalette::Inactive, QPalette::Button, brush28);
        palette18.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette18.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        QLinearGradient gradient22(0, 0, 0, 1);
        gradient22.setSpread(QGradient::PadSpread);
        gradient22.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient22.setColorAt(0, QColor(246, 247, 250, 255));
        gradient22.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush29(gradient22);
        palette18.setBrush(QPalette::Inactive, QPalette::Base, brush29);
        QLinearGradient gradient23(0, 0, 0, 1);
        gradient23.setSpread(QGradient::PadSpread);
        gradient23.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient23.setColorAt(0, QColor(246, 247, 250, 255));
        gradient23.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush30(gradient23);
        palette18.setBrush(QPalette::Inactive, QPalette::Window, brush30);
        palette18.setBrush(QPalette::Disabled, QPalette::WindowText, brush6);
        QLinearGradient gradient24(0, 0, 0, 1);
        gradient24.setSpread(QGradient::PadSpread);
        gradient24.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient24.setColorAt(0, QColor(246, 247, 250, 255));
        gradient24.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush31(gradient24);
        palette18.setBrush(QPalette::Disabled, QPalette::Button, brush31);
        palette18.setBrush(QPalette::Disabled, QPalette::Text, brush6);
        palette18.setBrush(QPalette::Disabled, QPalette::ButtonText, brush6);
        QLinearGradient gradient25(0, 0, 0, 1);
        gradient25.setSpread(QGradient::PadSpread);
        gradient25.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient25.setColorAt(0, QColor(246, 247, 250, 255));
        gradient25.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush32(gradient25);
        palette18.setBrush(QPalette::Disabled, QPalette::Base, brush32);
        QLinearGradient gradient26(0, 0, 0, 1);
        gradient26.setSpread(QGradient::PadSpread);
        gradient26.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient26.setColorAt(0, QColor(246, 247, 250, 255));
        gradient26.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush33(gradient26);
        palette18.setBrush(QPalette::Disabled, QPalette::Window, brush33);
        butUpdateDAC->setPalette(palette18);
        butUpdateDAC->setFont(font);
        butUpdateDAC->setFocusPolicy(Qt::NoFocus);
        butUpdateDAC->setStyleSheet(QString::fromUtf8(" QPushButton {\n"
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
        butRstDAC = new QPushButton(grpDACSettings);
        butRstDAC->setObjectName(QString::fromUtf8("butRstDAC"));
        butRstDAC->setGeometry(QRect(390, 10, 84, 40));
        QPalette palette19;
        palette19.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        QLinearGradient gradient27(0, 0, 0, 1);
        gradient27.setSpread(QGradient::PadSpread);
        gradient27.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient27.setColorAt(0, QColor(246, 247, 250, 255));
        gradient27.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush34(gradient27);
        palette19.setBrush(QPalette::Active, QPalette::Button, brush34);
        palette19.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette19.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        QLinearGradient gradient28(0, 0, 0, 1);
        gradient28.setSpread(QGradient::PadSpread);
        gradient28.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient28.setColorAt(0, QColor(246, 247, 250, 255));
        gradient28.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush35(gradient28);
        palette19.setBrush(QPalette::Active, QPalette::Base, brush35);
        QLinearGradient gradient29(0, 0, 0, 1);
        gradient29.setSpread(QGradient::PadSpread);
        gradient29.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient29.setColorAt(0, QColor(246, 247, 250, 255));
        gradient29.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush36(gradient29);
        palette19.setBrush(QPalette::Active, QPalette::Window, brush36);
        palette19.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        QLinearGradient gradient30(0, 0, 0, 1);
        gradient30.setSpread(QGradient::PadSpread);
        gradient30.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient30.setColorAt(0, QColor(246, 247, 250, 255));
        gradient30.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush37(gradient30);
        palette19.setBrush(QPalette::Inactive, QPalette::Button, brush37);
        palette19.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette19.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        QLinearGradient gradient31(0, 0, 0, 1);
        gradient31.setSpread(QGradient::PadSpread);
        gradient31.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient31.setColorAt(0, QColor(246, 247, 250, 255));
        gradient31.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush38(gradient31);
        palette19.setBrush(QPalette::Inactive, QPalette::Base, brush38);
        QLinearGradient gradient32(0, 0, 0, 1);
        gradient32.setSpread(QGradient::PadSpread);
        gradient32.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient32.setColorAt(0, QColor(246, 247, 250, 255));
        gradient32.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush39(gradient32);
        palette19.setBrush(QPalette::Inactive, QPalette::Window, brush39);
        palette19.setBrush(QPalette::Disabled, QPalette::WindowText, brush6);
        QLinearGradient gradient33(0, 0, 0, 1);
        gradient33.setSpread(QGradient::PadSpread);
        gradient33.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient33.setColorAt(0, QColor(246, 247, 250, 255));
        gradient33.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush40(gradient33);
        palette19.setBrush(QPalette::Disabled, QPalette::Button, brush40);
        palette19.setBrush(QPalette::Disabled, QPalette::Text, brush6);
        palette19.setBrush(QPalette::Disabled, QPalette::ButtonText, brush6);
        QLinearGradient gradient34(0, 0, 0, 1);
        gradient34.setSpread(QGradient::PadSpread);
        gradient34.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient34.setColorAt(0, QColor(246, 247, 250, 255));
        gradient34.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush41(gradient34);
        palette19.setBrush(QPalette::Disabled, QPalette::Base, brush41);
        QLinearGradient gradient35(0, 0, 0, 1);
        gradient35.setSpread(QGradient::PadSpread);
        gradient35.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient35.setColorAt(0, QColor(246, 247, 250, 255));
        gradient35.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush42(gradient35);
        palette19.setBrush(QPalette::Disabled, QPalette::Window, brush42);
        butRstDAC->setPalette(palette19);
        butRstDAC->setFont(font);
        butRstDAC->setFocusPolicy(Qt::NoFocus);
        butRstDAC->setStyleSheet(QString::fromUtf8(" QPushButton {\n"
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
        grpAD7190 = new QGroupBox(AD5318);
        grpAD7190->setObjectName(QString::fromUtf8("grpAD7190"));
        grpAD7190->setGeometry(QRect(240, 190, 261, 181));
        QPalette palette20;
        palette20.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette20.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette20.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        grpAD7190->setPalette(palette20);
        butStartADC = new QPushButton(grpAD7190);
        butStartADC->setObjectName(QString::fromUtf8("butStartADC"));
        butStartADC->setGeometry(QRect(40, 130, 84, 40));
        QPalette palette21;
        palette21.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        QLinearGradient gradient36(0, 0, 0, 1);
        gradient36.setSpread(QGradient::PadSpread);
        gradient36.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient36.setColorAt(0, QColor(246, 247, 250, 255));
        gradient36.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush43(gradient36);
        palette21.setBrush(QPalette::Active, QPalette::Button, brush43);
        palette21.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette21.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        QLinearGradient gradient37(0, 0, 0, 1);
        gradient37.setSpread(QGradient::PadSpread);
        gradient37.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient37.setColorAt(0, QColor(246, 247, 250, 255));
        gradient37.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush44(gradient37);
        palette21.setBrush(QPalette::Active, QPalette::Base, brush44);
        QLinearGradient gradient38(0, 0, 0, 1);
        gradient38.setSpread(QGradient::PadSpread);
        gradient38.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient38.setColorAt(0, QColor(246, 247, 250, 255));
        gradient38.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush45(gradient38);
        palette21.setBrush(QPalette::Active, QPalette::Window, brush45);
        palette21.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        QLinearGradient gradient39(0, 0, 0, 1);
        gradient39.setSpread(QGradient::PadSpread);
        gradient39.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient39.setColorAt(0, QColor(246, 247, 250, 255));
        gradient39.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush46(gradient39);
        palette21.setBrush(QPalette::Inactive, QPalette::Button, brush46);
        palette21.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette21.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        QLinearGradient gradient40(0, 0, 0, 1);
        gradient40.setSpread(QGradient::PadSpread);
        gradient40.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient40.setColorAt(0, QColor(246, 247, 250, 255));
        gradient40.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush47(gradient40);
        palette21.setBrush(QPalette::Inactive, QPalette::Base, brush47);
        QLinearGradient gradient41(0, 0, 0, 1);
        gradient41.setSpread(QGradient::PadSpread);
        gradient41.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient41.setColorAt(0, QColor(246, 247, 250, 255));
        gradient41.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush48(gradient41);
        palette21.setBrush(QPalette::Inactive, QPalette::Window, brush48);
        palette21.setBrush(QPalette::Disabled, QPalette::WindowText, brush6);
        QLinearGradient gradient42(0, 0, 0, 1);
        gradient42.setSpread(QGradient::PadSpread);
        gradient42.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient42.setColorAt(0, QColor(246, 247, 250, 255));
        gradient42.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush49(gradient42);
        palette21.setBrush(QPalette::Disabled, QPalette::Button, brush49);
        palette21.setBrush(QPalette::Disabled, QPalette::Text, brush6);
        palette21.setBrush(QPalette::Disabled, QPalette::ButtonText, brush6);
        QLinearGradient gradient43(0, 0, 0, 1);
        gradient43.setSpread(QGradient::PadSpread);
        gradient43.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient43.setColorAt(0, QColor(246, 247, 250, 255));
        gradient43.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush50(gradient43);
        palette21.setBrush(QPalette::Disabled, QPalette::Base, brush50);
        QLinearGradient gradient44(0, 0, 0, 1);
        gradient44.setSpread(QGradient::PadSpread);
        gradient44.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient44.setColorAt(0, QColor(246, 247, 250, 255));
        gradient44.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush51(gradient44);
        palette21.setBrush(QPalette::Disabled, QPalette::Window, brush51);
        butStartADC->setPalette(palette21);
        butStartADC->setFont(font);
        butStartADC->setFocusPolicy(Qt::NoFocus);
        butStartADC->setStyleSheet(QString::fromUtf8(" QPushButton {\n"
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
        butStopADC = new QPushButton(grpAD7190);
        butStopADC->setObjectName(QString::fromUtf8("butStopADC"));
        butStopADC->setGeometry(QRect(140, 130, 84, 40));
        QPalette palette22;
        palette22.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        QLinearGradient gradient45(0, 0, 0, 1);
        gradient45.setSpread(QGradient::PadSpread);
        gradient45.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient45.setColorAt(0, QColor(246, 247, 250, 255));
        gradient45.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush52(gradient45);
        palette22.setBrush(QPalette::Active, QPalette::Button, brush52);
        palette22.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette22.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        QLinearGradient gradient46(0, 0, 0, 1);
        gradient46.setSpread(QGradient::PadSpread);
        gradient46.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient46.setColorAt(0, QColor(246, 247, 250, 255));
        gradient46.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush53(gradient46);
        palette22.setBrush(QPalette::Active, QPalette::Base, brush53);
        QLinearGradient gradient47(0, 0, 0, 1);
        gradient47.setSpread(QGradient::PadSpread);
        gradient47.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient47.setColorAt(0, QColor(246, 247, 250, 255));
        gradient47.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush54(gradient47);
        palette22.setBrush(QPalette::Active, QPalette::Window, brush54);
        palette22.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        QLinearGradient gradient48(0, 0, 0, 1);
        gradient48.setSpread(QGradient::PadSpread);
        gradient48.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient48.setColorAt(0, QColor(246, 247, 250, 255));
        gradient48.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush55(gradient48);
        palette22.setBrush(QPalette::Inactive, QPalette::Button, brush55);
        palette22.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette22.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        QLinearGradient gradient49(0, 0, 0, 1);
        gradient49.setSpread(QGradient::PadSpread);
        gradient49.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient49.setColorAt(0, QColor(246, 247, 250, 255));
        gradient49.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush56(gradient49);
        palette22.setBrush(QPalette::Inactive, QPalette::Base, brush56);
        QLinearGradient gradient50(0, 0, 0, 1);
        gradient50.setSpread(QGradient::PadSpread);
        gradient50.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient50.setColorAt(0, QColor(246, 247, 250, 255));
        gradient50.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush57(gradient50);
        palette22.setBrush(QPalette::Inactive, QPalette::Window, brush57);
        palette22.setBrush(QPalette::Disabled, QPalette::WindowText, brush6);
        QLinearGradient gradient51(0, 0, 0, 1);
        gradient51.setSpread(QGradient::PadSpread);
        gradient51.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient51.setColorAt(0, QColor(246, 247, 250, 255));
        gradient51.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush58(gradient51);
        palette22.setBrush(QPalette::Disabled, QPalette::Button, brush58);
        palette22.setBrush(QPalette::Disabled, QPalette::Text, brush6);
        palette22.setBrush(QPalette::Disabled, QPalette::ButtonText, brush6);
        QLinearGradient gradient52(0, 0, 0, 1);
        gradient52.setSpread(QGradient::PadSpread);
        gradient52.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient52.setColorAt(0, QColor(246, 247, 250, 255));
        gradient52.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush59(gradient52);
        palette22.setBrush(QPalette::Disabled, QPalette::Base, brush59);
        QLinearGradient gradient53(0, 0, 0, 1);
        gradient53.setSpread(QGradient::PadSpread);
        gradient53.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient53.setColorAt(0, QColor(246, 247, 250, 255));
        gradient53.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush60(gradient53);
        palette22.setBrush(QPalette::Disabled, QPalette::Window, brush60);
        butStopADC->setPalette(palette22);
        butStopADC->setFont(font);
        butStopADC->setFocusPolicy(Qt::NoFocus);
        butStopADC->setStyleSheet(QString::fromUtf8(" QPushButton {\n"
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
        chkADC1 = new QCheckBox(grpAD7190);
        chkADC1->setObjectName(QString::fromUtf8("chkADC1"));
        chkADC1->setGeometry(QRect(20, 50, 81, 25));
        QPalette palette23;
        palette23.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette23.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette23.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette23.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette23.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette23.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette23.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette23.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette23.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        chkADC1->setPalette(palette23);
        chkADC1->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
"font: 14px;\n"
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
        chkADC2 = new QCheckBox(grpAD7190);
        chkADC2->setObjectName(QString::fromUtf8("chkADC2"));
        chkADC2->setGeometry(QRect(20, 90, 81, 25));
        QPalette palette24;
        palette24.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette24.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette24.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette24.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette24.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette24.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette24.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette24.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette24.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        chkADC2->setPalette(palette24);
        chkADC2->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
"font: 14px;\n"
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
        leADC1 = new QLineEdit(grpAD7190);
        leADC1->setObjectName(QString::fromUtf8("leADC1"));
        leADC1->setGeometry(QRect(110, 45, 113, 31));
        QPalette palette25;
        palette25.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush61(QColor(0, 0, 0, 255));
        brush61.setStyle(Qt::SolidPattern);
        palette25.setBrush(QPalette::Active, QPalette::Button, brush61);
        palette25.setBrush(QPalette::Active, QPalette::Text, brush);
        palette25.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette25.setBrush(QPalette::Active, QPalette::Base, brush61);
        palette25.setBrush(QPalette::Active, QPalette::Window, brush61);
        palette25.setBrush(QPalette::Active, QPalette::Highlight, brush2);
        palette25.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette25.setBrush(QPalette::Inactive, QPalette::Button, brush61);
        palette25.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette25.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette25.setBrush(QPalette::Inactive, QPalette::Base, brush61);
        palette25.setBrush(QPalette::Inactive, QPalette::Window, brush61);
        palette25.setBrush(QPalette::Inactive, QPalette::Highlight, brush2);
        palette25.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette25.setBrush(QPalette::Disabled, QPalette::Button, brush61);
        palette25.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette25.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette25.setBrush(QPalette::Disabled, QPalette::Base, brush61);
        palette25.setBrush(QPalette::Disabled, QPalette::Window, brush61);
        palette25.setBrush(QPalette::Disabled, QPalette::Highlight, brush2);
        leADC1->setPalette(palette25);
        leADC2 = new QLineEdit(grpAD7190);
        leADC2->setObjectName(QString::fromUtf8("leADC2"));
        leADC2->setGeometry(QRect(110, 90, 113, 31));
        QPalette palette26;
        palette26.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette26.setBrush(QPalette::Active, QPalette::Button, brush61);
        palette26.setBrush(QPalette::Active, QPalette::Text, brush);
        palette26.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette26.setBrush(QPalette::Active, QPalette::Base, brush61);
        palette26.setBrush(QPalette::Active, QPalette::Window, brush61);
        palette26.setBrush(QPalette::Active, QPalette::Highlight, brush2);
        palette26.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette26.setBrush(QPalette::Inactive, QPalette::Button, brush61);
        palette26.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette26.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette26.setBrush(QPalette::Inactive, QPalette::Base, brush61);
        palette26.setBrush(QPalette::Inactive, QPalette::Window, brush61);
        palette26.setBrush(QPalette::Inactive, QPalette::Highlight, brush2);
        palette26.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette26.setBrush(QPalette::Disabled, QPalette::Button, brush61);
        palette26.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette26.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette26.setBrush(QPalette::Disabled, QPalette::Base, brush61);
        palette26.setBrush(QPalette::Disabled, QPalette::Window, brush61);
        palette26.setBrush(QPalette::Disabled, QPalette::Highlight, brush2);
        leADC2->setPalette(palette26);
        chkPseudo = new QCheckBox(grpAD7190);
        chkPseudo->setObjectName(QString::fromUtf8("chkPseudo"));
        chkPseudo->setGeometry(QRect(156, 20, 91, 25));
        QPalette palette27;
        palette27.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette27.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette27.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette27.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette27.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette27.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette27.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette27.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette27.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        chkPseudo->setPalette(palette27);
        chkPseudo->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
"font: 14px;\n"
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
        grpDCDrive = new QGroupBox(AD5318);
        grpDCDrive->setObjectName(QString::fromUtf8("grpDCDrive"));
        grpDCDrive->setGeometry(QRect(10, 190, 221, 181));
        QPalette palette28;
        palette28.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette28.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette28.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        grpDCDrive->setPalette(palette28);
        label_3 = new QLabel(grpDCDrive);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 40, 61, 31));
        QPalette palette29;
        palette29.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette29.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette29.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette29.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette29.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette29.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette29.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette29.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette29.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        label_3->setPalette(palette29);
        butDriveDC = new QPushButton(grpDCDrive);
        butDriveDC->setObjectName(QString::fromUtf8("butDriveDC"));
        butDriveDC->setGeometry(QRect(87, 85, 84, 40));
        QPalette palette30;
        palette30.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        QLinearGradient gradient54(0, 0, 0, 1);
        gradient54.setSpread(QGradient::PadSpread);
        gradient54.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient54.setColorAt(0, QColor(246, 247, 250, 255));
        gradient54.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush62(gradient54);
        palette30.setBrush(QPalette::Active, QPalette::Button, brush62);
        palette30.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette30.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        QLinearGradient gradient55(0, 0, 0, 1);
        gradient55.setSpread(QGradient::PadSpread);
        gradient55.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient55.setColorAt(0, QColor(246, 247, 250, 255));
        gradient55.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush63(gradient55);
        palette30.setBrush(QPalette::Active, QPalette::Base, brush63);
        QLinearGradient gradient56(0, 0, 0, 1);
        gradient56.setSpread(QGradient::PadSpread);
        gradient56.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient56.setColorAt(0, QColor(246, 247, 250, 255));
        gradient56.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush64(gradient56);
        palette30.setBrush(QPalette::Active, QPalette::Window, brush64);
        palette30.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        QLinearGradient gradient57(0, 0, 0, 1);
        gradient57.setSpread(QGradient::PadSpread);
        gradient57.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient57.setColorAt(0, QColor(246, 247, 250, 255));
        gradient57.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush65(gradient57);
        palette30.setBrush(QPalette::Inactive, QPalette::Button, brush65);
        palette30.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette30.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        QLinearGradient gradient58(0, 0, 0, 1);
        gradient58.setSpread(QGradient::PadSpread);
        gradient58.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient58.setColorAt(0, QColor(246, 247, 250, 255));
        gradient58.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush66(gradient58);
        palette30.setBrush(QPalette::Inactive, QPalette::Base, brush66);
        QLinearGradient gradient59(0, 0, 0, 1);
        gradient59.setSpread(QGradient::PadSpread);
        gradient59.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient59.setColorAt(0, QColor(246, 247, 250, 255));
        gradient59.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush67(gradient59);
        palette30.setBrush(QPalette::Inactive, QPalette::Window, brush67);
        palette30.setBrush(QPalette::Disabled, QPalette::WindowText, brush6);
        QLinearGradient gradient60(0, 0, 0, 1);
        gradient60.setSpread(QGradient::PadSpread);
        gradient60.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient60.setColorAt(0, QColor(246, 247, 250, 255));
        gradient60.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush68(gradient60);
        palette30.setBrush(QPalette::Disabled, QPalette::Button, brush68);
        palette30.setBrush(QPalette::Disabled, QPalette::Text, brush6);
        palette30.setBrush(QPalette::Disabled, QPalette::ButtonText, brush6);
        QLinearGradient gradient61(0, 0, 0, 1);
        gradient61.setSpread(QGradient::PadSpread);
        gradient61.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient61.setColorAt(0, QColor(246, 247, 250, 255));
        gradient61.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush69(gradient61);
        palette30.setBrush(QPalette::Disabled, QPalette::Base, brush69);
        QLinearGradient gradient62(0, 0, 0, 1);
        gradient62.setSpread(QGradient::PadSpread);
        gradient62.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient62.setColorAt(0, QColor(246, 247, 250, 255));
        gradient62.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush70(gradient62);
        palette30.setBrush(QPalette::Disabled, QPalette::Window, brush70);
        butDriveDC->setPalette(palette30);
        butDriveDC->setFont(font);
        butDriveDC->setFocusPolicy(Qt::NoFocus);
        butDriveDC->setStyleSheet(QString::fromUtf8(" QPushButton {\n"
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
        lineEdit = new QLineEdit(grpDCDrive);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(76, 37, 113, 41));
        QPalette palette31;
        palette31.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette31.setBrush(QPalette::Active, QPalette::Button, brush61);
        palette31.setBrush(QPalette::Active, QPalette::Text, brush);
        palette31.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette31.setBrush(QPalette::Active, QPalette::Base, brush61);
        palette31.setBrush(QPalette::Active, QPalette::Window, brush61);
        palette31.setBrush(QPalette::Active, QPalette::Highlight, brush2);
        palette31.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette31.setBrush(QPalette::Inactive, QPalette::Button, brush61);
        palette31.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette31.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette31.setBrush(QPalette::Inactive, QPalette::Base, brush61);
        palette31.setBrush(QPalette::Inactive, QPalette::Window, brush61);
        palette31.setBrush(QPalette::Inactive, QPalette::Highlight, brush2);
        palette31.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette31.setBrush(QPalette::Disabled, QPalette::Button, brush61);
        palette31.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette31.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette31.setBrush(QPalette::Disabled, QPalette::Base, brush61);
        palette31.setBrush(QPalette::Disabled, QPalette::Window, brush61);
        palette31.setBrush(QPalette::Disabled, QPalette::Highlight, brush2);
        lineEdit->setPalette(palette31);
        chkP1V = new QCheckBox(grpDCDrive);
        chkP1V->setObjectName(QString::fromUtf8("chkP1V"));
        chkP1V->setGeometry(QRect(10, 136, 81, 25));
        QPalette palette32;
        palette32.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette32.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette32.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette32.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette32.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette32.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette32.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette32.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette32.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        chkP1V->setPalette(palette32);
        chkP1V->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
"font: 14px;\n"
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
        chkP2V = new QCheckBox(grpDCDrive);
        chkP2V->setObjectName(QString::fromUtf8("chkP2V"));
        chkP2V->setGeometry(QRect(130, 136, 81, 25));
        QPalette palette33;
        palette33.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette33.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette33.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette33.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette33.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette33.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette33.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette33.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette33.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        chkP2V->setPalette(palette33);
        chkP2V->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
"font: 14px;\n"
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
        grpGain = new QGroupBox(AD5318);
        grpGain->setObjectName(QString::fromUtf8("grpGain"));
        grpGain->setGeometry(QRect(510, 190, 151, 181));
        QPalette palette34;
        palette34.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette34.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette34.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        grpGain->setPalette(palette34);
        butGain1 = new QRadioButton(grpGain);
        butGain1->setObjectName(QString::fromUtf8("butGain1"));
        butGain1->setGeometry(QRect(20, 30, 61, 26));
        butGain1->setStyleSheet(QString::fromUtf8("QRadioButton{\n"
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
        butGain8 = new QRadioButton(grpGain);
        butGain8->setObjectName(QString::fromUtf8("butGain8"));
        butGain8->setGeometry(QRect(80, 30, 61, 26));
        butGain8->setStyleSheet(QString::fromUtf8("QRadioButton{\n"
"font: 14px;\n"
"color:yellow\n"
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
        butGain16 = new QRadioButton(grpGain);
        butGain16->setObjectName(QString::fromUtf8("butGain16"));
        butGain16->setGeometry(QRect(20, 70, 61, 26));
        butGain16->setStyleSheet(QString::fromUtf8("QRadioButton{\n"
"font: 14px;\n"
"color:yellow\n"
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
        butGain32 = new QRadioButton(grpGain);
        butGain32->setObjectName(QString::fromUtf8("butGain32"));
        butGain32->setGeometry(QRect(80, 70, 61, 26));
        butGain32->setStyleSheet(QString::fromUtf8("QRadioButton{\n"
"font: 14px;\n"
"color:yellow\n"
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
        butGain64 = new QRadioButton(grpGain);
        butGain64->setObjectName(QString::fromUtf8("butGain64"));
        butGain64->setGeometry(QRect(20, 110, 61, 26));
        butGain64->setStyleSheet(QString::fromUtf8("QRadioButton{\n"
"font: 14px;\n"
"color:yellow\n"
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
        butGain128 = new QRadioButton(grpGain);
        butGain128->setObjectName(QString::fromUtf8("butGain128"));
        butGain128->setGeometry(QRect(80, 110, 61, 26));
        butGain128->setStyleSheet(QString::fromUtf8("QRadioButton{\n"
"font: 14px;\n"
"color:yellow\n"
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
        butSwitchRly = new QPushButton(grpGain);
        butSwitchRly->setObjectName(QString::fromUtf8("butSwitchRly"));
        butSwitchRly->setGeometry(QRect(30, 140, 84, 40));
        QPalette palette35;
        palette35.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        QLinearGradient gradient63(0, 0, 0, 1);
        gradient63.setSpread(QGradient::PadSpread);
        gradient63.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient63.setColorAt(0, QColor(246, 247, 250, 255));
        gradient63.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush71(gradient63);
        palette35.setBrush(QPalette::Active, QPalette::Button, brush71);
        palette35.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette35.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        QLinearGradient gradient64(0, 0, 0, 1);
        gradient64.setSpread(QGradient::PadSpread);
        gradient64.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient64.setColorAt(0, QColor(246, 247, 250, 255));
        gradient64.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush72(gradient64);
        palette35.setBrush(QPalette::Active, QPalette::Base, brush72);
        QLinearGradient gradient65(0, 0, 0, 1);
        gradient65.setSpread(QGradient::PadSpread);
        gradient65.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient65.setColorAt(0, QColor(246, 247, 250, 255));
        gradient65.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush73(gradient65);
        palette35.setBrush(QPalette::Active, QPalette::Window, brush73);
        palette35.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        QLinearGradient gradient66(0, 0, 0, 1);
        gradient66.setSpread(QGradient::PadSpread);
        gradient66.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient66.setColorAt(0, QColor(246, 247, 250, 255));
        gradient66.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush74(gradient66);
        palette35.setBrush(QPalette::Inactive, QPalette::Button, brush74);
        palette35.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette35.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        QLinearGradient gradient67(0, 0, 0, 1);
        gradient67.setSpread(QGradient::PadSpread);
        gradient67.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient67.setColorAt(0, QColor(246, 247, 250, 255));
        gradient67.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush75(gradient67);
        palette35.setBrush(QPalette::Inactive, QPalette::Base, brush75);
        QLinearGradient gradient68(0, 0, 0, 1);
        gradient68.setSpread(QGradient::PadSpread);
        gradient68.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient68.setColorAt(0, QColor(246, 247, 250, 255));
        gradient68.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush76(gradient68);
        palette35.setBrush(QPalette::Inactive, QPalette::Window, brush76);
        palette35.setBrush(QPalette::Disabled, QPalette::WindowText, brush6);
        QLinearGradient gradient69(0, 0, 0, 1);
        gradient69.setSpread(QGradient::PadSpread);
        gradient69.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient69.setColorAt(0, QColor(246, 247, 250, 255));
        gradient69.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush77(gradient69);
        palette35.setBrush(QPalette::Disabled, QPalette::Button, brush77);
        palette35.setBrush(QPalette::Disabled, QPalette::Text, brush6);
        palette35.setBrush(QPalette::Disabled, QPalette::ButtonText, brush6);
        QLinearGradient gradient70(0, 0, 0, 1);
        gradient70.setSpread(QGradient::PadSpread);
        gradient70.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient70.setColorAt(0, QColor(246, 247, 250, 255));
        gradient70.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush78(gradient70);
        palette35.setBrush(QPalette::Disabled, QPalette::Base, brush78);
        QLinearGradient gradient71(0, 0, 0, 1);
        gradient71.setSpread(QGradient::PadSpread);
        gradient71.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient71.setColorAt(0, QColor(246, 247, 250, 255));
        gradient71.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush79(gradient71);
        palette35.setBrush(QPalette::Disabled, QPalette::Window, brush79);
        butSwitchRly->setPalette(palette35);
        butSwitchRly->setFont(font);
        butSwitchRly->setFocusPolicy(Qt::NoFocus);
        butSwitchRly->setStyleSheet(QString::fromUtf8(" QPushButton {\n"
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
        grpAD5293 = new QGroupBox(AD5318);
        grpAD5293->setObjectName(QString::fromUtf8("grpAD5293"));
        grpAD5293->setGeometry(QRect(10, 370, 260, 130));
        QPalette palette36;
        palette36.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette36.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette36.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        grpAD5293->setPalette(palette36);
        label_4 = new QLabel(grpAD5293);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(14, 73, 61, 31));
        QPalette palette37;
        palette37.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette37.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette37.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette37.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette37.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette37.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette37.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette37.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette37.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        label_4->setPalette(palette37);
        lineEdit_2 = new QLineEdit(grpAD5293);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(80, 70, 113, 41));
        QPalette palette38;
        palette38.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette38.setBrush(QPalette::Active, QPalette::Button, brush61);
        palette38.setBrush(QPalette::Active, QPalette::Text, brush);
        palette38.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette38.setBrush(QPalette::Active, QPalette::Base, brush61);
        palette38.setBrush(QPalette::Active, QPalette::Window, brush61);
        palette38.setBrush(QPalette::Active, QPalette::Highlight, brush2);
        palette38.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette38.setBrush(QPalette::Inactive, QPalette::Button, brush61);
        palette38.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette38.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette38.setBrush(QPalette::Inactive, QPalette::Base, brush61);
        palette38.setBrush(QPalette::Inactive, QPalette::Window, brush61);
        palette38.setBrush(QPalette::Inactive, QPalette::Highlight, brush2);
        palette38.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette38.setBrush(QPalette::Disabled, QPalette::Button, brush61);
        palette38.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette38.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette38.setBrush(QPalette::Disabled, QPalette::Base, brush61);
        palette38.setBrush(QPalette::Disabled, QPalette::Window, brush61);
        palette38.setBrush(QPalette::Disabled, QPalette::Highlight, brush2);
        lineEdit_2->setPalette(palette38);
        butAD5293Drive = new QPushButton(grpAD5293);
        butAD5293Drive->setObjectName(QString::fromUtf8("butAD5293Drive"));
        butAD5293Drive->setGeometry(QRect(200, 20, 50, 90));
        QPalette palette39;
        palette39.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        QLinearGradient gradient72(0, 0, 0, 1);
        gradient72.setSpread(QGradient::PadSpread);
        gradient72.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient72.setColorAt(0, QColor(246, 247, 250, 255));
        gradient72.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush80(gradient72);
        palette39.setBrush(QPalette::Active, QPalette::Button, brush80);
        palette39.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette39.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        QLinearGradient gradient73(0, 0, 0, 1);
        gradient73.setSpread(QGradient::PadSpread);
        gradient73.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient73.setColorAt(0, QColor(246, 247, 250, 255));
        gradient73.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush81(gradient73);
        palette39.setBrush(QPalette::Active, QPalette::Base, brush81);
        QLinearGradient gradient74(0, 0, 0, 1);
        gradient74.setSpread(QGradient::PadSpread);
        gradient74.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient74.setColorAt(0, QColor(246, 247, 250, 255));
        gradient74.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush82(gradient74);
        palette39.setBrush(QPalette::Active, QPalette::Window, brush82);
        palette39.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        QLinearGradient gradient75(0, 0, 0, 1);
        gradient75.setSpread(QGradient::PadSpread);
        gradient75.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient75.setColorAt(0, QColor(246, 247, 250, 255));
        gradient75.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush83(gradient75);
        palette39.setBrush(QPalette::Inactive, QPalette::Button, brush83);
        palette39.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette39.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        QLinearGradient gradient76(0, 0, 0, 1);
        gradient76.setSpread(QGradient::PadSpread);
        gradient76.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient76.setColorAt(0, QColor(246, 247, 250, 255));
        gradient76.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush84(gradient76);
        palette39.setBrush(QPalette::Inactive, QPalette::Base, brush84);
        QLinearGradient gradient77(0, 0, 0, 1);
        gradient77.setSpread(QGradient::PadSpread);
        gradient77.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient77.setColorAt(0, QColor(246, 247, 250, 255));
        gradient77.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush85(gradient77);
        palette39.setBrush(QPalette::Inactive, QPalette::Window, brush85);
        palette39.setBrush(QPalette::Disabled, QPalette::WindowText, brush6);
        QLinearGradient gradient78(0, 0, 0, 1);
        gradient78.setSpread(QGradient::PadSpread);
        gradient78.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient78.setColorAt(0, QColor(246, 247, 250, 255));
        gradient78.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush86(gradient78);
        palette39.setBrush(QPalette::Disabled, QPalette::Button, brush86);
        palette39.setBrush(QPalette::Disabled, QPalette::Text, brush6);
        palette39.setBrush(QPalette::Disabled, QPalette::ButtonText, brush6);
        QLinearGradient gradient79(0, 0, 0, 1);
        gradient79.setSpread(QGradient::PadSpread);
        gradient79.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient79.setColorAt(0, QColor(246, 247, 250, 255));
        gradient79.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush87(gradient79);
        palette39.setBrush(QPalette::Disabled, QPalette::Base, brush87);
        QLinearGradient gradient80(0, 0, 0, 1);
        gradient80.setSpread(QGradient::PadSpread);
        gradient80.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient80.setColorAt(0, QColor(246, 247, 250, 255));
        gradient80.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush88(gradient80);
        palette39.setBrush(QPalette::Disabled, QPalette::Window, brush88);
        butAD5293Drive->setPalette(palette39);
        butAD5293Drive->setFont(font);
        butAD5293Drive->setFocusPolicy(Qt::NoFocus);
        butAD5293Drive->setStyleSheet(QString::fromUtf8(" QPushButton {\n"
"     border: 2px solid #8f8f91;\n"
"     border-radius: 10px;\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #f6f7fa, stop: 1 #dadbde);\n"
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
        comboBox = new QComboBox(grpAD5293);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(85, 20, 101, 41));
        label_5 = new QLabel(grpAD5293);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(27, 25, 61, 31));
        QPalette palette40;
        palette40.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette40.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette40.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette40.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette40.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette40.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette40.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette40.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette40.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        label_5->setPalette(palette40);
        calibrationBox = new QGroupBox(AD5318);
        calibrationBox->setObjectName(QString::fromUtf8("calibrationBox"));
        calibrationBox->setGeometry(QRect(280, 370, 280, 160));
        QPalette palette41;
        palette41.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette41.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette41.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        calibrationBox->setPalette(palette41);
        DriveCurrent = new QPushButton(calibrationBox);
        DriveCurrent->setObjectName(QString::fromUtf8("DriveCurrent"));
        DriveCurrent->setGeometry(QRect(10, 30, 80, 50));
        DriveCurrent->setFont(font);
        DriveVoltage = new QPushButton(calibrationBox);
        DriveVoltage->setObjectName(QString::fromUtf8("DriveVoltage"));
        DriveVoltage->setGeometry(QRect(10, 80, 80, 50));
        DriveVoltage->setFont(font);
        Receiver = new QPushButton(calibrationBox);
        Receiver->setObjectName(QString::fromUtf8("Receiver"));
        Receiver->setGeometry(QRect(100, 30, 80, 50));
        Receiver->setFont(font);
        Reference = new QPushButton(calibrationBox);
        Reference->setObjectName(QString::fromUtf8("Reference"));
        Reference->setGeometry(QRect(100, 80, 80, 50));
        Reference->setFont(font);
        butCheckDriveDone = new QPushButton(calibrationBox);
        butCheckDriveDone->setObjectName(QString::fromUtf8("butCheckDriveDone"));
        butCheckDriveDone->setGeometry(QRect(190, 30, 60, 100));
        QPalette palette42;
        palette42.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        QLinearGradient gradient81(0, 0, 0, 1);
        gradient81.setSpread(QGradient::PadSpread);
        gradient81.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient81.setColorAt(0, QColor(246, 247, 250, 255));
        gradient81.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush89(gradient81);
        palette42.setBrush(QPalette::Active, QPalette::Button, brush89);
        palette42.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette42.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        QLinearGradient gradient82(0, 0, 0, 1);
        gradient82.setSpread(QGradient::PadSpread);
        gradient82.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient82.setColorAt(0, QColor(246, 247, 250, 255));
        gradient82.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush90(gradient82);
        palette42.setBrush(QPalette::Active, QPalette::Base, brush90);
        QLinearGradient gradient83(0, 0, 0, 1);
        gradient83.setSpread(QGradient::PadSpread);
        gradient83.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient83.setColorAt(0, QColor(246, 247, 250, 255));
        gradient83.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush91(gradient83);
        palette42.setBrush(QPalette::Active, QPalette::Window, brush91);
        palette42.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        QLinearGradient gradient84(0, 0, 0, 1);
        gradient84.setSpread(QGradient::PadSpread);
        gradient84.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient84.setColorAt(0, QColor(246, 247, 250, 255));
        gradient84.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush92(gradient84);
        palette42.setBrush(QPalette::Inactive, QPalette::Button, brush92);
        palette42.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette42.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        QLinearGradient gradient85(0, 0, 0, 1);
        gradient85.setSpread(QGradient::PadSpread);
        gradient85.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient85.setColorAt(0, QColor(246, 247, 250, 255));
        gradient85.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush93(gradient85);
        palette42.setBrush(QPalette::Inactive, QPalette::Base, brush93);
        QLinearGradient gradient86(0, 0, 0, 1);
        gradient86.setSpread(QGradient::PadSpread);
        gradient86.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient86.setColorAt(0, QColor(246, 247, 250, 255));
        gradient86.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush94(gradient86);
        palette42.setBrush(QPalette::Inactive, QPalette::Window, brush94);
        palette42.setBrush(QPalette::Disabled, QPalette::WindowText, brush6);
        QLinearGradient gradient87(0, 0, 0, 1);
        gradient87.setSpread(QGradient::PadSpread);
        gradient87.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient87.setColorAt(0, QColor(246, 247, 250, 255));
        gradient87.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush95(gradient87);
        palette42.setBrush(QPalette::Disabled, QPalette::Button, brush95);
        palette42.setBrush(QPalette::Disabled, QPalette::Text, brush6);
        palette42.setBrush(QPalette::Disabled, QPalette::ButtonText, brush6);
        QLinearGradient gradient88(0, 0, 0, 1);
        gradient88.setSpread(QGradient::PadSpread);
        gradient88.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient88.setColorAt(0, QColor(246, 247, 250, 255));
        gradient88.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush96(gradient88);
        palette42.setBrush(QPalette::Disabled, QPalette::Base, brush96);
        QLinearGradient gradient89(0, 0, 0, 1);
        gradient89.setSpread(QGradient::PadSpread);
        gradient89.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient89.setColorAt(0, QColor(246, 247, 250, 255));
        gradient89.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush97(gradient89);
        palette42.setBrush(QPalette::Disabled, QPalette::Window, brush97);
        butCheckDriveDone->setPalette(palette42);
        butCheckDriveDone->setFont(font);
        butCheckDriveDone->setFocusPolicy(Qt::NoFocus);
        butCheckDriveDone->setStyleSheet(QString::fromUtf8(" QPushButton {\n"
"     border: 2px solid #8f8f91;\n"
"     border-radius: 10px;\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #f6f7fa, stop: 1 #dadbde);\n"
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
        butFileManager = new QPushButton(AD5318);
        butFileManager->setObjectName(QString::fromUtf8("butFileManager"));
        butFileManager->setGeometry(QRect(680, 410, 111, 50));
        butFileManager->setFont(font);
        butLMH6518 = new QPushButton(AD5318);
        butLMH6518->setObjectName(QString::fromUtf8("butLMH6518"));
        butLMH6518->setGeometry(QRect(560, 410, 111, 50));
        butLMH6518->setFont(font);
        pushButton = new QPushButton(AD5318);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(680, 210, 110, 41));
        pushButton_2 = new QPushButton(AD5318);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(680, 270, 110, 41));
        appBck = new QPushButton(AD5318);
        appBck->setObjectName(QString::fromUtf8("appBck"));
        appBck->setGeometry(QRect(730, 340, 61, 61));
        appBck->setFocusPolicy(Qt::NoFocus);
        appBck->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"         border: 2px solid rgba(0,0,0,0);\n"
"         border-radius: 25px;\n"
"         background-color: rgba(0,0,0,0);image: url(:/settings_iOS4.png);\n"
"\n"
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
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Symbols/Control-Panel-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        appBck->setIcon(icon);
        appBck->setIconSize(QSize(55, 50));

        retranslateUi(AD5318);

        QMetaObject::connectSlotsByName(AD5318);
    } // setupUi

    void retranslateUi(QWidget *AD5318)
    {
        AD5318->setWindowTitle(QApplication::translate("AD5318", "PTAPPCardComponents", 0, QApplication::UnicodeUTF8));
        grpGeneral->setTitle(QApplication::translate("AD5318", "General", 0, QApplication::UnicodeUTF8));
        lblAddress->setText(QApplication::translate("AD5318", "Address:", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("AD5318", "Data:", 0, QApplication::UnicodeUTF8));
        butRead->setText(QApplication::translate("AD5318", "Read", 0, QApplication::UnicodeUTF8));
        butWrite->setText(QApplication::translate("AD5318", "Write", 0, QApplication::UnicodeUTF8));
        butStart->setText(QApplication::translate("AD5318", "Start", 0, QApplication::UnicodeUTF8));
        chkAddrWrite->setText(QApplication::translate("AD5318", "write", 0, QApplication::UnicodeUTF8));
        grpDACSelection->setTitle(QApplication::translate("AD5318", "DAC Selection", 0, QApplication::UnicodeUTF8));
        chkDACA->setText(QApplication::translate("AD5318", "DAC A\n"
"DSO1-OFF", 0, QApplication::UnicodeUTF8));
        chkDACB->setText(QApplication::translate("AD5318", "DAC B\n"
"DSO1-T-OFF", 0, QApplication::UnicodeUTF8));
        chkDACC->setText(QApplication::translate("AD5318", "DAC C\n"
"DSO2-OFF", 0, QApplication::UnicodeUTF8));
        chkDACD->setText(QApplication::translate("AD5318", "DAC D\n"
"DSO2-T-OFF", 0, QApplication::UnicodeUTF8));
        chkDACE->setText(QApplication::translate("AD5318", "DAC E\n"
"EXT-T-OFF", 0, QApplication::UnicodeUTF8));
        chkDACF->setText(QApplication::translate("AD5318", "DAC F\n"
"FG-OFF", 0, QApplication::UnicodeUTF8));
        chkDACG->setText(QApplication::translate("AD5318", "DAC G\n"
"Current", 0, QApplication::UnicodeUTF8));
        chkDACH->setText(QApplication::translate("AD5318", "DAC H\n"
"Over Range", 0, QApplication::UnicodeUTF8));
        grpDACSettings->setTitle(QString());
        label_2->setText(QApplication::translate("AD5318", "DAC INPUT:", 0, QApplication::UnicodeUTF8));
        butUpdateDAC->setText(QApplication::translate("AD5318", "Update DAC", 0, QApplication::UnicodeUTF8));
        butRstDAC->setText(QApplication::translate("AD5318", "Reset DAC", 0, QApplication::UnicodeUTF8));
        grpAD7190->setTitle(QApplication::translate("AD5318", "AD7190", 0, QApplication::UnicodeUTF8));
        butStartADC->setText(QApplication::translate("AD5318", "Start", 0, QApplication::UnicodeUTF8));
        butStopADC->setText(QApplication::translate("AD5318", "Stop", 0, QApplication::UnicodeUTF8));
        chkADC1->setText(QApplication::translate("AD5318", "ADC 1", 0, QApplication::UnicodeUTF8));
        chkADC2->setText(QApplication::translate("AD5318", "ADC 2", 0, QApplication::UnicodeUTF8));
        chkPseudo->setText(QApplication::translate("AD5318", "Psuedo", 0, QApplication::UnicodeUTF8));
        grpDCDrive->setTitle(QApplication::translate("AD5318", "DC", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("AD5318", "Voltage:", 0, QApplication::UnicodeUTF8));
        butDriveDC->setText(QApplication::translate("AD5318", "Drive", 0, QApplication::UnicodeUTF8));
        chkP1V->setText(QApplication::translate("AD5318", "0.1V", 0, QApplication::UnicodeUTF8));
        chkP2V->setText(QApplication::translate("AD5318", "0.2V", 0, QApplication::UnicodeUTF8));
        grpGain->setTitle(QApplication::translate("AD5318", "Gain", 0, QApplication::UnicodeUTF8));
        butGain1->setText(QApplication::translate("AD5318", "1", 0, QApplication::UnicodeUTF8));
        butGain8->setText(QApplication::translate("AD5318", "8", 0, QApplication::UnicodeUTF8));
        butGain16->setText(QApplication::translate("AD5318", "16", 0, QApplication::UnicodeUTF8));
        butGain32->setText(QApplication::translate("AD5318", "32", 0, QApplication::UnicodeUTF8));
        butGain64->setText(QApplication::translate("AD5318", "64", 0, QApplication::UnicodeUTF8));
        butGain128->setText(QApplication::translate("AD5318", "128", 0, QApplication::UnicodeUTF8));
        butSwitchRly->setText(QApplication::translate("AD5318", "switchRLY", 0, QApplication::UnicodeUTF8));
        grpAD5293->setTitle(QApplication::translate("AD5318", "AD5293", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("AD5318", "Refin:", 0, QApplication::UnicodeUTF8));
        butAD5293Drive->setText(QApplication::translate("AD5318", "Drive", 0, QApplication::UnicodeUTF8));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("AD5318", "0.5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("AD5318", "1.5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("AD5318", "3.5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("AD5318", "7.0", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("AD5318", "13.0", 0, QApplication::UnicodeUTF8)
        );
        label_5->setText(QApplication::translate("AD5318", "Voltage", 0, QApplication::UnicodeUTF8));
        calibrationBox->setTitle(QApplication::translate("AD5318", "Calibrations", 0, QApplication::UnicodeUTF8));
        DriveCurrent->setText(QApplication::translate("AD5318", "Drive \n"
"Current", 0, QApplication::UnicodeUTF8));
        DriveVoltage->setText(QApplication::translate("AD5318", "Drive\n"
"Voltage", 0, QApplication::UnicodeUTF8));
        Receiver->setText(QApplication::translate("AD5318", "Receiver", 0, QApplication::UnicodeUTF8));
        Reference->setText(QApplication::translate("AD5318", "Reference", 0, QApplication::UnicodeUTF8));
        butCheckDriveDone->setText(QApplication::translate("AD5318", "check\n"
"Drive\n"
"done", 0, QApplication::UnicodeUTF8));
        butFileManager->setText(QApplication::translate("AD5318", "File\n"
"Manager", 0, QApplication::UnicodeUTF8));
        butLMH6518->setText(QApplication::translate("AD5318", "LMH6518", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("AD5318", "Enable Debug \n"
"Panel", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("AD5318", "Close Testjig", 0, QApplication::UnicodeUTF8));
        appBck->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AD5318: public Ui_AD5318 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AD5318_H
