/********************************************************************************
** Form generated from reading UI file 'embeddedkeys.ui'
**
** Created: Mon Nov 24 17:14:29 2014
**      by: Qt User Interface Compiler version 4.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMBEDDEDKEYS_H
#define UI_EMBEDDEDKEYS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EmbeddedKeysClass
{
public:
    QPushButton *butLeft;
    QPushButton *butRigth;
    QLineEdit *lblLeftText;
    QLineEdit *lblRightText;
    QLabel *label_3;
    QLabel *label;
    QLabel *label_2;
    QListWidget *lstKeyOperations;
    QPushButton *butMiddle;
    QLineEdit *lblMiddleText;
    QPushButton *butClose;
    QFrame *line_16;
    QFrame *line_17;
    QFrame *line_18;
    QFrame *line_19;
    QFrame *line_20;
    QFrame *line_21;
    QComboBox *cmbCombinationKeys;
    QLabel *label_4;

    void setupUi(QWidget *EmbeddedKeysClass)
    {
        if (EmbeddedKeysClass->objectName().isEmpty())
            EmbeddedKeysClass->setObjectName(QString::fromUtf8("EmbeddedKeysClass"));
        EmbeddedKeysClass->setWindowModality(Qt::WindowModal);
        EmbeddedKeysClass->resize(572, 376);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(EmbeddedKeysClass->sizePolicy().hasHeightForWidth());
        EmbeddedKeysClass->setSizePolicy(sizePolicy);
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
        EmbeddedKeysClass->setPalette(palette);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/res/image.png"), QSize(), QIcon::Normal, QIcon::Off);
        EmbeddedKeysClass->setWindowIcon(icon);
        EmbeddedKeysClass->setStyleSheet(QString::fromUtf8("QWidget{\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 1,\n"
"stop: 0 #636655, stop: 0.4 gray, stop: 0.8 #636655, stop: 1 gray);\n"
"}\n"
"Line{\n"
"background-color:rgba(0,0,0,0);\n"
"}\n"
""));
        butLeft = new QPushButton(EmbeddedKeysClass);
        butLeft->setObjectName(QString::fromUtf8("butLeft"));
        butLeft->setGeometry(QRect(260, 100, 161, 61));
        QFont font;
        font.setFamily(QString::fromUtf8("DejaVu Sans"));
        font.setPointSize(12);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        butLeft->setFont(font);
        butLeft->setFocusPolicy(Qt::NoFocus);
        butLeft->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        butRigth = new QPushButton(EmbeddedKeysClass);
        butRigth->setObjectName(QString::fromUtf8("butRigth"));
        butRigth->setGeometry(QRect(260, 248, 161, 61));
        QFont font1;
        font1.setFamily(QString::fromUtf8("DejaVu Sans"));
        font1.setPointSize(12);
        font1.setBold(false);
        font1.setWeight(50);
        butRigth->setFont(font1);
        butRigth->setFocusPolicy(Qt::NoFocus);
        butRigth->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        lblLeftText = new QLineEdit(EmbeddedKeysClass);
        lblLeftText->setObjectName(QString::fromUtf8("lblLeftText"));
        lblLeftText->setGeometry(QRect(432, 108, 131, 41));
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
        lblLeftText->setPalette(palette1);
        QFont font2;
        font2.setFamily(QString::fromUtf8("DejaVu Sans"));
        font2.setPointSize(12);
        lblLeftText->setFont(font2);
        lblLeftText->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{\n"
"border:1px solid white;border-radius:10px;\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #3a5976, stop: 1 #000000);\n"
"color:white;\n"
"}"));
        lblRightText = new QLineEdit(EmbeddedKeysClass);
        lblRightText->setObjectName(QString::fromUtf8("lblRightText"));
        lblRightText->setGeometry(QRect(430, 258, 131, 41));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QLinearGradient gradient18(0, 0, 0, 1);
        gradient18.setSpread(QGradient::PadSpread);
        gradient18.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient18.setColorAt(0, QColor(58, 89, 118, 255));
        gradient18.setColorAt(1, QColor(0, 0, 0, 255));
        QBrush brush26(gradient18);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush26);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QLinearGradient gradient19(0, 0, 0, 1);
        gradient19.setSpread(QGradient::PadSpread);
        gradient19.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient19.setColorAt(0, QColor(58, 89, 118, 255));
        gradient19.setColorAt(1, QColor(0, 0, 0, 255));
        QBrush brush27(gradient19);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush27);
        QLinearGradient gradient20(0, 0, 0, 1);
        gradient20.setSpread(QGradient::PadSpread);
        gradient20.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient20.setColorAt(0, QColor(58, 89, 118, 255));
        gradient20.setColorAt(1, QColor(0, 0, 0, 255));
        QBrush brush28(gradient20);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush28);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QLinearGradient gradient21(0, 0, 0, 1);
        gradient21.setSpread(QGradient::PadSpread);
        gradient21.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient21.setColorAt(0, QColor(58, 89, 118, 255));
        gradient21.setColorAt(1, QColor(0, 0, 0, 255));
        QBrush brush29(gradient21);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush29);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        QLinearGradient gradient22(0, 0, 0, 1);
        gradient22.setSpread(QGradient::PadSpread);
        gradient22.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient22.setColorAt(0, QColor(58, 89, 118, 255));
        gradient22.setColorAt(1, QColor(0, 0, 0, 255));
        QBrush brush30(gradient22);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush30);
        QLinearGradient gradient23(0, 0, 0, 1);
        gradient23.setSpread(QGradient::PadSpread);
        gradient23.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient23.setColorAt(0, QColor(58, 89, 118, 255));
        gradient23.setColorAt(1, QColor(0, 0, 0, 255));
        QBrush brush31(gradient23);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush31);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        QLinearGradient gradient24(0, 0, 0, 1);
        gradient24.setSpread(QGradient::PadSpread);
        gradient24.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient24.setColorAt(0, QColor(58, 89, 118, 255));
        gradient24.setColorAt(1, QColor(0, 0, 0, 255));
        QBrush brush32(gradient24);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush32);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        QLinearGradient gradient25(0, 0, 0, 1);
        gradient25.setSpread(QGradient::PadSpread);
        gradient25.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient25.setColorAt(0, QColor(58, 89, 118, 255));
        gradient25.setColorAt(1, QColor(0, 0, 0, 255));
        QBrush brush33(gradient25);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush33);
        QLinearGradient gradient26(0, 0, 0, 1);
        gradient26.setSpread(QGradient::PadSpread);
        gradient26.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient26.setColorAt(0, QColor(58, 89, 118, 255));
        gradient26.setColorAt(1, QColor(0, 0, 0, 255));
        QBrush brush34(gradient26);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush34);
        lblRightText->setPalette(palette2);
        lblRightText->setFont(font2);
        lblRightText->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{\n"
"border:1px solid white;border-radius:10px;\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #3a5976, stop: 1 #000000);\n"
"color:white;\n"
"}"));
        label_3 = new QLabel(EmbeddedKeysClass);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(440, 238, 69, 20));
        QFont font3;
        font3.setFamily(QString::fromUtf8("DejaVu Sans"));
        font3.setPointSize(16);
        label_3->setFont(font3);
        label = new QLabel(EmbeddedKeysClass);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(440, 88, 61, 20));
        label->setFont(font3);
        label_2 = new QLabel(EmbeddedKeysClass);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(440, 168, 101, 20));
        label_2->setFont(font3);
        lstKeyOperations = new QListWidget(EmbeddedKeysClass);
        lstKeyOperations->setObjectName(QString::fromUtf8("lstKeyOperations"));
        lstKeyOperations->setGeometry(QRect(10, 106, 241, 201));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QLinearGradient gradient27(0, 0, 0, 1);
        gradient27.setSpread(QGradient::PadSpread);
        gradient27.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient27.setColorAt(0, QColor(58, 89, 118, 255));
        gradient27.setColorAt(1, QColor(0, 0, 0, 255));
        QBrush brush35(gradient27);
        palette3.setBrush(QPalette::Active, QPalette::Button, brush35);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QLinearGradient gradient28(0, 0, 0, 1);
        gradient28.setSpread(QGradient::PadSpread);
        gradient28.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient28.setColorAt(0, QColor(58, 89, 118, 255));
        gradient28.setColorAt(1, QColor(0, 0, 0, 255));
        QBrush brush36(gradient28);
        palette3.setBrush(QPalette::Active, QPalette::Base, brush36);
        QLinearGradient gradient29(0, 0, 0, 1);
        gradient29.setSpread(QGradient::PadSpread);
        gradient29.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient29.setColorAt(0, QColor(58, 89, 118, 255));
        gradient29.setColorAt(1, QColor(0, 0, 0, 255));
        QBrush brush37(gradient29);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush37);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QLinearGradient gradient30(0, 0, 0, 1);
        gradient30.setSpread(QGradient::PadSpread);
        gradient30.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient30.setColorAt(0, QColor(58, 89, 118, 255));
        gradient30.setColorAt(1, QColor(0, 0, 0, 255));
        QBrush brush38(gradient30);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush38);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        QLinearGradient gradient31(0, 0, 0, 1);
        gradient31.setSpread(QGradient::PadSpread);
        gradient31.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient31.setColorAt(0, QColor(58, 89, 118, 255));
        gradient31.setColorAt(1, QColor(0, 0, 0, 255));
        QBrush brush39(gradient31);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush39);
        QLinearGradient gradient32(0, 0, 0, 1);
        gradient32.setSpread(QGradient::PadSpread);
        gradient32.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient32.setColorAt(0, QColor(58, 89, 118, 255));
        gradient32.setColorAt(1, QColor(0, 0, 0, 255));
        QBrush brush40(gradient32);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush40);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        QLinearGradient gradient33(0, 0, 0, 1);
        gradient33.setSpread(QGradient::PadSpread);
        gradient33.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient33.setColorAt(0, QColor(58, 89, 118, 255));
        gradient33.setColorAt(1, QColor(0, 0, 0, 255));
        QBrush brush41(gradient33);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush41);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        QLinearGradient gradient34(0, 0, 0, 1);
        gradient34.setSpread(QGradient::PadSpread);
        gradient34.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient34.setColorAt(0, QColor(58, 89, 118, 255));
        gradient34.setColorAt(1, QColor(0, 0, 0, 255));
        QBrush brush42(gradient34);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush42);
        QLinearGradient gradient35(0, 0, 0, 1);
        gradient35.setSpread(QGradient::PadSpread);
        gradient35.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient35.setColorAt(0, QColor(58, 89, 118, 255));
        gradient35.setColorAt(1, QColor(0, 0, 0, 255));
        QBrush brush43(gradient35);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush43);
        lstKeyOperations->setPalette(palette3);
        QFont font4;
        font4.setFamily(QString::fromUtf8("DejaVu Sans"));
        font4.setPointSize(20);
        font4.setBold(false);
        font4.setWeight(50);
        lstKeyOperations->setFont(font4);
        lstKeyOperations->setFocusPolicy(Qt::NoFocus);
        lstKeyOperations->setStyleSheet(QString::fromUtf8(" QListView {\n"
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
""));
        lstKeyOperations->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        butMiddle = new QPushButton(EmbeddedKeysClass);
        butMiddle->setObjectName(QString::fromUtf8("butMiddle"));
        butMiddle->setGeometry(QRect(260, 180, 161, 61));
        butMiddle->setFont(font1);
        butMiddle->setFocusPolicy(Qt::NoFocus);
        butMiddle->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        lblMiddleText = new QLineEdit(EmbeddedKeysClass);
        lblMiddleText->setObjectName(QString::fromUtf8("lblMiddleText"));
        lblMiddleText->setGeometry(QRect(432, 188, 131, 41));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QLinearGradient gradient36(0, 0, 0, 1);
        gradient36.setSpread(QGradient::PadSpread);
        gradient36.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient36.setColorAt(0, QColor(58, 89, 118, 255));
        gradient36.setColorAt(1, QColor(0, 0, 0, 255));
        QBrush brush44(gradient36);
        palette4.setBrush(QPalette::Active, QPalette::Button, brush44);
        palette4.setBrush(QPalette::Active, QPalette::Text, brush);
        palette4.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QLinearGradient gradient37(0, 0, 0, 1);
        gradient37.setSpread(QGradient::PadSpread);
        gradient37.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient37.setColorAt(0, QColor(58, 89, 118, 255));
        gradient37.setColorAt(1, QColor(0, 0, 0, 255));
        QBrush brush45(gradient37);
        palette4.setBrush(QPalette::Active, QPalette::Base, brush45);
        QLinearGradient gradient38(0, 0, 0, 1);
        gradient38.setSpread(QGradient::PadSpread);
        gradient38.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient38.setColorAt(0, QColor(58, 89, 118, 255));
        gradient38.setColorAt(1, QColor(0, 0, 0, 255));
        QBrush brush46(gradient38);
        palette4.setBrush(QPalette::Active, QPalette::Window, brush46);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QLinearGradient gradient39(0, 0, 0, 1);
        gradient39.setSpread(QGradient::PadSpread);
        gradient39.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient39.setColorAt(0, QColor(58, 89, 118, 255));
        gradient39.setColorAt(1, QColor(0, 0, 0, 255));
        QBrush brush47(gradient39);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush47);
        palette4.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        QLinearGradient gradient40(0, 0, 0, 1);
        gradient40.setSpread(QGradient::PadSpread);
        gradient40.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient40.setColorAt(0, QColor(58, 89, 118, 255));
        gradient40.setColorAt(1, QColor(0, 0, 0, 255));
        QBrush brush48(gradient40);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush48);
        QLinearGradient gradient41(0, 0, 0, 1);
        gradient41.setSpread(QGradient::PadSpread);
        gradient41.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient41.setColorAt(0, QColor(58, 89, 118, 255));
        gradient41.setColorAt(1, QColor(0, 0, 0, 255));
        QBrush brush49(gradient41);
        palette4.setBrush(QPalette::Inactive, QPalette::Window, brush49);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        QLinearGradient gradient42(0, 0, 0, 1);
        gradient42.setSpread(QGradient::PadSpread);
        gradient42.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient42.setColorAt(0, QColor(58, 89, 118, 255));
        gradient42.setColorAt(1, QColor(0, 0, 0, 255));
        QBrush brush50(gradient42);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush50);
        palette4.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        QLinearGradient gradient43(0, 0, 0, 1);
        gradient43.setSpread(QGradient::PadSpread);
        gradient43.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient43.setColorAt(0, QColor(58, 89, 118, 255));
        gradient43.setColorAt(1, QColor(0, 0, 0, 255));
        QBrush brush51(gradient43);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush51);
        QLinearGradient gradient44(0, 0, 0, 1);
        gradient44.setSpread(QGradient::PadSpread);
        gradient44.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient44.setColorAt(0, QColor(58, 89, 118, 255));
        gradient44.setColorAt(1, QColor(0, 0, 0, 255));
        QBrush brush52(gradient44);
        palette4.setBrush(QPalette::Disabled, QPalette::Window, brush52);
        lblMiddleText->setPalette(palette4);
        lblMiddleText->setFont(font2);
        lblMiddleText->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{\n"
"border:1px solid white;border-radius:10px;\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #3a5976, stop: 1 #000000);\n"
"color:white;\n"
"}"));
        butClose = new QPushButton(EmbeddedKeysClass);
        butClose->setObjectName(QString::fromUtf8("butClose"));
        butClose->setGeometry(QRect(460, 308, 101, 61));
        butClose->setFont(font3);
        butClose->setFocusPolicy(Qt::NoFocus);
        butClose->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"border: 2px solid #8f8f91;\n"
"border-radius: 25px;\n"
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
        line_16 = new QFrame(EmbeddedKeysClass);
        line_16->setObjectName(QString::fromUtf8("line_16"));
        line_16->setGeometry(QRect(250, 122, 16, 21));
        line_16->setStyleSheet(QString::fromUtf8("background-color:rgba(0,0,0,0);\n"
""));
        line_16->setFrameShape(QFrame::HLine);
        line_16->setFrameShadow(QFrame::Sunken);
        line_17 = new QFrame(EmbeddedKeysClass);
        line_17->setObjectName(QString::fromUtf8("line_17"));
        line_17->setGeometry(QRect(251, 268, 11, 15));
        line_17->setStyleSheet(QString::fromUtf8("background-color:rgba(0,0,0,0);\n"
""));
        line_17->setFrameShape(QFrame::HLine);
        line_17->setFrameShadow(QFrame::Sunken);
        line_18 = new QFrame(EmbeddedKeysClass);
        line_18->setObjectName(QString::fromUtf8("line_18"));
        line_18->setGeometry(QRect(419, 120, 14, 15));
        line_18->setStyleSheet(QString::fromUtf8("background-color:rgba(0,0,0,0);\n"
""));
        line_18->setFrameShape(QFrame::HLine);
        line_18->setFrameShadow(QFrame::Sunken);
        line_19 = new QFrame(EmbeddedKeysClass);
        line_19->setObjectName(QString::fromUtf8("line_19"));
        line_19->setGeometry(QRect(421, 201, 13, 15));
        line_19->setStyleSheet(QString::fromUtf8("background-color:rgba(0,0,0,0);\n"
""));
        line_19->setFrameShape(QFrame::HLine);
        line_19->setFrameShadow(QFrame::Sunken);
        line_20 = new QFrame(EmbeddedKeysClass);
        line_20->setObjectName(QString::fromUtf8("line_20"));
        line_20->setGeometry(QRect(419, 270, 12, 15));
        line_20->setStyleSheet(QString::fromUtf8("background-color:rgba(0,0,0,0);\n"
""));
        line_20->setFrameShape(QFrame::HLine);
        line_20->setFrameShadow(QFrame::Sunken);
        line_21 = new QFrame(EmbeddedKeysClass);
        line_21->setObjectName(QString::fromUtf8("line_21"));
        line_21->setGeometry(QRect(251, 203, 11, 15));
        line_21->setStyleSheet(QString::fromUtf8("background-color:rgba(0,0,0,0);\n"
""));
        line_21->setFrameShape(QFrame::HLine);
        line_21->setFrameShadow(QFrame::Sunken);
        cmbCombinationKeys = new QComboBox(EmbeddedKeysClass);
        cmbCombinationKeys->setObjectName(QString::fromUtf8("cmbCombinationKeys"));
        cmbCombinationKeys->setGeometry(QRect(11, 33, 241, 51));
        QFont font5;
        font5.setFamily(QString::fromUtf8("DejaVu Sans"));
        font5.setPointSize(20);
        cmbCombinationKeys->setFont(font5);
        cmbCombinationKeys->setStyleSheet(QString::fromUtf8("QComboBox{\n"
"show-decoration-selected: 1; \n"
"border:1px solid #F1F5DA;\n"
"border-radius: 10px;\n"
"color:white;\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #3a5976, stop: 1 #000000);\n"
"}\n"
"QComboBox::drop-down {\n"
"     width:40px;\n"
"	color:white;\n"
" }\n"
"\n"
"QComboBox::::item:selected {\n"
"     border: 1px solid #6a6ea9;\n"
" }\n"
"\n"
""));
        label_4 = new QLabel(EmbeddedKeysClass);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(11, 13, 171, 20));
        label_4->setFont(font3);

        retranslateUi(EmbeddedKeysClass);

        QMetaObject::connectSlotsByName(EmbeddedKeysClass);
    } // setupUi

    void retranslateUi(QWidget *EmbeddedKeysClass)
    {
        EmbeddedKeysClass->setWindowTitle(QApplication::translate("EmbeddedKeysClass", "Select Embedded Keys", 0, QApplication::UnicodeUTF8));
        butLeft->setText(QApplication::translate("EmbeddedKeysClass", "Assign to Left Key", 0, QApplication::UnicodeUTF8));
        butRigth->setText(QApplication::translate("EmbeddedKeysClass", "Assign to Right Key", 0, QApplication::UnicodeUTF8));
        lblLeftText->setText(QApplication::translate("EmbeddedKeysClass", "RUN/STOP", 0, QApplication::UnicodeUTF8));
        lblRightText->setText(QApplication::translate("EmbeddedKeysClass", "DELETE", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("EmbeddedKeysClass", "RIGHT:", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("EmbeddedKeysClass", "LEFT:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("EmbeddedKeysClass", "MIDDLE:", 0, QApplication::UnicodeUTF8));
        butMiddle->setText(QApplication::translate("EmbeddedKeysClass", "Assign to Middle Key", 0, QApplication::UnicodeUTF8));
        lblMiddleText->setText(QApplication::translate("EmbeddedKeysClass", "STORE", 0, QApplication::UnicodeUTF8));
        butClose->setText(QApplication::translate("EmbeddedKeysClass", "Close", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("EmbeddedKeysClass", "PRIMARY KEY:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class EmbeddedKeysClass: public Ui_EmbeddedKeysClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMBEDDEDKEYS_H
