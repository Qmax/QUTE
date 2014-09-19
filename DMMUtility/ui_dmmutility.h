/********************************************************************************
** Form generated from reading UI file 'dmmutility.ui'
**
** Created: Thu Sep 18 19:14:27 2014
**      by: Qt User Interface Compiler version 4.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DMMUTILITY_H
#define UI_DMMUTILITY_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_DMMUtility
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QPushButton *pushButton_12;
    QPushButton *pushButton_13;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *DMMUtility)
    {
        if (DMMUtility->objectName().isEmpty())
            DMMUtility->setObjectName(QString::fromUtf8("DMMUtility"));
        DMMUtility->resize(270, 200);
        DMMUtility->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color:white;\n"
"border: 1px solid #2D5059;\n"
"border-radius: 20px;\n"
"background-color: qlineargradient(x1: 0, y1: 1, x2: 1, y2: 0,stop: 0 #1A74DB, stop: 0.6 #5293DE, stop:1 #FFFFFF);\n"
"font:bold;\n"
"}\n"
"QPushButton:pressed {\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}\n"
"QPushButton:flat {\n"
"border: none; \n"
"}\n"
"QPushButton:default {\n"
"border-color: navy; \n"
"}\n"
"\n"
"QPushButton:disabled\n"
"{\n"
"color:lightgrey;\n"
"background-color:grey\n"
"}"));
        pushButton = new QPushButton(DMMUtility);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(4, 87, 51, 51));
        pushButton_2 = new QPushButton(DMMUtility);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(57, 87, 51, 51));
        pushButton_3 = new QPushButton(DMMUtility);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(111, 87, 51, 51));
        pushButton_4 = new QPushButton(DMMUtility);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(163, 87, 51, 51));
        pushButton_5 = new QPushButton(DMMUtility);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(216, 87, 51, 51));
        pushButton_6 = new QPushButton(DMMUtility);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(216, 147, 51, 51));
        pushButton_7 = new QPushButton(DMMUtility);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(111, 147, 51, 51));
        pushButton_8 = new QPushButton(DMMUtility);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setGeometry(QRect(4, 147, 51, 51));
        pushButton_9 = new QPushButton(DMMUtility);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setGeometry(QRect(57, 147, 51, 51));
        pushButton_10 = new QPushButton(DMMUtility);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));
        pushButton_10->setGeometry(QRect(163, 147, 51, 51));
        pushButton_12 = new QPushButton(DMMUtility);
        pushButton_12->setObjectName(QString::fromUtf8("pushButton_12"));
        pushButton_12->setGeometry(QRect(3, 53, 191, 30));
        pushButton_13 = new QPushButton(DMMUtility);
        pushButton_13->setObjectName(QString::fromUtf8("pushButton_13"));
        pushButton_13->setGeometry(QRect(196, 53, 71, 30));
        label = new QLabel(DMMUtility);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(6, 3, 191, 56));
        QFont font;
        font.setFamily(QString::fromUtf8("DejaVu Sans"));
        font.setPointSize(40);
        label->setFont(font);
        label_2 = new QLabel(DMMUtility);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(200, 3, 64, 56));
        QFont font1;
        font1.setFamily(QString::fromUtf8("DejaVu Sans"));
        font1.setPointSize(25);
        label_2->setFont(font1);

        retranslateUi(DMMUtility);

        QMetaObject::connectSlotsByName(DMMUtility);
    } // setupUi

    void retranslateUi(QDialog *DMMUtility)
    {
        DMMUtility->setWindowTitle(QApplication::translate("DMMUtility", "DMMUtility", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("DMMUtility", "V", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("DMMUtility", "I", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("DMMUtility", "R", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("DMMUtility", "D", 0, QApplication::UnicodeUTF8));
        pushButton_5->setText(QApplication::translate("DMMUtility", "CTY", 0, QApplication::UnicodeUTF8));
        pushButton_6->setText(QApplication::translate("DMMUtility", ">", 0, QApplication::UnicodeUTF8));
        pushButton_7->setText(QApplication::translate("DMMUtility", "5ME", 0, QApplication::UnicodeUTF8));
        pushButton_8->setText(QApplication::translate("DMMUtility", "<", 0, QApplication::UnicodeUTF8));
        pushButton_9->setText(QApplication::translate("DMMUtility", "500KE", 0, QApplication::UnicodeUTF8));
        pushButton_10->setText(QApplication::translate("DMMUtility", "50ME", 0, QApplication::UnicodeUTF8));
        pushButton_12->setText(QApplication::translate("DMMUtility", "Expand", 0, QApplication::UnicodeUTF8));
        pushButton_13->setText(QApplication::translate("DMMUtility", "Auto", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("DMMUtility", "1.0003", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("DMMUtility", "mE", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DMMUtility: public Ui_DMMUtility {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DMMUTILITY_H
