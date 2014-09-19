/********************************************************************************
** Form generated from reading UI file 'arbitary.ui'
**
** Created: Sat Sep 6 10:52:28 2014
**      by: Qt User Interface Compiler version 4.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ARBITARY_H
#define UI_ARBITARY_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Arbitary
{
public:
    QGroupBox *groupBox;
    QPushButton *userDefined;
    QPushButton *triangle;
    QPushButton *am;
    QPushButton *fm;
    QPushButton *square;
    QPushButton *ramp;
    QPushButton *pulse;
    QPushButton *sine;
    QPushButton *pm;
    QPushButton *dc;
    QPushButton *userDefined_2;
    QGroupBox *groupBox_2;
    QGroupBox *groupBox_3;
    QComboBox *cmbAmplitude;
    QComboBox *cmbFrequency;
    QLabel *lblLength;
    QDoubleSpinBox *spinFrequency;
    QSpinBox *spinLength;
    QLabel *lblFrequency;
    QLabel *lblAmplitude;
    QDoubleSpinBox *spinAmplitude;
    QDoubleSpinBox *spinOffset;
    QLabel *lblOffset;
    QLabel *label;

    void setupUi(QWidget *Arbitary)
    {
        if (Arbitary->objectName().isEmpty())
            Arbitary->setObjectName(QString::fromUtf8("Arbitary"));
        Arbitary->resize(800, 600);
        groupBox = new QGroupBox(Arbitary);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(1, 1, 798, 50));
        groupBox->setStyleSheet(QString::fromUtf8("QGroupBox{border:2px solid black;border-style: ridge;border-radius:5px;\n"
"background-color: rgba(100,100,100,100);}"));
        userDefined = new QPushButton(groupBox);
        userDefined->setObjectName(QString::fromUtf8("userDefined"));
        userDefined->setGeometry(QRect(450, 0, 50, 50));
        userDefined->setFocusPolicy(Qt::NoFocus);
        userDefined->setStyleSheet(QString::fromUtf8("QPushButton {border: 2px solid rgba(0,0,0,0); border-radius: 25px;  background-color: rgba(0,0,0,0); }\n"
" QPushButton:pressed {	background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #dadbde, stop: 1 #f6f7fa); }\n"
"   QPushButton:flat {border: none; }     QPushButton:default {border-color: navy;}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/awg.png"), QSize(), QIcon::Normal, QIcon::Off);
        userDefined->setIcon(icon);
        userDefined->setIconSize(QSize(42, 48));
        triangle = new QPushButton(groupBox);
        triangle->setObjectName(QString::fromUtf8("triangle"));
        triangle->setGeometry(QRect(150, 0, 50, 50));
        triangle->setFocusPolicy(Qt::NoFocus);
        triangle->setStyleSheet(QString::fromUtf8("QPushButton {border: 2px solid rgba(0,0,0,0); border-radius: 25px;  background-color: rgba(0,0,0,0); }\n"
" QPushButton:pressed {	background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #dadbde, stop: 1 #f6f7fa); }\n"
"   QPushButton:flat {border: none; }     QPushButton:default {border-color: navy;}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Triangle.png"), QSize(), QIcon::Normal, QIcon::Off);
        triangle->setIcon(icon1);
        triangle->setIconSize(QSize(40, 48));
        am = new QPushButton(groupBox);
        am->setObjectName(QString::fromUtf8("am"));
        am->setGeometry(QRect(300, 0, 50, 50));
        am->setFocusPolicy(Qt::NoFocus);
        am->setStyleSheet(QString::fromUtf8("QPushButton {border: 2px solid rgba(0,0,0,0); border-radius: 25px;  background-color: rgba(0,0,0,0); }\n"
" QPushButton:pressed {	background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #dadbde, stop: 1 #f6f7fa); }\n"
"   QPushButton:flat {border: none; }     QPushButton:default {border-color: navy;}"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Am.png"), QSize(), QIcon::Normal, QIcon::Off);
        am->setIcon(icon2);
        am->setIconSize(QSize(40, 48));
        fm = new QPushButton(groupBox);
        fm->setObjectName(QString::fromUtf8("fm"));
        fm->setGeometry(QRect(400, 0, 50, 50));
        fm->setFocusPolicy(Qt::NoFocus);
        fm->setStyleSheet(QString::fromUtf8("QPushButton {border: 2px solid rgba(0,0,0,0); border-radius: 25px;  background-color: rgba(0,0,0,0); }\n"
" QPushButton:pressed {	background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #dadbde, stop: 1 #f6f7fa); }\n"
"   QPushButton:flat {border: none; }     QPushButton:default {border-color: navy;}\n"
""));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/fm.png"), QSize(), QIcon::Normal, QIcon::Off);
        fm->setIcon(icon3);
        fm->setIconSize(QSize(40, 48));
        square = new QPushButton(groupBox);
        square->setObjectName(QString::fromUtf8("square"));
        square->setGeometry(QRect(50, 0, 50, 50));
        square->setFocusPolicy(Qt::NoFocus);
        square->setStyleSheet(QString::fromUtf8("QPushButton {border: 2px solid rgba(0,0,0,0); border-radius: 25px;  background-color: rgba(0,0,0,0); }\n"
" QPushButton:pressed {	background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #dadbde, stop: 1 #f6f7fa); }\n"
"   QPushButton:flat {border: none; }     QPushButton:default {border-color: navy;}\n"
""));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/square wave.png"), QSize(), QIcon::Normal, QIcon::Off);
        square->setIcon(icon4);
        square->setIconSize(QSize(40, 48));
        ramp = new QPushButton(groupBox);
        ramp->setObjectName(QString::fromUtf8("ramp"));
        ramp->setGeometry(QRect(100, 0, 50, 50));
        ramp->setFocusPolicy(Qt::NoFocus);
        ramp->setStyleSheet(QString::fromUtf8("QPushButton {border: 2px solid rgba(0,0,0,0); border-radius: 25px;  background-color: rgba(0,0,0,0); }\n"
" QPushButton:pressed {	background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #dadbde, stop: 1 #f6f7fa); }\n"
"   QPushButton:flat {border: none; }     QPushButton:default {border-color: navy;}"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/ramp.png"), QSize(), QIcon::Normal, QIcon::Off);
        ramp->setIcon(icon5);
        ramp->setIconSize(QSize(40, 48));
        pulse = new QPushButton(groupBox);
        pulse->setObjectName(QString::fromUtf8("pulse"));
        pulse->setGeometry(QRect(250, 0, 50, 50));
        pulse->setFocusPolicy(Qt::NoFocus);
        pulse->setStyleSheet(QString::fromUtf8("QPushButton {border: 2px solid rgba(0,0,0,0); border-radius: 25px;  background-color: rgba(0,0,0,0); }\n"
" QPushButton:pressed {	background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #dadbde, stop: 1 #f6f7fa); }\n"
"   QPushButton:flat {border: none; }     QPushButton:default {border-color: navy;}\n"
""));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/Pulse.png"), QSize(), QIcon::Normal, QIcon::Off);
        pulse->setIcon(icon6);
        pulse->setIconSize(QSize(40, 48));
        sine = new QPushButton(groupBox);
        sine->setObjectName(QString::fromUtf8("sine"));
        sine->setGeometry(QRect(0, 0, 50, 50));
        sine->setFocusPolicy(Qt::NoFocus);
        sine->setStyleSheet(QString::fromUtf8("QPushButton {border: 2px solid rgba(0,0,0,0); border-radius: 25px;  background-color: rgba(0,0,0,0); }\n"
" QPushButton:pressed {	background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #dadbde, stop: 1 #f6f7fa); }\n"
"   QPushButton:flat {border: none; }     QPushButton:default {border-color: navy;}"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/sinewave.png"), QSize(), QIcon::Normal, QIcon::Off);
        sine->setIcon(icon7);
        sine->setIconSize(QSize(40, 48));
        pm = new QPushButton(groupBox);
        pm->setObjectName(QString::fromUtf8("pm"));
        pm->setGeometry(QRect(350, 0, 50, 50));
        pm->setFocusPolicy(Qt::NoFocus);
        pm->setStyleSheet(QString::fromUtf8("QPushButton {border: 2px solid rgba(0,0,0,0); border-radius: 25px;  background-color: rgba(0,0,0,0); }\n"
" QPushButton:pressed {	background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #dadbde, stop: 1 #f6f7fa); }\n"
"   QPushButton:flat {border: none; }     QPushButton:default {border-color: navy;}"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/Pm.png"), QSize(), QIcon::Normal, QIcon::Off);
        pm->setIcon(icon8);
        pm->setIconSize(QSize(40, 48));
        dc = new QPushButton(groupBox);
        dc->setObjectName(QString::fromUtf8("dc"));
        dc->setGeometry(QRect(199, 0, 50, 50));
        dc->setFocusPolicy(Qt::NoFocus);
        dc->setStyleSheet(QString::fromUtf8("QPushButton {border: 2px solid rgba(0,0,0,0); border-radius: 25px;  background-color: rgba(0,0,0,0); }\n"
" QPushButton:pressed {	background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #dadbde, stop: 1 #f6f7fa); }\n"
"   QPushButton:flat {border: none; }     QPushButton:default {border-color: navy;}"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/vdc.png"), QSize(), QIcon::Normal, QIcon::Off);
        dc->setIcon(icon9);
        dc->setIconSize(QSize(42, 48));
        userDefined_2 = new QPushButton(groupBox);
        userDefined_2->setObjectName(QString::fromUtf8("userDefined_2"));
        userDefined_2->setGeometry(QRect(740, 0, 50, 50));
        userDefined_2->setFocusPolicy(Qt::NoFocus);
        userDefined_2->setStyleSheet(QString::fromUtf8("QPushButton {border: 2px solid rgba(0,0,0,0); border-radius: 25px;  background-color: rgba(0,0,0,0); }\n"
" QPushButton:pressed {	background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #dadbde, stop: 1 #f6f7fa); }\n"
"   QPushButton:flat {border: none; }     QPushButton:default {border-color: navy;}"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/Button-exit-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        userDefined_2->setIcon(icon10);
        userDefined_2->setIconSize(QSize(42, 48));
        groupBox_2 = new QGroupBox(Arbitary);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(1, 53, 798, 460));
        groupBox_2->setStyleSheet(QString::fromUtf8("QGroupBox{border:2px solid black;border-style: ridge;border-radius:5px;\n"
"background-color: rgba(100,100,100,100);}"));
        groupBox_3 = new QGroupBox(Arbitary);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(0, 515, 798, 83));
        groupBox_3->setStyleSheet(QString::fromUtf8("QGroupBox{border:2px solid black;border-style: ridge;border-radius:5px;\n"
"background-color: rgba(100,100,100,100);}"));
        cmbAmplitude = new QComboBox(groupBox_3);
        cmbAmplitude->setObjectName(QString::fromUtf8("cmbAmplitude"));
        cmbAmplitude->setGeometry(QRect(700, 11, 90, 23));
        cmbFrequency = new QComboBox(groupBox_3);
        cmbFrequency->setObjectName(QString::fromUtf8("cmbFrequency"));
        cmbFrequency->setGeometry(QRect(700, 50, 90, 23));
        lblLength = new QLabel(groupBox_3);
        lblLength->setObjectName(QString::fromUtf8("lblLength"));
        lblLength->setGeometry(QRect(18, 23, 70, 17));
        spinFrequency = new QDoubleSpinBox(groupBox_3);
        spinFrequency->setObjectName(QString::fromUtf8("spinFrequency"));
        spinFrequency->setGeometry(QRect(250, 20, 70, 23));
        spinFrequency->setMinimum(0.1);
        spinFrequency->setMaximum(10000);
        spinFrequency->setSingleStep(0.1);
        spinFrequency->setValue(1);
        spinLength = new QSpinBox(groupBox_3);
        spinLength->setObjectName(QString::fromUtf8("spinLength"));
        spinLength->setGeometry(QRect(70, 20, 90, 23));
        spinLength->setMaximum(4096);
        spinLength->setValue(4096);
        lblFrequency = new QLabel(groupBox_3);
        lblFrequency->setObjectName(QString::fromUtf8("lblFrequency"));
        lblFrequency->setGeometry(QRect(170, 22, 80, 17));
        lblAmplitude = new QLabel(groupBox_3);
        lblAmplitude->setObjectName(QString::fromUtf8("lblAmplitude"));
        lblAmplitude->setGeometry(QRect(360, 22, 80, 17));
        spinAmplitude = new QDoubleSpinBox(groupBox_3);
        spinAmplitude->setObjectName(QString::fromUtf8("spinAmplitude"));
        spinAmplitude->setGeometry(QRect(440, 19, 80, 23));
        spinAmplitude->setMinimum(0.1);
        spinAmplitude->setMaximum(20);
        spinAmplitude->setSingleStep(0.1);
        spinAmplitude->setValue(1);
        spinOffset = new QDoubleSpinBox(groupBox_3);
        spinOffset->setObjectName(QString::fromUtf8("spinOffset"));
        spinOffset->setGeometry(QRect(590, 20, 80, 23));
        spinOffset->setMaximum(5);
        spinOffset->setSingleStep(0.1);
        spinOffset->setValue(0);
        lblOffset = new QLabel(groupBox_3);
        lblOffset->setObjectName(QString::fromUtf8("lblOffset"));
        lblOffset->setGeometry(QRect(540, 23, 80, 17));
        label = new QLabel(groupBox_3);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(320, 22, 31, 20));

        retranslateUi(Arbitary);

        QMetaObject::connectSlotsByName(Arbitary);
    } // setupUi

    void retranslateUi(QWidget *Arbitary)
    {
        Arbitary->setWindowTitle(QApplication::translate("Arbitary", "Arbitary", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QString());
        userDefined->setText(QString());
        triangle->setText(QString());
        am->setText(QString());
        fm->setText(QString());
        square->setText(QString());
        ramp->setText(QString());
        pulse->setText(QString());
        sine->setText(QString());
        pm->setText(QString());
        dc->setText(QString());
        userDefined_2->setText(QString());
        groupBox_2->setTitle(QString());
        groupBox_3->setTitle(QString());
        cmbAmplitude->clear();
        cmbAmplitude->insertItems(0, QStringList()
         << QApplication::translate("Arbitary", "0.5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Arbitary", "1.5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Arbitary", "3.5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Arbitary", "7", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Arbitary", "13", 0, QApplication::UnicodeUTF8)
        );
        cmbFrequency->clear();
        cmbFrequency->insertItems(0, QStringList()
         << QApplication::translate("Arbitary", "10Hz", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Arbitary", "100Hz", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Arbitary", "1KHz", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Arbitary", "10KHz", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Arbitary", "100KHz", 0, QApplication::UnicodeUTF8)
        );
        lblLength->setText(QApplication::translate("Arbitary", "Length", 0, QApplication::UnicodeUTF8));
        lblFrequency->setText(QApplication::translate("Arbitary", "Frequency", 0, QApplication::UnicodeUTF8));
        lblAmplitude->setText(QApplication::translate("Arbitary", "Amplitude", 0, QApplication::UnicodeUTF8));
        lblOffset->setText(QApplication::translate("Arbitary", "Offset", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Arbitary", "KHz", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Arbitary: public Ui_Arbitary {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ARBITARY_H
