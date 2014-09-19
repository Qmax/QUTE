/********************************************************************************
** Form generated from reading UI file 'testdigrapher.ui'
**
** Created: Wed Sep 10 10:33:19 2014
**      by: Qt User Interface Compiler version 4.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTDIGRAPHER_H
#define UI_TESTDIGRAPHER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TestDIGrapher
{
public:
    QWidget *centralWidget;

    void setupUi(QMainWindow *TestDIGrapher)
    {
        if (TestDIGrapher->objectName().isEmpty())
            TestDIGrapher->setObjectName(QString::fromUtf8("TestDIGrapher"));
        TestDIGrapher->resize(800, 600);
        centralWidget = new QWidget(TestDIGrapher);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        TestDIGrapher->setCentralWidget(centralWidget);

        retranslateUi(TestDIGrapher);

        QMetaObject::connectSlotsByName(TestDIGrapher);
    } // setupUi

    void retranslateUi(QMainWindow *TestDIGrapher)
    {
        TestDIGrapher->setWindowTitle(QApplication::translate("TestDIGrapher", "TestDIGrapher", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class TestDIGrapher: public Ui_TestDIGrapher {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTDIGRAPHER_H
