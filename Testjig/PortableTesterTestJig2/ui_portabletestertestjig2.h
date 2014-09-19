/********************************************************************************
** Form generated from reading UI file 'portabletestertestjig2.ui'
**
** Created: Fri Sep 19 18:58:45 2014
**      by: Qt User Interface Compiler version 4.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PORTABLETESTERTESTJIG2_H
#define UI_PORTABLETESTERTESTJIG2_H

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
#include <QtGui/QScrollArea>
#include <QtGui/QSpinBox>
#include <QtGui/QTabWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PortableTesterTestJig2Class
{
public:
    QTabWidget *tabWidget;
    QWidget *AWG;
    QWidget *DMMSL;
    QWidget *ICM;
    QWidget *VI;
    QWidget *FM;
    QWidget *ACR;
    QWidget *PSOC;
    QWidget *KeyKnob;
    QWidget *DDS;
    QWidget *Plot;
    QWidget *HAADC;
    QWidget *APPDRVRX;
    QWidget *AD5318;
    QWidget *RAMData;
    QWidget *AD9102;
    QWidget *Viewer;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGroupBox *groupBox;
    QLabel *PAGElabel;
    QSpinBox *pageSpinBox;
    QPushButton *LOADpushButton;
    QLineEdit *lineEdit;
    QLabel *ZOOMlabel;
    QComboBox *scaleComboBox;
    QGroupBox *groupBox_2;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;

    void setupUi(QWidget *PortableTesterTestJig2Class)
    {
        if (PortableTesterTestJig2Class->objectName().isEmpty())
            PortableTesterTestJig2Class->setObjectName(QString::fromUtf8("PortableTesterTestJig2Class"));
        PortableTesterTestJig2Class->resize(800, 600);
        QPalette palette;
        QBrush brush(QColor(108, 108, 107, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        PortableTesterTestJig2Class->setPalette(palette);
        QFont font;
        font.setFamily(QString::fromUtf8("DejaVu Sans"));
        font.setPointSize(11);
        PortableTesterTestJig2Class->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/pt1.png"), QSize(), QIcon::Normal, QIcon::Off);
        PortableTesterTestJig2Class->setWindowIcon(icon);
        tabWidget = new QTabWidget(PortableTesterTestJig2Class);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 800, 601));
        QPalette palette1;
        QBrush brush2(QColor(0, 0, 0, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush);
        QBrush brush3(QColor(162, 162, 161, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush3);
        QBrush brush4(QColor(135, 135, 134, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Midlight, brush4);
        QBrush brush5(QColor(54, 54, 53, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Dark, brush5);
        QBrush brush6(QColor(72, 72, 71, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Mid, brush6);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush5);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Midlight, brush4);
        palette1.setBrush(QPalette::Inactive, QPalette::Dark, brush5);
        palette1.setBrush(QPalette::Inactive, QPalette::Mid, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush5);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush5);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Midlight, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Dark, brush5);
        palette1.setBrush(QPalette::Disabled, QPalette::Mid, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush5);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush5);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush5);
        tabWidget->setPalette(palette1);
        QFont font1;
        font1.setFamily(QString::fromUtf8("DejaVu Sans"));
        font1.setBold(false);
        font1.setWeight(50);
        tabWidget->setFont(font1);
        tabWidget->setStyleSheet(QString::fromUtf8("QTabWidget{\n"
"font: \"DejaVu Sans\";\n"
"}\n"
"\n"
"QTabBar::scroller {\n"
"width: 50px;\n"
"}\n"
"\n"
"QWidget{\n"
"font: \"DejaVu Sans\";\n"
"}"));
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setIconSize(QSize(32, 32));
        tabWidget->setElideMode(Qt::ElideNone);
        tabWidget->setDocumentMode(true);
        tabWidget->setTabsClosable(false);
        tabWidget->setMovable(false);
        AWG = new QWidget();
        AWG->setObjectName(QString::fromUtf8("AWG"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/awg.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(AWG, icon1, QString());
        DMMSL = new QWidget();
        DMMSL->setObjectName(QString::fromUtf8("DMMSL"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/Dmmlg.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(DMMSL, icon2, QString());
        ICM = new QWidget();
        ICM->setObjectName(QString::fromUtf8("ICM"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/Icmbr.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(ICM, icon3, QString());
        VI = new QWidget();
        VI->setObjectName(QString::fromUtf8("VI"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/vib.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(VI, icon4, QString());
        FM = new QWidget();
        FM->setObjectName(QString::fromUtf8("FM"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/ram.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(FM, icon5, QString());
        ACR = new QWidget();
        ACR->setObjectName(QString::fromUtf8("ACR"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/images/Pulse with modulation.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(ACR, icon6, QString());
        PSOC = new QWidget();
        PSOC->setObjectName(QString::fromUtf8("PSOC"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/images/Shortr.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(PSOC, icon7, QString());
        KeyKnob = new QWidget();
        KeyKnob->setObjectName(QString::fromUtf8("KeyKnob"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/images/key.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(KeyKnob, icon8, QString());
        DDS = new QWidget();
        DDS->setObjectName(QString::fromUtf8("DDS"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/images/sincos.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(DDS, icon9, QString());
        Plot = new QWidget();
        Plot->setObjectName(QString::fromUtf8("Plot"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/images/Plot.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(Plot, icon10, QString());
        HAADC = new QWidget();
        HAADC->setObjectName(QString::fromUtf8("HAADC"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/images/HAADC.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(HAADC, icon11, QString());
        APPDRVRX = new QWidget();
        APPDRVRX->setObjectName(QString::fromUtf8("APPDRVRX"));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/images/appdrvrx.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(APPDRVRX, icon12, QString());
        AD5318 = new QWidget();
        AD5318->setObjectName(QString::fromUtf8("AD5318"));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/images/AD5318.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(AD5318, icon13, QString());
        RAMData = new QWidget();
        RAMData->setObjectName(QString::fromUtf8("RAMData"));
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/images/ram-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(RAMData, icon14, QString());
        AD9102 = new QWidget();
        AD9102->setObjectName(QString::fromUtf8("AD9102"));
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/images/AD9102.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(AD9102, icon15, QString());
        Viewer = new QWidget();
        Viewer->setObjectName(QString::fromUtf8("Viewer"));
        scrollArea = new QScrollArea(Viewer);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(0, 0, 730, 520));
        scrollArea->setFont(font1);
        scrollArea->setFocusPolicy(Qt::NoFocus);
        scrollArea->setStyleSheet(QString::fromUtf8("QScrollArea{\n"
"\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 gray, stop: 1 #E0E0E0);\n"
"     border: 1px solid black;\n"
"     border-radius: 0px;\n"
"}\n"
"  "));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 728, 518));
        scrollArea->setWidget(scrollAreaWidgetContents);
        groupBox = new QGroupBox(Viewer);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(730, -6, 70, 300));
        QFont font2;
        font2.setFamily(QString::fromUtf8("DejaVu Sans"));
        font2.setPointSize(10);
        font2.setBold(false);
        font2.setWeight(50);
        groupBox->setFont(font2);
        groupBox->setStyleSheet(QString::fromUtf8(" QGroupBox {\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 gray, stop: 1 #E0E0E0);\n"
"     border: 1px solid black;\n"
"     border-radius: 0px;\n"
"     margin-top: 1ex; /* leave space at the top for the title */\n"
" }\n"
""));
        PAGElabel = new QLabel(groupBox);
        PAGElabel->setObjectName(QString::fromUtf8("PAGElabel"));
        PAGElabel->setGeometry(QRect(20, 91, 51, 17));
        QFont font3;
        font3.setFamily(QString::fromUtf8("DejaVu Sans"));
        font3.setPointSize(12);
        font3.setBold(false);
        font3.setWeight(50);
        PAGElabel->setFont(font3);
        pageSpinBox = new QSpinBox(groupBox);
        pageSpinBox->setObjectName(QString::fromUtf8("pageSpinBox"));
        pageSpinBox->setEnabled(false);
        pageSpinBox->setGeometry(QRect(4, 140, 60, 70));
        pageSpinBox->setFont(font1);
        pageSpinBox->setFocusPolicy(Qt::NoFocus);
        pageSpinBox->setLayoutDirection(Qt::RightToLeft);
        pageSpinBox->setStyleSheet(QString::fromUtf8(" QSpinBox {\n"
" border: 2px solid #8f8f91;\n"
"     border-radius: 6px;\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #f6f7fa, stop: 1 #dadbde);\n"
" }\n"
"\n"
" QSpinBox::up-button {\n"
"     subcontrol-origin: border;\n"
"     subcontrol-position: top right; /* position at the top right corner */\n"
"     width: 70px; /* 16 + 2*1px border-width = 15px padding + 3px parent border */\n"
" }\n"
" QSpinBox::up-arrow {\n"
"     width: 50px;\n"
"     height: 50px;\n"
" }\n"
"\n"
"\n"
" QSpinBox::down-button {\n"
"     subcontrol-origin: border;\n"
"     subcontrol-position: bottom right; /* position at bottom right corner */\n"
"     width: 70px;\n"
" }\n"
"\n"
" QSpinBox::down-arrow {\n"
"\n"
"     width: 50px;\n"
"     height: 50px;\n"
" }\n"
"\n"
""));
        pageSpinBox->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        LOADpushButton = new QPushButton(groupBox);
        LOADpushButton->setObjectName(QString::fromUtf8("LOADpushButton"));
        LOADpushButton->setGeometry(QRect(2, 24, 64, 61));
        QFont font4;
        font4.setFamily(QString::fromUtf8("DejaVu Sans"));
        font4.setPointSize(12);
        font4.setBold(false);
        font4.setWeight(50);
        font4.setStyleStrategy(QFont::PreferAntialias);
        LOADpushButton->setFont(font4);
        LOADpushButton->setFocusPolicy(Qt::NoFocus);
        LOADpushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"     border: 2px solid #8f8f91;\n"
"     border-radius: 18px;\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #f6f7fa, stop: 1 #dadbde);\n"
"}\n"
"\n"
" QPushButton:pressed {\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
" }\n"
"\n"
" QPushButton:flat {\n"
"     border: none; /* no border for a flat push button */\n"
" }\n"
"\n"
" QPushButton:default {\n"
"     border-color: navy; /* make the default button prominent */\n"
" }"));
        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(15, 105, 40, 30));
        QFont font5;
        font5.setBold(false);
        font5.setItalic(false);
        font5.setWeight(50);
        lineEdit->setFont(font5);
        lineEdit->setFocusPolicy(Qt::NoFocus);
        lineEdit->setLayoutDirection(Qt::LeftToRight);
        lineEdit->setStyleSheet(QString::fromUtf8(" QLineEdit {\n"
" border: 2px solid #8f8f91;\n"
"     border-radius: 6px;\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #f6f7fa, stop: 1 #dadbde);\n"
" }\n"
""));
        lineEdit->setAlignment(Qt::AlignCenter);
        ZOOMlabel = new QLabel(groupBox);
        ZOOMlabel->setObjectName(QString::fromUtf8("ZOOMlabel"));
        ZOOMlabel->setGeometry(QRect(16, 230, 70, 17));
        ZOOMlabel->setFont(font3);
        scaleComboBox = new QComboBox(groupBox);
        scaleComboBox->setObjectName(QString::fromUtf8("scaleComboBox"));
        scaleComboBox->setEnabled(false);
        scaleComboBox->setGeometry(QRect(5, 249, 60, 31));
        scaleComboBox->setFont(font5);
        scaleComboBox->setFocusPolicy(Qt::NoFocus);
        scaleComboBox->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"   border: 2px solid #8f8f91;\n"
"     border-radius: 6px;\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #f6f7fa, stop: 1 #dadbde);\n"
" }\n"
""));
        groupBox_2 = new QGroupBox(Viewer);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(730, 287, 70, 233));
        groupBox_2->setStyleSheet(QString::fromUtf8(" QGroupBox {\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 gray, stop: 1 #E0E0E0);\n"
"     border: 1px solid black;\n"
"     border-radius: 0px;\n"
"     margin-top: 1ex; /* leave space at the top for the title */\n"
" }\n"
""));
        pushButton_2 = new QPushButton(groupBox_2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(0, 10, 70, 70));
        pushButton_2->setFont(font5);
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"     border: 2px solid #8f8f91;\n"
"     border-radius: 2px;\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #f6f7fa, stop: 1 #dadbde);\n"
"}\n"
"\n"
" QPushButton:pressed {\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
" }\n"
"\n"
" QPushButton:flat {\n"
"     border: none; /* no border for a flat push button */\n"
" }\n"
"\n"
" QPushButton:default {\n"
"     border-color: navy; /* make the default button prominent */\n"
" }"));
        pushButton_3 = new QPushButton(groupBox_2);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(0, 80, 70, 70));
        pushButton_3->setFont(font5);
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"     border: 2px solid #8f8f91;\n"
"     border-radius: 2px;\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #f6f7fa, stop: 1 #dadbde);\n"
"}\n"
"\n"
" QPushButton:pressed {\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
" }\n"
"\n"
" QPushButton:flat {\n"
"     border: none; /* no border for a flat push button */\n"
" }\n"
"\n"
" QPushButton:default {\n"
"     border-color: navy; /* make the default button prominent */\n"
" }"));
        pushButton_4 = new QPushButton(groupBox_2);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(0, 150, 70, 70));
        pushButton_4->setFont(font5);
        pushButton_4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"     border: 2px solid #8f8f91;\n"
"     border-radius: 2px;\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #f6f7fa, stop: 1 #dadbde);\n"
"}\n"
"\n"
" QPushButton:pressed {\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
" }\n"
"\n"
" QPushButton:flat {\n"
"     border: none; /* no border for a flat push button */\n"
" }\n"
"\n"
" QPushButton:default {\n"
"     border-color: navy; /* make the default button prominent */\n"
" }"));
        pushButton = new QPushButton(Viewer);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(660, 450, 50, 50));
        pushButton->setFont(font5);
        pushButton->setFocusPolicy(Qt::NoFocus);
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"     border: 2px solid #8f8f91;\n"
"     border-radius: 25px;\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #f6f7fa, stop: 1 #dadbde);\n"
"}\n"
"\n"
" QPushButton:pressed {\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
" }\n"
"\n"
" QPushButton:flat {\n"
"     border: none; /* no border for a flat push button */\n"
" }\n"
"\n"
" QPushButton:default {\n"
"     border-color: navy; /* make the default button prominent */\n"
" }"));
        pushButton_5 = new QPushButton(Viewer);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(600, 450, 50, 50));
        pushButton_5->setFont(font5);
        pushButton_5->setFocusPolicy(Qt::NoFocus);
        pushButton_5->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"     border: 2px solid #8f8f91;\n"
"     border-radius: 25px;\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #f6f7fa, stop: 1 #dadbde);\n"
"}\n"
"\n"
" QPushButton:pressed {\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
" }\n"
"\n"
" QPushButton:flat {\n"
"     border: none; /* no border for a flat push button */\n"
" }\n"
"\n"
" QPushButton:default {\n"
"     border-color: navy; /* make the default button prominent */\n"
" }"));
        QIcon icon16;
        icon16.addFile(QString::fromUtf8(":/images/viewer.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(Viewer, icon16, QString());
        scrollArea->raise();
        groupBox->raise();
        groupBox_2->raise();
        pushButton_5->raise();
        pushButton->raise();
        pushButton_6 = new QPushButton(PortableTesterTestJig2Class);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(739, 1, 60, 45));

        retranslateUi(PortableTesterTestJig2Class);

        tabWidget->setCurrentIndex(6);
        scaleComboBox->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(PortableTesterTestJig2Class);
    } // setupUi

    void retranslateUi(QWidget *PortableTesterTestJig2Class)
    {
        PortableTesterTestJig2Class->setWindowTitle(QApplication::translate("PortableTesterTestJig2Class", "PortableTesterTestJig2", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(AWG), QApplication::translate("PortableTesterTestJig2Class", "AWG", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(DMMSL), QApplication::translate("PortableTesterTestJig2Class", "DMM/SL", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(ICM), QApplication::translate("PortableTesterTestJig2Class", "ICM", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(VI), QApplication::translate("PortableTesterTestJig2Class", "VI", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(FM), QApplication::translate("PortableTesterTestJig2Class", "Flash", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(ACR), QApplication::translate("PortableTesterTestJig2Class", "ACR", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(PSOC), QApplication::translate("PortableTesterTestJig2Class", "PSOC", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(KeyKnob), QApplication::translate("PortableTesterTestJig2Class", "KeyKnob", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(DDS), QApplication::translate("PortableTesterTestJig2Class", "DDS", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(Plot), QApplication::translate("PortableTesterTestJig2Class", "Plot", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(HAADC), QApplication::translate("PortableTesterTestJig2Class", "HAADC", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(APPDRVRX), QApplication::translate("PortableTesterTestJig2Class", "APP_DRV_RX", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(AD5318), QApplication::translate("PortableTesterTestJig2Class", "AD5318", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(RAMData), QApplication::translate("PortableTesterTestJig2Class", "RAMData", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(AD9102), QApplication::translate("PortableTesterTestJig2Class", "AD9102", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QString());
        PAGElabel->setText(QApplication::translate("PortableTesterTestJig2Class", "PAGE", 0, QApplication::UnicodeUTF8));
        LOADpushButton->setText(QApplication::translate("PortableTesterTestJig2Class", "OPEN \n"
" FILE", 0, QApplication::UnicodeUTF8));
        ZOOMlabel->setText(QApplication::translate("PortableTesterTestJig2Class", "SCALE", 0, QApplication::UnicodeUTF8));
        scaleComboBox->clear();
        scaleComboBox->insertItems(0, QStringList()
         << QApplication::translate("PortableTesterTestJig2Class", "25%", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PortableTesterTestJig2Class", "50%", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PortableTesterTestJig2Class", "75%", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PortableTesterTestJig2Class", "100%", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PortableTesterTestJig2Class", "125%", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PortableTesterTestJig2Class", "150%", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PortableTesterTestJig2Class", "200%", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PortableTesterTestJig2Class", "300%", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PortableTesterTestJig2Class", "400%", 0, QApplication::UnicodeUTF8)
        );
        groupBox_2->setTitle(QString());
        pushButton_2->setText(QApplication::translate("PortableTesterTestJig2Class", "AppCard\n"
"Register\n"
"Details", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("PortableTesterTestJig2Class", "BackPanel\n"
"Register\n"
"Details", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("PortableTesterTestJig2Class", "PSOC\n"
"Commands\n"
"Details", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("PortableTesterTestJig2Class", "-", 0, QApplication::UnicodeUTF8));
        pushButton_5->setText(QApplication::translate("PortableTesterTestJig2Class", "+", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(Viewer), QApplication::translate("PortableTesterTestJig2Class", "Viewer", 0, QApplication::UnicodeUTF8));
        pushButton_6->setText(QApplication::translate("PortableTesterTestJig2Class", "CLOSE", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class PortableTesterTestJig2Class: public Ui_PortableTesterTestJig2Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PORTABLETESTERTESTJIG2_H
