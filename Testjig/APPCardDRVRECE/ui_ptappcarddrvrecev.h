/********************************************************************************
** Form generated from reading UI file 'ptappcarddrvrecev.ui'
**
** Created: Sat Sep 6 10:53:10 2014
**      by: Qt User Interface Compiler version 4.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PTAPPCARDDRVRECEV_H
#define UI_PTAPPCARDDRVRECEV_H

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
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PtAppCardDrvRecev
{
public:
    QGroupBox *groupBox;
    QGroupBox *groupBox_5;
    QCheckBox *chkSRCN;
    QComboBox *cmbIRS;
    QCheckBox *chkVIS;
    QLabel *label;
    QGroupBox *grpSource;
    QComboBox *cmbSourceSelection;
    QGroupBox *groupBox_2;
    QComboBox *cmbVISelection;
    QCheckBox *chkSlotOffsetEN;
    QGroupBox *grpSI;
    QComboBox *cmbBPSourceImpedance;
    QPushButton *butDriveRelay;
    QGroupBox *groupBox_4;
    QGroupBox *grpReceiver1;
    QCheckBox *chkRece1HSHA;
    QCheckBox *chkRece1HAAC;
    QCheckBox *chkRece1RMSIN;
    QCheckBox *chkRece1RMSGAIN;
    QCheckBox *chkRece1HAIPSEL;
    QCheckBox *chkRece1HSVI;
    QComboBox *cmbR1Coupling;
    QLabel *label_5;
    QCheckBox *chkRece1RMSCAVG;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_15;
    QGroupBox *grpReceiver2;
    QCheckBox *chkRece2HSHA;
    QCheckBox *chkRece2HAAC;
    QCheckBox *chkRece2RMSIN;
    QCheckBox *chkRece2RMSGAIN;
    QCheckBox *chkRece2HAIPSEL;
    QCheckBox *chkRece2ICMEN;
    QLabel *label_4;
    QComboBox *cmbR2Coupling;
    QCheckBox *chkRece2RMSCAVG;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_16;
    QGroupBox *grpICMGAIN;
    QComboBox *cmbICMRange;
    QLabel *label_6;
    QCheckBox *chkICMGAIN;
    QCheckBox *chkICMIASEL;
    QCheckBox *chkICMBCAPSEL;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_19;
    QGroupBox *grpGeneral;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QPushButton *butAppRead;
    QPushButton *butAppWrite;
    QPushButton *butReceiveRelay;

    void setupUi(QWidget *PtAppCardDrvRecev)
    {
        if (PtAppCardDrvRecev->objectName().isEmpty())
            PtAppCardDrvRecev->setObjectName(QString::fromUtf8("PtAppCardDrvRecev"));
        PtAppCardDrvRecev->resize(800, 520);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush1(QColor(170, 170, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        PtAppCardDrvRecev->setPalette(palette);
        PtAppCardDrvRecev->setStyleSheet(QString::fromUtf8("QLineEdit{border-width: 2px;border-style: outset;border-color: gray; border-radius: 1px;  padding: 0 8px;     background: black;     selection-background-color: yellow;   color:white;     font: bold 14px;}\n"
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
"QCheckBox::indicator:checked:pressed {	background-color:#f2a400;}"));
        groupBox = new QGroupBox(PtAppCardDrvRecev);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 0, 781, 191));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        QBrush brush2(QColor(0, 0, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        groupBox->setPalette(palette1);
        QFont font;
        font.setFamily(QString::fromUtf8("DejaVu Sans"));
        font.setBold(false);
        font.setWeight(50);
        groupBox->setFont(font);
        groupBox_5 = new QGroupBox(groupBox);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(10, 20, 380, 81));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        groupBox_5->setPalette(palette2);
        groupBox_5->setFont(font);
        chkSRCN = new QCheckBox(groupBox_5);
        chkSRCN->setObjectName(QString::fromUtf8("chkSRCN"));
        chkSRCN->setGeometry(QRect(270, 30, 81, 31));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        chkSRCN->setPalette(palette3);
        QFont font1;
        font1.setFamily(QString::fromUtf8("DejaVu Sans"));
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        chkSRCN->setFont(font1);
        chkSRCN->setStyleSheet(QString::fromUtf8(""));
        cmbIRS = new QComboBox(groupBox_5);
        cmbIRS->setObjectName(QString::fromUtf8("cmbIRS"));
        cmbIRS->setEnabled(true);
        cmbIRS->setGeometry(QRect(150, 20, 101, 51));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(10);
        sizePolicy.setHeightForWidth(cmbIRS->sizePolicy().hasHeightForWidth());
        cmbIRS->setSizePolicy(sizePolicy);
        cmbIRS->setMinimumSize(QSize(0, 30));
        cmbIRS->setSizeIncrement(QSize(10, 10));
        cmbIRS->setBaseSize(QSize(0, 10));
        QPalette palette4;
        QBrush brush3(QColor(0, 0, 127, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush3);
        palette4.setBrush(QPalette::Active, QPalette::Text, brush3);
        palette4.setBrush(QPalette::Active, QPalette::ButtonText, brush3);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush3);
        palette4.setBrush(QPalette::Inactive, QPalette::Text, brush3);
        palette4.setBrush(QPalette::Inactive, QPalette::ButtonText, brush3);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette4.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette4.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        cmbIRS->setPalette(palette4);
        QFont font2;
        font2.setFamily(QString::fromUtf8("DejaVu Sans"));
        font2.setPointSize(13);
        font2.setBold(false);
        font2.setWeight(50);
        cmbIRS->setFont(font2);
        chkVIS = new QCheckBox(groupBox_5);
        chkVIS->setObjectName(QString::fromUtf8("chkVIS"));
        chkVIS->setGeometry(QRect(30, 30, 71, 31));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Active, QPalette::Text, brush);
        palette5.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette5.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette5.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        chkVIS->setPalette(palette5);
        chkVIS->setFont(font1);
        chkVIS->setStyleSheet(QString::fromUtf8(""));
        label = new QLabel(groupBox_5);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(110, 35, 31, 20));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette6.setBrush(QPalette::Active, QPalette::Text, brush);
        palette6.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette6.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette6.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        label->setPalette(palette6);
        label->setFont(font);
        grpSource = new QGroupBox(groupBox);
        grpSource->setObjectName(QString::fromUtf8("grpSource"));
        grpSource->setGeometry(QRect(400, 20, 370, 81));
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette7.setBrush(QPalette::Active, QPalette::Text, brush);
        palette7.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette7.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette7.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette7.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        grpSource->setPalette(palette7);
        grpSource->setFont(font);
        cmbSourceSelection = new QComboBox(grpSource);
        cmbSourceSelection->setObjectName(QString::fromUtf8("cmbSourceSelection"));
        cmbSourceSelection->setGeometry(QRect(20, 20, 331, 51));
        QPalette palette8;
        palette8.setBrush(QPalette::Active, QPalette::WindowText, brush3);
        palette8.setBrush(QPalette::Active, QPalette::Text, brush3);
        palette8.setBrush(QPalette::Active, QPalette::ButtonText, brush3);
        palette8.setBrush(QPalette::Inactive, QPalette::WindowText, brush3);
        palette8.setBrush(QPalette::Inactive, QPalette::Text, brush3);
        palette8.setBrush(QPalette::Inactive, QPalette::ButtonText, brush3);
        palette8.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette8.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette8.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        cmbSourceSelection->setPalette(palette8);
        cmbSourceSelection->setFont(font2);
        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 100, 380, 80));
        QPalette palette9;
        palette9.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette9.setBrush(QPalette::Active, QPalette::Text, brush);
        palette9.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette9.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette9.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette9.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette9.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette9.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette9.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        groupBox_2->setPalette(palette9);
        groupBox_2->setFont(font);
        cmbVISelection = new QComboBox(groupBox_2);
        cmbVISelection->setObjectName(QString::fromUtf8("cmbVISelection"));
        cmbVISelection->setEnabled(true);
        cmbVISelection->setGeometry(QRect(30, 20, 100, 51));
        sizePolicy.setHeightForWidth(cmbVISelection->sizePolicy().hasHeightForWidth());
        cmbVISelection->setSizePolicy(sizePolicy);
        cmbVISelection->setMinimumSize(QSize(0, 30));
        cmbVISelection->setSizeIncrement(QSize(10, 10));
        cmbVISelection->setBaseSize(QSize(0, 10));
        QPalette palette10;
        palette10.setBrush(QPalette::Active, QPalette::WindowText, brush3);
        palette10.setBrush(QPalette::Active, QPalette::Text, brush3);
        palette10.setBrush(QPalette::Active, QPalette::ButtonText, brush3);
        palette10.setBrush(QPalette::Inactive, QPalette::WindowText, brush3);
        palette10.setBrush(QPalette::Inactive, QPalette::Text, brush3);
        palette10.setBrush(QPalette::Inactive, QPalette::ButtonText, brush3);
        palette10.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette10.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette10.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        cmbVISelection->setPalette(palette10);
        cmbVISelection->setFont(font2);
        chkSlotOffsetEN = new QCheckBox(groupBox_2);
        chkSlotOffsetEN->setObjectName(QString::fromUtf8("chkSlotOffsetEN"));
        chkSlotOffsetEN->setGeometry(QRect(210, 30, 150, 31));
        QPalette palette11;
        palette11.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette11.setBrush(QPalette::Active, QPalette::Text, brush);
        palette11.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette11.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette11.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette11.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette11.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette11.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette11.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        chkSlotOffsetEN->setPalette(palette11);
        chkSlotOffsetEN->setFont(font1);
        chkSlotOffsetEN->setStyleSheet(QString::fromUtf8(""));
        grpSI = new QGroupBox(groupBox);
        grpSI->setObjectName(QString::fromUtf8("grpSI"));
        grpSI->setGeometry(QRect(400, 100, 260, 80));
        QPalette palette12;
        palette12.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette12.setBrush(QPalette::Active, QPalette::Text, brush);
        palette12.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette12.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette12.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette12.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette12.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette12.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette12.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        grpSI->setPalette(palette12);
        grpSI->setFont(font);
        cmbBPSourceImpedance = new QComboBox(grpSI);
        cmbBPSourceImpedance->setObjectName(QString::fromUtf8("cmbBPSourceImpedance"));
        cmbBPSourceImpedance->setGeometry(QRect(80, 20, 130, 51));
        QPalette palette13;
        palette13.setBrush(QPalette::Active, QPalette::WindowText, brush3);
        palette13.setBrush(QPalette::Active, QPalette::Text, brush3);
        palette13.setBrush(QPalette::Active, QPalette::ButtonText, brush3);
        palette13.setBrush(QPalette::Inactive, QPalette::WindowText, brush3);
        palette13.setBrush(QPalette::Inactive, QPalette::Text, brush3);
        palette13.setBrush(QPalette::Inactive, QPalette::ButtonText, brush3);
        palette13.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette13.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette13.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        cmbBPSourceImpedance->setPalette(palette13);
        cmbBPSourceImpedance->setFont(font);
        butDriveRelay = new QPushButton(groupBox);
        butDriveRelay->setObjectName(QString::fromUtf8("butDriveRelay"));
        butDriveRelay->setGeometry(QRect(670, 110, 93, 71));
        QPalette palette14;
        palette14.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QLinearGradient gradient(0, 0, 0, 1);
        gradient.setSpread(QGradient::PadSpread);
        gradient.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient.setColorAt(0, QColor(246, 247, 250, 255));
        gradient.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush4(gradient);
        palette14.setBrush(QPalette::Active, QPalette::Button, brush4);
        palette14.setBrush(QPalette::Active, QPalette::Text, brush);
        palette14.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QLinearGradient gradient1(0, 0, 0, 1);
        gradient1.setSpread(QGradient::PadSpread);
        gradient1.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient1.setColorAt(0, QColor(246, 247, 250, 255));
        gradient1.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush5(gradient1);
        palette14.setBrush(QPalette::Active, QPalette::Base, brush5);
        QLinearGradient gradient2(0, 0, 0, 1);
        gradient2.setSpread(QGradient::PadSpread);
        gradient2.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient2.setColorAt(0, QColor(246, 247, 250, 255));
        gradient2.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush6(gradient2);
        palette14.setBrush(QPalette::Active, QPalette::Window, brush6);
        palette14.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QLinearGradient gradient3(0, 0, 0, 1);
        gradient3.setSpread(QGradient::PadSpread);
        gradient3.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient3.setColorAt(0, QColor(246, 247, 250, 255));
        gradient3.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush7(gradient3);
        palette14.setBrush(QPalette::Inactive, QPalette::Button, brush7);
        palette14.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette14.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        QLinearGradient gradient4(0, 0, 0, 1);
        gradient4.setSpread(QGradient::PadSpread);
        gradient4.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient4.setColorAt(0, QColor(246, 247, 250, 255));
        gradient4.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush8(gradient4);
        palette14.setBrush(QPalette::Inactive, QPalette::Base, brush8);
        QLinearGradient gradient5(0, 0, 0, 1);
        gradient5.setSpread(QGradient::PadSpread);
        gradient5.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient5.setColorAt(0, QColor(246, 247, 250, 255));
        gradient5.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush9(gradient5);
        palette14.setBrush(QPalette::Inactive, QPalette::Window, brush9);
        palette14.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        QLinearGradient gradient6(0, 0, 0, 1);
        gradient6.setSpread(QGradient::PadSpread);
        gradient6.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient6.setColorAt(0, QColor(246, 247, 250, 255));
        gradient6.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush10(gradient6);
        palette14.setBrush(QPalette::Disabled, QPalette::Button, brush10);
        palette14.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette14.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        QLinearGradient gradient7(0, 0, 0, 1);
        gradient7.setSpread(QGradient::PadSpread);
        gradient7.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient7.setColorAt(0, QColor(246, 247, 250, 255));
        gradient7.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush11(gradient7);
        palette14.setBrush(QPalette::Disabled, QPalette::Base, brush11);
        QLinearGradient gradient8(0, 0, 0, 1);
        gradient8.setSpread(QGradient::PadSpread);
        gradient8.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient8.setColorAt(0, QColor(246, 247, 250, 255));
        gradient8.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush12(gradient8);
        palette14.setBrush(QPalette::Disabled, QPalette::Window, brush12);
        butDriveRelay->setPalette(palette14);
        butDriveRelay->setFont(font);
        butDriveRelay->setStyleSheet(QString::fromUtf8(" QPushButton {\n"
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
        groupBox_4 = new QGroupBox(PtAppCardDrvRecev);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(10, 190, 781, 301));
        QPalette palette15;
        palette15.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette15.setBrush(QPalette::Active, QPalette::Text, brush);
        palette15.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette15.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette15.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette15.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette15.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette15.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette15.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        groupBox_4->setPalette(palette15);
        groupBox_4->setFont(font);
        grpReceiver1 = new QGroupBox(groupBox_4);
        grpReceiver1->setObjectName(QString::fromUtf8("grpReceiver1"));
        grpReceiver1->setGeometry(QRect(10, 20, 375, 171));
        QPalette palette16;
        palette16.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette16.setBrush(QPalette::Active, QPalette::Text, brush);
        palette16.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette16.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette16.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette16.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette16.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette16.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette16.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        grpReceiver1->setPalette(palette16);
        grpReceiver1->setFont(font);
        chkRece1HSHA = new QCheckBox(grpReceiver1);
        chkRece1HSHA->setObjectName(QString::fromUtf8("chkRece1HSHA"));
        chkRece1HSHA->setGeometry(QRect(10, 30, 81, 31));
        QPalette palette17;
        palette17.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette17.setBrush(QPalette::Active, QPalette::Text, brush);
        palette17.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette17.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette17.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette17.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette17.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette17.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette17.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        chkRece1HSHA->setPalette(palette17);
        chkRece1HSHA->setFont(font1);
        chkRece1HSHA->setStyleSheet(QString::fromUtf8(""));
        chkRece1HAAC = new QCheckBox(grpReceiver1);
        chkRece1HAAC->setObjectName(QString::fromUtf8("chkRece1HAAC"));
        chkRece1HAAC->setGeometry(QRect(140, 30, 81, 31));
        QPalette palette18;
        palette18.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette18.setBrush(QPalette::Active, QPalette::Text, brush);
        palette18.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette18.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette18.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette18.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette18.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette18.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette18.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        chkRece1HAAC->setPalette(palette18);
        chkRece1HAAC->setFont(font1);
        chkRece1HAAC->setStyleSheet(QString::fromUtf8(""));
        chkRece1RMSIN = new QCheckBox(grpReceiver1);
        chkRece1RMSIN->setObjectName(QString::fromUtf8("chkRece1RMSIN"));
        chkRece1RMSIN->setGeometry(QRect(270, 30, 81, 31));
        QPalette palette19;
        palette19.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette19.setBrush(QPalette::Active, QPalette::Text, brush);
        palette19.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette19.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette19.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette19.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette19.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette19.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette19.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        chkRece1RMSIN->setPalette(palette19);
        chkRece1RMSIN->setFont(font1);
        chkRece1RMSIN->setStyleSheet(QString::fromUtf8(""));
        chkRece1RMSGAIN = new QCheckBox(grpReceiver1);
        chkRece1RMSGAIN->setObjectName(QString::fromUtf8("chkRece1RMSGAIN"));
        chkRece1RMSGAIN->setGeometry(QRect(10, 80, 110, 31));
        QPalette palette20;
        palette20.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette20.setBrush(QPalette::Active, QPalette::Text, brush);
        palette20.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette20.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette20.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette20.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette20.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette20.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette20.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        chkRece1RMSGAIN->setPalette(palette20);
        chkRece1RMSGAIN->setFont(font1);
        chkRece1RMSGAIN->setStyleSheet(QString::fromUtf8(""));
        chkRece1HAIPSEL = new QCheckBox(grpReceiver1);
        chkRece1HAIPSEL->setObjectName(QString::fromUtf8("chkRece1HAIPSEL"));
        chkRece1HAIPSEL->setGeometry(QRect(270, 78, 101, 31));
        QPalette palette21;
        palette21.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette21.setBrush(QPalette::Active, QPalette::Text, brush);
        palette21.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette21.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette21.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette21.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette21.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette21.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette21.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        chkRece1HAIPSEL->setPalette(palette21);
        chkRece1HAIPSEL->setFont(font1);
        chkRece1HAIPSEL->setStyleSheet(QString::fromUtf8(""));
        chkRece1HSVI = new QCheckBox(grpReceiver1);
        chkRece1HSVI->setObjectName(QString::fromUtf8("chkRece1HSVI"));
        chkRece1HSVI->setGeometry(QRect(10, 130, 71, 31));
        QPalette palette22;
        palette22.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette22.setBrush(QPalette::Active, QPalette::Text, brush);
        palette22.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette22.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette22.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette22.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette22.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette22.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette22.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        chkRece1HSVI->setPalette(palette22);
        chkRece1HSVI->setFont(font1);
        chkRece1HSVI->setStyleSheet(QString::fromUtf8(""));
        cmbR1Coupling = new QComboBox(grpReceiver1);
        cmbR1Coupling->setObjectName(QString::fromUtf8("cmbR1Coupling"));
        cmbR1Coupling->setEnabled(true);
        cmbR1Coupling->setGeometry(QRect(258, 129, 101, 31));
        sizePolicy.setHeightForWidth(cmbR1Coupling->sizePolicy().hasHeightForWidth());
        cmbR1Coupling->setSizePolicy(sizePolicy);
        cmbR1Coupling->setMinimumSize(QSize(0, 30));
        cmbR1Coupling->setSizeIncrement(QSize(10, 10));
        cmbR1Coupling->setBaseSize(QSize(0, 10));
        QPalette palette23;
        palette23.setBrush(QPalette::Active, QPalette::WindowText, brush3);
        palette23.setBrush(QPalette::Active, QPalette::Text, brush3);
        palette23.setBrush(QPalette::Active, QPalette::ButtonText, brush3);
        palette23.setBrush(QPalette::Inactive, QPalette::WindowText, brush3);
        palette23.setBrush(QPalette::Inactive, QPalette::Text, brush3);
        palette23.setBrush(QPalette::Inactive, QPalette::ButtonText, brush3);
        palette23.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette23.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette23.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        cmbR1Coupling->setPalette(palette23);
        cmbR1Coupling->setFont(font2);
        label_5 = new QLabel(grpReceiver1);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(220, 140, 31, 10));
        QPalette palette24;
        palette24.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette24.setBrush(QPalette::Active, QPalette::Text, brush);
        palette24.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette24.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette24.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette24.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette24.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette24.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette24.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        label_5->setPalette(palette24);
        label_5->setFont(font);
        chkRece1RMSCAVG = new QCheckBox(grpReceiver1);
        chkRece1RMSCAVG->setObjectName(QString::fromUtf8("chkRece1RMSCAVG"));
        chkRece1RMSCAVG->setGeometry(QRect(140, 80, 110, 31));
        QPalette palette25;
        palette25.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette25.setBrush(QPalette::Active, QPalette::Text, brush);
        palette25.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette25.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette25.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette25.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette25.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette25.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette25.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        chkRece1RMSCAVG->setPalette(palette25);
        chkRece1RMSCAVG->setFont(font1);
        chkRece1RMSCAVG->setStyleSheet(QString::fromUtf8(""));
        label_7 = new QLabel(grpReceiver1);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(300, 50, 51, 20));
        QPalette palette26;
        palette26.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette26.setBrush(QPalette::Active, QPalette::Text, brush);
        palette26.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette26.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette26.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette26.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette26.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette26.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette26.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        label_7->setPalette(palette26);
        QFont font3;
        font3.setFamily(QString::fromUtf8("DejaVu Sans"));
        font3.setPointSize(9);
        font3.setBold(false);
        font3.setWeight(50);
        label_7->setFont(font3);
        label_8 = new QLabel(grpReceiver1);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(52, 100, 51, 20));
        QPalette palette27;
        palette27.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette27.setBrush(QPalette::Active, QPalette::Text, brush);
        palette27.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette27.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette27.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette27.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette27.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette27.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette27.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        label_8->setPalette(palette27);
        label_8->setFont(font3);
        label_9 = new QLabel(grpReceiver1);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(180, 100, 51, 20));
        QPalette palette28;
        palette28.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette28.setBrush(QPalette::Active, QPalette::Text, brush);
        palette28.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette28.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette28.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette28.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette28.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette28.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette28.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        label_9->setPalette(palette28);
        label_9->setFont(font3);
        label_10 = new QLabel(grpReceiver1);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(300, 100, 71, 20));
        QPalette palette29;
        palette29.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette29.setBrush(QPalette::Active, QPalette::Text, brush);
        palette29.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette29.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette29.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette29.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette29.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette29.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette29.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        label_10->setPalette(palette29);
        label_10->setFont(font3);
        label_15 = new QLabel(grpReceiver1);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(170, 50, 51, 20));
        QPalette palette30;
        palette30.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette30.setBrush(QPalette::Active, QPalette::Text, brush);
        palette30.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette30.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette30.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette30.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette30.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette30.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette30.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        label_15->setPalette(palette30);
        label_15->setFont(font3);
        grpReceiver2 = new QGroupBox(groupBox_4);
        grpReceiver2->setObjectName(QString::fromUtf8("grpReceiver2"));
        grpReceiver2->setGeometry(QRect(390, 20, 381, 171));
        QPalette palette31;
        palette31.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette31.setBrush(QPalette::Active, QPalette::Text, brush);
        palette31.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette31.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette31.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette31.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette31.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette31.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette31.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        grpReceiver2->setPalette(palette31);
        grpReceiver2->setFont(font);
        chkRece2HSHA = new QCheckBox(grpReceiver2);
        chkRece2HSHA->setObjectName(QString::fromUtf8("chkRece2HSHA"));
        chkRece2HSHA->setGeometry(QRect(10, 30, 81, 31));
        QPalette palette32;
        palette32.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette32.setBrush(QPalette::Active, QPalette::Text, brush);
        palette32.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette32.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette32.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette32.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette32.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette32.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette32.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        chkRece2HSHA->setPalette(palette32);
        chkRece2HSHA->setFont(font1);
        chkRece2HSHA->setStyleSheet(QString::fromUtf8(""));
        chkRece2HAAC = new QCheckBox(grpReceiver2);
        chkRece2HAAC->setObjectName(QString::fromUtf8("chkRece2HAAC"));
        chkRece2HAAC->setGeometry(QRect(270, 30, 81, 31));
        QPalette palette33;
        palette33.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette33.setBrush(QPalette::Active, QPalette::Text, brush);
        palette33.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette33.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette33.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette33.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette33.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette33.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette33.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        chkRece2HAAC->setPalette(palette33);
        chkRece2HAAC->setFont(font1);
        chkRece2HAAC->setStyleSheet(QString::fromUtf8(""));
        chkRece2RMSIN = new QCheckBox(grpReceiver2);
        chkRece2RMSIN->setObjectName(QString::fromUtf8("chkRece2RMSIN"));
        chkRece2RMSIN->setGeometry(QRect(10, 70, 81, 31));
        QPalette palette34;
        palette34.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette34.setBrush(QPalette::Active, QPalette::Text, brush);
        palette34.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette34.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette34.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette34.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette34.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette34.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette34.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        chkRece2RMSIN->setPalette(palette34);
        chkRece2RMSIN->setFont(font1);
        chkRece2RMSIN->setStyleSheet(QString::fromUtf8(""));
        chkRece2RMSGAIN = new QCheckBox(grpReceiver2);
        chkRece2RMSGAIN->setObjectName(QString::fromUtf8("chkRece2RMSGAIN"));
        chkRece2RMSGAIN->setGeometry(QRect(140, 71, 100, 31));
        QPalette palette35;
        palette35.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette35.setBrush(QPalette::Active, QPalette::Text, brush);
        palette35.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette35.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette35.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette35.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette35.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette35.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette35.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        chkRece2RMSGAIN->setPalette(palette35);
        chkRece2RMSGAIN->setFont(font1);
        chkRece2RMSGAIN->setStyleSheet(QString::fromUtf8(""));
        chkRece2HAIPSEL = new QCheckBox(grpReceiver2);
        chkRece2HAIPSEL->setObjectName(QString::fromUtf8("chkRece2HAIPSEL"));
        chkRece2HAIPSEL->setGeometry(QRect(10, 120, 101, 31));
        QPalette palette36;
        palette36.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette36.setBrush(QPalette::Active, QPalette::Text, brush);
        palette36.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette36.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette36.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette36.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette36.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette36.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette36.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        chkRece2HAIPSEL->setPalette(palette36);
        chkRece2HAIPSEL->setFont(font1);
        chkRece2HAIPSEL->setStyleSheet(QString::fromUtf8(""));
        chkRece2ICMEN = new QCheckBox(grpReceiver2);
        chkRece2ICMEN->setObjectName(QString::fromUtf8("chkRece2ICMEN"));
        chkRece2ICMEN->setGeometry(QRect(140, 30, 81, 31));
        QPalette palette37;
        palette37.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette37.setBrush(QPalette::Active, QPalette::Text, brush);
        palette37.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette37.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette37.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette37.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette37.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette37.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette37.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        chkRece2ICMEN->setPalette(palette37);
        chkRece2ICMEN->setFont(font1);
        chkRece2ICMEN->setStyleSheet(QString::fromUtf8(""));
        label_4 = new QLabel(grpReceiver2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(220, 140, 31, 10));
        QPalette palette38;
        palette38.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette38.setBrush(QPalette::Active, QPalette::Text, brush);
        palette38.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette38.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette38.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette38.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette38.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette38.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette38.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        label_4->setPalette(palette38);
        label_4->setFont(font);
        cmbR2Coupling = new QComboBox(grpReceiver2);
        cmbR2Coupling->setObjectName(QString::fromUtf8("cmbR2Coupling"));
        cmbR2Coupling->setEnabled(true);
        cmbR2Coupling->setGeometry(QRect(258, 129, 101, 31));
        sizePolicy.setHeightForWidth(cmbR2Coupling->sizePolicy().hasHeightForWidth());
        cmbR2Coupling->setSizePolicy(sizePolicy);
        cmbR2Coupling->setMinimumSize(QSize(0, 30));
        cmbR2Coupling->setSizeIncrement(QSize(10, 10));
        cmbR2Coupling->setBaseSize(QSize(0, 10));
        QPalette palette39;
        palette39.setBrush(QPalette::Active, QPalette::WindowText, brush3);
        palette39.setBrush(QPalette::Active, QPalette::Text, brush3);
        palette39.setBrush(QPalette::Active, QPalette::ButtonText, brush3);
        palette39.setBrush(QPalette::Inactive, QPalette::WindowText, brush3);
        palette39.setBrush(QPalette::Inactive, QPalette::Text, brush3);
        palette39.setBrush(QPalette::Inactive, QPalette::ButtonText, brush3);
        palette39.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette39.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette39.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        cmbR2Coupling->setPalette(palette39);
        cmbR2Coupling->setFont(font2);
        chkRece2RMSCAVG = new QCheckBox(grpReceiver2);
        chkRece2RMSCAVG->setObjectName(QString::fromUtf8("chkRece2RMSCAVG"));
        chkRece2RMSCAVG->setGeometry(QRect(270, 70, 120, 31));
        QPalette palette40;
        palette40.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette40.setBrush(QPalette::Active, QPalette::Text, brush);
        palette40.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette40.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette40.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette40.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette40.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette40.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette40.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        chkRece2RMSCAVG->setPalette(palette40);
        chkRece2RMSCAVG->setFont(font1);
        chkRece2RMSCAVG->setStyleSheet(QString::fromUtf8(""));
        label_11 = new QLabel(grpReceiver2);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(40, 140, 71, 20));
        QPalette palette41;
        palette41.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette41.setBrush(QPalette::Active, QPalette::Text, brush);
        palette41.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette41.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette41.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette41.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette41.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette41.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette41.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        label_11->setPalette(palette41);
        label_11->setFont(font3);
        label_12 = new QLabel(grpReceiver2);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(40, 90, 51, 20));
        QPalette palette42;
        palette42.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette42.setBrush(QPalette::Active, QPalette::Text, brush);
        palette42.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette42.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette42.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette42.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette42.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette42.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette42.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        label_12->setPalette(palette42);
        label_12->setFont(font3);
        label_13 = new QLabel(grpReceiver2);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(170, 90, 51, 20));
        QPalette palette43;
        palette43.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette43.setBrush(QPalette::Active, QPalette::Text, brush);
        palette43.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette43.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette43.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette43.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette43.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette43.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette43.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        label_13->setPalette(palette43);
        label_13->setFont(font3);
        label_14 = new QLabel(grpReceiver2);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(310, 90, 51, 20));
        QPalette palette44;
        palette44.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette44.setBrush(QPalette::Active, QPalette::Text, brush);
        palette44.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette44.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette44.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette44.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette44.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette44.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette44.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        label_14->setPalette(palette44);
        label_14->setFont(font3);
        label_16 = new QLabel(grpReceiver2);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(300, 50, 51, 20));
        QPalette palette45;
        palette45.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette45.setBrush(QPalette::Active, QPalette::Text, brush);
        palette45.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette45.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette45.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette45.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette45.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette45.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette45.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        label_16->setPalette(palette45);
        label_16->setFont(font3);
        grpICMGAIN = new QGroupBox(groupBox_4);
        grpICMGAIN->setObjectName(QString::fromUtf8("grpICMGAIN"));
        grpICMGAIN->setGeometry(QRect(10, 190, 411, 101));
        QPalette palette46;
        palette46.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette46.setBrush(QPalette::Active, QPalette::Text, brush);
        palette46.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette46.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette46.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette46.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette46.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette46.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette46.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        grpICMGAIN->setPalette(palette46);
        grpICMGAIN->setFont(font);
        cmbICMRange = new QComboBox(grpICMGAIN);
        cmbICMRange->setObjectName(QString::fromUtf8("cmbICMRange"));
        cmbICMRange->setEnabled(true);
        cmbICMRange->setGeometry(QRect(10, 40, 101, 51));
        sizePolicy.setHeightForWidth(cmbICMRange->sizePolicy().hasHeightForWidth());
        cmbICMRange->setSizePolicy(sizePolicy);
        cmbICMRange->setMinimumSize(QSize(0, 30));
        cmbICMRange->setSizeIncrement(QSize(10, 10));
        cmbICMRange->setBaseSize(QSize(0, 10));
        QPalette palette47;
        palette47.setBrush(QPalette::Active, QPalette::WindowText, brush3);
        palette47.setBrush(QPalette::Active, QPalette::Text, brush3);
        palette47.setBrush(QPalette::Active, QPalette::ButtonText, brush3);
        palette47.setBrush(QPalette::Inactive, QPalette::WindowText, brush3);
        palette47.setBrush(QPalette::Inactive, QPalette::Text, brush3);
        palette47.setBrush(QPalette::Inactive, QPalette::ButtonText, brush3);
        palette47.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette47.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette47.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        cmbICMRange->setPalette(palette47);
        cmbICMRange->setFont(font2);
        label_6 = new QLabel(grpICMGAIN);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(30, 20, 51, 20));
        QPalette palette48;
        palette48.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette48.setBrush(QPalette::Active, QPalette::Text, brush);
        palette48.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette48.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette48.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette48.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette48.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette48.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette48.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        label_6->setPalette(palette48);
        label_6->setFont(font);
        chkICMGAIN = new QCheckBox(grpICMGAIN);
        chkICMGAIN->setObjectName(QString::fromUtf8("chkICMGAIN"));
        chkICMGAIN->setGeometry(QRect(120, 42, 81, 31));
        QPalette palette49;
        palette49.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette49.setBrush(QPalette::Active, QPalette::Text, brush);
        palette49.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette49.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette49.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette49.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette49.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette49.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette49.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        chkICMGAIN->setPalette(palette49);
        chkICMGAIN->setFont(font1);
        chkICMGAIN->setStyleSheet(QString::fromUtf8(""));
        chkICMIASEL = new QCheckBox(grpICMGAIN);
        chkICMIASEL->setObjectName(QString::fromUtf8("chkICMIASEL"));
        chkICMIASEL->setGeometry(QRect(210, 40, 90, 31));
        QPalette palette50;
        palette50.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette50.setBrush(QPalette::Active, QPalette::Text, brush);
        palette50.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette50.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette50.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette50.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette50.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette50.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette50.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        chkICMIASEL->setPalette(palette50);
        chkICMIASEL->setFont(font1);
        chkICMIASEL->setStyleSheet(QString::fromUtf8(""));
        chkICMBCAPSEL = new QCheckBox(grpICMGAIN);
        chkICMBCAPSEL->setObjectName(QString::fromUtf8("chkICMBCAPSEL"));
        chkICMBCAPSEL->setGeometry(QRect(300, 40, 101, 31));
        QPalette palette51;
        palette51.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette51.setBrush(QPalette::Active, QPalette::Text, brush);
        palette51.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette51.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette51.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette51.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette51.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette51.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette51.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        chkICMBCAPSEL->setPalette(palette51);
        chkICMBCAPSEL->setFont(font1);
        chkICMBCAPSEL->setStyleSheet(QString::fromUtf8(""));
        label_17 = new QLabel(grpICMGAIN);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(330, 62, 90, 20));
        QPalette palette52;
        palette52.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette52.setBrush(QPalette::Active, QPalette::Text, brush);
        palette52.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette52.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette52.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette52.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette52.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette52.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette52.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        label_17->setPalette(palette52);
        label_17->setFont(font3);
        label_18 = new QLabel(grpICMGAIN);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(240, 60, 60, 31));
        QPalette palette53;
        palette53.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette53.setBrush(QPalette::Active, QPalette::Text, brush);
        palette53.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette53.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette53.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette53.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette53.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette53.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette53.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        label_18->setPalette(palette53);
        label_18->setFont(font3);
        label_19 = new QLabel(grpICMGAIN);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(144, 64, 60, 20));
        QPalette palette54;
        palette54.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette54.setBrush(QPalette::Active, QPalette::Text, brush);
        palette54.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette54.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette54.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette54.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette54.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette54.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette54.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        label_19->setPalette(palette54);
        label_19->setFont(font3);
        grpGeneral = new QGroupBox(groupBox_4);
        grpGeneral->setObjectName(QString::fromUtf8("grpGeneral"));
        grpGeneral->setGeometry(QRect(430, 190, 231, 101));
        QPalette palette55;
        palette55.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette55.setBrush(QPalette::Active, QPalette::Text, brush);
        palette55.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette55.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette55.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette55.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette55.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette55.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette55.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        grpGeneral->setPalette(palette55);
        grpGeneral->setFont(font);
        label_2 = new QLabel(grpGeneral);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(50, 14, 61, 20));
        QPalette palette56;
        palette56.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette56.setBrush(QPalette::Active, QPalette::Text, brush);
        palette56.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette56.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette56.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette56.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette56.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette56.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette56.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        label_2->setPalette(palette56);
        label_2->setFont(font);
        lineEdit = new QLineEdit(grpGeneral);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(38, 34, 81, 31));
        QPalette palette57;
        palette57.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush13(QColor(0, 0, 0, 255));
        brush13.setStyle(Qt::SolidPattern);
        palette57.setBrush(QPalette::Active, QPalette::Button, brush13);
        palette57.setBrush(QPalette::Active, QPalette::Text, brush);
        palette57.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette57.setBrush(QPalette::Active, QPalette::Base, brush13);
        palette57.setBrush(QPalette::Active, QPalette::Window, brush13);
        QBrush brush14(QColor(255, 255, 0, 255));
        brush14.setStyle(Qt::SolidPattern);
        palette57.setBrush(QPalette::Active, QPalette::Highlight, brush14);
        palette57.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette57.setBrush(QPalette::Inactive, QPalette::Button, brush13);
        palette57.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette57.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette57.setBrush(QPalette::Inactive, QPalette::Base, brush13);
        palette57.setBrush(QPalette::Inactive, QPalette::Window, brush13);
        palette57.setBrush(QPalette::Inactive, QPalette::Highlight, brush14);
        palette57.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette57.setBrush(QPalette::Disabled, QPalette::Button, brush13);
        palette57.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette57.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette57.setBrush(QPalette::Disabled, QPalette::Base, brush13);
        palette57.setBrush(QPalette::Disabled, QPalette::Window, brush13);
        palette57.setBrush(QPalette::Disabled, QPalette::Highlight, brush14);
        lineEdit->setPalette(palette57);
        QFont font4;
        font4.setBold(true);
        font4.setItalic(false);
        font4.setWeight(75);
        lineEdit->setFont(font4);
        label_3 = new QLabel(grpGeneral);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(144, 14, 41, 20));
        QPalette palette58;
        palette58.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette58.setBrush(QPalette::Active, QPalette::Text, brush);
        palette58.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette58.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette58.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette58.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette58.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette58.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette58.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        label_3->setPalette(palette58);
        label_3->setFont(font);
        lineEdit_2 = new QLineEdit(grpGeneral);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(128, 34, 81, 31));
        QPalette palette59;
        palette59.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette59.setBrush(QPalette::Active, QPalette::Button, brush13);
        palette59.setBrush(QPalette::Active, QPalette::Text, brush);
        palette59.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette59.setBrush(QPalette::Active, QPalette::Base, brush13);
        palette59.setBrush(QPalette::Active, QPalette::Window, brush13);
        palette59.setBrush(QPalette::Active, QPalette::Highlight, brush14);
        palette59.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette59.setBrush(QPalette::Inactive, QPalette::Button, brush13);
        palette59.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette59.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette59.setBrush(QPalette::Inactive, QPalette::Base, brush13);
        palette59.setBrush(QPalette::Inactive, QPalette::Window, brush13);
        palette59.setBrush(QPalette::Inactive, QPalette::Highlight, brush14);
        palette59.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette59.setBrush(QPalette::Disabled, QPalette::Button, brush13);
        palette59.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette59.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette59.setBrush(QPalette::Disabled, QPalette::Base, brush13);
        palette59.setBrush(QPalette::Disabled, QPalette::Window, brush13);
        palette59.setBrush(QPalette::Disabled, QPalette::Highlight, brush14);
        lineEdit_2->setPalette(palette59);
        lineEdit_2->setFont(font4);
        butAppRead = new QPushButton(grpGeneral);
        butAppRead->setObjectName(QString::fromUtf8("butAppRead"));
        butAppRead->setGeometry(QRect(31, 68, 93, 30));
        QPalette palette60;
        palette60.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QLinearGradient gradient9(0, 0, 0, 1);
        gradient9.setSpread(QGradient::PadSpread);
        gradient9.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient9.setColorAt(0, QColor(246, 247, 250, 255));
        gradient9.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush15(gradient9);
        palette60.setBrush(QPalette::Active, QPalette::Button, brush15);
        palette60.setBrush(QPalette::Active, QPalette::Text, brush);
        palette60.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QLinearGradient gradient10(0, 0, 0, 1);
        gradient10.setSpread(QGradient::PadSpread);
        gradient10.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient10.setColorAt(0, QColor(246, 247, 250, 255));
        gradient10.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush16(gradient10);
        palette60.setBrush(QPalette::Active, QPalette::Base, brush16);
        QLinearGradient gradient11(0, 0, 0, 1);
        gradient11.setSpread(QGradient::PadSpread);
        gradient11.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient11.setColorAt(0, QColor(246, 247, 250, 255));
        gradient11.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush17(gradient11);
        palette60.setBrush(QPalette::Active, QPalette::Window, brush17);
        palette60.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QLinearGradient gradient12(0, 0, 0, 1);
        gradient12.setSpread(QGradient::PadSpread);
        gradient12.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient12.setColorAt(0, QColor(246, 247, 250, 255));
        gradient12.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush18(gradient12);
        palette60.setBrush(QPalette::Inactive, QPalette::Button, brush18);
        palette60.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette60.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        QLinearGradient gradient13(0, 0, 0, 1);
        gradient13.setSpread(QGradient::PadSpread);
        gradient13.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient13.setColorAt(0, QColor(246, 247, 250, 255));
        gradient13.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush19(gradient13);
        palette60.setBrush(QPalette::Inactive, QPalette::Base, brush19);
        QLinearGradient gradient14(0, 0, 0, 1);
        gradient14.setSpread(QGradient::PadSpread);
        gradient14.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient14.setColorAt(0, QColor(246, 247, 250, 255));
        gradient14.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush20(gradient14);
        palette60.setBrush(QPalette::Inactive, QPalette::Window, brush20);
        palette60.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        QLinearGradient gradient15(0, 0, 0, 1);
        gradient15.setSpread(QGradient::PadSpread);
        gradient15.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient15.setColorAt(0, QColor(246, 247, 250, 255));
        gradient15.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush21(gradient15);
        palette60.setBrush(QPalette::Disabled, QPalette::Button, brush21);
        palette60.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette60.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        QLinearGradient gradient16(0, 0, 0, 1);
        gradient16.setSpread(QGradient::PadSpread);
        gradient16.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient16.setColorAt(0, QColor(246, 247, 250, 255));
        gradient16.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush22(gradient16);
        palette60.setBrush(QPalette::Disabled, QPalette::Base, brush22);
        QLinearGradient gradient17(0, 0, 0, 1);
        gradient17.setSpread(QGradient::PadSpread);
        gradient17.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient17.setColorAt(0, QColor(246, 247, 250, 255));
        gradient17.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush23(gradient17);
        palette60.setBrush(QPalette::Disabled, QPalette::Window, brush23);
        butAppRead->setPalette(palette60);
        butAppRead->setFont(font);
        butAppRead->setStyleSheet(QString::fromUtf8(" QPushButton {\n"
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
        butAppWrite = new QPushButton(grpGeneral);
        butAppWrite->setObjectName(QString::fromUtf8("butAppWrite"));
        butAppWrite->setGeometry(QRect(129, 68, 93, 30));
        QPalette palette61;
        palette61.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QLinearGradient gradient18(0, 0, 0, 1);
        gradient18.setSpread(QGradient::PadSpread);
        gradient18.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient18.setColorAt(0, QColor(246, 247, 250, 255));
        gradient18.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush24(gradient18);
        palette61.setBrush(QPalette::Active, QPalette::Button, brush24);
        palette61.setBrush(QPalette::Active, QPalette::Text, brush);
        palette61.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QLinearGradient gradient19(0, 0, 0, 1);
        gradient19.setSpread(QGradient::PadSpread);
        gradient19.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient19.setColorAt(0, QColor(246, 247, 250, 255));
        gradient19.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush25(gradient19);
        palette61.setBrush(QPalette::Active, QPalette::Base, brush25);
        QLinearGradient gradient20(0, 0, 0, 1);
        gradient20.setSpread(QGradient::PadSpread);
        gradient20.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient20.setColorAt(0, QColor(246, 247, 250, 255));
        gradient20.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush26(gradient20);
        palette61.setBrush(QPalette::Active, QPalette::Window, brush26);
        palette61.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QLinearGradient gradient21(0, 0, 0, 1);
        gradient21.setSpread(QGradient::PadSpread);
        gradient21.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient21.setColorAt(0, QColor(246, 247, 250, 255));
        gradient21.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush27(gradient21);
        palette61.setBrush(QPalette::Inactive, QPalette::Button, brush27);
        palette61.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette61.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        QLinearGradient gradient22(0, 0, 0, 1);
        gradient22.setSpread(QGradient::PadSpread);
        gradient22.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient22.setColorAt(0, QColor(246, 247, 250, 255));
        gradient22.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush28(gradient22);
        palette61.setBrush(QPalette::Inactive, QPalette::Base, brush28);
        QLinearGradient gradient23(0, 0, 0, 1);
        gradient23.setSpread(QGradient::PadSpread);
        gradient23.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient23.setColorAt(0, QColor(246, 247, 250, 255));
        gradient23.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush29(gradient23);
        palette61.setBrush(QPalette::Inactive, QPalette::Window, brush29);
        palette61.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        QLinearGradient gradient24(0, 0, 0, 1);
        gradient24.setSpread(QGradient::PadSpread);
        gradient24.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient24.setColorAt(0, QColor(246, 247, 250, 255));
        gradient24.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush30(gradient24);
        palette61.setBrush(QPalette::Disabled, QPalette::Button, brush30);
        palette61.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette61.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        QLinearGradient gradient25(0, 0, 0, 1);
        gradient25.setSpread(QGradient::PadSpread);
        gradient25.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient25.setColorAt(0, QColor(246, 247, 250, 255));
        gradient25.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush31(gradient25);
        palette61.setBrush(QPalette::Disabled, QPalette::Base, brush31);
        QLinearGradient gradient26(0, 0, 0, 1);
        gradient26.setSpread(QGradient::PadSpread);
        gradient26.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient26.setColorAt(0, QColor(246, 247, 250, 255));
        gradient26.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush32(gradient26);
        palette61.setBrush(QPalette::Disabled, QPalette::Window, brush32);
        butAppWrite->setPalette(palette61);
        butAppWrite->setFont(font);
        butAppWrite->setStyleSheet(QString::fromUtf8(" QPushButton {\n"
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
        butReceiveRelay = new QPushButton(groupBox_4);
        butReceiveRelay->setObjectName(QString::fromUtf8("butReceiveRelay"));
        butReceiveRelay->setGeometry(QRect(670, 210, 93, 71));
        QPalette palette62;
        palette62.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        QLinearGradient gradient27(0, 0, 0, 1);
        gradient27.setSpread(QGradient::PadSpread);
        gradient27.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient27.setColorAt(0, QColor(246, 247, 250, 255));
        gradient27.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush33(gradient27);
        palette62.setBrush(QPalette::Active, QPalette::Button, brush33);
        palette62.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette62.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        QLinearGradient gradient28(0, 0, 0, 1);
        gradient28.setSpread(QGradient::PadSpread);
        gradient28.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient28.setColorAt(0, QColor(246, 247, 250, 255));
        gradient28.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush34(gradient28);
        palette62.setBrush(QPalette::Active, QPalette::Base, brush34);
        QLinearGradient gradient29(0, 0, 0, 1);
        gradient29.setSpread(QGradient::PadSpread);
        gradient29.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient29.setColorAt(0, QColor(246, 247, 250, 255));
        gradient29.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush35(gradient29);
        palette62.setBrush(QPalette::Active, QPalette::Window, brush35);
        palette62.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        QLinearGradient gradient30(0, 0, 0, 1);
        gradient30.setSpread(QGradient::PadSpread);
        gradient30.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient30.setColorAt(0, QColor(246, 247, 250, 255));
        gradient30.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush36(gradient30);
        palette62.setBrush(QPalette::Inactive, QPalette::Button, brush36);
        palette62.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette62.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        QLinearGradient gradient31(0, 0, 0, 1);
        gradient31.setSpread(QGradient::PadSpread);
        gradient31.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient31.setColorAt(0, QColor(246, 247, 250, 255));
        gradient31.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush37(gradient31);
        palette62.setBrush(QPalette::Inactive, QPalette::Base, brush37);
        QLinearGradient gradient32(0, 0, 0, 1);
        gradient32.setSpread(QGradient::PadSpread);
        gradient32.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient32.setColorAt(0, QColor(246, 247, 250, 255));
        gradient32.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush38(gradient32);
        palette62.setBrush(QPalette::Inactive, QPalette::Window, brush38);
        palette62.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        QLinearGradient gradient33(0, 0, 0, 1);
        gradient33.setSpread(QGradient::PadSpread);
        gradient33.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient33.setColorAt(0, QColor(246, 247, 250, 255));
        gradient33.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush39(gradient33);
        palette62.setBrush(QPalette::Disabled, QPalette::Button, brush39);
        palette62.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette62.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        QLinearGradient gradient34(0, 0, 0, 1);
        gradient34.setSpread(QGradient::PadSpread);
        gradient34.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient34.setColorAt(0, QColor(246, 247, 250, 255));
        gradient34.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush40(gradient34);
        palette62.setBrush(QPalette::Disabled, QPalette::Base, brush40);
        QLinearGradient gradient35(0, 0, 0, 1);
        gradient35.setSpread(QGradient::PadSpread);
        gradient35.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient35.setColorAt(0, QColor(246, 247, 250, 255));
        gradient35.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush41(gradient35);
        palette62.setBrush(QPalette::Disabled, QPalette::Window, brush41);
        butReceiveRelay->setPalette(palette62);
        butReceiveRelay->setFont(font);
        butReceiveRelay->setStyleSheet(QString::fromUtf8(" QPushButton {\n"
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

        retranslateUi(PtAppCardDrvRecev);

        QMetaObject::connectSlotsByName(PtAppCardDrvRecev);
    } // setupUi

    void retranslateUi(QWidget *PtAppCardDrvRecev)
    {
        PtAppCardDrvRecev->setWindowTitle(QApplication::translate("PtAppCardDrvRecev", "PtAppCardDrvRecev", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("PtAppCardDrvRecev", "Drive Relays", 0, QApplication::UnicodeUTF8));
        groupBox_5->setTitle(QApplication::translate("PtAppCardDrvRecev", "Drive Source (0x16)", 0, QApplication::UnicodeUTF8));
        chkSRCN->setText(QApplication::translate("PtAppCardDrvRecev", "SRCN", 0, QApplication::UnicodeUTF8));
        cmbIRS->clear();
        cmbIRS->insertItems(0, QStringList()
         << QApplication::translate("PtAppCardDrvRecev", "50 mA", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PtAppCardDrvRecev", "500 uA", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PtAppCardDrvRecev", "5 uA", 0, QApplication::UnicodeUTF8)
        );
        chkVIS->setText(QApplication::translate("PtAppCardDrvRecev", "I/V", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("PtAppCardDrvRecev", "IRS:", 0, QApplication::UnicodeUTF8));
        grpSource->setTitle(QApplication::translate("PtAppCardDrvRecev", "Source Selection (0x34)", 0, QApplication::UnicodeUTF8));
        cmbSourceSelection->clear();
        cmbSourceSelection->insertItems(0, QStringList()
         << QApplication::translate("PtAppCardDrvRecev", "INT - Drive+Receive1+Receive2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PtAppCardDrvRecev", "INT - Drive + Receive1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PtAppCardDrvRecev", "INT - Drive + Receive2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PtAppCardDrvRecev", "NORMAL", 0, QApplication::UnicodeUTF8)
        );
        groupBox_2->setTitle(QApplication::translate("PtAppCardDrvRecev", "Drive Recive Gain (0x48)", 0, QApplication::UnicodeUTF8));
        cmbVISelection->clear();
        cmbVISelection->insertItems(0, QStringList()
         << QApplication::translate("PtAppCardDrvRecev", "0.5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PtAppCardDrvRecev", "1.5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PtAppCardDrvRecev", "3.5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PtAppCardDrvRecev", "7.0", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PtAppCardDrvRecev", "13.0", 0, QApplication::UnicodeUTF8)
        );
        chkSlotOffsetEN->setText(QApplication::translate("PtAppCardDrvRecev", "SLOFFSET_EN", 0, QApplication::UnicodeUTF8));
        grpSI->setTitle(QApplication::translate("PtAppCardDrvRecev", "BackPanel - (0x26)", 0, QApplication::UnicodeUTF8));
        cmbBPSourceImpedance->clear();
        cmbBPSourceImpedance->insertItems(0, QStringList()
         << QApplication::translate("PtAppCardDrvRecev", "0 E", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PtAppCardDrvRecev", "10 E", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PtAppCardDrvRecev", "20 E", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PtAppCardDrvRecev", "50 E", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PtAppCardDrvRecev", "100 E", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PtAppCardDrvRecev", "200 E", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PtAppCardDrvRecev", "500 E", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PtAppCardDrvRecev", "1K", 0, QApplication::UnicodeUTF8)
        );
        butDriveRelay->setText(QApplication::translate("PtAppCardDrvRecev", "Drive", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("PtAppCardDrvRecev", "Receive Relays", 0, QApplication::UnicodeUTF8));
        grpReceiver1->setTitle(QApplication::translate("PtAppCardDrvRecev", "Receiver1(0x36)", 0, QApplication::UnicodeUTF8));
        chkRece1HSHA->setText(QApplication::translate("PtAppCardDrvRecev", "HS/HA", 0, QApplication::UnicodeUTF8));
        chkRece1HAAC->setText(QApplication::translate("PtAppCardDrvRecev", "HAAC", 0, QApplication::UnicodeUTF8));
        chkRece1RMSIN->setText(QApplication::translate("PtAppCardDrvRecev", "RMSIN", 0, QApplication::UnicodeUTF8));
        chkRece1RMSGAIN->setText(QApplication::translate("PtAppCardDrvRecev", "RMSGAIN", 0, QApplication::UnicodeUTF8));
        chkRece1HAIPSEL->setText(QApplication::translate("PtAppCardDrvRecev", "HAIPSEL", 0, QApplication::UnicodeUTF8));
        chkRece1HSVI->setText(QApplication::translate("PtAppCardDrvRecev", "HS/VI", 0, QApplication::UnicodeUTF8));
        cmbR1Coupling->clear();
        cmbR1Coupling->insertItems(0, QStringList()
         << QApplication::translate("PtAppCardDrvRecev", "DC", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PtAppCardDrvRecev", "AC", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PtAppCardDrvRecev", "GND", 0, QApplication::UnicodeUTF8)
        );
        label_5->setText(QApplication::translate("PtAppCardDrvRecev", "HSC", 0, QApplication::UnicodeUTF8));
        chkRece1RMSCAVG->setText(QApplication::translate("PtAppCardDrvRecev", "RMSCAVG", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("PtAppCardDrvRecev", "AC/DC", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("PtAppCardDrvRecev", "X1/X2 ", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("PtAppCardDrvRecev", "10/1 uF", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("PtAppCardDrvRecev", "Diff/Pseudo", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("PtAppCardDrvRecev", "DC/RMS", 0, QApplication::UnicodeUTF8));
        grpReceiver2->setTitle(QApplication::translate("PtAppCardDrvRecev", "Receiver2(0x38)", 0, QApplication::UnicodeUTF8));
        chkRece2HSHA->setText(QApplication::translate("PtAppCardDrvRecev", "HS/HA", 0, QApplication::UnicodeUTF8));
        chkRece2HAAC->setText(QApplication::translate("PtAppCardDrvRecev", "HAAC", 0, QApplication::UnicodeUTF8));
        chkRece2RMSIN->setText(QApplication::translate("PtAppCardDrvRecev", "RMSIN", 0, QApplication::UnicodeUTF8));
        chkRece2RMSGAIN->setText(QApplication::translate("PtAppCardDrvRecev", "RMSGAIN", 0, QApplication::UnicodeUTF8));
        chkRece2HAIPSEL->setText(QApplication::translate("PtAppCardDrvRecev", "HAIPSEL", 0, QApplication::UnicodeUTF8));
        chkRece2ICMEN->setText(QApplication::translate("PtAppCardDrvRecev", "ICMEN", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("PtAppCardDrvRecev", "HSC", 0, QApplication::UnicodeUTF8));
        cmbR2Coupling->clear();
        cmbR2Coupling->insertItems(0, QStringList()
         << QApplication::translate("PtAppCardDrvRecev", "DC", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PtAppCardDrvRecev", "AC", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PtAppCardDrvRecev", "GND", 0, QApplication::UnicodeUTF8)
        );
        chkRece2RMSCAVG->setText(QApplication::translate("PtAppCardDrvRecev", "RMSCAVG", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("PtAppCardDrvRecev", "Diff/Pseudo", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("PtAppCardDrvRecev", "AC/DC", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("PtAppCardDrvRecev", "X1/X2 ", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("PtAppCardDrvRecev", "10/1 uF", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("PtAppCardDrvRecev", "DC/RMS", 0, QApplication::UnicodeUTF8));
        grpICMGAIN->setTitle(QApplication::translate("PtAppCardDrvRecev", "ICM Range / Gain (0x3A)", 0, QApplication::UnicodeUTF8));
        cmbICMRange->clear();
        cmbICMRange->insertItems(0, QStringList()
         << QApplication::translate("PtAppCardDrvRecev", "10E", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PtAppCardDrvRecev", "100E", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PtAppCardDrvRecev", "1KE", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PtAppCardDrvRecev", "10KE", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PtAppCardDrvRecev", "100KE", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PtAppCardDrvRecev", "1ME", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PtAppCardDrvRecev", "RESERVED1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PtAppCardDrvRecev", "RESERVED2", 0, QApplication::UnicodeUTF8)
        );
        label_6->setText(QApplication::translate("PtAppCardDrvRecev", "Range", 0, QApplication::UnicodeUTF8));
        chkICMGAIN->setText(QApplication::translate("PtAppCardDrvRecev", "GAIN", 0, QApplication::UnicodeUTF8));
        chkICMIASEL->setText(QApplication::translate("PtAppCardDrvRecev", "IASEL", 0, QApplication::UnicodeUTF8));
        chkICMBCAPSEL->setText(QApplication::translate("PtAppCardDrvRecev", "BCAPSEL", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("PtAppCardDrvRecev", "0.1/0.001 uF", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("PtAppCardDrvRecev", "OP07/\n"
"LT1012", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("PtAppCardDrvRecev", "div1/div2 ", 0, QApplication::UnicodeUTF8));
        grpGeneral->setTitle(QApplication::translate("PtAppCardDrvRecev", "General", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("PtAppCardDrvRecev", "Address:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("PtAppCardDrvRecev", "Data:", 0, QApplication::UnicodeUTF8));
        butAppRead->setText(QApplication::translate("PtAppCardDrvRecev", "Read", 0, QApplication::UnicodeUTF8));
        butAppWrite->setText(QApplication::translate("PtAppCardDrvRecev", "Write", 0, QApplication::UnicodeUTF8));
        butReceiveRelay->setText(QApplication::translate("PtAppCardDrvRecev", "Drive", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class PtAppCardDrvRecev: public Ui_PtAppCardDrvRecev {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PTAPPCARDDRVRECEV_H
