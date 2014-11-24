/********************************************************************************
** Form generated from reading UI file 'testspi.ui'
**
** Created: Sun Nov 23 18:06:27 2014
**      by: Qt User Interface Compiler version 4.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTSPI_H
#define UI_TESTSPI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QFrame>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSlider>
#include <QtGui/QTableWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_testSPIClass
{
public:
    QWidget *gridWidget;
    QComboBox *SelectSPI;
    QComboBox *SelectOperation;
    QComboBox *AppendBit;
    QLineEdit *Data;
    QLineEdit *Address;
    QLabel *AddressLbl;
    QLabel *DataLbl;
    QComboBox *SelectMask;
    QLineEdit *Mask;
    QComboBox *SelectMode;
    QPushButton *Execute;
    QPushButton *Exit;
    QComboBox *SelectPart;
    QLabel *AddressLbl_3;
    QLineEdit *SPIClock;
    QGroupBox *AppBox;
    QLabel *AppAddressLbl;
    QLineEdit *AppAddress;
    QLineEdit *AppData;
    QLabel *AppDataLbl;
    QPushButton *AppRead;
    QPushButton *AppWrite;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QComboBox *SelectApp;
    QLineEdit *DMMAddrEdit;
    QLabel *DMMAddrLbl;
    QPushButton *Reset;
    QPushButton *ReadAll;
    QTableWidget *tableWidget;
    QComboBox *DCVolt;
    QSlider *horizontalSlider;
    QLineEdit *ADCRead;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *Reg1;
    QLabel *label_5;
    QLabel *Reg0;
    QLabel *Reg2;
    QLabel *label_8;
    QLabel *Bit24;
    QLabel *label_10;
    QComboBox *testFileLoad;
    QPushButton *testFile;
    QLabel *minus;
    QLabel *Bit24_2;
    QComboBox *SelectADC;
    QLabel *label_4;
    QLineEdit *lineEditAvg;
    QLineEdit *lineEditOutput;
    QLabel *unit;
    QLabel *dSymbol;
    QLabel *Reg4;
    QLabel *Reg3;
    QLabel *label_6;
    QLabel *label_7;
    QFrame *line;
    QFrame *line_2;
    QLabel *pkhmin;
    QLabel *label_9;
    QLabel *label_11;
    QLabel *pkhmax;
    QPushButton *pushButton;

    void setupUi(QWidget *testSPIClass)
    {
        if (testSPIClass->objectName().isEmpty())
            testSPIClass->setObjectName(QString::fromUtf8("testSPIClass"));
        testSPIClass->resize(800, 580);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/pt6.png"), QSize(), QIcon::Normal, QIcon::Off);
        testSPIClass->setWindowIcon(icon);
        gridWidget = new QWidget(testSPIClass);
        gridWidget->setObjectName(QString::fromUtf8("gridWidget"));
        gridWidget->setGeometry(QRect(10, 100, 541, 330));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        gridWidget->setFont(font);
        SelectSPI = new QComboBox(gridWidget);
        SelectSPI->setObjectName(QString::fromUtf8("SelectSPI"));
        SelectSPI->setGeometry(QRect(20, 147, 120, 27));
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SelectSPI->sizePolicy().hasHeightForWidth());
        SelectSPI->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setFamily(QString::fromUtf8("DejaVu Sans"));
        font1.setPointSize(11);
        font1.setBold(false);
        font1.setWeight(50);
        SelectSPI->setFont(font1);
        SelectOperation = new QComboBox(gridWidget);
        SelectOperation->setObjectName(QString::fromUtf8("SelectOperation"));
        SelectOperation->setGeometry(QRect(150, 147, 131, 27));
        sizePolicy.setHeightForWidth(SelectOperation->sizePolicy().hasHeightForWidth());
        SelectOperation->setSizePolicy(sizePolicy);
        SelectOperation->setFont(font1);
        AppendBit = new QComboBox(gridWidget);
        AppendBit->setObjectName(QString::fromUtf8("AppendBit"));
        AppendBit->setGeometry(QRect(290, 147, 103, 27));
        sizePolicy.setHeightForWidth(AppendBit->sizePolicy().hasHeightForWidth());
        AppendBit->setSizePolicy(sizePolicy);
        AppendBit->setFont(font1);
        Data = new QLineEdit(gridWidget);
        Data->setObjectName(QString::fromUtf8("Data"));
        Data->setGeometry(QRect(136, 257, 131, 29));
        sizePolicy.setHeightForWidth(Data->sizePolicy().hasHeightForWidth());
        Data->setSizePolicy(sizePolicy);
        QFont font2;
        font2.setFamily(QString::fromUtf8("DejaVu Sans"));
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setWeight(75);
        Data->setFont(font2);
        Address = new QLineEdit(gridWidget);
        Address->setObjectName(QString::fromUtf8("Address"));
        Address->setGeometry(QRect(133, 217, 131, 29));
        sizePolicy.setHeightForWidth(Address->sizePolicy().hasHeightForWidth());
        Address->setSizePolicy(sizePolicy);
        Address->setFont(font2);
        AddressLbl = new QLabel(gridWidget);
        AddressLbl->setObjectName(QString::fromUtf8("AddressLbl"));
        AddressLbl->setGeometry(QRect(20, 223, 83, 17));
        QSizePolicy sizePolicy1(QSizePolicy::Ignored, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(AddressLbl->sizePolicy().hasHeightForWidth());
        AddressLbl->setSizePolicy(sizePolicy1);
        AddressLbl->setFont(font1);
        DataLbl = new QLabel(gridWidget);
        DataLbl->setObjectName(QString::fromUtf8("DataLbl"));
        DataLbl->setGeometry(QRect(20, 267, 78, 17));
        sizePolicy1.setHeightForWidth(DataLbl->sizePolicy().hasHeightForWidth());
        DataLbl->setSizePolicy(sizePolicy1);
        DataLbl->setFont(font1);
        SelectMask = new QComboBox(gridWidget);
        SelectMask->setObjectName(QString::fromUtf8("SelectMask"));
        SelectMask->setGeometry(QRect(270, 224, 111, 27));
        SelectMask->setFont(font1);
        Mask = new QLineEdit(gridWidget);
        Mask->setObjectName(QString::fromUtf8("Mask"));
        Mask->setGeometry(QRect(406, 217, 130, 29));
        sizePolicy.setHeightForWidth(Mask->sizePolicy().hasHeightForWidth());
        Mask->setSizePolicy(sizePolicy);
        Mask->setFont(font2);
        SelectMode = new QComboBox(gridWidget);
        SelectMode->setObjectName(QString::fromUtf8("SelectMode"));
        SelectMode->setGeometry(QRect(406, 147, 112, 27));
        sizePolicy.setHeightForWidth(SelectMode->sizePolicy().hasHeightForWidth());
        SelectMode->setSizePolicy(sizePolicy);
        SelectMode->setFont(font1);
        Execute = new QPushButton(gridWidget);
        Execute->setObjectName(QString::fromUtf8("Execute"));
        Execute->setGeometry(QRect(360, 296, 85, 27));
        sizePolicy.setHeightForWidth(Execute->sizePolicy().hasHeightForWidth());
        Execute->setSizePolicy(sizePolicy);
        Execute->setFont(font1);
        Execute->setStyleSheet(QString::fromUtf8("border:1px solid gray;\n"
"border-radius:3px;"));
        Exit = new QPushButton(gridWidget);
        Exit->setObjectName(QString::fromUtf8("Exit"));
        Exit->setGeometry(QRect(450, 296, 85, 27));
        sizePolicy.setHeightForWidth(Exit->sizePolicy().hasHeightForWidth());
        Exit->setSizePolicy(sizePolicy);
        Exit->setFont(font1);
        Exit->setStyleSheet(QString::fromUtf8("border:1px solid gray;\n"
"border-radius:3px;"));
        SelectPart = new QComboBox(gridWidget);
        SelectPart->setObjectName(QString::fromUtf8("SelectPart"));
        SelectPart->setGeometry(QRect(20, 180, 120, 27));
        sizePolicy.setHeightForWidth(SelectPart->sizePolicy().hasHeightForWidth());
        SelectPart->setSizePolicy(sizePolicy);
        SelectPart->setFont(font2);
        AddressLbl_3 = new QLabel(gridWidget);
        AddressLbl_3->setObjectName(QString::fromUtf8("AddressLbl_3"));
        AddressLbl_3->setGeometry(QRect(320, 186, 83, 17));
        sizePolicy1.setHeightForWidth(AddressLbl_3->sizePolicy().hasHeightForWidth());
        AddressLbl_3->setSizePolicy(sizePolicy1);
        AddressLbl_3->setFont(font1);
        SPIClock = new QLineEdit(gridWidget);
        SPIClock->setObjectName(QString::fromUtf8("SPIClock"));
        SPIClock->setGeometry(QRect(410, 180, 110, 29));
        sizePolicy.setHeightForWidth(SPIClock->sizePolicy().hasHeightForWidth());
        SPIClock->setSizePolicy(sizePolicy);
        SPIClock->setFont(font2);
        AppBox = new QGroupBox(gridWidget);
        AppBox->setObjectName(QString::fromUtf8("AppBox"));
        AppBox->setGeometry(QRect(10, 0, 520, 120));
        QFont font3;
        font3.setFamily(QString::fromUtf8("12"));
        font3.setBold(false);
        font3.setItalic(false);
        font3.setWeight(50);
        AppBox->setFont(font3);
        AppBox->setStyleSheet(QString::fromUtf8("QGroupBox { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #E0E0E0, stop: 1 #FFFFFF); border: 1px solid gray; border-radius: 2px; margin-top: 1ex; /* leave space at the top for the title */ font:14px bold; color:black; } QGroupBox::title { subcontrol-origin: margin; subcontrol-position: top center; /* position at the top center */ padding: 0 1px; background-color:white; border:1px solid black; border-radius:10px; }"));
        AppAddressLbl = new QLabel(AppBox);
        AppAddressLbl->setObjectName(QString::fromUtf8("AppAddressLbl"));
        AppAddressLbl->setGeometry(QRect(20, 40, 80, 17));
        AppAddressLbl->setFont(font1);
        AppAddress = new QLineEdit(AppBox);
        AppAddress->setObjectName(QString::fromUtf8("AppAddress"));
        AppAddress->setGeometry(QRect(100, 30, 131, 29));
        sizePolicy.setHeightForWidth(AppAddress->sizePolicy().hasHeightForWidth());
        AppAddress->setSizePolicy(sizePolicy);
        AppAddress->setFont(font);
        AppData = new QLineEdit(AppBox);
        AppData->setObjectName(QString::fromUtf8("AppData"));
        AppData->setGeometry(QRect(350, 30, 131, 29));
        sizePolicy.setHeightForWidth(AppData->sizePolicy().hasHeightForWidth());
        AppData->setSizePolicy(sizePolicy);
        AppData->setFont(font);
        AppDataLbl = new QLabel(AppBox);
        AppDataLbl->setObjectName(QString::fromUtf8("AppDataLbl"));
        AppDataLbl->setGeometry(QRect(300, 40, 50, 17));
        AppDataLbl->setFont(font1);
        AppRead = new QPushButton(AppBox);
        AppRead->setObjectName(QString::fromUtf8("AppRead"));
        AppRead->setGeometry(QRect(290, 80, 91, 27));
        AppRead->setFont(font1);
        AppRead->setStyleSheet(QString::fromUtf8("border:1px solid gray;\n"
"border-radius:3px;"));
        AppWrite = new QPushButton(AppBox);
        AppWrite->setObjectName(QString::fromUtf8("AppWrite"));
        AppWrite->setGeometry(QRect(400, 80, 91, 27));
        AppWrite->setFont(font1);
        AppWrite->setStyleSheet(QString::fromUtf8("border:1px solid gray;\n"
"border-radius:3px;"));
        radioButton = new QRadioButton(AppBox);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(20, 90, 81, 21));
        radioButton_2 = new QRadioButton(AppBox);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setGeometry(QRect(110, 90, 81, 21));
        radioButton_2->setChecked(true);
        SelectApp = new QComboBox(gridWidget);
        SelectApp->setObjectName(QString::fromUtf8("SelectApp"));
        SelectApp->setGeometry(QRect(151, 180, 130, 27));
        sizePolicy.setHeightForWidth(SelectApp->sizePolicy().hasHeightForWidth());
        SelectApp->setSizePolicy(sizePolicy);
        SelectApp->setFont(font1);
        DMMAddrEdit = new QLineEdit(gridWidget);
        DMMAddrEdit->setObjectName(QString::fromUtf8("DMMAddrEdit"));
        DMMAddrEdit->setGeometry(QRect(400, 260, 131, 29));
        sizePolicy.setHeightForWidth(DMMAddrEdit->sizePolicy().hasHeightForWidth());
        DMMAddrEdit->setSizePolicy(sizePolicy);
        DMMAddrEdit->setFont(font2);
        DMMAddrLbl = new QLabel(gridWidget);
        DMMAddrLbl->setObjectName(QString::fromUtf8("DMMAddrLbl"));
        DMMAddrLbl->setGeometry(QRect(284, 270, 78, 17));
        sizePolicy1.setHeightForWidth(DMMAddrLbl->sizePolicy().hasHeightForWidth());
        DMMAddrLbl->setSizePolicy(sizePolicy1);
        DMMAddrLbl->setFont(font1);
        Reset = new QPushButton(gridWidget);
        Reset->setObjectName(QString::fromUtf8("Reset"));
        Reset->setGeometry(QRect(180, 296, 85, 27));
        sizePolicy.setHeightForWidth(Reset->sizePolicy().hasHeightForWidth());
        Reset->setSizePolicy(sizePolicy);
        Reset->setFont(font1);
        Reset->setStyleSheet(QString::fromUtf8("border:1px solid gray;\n"
"border-radius:3px;"));
        ReadAll = new QPushButton(gridWidget);
        ReadAll->setObjectName(QString::fromUtf8("ReadAll"));
        ReadAll->setGeometry(QRect(270, 296, 85, 27));
        sizePolicy.setHeightForWidth(ReadAll->sizePolicy().hasHeightForWidth());
        ReadAll->setSizePolicy(sizePolicy);
        ReadAll->setFont(font1);
        ReadAll->setStyleSheet(QString::fromUtf8("border:1px solid gray;\n"
"border-radius:3px;"));
        tableWidget = new QTableWidget(testSPIClass);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        QFont font4;
        font4.setFamily(QString::fromUtf8("DejaVu Sans"));
        font4.setPointSize(14);
        font4.setBold(true);
        font4.setWeight(75);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem->setFont(font4);
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem1->setFont(font4);
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        if (tableWidget->rowCount() < 56)
            tableWidget->setRowCount(56);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setTextAlignment(Qt::AlignLeft|Qt::AlignVCenter);
        tableWidget->setItem(0, 0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setTextAlignment(Qt::AlignLeft|Qt::AlignVCenter);
        tableWidget->setItem(1, 0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setItem(2, 0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setItem(3, 0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setItem(4, 0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setItem(5, 0, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setItem(6, 0, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setItem(7, 0, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setItem(8, 0, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget->setItem(9, 0, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget->setItem(10, 0, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget->setItem(11, 0, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget->setItem(12, 0, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget->setItem(13, 0, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget->setItem(14, 0, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidget->setItem(15, 0, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableWidget->setItem(16, 0, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableWidget->setItem(17, 0, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tableWidget->setItem(18, 0, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        tableWidget->setItem(19, 0, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tableWidget->setItem(20, 0, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        tableWidget->setItem(21, 0, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        tableWidget->setItem(22, 0, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        tableWidget->setItem(23, 0, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        tableWidget->setItem(24, 0, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        tableWidget->setItem(25, 0, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        tableWidget->setItem(26, 0, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        tableWidget->setItem(27, 0, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        tableWidget->setItem(28, 0, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        tableWidget->setItem(29, 0, __qtablewidgetitem31);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        tableWidget->setItem(30, 0, __qtablewidgetitem32);
        QTableWidgetItem *__qtablewidgetitem33 = new QTableWidgetItem();
        tableWidget->setItem(31, 0, __qtablewidgetitem33);
        QTableWidgetItem *__qtablewidgetitem34 = new QTableWidgetItem();
        tableWidget->setItem(32, 0, __qtablewidgetitem34);
        QTableWidgetItem *__qtablewidgetitem35 = new QTableWidgetItem();
        tableWidget->setItem(33, 0, __qtablewidgetitem35);
        QTableWidgetItem *__qtablewidgetitem36 = new QTableWidgetItem();
        tableWidget->setItem(34, 0, __qtablewidgetitem36);
        QTableWidgetItem *__qtablewidgetitem37 = new QTableWidgetItem();
        tableWidget->setItem(35, 0, __qtablewidgetitem37);
        QTableWidgetItem *__qtablewidgetitem38 = new QTableWidgetItem();
        tableWidget->setItem(36, 0, __qtablewidgetitem38);
        QTableWidgetItem *__qtablewidgetitem39 = new QTableWidgetItem();
        tableWidget->setItem(37, 0, __qtablewidgetitem39);
        QTableWidgetItem *__qtablewidgetitem40 = new QTableWidgetItem();
        tableWidget->setItem(38, 0, __qtablewidgetitem40);
        QTableWidgetItem *__qtablewidgetitem41 = new QTableWidgetItem();
        tableWidget->setItem(39, 0, __qtablewidgetitem41);
        QTableWidgetItem *__qtablewidgetitem42 = new QTableWidgetItem();
        tableWidget->setItem(40, 0, __qtablewidgetitem42);
        QTableWidgetItem *__qtablewidgetitem43 = new QTableWidgetItem();
        tableWidget->setItem(41, 0, __qtablewidgetitem43);
        QTableWidgetItem *__qtablewidgetitem44 = new QTableWidgetItem();
        tableWidget->setItem(42, 0, __qtablewidgetitem44);
        QTableWidgetItem *__qtablewidgetitem45 = new QTableWidgetItem();
        tableWidget->setItem(43, 0, __qtablewidgetitem45);
        QTableWidgetItem *__qtablewidgetitem46 = new QTableWidgetItem();
        tableWidget->setItem(44, 0, __qtablewidgetitem46);
        QTableWidgetItem *__qtablewidgetitem47 = new QTableWidgetItem();
        tableWidget->setItem(45, 0, __qtablewidgetitem47);
        QTableWidgetItem *__qtablewidgetitem48 = new QTableWidgetItem();
        tableWidget->setItem(46, 0, __qtablewidgetitem48);
        QTableWidgetItem *__qtablewidgetitem49 = new QTableWidgetItem();
        tableWidget->setItem(47, 0, __qtablewidgetitem49);
        QTableWidgetItem *__qtablewidgetitem50 = new QTableWidgetItem();
        tableWidget->setItem(48, 0, __qtablewidgetitem50);
        QTableWidgetItem *__qtablewidgetitem51 = new QTableWidgetItem();
        tableWidget->setItem(49, 0, __qtablewidgetitem51);
        QTableWidgetItem *__qtablewidgetitem52 = new QTableWidgetItem();
        tableWidget->setItem(50, 0, __qtablewidgetitem52);
        QTableWidgetItem *__qtablewidgetitem53 = new QTableWidgetItem();
        tableWidget->setItem(51, 0, __qtablewidgetitem53);
        QTableWidgetItem *__qtablewidgetitem54 = new QTableWidgetItem();
        tableWidget->setItem(52, 0, __qtablewidgetitem54);
        QTableWidgetItem *__qtablewidgetitem55 = new QTableWidgetItem();
        tableWidget->setItem(53, 0, __qtablewidgetitem55);
        QTableWidgetItem *__qtablewidgetitem56 = new QTableWidgetItem();
        tableWidget->setItem(54, 0, __qtablewidgetitem56);
        QTableWidgetItem *__qtablewidgetitem57 = new QTableWidgetItem();
        tableWidget->setItem(55, 0, __qtablewidgetitem57);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(565, 10, 221, 550));
        QPalette palette;
        QBrush brush(QColor(0, 0, 127, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        QBrush brush1(QColor(126, 125, 125, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        tableWidget->setPalette(palette);
        QFont font5;
        font5.setFamily(QString::fromUtf8("Droid Sans"));
        font5.setPointSize(14);
        font5.setBold(true);
        font5.setItalic(false);
        font5.setWeight(75);
        tableWidget->setFont(font5);
        tableWidget->setFocusPolicy(Qt::NoFocus);
        tableWidget->setLayoutDirection(Qt::LeftToRight);
        tableWidget->setFrameShape(QFrame::WinPanel);
        tableWidget->setFrameShadow(QFrame::Sunken);
        tableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget->setAutoScroll(true);
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectItems);
        tableWidget->setTextElideMode(Qt::ElideLeft);
        tableWidget->setGridStyle(Qt::DashDotLine);
        tableWidget->setRowCount(56);
        tableWidget->setColumnCount(2);
        tableWidget->horizontalHeader()->setVisible(false);
        tableWidget->horizontalHeader()->setMinimumSectionSize(27);
        tableWidget->verticalHeader()->setVisible(false);
        tableWidget->verticalHeader()->setMinimumSectionSize(21);
        DCVolt = new QComboBox(testSPIClass);
        DCVolt->setObjectName(QString::fromUtf8("DCVolt"));
        DCVolt->setGeometry(QRect(85, 395, 100, 29));
        DCVolt->setFont(font1);
        horizontalSlider = new QSlider(testSPIClass);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(448, 536, 60, 40));
        horizontalSlider->setFont(font);
        horizontalSlider->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal { \n"
"border: 1px solid #bbb; background: white; height: 10px; border-radius: 4px; \n"
"} \n"
"QSlider::sub-page:horizontal { \n"
"background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #66e, stop: 1 #bbf); background: qlineargradient(x1: 0, y1: 0.2, x2: 1, y2: 1, stop: 0 #bbf, stop: 1 #55f); border: 1px solid #777; height: 10px; border-radius: 4px; \n"
"}\n"
"QSlider::add-page:horizontal {\n"
"background: #fff; border: 1px solid #777; height: 10px; border-radius: 4px; \n"
"}\n"
"QSlider::handle:horizontal {\n"
"background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #eee, stop:1 #ccc); border: 1px solid #777;width: 25px; margin-top: -5px; margin-bottom: -5px; border-radius: 10px; \n"
"}\n"
"QSlider::handle:horizontal:hover {\n"
"background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #fff, stop:1 #ddd); border: 1px solid #444; border-radius: 10px; \n"
"}\n"
"QSlider::sub-page:horizontal:disabled {\n"
"background: #bbb; border-color: #999; \n"
"}\n"
"QSlider::add-page"
                        ":horizontal:disabled {\n"
"background: #eee; border-color: #999; \n"
"}\n"
"QSlider::handle:horizontal:disabled {\n"
"background: #eee; border: 1px solid #aaa; border-radius: 4px;\n"
"}"));
        horizontalSlider->setMaximum(1);
        horizontalSlider->setPageStep(1);
        horizontalSlider->setOrientation(Qt::Horizontal);
        ADCRead = new QLineEdit(testSPIClass);
        ADCRead->setObjectName(QString::fromUtf8("ADCRead"));
        ADCRead->setGeometry(QRect(30, 430, 210, 29));
        sizePolicy.setHeightForWidth(ADCRead->sizePolicy().hasHeightForWidth());
        ADCRead->setSizePolicy(sizePolicy);
        QFont font6;
        font6.setFamily(QString::fromUtf8("DejaVu Sans"));
        font6.setPointSize(10);
        font6.setBold(false);
        font6.setWeight(50);
        ADCRead->setFont(font6);
        label = new QLabel(testSPIClass);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(408, 549, 41, 17));
        label->setFont(font1);
        label_2 = new QLabel(testSPIClass);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(510, 546, 50, 17));
        label_2->setFont(font1);
        label_3 = new QLabel(testSPIClass);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 494, 61, 17));
        label_3->setFont(font1);
        Reg1 = new QLabel(testSPIClass);
        Reg1->setObjectName(QString::fromUtf8("Reg1"));
        Reg1->setGeometry(QRect(70, 494, 80, 17));
        QFont font7;
        font7.setFamily(QString::fromUtf8("DejaVu Sans"));
        font7.setPointSize(12);
        font7.setBold(false);
        font7.setWeight(50);
        Reg1->setFont(font7);
        Reg1->setStyleSheet(QString::fromUtf8("QLabel{border:1px solid gray;}"));
        label_5 = new QLabel(testSPIClass);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 464, 61, 17));
        label_5->setFont(font1);
        Reg0 = new QLabel(testSPIClass);
        Reg0->setObjectName(QString::fromUtf8("Reg0"));
        Reg0->setGeometry(QRect(70, 464, 80, 17));
        Reg0->setFont(font7);
        Reg0->setStyleSheet(QString::fromUtf8("QLabel{border:1px solid gray;}"));
        Reg2 = new QLabel(testSPIClass);
        Reg2->setObjectName(QString::fromUtf8("Reg2"));
        Reg2->setGeometry(QRect(70, 524, 80, 17));
        Reg2->setFont(font7);
        Reg2->setStyleSheet(QString::fromUtf8("QLabel{border:1px solid gray;}"));
        label_8 = new QLabel(testSPIClass);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(20, 524, 61, 17));
        label_8->setFont(font1);
        Bit24 = new QLabel(testSPIClass);
        Bit24->setObjectName(QString::fromUtf8("Bit24"));
        Bit24->setGeometry(QRect(90, 550, 130, 17));
        Bit24->setFont(font7);
        Bit24->setStyleSheet(QString::fromUtf8("QLabel{border:1px solid gray;}"));
        label_10 = new QLabel(testSPIClass);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(20, 550, 61, 17));
        label_10->setFont(font);
        testFileLoad = new QComboBox(testSPIClass);
        testFileLoad->setObjectName(QString::fromUtf8("testFileLoad"));
        testFileLoad->setGeometry(QRect(370, 510, 101, 27));
        testFileLoad->setFont(font1);
        testFile = new QPushButton(testSPIClass);
        testFile->setObjectName(QString::fromUtf8("testFile"));
        testFile->setGeometry(QRect(473, 510, 80, 27));
        testFile->setFont(font1);
        minus = new QLabel(testSPIClass);
        minus->setObjectName(QString::fromUtf8("minus"));
        minus->setGeometry(QRect(14, 436, 21, 17));
        minus->setFont(font2);
        Bit24_2 = new QLabel(testSPIClass);
        Bit24_2->setObjectName(QString::fromUtf8("Bit24_2"));
        Bit24_2->setGeometry(QRect(240, 550, 160, 17));
        Bit24_2->setFont(font7);
        Bit24_2->setStyleSheet(QString::fromUtf8("QLabel{border:1px solid gray;}"));
        SelectADC = new QComboBox(testSPIClass);
        SelectADC->setObjectName(QString::fromUtf8("SelectADC"));
        SelectADC->setGeometry(QRect(14, 397, 70, 27));
        SelectADC->setFont(font1);
        label_4 = new QLabel(testSPIClass);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(410, 440, 60, 17));
        label_4->setFont(font1);
        lineEditAvg = new QLineEdit(testSPIClass);
        lineEditAvg->setObjectName(QString::fromUtf8("lineEditAvg"));
        lineEditAvg->setGeometry(QRect(480, 432, 70, 29));
        lineEditOutput = new QLineEdit(testSPIClass);
        lineEditOutput->setObjectName(QString::fromUtf8("lineEditOutput"));
        lineEditOutput->setGeometry(QRect(241, 430, 163, 29));
        QFont font8;
        font8.setFamily(QString::fromUtf8("DejaVu Sans"));
        lineEditOutput->setFont(font8);
        unit = new QLabel(testSPIClass);
        unit->setObjectName(QString::fromUtf8("unit"));
        unit->setGeometry(QRect(460, 10, 90, 80));
        QFont font9;
        font9.setFamily(QString::fromUtf8("DejaVu Sans"));
        font9.setPointSize(48);
        unit->setFont(font9);
        unit->setStyleSheet(QString::fromUtf8(""));
        dSymbol = new QLabel(testSPIClass);
        dSymbol->setObjectName(QString::fromUtf8("dSymbol"));
        dSymbol->setGeometry(QRect(10, 10, 90, 80));
        dSymbol->setFont(font9);
        dSymbol->setStyleSheet(QString::fromUtf8(""));
        Reg4 = new QLabel(testSPIClass);
        Reg4->setObjectName(QString::fromUtf8("Reg4"));
        Reg4->setGeometry(QRect(210, 494, 80, 17));
        Reg4->setFont(font7);
        Reg4->setStyleSheet(QString::fromUtf8("QLabel{border:1px solid gray;}"));
        Reg3 = new QLabel(testSPIClass);
        Reg3->setObjectName(QString::fromUtf8("Reg3"));
        Reg3->setGeometry(QRect(210, 464, 80, 17));
        Reg3->setFont(font7);
        Reg3->setStyleSheet(QString::fromUtf8("QLabel{border:1px solid gray;}"));
        label_6 = new QLabel(testSPIClass);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(160, 464, 61, 17));
        label_6->setFont(font1);
        label_7 = new QLabel(testSPIClass);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(160, 494, 61, 17));
        label_7->setFont(font1);
        line = new QFrame(testSPIClass);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(0, 391, 565, 3));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(testSPIClass);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(1, 233, 565, 3));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        pkhmin = new QLabel(testSPIClass);
        pkhmin->setObjectName(QString::fromUtf8("pkhmin"));
        pkhmin->setGeometry(QRect(370, 490, 110, 17));
        pkhmin->setFont(font7);
        pkhmin->setStyleSheet(QString::fromUtf8("QLabel{border:1px solid gray;}"));
        label_9 = new QLabel(testSPIClass);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(300, 465, 61, 17));
        label_9->setFont(font1);
        label_11 = new QLabel(testSPIClass);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(300, 490, 61, 17));
        label_11->setFont(font1);
        pkhmax = new QLabel(testSPIClass);
        pkhmax->setObjectName(QString::fromUtf8("pkhmax"));
        pkhmax->setGeometry(QRect(370, 465, 110, 17));
        pkhmax->setFont(font7);
        pkhmax->setStyleSheet(QString::fromUtf8("QLabel{border:1px solid gray;}"));
        pushButton = new QPushButton(testSPIClass);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(485, 464, 71, 40));
        pushButton->setFont(font8);

        retranslateUi(testSPIClass);

        QMetaObject::connectSlotsByName(testSPIClass);
    } // setupUi

    void retranslateUi(QWidget *testSPIClass)
    {
        testSPIClass->setWindowTitle(QApplication::translate("testSPIClass", "testSPI", 0, QApplication::UnicodeUTF8));
        SelectSPI->clear();
        SelectSPI->insertItems(0, QStringList()
         << QApplication::translate("testSPIClass", "Select SPI", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("testSPIClass", "SPI1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("testSPIClass", "SPI2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("testSPIClass", "SPI3", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("testSPIClass", "SPI4", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("testSPIClass", "SPI5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("testSPIClass", "SPI6", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("testSPIClass", "DMMSPI", 0, QApplication::UnicodeUTF8)
        );
        SelectOperation->clear();
        SelectOperation->insertItems(0, QStringList()
         << QApplication::translate("testSPIClass", "Select Operation", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("testSPIClass", "WRITE", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("testSPIClass", "READ", 0, QApplication::UnicodeUTF8)
        );
        AppendBit->clear();
        AppendBit->insertItems(0, QStringList()
         << QApplication::translate("testSPIClass", "Append Bit", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("testSPIClass", "0x8000", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("testSPIClass", "0xC000", 0, QApplication::UnicodeUTF8)
        );
        AddressLbl->setText(QApplication::translate("testSPIClass", "MSW(16-Bit)", 0, QApplication::UnicodeUTF8));
        DataLbl->setText(QApplication::translate("testSPIClass", "LSW(16-Bit)", 0, QApplication::UnicodeUTF8));
        SelectMask->clear();
        SelectMask->insertItems(0, QStringList()
         << QApplication::translate("testSPIClass", "Select Mask", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("testSPIClass", "&", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("testSPIClass", "|", 0, QApplication::UnicodeUTF8)
        );
        SelectMode->clear();
        SelectMode->insertItems(0, QStringList()
         << QApplication::translate("testSPIClass", "Select Mode", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("testSPIClass", "8-Bit", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("testSPIClass", "16-Bit", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("testSPIClass", "24-Bit", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("testSPIClass", "32-Bit", 0, QApplication::UnicodeUTF8)
        );
        Execute->setText(QApplication::translate("testSPIClass", "EXECUTE", 0, QApplication::UnicodeUTF8));
        Exit->setText(QApplication::translate("testSPIClass", "Exit", 0, QApplication::UnicodeUTF8));
        AddressLbl_3->setText(QApplication::translate("testSPIClass", "SPI Clock :", 0, QApplication::UnicodeUTF8));
        AppBox->setTitle(QApplication::translate("testSPIClass", "Application Card", 0, QApplication::UnicodeUTF8));
        AppAddressLbl->setText(QApplication::translate("testSPIClass", "Address:", 0, QApplication::UnicodeUTF8));
        AppDataLbl->setText(QApplication::translate("testSPIClass", "Data:", 0, QApplication::UnicodeUTF8));
        AppRead->setText(QApplication::translate("testSPIClass", "Read", 0, QApplication::UnicodeUTF8));
        AppWrite->setText(QApplication::translate("testSPIClass", "Write", 0, QApplication::UnicodeUTF8));
        radioButton->setText(QApplication::translate("testSPIClass", "BackPanel", 0, QApplication::UnicodeUTF8));
        radioButton_2->setText(QApplication::translate("testSPIClass", "AppCard", 0, QApplication::UnicodeUTF8));
        SelectApp->clear();
        SelectApp->insertItems(0, QStringList()
         << QApplication::translate("testSPIClass", "Select App", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("testSPIClass", "HY3131", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("testSPIClass", "Custom", 0, QApplication::UnicodeUTF8)
        );
        DMMAddrLbl->setText(QApplication::translate("testSPIClass", "Address", 0, QApplication::UnicodeUTF8));
        Reset->setText(QApplication::translate("testSPIClass", "RESET", 0, QApplication::UnicodeUTF8));
        ReadAll->setText(QApplication::translate("testSPIClass", "READ ALL", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("testSPIClass", "Address", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("testSPIClass", "Data", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled = tableWidget->isSortingEnabled();
        tableWidget->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->item(0, 0);
        ___qtablewidgetitem2->setText(QApplication::translate("testSPIClass", "0x37", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->item(1, 0);
        ___qtablewidgetitem3->setText(QApplication::translate("testSPIClass", "0x36", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->item(2, 0);
        ___qtablewidgetitem4->setText(QApplication::translate("testSPIClass", "0x35", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->item(3, 0);
        ___qtablewidgetitem5->setText(QApplication::translate("testSPIClass", "0x34", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->item(4, 0);
        ___qtablewidgetitem6->setText(QApplication::translate("testSPIClass", "0x33", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->item(5, 0);
        ___qtablewidgetitem7->setText(QApplication::translate("testSPIClass", "0x32", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->item(6, 0);
        ___qtablewidgetitem8->setText(QApplication::translate("testSPIClass", "0x31", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->item(7, 0);
        ___qtablewidgetitem9->setText(QApplication::translate("testSPIClass", "0x30", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->item(8, 0);
        ___qtablewidgetitem10->setText(QApplication::translate("testSPIClass", "0x2F", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->item(9, 0);
        ___qtablewidgetitem11->setText(QApplication::translate("testSPIClass", "0x2E", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget->item(10, 0);
        ___qtablewidgetitem12->setText(QApplication::translate("testSPIClass", "0x2D", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget->item(11, 0);
        ___qtablewidgetitem13->setText(QApplication::translate("testSPIClass", "0x2C", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget->item(12, 0);
        ___qtablewidgetitem14->setText(QApplication::translate("testSPIClass", "0x2B", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget->item(13, 0);
        ___qtablewidgetitem15->setText(QApplication::translate("testSPIClass", "0x2A", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget->item(14, 0);
        ___qtablewidgetitem16->setText(QApplication::translate("testSPIClass", "0x29", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget->item(15, 0);
        ___qtablewidgetitem17->setText(QApplication::translate("testSPIClass", "0x28", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget->item(16, 0);
        ___qtablewidgetitem18->setText(QApplication::translate("testSPIClass", "0x27", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidget->item(17, 0);
        ___qtablewidgetitem19->setText(QApplication::translate("testSPIClass", "0x26", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem20 = tableWidget->item(18, 0);
        ___qtablewidgetitem20->setText(QApplication::translate("testSPIClass", "0x25", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem21 = tableWidget->item(19, 0);
        ___qtablewidgetitem21->setText(QApplication::translate("testSPIClass", "0x24", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem22 = tableWidget->item(20, 0);
        ___qtablewidgetitem22->setText(QApplication::translate("testSPIClass", "0x23", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem23 = tableWidget->item(21, 0);
        ___qtablewidgetitem23->setText(QApplication::translate("testSPIClass", "0x22", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem24 = tableWidget->item(22, 0);
        ___qtablewidgetitem24->setText(QApplication::translate("testSPIClass", "0x21", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem25 = tableWidget->item(23, 0);
        ___qtablewidgetitem25->setText(QApplication::translate("testSPIClass", "0x20", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem26 = tableWidget->item(24, 0);
        ___qtablewidgetitem26->setText(QApplication::translate("testSPIClass", "0x1F", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem27 = tableWidget->item(25, 0);
        ___qtablewidgetitem27->setText(QApplication::translate("testSPIClass", "0x1E", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem28 = tableWidget->item(26, 0);
        ___qtablewidgetitem28->setText(QApplication::translate("testSPIClass", "0x1D", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem29 = tableWidget->item(27, 0);
        ___qtablewidgetitem29->setText(QApplication::translate("testSPIClass", "0x1C", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem30 = tableWidget->item(28, 0);
        ___qtablewidgetitem30->setText(QApplication::translate("testSPIClass", "0x1B", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem31 = tableWidget->item(29, 0);
        ___qtablewidgetitem31->setText(QApplication::translate("testSPIClass", "0x1A", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem32 = tableWidget->item(30, 0);
        ___qtablewidgetitem32->setText(QApplication::translate("testSPIClass", "0x19", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem33 = tableWidget->item(31, 0);
        ___qtablewidgetitem33->setText(QApplication::translate("testSPIClass", "0x18", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem34 = tableWidget->item(32, 0);
        ___qtablewidgetitem34->setText(QApplication::translate("testSPIClass", "0x17", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem35 = tableWidget->item(33, 0);
        ___qtablewidgetitem35->setText(QApplication::translate("testSPIClass", "0x16", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem36 = tableWidget->item(34, 0);
        ___qtablewidgetitem36->setText(QApplication::translate("testSPIClass", "0x15", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem37 = tableWidget->item(35, 0);
        ___qtablewidgetitem37->setText(QApplication::translate("testSPIClass", "0x14", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem38 = tableWidget->item(36, 0);
        ___qtablewidgetitem38->setText(QApplication::translate("testSPIClass", "0x13", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem39 = tableWidget->item(37, 0);
        ___qtablewidgetitem39->setText(QApplication::translate("testSPIClass", "0x12", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem40 = tableWidget->item(38, 0);
        ___qtablewidgetitem40->setText(QApplication::translate("testSPIClass", "0x11", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem41 = tableWidget->item(39, 0);
        ___qtablewidgetitem41->setText(QApplication::translate("testSPIClass", "0x10", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem42 = tableWidget->item(40, 0);
        ___qtablewidgetitem42->setText(QApplication::translate("testSPIClass", "0x0F", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem43 = tableWidget->item(41, 0);
        ___qtablewidgetitem43->setText(QApplication::translate("testSPIClass", "0x0E", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem44 = tableWidget->item(42, 0);
        ___qtablewidgetitem44->setText(QApplication::translate("testSPIClass", "0x0D", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem45 = tableWidget->item(43, 0);
        ___qtablewidgetitem45->setText(QApplication::translate("testSPIClass", "0x0C", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem46 = tableWidget->item(44, 0);
        ___qtablewidgetitem46->setText(QApplication::translate("testSPIClass", "0x0B", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem47 = tableWidget->item(45, 0);
        ___qtablewidgetitem47->setText(QApplication::translate("testSPIClass", "0x0A", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem48 = tableWidget->item(46, 0);
        ___qtablewidgetitem48->setText(QApplication::translate("testSPIClass", "0x09", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem49 = tableWidget->item(47, 0);
        ___qtablewidgetitem49->setText(QApplication::translate("testSPIClass", "0x08", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem50 = tableWidget->item(48, 0);
        ___qtablewidgetitem50->setText(QApplication::translate("testSPIClass", "0x07", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem51 = tableWidget->item(49, 0);
        ___qtablewidgetitem51->setText(QApplication::translate("testSPIClass", "0x06", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem52 = tableWidget->item(50, 0);
        ___qtablewidgetitem52->setText(QApplication::translate("testSPIClass", "0x05", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem53 = tableWidget->item(51, 0);
        ___qtablewidgetitem53->setText(QApplication::translate("testSPIClass", "0x04", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem54 = tableWidget->item(52, 0);
        ___qtablewidgetitem54->setText(QApplication::translate("testSPIClass", "0x03", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem55 = tableWidget->item(53, 0);
        ___qtablewidgetitem55->setText(QApplication::translate("testSPIClass", "0x02", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem56 = tableWidget->item(54, 0);
        ___qtablewidgetitem56->setText(QApplication::translate("testSPIClass", "0x01", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem57 = tableWidget->item(55, 0);
        ___qtablewidgetitem57->setText(QApplication::translate("testSPIClass", "0x00", 0, QApplication::UnicodeUTF8));
        tableWidget->setSortingEnabled(__sortingEnabled);

        DCVolt->clear();
        DCVolt->insertItems(0, QStringList()
         << QApplication::translate("testSPIClass", "Switching", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("testSPIClass", "AC/DC-mV", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("testSPIClass", "AC/DC-V", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("testSPIClass", "AC/DC-Amps", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("testSPIClass", "AC/DC-mA", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("testSPIClass", "AC/DC-uA", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("testSPIClass", "Resistance", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("testSPIClass", "Frequency", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("testSPIClass", "Capacitance", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("testSPIClass", "Diode", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("testSPIClass", "Beep", 0, QApplication::UnicodeUTF8)
        );
        label->setText(QApplication::translate("testSPIClass", "STOP", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("testSPIClass", "START", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("testSPIClass", "REG-1", 0, QApplication::UnicodeUTF8));
        Reg1->setText(QString());
        label_5->setText(QApplication::translate("testSPIClass", "REG-0", 0, QApplication::UnicodeUTF8));
        Reg0->setText(QString());
        Reg2->setText(QString());
        label_8->setText(QApplication::translate("testSPIClass", "REG-2", 0, QApplication::UnicodeUTF8));
        Bit24->setText(QString());
        label_10->setText(QApplication::translate("testSPIClass", "24-Bit", 0, QApplication::UnicodeUTF8));
        testFileLoad->clear();
        testFileLoad->insertItems(0, QStringList()
         << QApplication::translate("testSPIClass", "File...", 0, QApplication::UnicodeUTF8)
        );
        testFile->setText(QApplication::translate("testSPIClass", "LOAD", 0, QApplication::UnicodeUTF8));
        minus->setText(QApplication::translate("testSPIClass", "-", 0, QApplication::UnicodeUTF8));
        Bit24_2->setText(QString());
        SelectADC->clear();
        SelectADC->insertItems(0, QStringList()
         << QApplication::translate("testSPIClass", "ADC1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("testSPIClass", "ADC2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("testSPIClass", "LPF", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("testSPIClass", "RMS", 0, QApplication::UnicodeUTF8)
        );
        label_4->setText(QApplication::translate("testSPIClass", "Samples", 0, QApplication::UnicodeUTF8));
        unit->setText(QString());
        dSymbol->setText(QString());
        Reg4->setText(QString());
        Reg3->setText(QString());
        label_6->setText(QApplication::translate("testSPIClass", "REG-3", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("testSPIClass", "REG-4", 0, QApplication::UnicodeUTF8));
        pkhmin->setText(QString());
        label_9->setText(QApplication::translate("testSPIClass", "PKHMAX", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("testSPIClass", "PKHMIN", 0, QApplication::UnicodeUTF8));
        pkhmax->setText(QString());
        pushButton->setText(QApplication::translate("testSPIClass", "Calibration \n"
"Panel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class testSPIClass: public Ui_testSPIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTSPI_H
