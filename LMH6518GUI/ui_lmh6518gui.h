/********************************************************************************
** Form generated from reading UI file 'lmh6518gui.ui'
**
** Created: Tue Sep 30 16:45:47 2014
**      by: Qt User Interface Compiler version 4.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LMH6518GUI_H
#define UI_LMH6518GUI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDial>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSlider>
#include <QtGui/QTabWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LMH6518GUI
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGroupBox *groupBox_3;
    QLabel *label_3;
    QPushButton *Read;
    QLabel *label_2;
    QLabel *lblVoltage;
    QComboBox *Filter;
    QLabel *label_6;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *totalGaindB;
    QSlider *Attenuater;
    QPushButton *Exit;
    QLabel *label;
    QComboBox *PreAmpGain;
    QPushButton *Write;
    QComboBox *Voltage;
    QLineEdit *ladder;
    QLineEdit *TotalGain;
    QComboBox *PowerMode;
    QPushButton *Calculate;
    QLineEdit *Data;
    QLabel *label_16;
    QLineEdit *totalGainV;
    QLabel *label_17;
    QComboBox *ChannelSel;
    QLabel *lblChannel;
    QGroupBox *groupBox_8;
    QComboBox *cmbCouplingR1;
    QGroupBox *groupBox_9;
    QComboBox *cmbCouplingR2;
    QGroupBox *groupBox_7;
    QCheckBox *chkR1;
    QCheckBox *chkR2;
    QGroupBox *m_tabDAC;
    QRadioButton *m_rbDACA;
    QRadioButton *m_rbDACB;
    QRadioButton *m_rbDACC;
    QRadioButton *m_rbDACD;
    QRadioButton *m_rbDACE;
    QLineEdit *m_leDACValue;
    QGroupBox *grpCH1;
    QCheckBox *chkCH1Even;
    QCheckBox *chkCH1Odd;
    QGroupBox *grpCH2;
    QCheckBox *chkCH2Odd;
    QCheckBox *chkCH2Even;
    QWidget *tab_2;
    QGroupBox *grpTime;
    QComboBox *cmbTimeBase;
    QComboBox *cmbTimeUnit;
    QDial *timebaseDial;
    QLabel *lblTimeBase;
    QPushButton *butOffset;
    QGroupBox *groupBox_5;
    QRadioButton *optSingle;
    QRadioButton *optAuto;
    QRadioButton *optNormal;
    QPushButton *butRUN;
    QPushButton *butSTOP;
    QGroupBox *grpTimeSettings;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *leBTUR;
    QLineEdit *leBDR;
    QGroupBox *grpSamples;
    QLabel *label_9;
    QLabel *label_10;
    QLineEdit *lePosTrigger;
    QLineEdit *lePreTrigger;
    QGroupBox *groupBox_6;
    QPushButton *butForceTrigger;
    QComboBox *cmbChannel;
    QComboBox *cmbTriggerSoruce;
    QGroupBox *grpMemory;
    QComboBox *cmbMemory;
    QDoubleSpinBox *dblHorizontalTrigger;
    QLabel *label_21;
    QComboBox *cmbSamples;
    QCheckBox *chkInt_Ext;
    QDial *memoryDial;
    QLabel *lblSamples;
    QLabel *label_11;
    QLabel *label_13;
    QLineEdit *leDispFreq;
    QLineEdit *leDispTSamples;
    QGroupBox *groupBox;
    QLabel *label_18;
    QDoubleSpinBox *dblVerticalTrigger;
    QLabel *label_20;
    QComboBox *cmbLMHVoltage;
    QLineEdit *leGainDB;
    QLabel *label_22;
    QLabel *label_23;
    QLineEdit *leTotalV;
    QComboBox *LMHFilter;
    QLabel *label_24;
    QComboBox *LMHPowerMode;
    QLabel *label_25;
    QWidget *graphW;
    QPushButton *butSerialPanel;
    QLineEdit *leStatus;
    QWidget *ch1Widget;
    QWidget *tab_3;
    QGroupBox *PARAMETRS;
    QLineEdit *leamplitude;
    QLineEdit *lephase;
    QLabel *label_12;
    QLineEdit *leoffset;
    QLabel *label_14;
    QLabel *label_15;
    QLineEdit *lefrequency;
    QLabel *label_19;
    QGroupBox *DRIVE_MODE;
    QRadioButton *burstWave;
    QRadioButton *continuousWave;
    QRadioButton *singleWave;
    QGroupBox *WAVE_TYPE;
    QRadioButton *triangle;
    QRadioButton *square;
    QRadioButton *sine;
    QRadioButton *ramp;
    QGroupBox *RUN_STOP;
    QPushButton *startDrive;
    QPushButton *stopDrive;
    QPushButton *pushButton;
    QGroupBox *DSOParameters;
    QLabel *label_26;
    QComboBox *cmbSamplingType;
    QWidget *tab_4;

    void setupUi(QMainWindow *LMH6518GUI)
    {
        if (LMH6518GUI->objectName().isEmpty())
            LMH6518GUI->setObjectName(QString::fromUtf8("LMH6518GUI"));
        LMH6518GUI->resize(800, 600);
        LMH6518GUI->setStyleSheet(QString::fromUtf8("QLineEdit{border-width: 2px;border-style: outset;border-color: gray; border-radius: 2px;  padding: 0 8px;     background: black;     selection-background-color: yellow;   color:white;     font: 14px;}\n"
"\n"
"QLineEdit:disabled{border-width: 2px;border-style: outset;border-color: gray; border-radius: 2px;  padding: 0 8px;     background: gray;     selection-background-color: yellow;   color:white;     font: 14px;}\n"
"\n"
"QGroupBox{ \n"
"background:qlineargradient(\n"
"x1: 0, y1: 0, x2: 1, y2: 1, \n"
"stop: 0 #a9aa96,stop: 0.2 #bab9a9,\n"
"stop: 0.4 #d8d7c8,stop: 0.6 #a9aa96, \n"
"stop: 0.8 #bab9a9,stop: 1 #717164); \n"
"border:2px solid white;\n"
"border-radius:20px; }\n"
" QGroupBox::title {\n"
"	border:rgba(0,0,0,0);\n"
"	border-radius:8px;\n"
"     subcontrol-origin: margin;\n"
"     subcontrol-position: top middle; \n"
"     padding: 0 20px;\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #d8dff2, stop: 1 #FFFFFF);\n"
" }\n"
"QPus"
                        "hButton{\n"
"color:white;\n"
"border: 1px solid #2D5059;\n"
"background-color: \n"
"qlineargradient(x1: 0, y1: 1, x2: 1, y2: 0,\n"
"stop: 0 #1A74DB, \n"
"stop: 0.6 #5293DE, \n"
"stop:1 #FFFFFF);\n"
"}\n"
"\n"
"QComboBox{border: 2px solid gray;border-radius: 10px;color:black;}\n"
"\n"
"QToolButton {border: 1px solid black; border-radius: 5px;font:18px bold;background-color:rgba(170,170,170,255);}\n"
"\n"
"QSpinBox{border: 2px solid gray;border-radius: 10px;color:black;}\n"
"\n"
"QDoubleSpinBox{border: 2px solid gray;border-radius: 10px;color:black;}\n"
"\n"
"QCheckBox{font: bold 14px;} QCheckBox::indicator {width:20px;height:20px;border: 2px solid black;border-radius:1; } QCheckBox::indicator::unchecked {background-color:white;}QCheckBox::indicator:unchecked:hover {background-color:white; }\n"
"QCheckBox::indicator:unchecked:pressed {	background-color:white; }\n"
"QCheckBox::indicator::checked {background-color:#f2a400;}  QCheckBox::indicator:checked:hover {background-color:#f2a400;}\n"
"QCheckBox::indicator:ch"
                        "ecked:pressed {	background-color:#f2a400;}\n"
"\n"
"QLabel{font:bold 14px;color:black;}\n"
"QRadioButton{\n"
"font:14px;\n"
"color:white;\n"
"}\n"
" QRadioButton::indicator {\n"
"     width: 15px;\n"
"     height:15px;\n"
"   border: 1px solid black;\n"
"	 border-radius:8px;\n"
"\n"
" }\n"
" QRadioButton::indicator::unchecked {\n"
"		background-color:white;\n"
"     }\n"
"\n"
"     QRadioButton::indicator:unchecked:hover {\n"
"		background-color:white;\n"
"     }\n"
"\n"
"     QRadioButton::indicator:unchecked:pressed {\n"
"		background-color:white;\n"
"     }\n"
"\n"
"     QRadioButton::indicator::checked {\n"
"		background-color:#f2a400;\n"
"     }\n"
"\n"
"     QRadioButton::indicator:checked:hover {\n"
"		background-color:#f2a400;\n"
"     }\n"
"\n"
"     QRadioButton::indicator:checked:pressed {\n"
"		background-color:#f2a400;\n"
"     }\n"
"\n"
""));
        centralWidget = new QWidget(LMH6518GUI);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(0, 10, 791, 571));
        QFont font;
        font.setFamily(QString::fromUtf8("DejaVu Sans"));
        font.setBold(true);
        font.setWeight(75);
        tabWidget->setFont(font);
        tabWidget->setStyleSheet(QString::fromUtf8("QLineEdit{border-width: 2px;border-style: outset;border-color: gray; border-radius: 1px;  padding: 0 8px;     background: black;     selection-background-color: yellow;   color:white;     font: bold 14px;}\n"
"\n"
"QPushButton {border: 2px solid #8f8f91; border-radius: 8px; background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #f6f7fa, stop: 1 #dadbde); color:blue;} QPushButton:pressed {background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #dadbde, stop: 1 #f6f7fa);} QPushButton:flat {border: none;} QPushButton:default {border-color: navy;}\n"
"\n"
"QComboBox{border: 2px solid gray;border-radius: 10px;color:black;}"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        groupBox_3 = new QGroupBox(tab);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(20, 12, 740, 361));
        QFont font1;
        font1.setBold(true);
        font1.setItalic(false);
        font1.setWeight(75);
        groupBox_3->setFont(font1);
        groupBox_3->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"   background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #4a79b5, stop: 1 #0f0f0f);\n"
"/*                                       stop: 0 #3a5976, stop: 1 #000000);*/\n"
"     border: 2px solid gray;\n"
"     border-radius: 5px;\n"
"     margin-top: 1ex; /* leave space at the top for the title */\n"
"	 font:bold 16px;	\n"
" }\n"
"\n"
" QGroupBox::title {\n"
"	border:2px solid white;\n"
"	border-radius:5px;\n"
"     subcontrol-origin: margin;\n"
"     subcontrol-position: top left; /* position at the top center */\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #d8dff2, stop: 1 #FFFFFF);\n"
" }\n"
"QLabel{\n"
"	color:white;\n"
"}<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"
"<ui version=\"4.0\">\n"
" <widget name=\"__qt_fake_top_level\">\n"
"  <widget class=\"QLabel\" name=\"label_3\">\n"
"   <property name=\"geometry\">\n"
"    <rect>\n"
"     <x>10</x>\n"
"     <y"
                        ">145</y>\n"
"     <width>39</width>\n"
"     <height>17</height>\n"
"    </rect>\n"
"   </property>\n"
"   <property name=\"sizePolicy\">\n"
"    <sizepolicy hsizetype=\"Fixed\" vsizetype=\"Fixed\">\n"
"     <horstretch>0</horstretch>\n"
"     <verstretch>0</verstretch>\n"
"    </sizepolicy>\n"
"   </property>\n"
"   <property name=\"font\">\n"
"    <font>\n"
"     <weight>75</weight>\n"
"     <bold>true</bold>\n"
"    </font>\n"
"   </property>\n"
"   <property name=\"text\">\n"
"    <string>Filter</string>\n"
"   </property>\n"
"   <property name=\"alignment\">\n"
"    <set>Qt::AlignCenter</set>\n"
"   </property>\n"
"  </widget>\n"
"  <widget class=\"QPushButton\" name=\"Read\">\n"
"   <property name=\"geometry\">\n"
"    <rect>\n"
"     <x>250</x>\n"
"     <y>280</y>\n"
"     <width>100</width>\n"
"     <height>40</height>\n"
"    </rect>\n"
"   </property>\n"
"   <property name=\"text\">\n"
"    <string>&amp;Read</string>\n"
"   </property>\n"
"  </widget>\n"
"  <widget class=\"QLabel\" name=\"label_2\">\n"
""
                        "   <property name=\"geometry\">\n"
"    <rect>\n"
"     <x>32</x>\n"
"     <y>216</y>\n"
"     <width>72</width>\n"
"     <height>17</height>\n"
"    </rect>\n"
"   </property>\n"
"   <property name=\"sizePolicy\">\n"
"    <sizepolicy hsizetype=\"Fixed\" vsizetype=\"Fixed\">\n"
"     <horstretch>0</horstretch>\n"
"     <verstretch>0</verstretch>\n"
"    </sizepolicy>\n"
"   </property>\n"
"   <property name=\"font\">\n"
"    <font>\n"
"     <weight>75</weight>\n"
"     <bold>true</bold>\n"
"    </font>\n"
"   </property>\n"
"   <property name=\"text\">\n"
"    <string>Total Gain</string>\n"
"   </property>\n"
"   <property name=\"alignment\">\n"
"    <set>Qt::AlignCenter</set>\n"
"   </property>\n"
"  </widget>\n"
"  <widget class=\"QLabel\" name=\"lblVoltage\">\n"
"   <property name=\"geometry\">\n"
"    <rect>\n"
"     <x>292</x>\n"
"     <y>145</y>\n"
"     <width>70</width>\n"
"     <height>17</height>\n"
"    </rect>\n"
"   </property>\n"
"   <property name=\"sizePolicy\">\n"
"    <sizepolicy hsizetype=\""
                        "Fixed\" vsizetype=\"Fixed\">\n"
"     <horstretch>0</horstretch>\n"
"     <verstretch>0</verstretch>\n"
"    </sizepolicy>\n"
"   </property>\n"
"   <property name=\"font\">\n"
"    <font>\n"
"     <weight>75</weight>\n"
"     <bold>true</bold>\n"
"    </font>\n"
"   </property>\n"
"   <property name=\"text\">\n"
"    <string>Voltage</string>\n"
"   </property>\n"
"   <property name=\"alignment\">\n"
"    <set>Qt::AlignCenter</set>\n"
"   </property>\n"
"  </widget>\n"
"  <widget class=\"QComboBox\" name=\"Filter\">\n"
"   <property name=\"geometry\">\n"
"    <rect>\n"
"     <x>118</x>\n"
"     <y>140</y>\n"
"     <width>150</width>\n"
"     <height>27</height>\n"
"    </rect>\n"
"   </property>\n"
"   <item>\n"
"    <property name=\"text\">\n"
"     <string>Full</string>\n"
"    </property>\n"
"   </item>\n"
"   <item>\n"
"    <property name=\"text\">\n"
"     <string>20</string>\n"
"    </property>\n"
"   </item>\n"
"   <item>\n"
"    <property name=\"text\">\n"
"     <string>100</string>\n"
"    </property>"
                        "\n"
"   </item>\n"
"   <item>\n"
"    <property name=\"text\">\n"
"     <string>200</string>\n"
"    </property>\n"
"   </item>\n"
"   <item>\n"
"    <property name=\"text\">\n"
"     <string>350</string>\n"
"    </property>\n"
"   </item>\n"
"   <item>\n"
"    <property name=\"text\">\n"
"     <string>650</string>\n"
"    </property>\n"
"   </item>\n"
"   <item>\n"
"    <property name=\"text\">\n"
"     <string>750</string>\n"
"    </property>\n"
"   </item>\n"
"   <item>\n"
"    <property name=\"text\">\n"
"     <string>X</string>\n"
"    </property>\n"
"   </item>\n"
"  </widget>\n"
"  <widget class=\"QLabel\" name=\"label_6\">\n"
"   <property name=\"geometry\">\n"
"    <rect>\n"
"     <x>292</x>\n"
"     <y>207</y>\n"
"     <width>90</width>\n"
"     <height>40</height>\n"
"    </rect>\n"
"   </property>\n"
"   <property name=\"sizePolicy\">\n"
"    <sizepolicy hsizetype=\"Fixed\" vsizetype=\"Fixed\">\n"
"     <horstretch>0</horstretch>\n"
"     <verstretch>0</verstretch>\n"
"    </sizepolicy>\n"
"   </pr"
                        "operty>\n"
"   <property name=\"font\">\n"
"    <font>\n"
"     <weight>75</weight>\n"
"     <bold>true</bold>\n"
"    </font>\n"
"   </property>\n"
"   <property name=\"text\">\n"
"    <string>Full Scale</string>\n"
"   </property>\n"
"   <property name=\"alignment\">\n"
"    <set>Qt::AlignCenter</set>\n"
"   </property>\n"
"  </widget>\n"
"  <widget class=\"QLabel\" name=\"label_4\">\n"
"   <property name=\"geometry\">\n"
"    <rect>\n"
"     <x>10</x>\n"
"     <y>75</y>\n"
"     <width>92</width>\n"
"     <height>17</height>\n"
"    </rect>\n"
"   </property>\n"
"   <property name=\"sizePolicy\">\n"
"    <sizepolicy hsizetype=\"Fixed\" vsizetype=\"Fixed\">\n"
"     <horstretch>0</horstretch>\n"
"     <verstretch>0</verstretch>\n"
"    </sizepolicy>\n"
"   </property>\n"
"   <property name=\"font\">\n"
"    <font>\n"
"     <weight>75</weight>\n"
"     <bold>true</bold>\n"
"    </font>\n"
"   </property>\n"
"   <property name=\"text\">\n"
"    <string>Power Mode</string>\n"
"   </property>\n"
"   <property na"
                        "me=\"alignment\">\n"
"    <set>Qt::AlignCenter</set>\n"
"   </property>\n"
"  </widget>\n"
"  <widget class=\"QLabel\" name=\"label_5\">\n"
"   <property name=\"geometry\">\n"
"    <rect>\n"
"     <x>292</x>\n"
"     <y>75</y>\n"
"     <width>102</width>\n"
"     <height>17</height>\n"
"    </rect>\n"
"   </property>\n"
"   <property name=\"sizePolicy\">\n"
"    <sizepolicy hsizetype=\"Fixed\" vsizetype=\"Fixed\">\n"
"     <horstretch>0</horstretch>\n"
"     <verstretch>0</verstretch>\n"
"    </sizepolicy>\n"
"   </property>\n"
"   <property name=\"font\">\n"
"    <font>\n"
"     <weight>75</weight>\n"
"     <bold>true</bold>\n"
"    </font>\n"
"   </property>\n"
"   <property name=\"text\">\n"
"    <string>Pre Amp Gain</string>\n"
"   </property>\n"
"   <property name=\"alignment\">\n"
"    <set>Qt::AlignCenter</set>\n"
"   </property>\n"
"  </widget>\n"
"  <widget class=\"QLineEdit\" name=\"CalcFullScale\">\n"
"   <property name=\"geometry\">\n"
"    <rect>\n"
"     <x>400</x>\n"
"     <y>210</y>\n"
"     <w"
                        "idth>150</width>\n"
"     <height>29</height>\n"
"    </rect>\n"
"   </property>\n"
"   <property name=\"text\">\n"
"    <string/>\n"
"   </property>\n"
"  </widget>\n"
"  <widget class=\"QSlider\" name=\"Attenuater\">\n"
"   <property name=\"geometry\">\n"
"    <rect>\n"
"     <x>100</x>\n"
"     <y>10</y>\n"
"     <width>360</width>\n"
"     <height>30</height>\n"
"    </rect>\n"
"   </property>\n"
"   <property name=\"sizePolicy\">\n"
"    <sizepolicy hsizetype=\"Expanding\" vsizetype=\"Maximum\">\n"
"     <horstretch>0</horstretch>\n"
"     <verstretch>0</verstretch>\n"
"    </sizepolicy>\n"
"   </property>\n"
"   <property name=\"styleSheet\">\n"
"    <string notr=\"true\">QSlider::groove:horizontal { border: 1px solid white; height: 5px;background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #B1B1B1, stop:1 #c4c4c4);margin: 1px 0;}    \n"
"QSlider::handle:horizontal { background: qlineargradient(x1: 0, y1: 1, x2: 1, y2: 0,stop: 0 #1A74DB, stop: 0.6 #5293DE, stop:1 #FFFFFF); border: 1px solid white;wid"
                        "th: 20px; height:10px; margin: -15px 0;border-radius: 10px;}</string>\n"
"   </property>\n"
"   <property name=\"maximum\">\n"
"    <number>14</number>\n"
"   </property>\n"
"   <property name=\"pageStep\">\n"
"    <number>1</number>\n"
"   </property>\n"
"   <property name=\"orientation\">\n"
"    <enum>Qt::Horizontal</enum>\n"
"   </property>\n"
"  </widget>\n"
"  <widget class=\"QPushButton\" name=\"Exit\">\n"
"   <property name=\"geometry\">\n"
"    <rect>\n"
"     <x>410</x>\n"
"     <y>280</y>\n"
"     <width>100</width>\n"
"     <height>40</height>\n"
"    </rect>\n"
"   </property>\n"
"   <property name=\"text\">\n"
"    <string>&amp;Exit</string>\n"
"   </property>\n"
"  </widget>\n"
"  <widget class=\"QLabel\" name=\"label\">\n"
"   <property name=\"geometry\">\n"
"    <rect>\n"
"     <x>10</x>\n"
"     <y>10</y>\n"
"     <width>84</width>\n"
"     <height>33</height>\n"
"    </rect>\n"
"   </property>\n"
"   <property name=\"sizePolicy\">\n"
"    <sizepolicy hsizetype=\"Fixed\" vsizetype=\"Fixed\">\n"
""
                        "     <horstretch>0</horstretch>\n"
"     <verstretch>0</verstretch>\n"
"    </sizepolicy>\n"
"   </property>\n"
"   <property name=\"font\">\n"
"    <font>\n"
"     <weight>75</weight>\n"
"     <bold>true</bold>\n"
"    </font>\n"
"   </property>\n"
"   <property name=\"text\">\n"
"    <string>Ladder \n"
"Attenuator </string>\n"
"   </property>\n"
"   <property name=\"alignment\">\n"
"    <set>Qt::AlignCenter</set>\n"
"   </property>\n"
"  </widget>\n"
"  <widget class=\"QComboBox\" name=\"PreAmpGain\">\n"
"   <property name=\"geometry\">\n"
"    <rect>\n"
"     <x>400</x>\n"
"     <y>70</y>\n"
"     <width>150</width>\n"
"     <height>27</height>\n"
"    </rect>\n"
"   </property>\n"
"   <item>\n"
"    <property name=\"text\">\n"
"     <string>Low Gain</string>\n"
"    </property>\n"
"   </item>\n"
"   <item>\n"
"    <property name=\"text\">\n"
"     <string>High Gain</string>\n"
"    </property>\n"
"   </item>\n"
"  </widget>\n"
"  <widget class=\"QPushButton\" name=\"Write\">\n"
"   <property name=\"geometr"
                        "y\">\n"
"    <rect>\n"
"     <x>80</x>\n"
"     <y>280</y>\n"
"     <width>100</width>\n"
"     <height>40</height>\n"
"    </rect>\n"
"   </property>\n"
"   <property name=\"text\">\n"
"    <string>&amp;Write</string>\n"
"   </property>\n"
"  </widget>\n"
"  <widget class=\"QComboBox\" name=\"Voltage\">\n"
"   <property name=\"geometry\">\n"
"    <rect>\n"
"     <x>400</x>\n"
"     <y>140</y>\n"
"     <width>150</width>\n"
"     <height>27</height>\n"
"    </rect>\n"
"   </property>\n"
"   <item>\n"
"    <property name=\"text\">\n"
"     <string>20mV</string>\n"
"    </property>\n"
"   </item>\n"
"   <item>\n"
"    <property name=\"text\">\n"
"     <string>50mV</string>\n"
"    </property>\n"
"   </item>\n"
"   <item>\n"
"    <property name=\"text\">\n"
"     <string>100mV</string>\n"
"    </property>\n"
"   </item>\n"
"   <item>\n"
"    <property name=\"text\">\n"
"     <string>200mV</string>\n"
"    </property>\n"
"   </item>\n"
"   <item>\n"
"    <property name=\"text\">\n"
"     <string>500mV</string>\n"
""
                        "    </property>\n"
"   </item>\n"
"   <item>\n"
"    <property name=\"text\">\n"
"     <string>1</string>\n"
"    </property>\n"
"   </item>\n"
"   <item>\n"
"    <property name=\"text\">\n"
"     <string>2</string>\n"
"    </property>\n"
"   </item>\n"
"   <item>\n"
"    <property name=\"text\">\n"
"     <string>5</string>\n"
"    </property>\n"
"   </item>\n"
"   <item>\n"
"    <property name=\"text\">\n"
"     <string>10</string>\n"
"    </property>\n"
"   </item>\n"
"  </widget>\n"
"  <widget class=\"QLineEdit\" name=\"ladder\">\n"
"   <property name=\"geometry\">\n"
"    <rect>\n"
"     <x>470</x>\n"
"     <y>12</y>\n"
"     <width>90</width>\n"
"     <height>29</height>\n"
"    </rect>\n"
"   </property>\n"
"   <property name=\"sizePolicy\">\n"
"    <sizepolicy hsizetype=\"Fixed\" vsizetype=\"Fixed\">\n"
"     <horstretch>0</horstretch>\n"
"     <verstretch>0</verstretch>\n"
"    </sizepolicy>\n"
"   </property>\n"
"   <property name=\"text\">\n"
"    <string/>\n"
"   </property>\n"
"  </widget>\n"
"  <w"
                        "idget class=\"QLineEdit\" name=\"TotalGain\">\n"
"   <property name=\"geometry\">\n"
"    <rect>\n"
"     <x>140</x>\n"
"     <y>210</y>\n"
"     <width>150</width>\n"
"     <height>29</height>\n"
"    </rect>\n"
"   </property>\n"
"   <property name=\"text\">\n"
"    <string/>\n"
"   </property>\n"
"  </widget>\n"
"  <widget class=\"QComboBox\" name=\"PowerMode\">\n"
"   <property name=\"geometry\">\n"
"    <rect>\n"
"     <x>118</x>\n"
"     <y>70</y>\n"
"     <width>150</width>\n"
"     <height>27</height>\n"
"    </rect>\n"
"   </property>\n"
"   <item>\n"
"    <property name=\"text\">\n"
"     <string>Full Power</string>\n"
"    </property>\n"
"   </item>\n"
"   <item>\n"
"    <property name=\"text\">\n"
"     <string>Aux Hi-Z</string>\n"
"    </property>\n"
"   </item>\n"
"  </widget>\n"
" </widget>\n"
" <resources/>\n"
"</ui>\n"
""));
        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(540, 95, 60, 17));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setFont(font1);
        label_3->setAlignment(Qt::AlignCenter);
        Read = new QPushButton(groupBox_3);
        Read->setObjectName(QString::fromUtf8("Read"));
        Read->setGeometry(QRect(410, 300, 100, 40));
        QFont font2;
        font2.setFamily(QString::fromUtf8("DejaVu Sans"));
        Read->setFont(font2);
        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(500, 167, 80, 17));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignCenter);
        lblVoltage = new QLabel(groupBox_3);
        lblVoltage->setObjectName(QString::fromUtf8("lblVoltage"));
        lblVoltage->setGeometry(QRect(50, 170, 70, 17));
        sizePolicy.setHeightForWidth(lblVoltage->sizePolicy().hasHeightForWidth());
        lblVoltage->setSizePolicy(sizePolicy);
        lblVoltage->setFont(font1);
        lblVoltage->setAlignment(Qt::AlignCenter);
        Filter = new QComboBox(groupBox_3);
        Filter->setObjectName(QString::fromUtf8("Filter"));
        Filter->setGeometry(QRect(610, 90, 100, 27));
        Filter->setFont(font2);
        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(250, 230, 90, 40));
        sizePolicy.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy);
        label_6->setFont(font1);
        label_6->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(42, 89, 92, 40));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);
        label_4->setFont(font1);
        label_4->setAlignment(Qt::AlignCenter);
        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(270, 95, 102, 17));
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);
        label_5->setFont(font1);
        label_5->setAlignment(Qt::AlignCenter);
        totalGaindB = new QLineEdit(groupBox_3);
        totalGaindB->setObjectName(QString::fromUtf8("totalGaindB"));
        totalGaindB->setGeometry(QRect(340, 234, 120, 29));
        totalGaindB->setFont(font1);
        Attenuater = new QSlider(groupBox_3);
        Attenuater->setObjectName(QString::fromUtf8("Attenuater"));
        Attenuater->setGeometry(QRect(139, 10, 441, 71));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(Attenuater->sizePolicy().hasHeightForWidth());
        Attenuater->setSizePolicy(sizePolicy1);
        Attenuater->setFont(font2);
        Attenuater->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal { border: 1px solid white; height: 5px;background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #B1B1B1, stop:1 #c4c4c4);margin: 1px 0;}    \n"
"QSlider::handle:horizontal { background: qlineargradient(x1: 0, y1: 1, x2: 1, y2: 0,stop: 0 #1A74DB, stop: 0.6 #5293DE, stop:1 #FFFFFF); border: 1px solid white;width: 30px; height:25px; margin: -8px 0px;border-radius: 10px;}"));
        Attenuater->setMaximum(10);
        Attenuater->setPageStep(1);
        Attenuater->setOrientation(Qt::Horizontal);
        Exit = new QPushButton(groupBox_3);
        Exit->setObjectName(QString::fromUtf8("Exit"));
        Exit->setGeometry(QRect(570, 300, 100, 40));
        Exit->setFont(font2);
        label = new QLabel(groupBox_3);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(42, 30, 84, 33));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setFont(font1);
        label->setAlignment(Qt::AlignCenter);
        PreAmpGain = new QComboBox(groupBox_3);
        PreAmpGain->setObjectName(QString::fromUtf8("PreAmpGain"));
        PreAmpGain->setGeometry(QRect(390, 90, 110, 27));
        PreAmpGain->setFont(font2);
        Write = new QPushButton(groupBox_3);
        Write->setObjectName(QString::fromUtf8("Write"));
        Write->setGeometry(QRect(240, 300, 100, 40));
        Write->setFont(font2);
        Voltage = new QComboBox(groupBox_3);
        Voltage->setObjectName(QString::fromUtf8("Voltage"));
        Voltage->setGeometry(QRect(140, 166, 100, 27));
        Voltage->setFont(font2);
        ladder = new QLineEdit(groupBox_3);
        ladder->setObjectName(QString::fromUtf8("ladder"));
        ladder->setGeometry(QRect(620, 32, 90, 29));
        sizePolicy.setHeightForWidth(ladder->sizePolicy().hasHeightForWidth());
        ladder->setSizePolicy(sizePolicy);
        ladder->setFont(font1);
        TotalGain = new QLineEdit(groupBox_3);
        TotalGain->setObjectName(QString::fromUtf8("TotalGain"));
        TotalGain->setGeometry(QRect(590, 160, 120, 29));
        TotalGain->setFont(font1);
        PowerMode = new QComboBox(groupBox_3);
        PowerMode->setObjectName(QString::fromUtf8("PowerMode"));
        PowerMode->setGeometry(QRect(140, 90, 100, 27));
        PowerMode->setFont(font2);
        Calculate = new QPushButton(groupBox_3);
        Calculate->setObjectName(QString::fromUtf8("Calculate"));
        Calculate->setGeometry(QRect(80, 300, 100, 40));
        Calculate->setFont(font2);
        Data = new QLineEdit(groupBox_3);
        Data->setObjectName(QString::fromUtf8("Data"));
        Data->setGeometry(QRect(340, 162, 120, 29));
        Data->setFont(font1);
        label_16 = new QLabel(groupBox_3);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(270, 170, 61, 17));
        sizePolicy.setHeightForWidth(label_16->sizePolicy().hasHeightForWidth());
        label_16->setSizePolicy(sizePolicy);
        label_16->setFont(font1);
        label_16->setAlignment(Qt::AlignCenter);
        totalGainV = new QLineEdit(groupBox_3);
        totalGainV->setObjectName(QString::fromUtf8("totalGainV"));
        totalGainV->setGeometry(QRect(590, 234, 120, 29));
        totalGainV->setFont(font1);
        label_17 = new QLabel(groupBox_3);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(500, 230, 90, 40));
        sizePolicy.setHeightForWidth(label_17->sizePolicy().hasHeightForWidth());
        label_17->setSizePolicy(sizePolicy);
        label_17->setFont(font1);
        label_17->setAlignment(Qt::AlignCenter);
        ChannelSel = new QComboBox(groupBox_3);
        ChannelSel->setObjectName(QString::fromUtf8("ChannelSel"));
        ChannelSel->setGeometry(QRect(140, 230, 100, 27));
        ChannelSel->setFont(font2);
        lblChannel = new QLabel(groupBox_3);
        lblChannel->setObjectName(QString::fromUtf8("lblChannel"));
        lblChannel->setGeometry(QRect(50, 234, 70, 17));
        sizePolicy.setHeightForWidth(lblChannel->sizePolicy().hasHeightForWidth());
        lblChannel->setSizePolicy(sizePolicy);
        lblChannel->setFont(font1);
        lblChannel->setAlignment(Qt::AlignCenter);
        groupBox_8 = new QGroupBox(tab);
        groupBox_8->setObjectName(QString::fromUtf8("groupBox_8"));
        groupBox_8->setGeometry(QRect(240, 375, 121, 80));
        groupBox_8->setFont(font1);
        groupBox_8->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"   background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #4a79b5, stop: 1 #0f0f0f);\n"
"/*                                       stop: 0 #3a5976, stop: 1 #000000);*/\n"
"     border: 2px solid gray;\n"
"     border-radius: 5px;\n"
"     margin-top: 1ex; /* leave space at the top for the title */\n"
"	 font:bold 12px;	\n"
" }\n"
"\n"
" QGroupBox::title {\n"
"	border:2px solid white;\n"
"	border-radius:5px;\n"
"     subcontrol-origin: margin;\n"
"     subcontrol-position: top left; /* position at the top center */\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #d8dff2, stop: 1 #FFFFFF);\n"
" }\n"
"QLabel{\n"
"	color:white;\n"
"}"));
        cmbCouplingR1 = new QComboBox(groupBox_8);
        cmbCouplingR1->setObjectName(QString::fromUtf8("cmbCouplingR1"));
        cmbCouplingR1->setGeometry(QRect(10, 30, 101, 41));
        QFont font3;
        font3.setFamily(QString::fromUtf8("DejaVu Sans"));
        font3.setPointSize(14);
        cmbCouplingR1->setFont(font3);
        cmbCouplingR1->setStyleSheet(QString::fromUtf8("QComboBox{\n"
"show-decoration-selected: 1; \n"
"border:1px solid #F1F5DA;\n"
"border-radius: 10px;\n"
"color:black;\n"
"}\n"
"QComboBox::drop-down {\n"
"     width:40px;\n"
"	color:black;\n"
" }\n"
"\n"
"QComboBox::::item:selected {\n"
"     border: 1px solid #6a6ea9;\n"
" }\n"
"\n"
""));
        groupBox_9 = new QGroupBox(tab);
        groupBox_9->setObjectName(QString::fromUtf8("groupBox_9"));
        groupBox_9->setGeometry(QRect(369, 377, 121, 80));
        groupBox_9->setFont(font1);
        groupBox_9->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"   background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #4a79b5, stop: 1 #0f0f0f);\n"
"/*                                       stop: 0 #3a5976, stop: 1 #000000);*/\n"
"     border: 2px solid gray;\n"
"     border-radius: 5px;\n"
"     margin-top: 1ex; /* leave space at the top for the title */\n"
"	 font:bold 12px;	\n"
" }\n"
"\n"
" QGroupBox::title {\n"
"	border:2px solid white;\n"
"	border-radius:5px;\n"
"     subcontrol-origin: margin;\n"
"     subcontrol-position: top left; /* position at the top center */\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #d8dff2, stop: 1 #FFFFFF);\n"
" }\n"
"QLabel{\n"
"	color:white;\n"
"}"));
        cmbCouplingR2 = new QComboBox(groupBox_9);
        cmbCouplingR2->setObjectName(QString::fromUtf8("cmbCouplingR2"));
        cmbCouplingR2->setGeometry(QRect(13, 30, 91, 41));
        cmbCouplingR2->setFont(font3);
        cmbCouplingR2->setStyleSheet(QString::fromUtf8("QComboBox{\n"
"show-decoration-selected: 1; \n"
"border:1px solid #F1F5DA;\n"
"border-radius: 10px;\n"
"color:black;\n"
"}\n"
"QComboBox::drop-down {\n"
"     width:40px;\n"
"	color:black;\n"
" }\n"
"\n"
"QComboBox::::item:selected {\n"
"     border: 1px solid #6a6ea9;\n"
" }\n"
"\n"
""));
        groupBox_7 = new QGroupBox(tab);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        groupBox_7->setGeometry(QRect(20, 375, 211, 80));
        groupBox_7->setFont(font1);
        groupBox_7->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"   background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #4a79b5, stop: 1 #0f0f0f);\n"
"/*                                       stop: 0 #3a5976, stop: 1 #000000);*/\n"
"     border: 2px solid gray;\n"
"     border-radius: 5px;\n"
"     margin-top: 1ex; /* leave space at the top for the title */\n"
"	 font:bold 12px;	\n"
" }\n"
"\n"
" QGroupBox::title {\n"
"	border:2px solid white;\n"
"	border-radius:5px;\n"
"     subcontrol-origin: margin;\n"
"     subcontrol-position: top left; /* position at the top center */\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #d8dff2, stop: 1 #FFFFFF);\n"
" }\n"
"QLabel{\n"
"	color:white;\n"
"}"));
        chkR1 = new QCheckBox(groupBox_7);
        chkR1->setObjectName(QString::fromUtf8("chkR1"));
        chkR1->setGeometry(QRect(20, 30, 81, 41));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(255, 85, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        chkR1->setPalette(palette);
        QFont font4;
        font4.setBold(false);
        font4.setItalic(false);
        font4.setWeight(50);
        chkR1->setFont(font4);
        chkR1->setFocusPolicy(Qt::NoFocus);
        chkR1->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
"font: 20px;\n"
"color:white\n"
"}\n"
" QCheckBox::indicator {\n"
"     width: 25px;\n"
"     height:25px;\n"
" }"));
        chkR2 = new QCheckBox(groupBox_7);
        chkR2->setObjectName(QString::fromUtf8("chkR2"));
        chkR2->setGeometry(QRect(110, 30, 81, 41));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        chkR2->setPalette(palette1);
        chkR2->setFont(font4);
        chkR2->setFocusPolicy(Qt::NoFocus);
        chkR2->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
"font: 20px;\n"
"color:white\n"
"}\n"
" QCheckBox::indicator {\n"
"     width: 25px;\n"
"     height:25px;\n"
" }"));
        m_tabDAC = new QGroupBox(tab);
        m_tabDAC->setObjectName(QString::fromUtf8("m_tabDAC"));
        m_tabDAC->setGeometry(QRect(20, 456, 740, 70));
        m_tabDAC->setFont(font1);
        m_tabDAC->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"   background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #4a79b5, stop: 1 #0f0f0f);\n"
"/*                                       stop: 0 #3a5976, stop: 1 #000000);*/\n"
"     border: 2px solid gray;\n"
"     border-radius: 5px;\n"
"     margin-top: 1ex; /* leave space at the top for the title */\n"
"	 font:bold 12px;	\n"
" }\n"
"\n"
" QGroupBox::title {\n"
"	border:2px solid white;\n"
"	border-radius:5px;\n"
"     subcontrol-origin: margin;\n"
"     subcontrol-position: top left; /* position at the top center */\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #d8dff2, stop: 1 #FFFFFF);\n"
" }\n"
"QLabel{\n"
"	color:white;\n"
"}"));
        m_rbDACA = new QRadioButton(m_tabDAC);
        m_rbDACA->setObjectName(QString::fromUtf8("m_rbDACA"));
        m_rbDACA->setGeometry(QRect(10, 23, 120, 30));
        m_rbDACB = new QRadioButton(m_tabDAC);
        m_rbDACB->setObjectName(QString::fromUtf8("m_rbDACB"));
        m_rbDACB->setGeometry(QRect(130, 23, 130, 30));
        m_rbDACC = new QRadioButton(m_tabDAC);
        m_rbDACC->setObjectName(QString::fromUtf8("m_rbDACC"));
        m_rbDACC->setGeometry(QRect(253, 13, 130, 40));
        m_rbDACD = new QRadioButton(m_tabDAC);
        m_rbDACD->setObjectName(QString::fromUtf8("m_rbDACD"));
        m_rbDACD->setGeometry(QRect(370, 13, 140, 40));
        m_rbDACE = new QRadioButton(m_tabDAC);
        m_rbDACE->setObjectName(QString::fromUtf8("m_rbDACE"));
        m_rbDACE->setGeometry(QRect(500, 13, 140, 40));
        m_leDACValue = new QLineEdit(m_tabDAC);
        m_leDACValue->setObjectName(QString::fromUtf8("m_leDACValue"));
        m_leDACValue->setGeometry(QRect(640, 20, 90, 29));
        m_leDACValue->setFont(font1);
        grpCH1 = new QGroupBox(tab);
        grpCH1->setObjectName(QString::fromUtf8("grpCH1"));
        grpCH1->setGeometry(QRect(499, 379, 131, 80));
        grpCH1->setFont(font1);
        grpCH1->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"   background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #4a79b5, stop: 1 #0f0f0f);\n"
"/*                                       stop: 0 #3a5976, stop: 1 #000000);*/\n"
"     border: 2px solid gray;\n"
"     border-radius: 5px;\n"
"     margin-top: 1ex; /* leave space at the top for the title */\n"
"	 font:bold 12px;	\n"
" }\n"
"\n"
" QGroupBox::title {\n"
"	border:2px solid white;\n"
"	border-radius:5px;\n"
"     subcontrol-origin: margin;\n"
"     subcontrol-position: top left; /* position at the top center */\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #d8dff2, stop: 1 #FFFFFF);\n"
" }\n"
"QLabel{\n"
"	color:white;\n"
"}"));
        chkCH1Even = new QCheckBox(grpCH1);
        chkCH1Even->setObjectName(QString::fromUtf8("chkCH1Even"));
        chkCH1Even->setGeometry(QRect(65, 30, 61, 31));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        chkCH1Even->setPalette(palette2);
        chkCH1Even->setFont(font4);
        chkCH1Even->setFocusPolicy(Qt::NoFocus);
        chkCH1Even->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
"font: 12px;\n"
"color:white\n"
"}\n"
" QCheckBox::indicator {\n"
"     width: 16px;\n"
"     height:16px;\n"
" }"));
        chkCH1Odd = new QCheckBox(grpCH1);
        chkCH1Odd->setObjectName(QString::fromUtf8("chkCH1Odd"));
        chkCH1Odd->setGeometry(QRect(0, 30, 61, 31));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        chkCH1Odd->setPalette(palette3);
        chkCH1Odd->setFont(font4);
        chkCH1Odd->setFocusPolicy(Qt::NoFocus);
        chkCH1Odd->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
"font: 12px;\n"
"color:white\n"
"}\n"
" QCheckBox::indicator {\n"
"     width: 16px;\n"
"     height:16px;\n"
" }"));
        grpCH2 = new QGroupBox(tab);
        grpCH2->setObjectName(QString::fromUtf8("grpCH2"));
        grpCH2->setGeometry(QRect(640, 380, 131, 80));
        grpCH2->setFont(font1);
        grpCH2->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"   background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #4a79b5, stop: 1 #0f0f0f);\n"
"/*                                       stop: 0 #3a5976, stop: 1 #000000);*/\n"
"     border: 2px solid gray;\n"
"     border-radius: 5px;\n"
"     margin-top: 1ex; /* leave space at the top for the title */\n"
"	 font:bold 12px;	\n"
" }\n"
"\n"
" QGroupBox::title {\n"
"	border:2px solid white;\n"
"	border-radius:5px;\n"
"     subcontrol-origin: margin;\n"
"     subcontrol-position: top left; /* position at the top center */\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #d8dff2, stop: 1 #FFFFFF);\n"
" }\n"
"QLabel{\n"
"	color:white;\n"
"}"));
        chkCH2Odd = new QCheckBox(grpCH2);
        chkCH2Odd->setObjectName(QString::fromUtf8("chkCH2Odd"));
        chkCH2Odd->setGeometry(QRect(3, 30, 61, 31));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette4.setBrush(QPalette::Active, QPalette::Text, brush);
        palette4.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        chkCH2Odd->setPalette(palette4);
        chkCH2Odd->setFont(font4);
        chkCH2Odd->setFocusPolicy(Qt::NoFocus);
        chkCH2Odd->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
"font: 12px;\n"
"color:white\n"
"}\n"
" QCheckBox::indicator {\n"
"     width: 16px;\n"
"     height:16px;\n"
" }"));
        chkCH2Even = new QCheckBox(grpCH2);
        chkCH2Even->setObjectName(QString::fromUtf8("chkCH2Even"));
        chkCH2Even->setGeometry(QRect(60, 30, 61, 31));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette5.setBrush(QPalette::Active, QPalette::Text, brush);
        palette5.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        chkCH2Even->setPalette(palette5);
        chkCH2Even->setFont(font4);
        chkCH2Even->setFocusPolicy(Qt::NoFocus);
        chkCH2Even->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
"font: 12px;\n"
"color:white\n"
"}\n"
" QCheckBox::indicator {\n"
"     width: 16px;\n"
"     height:16px;\n"
" }"));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        grpTime = new QGroupBox(tab_2);
        grpTime->setObjectName(QString::fromUtf8("grpTime"));
        grpTime->setGeometry(QRect(440, 2, 141, 131));
        grpTime->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"   background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #4a79b5, stop: 1 #0f0f0f);\n"
"/*                                       stop: 0 #3a5976, stop: 1 #000000);*/\n"
"     border: 2px solid gray;\n"
"     border-radius: 5px;\n"
"     margin-top: 1ex; /* leave space at the top for the title */\n"
"	 font:bold 14px;	\n"
" }\n"
"\n"
" QGroupBox::title {\n"
"	border:2px solid white;\n"
"	border-radius:5px;\n"
"     subcontrol-origin: margin;\n"
"     subcontrol-position: top left; /* position at the top center */\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #d8dff2, stop: 1 #FFFFFF);\n"
" }\n"
"QLabel{\n"
"	color:white;\n"
"}"));
        cmbTimeBase = new QComboBox(grpTime);
        cmbTimeBase->setObjectName(QString::fromUtf8("cmbTimeBase"));
        cmbTimeBase->setGeometry(QRect(110, 10, 20, 31));
        QFont font5;
        font5.setFamily(QString::fromUtf8("DejaVu Serif"));
        font5.setPointSize(20);
        cmbTimeBase->setFont(font5);
        cmbTimeBase->setStyleSheet(QString::fromUtf8("QComboBox{\n"
"show-decoration-selected: 1; \n"
"border:2px solid #F1F5DA;\n"
"border-radius: 10;\n"
"color:black;\n"
"}\n"
"QComboBox::drop-down {\n"
"     width:40px;\n"
"	color:black;\n"
" }\n"
"\n"
"QComboBox::item:selected {\n"
"     border:2px solid #6a6ea9;\n"
" }\n"
"QComboBox:hover { color: white }\n"
""));
        cmbTimeUnit = new QComboBox(grpTime);
        cmbTimeUnit->setObjectName(QString::fromUtf8("cmbTimeUnit"));
        cmbTimeUnit->setGeometry(QRect(109, 40, 21, 31));
        cmbTimeUnit->setFont(font5);
        cmbTimeUnit->setStyleSheet(QString::fromUtf8("QComboBox{\n"
"show-decoration-selected: 1; \n"
"border:1px solid #F1F5DA;\n"
"border-radius: 10px;\n"
"color:black;\n"
"}\n"
"QComboBox::drop-down {\n"
"     width:40px;\n"
"	color:black;\n"
" }\n"
"\n"
"QComboBox::::item:selected {\n"
"     border: 1px solid #6a6ea9;\n"
" }\n"
"\n"
""));
        timebaseDial = new QDial(grpTime);
        timebaseDial->setObjectName(QString::fromUtf8("timebaseDial"));
        timebaseDial->setGeometry(QRect(-16, 12, 131, 121));
        timebaseDial->setMinimum(1);
        timebaseDial->setMaximum(30);
        timebaseDial->setPageStep(2);
        timebaseDial->setValue(1);
        timebaseDial->setOrientation(Qt::Horizontal);
        timebaseDial->setInvertedAppearance(false);
        timebaseDial->setInvertedControls(false);
        timebaseDial->setWrapping(true);
        timebaseDial->setNotchTarget(9);
        timebaseDial->setNotchesVisible(false);
        lblTimeBase = new QLabel(grpTime);
        lblTimeBase->setObjectName(QString::fromUtf8("lblTimeBase"));
        lblTimeBase->setGeometry(QRect(90, 10, 51, 20));
        butOffset = new QPushButton(grpTime);
        butOffset->setObjectName(QString::fromUtf8("butOffset"));
        butOffset->setGeometry(QRect(89, 99, 51, 30));
        groupBox_5 = new QGroupBox(tab_2);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(280, 450, 291, 81));
        groupBox_5->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"   background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #4a79b5, stop: 1 #0f0f0f);\n"
"/*                                       stop: 0 #3a5976, stop: 1 #000000);*/\n"
"     border: 2px solid gray;\n"
"     border-radius: 5px;\n"
"     margin-top: 1ex; /* leave space at the top for the title */\n"
"	 font:bold 14px;	\n"
" }\n"
"\n"
" QGroupBox::title {\n"
"	border:2px solid white;\n"
"	border-radius:5px;\n"
"     subcontrol-origin: margin;\n"
"     subcontrol-position: top left; /* position at the top center */\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #d8dff2, stop: 1 #FFFFFF);\n"
" }\n"
"QLabel{\n"
"	color:white;\n"
"}"));
        optSingle = new QRadioButton(groupBox_5);
        optSingle->setObjectName(QString::fromUtf8("optSingle"));
        optSingle->setGeometry(QRect(10, 40, 91, 41));
        optSingle->setFont(font1);
        optSingle->setFocusPolicy(Qt::NoFocus);
        optSingle->setStyleSheet(QString::fromUtf8("QRadioButton{\n"
"font:bold 12px;\n"
"color:white;\n"
"}\n"
" QRadioButton::indicator {\n"
"     width: 20px;\n"
"     height:20px;\n"
"   border: 2px solid black;\n"
"	 border-radius:12px;\n"
"\n"
" }\n"
" QRadioButton::indicator::unchecked {\n"
"		background-color:white;\n"
"     }\n"
"\n"
"     QRadioButton::indicator:unchecked:hover {\n"
"		background-color:white;\n"
"     }\n"
"\n"
"     QRadioButton::indicator:unchecked:pressed {\n"
"		background-color:white;\n"
"     }\n"
"\n"
"     QRadioButton::indicator::checked {\n"
"		background-color:#f2a400;\n"
"     }\n"
"\n"
"     QRadioButton::indicator:checked:hover {\n"
"		background-color:#f2a400;\n"
"     }\n"
"\n"
"     QRadioButton::indicator:checked:pressed {\n"
"		background-color:#f2a400;\n"
"     }"));
        optAuto = new QRadioButton(groupBox_5);
        optAuto->setObjectName(QString::fromUtf8("optAuto"));
        optAuto->setGeometry(QRect(104, 40, 71, 41));
        optAuto->setFont(font1);
        optAuto->setFocusPolicy(Qt::NoFocus);
        optAuto->setStyleSheet(QString::fromUtf8("QRadioButton{\n"
"font:bold 12px;\n"
"color:white;\n"
"}\n"
" QRadioButton::indicator {\n"
"     width: 20px;\n"
"     height:20px;\n"
"   border: 2px solid black;\n"
"	 border-radius:12px;\n"
"\n"
" }\n"
" QRadioButton::indicator::unchecked {\n"
"		background-color:white;\n"
"     }\n"
"\n"
"     QRadioButton::indicator:unchecked:hover {\n"
"		background-color:white;\n"
"     }\n"
"\n"
"     QRadioButton::indicator:unchecked:pressed {\n"
"		background-color:white;\n"
"     }\n"
"\n"
"     QRadioButton::indicator::checked {\n"
"		background-color:#f2a400;\n"
"     }\n"
"\n"
"     QRadioButton::indicator:checked:hover {\n"
"		background-color:#f2a400;\n"
"     }\n"
"\n"
"     QRadioButton::indicator:checked:pressed {\n"
"		background-color:#f2a400;\n"
"     }"));
        optNormal = new QRadioButton(groupBox_5);
        optNormal->setObjectName(QString::fromUtf8("optNormal"));
        optNormal->setGeometry(QRect(184, 40, 91, 41));
        optNormal->setFont(font1);
        optNormal->setFocusPolicy(Qt::NoFocus);
        optNormal->setStyleSheet(QString::fromUtf8("QRadioButton{\n"
"font:bold 12px;\n"
"color:white;\n"
"}\n"
" QRadioButton::indicator {\n"
"     width: 20px;\n"
"     height:20px;\n"
"   border: 2px solid black;\n"
"	 border-radius:12px;\n"
"\n"
" }\n"
" QRadioButton::indicator::unchecked {\n"
"		background-color:white;\n"
"     }\n"
"\n"
"     QRadioButton::indicator:unchecked:hover {\n"
"		background-color:white;\n"
"     }\n"
"\n"
"     QRadioButton::indicator:unchecked:pressed {\n"
"		background-color:white;\n"
"     }\n"
"\n"
"     QRadioButton::indicator::checked {\n"
"		background-color:#f2a400;\n"
"     }\n"
"\n"
"     QRadioButton::indicator:checked:hover {\n"
"		background-color:#f2a400;\n"
"     }\n"
"\n"
"     QRadioButton::indicator:checked:pressed {\n"
"		background-color:#f2a400;\n"
"     }"));
        butRUN = new QPushButton(groupBox_5);
        butRUN->setObjectName(QString::fromUtf8("butRUN"));
        butRUN->setGeometry(QRect(120, 10, 84, 30));
        butSTOP = new QPushButton(groupBox_5);
        butSTOP->setObjectName(QString::fromUtf8("butSTOP"));
        butSTOP->setGeometry(QRect(201, 10, 84, 30));
        grpTimeSettings = new QGroupBox(tab_2);
        grpTimeSettings->setObjectName(QString::fromUtf8("grpTimeSettings"));
        grpTimeSettings->setGeometry(QRect(12, 2, 211, 131));
        grpTimeSettings->setFont(font1);
        grpTimeSettings->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"   background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #4a79b5, stop: 1 #0f0f0f);\n"
"/*                                       stop: 0 #3a5976, stop: 1 #000000);*/\n"
"     border: 2px solid gray;\n"
"     border-radius: 5px;\n"
"     margin-top: 1ex; /* leave space at the top for the title */\n"
"	 font:bold 14px;	\n"
" }\n"
"\n"
" QGroupBox::title {\n"
"	border:2px solid white;\n"
"	border-radius:5px;\n"
"     subcontrol-origin: margin;\n"
"     subcontrol-position: top left; /* position at the top center */\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #d8dff2, stop: 1 #FFFFFF);\n"
" }\n"
"QLabel{\n"
"	color:white;\n"
"}"));
        label_7 = new QLabel(grpTimeSettings);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(7, 39, 111, 40));
        label_7->setFont(font1);
        label_8 = new QLabel(grpTimeSettings);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(8, 80, 91, 40));
        label_8->setFont(font1);
        leBTUR = new QLineEdit(grpTimeSettings);
        leBTUR->setObjectName(QString::fromUtf8("leBTUR"));
        leBTUR->setGeometry(QRect(90, 32, 111, 30));
        leBDR = new QLineEdit(grpTimeSettings);
        leBDR->setObjectName(QString::fromUtf8("leBDR"));
        leBDR->setGeometry(QRect(90, 80, 111, 30));
        grpSamples = new QGroupBox(tab_2);
        grpSamples->setObjectName(QString::fromUtf8("grpSamples"));
        grpSamples->setGeometry(QRect(240, 2, 191, 131));
        grpSamples->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"   background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #4a79b5, stop: 1 #0f0f0f);\n"
"/*                                       stop: 0 #3a5976, stop: 1 #000000);*/\n"
"     border: 2px solid gray;\n"
"     border-radius: 5px;\n"
"     margin-top: 1ex; /* leave space at the top for the title */\n"
"	 font:bold 14px;	\n"
" }\n"
"\n"
" QGroupBox::title {\n"
"	border:2px solid white;\n"
"	border-radius:5px;\n"
"     subcontrol-origin: margin;\n"
"     subcontrol-position: top left; /* position at the top center */\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #d8dff2, stop: 1 #FFFFFF);\n"
" }\n"
"QLabel{\n"
"	color:white;\n"
"}"));
        label_9 = new QLabel(grpSamples);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(7, 40, 81, 20));
        label_10 = new QLabel(grpSamples);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(7, 90, 81, 20));
        lePosTrigger = new QLineEdit(grpSamples);
        lePosTrigger->setObjectName(QString::fromUtf8("lePosTrigger"));
        lePosTrigger->setGeometry(QRect(100, 30, 81, 41));
        lePreTrigger = new QLineEdit(grpSamples);
        lePreTrigger->setObjectName(QString::fromUtf8("lePreTrigger"));
        lePreTrigger->setGeometry(QRect(100, 80, 81, 41));
        groupBox_6 = new QGroupBox(tab_2);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        groupBox_6->setGeometry(QRect(0, 451, 271, 81));
        groupBox_6->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"   background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #4a79b5, stop: 1 #0f0f0f);\n"
"/*                                       stop: 0 #3a5976, stop: 1 #000000);*/\n"
"     border: 2px solid gray;\n"
"     border-radius: 5px;\n"
"     margin-top: 1ex; /* leave space at the top for the title */\n"
"	 font:bold 14px;	\n"
" }\n"
"\n"
" QGroupBox::title {\n"
"	border:2px solid white;\n"
"	border-radius:5px;\n"
"     subcontrol-origin: margin;\n"
"     subcontrol-position: top left; /* position at the top center */\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #d8dff2, stop: 1 #FFFFFF);\n"
" }\n"
"QLabel{\n"
"	color:white;\n"
"}"));
        butForceTrigger = new QPushButton(groupBox_6);
        butForceTrigger->setObjectName(QString::fromUtf8("butForceTrigger"));
        butForceTrigger->setGeometry(QRect(213, 30, 51, 41));
        QFont font6;
        font6.setPointSize(9);
        butForceTrigger->setFont(font6);
        cmbChannel = new QComboBox(groupBox_6);
        cmbChannel->setObjectName(QString::fromUtf8("cmbChannel"));
        cmbChannel->setGeometry(QRect(10, 30, 91, 41));
        QFont font7;
        font7.setFamily(QString::fromUtf8("DejaVu Serif"));
        font7.setPointSize(14);
        font7.setBold(true);
        font7.setWeight(75);
        cmbChannel->setFont(font7);
        cmbChannel->setStyleSheet(QString::fromUtf8("QComboBox{\n"
"show-decoration-selected: 1; \n"
"border:1px solid #F1F5DA;\n"
"border-radius: 10px;\n"
"color:black;\n"
"}\n"
"QComboBox::drop-down {\n"
"     width:40px;\n"
"	color:black;\n"
" }\n"
"\n"
"QComboBox::::item:selected {\n"
"     border: 1px solid #6a6ea9;\n"
" }\n"
"\n"
""));
        cmbTriggerSoruce = new QComboBox(groupBox_6);
        cmbTriggerSoruce->setObjectName(QString::fromUtf8("cmbTriggerSoruce"));
        cmbTriggerSoruce->setGeometry(QRect(110, 30, 91, 41));
        QFont font8;
        font8.setFamily(QString::fromUtf8("DejaVu Serif"));
        font8.setPointSize(12);
        font8.setBold(true);
        font8.setWeight(75);
        cmbTriggerSoruce->setFont(font8);
        cmbTriggerSoruce->setStyleSheet(QString::fromUtf8("QComboBox{\n"
"show-decoration-selected: 1; \n"
"border:1px solid #F1F5DA;\n"
"border-radius: 10px;\n"
"color:black;\n"
"}\n"
"QComboBox::drop-down {\n"
"     width:40px;\n"
"	color:black;\n"
" }\n"
"\n"
"QComboBox::::item:selected {\n"
"     border: 1px solid #6a6ea9;\n"
" }\n"
"\n"
""));
        grpMemory = new QGroupBox(tab_2);
        grpMemory->setObjectName(QString::fromUtf8("grpMemory"));
        grpMemory->setGeometry(QRect(590, -1, 191, 141));
        grpMemory->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"   background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #4a79b5, stop: 1 #0f0f0f);\n"
"/*                                       stop: 0 #3a5976, stop: 1 #000000);*/\n"
"     border: 2px solid gray;\n"
"     border-radius: 5px;\n"
"     margin-top: 1ex; /* leave space at the top for the title */\n"
"	 font:bold 14px;	\n"
" }\n"
"\n"
" QGroupBox::title {\n"
"	border:2px solid white;\n"
"	border-radius:5px;\n"
"     subcontrol-origin: margin;\n"
"     subcontrol-position: top left; /* position at the top center */\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #d8dff2, stop: 1 #FFFFFF);\n"
" }\n"
"QLabel{\n"
"	color:white;\n"
"}"));
        cmbMemory = new QComboBox(grpMemory);
        cmbMemory->setObjectName(QString::fromUtf8("cmbMemory"));
        cmbMemory->setGeometry(QRect(137, 10, 16, 41));
        cmbMemory->setFont(font5);
        cmbMemory->setStyleSheet(QString::fromUtf8("QComboBox{\n"
"show-decoration-selected: 1; \n"
"border:1px solid #F1F5DA;\n"
"border-radius: 10px;\n"
"color:black;\n"
"}\n"
"QComboBox::drop-down {\n"
"     width:40px;\n"
"	color:black;\n"
" }\n"
"\n"
"QComboBox::::item:selected {\n"
"     border: 1px solid #6a6ea9;\n"
" }\n"
"\n"
""));
        dblHorizontalTrigger = new QDoubleSpinBox(grpMemory);
        dblHorizontalTrigger->setObjectName(QString::fromUtf8("dblHorizontalTrigger"));
        dblHorizontalTrigger->setGeometry(QRect(115, 56, 61, 41));
        label_21 = new QLabel(grpMemory);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(111, 36, 81, 20));
        cmbSamples = new QComboBox(grpMemory);
        cmbSamples->setObjectName(QString::fromUtf8("cmbSamples"));
        cmbSamples->setGeometry(QRect(120, 10, 20, 41));
        QFont font9;
        font9.setFamily(QString::fromUtf8("DejaVu Serif"));
        font9.setPointSize(15);
        cmbSamples->setFont(font9);
        cmbSamples->setStyleSheet(QString::fromUtf8("QComboBox{\n"
"show-decoration-selected: 1; \n"
"border:1px solid #F1F5DA;\n"
"border-radius: 10px;\n"
"color:black;\n"
"}\n"
"QComboBox::drop-down {\n"
"     width:30px;\n"
"	color:black;\n"
" }\n"
"\n"
"QComboBox::::item:selected {\n"
"     border: 1px solid #6a6ea9;\n"
" }\n"
"\n"
""));
        chkInt_Ext = new QCheckBox(grpMemory);
        chkInt_Ext->setObjectName(QString::fromUtf8("chkInt_Ext"));
        chkInt_Ext->setGeometry(QRect(110, 100, 71, 31));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette6.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette6.setBrush(QPalette::Active, QPalette::Text, brush);
        palette6.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        chkInt_Ext->setPalette(palette6);
        chkInt_Ext->setFont(font4);
        chkInt_Ext->setFocusPolicy(Qt::NoFocus);
        chkInt_Ext->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
"font: 12px;\n"
"color:white\n"
"}\n"
" QCheckBox::indicator {\n"
"     width: 16px;\n"
"     height:16px;\n"
" }"));
        memoryDial = new QDial(grpMemory);
        memoryDial->setObjectName(QString::fromUtf8("memoryDial"));
        memoryDial->setGeometry(QRect(-9, 14, 131, 131));
        memoryDial->setMinimum(1);
        memoryDial->setMaximum(15);
        memoryDial->setPageStep(2);
        memoryDial->setValue(1);
        memoryDial->setOrientation(Qt::Horizontal);
        memoryDial->setInvertedAppearance(false);
        memoryDial->setInvertedControls(false);
        memoryDial->setWrapping(true);
        memoryDial->setNotchTarget(10);
        memoryDial->setNotchesVisible(false);
        lblSamples = new QLabel(grpMemory);
        lblSamples->setObjectName(QString::fromUtf8("lblSamples"));
        lblSamples->setGeometry(QRect(110, 10, 61, 20));
        label_11 = new QLabel(tab_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(580, 470, 51, 20));
        label_13 = new QLabel(tab_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(580, 500, 71, 31));
        leDispFreq = new QLineEdit(tab_2);
        leDispFreq->setObjectName(QString::fromUtf8("leDispFreq"));
        leDispFreq->setGeometry(QRect(640, 460, 101, 31));
        leDispTSamples = new QLineEdit(tab_2);
        leDispTSamples->setObjectName(QString::fromUtf8("leDispTSamples"));
        leDispTSamples->setGeometry(QRect(643, 500, 101, 31));
        groupBox = new QGroupBox(tab_2);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(670, 150, 111, 301));
        groupBox->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"   background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #4a79b5, stop: 1 #0f0f0f);\n"
"/*                                       stop: 0 #3a5976, stop: 1 #000000);*/\n"
"     border: 2px solid gray;\n"
"     border-radius: 5px;\n"
"     margin-top: 1ex; /* leave space at the top for the title */\n"
"	 font:bold 14px;	\n"
" }\n"
"\n"
" QGroupBox::title {\n"
"	border:2px solid white;\n"
"	border-radius:5px;\n"
"     subcontrol-origin: margin;\n"
"     subcontrol-position: top left; /* position at the top center */\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #d8dff2, stop: 1 #FFFFFF);\n"
" }\n"
"QLabel{\n"
"	color:white;\n"
"}"));
        label_18 = new QLabel(groupBox);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(10, 60, 81, 20));
        dblVerticalTrigger = new QDoubleSpinBox(groupBox);
        dblVerticalTrigger->setObjectName(QString::fromUtf8("dblVerticalTrigger"));
        dblVerticalTrigger->setGeometry(QRect(0, 80, 111, 31));
        dblVerticalTrigger->setDecimals(8);
        label_20 = new QLabel(groupBox);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(10, 24, 81, 20));
        cmbLMHVoltage = new QComboBox(groupBox);
        cmbLMHVoltage->setObjectName(QString::fromUtf8("cmbLMHVoltage"));
        cmbLMHVoltage->setGeometry(QRect(10, 44, 91, 16));
        cmbLMHVoltage->setFont(font2);
        cmbLMHVoltage->setStyleSheet(QString::fromUtf8("QComboBox{\n"
"show-decoration-selected: 1; \n"
"border:1px solid #F1F5DA;\n"
"border-radius: 10px;\n"
"color:black;\n"
"}\n"
"QComboBox::drop-down {\n"
"     width:30px;\n"
"	color:black;\n"
" }\n"
"\n"
"QComboBox::::item:selected {\n"
"     border: 1px solid #6a6ea9;\n"
" }\n"
"\n"
""));
        leGainDB = new QLineEdit(groupBox);
        leGainDB->setObjectName(QString::fromUtf8("leGainDB"));
        leGainDB->setGeometry(QRect(10, 221, 91, 29));
        leGainDB->setFont(font1);
        label_22 = new QLabel(groupBox);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(8, 198, 90, 31));
        sizePolicy.setHeightForWidth(label_22->sizePolicy().hasHeightForWidth());
        label_22->setSizePolicy(sizePolicy);
        label_22->setFont(font1);
        label_22->setAlignment(Qt::AlignCenter);
        label_23 = new QLabel(groupBox);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(8, 244, 90, 21));
        sizePolicy.setHeightForWidth(label_23->sizePolicy().hasHeightForWidth());
        label_23->setSizePolicy(sizePolicy);
        label_23->setFont(font1);
        label_23->setAlignment(Qt::AlignCenter);
        leTotalV = new QLineEdit(groupBox);
        leTotalV->setObjectName(QString::fromUtf8("leTotalV"));
        leTotalV->setGeometry(QRect(10, 267, 91, 29));
        leTotalV->setFont(font1);
        LMHFilter = new QComboBox(groupBox);
        LMHFilter->setObjectName(QString::fromUtf8("LMHFilter"));
        LMHFilter->setGeometry(QRect(20, 130, 71, 27));
        LMHFilter->setFont(font2);
        label_24 = new QLabel(groupBox);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(23, 114, 60, 17));
        sizePolicy.setHeightForWidth(label_24->sizePolicy().hasHeightForWidth());
        label_24->setSizePolicy(sizePolicy);
        label_24->setFont(font1);
        label_24->setAlignment(Qt::AlignCenter);
        LMHPowerMode = new QComboBox(groupBox);
        LMHPowerMode->setObjectName(QString::fromUtf8("LMHPowerMode"));
        LMHPowerMode->setGeometry(QRect(10, 179, 91, 27));
        LMHPowerMode->setFont(font2);
        label_25 = new QLabel(groupBox);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setGeometry(QRect(10, 154, 92, 31));
        sizePolicy.setHeightForWidth(label_25->sizePolicy().hasHeightForWidth());
        label_25->setSizePolicy(sizePolicy);
        label_25->setFont(font1);
        label_25->setAlignment(Qt::AlignCenter);
        graphW = new QWidget(tab_2);
        graphW->setObjectName(QString::fromUtf8("graphW"));
        graphW->setGeometry(QRect(8, 143, 651, 301));
        QPalette palette7;
        QBrush brush2(QColor(0, 0, 0, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette7.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette7.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette7.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette7.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette7.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette7.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        palette7.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette7.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette7.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        graphW->setPalette(palette7);
        graphW->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        butSerialPanel = new QPushButton(tab_2);
        butSerialPanel->setObjectName(QString::fromUtf8("butSerialPanel"));
        butSerialPanel->setGeometry(QRect(741, 455, 41, 41));
        butSerialPanel->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"         border: 2px solid rgba(0,0,0,0);\n"
"         border-radius: 25px;\n"
"         background-color: rgba(0,0,0,0);\n"
"     }\n"
"\n"
"     QPushButton:pressed {\n"
"		background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"     }\n"
"\n"
"     QPushButton:flat {\n"
"         border: none; /* no border for a flat push button */\n"
"     }\n"
"\n"
"     QPushButton:default {\n"
"         border-color: navy; /* make the default button prominent */\n"
"     }"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Control-Panel-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        butSerialPanel->setIcon(icon);
        butSerialPanel->setIconSize(QSize(48, 48));
        leStatus = new QLineEdit(tab_2);
        leStatus->setObjectName(QString::fromUtf8("leStatus"));
        leStatus->setGeometry(QRect(581, 439, 81, 21));
        QPalette palette8;
        QBrush brush3(QColor(255, 255, 127, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette8.setBrush(QPalette::Active, QPalette::WindowText, brush3);
        palette8.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette8.setBrush(QPalette::Active, QPalette::Text, brush3);
        palette8.setBrush(QPalette::Active, QPalette::ButtonText, brush3);
        palette8.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette8.setBrush(QPalette::Active, QPalette::Window, brush2);
        QBrush brush4(QColor(255, 255, 0, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette8.setBrush(QPalette::Active, QPalette::Highlight, brush4);
        palette8.setBrush(QPalette::Inactive, QPalette::WindowText, brush3);
        palette8.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette8.setBrush(QPalette::Inactive, QPalette::Text, brush3);
        palette8.setBrush(QPalette::Inactive, QPalette::ButtonText, brush3);
        palette8.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette8.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        palette8.setBrush(QPalette::Inactive, QPalette::Highlight, brush4);
        palette8.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette8.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette8.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette8.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        palette8.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette8.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        palette8.setBrush(QPalette::Disabled, QPalette::Highlight, brush4);
        leStatus->setPalette(palette8);
        leStatus->setFont(font1);
        leStatus->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 127);"));
        ch1Widget = new QWidget(tab_2);
        ch1Widget->setObjectName(QString::fromUtf8("ch1Widget"));
        ch1Widget->setGeometry(QRect(10, 270, 651, 80));
        QPalette palette9;
        palette9.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette9.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette9.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette9.setBrush(QPalette::Active, QPalette::Midlight, brush2);
        palette9.setBrush(QPalette::Active, QPalette::Dark, brush2);
        palette9.setBrush(QPalette::Active, QPalette::Mid, brush2);
        palette9.setBrush(QPalette::Active, QPalette::Text, brush);
        palette9.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette9.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette9.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette9.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette9.setBrush(QPalette::Active, QPalette::Shadow, brush2);
        palette9.setBrush(QPalette::Active, QPalette::AlternateBase, brush2);
        QBrush brush5(QColor(255, 255, 220, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette9.setBrush(QPalette::Active, QPalette::ToolTipBase, brush5);
        palette9.setBrush(QPalette::Active, QPalette::ToolTipText, brush2);
        palette9.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette9.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette9.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette9.setBrush(QPalette::Inactive, QPalette::Midlight, brush2);
        palette9.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
        palette9.setBrush(QPalette::Inactive, QPalette::Mid, brush2);
        palette9.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette9.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette9.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette9.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette9.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        palette9.setBrush(QPalette::Inactive, QPalette::Shadow, brush2);
        palette9.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush2);
        palette9.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush5);
        palette9.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush2);
        palette9.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette9.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette9.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette9.setBrush(QPalette::Disabled, QPalette::Midlight, brush2);
        palette9.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
        palette9.setBrush(QPalette::Disabled, QPalette::Mid, brush2);
        palette9.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette9.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette9.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette9.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette9.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        palette9.setBrush(QPalette::Disabled, QPalette::Shadow, brush2);
        palette9.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush2);
        palette9.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush5);
        palette9.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush2);
        ch1Widget->setPalette(palette9);
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        PARAMETRS = new QGroupBox(tab_3);
        PARAMETRS->setObjectName(QString::fromUtf8("PARAMETRS"));
        PARAMETRS->setGeometry(QRect(20, 160, 541, 130));
        QFont font10;
        font10.setFamily(QString::fromUtf8("DejaVu Sans"));
        font10.setPointSize(11);
        PARAMETRS->setFont(font10);
        PARAMETRS->setStyleSheet(QString::fromUtf8(""));
        PARAMETRS->setFlat(false);
        leamplitude = new QLineEdit(PARAMETRS);
        leamplitude->setObjectName(QString::fromUtf8("leamplitude"));
        leamplitude->setGeometry(QRect(391, 30, 92, 25));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(leamplitude->sizePolicy().hasHeightForWidth());
        leamplitude->setSizePolicy(sizePolicy2);
        lephase = new QLineEdit(PARAMETRS);
        lephase->setObjectName(QString::fromUtf8("lephase"));
        lephase->setGeometry(QRect(150, 80, 92, 25));
        label_12 = new QLabel(PARAMETRS);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(46, 80, 101, 24));
        leoffset = new QLineEdit(PARAMETRS);
        leoffset->setObjectName(QString::fromUtf8("leoffset"));
        leoffset->setGeometry(QRect(390, 80, 92, 25));
        sizePolicy2.setHeightForWidth(leoffset->sizePolicy().hasHeightForWidth());
        leoffset->setSizePolicy(sizePolicy2);
        label_14 = new QLabel(PARAMETRS);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(280, 30, 113, 24));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_14->sizePolicy().hasHeightForWidth());
        label_14->setSizePolicy(sizePolicy3);
        label_15 = new QLabel(PARAMETRS);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(46, 30, 101, 24));
        sizePolicy3.setHeightForWidth(label_15->sizePolicy().hasHeightForWidth());
        label_15->setSizePolicy(sizePolicy3);
        lefrequency = new QLineEdit(PARAMETRS);
        lefrequency->setObjectName(QString::fromUtf8("lefrequency"));
        lefrequency->setGeometry(QRect(150, 30, 92, 25));
        sizePolicy2.setHeightForWidth(lefrequency->sizePolicy().hasHeightForWidth());
        lefrequency->setSizePolicy(sizePolicy2);
        label_19 = new QLabel(PARAMETRS);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(280, 80, 67, 24));
        sizePolicy3.setHeightForWidth(label_19->sizePolicy().hasHeightForWidth());
        label_19->setSizePolicy(sizePolicy3);
        DRIVE_MODE = new QGroupBox(tab_3);
        DRIVE_MODE->setObjectName(QString::fromUtf8("DRIVE_MODE"));
        DRIVE_MODE->setGeometry(QRect(571, 20, 180, 131));
        DRIVE_MODE->setFont(font10);
        DRIVE_MODE->setFlat(false);
        burstWave = new QRadioButton(DRIVE_MODE);
        burstWave->setObjectName(QString::fromUtf8("burstWave"));
        burstWave->setGeometry(QRect(30, 90, 119, 17));
        burstWave->setFocusPolicy(Qt::NoFocus);
        burstWave->setStyleSheet(QString::fromUtf8("QRadioButton::indicator::checked {\n"
"		background-color:cyan;\n"
"     }\n"
"\n"
"     QRadioButton::indicator:checked:hover {\n"
"		background-color:cyan;\n"
"     }\n"
"\n"
"     QRadioButton::indicator:checked:pressed {\n"
"		background-color:cyan;\n"
"     }"));
        continuousWave = new QRadioButton(DRIVE_MODE);
        continuousWave->setObjectName(QString::fromUtf8("continuousWave"));
        continuousWave->setGeometry(QRect(30, 60, 131, 17));
        continuousWave->setFocusPolicy(Qt::NoFocus);
        continuousWave->setStyleSheet(QString::fromUtf8(""));
        continuousWave->setChecked(true);
        singleWave = new QRadioButton(DRIVE_MODE);
        singleWave->setObjectName(QString::fromUtf8("singleWave"));
        singleWave->setGeometry(QRect(30, 30, 120, 17));
        singleWave->setFocusPolicy(Qt::NoFocus);
        singleWave->setStyleSheet(QString::fromUtf8("QRadioButton::indicator::checked {\n"
"		background-color:cyan;\n"
"     }\n"
"\n"
"     QRadioButton::indicator:checked:hover {\n"
"		background-color:cyan;\n"
"     }\n"
"\n"
"     QRadioButton::indicator:checked:pressed {\n"
"		background-color:cyan;\n"
"     }"));
        WAVE_TYPE = new QGroupBox(tab_3);
        WAVE_TYPE->setObjectName(QString::fromUtf8("WAVE_TYPE"));
        WAVE_TYPE->setGeometry(QRect(20, 20, 541, 131));
        WAVE_TYPE->setFont(font10);
        WAVE_TYPE->setStyleSheet(QString::fromUtf8(""));
        WAVE_TYPE->setFlat(false);
        triangle = new QRadioButton(WAVE_TYPE);
        triangle->setObjectName(QString::fromUtf8("triangle"));
        triangle->setGeometry(QRect(370, 55, 110, 22));
        sizePolicy.setHeightForWidth(triangle->sizePolicy().hasHeightForWidth());
        triangle->setSizePolicy(sizePolicy);
        triangle->setFocusPolicy(Qt::NoFocus);
        square = new QRadioButton(WAVE_TYPE);
        square->setObjectName(QString::fromUtf8("square"));
        square->setGeometry(QRect(150, 55, 90, 22));
        sizePolicy.setHeightForWidth(square->sizePolicy().hasHeightForWidth());
        square->setSizePolicy(sizePolicy);
        square->setFocusPolicy(Qt::NoFocus);
        sine = new QRadioButton(WAVE_TYPE);
        sine->setObjectName(QString::fromUtf8("sine"));
        sine->setGeometry(QRect(50, 55, 70, 22));
        sizePolicy.setHeightForWidth(sine->sizePolicy().hasHeightForWidth());
        sine->setSizePolicy(sizePolicy);
        sine->setFocusPolicy(Qt::NoFocus);
        sine->setChecked(true);
        ramp = new QRadioButton(WAVE_TYPE);
        ramp->setObjectName(QString::fromUtf8("ramp"));
        ramp->setGeometry(QRect(270, 55, 80, 22));
        sizePolicy.setHeightForWidth(ramp->sizePolicy().hasHeightForWidth());
        ramp->setSizePolicy(sizePolicy);
        ramp->setFocusPolicy(Qt::NoFocus);
        RUN_STOP = new QGroupBox(tab_3);
        RUN_STOP->setObjectName(QString::fromUtf8("RUN_STOP"));
        RUN_STOP->setGeometry(QRect(571, 160, 180, 131));
        RUN_STOP->setFont(font10);
        RUN_STOP->setFlat(false);
        startDrive = new QPushButton(RUN_STOP);
        startDrive->setObjectName(QString::fromUtf8("startDrive"));
        startDrive->setGeometry(QRect(10, 50, 84, 41));
        startDrive->setFocusPolicy(Qt::NoFocus);
        startDrive->setStyleSheet(QString::fromUtf8("QPushButton { border: 2px solid rgba(0,0,0,0); border-radius: 25px; background-color: rgba(0,0,0,0); } QPushButton:pressed { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #dadbde, stop: 1 #f6f7fa); } QPushButton:flat { border: none; /* no border for a flat push button */ } QPushButton:default { border-color: navy; /* make the default button prominent */ }"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Actions-player-play-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        startDrive->setIcon(icon1);
        startDrive->setIconSize(QSize(48, 48));
        stopDrive = new QPushButton(RUN_STOP);
        stopDrive->setObjectName(QString::fromUtf8("stopDrive"));
        stopDrive->setGeometry(QRect(90, 50, 84, 41));
        stopDrive->setFocusPolicy(Qt::NoFocus);
        stopDrive->setStyleSheet(QString::fromUtf8("QPushButton { border: 2px solid rgba(0,0,0,0); border-radius: 25px; background-color: rgba(0,0,0,0); } QPushButton:pressed { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #dadbde, stop: 1 #f6f7fa); } QPushButton:flat { border: none; /* no border for a flat push button */ } QPushButton:default { border-color: navy; /* make the default button prominent */ }"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Actions-player-stop-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        stopDrive->setIcon(icon2);
        stopDrive->setIconSize(QSize(48, 48));
        stopDrive->setChecked(false);
        pushButton = new QPushButton(tab_3);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(680, 330, 51, 41));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"         border: 2px solid rgba(0,0,0,0);\n"
"         border-radius: 25px;\n"
"         background-color: rgba(0,0,0,0);\n"
"     }\n"
"\n"
"     QPushButton:pressed {\n"
"		background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"     }\n"
"\n"
"     QPushButton:flat {\n"
"         border: none; /* no border for a flat push button */\n"
"     }\n"
"\n"
"     QPushButton:default {\n"
"         border-color: navy; /* make the default button prominent */\n"
"     }"));
        pushButton->setIcon(icon);
        pushButton->setIconSize(QSize(48, 48));
        DSOParameters = new QGroupBox(tab_3);
        DSOParameters->setObjectName(QString::fromUtf8("DSOParameters"));
        DSOParameters->setGeometry(QRect(23, 300, 541, 171));
        DSOParameters->setFont(font10);
        DSOParameters->setStyleSheet(QString::fromUtf8(""));
        DSOParameters->setFlat(false);
        label_26 = new QLabel(DSOParameters);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setGeometry(QRect(38, 10, 101, 24));
        cmbSamplingType = new QComboBox(DSOParameters);
        cmbSamplingType->setObjectName(QString::fromUtf8("cmbSamplingType"));
        cmbSamplingType->setGeometry(QRect(10, 32, 201, 31));
        QFont font11;
        font11.setFamily(QString::fromUtf8("DejaVu Serif"));
        font11.setPointSize(14);
        cmbSamplingType->setFont(font11);
        cmbSamplingType->setStyleSheet(QString::fromUtf8("QComboBox{\n"
"show-decoration-selected: 1; \n"
"border:1px solid #F1F5DA;\n"
"border-radius: 10px;\n"
"color:black;\n"
"}\n"
"QComboBox::drop-down {\n"
"     width:40px;\n"
"	color:black;\n"
" }\n"
"\n"
"QComboBox::::item:selected {\n"
"     border: 1px solid #6a6ea9;\n"
" }\n"
"\n"
""));
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        tabWidget->addTab(tab_4, QString());
        LMH6518GUI->setCentralWidget(centralWidget);

        retranslateUi(LMH6518GUI);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(LMH6518GUI);
    } // setupUi

    void retranslateUi(QMainWindow *LMH6518GUI)
    {
        LMH6518GUI->setWindowTitle(QApplication::translate("LMH6518GUI", "LMH6518GUI", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QString());
        label_3->setText(QApplication::translate("LMH6518GUI", "Filter", 0, QApplication::UnicodeUTF8));
        Read->setText(QApplication::translate("LMH6518GUI", "&Read", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("LMH6518GUI", "LMH o/p", 0, QApplication::UnicodeUTF8));
        lblVoltage->setText(QApplication::translate("LMH6518GUI", "Voltage", 0, QApplication::UnicodeUTF8));
        Filter->clear();
        Filter->insertItems(0, QStringList()
         << QApplication::translate("LMH6518GUI", "Full", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LMH6518GUI", "20", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LMH6518GUI", "100", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LMH6518GUI", "200", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LMH6518GUI", "350", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LMH6518GUI", "650", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LMH6518GUI", "750", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LMH6518GUI", "X", 0, QApplication::UnicodeUTF8)
        );
        label_6->setText(QApplication::translate("LMH6518GUI", "Total Gain\n"
"(dB)", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("LMH6518GUI", "Power \n"
"Mode", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("LMH6518GUI", "Pre Amp Gain", 0, QApplication::UnicodeUTF8));
        totalGaindB->setText(QString());
        Exit->setText(QApplication::translate("LMH6518GUI", "&Exit", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("LMH6518GUI", "Ladder \n"
"Attenuator ", 0, QApplication::UnicodeUTF8));
        PreAmpGain->clear();
        PreAmpGain->insertItems(0, QStringList()
         << QApplication::translate("LMH6518GUI", "Low Gain", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LMH6518GUI", "High Gain", 0, QApplication::UnicodeUTF8)
        );
        Write->setText(QApplication::translate("LMH6518GUI", "&Write", 0, QApplication::UnicodeUTF8));
        Voltage->clear();
        Voltage->insertItems(0, QStringList()
         << QApplication::translate("LMH6518GUI", "20mV", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LMH6518GUI", "50mV", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LMH6518GUI", "100mV", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LMH6518GUI", "200mV", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LMH6518GUI", "500mV", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LMH6518GUI", "1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LMH6518GUI", "2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LMH6518GUI", "5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LMH6518GUI", "10", 0, QApplication::UnicodeUTF8)
        );
        ladder->setText(QString());
        TotalGain->setText(QString());
        PowerMode->clear();
        PowerMode->insertItems(0, QStringList()
         << QApplication::translate("LMH6518GUI", "Full Power", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LMH6518GUI", "Aux Hi-Z", 0, QApplication::UnicodeUTF8)
        );
        Calculate->setText(QApplication::translate("LMH6518GUI", "&Calculate", 0, QApplication::UnicodeUTF8));
        Data->setText(QString());
        label_16->setText(QApplication::translate("LMH6518GUI", "Data", 0, QApplication::UnicodeUTF8));
        totalGainV->setText(QString());
        label_17->setText(QApplication::translate("LMH6518GUI", "Total Gain\n"
"(Volt)", 0, QApplication::UnicodeUTF8));
        ChannelSel->clear();
        ChannelSel->insertItems(0, QStringList()
         << QApplication::translate("LMH6518GUI", "1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LMH6518GUI", "2", 0, QApplication::UnicodeUTF8)
        );
        lblChannel->setText(QApplication::translate("LMH6518GUI", "Channel", 0, QApplication::UnicodeUTF8));
        groupBox_8->setTitle(QApplication::translate("LMH6518GUI", "Receiver1", 0, QApplication::UnicodeUTF8));
        cmbCouplingR1->clear();
        cmbCouplingR1->insertItems(0, QStringList()
         << QApplication::translate("LMH6518GUI", "DC", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LMH6518GUI", "AC", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LMH6518GUI", "GND", 0, QApplication::UnicodeUTF8)
        );
        groupBox_9->setTitle(QApplication::translate("LMH6518GUI", "Receiver2", 0, QApplication::UnicodeUTF8));
        cmbCouplingR2->clear();
        cmbCouplingR2->insertItems(0, QStringList()
         << QApplication::translate("LMH6518GUI", "DC", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LMH6518GUI", "AC", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LMH6518GUI", "GND", 0, QApplication::UnicodeUTF8)
        );
        groupBox_7->setTitle(QApplication::translate("LMH6518GUI", "Receive Relays", 0, QApplication::UnicodeUTF8));
        chkR1->setText(QApplication::translate("LMH6518GUI", "CH1", 0, QApplication::UnicodeUTF8));
        chkR2->setText(QApplication::translate("LMH6518GUI", "CH2", 0, QApplication::UnicodeUTF8));
        m_tabDAC->setTitle(QApplication::translate("LMH6518GUI", "DAC", 0, QApplication::UnicodeUTF8));
        m_rbDACA->setText(QApplication::translate("LMH6518GUI", "DAC A\n"
"(DSO1-OFF)", 0, QApplication::UnicodeUTF8));
        m_rbDACB->setText(QApplication::translate("LMH6518GUI", "DAC B\n"
"(DSO1-T-OFF)", 0, QApplication::UnicodeUTF8));
        m_rbDACC->setText(QApplication::translate("LMH6518GUI", "DAC C\n"
"(DSO 2-OFF)", 0, QApplication::UnicodeUTF8));
        m_rbDACD->setText(QApplication::translate("LMH6518GUI", "DAC D\n"
"(DSO 2-T-OFF)", 0, QApplication::UnicodeUTF8));
        m_rbDACE->setText(QApplication::translate("LMH6518GUI", "DAC E\n"
"(DSO-E-T-OFF)", 0, QApplication::UnicodeUTF8));
        m_leDACValue->setText(QString());
        grpCH1->setTitle(QApplication::translate("LMH6518GUI", "Channel1", 0, QApplication::UnicodeUTF8));
        chkCH1Even->setText(QApplication::translate("LMH6518GUI", "Even", 0, QApplication::UnicodeUTF8));
        chkCH1Odd->setText(QApplication::translate("LMH6518GUI", "Odd", 0, QApplication::UnicodeUTF8));
        grpCH2->setTitle(QApplication::translate("LMH6518GUI", "Channel2", 0, QApplication::UnicodeUTF8));
        chkCH2Odd->setText(QApplication::translate("LMH6518GUI", "Odd", 0, QApplication::UnicodeUTF8));
        chkCH2Even->setText(QApplication::translate("LMH6518GUI", "Even", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("LMH6518GUI", "LMH6518 /ReceiverConf", 0, QApplication::UnicodeUTF8));
        grpTime->setTitle(QApplication::translate("LMH6518GUI", "Time", 0, QApplication::UnicodeUTF8));
        cmbTimeBase->clear();
        cmbTimeBase->insertItems(0, QStringList()
         << QApplication::translate("LMH6518GUI", "1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LMH6518GUI", "2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LMH6518GUI", "5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LMH6518GUI", "10", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LMH6518GUI", "20", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LMH6518GUI", "50", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LMH6518GUI", "100", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LMH6518GUI", "200", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LMH6518GUI", "500", 0, QApplication::UnicodeUTF8)
        );
        cmbTimeUnit->clear();
        cmbTimeUnit->insertItems(0, QStringList()
         << QApplication::translate("LMH6518GUI", "nS", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LMH6518GUI", "uS", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LMH6518GUI", "mS", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LMH6518GUI", "S", 0, QApplication::UnicodeUTF8)
        );
        lblTimeBase->setText(QApplication::translate("LMH6518GUI", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Century Schoolbook L'; font-weight:600; font-style:normal;\">\n"
"<table style=\"-qt-table-type: root; margin-top:4px; margin-bottom:4px; margin-left:4px; margin-right:4px;\">\n"
"<tr>\n"
"<td style=\"border: none;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"></p></td></tr></table></body></html>", 0, QApplication::UnicodeUTF8));
        butOffset->setText(QApplication::translate("LMH6518GUI", "Offset", 0, QApplication::UnicodeUTF8));
        groupBox_5->setTitle(QApplication::translate("LMH6518GUI", "RunMode", 0, QApplication::UnicodeUTF8));
        optSingle->setText(QApplication::translate("LMH6518GUI", "SINGLE", 0, QApplication::UnicodeUTF8));
        optAuto->setText(QApplication::translate("LMH6518GUI", "AUTO", 0, QApplication::UnicodeUTF8));
        optNormal->setText(QApplication::translate("LMH6518GUI", "NORMAL", 0, QApplication::UnicodeUTF8));
        butRUN->setText(QApplication::translate("LMH6518GUI", "RUN", 0, QApplication::UnicodeUTF8));
        butSTOP->setText(QApplication::translate("LMH6518GUI", "STOP", 0, QApplication::UnicodeUTF8));
        grpTimeSettings->setTitle(QApplication::translate("LMH6518GUI", "Timebase Settings", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("LMH6518GUI", "System\n"
"Frequency(Fs)", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("LMH6518GUI", "Fo - FTW\n"
"(0x98,0x9A)", 0, QApplication::UnicodeUTF8));
        leBTUR->setText(QString());
        grpSamples->setTitle(QApplication::translate("LMH6518GUI", "Samples", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("LMH6518GUI", "Post Count:", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("LMH6518GUI", "Pre Count:", 0, QApplication::UnicodeUTF8));
        lePreTrigger->setText(QString());
        groupBox_6->setTitle(QApplication::translate("LMH6518GUI", "Channel/Force Trigger", 0, QApplication::UnicodeUTF8));
        butForceTrigger->setText(QApplication::translate("LMH6518GUI", "Trigger", 0, QApplication::UnicodeUTF8));
        cmbChannel->clear();
        cmbChannel->insertItems(0, QStringList()
         << QApplication::translate("LMH6518GUI", "CH1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LMH6518GUI", "CH2", 0, QApplication::UnicodeUTF8)
        );
        cmbTriggerSoruce->clear();
        cmbTriggerSoruce->insertItems(0, QStringList()
         << QApplication::translate("LMH6518GUI", "ED_R", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LMH6518GUI", "ED_F", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LMH6518GUI", "PU_+", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LMH6518GUI", "PU_-", 0, QApplication::UnicodeUTF8)
        );
        grpMemory->setTitle(QApplication::translate("LMH6518GUI", "Memory", 0, QApplication::UnicodeUTF8));
        cmbMemory->clear();
        cmbMemory->insertItems(0, QStringList()
         << QApplication::translate("LMH6518GUI", "1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LMH6518GUI", "2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LMH6518GUI", "2.5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LMH6518GUI", "5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LMH6518GUI", "10", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LMH6518GUI", "25", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LMH6518GUI", "50", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LMH6518GUI", "100", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LMH6518GUI", "250", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LMH6518GUI", "500", 0, QApplication::UnicodeUTF8)
        );
        label_21->setText(QApplication::translate("LMH6518GUI", "HTrigger:", 0, QApplication::UnicodeUTF8));
        cmbSamples->clear();
        cmbSamples->insertItems(0, QStringList()
         << QApplication::translate("LMH6518GUI", "S", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LMH6518GUI", "KS", 0, QApplication::UnicodeUTF8)
        );
        chkInt_Ext->setText(QApplication::translate("LMH6518GUI", "Int/Ext", 0, QApplication::UnicodeUTF8));
        lblSamples->setText(QApplication::translate("LMH6518GUI", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Century Schoolbook L'; font-weight:600; font-style:normal;\">\n"
"<table style=\"-qt-table-type: root; margin-top:4px; margin-bottom:4px; margin-left:4px; margin-right:4px;\">\n"
"<tr>\n"
"<td style=\"border: none;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"></p></td></tr></table></body></html>", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("LMH6518GUI", "FREQ:", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("LMH6518GUI", "Total\n"
"Samples:", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("LMH6518GUI", "Voltage", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("LMH6518GUI", "Trigger", 0, QApplication::UnicodeUTF8));
        label_20->setText(QApplication::translate("LMH6518GUI", "Voltage", 0, QApplication::UnicodeUTF8));
        cmbLMHVoltage->clear();
        cmbLMHVoltage->insertItems(0, QStringList()
         << QApplication::translate("LMH6518GUI", "20mV", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LMH6518GUI", "50mV", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LMH6518GUI", "100mV", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LMH6518GUI", "200mV", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LMH6518GUI", "500mV", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LMH6518GUI", "1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LMH6518GUI", "2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LMH6518GUI", "5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LMH6518GUI", "10", 0, QApplication::UnicodeUTF8)
        );
        leGainDB->setText(QString());
        label_22->setText(QApplication::translate("LMH6518GUI", "Gain(dB)", 0, QApplication::UnicodeUTF8));
        label_23->setText(QApplication::translate("LMH6518GUI", "Gain(V)", 0, QApplication::UnicodeUTF8));
        leTotalV->setText(QString());
        LMHFilter->clear();
        LMHFilter->insertItems(0, QStringList()
         << QApplication::translate("LMH6518GUI", "Full", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LMH6518GUI", "20", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LMH6518GUI", "100", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LMH6518GUI", "200", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LMH6518GUI", "350", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LMH6518GUI", "650", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LMH6518GUI", "750", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LMH6518GUI", "X", 0, QApplication::UnicodeUTF8)
        );
        label_24->setText(QApplication::translate("LMH6518GUI", "Filter", 0, QApplication::UnicodeUTF8));
        LMHPowerMode->clear();
        LMHPowerMode->insertItems(0, QStringList()
         << QApplication::translate("LMH6518GUI", "Full Power", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LMH6518GUI", "Aux Hi-Z", 0, QApplication::UnicodeUTF8)
        );
        label_25->setText(QApplication::translate("LMH6518GUI", "Powermode", 0, QApplication::UnicodeUTF8));
        butSerialPanel->setText(QString());
        leStatus->setText(QApplication::translate("LMH6518GUI", "Ready..", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("LMH6518GUI", "WaveSettings", 0, QApplication::UnicodeUTF8));
        PARAMETRS->setTitle(QApplication::translate("LMH6518GUI", "PARAMETERS", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("LMH6518GUI", "PHASE", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("LMH6518GUI", "AMPLITUDE", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("LMH6518GUI", "FREQUENCY", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("LMH6518GUI", "OFFSET", 0, QApplication::UnicodeUTF8));
        DRIVE_MODE->setTitle(QApplication::translate("LMH6518GUI", "DRIVE MODE", 0, QApplication::UnicodeUTF8));
        burstWave->setText(QApplication::translate("LMH6518GUI", "BURST", 0, QApplication::UnicodeUTF8));
        continuousWave->setText(QApplication::translate("LMH6518GUI", "CONTINUOUS", 0, QApplication::UnicodeUTF8));
        singleWave->setText(QApplication::translate("LMH6518GUI", "SINGLE", 0, QApplication::UnicodeUTF8));
        WAVE_TYPE->setTitle(QApplication::translate("LMH6518GUI", "WAVE TYPE", 0, QApplication::UnicodeUTF8));
        triangle->setText(QApplication::translate("LMH6518GUI", "TRIANGLE", 0, QApplication::UnicodeUTF8));
        square->setText(QApplication::translate("LMH6518GUI", "SQUARE", 0, QApplication::UnicodeUTF8));
        sine->setText(QApplication::translate("LMH6518GUI", "SINE", 0, QApplication::UnicodeUTF8));
        ramp->setText(QApplication::translate("LMH6518GUI", "RAMP", 0, QApplication::UnicodeUTF8));
        RUN_STOP->setTitle(QApplication::translate("LMH6518GUI", "RUN/STOP", 0, QApplication::UnicodeUTF8));
        startDrive->setText(QString());
        stopDrive->setText(QString());
        pushButton->setText(QString());
        DSOParameters->setTitle(QApplication::translate("LMH6518GUI", "DSO Parameters", 0, QApplication::UnicodeUTF8));
        label_26->setText(QApplication::translate("LMH6518GUI", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Century Schoolbook L'; font-weight:600; font-style:normal;\">\n"
"<table border=\"0\" style=\"-qt-table-type: root; margin-top:4px; margin-bottom:4px; margin-left:4px; margin-right:4px;\">\n"
"<tr>\n"
"<td style=\"border: none;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:11pt;\">SAMPLING</span><span style=\" font-size:14pt;\">:</span></p></td></tr></table></body></html>", 0, QApplication::UnicodeUTF8));
        cmbSamplingType->clear();
        cmbSamplingType->insertItems(0, QStringList()
         << QApplication::translate("LMH6518GUI", "SAMPLE", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LMH6518GUI", "MIN-MAX", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LMH6518GUI", "HIRES", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LMH6518GUI", "MOVING_AVERAGE", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LMH6518GUI", "LINEAR_INTERPOLATION", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LMH6518GUI", "MOVING_LINEAR", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LMH6518GUI", "NORMAL", 0, QApplication::UnicodeUTF8)
        );
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("LMH6518GUI", "FunctionGenerator", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("LMH6518GUI", "AD9102", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class LMH6518GUI: public Ui_LMH6518GUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LMH6518GUI_H
