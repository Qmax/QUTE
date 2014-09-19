/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created: Tue Sep 9 12:03:22 2014
**      by: Qt User Interface Compiler version 4.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

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

class Ui_Widget
{
public:
    QGroupBox *grpGeneral;
    QLabel *lblAddress;
    QPushButton *butRead;
    QLabel *lblData;
    QPushButton *butWrite;
    QLineEdit *edAddress;
    QLineEdit *edData;
    QGroupBox *groupBox;
    QLabel *lblDrRanve;
    QLineEdit *edAddress_2;
    QLabel *lblDrRanve_2;
    QLineEdit *edAddress_6;
    QLineEdit *edAddress_3;
    QLabel *lblDrRanve_3;
    QRadioButton *optDifferential;
    QRadioButton *optPseudo;
    QGroupBox *grpReceivers;
    QCheckBox *chkReceiver1;
    QCheckBox *chkReceiver2;
    QLabel *lblADC1;
    QLabel *lblADC2;
    QCheckBox *chkP1V;
    QCheckBox *chkP2V;
    QFrame *line;
    QPushButton *butDCDrive;
    QCheckBox *chkDDSFreq;
    QGroupBox *grpSettings;
    QLabel *lblSrcImped_4;
    QComboBox *cmbResistance;
    QComboBox *cmbCapcitance;
    QLabel *lblSrcImped_2;
    QComboBox *cmbInductance;
    QLabel *lblSrcImped_3;
    QCheckBox *checkBox;
    QComboBox *cmbICMRange;
    QLabel *label_6;
    QGroupBox *groupBox_2;
    QLabel *lblSrcImped_5;
    QLabel *lblSrcImped_6;
    QLabel *lblSrcImped_7;
    QLabel *lblSrcImped_8;
    QGroupBox *groupBox_3;
    QGroupBox *groupBox_4;
    QCheckBox *chkCapSet;
    QCheckBox *chkPOTSel;
    QCheckBox *chkDivSel;
    QPushButton *butMeasure;
    QPushButton *butStop;
    QRadioButton *optResistance;
    QRadioButton *optCapacitance;
    QRadioButton *optInductance;
    QLabel *lblResistance;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(800, 600);
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
        Widget->setPalette(palette);
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        Widget->setFont(font);
        grpGeneral = new QGroupBox(Widget);
        grpGeneral->setObjectName(QString::fromUtf8("grpGeneral"));
        grpGeneral->setGeometry(QRect(20, 0, 271, 161));
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
        lblAddress->setGeometry(QRect(20, 26, 56, 16));
        lblAddress->setFont(font1);
        butRead = new QPushButton(grpGeneral);
        butRead->setObjectName(QString::fromUtf8("butRead"));
        butRead->setGeometry(QRect(80, 110, 75, 41));
        butRead->setFont(font1);
        lblData = new QLabel(grpGeneral);
        lblData->setObjectName(QString::fromUtf8("lblData"));
        lblData->setGeometry(QRect(20, 70, 36, 16));
        lblData->setFont(font1);
        butWrite = new QPushButton(grpGeneral);
        butWrite->setObjectName(QString::fromUtf8("butWrite"));
        butWrite->setGeometry(QRect(160, 110, 75, 41));
        butWrite->setFont(font1);
        edAddress = new QLineEdit(grpGeneral);
        edAddress->setObjectName(QString::fromUtf8("edAddress"));
        edAddress->setGeometry(QRect(90, 15, 161, 41));
        edAddress->setFont(font1);
        edData = new QLineEdit(grpGeneral);
        edData->setObjectName(QString::fromUtf8("edData"));
        edData->setGeometry(QRect(90, 60, 161, 41));
        edData->setFont(font1);
        groupBox = new QGroupBox(Widget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(20, 160, 271, 360));
        groupBox->setFont(font1);
        lblDrRanve = new QLabel(groupBox);
        lblDrRanve->setObjectName(QString::fromUtf8("lblDrRanve"));
        lblDrRanve->setGeometry(QRect(30, 30, 71, 41));
        lblDrRanve->setFont(font1);
        edAddress_2 = new QLineEdit(groupBox);
        edAddress_2->setObjectName(QString::fromUtf8("edAddress_2"));
        edAddress_2->setGeometry(QRect(120, 30, 91, 41));
        edAddress_2->setFont(font1);
        lblDrRanve_2 = new QLabel(groupBox);
        lblDrRanve_2->setObjectName(QString::fromUtf8("lblDrRanve_2"));
        lblDrRanve_2->setGeometry(QRect(10, 323, 131, 20));
        QFont font2;
        font2.setFamily(QString::fromUtf8("DejaVu Sans"));
        font2.setPointSize(11);
        font2.setBold(false);
        font2.setWeight(50);
        lblDrRanve_2->setFont(font2);
        edAddress_6 = new QLineEdit(groupBox);
        edAddress_6->setObjectName(QString::fromUtf8("edAddress_6"));
        edAddress_6->setGeometry(QRect(140, 320, 111, 31));
        edAddress_6->setFont(font1);
        edAddress_3 = new QLineEdit(groupBox);
        edAddress_3->setObjectName(QString::fromUtf8("edAddress_3"));
        edAddress_3->setGeometry(QRect(120, 80, 111, 41));
        edAddress_3->setFont(font1);
        lblDrRanve_3 = new QLabel(groupBox);
        lblDrRanve_3->setObjectName(QString::fromUtf8("lblDrRanve_3"));
        lblDrRanve_3->setGeometry(QRect(20, 90, 91, 20));
        lblDrRanve_3->setFont(font1);
        optDifferential = new QRadioButton(groupBox);
        optDifferential->setObjectName(QString::fromUtf8("optDifferential"));
        optDifferential->setGeometry(QRect(150, 180, 111, 51));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        optDifferential->setPalette(palette1);
        QFont font3;
        font3.setBold(false);
        font3.setItalic(false);
        font3.setWeight(50);
        optDifferential->setFont(font3);
        optDifferential->setFocusPolicy(Qt::NoFocus);
        optDifferential->setStyleSheet(QString::fromUtf8("QRadioButton{\n"
"font: 14px;\n"
"color:white\n"
"}\n"
"\n"
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
"     }\n"
""));
        optPseudo = new QRadioButton(groupBox);
        optPseudo->setObjectName(QString::fromUtf8("optPseudo"));
        optPseudo->setGeometry(QRect(150, 220, 111, 51));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        optPseudo->setPalette(palette2);
        optPseudo->setFont(font3);
        optPseudo->setFocusPolicy(Qt::NoFocus);
        optPseudo->setStyleSheet(QString::fromUtf8("QRadioButton{\n"
"font: 14px;\n"
"color:white\n"
"}\n"
"\n"
"  QRadioButton::indicator {\n"
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
"     }\n"
""));
        grpReceivers = new QGroupBox(groupBox);
        grpReceivers->setObjectName(QString::fromUtf8("grpReceivers"));
        grpReceivers->setGeometry(QRect(10, 170, 131, 111));
        chkReceiver1 = new QCheckBox(grpReceivers);
        chkReceiver1->setObjectName(QString::fromUtf8("chkReceiver1"));
        chkReceiver1->setGeometry(QRect(10, 30, 111, 41));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        chkReceiver1->setPalette(palette3);
        chkReceiver1->setFont(font3);
        chkReceiver1->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
"font: 14px;\n"
"color:white\n"
"\n"
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
        chkReceiver2 = new QCheckBox(grpReceivers);
        chkReceiver2->setObjectName(QString::fromUtf8("chkReceiver2"));
        chkReceiver2->setGeometry(QRect(10, 70, 111, 41));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Active, QPalette::Text, brush);
        palette4.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        chkReceiver2->setPalette(palette4);
        chkReceiver2->setFont(font3);
        chkReceiver2->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
"font: 14px;\n"
"color:white\n"
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
        lblADC1 = new QLabel(groupBox);
        lblADC1->setObjectName(QString::fromUtf8("lblADC1"));
        lblADC1->setGeometry(QRect(20, 290, 91, 20));
        lblADC2 = new QLabel(groupBox);
        lblADC2->setObjectName(QString::fromUtf8("lblADC2"));
        lblADC2->setGeometry(QRect(150, 290, 91, 20));
        chkP1V = new QCheckBox(groupBox);
        chkP1V->setObjectName(QString::fromUtf8("chkP1V"));
        chkP1V->setGeometry(QRect(20, 129, 81, 25));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Active, QPalette::Text, brush);
        palette5.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        chkP1V->setPalette(palette5);
        chkP1V->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
"font: 14px;\n"
"color:white\n"
"\n"
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
        chkP2V = new QCheckBox(groupBox);
        chkP2V->setObjectName(QString::fromUtf8("chkP2V"));
        chkP2V->setGeometry(QRect(100, 130, 81, 25));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette6.setBrush(QPalette::Active, QPalette::Text, brush);
        palette6.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        chkP2V->setPalette(palette6);
        chkP2V->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
"font: 14px;\n"
"color:white\n"
"\n"
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
        line = new QFrame(groupBox);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(0, 150, 271, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        butDCDrive = new QPushButton(groupBox);
        butDCDrive->setObjectName(QString::fromUtf8("butDCDrive"));
        butDCDrive->setGeometry(QRect(216, 30, 51, 41));
        chkDDSFreq = new QCheckBox(groupBox);
        chkDDSFreq->setObjectName(QString::fromUtf8("chkDDSFreq"));
        chkDDSFreq->setGeometry(QRect(171, 130, 91, 25));
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette7.setBrush(QPalette::Active, QPalette::Text, brush);
        palette7.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette7.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette7.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette7.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        chkDDSFreq->setPalette(palette7);
        chkDDSFreq->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
"font: 14px;\n"
"color:white\n"
"\n"
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
        grpSettings = new QGroupBox(Widget);
        grpSettings->setObjectName(QString::fromUtf8("grpSettings"));
        grpSettings->setGeometry(QRect(309, 0, 474, 131));
        grpSettings->setFont(font1);
        lblSrcImped_4 = new QLabel(grpSettings);
        lblSrcImped_4->setObjectName(QString::fromUtf8("lblSrcImped_4"));
        lblSrcImped_4->setGeometry(QRect(40, 20, 101, 20));
        lblSrcImped_4->setFont(font1);
        cmbResistance = new QComboBox(grpSettings);
        cmbResistance->setObjectName(QString::fromUtf8("cmbResistance"));
        cmbResistance->setGeometry(QRect(40, 40, 121, 51));
        cmbResistance->setFont(font1);
        cmbCapcitance = new QComboBox(grpSettings);
        cmbCapcitance->setObjectName(QString::fromUtf8("cmbCapcitance"));
        cmbCapcitance->setGeometry(QRect(190, 40, 121, 51));
        cmbCapcitance->setFont(font1);
        lblSrcImped_2 = new QLabel(grpSettings);
        lblSrcImped_2->setObjectName(QString::fromUtf8("lblSrcImped_2"));
        lblSrcImped_2->setGeometry(QRect(190, 20, 101, 20));
        lblSrcImped_2->setFont(font1);
        cmbInductance = new QComboBox(grpSettings);
        cmbInductance->setObjectName(QString::fromUtf8("cmbInductance"));
        cmbInductance->setGeometry(QRect(340, 40, 111, 51));
        cmbInductance->setFont(font1);
        lblSrcImped_3 = new QLabel(grpSettings);
        lblSrcImped_3->setObjectName(QString::fromUtf8("lblSrcImped_3"));
        lblSrcImped_3->setGeometry(QRect(340, 20, 111, 20));
        lblSrcImped_3->setFont(font1);
        checkBox = new QCheckBox(grpSettings);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(30, 100, 141, 25));
        checkBox->setFont(font1);
        cmbICMRange = new QComboBox(grpSettings);
        cmbICMRange->setObjectName(QString::fromUtf8("cmbICMRange"));
        cmbICMRange->setEnabled(true);
        cmbICMRange->setGeometry(QRect(302, 95, 101, 31));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(10);
        sizePolicy.setHeightForWidth(cmbICMRange->sizePolicy().hasHeightForWidth());
        cmbICMRange->setSizePolicy(sizePolicy);
        cmbICMRange->setMinimumSize(QSize(0, 30));
        cmbICMRange->setSizeIncrement(QSize(10, 10));
        cmbICMRange->setBaseSize(QSize(0, 10));
        QPalette palette8;
        palette8.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        palette8.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette8.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette8.setBrush(QPalette::Active, QPalette::Base, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        palette8.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette8.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette8.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette8.setBrush(QPalette::Disabled, QPalette::WindowText, brush6);
        palette8.setBrush(QPalette::Disabled, QPalette::Text, brush6);
        palette8.setBrush(QPalette::Disabled, QPalette::ButtonText, brush6);
        palette8.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        cmbICMRange->setPalette(palette8);
        cmbICMRange->setFont(font1);
        label_6 = new QLabel(grpSettings);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(240, 100, 61, 20));
        QPalette palette9;
        palette9.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette9.setBrush(QPalette::Active, QPalette::Text, brush);
        palette9.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette9.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette9.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette9.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        QBrush brush8(QColor(0, 0, 255, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette9.setBrush(QPalette::Disabled, QPalette::WindowText, brush8);
        palette9.setBrush(QPalette::Disabled, QPalette::Text, brush8);
        palette9.setBrush(QPalette::Disabled, QPalette::ButtonText, brush8);
        label_6->setPalette(palette9);
        QFont font4;
        font4.setFamily(QString::fromUtf8("DejaVu Sans"));
        font4.setBold(false);
        font4.setWeight(50);
        label_6->setFont(font4);
        groupBox_2 = new QGroupBox(Widget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(309, 130, 474, 91));
        groupBox_2->setFont(font1);
        lblSrcImped_5 = new QLabel(groupBox_2);
        lblSrcImped_5->setObjectName(QString::fromUtf8("lblSrcImped_5"));
        lblSrcImped_5->setGeometry(QRect(140, 20, 101, 20));
        lblSrcImped_5->setFont(font1);
        lblSrcImped_6 = new QLabel(groupBox_2);
        lblSrcImped_6->setObjectName(QString::fromUtf8("lblSrcImped_6"));
        lblSrcImped_6->setGeometry(QRect(250, 20, 101, 20));
        lblSrcImped_6->setFont(font1);
        lblSrcImped_7 = new QLabel(groupBox_2);
        lblSrcImped_7->setObjectName(QString::fromUtf8("lblSrcImped_7"));
        lblSrcImped_7->setGeometry(QRect(360, 20, 101, 20));
        lblSrcImped_7->setFont(font1);
        lblSrcImped_8 = new QLabel(groupBox_2);
        lblSrcImped_8->setObjectName(QString::fromUtf8("lblSrcImped_8"));
        lblSrcImped_8->setGeometry(QRect(40, 20, 81, 20));
        lblSrcImped_8->setFont(font1);
        groupBox_3 = new QGroupBox(Widget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(489, 220, 294, 300));
        groupBox_3->setFont(font1);
        groupBox_4 = new QGroupBox(Widget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(310, 220, 171, 301));
        groupBox_4->setFont(font1);
        chkCapSet = new QCheckBox(groupBox_4);
        chkCapSet->setObjectName(QString::fromUtf8("chkCapSet"));
        chkCapSet->setGeometry(QRect(17, 20, 141, 41));
        QPalette palette10;
        palette10.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette10.setBrush(QPalette::Active, QPalette::Text, brush);
        palette10.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette10.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette10.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette10.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette10.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette10.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette10.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        chkCapSet->setPalette(palette10);
        chkCapSet->setFont(font3);
        chkCapSet->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
"font: 14px;\n"
"color:white\n"
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
        chkPOTSel = new QCheckBox(groupBox_4);
        chkPOTSel->setObjectName(QString::fromUtf8("chkPOTSel"));
        chkPOTSel->setGeometry(QRect(15, 60, 141, 41));
        QPalette palette11;
        palette11.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette11.setBrush(QPalette::Active, QPalette::Text, brush);
        palette11.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette11.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette11.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette11.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette11.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette11.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette11.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        chkPOTSel->setPalette(palette11);
        chkPOTSel->setFont(font3);
        chkPOTSel->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
"font: 14px;\n"
"color:white\n"
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
        chkDivSel = new QCheckBox(groupBox_4);
        chkDivSel->setObjectName(QString::fromUtf8("chkDivSel"));
        chkDivSel->setGeometry(QRect(15, 100, 141, 41));
        QPalette palette12;
        palette12.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette12.setBrush(QPalette::Active, QPalette::Text, brush);
        palette12.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette12.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette12.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette12.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette12.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette12.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette12.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        chkDivSel->setPalette(palette12);
        chkDivSel->setFont(font3);
        chkDivSel->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
"font: 14px;\n"
"color:white\n"
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
        butMeasure = new QPushButton(groupBox_4);
        butMeasure->setObjectName(QString::fromUtf8("butMeasure"));
        butMeasure->setGeometry(QRect(10, 150, 91, 51));
        butMeasure->setFont(font1);
        butStop = new QPushButton(groupBox_4);
        butStop->setObjectName(QString::fromUtf8("butStop"));
        butStop->setGeometry(QRect(10, 210, 91, 51));
        butStop->setFont(font1);
        optResistance = new QRadioButton(groupBox_4);
        optResistance->setObjectName(QString::fromUtf8("optResistance"));
        optResistance->setGeometry(QRect(110, 130, 51, 51));
        optResistance->setFont(font3);
        optResistance->setFocusPolicy(Qt::NoFocus);
        optResistance->setStyleSheet(QString::fromUtf8("QRadioButton{\n"
"font: 14px;\n"
"color:white\n"
"}\n"
"\n"
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
"     }\n"
""));
        optCapacitance = new QRadioButton(groupBox_4);
        optCapacitance->setObjectName(QString::fromUtf8("optCapacitance"));
        optCapacitance->setGeometry(QRect(110, 170, 51, 51));
        optCapacitance->setFont(font3);
        optCapacitance->setFocusPolicy(Qt::NoFocus);
        optCapacitance->setStyleSheet(QString::fromUtf8("QRadioButton{\n"
"font: 14px;\n"
"color:white\n"
"}\n"
"\n"
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
"     }\n"
""));
        optInductance = new QRadioButton(groupBox_4);
        optInductance->setObjectName(QString::fromUtf8("optInductance"));
        optInductance->setGeometry(QRect(110, 210, 51, 51));
        optInductance->setFont(font3);
        optInductance->setFocusPolicy(Qt::NoFocus);
        optInductance->setStyleSheet(QString::fromUtf8("QRadioButton{\n"
"font: 14px;\n"
"color:white\n"
"}\n"
"\n"
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
"     }\n"
""));
        lblResistance = new QLabel(groupBox_4);
        lblResistance->setObjectName(QString::fromUtf8("lblResistance"));
        lblResistance->setGeometry(QRect(0, 270, 171, 20));
        QFont font5;
        font5.setPointSize(10);
        font5.setBold(true);
        font5.setWeight(75);
        lblResistance->setFont(font5);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "ICM", 0, QApplication::UnicodeUTF8));
        grpGeneral->setTitle(QApplication::translate("Widget", "General", 0, QApplication::UnicodeUTF8));
        lblAddress->setText(QApplication::translate("Widget", "Address :", 0, QApplication::UnicodeUTF8));
        butRead->setText(QApplication::translate("Widget", "Read", 0, QApplication::UnicodeUTF8));
        lblData->setText(QApplication::translate("Widget", "Data :", 0, QApplication::UnicodeUTF8));
        butWrite->setText(QApplication::translate("Widget", "Write", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("Widget", "Settings", 0, QApplication::UnicodeUTF8));
        lblDrRanve->setText(QApplication::translate("Widget", "Force \n"
"Voltage", 0, QApplication::UnicodeUTF8));
        lblDrRanve_2->setText(QApplication::translate("Widget", "Average Samples", 0, QApplication::UnicodeUTF8));
        lblDrRanve_3->setText(QApplication::translate("Widget", "Frequency", 0, QApplication::UnicodeUTF8));
        optDifferential->setText(QApplication::translate("Widget", "Differntial", 0, QApplication::UnicodeUTF8));
        optPseudo->setText(QApplication::translate("Widget", "Pseudo", 0, QApplication::UnicodeUTF8));
        grpReceivers->setTitle(QApplication::translate("Widget", "Receivers", 0, QApplication::UnicodeUTF8));
        chkReceiver1->setText(QApplication::translate("Widget", "Receiver1", 0, QApplication::UnicodeUTF8));
        chkReceiver2->setText(QApplication::translate("Widget", "Receiver2", 0, QApplication::UnicodeUTF8));
        lblADC1->setText(QApplication::translate("Widget", "TextLabel", 0, QApplication::UnicodeUTF8));
        lblADC2->setText(QApplication::translate("Widget", "TextLabel", 0, QApplication::UnicodeUTF8));
        chkP1V->setText(QApplication::translate("Widget", "0.1V", 0, QApplication::UnicodeUTF8));
        chkP2V->setText(QApplication::translate("Widget", "0.2V", 0, QApplication::UnicodeUTF8));
        butDCDrive->setText(QApplication::translate("Widget", "DC", 0, QApplication::UnicodeUTF8));
        chkDDSFreq->setText(QApplication::translate("Widget", "DDS En", 0, QApplication::UnicodeUTF8));
        grpSettings->setTitle(QApplication::translate("Widget", "Measurment", 0, QApplication::UnicodeUTF8));
        lblSrcImped_4->setText(QApplication::translate("Widget", "Resistance", 0, QApplication::UnicodeUTF8));
        cmbResistance->clear();
        cmbResistance->insertItems(0, QStringList()
         << QApplication::translate("Widget", "10E", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "100E", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "1KE", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "10KE", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "100KE", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "1ME", 0, QApplication::UnicodeUTF8)
        );
        cmbCapcitance->clear();
        cmbCapcitance->insertItems(0, QStringList()
         << QApplication::translate("Widget", "10pF-100pF", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "100pF-1nF", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "1nF-10nF", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "10nF-100nF", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "100nF-1uF", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "1uF-10uF", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "10uF-100uF", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "100uF-1mF", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "1mF-10mF", 0, QApplication::UnicodeUTF8)
        );
        lblSrcImped_2->setText(QApplication::translate("Widget", "Capcitance", 0, QApplication::UnicodeUTF8));
        cmbInductance->clear();
        cmbInductance->insertItems(0, QStringList()
         << QApplication::translate("Widget", "3uH-30uH", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "30uH-300uH", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "300uH-3mH", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "3mH-30mH", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "30mH-300mH", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "300mH-3H", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "3H-30H", 0, QApplication::UnicodeUTF8)
        );
        lblSrcImped_3->setText(QApplication::translate("Widget", "Inductance", 0, QApplication::UnicodeUTF8));
        checkBox->setText(QApplication::translate("Widget", "Auto/Manual", 0, QApplication::UnicodeUTF8));
        cmbICMRange->clear();
        cmbICMRange->insertItems(0, QStringList()
         << QApplication::translate("Widget", "10E", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "100E", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "1KE", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "10KE", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "100KE", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "1ME", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "RESERVED1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "RESERVED2", 0, QApplication::UnicodeUTF8)
        );
        label_6->setText(QApplication::translate("Widget", "Range", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("Widget", "Display Segment", 0, QApplication::UnicodeUTF8));
        lblSrcImped_5->setText(QApplication::translate("Widget", "Resistance", 0, QApplication::UnicodeUTF8));
        lblSrcImped_6->setText(QApplication::translate("Widget", "Capcitance", 0, QApplication::UnicodeUTF8));
        lblSrcImped_7->setText(QApplication::translate("Widget", "Inductance", 0, QApplication::UnicodeUTF8));
        lblSrcImped_8->setText(QApplication::translate("Widget", "Voltage", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("Widget", "Waveform", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("Widget", "ICM Settings", 0, QApplication::UnicodeUTF8));
        chkCapSet->setText(QApplication::translate("Widget", "0.001uF/0.0001uF", 0, QApplication::UnicodeUTF8));
        chkPOTSel->setText(QApplication::translate("Widget", "OP07 / LT1012", 0, QApplication::UnicodeUTF8));
        chkDivSel->setText(QApplication::translate("Widget", "DIV0 / DIV1", 0, QApplication::UnicodeUTF8));
        butMeasure->setText(QApplication::translate("Widget", "Measure", 0, QApplication::UnicodeUTF8));
        butStop->setText(QApplication::translate("Widget", "Stop", 0, QApplication::UnicodeUTF8));
        optResistance->setText(QApplication::translate("Widget", "R", 0, QApplication::UnicodeUTF8));
        optCapacitance->setText(QApplication::translate("Widget", "C", 0, QApplication::UnicodeUTF8));
        optInductance->setText(QApplication::translate("Widget", "L", 0, QApplication::UnicodeUTF8));
        lblResistance->setText(QApplication::translate("Widget", "TextLabel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
