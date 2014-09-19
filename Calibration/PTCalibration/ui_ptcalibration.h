/********************************************************************************
** Form generated from reading UI file 'ptcalibration.ui'
**
** Created: Mon Dec 2 12:40:26 2013
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PTCALIBRATION_H
#define UI_PTCALIBRATION_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QStackedWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PTCalibration
{
public:
    QGridLayout *gridLayout_2;
    QComboBox *comboBox;
    QLabel *label;
    QComboBox *comboBox_2;
    QLabel *label_2;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QGridLayout *gridLayout_3;
    QLabel *label_11;
    QLineEdit *lineEdit_5;
    QLabel *label_14;
    QLineEdit *lineEdit_6;
    QLabel *label_15;
    QLineEdit *lineEdit_7;
    QPushButton *nextBut_2;
    QLabel *samples_2;
    QLabel *label_16;
    QLabel *label_18;
    QLineEdit *lineEdit_8;
    QCheckBox *Calibrated_2;
    QLineEdit *constant_2;
    QLabel *label_17;
    QLineEdit *slope_2;
    QPushButton *driveBut_3;
    QPushButton *driveBut_4;
    QLabel *label_12;
    QLabel *label_13;
    QComboBox *comboBox_4;
    QPushButton *saveBut_2;
    QPushButton *exitBut_2;
    QComboBox *comboBox_5;
    QWidget *page_2;

    void setupUi(QDialog *PTCalibration)
    {
        if (PTCalibration->objectName().isEmpty())
            PTCalibration->setObjectName(QString::fromUtf8("PTCalibration"));
        PTCalibration->resize(694, 388);
        PTCalibration->setStyleSheet(QString::fromUtf8("QLineEdit{  \n"
"min-width: 80px;\n"
"min-height:30px;\n"
"}\n"
"QPushButton{  \n"
"min-width: 60px;\n"
"min-height:30px;\n"
"}"));
        gridLayout_2 = new QGridLayout(PTCalibration);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        comboBox = new QComboBox(PTCalibration);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy);
        comboBox->setStyleSheet(QString::fromUtf8("min-width: 140px;\n"
"min-height:30px;\n"
"\n"
""));

        gridLayout_2->addWidget(comboBox, 0, 1, 1, 1);

        label = new QLabel(PTCalibration);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        comboBox_2 = new QComboBox(PTCalibration);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(comboBox_2->sizePolicy().hasHeightForWidth());
        comboBox_2->setSizePolicy(sizePolicy2);
        comboBox_2->setStyleSheet(QString::fromUtf8("min-width: 140px;\n"
"min-height:30px;\n"
"\n"
""));

        gridLayout_2->addWidget(comboBox_2, 0, 4, 1, 2);

        label_2 = new QLabel(PTCalibration);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(label_2, 0, 3, 1, 1);

        stackedWidget = new QStackedWidget(PTCalibration);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        gridLayout_3 = new QGridLayout(page);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_11 = new QLabel(page);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        sizePolicy1.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy1);
        QFont font;
        font.setFamily(QString::fromUtf8("DejaVu Sans"));
        font.setPointSize(12);
        label_11->setFont(font);

        gridLayout_3->addWidget(label_11, 0, 0, 1, 3);

        lineEdit_5 = new QLineEdit(page);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Ignored);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(lineEdit_5->sizePolicy().hasHeightForWidth());
        lineEdit_5->setSizePolicy(sizePolicy3);
        QFont font1;
        font1.setBold(true);
        font1.setItalic(false);
        font1.setWeight(75);
        lineEdit_5->setFont(font1);
        lineEdit_5->setStyleSheet(QString::fromUtf8(""));

        gridLayout_3->addWidget(lineEdit_5, 0, 3, 1, 1);

        label_14 = new QLabel(page);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        sizePolicy1.setHeightForWidth(label_14->sizePolicy().hasHeightForWidth());
        label_14->setSizePolicy(sizePolicy1);
        label_14->setFont(font);

        gridLayout_3->addWidget(label_14, 1, 0, 1, 3);

        lineEdit_6 = new QLineEdit(page);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));
        sizePolicy3.setHeightForWidth(lineEdit_6->sizePolicy().hasHeightForWidth());
        lineEdit_6->setSizePolicy(sizePolicy3);
        lineEdit_6->setFont(font1);
        lineEdit_6->setStyleSheet(QString::fromUtf8(""));

        gridLayout_3->addWidget(lineEdit_6, 1, 3, 1, 3);

        label_15 = new QLabel(page);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        sizePolicy1.setHeightForWidth(label_15->sizePolicy().hasHeightForWidth());
        label_15->setSizePolicy(sizePolicy1);
        label_15->setFont(font);

        gridLayout_3->addWidget(label_15, 2, 0, 1, 3);

        lineEdit_7 = new QLineEdit(page);
        lineEdit_7->setObjectName(QString::fromUtf8("lineEdit_7"));
        sizePolicy3.setHeightForWidth(lineEdit_7->sizePolicy().hasHeightForWidth());
        lineEdit_7->setSizePolicy(sizePolicy3);
        lineEdit_7->setFont(font1);
        lineEdit_7->setStyleSheet(QString::fromUtf8(""));

        gridLayout_3->addWidget(lineEdit_7, 2, 3, 1, 3);

        nextBut_2 = new QPushButton(page);
        nextBut_2->setObjectName(QString::fromUtf8("nextBut_2"));
        QSizePolicy sizePolicy4(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(nextBut_2->sizePolicy().hasHeightForWidth());
        nextBut_2->setSizePolicy(sizePolicy4);
        nextBut_2->setFont(font);
        nextBut_2->setStyleSheet(QString::fromUtf8(""));

        gridLayout_3->addWidget(nextBut_2, 2, 7, 1, 3);

        samples_2 = new QLabel(page);
        samples_2->setObjectName(QString::fromUtf8("samples_2"));
        sizePolicy4.setHeightForWidth(samples_2->sizePolicy().hasHeightForWidth());
        samples_2->setSizePolicy(sizePolicy4);

        gridLayout_3->addWidget(samples_2, 2, 10, 1, 1);

        label_16 = new QLabel(page);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        sizePolicy1.setHeightForWidth(label_16->sizePolicy().hasHeightForWidth());
        label_16->setSizePolicy(sizePolicy1);
        label_16->setFont(font);

        gridLayout_3->addWidget(label_16, 3, 0, 1, 2);

        label_18 = new QLabel(page);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        sizePolicy1.setHeightForWidth(label_18->sizePolicy().hasHeightForWidth());
        label_18->setSizePolicy(sizePolicy1);
        label_18->setFont(font);

        gridLayout_3->addWidget(label_18, 4, 0, 1, 2);

        lineEdit_8 = new QLineEdit(page);
        lineEdit_8->setObjectName(QString::fromUtf8("lineEdit_8"));
        sizePolicy3.setHeightForWidth(lineEdit_8->sizePolicy().hasHeightForWidth());
        lineEdit_8->setSizePolicy(sizePolicy3);
        lineEdit_8->setFont(font1);
        lineEdit_8->setStyleSheet(QString::fromUtf8(""));

        gridLayout_3->addWidget(lineEdit_8, 4, 2, 1, 2);

        Calibrated_2 = new QCheckBox(page);
        Calibrated_2->setObjectName(QString::fromUtf8("Calibrated_2"));
        sizePolicy1.setHeightForWidth(Calibrated_2->sizePolicy().hasHeightForWidth());
        Calibrated_2->setSizePolicy(sizePolicy1);
        Calibrated_2->setFont(font);

        gridLayout_3->addWidget(Calibrated_2, 4, 5, 1, 2);

        constant_2 = new QLineEdit(page);
        constant_2->setObjectName(QString::fromUtf8("constant_2"));
        sizePolicy3.setHeightForWidth(constant_2->sizePolicy().hasHeightForWidth());
        constant_2->setSizePolicy(sizePolicy3);
        constant_2->setFont(font1);
        constant_2->setStyleSheet(QString::fromUtf8(""));
        constant_2->setReadOnly(true);

        gridLayout_3->addWidget(constant_2, 3, 7, 1, 2);

        label_17 = new QLabel(page);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        sizePolicy1.setHeightForWidth(label_17->sizePolicy().hasHeightForWidth());
        label_17->setSizePolicy(sizePolicy1);
        label_17->setFont(font);

        gridLayout_3->addWidget(label_17, 3, 5, 1, 2);

        slope_2 = new QLineEdit(page);
        slope_2->setObjectName(QString::fromUtf8("slope_2"));
        sizePolicy3.setHeightForWidth(slope_2->sizePolicy().hasHeightForWidth());
        slope_2->setSizePolicy(sizePolicy3);
        slope_2->setFont(font1);
        slope_2->setStyleSheet(QString::fromUtf8(""));
        slope_2->setReadOnly(true);

        gridLayout_3->addWidget(slope_2, 3, 2, 1, 2);

        driveBut_3 = new QPushButton(page);
        driveBut_3->setObjectName(QString::fromUtf8("driveBut_3"));
        sizePolicy4.setHeightForWidth(driveBut_3->sizePolicy().hasHeightForWidth());
        driveBut_3->setSizePolicy(sizePolicy4);
        driveBut_3->setFont(font);
        driveBut_3->setStyleSheet(QString::fromUtf8(""));

        gridLayout_3->addWidget(driveBut_3, 1, 7, 1, 3);

        driveBut_4 = new QPushButton(page);
        driveBut_4->setObjectName(QString::fromUtf8("driveBut_4"));
        sizePolicy4.setHeightForWidth(driveBut_4->sizePolicy().hasHeightForWidth());
        driveBut_4->setSizePolicy(sizePolicy4);
        driveBut_4->setFont(font);
        driveBut_4->setStyleSheet(QString::fromUtf8(""));

        gridLayout_3->addWidget(driveBut_4, 4, 7, 1, 3);

        label_12 = new QLabel(page);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        sizePolicy1.setHeightForWidth(label_12->sizePolicy().hasHeightForWidth());
        label_12->setSizePolicy(sizePolicy1);
        label_12->setFont(font);

        gridLayout_3->addWidget(label_12, 0, 5, 1, 1);

        label_13 = new QLabel(page);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        sizePolicy4.setHeightForWidth(label_13->sizePolicy().hasHeightForWidth());
        label_13->setSizePolicy(sizePolicy4);
        QFont font2;
        font2.setPointSize(11);
        label_13->setFont(font2);
        label_13->setStyleSheet(QString::fromUtf8("min-width: 40px;\n"
"min-height:30px;\n"
"\n"
""));
        label_13->setTextFormat(Qt::AutoText);
        label_13->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_13, 0, 8, 1, 1);

        comboBox_4 = new QComboBox(page);
        comboBox_4->setObjectName(QString::fromUtf8("comboBox_4"));
        sizePolicy4.setHeightForWidth(comboBox_4->sizePolicy().hasHeightForWidth());
        comboBox_4->setSizePolicy(sizePolicy4);
        QFont font3;
        font3.setPointSize(12);
        font3.setBold(true);
        font3.setWeight(75);
        comboBox_4->setFont(font3);
        comboBox_4->setStyleSheet(QString::fromUtf8("min-width: 140px;\n"
"min-height:30px;\n"
"\n"
""));

        gridLayout_3->addWidget(comboBox_4, 0, 6, 1, 2);

        saveBut_2 = new QPushButton(page);
        saveBut_2->setObjectName(QString::fromUtf8("saveBut_2"));
        sizePolicy4.setHeightForWidth(saveBut_2->sizePolicy().hasHeightForWidth());
        saveBut_2->setSizePolicy(sizePolicy4);
        saveBut_2->setFont(font);
        saveBut_2->setStyleSheet(QString::fromUtf8(""));

        gridLayout_3->addWidget(saveBut_2, 5, 1, 1, 3);

        exitBut_2 = new QPushButton(page);
        exitBut_2->setObjectName(QString::fromUtf8("exitBut_2"));
        sizePolicy4.setHeightForWidth(exitBut_2->sizePolicy().hasHeightForWidth());
        exitBut_2->setSizePolicy(sizePolicy4);
        exitBut_2->setFont(font);
        exitBut_2->setStyleSheet(QString::fromUtf8(""));

        gridLayout_3->addWidget(exitBut_2, 5, 5, 1, 3);

        comboBox_5 = new QComboBox(page);
        comboBox_5->setObjectName(QString::fromUtf8("comboBox_5"));
        QSizePolicy sizePolicy5(QSizePolicy::Ignored, QSizePolicy::Minimum);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(comboBox_5->sizePolicy().hasHeightForWidth());
        comboBox_5->setSizePolicy(sizePolicy5);
        comboBox_5->setStyleSheet(QString::fromUtf8("min-width: 140px;\n"
"min-height:30px;\n"
"\n"
""));

        gridLayout_3->addWidget(comboBox_5, 6, 7, 1, 1);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        stackedWidget->addWidget(page_2);

        gridLayout_2->addWidget(stackedWidget, 1, 0, 1, 6);


        retranslateUi(PTCalibration);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(PTCalibration);
    } // setupUi

    void retranslateUi(QDialog *PTCalibration)
    {
        PTCalibration->setWindowTitle(QApplication::translate("PTCalibration", "PTCalibration", 0, QApplication::UnicodeUTF8));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("PTCalibration", "DMM", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PTCalibration", "VI-QSM", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PTCalibration", "FG", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PTCalibration", "SH LOC", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PTCalibration", "ICM", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PTCalibration", "DSO", 0, QApplication::UnicodeUTF8)
        );
        label->setText(QApplication::translate("PTCalibration", "Application :", 0, QApplication::UnicodeUTF8));
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("PTCalibration", "Drive Current", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PTCalibration", "Receive Voltage", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PTCalibration", "Reference Voltage", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PTCalibration", "Screen Calibration", 0, QApplication::UnicodeUTF8)
        );
        label_2->setText(QApplication::translate("PTCalibration", "Component", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("PTCalibration", "No of Points:", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("PTCalibration", "Drive Current(x):", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("PTCalibration", "RX'd Current(y):", 0, QApplication::UnicodeUTF8));
        nextBut_2->setText(QApplication::translate("PTCalibration", "NEXT", 0, QApplication::UnicodeUTF8));
        samples_2->setText(QString());
        label_16->setText(QApplication::translate("PTCalibration", "Slope:", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("PTCalibration", "Test Volt:", 0, QApplication::UnicodeUTF8));
        Calibrated_2->setText(QApplication::translate("PTCalibration", "Calibrated", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("PTCalibration", "Constant:", 0, QApplication::UnicodeUTF8));
        driveBut_3->setText(QApplication::translate("PTCalibration", "DRIVE", 0, QApplication::UnicodeUTF8));
        driveBut_4->setText(QApplication::translate("PTCalibration", "DRIVE", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("PTCalibration", "Range:", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("PTCalibration", "mA", 0, QApplication::UnicodeUTF8));
        comboBox_4->clear();
        comboBox_4->insertItems(0, QStringList()
         << QApplication::translate("PTCalibration", "50", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PTCalibration", "500", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PTCalibration", "5", 0, QApplication::UnicodeUTF8)
        );
        saveBut_2->setText(QApplication::translate("PTCalibration", "SAVE", 0, QApplication::UnicodeUTF8));
        exitBut_2->setText(QApplication::translate("PTCalibration", "EXIT", 0, QApplication::UnicodeUTF8));
        comboBox_5->clear();
        comboBox_5->insertItems(0, QStringList()
         << QApplication::translate("PTCalibration", "PlasticStyle", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PTCalibration", "CleanLookStyle", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PTCalibration", "MotifStyle", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PTCalibration", "CDEStyle", 0, QApplication::UnicodeUTF8)
        );
    } // retranslateUi

};

namespace Ui {
    class PTCalibration: public Ui_PTCalibration {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PTCALIBRATION_H
