/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Thu Sep 25 16:58:32 2014
**      by: Qt User Interface Compiler version 4.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSine;
    QAction *actionSquare;
    QAction *actionTriangle;
    QAction *actionSAwtooth;
    QAction *actionPulse;
    QAction *actionMerge_All;
    QAction *actionRandom;
    QAction *actionRemove_All;
    QAction *actionRemove_Selected;
    QAction *actionZoomin;
    QAction *actionZoom_Out;
    QWidget *centralWidget;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_3;
    QCustomPlot *customPlot;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *butSine;
    QPushButton *butSquare;
    QPushButton *butTriangle;
    QPushButton *butSawtooth;
    QPushButton *butPulse;
    QPushButton *butRandom;
    QPushButton *butMergeAll;
    QPushButton *butRemoveSelected;
    QPushButton *butRemoveAll;
    QPushButton *butExit;
    QWidget *verticalWidget_2;
    QLabel *label_Amplitude;
    QLineEdit *lineEdit;
    QWidget *verticalWidget_3;
    QLabel *label_Frequency;
    QLineEdit *lineEdit_2;
    QWidget *verticalWidget_4;
    QLabel *label_Offset;
    QLineEdit *lineEdit_3;
    QWidget *verticalWidget_5;
    QLabel *label_Phase;
    QLineEdit *lineEdit_4;
    QPushButton *butZoomIn;
    QPushButton *butZoomOut;
    QPushButton *butStop;
    QPushButton *butStart;
    QPushButton *butRefresh;
    QPushButton *butAppBck;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        MainWindow->setStyleSheet(QString::fromUtf8("QWidget{\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #ffffff, stop: 1 #dadbff);border-radius:10px;}"));
        actionSine = new QAction(MainWindow);
        actionSine->setObjectName(QString::fromUtf8("actionSine"));
        actionSquare = new QAction(MainWindow);
        actionSquare->setObjectName(QString::fromUtf8("actionSquare"));
        actionTriangle = new QAction(MainWindow);
        actionTriangle->setObjectName(QString::fromUtf8("actionTriangle"));
        actionSAwtooth = new QAction(MainWindow);
        actionSAwtooth->setObjectName(QString::fromUtf8("actionSAwtooth"));
        actionPulse = new QAction(MainWindow);
        actionPulse->setObjectName(QString::fromUtf8("actionPulse"));
        actionMerge_All = new QAction(MainWindow);
        actionMerge_All->setObjectName(QString::fromUtf8("actionMerge_All"));
        actionRandom = new QAction(MainWindow);
        actionRandom->setObjectName(QString::fromUtf8("actionRandom"));
        actionRemove_All = new QAction(MainWindow);
        actionRemove_All->setObjectName(QString::fromUtf8("actionRemove_All"));
        actionRemove_Selected = new QAction(MainWindow);
        actionRemove_Selected->setObjectName(QString::fromUtf8("actionRemove_Selected"));
        actionZoomin = new QAction(MainWindow);
        actionZoomin->setObjectName(QString::fromUtf8("actionZoomin"));
        actionZoom_Out = new QAction(MainWindow);
        actionZoom_Out->setObjectName(QString::fromUtf8("actionZoom_Out"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        frame_2 = new QFrame(centralWidget);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(10, 33, 693, 453));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Sunken);
        frame_2->setLineWidth(1);
        frame_2->setMidLineWidth(0);
        verticalLayout_3 = new QVBoxLayout(frame_2);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        customPlot = new QCustomPlot(frame_2);
        customPlot->setObjectName(QString::fromUtf8("customPlot"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(customPlot->sizePolicy().hasHeightForWidth());
        customPlot->setSizePolicy(sizePolicy);

        verticalLayout_3->addWidget(customPlot);

        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(710, 40, 81, 441));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        butSine = new QPushButton(verticalLayoutWidget);
        butSine->setObjectName(QString::fromUtf8("butSine"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(butSine->sizePolicy().hasHeightForWidth());
        butSine->setSizePolicy(sizePolicy1);
        QFont font;
        font.setFamily(QString::fromUtf8("DejaVu Sans"));
        font.setBold(true);
        font.setItalic(false);
        font.setWeight(75);
        butSine->setFont(font);
        butSine->setFocusPolicy(Qt::NoFocus);
        butSine->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color:white;\n"
"border: 1px solid #2D5059;\n"
"border-radius: 20px;\n"
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
"}"));

        verticalLayout->addWidget(butSine);

        butSquare = new QPushButton(verticalLayoutWidget);
        butSquare->setObjectName(QString::fromUtf8("butSquare"));
        sizePolicy1.setHeightForWidth(butSquare->sizePolicy().hasHeightForWidth());
        butSquare->setSizePolicy(sizePolicy1);
        butSquare->setFont(font);
        butSquare->setFocusPolicy(Qt::NoFocus);
        butSquare->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color:white;\n"
"border: 1px solid #2D5059;\n"
"border-radius: 20px;\n"
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
"}"));

        verticalLayout->addWidget(butSquare);

        butTriangle = new QPushButton(verticalLayoutWidget);
        butTriangle->setObjectName(QString::fromUtf8("butTriangle"));
        sizePolicy1.setHeightForWidth(butTriangle->sizePolicy().hasHeightForWidth());
        butTriangle->setSizePolicy(sizePolicy1);
        butTriangle->setFont(font);
        butTriangle->setFocusPolicy(Qt::NoFocus);
        butTriangle->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color:white;\n"
"border: 1px solid #2D5059;\n"
"border-radius: 20px;\n"
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
"}"));

        verticalLayout->addWidget(butTriangle);

        butSawtooth = new QPushButton(verticalLayoutWidget);
        butSawtooth->setObjectName(QString::fromUtf8("butSawtooth"));
        sizePolicy1.setHeightForWidth(butSawtooth->sizePolicy().hasHeightForWidth());
        butSawtooth->setSizePolicy(sizePolicy1);
        butSawtooth->setFont(font);
        butSawtooth->setFocusPolicy(Qt::NoFocus);
        butSawtooth->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color:white;\n"
"border: 1px solid #2D5059;\n"
"border-radius: 20px;\n"
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
"}"));

        verticalLayout->addWidget(butSawtooth);

        butPulse = new QPushButton(verticalLayoutWidget);
        butPulse->setObjectName(QString::fromUtf8("butPulse"));
        sizePolicy1.setHeightForWidth(butPulse->sizePolicy().hasHeightForWidth());
        butPulse->setSizePolicy(sizePolicy1);
        butPulse->setFont(font);
        butPulse->setFocusPolicy(Qt::NoFocus);
        butPulse->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color:white;\n"
"border: 1px solid #2D5059;\n"
"border-radius: 20px;\n"
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
"}"));

        verticalLayout->addWidget(butPulse);

        butRandom = new QPushButton(verticalLayoutWidget);
        butRandom->setObjectName(QString::fromUtf8("butRandom"));
        sizePolicy1.setHeightForWidth(butRandom->sizePolicy().hasHeightForWidth());
        butRandom->setSizePolicy(sizePolicy1);
        butRandom->setFont(font);
        butRandom->setFocusPolicy(Qt::NoFocus);
        butRandom->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color:white;\n"
"border: 1px solid #2D5059;\n"
"border-radius: 20px;\n"
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
"}"));

        verticalLayout->addWidget(butRandom);

        butMergeAll = new QPushButton(verticalLayoutWidget);
        butMergeAll->setObjectName(QString::fromUtf8("butMergeAll"));
        sizePolicy1.setHeightForWidth(butMergeAll->sizePolicy().hasHeightForWidth());
        butMergeAll->setSizePolicy(sizePolicy1);
        butMergeAll->setFont(font);
        butMergeAll->setFocusPolicy(Qt::NoFocus);
        butMergeAll->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color:white;\n"
"border: 1px solid #2D5059;\n"
"border-radius: 20px;\n"
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
"}"));

        verticalLayout->addWidget(butMergeAll);

        butRemoveSelected = new QPushButton(verticalLayoutWidget);
        butRemoveSelected->setObjectName(QString::fromUtf8("butRemoveSelected"));
        sizePolicy1.setHeightForWidth(butRemoveSelected->sizePolicy().hasHeightForWidth());
        butRemoveSelected->setSizePolicy(sizePolicy1);
        butRemoveSelected->setFont(font);
        butRemoveSelected->setFocusPolicy(Qt::NoFocus);
        butRemoveSelected->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color:white;\n"
"border: 1px solid #2D5059;\n"
"border-radius: 20px;\n"
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
"}"));

        verticalLayout->addWidget(butRemoveSelected);

        butRemoveAll = new QPushButton(verticalLayoutWidget);
        butRemoveAll->setObjectName(QString::fromUtf8("butRemoveAll"));
        sizePolicy1.setHeightForWidth(butRemoveAll->sizePolicy().hasHeightForWidth());
        butRemoveAll->setSizePolicy(sizePolicy1);
        butRemoveAll->setFont(font);
        butRemoveAll->setFocusPolicy(Qt::NoFocus);
        butRemoveAll->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color:white;\n"
"border: 1px solid #2D5059;\n"
"border-radius: 20px;\n"
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
"}"));

        verticalLayout->addWidget(butRemoveAll);

        butExit = new QPushButton(centralWidget);
        butExit->setObjectName(QString::fromUtf8("butExit"));
        butExit->setGeometry(QRect(720, 490, 61, 61));
        sizePolicy1.setHeightForWidth(butExit->sizePolicy().hasHeightForWidth());
        butExit->setSizePolicy(sizePolicy1);
        butExit->setFont(font);
        butExit->setFocusPolicy(Qt::NoFocus);
        butExit->setStyleSheet(QString::fromUtf8("QPushButton {border: 1px solid rgba(0,0,0,0); border-radius: 8px; background-color: rgba(0,0,0,0,);\n"
"	image: url(:/res/LH1-Standby-icon.png);\n"
"\n"
"}\n"
""));
        verticalWidget_2 = new QWidget(centralWidget);
        verticalWidget_2->setObjectName(QString::fromUtf8("verticalWidget_2"));
        verticalWidget_2->setGeometry(QRect(8, 490, 142, 61));
        verticalWidget_2->setStyleSheet(QString::fromUtf8(""));
        label_Amplitude = new QLabel(verticalWidget_2);
        label_Amplitude->setObjectName(QString::fromUtf8("label_Amplitude"));
        label_Amplitude->setGeometry(QRect(9, 9, 120, 17));
        sizePolicy1.setHeightForWidth(label_Amplitude->sizePolicy().hasHeightForWidth());
        label_Amplitude->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setFamily(QString::fromUtf8("DejaVu Sans"));
        font1.setBold(true);
        font1.setWeight(75);
        label_Amplitude->setFont(font1);
        label_Amplitude->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 0, 0, 0);"));
        label_Amplitude->setAlignment(Qt::AlignCenter);
        lineEdit = new QLineEdit(verticalWidget_2);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(9, 28, 124, 30));
        sizePolicy1.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy1);
        lineEdit->setStyleSheet(QString::fromUtf8(""));
        verticalWidget_3 = new QWidget(centralWidget);
        verticalWidget_3->setObjectName(QString::fromUtf8("verticalWidget_3"));
        verticalWidget_3->setGeometry(QRect(150, 490, 142, 61));
        label_Frequency = new QLabel(verticalWidget_3);
        label_Frequency->setObjectName(QString::fromUtf8("label_Frequency"));
        label_Frequency->setGeometry(QRect(9, 9, 120, 17));
        sizePolicy1.setHeightForWidth(label_Frequency->sizePolicy().hasHeightForWidth());
        label_Frequency->setSizePolicy(sizePolicy1);
        label_Frequency->setFont(font1);
        label_Frequency->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 0, 0, 0);"));
        label_Frequency->setAlignment(Qt::AlignCenter);
        lineEdit_2 = new QLineEdit(verticalWidget_3);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(9, 28, 124, 30));
        sizePolicy1.setHeightForWidth(lineEdit_2->sizePolicy().hasHeightForWidth());
        lineEdit_2->setSizePolicy(sizePolicy1);
        verticalWidget_4 = new QWidget(centralWidget);
        verticalWidget_4->setObjectName(QString::fromUtf8("verticalWidget_4"));
        verticalWidget_4->setGeometry(QRect(430, 490, 141, 61));
        label_Offset = new QLabel(verticalWidget_4);
        label_Offset->setObjectName(QString::fromUtf8("label_Offset"));
        label_Offset->setGeometry(QRect(9, 9, 120, 17));
        sizePolicy1.setHeightForWidth(label_Offset->sizePolicy().hasHeightForWidth());
        label_Offset->setSizePolicy(sizePolicy1);
        label_Offset->setFont(font1);
        label_Offset->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 0, 0, 0);"));
        label_Offset->setAlignment(Qt::AlignCenter);
        lineEdit_3 = new QLineEdit(verticalWidget_4);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(9, 28, 123, 30));
        sizePolicy1.setHeightForWidth(lineEdit_3->sizePolicy().hasHeightForWidth());
        lineEdit_3->setSizePolicy(sizePolicy1);
        verticalWidget_5 = new QWidget(centralWidget);
        verticalWidget_5->setObjectName(QString::fromUtf8("verticalWidget_5"));
        verticalWidget_5->setGeometry(QRect(290, 490, 141, 61));
        label_Phase = new QLabel(verticalWidget_5);
        label_Phase->setObjectName(QString::fromUtf8("label_Phase"));
        label_Phase->setGeometry(QRect(9, 9, 120, 17));
        sizePolicy1.setHeightForWidth(label_Phase->sizePolicy().hasHeightForWidth());
        label_Phase->setSizePolicy(sizePolicy1);
        label_Phase->setFont(font1);
        label_Phase->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 0, 0, 0);"));
        label_Phase->setAlignment(Qt::AlignCenter);
        lineEdit_4 = new QLineEdit(verticalWidget_5);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(9, 28, 123, 30));
        sizePolicy1.setHeightForWidth(lineEdit_4->sizePolicy().hasHeightForWidth());
        lineEdit_4->setSizePolicy(sizePolicy1);
        butZoomIn = new QPushButton(centralWidget);
        butZoomIn->setObjectName(QString::fromUtf8("butZoomIn"));
        butZoomIn->setGeometry(QRect(50, 4, 40, 40));
        sizePolicy1.setHeightForWidth(butZoomIn->sizePolicy().hasHeightForWidth());
        butZoomIn->setSizePolicy(sizePolicy1);
        butZoomIn->setFont(font);
        butZoomIn->setFocusPolicy(Qt::NoFocus);
        butZoomIn->setStyleSheet(QString::fromUtf8("QPushButton {border: 1px solid rgba(0,0,0,0); border-radius: 8px; background-color: rgba(0,0,0,0,);\n"
"\n"
"\n"
"image: url(:/res/Zoom-Out-icon.png);}\n"
""));
        butZoomOut = new QPushButton(centralWidget);
        butZoomOut->setObjectName(QString::fromUtf8("butZoomOut"));
        butZoomOut->setGeometry(QRect(90, 4, 40, 40));
        sizePolicy1.setHeightForWidth(butZoomOut->sizePolicy().hasHeightForWidth());
        butZoomOut->setSizePolicy(sizePolicy1);
        butZoomOut->setFont(font);
        butZoomOut->setFocusPolicy(Qt::NoFocus);
        butZoomOut->setStyleSheet(QString::fromUtf8("QPushButton {border: 1px solid rgba(0,0,0,0); border-radius: 8px; background-color: rgba(0,0,0,0,);\n"
"	image: url(:/res/Zoom-In-icon.png);\n"
"}\n"
""));
        butStop = new QPushButton(centralWidget);
        butStop->setObjectName(QString::fromUtf8("butStop"));
        butStop->setGeometry(QRect(650, 490, 61, 61));
        sizePolicy1.setHeightForWidth(butStop->sizePolicy().hasHeightForWidth());
        butStop->setSizePolicy(sizePolicy1);
        butStop->setFont(font);
        butStop->setFocusPolicy(Qt::NoFocus);
        butStop->setStyleSheet(QString::fromUtf8("QPushButton {border: 1px solid rgba(0,0,0,0); border-radius: 8px; background-color: rgba(0,0,0,0,);\n"
"\n"
"	image: url(:/res/LH1-Stop-icon.png);\n"
"}\n"
""));
        butStart = new QPushButton(centralWidget);
        butStart->setObjectName(QString::fromUtf8("butStart"));
        butStart->setGeometry(QRect(580, 490, 61, 61));
        sizePolicy1.setHeightForWidth(butStart->sizePolicy().hasHeightForWidth());
        butStart->setSizePolicy(sizePolicy1);
        butStart->setFont(font);
        butStart->setFocusPolicy(Qt::NoFocus);
        butStart->setStyleSheet(QString::fromUtf8("QPushButton {border: 1px solid rgba(0,0,0,0); border-radius: 8px; background-color: rgba(0,0,0,0,);\n"
"\n"
"image: url(:/res/LH1-Play-icon.png);}\n"
""));
        butRefresh = new QPushButton(centralWidget);
        butRefresh->setObjectName(QString::fromUtf8("butRefresh"));
        butRefresh->setGeometry(QRect(10, 4, 40, 40));
        sizePolicy1.setHeightForWidth(butRefresh->sizePolicy().hasHeightForWidth());
        butRefresh->setSizePolicy(sizePolicy1);
        butRefresh->setFont(font);
        butRefresh->setFocusPolicy(Qt::NoFocus);
        butRefresh->setStyleSheet(QString::fromUtf8("QPushButton {border: 1px solid rgba(0,0,0,0); border-radius: 8px; background-color: rgba(0,0,0,0,);\n"
"\n"
"	image: url(:/res/Refresh-icon.png);}"));
        butAppBck = new QPushButton(centralWidget);
        butAppBck->setObjectName(QString::fromUtf8("butAppBck"));
        butAppBck->setGeometry(QRect(660, 0, 40, 40));
        sizePolicy1.setHeightForWidth(butAppBck->sizePolicy().hasHeightForWidth());
        butAppBck->setSizePolicy(sizePolicy1);
        butAppBck->setFont(font);
        butAppBck->setFocusPolicy(Qt::NoFocus);
        butAppBck->setStyleSheet(QString::fromUtf8("QPushButton {border: 1px solid rgba(0,0,0,0); border-radius: 8px; background-color: rgba(0,0,0,0,);\n"
"\n"
"image: url(:/res/automatic-512.png);}\n"
""));
        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "QCustomPlot Interaction Example", 0, QApplication::UnicodeUTF8));
        actionSine->setText(QApplication::translate("MainWindow", "Sine", 0, QApplication::UnicodeUTF8));
        actionSquare->setText(QApplication::translate("MainWindow", "Square", 0, QApplication::UnicodeUTF8));
        actionTriangle->setText(QApplication::translate("MainWindow", "Triangle", 0, QApplication::UnicodeUTF8));
        actionSAwtooth->setText(QApplication::translate("MainWindow", "Sawtooth", 0, QApplication::UnicodeUTF8));
        actionPulse->setText(QApplication::translate("MainWindow", "Pulse", 0, QApplication::UnicodeUTF8));
        actionMerge_All->setText(QApplication::translate("MainWindow", "Merge All", 0, QApplication::UnicodeUTF8));
        actionRandom->setText(QApplication::translate("MainWindow", "Random", 0, QApplication::UnicodeUTF8));
        actionRemove_All->setText(QApplication::translate("MainWindow", "Remove All", 0, QApplication::UnicodeUTF8));
        actionRemove_Selected->setText(QApplication::translate("MainWindow", "Remove Selected", 0, QApplication::UnicodeUTF8));
        actionZoomin->setText(QApplication::translate("MainWindow", "Zoom In", 0, QApplication::UnicodeUTF8));
        actionZoom_Out->setText(QApplication::translate("MainWindow", "Zoom Out", 0, QApplication::UnicodeUTF8));
        butSine->setText(QApplication::translate("MainWindow", "Sine", 0, QApplication::UnicodeUTF8));
        butSquare->setText(QApplication::translate("MainWindow", "Square", 0, QApplication::UnicodeUTF8));
        butTriangle->setText(QApplication::translate("MainWindow", "Triangle", 0, QApplication::UnicodeUTF8));
        butSawtooth->setText(QApplication::translate("MainWindow", "Sawtooth", 0, QApplication::UnicodeUTF8));
        butPulse->setText(QApplication::translate("MainWindow", "Pulse", 0, QApplication::UnicodeUTF8));
        butRandom->setText(QApplication::translate("MainWindow", "Random", 0, QApplication::UnicodeUTF8));
        butMergeAll->setText(QApplication::translate("MainWindow", "Merge\n"
"All", 0, QApplication::UnicodeUTF8));
        butRemoveSelected->setText(QApplication::translate("MainWindow", "Remove\n"
"Selected", 0, QApplication::UnicodeUTF8));
        butRemoveAll->setText(QApplication::translate("MainWindow", "Remove\n"
"All", 0, QApplication::UnicodeUTF8));
        butExit->setText(QString());
        label_Amplitude->setText(QApplication::translate("MainWindow", "AMPLITUDE", 0, QApplication::UnicodeUTF8));
        label_Frequency->setText(QApplication::translate("MainWindow", "SAMPLES", 0, QApplication::UnicodeUTF8));
        label_Offset->setText(QApplication::translate("MainWindow", "OFFSET", 0, QApplication::UnicodeUTF8));
        label_Phase->setText(QApplication::translate("MainWindow", "CYCLES", 0, QApplication::UnicodeUTF8));
        butZoomIn->setText(QString());
        butZoomOut->setText(QString());
        butStop->setText(QString());
        butStart->setText(QString());
        butRefresh->setText(QString());
        butAppBck->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
