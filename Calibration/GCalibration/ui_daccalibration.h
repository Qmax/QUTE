/***********************************************************
***************Created by Ravivarman.R,Qmax*****************
***********************************************************/
/********************************************************************************
** Form generated from reading UI file 'daccalibration.ui'
**
** Created: Sat Sep 6 10:52:35 2014
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
    QLabel *label_4;
    QLineEdit *lineEdit_3;
    QLabel *label_5;
    QLineEdit *slope;
    QLabel *label_6;
    QLineEdit *constant;
    QPushButton *saveBut;
    QPushButton *exitBut;
    QLabel *samples;
    QPushButton *nextBut;
    QLabel *count;
    QComboBox *ICM;

    void setupUi(QWidget *DACCalibrationClass)
    {
        if (DACCalibrationClass->objectName().isEmpty())
            DACCalibrationClass->setObjectName(QString::fromUtf8("DACCalibrationClass"));
        DACCalibrationClass->resize(400, 341);
        DACCalibrationClass->setStyleSheet(QString::fromUtf8("QWidget{\n"
"background-color:rgba(0,0,0,0);\n"
"}"));
        CalibBox = new QGroupBox(DACCalibrationClass);
        CalibBox->setObjectName(QString::fromUtf8("CalibBox"));
        CalibBox->setGeometry(QRect(5, 2, 391, 337));
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
        label->setGeometry(QRect(10, 50, 90, 20));
        QFont font;
        font.setFamily(QString::fromUtf8("DejaVu Sans"));
        font.setPointSize(12);
        label->setFont(font);
        lineEdit = new QLineEdit(CalibBox);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(110, 50, 70, 25));
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
        label_2->setGeometry(QRect(190, 50, 110, 20));
        label_2->setFont(font);
        comboBox = new QComboBox(CalibBox);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(300, 50, 81, 25));
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
        label_3->setGeometry(QRect(10, 117, 101, 20));
        label_3->setFont(font);
        lineEdit_2 = new QLineEdit(CalibBox);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(130, 117, 150, 25));
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
        label_4 = new QLabel(CalibBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 177, 101, 20));
        label_4->setFont(font);
        lineEdit_3 = new QLineEdit(CalibBox);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(130, 177, 150, 25));
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
        label_5 = new QLabel(CalibBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 240, 69, 20));
        label_5->setFont(font);
        slope = new QLineEdit(CalibBox);
        slope->setObjectName(QString::fromUtf8("slope"));
        slope->setGeometry(QRect(90, 240, 90, 26));
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
        label_6->setGeometry(QRect(202, 240, 80, 20));
        label_6->setFont(font);
        constant = new QLineEdit(CalibBox);
        constant->setObjectName(QString::fromUtf8("constant"));
        constant->setGeometry(QRect(280, 240, 90, 26));
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
        saveBut->setGeometry(QRect(70, 290, 93, 30));
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
        exitBut->setGeometry(QRect(230, 290, 93, 30));
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
        samples = new QLabel(CalibBox);
        samples->setObjectName(QString::fromUtf8("samples"));
        samples->setGeometry(QRect(330, 144, 31, 20));
        nextBut = new QPushButton(CalibBox);
        nextBut->setObjectName(QString::fromUtf8("nextBut"));
        nextBut->setGeometry(QRect(286, 177, 65, 27));
        nextBut->setStyleSheet(QString::fromUtf8(" QPushButton {\n"
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
        count = new QLabel(CalibBox);
        count->setObjectName(QString::fromUtf8("count"));
        count->setGeometry(QRect(355, 180, 31, 17));
        ICM = new QComboBox(CalibBox);
        ICM->setObjectName(QString::fromUtf8("ICM"));
        ICM->setGeometry(QRect(300, 117, 80, 23));
        ICM->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"     border: 2px solid gray;\n"
"     border-radius: 5px;\n"
"     padding: 1px 18px 1px 3px;\n"
"	background-color:white;\n"
"	color:black;\n"
" }\n"
""));

        retranslateUi(DACCalibrationClass);

        QMetaObject::connectSlotsByName(DACCalibrationClass);
    } // setupUi

    void retranslateUi(QWidget *DACCalibrationClass)
    {
        DACCalibrationClass->setWindowTitle(QApplication::translate("DACCalibrationClass", "DACCalibration", 0, QApplication::UnicodeUTF8));
        CalibBox->setTitle(QApplication::translate("DACCalibrationClass", "GENERIC CALIBRATION PANEL", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("DACCalibrationClass", "No of Points:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("DACCalibrationClass", "Drive Element", 0, QApplication::UnicodeUTF8));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("DACCalibrationClass", "ICM-R", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DACCalibrationClass", "ICM-L", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DACCalibrationClass", "ICM-C", 0, QApplication::UnicodeUTF8)
        );
        label_3->setText(QApplication::translate("DACCalibrationClass", "Actual Value", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("DACCalibrationClass", "Rx'd Value", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("DACCalibrationClass", "Slope:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("DACCalibrationClass", "Constant:", 0, QApplication::UnicodeUTF8));
        saveBut->setText(QApplication::translate("DACCalibrationClass", "SAVE", 0, QApplication::UnicodeUTF8));
        exitBut->setText(QApplication::translate("DACCalibrationClass", "EXIT", 0, QApplication::UnicodeUTF8));
        samples->setText(QString());
        nextBut->setText(QApplication::translate("DACCalibrationClass", "Next", 0, QApplication::UnicodeUTF8));
        count->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DACCalibrationClass: public Ui_DACCalibrationClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DACCALIBRATION_H
