/********************************************************************************
** Form generated from reading UI file 'adchighspeed.ui'
**
** Created: Tue Sep 9 12:03:46 2014
**      by: Qt User Interface Compiler version 4.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADCHIGHSPEED_H
#define UI_ADCHIGHSPEED_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ADCHighSpeed
{
public:
    QPushButton *readCodeID;
    QLineEdit *codeID;
    QLabel *AppCardID;
    QLineEdit *appCardCodeID;
    QLineEdit *version;
    QPushButton *readVersion;
    QPushButton *readVersion_2;
    QPushButton *readVersion_3;

    void setupUi(QWidget *ADCHighSpeed)
    {
        if (ADCHighSpeed->objectName().isEmpty())
            ADCHighSpeed->setObjectName(QString::fromUtf8("ADCHighSpeed"));
        ADCHighSpeed->resize(600, 400);
        readCodeID = new QPushButton(ADCHighSpeed);
        readCodeID->setObjectName(QString::fromUtf8("readCodeID"));
        readCodeID->setGeometry(QRect(180, 80, 100, 30));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        readCodeID->setFont(font);
        readCodeID->setFocusPolicy(Qt::NoFocus);
        readCodeID->setStyleSheet(QString::fromUtf8("QPushButton { color:white; border: 1px solid #2D5059; border-radius: 15px; background-color: qlineargradient(x1: 0, y1: 1, x2: 1, y2: 0,stop: 0 #1A74DB, stop: 0.6 #5293DE, stop:1 #FFFFFF); min-width: 80px; } QPushButton:pressed { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #dadbde, stop: 1 #f6f7fa); } QPushButton:flat { border: none; } QPushButton:default { border-color: navy; } "));
        codeID = new QLineEdit(ADCHighSpeed);
        codeID->setObjectName(QString::fromUtf8("codeID"));
        codeID->setGeometry(QRect(50, 80, 100, 30));
        codeID->setFont(font);
        codeID->setFocusPolicy(Qt::NoFocus);
        codeID->setStyleSheet(QString::fromUtf8("border:1px solid gray;\n"
"border-radius:3px;"));
        AppCardID = new QLabel(ADCHighSpeed);
        AppCardID->setObjectName(QString::fromUtf8("AppCardID"));
        AppCardID->setGeometry(QRect(50, 40, 100, 30));
        AppCardID->setFont(font);
        AppCardID->setFocusPolicy(Qt::NoFocus);
        AppCardID->setStyleSheet(QString::fromUtf8("border-radius:3px;"));
        appCardCodeID = new QLineEdit(ADCHighSpeed);
        appCardCodeID->setObjectName(QString::fromUtf8("appCardCodeID"));
        appCardCodeID->setGeometry(QRect(180, 40, 100, 30));
        appCardCodeID->setFont(font);
        appCardCodeID->setFocusPolicy(Qt::NoFocus);
        appCardCodeID->setStyleSheet(QString::fromUtf8("border:1px solid gray;\n"
"border-radius:3px;"));
        version = new QLineEdit(ADCHighSpeed);
        version->setObjectName(QString::fromUtf8("version"));
        version->setGeometry(QRect(50, 130, 100, 30));
        version->setFont(font);
        version->setFocusPolicy(Qt::NoFocus);
        version->setStyleSheet(QString::fromUtf8("border:1px solid gray;\n"
"border-radius:3px;"));
        readVersion = new QPushButton(ADCHighSpeed);
        readVersion->setObjectName(QString::fromUtf8("readVersion"));
        readVersion->setGeometry(QRect(180, 130, 100, 30));
        readVersion->setFont(font);
        readVersion->setFocusPolicy(Qt::NoFocus);
        readVersion->setStyleSheet(QString::fromUtf8("QPushButton { color:white; border: 1px solid #2D5059; border-radius: 15px; background-color: qlineargradient(x1: 0, y1: 1, x2: 1, y2: 0,stop: 0 #1A74DB, stop: 0.6 #5293DE, stop:1 #FFFFFF); min-width: 80px; } QPushButton:pressed { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #dadbde, stop: 1 #f6f7fa); } QPushButton:flat { border: none; } QPushButton:default { border-color: navy; } "));
        readVersion_2 = new QPushButton(ADCHighSpeed);
        readVersion_2->setObjectName(QString::fromUtf8("readVersion_2"));
        readVersion_2->setGeometry(QRect(170, 220, 100, 30));
        readVersion_2->setFont(font);
        readVersion_2->setFocusPolicy(Qt::NoFocus);
        readVersion_2->setStyleSheet(QString::fromUtf8("QPushButton { color:white; border: 1px solid #2D5059; border-radius: 15px; background-color: qlineargradient(x1: 0, y1: 1, x2: 1, y2: 0,stop: 0 #1A74DB, stop: 0.6 #5293DE, stop:1 #FFFFFF); min-width: 80px; } QPushButton:pressed { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #dadbde, stop: 1 #f6f7fa); } QPushButton:flat { border: none; } QPushButton:default { border-color: navy; } "));
        readVersion_3 = new QPushButton(ADCHighSpeed);
        readVersion_3->setObjectName(QString::fromUtf8("readVersion_3"));
        readVersion_3->setGeometry(QRect(170, 280, 100, 30));
        readVersion_3->setFont(font);
        readVersion_3->setFocusPolicy(Qt::NoFocus);
        readVersion_3->setStyleSheet(QString::fromUtf8("QPushButton { color:white; border: 1px solid #2D5059; border-radius: 15px; background-color: qlineargradient(x1: 0, y1: 1, x2: 1, y2: 0,stop: 0 #1A74DB, stop: 0.6 #5293DE, stop:1 #FFFFFF); min-width: 80px; } QPushButton:pressed { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #dadbde, stop: 1 #f6f7fa); } QPushButton:flat { border: none; } QPushButton:default { border-color: navy; } "));

        retranslateUi(ADCHighSpeed);

        QMetaObject::connectSlotsByName(ADCHighSpeed);
    } // setupUi

    void retranslateUi(QWidget *ADCHighSpeed)
    {
        ADCHighSpeed->setWindowTitle(QApplication::translate("ADCHighSpeed", "ADCHighSpeed", 0, QApplication::UnicodeUTF8));
        readCodeID->setText(QApplication::translate("ADCHighSpeed", "Read CodeID", 0, QApplication::UnicodeUTF8));
        AppCardID->setText(QApplication::translate("ADCHighSpeed", "Appcard Code ID : ", 0, QApplication::UnicodeUTF8));
        readVersion->setText(QApplication::translate("ADCHighSpeed", "Read Version", 0, QApplication::UnicodeUTF8));
        readVersion_2->setText(QApplication::translate("ADCHighSpeed", "Read", 0, QApplication::UnicodeUTF8));
        readVersion_3->setText(QApplication::translate("ADCHighSpeed", "4-Wire Mode", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ADCHighSpeed: public Ui_ADCHighSpeed {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADCHIGHSPEED_H
