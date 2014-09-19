/********************************************************************************
** Form generated from reading UI file 'muxjig.ui'
**
** Created: Tue Sep 9 12:03:33 2014
**      by: Qt User Interface Compiler version 4.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MUXJIG_H
#define UI_MUXJIG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MuxJig
{
public:
    QGroupBox *testChannel;
    QGroupBox *refChannel;
    QGroupBox *groupBox;
    QCheckBox *extMux;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QPushButton *reset;
    QPushButton *reset_2;
    QPushButton *resetRefCh;
    QPushButton *resetTestCh;
    QPushButton *resetBothCh;
    QPushButton *pushButton_5;
    QPushButton *switchExtMux;
    QPushButton *readCodeId;

    void setupUi(QWidget *MuxJig)
    {
        if (MuxJig->objectName().isEmpty())
            MuxJig->setObjectName(QString::fromUtf8("MuxJig"));
        MuxJig->resize(800, 610);
        MuxJig->setStyleSheet(QString::fromUtf8(""));
        testChannel = new QGroupBox(MuxJig);
        testChannel->setObjectName(QString::fromUtf8("testChannel"));
        testChannel->setGeometry(QRect(10, 10, 780, 220));
        QFont font;
        font.setFamily(QString::fromUtf8("DejaVu Sans"));
        font.setPointSize(12);
        testChannel->setFont(font);
        testChannel->setStyleSheet(QString::fromUtf8("color:white;"));
        refChannel = new QGroupBox(MuxJig);
        refChannel->setObjectName(QString::fromUtf8("refChannel"));
        refChannel->setGeometry(QRect(10, 230, 780, 220));
        refChannel->setFont(font);
        refChannel->setStyleSheet(QString::fromUtf8("color:white;"));
        groupBox = new QGroupBox(MuxJig);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(20, 450, 780, 121));
        groupBox->setFont(font);
        groupBox->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
"color:white;\n"
"}"));
        extMux = new QCheckBox(groupBox);
        extMux->setObjectName(QString::fromUtf8("extMux"));
        extMux->setGeometry(QRect(20, 40, 141, 22));
        QFont font1;
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        extMux->setFont(font1);
        extMux->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
"font: 14px;\n"
"color:white;\n"
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
        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(570, 30, 97, 27));
        pushButton_2->setFont(font);
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"         border: 2px solid #8f8f91;\n"
"         border-radius: 10px;\n"
"         background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                           stop: 0 #f6f7fa, stop: 1 #dadbde);\n"
"         min-width: 80px;\n"
"     }\n"
"\n"
"     QPushButton:pressed {\n"
"         background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                           stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"     }\n"
"\n"
"     QPushButton:flat {\n"
"         border: none; /* no border for a flat push button */\n"
"     }\n"
"\n"
"     QPushButton:default {\n"
"         border-color: navy; /* make the default button prominent */\n"
"     }"));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(20, 70, 150, 30));
        pushButton->setFont(font);
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"         border: 2px solid #8f8f91;\n"
"         border-radius: 10px;\n"
"         background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                           stop: 0 #f6f7fa, stop: 1 #dadbde);\n"
"         min-width: 80px;\n"
"     }\n"
"\n"
"     QPushButton:pressed {\n"
"         background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                           stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"     }\n"
"\n"
"     QPushButton:flat {\n"
"         border: none; /* no border for a flat push button */\n"
"     }\n"
"\n"
"     QPushButton:default {\n"
"         border-color: navy; /* make the default button prominent */\n"
"     }"));
        reset = new QPushButton(groupBox);
        reset->setObjectName(QString::fromUtf8("reset"));
        reset->setGeometry(QRect(443, 70, 120, 27));
        reset->setFont(font);
        reset->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"         border: 2px solid #8f8f91;\n"
"         border-radius: 10px;\n"
"         background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                           stop: 0 #f6f7fa, stop: 1 #dadbde);\n"
"         min-width: 80px;\n"
"     }\n"
"\n"
"     QPushButton:pressed {\n"
"         background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                           stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"     }\n"
"\n"
"     QPushButton:flat {\n"
"         border: none; /* no border for a flat push button */\n"
"     }\n"
"\n"
"     QPushButton:default {\n"
"         border-color: navy; /* make the default button prominent */\n"
"     }"));
        reset_2 = new QPushButton(groupBox);
        reset_2->setObjectName(QString::fromUtf8("reset_2"));
        reset_2->setGeometry(QRect(443, 30, 120, 27));
        reset_2->setFont(font);
        reset_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"         border: 2px solid #8f8f91;\n"
"         border-radius: 10px;\n"
"         background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                           stop: 0 #f6f7fa, stop: 1 #dadbde);\n"
"         min-width: 80px;\n"
"     }\n"
"\n"
"     QPushButton:pressed {\n"
"         background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                           stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"     }\n"
"\n"
"     QPushButton:flat {\n"
"         border: none; /* no border for a flat push button */\n"
"     }\n"
"\n"
"     QPushButton:default {\n"
"         border-color: navy; /* make the default button prominent */\n"
"     }"));
        resetRefCh = new QPushButton(groupBox);
        resetRefCh->setObjectName(QString::fromUtf8("resetRefCh"));
        resetRefCh->setGeometry(QRect(240, 70, 100, 30));
        resetRefCh->setFont(font);
        resetRefCh->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"         border: 2px solid #8f8f91;\n"
"         border-radius: 10px;\n"
"         background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                           stop: 0 #f6f7fa, stop: 1 #dadbde);\n"
"         min-width: 80px;\n"
"     }\n"
"\n"
"     QPushButton:pressed {\n"
"         background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                           stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"     }\n"
"\n"
"     QPushButton:flat {\n"
"         border: none; /* no border for a flat push button */\n"
"     }\n"
"\n"
"     QPushButton:default {\n"
"         border-color: navy; /* make the default button prominent */\n"
"     }"));
        resetTestCh = new QPushButton(groupBox);
        resetTestCh->setObjectName(QString::fromUtf8("resetTestCh"));
        resetTestCh->setGeometry(QRect(240, 30, 100, 30));
        resetTestCh->setFont(font);
        resetTestCh->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"         border: 2px solid #8f8f91;\n"
"         border-radius: 10px;\n"
"         background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                           stop: 0 #f6f7fa, stop: 1 #dadbde);\n"
"         min-width: 80px;\n"
"     }\n"
"\n"
"     QPushButton:pressed {\n"
"         background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                           stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"     }\n"
"\n"
"     QPushButton:flat {\n"
"         border: none; /* no border for a flat push button */\n"
"     }\n"
"\n"
"     QPushButton:default {\n"
"         border-color: navy; /* make the default button prominent */\n"
"     }"));
        resetBothCh = new QPushButton(groupBox);
        resetBothCh->setObjectName(QString::fromUtf8("resetBothCh"));
        resetBothCh->setGeometry(QRect(350, 30, 84, 68));
        resetBothCh->setFont(font);
        resetBothCh->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"         border: 2px solid #8f8f91;\n"
"         border-radius: 10px;\n"
"         background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                           stop: 0 #f6f7fa, stop: 1 #dadbde);\n"
"         min-width: 80px;\n"
"     }\n"
"\n"
"     QPushButton:pressed {\n"
"         background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                           stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"     }\n"
"\n"
"     QPushButton:flat {\n"
"         border: none; /* no border for a flat push button */\n"
"     }\n"
"\n"
"     QPushButton:default {\n"
"         border-color: navy; /* make the default button prominent */\n"
"     }"));
        pushButton_5 = new QPushButton(groupBox);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(671, 30, 97, 68));
        pushButton_5->setFont(font);
        pushButton_5->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"         border: 2px solid #8f8f91;\n"
"         border-radius: 10px;\n"
"         background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                           stop: 0 #f6f7fa, stop: 1 #dadbde);\n"
"         min-width: 80px;\n"
"     }\n"
"\n"
"     QPushButton:pressed {\n"
"         background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                           stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"     }\n"
"\n"
"     QPushButton:flat {\n"
"         border: none; /* no border for a flat push button */\n"
"     }\n"
"\n"
"     QPushButton:default {\n"
"         border-color: navy; /* make the default button prominent */\n"
"     }"));
        switchExtMux = new QPushButton(groupBox);
        switchExtMux->setObjectName(QString::fromUtf8("switchExtMux"));
        switchExtMux->setGeometry(QRect(570, 70, 97, 27));
        switchExtMux->setFont(font);
        switchExtMux->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"         border: 2px solid #8f8f91;\n"
"         border-radius: 10px;\n"
"         background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                           stop: 0 #f6f7fa, stop: 1 #dadbde);\n"
"         min-width: 80px;\n"
"     }\n"
"\n"
"     QPushButton:pressed {\n"
"         background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                           stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"     }\n"
"\n"
"     QPushButton:flat {\n"
"         border: none; /* no border for a flat push button */\n"
"     }\n"
"\n"
"     QPushButton:default {\n"
"         border-color: navy; /* make the default button prominent */\n"
"     }"));
        readCodeId = new QPushButton(groupBox);
        readCodeId->setObjectName(QString::fromUtf8("readCodeId"));
        readCodeId->setGeometry(QRect(175, 30, 60, 71));
        readCodeId->setFont(font);
        readCodeId->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"         border: 2px solid #8f8f91;\n"
"         border-radius: 10px;\n"
"         background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                           stop: 0 #f6f7fa, stop: 1 #dadbde);\n"
"     }\n"
"\n"
"     QPushButton:pressed {\n"
"         background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                           stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"     }\n"
"\n"
"     QPushButton:flat {\n"
"         border: none; /* no border for a flat push button */\n"
"     }\n"
"\n"
"     QPushButton:default {\n"
"         border-color: navy; /* make the default button prominent */\n"
"     }"));

        retranslateUi(MuxJig);

        QMetaObject::connectSlotsByName(MuxJig);
    } // setupUi

    void retranslateUi(QWidget *MuxJig)
    {
        MuxJig->setWindowTitle(QApplication::translate("MuxJig", "MuxJig", 0, QApplication::UnicodeUTF8));
        testChannel->setTitle(QApplication::translate("MuxJig", "Test Channel", 0, QApplication::UnicodeUTF8));
        refChannel->setTitle(QApplication::translate("MuxJig", "Reference Channel", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MuxJig", "Control", 0, QApplication::UnicodeUTF8));
        extMux->setText(QApplication::translate("MuxJig", "Enable Ext Mux", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("MuxJig", "Self Test", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MuxJig", "Switch Ext Test_Ref", 0, QApplication::UnicodeUTF8));
        reset->setText(QApplication::translate("MuxJig", "Reset_PSoC", 0, QApplication::UnicodeUTF8));
        reset_2->setText(QApplication::translate("MuxJig", "PSoC_App_Bck", 0, QApplication::UnicodeUTF8));
        resetRefCh->setText(QApplication::translate("MuxJig", "Reset Ref Ch", 0, QApplication::UnicodeUTF8));
        resetTestCh->setText(QApplication::translate("MuxJig", "Reset Test Ch", 0, QApplication::UnicodeUTF8));
        resetBothCh->setText(QApplication::translate("MuxJig", "Reset\n"
" Both \n"
" Channels", 0, QApplication::UnicodeUTF8));
        pushButton_5->setText(QApplication::translate("MuxJig", "Exit\n"
"MuxJig", 0, QApplication::UnicodeUTF8));
        switchExtMux->setText(QApplication::translate("MuxJig", "Switch Ext", 0, QApplication::UnicodeUTF8));
        readCodeId->setText(QApplication::translate("MuxJig", "Read\n"
"Mux\n"
"CodeId", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MuxJig: public Ui_MuxJig {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MUXJIG_H
