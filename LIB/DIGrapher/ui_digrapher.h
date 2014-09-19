/********************************************************************************
** Form generated from reading UI file 'digrapher.ui'
**
** Created: Wed Sep 10 15:47:05 2014
**      by: Qt User Interface Compiler version 4.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIGRAPHER_H
#define UI_DIGRAPHER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_DIGrapher
{
public:
    QGridLayout *gridLayout;
    QCustomPlot *plotter;
    QPushButton *ZoomIn;
    QPushButton *ZoomOut;
    QPushButton *Refresh;

    void setupUi(QWidget *DIGrapher)
    {
        if (DIGrapher->objectName().isEmpty())
            DIGrapher->setObjectName(QString::fromUtf8("DIGrapher"));
        DIGrapher->resize(600, 200);
        gridLayout = new QGridLayout(DIGrapher);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        plotter = new QCustomPlot(DIGrapher);
        plotter->setObjectName(QString::fromUtf8("plotter"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(plotter->sizePolicy().hasHeightForWidth());
        plotter->setSizePolicy(sizePolicy);
        ZoomIn = new QPushButton(plotter);
        ZoomIn->setObjectName(QString::fromUtf8("ZoomIn"));
        ZoomIn->setGeometry(QRect(0, -2, 31, 31));
        ZoomIn->setFocusPolicy(Qt::NoFocus);
        ZoomIn->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border: 1px solid rgba(0,0,0,0);\n"
"background-color: rgba(0, 0, 0, 0);\n"
"image: url(:/res/Zoom-In-icon.png);\n"
"}"));
        ZoomOut = new QPushButton(plotter);
        ZoomOut->setObjectName(QString::fromUtf8("ZoomOut"));
        ZoomOut->setGeometry(QRect(0, -2, 31, 31));
        ZoomOut->setFocusPolicy(Qt::NoFocus);
        ZoomOut->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border: 1px solid rgba(0,0,0,0);\n"
"background-color: rgba(0, 0, 0, 0);\n"
"image: url(:/res/Zoom-Out-icon.png);\n"
"}"));
        Refresh = new QPushButton(plotter);
        Refresh->setObjectName(QString::fromUtf8("Refresh"));
        Refresh->setGeometry(QRect(26, -2, 31, 31));
        Refresh->setFocusPolicy(Qt::NoFocus);
        Refresh->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border: 1px solid rgba(0,0,0,0);\n"
"background-color: rgba(0, 0, 0, 0);\n"
"	image: url(:/res/Refresh-icon.png);\n"
"}"));
        ZoomOut->raise();
        ZoomIn->raise();
        Refresh->raise();

        gridLayout->addWidget(plotter, 0, 0, 1, 1);


        retranslateUi(DIGrapher);

        QMetaObject::connectSlotsByName(DIGrapher);
    } // setupUi

    void retranslateUi(QWidget *DIGrapher)
    {
        DIGrapher->setWindowTitle(QApplication::translate("DIGrapher", "DIGrapher", 0, QApplication::UnicodeUTF8));
        ZoomIn->setText(QString());
        ZoomOut->setText(QString());
        Refresh->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DIGrapher: public Ui_DIGrapher {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIGRAPHER_H
