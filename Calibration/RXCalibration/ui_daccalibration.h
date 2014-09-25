/***********************************************************
***************Created by Ravivarman.R,Qmax*****************
***********************************************************/
/********************************************************************************
** Form generated from reading UI file 'daccalibration.ui'
**
** Created: Wed Sep 25 16:59:23 2013
**      by: Qt User Interface Compiler version 4.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DACCALIBRATION_H
#define UI_DACCALIBRATION_H

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

class Ui_DACCalibrationClass
{
public:
    QGroupBox *CalibBox;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QComboBox *comboBox;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QPushButton *driveBut;
    QLabel *label_4;
    QLineEdit *lineEdit_3;
    QPushButton *nextBut;
    QLabel *label_5;
    QLineEdit *slope;
    QLabel *label_6;
    QLineEdit *constant;
    QPushButton *saveBut;
    QPushButton *exitBut;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *lineEdit_4;
    QPushButton *driveBut_2;
    QCheckBox *Calibrated;
    QGroupBox *groupBox;
    QLineEdit *lineEdit_5;
    QLabel *samples;
    QComboBox *comboBox_2;
    QLabel *label_9;
    QComboBox *comboBox_3;
    QLabel *label_10;
    QGroupBox *groupBox_2;
    QGroupBox *groupBox_3;
    QCheckBox *Calibrated_2;
    QCheckBox *loopbck;
    QCheckBox *checkBox_2;
    QCheckBox *Calibrated_3;
    QGroupBox *groupBox_4;
    QCheckBox *enableDrive;
    QCheckBox *enableReceive;
    QPushButton *stopBut;
    QCheckBox *Calibrated_4;

    void setupUi(QWidget *DACCalibrationClass)
    {
        if (DACCalibrationClass->objectName().isEmpty())
            DACCalibrationClass->setObjectName(QString::fromUtf8("DACCalibrationClass"));
        DACCalibrationClass->resize(511, 414);
        DACCalibrationClass->setStyleSheet(QString::fromUtf8("QWidget{\n"
"background-color:rgba(0,0,0,0);\n"
"}"));
        CalibBox = new QGroupBox(DACCalibrationClass);
        CalibBox->setObjectName(QString::fromUtf8("CalibBox"));
        CalibBox->setGeometry(QRect(10, 6, 496, 400));
        CalibBox->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #E0E0E0, stop: 1 #FFFFFF);\n"
"     border: 2px solid gray;\n"
"     border-radius: 10px;\n"
"     margin-top: 1ex; /* leave space at the top for the title */\n"
"	font:18px bold;\n"
"	color:black;\n"
" }\n"
"\n"
" QGroupBox::title {\n"
"     subcontrol-origin: margin;\n"
"     subcontrol-position: top center; /* position at the top center */\n"
"     padding: 0 3px;\n"
"	 background-color:white;\n"
"     border:2px solid black;\n"
"	border-radius:10px;\n"
" }"));
        label = new QLabel(CalibBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 88, 90, 20));
        QFont font;
        font.setFamily(QString::fromUtf8("DejaVu Sans"));
        font.setPointSize(12);
        label->setFont(font);
        lineEdit = new QLineEdit(CalibBox);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(91, 88, 70, 25));
        QFont font1;
        font1.setBold(true);
        font1.setItalic(false);
        font1.setWeight(75);
        lineEdit->setFont(font1);
        lineEdit->setStyleSheet(QString::fromUtf8(" QLineEdit {\n"
"     border: 2px solid gray;\n"
"     border-radius: 8px;\n"
"     padding: 0 8px;\n"
"     background: white;\n"
"     selection-background-color: darkgray;\n"
"	 color:black;\n"
"     font: bold 12px;\n"
" }"));
        label_2 = new QLabel(CalibBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(200, 88, 91, 20));
        label_2->setFont(font);
        comboBox = new QComboBox(CalibBox);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(300, 88, 70, 30));
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setWeight(75);
        comboBox->setFont(font2);
        comboBox->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"     border: 2px solid gray;\n"
"     border-radius: 5px;\n"
"     padding: 1px 18px 1px 3px;\n"
"	background-color:white;\n"
"	color:black;\n"
" }\n"
""));
        label_3 = new QLabel(CalibBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(11, 146, 101, 20));
        label_3->setFont(font);
        lineEdit_2 = new QLineEdit(CalibBox);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(91, 146, 70, 25));
        lineEdit_2->setFont(font1);
        lineEdit_2->setStyleSheet(QString::fromUtf8(" QLineEdit {\n"
"     border: 2px solid gray;\n"
"     border-radius: 8px;\n"
"     padding: 0 8px;\n"
"     background: white;\n"
"     selection-background-color: darkgray;\n"
"	 color:black;\n"
"     font: bold 12px;\n"
" }"));
        driveBut = new QPushButton(CalibBox);
        driveBut->setObjectName(QString::fromUtf8("driveBut"));
        driveBut->setGeometry(QRect(200, 141, 93, 30));
        driveBut->setFont(font);
        driveBut->setStyleSheet(QString::fromUtf8(" QPushButton {\n"
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
        label_4 = new QLabel(CalibBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(11, 192, 101, 20));
        label_4->setFont(font);
        lineEdit_3 = new QLineEdit(CalibBox);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(91, 192, 90, 25));
        lineEdit_3->setFont(font1);
        lineEdit_3->setStyleSheet(QString::fromUtf8(" QLineEdit {\n"
"     border: 2px solid gray;\n"
"     border-radius: 8px;\n"
"     padding: 0 8px;\n"
"     background: white;\n"
"     selection-background-color: darkgray;\n"
"	 color:black;\n"
"     font: bold 12px;\n"
" }"));
        nextBut = new QPushButton(CalibBox);
        nextBut->setObjectName(QString::fromUtf8("nextBut"));
        nextBut->setGeometry(QRect(200, 192, 93, 30));
        nextBut->setFont(font);
        nextBut->setStyleSheet(QString::fromUtf8(" QPushButton {\n"
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
        label_5 = new QLabel(CalibBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(12, 254, 69, 20));
        label_5->setFont(font);
        slope = new QLineEdit(CalibBox);
        slope->setObjectName(QString::fromUtf8("slope"));
        slope->setGeometry(QRect(92, 254, 90, 26));
        slope->setFont(font1);
        slope->setStyleSheet(QString::fromUtf8(" QLineEdit {\n"
"     border: 2px solid gray;\n"
"     border-radius: 8px;\n"
"     padding: 0 8px;\n"
"     background: gray;\n"
"     selection-background-color: darkgray;\n"
"	 color:white;\n"
"     font: bold 12px;\n"
" }"));
        label_6 = new QLabel(CalibBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(270, 254, 80, 20));
        label_6->setFont(font);
        constant = new QLineEdit(CalibBox);
        constant->setObjectName(QString::fromUtf8("constant"));
        constant->setGeometry(QRect(348, 254, 90, 26));
        constant->setFont(font1);
        constant->setStyleSheet(QString::fromUtf8(" QLineEdit {\n"
"     border: 2px solid gray;\n"
"     border-radius: 8px;\n"
"     padding: 0 8px;\n"
"     background: gray;\n"
"     selection-background-color: darkgray;\n"
"	 color:white;\n"
"     font: bold 12px;\n"
" }"));
        saveBut = new QPushButton(CalibBox);
        saveBut->setObjectName(QString::fromUtf8("saveBut"));
        saveBut->setGeometry(QRect(280, 360, 93, 30));
        saveBut->setFont(font);
        saveBut->setStyleSheet(QString::fromUtf8(" QPushButton {\n"
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
        exitBut = new QPushButton(CalibBox);
        exitBut->setObjectName(QString::fromUtf8("exitBut"));
        exitBut->setGeometry(QRect(380, 360, 93, 30));
        exitBut->setFont(font);
        exitBut->setStyleSheet(QString::fromUtf8(" QPushButton {\n"
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
        label_7 = new QLabel(CalibBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(332, 95, 20, 20));
        label_8 = new QLabel(CalibBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(10, 314, 80, 20));
        label_8->setFont(font);
        lineEdit_4 = new QLineEdit(CalibBox);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(70, 314, 60, 25));
        lineEdit_4->setFont(font1);
        lineEdit_4->setStyleSheet(QString::fromUtf8(" QLineEdit {\n"
"     border: 2px solid gray;\n"
"     border-radius: 8px;\n"
"     padding: 0 8px;\n"
"     background: white;\n"
"     selection-background-color: darkgray;\n"
"	 color:black;\n"
"     font: bold 12px;\n"
" }"));
        driveBut_2 = new QPushButton(CalibBox);
        driveBut_2->setObjectName(QString::fromUtf8("driveBut_2"));
        driveBut_2->setGeometry(QRect(380, 310, 84, 30));
        driveBut_2->setFont(font);
        driveBut_2->setStyleSheet(QString::fromUtf8(" QPushButton {\n"
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
        Calibrated = new QCheckBox(CalibBox);
        Calibrated->setObjectName(QString::fromUtf8("Calibrated"));
        Calibrated->setGeometry(QRect(250, 314, 93, 25));
        Calibrated->setFont(font);
        groupBox = new QGroupBox(CalibBox);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(5, 290, 487, 61));
        groupBox->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #E0E0E0, stop: 1 #FFFFFF);\n"
"     border: 1px solid gray;\n"
"     border-radius: 10px;\n"
"     margin-top: 1ex; /* leave space at the top for the title */\n"
"	font:18px bold;\n"
"	color:black;\n"
" }\n"
"\n"
" "));
        lineEdit_5 = new QLineEdit(groupBox);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(130, 24, 80, 25));
        lineEdit_5->setFont(font1);
        lineEdit_5->setStyleSheet(QString::fromUtf8(" QLineEdit {\n"
"     border: 2px solid gray;\n"
"     border-radius: 8px;\n"
"     padding: 0 8px;\n"
"     background: white;\n"
"     selection-background-color: darkgray;\n"
"	 color:black;\n"
"     font: bold 12px;\n"
" }"));
        samples = new QLabel(CalibBox);
        samples->setObjectName(QString::fromUtf8("samples"));
        samples->setGeometry(QRect(300, 196, 31, 20));
        comboBox_2 = new QComboBox(CalibBox);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(300, 40, 70, 30));
        QFont font3;
        font3.setPointSize(12);
        comboBox_2->setFont(font3);
        comboBox_2->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"     border: 2px solid gray;\n"
"     border-radius: 5px;\n"
"     padding: 1px 18px 1px 3px;\n"
"	background-color:white;\n"
"	color:black;\n"
" }\n"
""));
        label_9 = new QLabel(CalibBox);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(10, 46, 90, 20));
        label_9->setFont(font);
        comboBox_3 = new QComboBox(CalibBox);
        comboBox_3->setObjectName(QString::fromUtf8("comboBox_3"));
        comboBox_3->setGeometry(QRect(91, 40, 90, 30));
        comboBox_3->setFont(font3);
        comboBox_3->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"     border: 2px solid gray;\n"
"     border-radius: 5px;\n"
"     padding: 1px 18px 1px 3px;\n"
"	background-color:white;\n"
"	color:black;\n"
" }\n"
""));
        label_10 = new QLabel(CalibBox);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(200, 46, 90, 20));
        label_10->setFont(font);
        groupBox_2 = new QGroupBox(CalibBox);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(4, 230, 487, 61));
        groupBox_2->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #E0E0E0, stop: 1 #FFFFFF);\n"
"     border: 1px solid gray;\n"
"     border-radius: 10px;\n"
"     margin-top: 1ex; /* leave space at the top for the title */\n"
"	font:18px bold;\n"
"	color:black;\n"
" }\n"
"\n"
" "));
        groupBox_3 = new QGroupBox(CalibBox);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(5, 120, 487, 110));
        groupBox_3->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #E0E0E0, stop: 1 #FFFFFF);\n"
"     border: 1px solid gray;\n"
"     border-radius: 10px;\n"
"     margin-top: 1ex; /* leave space at the top for the title */\n"
"	font:18px bold;\n"
"	color:black;\n"
" }\n"
"\n"
" "));
        Calibrated_2 = new QCheckBox(groupBox_3);
        Calibrated_2->setObjectName(QString::fromUtf8("Calibrated_2"));
        Calibrated_2->setGeometry(QRect(300, 23, 93, 25));
        Calibrated_2->setFont(font);
        loopbck = new QCheckBox(groupBox_3);
        loopbck->setObjectName(QString::fromUtf8("loopbck"));
        loopbck->setGeometry(QRect(400, 23, 93, 25));
        loopbck->setFont(font);
        checkBox_2 = new QCheckBox(groupBox_3);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setGeometry(QRect(400, 70, 93, 25));
        checkBox_2->setFont(font);
        Calibrated_3 = new QCheckBox(groupBox_3);
        Calibrated_3->setObjectName(QString::fromUtf8("Calibrated_3"));
        Calibrated_3->setGeometry(QRect(300, 70, 93, 25));
        Calibrated_3->setFont(font);
        groupBox_4 = new QGroupBox(CalibBox);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(5, 20, 487, 103));
        groupBox_4->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #E0E0E0, stop: 1 #FFFFFF);\n"
"     border: 1px solid gray;\n"
"     border-radius: 10px;\n"
"     margin-top: 1ex; /* leave space at the top for the title */\n"
"	font:18px bold;\n"
"	color:black;\n"
" }\n"
"\n"
" "));
        enableDrive = new QCheckBox(groupBox_4);
        enableDrive->setObjectName(QString::fromUtf8("enableDrive"));
        enableDrive->setGeometry(QRect(375, 70, 96, 22));
        QFont font4;
        font4.setFamily(QString::fromUtf8("DejaVu Sans"));
        enableDrive->setFont(font4);
        enableReceive = new QCheckBox(groupBox_4);
        enableReceive->setObjectName(QString::fromUtf8("enableReceive"));
        enableReceive->setGeometry(QRect(375, 20, 120, 22));
        enableReceive->setFont(font4);
        stopBut = new QPushButton(CalibBox);
        stopBut->setObjectName(QString::fromUtf8("stopBut"));
        stopBut->setGeometry(QRect(180, 360, 93, 30));
        stopBut->setFont(font);
        stopBut->setStyleSheet(QString::fromUtf8(" QPushButton {\n"
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
        Calibrated_4 = new QCheckBox(CalibBox);
        Calibrated_4->setObjectName(QString::fromUtf8("Calibrated_4"));
        Calibrated_4->setGeometry(QRect(10, 360, 151, 25));
        Calibrated_4->setFont(font);
        groupBox->raise();
        groupBox_2->raise();
        groupBox_3->raise();
        groupBox_4->raise();
        label->raise();
        lineEdit->raise();
        label_2->raise();
        comboBox->raise();
        label_3->raise();
        lineEdit_2->raise();
        driveBut->raise();
        label_4->raise();
        lineEdit_3->raise();
        nextBut->raise();
        label_5->raise();
        slope->raise();
        label_6->raise();
        constant->raise();
        saveBut->raise();
        exitBut->raise();
        label_7->raise();
        label_8->raise();
        lineEdit_4->raise();
        driveBut_2->raise();
        Calibrated->raise();
        samples->raise();
        comboBox_2->raise();
        label_9->raise();
        comboBox_3->raise();
        label_10->raise();
        stopBut->raise();
        Calibrated_4->raise();

        retranslateUi(DACCalibrationClass);

        comboBox_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(DACCalibrationClass);
    } // setupUi

    void retranslateUi(QWidget *DACCalibrationClass)
    {
        DACCalibrationClass->setWindowTitle(QApplication::translate("DACCalibrationClass", "DACCalibration", 0, QApplication::UnicodeUTF8));
        CalibBox->setTitle(QApplication::translate("DACCalibrationClass", "RECEIVE CALIBRATION PANEL", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("DACCalibrationClass", "No of Points:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("DACCalibrationClass", "Drive Range:", 0, QApplication::UnicodeUTF8));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("DACCalibrationClass", "0.6", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DACCalibrationClass", "1.5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DACCalibrationClass", "3.5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DACCalibrationClass", "7", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DACCalibrationClass", "13", 0, QApplication::UnicodeUTF8)
        );
        label_3->setText(QApplication::translate("DACCalibrationClass", "Drive Volt(x):", 0, QApplication::UnicodeUTF8));
        driveBut->setText(QApplication::translate("DACCalibrationClass", "DRIVE", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("DACCalibrationClass", "RX'd Volt(y):", 0, QApplication::UnicodeUTF8));
        nextBut->setText(QApplication::translate("DACCalibrationClass", "NEXT", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("DACCalibrationClass", "Slope:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("DACCalibrationClass", "Constant:", 0, QApplication::UnicodeUTF8));
        saveBut->setText(QApplication::translate("DACCalibrationClass", "SAVE", 0, QApplication::UnicodeUTF8));
        exitBut->setText(QApplication::translate("DACCalibrationClass", "EXIT", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("DACCalibrationClass", "V", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("DACCalibrationClass", "Test Volt:", 0, QApplication::UnicodeUTF8));
        driveBut_2->setText(QApplication::translate("DACCalibrationClass", "DRIVE", 0, QApplication::UnicodeUTF8));
        Calibrated->setText(QApplication::translate("DACCalibrationClass", "Calibrated", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QString());
        samples->setText(QString());
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("DACCalibrationClass", "1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DACCalibrationClass", "8", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DACCalibrationClass", "64", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DACCalibrationClass", "128", 0, QApplication::UnicodeUTF8)
        );
        label_9->setText(QApplication::translate("DACCalibrationClass", "Select ADC:", 0, QApplication::UnicodeUTF8));
        comboBox_3->clear();
        comboBox_3->insertItems(0, QStringList()
         << QApplication::translate("DACCalibrationClass", "HAADC1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DACCalibrationClass", "HAADC2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DACCalibrationClass", "HSADC1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DACCalibrationClass", "HSADC2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DACCalibrationClass", "VIADC", 0, QApplication::UnicodeUTF8)
        );
        label_10->setText(QApplication::translate("DACCalibrationClass", "Select Gain:", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QString());
        groupBox_3->setTitle(QString());
        Calibrated_2->setText(QApplication::translate("DACCalibrationClass", "Calibrated", 0, QApplication::UnicodeUTF8));
        loopbck->setText(QApplication::translate("DACCalibrationClass", "EXT/INT\n"
"LOOP", 0, QApplication::UnicodeUTF8));
        checkBox_2->setText(QApplication::translate("DACCalibrationClass", "EXT/INT\n"
"LOOP", 0, QApplication::UnicodeUTF8));
        Calibrated_3->setText(QApplication::translate("DACCalibrationClass", "Calibrated", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QString());
        enableDrive->setText(QApplication::translate("DACCalibrationClass", "Enable Drive", 0, QApplication::UnicodeUTF8));
        enableReceive->setText(QApplication::translate("DACCalibrationClass", "Enable Receive", 0, QApplication::UnicodeUTF8));
        stopBut->setText(QApplication::translate("DACCalibrationClass", "STOP", 0, QApplication::UnicodeUTF8));
        Calibrated_4->setText(QApplication::translate("DACCalibrationClass", "Calibrated Reference", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DACCalibrationClass: public Ui_DACCalibrationClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DACCALIBRATION_H
