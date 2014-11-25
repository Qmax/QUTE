/********************************************************************************
** Form generated from reading UI file 'haadc.ui'
**
** Created: Fri Mar 7 10:35:55 2014
**      by: Qt User Interface Compiler version 4.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HAADC_H
#define UI_HAADC_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_haadcClass
{
public:

    void setupUi(QWidget *haadcClass)
    {
        if (haadcClass->objectName().isEmpty())
            haadcClass->setObjectName(QString::fromUtf8("haadcClass"));
        haadcClass->resize(400, 300);

        retranslateUi(haadcClass);

        QMetaObject::connectSlotsByName(haadcClass);
    } // setupUi

    void retranslateUi(QWidget *haadcClass)
    {
        haadcClass->setWindowTitle(QApplication::translate("haadcClass", "haadc", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class haadcClass: public Ui_haadcClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HAADC_H
