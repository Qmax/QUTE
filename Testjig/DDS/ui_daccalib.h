/********************************************************************************
** Form generated from reading UI file 'daccalib.ui'
**
** Created: Wed May 22 11:30:35 2013
**      by: Qt User Interface Compiler version 4.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DACCALIB_H
#define UI_DACCALIB_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_DACCALIBClass
{
public:
    QGroupBox *CalibBox;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QComboBox *comboBox;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton;
    QLabel *label_4;
    QLineEdit *lineEdit_3;
    QPushButton *pushButton_2;
    QLabel *label_5;
    QLineEdit *lineEdit_4;
    QLabel *label_6;
    QLineEdit *lineEdit_5;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;

    void setupUi(QDialog *DACCALIBClass)
    {
        if (DACCALIBClass->objectName().isEmpty())
            DACCALIBClass->setObjectName(QString::fromUtf8("DACCALIBClass"));
        DACCALIBClass->resize(400, 305);
        DACCALIBClass->setStyleSheet(QString::fromUtf8("QDialog{\n"
"color:rgba(0,0,0,0);\n"
"background-color:rgba(0,0,0,0);\n"
"}"));
        CalibBox = new QGroupBox(DACCALIBClass);
        CalibBox->setObjectName(QString::fromUtf8("CalibBox"));
        CalibBox->setGeometry(QRect(5, 0, 391, 301));
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
        label->setGeometry(QRect(10, 40, 90, 20));
        lineEdit = new QLineEdit(CalibBox);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(110, 40, 70, 25));
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
        label_2->setGeometry(QRect(190, 40, 91, 20));
        comboBox = new QComboBox(CalibBox);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(290, 40, 70, 25));
        label_3 = new QLabel(CalibBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 90, 101, 20));
        lineEdit_2 = new QLineEdit(CalibBox);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(110, 90, 70, 25));
        lineEdit_2->setStyleSheet(QString::fromUtf8(" QLineEdit {\n"
"     border: 2px solid gray;\n"
"     border-radius: 8px;\n"
"     padding: 0 8px;\n"
"     background: white;\n"
"     selection-background-color: darkgray;\n"
"	 color:black;\n"
"     font: bold 12px;\n"
" }"));
        pushButton = new QPushButton(CalibBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(230, 90, 93, 30));
        label_4 = new QLabel(CalibBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 140, 101, 20));
        lineEdit_3 = new QLineEdit(CalibBox);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(110, 140, 70, 25));
        lineEdit_3->setStyleSheet(QString::fromUtf8(" QLineEdit {\n"
"     border: 2px solid gray;\n"
"     border-radius: 8px;\n"
"     padding: 0 8px;\n"
"     background: white;\n"
"     selection-background-color: darkgray;\n"
"	 color:black;\n"
"     font: bold 12px;\n"
" }"));
        pushButton_2 = new QPushButton(CalibBox);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(230, 140, 93, 30));
        label_5 = new QLabel(CalibBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 190, 69, 20));
        lineEdit_4 = new QLineEdit(CalibBox);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(90, 190, 90, 26));
        lineEdit_4->setStyleSheet(QString::fromUtf8(" QLineEdit {\n"
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
        label_6->setGeometry(QRect(206, 190, 69, 20));
        lineEdit_5 = new QLineEdit(CalibBox);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(280, 190, 90, 26));
        lineEdit_5->setStyleSheet(QString::fromUtf8(" QLineEdit {\n"
"     border: 2px solid gray;\n"
"     border-radius: 8px;\n"
"     padding: 0 8px;\n"
"     background: gray;\n"
"     selection-background-color: darkgray;\n"
"	 color:white;\n"
"     font: bold 12px;\n"
" }"));
        pushButton_3 = new QPushButton(CalibBox);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(70, 250, 93, 30));
        pushButton_3->setStyleSheet(QString::fromUtf8(" QPushButton {\n"
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
        pushButton_4 = new QPushButton(CalibBox);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(230, 250, 93, 30));
        pushButton_4->setStyleSheet(QString::fromUtf8(" QPushButton {\n"
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

        retranslateUi(DACCALIBClass);

        QMetaObject::connectSlotsByName(DACCALIBClass);
    } // setupUi

    void retranslateUi(QDialog *DACCALIBClass)
    {
        DACCALIBClass->setWindowTitle(QApplication::translate("DACCALIBClass", "DACCALIB", 0, QApplication::UnicodeUTF8));
        CalibBox->setTitle(QApplication::translate("DACCALIBClass", "DAC CALIBRATION PANEL", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("DACCALIBClass", "No of Points:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("DACCALIBClass", "Drive Range:", 0, QApplication::UnicodeUTF8));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("DACCALIBClass", "0.6V", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DACCALIBClass", "1.5V", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DACCALIBClass", "3.5V", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DACCALIBClass", "7V", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DACCALIBClass", "13V", 0, QApplication::UnicodeUTF8)
        );
        label_3->setText(QApplication::translate("DACCALIBClass", "Drive Volt(x):", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("DACCALIBClass", "DRIVE", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("DACCALIBClass", "RX'd Volt(y):", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("DACCALIBClass", "NEXT", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("DACCALIBClass", "Slope:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("DACCALIBClass", "Constant:", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("DACCALIBClass", "SAVE", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("DACCALIBClass", "EXIT", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DACCALIBClass: public Ui_DACCALIBClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DACCALIB_H
