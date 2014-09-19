/********************************************************************************
** Form generated from reading UI file 'dialwidget.ui'
**
** Created: Tue Apr 8 11:32:17 2014
**      by: Qt User Interface Compiler version 4.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALWIDGET_H
#define UI_DIALWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dialWidget
{
public:
    QGroupBox *grpVoltDiv;
    QGroupBox *grpTimeDiv;
    QPushButton *butClose;

    void setupUi(QWidget *dialWidget)
    {
        if (dialWidget->objectName().isEmpty())
            dialWidget->setObjectName(QString::fromUtf8("dialWidget"));
        dialWidget->setWindowModality(Qt::WindowModal);
        dialWidget->resize(367, 246);
        dialWidget->setCursor(QCursor(Qt::BlankCursor));
        dialWidget->setStyleSheet(QString::fromUtf8("QWidget\n"
"{\n"
"background-color: rgb(108, 108, 107);\n"
"}"));
        grpVoltDiv = new QGroupBox(dialWidget);
        grpVoltDiv->setObjectName(QString::fromUtf8("grpVoltDiv"));
        grpVoltDiv->setGeometry(QRect(9, 25, 170, 170));
        grpVoltDiv->setCursor(QCursor(Qt::BlankCursor));
        grpTimeDiv = new QGroupBox(dialWidget);
        grpTimeDiv->setObjectName(QString::fromUtf8("grpTimeDiv"));
        grpTimeDiv->setGeometry(QRect(190, 25, 170, 170));
        grpTimeDiv->setCursor(QCursor(Qt::BlankCursor));
        butClose = new QPushButton(dialWidget);
        butClose->setObjectName(QString::fromUtf8("butClose"));
        butClose->setGeometry(QRect(150, 200, 71, 41));
        butClose->setFocusPolicy(Qt::NoFocus);

        retranslateUi(dialWidget);

        QMetaObject::connectSlotsByName(dialWidget);
    } // setupUi

    void retranslateUi(QWidget *dialWidget)
    {
        dialWidget->setWindowTitle(QApplication::translate("dialWidget", "Dial Selection", 0, QApplication::UnicodeUTF8));
        dialWidget->setWindowFilePath(QApplication::translate("dialWidget", "DialSelection", 0, QApplication::UnicodeUTF8));
        grpVoltDiv->setTitle(QApplication::translate("dialWidget", "Volt/Div", 0, QApplication::UnicodeUTF8));
        grpTimeDiv->setTitle(QApplication::translate("dialWidget", "Time/Div", 0, QApplication::UnicodeUTF8));
        butClose->setText(QApplication::translate("dialWidget", "Close", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class dialWidget: public Ui_dialWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALWIDGET_H
