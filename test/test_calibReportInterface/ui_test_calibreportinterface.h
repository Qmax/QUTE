/********************************************************************************
** Form generated from reading UI file 'test_calibreportinterface.ui'
**
** Created: Thu Sep 18 10:45:32 2014
**      by: Qt User Interface Compiler version 4.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEST_CALIBREPORTINTERFACE_H
#define UI_TEST_CALIBREPORTINTERFACE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_test_CalibReportInterfaceClass
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *test_CalibReportInterfaceClass)
    {
        if (test_CalibReportInterfaceClass->objectName().isEmpty())
            test_CalibReportInterfaceClass->setObjectName(QString::fromUtf8("test_CalibReportInterfaceClass"));
        test_CalibReportInterfaceClass->resize(400, 300);
        pushButton = new QPushButton(test_CalibReportInterfaceClass);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(50, 80, 131, 41));
        pushButton->setFocusPolicy(Qt::NoFocus);
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        pushButton_2 = new QPushButton(test_CalibReportInterfaceClass);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(180, 170, 171, 41));
        pushButton_2->setFocusPolicy(Qt::NoFocus);
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        retranslateUi(test_CalibReportInterfaceClass);

        QMetaObject::connectSlotsByName(test_CalibReportInterfaceClass);
    } // setupUi

    void retranslateUi(QWidget *test_CalibReportInterfaceClass)
    {
        test_CalibReportInterfaceClass->setWindowTitle(QApplication::translate("test_CalibReportInterfaceClass", "test_CalibReportInterface", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("test_CalibReportInterfaceClass", "GENERATE", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("test_CalibReportInterfaceClass", "GENERATE FROM FILE", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class test_CalibReportInterfaceClass: public Ui_test_CalibReportInterfaceClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEST_CALIBREPORTINTERFACE_H
