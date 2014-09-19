/********************************************************************************
** Form generated from reading UI file 'channelwidget.ui'
**
** Created: Tue Apr 8 11:32:17 2014
**      by: Qt User Interface Compiler version 4.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANNELWIDGET_H
#define UI_CHANNELWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChannelWidget
{
public:
    QGroupBox *groupBox;
    QCheckBox *Ch1TraceON;
    QCheckBox *checkBox_4;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QGroupBox *groupBox_2;
    QCheckBox *Ch1VariableGain;
    QGroupBox *groupBox_3;
    QCheckBox *Ch1ZeroOffset;
    QGroupBox *groupBox_4;
    QWidget *Ch1CouplingPopup;
    QPushButton *ch1CouplingDC;
    QPushButton *ch1CouplingAC;
    QPushButton *ch1CouplingGND;
    QPushButton *butClose;

    void setupUi(QWidget *ChannelWidget)
    {
        if (ChannelWidget->objectName().isEmpty())
            ChannelWidget->setObjectName(QString::fromUtf8("ChannelWidget"));
        ChannelWidget->setWindowModality(Qt::ApplicationModal);
        ChannelWidget->resize(239, 488);
        groupBox = new QGroupBox(ChannelWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(1, -6, 261, 501));
        groupBox->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
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
        Ch1TraceON = new QCheckBox(groupBox);
        Ch1TraceON->setObjectName(QString::fromUtf8("Ch1TraceON"));
        Ch1TraceON->setGeometry(QRect(10, 417, 111, 25));
        QFont font;
        font.setFamily(QString::fromUtf8("DejaVu Sans"));
        font.setPointSize(12);
        font.setBold(false);
        font.setWeight(50);
        Ch1TraceON->setFont(font);
        Ch1TraceON->setFocusPolicy(Qt::NoFocus);
        Ch1TraceON->setStyleSheet(QString::fromUtf8("QCheckBox::indicator {\n"
"     width: 24px;\n"
"     height: 24px;\n"
" }\n"
"QCheckBox\n"
"{\n"
"color:white\n"
"}"));
        checkBox_4 = new QCheckBox(groupBox);
        checkBox_4->setObjectName(QString::fromUtf8("checkBox_4"));
        checkBox_4->setGeometry(QRect(130, 417, 93, 25));
        checkBox_4->setFont(font);
        checkBox_4->setFocusPolicy(Qt::NoFocus);
        checkBox_4->setStyleSheet(QString::fromUtf8("QCheckBox::indicator {\n"
"     width: 24px;\n"
"     height: 24px;\n"
" }\n"
"QCheckBox\n"
"{\n"
"color:white\n"
"}\n"
""));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 19, 221, 381));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        groupBox_2 = new QGroupBox(layoutWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        QFont font1;
        font1.setBold(true);
        font1.setItalic(false);
        font1.setWeight(75);
        groupBox_2->setFont(font1);
        Ch1VariableGain = new QCheckBox(groupBox_2);
        Ch1VariableGain->setObjectName(QString::fromUtf8("Ch1VariableGain"));
        Ch1VariableGain->setGeometry(QRect(10, 92, 141, 25));
        Ch1VariableGain->setFont(font);
        Ch1VariableGain->setFocusPolicy(Qt::NoFocus);
        Ch1VariableGain->setStyleSheet(QString::fromUtf8("QCheckBox::indicator {\n"
"     width: 24px;\n"
"     height: 24px;\n"
" }\n"
"\n"
"QCheckBox\n"
"{\n"
"color:white\n"
"}"));

        gridLayout->addWidget(groupBox_2, 0, 0, 1, 1);

        groupBox_3 = new QGroupBox(layoutWidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setFont(font1);
        Ch1ZeroOffset = new QCheckBox(groupBox_3);
        Ch1ZeroOffset->setObjectName(QString::fromUtf8("Ch1ZeroOffset"));
        Ch1ZeroOffset->setGeometry(QRect(10, 84, 121, 25));
        Ch1ZeroOffset->setFont(font);
        Ch1ZeroOffset->setFocusPolicy(Qt::NoFocus);
        Ch1ZeroOffset->setStyleSheet(QString::fromUtf8("QCheckBox::indicator {\n"
"     width: 24px;\n"
"     height: 24px;\n"
" }\n"
"QCheckBox\n"
"{\n"
"color:white\n"
"}"));

        gridLayout->addWidget(groupBox_3, 1, 0, 1, 1);

        groupBox_4 = new QGroupBox(layoutWidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setFont(font1);
        Ch1CouplingPopup = new QWidget(groupBox_4);
        Ch1CouplingPopup->setObjectName(QString::fromUtf8("Ch1CouplingPopup"));
        Ch1CouplingPopup->setGeometry(QRect(20, 78, 141, 31));
        ch1CouplingDC = new QPushButton(Ch1CouplingPopup);
        ch1CouplingDC->setObjectName(QString::fromUtf8("ch1CouplingDC"));
        ch1CouplingDC->setGeometry(QRect(1, 2, 41, 25));
        QFont font2;
        font2.setFamily(QString::fromUtf8("DejaVu Sans"));
        font2.setPointSize(11);
        ch1CouplingDC->setFont(font2);
        ch1CouplingDC->setFocusPolicy(Qt::NoFocus);
        ch1CouplingDC->setStyleSheet(QString::fromUtf8(" QPushButton {\n"
"     border: 2px solid #8f8f91;\n"
"     border-radius: 10px;\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #f6f7fa, stop: 1 #dadbfe);\n"
" }\n"
"\n"
" QPushButton:pressed {\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
" }\n"
"\n"
" QPushButton:flat {\n"
"     border: none; /* no border for a flat push button */\n"
" }\n"
"\n"
" QPushButton:default {\n"
"     border-color: blue; /* make the default button prominent */\n"
" }"));
        ch1CouplingAC = new QPushButton(Ch1CouplingPopup);
        ch1CouplingAC->setObjectName(QString::fromUtf8("ch1CouplingAC"));
        ch1CouplingAC->setGeometry(QRect(46, 2, 41, 25));
        ch1CouplingAC->setFont(font2);
        ch1CouplingAC->setFocusPolicy(Qt::NoFocus);
        ch1CouplingAC->setStyleSheet(QString::fromUtf8(" QPushButton {\n"
"     border: 2px solid #8f8f91;\n"
"     border-radius: 10px;\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #f6f7fa, stop: 1 #dadbfe);\n"
" }\n"
"\n"
" QPushButton:pressed {\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
" }\n"
"\n"
" QPushButton:flat {\n"
"     border: none; /* no border for a flat push button */\n"
" }\n"
"\n"
" QPushButton:default {\n"
"     border-color: blue; /* make the default button prominent */\n"
" }"));
        ch1CouplingGND = new QPushButton(Ch1CouplingPopup);
        ch1CouplingGND->setObjectName(QString::fromUtf8("ch1CouplingGND"));
        ch1CouplingGND->setGeometry(QRect(92, 2, 41, 25));
        ch1CouplingGND->setFont(font2);
        ch1CouplingGND->setFocusPolicy(Qt::NoFocus);
        ch1CouplingGND->setStyleSheet(QString::fromUtf8(" QPushButton {\n"
"     border: 2px solid #8f8f91;\n"
"     border-radius: 10px;\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #f6f7fa, stop: 1 #dadbfe);\n"
" }\n"
"\n"
" QPushButton:pressed {\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
" }\n"
"\n"
" QPushButton:flat {\n"
"     border: none; /* no border for a flat push button */\n"
" }\n"
"\n"
" QPushButton:default {\n"
"     border-color: blue; /* make the default button prominent */\n"
" }"));

        gridLayout->addWidget(groupBox_4, 2, 0, 1, 1);

        butClose = new QPushButton(groupBox);
        butClose->setObjectName(QString::fromUtf8("butClose"));
        butClose->setGeometry(QRect(69, 455, 93, 30));
        butClose->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	color:white\n"
"}"));

        retranslateUi(ChannelWidget);

        QMetaObject::connectSlotsByName(ChannelWidget);
    } // setupUi

    void retranslateUi(QWidget *ChannelWidget)
    {
        ChannelWidget->setWindowTitle(QApplication::translate("ChannelWidget", "Channel1", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QString());
        Ch1TraceON->setText(QApplication::translate("ChannelWidget", "Trace ON", 0, QApplication::UnicodeUTF8));
        checkBox_4->setText(QApplication::translate("ChannelWidget", "Invert", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("ChannelWidget", "Volt/div", 0, QApplication::UnicodeUTF8));
        Ch1VariableGain->setText(QApplication::translate("ChannelWidget", "Variable Gain", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("ChannelWidget", "Offset", 0, QApplication::UnicodeUTF8));
        Ch1ZeroOffset->setText(QApplication::translate("ChannelWidget", "Zero Offset", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("ChannelWidget", "Coupling", 0, QApplication::UnicodeUTF8));
        ch1CouplingDC->setText(QApplication::translate("ChannelWidget", "DC", 0, QApplication::UnicodeUTF8));
        ch1CouplingAC->setText(QApplication::translate("ChannelWidget", "AC", 0, QApplication::UnicodeUTF8));
        ch1CouplingGND->setText(QApplication::translate("ChannelWidget", "GND", 0, QApplication::UnicodeUTF8));
        butClose->setText(QApplication::translate("ChannelWidget", "Close", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ChannelWidget: public Ui_ChannelWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANNELWIDGET_H
