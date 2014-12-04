/********************************************************************************
** Form generated from reading UI file 'about.ui'
**
** Created: Thu Dec 4 10:15:31 2014
**      by: Qt User Interface Compiler version 4.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUT_H
#define UI_ABOUT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_About
{
public:
    QFrame *logo;
    QPushButton *pbClose;
    QFrame *frame;

    void setupUi(QDialog *About)
    {
        if (About->objectName().isEmpty())
            About->setObjectName(QString::fromUtf8("About"));
        About->resize(600, 400);
        logo = new QFrame(About);
        logo->setObjectName(QString::fromUtf8("logo"));
        logo->setGeometry(QRect(-3, -7, 610, 90));
        logo->setStyleSheet(QString::fromUtf8("image: url(:/logo.png);"));
        logo->setFrameShape(QFrame::StyledPanel);
        logo->setFrameShadow(QFrame::Raised);
        pbClose = new QPushButton(logo);
        pbClose->setObjectName(QString::fromUtf8("pbClose"));
        pbClose->setGeometry(QRect(548, 9, 50, 40));
        QFont font;
        font.setFamily(QString::fromUtf8("DejaVu Sans"));
        font.setPointSize(12);
        pbClose->setFont(font);
        pbClose->setStyleSheet(QString::fromUtf8("border:1px solid black;\n"
"border-radius:10px;"));
        frame = new QFrame(About);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(-149, 55, 749, 370));
        frame->setStyleSheet(QString::fromUtf8("image: url(:/intro.png);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        frame->raise();
        logo->raise();

        retranslateUi(About);

        QMetaObject::connectSlotsByName(About);
    } // setupUi

    void retranslateUi(QDialog *About)
    {
        About->setWindowTitle(QApplication::translate("About", "About", 0, QApplication::UnicodeUTF8));
        pbClose->setText(QApplication::translate("About", "CLOSE", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class About: public Ui_About {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUT_H
