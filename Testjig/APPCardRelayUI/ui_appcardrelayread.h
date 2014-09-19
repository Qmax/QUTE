/********************************************************************************
** Form generated from reading UI file 'appcardrelayread.ui'
**
** Created: Sat May 11 11:53:25 2013
**      by: Qt User Interface Compiler version 4.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APPCARDRELAYREAD_H
#define UI_APPCARDRELAYREAD_H

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

class Ui_AppCardRelayRead
{
public:
    QGroupBox *grpdrvRelays;
    QGroupBox *grpReceRly;
    QGroupBox *grpICMVIRly;
    QPushButton *butReadRelay;
    QGroupBox *groupBox_3;
    QLineEdit *objADDR;
    QLabel *label_28;
    QLabel *label_29;
    QLineEdit *objDATA;
    QPushButton *butWrite;
    QPushButton *butREAD;

    void setupUi(QWidget *AppCardRelayRead)
    {
        if (AppCardRelayRead->objectName().isEmpty())
            AppCardRelayRead->setObjectName(QString::fromUtf8("AppCardRelayRead"));
        AppCardRelayRead->resize(800, 600);
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
        AppCardRelayRead->setPalette(palette);
        grpdrvRelays = new QGroupBox(AppCardRelayRead);
        grpdrvRelays->setObjectName(QString::fromUtf8("grpdrvRelays"));
        grpdrvRelays->setGeometry(QRect(20, 240, 381, 151));
        grpReceRly = new QGroupBox(AppCardRelayRead);
        grpReceRly->setObjectName(QString::fromUtf8("grpReceRly"));
        grpReceRly->setGeometry(QRect(20, 10, 381, 221));
        grpICMVIRly = new QGroupBox(AppCardRelayRead);
        grpICMVIRly->setObjectName(QString::fromUtf8("grpICMVIRly"));
        grpICMVIRly->setGeometry(QRect(410, 240, 381, 151));
        butReadRelay = new QPushButton(AppCardRelayRead);
        butReadRelay->setObjectName(QString::fromUtf8("butReadRelay"));
        butReadRelay->setGeometry(QRect(340, 410, 141, 51));
        groupBox_3 = new QGroupBox(AppCardRelayRead);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(460, 10, 291, 201));
        objADDR = new QLineEdit(groupBox_3);
        objADDR->setObjectName(QString::fromUtf8("objADDR"));
        objADDR->setGeometry(QRect(120, 20, 161, 51));
        label_28 = new QLabel(groupBox_3);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setGeometry(QRect(30, 30, 91, 41));
        label_29 = new QLabel(groupBox_3);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setGeometry(QRect(30, 90, 91, 41));
        objDATA = new QLineEdit(groupBox_3);
        objDATA->setObjectName(QString::fromUtf8("objDATA"));
        objDATA->setGeometry(QRect(120, 80, 161, 51));
        butWrite = new QPushButton(groupBox_3);
        butWrite->setObjectName(QString::fromUtf8("butWrite"));
        butWrite->setGeometry(QRect(160, 140, 93, 51));
        butREAD = new QPushButton(groupBox_3);
        butREAD->setObjectName(QString::fromUtf8("butREAD"));
        butREAD->setGeometry(QRect(40, 140, 93, 51));

        retranslateUi(AppCardRelayRead);

        QMetaObject::connectSlotsByName(AppCardRelayRead);
    } // setupUi

    void retranslateUi(QWidget *AppCardRelayRead)
    {
        AppCardRelayRead->setWindowTitle(QApplication::translate("AppCardRelayRead", "Form", 0, QApplication::UnicodeUTF8));
        grpdrvRelays->setTitle(QApplication::translate("AppCardRelayRead", "Drive Relay Status", 0, QApplication::UnicodeUTF8));
        grpReceRly->setTitle(QApplication::translate("AppCardRelayRead", "Receive Relay Status", 0, QApplication::UnicodeUTF8));
        grpICMVIRly->setTitle(QApplication::translate("AppCardRelayRead", "ICM/VI Piggy Relay Status", 0, QApplication::UnicodeUTF8));
        butReadRelay->setText(QApplication::translate("AppCardRelayRead", "Read Relay Status", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("AppCardRelayRead", "General", 0, QApplication::UnicodeUTF8));
        label_28->setText(QApplication::translate("AppCardRelayRead", "ADDRESS :", 0, QApplication::UnicodeUTF8));
        label_29->setText(QApplication::translate("AppCardRelayRead", "DATA:", 0, QApplication::UnicodeUTF8));
        butWrite->setText(QApplication::translate("AppCardRelayRead", "WRITE", 0, QApplication::UnicodeUTF8));
        butREAD->setText(QApplication::translate("AppCardRelayRead", "READ", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AppCardRelayRead: public Ui_AppCardRelayRead {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APPCARDRELAYREAD_H
