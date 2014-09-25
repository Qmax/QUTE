/********************************************************************************
** Form generated from reading UI file 'wavedata.ui'
**
** Created: Thu Sep 25 16:58:32 2014
**      by: Qt User Interface Compiler version 4.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WAVEDATA_H
#define UI_WAVEDATA_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_WaveData
{
public:
    QPushButton *pb_Ok;
    QPushButton *pb_Cancel;
    QLabel *lbl_Samples;
    QLabel *lbl_StartTick;
    QLabel *lbl_Endtick;
    QLabel *lbl_DutyCycles;
    QLineEdit *le_Samples;
    QLineEdit *le_StartTick;
    QLineEdit *le_EndTick;
    QLineEdit *le_DutyCycle;
    QLabel *lbl_Title;

    void setupUi(QDialog *WaveData)
    {
        if (WaveData->objectName().isEmpty())
            WaveData->setObjectName(QString::fromUtf8("WaveData"));
        WaveData->resize(240, 250);
        WaveData->setStyleSheet(QString::fromUtf8("QDialog{border:1px solid black; background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #ffffff, stop: 1 #dadbff);border-radius:10px;}\n"
""));
        pb_Ok = new QPushButton(WaveData);
        pb_Ok->setObjectName(QString::fromUtf8("pb_Ok"));
        pb_Ok->setGeometry(QRect(70, 210, 70, 30));
        pb_Ok->setFocusPolicy(Qt::NoFocus);
        pb_Ok->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color:white;\n"
"border: 1px solid #2D5059;\n"
"border-radius: 15px;\n"
"background-color: qlineargradient(x1: 0, y1: 1, x2: 1, y2: 0,stop: 0 #000000, stop: 0.6 #292929 , stop:1 #FFFFFF);\n"
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
"}\n"
""));
        pb_Cancel = new QPushButton(WaveData);
        pb_Cancel->setObjectName(QString::fromUtf8("pb_Cancel"));
        pb_Cancel->setGeometry(QRect(150, 210, 70, 30));
        pb_Cancel->setFocusPolicy(Qt::NoFocus);
        pb_Cancel->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color:white;\n"
"border: 1px solid #2D5059;\n"
"border-radius: 15px;\n"
"background-color: qlineargradient(x1: 0, y1: 1, x2: 1, y2: 0,stop: 0 #000000, stop: 0.6 #292929 , stop:1 #FFFFFF);\n"
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
"}\n"
""));
        lbl_Samples = new QLabel(WaveData);
        lbl_Samples->setObjectName(QString::fromUtf8("lbl_Samples"));
        lbl_Samples->setGeometry(QRect(10, 50, 110, 20));
        QFont font;
        font.setFamily(QString::fromUtf8("DejaVu Sans"));
        font.setPointSize(12);
        font.setBold(false);
        font.setWeight(50);
        lbl_Samples->setFont(font);
        lbl_Samples->setStyleSheet(QString::fromUtf8("color: rgba(0,0,0,255);border: rgba(0,0,0,0);border-radius: 3px;background-color: rgba(0, 0, 0,0);qproperty-wordWrap: true;"));
        lbl_Samples->setFrameShape(QFrame::StyledPanel);
        lbl_StartTick = new QLabel(WaveData);
        lbl_StartTick->setObjectName(QString::fromUtf8("lbl_StartTick"));
        lbl_StartTick->setGeometry(QRect(10, 90, 110, 20));
        lbl_StartTick->setFont(font);
        lbl_StartTick->setStyleSheet(QString::fromUtf8("color: rgba(0,0,0,255);border: rgba(0,0,0,0);border-radius: 3px;background-color: rgba(0, 0, 0,0);qproperty-wordWrap: true;"));
        lbl_StartTick->setFrameShape(QFrame::StyledPanel);
        lbl_Endtick = new QLabel(WaveData);
        lbl_Endtick->setObjectName(QString::fromUtf8("lbl_Endtick"));
        lbl_Endtick->setGeometry(QRect(10, 130, 110, 20));
        lbl_Endtick->setFont(font);
        lbl_Endtick->setStyleSheet(QString::fromUtf8("color: rgba(0,0,0,255);border: rgba(0,0,0,0);border-radius: 3px;background-color: rgba(0, 0, 0,0);qproperty-wordWrap: true;"));
        lbl_Endtick->setFrameShape(QFrame::StyledPanel);
        lbl_DutyCycles = new QLabel(WaveData);
        lbl_DutyCycles->setObjectName(QString::fromUtf8("lbl_DutyCycles"));
        lbl_DutyCycles->setGeometry(QRect(10, 170, 110, 20));
        lbl_DutyCycles->setFont(font);
        lbl_DutyCycles->setStyleSheet(QString::fromUtf8("color: rgba(0,0,0,255);border: rgba(0,0,0,0);border-radius: 3px;background-color: rgba(0, 0, 0,0);qproperty-wordWrap: true;"));
        lbl_DutyCycles->setFrameShape(QFrame::StyledPanel);
        le_Samples = new QLineEdit(WaveData);
        le_Samples->setObjectName(QString::fromUtf8("le_Samples"));
        le_Samples->setGeometry(QRect(110, 45, 113, 30));
        le_StartTick = new QLineEdit(WaveData);
        le_StartTick->setObjectName(QString::fromUtf8("le_StartTick"));
        le_StartTick->setGeometry(QRect(110, 85, 113, 30));
        le_EndTick = new QLineEdit(WaveData);
        le_EndTick->setObjectName(QString::fromUtf8("le_EndTick"));
        le_EndTick->setGeometry(QRect(110, 125, 113, 30));
        le_DutyCycle = new QLineEdit(WaveData);
        le_DutyCycle->setObjectName(QString::fromUtf8("le_DutyCycle"));
        le_DutyCycle->setGeometry(QRect(110, 165, 113, 30));
        lbl_Title = new QLabel(WaveData);
        lbl_Title->setObjectName(QString::fromUtf8("lbl_Title"));
        lbl_Title->setGeometry(QRect(4, 4, 232, 28));
        QFont font1;
        font1.setFamily(QString::fromUtf8("DejaVu Sans"));
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        lbl_Title->setFont(font1);
        lbl_Title->setStyleSheet(QString::fromUtf8("     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #3a5976, stop: 1 #000000);color:white;border-radius:10px;"));
        lbl_Title->setFrameShape(QFrame::StyledPanel);
        lbl_Title->setAlignment(Qt::AlignCenter);

        retranslateUi(WaveData);

        QMetaObject::connectSlotsByName(WaveData);
    } // setupUi

    void retranslateUi(QDialog *WaveData)
    {
        WaveData->setWindowTitle(QApplication::translate("WaveData", "Dialog", 0, QApplication::UnicodeUTF8));
        pb_Ok->setText(QApplication::translate("WaveData", "OK", 0, QApplication::UnicodeUTF8));
        pb_Cancel->setText(QApplication::translate("WaveData", "Cancel", 0, QApplication::UnicodeUTF8));
        lbl_Samples->setText(QApplication::translate("WaveData", "Samples :", 0, QApplication::UnicodeUTF8));
        lbl_StartTick->setText(QApplication::translate("WaveData", "Start Tick:", 0, QApplication::UnicodeUTF8));
        lbl_Endtick->setText(QApplication::translate("WaveData", "End Tick:", 0, QApplication::UnicodeUTF8));
        lbl_DutyCycles->setText(QApplication::translate("WaveData", "Duty Cycle:", 0, QApplication::UnicodeUTF8));
        lbl_Title->setText(QApplication::translate("WaveData", "Wave Settings", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class WaveData: public Ui_WaveData {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WAVEDATA_H
