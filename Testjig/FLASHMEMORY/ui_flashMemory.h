/********************************************************************************
** Form generated from reading UI file 'flashMemory.ui'
**
** Created: Sat Sep 6 10:53:04 2014
**      by: Qt User Interface Compiler version 4.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FLASHMEMORY_H
#define UI_FLASHMEMORY_H

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
#include <QtGui/QRadioButton>
#include <QtGui/QTableWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGroupBox *grpFLASHRW;
    QTableWidget *tableWidget;
    QGroupBox *grpMEMSeque;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QGroupBox *groupBox;
    QRadioButton *optFlash;
    QRadioButton *optRAM;
    QRadioButton *optDDR;
    QRadioButton *optSystemMemory;
    QRadioButton *optReceiveRAM;
    QGroupBox *grpdrvBulkMEM;
    QPushButton *butRead;
    QPushButton *butWrite;
    QCheckBox *chkSingle;
    QGroupBox *grpMEMfill;
    QRadioButton *optZeros;
    QRadioButton *optFFs;
    QGroupBox *grpSELECTCARD;
    QPushButton *butLoadFile;
    QPushButton *butSaveFile;
    QGroupBox *grpMEMErase;
    QPushButton *butPageErase;
    QLabel *label;
    QPushButton *butErase;
    QGroupBox *grpSYSTEMMEMORY;
    QRadioButton *optSlot1;
    QRadioButton *optSlot2;
    QRadioButton *optSlot3;
    QRadioButton *optSlot0;
    QGroupBox *grpCODEID;
    QPushButton *butCODEID;
    QLineEdit *lecodeID;
    QGroupBox *grpSYSTEM;
    QComboBox *cmbHWSelect;
    QLabel *label_2;
    QLabel *lblIndex;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(800, 600);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(108, 108, 107, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(162, 162, 161, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(135, 135, 134, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(54, 54, 53, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(72, 72, 71, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QBrush brush6(QColor(0, 0, 0, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush6);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush4);
        QBrush brush7(QColor(255, 255, 220, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush6);
        Widget->setPalette(palette);
        Widget->setStyleSheet(QString::fromUtf8("\n"
"QPushButton{\n"
"border: 1px solid #2D5059;\n"
"border-radius: 20px;\n"
"background-color: qlineargradient(x1: 0, y1: 1, x2: 1, y2: 0,stop: 0 #1A74DB, stop: 0.6 #5293DE, stop:1 #FFFFFF);\n"
"font:bold;\n"
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
        grpFLASHRW = new QGroupBox(Widget);
        grpFLASHRW->setObjectName(QString::fromUtf8("grpFLASHRW"));
        grpFLASHRW->setGeometry(QRect(10, 10, 781, 371));
        grpFLASHRW->setStyleSheet(QString::fromUtf8("QGroupBox::title {\n"
"		color:white;\n"
"     subcontrol-origin: margin;\n"
"     subcontrol-position: top center; /* position at the top center */\n"
"     padding: 0 3px;\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #FFOECE, stop: 1 #FFFFFF);\n"
" }\n"
"QLabel{\n"
"	color:white;\n"
"}"));
        tableWidget = new QTableWidget(grpFLASHRW);
        if (tableWidget->columnCount() < 16)
            tableWidget->setColumnCount(16);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(9, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(10, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(11, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(12, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(13, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(14, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(15, __qtablewidgetitem15);
        if (tableWidget->rowCount() < 16)
            tableWidget->setRowCount(16);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(2, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(3, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(4, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(5, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(6, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(7, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(8, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(9, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(10, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(11, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(12, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(13, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(14, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(15, __qtablewidgetitem31);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(7, 15, 511, 351));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy);
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        tableWidget->setPalette(palette1);
        tableWidget->setAutoFillBackground(true);
        tableWidget->setStyleSheet(QString::fromUtf8("QTableWidget{color:white;}\n"
"QHeaderView::section\n"
"{\n"
"spacing: 10px;\n"
"background-color:lightblue;\n"
"color: black;\n"
"border: 1px solid black;\n"
"margin: 1px;\n"
"text-align: right;\n"
"font-family: arial;\n"
"font-size:12px;\n"
"}\n"
""));
        tableWidget->setFrameShape(QFrame::Panel);
        tableWidget->setFrameShadow(QFrame::Raised);
        tableWidget->setLineWidth(3);
        tableWidget->setMidLineWidth(3);
        tableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        tableWidget->setAlternatingRowColors(false);
        tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidget->setTextElideMode(Qt::ElideMiddle);
        tableWidget->setGridStyle(Qt::SolidLine);
        tableWidget->setWordWrap(true);
        tableWidget->setCornerButtonEnabled(false);
        tableWidget->setRowCount(16);
        tableWidget->horizontalHeader()->setVisible(true);
        tableWidget->horizontalHeader()->setCascadingSectionResizes(false);
        tableWidget->horizontalHeader()->setDefaultSectionSize(40);
        tableWidget->horizontalHeader()->setHighlightSections(true);
        tableWidget->horizontalHeader()->setMinimumSectionSize(40);
        tableWidget->verticalHeader()->setVisible(true);
        tableWidget->verticalHeader()->setDefaultSectionSize(20);
        tableWidget->verticalHeader()->setHighlightSections(true);
        tableWidget->verticalHeader()->setMinimumSectionSize(20);
        grpMEMSeque = new QGroupBox(grpFLASHRW);
        grpMEMSeque->setObjectName(QString::fromUtf8("grpMEMSeque"));
        grpMEMSeque->setGeometry(QRect(524, 20, 251, 131));
        grpMEMSeque->setStyleSheet(QString::fromUtf8("QGroupBox::title {\n"
"		color:white;\n"
"     subcontrol-origin: margin;\n"
"     subcontrol-position: top center; /* position at the top center */\n"
"     padding: 0 3px;\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #FFOECE, stop: 1 #FFFFFF);\n"
" }\n"
"QLabel{\n"
"	color:white;\n"
"}"));
        label_3 = new QLabel(grpMEMSeque);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(11, 2, 101, 20));
        label_4 = new QLabel(grpMEMSeque);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(12, 62, 101, 20));
        label_5 = new QLabel(grpMEMSeque);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(136, 2, 101, 20));
        label_6 = new QLabel(grpMEMSeque);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(110, 63, 51, 20));
        label_7 = new QLabel(grpMEMSeque);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(181, 63, 51, 20));
        groupBox = new QGroupBox(grpFLASHRW);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(526, 220, 181, 131));
        groupBox->setStyleSheet(QString::fromUtf8("QGroupBox::title {\n"
"		color:white;\n"
"     subcontrol-origin: margin;\n"
"     subcontrol-position: top center; /* position at the top center */\n"
"     padding: 0 3px;\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #FFOECE, stop: 1 #FFFFFF);\n"
" }\n"
"QLabel{\n"
"	color:white;\n"
"}"));
        optFlash = new QRadioButton(groupBox);
        optFlash->setObjectName(QString::fromUtf8("optFlash"));
        optFlash->setGeometry(QRect(10, 53, 91, 31));
        QFont font;
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        optFlash->setFont(font);
        optFlash->setStyleSheet(QString::fromUtf8("QRadioButton{\n"
"font: 14px;\n"
"color:white\n"
"}\n"
" QRadioButton::indicator {\n"
"     width: 20px;\n"
"     height:20px;\n"
"   border: 2px solid black;\n"
"	 border-radius:12px;\n"
"\n"
" }\n"
" QRadioButton::indicator::unchecked {\n"
"		background-color:white;\n"
"     }\n"
"\n"
"     QRadioButton::indicator:unchecked:hover {\n"
"		background-color:white;\n"
"     }\n"
"\n"
"     QRadioButton::indicator:unchecked:pressed {\n"
"		background-color:white;\n"
"     }\n"
"\n"
"     QRadioButton::indicator::checked {\n"
"		background-color:#f2a400;\n"
"     }\n"
"\n"
"     QRadioButton::indicator:checked:hover {\n"
"		background-color:#f2a400;\n"
"     }\n"
"\n"
"     QRadioButton::indicator:checked:pressed {\n"
"		background-color:#f2a400;\n"
"     }"));
        optRAM = new QRadioButton(groupBox);
        optRAM->setObjectName(QString::fromUtf8("optRAM"));
        optRAM->setGeometry(QRect(10, 89, 91, 31));
        optRAM->setFont(font);
        optRAM->setStyleSheet(QString::fromUtf8("QRadioButton{\n"
"font: 14px;\n"
"color:white\n"
"}\n"
" QRadioButton::indicator {\n"
"     width: 20px;\n"
"     height:20px;\n"
"   border: 2px solid black;\n"
"	 border-radius:12px;\n"
"\n"
" }\n"
" QRadioButton::indicator::unchecked {\n"
"		background-color:white;\n"
"     }\n"
"\n"
"     QRadioButton::indicator:unchecked:hover {\n"
"		background-color:white;\n"
"     }\n"
"\n"
"     QRadioButton::indicator:unchecked:pressed {\n"
"		background-color:white;\n"
"     }\n"
"\n"
"     QRadioButton::indicator::checked {\n"
"		background-color:#f2a400;\n"
"     }\n"
"\n"
"     QRadioButton::indicator:checked:hover {\n"
"		background-color:#f2a400;\n"
"     }\n"
"\n"
"     QRadioButton::indicator:checked:pressed {\n"
"		background-color:#f2a400;\n"
"     }"));
        optDDR = new QRadioButton(groupBox);
        optDDR->setObjectName(QString::fromUtf8("optDDR"));
        optDDR->setGeometry(QRect(99, 53, 81, 31));
        optDDR->setFont(font);
        optDDR->setStyleSheet(QString::fromUtf8("QRadioButton{\n"
"font: 14px;\n"
"color:white\n"
"}\n"
" QRadioButton::indicator {\n"
"     width: 20px;\n"
"     height:20px;\n"
"   border: 2px solid black;\n"
"	 border-radius:12px;\n"
"\n"
" }\n"
" QRadioButton::indicator::unchecked {\n"
"		background-color:white;\n"
"     }\n"
"\n"
"     QRadioButton::indicator:unchecked:hover {\n"
"		background-color:white;\n"
"     }\n"
"\n"
"     QRadioButton::indicator:unchecked:pressed {\n"
"		background-color:white;\n"
"     }\n"
"\n"
"     QRadioButton::indicator::checked {\n"
"		background-color:#f2a400;\n"
"     }\n"
"\n"
"     QRadioButton::indicator:checked:hover {\n"
"		background-color:#f2a400;\n"
"     }\n"
"\n"
"     QRadioButton::indicator:checked:pressed {\n"
"		background-color:#f2a400;\n"
"     }"));
        optSystemMemory = new QRadioButton(groupBox);
        optSystemMemory->setObjectName(QString::fromUtf8("optSystemMemory"));
        optSystemMemory->setGeometry(QRect(10, 17, 171, 31));
        optSystemMemory->setFont(font);
        optSystemMemory->setStyleSheet(QString::fromUtf8("QRadioButton{\n"
"font: 14px;\n"
"color:white\n"
"}\n"
" QRadioButton::indicator {\n"
"     width: 20px;\n"
"     height:20px;\n"
"   border: 2px solid black;\n"
"	 border-radius:12px;\n"
"\n"
" }\n"
" QRadioButton::indicator::unchecked {\n"
"		background-color:white;\n"
"     }\n"
"\n"
"     QRadioButton::indicator:unchecked:hover {\n"
"		background-color:white;\n"
"     }\n"
"\n"
"     QRadioButton::indicator:unchecked:pressed {\n"
"		background-color:white;\n"
"     }\n"
"\n"
"     QRadioButton::indicator::checked {\n"
"		background-color:#f2a400;\n"
"     }\n"
"\n"
"     QRadioButton::indicator:checked:hover {\n"
"		background-color:#f2a400;\n"
"     }\n"
"\n"
"     QRadioButton::indicator:checked:pressed {\n"
"		background-color:#f2a400;\n"
"     }"));
        optReceiveRAM = new QRadioButton(groupBox);
        optReceiveRAM->setObjectName(QString::fromUtf8("optReceiveRAM"));
        optReceiveRAM->setGeometry(QRect(100, 90, 81, 31));
        optReceiveRAM->setFont(font);
        optReceiveRAM->setStyleSheet(QString::fromUtf8("QRadioButton{\n"
"font: 14px;\n"
"color:white\n"
"}\n"
" QRadioButton::indicator {\n"
"     width: 20px;\n"
"     height:20px;\n"
"   border: 2px solid black;\n"
"	 border-radius:12px;\n"
"\n"
" }\n"
" QRadioButton::indicator::unchecked {\n"
"		background-color:white;\n"
"     }\n"
"\n"
"     QRadioButton::indicator:unchecked:hover {\n"
"		background-color:white;\n"
"     }\n"
"\n"
"     QRadioButton::indicator:unchecked:pressed {\n"
"		background-color:white;\n"
"     }\n"
"\n"
"     QRadioButton::indicator::checked {\n"
"		background-color:#f2a400;\n"
"     }\n"
"\n"
"     QRadioButton::indicator:checked:hover {\n"
"		background-color:#f2a400;\n"
"     }\n"
"\n"
"     QRadioButton::indicator:checked:pressed {\n"
"		background-color:#f2a400;\n"
"     }"));
        grpdrvBulkMEM = new QGroupBox(grpFLASHRW);
        grpdrvBulkMEM->setObjectName(QString::fromUtf8("grpdrvBulkMEM"));
        grpdrvBulkMEM->setGeometry(QRect(526, 150, 251, 67));
        grpdrvBulkMEM->setStyleSheet(QString::fromUtf8("QGroupBox::title {\n"
"		color:white;\n"
"     subcontrol-origin: margin;\n"
"     subcontrol-position: top center; /* position at the top center */\n"
"     padding: 0 3px;\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #FFOECE, stop: 1 #FFFFFF);\n"
" }\n"
"QLabel{\n"
"	color:white;\n"
"}"));
        butRead = new QPushButton(grpdrvBulkMEM);
        butRead->setObjectName(QString::fromUtf8("butRead"));
        butRead->setGeometry(QRect(10, 20, 84, 41));
        butRead->setFocusPolicy(Qt::NoFocus);
        butRead->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color:white;\n"
"border: 1px solid #2D5059;\n"
"border-radius: 20px;\n"
"background-color: qlineargradient(x1: 0, y1: 1, x2: 1, y2: 0,stop: 0 #1A74DB, stop: 0.6 #5293DE, stop:1 #FFFFFF);\n"
"font:bold;\n"
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
        butWrite = new QPushButton(grpdrvBulkMEM);
        butWrite->setObjectName(QString::fromUtf8("butWrite"));
        butWrite->setGeometry(QRect(100, 20, 84, 41));
        butWrite->setFocusPolicy(Qt::NoFocus);
        butWrite->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color:white;\n"
"border: 1px solid #2D5059;\n"
"border-radius: 20px;\n"
"background-color: qlineargradient(x1: 0, y1: 1, x2: 1, y2: 0,stop: 0 #1A74DB, stop: 0.6 #5293DE, stop:1 #FFFFFF);\n"
"font:bold;\n"
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
        chkSingle = new QCheckBox(grpdrvBulkMEM);
        chkSingle->setObjectName(QString::fromUtf8("chkSingle"));
        chkSingle->setGeometry(QRect(188, 24, 61, 31));
        QFont font1;
        font1.setPointSize(9);
        chkSingle->setFont(font1);
        chkSingle->setStyleSheet(QString::fromUtf8("color:white;"));
        grpMEMfill = new QGroupBox(grpFLASHRW);
        grpMEMfill->setObjectName(QString::fromUtf8("grpMEMfill"));
        grpMEMfill->setGeometry(QRect(710, 220, 61, 131));
        grpMEMfill->setStyleSheet(QString::fromUtf8("QGroupBox::title {\n"
"		color:white;\n"
"     subcontrol-origin: margin;\n"
"     subcontrol-position: top center; /* position at the top center */\n"
"     padding: 0 3px;\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #FFOECE, stop: 1 #FFFFFF);\n"
" }\n"
"QLabel{\n"
"	color:white;\n"
"}"));
        optZeros = new QRadioButton(grpMEMfill);
        optZeros->setObjectName(QString::fromUtf8("optZeros"));
        optZeros->setGeometry(QRect(4, 24, 51, 41));
        optZeros->setStyleSheet(QString::fromUtf8("QRadioButton{\n"
"font: 14px;\n"
"color:white\n"
"}\n"
" QRadioButton::indicator {\n"
"     width: 20px;\n"
"     height:20px;\n"
"   border: 2px solid black;\n"
"	 border-radius:12px;\n"
"\n"
" }\n"
" QRadioButton::indicator::unchecked {\n"
"		background-color:white;\n"
"     }\n"
"\n"
"     QRadioButton::indicator:unchecked:hover {\n"
"		background-color:white;\n"
"     }\n"
"\n"
"     QRadioButton::indicator:unchecked:pressed {\n"
"		background-color:white;\n"
"     }\n"
"\n"
"     QRadioButton::indicator::checked {\n"
"		background-color:#f2a400;\n"
"     }\n"
"\n"
"     QRadioButton::indicator:checked:hover {\n"
"		background-color:#f2a400;\n"
"     }\n"
"\n"
"     QRadioButton::indicator:checked:pressed {\n"
"		background-color:#f2a400;\n"
"     }"));
        optFFs = new QRadioButton(grpMEMfill);
        optFFs->setObjectName(QString::fromUtf8("optFFs"));
        optFFs->setGeometry(QRect(4, 74, 51, 41));
        optFFs->setStyleSheet(QString::fromUtf8("QRadioButton{\n"
"font: 14px;\n"
"color:white\n"
"}\n"
" QRadioButton::indicator {\n"
"     width: 20px;\n"
"     height:20px;\n"
"   border: 2px solid black;\n"
"	 border-radius:12px;\n"
"\n"
" }\n"
" QRadioButton::indicator::unchecked {\n"
"		background-color:white;\n"
"     }\n"
"\n"
"     QRadioButton::indicator:unchecked:hover {\n"
"		background-color:white;\n"
"     }\n"
"\n"
"     QRadioButton::indicator:unchecked:pressed {\n"
"		background-color:white;\n"
"     }\n"
"\n"
"     QRadioButton::indicator::checked {\n"
"		background-color:#f2a400;\n"
"     }\n"
"\n"
"     QRadioButton::indicator:checked:hover {\n"
"		background-color:#f2a400;\n"
"     }\n"
"\n"
"     QRadioButton::indicator:checked:pressed {\n"
"		background-color:#f2a400;\n"
"     }"));
        grpSELECTCARD = new QGroupBox(Widget);
        grpSELECTCARD->setObjectName(QString::fromUtf8("grpSELECTCARD"));
        grpSELECTCARD->setGeometry(QRect(160, 380, 121, 140));
        grpSELECTCARD->setStyleSheet(QString::fromUtf8("QGroupBox::title {\n"
"		color:white;\n"
"     subcontrol-origin: margin;\n"
"     subcontrol-position: top center; /* position at the top center */\n"
"     padding: 0 3px;\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #FFOECE, stop: 1 #FFFFFF);\n"
" }\n"
"QLabel{\n"
"	color:white;\n"
"}"));
        butLoadFile = new QPushButton(grpSELECTCARD);
        butLoadFile->setObjectName(QString::fromUtf8("butLoadFile"));
        butLoadFile->setGeometry(QRect(20, 20, 84, 51));
        butLoadFile->setFocusPolicy(Qt::NoFocus);
        butLoadFile->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color:white;\n"
"border: 1px solid #2D5059;\n"
"border-radius: 20px;\n"
"background-color: qlineargradient(x1: 0, y1: 1, x2: 1, y2: 0,stop: 0 #1A74DB, stop: 0.6 #5293DE, stop:1 #FFFFFF);\n"
"font:bold;\n"
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
        butSaveFile = new QPushButton(grpSELECTCARD);
        butSaveFile->setObjectName(QString::fromUtf8("butSaveFile"));
        butSaveFile->setGeometry(QRect(20, 77, 84, 51));
        butSaveFile->setFocusPolicy(Qt::NoFocus);
        butSaveFile->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color:white;\n"
"border: 1px solid #2D5059;\n"
"border-radius: 20px;\n"
"background-color: qlineargradient(x1: 0, y1: 1, x2: 1, y2: 0,stop: 0 #1A74DB, stop: 0.6 #5293DE, stop:1 #FFFFFF);\n"
"font:bold;\n"
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
        grpMEMErase = new QGroupBox(Widget);
        grpMEMErase->setObjectName(QString::fromUtf8("grpMEMErase"));
        grpMEMErase->setGeometry(QRect(290, 380, 271, 91));
        grpMEMErase->setStyleSheet(QString::fromUtf8("QGroupBox::title {\n"
"		color:white;\n"
"     subcontrol-origin: margin;\n"
"     subcontrol-position: top center; /* position at the top center */\n"
"     padding: 0 3px;\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #FFOECE, stop: 1 #FFFFFF);\n"
" }\n"
"QLabel{\n"
"	color:white;\n"
"}"));
        butPageErase = new QPushButton(grpMEMErase);
        butPageErase->setObjectName(QString::fromUtf8("butPageErase"));
        butPageErase->setGeometry(QRect(140, 20, 121, 31));
        butPageErase->setFocusPolicy(Qt::NoFocus);
        butPageErase->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color:white;\n"
"border: 1px solid #2D5059;\n"
"border-radius: 20px;\n"
"background-color: qlineargradient(x1: 0, y1: 1, x2: 1, y2: 0,stop: 0 #1A74DB, stop: 0.6 #5293DE, stop:1 #FFFFFF);\n"
"font:bold;\n"
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
        label = new QLabel(grpMEMErase);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 10, 101, 20));
        butErase = new QPushButton(grpMEMErase);
        butErase->setObjectName(QString::fromUtf8("butErase"));
        butErase->setGeometry(QRect(140, 53, 121, 31));
        butErase->setFocusPolicy(Qt::NoFocus);
        butErase->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color:white;\n"
"border: 1px solid #2D5059;\n"
"border-radius: 20px;\n"
"background-color: qlineargradient(x1: 0, y1: 1, x2: 1, y2: 0,stop: 0 #1A74DB, stop: 0.6 #5293DE, stop:1 #FFFFFF);\n"
"font:bold;\n"
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
        grpSYSTEMMEMORY = new QGroupBox(Widget);
        grpSYSTEMMEMORY->setObjectName(QString::fromUtf8("grpSYSTEMMEMORY"));
        grpSYSTEMMEMORY->setEnabled(true);
        grpSYSTEMMEMORY->setGeometry(QRect(570, 380, 221, 141));
        grpSYSTEMMEMORY->setStyleSheet(QString::fromUtf8("QGroupBox::title {\n"
"		color:white;\n"
"     subcontrol-origin: margin;\n"
"     subcontrol-position: top center; /* position at the top center */\n"
"     padding: 0 3px;\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #FFOECE, stop: 1 #FFFFFF);\n"
" }\n"
"QLabel{\n"
"	color:white;\n"
"}"));
        optSlot1 = new QRadioButton(grpSYSTEMMEMORY);
        optSlot1->setObjectName(QString::fromUtf8("optSlot1"));
        optSlot1->setGeometry(QRect(120, 30, 91, 31));
        optSlot1->setFont(font);
        optSlot1->setStyleSheet(QString::fromUtf8("QRadioButton{\n"
"font: 14px;\n"
"color:white;\n"
"}\n"
" QRadioButton::indicator {\n"
"     width: 25px;\n"
"     height:25px;\n"
"   border: 2px solid black;\n"
"	 border-radius:12px;\n"
"\n"
" }\n"
" QRadioButton::indicator::unchecked {\n"
"		background-color:white;\n"
"     }\n"
"\n"
"     QRadioButton::indicator:unchecked:hover {\n"
"		background-color:white;\n"
"     }\n"
"\n"
"     QRadioButton::indicator:unchecked:pressed {\n"
"		background-color:white;\n"
"     }\n"
"\n"
"     QRadioButton::indicator::checked {\n"
"		background-color:#f2a400;\n"
"     }\n"
"\n"
"     QRadioButton::indicator:checked:hover {\n"
"		background-color:#f2a400;\n"
"     }\n"
"\n"
"     QRadioButton::indicator:checked:pressed {\n"
"		background-color:#f2a400;\n"
"     }"));
        optSlot2 = new QRadioButton(grpSYSTEMMEMORY);
        optSlot2->setObjectName(QString::fromUtf8("optSlot2"));
        optSlot2->setGeometry(QRect(12, 70, 91, 31));
        optSlot2->setFont(font);
        optSlot2->setStyleSheet(QString::fromUtf8("QRadioButton{\n"
"font: 14px;\n"
"color:white;\n"
"}\n"
" QRadioButton::indicator {\n"
"     width: 25px;\n"
"     height:25px;\n"
"   border: 2px solid black;\n"
"	 border-radius:12px;\n"
"\n"
" }\n"
" QRadioButton::indicator::unchecked {\n"
"		background-color:white;\n"
"     }\n"
"\n"
"     QRadioButton::indicator:unchecked:hover {\n"
"		background-color:white;\n"
"     }\n"
"\n"
"     QRadioButton::indicator:unchecked:pressed {\n"
"		background-color:white;\n"
"     }\n"
"\n"
"     QRadioButton::indicator::checked {\n"
"		background-color:#f2a400;\n"
"     }\n"
"\n"
"     QRadioButton::indicator:checked:hover {\n"
"		background-color:#f2a400;\n"
"     }\n"
"\n"
"     QRadioButton::indicator:checked:pressed {\n"
"		background-color:#f2a400;\n"
"     }"));
        optSlot3 = new QRadioButton(grpSYSTEMMEMORY);
        optSlot3->setObjectName(QString::fromUtf8("optSlot3"));
        optSlot3->setGeometry(QRect(120, 70, 91, 31));
        optSlot3->setFont(font);
        optSlot3->setStyleSheet(QString::fromUtf8("QRadioButton{\n"
"font: 14px;\n"
"color:white;\n"
"}\n"
" QRadioButton::indicator {\n"
"     width: 25px;\n"
"     height:25px;\n"
"   border: 2px solid black;\n"
"	 border-radius:12px;\n"
"\n"
" }\n"
" QRadioButton::indicator::unchecked {\n"
"		background-color:white;\n"
"     }\n"
"\n"
"     QRadioButton::indicator:unchecked:hover {\n"
"		background-color:white;\n"
"     }\n"
"\n"
"     QRadioButton::indicator:unchecked:pressed {\n"
"		background-color:white;\n"
"     }\n"
"\n"
"     QRadioButton::indicator::checked {\n"
"		background-color:#f2a400;\n"
"     }\n"
"\n"
"     QRadioButton::indicator:checked:hover {\n"
"		background-color:#f2a400;\n"
"     }\n"
"\n"
"     QRadioButton::indicator:checked:pressed {\n"
"		background-color:#f2a400;\n"
"     }"));
        optSlot0 = new QRadioButton(grpSYSTEMMEMORY);
        optSlot0->setObjectName(QString::fromUtf8("optSlot0"));
        optSlot0->setGeometry(QRect(10, 30, 91, 31));
        optSlot0->setFont(font);
        optSlot0->setStyleSheet(QString::fromUtf8("QRadioButton{\n"
"font: 14px;\n"
"color:white;\n"
"}\n"
" QRadioButton::indicator {\n"
"     width: 25px;\n"
"     height:25px;\n"
"   border: 2px solid black;\n"
"	 border-radius:12px;\n"
"\n"
" }\n"
" QRadioButton::indicator::unchecked {\n"
"		background-color:white;\n"
"     }\n"
"\n"
"     QRadioButton::indicator:unchecked:hover {\n"
"		background-color:white;\n"
"     }\n"
"\n"
"     QRadioButton::indicator:unchecked:pressed {\n"
"		background-color:white;\n"
"     }\n"
"\n"
"     QRadioButton::indicator::checked {\n"
"		background-color:#f2a400;\n"
"     }\n"
"\n"
"     QRadioButton::indicator:checked:hover {\n"
"		background-color:#f2a400;\n"
"     }\n"
"\n"
"     QRadioButton::indicator:checked:pressed {\n"
"		background-color:#f2a400;\n"
"     }"));
        grpCODEID = new QGroupBox(Widget);
        grpCODEID->setObjectName(QString::fromUtf8("grpCODEID"));
        grpCODEID->setGeometry(QRect(290, 470, 271, 51));
        grpCODEID->setStyleSheet(QString::fromUtf8("QGroupBox::title {\n"
"		color:white;\n"
"     subcontrol-origin: margin;\n"
"     subcontrol-position: top center; /* position at the top center */\n"
"     padding: 0 3px;\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #FFOECE, stop: 1 #FFFFFF);\n"
" }\n"
"QLabel{\n"
"	color:white;\n"
"}"));
        butCODEID = new QPushButton(grpCODEID);
        butCODEID->setObjectName(QString::fromUtf8("butCODEID"));
        butCODEID->setGeometry(QRect(144, 15, 121, 31));
        butCODEID->setFocusPolicy(Qt::NoFocus);
        butCODEID->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color:white;\n"
"border: 1px solid #2D5059;\n"
"border-radius: 20px;\n"
"background-color: qlineargradient(x1: 0, y1: 1, x2: 1, y2: 0,stop: 0 #1A74DB, stop: 0.6 #5293DE, stop:1 #FFFFFF);\n"
"font:bold;\n"
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
        lecodeID = new QLineEdit(grpCODEID);
        lecodeID->setObjectName(QString::fromUtf8("lecodeID"));
        lecodeID->setGeometry(QRect(11, 16, 101, 31));
        lecodeID->setStyleSheet(QString::fromUtf8(" QLineEdit {\n"
"     border: 2px solid gray;\n"
"     border-radius: 30px;\n"
"     padding: 0 8px;\n"
"     background: gray;\n"
"     selection-background-color: darkgray;\n"
"	 color:black;\n"
"     font: bold 14px;\n"
" }"));
        grpSYSTEM = new QGroupBox(Widget);
        grpSYSTEM->setObjectName(QString::fromUtf8("grpSYSTEM"));
        grpSYSTEM->setGeometry(QRect(10, 380, 141, 141));
        grpSYSTEM->setStyleSheet(QString::fromUtf8("QGroupBox::title {\n"
"		color:white;\n"
"     subcontrol-origin: margin;\n"
"     subcontrol-position: top center; /* position at the top center */\n"
"     padding: 0 3px;\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #FFOECE, stop: 1 #FFFFFF);\n"
" }\n"
"QLabel{\n"
"	color:white;\n"
"}"));
        cmbHWSelect = new QComboBox(grpSYSTEM);
        cmbHWSelect->setObjectName(QString::fromUtf8("cmbHWSelect"));
        cmbHWSelect->setGeometry(QRect(4, 20, 131, 41));
        cmbHWSelect->setFocusPolicy(Qt::NoFocus);
        cmbHWSelect->setStyleSheet(QString::fromUtf8(" QComboBox {\n"
"     border: 1px solid gray;\n"
"     border-radius: 3px;\n"
"     padding: 1px 18px 1px 3px;\n"
"     min-width: 6em;\n"
"     color:black;\n"
"     font:14px bold;\n"
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
" }"));
        label_2 = new QLabel(grpSYSTEM);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(19, 82, 101, 20));
        lblIndex = new QLabel(grpSYSTEM);
        lblIndex->setObjectName(QString::fromUtf8("lblIndex"));
        lblIndex->setGeometry(QRect(10, 100, 111, 31));
        lblIndex->setStyleSheet(QString::fromUtf8(" QLabel {\n"
"     border: 2px solid gray;\n"
"     border-radius: 23px;\n"
"     padding: 0 8px;\n"
"     background: gray;\n"
"     selection-background-color: darkgray;\n"
"	 color:white;\n"
"     font: bold 12px;\n"
" }"));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0, QApplication::UnicodeUTF8));
        grpFLASHRW->setTitle(QApplication::translate("Widget", "Read/Write Sequence", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Widget", "0", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Widget", "1", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("Widget", "2", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("Widget", "3", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("Widget", "4", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("Widget", "5", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("Widget", "6", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("Widget", "7", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QApplication::translate("Widget", "8", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->horizontalHeaderItem(9);
        ___qtablewidgetitem9->setText(QApplication::translate("Widget", "9", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->horizontalHeaderItem(10);
        ___qtablewidgetitem10->setText(QApplication::translate("Widget", "10", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->horizontalHeaderItem(11);
        ___qtablewidgetitem11->setText(QApplication::translate("Widget", "11", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget->horizontalHeaderItem(12);
        ___qtablewidgetitem12->setText(QApplication::translate("Widget", "12", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget->horizontalHeaderItem(13);
        ___qtablewidgetitem13->setText(QApplication::translate("Widget", "13", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget->horizontalHeaderItem(14);
        ___qtablewidgetitem14->setText(QApplication::translate("Widget", "14", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget->horizontalHeaderItem(15);
        ___qtablewidgetitem15->setText(QApplication::translate("Widget", "15", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem16->setText(QApplication::translate("Widget", "0", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem17->setText(QApplication::translate("Widget", "1", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget->verticalHeaderItem(2);
        ___qtablewidgetitem18->setText(QApplication::translate("Widget", "2", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidget->verticalHeaderItem(3);
        ___qtablewidgetitem19->setText(QApplication::translate("Widget", "3", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem20 = tableWidget->verticalHeaderItem(4);
        ___qtablewidgetitem20->setText(QApplication::translate("Widget", "4", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem21 = tableWidget->verticalHeaderItem(5);
        ___qtablewidgetitem21->setText(QApplication::translate("Widget", "5", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem22 = tableWidget->verticalHeaderItem(6);
        ___qtablewidgetitem22->setText(QApplication::translate("Widget", "6", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem23 = tableWidget->verticalHeaderItem(7);
        ___qtablewidgetitem23->setText(QApplication::translate("Widget", "7", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem24 = tableWidget->verticalHeaderItem(8);
        ___qtablewidgetitem24->setText(QApplication::translate("Widget", "8", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem25 = tableWidget->verticalHeaderItem(9);
        ___qtablewidgetitem25->setText(QApplication::translate("Widget", "9", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem26 = tableWidget->verticalHeaderItem(10);
        ___qtablewidgetitem26->setText(QApplication::translate("Widget", "10", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem27 = tableWidget->verticalHeaderItem(11);
        ___qtablewidgetitem27->setText(QApplication::translate("Widget", "11", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem28 = tableWidget->verticalHeaderItem(12);
        ___qtablewidgetitem28->setText(QApplication::translate("Widget", "12", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem29 = tableWidget->verticalHeaderItem(13);
        ___qtablewidgetitem29->setText(QApplication::translate("Widget", "13", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem30 = tableWidget->verticalHeaderItem(14);
        ___qtablewidgetitem30->setText(QApplication::translate("Widget", "14", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem31 = tableWidget->verticalHeaderItem(15);
        ___qtablewidgetitem31->setText(QApplication::translate("Widget", "15", 0, QApplication::UnicodeUTF8));
        grpMEMSeque->setTitle(QString());
        label_3->setText(QApplication::translate("Widget", "Start Address", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Widget", "End Address", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Widget", "Address Count", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("Widget", "Index", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("Widget", "Data", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("Widget", "Select Memory", 0, QApplication::UnicodeUTF8));
        optFlash->setText(QApplication::translate("Widget", "Flash", 0, QApplication::UnicodeUTF8));
        optRAM->setText(QApplication::translate("Widget", "DRAM", 0, QApplication::UnicodeUTF8));
        optDDR->setText(QApplication::translate("Widget", "DDR", 0, QApplication::UnicodeUTF8));
        optSystemMemory->setText(QApplication::translate("Widget", "SYSTEM MEMORY", 0, QApplication::UnicodeUTF8));
        optReceiveRAM->setText(QApplication::translate("Widget", "RRAM", 0, QApplication::UnicodeUTF8));
        grpdrvBulkMEM->setTitle(QApplication::translate("Widget", "MEMORY READ / WRITE", 0, QApplication::UnicodeUTF8));
        butRead->setText(QApplication::translate("Widget", "READ", 0, QApplication::UnicodeUTF8));
        butWrite->setText(QApplication::translate("Widget", "WRITE", 0, QApplication::UnicodeUTF8));
        chkSingle->setText(QApplication::translate("Widget", "Single", 0, QApplication::UnicodeUTF8));
        grpMEMfill->setTitle(QApplication::translate("Widget", "Fill", 0, QApplication::UnicodeUTF8));
        optZeros->setText(QApplication::translate("Widget", "0's", 0, QApplication::UnicodeUTF8));
        optFFs->setText(QApplication::translate("Widget", "F's", 0, QApplication::UnicodeUTF8));
        grpSELECTCARD->setTitle(QApplication::translate("Widget", "File", 0, QApplication::UnicodeUTF8));
        butLoadFile->setText(QApplication::translate("Widget", "LOAD", 0, QApplication::UnicodeUTF8));
        butSaveFile->setText(QApplication::translate("Widget", "SAVE", 0, QApplication::UnicodeUTF8));
        grpMEMErase->setTitle(QApplication::translate("Widget", "PAGE MEMORY ERASE", 0, QApplication::UnicodeUTF8));
        butPageErase->setText(QApplication::translate("Widget", "PAGE ERASE", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Widget", "Start Address", 0, QApplication::UnicodeUTF8));
        butErase->setText(QApplication::translate("Widget", "BULK ERASE", 0, QApplication::UnicodeUTF8));
        grpSYSTEMMEMORY->setTitle(QApplication::translate("Widget", "System Memory -APP CARD", 0, QApplication::UnicodeUTF8));
        optSlot1->setText(QApplication::translate("Widget", "SLOT 1", 0, QApplication::UnicodeUTF8));
        optSlot2->setText(QApplication::translate("Widget", "SLOT 2", 0, QApplication::UnicodeUTF8));
        optSlot3->setText(QApplication::translate("Widget", "SLOT 3", 0, QApplication::UnicodeUTF8));
        optSlot0->setText(QApplication::translate("Widget", "SLOT 0", 0, QApplication::UnicodeUTF8));
        grpCODEID->setTitle(QApplication::translate("Widget", "Flash Memory", 0, QApplication::UnicodeUTF8));
        butCODEID->setText(QApplication::translate("Widget", "CODE ID", 0, QApplication::UnicodeUTF8));
        grpSYSTEM->setTitle(QApplication::translate("Widget", "System Selection", 0, QApplication::UnicodeUTF8));
        cmbHWSelect->clear();
        cmbHWSelect->insertItems(0, QStringList()
         << QApplication::translate("Widget", "BACKPANEL", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "APP CARD", 0, QApplication::UnicodeUTF8)
        );
        label_2->setText(QApplication::translate("Widget", "Base Address", 0, QApplication::UnicodeUTF8));
        lblIndex->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FLASHMEMORY_H
