/********************************************************************************
** Form generated from reading UI file 'mutlipewavedialog.ui'
**
** Created: Sat Oct 25 11:32:04 2014
**      by: Qt User Interface Compiler version 4.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MUTLIPEWAVEDIALOG_H
#define UI_MUTLIPEWAVEDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSplitter>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MutlipeWaveDialogClass
{
public:
    QSplitter *butSplitter;
    QPushButton *butPass;
    QPushButton *butFail;
    QPushButton *butALL;
    QPushButton *butPrev;
    QPushButton *butNext;
    QPushButton *objClose;
    QSplitter *butSplitter_2;
    QPushButton *butPass_2;
    QPushButton *butFail_2;
    QPushButton *butALL_2;
    QPushButton *butPrev_2;
    QPushButton *butNext_2;
    QPushButton *objClose_2;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *lblPinComb;
    QLabel *lblCombinations;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lblPinComb_2;
    QLabel *lblCurrenttoTotal;

    void setupUi(QDialog *MutlipeWaveDialogClass)
    {
        if (MutlipeWaveDialogClass->objectName().isEmpty())
            MutlipeWaveDialogClass->setObjectName(QString::fromUtf8("MutlipeWaveDialogClass"));
        MutlipeWaveDialogClass->resize(578, 450);
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
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush6);
        MutlipeWaveDialogClass->setPalette(palette);
        butSplitter = new QSplitter(MutlipeWaveDialogClass);
        butSplitter->setObjectName(QString::fromUtf8("butSplitter"));
        butSplitter->setGeometry(QRect(714, 280, 81, 211));
        butSplitter->setOrientation(Qt::Vertical);
        butPass = new QPushButton(butSplitter);
        butPass->setObjectName(QString::fromUtf8("butPass"));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        QLinearGradient gradient(0, 1, 1, 0);
        gradient.setSpread(QGradient::PadSpread);
        gradient.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient.setColorAt(0, QColor(26, 116, 219, 255));
        gradient.setColorAt(0.6, QColor(82, 147, 222, 255));
        gradient.setColorAt(1, QColor(255, 255, 255, 255));
        QBrush brush8(gradient);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush8);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        QLinearGradient gradient1(0, 1, 1, 0);
        gradient1.setSpread(QGradient::PadSpread);
        gradient1.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient1.setColorAt(0, QColor(26, 116, 219, 255));
        gradient1.setColorAt(0.6, QColor(82, 147, 222, 255));
        gradient1.setColorAt(1, QColor(255, 255, 255, 255));
        QBrush brush9(gradient1);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush9);
        QLinearGradient gradient2(0, 1, 1, 0);
        gradient2.setSpread(QGradient::PadSpread);
        gradient2.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient2.setColorAt(0, QColor(26, 116, 219, 255));
        gradient2.setColorAt(0.6, QColor(82, 147, 222, 255));
        gradient2.setColorAt(1, QColor(255, 255, 255, 255));
        QBrush brush10(gradient2);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush10);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        QLinearGradient gradient3(0, 1, 1, 0);
        gradient3.setSpread(QGradient::PadSpread);
        gradient3.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient3.setColorAt(0, QColor(26, 116, 219, 255));
        gradient3.setColorAt(0.6, QColor(82, 147, 222, 255));
        gradient3.setColorAt(1, QColor(255, 255, 255, 255));
        QBrush brush11(gradient3);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush11);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        QLinearGradient gradient4(0, 1, 1, 0);
        gradient4.setSpread(QGradient::PadSpread);
        gradient4.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient4.setColorAt(0, QColor(26, 116, 219, 255));
        gradient4.setColorAt(0.6, QColor(82, 147, 222, 255));
        gradient4.setColorAt(1, QColor(255, 255, 255, 255));
        QBrush brush12(gradient4);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush12);
        QLinearGradient gradient5(0, 1, 1, 0);
        gradient5.setSpread(QGradient::PadSpread);
        gradient5.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient5.setColorAt(0, QColor(26, 116, 219, 255));
        gradient5.setColorAt(0.6, QColor(82, 147, 222, 255));
        gradient5.setColorAt(1, QColor(255, 255, 255, 255));
        QBrush brush13(gradient5);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush13);
        QBrush brush14(QColor(211, 211, 211, 255));
        brush14.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush14);
        QBrush brush15(QColor(128, 128, 128, 255));
        brush15.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush15);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush14);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush14);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush15);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush15);
        butPass->setPalette(palette1);
        QFont font;
        font.setFamily(QString::fromUtf8("DejaVu Sans"));
        font.setPointSize(16);
        butPass->setFont(font);
        butPass->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color:black;\n"
"border: 1px solid #2D5059;\n"
"border-radius: 20px;\n"
"background-color: qlineargradient(x1: 0, y1: 1, x2: 1, y2: 0,\n"
"stop: 0 #1A74DB, stop: 0.6 #5293DE, stop:1 #FFFFFF);\n"
"min-width: 80px;\n"
"}\n"
"QPushButton:pressed {\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}\n"
"QPushButton:flat {\n"
"border: none; \n"
"}\n"
"QPushButton:disabled\n"
"{\n"
"color:lightgrey;\n"
"background-color:grey\n"
"}\n"
"QPushButton:default {\n"
"border-color: navy; \n"
"}"));
        butSplitter->addWidget(butPass);
        butFail = new QPushButton(butSplitter);
        butFail->setObjectName(QString::fromUtf8("butFail"));
        butFail->setFont(font);
        butFail->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color:black;\n"
"border: 1px solid #2D5059;\n"
"border-radius: 20px;\n"
"background-color: qlineargradient(x1: 0, y1: 1, x2: 1, y2: 0,\n"
"stop: 0 #1A74DB, stop: 0.6 #5293DE, stop:1 #FFFFFF);\n"
"min-width: 80px;\n"
"}\n"
"QPushButton:pressed {\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}\n"
"QPushButton:disabled\n"
"{\n"
"color:lightgrey;\n"
"background-color:grey\n"
"}\n"
"QPushButton:flat {\n"
"border: none; \n"
"}\n"
"QPushButton:default {\n"
"border-color: navy; \n"
"}"));
        butSplitter->addWidget(butFail);
        butALL = new QPushButton(butSplitter);
        butALL->setObjectName(QString::fromUtf8("butALL"));
        butALL->setFont(font);
        butALL->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color:black;\n"
"border: 1px solid #2D5059;\n"
"border-radius: 20px;\n"
"background-color: qlineargradient(x1: 0, y1: 1, x2: 1, y2: 0,\n"
"stop: 0 #1A74DB, stop: 0.6 #5293DE, stop:1 #FFFFFF);\n"
"min-width: 80px;\n"
"}\n"
"QPushButton:pressed {\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}\n"
"QPushButton:flat {\n"
"border: none; \n"
"}\n"
"QPushButton:disabled\n"
"{\n"
"color:lightgrey;\n"
"background-color:grey\n"
"}\n"
"QPushButton:default {\n"
"border-color: navy; \n"
"}"));
        butSplitter->addWidget(butALL);
        butPrev = new QPushButton(MutlipeWaveDialogClass);
        butPrev->setObjectName(QString::fromUtf8("butPrev"));
        butPrev->setGeometry(QRect(530, 600, 84, 51));
        butPrev->setFont(font);
        butPrev->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        butNext = new QPushButton(MutlipeWaveDialogClass);
        butNext->setObjectName(QString::fromUtf8("butNext"));
        butNext->setGeometry(QRect(620, 600, 84, 51));
        butNext->setFont(font);
        butNext->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        objClose = new QPushButton(MutlipeWaveDialogClass);
        objClose->setObjectName(QString::fromUtf8("objClose"));
        objClose->setGeometry(QRect(710, 600, 84, 51));
        objClose->setFont(font);
        objClose->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        butSplitter_2 = new QSplitter(MutlipeWaveDialogClass);
        butSplitter_2->setObjectName(QString::fromUtf8("butSplitter_2"));
        butSplitter_2->setGeometry(QRect(484, 70, 81, 211));
        butSplitter_2->setOrientation(Qt::Vertical);
        butPass_2 = new QPushButton(butSplitter_2);
        butPass_2->setObjectName(QString::fromUtf8("butPass_2"));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        QLinearGradient gradient6(0, 1, 1, 0);
        gradient6.setSpread(QGradient::PadSpread);
        gradient6.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient6.setColorAt(0, QColor(26, 116, 219, 255));
        gradient6.setColorAt(0.6, QColor(82, 147, 222, 255));
        gradient6.setColorAt(1, QColor(255, 255, 255, 255));
        QBrush brush16(gradient6);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush16);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        QLinearGradient gradient7(0, 1, 1, 0);
        gradient7.setSpread(QGradient::PadSpread);
        gradient7.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient7.setColorAt(0, QColor(26, 116, 219, 255));
        gradient7.setColorAt(0.6, QColor(82, 147, 222, 255));
        gradient7.setColorAt(1, QColor(255, 255, 255, 255));
        QBrush brush17(gradient7);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush17);
        QLinearGradient gradient8(0, 1, 1, 0);
        gradient8.setSpread(QGradient::PadSpread);
        gradient8.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient8.setColorAt(0, QColor(26, 116, 219, 255));
        gradient8.setColorAt(0.6, QColor(82, 147, 222, 255));
        gradient8.setColorAt(1, QColor(255, 255, 255, 255));
        QBrush brush18(gradient8);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush18);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        QLinearGradient gradient9(0, 1, 1, 0);
        gradient9.setSpread(QGradient::PadSpread);
        gradient9.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient9.setColorAt(0, QColor(26, 116, 219, 255));
        gradient9.setColorAt(0.6, QColor(82, 147, 222, 255));
        gradient9.setColorAt(1, QColor(255, 255, 255, 255));
        QBrush brush19(gradient9);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush19);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        QLinearGradient gradient10(0, 1, 1, 0);
        gradient10.setSpread(QGradient::PadSpread);
        gradient10.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient10.setColorAt(0, QColor(26, 116, 219, 255));
        gradient10.setColorAt(0.6, QColor(82, 147, 222, 255));
        gradient10.setColorAt(1, QColor(255, 255, 255, 255));
        QBrush brush20(gradient10);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush20);
        QLinearGradient gradient11(0, 1, 1, 0);
        gradient11.setSpread(QGradient::PadSpread);
        gradient11.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient11.setColorAt(0, QColor(26, 116, 219, 255));
        gradient11.setColorAt(0.6, QColor(82, 147, 222, 255));
        gradient11.setColorAt(1, QColor(255, 255, 255, 255));
        QBrush brush21(gradient11);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush21);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush14);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush15);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush14);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush14);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush15);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush15);
        butPass_2->setPalette(palette2);
        butPass_2->setFont(font);
        butPass_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color:black;\n"
"border: 1px solid #2D5059;\n"
"border-radius: 20px;\n"
"background-color: qlineargradient(x1: 0, y1: 1, x2: 1, y2: 0,\n"
"stop: 0 #1A74DB, stop: 0.6 #5293DE, stop:1 #FFFFFF);\n"
"min-width: 80px;\n"
"}\n"
"QPushButton:pressed {\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}\n"
"QPushButton:flat {\n"
"border: none; \n"
"}\n"
"QPushButton:disabled\n"
"{\n"
"color:lightgrey;\n"
"background-color:grey\n"
"}\n"
"QPushButton:default {\n"
"border-color: navy; \n"
"}"));
        butSplitter_2->addWidget(butPass_2);
        butFail_2 = new QPushButton(butSplitter_2);
        butFail_2->setObjectName(QString::fromUtf8("butFail_2"));
        butFail_2->setFont(font);
        butFail_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color:black;\n"
"border: 1px solid #2D5059;\n"
"border-radius: 20px;\n"
"background-color: qlineargradient(x1: 0, y1: 1, x2: 1, y2: 0,\n"
"stop: 0 #1A74DB, stop: 0.6 #5293DE, stop:1 #FFFFFF);\n"
"min-width: 80px;\n"
"}\n"
"QPushButton:pressed {\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}\n"
"QPushButton:disabled\n"
"{\n"
"color:lightgrey;\n"
"background-color:grey\n"
"}\n"
"QPushButton:flat {\n"
"border: none; \n"
"}\n"
"QPushButton:default {\n"
"border-color: navy; \n"
"}"));
        butSplitter_2->addWidget(butFail_2);
        butALL_2 = new QPushButton(butSplitter_2);
        butALL_2->setObjectName(QString::fromUtf8("butALL_2"));
        butALL_2->setFont(font);
        butALL_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color:black;\n"
"border: 1px solid #2D5059;\n"
"border-radius: 20px;\n"
"background-color: qlineargradient(x1: 0, y1: 1, x2: 1, y2: 0,\n"
"stop: 0 #1A74DB, stop: 0.6 #5293DE, stop:1 #FFFFFF);\n"
"min-width: 80px;\n"
"}\n"
"QPushButton:pressed {\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}\n"
"QPushButton:flat {\n"
"border: none; \n"
"}\n"
"QPushButton:disabled\n"
"{\n"
"color:lightgrey;\n"
"background-color:grey\n"
"}\n"
"QPushButton:default {\n"
"border-color: navy; \n"
"}"));
        butSplitter_2->addWidget(butALL_2);
        butPrev_2 = new QPushButton(MutlipeWaveDialogClass);
        butPrev_2->setObjectName(QString::fromUtf8("butPrev_2"));
        butPrev_2->setGeometry(QRect(300, 390, 84, 51));
        butPrev_2->setFont(font);
        butPrev_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        butNext_2 = new QPushButton(MutlipeWaveDialogClass);
        butNext_2->setObjectName(QString::fromUtf8("butNext_2"));
        butNext_2->setGeometry(QRect(390, 390, 84, 51));
        butNext_2->setFont(font);
        butNext_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        objClose_2 = new QPushButton(MutlipeWaveDialogClass);
        objClose_2->setObjectName(QString::fromUtf8("objClose_2"));
        objClose_2->setGeometry(QRect(480, 390, 84, 51));
        objClose_2->setFont(font);
        objClose_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        layoutWidget = new QWidget(MutlipeWaveDialogClass);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 360, 251, 41));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        lblPinComb = new QLabel(layoutWidget);
        lblPinComb->setObjectName(QString::fromUtf8("lblPinComb"));
        QPalette palette3;
        QBrush brush22(QColor(0, 170, 255, 255));
        brush22.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush22);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush22);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        lblPinComb->setPalette(palette3);
        QFont font1;
        font1.setFamily(QString::fromUtf8("DejaVu Sans"));
        font1.setPointSize(16);
        font1.setBold(false);
        font1.setWeight(50);
        lblPinComb->setFont(font1);

        horizontalLayout->addWidget(lblPinComb);

        lblCombinations = new QLabel(layoutWidget);
        lblCombinations->setObjectName(QString::fromUtf8("lblCombinations"));
        QPalette palette4;
        QBrush brush23(QColor(255, 255, 0, 255));
        brush23.setStyle(Qt::SolidPattern);
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush23);
        QBrush brush24(QColor(85, 255, 255, 255));
        brush24.setStyle(Qt::SolidPattern);
        palette4.setBrush(QPalette::Active, QPalette::Text, brush24);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush23);
        palette4.setBrush(QPalette::Inactive, QPalette::Text, brush24);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette4.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        lblCombinations->setPalette(palette4);
        QFont font2;
        font2.setFamily(QString::fromUtf8("DejaVu Sans"));
        font2.setPointSize(16);
        font2.setBold(true);
        font2.setWeight(75);
        lblCombinations->setFont(font2);

        horizontalLayout->addWidget(lblCombinations);

        layoutWidget_2 = new QWidget(MutlipeWaveDialogClass);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(2, 400, 249, 45));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        lblPinComb_2 = new QLabel(layoutWidget_2);
        lblPinComb_2->setObjectName(QString::fromUtf8("lblPinComb_2"));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::Text, brush24);
        QBrush brush25(QColor(85, 170, 255, 255));
        brush25.setStyle(Qt::SolidPattern);
        palette5.setBrush(QPalette::Active, QPalette::BrightText, brush25);
        palette5.setBrush(QPalette::Active, QPalette::ButtonText, brush24);
        palette5.setBrush(QPalette::Inactive, QPalette::Text, brush24);
        palette5.setBrush(QPalette::Inactive, QPalette::BrightText, brush25);
        palette5.setBrush(QPalette::Inactive, QPalette::ButtonText, brush24);
        palette5.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette5.setBrush(QPalette::Disabled, QPalette::BrightText, brush25);
        palette5.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        lblPinComb_2->setPalette(palette5);
        lblPinComb_2->setFont(font1);

        horizontalLayout_2->addWidget(lblPinComb_2);

        lblCurrenttoTotal = new QLabel(layoutWidget_2);
        lblCurrenttoTotal->setObjectName(QString::fromUtf8("lblCurrenttoTotal"));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::WindowText, brush23);
        palette6.setBrush(QPalette::Active, QPalette::Text, brush24);
        palette6.setBrush(QPalette::Active, QPalette::BrightText, brush25);
        palette6.setBrush(QPalette::Active, QPalette::ButtonText, brush24);
        palette6.setBrush(QPalette::Inactive, QPalette::WindowText, brush23);
        palette6.setBrush(QPalette::Inactive, QPalette::Text, brush24);
        palette6.setBrush(QPalette::Inactive, QPalette::BrightText, brush25);
        palette6.setBrush(QPalette::Inactive, QPalette::ButtonText, brush24);
        palette6.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette6.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette6.setBrush(QPalette::Disabled, QPalette::BrightText, brush25);
        palette6.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        lblCurrenttoTotal->setPalette(palette6);
        lblCurrenttoTotal->setFont(font2);

        horizontalLayout_2->addWidget(lblCurrenttoTotal);


        retranslateUi(MutlipeWaveDialogClass);

        QMetaObject::connectSlotsByName(MutlipeWaveDialogClass);
    } // setupUi

    void retranslateUi(QDialog *MutlipeWaveDialogClass)
    {
        MutlipeWaveDialogClass->setWindowTitle(QApplication::translate("MutlipeWaveDialogClass", "MutlipeWaveDialog", 0, QApplication::UnicodeUTF8));
        butPass->setText(QApplication::translate("MutlipeWaveDialogClass", "Pass", 0, QApplication::UnicodeUTF8));
        butFail->setText(QApplication::translate("MutlipeWaveDialogClass", "Fail", 0, QApplication::UnicodeUTF8));
        butALL->setText(QApplication::translate("MutlipeWaveDialogClass", "All", 0, QApplication::UnicodeUTF8));
        butPrev->setText(QApplication::translate("MutlipeWaveDialogClass", "Prev", 0, QApplication::UnicodeUTF8));
        butNext->setText(QApplication::translate("MutlipeWaveDialogClass", "Next", 0, QApplication::UnicodeUTF8));
        objClose->setText(QApplication::translate("MutlipeWaveDialogClass", "Close", 0, QApplication::UnicodeUTF8));
        butPass_2->setText(QApplication::translate("MutlipeWaveDialogClass", "Pass", 0, QApplication::UnicodeUTF8));
        butFail_2->setText(QApplication::translate("MutlipeWaveDialogClass", "Fail", 0, QApplication::UnicodeUTF8));
        butALL_2->setText(QApplication::translate("MutlipeWaveDialogClass", "All", 0, QApplication::UnicodeUTF8));
        butPrev_2->setText(QApplication::translate("MutlipeWaveDialogClass", "Prev", 0, QApplication::UnicodeUTF8));
        butNext_2->setText(QApplication::translate("MutlipeWaveDialogClass", "Next", 0, QApplication::UnicodeUTF8));
        objClose_2->setText(QApplication::translate("MutlipeWaveDialogClass", "Close", 0, QApplication::UnicodeUTF8));
        lblPinComb->setText(QApplication::translate("MutlipeWaveDialogClass", "No of Combinations:", 0, QApplication::UnicodeUTF8));
        lblCombinations->setText(QString());
        lblPinComb_2->setText(QApplication::translate("MutlipeWaveDialogClass", "Combinations:", 0, QApplication::UnicodeUTF8));
        lblCurrenttoTotal->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MutlipeWaveDialogClass: public Ui_MutlipeWaveDialogClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MUTLIPEWAVEDIALOG_H
