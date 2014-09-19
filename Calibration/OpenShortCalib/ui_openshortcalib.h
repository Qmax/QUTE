/********************************************************************************
** Form generated from reading UI file 'openshortcalib.ui'
**
** Created: Mon Sep 16 16:10:05 2013
**      by: Qt User Interface Compiler version 4.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPENSHORTCALIB_H
#define UI_OPENSHORTCALIB_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OpenShortCalib
{
public:
    QGroupBox *gbBasePanel;
    QLabel *lblComponent;
    QComboBox *cmbCompnt;
    QLabel *lblMethod;
    QCheckBox *chkOpen;
    QCheckBox *chkShort;
    QCheckBox *chkLoad;
    QPushButton *pbCalibrate;
    QCheckBox *chkCalibrated;
    QPushButton *pbMeasure;
    QPushButton *pbStop;
    QLabel *lblMeasured;
    QLineEdit *leMeasured;
    QPushButton *pbClose;
    QComboBox *cmbRRange;
    QLabel *lblRange;
    QComboBox *cmbLRange;
    QComboBox *cmbCRange;

    void setupUi(QWidget *OpenShortCalib)
    {
        if (OpenShortCalib->objectName().isEmpty())
            OpenShortCalib->setObjectName(QString::fromUtf8("OpenShortCalib"));
        OpenShortCalib->resize(400, 300);
        OpenShortCalib->setStyleSheet(QString::fromUtf8("QWidget{\n"
"background-color:rgba(0,0,0,0);\n"
"}"));
        gbBasePanel = new QGroupBox(OpenShortCalib);
        gbBasePanel->setObjectName(QString::fromUtf8("gbBasePanel"));
        gbBasePanel->setGeometry(QRect(4, 3, 392, 290));
        gbBasePanel->setFocusPolicy(Qt::NoFocus);
        gbBasePanel->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"background:qlineargradient(\n"
"x1: 0, y1: 0, x2: 1, y2: 1, \n"
"stop: 0 #a9aa96,stop: 0.2 #cab9a9,\n"
"stop: 0.4 #d8d7c8,stop: 0.6 #a9aa96, \n"
"stop: 0.8 #cab9a9,stop: 1 #717164);\n"
"     border: 1px solid gray;\n"
"     border-radius: 5px;\n"
"     margin-top: 1ex; /* leave space at the top for the title */\n"
"	font:16px bold;\n"
"	color:black;\n"
" }\n"
"\n"
" QGroupBox::title {\n"
"     subcontrol-origin: margin;\n"
"     subcontrol-position: top center; /* position at the top center */\n"
"     padding: 0 3px;\n"
"	 background-color:white;\n"
"     border:1px solid black;\n"
"	border-radius:5px;\n"
" }\n"
""));
        lblComponent = new QLabel(gbBasePanel);
        lblComponent->setObjectName(QString::fromUtf8("lblComponent"));
        lblComponent->setGeometry(QRect(10, 40, 150, 17));
        QFont font;
        font.setFamily(QString::fromUtf8("DejaVu Sans"));
        lblComponent->setFont(font);
        lblComponent->setFocusPolicy(Qt::NoFocus);
        cmbCompnt = new QComboBox(gbBasePanel);
        cmbCompnt->setObjectName(QString::fromUtf8("cmbCompnt"));
        cmbCompnt->setGeometry(QRect(170, 40, 140, 20));
        cmbCompnt->setFocusPolicy(Qt::NoFocus);
        cmbCompnt->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"     border: 2px solid black;\n"
"     border-radius: 5px;\n"
"     padding: 1px 18px 1px 3px;\n"
"	background-color:white;\n"
"	color:black;\n"
" }\n"
""));
        lblMethod = new QLabel(gbBasePanel);
        lblMethod->setObjectName(QString::fromUtf8("lblMethod"));
        lblMethod->setGeometry(QRect(10, 110, 140, 20));
        lblMethod->setFont(font);
        lblMethod->setFocusPolicy(Qt::NoFocus);
        chkOpen = new QCheckBox(gbBasePanel);
        chkOpen->setObjectName(QString::fromUtf8("chkOpen"));
        chkOpen->setGeometry(QRect(140, 110, 120, 20));
        QFont font1;
        font1.setFamily(QString::fromUtf8("12"));
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        chkOpen->setFont(font1);
        chkOpen->setFocusPolicy(Qt::NoFocus);
        chkOpen->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
"font: 14px bold;\n"
"color:black;\n"
"}\n"
" QCheckBox::indicator {\n"
"     width: 16px;\n"
"     height:16px;\n"
"   border: 2px solid black;\n"
"	 border-radius:1;\n"
"\n"
" }\n"
" QCheckBox::indicator::unchecked {\n"
"		background-color:white;\n"
"     }\n"
"\n"
"     QCheckBox::indicator:unchecked:hover {\n"
"		background-color:white;\n"
"     }\n"
"\n"
"     QCheckBox::indicator:unchecked:pressed {\n"
"		background-color:white;\n"
"     }\n"
"\n"
"     QCheckBox::indicator::checked {\n"
"		background-color:#f2a400;\n"
"     }\n"
"\n"
"     QCheckBox::indicator:checked:hover {\n"
"		background-color:#f2a400;\n"
"     }\n"
"\n"
"     QCheckBox::indicator:checked:pressed {\n"
"		background-color:#f2a400;\n"
"     }"));
        chkShort = new QCheckBox(gbBasePanel);
        chkShort->setObjectName(QString::fromUtf8("chkShort"));
        chkShort->setGeometry(QRect(270, 110, 120, 20));
        chkShort->setFont(font1);
        chkShort->setFocusPolicy(Qt::NoFocus);
        chkShort->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
"font: 14px bold;\n"
"color:black;\n"
"}\n"
" QCheckBox::indicator {\n"
"     width: 16px;\n"
"     height:16px;\n"
"   border: 2px solid black;\n"
"	 border-radius:1;\n"
"\n"
" }\n"
" QCheckBox::indicator::unchecked {\n"
"		background-color:white;\n"
"     }\n"
"\n"
"     QCheckBox::indicator:unchecked:hover {\n"
"		background-color:white;\n"
"     }\n"
"\n"
"     QCheckBox::indicator:unchecked:pressed {\n"
"		background-color:white;\n"
"     }\n"
"\n"
"     QCheckBox::indicator::checked {\n"
"		background-color:#f2a400;\n"
"     }\n"
"\n"
"     QCheckBox::indicator:checked:hover {\n"
"		background-color:#f2a400;\n"
"     }\n"
"\n"
"     QCheckBox::indicator:checked:pressed {\n"
"		background-color:#f2a400;\n"
"     }"));
        chkLoad = new QCheckBox(gbBasePanel);
        chkLoad->setObjectName(QString::fromUtf8("chkLoad"));
        chkLoad->setGeometry(QRect(140, 150, 150, 20));
        chkLoad->setFont(font1);
        chkLoad->setFocusPolicy(Qt::NoFocus);
        chkLoad->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
"font: 14px bold;\n"
"color:black;\n"
"}\n"
" QCheckBox::indicator {\n"
"     width: 16px;\n"
"     height:16px;\n"
"   border: 2px solid black;\n"
"	 border-radius:1;\n"
"\n"
" }\n"
" QCheckBox::indicator::unchecked {\n"
"		background-color:white;\n"
"     }\n"
"\n"
"     QCheckBox::indicator:unchecked:hover {\n"
"		background-color:white;\n"
"     }\n"
"\n"
"     QCheckBox::indicator:unchecked:pressed {\n"
"		background-color:white;\n"
"     }\n"
"\n"
"     QCheckBox::indicator::checked {\n"
"		background-color:#f2a400;\n"
"     }\n"
"\n"
"     QCheckBox::indicator:checked:hover {\n"
"		background-color:#f2a400;\n"
"     }\n"
"\n"
"     QCheckBox::indicator:checked:pressed {\n"
"		background-color:#f2a400;\n"
"     }"));
        pbCalibrate = new QPushButton(gbBasePanel);
        pbCalibrate->setObjectName(QString::fromUtf8("pbCalibrate"));
        pbCalibrate->setGeometry(QRect(203, 240, 82, 27));
        QFont font2;
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(50);
        pbCalibrate->setFont(font2);
        pbCalibrate->setFocusPolicy(Qt::NoFocus);
        pbCalibrate->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"color:white;\n"
"border: 1px solid #2D5059;\n"
"border-radius: 10px;\n"
"background-color: \n"
"qlineargradient(x1: 0, y1: 1, x2: 1, y2: 0,\n"
"stop: 0 #1A74DB, \n"
"stop: 0.6 #5293DE, \n"
"stop:1 #FFFFFF);\n"
"min-width: 80px;\n"
"font: 12px;}"));
        chkCalibrated = new QCheckBox(gbBasePanel);
        chkCalibrated->setObjectName(QString::fromUtf8("chkCalibrated"));
        chkCalibrated->setGeometry(QRect(290, 190, 110, 22));
        chkCalibrated->setFocusPolicy(Qt::NoFocus);
        chkCalibrated->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
"font: 14px bold;\n"
"color:black;\n"
"}\n"
" QCheckBox::indicator {\n"
"     width: 16px;\n"
"     height:16px;\n"
"   border: 2px solid black;\n"
"	 border-radius:1;\n"
"\n"
" }\n"
" QCheckBox::indicator::unchecked {\n"
"		background-color:white;\n"
"     }\n"
"\n"
"     QCheckBox::indicator:unchecked:hover {\n"
"		background-color:white;\n"
"     }\n"
"\n"
"     QCheckBox::indicator:unchecked:pressed {\n"
"		background-color:white;\n"
"     }\n"
"\n"
"     QCheckBox::indicator::checked {\n"
"		background-color:#f2a400;\n"
"     }\n"
"\n"
"     QCheckBox::indicator:checked:hover {\n"
"		background-color:#f2a400;\n"
"     }\n"
"\n"
"     QCheckBox::indicator:checked:pressed {\n"
"		background-color:#f2a400;\n"
"     }"));
        pbMeasure = new QPushButton(gbBasePanel);
        pbMeasure->setObjectName(QString::fromUtf8("pbMeasure"));
        pbMeasure->setGeometry(QRect(10, 240, 82, 27));
        pbMeasure->setFont(font2);
        pbMeasure->setFocusPolicy(Qt::NoFocus);
        pbMeasure->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"color:white;\n"
"border: 1px solid #2D5059;\n"
"border-radius: 10px;\n"
"background-color: \n"
"qlineargradient(x1: 0, y1: 1, x2: 1, y2: 0,\n"
"stop: 0 #1A74DB, \n"
"stop: 0.6 #5293DE, \n"
"stop:1 #FFFFFF);\n"
"min-width: 80px;\n"
"font: 12px;}"));
        pbStop = new QPushButton(gbBasePanel);
        pbStop->setObjectName(QString::fromUtf8("pbStop"));
        pbStop->setGeometry(QRect(106, 240, 82, 27));
        pbStop->setFont(font2);
        pbStop->setFocusPolicy(Qt::NoFocus);
        pbStop->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"color:white;\n"
"border: 1px solid #2D5059;\n"
"border-radius: 10px;\n"
"background-color: \n"
"qlineargradient(x1: 0, y1: 1, x2: 1, y2: 0,\n"
"stop: 0 #1A74DB, \n"
"stop: 0.6 #5293DE, \n"
"stop:1 #FFFFFF);\n"
"min-width: 80px;\n"
"font: 12px;}"));
        lblMeasured = new QLabel(gbBasePanel);
        lblMeasured->setObjectName(QString::fromUtf8("lblMeasured"));
        lblMeasured->setGeometry(QRect(10, 190, 140, 20));
        lblMeasured->setFont(font);
        lblMeasured->setFocusPolicy(Qt::NoFocus);
        leMeasured = new QLineEdit(gbBasePanel);
        leMeasured->setObjectName(QString::fromUtf8("leMeasured"));
        leMeasured->setGeometry(QRect(140, 190, 140, 23));
        leMeasured->setFocusPolicy(Qt::NoFocus);
        leMeasured->setStyleSheet(QString::fromUtf8(" QLineEdit {\n"
"     border: 2px solid black;\n"
"     border-radius: 5px;\n"
"     padding: 0 8px;\n"
"     background: white;\n"
"     selection-background-color: darkgray;\n"
"	 color:black;\n"
"     font: bold 12px;\n"
" }"));
        pbClose = new QPushButton(gbBasePanel);
        pbClose->setObjectName(QString::fromUtf8("pbClose"));
        pbClose->setGeometry(QRect(300, 240, 82, 27));
        pbClose->setFont(font2);
        pbClose->setFocusPolicy(Qt::NoFocus);
        pbClose->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"color:white;\n"
"border: 1px solid #2D5059;\n"
"border-radius: 10px;\n"
"background-color: \n"
"qlineargradient(x1: 0, y1: 1, x2: 1, y2: 0,\n"
"stop: 0 #1A74DB, \n"
"stop: 0.6 #5293DE, \n"
"stop:1 #FFFFFF);\n"
"min-width: 80px;\n"
"font: 12px;}"));
        cmbRRange = new QComboBox(gbBasePanel);
        cmbRRange->setObjectName(QString::fromUtf8("cmbRRange"));
        cmbRRange->setGeometry(QRect(170, 70, 100, 20));
        cmbRRange->setFocusPolicy(Qt::NoFocus);
        cmbRRange->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"     border: 2px solid black;\n"
"     border-radius: 5px;\n"
" 	background-color:white;\n"
"	color:black;\n"
" }\n"
""));
        lblRange = new QLabel(gbBasePanel);
        lblRange->setObjectName(QString::fromUtf8("lblRange"));
        lblRange->setGeometry(QRect(10, 70, 150, 17));
        lblRange->setFont(font);
        lblRange->setFocusPolicy(Qt::NoFocus);
        cmbLRange = new QComboBox(gbBasePanel);
        cmbLRange->setObjectName(QString::fromUtf8("cmbLRange"));
        cmbLRange->setGeometry(QRect(170, 70, 100, 20));
        cmbLRange->setFocusPolicy(Qt::NoFocus);
        cmbLRange->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"     border: 2px solid black;\n"
"     border-radius: 5px;\n"
"     padding: 1px 18px 1px 3px;\n"
"	background-color:white;\n"
"	color:black;\n"
" }\n"
""));
        cmbCRange = new QComboBox(gbBasePanel);
        cmbCRange->setObjectName(QString::fromUtf8("cmbCRange"));
        cmbCRange->setGeometry(QRect(170, 70, 100, 20));
        cmbCRange->setFocusPolicy(Qt::NoFocus);
        cmbCRange->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"     border: 2px solid black;\n"
"     border-radius: 5px;\n"
"     padding: 1px 18px 1px 3px;\n"
"	background-color:white;\n"
"	color:black;\n"
" }\n"
""));

        retranslateUi(OpenShortCalib);

        QMetaObject::connectSlotsByName(OpenShortCalib);
    } // setupUi

    void retranslateUi(QWidget *OpenShortCalib)
    {
        OpenShortCalib->setWindowTitle(QApplication::translate("OpenShortCalib", "OpenShortCalib", 0, QApplication::UnicodeUTF8));
        gbBasePanel->setTitle(QApplication::translate("OpenShortCalib", "Open/Short Calibration Panel", 0, QApplication::UnicodeUTF8));
        lblComponent->setText(QApplication::translate("OpenShortCalib", "Select Component :", 0, QApplication::UnicodeUTF8));
        cmbCompnt->clear();
        cmbCompnt->insertItems(0, QStringList()
         << QApplication::translate("OpenShortCalib", "Resistance", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("OpenShortCalib", "Inductance", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("OpenShortCalib", "Capacitance", 0, QApplication::UnicodeUTF8)
        );
        lblMethod->setText(QApplication::translate("OpenShortCalib", "Select Method :", 0, QApplication::UnicodeUTF8));
        chkOpen->setText(QApplication::translate("OpenShortCalib", "Probes Open", 0, QApplication::UnicodeUTF8));
        chkShort->setText(QApplication::translate("OpenShortCalib", "Probes Short", 0, QApplication::UnicodeUTF8));
        chkLoad->setText(QApplication::translate("OpenShortCalib", "Probes with Load", 0, QApplication::UnicodeUTF8));
        pbCalibrate->setText(QApplication::translate("OpenShortCalib", "Calibrate", 0, QApplication::UnicodeUTF8));
        chkCalibrated->setText(QApplication::translate("OpenShortCalib", "Calibrated", 0, QApplication::UnicodeUTF8));
        pbMeasure->setText(QApplication::translate("OpenShortCalib", "Measure", 0, QApplication::UnicodeUTF8));
        pbStop->setText(QApplication::translate("OpenShortCalib", "Stop", 0, QApplication::UnicodeUTF8));
        lblMeasured->setText(QApplication::translate("OpenShortCalib", "Measured Value :", 0, QApplication::UnicodeUTF8));
        pbClose->setText(QApplication::translate("OpenShortCalib", "Close", 0, QApplication::UnicodeUTF8));
        cmbRRange->clear();
        cmbRRange->insertItems(0, QStringList()
         << QApplication::translate("OpenShortCalib", "10E", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("OpenShortCalib", "100E", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("OpenShortCalib", "1KE", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("OpenShortCalib", "10KE", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("OpenShortCalib", "100KE", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("OpenShortCalib", "1ME", 0, QApplication::UnicodeUTF8)
        );
        lblRange->setText(QApplication::translate("OpenShortCalib", "Select Range :", 0, QApplication::UnicodeUTF8));
        cmbLRange->clear();
        cmbLRange->insertItems(0, QStringList()
         << QApplication::translate("OpenShortCalib", "30uH", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("OpenShortCalib", "300uH", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("OpenShortCalib", "3mH", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("OpenShortCalib", "30mH", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("OpenShortCalib", "300mH", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("OpenShortCalib", "3H", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("OpenShortCalib", "30H", 0, QApplication::UnicodeUTF8)
        );
        cmbCRange->clear();
        cmbCRange->insertItems(0, QStringList()
         << QApplication::translate("OpenShortCalib", "100pF", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("OpenShortCalib", "1nF", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("OpenShortCalib", "10nF", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("OpenShortCalib", "100nF", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("OpenShortCalib", "1uF", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("OpenShortCalib", "10uF", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("OpenShortCalib", "100uF", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("OpenShortCalib", "1mF", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("OpenShortCalib", "10mF", 0, QApplication::UnicodeUTF8)
        );
    } // retranslateUi

};

namespace Ui {
    class OpenShortCalib: public Ui_OpenShortCalib {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPENSHORTCALIB_H
