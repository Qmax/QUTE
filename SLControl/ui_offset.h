/********************************************************************************
** Form generated from reading UI file 'offset.ui'
**
** Created: Mon Sep 8 12:05:12 2014
**      by: Qt User Interface Compiler version 4.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OFFSET_H
#define UI_OFFSET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_offset
{
public:
    QPushButton *Gdown;
    QLabel *Glbl;
    QPushButton *Gleft;
    QPushButton *Gright;
    QPushButton *Gup;
    QLineEdit *Gedit;
    QGroupBox *OffsetDAC;
    QPushButton *Fdown;
    QPushButton *Fleft;
    QPushButton *Fright;
    QPushButton *Fup;
    QLineEdit *Fedit;
    QPushButton *pushButton;

    void setupUi(QWidget *offset)
    {
        if (offset->objectName().isEmpty())
            offset->setObjectName(QString::fromUtf8("offset"));
        offset->resize(239, 170);
        offset->setStyleSheet(QString::fromUtf8("border:1px solid black;\n"
"color:white;\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #94aaa1, stop: 1 #000000);\n"
""));
        Gdown = new QPushButton(offset);
        Gdown->setObjectName(QString::fromUtf8("Gdown"));
        Gdown->setGeometry(QRect(200, 190, 50, 40));
        Gdown->setFocusPolicy(Qt::NoFocus);
        Gdown->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        icon.addFile(QString::fromUtf8(":/Button-Download-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        Gdown->setIcon(icon);
        Gdown->setIconSize(QSize(32, 32));
        Glbl = new QLabel(offset);
        Glbl->setObjectName(QString::fromUtf8("Glbl"));
        Glbl->setGeometry(QRect(10, 150, 81, 17));
        QFont font;
        font.setPointSize(14);
        Glbl->setFont(font);
        Gleft = new QPushButton(offset);
        Gleft->setObjectName(QString::fromUtf8("Gleft"));
        Gleft->setGeometry(QRect(80, 190, 50, 40));
        Gleft->setFocusPolicy(Qt::NoFocus);
        Gleft->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        icon1.addFile(QString::fromUtf8(":/Button-Previous-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        Gleft->setIcon(icon1);
        Gleft->setIconSize(QSize(32, 32));
        Gright = new QPushButton(offset);
        Gright->setObjectName(QString::fromUtf8("Gright"));
        Gright->setGeometry(QRect(122, 190, 50, 40));
        QFont font1;
        font1.setPointSize(13);
        Gright->setFont(font1);
        Gright->setFocusPolicy(Qt::NoFocus);
        Gright->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        icon2.addFile(QString::fromUtf8(":/Button-Next-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        Gright->setIcon(icon2);
        Gright->setIconSize(QSize(32, 32));
        Gup = new QPushButton(offset);
        Gup->setObjectName(QString::fromUtf8("Gup"));
        Gup->setGeometry(QRect(160, 190, 50, 40));
        Gup->setFocusPolicy(Qt::NoFocus);
        Gup->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        icon3.addFile(QString::fromUtf8(":/Button-Upload-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        Gup->setIcon(icon3);
        Gup->setIconSize(QSize(32, 32));
        Gedit = new QLineEdit(offset);
        Gedit->setObjectName(QString::fromUtf8("Gedit"));
        Gedit->setGeometry(QRect(90, 140, 151, 41));
        Gedit->setStyleSheet(QString::fromUtf8(" QLineEdit {\n"
"     border: 2px solid gray;\n"
"     border-radius: 8px;\n"
"     padding: 0 8px;\n"
"     background: white;\n"
"     selection-background-color: darkgray;\n"
"	 color:black;\n"
"     font: bold 12px;\n"
" }"));
        OffsetDAC = new QGroupBox(offset);
        OffsetDAC->setObjectName(QString::fromUtf8("OffsetDAC"));
        OffsetDAC->setGeometry(QRect(0, 0, 240, 170));
        OffsetDAC->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #E0E0E0, stop: 1 #FFFFFF);\n"
"     border: 2px solid gray;\n"
"     border-radius: 10px;\n"
"     margin-top: 1ex; /* leave space at the top for the title */\n"
"	font:18px bold;\n"
"	color:black;\n"
" }\n"
"\n"
" QGroupBox::title {\n"
"     subcontrol-origin: margin;\n"
"     subcontrol-position: top center; /* position at the top center */\n"
"     padding: 0 3px;\n"
"	 background-color:white;\n"
"     border:2px solid black;\n"
"	border-radius:10px;\n"
" }"));
        Fdown = new QPushButton(OffsetDAC);
        Fdown->setObjectName(QString::fromUtf8("Fdown"));
        Fdown->setGeometry(QRect(150, 90, 50, 40));
        Fdown->setFocusPolicy(Qt::NoFocus);
        Fdown->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        Fdown->setIcon(icon);
        Fdown->setIconSize(QSize(32, 32));
        Fleft = new QPushButton(OffsetDAC);
        Fleft->setObjectName(QString::fromUtf8("Fleft"));
        Fleft->setGeometry(QRect(30, 90, 50, 40));
        Fleft->setFocusPolicy(Qt::NoFocus);
        Fleft->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        Fleft->setIcon(icon1);
        Fleft->setIconSize(QSize(32, 32));
        Fright = new QPushButton(OffsetDAC);
        Fright->setObjectName(QString::fromUtf8("Fright"));
        Fright->setGeometry(QRect(72, 90, 50, 40));
        Fright->setFocusPolicy(Qt::NoFocus);
        Fright->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        Fright->setIcon(icon2);
        Fright->setIconSize(QSize(32, 32));
        Fup = new QPushButton(OffsetDAC);
        Fup->setObjectName(QString::fromUtf8("Fup"));
        Fup->setGeometry(QRect(110, 90, 50, 40));
        Fup->setFocusPolicy(Qt::NoFocus);
        Fup->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        Fup->setIcon(icon3);
        Fup->setIconSize(QSize(32, 32));
        Fedit = new QLineEdit(OffsetDAC);
        Fedit->setObjectName(QString::fromUtf8("Fedit"));
        Fedit->setGeometry(QRect(40, 40, 151, 41));
        Fedit->setStyleSheet(QString::fromUtf8(" QLineEdit {\n"
"     border: 2px solid gray;\n"
"     border-radius: 8px;\n"
"     padding: 0 8px;\n"
"     background: white;\n"
"     selection-background-color: darkgray;\n"
"	 color:black;\n"
"     font: bold 12px;\n"
" }"));
        pushButton = new QPushButton(OffsetDAC);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(207, 13, 30, 30));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/Actions-window-close-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon4);
        pushButton->setIconSize(QSize(32, 32));

        retranslateUi(offset);

        QMetaObject::connectSlotsByName(offset);
    } // setupUi

    void retranslateUi(QWidget *offset)
    {
        offset->setWindowTitle(QApplication::translate("offset", "Form", 0, QApplication::UnicodeUTF8));
        Gdown->setText(QString());
        Glbl->setText(QApplication::translate("offset", "DAC G :", 0, QApplication::UnicodeUTF8));
        Gleft->setText(QString());
        Gright->setText(QString());
        Gup->setText(QString());
        OffsetDAC->setTitle(QApplication::translate("offset", "Offset DAC", 0, QApplication::UnicodeUTF8));
        Fdown->setText(QString());
        Fleft->setText(QString());
        Fright->setText(QString());
        Fup->setText(QString());
        pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class offset: public Ui_offset {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OFFSET_H
