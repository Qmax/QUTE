/********************************************************************************
** Form generated from reading UI file 'clipdialog.ui'
**
** Created: Sat Oct 25 11:32:04 2014
**      by: Qt User Interface Compiler version 4.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIPDIALOG_H
#define UI_CLIPDIALOG_H

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

class Ui_ClipDialog
{
public:
    QLabel *label;
    QPushButton *butClose;
    QLabel *label_2;
    QGroupBox *groupBox;
    QLabel *lblRefChannel;
    QWidget *widget;
    QGridLayout *gridLayout;
    QRadioButton *objFixedOption;
    QRadioButton *objFixedOption_2;
    QWidget *widget1;
    QGridLayout *gridLayout_3;
    QLabel *label_3;
    QLabel *lblCombinations;
    QListWidget *listWidget;
    QPushButton *butOK;
    QGroupBox *grpCompare;
    QLabel *label_4;
    QWidget *widget2;
    QGridLayout *gridLayout_2;
    QRadioButton *optAverage;
    QRadioButton *optLinear;
    QCheckBox *chkStoponFail;

    void setupUi(QDialog *ClipDialog)
    {
        if (ClipDialog->objectName().isEmpty())
            ClipDialog->setObjectName(QString::fromUtf8("ClipDialog"));
        ClipDialog->setWindowModality(Qt::WindowModal);
        ClipDialog->resize(527, 321);
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
        ClipDialog->setPalette(palette);
        QFont font;
        font.setFamily(QString::fromUtf8("DejaVu Sans"));
        ClipDialog->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image.png"), QSize(), QIcon::Normal, QIcon::Off);
        ClipDialog->setWindowIcon(icon);
        ClipDialog->setStyleSheet(QString::fromUtf8("QDialog{\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 1,\n"
"stop: 0 #636655, stop: 0.4 gray, stop: 0.8 #636655, stop: 1 gray);\n"
"}"));
        label = new QLabel(ClipDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(7, 5, 101, 20));
        QFont font1;
        font1.setFamily(QString::fromUtf8("DejaVu Sans"));
        font1.setPointSize(14);
        label->setFont(font1);
        butClose = new QPushButton(ClipDialog);
        butClose->setObjectName(QString::fromUtf8("butClose"));
        butClose->setGeometry(QRect(360, 250, 84, 61));
        QFont font2;
        font2.setFamily(QString::fromUtf8("DejaVu Sans"));
        font2.setPointSize(16);
        butClose->setFont(font2);
        butClose->setFocusPolicy(Qt::NoFocus);
        butClose->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"border: 2px solid #8f8f91;\n"
"border-radius: 20px;\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"stop: 0 #f6f7fa, stop: 1 #dadbde);\n"
"min-width: 80px;\n"
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
"}"));
        label_2 = new QLabel(ClipDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(280, 65, 41, 20));
        label_2->setFont(font1);
        groupBox = new QGroupBox(ClipDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(220, 30, 281, 211));
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
        lblRefChannel = new QLabel(groupBox);
        lblRefChannel->setObjectName(QString::fromUtf8("lblRefChannel"));
        lblRefChannel->setGeometry(QRect(60, 138, 131, 20));
        lblRefChannel->setFont(font1);
        widget = new QWidget(groupBox);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(14, 79, 251, 41));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        objFixedOption = new QRadioButton(widget);
        objFixedOption->setObjectName(QString::fromUtf8("objFixedOption"));
        QFont font3;
        font3.setBold(true);
        font3.setItalic(false);
        font3.setWeight(75);
        objFixedOption->setFont(font3);
        objFixedOption->setFocusPolicy(Qt::NoFocus);
        objFixedOption->setStyleSheet(QString::fromUtf8("QRadioButton{\n"
"font:bold 18px;\n"
"color:white;\n"
"}\n"
"QRadioButton::indicator {\n"
"width: 20px;\n"
"height:20px;\n"
"border: 2px solid black;\n"
"border-radius:12px;\n"
"}\n"
"QRadioButton::indicator::unchecked {\n"
"background-color:white;\n"
"}\n"
"QRadioButton::indicator:unchecked:hover {\n"
"background-color:white;\n"
"}\n"
"QRadioButton::indicator:unchecked:pressed {\n"
"background-color:white;\n"
"}\n"
"QRadioButton::indicator::checked {\n"
"background-color:#f2a400;\n"
"}\n"
"QRadioButton::indicator:checked:hover {\n"
"background-color:#f2a400;\n"
"}\n"
"QRadioButton::indicator:checked:pressed {\n"
"background-color:#f2a400;\n"
"}"));

        gridLayout->addWidget(objFixedOption, 0, 0, 1, 1);

        objFixedOption_2 = new QRadioButton(widget);
        objFixedOption_2->setObjectName(QString::fromUtf8("objFixedOption_2"));
        objFixedOption_2->setFont(font3);
        objFixedOption_2->setFocusPolicy(Qt::NoFocus);
        objFixedOption_2->setStyleSheet(QString::fromUtf8("QRadioButton{\n"
"font:bold 18px;\n"
"color:white;\n"
"}\n"
"QRadioButton::indicator {\n"
"width: 20px;\n"
"height:20px;\n"
"border: 2px solid black;\n"
"border-radius:12px;\n"
"}\n"
"QRadioButton::indicator::unchecked {\n"
"background-color:white;\n"
"}\n"
"QRadioButton::indicator:unchecked:hover {\n"
"background-color:white;\n"
"}\n"
"QRadioButton::indicator:unchecked:pressed {\n"
"background-color:white;\n"
"}\n"
"QRadioButton::indicator::checked {\n"
"background-color:#f2a400;\n"
"}\n"
"QRadioButton::indicator:checked:hover {\n"
"background-color:#f2a400;\n"
"}\n"
"QRadioButton::indicator:checked:pressed {\n"
"background-color:#f2a400;\n"
"}"));

        gridLayout->addWidget(objFixedOption_2, 0, 1, 1, 1);

        widget1 = new QWidget(groupBox);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(10, 177, 261, 27));
        gridLayout_3 = new QGridLayout(widget1);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(widget1);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font1);

        gridLayout_3->addWidget(label_3, 0, 0, 1, 1);

        lblCombinations = new QLabel(widget1);
        lblCombinations->setObjectName(QString::fromUtf8("lblCombinations"));
        lblCombinations->setFont(font2);

        gridLayout_3->addWidget(lblCombinations, 0, 1, 1, 1);

        listWidget = new QListWidget(ClipDialog);
        QFont font4;
        font4.setPointSize(20);
        QListWidgetItem *__qlistwidgetitem = new QListWidgetItem(listWidget);
        __qlistwidgetitem->setFont(font4);
        QListWidgetItem *__qlistwidgetitem1 = new QListWidgetItem(listWidget);
        __qlistwidgetitem1->setFont(font4);
        QListWidgetItem *__qlistwidgetitem2 = new QListWidgetItem(listWidget);
        __qlistwidgetitem2->setFont(font4);
        QListWidgetItem *__qlistwidgetitem3 = new QListWidgetItem(listWidget);
        __qlistwidgetitem3->setFont(font4);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(7, 30, 201, 141));
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
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QLinearGradient gradient12(0, 0, 0, 1);
        gradient12.setSpread(QGradient::PadSpread);
        gradient12.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient12.setColorAt(0, QColor(58, 89, 118, 255));
        gradient12.setColorAt(1, QColor(0, 0, 0, 255));
        QBrush brush20(gradient12);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush20);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        QLinearGradient gradient13(0, 0, 0, 1);
        gradient13.setSpread(QGradient::PadSpread);
        gradient13.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient13.setColorAt(0, QColor(58, 89, 118, 255));
        gradient13.setColorAt(1, QColor(0, 0, 0, 255));
        QBrush brush21(gradient13);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush21);
        QLinearGradient gradient14(0, 0, 0, 1);
        gradient14.setSpread(QGradient::PadSpread);
        gradient14.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient14.setColorAt(0, QColor(58, 89, 118, 255));
        gradient14.setColorAt(1, QColor(0, 0, 0, 255));
        QBrush brush22(gradient14);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush22);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        QLinearGradient gradient15(0, 0, 0, 1);
        gradient15.setSpread(QGradient::PadSpread);
        gradient15.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient15.setColorAt(0, QColor(58, 89, 118, 255));
        gradient15.setColorAt(1, QColor(0, 0, 0, 255));
        QBrush brush23(gradient15);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush23);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        QLinearGradient gradient16(0, 0, 0, 1);
        gradient16.setSpread(QGradient::PadSpread);
        gradient16.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient16.setColorAt(0, QColor(58, 89, 118, 255));
        gradient16.setColorAt(1, QColor(0, 0, 0, 255));
        QBrush brush24(gradient16);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush24);
        QLinearGradient gradient17(0, 0, 0, 1);
        gradient17.setSpread(QGradient::PadSpread);
        gradient17.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient17.setColorAt(0, QColor(58, 89, 118, 255));
        gradient17.setColorAt(1, QColor(0, 0, 0, 255));
        QBrush brush25(gradient17);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush25);
        listWidget->setPalette(palette1);
        QFont font5;
        font5.setFamily(QString::fromUtf8("DejaVu Sans"));
        font5.setPointSize(18);
        listWidget->setFont(font5);
        listWidget->setFocusPolicy(Qt::NoFocus);
        listWidget->setStyleSheet(QString::fromUtf8(" QListView {\n"
"     show-decoration-selected: 1; /* make the selection span the entire width of the\n"
"view */\n"
"border:2px solid #F1F5DA;\n"
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
        listWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        listWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        butOK = new QPushButton(ClipDialog);
        butOK->setObjectName(QString::fromUtf8("butOK"));
        butOK->setGeometry(QRect(270, 250, 84, 61));
        butOK->setFont(font2);
        butOK->setFocusPolicy(Qt::NoFocus);
        butOK->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"border: 2px solid #8f8f91;\n"
"border-radius: 20px;\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"stop: 0 #f6f7fa, stop: 1 #dadbde);\n"
"min-width: 80px;\n"
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
"}"));
        grpCompare = new QGroupBox(ClipDialog);
        grpCompare->setObjectName(QString::fromUtf8("grpCompare"));
        grpCompare->setGeometry(QRect(7, 177, 201, 141));
        QFont font6;
        font6.setFamily(QString::fromUtf8("DejaVu Sans"));
        font6.setPointSize(12);
        grpCompare->setFont(font6);
        grpCompare->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
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
        label_4 = new QLabel(grpCompare);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 106, 101, 20));
        QFont font7;
        font7.setFamily(QString::fromUtf8("DejaVu Sans"));
        font7.setPointSize(14);
        font7.setBold(false);
        font7.setWeight(50);
        label_4->setFont(font7);
        widget2 = new QWidget(grpCompare);
        widget2->setObjectName(QString::fromUtf8("widget2"));
        widget2->setGeometry(QRect(20, 20, 141, 81));
        gridLayout_2 = new QGridLayout(widget2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        optAverage = new QRadioButton(widget2);
        optAverage->setObjectName(QString::fromUtf8("optAverage"));
        optAverage->setFont(font3);
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

        gridLayout_2->addWidget(optAverage, 0, 0, 1, 1);

        optLinear = new QRadioButton(widget2);
        optLinear->setObjectName(QString::fromUtf8("optLinear"));
        optLinear->setFont(font3);
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

        gridLayout_2->addWidget(optLinear, 1, 0, 1, 1);

        chkStoponFail = new QCheckBox(ClipDialog);
        chkStoponFail->setObjectName(QString::fromUtf8("chkStoponFail"));
        chkStoponFail->setEnabled(false);
        chkStoponFail->setGeometry(QRect(440, 330, 91, 25));
        QFont font8;
        font8.setBold(false);
        font8.setItalic(false);
        font8.setWeight(50);
        chkStoponFail->setFont(font8);
        chkStoponFail->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
"font:14px;\n"
"color:white;\n"
"}\n"
" QCheckBox::indicator {\n"
"     width: 22px;\n"
"     height:22px;\n"
"   border: 2px solid black;\n"
"	 border-radius:1\n"
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

        retranslateUi(ClipDialog);

        QMetaObject::connectSlotsByName(ClipDialog);
    } // setupUi

    void retranslateUi(QDialog *ClipDialog)
    {
        ClipDialog->setWindowTitle(QApplication::translate("ClipDialog", "Clip Selection", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ClipDialog", "Select Clip:", 0, QApplication::UnicodeUTF8));
        butClose->setText(QApplication::translate("ClipDialog", "Cancel", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ClipDialog", "Pins:", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("ClipDialog", "Pin Combination", 0, QApplication::UnicodeUTF8));
        lblRefChannel->setText(QApplication::translate("ClipDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'DejaVu Sans'; font-size:14pt; font-weight:400; font-style:normal;\">\n"
"<table style=\"-qt-table-type: root; margin-top:4px; margin-bottom:4px; margin-left:4px; margin-right:4px;\">\n"
"<tr>\n"
"<td style=\"border: none;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Fixed Ref Pin:</p></td></tr></table></body></html>", 0, QApplication::UnicodeUTF8));
        objFixedOption->setText(QApplication::translate("ClipDialog", "FIXED", 0, QApplication::UnicodeUTF8));
        objFixedOption_2->setText(QApplication::translate("ClipDialog", "MOVING", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ClipDialog", "Pins Combinations:", 0, QApplication::UnicodeUTF8));
        lblCombinations->setText(QString());

        const bool __sortingEnabled = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("ClipDialog", "14 PINS", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem1 = listWidget->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("ClipDialog", "20 PINS", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem2 = listWidget->item(2);
        ___qlistwidgetitem2->setText(QApplication::translate("ClipDialog", "24 PINS", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem3 = listWidget->item(3);
        ___qlistwidgetitem3->setText(QApplication::translate("ClipDialog", "28 PINS", 0, QApplication::UnicodeUTF8));
        listWidget->setSortingEnabled(__sortingEnabled);

        butOK->setText(QApplication::translate("ClipDialog", "OK", 0, QApplication::UnicodeUTF8));
        grpCompare->setTitle(QApplication::translate("ClipDialog", "Comparison", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("ClipDialog", "Threshold:", 0, QApplication::UnicodeUTF8));
        optAverage->setText(QApplication::translate("ClipDialog", "Average", 0, QApplication::UnicodeUTF8));
        optLinear->setText(QApplication::translate("ClipDialog", "Envelope", 0, QApplication::UnicodeUTF8));
        chkStoponFail->setText(QApplication::translate("ClipDialog", "Stop on Fail", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ClipDialog: public Ui_ClipDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIPDIALOG_H
