/********************************************************************************
** Form generated from reading UI file 'datetime.ui'
**
** Created: Tue Sep 23 10:02:47 2014
**      by: Qt User Interface Compiler version 4.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATETIME_H
#define UI_DATETIME_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCalendarWidget>
#include <QtGui/QDateTimeEdit>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DateTime
{
public:
    QCalendarWidget *calendarWidget;
    QPushButton *pb_exit;
    QDateTimeEdit *dateTimeEdit;
    QPushButton *pb_Apply;

    void setupUi(QWidget *DateTime)
    {
        if (DateTime->objectName().isEmpty())
            DateTime->setObjectName(QString::fromUtf8("DateTime"));
        DateTime->resize(400, 350);
        calendarWidget = new QCalendarWidget(DateTime);
        calendarWidget->setObjectName(QString::fromUtf8("calendarWidget"));
        calendarWidget->setGeometry(QRect(0, 0, 400, 239));
        QFont font;
        font.setFamily(QString::fromUtf8("DejaVu Sans"));
        font.setPointSize(12);
        calendarWidget->setFont(font);
        pb_exit = new QPushButton(DateTime);
        pb_exit->setObjectName(QString::fromUtf8("pb_exit"));
        pb_exit->setGeometry(QRect(230, 310, 100, 34));
        QFont font1;
        font1.setBold(true);
        font1.setItalic(false);
        font1.setWeight(75);
        pb_exit->setFont(font1);
        pb_exit->setFocusPolicy(Qt::NoFocus);
        pb_exit->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color:white;\n"
"border: 1px solid #2D5059;\n"
"border-radius: 10px;\n"
"background-color: qlineargradient(x1: 0, y1: 1, x2: 1, y2: 0,stop: 0 #000000, stop: 0.6 #292929 , stop:1 #FFFFFF);\n"
"font:bold 14px;\n"
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
        pb_exit->setIconSize(QSize(65, 40));
        dateTimeEdit = new QDateTimeEdit(DateTime);
        dateTimeEdit->setObjectName(QString::fromUtf8("dateTimeEdit"));
        dateTimeEdit->setGeometry(QRect(1, 240, 400, 60));
        QFont font2;
        font2.setFamily(QString::fromUtf8("DejaVu Sans"));
        font2.setPointSize(20);
        font2.setBold(true);
        font2.setWeight(75);
        dateTimeEdit->setFont(font2);
        dateTimeEdit->setStyleSheet(QString::fromUtf8("QDateTimeEdit::up-button {\n"
"     width: 70px; \n"
" }\n"
"QDateTimeEdit::down-button {\n"
"     width: 70px;\n"
" }"));
        pb_Apply = new QPushButton(DateTime);
        pb_Apply->setObjectName(QString::fromUtf8("pb_Apply"));
        pb_Apply->setGeometry(QRect(60, 310, 100, 34));
        pb_Apply->setFont(font1);
        pb_Apply->setFocusPolicy(Qt::NoFocus);
        pb_Apply->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color:white;\n"
"border: 1px solid #2D5059;\n"
"border-radius: 10px;\n"
"background-color: qlineargradient(x1: 0, y1: 1, x2: 1, y2: 0,stop: 0 #000000, stop: 0.6 #292929 , stop:1 #FFFFFF);\n"
"font:bold 14px;\n"
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
        pb_Apply->setIconSize(QSize(65, 40));

        retranslateUi(DateTime);

        QMetaObject::connectSlotsByName(DateTime);
    } // setupUi

    void retranslateUi(QWidget *DateTime)
    {
        DateTime->setWindowTitle(QApplication::translate("DateTime", "Form", 0, QApplication::UnicodeUTF8));
        pb_exit->setText(QApplication::translate("DateTime", "CLOSE", 0, QApplication::UnicodeUTF8));
        pb_Apply->setText(QApplication::translate("DateTime", "APPLY", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DateTime: public Ui_DateTime {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATETIME_H
