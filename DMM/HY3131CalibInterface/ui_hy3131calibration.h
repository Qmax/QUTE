/********************************************************************************
** Form generated from reading UI file 'hy3131calibration.ui'
**
** Created: Thu Sep 4 15:09:03 2014
**      by: Qt User Interface Compiler version 4.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HY3131CALIBRATION_H
#define UI_HY3131CALIBRATION_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HY3131Calibration
{
public:
    QGroupBox *CalibBox;
    QWidget *gridLayoutWidget;
    QGridLayout *OffsetInput;
    QLabel *lblOffsetInfo;
    QLabel *lblOffsetValue;
    QLineEdit *leOffsetValue;
    QPushButton *pbMeasureMin;
    QPushButton *pbStopMin;
    QLabel *leOffsetMeasured;
    QLabel *lblOffsetMeasured;
    QWidget *gridLayoutWidget_2;
    QGridLayout *Select;
    QLabel *lblComponent;
    QComboBox *cmbComponent;
    QLabel *lblRange;
    QComboBox *cmbRange;
    QWidget *gridLayoutWidget_3;
    QGridLayout *MaxInput;
    QLabel *lblMaxInfo;
    QLabel *lblMaxMeasured;
    QLabel *leMaxMeasured;
    QPushButton *pbStopMax;
    QPushButton *pbMeasureMax;
    QLineEdit *leMaxValue;
    QLabel *lblMaxValue;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *Tools;
    QPushButton *calibrateBut;
    QPushButton *saveBut;
    QPushButton *exitBut;
    QFrame *line;
    QFrame *line_2;
    QFrame *line_3;
    QFrame *line_4;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *Output;
    QLabel *lblGain;
    QLineEdit *leGain;
    QLabel *lblOffset;
    QLineEdit *leOffset;
    QFrame *line_5;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *Calibrated;
    QLabel *lblCalibrated;
    QLineEdit *leCalibrated;
    QPushButton *pbMeasureCalibrated;
    QPushButton *pt6;
    QGroupBox *groupBox;
    QCheckBox *selectKeithley;
    QPushButton *KReset;
    QPushButton *KClear;
    QWidget *horizontalLayoutWidget_4;
    QHBoxLayout *horizontalLayout;
    QRadioButton *CompCalibration;
    QRadioButton *IndCalibration;

    void setupUi(QDialog *HY3131Calibration)
    {
        if (HY3131Calibration->objectName().isEmpty())
            HY3131Calibration->setObjectName(QString::fromUtf8("HY3131Calibration"));
        HY3131Calibration->resize(425, 481);
        QFont font;
        font.setFamily(QString::fromUtf8("DejaVu Sans"));
        HY3131Calibration->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/pt6.png"), QSize(), QIcon::Normal, QIcon::Off);
        HY3131Calibration->setWindowIcon(icon);
        HY3131Calibration->setStyleSheet(QString::fromUtf8("QDialog{\n"
"background-color:rgba(0,0,0,0);\n"
"}"));
        CalibBox = new QGroupBox(HY3131Calibration);
        CalibBox->setObjectName(QString::fromUtf8("CalibBox"));
        CalibBox->setGeometry(QRect(4, 0, 417, 478));
        CalibBox->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #E0E0E0, stop: 1 #FFFFFF);\n"
"     border: 1px solid #0087b4;\n"
"	border-style: dotted;    \n"
"	 border-radius: 8px;\n"
"     margin-top: 1ex; /* leave space at the top for the title */\n"
"	font:18px bold;\n"
"	color:black;\n"
" }\n"
"\n"
" QGroupBox::title {\n"
"     subcontrol-origin: margin;\n"
"     subcontrol-position: top center; /* position at the top center */\n"
"     padding: 0 3px;\n"
"	 background-color:white;\n"
"     border:1px solid #0087b4;\n"
"	border-radius:5px;\n"
"	color:green;\n"
" }"));
        gridLayoutWidget = new QWidget(CalibBox);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 118, 401, 104));
        OffsetInput = new QGridLayout(gridLayoutWidget);
        OffsetInput->setObjectName(QString::fromUtf8("OffsetInput"));
        OffsetInput->setContentsMargins(0, 0, 0, 0);
        lblOffsetInfo = new QLabel(gridLayoutWidget);
        lblOffsetInfo->setObjectName(QString::fromUtf8("lblOffsetInfo"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("DejaVu Sans"));
        font1.setPointSize(12);
        lblOffsetInfo->setFont(font1);

        OffsetInput->addWidget(lblOffsetInfo, 0, 0, 1, 4);

        lblOffsetValue = new QLabel(gridLayoutWidget);
        lblOffsetValue->setObjectName(QString::fromUtf8("lblOffsetValue"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lblOffsetValue->sizePolicy().hasHeightForWidth());
        lblOffsetValue->setSizePolicy(sizePolicy);
        lblOffsetValue->setFont(font);
        lblOffsetValue->setStyleSheet(QString::fromUtf8("color:#212121;"));

        OffsetInput->addWidget(lblOffsetValue, 1, 0, 1, 1);

        leOffsetValue = new QLineEdit(gridLayoutWidget);
        leOffsetValue->setObjectName(QString::fromUtf8("leOffsetValue"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(leOffsetValue->sizePolicy().hasHeightForWidth());
        leOffsetValue->setSizePolicy(sizePolicy1);
        leOffsetValue->setFont(font);
        leOffsetValue->setFocusPolicy(Qt::NoFocus);
        leOffsetValue->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"     border: 2px solid #0085ce;\n"
"     border-radius: 5px;\n"
"     padding: 1px 18px 1px 3px;\n"
"	background-color:white;\n"
"	color:black;\n"
" }\n"
""));

        OffsetInput->addWidget(leOffsetValue, 1, 1, 1, 1);

        pbMeasureMin = new QPushButton(gridLayoutWidget);
        pbMeasureMin->setObjectName(QString::fromUtf8("pbMeasureMin"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(1);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pbMeasureMin->sizePolicy().hasHeightForWidth());
        pbMeasureMin->setSizePolicy(sizePolicy2);
        pbMeasureMin->setFont(font);
        pbMeasureMin->setFocusPolicy(Qt::NoFocus);
        pbMeasureMin->setStyleSheet(QString::fromUtf8("QPushButton{ color:white; border: 1px solid #2D5059; border-radius: 10px; background-color: qlineargradient(x1: 0, y1: 1, x2: 1, y2: 0, stop: 0 #1A74DB, stop: 0.6 #5293DE, stop:1 #FFFFFF); max-width: 100px;}"));

        OffsetInput->addWidget(pbMeasureMin, 1, 2, 1, 1);

        pbStopMin = new QPushButton(gridLayoutWidget);
        pbStopMin->setObjectName(QString::fromUtf8("pbStopMin"));
        sizePolicy2.setHeightForWidth(pbStopMin->sizePolicy().hasHeightForWidth());
        pbStopMin->setSizePolicy(sizePolicy2);
        pbStopMin->setFont(font);
        pbStopMin->setFocusPolicy(Qt::NoFocus);
        pbStopMin->setStyleSheet(QString::fromUtf8("QPushButton{ color:white; border: 1px solid #2D5059; border-radius: 10px; background-color: qlineargradient(x1: 0, y1: 1, x2: 1, y2: 0, stop: 0 #1A74DB, stop: 0.6 #5293DE, stop:1 #FFFFFF); max-width: 100px;}"));

        OffsetInput->addWidget(pbStopMin, 2, 2, 1, 1);

        leOffsetMeasured = new QLabel(gridLayoutWidget);
        leOffsetMeasured->setObjectName(QString::fromUtf8("leOffsetMeasured"));
        sizePolicy1.setHeightForWidth(leOffsetMeasured->sizePolicy().hasHeightForWidth());
        leOffsetMeasured->setSizePolicy(sizePolicy1);
        leOffsetMeasured->setFont(font);
        leOffsetMeasured->setStyleSheet(QString::fromUtf8("QLabel {\n"
"     border: 2px solid #0085ce;\n"
"     border-radius: 5px;\n"
"     padding: 1px 18px 1px 3px;\n"
"	background-color:white;\n"
"	color:black;\n"
" }\n"
""));

        OffsetInput->addWidget(leOffsetMeasured, 2, 1, 1, 1);

        lblOffsetMeasured = new QLabel(gridLayoutWidget);
        lblOffsetMeasured->setObjectName(QString::fromUtf8("lblOffsetMeasured"));
        sizePolicy.setHeightForWidth(lblOffsetMeasured->sizePolicy().hasHeightForWidth());
        lblOffsetMeasured->setSizePolicy(sizePolicy);
        lblOffsetMeasured->setFont(font);
        lblOffsetMeasured->setStyleSheet(QString::fromUtf8("color:#212121;"));

        OffsetInput->addWidget(lblOffsetMeasured, 2, 0, 1, 1);

        gridLayoutWidget_2 = new QWidget(CalibBox);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(10, 40, 400, 31));
        Select = new QGridLayout(gridLayoutWidget_2);
        Select->setObjectName(QString::fromUtf8("Select"));
        Select->setContentsMargins(0, 0, 0, 0);
        lblComponent = new QLabel(gridLayoutWidget_2);
        lblComponent->setObjectName(QString::fromUtf8("lblComponent"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(lblComponent->sizePolicy().hasHeightForWidth());
        lblComponent->setSizePolicy(sizePolicy3);
        lblComponent->setFont(font);
        lblComponent->setStyleSheet(QString::fromUtf8("color:#212121;"));

        Select->addWidget(lblComponent, 0, 0, 1, 1);

        cmbComponent = new QComboBox(gridLayoutWidget_2);
        cmbComponent->setObjectName(QString::fromUtf8("cmbComponent"));
        sizePolicy3.setHeightForWidth(cmbComponent->sizePolicy().hasHeightForWidth());
        cmbComponent->setSizePolicy(sizePolicy3);
        cmbComponent->setFont(font);
        cmbComponent->setFocusPolicy(Qt::NoFocus);
        cmbComponent->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"     border: 2px solid #0085ce;\n"
"     border-radius: 5px;\n"
"     padding: 1px 18px 1px 3px;\n"
"	background-color:white;\n"
"	color:black;\n"
" }\n"
""));

        Select->addWidget(cmbComponent, 0, 1, 1, 1);

        lblRange = new QLabel(gridLayoutWidget_2);
        lblRange->setObjectName(QString::fromUtf8("lblRange"));
        sizePolicy3.setHeightForWidth(lblRange->sizePolicy().hasHeightForWidth());
        lblRange->setSizePolicy(sizePolicy3);
        lblRange->setFont(font);
        lblRange->setStyleSheet(QString::fromUtf8("color:#212121;"));

        Select->addWidget(lblRange, 0, 2, 1, 1);

        cmbRange = new QComboBox(gridLayoutWidget_2);
        cmbRange->setObjectName(QString::fromUtf8("cmbRange"));
        cmbRange->setEnabled(true);
        sizePolicy3.setHeightForWidth(cmbRange->sizePolicy().hasHeightForWidth());
        cmbRange->setSizePolicy(sizePolicy3);
        cmbRange->setFont(font);
        cmbRange->setFocusPolicy(Qt::NoFocus);
        cmbRange->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"     border: 2px solid #0085ce;\n"
"     border-radius: 5px;\n"
"     padding: 1px 18px 1px 3px;\n"
"	background-color:white;\n"
"	color:black;\n"
" }\n"
""));

        Select->addWidget(cmbRange, 0, 3, 1, 1);

        gridLayoutWidget_3 = new QWidget(CalibBox);
        gridLayoutWidget_3->setObjectName(QString::fromUtf8("gridLayoutWidget_3"));
        gridLayoutWidget_3->setGeometry(QRect(10, 230, 401, 100));
        MaxInput = new QGridLayout(gridLayoutWidget_3);
        MaxInput->setObjectName(QString::fromUtf8("MaxInput"));
        MaxInput->setContentsMargins(0, 0, 0, 0);
        lblMaxInfo = new QLabel(gridLayoutWidget_3);
        lblMaxInfo->setObjectName(QString::fromUtf8("lblMaxInfo"));
        lblMaxInfo->setFont(font1);

        MaxInput->addWidget(lblMaxInfo, 0, 0, 1, 4);

        lblMaxMeasured = new QLabel(gridLayoutWidget_3);
        lblMaxMeasured->setObjectName(QString::fromUtf8("lblMaxMeasured"));
        sizePolicy.setHeightForWidth(lblMaxMeasured->sizePolicy().hasHeightForWidth());
        lblMaxMeasured->setSizePolicy(sizePolicy);
        lblMaxMeasured->setFont(font);
        lblMaxMeasured->setStyleSheet(QString::fromUtf8("color:#212121;"));

        MaxInput->addWidget(lblMaxMeasured, 2, 0, 1, 1);

        leMaxMeasured = new QLabel(gridLayoutWidget_3);
        leMaxMeasured->setObjectName(QString::fromUtf8("leMaxMeasured"));
        sizePolicy1.setHeightForWidth(leMaxMeasured->sizePolicy().hasHeightForWidth());
        leMaxMeasured->setSizePolicy(sizePolicy1);
        leMaxMeasured->setFont(font);
        leMaxMeasured->setStyleSheet(QString::fromUtf8("QLabel {\n"
"     border: 2px solid #0085ce;\n"
"     border-radius: 5px;\n"
"     padding: 1px 18px 1px 3px;\n"
"	background-color:white;\n"
"	color:black;\n"
" }\n"
""));

        MaxInput->addWidget(leMaxMeasured, 2, 1, 1, 1);

        pbStopMax = new QPushButton(gridLayoutWidget_3);
        pbStopMax->setObjectName(QString::fromUtf8("pbStopMax"));
        sizePolicy2.setHeightForWidth(pbStopMax->sizePolicy().hasHeightForWidth());
        pbStopMax->setSizePolicy(sizePolicy2);
        pbStopMax->setFont(font);
        pbStopMax->setFocusPolicy(Qt::NoFocus);
        pbStopMax->setStyleSheet(QString::fromUtf8("QPushButton{ color:white; border: 1px solid #2D5059; border-radius: 10px; background-color: qlineargradient(x1: 0, y1: 1, x2: 1, y2: 0, stop: 0 #1A74DB, stop: 0.6 #5293DE, stop:1 #FFFFFF); max-width: 100px;}"));

        MaxInput->addWidget(pbStopMax, 2, 2, 1, 1);

        pbMeasureMax = new QPushButton(gridLayoutWidget_3);
        pbMeasureMax->setObjectName(QString::fromUtf8("pbMeasureMax"));
        sizePolicy2.setHeightForWidth(pbMeasureMax->sizePolicy().hasHeightForWidth());
        pbMeasureMax->setSizePolicy(sizePolicy2);
        pbMeasureMax->setFont(font);
        pbMeasureMax->setFocusPolicy(Qt::NoFocus);
        pbMeasureMax->setStyleSheet(QString::fromUtf8("QPushButton{ color:white; border: 1px solid #2D5059; border-radius: 10px; background-color: qlineargradient(x1: 0, y1: 1, x2: 1, y2: 0, stop: 0 #1A74DB, stop: 0.6 #5293DE, stop:1 #FFFFFF); max-width: 100px;}"));

        MaxInput->addWidget(pbMeasureMax, 1, 2, 1, 1);

        leMaxValue = new QLineEdit(gridLayoutWidget_3);
        leMaxValue->setObjectName(QString::fromUtf8("leMaxValue"));
        sizePolicy1.setHeightForWidth(leMaxValue->sizePolicy().hasHeightForWidth());
        leMaxValue->setSizePolicy(sizePolicy1);
        leMaxValue->setFont(font);
        leMaxValue->setFocusPolicy(Qt::NoFocus);
        leMaxValue->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"     border: 2px solid #0085ce;\n"
"     border-radius: 5px;\n"
"     padding: 1px 18px 1px 3px;\n"
"	background-color:white;\n"
"	color:black;\n"
" }\n"
""));

        MaxInput->addWidget(leMaxValue, 1, 1, 1, 1);

        lblMaxValue = new QLabel(gridLayoutWidget_3);
        lblMaxValue->setObjectName(QString::fromUtf8("lblMaxValue"));
        sizePolicy.setHeightForWidth(lblMaxValue->sizePolicy().hasHeightForWidth());
        lblMaxValue->setSizePolicy(sizePolicy);
        lblMaxValue->setFont(font);
        lblMaxValue->setStyleSheet(QString::fromUtf8("color:#212121;"));

        MaxInput->addWidget(lblMaxValue, 1, 0, 1, 1);

        horizontalLayoutWidget = new QWidget(CalibBox);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(231, 422, 180, 51));
        Tools = new QHBoxLayout(horizontalLayoutWidget);
        Tools->setObjectName(QString::fromUtf8("Tools"));
        Tools->setContentsMargins(0, 0, 0, 0);
        calibrateBut = new QPushButton(horizontalLayoutWidget);
        calibrateBut->setObjectName(QString::fromUtf8("calibrateBut"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(calibrateBut->sizePolicy().hasHeightForWidth());
        calibrateBut->setSizePolicy(sizePolicy4);
        calibrateBut->setFont(font1);
        calibrateBut->setFocusPolicy(Qt::NoFocus);
        calibrateBut->setStyleSheet(QString::fromUtf8("QPushButton { border: 2px solid rgba(0,0,0,0); border-radius: 25px; background-color: rgba(0,0,0,0); }"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Images/calibrate.png"), QSize(), QIcon::Normal, QIcon::Off);
        calibrateBut->setIcon(icon1);
        calibrateBut->setIconSize(QSize(40, 40));

        Tools->addWidget(calibrateBut);

        saveBut = new QPushButton(horizontalLayoutWidget);
        saveBut->setObjectName(QString::fromUtf8("saveBut"));
        sizePolicy4.setHeightForWidth(saveBut->sizePolicy().hasHeightForWidth());
        saveBut->setSizePolicy(sizePolicy4);
        saveBut->setFont(font1);
        saveBut->setFocusPolicy(Qt::NoFocus);
        saveBut->setStyleSheet(QString::fromUtf8("QPushButton { border: 2px solid rgba(0,0,0,0); border-radius: 25px; background-color: rgba(0,0,0,0); }"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Images/images.png"), QSize(), QIcon::Normal, QIcon::Off);
        saveBut->setIcon(icon2);
        saveBut->setIconSize(QSize(35, 35));

        Tools->addWidget(saveBut);

        exitBut = new QPushButton(horizontalLayoutWidget);
        exitBut->setObjectName(QString::fromUtf8("exitBut"));
        sizePolicy4.setHeightForWidth(exitBut->sizePolicy().hasHeightForWidth());
        exitBut->setSizePolicy(sizePolicy4);
        exitBut->setFont(font1);
        exitBut->setFocusPolicy(Qt::NoFocus);
        exitBut->setStyleSheet(QString::fromUtf8("QPushButton { border: 2px solid rgba(0,0,0,0); border-radius: 25px; background-color: rgba(0,0,0,0); }"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Images/logout-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        exitBut->setIcon(icon3);
        exitBut->setIconSize(QSize(45, 45));

        Tools->addWidget(exitBut);

        line = new QFrame(CalibBox);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(15, 110, 390, 3));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(CalibBox);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(15, 226, 390, 3));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(CalibBox);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(15, 335, 390, 3));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        line_4 = new QFrame(CalibBox);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setGeometry(QRect(15, 378, 390, 3));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        horizontalLayoutWidget_2 = new QWidget(CalibBox);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(11, 343, 400, 30));
        Output = new QHBoxLayout(horizontalLayoutWidget_2);
        Output->setObjectName(QString::fromUtf8("Output"));
        Output->setContentsMargins(0, 0, 0, 0);
        lblGain = new QLabel(horizontalLayoutWidget_2);
        lblGain->setObjectName(QString::fromUtf8("lblGain"));
        sizePolicy.setHeightForWidth(lblGain->sizePolicy().hasHeightForWidth());
        lblGain->setSizePolicy(sizePolicy);
        lblGain->setFont(font);
        lblGain->setStyleSheet(QString::fromUtf8("color:#212121;"));

        Output->addWidget(lblGain);

        leGain = new QLineEdit(horizontalLayoutWidget_2);
        leGain->setObjectName(QString::fromUtf8("leGain"));
        sizePolicy1.setHeightForWidth(leGain->sizePolicy().hasHeightForWidth());
        leGain->setSizePolicy(sizePolicy1);
        leGain->setFont(font);
        leGain->setFocusPolicy(Qt::NoFocus);
        leGain->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"     border: 2px solid #0085ce;\n"
"     border-radius: 5px;\n"
"     padding: 1px 18px 1px 3px;\n"
"	background-color:white;\n"
"	color:black;\n"
" }\n"
""));

        Output->addWidget(leGain);

        lblOffset = new QLabel(horizontalLayoutWidget_2);
        lblOffset->setObjectName(QString::fromUtf8("lblOffset"));
        sizePolicy.setHeightForWidth(lblOffset->sizePolicy().hasHeightForWidth());
        lblOffset->setSizePolicy(sizePolicy);
        lblOffset->setFont(font);
        lblOffset->setStyleSheet(QString::fromUtf8("color:#212121;"));

        Output->addWidget(lblOffset);

        leOffset = new QLineEdit(horizontalLayoutWidget_2);
        leOffset->setObjectName(QString::fromUtf8("leOffset"));
        sizePolicy1.setHeightForWidth(leOffset->sizePolicy().hasHeightForWidth());
        leOffset->setSizePolicy(sizePolicy1);
        leOffset->setFont(font);
        leOffset->setFocusPolicy(Qt::NoFocus);
        leOffset->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"     border: 2px solid #0085ce;\n"
"     border-radius: 5px;\n"
"     padding: 1px 18px 1px 3px;\n"
"	background-color:white;\n"
"	color:black;\n"
" }\n"
""));

        Output->addWidget(leOffset);

        line_5 = new QFrame(CalibBox);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setGeometry(QRect(15, 416, 390, 3));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);
        horizontalLayoutWidget_3 = new QWidget(CalibBox);
        horizontalLayoutWidget_3->setObjectName(QString::fromUtf8("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(11, 383, 400, 30));
        Calibrated = new QHBoxLayout(horizontalLayoutWidget_3);
        Calibrated->setObjectName(QString::fromUtf8("Calibrated"));
        Calibrated->setContentsMargins(0, 0, 0, 0);
        lblCalibrated = new QLabel(horizontalLayoutWidget_3);
        lblCalibrated->setObjectName(QString::fromUtf8("lblCalibrated"));
        sizePolicy.setHeightForWidth(lblCalibrated->sizePolicy().hasHeightForWidth());
        lblCalibrated->setSizePolicy(sizePolicy);
        lblCalibrated->setFont(font);
        lblCalibrated->setStyleSheet(QString::fromUtf8("color:#212121;"));

        Calibrated->addWidget(lblCalibrated);

        leCalibrated = new QLineEdit(horizontalLayoutWidget_3);
        leCalibrated->setObjectName(QString::fromUtf8("leCalibrated"));
        sizePolicy1.setHeightForWidth(leCalibrated->sizePolicy().hasHeightForWidth());
        leCalibrated->setSizePolicy(sizePolicy1);
        leCalibrated->setFont(font);
        leCalibrated->setFocusPolicy(Qt::NoFocus);
        leCalibrated->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"     border: 2px solid #0085ce;\n"
"     border-radius: 5px;\n"
"     padding: 1px 18px 1px 3px;\n"
"	background-color:white;\n"
"	color:black;\n"
" }\n"
""));

        Calibrated->addWidget(leCalibrated);

        pbMeasureCalibrated = new QPushButton(horizontalLayoutWidget_3);
        pbMeasureCalibrated->setObjectName(QString::fromUtf8("pbMeasureCalibrated"));
        sizePolicy2.setHeightForWidth(pbMeasureCalibrated->sizePolicy().hasHeightForWidth());
        pbMeasureCalibrated->setSizePolicy(sizePolicy2);
        pbMeasureCalibrated->setFont(font);
        pbMeasureCalibrated->setFocusPolicy(Qt::NoFocus);
        pbMeasureCalibrated->setStyleSheet(QString::fromUtf8("QPushButton{ color:white; border: 1px solid #2D5059; border-radius: 10px; background-color: qlineargradient(x1: 0, y1: 1, x2: 1, y2: 0, stop: 0 #1A74DB, stop: 0.6 #5293DE, stop:1 #FFFFFF); max-width: 100px;}"));

        Calibrated->addWidget(pbMeasureCalibrated);

        pt6 = new QPushButton(CalibBox);
        pt6->setObjectName(QString::fromUtf8("pt6"));
        pt6->setGeometry(QRect(8, 5, 41, 41));
        sizePolicy4.setHeightForWidth(pt6->sizePolicy().hasHeightForWidth());
        pt6->setSizePolicy(sizePolicy4);
        pt6->setFont(font1);
        pt6->setFocusPolicy(Qt::NoFocus);
        pt6->setStyleSheet(QString::fromUtf8("QPushButton { border: 2px solid rgba(0,0,0,0); border-radius: 25px; background-color: rgba(0,0,0,0); }"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/Images/pt6.png"), QSize(), QIcon::Normal, QIcon::Off);
        pt6->setIcon(icon4);
        pt6->setIconSize(QSize(40, 40));
        groupBox = new QGroupBox(CalibBox);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(11, 421, 200, 50));
        groupBox->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"     background-color: rgba(0,0,0,0);\n"
"     border: 1px solid gray;\n"
"	 border-radius: 1px;\n"
"     margin-top: 1ex; /* leave space at the top for the title */\n"
"	font:1px bold;\n"
" }\n"
"\n"
" QGroupBox::title {\n"
"     subcontrol-origin: margin;\n"
"     subcontrol-position: top center; /* position at the top center */\n"
"     padding: 0 1px;\n"
"	 background-color:white;\n"
"     border:1px solid #0087b4;\n"
"	border-radius:1px;\n"
"	color:green;\n"
" }"));
        selectKeithley = new QCheckBox(groupBox);
        selectKeithley->setObjectName(QString::fromUtf8("selectKeithley"));
        selectKeithley->setGeometry(QRect(5, 7, 110, 40));
        selectKeithley->setFocusPolicy(Qt::NoFocus);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/Images/keithley.png"), QSize(), QIcon::Normal, QIcon::Off);
        selectKeithley->setIcon(icon5);
        selectKeithley->setIconSize(QSize(80, 80));
        KReset = new QPushButton(groupBox);
        KReset->setObjectName(QString::fromUtf8("KReset"));
        KReset->setGeometry(QRect(149, 12, 40, 30));
        sizePolicy4.setHeightForWidth(KReset->sizePolicy().hasHeightForWidth());
        KReset->setSizePolicy(sizePolicy4);
        KReset->setFont(font1);
        KReset->setFocusPolicy(Qt::NoFocus);
        KReset->setStyleSheet(QString::fromUtf8("QPushButton { border: 2px solid rgba(0,0,0,0); border-radius: 25px; background-color: rgba(0,0,0,0); }"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/Images/reset.png"), QSize(), QIcon::Normal, QIcon::Off);
        KReset->setIcon(icon6);
        KReset->setIconSize(QSize(40, 40));
        KClear = new QPushButton(groupBox);
        KClear->setObjectName(QString::fromUtf8("KClear"));
        KClear->setGeometry(QRect(117, 5, 30, 40));
        sizePolicy4.setHeightForWidth(KClear->sizePolicy().hasHeightForWidth());
        KClear->setSizePolicy(sizePolicy4);
        KClear->setFont(font1);
        KClear->setFocusPolicy(Qt::NoFocus);
        KClear->setStyleSheet(QString::fromUtf8("QPushButton { border: 2px solid rgba(0,0,0,0); border-radius: 25px; background-color: rgba(0,0,0,0); }"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/Images/clear.png"), QSize(), QIcon::Normal, QIcon::Off);
        KClear->setIcon(icon7);
        KClear->setIconSize(QSize(40, 40));
        horizontalLayoutWidget_4 = new QWidget(CalibBox);
        horizontalLayoutWidget_4->setObjectName(QString::fromUtf8("horizontalLayoutWidget_4"));
        horizontalLayoutWidget_4->setGeometry(QRect(10, 77, 400, 30));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget_4);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        CompCalibration = new QRadioButton(horizontalLayoutWidget_4);
        CompCalibration->setObjectName(QString::fromUtf8("CompCalibration"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("DejaVu Sans"));
        font2.setPointSize(10);
        font2.setBold(true);
        font2.setWeight(75);
        CompCalibration->setFont(font2);

        horizontalLayout->addWidget(CompCalibration);

        IndCalibration = new QRadioButton(horizontalLayoutWidget_4);
        IndCalibration->setObjectName(QString::fromUtf8("IndCalibration"));
        IndCalibration->setFont(font2);
        IndCalibration->setChecked(true);

        horizontalLayout->addWidget(IndCalibration);


        retranslateUi(HY3131Calibration);

        QMetaObject::connectSlotsByName(HY3131Calibration);
    } // setupUi

    void retranslateUi(QDialog *HY3131Calibration)
    {
        HY3131Calibration->setWindowTitle(QApplication::translate("HY3131Calibration", "HY3131 Calibration Panel", 0, QApplication::UnicodeUTF8));
        CalibBox->setTitle(QApplication::translate("HY3131Calibration", "HY3131 CALIBRATION PANEL", 0, QApplication::UnicodeUTF8));
        lblOffsetInfo->setText(QString());
        lblOffsetValue->setText(QApplication::translate("HY3131Calibration", "Offset Input:", 0, QApplication::UnicodeUTF8));
        pbMeasureMin->setText(QApplication::translate("HY3131Calibration", "Measure", 0, QApplication::UnicodeUTF8));
        pbStopMin->setText(QApplication::translate("HY3131Calibration", "Next", 0, QApplication::UnicodeUTF8));
        leOffsetMeasured->setText(QString());
        lblOffsetMeasured->setText(QApplication::translate("HY3131Calibration", "Measured:", 0, QApplication::UnicodeUTF8));
        lblComponent->setText(QApplication::translate("HY3131Calibration", "Component:", 0, QApplication::UnicodeUTF8));
        lblRange->setText(QApplication::translate("HY3131Calibration", "Range:", 0, QApplication::UnicodeUTF8));
        lblMaxInfo->setText(QString());
        lblMaxMeasured->setText(QApplication::translate("HY3131Calibration", "Measured:", 0, QApplication::UnicodeUTF8));
        leMaxMeasured->setText(QString());
        pbStopMax->setText(QApplication::translate("HY3131Calibration", "Next", 0, QApplication::UnicodeUTF8));
        pbMeasureMax->setText(QApplication::translate("HY3131Calibration", "Measure", 0, QApplication::UnicodeUTF8));
        lblMaxValue->setText(QApplication::translate("HY3131Calibration", "Max Input:", 0, QApplication::UnicodeUTF8));
        calibrateBut->setText(QString());
        saveBut->setText(QString());
        exitBut->setText(QString());
        lblGain->setText(QApplication::translate("HY3131Calibration", "Gain :", 0, QApplication::UnicodeUTF8));
        lblOffset->setText(QApplication::translate("HY3131Calibration", "Offset :", 0, QApplication::UnicodeUTF8));
        lblCalibrated->setText(QApplication::translate("HY3131Calibration", "Calibrated Value:", 0, QApplication::UnicodeUTF8));
        pbMeasureCalibrated->setText(QApplication::translate("HY3131Calibration", "Measure", 0, QApplication::UnicodeUTF8));
        pt6->setText(QString());
        groupBox->setTitle(QString());
        selectKeithley->setText(QString());
        KReset->setText(QString());
        KClear->setText(QString());
        CompCalibration->setText(QApplication::translate("HY3131Calibration", "Complete Calibration", 0, QApplication::UnicodeUTF8));
        IndCalibration->setText(QApplication::translate("HY3131Calibration", "Individual Calibration", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class HY3131Calibration: public Ui_HY3131Calibration {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HY3131CALIBRATION_H
