/********************************************************************************
** Form generated from reading UI file 'dsodisplay.ui'
**
** Created: Tue Sep 30 17:19:12 2014
**      by: Qt User Interface Compiler version 4.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DSODISPLAY_H
#define UI_DSODISPLAY_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DSODisplay
{
public:

    void setupUi(QWidget *DSODisplay)
    {
        if (DSODisplay->objectName().isEmpty())
            DSODisplay->setObjectName(QString::fromUtf8("DSODisplay"));
        DSODisplay->resize(795, 500);

        retranslateUi(DSODisplay);

        QMetaObject::connectSlotsByName(DSODisplay);
    } // setupUi

    void retranslateUi(QWidget *DSODisplay)
    {
        DSODisplay->setWindowTitle(QApplication::translate("DSODisplay", "DSODisplay", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DSODisplay: public Ui_DSODisplay {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DSODISPLAY_H
