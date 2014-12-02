/********************************************************************************
** Form generated from reading UI file 'settings.ui'
**
** Created: Tue Dec 2 10:33:48 2014
**      by: Qt User Interface Compiler version 4.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGS_H
#define UI_SETTINGS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QFrame>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Settings
{
public:
    QWidget *widget;
    QGroupBox *groupBox;
    QPushButton *pushButton;
    QLabel *label;
    QLineEdit *lineEdit;
    QCheckBox *chkPOTSel;
    QCheckBox *chkDivSel;
    QLineEdit *lineEdit_2;
    QLabel *label_2;
    QCheckBox *chkCapSet;
    QFrame *line;
    QLabel *label_3;
    QLabel *label_4;
    QCheckBox *R1RMSCAVG;
    QCheckBox *R1RMSGAIN;
    QCheckBox *R1RMSIN;
    QCheckBox *R2RMSIN;
    QCheckBox *R2RMSGAIN;
    QCheckBox *R2RMSCAVG;
    QCheckBox *ExtInt;
    QLabel *label_5;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLabel *label_6;
    QPushButton *ReadAppCard;
    QPushButton *WriteAppCard;
    QGroupBox *groupBox_2;
    QPushButton *adc1;
    QPushButton *adc2;
    QGroupBox *groupBox_3;
    QPushButton *WriteAppCard_2;
    QLineEdit *lineEdit_5;
    QPushButton *ReadAppCard_2;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *lineEdit_6;
    QPushButton *up;
    QPushButton *down;
    QPushButton *right;
    QPushButton *left;
    QComboBox *comboBox;
    QLabel *label_9;
    QPushButton *pushButton_2;
    QLabel *label_10;
    QLineEdit *lineEdit_7;
    QLabel *label_11;
    QComboBox *srcImpBox_10;

    void setupUi(QWidget *Settings)
    {
        if (Settings->objectName().isEmpty())
            Settings->setObjectName(QString::fromUtf8("Settings"));
        Settings->resize(525, 425);
        Settings->setStyleSheet(QString::fromUtf8("QWidget{background-color: rgba(0,0,0,0);border:1px solid rgba(0,0,0,0);}\n"
""));
        widget = new QWidget(Settings);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(3, 3, 520, 425));
        widget->setStyleSheet(QString::fromUtf8("QLineEdit{border-width: 2px;border-style: outset;border-color: gray; border-radius: 1px;  padding: 0 8px;     background: black;     selection-background-color: yellow;   color:white;     font: bold 14px;}\n"
"\n"
"QComboBox{border-width: 2px;border-style: outset;border-color: gray; border-radius: 1px;  padding: 0 8px;     background: black;     selection-background-color: yellow;   color:white;     font: bold 14px;}\n"
"\n"
"QPushButton {border: 2px solid #8f8f91; border-radius: 8px; background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #f6f7fa, stop: 1 #dadbde); color:black;} QPushButton:pressed {background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #dadbde, stop: 1 #f6f7fa);} QPushButton:flat {border: none;} QPushButton:default {border-color: navy;}\n"
"\n"
"QLabel{background-color: rgba(0,0,0,0);font:14px bold;color:white;border:2px solid rgba(0,0,0,0);}\n"
"\n"
"QGroupBox {\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                 "
                        "      stop: 0 #3a5976, stop: 1 #000000);     border: 2px solid gray;\n"
"     border-radius: 5px;\n"
"     margin-top: 1ex; /* leave space at the top for the title */\n"
"	 font:bold 15px;	\n"
" }\n"
"\n"
" QGroupBox::title {\n"
"	border:2px solid white;\n"
"	border-radius:5px;\n"
"     subcontrol-origin: margin;\n"
"     subcontrol-position: top left; /* position at the top center */\n"
"     padding: 0 3px;\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #d8dff2, stop: 1 #FFFFFF);\n"
" }\n"
"\n"
"QCheckBox{\n"
"background-color: rgba(0,0,0,0);\n"
"border:2px solid rgba(0,0,0,0);\n"
"font: 14px;\n"
"color:white;\n"
"}\n"
" QCheckBox::indicator {\n"
"     width: 20px;\n"
"     height:20px;\n"
"	border:2px solid rgba(0,0,0,0);\n"
" }\n"
" QCheckBox::indicator::unchecked {\n"
"		background-color:white;\n"
"     }\n"
"\n"
"     QCheckBox::indicator:unchecked:hover {\n"
"		background-color:white;\n"
"     }\n"
"\n"
"     QCheckBox::indicator"
                        ":unchecked:pressed {\n"
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
"     }\n"
"QGridLayout{\n"
"	border:2px solid rgba(0,0,0,0);\n"
"\n"
"	}"));
        groupBox = new QGroupBox(widget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(0, -5, 520, 425));
        groupBox->setStyleSheet(QString::fromUtf8(""));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(410, 329, 90, 50));
        QFont font;
        font.setFamily(QString::fromUtf8("DejaVu Sans"));
        font.setPointSize(14);
        pushButton->setFont(font);
        pushButton->setFocusPolicy(Qt::NoFocus);
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 18, 167, 24));
        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(170, 17, 96, 24));
        chkPOTSel = new QCheckBox(groupBox);
        chkPOTSel->setObjectName(QString::fromUtf8("chkPOTSel"));
        chkPOTSel->setGeometry(QRect(10, 161, 167, 28));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(0, 0, 0, 0));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        chkPOTSel->setPalette(palette);
        chkPOTSel->setFocusPolicy(Qt::NoFocus);
        chkPOTSel->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
"font: 14px;\n"
"color:white\n"
"}\n"
" QCheckBox::indicator {\n"
"     width: 20px;\n"
"     height:20px;\n"
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
        chkDivSel = new QCheckBox(groupBox);
        chkDivSel->setObjectName(QString::fromUtf8("chkDivSel"));
        chkDivSel->setGeometry(QRect(10, 191, 167, 28));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        chkDivSel->setPalette(palette1);
        chkDivSel->setFocusPolicy(Qt::NoFocus);
        chkDivSel->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
"font: 14px;\n"
"color:white\n"
"}\n"
" QCheckBox::indicator {\n"
"     width: 20px;\n"
"     height:20px;\n"
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
        lineEdit_2 = new QLineEdit(groupBox);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(170, 44, 96, 24));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 44, 167, 24));
        chkCapSet = new QCheckBox(groupBox);
        chkCapSet->setObjectName(QString::fromUtf8("chkCapSet"));
        chkCapSet->setGeometry(QRect(10, 132, 167, 28));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        chkCapSet->setPalette(palette2);
        chkCapSet->setFocusPolicy(Qt::NoFocus);
        chkCapSet->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
"font: 14px;\n"
"color:white\n"
"}\n"
" QCheckBox::indicator {\n"
"     width: 20px;\n"
"     height:20px;\n"
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
        line = new QFrame(groupBox);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(290, 20, 1, 260));
        line->setStyleSheet(QString::fromUtf8("color:black;\n"
"background-color:black;"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(300, 20, 81, 17));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(300, 150, 81, 17));
        R1RMSCAVG = new QCheckBox(groupBox);
        R1RMSCAVG->setObjectName(QString::fromUtf8("R1RMSCAVG"));
        R1RMSCAVG->setGeometry(QRect(310, 40, 141, 28));
        R1RMSCAVG->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
"font: 14px;\n"
"color:white\n"
"}\n"
" QCheckBox::indicator {\n"
"     width: 20px;\n"
"     height:20px;\n"
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
        R1RMSGAIN = new QCheckBox(groupBox);
        R1RMSGAIN->setObjectName(QString::fromUtf8("R1RMSGAIN"));
        R1RMSGAIN->setGeometry(QRect(310, 70, 141, 28));
        R1RMSGAIN->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
"font: 14px;\n"
"color:white\n"
"}\n"
" QCheckBox::indicator {\n"
"     width: 20px;\n"
"     height:20px;\n"
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
        R1RMSIN = new QCheckBox(groupBox);
        R1RMSIN->setObjectName(QString::fromUtf8("R1RMSIN"));
        R1RMSIN->setGeometry(QRect(310, 100, 141, 28));
        R1RMSIN->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
"font: 14px;\n"
"color:white\n"
"}\n"
" QCheckBox::indicator {\n"
"     width: 20px;\n"
"     height:20px;\n"
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
        R2RMSIN = new QCheckBox(groupBox);
        R2RMSIN->setObjectName(QString::fromUtf8("R2RMSIN"));
        R2RMSIN->setGeometry(QRect(310, 230, 141, 28));
        R2RMSIN->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
"font: 14px;\n"
"color:white\n"
"}\n"
" QCheckBox::indicator {\n"
"     width: 20px;\n"
"     height:20px;\n"
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
        R2RMSGAIN = new QCheckBox(groupBox);
        R2RMSGAIN->setObjectName(QString::fromUtf8("R2RMSGAIN"));
        R2RMSGAIN->setGeometry(QRect(310, 200, 141, 28));
        R2RMSGAIN->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
"font: 14px;\n"
"color:white\n"
"}\n"
" QCheckBox::indicator {\n"
"     width: 20px;\n"
"     height:20px;\n"
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
        R2RMSCAVG = new QCheckBox(groupBox);
        R2RMSCAVG->setObjectName(QString::fromUtf8("R2RMSCAVG"));
        R2RMSCAVG->setGeometry(QRect(310, 170, 141, 28));
        R2RMSCAVG->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
"font: 14px;\n"
"color:white\n"
"}\n"
" QCheckBox::indicator {\n"
"     width: 20px;\n"
"     height:20px;\n"
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
        ExtInt = new QCheckBox(groupBox);
        ExtInt->setObjectName(QString::fromUtf8("ExtInt"));
        ExtInt->setGeometry(QRect(10, 220, 201, 28));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        ExtInt->setPalette(palette3);
        ExtInt->setFocusPolicy(Qt::NoFocus);
        ExtInt->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
"font: 14px;\n"
"color:white\n"
"}\n"
" QCheckBox::indicator {\n"
"     width: 20px;\n"
"     height:20px;\n"
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
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 278, 71, 24));
        lineEdit_3 = new QLineEdit(groupBox);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(83, 278, 61, 24));
        lineEdit_4 = new QLineEdit(groupBox);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(197, 278, 61, 24));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(150, 278, 71, 24));
        ReadAppCard = new QPushButton(groupBox);
        ReadAppCard->setObjectName(QString::fromUtf8("ReadAppCard"));
        ReadAppCard->setGeometry(QRect(265, 275, 60, 30));
        QFont font1;
        font1.setFamily(QString::fromUtf8("DejaVu Sans"));
        font1.setPointSize(10);
        ReadAppCard->setFont(font1);
        ReadAppCard->setFocusPolicy(Qt::NoFocus);
        WriteAppCard = new QPushButton(groupBox);
        WriteAppCard->setObjectName(QString::fromUtf8("WriteAppCard"));
        WriteAppCard->setGeometry(QRect(328, 274, 60, 30));
        WriteAppCard->setFont(font1);
        WriteAppCard->setFocusPolicy(Qt::NoFocus);
        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 252, 383, 60));
        QFont font2;
        font2.setBold(true);
        font2.setItalic(false);
        font2.setWeight(75);
        groupBox_2->setFont(font2);
        groupBox_2->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #3a5976, stop: 1 #000000);     border: 2px solid gray;\n"
"     border-radius: 5px;\n"
"     margin-top: 1ex; /* leave space at the top for the title */\n"
"	 font:bold 15px;	\n"
" }\n"
"\n"
" QGroupBox::title {\n"
"	\n"
" }"));
        adc1 = new QPushButton(groupBox);
        adc1->setObjectName(QString::fromUtf8("adc1"));
        adc1->setGeometry(QRect(440, 20, 51, 81));
        QFont font3;
        font3.setFamily(QString::fromUtf8("DejaVu Sans"));
        font3.setPointSize(12);
        font3.setBold(false);
        font3.setWeight(50);
        adc1->setFont(font3);
        adc1->setFocusPolicy(Qt::NoFocus);
        adc2 = new QPushButton(groupBox);
        adc2->setObjectName(QString::fromUtf8("adc2"));
        adc2->setGeometry(QRect(440, 150, 51, 81));
        adc2->setFont(font3);
        adc2->setFocusPolicy(Qt::NoFocus);
        groupBox_3 = new QGroupBox(groupBox);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 320, 383, 60));
        groupBox_3->setFont(font2);
        groupBox_3->setStyleSheet(QString::fromUtf8("border:1px solid white;"));
        WriteAppCard_2 = new QPushButton(groupBox);
        WriteAppCard_2->setObjectName(QString::fromUtf8("WriteAppCard_2"));
        WriteAppCard_2->setGeometry(QRect(328, 342, 60, 30));
        WriteAppCard_2->setFont(font1);
        WriteAppCard_2->setFocusPolicy(Qt::NoFocus);
        lineEdit_5 = new QLineEdit(groupBox);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(83, 346, 61, 24));
        ReadAppCard_2 = new QPushButton(groupBox);
        ReadAppCard_2->setObjectName(QString::fromUtf8("ReadAppCard_2"));
        ReadAppCard_2->setGeometry(QRect(265, 343, 60, 30));
        ReadAppCard_2->setFont(font1);
        ReadAppCard_2->setFocusPolicy(Qt::NoFocus);
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 346, 71, 24));
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(150, 346, 71, 24));
        lineEdit_6 = new QLineEdit(groupBox);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));
        lineEdit_6->setGeometry(QRect(197, 346, 61, 24));
        up = new QPushButton(groupBox);
        up->setObjectName(QString::fromUtf8("up"));
        up->setGeometry(QRect(220, 188, 40, 30));
        up->setFocusPolicy(Qt::NoFocus);
        up->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"         border: 2px solid rgba(0,0,0,0);\n"
"         border-radius: 15px;\n"
"         background-color: rgba(0,0,0,0);\n"
"     }\n"
"\n"
"     QPushButton:pressed {\n"
"		background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"     }\n"
"\n"
"     QPushButton:flat {\n"
"         border: none; /* no border for a flat push button */\n"
"     }\n"
"\n"
"     QPushButton:default {\n"
"         border-color: navy; /* make the default button prominent */\n"
"     }"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Symbols/Button-Upload-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        up->setIcon(icon);
        up->setIconSize(QSize(32, 32));
        down = new QPushButton(groupBox);
        down->setObjectName(QString::fromUtf8("down"));
        down->setGeometry(QRect(252, 188, 40, 30));
        down->setFocusPolicy(Qt::NoFocus);
        down->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"         border: 2px solid rgba(0,0,0,0);\n"
"         border-radius: 15px;\n"
"         background-color: rgba(0,0,0,0);\n"
"     }\n"
"\n"
"     QPushButton:pressed {\n"
"		background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"     }\n"
"\n"
"     QPushButton:flat {\n"
"         border: none; /* no border for a flat push button */\n"
"     }\n"
"\n"
"     QPushButton:default {\n"
"         border-color: navy; /* make the default button prominent */\n"
"     }"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Symbols/Button-Download-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        down->setIcon(icon1);
        down->setIconSize(QSize(32, 32));
        right = new QPushButton(groupBox);
        right->setObjectName(QString::fromUtf8("right"));
        right->setGeometry(QRect(188, 188, 40, 30));
        right->setFocusPolicy(Qt::NoFocus);
        right->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"         border: 2px solid rgba(0,0,0,0);\n"
"         border-radius: 15px;\n"
"         background-color: rgba(0,0,0,0);\n"
"     }\n"
"\n"
"     QPushButton:pressed {\n"
"		background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"     }\n"
"\n"
"     QPushButton:flat {\n"
"         border: none; /* no border for a flat push button */\n"
"     }\n"
"\n"
"     QPushButton:default {\n"
"         border-color: navy; /* make the default button prominent */\n"
"     }"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Symbols/Button-Next-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        right->setIcon(icon2);
        right->setIconSize(QSize(32, 32));
        left = new QPushButton(groupBox);
        left->setObjectName(QString::fromUtf8("left"));
        left->setGeometry(QRect(156, 188, 40, 30));
        left->setFocusPolicy(Qt::NoFocus);
        left->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"         border: 2px solid rgba(0,0,0,0);\n"
"         border-radius: 15px;\n"
"         background-color: rgba(0,0,0,0);\n"
"     }\n"
"\n"
"     QPushButton:pressed {\n"
"		background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"     }\n"
"\n"
"     QPushButton:flat {\n"
"         border: none; /* no border for a flat push button */\n"
"     }\n"
"\n"
"     QPushButton:default {\n"
"         border-color: navy; /* make the default button prominent */\n"
"     }"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Symbols/Button-Previous-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        left->setIcon(icon3);
        left->setIconSize(QSize(32, 32));
        comboBox = new QComboBox(groupBox);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(170, 71, 96, 24));
        comboBox->setStyleSheet(QString::fromUtf8("color:cyan;\n"
""));
        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(10, 71, 150, 24));
        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(410, 261, 90, 50));
        QFont font4;
        font4.setFamily(QString::fromUtf8("DejaVu Sans"));
        pushButton_2->setFont(font4);
        pushButton_2->setFocusPolicy(Qt::NoFocus);
        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(10, 99, 150, 24));
        lineEdit_7 = new QLineEdit(groupBox);
        lineEdit_7->setObjectName(QString::fromUtf8("lineEdit_7"));
        lineEdit_7->setGeometry(QRect(170, 98, 96, 24));
        label_11 = new QLabel(groupBox);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(10, 393, 150, 24));
        srcImpBox_10 = new QComboBox(groupBox);
        srcImpBox_10->setObjectName(QString::fromUtf8("srcImpBox_10"));
        srcImpBox_10->setGeometry(QRect(160, 389, 131, 28));
        QFont font5;
        font5.setBold(false);
        font5.setItalic(false);
        font5.setWeight(50);
        srcImpBox_10->setFont(font5);
        srcImpBox_10->setStyleSheet(QString::fromUtf8(" QComboBox {\n"
"     border: 1px solid white;\n"
"     border-radius: 6px;\n"
"     padding: 1px 18px 1px 3px;\n"
"     min-width: 6em;\n"
"     color:black;\n"
"     font:14px;\n"
"\n"
" }\n"
"\n"
" QComboBox:editable {\n"
"     background: white;\n"
" }\n"
"\n"
" QComboBox:!editable, QComboBox::drop-down:editable {\n"
"      background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                  stop: 0 #E1E1E1, stop: 0.4 #DDDDDD,\n"
"                                  stop: 0.5 #D8D8D8, stop: 1.0 #D3D3D3);\n"
" }\n"
"\n"
" /* QComboBox gets the \"on\" state when the popup is open */\n"
" QComboBox:!editable:on, QComboBox::drop-down:editable:on {\n"
"     background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                 stop: 0 #D3D3D3, stop: 0.4 #D8D8D8,\n"
"                                 stop: 0.5 #DDDDDD, stop: 1.0 #E1E1E1);\n"
" }\n"
"\n"
" QComboBox:on { /* shift the text when the popup opens */\n"
"     padding-top: 3px;\n"
"     padding-left: 4px;\n"
""
                        " }\n"
"\n"
" QComboBox::drop-down {\n"
"     subcontrol-origin: padding;\n"
"     subcontrol-position: top right;\n"
"     width: 15px;\n"
"\n"
"     border-left-width: 1px;\n"
"     border-left-color: darkgray;\n"
"     border-left-style: solid; /* just a single line */\n"
"     border-top-right-radius: 3px; /* same radius as the QComboBox */\n"
"     border-bottom-right-radius: 3px;\n"
" }\n"
"\n"
" QComboBox::down-arrow {\n"
"     image: url(/usr/share/icons/crystalsvg/16x16/actions/1downarrow.png);\n"
" }\n"
"\n"
" QComboBox::down-arrow:on { /* shift the arrow when popup is open */\n"
"     top: 1px;\n"
"     left: 1px;\n"
" }\n"
""));

        retranslateUi(Settings);

        QMetaObject::connectSlotsByName(Settings);
    } // setupUi

    void retranslateUi(QWidget *Settings)
    {
        Settings->setWindowTitle(QApplication::translate("Settings", "Form", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("Settings", "Settings", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Settings", "Exit", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Settings", "Stimulus Voltage :", 0, QApplication::UnicodeUTF8));
        chkPOTSel->setText(QApplication::translate("Settings", "OP07 / LT1012", 0, QApplication::UnicodeUTF8));
        chkDivSel->setText(QApplication::translate("Settings", "DIV0 / DIV1", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Settings", "Offset :", 0, QApplication::UnicodeUTF8));
        chkCapSet->setText(QApplication::translate("Settings", "0.001uF/0.0001uF", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Settings", "Receiver-1", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Settings", "Receiver-2", 0, QApplication::UnicodeUTF8));
        R1RMSCAVG->setText(QApplication::translate("Settings", "RMSCAVG", 0, QApplication::UnicodeUTF8));
        R1RMSGAIN->setText(QApplication::translate("Settings", "RMSGAIN", 0, QApplication::UnicodeUTF8));
        R1RMSIN->setText(QApplication::translate("Settings", "RMSIN", 0, QApplication::UnicodeUTF8));
        R2RMSIN->setText(QApplication::translate("Settings", "RMSIN", 0, QApplication::UnicodeUTF8));
        R2RMSGAIN->setText(QApplication::translate("Settings", "RMSGAIN", 0, QApplication::UnicodeUTF8));
        R2RMSCAVG->setText(QApplication::translate("Settings", "RMSCAVG", 0, QApplication::UnicodeUTF8));
        ExtInt->setText(QApplication::translate("Settings", "EXT MUX / INTERNAL", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Settings", "Address :", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("Settings", "Data:", 0, QApplication::UnicodeUTF8));
        ReadAppCard->setText(QApplication::translate("Settings", "Read", 0, QApplication::UnicodeUTF8));
        WriteAppCard->setText(QApplication::translate("Settings", "Write", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("Settings", "AppCard", 0, QApplication::UnicodeUTF8));
        adc1->setText(QApplication::translate("Settings", "ADC1\n"
"reset\n"
"config\n"
"mode", 0, QApplication::UnicodeUTF8));
        adc2->setText(QApplication::translate("Settings", "ADC2\n"
"reset\n"
"config\n"
"mode", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("Settings", "BackPanel", 0, QApplication::UnicodeUTF8));
        WriteAppCard_2->setText(QApplication::translate("Settings", "Write", 0, QApplication::UnicodeUTF8));
        ReadAppCard_2->setText(QApplication::translate("Settings", "Read", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("Settings", "Address :", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("Settings", "Data:", 0, QApplication::UnicodeUTF8));
        up->setText(QString());
        down->setText(QString());
        right->setText(QString());
        left->setText(QString());
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("Settings", "10", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Settings", "100", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Settings", "1000", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Settings", "10000", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Settings", "100000", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Settings", "1000000", 0, QApplication::UnicodeUTF8)
        );
        label_9->setText(QApplication::translate("Settings", "FeedBack(R) :", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("Settings", "Open/Short \n"
" Calibration", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("Settings", "DC Voltage :", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("Settings", "Source Impedance:", 0, QApplication::UnicodeUTF8));
        srcImpBox_10->clear();
        srcImpBox_10->insertItems(0, QStringList()
         << QApplication::translate("Settings", "0E", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Settings", "10E", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Settings", "20E", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Settings", "50E", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Settings", "100E", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Settings", "200E", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Settings", "500E", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Settings", "1K", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Settings", "2K", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Settings", "5K", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Settings", "10K", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Settings", "20K", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Settings", "50K", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Settings", "100K", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Settings", "200K", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Settings", "500K", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Settings", "1M", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Settings", "X1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Settings", "X2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Settings", "X3", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Settings", "X4", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Settings", "X5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Settings", "X6", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Settings", "X7", 0, QApplication::UnicodeUTF8)
        );
    } // retranslateUi

};

namespace Ui {
    class Settings: public Ui_Settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_H
