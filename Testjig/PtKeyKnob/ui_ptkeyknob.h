/********************************************************************************
** Form generated from reading UI file 'ptkeyknob.ui'
**
** Created: Tue Sep 9 12:03:28 2014
**      by: Qt User Interface Compiler version 4.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PTKEYKNOB_H
#define UI_PTKEYKNOB_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDial>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PtKeyKnobClass
{
public:
    QGroupBox *groupBox_24;
    QLabel *label_150;
    QLabel *label_151;
    QLineEdit *lineEdit_28;
    QLineEdit *lineEdit_29;
    QLineEdit *lineEdit_30;
    QLineEdit *lineEdit_31;
    QDial *dial;
    QLabel *label_152;
    QLabel *label_153;
    QLabel *label_154;
    QLineEdit *lineEdit_32;
    QLabel *label_155;
    QLineEdit *lineEdit_33;
    QLabel *label_156;
    QLineEdit *lineEdit_34;
    QLabel *label_157;
    QLineEdit *lineEdit_35;
    QProgressBar *progressBar;
    QLabel *label_158;
    QLabel *label_159;
    QGroupBox *groupBox_25;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_160;
    QLabel *label_170;
    QLabel *label_165;
    QLabel *label_166;
    QLabel *label_167;
    QLabel *label_168;
    QLabel *label_169;
    QLabel *label_171;
    QLabel *label_172;
    QLabel *label_174;
    QLabel *label_173;
    QLabel *label_175;
    QLabel *label_161;
    QLabel *label_162;
    QLabel *label_163;
    QLabel *label_164;
    QLabel *label_176;
    QLabel *label_177;
    QGroupBox *groupBox;
    QSpinBox *spinBox_2;
    QSpinBox *spinBox_3;
    QPushButton *pushButton;
    QLabel *label_5;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_3;
    QSpinBox *spinBox;

    void setupUi(QWidget *PtKeyKnobClass)
    {
        if (PtKeyKnobClass->objectName().isEmpty())
            PtKeyKnobClass->setObjectName(QString::fromUtf8("PtKeyKnobClass"));
        PtKeyKnobClass->resize(800, 600);
        QPalette palette;
        QBrush brush(QColor(108, 108, 107, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        PtKeyKnobClass->setPalette(palette);
        QFont font;
        font.setFamily(QString::fromUtf8("DejaVu Sans"));
        font.setPointSize(12);
        PtKeyKnobClass->setFont(font);
        groupBox_24 = new QGroupBox(PtKeyKnobClass);
        groupBox_24->setObjectName(QString::fromUtf8("groupBox_24"));
        groupBox_24->setGeometry(QRect(10, 10, 401, 281));
        groupBox_24->setStyleSheet(QString::fromUtf8("QGroupBox::indicator {\n"
"     width: 25px;\n"
"     height: 25px;\n"
"     border: 2px solid #ffffff;\n"
"	 border-radius: 10px;\n"
"	 color:red;\n"
"	 background-color: gray;\n"
" }\n"
" QGroupBox {\n"
"     background-color: light gray;\n"
"     border: 2px solid black;\n"
"     border-radius: 10px;\n"
"     margin-top: 1ex; /* leave space at the top for the title */\n"
"     font:bold 14px;\n"
"	color:white;\n"
" }\n"
" QGroupBox::title {\n"
"     subcontrol-origin: margin;\n"
"     subcontrol-position: top left; /* position at the top center */\n"
"     padding: 0 3px;\n"
"    border: 2px solid black;\n"
" }"));
        groupBox_24->setFlat(false);
        groupBox_24->setCheckable(true);
        groupBox_24->setChecked(false);
        label_150 = new QLabel(groupBox_24);
        label_150->setObjectName(QString::fromUtf8("label_150"));
        label_150->setGeometry(QRect(30, 40, 71, 17));
        QFont font1;
        font1.setPointSize(13);
        label_150->setFont(font1);
        label_150->setStyleSheet(QString::fromUtf8("QLabel::Enabled{\n"
"color:white;\n"
"}\n"
"QLabel::Disabled{\n"
"color:black;\n"
"}"));
        label_151 = new QLabel(groupBox_24);
        label_151->setObjectName(QString::fromUtf8("label_151"));
        label_151->setGeometry(QRect(30, 90, 71, 17));
        label_151->setFont(font1);
        label_151->setStyleSheet(QString::fromUtf8("QLabel::Enabled{\n"
"color:white;\n"
"}\n"
"QLabel::Disabled{\n"
"color:black;\n"
"}"));
        lineEdit_28 = new QLineEdit(groupBox_24);
        lineEdit_28->setObjectName(QString::fromUtf8("lineEdit_28"));
        lineEdit_28->setGeometry(QRect(120, 40, 40, 20));
        lineEdit_28->setStyleSheet(QString::fromUtf8(""));
        lineEdit_28->setFrame(false);
        lineEdit_29 = new QLineEdit(groupBox_24);
        lineEdit_29->setObjectName(QString::fromUtf8("lineEdit_29"));
        lineEdit_29->setGeometry(QRect(180, 40, 40, 20));
        lineEdit_29->setStyleSheet(QString::fromUtf8(""));
        lineEdit_29->setFrame(false);
        lineEdit_30 = new QLineEdit(groupBox_24);
        lineEdit_30->setObjectName(QString::fromUtf8("lineEdit_30"));
        lineEdit_30->setGeometry(QRect(120, 90, 40, 20));
        lineEdit_30->setStyleSheet(QString::fromUtf8(""));
        lineEdit_30->setFrame(false);
        lineEdit_31 = new QLineEdit(groupBox_24);
        lineEdit_31->setObjectName(QString::fromUtf8("lineEdit_31"));
        lineEdit_31->setGeometry(QRect(180, 90, 40, 20));
        lineEdit_31->setStyleSheet(QString::fromUtf8(""));
        lineEdit_31->setFrame(false);
        dial = new QDial(groupBox_24);
        dial->setObjectName(QString::fromUtf8("dial"));
        dial->setGeometry(QRect(280, 20, 111, 101));
        dial->setMaximum(255);
        dial->setOrientation(Qt::Horizontal);
        dial->setWrapping(true);
        label_152 = new QLabel(groupBox_24);
        label_152->setObjectName(QString::fromUtf8("label_152"));
        label_152->setGeometry(QRect(220, 40, 51, 17));
        label_152->setFont(font1);
        label_153 = new QLabel(groupBox_24);
        label_153->setObjectName(QString::fromUtf8("label_153"));
        label_153->setGeometry(QRect(220, 90, 51, 17));
        label_153->setFont(font1);
        label_154 = new QLabel(groupBox_24);
        label_154->setObjectName(QString::fromUtf8("label_154"));
        label_154->setGeometry(QRect(30, 140, 81, 17));
        label_154->setFont(font1);
        label_154->setStyleSheet(QString::fromUtf8("QLabel::Enabled{\n"
"color:white;\n"
"}\n"
"QLabel::Disabled{\n"
"color:black;\n"
"}"));
        lineEdit_32 = new QLineEdit(groupBox_24);
        lineEdit_32->setObjectName(QString::fromUtf8("lineEdit_32"));
        lineEdit_32->setGeometry(QRect(120, 140, 61, 20));
        lineEdit_32->setStyleSheet(QString::fromUtf8(""));
        lineEdit_32->setFrame(false);
        label_155 = new QLabel(groupBox_24);
        label_155->setObjectName(QString::fromUtf8("label_155"));
        label_155->setGeometry(QRect(180, 140, 121, 17));
        label_155->setFont(font1);
        lineEdit_33 = new QLineEdit(groupBox_24);
        lineEdit_33->setObjectName(QString::fromUtf8("lineEdit_33"));
        lineEdit_33->setGeometry(QRect(310, 140, 61, 23));
        lineEdit_33->setStyleSheet(QString::fromUtf8(""));
        lineEdit_33->setFrame(false);
        label_156 = new QLabel(groupBox_24);
        label_156->setObjectName(QString::fromUtf8("label_156"));
        label_156->setGeometry(QRect(30, 190, 81, 17));
        label_156->setFont(font1);
        label_156->setStyleSheet(QString::fromUtf8("QLabel::Enabled{\n"
"color:white;\n"
"}\n"
"QLabel::Disabled{\n"
"color:black;\n"
"}"));
        lineEdit_34 = new QLineEdit(groupBox_24);
        lineEdit_34->setObjectName(QString::fromUtf8("lineEdit_34"));
        lineEdit_34->setGeometry(QRect(120, 190, 51, 20));
        lineEdit_34->setStyleSheet(QString::fromUtf8(""));
        label_157 = new QLabel(groupBox_24);
        label_157->setObjectName(QString::fromUtf8("label_157"));
        label_157->setGeometry(QRect(180, 190, 121, 17));
        label_157->setFont(font1);
        lineEdit_35 = new QLineEdit(groupBox_24);
        lineEdit_35->setObjectName(QString::fromUtf8("lineEdit_35"));
        lineEdit_35->setGeometry(QRect(310, 190, 31, 23));
        lineEdit_35->setStyleSheet(QString::fromUtf8(""));
        progressBar = new QProgressBar(groupBox_24);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(180, 240, 211, 23));
        progressBar->setFont(font1);
        progressBar->setStyleSheet(QString::fromUtf8(""));
        progressBar->setValue(37);
        progressBar->setOrientation(Qt::Horizontal);
        progressBar->setInvertedAppearance(false);
        progressBar->setTextDirection(QProgressBar::TopToBottom);
        label_158 = new QLabel(groupBox_24);
        label_158->setObjectName(QString::fromUtf8("label_158"));
        label_158->setGeometry(QRect(30, 240, 151, 17));
        label_158->setFont(font1);
        label_158->setStyleSheet(QString::fromUtf8("QLabel::Enabled{\n"
"color:white;\n"
"}\n"
"QLabel::Disabled{\n"
"color:black;\n"
"}"));
        label_159 = new QLabel(groupBox_24);
        label_159->setObjectName(QString::fromUtf8("label_159"));
        label_159->setGeometry(QRect(290, 220, 101, 20));
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(false);
        font2.setWeight(50);
        label_159->setFont(font2);
        label_159->setTextFormat(Qt::PlainText);
        label_159->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        groupBox_25 = new QGroupBox(PtKeyKnobClass);
        groupBox_25->setObjectName(QString::fromUtf8("groupBox_25"));
        groupBox_25->setGeometry(QRect(10, 310, 781, 201));
        groupBox_25->setStyleSheet(QString::fromUtf8(" QGroupBox {\n"
"     background-color: light gray;\n"
"     border: 2px solid black;\n"
"     border-radius: 10px;\n"
"     margin-top: 1ex; /* leave space at the top for the title */\n"
"     font:bold 14px;\n"
"	color:white;\n"
" }\n"
" QGroupBox::title {\n"
"     subcontrol-origin: margin;\n"
"     subcontrol-position: top center; /* position at the top center */\n"
"     padding: 0 3px;\n"
"	 border: 2px solid black;\n"
" }"));
        groupBox_25->setFlat(false);
        groupBox_25->setCheckable(false);
        groupBox_25->setChecked(false);
        gridLayoutWidget = new QWidget(groupBox_25);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 20, 761, 161));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_160 = new QLabel(gridLayoutWidget);
        label_160->setObjectName(QString::fromUtf8("label_160"));
        label_160->setStyleSheet(QString::fromUtf8(" QLabel {\n"
"     border: 2px solid gray;\n"
"     border-radius: 23px;\n"
"     padding: 0 8px;\n"
"     background: gray;\n"
"     selection-background-color: darkgray;\n"
"	 color:black;\n"
"     font: bold 14px;\n"
" }"));
        label_160->setFrameShape(QFrame::Box);
        label_160->setFrameShadow(QFrame::Plain);
        label_160->setLineWidth(1);
        label_160->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_160, 0, 0, 1, 1);

        label_170 = new QLabel(gridLayoutWidget);
        label_170->setObjectName(QString::fromUtf8("label_170"));
        label_170->setStyleSheet(QString::fromUtf8(" QLabel {\n"
"     border: 2px solid gray;\n"
"     border-radius: 23px;\n"
"     padding: 0 8px;\n"
"     background: gray;\n"
"     selection-background-color: darkgray;\n"
"	 color:black;\n"
"     font: bold 14px;\n"
" }"));
        label_170->setFrameShape(QFrame::Box);
        label_170->setFrameShadow(QFrame::Plain);
        label_170->setLineWidth(1);
        label_170->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_170, 0, 1, 1, 1);

        label_165 = new QLabel(gridLayoutWidget);
        label_165->setObjectName(QString::fromUtf8("label_165"));
        label_165->setStyleSheet(QString::fromUtf8(" QLabel {\n"
"     border: 2px solid gray;\n"
"     border-radius: 23px;\n"
"     padding: 0 8px;\n"
"     background: gray;\n"
"     selection-background-color: darkgray;\n"
"	 color:black;\n"
"     font: bold 14px;\n"
" }"));
        label_165->setFrameShape(QFrame::Box);
        label_165->setFrameShadow(QFrame::Plain);
        label_165->setLineWidth(1);
        label_165->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_165, 0, 2, 1, 1);

        label_166 = new QLabel(gridLayoutWidget);
        label_166->setObjectName(QString::fromUtf8("label_166"));
        label_166->setStyleSheet(QString::fromUtf8(" QLabel {\n"
"     border: 2px solid gray;\n"
"     border-radius: 23px;\n"
"     padding: 0 8px;\n"
"     background: gray;\n"
"     selection-background-color: darkgray;\n"
"	 color:black;\n"
"     font: bold 14px;\n"
" }"));
        label_166->setFrameShape(QFrame::Box);
        label_166->setFrameShadow(QFrame::Plain);
        label_166->setLineWidth(1);
        label_166->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_166, 0, 3, 1, 1);

        label_167 = new QLabel(gridLayoutWidget);
        label_167->setObjectName(QString::fromUtf8("label_167"));
        label_167->setStyleSheet(QString::fromUtf8(" QLabel {\n"
"     border: 2px solid gray;\n"
"     border-radius: 23px;\n"
"     padding: 0 8px;\n"
"     background: gray;\n"
"     selection-background-color: darkgray;\n"
"	 color:black;\n"
"     font: bold 14px;\n"
" }"));
        label_167->setFrameShape(QFrame::Box);
        label_167->setFrameShadow(QFrame::Plain);
        label_167->setLineWidth(1);
        label_167->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_167, 0, 4, 1, 1);

        label_168 = new QLabel(gridLayoutWidget);
        label_168->setObjectName(QString::fromUtf8("label_168"));
        label_168->setStyleSheet(QString::fromUtf8(" QLabel {\n"
"     border: 2px solid gray;\n"
"     border-radius: 23px;\n"
"     padding: 0 8px;\n"
"     background: gray;\n"
"     selection-background-color: darkgray;\n"
"	 color:black;\n"
"     font: bold 14px;\n"
" }"));
        label_168->setFrameShape(QFrame::Box);
        label_168->setFrameShadow(QFrame::Plain);
        label_168->setLineWidth(1);
        label_168->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_168, 0, 5, 1, 1);

        label_169 = new QLabel(gridLayoutWidget);
        label_169->setObjectName(QString::fromUtf8("label_169"));
        label_169->setStyleSheet(QString::fromUtf8(" QLabel {\n"
"     border: 2px solid gray;\n"
"     border-radius: 23px;\n"
"     padding: 0 8px;\n"
"     background: gray;\n"
"     selection-background-color: darkgray;\n"
"	 color:black;\n"
"     font: bold 14px;\n"
" }"));
        label_169->setFrameShape(QFrame::Box);
        label_169->setFrameShadow(QFrame::Plain);
        label_169->setLineWidth(1);
        label_169->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_169, 1, 0, 1, 1);

        label_171 = new QLabel(gridLayoutWidget);
        label_171->setObjectName(QString::fromUtf8("label_171"));
        label_171->setStyleSheet(QString::fromUtf8(" QLabel {\n"
"     border: 2px solid gray;\n"
"     border-radius: 23px;\n"
"     padding: 0 8px;\n"
"     background: gray;\n"
"     selection-background-color: darkgray;\n"
"	 color:black;\n"
"     font: bold 14px;\n"
" }"));
        label_171->setFrameShape(QFrame::Box);
        label_171->setFrameShadow(QFrame::Plain);
        label_171->setLineWidth(1);
        label_171->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_171, 1, 1, 1, 1);

        label_172 = new QLabel(gridLayoutWidget);
        label_172->setObjectName(QString::fromUtf8("label_172"));
        label_172->setStyleSheet(QString::fromUtf8(" QLabel {\n"
"     border: 2px solid gray;\n"
"     border-radius: 23px;\n"
"     padding: 0 8px;\n"
"     background: gray;\n"
"     selection-background-color: darkgray;\n"
"	 color:black;\n"
"     font: bold 14px;\n"
" }"));
        label_172->setFrameShape(QFrame::Box);
        label_172->setFrameShadow(QFrame::Plain);
        label_172->setLineWidth(1);
        label_172->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_172, 1, 2, 1, 1);

        label_174 = new QLabel(gridLayoutWidget);
        label_174->setObjectName(QString::fromUtf8("label_174"));
        label_174->setStyleSheet(QString::fromUtf8(" QLabel {\n"
"     border: 2px solid gray;\n"
"     border-radius: 23px;\n"
"     padding: 0 8px;\n"
"     background: gray;\n"
"     selection-background-color: darkgray;\n"
"	 color:black;\n"
"     font: bold 14px;\n"
" }"));
        label_174->setFrameShape(QFrame::Box);
        label_174->setFrameShadow(QFrame::Plain);
        label_174->setLineWidth(1);
        label_174->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_174, 1, 3, 1, 1);

        label_173 = new QLabel(gridLayoutWidget);
        label_173->setObjectName(QString::fromUtf8("label_173"));
        label_173->setStyleSheet(QString::fromUtf8(" QLabel {\n"
"     border: 2px solid gray;\n"
"     border-radius: 23px;\n"
"     padding: 0 8px;\n"
"     background: gray;\n"
"     selection-background-color: darkgray;\n"
"	 color:black;\n"
"     font: bold 14px;\n"
" }"));
        label_173->setFrameShape(QFrame::Box);
        label_173->setFrameShadow(QFrame::Plain);
        label_173->setLineWidth(1);
        label_173->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_173, 1, 4, 1, 1);

        label_175 = new QLabel(gridLayoutWidget);
        label_175->setObjectName(QString::fromUtf8("label_175"));
        label_175->setStyleSheet(QString::fromUtf8(" QLabel {\n"
"     border: 2px solid gray;\n"
"     border-radius: 23px;\n"
"     padding: 0 8px;\n"
"     background: gray;\n"
"     selection-background-color: darkgray;\n"
"	 color:black;\n"
"     font: bold 14px;\n"
" }"));
        label_175->setFrameShape(QFrame::Box);
        label_175->setFrameShadow(QFrame::Plain);
        label_175->setLineWidth(1);
        label_175->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_175, 1, 5, 1, 1);

        label_161 = new QLabel(gridLayoutWidget);
        label_161->setObjectName(QString::fromUtf8("label_161"));
        label_161->setStyleSheet(QString::fromUtf8(" QLabel {\n"
"     border: 2px solid gray;\n"
"     border-radius: 23px;\n"
"     padding: 0 8px;\n"
"     background: gray;\n"
"     selection-background-color: darkgray;\n"
"	 color:black;\n"
"     font: bold 14px;\n"
" }"));
        label_161->setFrameShape(QFrame::Box);
        label_161->setFrameShadow(QFrame::Plain);
        label_161->setLineWidth(1);
        label_161->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_161, 2, 0, 1, 1);

        label_162 = new QLabel(gridLayoutWidget);
        label_162->setObjectName(QString::fromUtf8("label_162"));
        label_162->setStyleSheet(QString::fromUtf8(" QLabel {\n"
"     border: 2px solid gray;\n"
"     border-radius: 23px;\n"
"     padding: 0 8px;\n"
"     background: gray;\n"
"     selection-background-color: darkgray;\n"
"	 color:black;\n"
"     font: bold 14px;\n"
" }"));
        label_162->setFrameShape(QFrame::Box);
        label_162->setFrameShadow(QFrame::Plain);
        label_162->setLineWidth(1);
        label_162->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_162, 2, 1, 1, 1);

        label_163 = new QLabel(gridLayoutWidget);
        label_163->setObjectName(QString::fromUtf8("label_163"));
        label_163->setStyleSheet(QString::fromUtf8(" QLabel {\n"
"     border: 2px solid gray;\n"
"     border-radius: 23px;\n"
"     padding: 0 8px;\n"
"     background: gray;\n"
"     selection-background-color: darkgray;\n"
"	 color:black;\n"
"     font: bold 14px;\n"
" }"));
        label_163->setFrameShape(QFrame::Box);
        label_163->setFrameShadow(QFrame::Plain);
        label_163->setLineWidth(1);
        label_163->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_163, 2, 2, 1, 1);

        label_164 = new QLabel(gridLayoutWidget);
        label_164->setObjectName(QString::fromUtf8("label_164"));
        label_164->setStyleSheet(QString::fromUtf8(" QLabel {\n"
"     border: 2px solid gray;\n"
"     border-radius: 23px;\n"
"     padding: 0 8px;\n"
"     background: gray;\n"
"     selection-background-color: darkgray;\n"
"	 color:black;\n"
"     font: bold 14px;\n"
" }"));
        label_164->setFrameShape(QFrame::Box);
        label_164->setFrameShadow(QFrame::Plain);
        label_164->setLineWidth(1);
        label_164->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_164, 2, 3, 1, 1);

        label_176 = new QLabel(gridLayoutWidget);
        label_176->setObjectName(QString::fromUtf8("label_176"));
        label_176->setStyleSheet(QString::fromUtf8(" QLabel {\n"
"     border: 2px solid gray;\n"
"     border-radius: 23px;\n"
"     padding: 0 8px;\n"
"     background: gray;\n"
"     selection-background-color: darkgray;\n"
"	 color:black;\n"
"     font: bold 14px;\n"
" }"));
        label_176->setFrameShape(QFrame::Box);
        label_176->setFrameShadow(QFrame::Plain);
        label_176->setLineWidth(1);
        label_176->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_176, 2, 4, 1, 1);

        label_177 = new QLabel(gridLayoutWidget);
        label_177->setObjectName(QString::fromUtf8("label_177"));
        label_177->setStyleSheet(QString::fromUtf8(" QLabel {\n"
"     border: 2px solid gray;\n"
"     border-radius: 23px;\n"
"     padding: 0 8px;\n"
"     background: gray;\n"
"     selection-background-color: darkgray;\n"
"	 color:black;\n"
"     font: bold 14px;\n"
" }"));
        label_177->setFrameShape(QFrame::Box);
        label_177->setFrameShadow(QFrame::Plain);
        label_177->setLineWidth(1);
        label_177->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_177, 2, 5, 1, 1);

        groupBox = new QGroupBox(PtKeyKnobClass);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(420, 10, 371, 281));
        groupBox->setStyleSheet(QString::fromUtf8(" QGroupBox {\n"
"     background-color: light gray;\n"
"     border: 2px solid black;\n"
"     border-radius: 10px;\n"
"     margin-top: 1ex; /* leave space at the top for the title */\n"
"     font:bold 14px;\n"
"	color:white;\n"
" }\n"
" QGroupBox::title {\n"
"     subcontrol-origin: margin;\n"
"     subcontrol-position: top center; /* position at the top center */\n"
"     padding: 0 3px;\n"
"	 border: 2px solid black;\n"
" }"));
        groupBox->setFlat(false);
        spinBox_2 = new QSpinBox(groupBox);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));
        spinBox_2->setGeometry(QRect(200, 100, 111, 41));
        spinBox_2->setFont(font);
        spinBox_2->setStyleSheet(QString::fromUtf8("QSpinBox::up-button {\n"
"     width: 50px; \n"
" }\n"
" QSpinBox::down-button {\n"
"     width: 50px;\n"
" }"));
        spinBox_2->setValue(31);
        spinBox_3 = new QSpinBox(groupBox);
        spinBox_3->setObjectName(QString::fromUtf8("spinBox_3"));
        spinBox_3->setGeometry(QRect(200, 160, 111, 41));
        spinBox_3->setFont(font);
        spinBox_3->setStyleSheet(QString::fromUtf8("QSpinBox::up-button {\n"
"     width: 50px; \n"
" }\n"
" QSpinBox::down-button {\n"
"     width: 50px;\n"
" }"));
        spinBox_3->setMinimum(2);
        spinBox_3->setMaximum(10);
        spinBox_3->setSingleStep(1);
        spinBox_3->setValue(2);
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(220, 210, 84, 31));
        QFont font3;
        font3.setFamily(QString::fromUtf8("DejaVu Sans"));
        font3.setPointSize(11);
        pushButton->setFont(font3);
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"     border: 2px solid #8f8f91;\n"
"     border-radius: 6px;\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #f6f7fa, stop: 1 #dadbde);\n"
"     min-width: 80px;\n"
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
"     border-color: navy; /* make the default button prominent */\n"
" }"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(330, 180, 31, 17));
        label_5->setFont(font3);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(50, 50, 71, 17));
        QFont font4;
        font4.setFamily(QString::fromUtf8("DejaVu Sans"));
        font4.setPointSize(13);
        label_2->setFont(font4);
        label_2->setStyleSheet(QString::fromUtf8("QLabel::Enabled{\n"
"color:white;\n"
"}\n"
"QLabel::Disabled{\n"
"color:black;\n"
"}"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(50, 170, 121, 17));
        label_4->setFont(font4);
        label_4->setStyleSheet(QString::fromUtf8("QLabel::Enabled{\n"
"color:white;\n"
"}\n"
"QLabel::Disabled{\n"
"color:black;\n"
"}"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(50, 110, 91, 17));
        label_3->setFont(font4);
        label_3->setStyleSheet(QString::fromUtf8("QLabel::Enabled{\n"
"color:white;\n"
"}\n"
"QLabel::Disabled{\n"
"color:black;\n"
"}"));
        spinBox = new QSpinBox(groupBox);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(200, 40, 111, 41));
        spinBox->setFont(font);
        spinBox->setStyleSheet(QString::fromUtf8("QSpinBox::up-button {\n"
"     width: 50px; \n"
" }\n"
" QSpinBox::down-button {\n"
"     width: 50px;\n"
" }"));
        spinBox->setValue(63);

        retranslateUi(PtKeyKnobClass);

        QMetaObject::connectSlotsByName(PtKeyKnobClass);
    } // setupUi

    void retranslateUi(QWidget *PtKeyKnobClass)
    {
        PtKeyKnobClass->setWindowTitle(QApplication::translate("PtKeyKnobClass", "PtKeyKnob", 0, QApplication::UnicodeUTF8));
        groupBox_24->setTitle(QApplication::translate("PtKeyKnobClass", "Magnetic Rotary Knob", 0, QApplication::UnicodeUTF8));
        label_150->setText(QApplication::translate("PtKeyKnobClass", "Gain     :", 0, QApplication::UnicodeUTF8));
        label_151->setText(QApplication::translate("PtKeyKnobClass", "Angle   :", 0, QApplication::UnicodeUTF8));
        label_152->setText(QApplication::translate("PtKeyKnobClass", "(Hex)", 0, QApplication::UnicodeUTF8));
        label_153->setText(QApplication::translate("PtKeyKnobClass", "(Hex)", 0, QApplication::UnicodeUTF8));
        label_154->setText(QApplication::translate("PtKeyKnobClass", "Interval :", 0, QApplication::UnicodeUTF8));
        label_155->setText(QApplication::translate("PtKeyKnobClass", "Drive Mode  :", 0, QApplication::UnicodeUTF8));
        label_156->setText(QApplication::translate("PtKeyKnobClass", "Degree :", 0, QApplication::UnicodeUTF8));
        label_157->setText(QApplication::translate("PtKeyKnobClass", "Data Validity :", 0, QApplication::UnicodeUTF8));
        label_158->setText(QApplication::translate("PtKeyKnobClass", "Signal Strength :", 0, QApplication::UnicodeUTF8));
        label_159->setText(QString());
        groupBox_25->setTitle(QApplication::translate("PtKeyKnobClass", "KeyPad", 0, QApplication::UnicodeUTF8));
        label_160->setText(QApplication::translate("PtKeyKnobClass", "MENU", 0, QApplication::UnicodeUTF8));
        label_170->setText(QApplication::translate("PtKeyKnobClass", "ESC", 0, QApplication::UnicodeUTF8));
        label_165->setText(QApplication::translate("PtKeyKnobClass", "F1", 0, QApplication::UnicodeUTF8));
        label_166->setText(QApplication::translate("PtKeyKnobClass", "F2", 0, QApplication::UnicodeUTF8));
        label_167->setText(QApplication::translate("PtKeyKnobClass", "F3", 0, QApplication::UnicodeUTF8));
        label_168->setText(QApplication::translate("PtKeyKnobClass", "F4", 0, QApplication::UnicodeUTF8));
        label_169->setText(QApplication::translate("PtKeyKnobClass", "F5", 0, QApplication::UnicodeUTF8));
        label_171->setText(QApplication::translate("PtKeyKnobClass", "UP", 0, QApplication::UnicodeUTF8));
        label_172->setText(QApplication::translate("PtKeyKnobClass", "DOWN", 0, QApplication::UnicodeUTF8));
        label_174->setText(QApplication::translate("PtKeyKnobClass", "RIGHT", 0, QApplication::UnicodeUTF8));
        label_173->setText(QApplication::translate("PtKeyKnobClass", "LEFT", 0, QApplication::UnicodeUTF8));
        label_175->setText(QApplication::translate("PtKeyKnobClass", "ENTER", 0, QApplication::UnicodeUTF8));
        label_161->setText(QApplication::translate("PtKeyKnobClass", "SETUP", 0, QApplication::UnicodeUTF8));
        label_162->setText(QApplication::translate("PtKeyKnobClass", "DEFAULT", 0, QApplication::UnicodeUTF8));
        label_163->setText(QApplication::translate("PtKeyKnobClass", "TOUCH", 0, QApplication::UnicodeUTF8));
        label_164->setText(QApplication::translate("PtKeyKnobClass", "FILE", 0, QApplication::UnicodeUTF8));
        label_176->setText(QApplication::translate("PtKeyKnobClass", "SCALE", 0, QApplication::UnicodeUTF8));
        label_177->setText(QApplication::translate("PtKeyKnobClass", "RUN/STOP", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("PtKeyKnobClass", "Back Light Control", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("PtKeyKnobClass", "on/off", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("PtKeyKnobClass", "sec", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("PtKeyKnobClass", "Period", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("PtKeyKnobClass", "ON/OFF Delay", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("PtKeyKnobClass", "DutyCycle", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class PtKeyKnobClass: public Ui_PtKeyKnobClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PTKEYKNOB_H
