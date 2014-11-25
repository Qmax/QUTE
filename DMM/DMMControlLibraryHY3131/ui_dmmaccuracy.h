/********************************************************************************
** Form generated from reading UI file 'dmmaccuracy.ui'
**
** Created: Mon Nov 24 11:18:03 2014
**      by: Qt User Interface Compiler version 4.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DMMACCURACY_H
#define UI_DMMACCURACY_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDateTimeEdit>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DMMAccuracy
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QDateTimeEdit *dateTimeEdit;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QSpinBox *spinBox;
    QLabel *label_4;
    QSpinBox *spinBox_2;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QWidget *horizontalLayoutWidget_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label;
    QLineEdit *dmmData;

    void setupUi(QWidget *DMMAccuracy)
    {
        if (DMMAccuracy->objectName().isEmpty())
            DMMAccuracy->setObjectName(QString::fromUtf8("DMMAccuracy"));
        DMMAccuracy->resize(499, 212);
        QIcon icon;
        icon.addFile(QString::fromUtf8("Control-Panel-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        DMMAccuracy->setWindowIcon(icon);
        horizontalLayoutWidget = new QWidget(DMMAccuracy);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 60, 481, 41));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(horizontalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(11);
        label_2->setFont(font);

        horizontalLayout->addWidget(label_2);

        dateTimeEdit = new QDateTimeEdit(horizontalLayoutWidget);
        dateTimeEdit->setObjectName(QString::fromUtf8("dateTimeEdit"));
        sizePolicy.setHeightForWidth(dateTimeEdit->sizePolicy().hasHeightForWidth());
        dateTimeEdit->setSizePolicy(sizePolicy);
        dateTimeEdit->setFont(font);
        dateTimeEdit->setStyleSheet(QString::fromUtf8("QDateTime::up-button {\n"
"     width: 50px; \n"
" }\n"
"QDateTime::down-button {\n"
"     width: 50px;\n"
" }"));

        horizontalLayout->addWidget(dateTimeEdit);

        horizontalLayoutWidget_2 = new QWidget(DMMAccuracy);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(10, 110, 484, 41));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(horizontalLayoutWidget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);
        label_3->setFont(font);

        horizontalLayout_2->addWidget(label_3);

        spinBox = new QSpinBox(horizontalLayoutWidget_2);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        sizePolicy.setHeightForWidth(spinBox->sizePolicy().hasHeightForWidth());
        spinBox->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setPointSize(12);
        spinBox->setFont(font1);
        spinBox->setStyleSheet(QString::fromUtf8("QSpinBox::up-button {\n"
"     width: 40px; \n"
" }\n"
" QSpinBox::down-button {\n"
"     width: 40px;\n"
" }"));
        spinBox->setMinimum(1);
        spinBox->setValue(1);

        horizontalLayout_2->addWidget(spinBox);

        label_4 = new QLabel(horizontalLayoutWidget_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy1.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy1);
        label_4->setFont(font);

        horizontalLayout_2->addWidget(label_4);

        spinBox_2 = new QSpinBox(horizontalLayoutWidget_2);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));
        sizePolicy.setHeightForWidth(spinBox_2->sizePolicy().hasHeightForWidth());
        spinBox_2->setSizePolicy(sizePolicy);
        spinBox_2->setFont(font1);
        spinBox_2->setStyleSheet(QString::fromUtf8("QSpinBox::up-button {\n"
"     width: 40px; \n"
" }\n"
" QSpinBox::down-button {\n"
"     width: 40px;\n"
" }"));
        spinBox_2->setMinimum(2);
        spinBox_2->setValue(2);

        horizontalLayout_2->addWidget(spinBox_2);

        horizontalLayoutWidget_3 = new QWidget(DMMAccuracy);
        horizontalLayoutWidget_3->setObjectName(QString::fromUtf8("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(10, 160, 481, 41));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(horizontalLayoutWidget_3);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy2);
        pushButton->setFont(font);

        horizontalLayout_3->addWidget(pushButton);

        pushButton_2 = new QPushButton(horizontalLayoutWidget_3);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        sizePolicy2.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy2);
        pushButton_2->setFont(font);

        horizontalLayout_3->addWidget(pushButton_2);

        horizontalLayoutWidget_4 = new QWidget(DMMAccuracy);
        horizontalLayoutWidget_4->setObjectName(QString::fromUtf8("horizontalLayoutWidget_4"));
        horizontalLayoutWidget_4->setGeometry(QRect(10, 10, 481, 41));
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget_4);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(horizontalLayoutWidget_4);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setFont(font);

        horizontalLayout_4->addWidget(label);

        dmmData = new QLineEdit(horizontalLayoutWidget_4);
        dmmData->setObjectName(QString::fromUtf8("dmmData"));
        sizePolicy.setHeightForWidth(dmmData->sizePolicy().hasHeightForWidth());
        dmmData->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(dmmData);


        retranslateUi(DMMAccuracy);

        QMetaObject::connectSlotsByName(DMMAccuracy);
    } // setupUi

    void retranslateUi(QWidget *DMMAccuracy)
    {
        DMMAccuracy->setWindowTitle(QApplication::translate("DMMAccuracy", "DMMAccuracy", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("DMMAccuracy", "Set Current Date & Time : ", 0, QApplication::UnicodeUTF8));
        dateTimeEdit->setDisplayFormat(QApplication::translate("DMMAccuracy", "dd/MM/yy h:mm", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("DMMAccuracy", "Reading Frequency : \n"
" (minutes)", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("DMMAccuracy", "No of Readings : ", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("DMMAccuracy", "START", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("DMMAccuracy", "CANCEL", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("DMMAccuracy", "DMM Data : ", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DMMAccuracy: public Ui_DMMAccuracy {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DMMACCURACY_H
