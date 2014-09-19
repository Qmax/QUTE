/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created: Sat Sep 6 10:53:17 2014
**      by: Qt User Interface Compiler version 4.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGroupBox *grpGeneral;
    QLabel *lblAddress;
    QPushButton *butRead;
    QLabel *lblData;
    QPushButton *butWrite;
    QLineEdit *edAddress;
    QLineEdit *edData;
    QGroupBox *grpSettings;
    QLabel *lblDrRanve;
    QComboBox *cmbDrvVoltage;
    QLabel *lblSrcImped;
    QComboBox *cmbImpedance;
    QComboBox *cmbDriveMode;
    QLabel *lblDrvMode;
    QGroupBox *grpWaveWindow;
    QGroupBox *grpWaveConfiguration;
    QLabel *lblPatternType;
    QComboBox *cmbPatterns;
    QLabel *lblOffset;
    QLabel *lblFrequency;
    QLabel *lblFrequency_2;
    QLabel *lblFrequency_3;
    QLabel *lblFrequency_4;
    QLabel *lblFrequency_5;
    QLineEdit *edFrequency_5;
    QLineEdit *edFrequency_4;
    QLineEdit *edOffset;
    QLineEdit *edFrequency;
    QLineEdit *edFrequency_2;
    QLineEdit *edFrequency_3;
    QGroupBox *groupBox;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QGroupBox *groupBox_2;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QGroupBox *groupBox_3;
    QPushButton *butExport;
    QPushButton *butStartDrive;
    QPushButton *butStopDrive;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->setWindowModality(Qt::NonModal);
        Widget->resize(800, 600);
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
        Widget->setPalette(palette);
        grpGeneral = new QGroupBox(Widget);
        grpGeneral->setObjectName(QString::fromUtf8("grpGeneral"));
        grpGeneral->setGeometry(QRect(20, 0, 271, 160));
        QFont font;
        font.setFamily(QString::fromUtf8("DejaVu Sans"));
        font.setPointSize(13);
        font.setBold(false);
        font.setWeight(50);
        grpGeneral->setFont(font);
        grpGeneral->setAutoFillBackground(false);
        grpGeneral->setFlat(false);
        lblAddress = new QLabel(grpGeneral);
        lblAddress->setObjectName(QString::fromUtf8("lblAddress"));
        lblAddress->setGeometry(QRect(20, 26, 56, 16));
        lblAddress->setFont(font);
        butRead = new QPushButton(grpGeneral);
        butRead->setObjectName(QString::fromUtf8("butRead"));
        butRead->setGeometry(QRect(80, 110, 75, 41));
        butRead->setFont(font);
        lblData = new QLabel(grpGeneral);
        lblData->setObjectName(QString::fromUtf8("lblData"));
        lblData->setGeometry(QRect(20, 70, 36, 16));
        lblData->setFont(font);
        butWrite = new QPushButton(grpGeneral);
        butWrite->setObjectName(QString::fromUtf8("butWrite"));
        butWrite->setGeometry(QRect(160, 110, 75, 41));
        butWrite->setFont(font);
        edAddress = new QLineEdit(grpGeneral);
        edAddress->setObjectName(QString::fromUtf8("edAddress"));
        edAddress->setGeometry(QRect(90, 15, 161, 41));
        edAddress->setFont(font);
        edData = new QLineEdit(grpGeneral);
        edData->setObjectName(QString::fromUtf8("edData"));
        edData->setGeometry(QRect(90, 60, 161, 41));
        edData->setFont(font);
        grpSettings = new QGroupBox(Widget);
        grpSettings->setObjectName(QString::fromUtf8("grpSettings"));
        grpSettings->setGeometry(QRect(310, 0, 471, 101));
        grpSettings->setFont(font);
        lblDrRanve = new QLabel(grpSettings);
        lblDrRanve->setObjectName(QString::fromUtf8("lblDrRanve"));
        lblDrRanve->setGeometry(QRect(7, 19, 151, 20));
        lblDrRanve->setFont(font);
        cmbDrvVoltage = new QComboBox(grpSettings);
        cmbDrvVoltage->setObjectName(QString::fromUtf8("cmbDrvVoltage"));
        cmbDrvVoltage->setGeometry(QRect(20, 40, 111, 51));
        cmbDrvVoltage->setFont(font);
        lblSrcImped = new QLabel(grpSettings);
        lblSrcImped->setObjectName(QString::fromUtf8("lblSrcImped"));
        lblSrcImped->setGeometry(QRect(150, 20, 151, 20));
        lblSrcImped->setFont(font);
        cmbImpedance = new QComboBox(grpSettings);
        cmbImpedance->setObjectName(QString::fromUtf8("cmbImpedance"));
        cmbImpedance->setGeometry(QRect(170, 40, 111, 51));
        cmbImpedance->setFont(font);
        cmbDriveMode = new QComboBox(grpSettings);
        cmbDriveMode->setObjectName(QString::fromUtf8("cmbDriveMode"));
        cmbDriveMode->setGeometry(QRect(330, 40, 121, 51));
        cmbDriveMode->setFont(font);
        lblDrvMode = new QLabel(grpSettings);
        lblDrvMode->setObjectName(QString::fromUtf8("lblDrvMode"));
        lblDrvMode->setGeometry(QRect(339, 20, 101, 20));
        lblDrvMode->setFont(font);
        grpWaveWindow = new QGroupBox(Widget);
        grpWaveWindow->setObjectName(QString::fromUtf8("grpWaveWindow"));
        grpWaveWindow->setGeometry(QRect(310, 100, 471, 250));
        grpWaveWindow->setFont(font);
        grpWaveConfiguration = new QGroupBox(Widget);
        grpWaveConfiguration->setObjectName(QString::fromUtf8("grpWaveConfiguration"));
        grpWaveConfiguration->setGeometry(QRect(20, 164, 271, 356));
        grpWaveConfiguration->setFont(font);
        lblPatternType = new QLabel(grpWaveConfiguration);
        lblPatternType->setObjectName(QString::fromUtf8("lblPatternType"));
        lblPatternType->setGeometry(QRect(10, 7, 90, 45));
        lblPatternType->setFont(font);
        cmbPatterns = new QComboBox(grpWaveConfiguration);
        cmbPatterns->setObjectName(QString::fromUtf8("cmbPatterns"));
        cmbPatterns->setGeometry(QRect(110, 10, 158, 40));
        cmbPatterns->setFont(font);
        lblOffset = new QLabel(grpWaveConfiguration);
        lblOffset->setObjectName(QString::fromUtf8("lblOffset"));
        lblOffset->setGeometry(QRect(10, 58, 90, 45));
        lblOffset->setFont(font);
        lblFrequency = new QLabel(grpWaveConfiguration);
        lblFrequency->setObjectName(QString::fromUtf8("lblFrequency"));
        lblFrequency->setGeometry(QRect(10, 108, 90, 45));
        lblFrequency->setFont(font);
        lblFrequency_2 = new QLabel(grpWaveConfiguration);
        lblFrequency_2->setObjectName(QString::fromUtf8("lblFrequency_2"));
        lblFrequency_2->setGeometry(QRect(10, 158, 90, 45));
        lblFrequency_2->setFont(font);
        lblFrequency_3 = new QLabel(grpWaveConfiguration);
        lblFrequency_3->setObjectName(QString::fromUtf8("lblFrequency_3"));
        lblFrequency_3->setGeometry(QRect(10, 208, 90, 45));
        lblFrequency_3->setFont(font);
        lblFrequency_4 = new QLabel(grpWaveConfiguration);
        lblFrequency_4->setObjectName(QString::fromUtf8("lblFrequency_4"));
        lblFrequency_4->setGeometry(QRect(10, 258, 90, 45));
        lblFrequency_4->setFont(font);
        lblFrequency_5 = new QLabel(grpWaveConfiguration);
        lblFrequency_5->setObjectName(QString::fromUtf8("lblFrequency_5"));
        lblFrequency_5->setGeometry(QRect(10, 307, 90, 45));
        lblFrequency_5->setFont(font);
        edFrequency_5 = new QLineEdit(grpWaveConfiguration);
        edFrequency_5->setObjectName(QString::fromUtf8("edFrequency_5"));
        edFrequency_5->setGeometry(QRect(110, 308, 158, 38));
        edFrequency_5->setFont(font);
        edFrequency_4 = new QLineEdit(grpWaveConfiguration);
        edFrequency_4->setObjectName(QString::fromUtf8("edFrequency_4"));
        edFrequency_4->setGeometry(QRect(110, 258, 158, 38));
        edFrequency_4->setFont(font);
        edOffset = new QLineEdit(grpWaveConfiguration);
        edOffset->setObjectName(QString::fromUtf8("edOffset"));
        edOffset->setGeometry(QRect(110, 58, 158, 38));
        edOffset->setFont(font);
        edFrequency = new QLineEdit(grpWaveConfiguration);
        edFrequency->setObjectName(QString::fromUtf8("edFrequency"));
        edFrequency->setGeometry(QRect(110, 108, 158, 38));
        edFrequency->setFont(font);
        edFrequency_2 = new QLineEdit(grpWaveConfiguration);
        edFrequency_2->setObjectName(QString::fromUtf8("edFrequency_2"));
        edFrequency_2->setGeometry(QRect(110, 158, 158, 38));
        edFrequency_2->setFont(font);
        edFrequency_3 = new QLineEdit(grpWaveConfiguration);
        edFrequency_3->setObjectName(QString::fromUtf8("edFrequency_3"));
        edFrequency_3->setGeometry(QRect(110, 208, 158, 38));
        edFrequency_3->setFont(font);
        groupBox = new QGroupBox(Widget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(510, 430, 271, 90));
        groupBox->setFont(font);
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(40, 28, 93, 51));
        pushButton->setFont(font);
        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(150, 28, 93, 51));
        pushButton_2->setFont(font);
        groupBox_2 = new QGroupBox(Widget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(310, 350, 191, 170));
        groupBox_2->setFont(font);
        radioButton = new QRadioButton(groupBox_2);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(30, 30, 151, 51));
        radioButton->setFont(font);
        radioButton->setFocusPolicy(Qt::NoFocus);
        radioButton->setStyleSheet(QString::fromUtf8("QRadioButton::indicator {\n"
"     width: 30px;\n"
"     height: 30px;\n"
"}\n"
""));
        radioButton->setChecked(true);
        radioButton_2 = new QRadioButton(groupBox_2);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setGeometry(QRect(30, 100, 151, 51));
        radioButton_2->setFont(font);
        radioButton_2->setFocusPolicy(Qt::NoFocus);
        radioButton_2->setStyleSheet(QString::fromUtf8("QRadioButton::indicator {\n"
"     width: 30px;\n"
"     height: 30px;\n"
"}\n"
""));
        groupBox_3 = new QGroupBox(Widget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(510, 360, 271, 77));
        groupBox_3->setFont(font);
        butExport = new QPushButton(groupBox_3);
        butExport->setObjectName(QString::fromUtf8("butExport"));
        butExport->setGeometry(QRect(10, 10, 75, 51));
        butExport->setFont(font);
        butStartDrive = new QPushButton(groupBox_3);
        butStartDrive->setObjectName(QString::fromUtf8("butStartDrive"));
        butStartDrive->setGeometry(QRect(100, 10, 75, 51));
        butStartDrive->setFont(font);
        butStopDrive = new QPushButton(groupBox_3);
        butStopDrive->setObjectName(QString::fromUtf8("butStopDrive"));
        butStopDrive->setGeometry(QRect(190, 10, 75, 51));
        butStopDrive->setFont(font);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "AWG", 0, QApplication::UnicodeUTF8));
        grpGeneral->setTitle(QApplication::translate("Widget", "General", 0, QApplication::UnicodeUTF8));
        lblAddress->setText(QApplication::translate("Widget", "Address :", 0, QApplication::UnicodeUTF8));
        butRead->setText(QApplication::translate("Widget", "Read", 0, QApplication::UnicodeUTF8));
        lblData->setText(QApplication::translate("Widget", "Data :", 0, QApplication::UnicodeUTF8));
        butWrite->setText(QApplication::translate("Widget", "Write", 0, QApplication::UnicodeUTF8));
        grpSettings->setTitle(QApplication::translate("Widget", "Settings", 0, QApplication::UnicodeUTF8));
        lblDrRanve->setText(QApplication::translate("Widget", "Drive Range (Vp-p)", 0, QApplication::UnicodeUTF8));
        cmbDrvVoltage->clear();
        cmbDrvVoltage->insertItems(0, QStringList()
         << QApplication::translate("Widget", "0.5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "1.5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "3.5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "7", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "13", 0, QApplication::UnicodeUTF8)
        );
        lblSrcImped->setText(QApplication::translate("Widget", "Source Impedance (E)", 0, QApplication::UnicodeUTF8));
        cmbImpedance->clear();
        cmbImpedance->insertItems(0, QStringList()
         << QApplication::translate("Widget", "10", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "100", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "1000", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "10000", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "100000", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "1000000", 0, QApplication::UnicodeUTF8)
        );
        cmbDriveMode->clear();
        cmbDriveMode->insertItems(0, QStringList()
         << QApplication::translate("Widget", "SINGLE", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "CONTINUOS", 0, QApplication::UnicodeUTF8)
        );
        lblDrvMode->setText(QApplication::translate("Widget", "Drive Pattern", 0, QApplication::UnicodeUTF8));
        grpWaveWindow->setTitle(QApplication::translate("Widget", "WaveFrom", 0, QApplication::UnicodeUTF8));
        grpWaveConfiguration->setTitle(QString());
        lblPatternType->setText(QApplication::translate("Widget", "Pattern Type", 0, QApplication::UnicodeUTF8));
        cmbPatterns->clear();
        cmbPatterns->insertItems(0, QStringList()
         << QApplication::translate("Widget", "SINE", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "SQUARE", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "RAMP", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "TRIANGLE", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "PULSE", 0, QApplication::UnicodeUTF8)
        );
        lblOffset->setText(QApplication::translate("Widget", "Offset", 0, QApplication::UnicodeUTF8));
        lblFrequency->setText(QApplication::translate("Widget", "Frequency", 0, QApplication::UnicodeUTF8));
        lblFrequency_2->setText(QApplication::translate("Widget", "Time", 0, QApplication::UnicodeUTF8));
        lblFrequency_3->setText(QApplication::translate("Widget", "TimeBase", 0, QApplication::UnicodeUTF8));
        lblFrequency_4->setText(QApplication::translate("Widget", "Duration", 0, QApplication::UnicodeUTF8));
        lblFrequency_5->setText(QApplication::translate("Widget", "Samples", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("Widget", "File", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Widget", "Export", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("Widget", "Import", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("Widget", "Select DAC", 0, QApplication::UnicodeUTF8));
        radioButton->setText(QApplication::translate("Widget", "AD9744", 0, QApplication::UnicodeUTF8));
        radioButton_2->setText(QApplication::translate("Widget", "AD9102", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QString());
        butExport->setText(QApplication::translate("Widget", "LOAD FIFO", 0, QApplication::UnicodeUTF8));
        butStartDrive->setText(QApplication::translate("Widget", "START", 0, QApplication::UnicodeUTF8));
        butStopDrive->setText(QApplication::translate("Widget", "STOP", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
