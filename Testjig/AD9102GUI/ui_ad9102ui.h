/********************************************************************************
** Form generated from reading UI file 'ad9102ui.ui'
**
** Created: Sat Sep 6 10:53:02 2014
**      by: Qt User Interface Compiler version 4.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AD9102UI_H
#define UI_AD9102UI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AD9102UI
{
public:
    QGroupBox *grpBox_ReadWrite;
    QLabel *lbl_Address;
    QLabel *lbl_Data;
    QLineEdit *le_Address;
    QLineEdit *le_Data;
    QPushButton *pb_Read;
    QPushButton *pb_Write;
    QGroupBox *grpBox_AppReadWrite;
    QLabel *lbl_AppAddress;
    QLabel *lbl_AppData;
    QLineEdit *le_AppAddress;
    QLineEdit *le_AppData;
    QPushButton *pb_AppRead;
    QPushButton *pb_AppWrite;
    QGroupBox *grpBox_Test;
    QLabel *lbl_Delay;
    QLineEdit *le_Delay;
    QPushButton *pb_Test;
    QPushButton *pb_Reset;
    QPushButton *pb_Trigger;
    QLabel *label;
    QPushButton *pb_TestWrite;
    QComboBox *comboBox;
    QPushButton *pb_Update;
    QLabel *label_2;
    QPushButton *pb_TestRUN;
    QLabel *writing1;
    QPushButton *pb_TestRead;
    QGroupBox *grpBox_SRAMReadWrite;
    QLabel *lbl_SRAMAddress;
    QLabel *lbl_SRAMData;
    QLineEdit *le_SRAMAddress;
    QLineEdit *le_SRAMData;
    QPushButton *pb_SRAMRead;
    QPushButton *pb_SRAMWrite;
    QLabel *label_3;
    QGroupBox *grpBox_SRAMUpdate;
    QLabel *lbl_SRAMStartAddress;
    QLineEdit *le_SRAMStartAddress;
    QPushButton *pb_SRAMLoad;
    QPushButton *pb_SRAMUpdate;
    QLabel *lbl_SRAMCount;
    QLineEdit *le_SRAMCount;
    QLabel *writing2;
    QGroupBox *grpBox_Parameters;
    QLabel *lbl_Frequency;
    QLineEdit *le_Frequency;
    QLineEdit *le_Phase;
    QLabel *lbl_Phase;
    QLabel *lbl_HexFrequency;
    QLabel *lbl_HexPhase;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

    void setupUi(QWidget *AD9102UI)
    {
        if (AD9102UI->objectName().isEmpty())
            AD9102UI->setObjectName(QString::fromUtf8("AD9102UI"));
        AD9102UI->resize(800, 600);
        grpBox_ReadWrite = new QGroupBox(AD9102UI);
        grpBox_ReadWrite->setObjectName(QString::fromUtf8("grpBox_ReadWrite"));
        grpBox_ReadWrite->setGeometry(QRect(10, 0, 250, 210));
        QFont font;
        font.setFamily(QString::fromUtf8("DejaVu Sans"));
        font.setPointSize(12);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        grpBox_ReadWrite->setFont(font);
        grpBox_ReadWrite->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #E0E0E0, stop: 1 #FFFFFF);\n"
"     border: 2px solid gray;\n"
"     border-radius: 5px;\n"
"     margin-top: 1ex; /* leave space at the top for the title */\n"
" }\n"
"\n"
" QGroupBox::title {\n"
"     subcontrol-origin: margin;\n"
"     subcontrol-position: top center; /* position at the top center */\n"
"     padding: 0 3px;\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #FFFECE, stop: 1 #FFFFFF);\n"
" }"));
        lbl_Address = new QLabel(grpBox_ReadWrite);
        lbl_Address->setObjectName(QString::fromUtf8("lbl_Address"));
        lbl_Address->setGeometry(QRect(21, 39, 88, 21));
        lbl_Address->setFont(font);
        lbl_Data = new QLabel(grpBox_ReadWrite);
        lbl_Data->setObjectName(QString::fromUtf8("lbl_Data"));
        lbl_Data->setGeometry(QRect(21, 96, 88, 21));
        lbl_Data->setFont(font);
        le_Address = new QLineEdit(grpBox_ReadWrite);
        le_Address->setObjectName(QString::fromUtf8("le_Address"));
        le_Address->setGeometry(QRect(120, 33, 108, 31));
        le_Address->setFont(font);
        le_Address->setFocusPolicy(Qt::NoFocus);
        le_Data = new QLineEdit(grpBox_ReadWrite);
        le_Data->setObjectName(QString::fromUtf8("le_Data"));
        le_Data->setGeometry(QRect(120, 90, 108, 31));
        le_Data->setFont(font);
        le_Data->setFocusPolicy(Qt::NoFocus);
        pb_Read = new QPushButton(grpBox_ReadWrite);
        pb_Read->setObjectName(QString::fromUtf8("pb_Read"));
        pb_Read->setGeometry(QRect(20, 143, 91, 40));
        pb_Read->setFont(font);
        pb_Read->setFocusPolicy(Qt::NoFocus);
        pb_Write = new QPushButton(grpBox_ReadWrite);
        pb_Write->setObjectName(QString::fromUtf8("pb_Write"));
        pb_Write->setGeometry(QRect(130, 143, 91, 40));
        pb_Write->setFont(font);
        pb_Write->setFocusPolicy(Qt::NoFocus);
        grpBox_AppReadWrite = new QGroupBox(AD9102UI);
        grpBox_AppReadWrite->setObjectName(QString::fromUtf8("grpBox_AppReadWrite"));
        grpBox_AppReadWrite->setGeometry(QRect(273, 0, 250, 210));
        grpBox_AppReadWrite->setFont(font);
        grpBox_AppReadWrite->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #E0E0E0, stop: 1 #FFFFFF);\n"
"     border: 2px solid gray;\n"
"     border-radius: 5px;\n"
"     margin-top: 1ex; /* leave space at the top for the title */\n"
" }\n"
"\n"
" QGroupBox::title {\n"
"     subcontrol-origin: margin;\n"
"     subcontrol-position: top center; /* position at the top center */\n"
"     padding: 0 3px;\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #FFFECE, stop: 1 #FFFFFF);\n"
" }"));
        lbl_AppAddress = new QLabel(grpBox_AppReadWrite);
        lbl_AppAddress->setObjectName(QString::fromUtf8("lbl_AppAddress"));
        lbl_AppAddress->setGeometry(QRect(21, 39, 88, 21));
        lbl_AppAddress->setFont(font);
        lbl_AppData = new QLabel(grpBox_AppReadWrite);
        lbl_AppData->setObjectName(QString::fromUtf8("lbl_AppData"));
        lbl_AppData->setGeometry(QRect(21, 96, 88, 21));
        lbl_AppData->setFont(font);
        le_AppAddress = new QLineEdit(grpBox_AppReadWrite);
        le_AppAddress->setObjectName(QString::fromUtf8("le_AppAddress"));
        le_AppAddress->setGeometry(QRect(120, 33, 108, 31));
        le_AppAddress->setFont(font);
        le_AppAddress->setFocusPolicy(Qt::NoFocus);
        le_AppData = new QLineEdit(grpBox_AppReadWrite);
        le_AppData->setObjectName(QString::fromUtf8("le_AppData"));
        le_AppData->setGeometry(QRect(120, 90, 108, 31));
        le_AppData->setFont(font);
        le_AppData->setFocusPolicy(Qt::NoFocus);
        pb_AppRead = new QPushButton(grpBox_AppReadWrite);
        pb_AppRead->setObjectName(QString::fromUtf8("pb_AppRead"));
        pb_AppRead->setGeometry(QRect(20, 143, 91, 40));
        pb_AppRead->setFont(font);
        pb_AppRead->setFocusPolicy(Qt::NoFocus);
        pb_AppWrite = new QPushButton(grpBox_AppReadWrite);
        pb_AppWrite->setObjectName(QString::fromUtf8("pb_AppWrite"));
        pb_AppWrite->setGeometry(QRect(130, 143, 91, 40));
        pb_AppWrite->setFont(font);
        pb_AppWrite->setFocusPolicy(Qt::NoFocus);
        grpBox_Test = new QGroupBox(AD9102UI);
        grpBox_Test->setObjectName(QString::fromUtf8("grpBox_Test"));
        grpBox_Test->setGeometry(QRect(10, 220, 511, 210));
        grpBox_Test->setFont(font);
        grpBox_Test->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #E0E0E0, stop: 1 #FFFFFF);\n"
"     border: 2px solid gray;\n"
"     border-radius: 5px;\n"
"     margin-top: 1ex; /* leave space at the top for the title */\n"
" }\n"
"\n"
" QGroupBox::title {\n"
"     subcontrol-origin: margin;\n"
"     subcontrol-position: top center; /* position at the top center */\n"
"     padding: 0 3px;\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #FFFECE, stop: 1 #FFFFFF);\n"
" }"));
        lbl_Delay = new QLabel(grpBox_Test);
        lbl_Delay->setObjectName(QString::fromUtf8("lbl_Delay"));
        lbl_Delay->setGeometry(QRect(21, 39, 88, 21));
        lbl_Delay->setFont(font);
        le_Delay = new QLineEdit(grpBox_Test);
        le_Delay->setObjectName(QString::fromUtf8("le_Delay"));
        le_Delay->setGeometry(QRect(120, 33, 108, 31));
        le_Delay->setFont(font);
        le_Delay->setFocusPolicy(Qt::NoFocus);
        pb_Test = new QPushButton(grpBox_Test);
        pb_Test->setObjectName(QString::fromUtf8("pb_Test"));
        pb_Test->setGeometry(QRect(160, 90, 100, 41));
        pb_Test->setFont(font);
        pb_Test->setFocusPolicy(Qt::NoFocus);
        pb_Reset = new QPushButton(grpBox_Test);
        pb_Reset->setObjectName(QString::fromUtf8("pb_Reset"));
        pb_Reset->setGeometry(QRect(350, 28, 120, 41));
        pb_Reset->setFont(font);
        pb_Reset->setFocusPolicy(Qt::NoFocus);
        pb_Trigger = new QPushButton(grpBox_Test);
        pb_Trigger->setObjectName(QString::fromUtf8("pb_Trigger"));
        pb_Trigger->setGeometry(QRect(350, 88, 120, 41));
        pb_Trigger->setFont(font);
        pb_Trigger->setFocusPolicy(Qt::NoFocus);
        label = new QLabel(grpBox_Test);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(160, 63, 81, 17));
        label->setFont(font);
        pb_TestWrite = new QPushButton(grpBox_Test);
        pb_TestWrite->setObjectName(QString::fromUtf8("pb_TestWrite"));
        pb_TestWrite->setGeometry(QRect(130, 150, 100, 41));
        pb_TestWrite->setFont(font);
        pb_TestWrite->setFocusPolicy(Qt::NoFocus);
        comboBox = new QComboBox(grpBox_Test);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(120, 90, 201, 41));
        comboBox->setFont(font);
        comboBox->setFocusPolicy(Qt::NoFocus);
        pb_Update = new QPushButton(grpBox_Test);
        pb_Update->setObjectName(QString::fromUtf8("pb_Update"));
        pb_Update->setGeometry(QRect(380, 148, 100, 41));
        pb_Update->setFont(font);
        pb_Update->setFocusPolicy(Qt::NoFocus);
        label_2 = new QLabel(grpBox_Test);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 100, 62, 17));
        label_2->setFont(font);
        pb_TestRUN = new QPushButton(grpBox_Test);
        pb_TestRUN->setObjectName(QString::fromUtf8("pb_TestRUN"));
        pb_TestRUN->setGeometry(QRect(260, 150, 100, 41));
        pb_TestRUN->setFont(font);
        pb_TestRUN->setFocusPolicy(Qt::NoFocus);
        writing1 = new QLabel(grpBox_Test);
        writing1->setObjectName(QString::fromUtf8("writing1"));
        writing1->setGeometry(QRect(190, 190, 62, 17));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        writing1->setFont(font1);
        writing1->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        pb_TestRead = new QPushButton(grpBox_Test);
        pb_TestRead->setObjectName(QString::fromUtf8("pb_TestRead"));
        pb_TestRead->setGeometry(QRect(10, 150, 100, 41));
        pb_TestRead->setFont(font);
        pb_TestRead->setFocusPolicy(Qt::NoFocus);
        grpBox_SRAMReadWrite = new QGroupBox(AD9102UI);
        grpBox_SRAMReadWrite->setObjectName(QString::fromUtf8("grpBox_SRAMReadWrite"));
        grpBox_SRAMReadWrite->setGeometry(QRect(535, 0, 250, 211));
        grpBox_SRAMReadWrite->setFont(font);
        grpBox_SRAMReadWrite->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #E0E0E0, stop: 1 #FFFFFF);\n"
"     border: 2px solid gray;\n"
"     border-radius: 5px;\n"
"     margin-top: 1ex; /* leave space at the top for the title */\n"
" }\n"
"\n"
" QGroupBox::title {\n"
"     subcontrol-origin: margin;\n"
"     subcontrol-position: top center; /* position at the top center */\n"
"     padding: 0 3px;\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #FFFECE, stop: 1 #FFFFFF);\n"
" }"));
        lbl_SRAMAddress = new QLabel(grpBox_SRAMReadWrite);
        lbl_SRAMAddress->setObjectName(QString::fromUtf8("lbl_SRAMAddress"));
        lbl_SRAMAddress->setGeometry(QRect(21, 39, 121, 21));
        lbl_SRAMAddress->setFont(font);
        lbl_SRAMData = new QLabel(grpBox_SRAMReadWrite);
        lbl_SRAMData->setObjectName(QString::fromUtf8("lbl_SRAMData"));
        lbl_SRAMData->setGeometry(QRect(21, 96, 88, 21));
        lbl_SRAMData->setFont(font);
        le_SRAMAddress = new QLineEdit(grpBox_SRAMReadWrite);
        le_SRAMAddress->setObjectName(QString::fromUtf8("le_SRAMAddress"));
        le_SRAMAddress->setGeometry(QRect(120, 33, 108, 31));
        le_SRAMAddress->setFont(font);
        le_SRAMAddress->setFocusPolicy(Qt::NoFocus);
        le_SRAMData = new QLineEdit(grpBox_SRAMReadWrite);
        le_SRAMData->setObjectName(QString::fromUtf8("le_SRAMData"));
        le_SRAMData->setGeometry(QRect(120, 90, 108, 31));
        le_SRAMData->setFont(font);
        le_SRAMData->setFocusPolicy(Qt::NoFocus);
        pb_SRAMRead = new QPushButton(grpBox_SRAMReadWrite);
        pb_SRAMRead->setObjectName(QString::fromUtf8("pb_SRAMRead"));
        pb_SRAMRead->setGeometry(QRect(20, 140, 91, 40));
        pb_SRAMRead->setFont(font);
        pb_SRAMRead->setFocusPolicy(Qt::NoFocus);
        pb_SRAMWrite = new QPushButton(grpBox_SRAMReadWrite);
        pb_SRAMWrite->setObjectName(QString::fromUtf8("pb_SRAMWrite"));
        pb_SRAMWrite->setGeometry(QRect(130, 140, 91, 40));
        pb_SRAMWrite->setFont(font);
        pb_SRAMWrite->setFocusPolicy(Qt::NoFocus);
        label_3 = new QLabel(grpBox_SRAMReadWrite);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(110, 66, 111, 17));
        label_3->setFont(font);
        grpBox_SRAMUpdate = new QGroupBox(AD9102UI);
        grpBox_SRAMUpdate->setObjectName(QString::fromUtf8("grpBox_SRAMUpdate"));
        grpBox_SRAMUpdate->setGeometry(QRect(535, 220, 250, 211));
        grpBox_SRAMUpdate->setFont(font);
        grpBox_SRAMUpdate->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #E0E0E0, stop: 1 #FFFFFF);\n"
"     border: 2px solid gray;\n"
"     border-radius: 5px;\n"
"     margin-top: 1ex; /* leave space at the top for the title */\n"
" }\n"
"\n"
" QGroupBox::title {\n"
"     subcontrol-origin: margin;\n"
"     subcontrol-position: top center; /* position at the top center */\n"
"     padding: 0 3px;\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #FFFECE, stop: 1 #FFFFFF);\n"
" }"));
        lbl_SRAMStartAddress = new QLabel(grpBox_SRAMUpdate);
        lbl_SRAMStartAddress->setObjectName(QString::fromUtf8("lbl_SRAMStartAddress"));
        lbl_SRAMStartAddress->setGeometry(QRect(21, 49, 121, 21));
        lbl_SRAMStartAddress->setFont(font);
        le_SRAMStartAddress = new QLineEdit(grpBox_SRAMUpdate);
        le_SRAMStartAddress->setObjectName(QString::fromUtf8("le_SRAMStartAddress"));
        le_SRAMStartAddress->setGeometry(QRect(120, 43, 108, 31));
        le_SRAMStartAddress->setFont(font);
        le_SRAMStartAddress->setFocusPolicy(Qt::NoFocus);
        pb_SRAMLoad = new QPushButton(grpBox_SRAMUpdate);
        pb_SRAMLoad->setObjectName(QString::fromUtf8("pb_SRAMLoad"));
        pb_SRAMLoad->setGeometry(QRect(20, 140, 91, 40));
        pb_SRAMLoad->setFont(font);
        pb_SRAMLoad->setFocusPolicy(Qt::NoFocus);
        pb_SRAMUpdate = new QPushButton(grpBox_SRAMUpdate);
        pb_SRAMUpdate->setObjectName(QString::fromUtf8("pb_SRAMUpdate"));
        pb_SRAMUpdate->setGeometry(QRect(130, 140, 91, 40));
        pb_SRAMUpdate->setFont(font);
        pb_SRAMUpdate->setFocusPolicy(Qt::NoFocus);
        lbl_SRAMCount = new QLabel(grpBox_SRAMUpdate);
        lbl_SRAMCount->setObjectName(QString::fromUtf8("lbl_SRAMCount"));
        lbl_SRAMCount->setGeometry(QRect(21, 96, 121, 21));
        lbl_SRAMCount->setFont(font);
        le_SRAMCount = new QLineEdit(grpBox_SRAMUpdate);
        le_SRAMCount->setObjectName(QString::fromUtf8("le_SRAMCount"));
        le_SRAMCount->setGeometry(QRect(120, 90, 108, 31));
        le_SRAMCount->setFont(font);
        le_SRAMCount->setFocusPolicy(Qt::NoFocus);
        writing2 = new QLabel(grpBox_SRAMUpdate);
        writing2->setObjectName(QString::fromUtf8("writing2"));
        writing2->setGeometry(QRect(160, 180, 62, 17));
        writing2->setFont(font1);
        writing2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        grpBox_Parameters = new QGroupBox(AD9102UI);
        grpBox_Parameters->setObjectName(QString::fromUtf8("grpBox_Parameters"));
        grpBox_Parameters->setGeometry(QRect(10, 440, 773, 80));
        grpBox_Parameters->setFont(font);
        grpBox_Parameters->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #E0E0E0, stop: 1 #FFFFFF);\n"
"     border: 2px solid gray;\n"
"     border-radius: 5px;\n"
"     margin-top: 1ex; /* leave space at the top for the title */\n"
" }\n"
"\n"
" QGroupBox::title {\n"
"     subcontrol-origin: margin;\n"
"     subcontrol-position: top center; /* position at the top center */\n"
"     padding: 0 3px;\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #FFFECE, stop: 1 #FFFFFF);\n"
" }"));
        lbl_Frequency = new QLabel(grpBox_Parameters);
        lbl_Frequency->setObjectName(QString::fromUtf8("lbl_Frequency"));
        lbl_Frequency->setGeometry(QRect(21, 26, 121, 21));
        lbl_Frequency->setFont(font);
        le_Frequency = new QLineEdit(grpBox_Parameters);
        le_Frequency->setObjectName(QString::fromUtf8("le_Frequency"));
        le_Frequency->setGeometry(QRect(110, 20, 108, 31));
        le_Frequency->setFont(font);
        le_Frequency->setFocusPolicy(Qt::NoFocus);
        le_Phase = new QLineEdit(grpBox_Parameters);
        le_Phase->setObjectName(QString::fromUtf8("le_Phase"));
        le_Phase->setGeometry(QRect(300, 20, 108, 31));
        le_Phase->setFont(font);
        le_Phase->setFocusPolicy(Qt::NoFocus);
        lbl_Phase = new QLabel(grpBox_Parameters);
        lbl_Phase->setObjectName(QString::fromUtf8("lbl_Phase"));
        lbl_Phase->setGeometry(QRect(231, 26, 121, 21));
        lbl_Phase->setFont(font);
        lbl_HexFrequency = new QLabel(grpBox_Parameters);
        lbl_HexFrequency->setObjectName(QString::fromUtf8("lbl_HexFrequency"));
        lbl_HexFrequency->setGeometry(QRect(160, 50, 62, 17));
        QFont font2;
        font2.setFamily(QString::fromUtf8("DejaVu Sans"));
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setWeight(75);
        lbl_HexFrequency->setFont(font2);
        lbl_HexPhase = new QLabel(grpBox_Parameters);
        lbl_HexPhase->setObjectName(QString::fromUtf8("lbl_HexPhase"));
        lbl_HexPhase->setGeometry(QRect(340, 50, 62, 17));
        lbl_HexPhase->setFont(font2);
        pushButton = new QPushButton(grpBox_Parameters);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(670, 10, 91, 27));
        pushButton_2 = new QPushButton(grpBox_Parameters);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(690, 40, 51, 27));
        pushButton_3 = new QPushButton(grpBox_Parameters);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(630, 40, 51, 27));

        retranslateUi(AD9102UI);

        QMetaObject::connectSlotsByName(AD9102UI);
    } // setupUi

    void retranslateUi(QWidget *AD9102UI)
    {
        AD9102UI->setWindowTitle(QApplication::translate("AD9102UI", "AD9102UI", 0, QApplication::UnicodeUTF8));
        grpBox_ReadWrite->setTitle(QApplication::translate("AD9102UI", "AD9102  SPI Read/Write", 0, QApplication::UnicodeUTF8));
        lbl_Address->setText(QApplication::translate("AD9102UI", "ADDRESS", 0, QApplication::UnicodeUTF8));
        lbl_Data->setText(QApplication::translate("AD9102UI", "DATA", 0, QApplication::UnicodeUTF8));
        pb_Read->setText(QApplication::translate("AD9102UI", "Read", 0, QApplication::UnicodeUTF8));
        pb_Write->setText(QApplication::translate("AD9102UI", "Write", 0, QApplication::UnicodeUTF8));
        grpBox_AppReadWrite->setTitle(QApplication::translate("AD9102UI", "APP Card Read/Write", 0, QApplication::UnicodeUTF8));
        lbl_AppAddress->setText(QApplication::translate("AD9102UI", "ADDRESS", 0, QApplication::UnicodeUTF8));
        lbl_AppData->setText(QApplication::translate("AD9102UI", "DATA", 0, QApplication::UnicodeUTF8));
        pb_AppRead->setText(QApplication::translate("AD9102UI", "Read", 0, QApplication::UnicodeUTF8));
        pb_AppWrite->setText(QApplication::translate("AD9102UI", "Write", 0, QApplication::UnicodeUTF8));
        grpBox_Test->setTitle(QApplication::translate("AD9102UI", "AD9102  SPI Data Operations", 0, QApplication::UnicodeUTF8));
        lbl_Delay->setText(QApplication::translate("AD9102UI", "Delay", 0, QApplication::UnicodeUTF8));
        pb_Test->setText(QApplication::translate("AD9102UI", "Load", 0, QApplication::UnicodeUTF8));
        pb_Reset->setText(QApplication::translate("AD9102UI", "Chip Reset", 0, QApplication::UnicodeUTF8));
        pb_Trigger->setText(QApplication::translate("AD9102UI", "Trigger High", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("AD9102UI", "1ms default", 0, QApplication::UnicodeUTF8));
        pb_TestWrite->setText(QApplication::translate("AD9102UI", "Write", 0, QApplication::UnicodeUTF8));
        pb_Update->setText(QApplication::translate("AD9102UI", "Update", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("AD9102UI", "Load", 0, QApplication::UnicodeUTF8));
        pb_TestRUN->setText(QApplication::translate("AD9102UI", "RUN", 0, QApplication::UnicodeUTF8));
        writing1->setText(QApplication::translate("AD9102UI", "....", 0, QApplication::UnicodeUTF8));
        pb_TestRead->setText(QApplication::translate("AD9102UI", "Read", 0, QApplication::UnicodeUTF8));
        grpBox_SRAMReadWrite->setTitle(QApplication::translate("AD9102UI", "AD9102 SRAM Read/Write", 0, QApplication::UnicodeUTF8));
        lbl_SRAMAddress->setText(QApplication::translate("AD9102UI", "ADDRESS", 0, QApplication::UnicodeUTF8));
        lbl_SRAMData->setText(QApplication::translate("AD9102UI", "DATA", 0, QApplication::UnicodeUTF8));
        pb_SRAMRead->setText(QApplication::translate("AD9102UI", "Read", 0, QApplication::UnicodeUTF8));
        pb_SRAMWrite->setText(QApplication::translate("AD9102UI", "Write", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("AD9102UI", "(0x6000-0x6FFF)", 0, QApplication::UnicodeUTF8));
        grpBox_SRAMUpdate->setTitle(QApplication::translate("AD9102UI", "AD9102  SRAM Update", 0, QApplication::UnicodeUTF8));
        lbl_SRAMStartAddress->setText(QApplication::translate("AD9102UI", "START ADDR", 0, QApplication::UnicodeUTF8));
        pb_SRAMLoad->setText(QApplication::translate("AD9102UI", "Load", 0, QApplication::UnicodeUTF8));
        pb_SRAMUpdate->setText(QApplication::translate("AD9102UI", "Write", 0, QApplication::UnicodeUTF8));
        lbl_SRAMCount->setText(QApplication::translate("AD9102UI", "COUNT", 0, QApplication::UnicodeUTF8));
        writing2->setText(QApplication::translate("AD9102UI", "....", 0, QApplication::UnicodeUTF8));
        grpBox_Parameters->setTitle(QApplication::translate("AD9102UI", "AD9102  Parameters", 0, QApplication::UnicodeUTF8));
        lbl_Frequency->setText(QApplication::translate("AD9102UI", "Frequency", 0, QApplication::UnicodeUTF8));
        lbl_Phase->setText(QApplication::translate("AD9102UI", "Phase", 0, QApplication::UnicodeUTF8));
        lbl_HexFrequency->setText(QString());
        lbl_HexPhase->setText(QString());
        pushButton->setText(QApplication::translate("AD9102UI", "PushButton", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("AD9102UI", "Zero", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("AD9102UI", "FF", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AD9102UI: public Ui_AD9102UI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AD9102UI_H
