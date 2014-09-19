/********************************************************************************
** Form generated from reading UI file 'vijig.ui'
**
** Created: Tue Sep 9 12:03:42 2014
**      by: Qt User Interface Compiler version 4.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIJIG_H
#define UI_VIJIG_H

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
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VIJig
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
    QLabel *lblSrcImped_2;
    QComboBox *cmbFrequency;
    QGroupBox *grpWaveWindow;
    QGroupBox *grpWaveConfiguration;
    QLineEdit *edFrequency;
    QLabel *lblDrvMode;
    QLabel *lblOffset;
    QLineEdit *edOffset;
    QLabel *lblFrequency;
    QComboBox *cmbPatterns;
    QComboBox *cmbDriveMode;
    QLabel *lblPatternType;
    QGroupBox *groupBox;
    QLabel *lblSrcImped_3;
    QComboBox *cmbFrequency_2;
    QPushButton *butStartDrive;
    QPushButton *butStopDrive;

    void setupUi(QWidget *VIJig)
    {
        if (VIJig->objectName().isEmpty())
            VIJig->setObjectName(QString::fromUtf8("VIJig"));
        VIJig->resize(800, 600);
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
        VIJig->setPalette(palette);
        grpGeneral = new QGroupBox(VIJig);
        grpGeneral->setObjectName(QString::fromUtf8("grpGeneral"));
        grpGeneral->setGeometry(QRect(20, 0, 271, 171));
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
        grpSettings = new QGroupBox(VIJig);
        grpSettings->setObjectName(QString::fromUtf8("grpSettings"));
        grpSettings->setGeometry(QRect(310, 0, 471, 150));
        grpSettings->setFont(font);
        lblDrRanve = new QLabel(grpSettings);
        lblDrRanve->setObjectName(QString::fromUtf8("lblDrRanve"));
        lblDrRanve->setGeometry(QRect(17, 39, 151, 20));
        lblDrRanve->setFont(font);
        cmbDrvVoltage = new QComboBox(grpSettings);
        cmbDrvVoltage->setObjectName(QString::fromUtf8("cmbDrvVoltage"));
        cmbDrvVoltage->setGeometry(QRect(30, 70, 111, 51));
        cmbDrvVoltage->setFont(font);
        lblSrcImped = new QLabel(grpSettings);
        lblSrcImped->setObjectName(QString::fromUtf8("lblSrcImped"));
        lblSrcImped->setGeometry(QRect(160, 40, 151, 20));
        lblSrcImped->setFont(font);
        cmbImpedance = new QComboBox(grpSettings);
        cmbImpedance->setObjectName(QString::fromUtf8("cmbImpedance"));
        cmbImpedance->setGeometry(QRect(180, 70, 111, 51));
        cmbImpedance->setFont(font);
        lblSrcImped_2 = new QLabel(grpSettings);
        lblSrcImped_2->setObjectName(QString::fromUtf8("lblSrcImped_2"));
        lblSrcImped_2->setGeometry(QRect(355, 40, 81, 20));
        lblSrcImped_2->setFont(font);
        cmbFrequency = new QComboBox(grpSettings);
        cmbFrequency->setObjectName(QString::fromUtf8("cmbFrequency"));
        cmbFrequency->setGeometry(QRect(340, 70, 111, 51));
        cmbFrequency->setFont(font);
        grpWaveWindow = new QGroupBox(VIJig);
        grpWaveWindow->setObjectName(QString::fromUtf8("grpWaveWindow"));
        grpWaveWindow->setGeometry(QRect(310, 160, 361, 360));
        grpWaveWindow->setFont(font);
        grpWaveConfiguration = new QGroupBox(VIJig);
        grpWaveConfiguration->setObjectName(QString::fromUtf8("grpWaveConfiguration"));
        grpWaveConfiguration->setGeometry(QRect(20, 190, 271, 330));
        grpWaveConfiguration->setFont(font);
        edFrequency = new QLineEdit(grpWaveConfiguration);
        edFrequency->setObjectName(QString::fromUtf8("edFrequency"));
        edFrequency->setGeometry(QRect(120, 230, 139, 40));
        edFrequency->setFont(font);
        lblDrvMode = new QLabel(grpWaveConfiguration);
        lblDrvMode->setObjectName(QString::fromUtf8("lblDrvMode"));
        lblDrvMode->setGeometry(QRect(10, 90, 104, 40));
        lblDrvMode->setFont(font);
        lblOffset = new QLabel(grpWaveConfiguration);
        lblOffset->setObjectName(QString::fromUtf8("lblOffset"));
        lblOffset->setGeometry(QRect(10, 160, 104, 40));
        lblOffset->setFont(font);
        edOffset = new QLineEdit(grpWaveConfiguration);
        edOffset->setObjectName(QString::fromUtf8("edOffset"));
        edOffset->setGeometry(QRect(120, 160, 139, 40));
        edOffset->setFont(font);
        lblFrequency = new QLabel(grpWaveConfiguration);
        lblFrequency->setObjectName(QString::fromUtf8("lblFrequency"));
        lblFrequency->setGeometry(QRect(10, 230, 104, 40));
        lblFrequency->setFont(font);
        cmbPatterns = new QComboBox(grpWaveConfiguration);
        cmbPatterns->setObjectName(QString::fromUtf8("cmbPatterns"));
        cmbPatterns->setGeometry(QRect(120, 20, 139, 40));
        cmbPatterns->setFont(font);
        cmbDriveMode = new QComboBox(grpWaveConfiguration);
        cmbDriveMode->setObjectName(QString::fromUtf8("cmbDriveMode"));
        cmbDriveMode->setGeometry(QRect(120, 90, 139, 40));
        cmbDriveMode->setFont(font);
        lblPatternType = new QLabel(grpWaveConfiguration);
        lblPatternType->setObjectName(QString::fromUtf8("lblPatternType"));
        lblPatternType->setGeometry(QRect(10, 20, 104, 40));
        lblPatternType->setFont(font);
        groupBox = new QGroupBox(VIJig);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(680, 170, 101, 350));
        groupBox->setFont(font);
        lblSrcImped_3 = new QLabel(groupBox);
        lblSrcImped_3->setObjectName(QString::fromUtf8("lblSrcImped_3"));
        lblSrcImped_3->setGeometry(QRect(14, 10, 81, 51));
        lblSrcImped_3->setFont(font);
        cmbFrequency_2 = new QComboBox(groupBox);
        cmbFrequency_2->setObjectName(QString::fromUtf8("cmbFrequency_2"));
        cmbFrequency_2->setGeometry(QRect(10, 60, 81, 41));
        cmbFrequency_2->setFont(font);
        butStartDrive = new QPushButton(groupBox);
        butStartDrive->setObjectName(QString::fromUtf8("butStartDrive"));
        butStartDrive->setGeometry(QRect(10, 160, 80, 65));
        butStartDrive->setFont(font);
        butStopDrive = new QPushButton(groupBox);
        butStopDrive->setObjectName(QString::fromUtf8("butStopDrive"));
        butStopDrive->setGeometry(QRect(10, 250, 80, 65));
        butStopDrive->setFont(font);

        retranslateUi(VIJig);

        QMetaObject::connectSlotsByName(VIJig);
    } // setupUi

    void retranslateUi(QWidget *VIJig)
    {
        VIJig->setWindowTitle(QApplication::translate("VIJig", "VIJig", 0, QApplication::UnicodeUTF8));
        grpGeneral->setTitle(QApplication::translate("VIJig", "General", 0, QApplication::UnicodeUTF8));
        lblAddress->setText(QApplication::translate("VIJig", "Address :", 0, QApplication::UnicodeUTF8));
        butRead->setText(QApplication::translate("VIJig", "Read", 0, QApplication::UnicodeUTF8));
        lblData->setText(QApplication::translate("VIJig", "Data :", 0, QApplication::UnicodeUTF8));
        butWrite->setText(QApplication::translate("VIJig", "Write", 0, QApplication::UnicodeUTF8));
        grpSettings->setTitle(QApplication::translate("VIJig", "Settings", 0, QApplication::UnicodeUTF8));
        lblDrRanve->setText(QApplication::translate("VIJig", "Drive Range (Vp-p)", 0, QApplication::UnicodeUTF8));
        cmbDrvVoltage->clear();
        cmbDrvVoltage->insertItems(0, QStringList()
         << QApplication::translate("VIJig", "0.5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("VIJig", "1.5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("VIJig", "3.5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("VIJig", "7", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("VIJig", "13", 0, QApplication::UnicodeUTF8)
        );
        lblSrcImped->setText(QApplication::translate("VIJig", "Source Impedance ", 0, QApplication::UnicodeUTF8));
        cmbImpedance->clear();
        cmbImpedance->insertItems(0, QStringList()
         << QApplication::translate("VIJig", "10 E", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("VIJig", "20 E", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("VIJig", "50 E", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("VIJig", "100 E", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("VIJig", "1 K", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("VIJig", "2 K", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("VIJig", "5 K", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("VIJig", "10 K", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("VIJig", "20 K", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("VIJig", "50 K", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("VIJig", "100 K", 0, QApplication::UnicodeUTF8)
        );
        lblSrcImped_2->setText(QApplication::translate("VIJig", "Frequency", 0, QApplication::UnicodeUTF8));
        cmbFrequency->clear();
        cmbFrequency->insertItems(0, QStringList()
         << QApplication::translate("VIJig", "10 Hz", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("VIJig", "20 Hz", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("VIJig", "50 Hz", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("VIJig", "100 Hz", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("VIJig", "1 KHz", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("VIJig", "2 KHz", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("VIJig", "5 KHz", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("VIJig", "10 KHz", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("VIJig", "20 KHz", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("VIJig", "50 KHz", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("VIJig", "100 KHz", 0, QApplication::UnicodeUTF8)
        );
        grpWaveWindow->setTitle(QApplication::translate("VIJig", "WaveFrom ", 0, QApplication::UnicodeUTF8));
        grpWaveConfiguration->setTitle(QString());
        lblDrvMode->setText(QApplication::translate("VIJig", "Drive Pattern", 0, QApplication::UnicodeUTF8));
        lblOffset->setText(QApplication::translate("VIJig", "Offset", 0, QApplication::UnicodeUTF8));
        lblFrequency->setText(QApplication::translate("VIJig", "Frequency", 0, QApplication::UnicodeUTF8));
        cmbPatterns->clear();
        cmbPatterns->insertItems(0, QStringList()
         << QApplication::translate("VIJig", "SINE", 0, QApplication::UnicodeUTF8)
        );
        cmbDriveMode->clear();
        cmbDriveMode->insertItems(0, QStringList()
         << QApplication::translate("VIJig", "SINGLE", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("VIJig", "CONTINUOS", 0, QApplication::UnicodeUTF8)
        );
        lblPatternType->setText(QApplication::translate("VIJig", "Pattern Type", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QString());
        lblSrcImped_3->setText(QApplication::translate("VIJig", "Wavetype", 0, QApplication::UnicodeUTF8));
        cmbFrequency_2->clear();
        cmbFrequency_2->insertItems(0, QStringList()
         << QApplication::translate("VIJig", "VI", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("VIJig", "VT", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("VIJig", "VZ", 0, QApplication::UnicodeUTF8)
        );
        butStartDrive->setText(QApplication::translate("VIJig", "START", 0, QApplication::UnicodeUTF8));
        butStopDrive->setText(QApplication::translate("VIJig", "STOP", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class VIJig: public Ui_VIJig {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIJIG_H
