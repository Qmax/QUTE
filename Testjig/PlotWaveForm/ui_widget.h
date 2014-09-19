/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created: Tue Sep 9 12:03:24 2014
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
#include <QtGui/QFrame>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGroupBox *grpRAM;
    QCheckBox *chkDriveRAM;
    QCheckBox *chkDriveRAM_2;
    QGroupBox *grpAddress;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton;
    QPushButton *butReceive;
    QLabel *label_3;
    QLabel *label_4;
    QGroupBox *grpReceiverDSO;
    QCheckBox *chkDSORece1;
    QFrame *line;
    QCheckBox *chkDSORece2;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QPushButton *butDSOReceive;
    QFrame *line_2;
    QLineEdit *leR1Count;
    QLineEdit *lineEdit_2;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(800, 600);
        grpRAM = new QGroupBox(Widget);
        grpRAM->setObjectName(QString::fromUtf8("grpRAM"));
        grpRAM->setGeometry(QRect(10, 410, 131, 110));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QBrush brush1(QColor(116, 116, 116, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        grpRAM->setPalette(palette);
        chkDriveRAM = new QCheckBox(grpRAM);
        chkDriveRAM->setObjectName(QString::fromUtf8("chkDriveRAM"));
        chkDriveRAM->setGeometry(QRect(30, 20, 91, 41));
        chkDriveRAM->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
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
        chkDriveRAM_2 = new QCheckBox(grpRAM);
        chkDriveRAM_2->setObjectName(QString::fromUtf8("chkDriveRAM_2"));
        chkDriveRAM_2->setGeometry(QRect(30, 60, 131, 41));
        chkDriveRAM_2->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
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
        grpAddress = new QGroupBox(Widget);
        grpAddress->setObjectName(QString::fromUtf8("grpAddress"));
        grpAddress->setGeometry(QRect(150, 410, 631, 110));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        grpAddress->setPalette(palette1);
        label = new QLabel(grpAddress);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 20, 91, 41));
        label_2 = new QLabel(grpAddress);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 60, 101, 41));
        pushButton = new QPushButton(grpAddress);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(450, 30, 84, 61));
        QPalette palette2;
        QBrush brush2(QColor(0, 0, 0, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        QLinearGradient gradient(0, 0, 0, 1);
        gradient.setSpread(QGradient::PadSpread);
        gradient.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient.setColorAt(0, QColor(246, 247, 250, 255));
        gradient.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush3(gradient);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush3);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush4(QColor(0, 0, 127, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush4);
        QLinearGradient gradient1(0, 0, 0, 1);
        gradient1.setSpread(QGradient::PadSpread);
        gradient1.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient1.setColorAt(0, QColor(246, 247, 250, 255));
        gradient1.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush5(gradient1);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush5);
        QLinearGradient gradient2(0, 0, 0, 1);
        gradient2.setSpread(QGradient::PadSpread);
        gradient2.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient2.setColorAt(0, QColor(246, 247, 250, 255));
        gradient2.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush6(gradient2);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        QLinearGradient gradient3(0, 0, 0, 1);
        gradient3.setSpread(QGradient::PadSpread);
        gradient3.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient3.setColorAt(0, QColor(246, 247, 250, 255));
        gradient3.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush7(gradient3);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush7);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush4);
        QLinearGradient gradient4(0, 0, 0, 1);
        gradient4.setSpread(QGradient::PadSpread);
        gradient4.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient4.setColorAt(0, QColor(246, 247, 250, 255));
        gradient4.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush8(gradient4);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush8);
        QLinearGradient gradient5(0, 0, 0, 1);
        gradient5.setSpread(QGradient::PadSpread);
        gradient5.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient5.setColorAt(0, QColor(246, 247, 250, 255));
        gradient5.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush9(gradient5);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush9);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        QLinearGradient gradient6(0, 0, 0, 1);
        gradient6.setSpread(QGradient::PadSpread);
        gradient6.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient6.setColorAt(0, QColor(246, 247, 250, 255));
        gradient6.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush10(gradient6);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush10);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        QLinearGradient gradient7(0, 0, 0, 1);
        gradient7.setSpread(QGradient::PadSpread);
        gradient7.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient7.setColorAt(0, QColor(246, 247, 250, 255));
        gradient7.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush11(gradient7);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush11);
        QLinearGradient gradient8(0, 0, 0, 1);
        gradient8.setSpread(QGradient::PadSpread);
        gradient8.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient8.setColorAt(0, QColor(246, 247, 250, 255));
        gradient8.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush12(gradient8);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush12);
        pushButton->setPalette(palette2);
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
        butReceive = new QPushButton(grpAddress);
        butReceive->setObjectName(QString::fromUtf8("butReceive"));
        butReceive->setGeometry(QRect(540, 30, 84, 61));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        QLinearGradient gradient9(0, 0, 0, 1);
        gradient9.setSpread(QGradient::PadSpread);
        gradient9.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient9.setColorAt(0, QColor(246, 247, 250, 255));
        gradient9.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush13(gradient9);
        palette3.setBrush(QPalette::Active, QPalette::Button, brush13);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush4);
        QLinearGradient gradient10(0, 0, 0, 1);
        gradient10.setSpread(QGradient::PadSpread);
        gradient10.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient10.setColorAt(0, QColor(246, 247, 250, 255));
        gradient10.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush14(gradient10);
        palette3.setBrush(QPalette::Active, QPalette::Base, brush14);
        QLinearGradient gradient11(0, 0, 0, 1);
        gradient11.setSpread(QGradient::PadSpread);
        gradient11.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient11.setColorAt(0, QColor(246, 247, 250, 255));
        gradient11.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush15(gradient11);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush15);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        QLinearGradient gradient12(0, 0, 0, 1);
        gradient12.setSpread(QGradient::PadSpread);
        gradient12.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient12.setColorAt(0, QColor(246, 247, 250, 255));
        gradient12.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush16(gradient12);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush16);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush4);
        QLinearGradient gradient13(0, 0, 0, 1);
        gradient13.setSpread(QGradient::PadSpread);
        gradient13.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient13.setColorAt(0, QColor(246, 247, 250, 255));
        gradient13.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush17(gradient13);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush17);
        QLinearGradient gradient14(0, 0, 0, 1);
        gradient14.setSpread(QGradient::PadSpread);
        gradient14.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient14.setColorAt(0, QColor(246, 247, 250, 255));
        gradient14.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush18(gradient14);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush18);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        QLinearGradient gradient15(0, 0, 0, 1);
        gradient15.setSpread(QGradient::PadSpread);
        gradient15.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient15.setColorAt(0, QColor(246, 247, 250, 255));
        gradient15.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush19(gradient15);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush19);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        QLinearGradient gradient16(0, 0, 0, 1);
        gradient16.setSpread(QGradient::PadSpread);
        gradient16.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient16.setColorAt(0, QColor(246, 247, 250, 255));
        gradient16.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush20(gradient16);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush20);
        QLinearGradient gradient17(0, 0, 0, 1);
        gradient17.setSpread(QGradient::PadSpread);
        gradient17.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient17.setColorAt(0, QColor(246, 247, 250, 255));
        gradient17.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush21(gradient17);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush21);
        butReceive->setPalette(palette3);
        butReceive->setStyleSheet(QString::fromUtf8(" QPushButton {\n"
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
        label_3 = new QLabel(grpAddress);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(220, 60, 111, 41));
        label_4 = new QLabel(grpAddress);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(220, 20, 101, 41));
        grpReceiverDSO = new QGroupBox(Widget);
        grpReceiverDSO->setObjectName(QString::fromUtf8("grpReceiverDSO"));
        grpReceiverDSO->setGeometry(QRect(572, 10, 221, 401));
        chkDSORece1 = new QCheckBox(grpReceiverDSO);
        chkDSORece1->setObjectName(QString::fromUtf8("chkDSORece1"));
        chkDSORece1->setGeometry(QRect(10, 20, 91, 41));
        chkDSORece1->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
"font: 12px;\n"
"color:black\n"
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
        line = new QFrame(grpReceiverDSO);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(0, 164, 221, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        chkDSORece2 = new QCheckBox(grpReceiverDSO);
        chkDSORece2->setObjectName(QString::fromUtf8("chkDSORece2"));
        chkDSORece2->setGeometry(QRect(10, 181, 91, 41));
        chkDSORece2->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
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
        label_5 = new QLabel(grpReceiverDSO);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 70, 91, 41));
        label_6 = new QLabel(grpReceiverDSO);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 221, 101, 41));
        label_7 = new QLabel(grpReceiverDSO);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 130, 61, 41));
        label_8 = new QLabel(grpReceiverDSO);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(10, 271, 61, 41));
        butDSOReceive = new QPushButton(grpReceiverDSO);
        butDSOReceive->setObjectName(QString::fromUtf8("butDSOReceive"));
        butDSOReceive->setGeometry(QRect(40, 330, 84, 61));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        QLinearGradient gradient18(0, 0, 0, 1);
        gradient18.setSpread(QGradient::PadSpread);
        gradient18.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient18.setColorAt(0, QColor(246, 247, 250, 255));
        gradient18.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush22(gradient18);
        palette4.setBrush(QPalette::Active, QPalette::Button, brush22);
        palette4.setBrush(QPalette::Active, QPalette::Text, brush);
        palette4.setBrush(QPalette::Active, QPalette::ButtonText, brush4);
        QLinearGradient gradient19(0, 0, 0, 1);
        gradient19.setSpread(QGradient::PadSpread);
        gradient19.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient19.setColorAt(0, QColor(246, 247, 250, 255));
        gradient19.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush23(gradient19);
        palette4.setBrush(QPalette::Active, QPalette::Base, brush23);
        QLinearGradient gradient20(0, 0, 0, 1);
        gradient20.setSpread(QGradient::PadSpread);
        gradient20.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient20.setColorAt(0, QColor(246, 247, 250, 255));
        gradient20.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush24(gradient20);
        palette4.setBrush(QPalette::Active, QPalette::Window, brush24);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        QLinearGradient gradient21(0, 0, 0, 1);
        gradient21.setSpread(QGradient::PadSpread);
        gradient21.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient21.setColorAt(0, QColor(246, 247, 250, 255));
        gradient21.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush25(gradient21);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush25);
        palette4.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::ButtonText, brush4);
        QLinearGradient gradient22(0, 0, 0, 1);
        gradient22.setSpread(QGradient::PadSpread);
        gradient22.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient22.setColorAt(0, QColor(246, 247, 250, 255));
        gradient22.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush26(gradient22);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush26);
        QLinearGradient gradient23(0, 0, 0, 1);
        gradient23.setSpread(QGradient::PadSpread);
        gradient23.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient23.setColorAt(0, QColor(246, 247, 250, 255));
        gradient23.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush27(gradient23);
        palette4.setBrush(QPalette::Inactive, QPalette::Window, brush27);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        QLinearGradient gradient24(0, 0, 0, 1);
        gradient24.setSpread(QGradient::PadSpread);
        gradient24.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient24.setColorAt(0, QColor(246, 247, 250, 255));
        gradient24.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush28(gradient24);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush28);
        palette4.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        QLinearGradient gradient25(0, 0, 0, 1);
        gradient25.setSpread(QGradient::PadSpread);
        gradient25.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient25.setColorAt(0, QColor(246, 247, 250, 255));
        gradient25.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush29(gradient25);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush29);
        QLinearGradient gradient26(0, 0, 0, 1);
        gradient26.setSpread(QGradient::PadSpread);
        gradient26.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient26.setColorAt(0, QColor(246, 247, 250, 255));
        gradient26.setColorAt(1, QColor(218, 219, 222, 255));
        QBrush brush30(gradient26);
        palette4.setBrush(QPalette::Disabled, QPalette::Window, brush30);
        butDSOReceive->setPalette(palette4);
        butDSOReceive->setStyleSheet(QString::fromUtf8(" QPushButton {\n"
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
        line_2 = new QFrame(grpReceiverDSO);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(0, 310, 221, 16));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        leR1Count = new QLineEdit(grpReceiverDSO);
        leR1Count->setObjectName(QString::fromUtf8("leR1Count"));
        leR1Count->setGeometry(QRect(70, 135, 131, 31));
        lineEdit_2 = new QLineEdit(grpReceiverDSO);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(70, 270, 131, 31));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0, QApplication::UnicodeUTF8));
        grpRAM->setTitle(QApplication::translate("Widget", "Select RAM", 0, QApplication::UnicodeUTF8));
        chkDriveRAM->setText(QApplication::translate("Widget", "DRIVE ", 0, QApplication::UnicodeUTF8));
        chkDriveRAM_2->setText(QApplication::translate("Widget", "RECEIVE", 0, QApplication::UnicodeUTF8));
        grpAddress->setTitle(QApplication::translate("Widget", "Address Settings", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Widget", "Drive Start\n"
"Address:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Widget", "Drive Address\n"
"Count:", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Widget", "DRIVE\n"
"READ", 0, QApplication::UnicodeUTF8));
        butReceive->setText(QApplication::translate("Widget", "RECEIVE\n"
"READ", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Widget", "Receive Address\n"
"Count:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Widget", "Receive Start\n"
"Address:", 0, QApplication::UnicodeUTF8));
        grpReceiverDSO->setTitle(QApplication::translate("Widget", "DSO Receivers", 0, QApplication::UnicodeUTF8));
        chkDSORece1->setText(QApplication::translate("Widget", "Receive1", 0, QApplication::UnicodeUTF8));
        chkDSORece2->setText(QApplication::translate("Widget", "Receive2", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Widget", "Receive Start\n"
" Address:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("Widget", "Receive Start\n"
"Address:", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("Widget", "Count:", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("Widget", "Count:", 0, QApplication::UnicodeUTF8));
        butDSOReceive->setText(QApplication::translate("Widget", "Start\n"
"Receive", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
