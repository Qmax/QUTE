/********************************************************************************
** Form generated from reading UI file 'probestatus.ui'
**
** Created: Mon Oct 28 11:12:10 2013
**      by: Qt User Interface Compiler version 4.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROBESTATUS_H
#define UI_PROBESTATUS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProbeStatus
{
public:
    QFrame *frame_2;
    QFrame *frame_3;
    QFrame *frame_4;
    QFrame *frame;
    QFrame *frame_5;
    QFrame *frame_6;
    QToolButton *toolButton;

    void setupUi(QWidget *ProbeStatus)
    {
        if (ProbeStatus->objectName().isEmpty())
            ProbeStatus->setObjectName(QString::fromUtf8("ProbeStatus"));
        ProbeStatus->setWindowModality(Qt::WindowModal);
        ProbeStatus->resize(564, 120);
        frame_2 = new QFrame(ProbeStatus);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(74, 10, 81, 101));
        frame_2->setFrameShape(QFrame::Panel);
        frame_2->setFrameShadow(QFrame::Raised);
        frame_3 = new QFrame(ProbeStatus);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setGeometry(QRect(174, 10, 151, 101));
        frame_3->setFrameShape(QFrame::Panel);
        frame_3->setFrameShadow(QFrame::Raised);
        frame_4 = new QFrame(ProbeStatus);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setGeometry(QRect(334, 10, 81, 101));
        frame_4->setFrameShape(QFrame::Panel);
        frame_4->setFrameShadow(QFrame::Raised);
        frame = new QFrame(frame_4);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(10, 20, 61, 16));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Plain);
        frame_5 = new QFrame(frame_4);
        frame_5->setObjectName(QString::fromUtf8("frame_5"));
        frame_5->setGeometry(QRect(10, 60, 61, 16));
        frame_5->setFrameShape(QFrame::Box);
        frame_5->setFrameShadow(QFrame::Plain);
        frame_6 = new QFrame(ProbeStatus);
        frame_6->setObjectName(QString::fromUtf8("frame_6"));
        frame_6->setGeometry(QRect(440, 44, 111, 31));
        frame_6->setFrameShape(QFrame::Box);
        frame_6->setFrameShadow(QFrame::Plain);
        toolButton = new QToolButton(ProbeStatus);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setGeometry(QRect(10, 10, 30, 101));

        retranslateUi(ProbeStatus);

        QMetaObject::connectSlotsByName(ProbeStatus);
    } // setupUi

    void retranslateUi(QWidget *ProbeStatus)
    {
        ProbeStatus->setWindowTitle(QApplication::translate("ProbeStatus", "Form", 0, QApplication::UnicodeUTF8));
        toolButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ProbeStatus: public Ui_ProbeStatus {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROBESTATUS_H
