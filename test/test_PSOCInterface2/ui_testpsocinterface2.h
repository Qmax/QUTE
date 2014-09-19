/********************************************************************************
** Form generated from reading UI file 'testpsocinterface2.ui'
**
** Created: Fri Jun 20 13:33:57 2014
**      by: Qt User Interface Compiler version 4.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTPSOCINTERFACE2_H
#define UI_TESTPSOCINTERFACE2_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_testPSOCInterface2
{
public:
    QWidget *centralWidget;
    QPushButton *readCodeID;
    QLineEdit *showCodeID;

    void setupUi(QMainWindow *testPSOCInterface2)
    {
        if (testPSOCInterface2->objectName().isEmpty())
            testPSOCInterface2->setObjectName(QString::fromUtf8("testPSOCInterface2"));
        testPSOCInterface2->resize(400, 300);
        centralWidget = new QWidget(testPSOCInterface2);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        readCodeID = new QPushButton(centralWidget);
        readCodeID->setObjectName(QString::fromUtf8("readCodeID"));
        readCodeID->setGeometry(QRect(40, 50, 120, 40));
        readCodeID->setFocusPolicy(Qt::NoFocus);
        readCodeID->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        showCodeID = new QLineEdit(centralWidget);
        showCodeID->setObjectName(QString::fromUtf8("showCodeID"));
        showCodeID->setGeometry(QRect(160, 50, 60, 40));
        showCodeID->setFocusPolicy(Qt::NoFocus);
        showCodeID->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"color:white;\n"
"border: 1px solid #2D5059;\n"
"border-radius: 20px;\n"
"background-color: qlineargradient(x1: 0, y1: 1, x2: 1, y2: 0,stop: 0 #1A74DB, stop: 0.6 #5293DE, stop:1 #FFFFFF);\n"
"font:bold;\n"
"}\n"
""));
        showCodeID->setAlignment(Qt::AlignCenter);
        testPSOCInterface2->setCentralWidget(centralWidget);

        retranslateUi(testPSOCInterface2);

        QMetaObject::connectSlotsByName(testPSOCInterface2);
    } // setupUi

    void retranslateUi(QMainWindow *testPSOCInterface2)
    {
        testPSOCInterface2->setWindowTitle(QApplication::translate("testPSOCInterface2", "testPSOCInterface2", 0, QApplication::UnicodeUTF8));
        readCodeID->setText(QApplication::translate("testPSOCInterface2", "Read Code ID", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class testPSOCInterface2: public Ui_testPSOCInterface2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTPSOCINTERFACE2_H
