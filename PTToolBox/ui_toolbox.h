/********************************************************************************
** Form generated from reading UI file 'toolbox.ui'
**
** Created: Tue Sep 23 18:40:48 2014
**      by: Qt User Interface Compiler version 4.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOOLBOX_H
#define UI_TOOLBOX_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ToolBox
{
public:
    QGroupBox *groupBox;
    QPushButton *pb_datetime;
    QLabel *label;
    QLabel *label_3;
    QPushButton *pb_touchcalib;
    QPushButton *pb_curEnDis;
    QLabel *label_5;
    QGroupBox *groupBox_2;
    QPushButton *pb_selftest;
    QLabel *label_2;
    QLabel *label_4;
    QPushButton *pb_testjig;
    QPushButton *pb_exit;

    void setupUi(QWidget *ToolBox)
    {
        if (ToolBox->objectName().isEmpty())
            ToolBox->setObjectName(QString::fromUtf8("ToolBox"));
        ToolBox->resize(350, 300);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/res/Folder-Settings-Tools-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        ToolBox->setWindowIcon(icon);
        ToolBox->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	font:bold 12px;\n"
"    border:1px solid yellow;border-radius:10px;\n"
"	background-color:white;\n"
"	color:black;\n"
"}     "));
        groupBox = new QGroupBox(ToolBox);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(7, 2, 334, 125));
        QFont font;
        font.setBold(true);
        font.setItalic(false);
        font.setWeight(75);
        groupBox->setFont(font);
        groupBox->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"     background-color: rgba(0,0,0,0);background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #ffffff, stop: 1 #dadbff);\n"
"     border: 2px solid black;\n"
"     border-radius: 5px;\n"
"     margin-top: 1ex; /* leave space at the top for the title */\n"
"	 font:bold 14px;	\n"
" }\n"
"\n"
" QGroupBox::title {\n"
"	border:1px solid white;\n"
"	border-radius:5px;\n"
"     subcontrol-origin: margin;\n"
"     subcontrol-position: top center; /* position at the top center */\n"
"     padding: 0 3px;\n"
"	 color:white;\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #3a5976, stop: 1 #000000);\n"
" }"));
        pb_datetime = new QPushButton(groupBox);
        pb_datetime->setObjectName(QString::fromUtf8("pb_datetime"));
        pb_datetime->setGeometry(QRect(40, 25, 55, 55));
        pb_datetime->setFont(font);
        pb_datetime->setFocusPolicy(Qt::NoFocus);
        pb_datetime->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"         border: 2px solid rgba(0,0,0,0);\n"
"         border-radius: 25px;\n"
"         background-color: rgba(0,0,0,0);\n"
"     }"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/res/Apps-preferences-system-time-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_datetime->setIcon(icon1);
        pb_datetime->setIconSize(QSize(48, 48));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 81, 100, 30));
        label->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(119, 81, 100, 30));
        label_3->setAlignment(Qt::AlignCenter);
        pb_touchcalib = new QPushButton(groupBox);
        pb_touchcalib->setObjectName(QString::fromUtf8("pb_touchcalib"));
        pb_touchcalib->setGeometry(QRect(140, 25, 55, 55));
        pb_touchcalib->setFont(font);
        pb_touchcalib->setFocusPolicy(Qt::NoFocus);
        pb_touchcalib->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"         border: 2px solid rgba(0,0,0,0);\n"
"         border-radius: 25px;\n"
"         background-color: rgba(0,0,0,0);\n"
"     }"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/res/tablet-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_touchcalib->setIcon(icon2);
        pb_touchcalib->setIconSize(QSize(48, 48));
        pb_curEnDis = new QPushButton(groupBox);
        pb_curEnDis->setObjectName(QString::fromUtf8("pb_curEnDis"));
        pb_curEnDis->setGeometry(QRect(247, 25, 55, 55));
        pb_curEnDis->setFont(font);
        pb_curEnDis->setFocusPolicy(Qt::NoFocus);
        pb_curEnDis->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"         border: 2px solid rgba(0,0,0,0);\n"
"         border-radius: 25px;\n"
"         background-color: rgba(0,0,0,0);\n"
"     }"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/res/Very-Basic-Cursor-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_curEnDis->setIcon(icon3);
        pb_curEnDis->setIconSize(QSize(48, 48));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(227, 81, 100, 30));
        label_5->setAlignment(Qt::AlignCenter);
        groupBox_2 = new QGroupBox(ToolBox);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(7, 122, 335, 125));
        groupBox_2->setFont(font);
        groupBox_2->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"     background-color: rgba(0,0,0,0);background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #ffffff, stop: 1 #dadbff);\n"
"     border: 2px solid black;\n"
"     border-radius: 5px;\n"
"     margin-top: 1ex; /* leave space at the top for the title */\n"
"	 font:bold 14px;	\n"
" }\n"
"\n"
" QGroupBox::title {\n"
"	border:1px solid white;\n"
"	border-radius:5px;\n"
"     subcontrol-origin: margin;\n"
"     subcontrol-position: top center; /* position at the top center */\n"
"     padding: 0 3px;\n"
"	 color:white;\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #3a5976, stop: 1 #000000);\n"
" }"));
        pb_selftest = new QPushButton(groupBox_2);
        pb_selftest->setObjectName(QString::fromUtf8("pb_selftest"));
        pb_selftest->setGeometry(QRect(40, 25, 55, 55));
        pb_selftest->setFont(font);
        pb_selftest->setFocusPolicy(Qt::NoFocus);
        pb_selftest->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"         border: 2px solid rgba(0,0,0,0);\n"
"		 border-radius:25px;\n"
"         background-color: rgba(0,0,0,0);\n"
"     }\n"
" QPushButton:pressed {\n"
"         border: 1px dotted rgba(1,1,1,255);\n"
"		 border-radius:15px;	\n"
"         background-color: rgba(0,0,0,0);\n"
"}\n"
""));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/res/application-check-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_selftest->setIcon(icon4);
        pb_selftest->setIconSize(QSize(48, 48));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 81, 80, 20));
        label_2->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(151, 81, 80, 20));
        label_4->setAlignment(Qt::AlignCenter);
        pb_testjig = new QPushButton(groupBox_2);
        pb_testjig->setObjectName(QString::fromUtf8("pb_testjig"));
        pb_testjig->setGeometry(QRect(162, 25, 55, 55));
        pb_testjig->setFont(font);
        pb_testjig->setFocusPolicy(Qt::NoFocus);
        pb_testjig->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"         border: 2px solid rgba(0,0,0,0);\n"
"         border-radius: 25px;\n"
"         background-color: rgba(0,0,0,0);\n"
"     }"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/res/Utilities-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_testjig->setIcon(icon5);
        pb_testjig->setIconSize(QSize(48, 48));
        pb_exit = new QPushButton(ToolBox);
        pb_exit->setObjectName(QString::fromUtf8("pb_exit"));
        pb_exit->setGeometry(QRect(120, 250, 100, 34));
        pb_exit->setFont(font);
        pb_exit->setFocusPolicy(Qt::NoFocus);
        pb_exit->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color:white;\n"
"border: 1px solid #2D5059;\n"
"border-radius: 10px;\n"
"background-color: qlineargradient(x1: 0, y1: 1, x2: 1, y2: 0,stop: 0 #000000, stop: 0.6 #292929 , stop:1 #FFFFFF);\n"
"font:bold 14px;\n"
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
        pb_exit->setIconSize(QSize(65, 40));

        retranslateUi(ToolBox);

        QMetaObject::connectSlotsByName(ToolBox);
    } // setupUi

    void retranslateUi(QWidget *ToolBox)
    {
        ToolBox->setWindowTitle(QApplication::translate("ToolBox", "ToolBox", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("ToolBox", "UTILITY PANEL", 0, QApplication::UnicodeUTF8));
        pb_datetime->setText(QString());
        label->setText(QApplication::translate("ToolBox", "DATE/TIME\n"
"ADJUSTMENT", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ToolBox", "TOUCH\n"
"CALIBRATION", 0, QApplication::UnicodeUTF8));
        pb_touchcalib->setText(QString());
        pb_curEnDis->setText(QString());
        label_5->setText(QApplication::translate("ToolBox", "CURSOR\n"
"ON/OFF", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("ToolBox", "TEST PANEL", 0, QApplication::UnicodeUTF8));
        pb_selftest->setText(QString());
        label_2->setText(QApplication::translate("ToolBox", "SELF TEST", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("ToolBox", "TESTJIG", 0, QApplication::UnicodeUTF8));
        pb_testjig->setText(QString());
        pb_exit->setText(QApplication::translate("ToolBox", "CLOSE", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ToolBox: public Ui_ToolBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOOLBOX_H
