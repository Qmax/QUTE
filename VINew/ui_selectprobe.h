/********************************************************************************
** Form generated from reading UI file 'selectprobe.ui'
**
** Created: Thu Oct 16 13:31:22 2014
**      by: Qt User Interface Compiler version 4.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTPROBE_H
#define UI_SELECTPROBE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SelectProbe
{
public:
    QGroupBox *groupBox;
    QListWidget *lstProbes;
    QGroupBox *grpComparison;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QRadioButton *optAverage;
    QRadioButton *optLinear;
    QGroupBox *grpACF;
    QRadioButton *optResistance;
    QRadioButton *optCapcitance;
    QRadioButton *optInductance;
    QRadioButton *optDiode;
    QRadioButton *optAll;
    QPushButton *butAdvSetup;
    QPushButton *butOK;
    QCheckBox *chkCommonGnd;
    QLabel *label;
    QGroupBox *grpReferenceProbes;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout_2;
    QRadioButton *optRefProbe1;
    QRadioButton *opRefProbe2;

    void setupUi(QDialog *SelectProbe)
    {
        if (SelectProbe->objectName().isEmpty())
            SelectProbe->setObjectName(QString::fromUtf8("SelectProbe"));
        SelectProbe->setWindowModality(Qt::ApplicationModal);
        SelectProbe->resize(432, 207);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QLinearGradient gradient(0, 0, 1, 1);
        gradient.setSpread(QGradient::PadSpread);
        gradient.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient.setColorAt(0, QColor(99, 102, 85, 255));
        gradient.setColorAt(0.4, QColor(128, 128, 128, 255));
        gradient.setColorAt(0.8, QColor(99, 102, 85, 255));
        gradient.setColorAt(1, QColor(128, 128, 128, 255));
        QBrush brush1(gradient);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(132, 132, 131, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(110, 110, 109, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(44, 44, 43, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(58, 58, 58, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QLinearGradient gradient1(0, 0, 1, 1);
        gradient1.setSpread(QGradient::PadSpread);
        gradient1.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient1.setColorAt(0, QColor(99, 102, 85, 255));
        gradient1.setColorAt(0.4, QColor(128, 128, 128, 255));
        gradient1.setColorAt(0.8, QColor(99, 102, 85, 255));
        gradient1.setColorAt(1, QColor(128, 128, 128, 255));
        QBrush brush6(gradient1);
        palette.setBrush(QPalette::Active, QPalette::Base, brush6);
        QLinearGradient gradient2(0, 0, 1, 1);
        gradient2.setSpread(QGradient::PadSpread);
        gradient2.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient2.setColorAt(0, QColor(99, 102, 85, 255));
        gradient2.setColorAt(0.4, QColor(128, 128, 128, 255));
        gradient2.setColorAt(0.8, QColor(99, 102, 85, 255));
        gradient2.setColorAt(1, QColor(128, 128, 128, 255));
        QBrush brush7(gradient2);
        palette.setBrush(QPalette::Active, QPalette::Window, brush7);
        QBrush brush8(QColor(0, 0, 0, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush8);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush4);
        QBrush brush9(QColor(255, 255, 220, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush9);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush8);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QLinearGradient gradient3(0, 0, 1, 1);
        gradient3.setSpread(QGradient::PadSpread);
        gradient3.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient3.setColorAt(0, QColor(99, 102, 85, 255));
        gradient3.setColorAt(0.4, QColor(128, 128, 128, 255));
        gradient3.setColorAt(0.8, QColor(99, 102, 85, 255));
        gradient3.setColorAt(1, QColor(128, 128, 128, 255));
        QBrush brush10(gradient3);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush10);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        QLinearGradient gradient4(0, 0, 1, 1);
        gradient4.setSpread(QGradient::PadSpread);
        gradient4.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient4.setColorAt(0, QColor(99, 102, 85, 255));
        gradient4.setColorAt(0.4, QColor(128, 128, 128, 255));
        gradient4.setColorAt(0.8, QColor(99, 102, 85, 255));
        gradient4.setColorAt(1, QColor(128, 128, 128, 255));
        QBrush brush11(gradient4);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush11);
        QLinearGradient gradient5(0, 0, 1, 1);
        gradient5.setSpread(QGradient::PadSpread);
        gradient5.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient5.setColorAt(0, QColor(99, 102, 85, 255));
        gradient5.setColorAt(0.4, QColor(128, 128, 128, 255));
        gradient5.setColorAt(0.8, QColor(99, 102, 85, 255));
        gradient5.setColorAt(1, QColor(128, 128, 128, 255));
        QBrush brush12(gradient5);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush12);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush8);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush9);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush8);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        QLinearGradient gradient6(0, 0, 1, 1);
        gradient6.setSpread(QGradient::PadSpread);
        gradient6.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient6.setColorAt(0, QColor(99, 102, 85, 255));
        gradient6.setColorAt(0.4, QColor(128, 128, 128, 255));
        gradient6.setColorAt(0.8, QColor(99, 102, 85, 255));
        gradient6.setColorAt(1, QColor(128, 128, 128, 255));
        QBrush brush13(gradient6);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush13);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        QLinearGradient gradient7(0, 0, 1, 1);
        gradient7.setSpread(QGradient::PadSpread);
        gradient7.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient7.setColorAt(0, QColor(99, 102, 85, 255));
        gradient7.setColorAt(0.4, QColor(128, 128, 128, 255));
        gradient7.setColorAt(0.8, QColor(99, 102, 85, 255));
        gradient7.setColorAt(1, QColor(128, 128, 128, 255));
        QBrush brush14(gradient7);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush14);
        QLinearGradient gradient8(0, 0, 1, 1);
        gradient8.setSpread(QGradient::PadSpread);
        gradient8.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient8.setColorAt(0, QColor(99, 102, 85, 255));
        gradient8.setColorAt(0.4, QColor(128, 128, 128, 255));
        gradient8.setColorAt(0.8, QColor(99, 102, 85, 255));
        gradient8.setColorAt(1, QColor(128, 128, 128, 255));
        QBrush brush15(gradient8);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush15);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush8);
        QBrush brush16(QColor(88, 88, 87, 255));
        brush16.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush16);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush9);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush8);
        SelectProbe->setPalette(palette);
        QFont font;
        font.setFamily(QString::fromUtf8("DejaVu Sans"));
        SelectProbe->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image.png"), QSize(), QIcon::Normal, QIcon::Off);
        SelectProbe->setWindowIcon(icon);
        SelectProbe->setStyleSheet(QString::fromUtf8("QDialog{\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 1,\n"
"                                       stop: 0 #636655, stop: 0.4 gray, stop: 0.8 #636655, stop: 1 gray);\n"
"}"));
        SelectProbe->setModal(false);
        groupBox = new QGroupBox(SelectProbe);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 151, 151));
        QFont font1;
        font1.setFamily(QString::fromUtf8("DejaVu Sans"));
        font1.setBold(false);
        font1.setWeight(50);
        groupBox->setFont(font1);
        groupBox->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
"color:white;\n"
"\n"
"border:1px solid white;\n"
"}\n"
" QGroupBox::title {\n"
"	border:1px solid white;\n"
"	border-radius:5px;\n"
"     subcontrol-origin: margin;\n"
"     subcontrol-position: top center; /* position at the top center */\n"
"     padding: 0 3px;\n"
"	 color:white;\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #3a5976, stop: 1 #000000);\n"
" }"));
        lstProbes = new QListWidget(groupBox);
        new QListWidgetItem(lstProbes);
        new QListWidgetItem(lstProbes);
        lstProbes->setObjectName(QString::fromUtf8("lstProbes"));
        lstProbes->setGeometry(QRect(11, 24, 131, 111));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QLinearGradient gradient9(0, 0, 0, 1);
        gradient9.setSpread(QGradient::PadSpread);
        gradient9.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient9.setColorAt(0, QColor(58, 89, 118, 255));
        gradient9.setColorAt(1, QColor(0, 0, 0, 255));
        QBrush brush17(gradient9);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush17);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QLinearGradient gradient10(0, 0, 0, 1);
        gradient10.setSpread(QGradient::PadSpread);
        gradient10.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient10.setColorAt(0, QColor(58, 89, 118, 255));
        gradient10.setColorAt(1, QColor(0, 0, 0, 255));
        QBrush brush18(gradient10);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush18);
        QLinearGradient gradient11(0, 0, 0, 1);
        gradient11.setSpread(QGradient::PadSpread);
        gradient11.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient11.setColorAt(0, QColor(58, 89, 118, 255));
        gradient11.setColorAt(1, QColor(0, 0, 0, 255));
        QBrush brush19(gradient11);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush19);
        QBrush brush20(QColor(40, 112, 128, 255));
        brush20.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Highlight, brush20);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QLinearGradient gradient12(0, 0, 0, 1);
        gradient12.setSpread(QGradient::PadSpread);
        gradient12.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient12.setColorAt(0, QColor(58, 89, 118, 255));
        gradient12.setColorAt(1, QColor(0, 0, 0, 255));
        QBrush brush21(gradient12);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush21);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        QLinearGradient gradient13(0, 0, 0, 1);
        gradient13.setSpread(QGradient::PadSpread);
        gradient13.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient13.setColorAt(0, QColor(58, 89, 118, 255));
        gradient13.setColorAt(1, QColor(0, 0, 0, 255));
        QBrush brush22(gradient13);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush22);
        QLinearGradient gradient14(0, 0, 0, 1);
        gradient14.setSpread(QGradient::PadSpread);
        gradient14.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient14.setColorAt(0, QColor(58, 89, 118, 255));
        gradient14.setColorAt(1, QColor(0, 0, 0, 255));
        QBrush brush23(gradient14);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush23);
        palette1.setBrush(QPalette::Inactive, QPalette::Highlight, brush20);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        QLinearGradient gradient15(0, 0, 0, 1);
        gradient15.setSpread(QGradient::PadSpread);
        gradient15.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient15.setColorAt(0, QColor(58, 89, 118, 255));
        gradient15.setColorAt(1, QColor(0, 0, 0, 255));
        QBrush brush24(gradient15);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush24);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        QLinearGradient gradient16(0, 0, 0, 1);
        gradient16.setSpread(QGradient::PadSpread);
        gradient16.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient16.setColorAt(0, QColor(58, 89, 118, 255));
        gradient16.setColorAt(1, QColor(0, 0, 0, 255));
        QBrush brush25(gradient16);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush25);
        QLinearGradient gradient17(0, 0, 0, 1);
        gradient17.setSpread(QGradient::PadSpread);
        gradient17.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient17.setColorAt(0, QColor(58, 89, 118, 255));
        gradient17.setColorAt(1, QColor(0, 0, 0, 255));
        QBrush brush26(gradient17);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush26);
        QBrush brush27(QColor(0, 0, 128, 255));
        brush27.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Disabled, QPalette::Highlight, brush27);
        lstProbes->setPalette(palette1);
        QFont font2;
        font2.setFamily(QString::fromUtf8("DejaVu Sans"));
        font2.setPointSize(20);
        font2.setBold(false);
        font2.setWeight(50);
        lstProbes->setFont(font2);
        lstProbes->setMouseTracking(false);
        lstProbes->setFocusPolicy(Qt::NoFocus);
        lstProbes->setStyleSheet(QString::fromUtf8(" QListView {\n"
"     show-decoration-selected: 1; /* make the selection span the entire width of the\n"
"view */\n"
"border:1px solid #F1F5DA;\n"
"color:white;\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #3a5976, stop: 1 #000000);\n"
" }\n"
"\n"
" QListView::item:alternate {\n"
"     background: #EEEEEE;\n"
" }\n"
"\n"
" QListView::item:selected {\n"
"     border: 1px solid #6a6ea9;\n"
" }\n"
"\n"
" QListView::item:selected:!active {\n"
"     background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                 stop: 0 #ABAFE5, stop: 1 #8588B2);\n"
" }\n"
"\n"
" QListView::item:selected:active {\n"
"     background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                 stop: 0 #6a6ea9, stop: 1 #888dd9);\n"
" }\n"
"\n"
"/* QListView::item:hover {\n"
"     background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                 stop: 0 #FAFBFE, stop: 1 #DCDEF1);\n"
" }*/"));
        lstProbes->setFrameShape(QFrame::StyledPanel);
        lstProbes->setFrameShadow(QFrame::Plain);
        lstProbes->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        lstProbes->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        lstProbes->setGridSize(QSize(30, 30));
        grpComparison = new QGroupBox(SelectProbe);
        grpComparison->setObjectName(QString::fromUtf8("grpComparison"));
        grpComparison->setGeometry(QRect(166, 10, 261, 81));
        QFont font3;
        font3.setFamily(QString::fromUtf8("DejaVu Sans"));
        font3.setPointSize(12);
        font3.setBold(false);
        font3.setWeight(50);
        grpComparison->setFont(font3);
        grpComparison->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
"color:white;\n"
"\n"
"border:1px solid white;\n"
"}\n"
" QGroupBox::title {\n"
"	border:1px solid white;\n"
"	border-radius:5px;\n"
"     subcontrol-origin: margin;\n"
"     subcontrol-position: top center; /* position at the top center */\n"
"     padding: 0 3px;\n"
"	 color:white;\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #3a5976, stop: 1 #000000);\n"
" }"));
        layoutWidget = new QWidget(grpComparison);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 14, 247, 56));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        optAverage = new QRadioButton(layoutWidget);
        optAverage->setObjectName(QString::fromUtf8("optAverage"));
        QFont font4;
        font4.setBold(true);
        font4.setItalic(false);
        font4.setWeight(75);
        optAverage->setFont(font4);
        optAverage->setFocusPolicy(Qt::NoFocus);
        optAverage->setStyleSheet(QString::fromUtf8("QRadioButton{\n"
"font:bold 18px;\n"
"color:white;\n"
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

        gridLayout->addWidget(optAverage, 0, 1, 1, 1);

        optLinear = new QRadioButton(layoutWidget);
        optLinear->setObjectName(QString::fromUtf8("optLinear"));
        optLinear->setFont(font4);
        optLinear->setFocusPolicy(Qt::NoFocus);
        optLinear->setStyleSheet(QString::fromUtf8("QRadioButton{\n"
"font:bold 18px;\n"
"color:white;\n"
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

        gridLayout->addWidget(optLinear, 0, 0, 1, 1);

        grpACF = new QGroupBox(SelectProbe);
        grpACF->setObjectName(QString::fromUtf8("grpACF"));
        grpACF->setGeometry(QRect(10, 210, 371, 91));
        grpACF->setFont(font1);
        optResistance = new QRadioButton(grpACF);
        optResistance->setObjectName(QString::fromUtf8("optResistance"));
        optResistance->setGeometry(QRect(16, 20, 61, 61));
        optResistance->setFont(font4);
        optResistance->setFocusPolicy(Qt::NoFocus);
        optResistance->setStyleSheet(QString::fromUtf8("QRadioButton{\n"
"font:bold 18px;\n"
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
        optCapcitance = new QRadioButton(grpACF);
        optCapcitance->setObjectName(QString::fromUtf8("optCapcitance"));
        optCapcitance->setGeometry(QRect(77, 20, 61, 61));
        optCapcitance->setFont(font4);
        optCapcitance->setFocusPolicy(Qt::NoFocus);
        optCapcitance->setStyleSheet(QString::fromUtf8("QRadioButton{\n"
"font:bold 18px;\n"
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
        optInductance = new QRadioButton(grpACF);
        optInductance->setObjectName(QString::fromUtf8("optInductance"));
        optInductance->setGeometry(QRect(147, 20, 61, 61));
        optInductance->setFont(font4);
        optInductance->setFocusPolicy(Qt::NoFocus);
        optInductance->setStyleSheet(QString::fromUtf8("QRadioButton{\n"
"font:bold 18px;\n"
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
        optDiode = new QRadioButton(grpACF);
        optDiode->setObjectName(QString::fromUtf8("optDiode"));
        optDiode->setGeometry(QRect(220, 20, 81, 61));
        optDiode->setFont(font4);
        optDiode->setFocusPolicy(Qt::NoFocus);
        optDiode->setStyleSheet(QString::fromUtf8("QRadioButton{\n"
"font:bold 18px;\n"
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
        optAll = new QRadioButton(grpACF);
        optAll->setObjectName(QString::fromUtf8("optAll"));
        optAll->setGeometry(QRect(307, 20, 61, 61));
        optAll->setFont(font4);
        optAll->setFocusPolicy(Qt::NoFocus);
        optAll->setStyleSheet(QString::fromUtf8("QRadioButton{\n"
"font:bold 18px;\n"
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
        butAdvSetup = new QPushButton(grpACF);
        butAdvSetup->setObjectName(QString::fromUtf8("butAdvSetup"));
        butAdvSetup->setGeometry(QRect(290, 20, 93, 51));
        QFont font5;
        font5.setFamily(QString::fromUtf8("DejaVu Sans"));
        font5.setPointSize(14);
        font5.setBold(false);
        font5.setWeight(50);
        butAdvSetup->setFont(font5);
        butAdvSetup->setFocusPolicy(Qt::NoFocus);
        butAdvSetup->setStyleSheet(QString::fromUtf8(" QPushButton {\n"
"     border: 2px solid #8f8f91;\n"
"     border-radius: 20px;\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #f6f7fa, stop: 1 #dadbde);\n"
"     min-width: 80px;\n"
" }\n"
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
        butOK = new QPushButton(SelectProbe);
        butOK->setObjectName(QString::fromUtf8("butOK"));
        butOK->setGeometry(QRect(180, 148, 93, 51));
        butOK->setFont(font5);
        butOK->setFocusPolicy(Qt::NoFocus);
        butOK->setStyleSheet(QString::fromUtf8(" QPushButton {\n"
"     border: 2px solid #8f8f91;\n"
"     border-radius: 20px;\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #f6f7fa, stop: 1 #dadbde);\n"
"     min-width: 80px;\n"
" }\n"
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
        chkCommonGnd = new QCheckBox(SelectProbe);
        chkCommonGnd->setObjectName(QString::fromUtf8("chkCommonGnd"));
        chkCommonGnd->setGeometry(QRect(50, 290, 101, 41));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush28(QColor(255, 85, 255, 255));
        brush28.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush28);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush28);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush28);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        chkCommonGnd->setPalette(palette2);
        chkCommonGnd->setFont(font4);
        chkCommonGnd->setFocusPolicy(Qt::NoFocus);
        chkCommonGnd->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
"font:bold 18px;\n"
"color:white;\n"
"}\n"
" QCheckBox::indicator {\n"
"     width: 20px;\n"
"     height:20px;\n"
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
        label = new QLabel(SelectProbe);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(170, 99, 101, 20));
        label->setFont(font5);
        grpReferenceProbes = new QGroupBox(SelectProbe);
        grpReferenceProbes->setObjectName(QString::fromUtf8("grpReferenceProbes"));
        grpReferenceProbes->setGeometry(QRect(220, 80, 261, 81));
        grpReferenceProbes->setFont(font3);
        grpReferenceProbes->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
"color:white;\n"
"\n"
"border:1px solid white;\n"
"}\n"
" QGroupBox::title {\n"
"	border:1px solid white;\n"
"	border-radius:5px;\n"
"     subcontrol-origin: margin;\n"
"     subcontrol-position: top center; /* position at the top center */\n"
"     padding: 0 3px;\n"
"	 color:white;\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #3a5976, stop: 1 #000000);\n"
" }"));
        layoutWidget1 = new QWidget(grpReferenceProbes);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 30, 216, 26));
        gridLayout_2 = new QGridLayout(layoutWidget1);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        optRefProbe1 = new QRadioButton(layoutWidget1);
        optRefProbe1->setObjectName(QString::fromUtf8("optRefProbe1"));
        optRefProbe1->setFont(font4);
        optRefProbe1->setFocusPolicy(Qt::NoFocus);
        optRefProbe1->setStyleSheet(QString::fromUtf8("QRadioButton{\n"
"font:bold 18px;\n"
"color:white;\n"
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

        gridLayout_2->addWidget(optRefProbe1, 0, 0, 1, 1);

        opRefProbe2 = new QRadioButton(layoutWidget1);
        opRefProbe2->setObjectName(QString::fromUtf8("opRefProbe2"));
        opRefProbe2->setFont(font4);
        opRefProbe2->setFocusPolicy(Qt::NoFocus);
        opRefProbe2->setStyleSheet(QString::fromUtf8("QRadioButton{\n"
"font:bold 18px;\n"
"color:white;\n"
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

        gridLayout_2->addWidget(opRefProbe2, 0, 1, 1, 1);


        retranslateUi(SelectProbe);

        lstProbes->setCurrentRow(-1);


        QMetaObject::connectSlotsByName(SelectProbe);
    } // setupUi

    void retranslateUi(QDialog *SelectProbe)
    {
        SelectProbe->setWindowTitle(QApplication::translate("SelectProbe", "Probe", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("SelectProbe", "Probe", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled = lstProbes->isSortingEnabled();
        lstProbes->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = lstProbes->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("SelectProbe", "SINGLE", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem1 = lstProbes->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("SelectProbe", "DUAL", 0, QApplication::UnicodeUTF8));
        lstProbes->setSortingEnabled(__sortingEnabled);

        grpComparison->setTitle(QApplication::translate("SelectProbe", "Comparison", 0, QApplication::UnicodeUTF8));
        optAverage->setText(QApplication::translate("SelectProbe", "Average", 0, QApplication::UnicodeUTF8));
        optLinear->setText(QApplication::translate("SelectProbe", "Envelope", 0, QApplication::UnicodeUTF8));
        grpACF->setTitle(QApplication::translate("SelectProbe", "AutoCurveFit", 0, QApplication::UnicodeUTF8));
        optResistance->setText(QApplication::translate("SelectProbe", "R", 0, QApplication::UnicodeUTF8));
        optCapcitance->setText(QApplication::translate("SelectProbe", "C", 0, QApplication::UnicodeUTF8));
        optInductance->setText(QApplication::translate("SelectProbe", "L", 0, QApplication::UnicodeUTF8));
        optDiode->setText(QApplication::translate("SelectProbe", "Diode", 0, QApplication::UnicodeUTF8));
        optAll->setText(QApplication::translate("SelectProbe", "All", 0, QApplication::UnicodeUTF8));
        butAdvSetup->setText(QApplication::translate("SelectProbe", "Advaned", 0, QApplication::UnicodeUTF8));
        butOK->setText(QApplication::translate("SelectProbe", "OK", 0, QApplication::UnicodeUTF8));
        chkCommonGnd->setText(QApplication::translate("SelectProbe", "C-GND", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("SelectProbe", "Threshold:", 0, QApplication::UnicodeUTF8));
        grpReferenceProbes->setTitle(QApplication::translate("SelectProbe", "Reference Probe", 0, QApplication::UnicodeUTF8));
        optRefProbe1->setText(QApplication::translate("SelectProbe", "Probe1", 0, QApplication::UnicodeUTF8));
        opRefProbe2->setText(QApplication::translate("SelectProbe", "Probe2", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SelectProbe: public Ui_SelectProbe {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTPROBE_H
