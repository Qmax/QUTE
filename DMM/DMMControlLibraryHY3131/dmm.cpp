/*
 * Library - DMM Control Library UI
 * Author  - Ravivarman R,QMax
 */

#include "dmm.h"
#include "ui_dmm.h"

struct Flags {
    unsigned char vFlag, iFlag, r2wFlag;
    unsigned char autoFlag;
    unsigned char dcFlag, acFlag;
    unsigned char diodeFlag, continuityFlag, nullFlag, buzzerFlag;
    unsigned char runFlag;
} Flag;

struct Display {
    double nullify, retval, retval2, retvalHY3131;
} display;

double nullit;

void customMessageHandler(QtMsgType type, const char *msg) {
    QString dt = QDateTime::currentDateTime().toString("dd/MM/yyyy hh:mm:ss");
    QString txt = QString("[%1] ").arg(dt);

    switch (type) {
    case QtDebugMsg:
        txt += QString("{Debug} \t\t %1").arg(msg);
        break;
    case QtWarningMsg:
        txt += QString("{Warning} \t %1").arg(msg);
        break;
    case QtCriticalMsg:
        txt += QString("{Critical} \t %1").arg(msg);
        break;
    case QtFatalMsg:
        txt += QString("{Fatal} \t\t %1").arg(msg);
        abort();
        break;
    }

    QFile outFile("DMMLogFile.log");

    if (outFile.size() > 1298368)
        outFile.open(QIODevice::WriteOnly);
    else
        outFile.open(QIODevice::WriteOnly | QIODevice::Append);

    QTextStream textStream(&outFile);
    outFile.close();
    textStream << txt << endl;

}

DMM::DMM(QWidget *parent) :
        QMainWindow(parent), ui(new Ui::DMM) {
    ui->setupUi(this);
    QPluginLoader hy3131Loader("libHY3131DMMLib.so", this);
    hy3131DMM = qobject_cast<IHY3131DMMLibInterface*> (hy3131Loader.instance());
    hy3131Calib = new HY3131Calibration();
    //BackPlaneInterfacePlugin
    QPluginLoader loader2("libBackPlaneInterface.so", this);
    IBackPlane = qobject_cast<IntefaceBackPlane*> (loader2.instance());
    IBackPlane->InitializeBpObject();

    QPluginLoader loader5("libGPIOEventInterface.so", this);
    IGPIOEvent = qobject_cast<PTGPIOEventInterface*> (loader5.instance());

    QPluginLoader loader6("libPTKeyEventInterfaces.so", this);
    IPTKeyEvent = qobject_cast<PTEventInterface*> (loader6.instance());

    QPluginLoader loader7("libQmaxPTInterface.so", this);
    IPTLibrary = qobject_cast<IQmaxPTLibrary*> (loader7.instance());
    QMsgBox = qobject_cast<IQmaxMessageBox*> (loader7.instance());

    QPluginLoader loader8("libPTGPIOPinInterface.so", this);
    IGPIOPin = qobject_cast<InterfaceGPIOPins*> (loader8.instance());

    QPluginLoader loaderGeneral("libHY3131CalibInterface.so", this);
    calib = qobject_cast<IHY3131CalibInterface*> (loaderGeneral.instance());

    m_nADCtimer = new QTimer(this);
    connect(m_nADCtimer, SIGNAL(timeout()), this, SLOT(onMeasure()));

    objDMMAcc = new DMMAccuracy();
    connect(this, SIGNAL(DMM2AccuCalc(double,QString)), objDMMAcc,
            SLOT(getData(double,QString)));

    QPluginLoader loaderDMMTESTJIG("libtestSPI.so", this);
    DMMTestjig = qobject_cast<DMMSPITestJigInterface*> (
    loaderDMMTESTJIG.instance());

//_______________________________________________________________________
    QPluginLoader testing("libDIGrapher.so", this);
    DMMGraph = qobject_cast<DIGrapherInterface*> (testing.instance());
    graphWidget = DMMGraph->getDIGraph();
    graphWidget->setParent(this);
    graphWidget->setVisible(false);
    DMMGraph->setGraphGeometry(0,425,713,178);
    DMMGraph->setZoomOutGraphGeometry(0,425,713,178);
    DMMGraph->setZoomInGraphGeometry(0,192,713,412);
    DMMGraph->setGraphCount(3);
    DMMGraph->setLegendVisible(false);
    DMMGraph->setupGraphWindow();

    xData.resize(110);yData.resize(110);yMaxData.resize(110);yMinData.resize(110);
    graphLoop=0;

//_______________________________________________________________________


    //~~~~~~~~Check for debug panel~~~~~~~~~~~~~~~~~~~~~~~~
    QStringList debugPanel;
    QFile textFile2("debugPanel.txt");
    if (textFile2.open(QIODevice::ReadOnly)) {
        QTextStream textStream(&textFile2);
        while (!textStream.atEnd()) {
            debugPanel.append(textStream.readLine());
            if (debugPanel.value(0) == "1")
                ToolBox(true);
            else
                ToolBox(false);
        }
    } else {
        ToolBox(false);
    }
    textFile2.close();
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    InitialiseValues();

    IPTKeyEvent->InvokeGPIOEvent(this, "/dev/input/event2", "pt_kpp",&m_nPTKeyCode);

    ui->label_3->setVisible(false);
    msgBoxLive = false;
    nullit = 0.0;

    ohms = QChar(0x2126);
    micro = QChar(0x00B5);

    ui->rangeFrame->setVisible(false);
    ui->frame_6->setVisible(false);
    ui->label_18->setVisible(false);

    ui->line->setVisible(false);
    ui->line_4->setVisible(false);
    ui->line_8->setVisible(false);
    ui->line_9->setVisible(false);

    ui->r4w->setVisible(false);
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    /*	QPluginLoader testing("libAppBckPsoc.so", this);
         test = qobject_cast<IPTAppBckPsocInterface*> (testing.instance());*/

    //	QTimer *timerb1 = new QTimer(this);
    //	connect(timerb1, SIGNAL(timeout()), this, SLOT(blink1()));
    //
    //	QTimer *timerb2 = new QTimer(this);
    //	connect(timerb2, SIGNAL(timeout()), this, SLOT(blink2()));

    dis = new DISPLAY(ui->displayPanel);
    dis->selectGeometry(150, 25);
    ui->lineEdit_3->setVisible(false);

    ui->calibrateDisplay->setChecked(false);

    //  qInstallMsgHandler(customMessageHandler);
}

void DMM::customEvent(QEvent *e) {
    //qDebug() << "DMM Custom Event";
    if (e->type() == ((QEvent::Type) 5678)) {
        doPTKeyFunction();
    }
    QEvent(e->type());
}
void DMM::doPTKeyFunction() {
    if (m_nPTKeyCode == 1) {
        ui->exit->animateClick(1);
    } else if (m_nPTKeyCode == 2) {
        ui->exit->animateClick(1);
    } else if (m_nPTKeyCode == 3) {
        ui->Null->animateClick(1);
    } else if (m_nPTKeyCode == 4) {
        ui->voltMeter->animateClick(1);
    } else if (m_nPTKeyCode == 5) {
        ui->ampMeter->animateClick(1);
    } else if (m_nPTKeyCode == 6) {
        ui->ohmMeter->animateClick(1);
    } else if (m_nPTKeyCode == 7) {
        ui->ohmMeter_2->animateClick(1);
    } else if (m_nPTKeyCode == 8) {
    } else if (m_nPTKeyCode == 9) {
    } else if (m_nPTKeyCode == 10) {
    } else if (m_nPTKeyCode == 11) {
        ui->rightArrow->animateClick(1);
    } else if (m_nPTKeyCode == 12) {
        ui->leftArrow->animateClick(1);
    } else if (m_nPTKeyCode == 13) {
        //    	clickedPRSCR();
    } else if (m_nPTKeyCode == 14) {
        //        if(toolboxFlag==true){
        //            toolboxFlag=false;
        //            ToolBox(toolboxFlag);
        //        }else{
        //            toolboxFlag=true;
        //            ToolBox(toolboxFlag);
        //        }
    } else if (m_nPTKeyCode == 15) {
    } else if (m_nPTKeyCode == 16) {
    } else if (m_nPTKeyCode == 17) {
    } else if (m_nPTKeyCode == 18) {
    } else if (m_nPTKeyCode == 19) {
    }
}
void DMM::ToolBox(bool flag) {
    ui->debugPanel->setVisible(flag);
    ui->frontPanel_DMM->setVisible(!flag);
    ui->calibrateDisplay->setVisible(flag);
    //	ui->HAADC_WIDGET->setVisible(flag);
    ui->pushButton->setVisible(flag);
    ui->pushButton_14->setVisible(flag);
    ui->pushButton_13->setVisible(flag);
    ui->pushButton_16->setVisible(flag);
    ui->pushButton_15->setVisible(flag);
    ui->haadcClose->setVisible(flag);

}
bool DMM::showMessageBox(bool ok, bool cancel, QString text, QString okText =
                         "Ok", QString calcelText = "Cancel") {
    msgBoxLive = true;
    msgBox = new QMessageBox(this);
    msgBox->setFont(QFont("DejaVu Sans", 15, 50, false));
    msgBox->setIcon(QMessageBox::Information);
    msgBox->setStyleSheet("color : white;background-color :rgb(88,88,87,255);");
    msgBox->setWindowIcon(QIcon(":/image.png"));
    msgBox->setText(text);
    if (ok == true) {
        connectButton = msgBox->addButton(okText, QMessageBox::YesRole);
        connectButton->setFont(QFont("DejaVu Sans", 20, 50, false));
    }
    if (cancel == true) {
        abortButton = msgBox->addButton(calcelText, QMessageBox::NoRole);
        abortButton->setFont(QFont("DejaVu Sans", 20, 50, false));
    }
    msgBox->exec();
    if (msgBox->clickedButton() == connectButton) {
        msgBoxLive = false;
        return true;
    }
    if (cancel == true)
        if (msgBox->clickedButton() == abortButton) {
        msgBoxLive = false;
        return false;
    }
    return true;
}

double DMM::digitsLimiter(double unlimitedValue) {
    return unlimitedValue;
    ui->lineEdit->setText(QString::number(unlimitedValue));
    QRegExp rx("[0-9]\\d{0,4}");
    ui->lineEdit->setValidator(new QRegExpValidator(rx, this));
    return ui->lineEdit->text().toDouble();
}
void DMM::clickedPRSCR() {
    Pix = QPixmap();
    Pix = QPixmap::grabWindow(this->winId());
    Pix.save("DMM.jpg");
    QClipboard *board = QApplication::clipboard();
    board->setPixmap(Pix);
    QWidget::showFullScreen();
}

//Value Mapping----------------------------------------------------
void DMM::InitialiseValues() {
    //set DC Voltage
    mapDCVoltage.insert(0, "50mV");
    mapDCVoltage.insert(1, "500mV");
    mapDCVoltage.insert(2, "5V");
    mapDCVoltage.insert(3, "50V");
    mapDCVoltage.insert(4, "500V");
    mapDCVoltage.insert(5, "1000V");
    //set AC Voltage
    mapACVoltage.insert(0, "50mV");
    mapACVoltage.insert(1, "500mV");
    mapACVoltage.insert(2, "5V");
    mapACVoltage.insert(3, "50V");
    mapACVoltage.insert(4, "500V");
    mapACVoltage.insert(5, "750V");
    // set Current
    mapCurrent.insert(0, "500uA");
    mapCurrent.insert(1, "5mA");
    mapCurrent.insert(2, "50mA");
    mapCurrent.insert(3, "500mA");
    mapCurrent.insert(4, "3A");
    // set Resistance
    mapResistance.insert(0, "50E");
    mapResistance.insert(1, "500E");
    mapResistance.insert(2, "5KE");
    mapResistance.insert(3, "50KE");
    mapResistance.insert(4, "500KE");
    mapResistance.insert(5, "5ME");
    mapResistance.insert(6, "50ME");

    nVoltagePrev = 4, nVoltageCur = 5, nVoltageNext = 5;
    n2WResistancePrev = 0, n2WResistanceCur = 0, n2WResistanceNext = 1;
    nCurrentPrev = 0, nCurrentCur = 0, nCurrentNext = 1;

    Flag.acFlag = 1;
    setHighlight(0);
    ui->Auto->setStyleSheet(
            "QPushButton {color:white;border: 1px solid #2D5059;border-radius: 20px;background-color: qlineargradient(x1: 0, y1: 1, x2: 1, y2: 0,stop: 0 #e59244, stop: 0.6 #ffa500 , stop:1 #FFFFFF);font:bold;}");
    buttonPressed(0);
    //Setting Auto mode as default
    buttonPressed(14);

    ui->label_6->setDisabled(true);
    ui->label_5->setDisabled(true);
    ui->label_4->setDisabled(true);

    //set default range
    ui->label->setText(mapACVoltage.value(nVoltageCur));
    QString str28 = "font-size:36pt;";
    QString str36 = "font-size:36pt;";
    ui->textEdit->setStyleSheet(str36);

    QFont font = QFont("Courier");
    font.setPointSize(18);
    font.setFixedPitch(true);
    ui->textEdit->setFont(font);

    display.retval = 0.0;
    display.retval2 = 0.0;
    display.retvalHY3131 = 0.0;

    ui->textEdit_6->setText("");

    calibedSlope = 1.0;
    calibedConstant = 0.0;
    ui->holdLabel->setVisible(false);
    ui->Diode->setVisible(false);
    ui->Continuity->setVisible(false);

    noOfSamples = 10;
    avg = 0;
    retval = 0.0;
    for (int i = 0; i < noOfSamples; i++)
        avgRetval[i] = 0.0;

    buttonPressed(9);

}
DMM::~DMM() {
    delete ui;
}

void DMM::changeEvent(QEvent *e) {
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
double DMM::convertToValues(QString input) {

    QString unit, value;
    double inValue;
    bool ok = true;

    int j = 0;

    for (int i = 0; i <= input.count(); i++) {
        if ((input[i] >= 'A' && input[i] <= 'Z') || (input[i] >= 'a'
                                                     && input[i] <= 'z') || (input[i] == QChar(0x2126)) || (input[i]
                                                                                                            == QChar(0x00B5))) {
            unit[j] = input[i];
            j++;
        }
    }
    for (int k = 0; k < (input.count() - unit.count()); k++)
        value[k] = input[k];

    inValue = value.toDouble(&ok);

    if (unit[0] == 'n') {
        return (inValue / 1000000000);
    } else if ((unit[0] == QChar(0x00B5)) || (unit[0] == 'u')) {
        return (inValue / 1000000);
    } else if (unit[0] == 'm') {
        return (inValue / 1000);
    } else if (unit[0] == 'K') {
        return (inValue * 1000);
    } else if (unit[0] == 'M') {
        return (inValue * 1000000);
    } else {
        return (inValue * 1);
    }
}

void DMM::onMeasure() {
//    movie->start();

    //***********************2Wire*************************************
    if (!hy3131DMM->busyFlag()) {
        if (Flag.r2wFlag == 1) {
            if (ui->label_5->text() == mapResistance.value(0)) {
                display.retvalHY3131 = hy3131DMM->Measure(R50E);
                display.retval = display.retvalHY3131;
                dis->setRange(50);
            } else if (ui->label_5->text() == mapResistance.value(1)) {
                display.retvalHY3131 = hy3131DMM->Measure(R500E);
                display.retval = display.retvalHY3131;
                dis->setRange(500);
            } else if (ui->label_5->text() == mapResistance.value(2)) {
                ////qDebug()<<"5K Range";
                display.retvalHY3131 = hy3131DMM->Measure(R5K);
                display.retval = display.retvalHY3131 * 1000;
                dis->setRange(5);
            } else if (ui->label_5->text() == mapResistance.value(3)) {
                display.retvalHY3131 = hy3131DMM->Measure(R50K);
                display.retval = display.retvalHY3131 * 1000;
                dis->setRange(50);
            } else if (ui->label_5->text() == mapResistance.value(4)) {
                display.retvalHY3131 = hy3131DMM->Measure(R500K);
                display.retval = display.retvalHY3131 * 1000;
                dis->setRange(500);
            } else if (ui->label_5->text() == mapResistance.value(5)) {
                display.retvalHY3131 = hy3131DMM->Measure(R5M);
                display.retval = display.retvalHY3131 * 1000000;
                dis->setRange(5);
            } else if (ui->label_5->text() == mapResistance.value(6)) {
                display.retvalHY3131 = hy3131DMM->Measure(R50M);
                display.retval = display.retvalHY3131 * 1000000;
                dis->setRange(50);
            }
            ////qDebug()<<"retvalHY3131:"<<display.retvalHY3131<<"display.retval:"<<display.retval;
        }
        //***********************Voltage*************************************
        if (Flag.vFlag == 1) {
            if (Flag.dcFlag == 1) {
                if (ui->label_5->text() == mapDCVoltage.value(0)) {
                    display.retvalHY3131 = hy3131DMM->Measure(DC50mV);
                    display.retval = display.retvalHY3131*1e-3;
                    dis->setRange(50);
                } else if (ui->label_5->text() == mapDCVoltage.value(1)) {
                    display.retvalHY3131 = hy3131DMM->Measure(DC500mV);
                    display.retval = display.retvalHY3131*1e-3;
                    dis->setRange(500);
                } else if (ui->label_5->text() == mapDCVoltage.value(2)) {
                    display.retvalHY3131 = hy3131DMM->Measure(DC5V);
                    display.retval = display.retvalHY3131 * 1000;
                    dis->setRange(5);
                } else if (ui->label_5->text() == mapDCVoltage.value(3)) {
                    display.retvalHY3131 = hy3131DMM->Measure(DC50V);
                    display.retval = display.retvalHY3131 * 1000;
                    dis->setRange(50);
                } else if (ui->label_5->text() == mapDCVoltage.value(4)) {
                    display.retvalHY3131 = hy3131DMM->Measure(DC500V);
                    display.retval = display.retvalHY3131 * 1000;
                    dis->setRange(500);
                } else if (ui->label_5->text() == mapDCVoltage.value(5)) {
                    display.retvalHY3131 = hy3131DMM->Measure(DC1000V);
                    display.retval = display.retvalHY3131 * 1000;
                    dis->setRange(1000);
                }
            } else if (Flag.acFlag == 1) {
                if (ui->label_5->text() == mapACVoltage.value(0)) {
                    display.retvalHY3131 = hy3131DMM->Measure(AC50mV);
                    display.retval = display.retvalHY3131*1e-3;
                    dis->setRange(50);
                } else if (ui->label_5->text() == mapACVoltage.value(1)) {
                    display.retvalHY3131 = hy3131DMM->Measure(AC500mV);
                    display.retval = display.retvalHY3131*1e-3;
                    dis->setRange(500);
                } else if (ui->label_5->text() == mapACVoltage.value(2)) {
                    display.retvalHY3131 = hy3131DMM->Measure(AC5V);
                    display.retval = display.retvalHY3131 * 1000;
                    dis->setRange(5);
                } else if (ui->label_5->text() == mapACVoltage.value(3)) {
                    display.retvalHY3131 = hy3131DMM->Measure(AC50V);
                    display.retval = display.retvalHY3131 * 1000;
                    dis->setRange(50);
                } else if (ui->label_5->text() == mapACVoltage.value(4)) {
                    display.retvalHY3131 = hy3131DMM->Measure(AC500V);
                    display.retval = display.retvalHY3131 * 1000;
                    dis->setRange(500);
                } else if (ui->label_5->text() == mapACVoltage.value(5)) {
                    display.retvalHY3131 = hy3131DMM->Measure(AC1000V);
                    display.retval = display.retvalHY3131 * 1000;
                    dis->setRange(1000);
                }
            }
        }
        //***********************Current*************************************
        if (Flag.iFlag == 1) {
            if (Flag.dcFlag == 1) {
                if (ui->label_5->text() == mapCurrent.value(0)) {
                    display.retvalHY3131 = hy3131DMM->Measure(DC500uA);
                    display.retval = display.retvalHY3131*1e-6;
                    dis->setRange(500);
                } else if (ui->label_5->text() == mapCurrent.value(1)) {
                    display.retvalHY3131 = hy3131DMM->Measure(DC5mA);
                    display.retval = display.retvalHY3131*1e-3;
                    dis->setRange(5);
                } else if (ui->label_5->text() == mapCurrent.value(2)) {
                    display.retvalHY3131 = hy3131DMM->Measure(DC50mA);
                    display.retval = display.retvalHY3131*1e-3;
                    dis->setRange(50);
                } else if (ui->label_5->text() == mapCurrent.value(3)) {
                    display.retvalHY3131 = hy3131DMM->Measure(DC500mA);
                    display.retval = display.retvalHY3131*1e-3;
                    dis->setRange(500);
                } else if (ui->label_5->text() == mapCurrent.value(4)) {
                    display.retvalHY3131 = hy3131DMM->Measure(DC3A);
                    display.retval = display.retvalHY3131;
                    dis->setRange(3);
                }
            } else if (Flag.acFlag == 1) {
                if (ui->label_5->text() == mapCurrent.value(0)) {
                    display.retvalHY3131 = hy3131DMM->Measure(AC500uA);
                    display.retval = display.retvalHY3131*1e-6;
                    dis->setRange(500);
                } else if (ui->label_5->text() == mapCurrent.value(1)) {
                    display.retvalHY3131 = hy3131DMM->Measure(AC5mA);
                    display.retval = display.retvalHY3131*1e-3;
                    dis->setRange(5);
                } else if (ui->label_5->text() == mapCurrent.value(2)) {
                    display.retvalHY3131 = hy3131DMM->Measure(AC50mA);
                    display.retval = display.retvalHY3131*1e-3;
                    dis->setRange(50);
                } else if (ui->label_5->text() == mapCurrent.value(3)) {
                    display.retvalHY3131 = hy3131DMM->Measure(AC500mA);
                    display.retval = display.retvalHY3131*1e-3;
                    dis->setRange(500);
                } else if (ui->label_5->text() == mapCurrent.value(4)) {
                    display.retvalHY3131 = hy3131DMM->Measure(AC3A);
                    display.retval = display.retvalHY3131;
                    dis->setRange(3);
                }
            }
        }
        //*******************Diode*************************************
        if (Flag.diodeFlag == 1) {
            display.retvalHY3131 = hy3131DMM->Measure(DIODE)*10;
            display.retval = display.retvalHY3131*1e-3;
            dis->setRange(1000);
        }
        //*******************Continuity***********************************
        if (Flag.continuityFlag == 1) {
            display.retvalHY3131 = hy3131DMM->Measure(CNTY);
            display.retval = display.retvalHY3131;
            dis->setRange(500);
            ui->label->setText(mapResistance.value(1));
            n2WResistanceCur=1;
        }
        if (Flag.buzzerFlag == 1) {
            if (n2WResistanceCur == 0 && display.retval < 1)
                Beep(true);
            else if (n2WResistanceCur == 1 && display.retval < 10)
                Beep(true);
            else if (n2WResistanceCur == 2 && display.retval < 100)
                Beep(true);
            else if (n2WResistanceCur == 3 && display.retval < 1000)
                Beep(true);
            else if (n2WResistanceCur == 4 && display.retval < 10000)
                Beep(true);
            else if (n2WResistanceCur == 5 && display.retval < 100000)
                Beep(true);
            else if (n2WResistanceCur == 6 && display.retval < 1000000)
                Beep(true);
            else
                Beep(false);
        }
        ui->displayInput->setText(QString::number(display.retval, 'f', 5));

        //		display.retval2 = display.retval;
        display.retval2 = display.retvalHY3131;

        display.retvalHY3131 = display.retval2 - nullit;

        if (ui->calibrateDisplay->isChecked()) {
            CalibrateDisplay(ui->label_5->text());
            //qDebug() << "Screen Calibration-Slope:" << calibedSlope
                    //<< "Constant:" << calibedConstant;
            double y, x, c, m;
            x = display.retvalHY3131;
            c = calibedConstant;
            m = calibedSlope;
            y = (x - c) / m;
            //qDebug() << "Actual:" << display.retval2 << "Calibrated:" << y;
            display.retvalHY3131 = y;
        }
        if (Flag.autoFlag == 1) {
            AutoRange();
        }


        if (display.retval >= 999999999) {
            dis->setValue("OL");
            if (Flag.continuityFlag == 1 || Flag.r2wFlag == 1)
                showSymbol(7);
        } else {

            //*******************Display*************************************
            //***********************Unit change***************************

            emit DMM2GCalib(display.retval2, ui->label_5->text());

            if (ui->label_5->text() == mapResistance.value(0)
                || ui->label_5->text() == mapResistance.value(1))
                showSymbol(7);
            else if (ui->label_5->text() == mapResistance.value(2)
                || ui->label_5->text() == mapResistance.value(3)
                || ui->label_5->text() == mapResistance.value(4))
                showSymbol(3);
            else if (ui->label_5->text() == mapResistance.value(5)
                || ui->label_5->text() == mapResistance.value(6))
                showSymbol(5);

            if (ui->label_5->text() == mapDCVoltage.value(0)
                || ui->label_5->text() == mapDCVoltage.value(1))
                ui->lineEdit_4->setText("mV");
            else if (ui->label_5->text() == mapDCVoltage.value(2)
                || ui->label_5->text() == mapDCVoltage.value(3)
                || ui->label_5->text() == mapDCVoltage.value(4)
                || ui->label_5->text() == mapDCVoltage.value(5))
                ui->lineEdit_4->setText("V");
            if (ui->label_5->text() == mapACVoltage.value(0)
                || ui->label_5->text() == mapACVoltage.value(1))
                ui->lineEdit_4->setText("mV");
            else if (ui->label_5->text() == mapACVoltage.value(2)
                || ui->label_5->text() == mapACVoltage.value(3)
                || ui->label_5->text() == mapACVoltage.value(4)
                || ui->label_5->text() == mapACVoltage.value(5))
                ui->lineEdit_4->setText("V");

            if (ui->label_5->text() == mapCurrent.value(0))
                ui->lineEdit_4->setText(micro + "A");
            else if (ui->label_5->text() == mapCurrent.value(1)
                || ui->label_5->text() == mapCurrent.value(2)
                || ui->label_5->text() == mapCurrent.value(3))
                ui->lineEdit_4->setText("mA");
            else if (ui->label_5->text() == mapCurrent.value(4))
                ui->lineEdit_4->setText("A");

            if (display.retval2 >= 0.0 && display.retval2 < 1.0) {
                if (Flag.diodeFlag == 1)
                    ui->lineEdit_4->setText(micro + "V");
                else if (Flag.continuityFlag == 1) {
                    showSymbol(7);
                }
            } else if (display.retval2 >= 1.0 && display.retval2 < 1000.0) {
                if (Flag.diodeFlag == 1)
                    ui->lineEdit_4->setText("mV");
                else if (Flag.continuityFlag == 1) {
                    showSymbol(7);
                }
            } else if (display.retval2 > 1000.0) {
                if (Flag.diodeFlag == 1)
                    ui->lineEdit_4->setText("V");
                else if (Flag.continuityFlag == 1) {
                    showSymbol(3);
                }
            } else if (display.retval2 > 1000000.0) {
                if (Flag.diodeFlag == 1)
                    ui->lineEdit_4->setText("V");
                else if (Flag.continuityFlag == 1) {
                    showSymbol(5);
                }
            } else if (display.retval2 > -1000.0 && display.retval2 < 0.0) {
                if (Flag.diodeFlag == 1)
                    ui->lineEdit_4->setText("mV");
                else if (Flag.continuityFlag == 1) {
                    showSymbol(7);
                }
            } else if (display.retval2 > -1000000.0 && display.retval2 <= -1000) {
                if (Flag.diodeFlag == 1)
                    ui->lineEdit_4->setText("V");
                else if (Flag.continuityFlag == 1) {
                    showSymbol(3);
                }
            } else if (display.retval2 <= -1000000.0) {
                if (Flag.diodeFlag == 1)
                    ui->lineEdit_4->setText("V");
                else if (Flag.continuityFlag == 1) {
                    showSymbol(5);
                }
            }

            //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
            if(Flag.diodeFlag==true){
            	dis->setValue(digitsLimiter(display.retvalHY3131));
            }
            else if((ui->label_5->text()==mapResistance.value(2)||ui->label_5->text()==mapResistance.value(5)||ui->label_5->text()==mapCurrent.value(1)||ui->label_5->text()==mapDCVoltage.value(2)||ui->label_5->text()==mapACVoltage.value(2))&&(digitsLimiter(display.retvalHY3131)>5.1)){
                dis->setValue("OL");
            }
            else if((ui->label_5->text()==mapResistance.value(0)||ui->label_5->text()==mapResistance.value(3)||ui->label_5->text()==mapResistance.value(6)||ui->label_5->text()==mapCurrent.value(2)||ui->label_5->text()==mapDCVoltage.value(0)||ui->label_5->text()==mapDCVoltage.value(3)||ui->label_5->text()==mapACVoltage.value(0)||ui->label_5->text()==mapACVoltage.value(3))&&(digitsLimiter(display.retvalHY3131)>51)){
                dis->setValue("OL");
            }
            else if((ui->label_5->text()==mapResistance.value(1)||ui->label_5->text()==mapResistance.value(4)||ui->label_5->text()==mapCurrent.value(0)||ui->label_5->text()==mapCurrent.value(3)||ui->label_5->text()==mapDCVoltage.value(1)||ui->label_5->text()==mapDCVoltage.value(4)||ui->label_5->text()==mapACVoltage.value(1)||ui->label_5->text()==mapACVoltage.value(4))&&(digitsLimiter(display.retvalHY3131)>510)){
                dis->setValue("OL");
            }
            else if((ui->label_5->text()==mapCurrent.value(4))&&(digitsLimiter(display.retvalHY3131)>3.1)){
                dis->setValue("OL");
            }
            else if((ui->label_5->text()==mapACVoltage.value(5))&&(digitsLimiter(display.retvalHY3131)>760)){
                dis->setValue("OL");
            }
            else if((ui->label_5->text()==mapDCVoltage.value(4))&&(digitsLimiter(display.retvalHY3131)>1100)){
                dis->setValue("OL");
            }
            else{
                dis->setValue(digitsLimiter(display.retvalHY3131));
            }
            emit DMM2AccuCalc(display.retvalHY3131, ui->label_5->text());
        }
        ////qDebug()<<"Display.retavl:"<<display.retval;
//        ADC values = IDMMLib->getAdcDatas();
//
//                 ui->adcRawData->setText(QString::number(values.Data, 10));
//                 ui->adcConvData->setText(QString::number(values.ConvertedData, 'f', 16));
    }	if(graphWidget->isVisible())
    		InsertGraphData(display.retval2);
 }
void DMM::configGraphData(){
	DMMGraph->setGraphRange("Time",0,99,ui->label->text()+" Range",0,convertToValues(ui->label->text()));
}
void DMM::InsertGraphData(double gData){
	qDebug()<<"~~~~ GrapLoop"<<graphLoop<<"~~~~ Range:"<<ui->label->text()<<"~~~~ Value:"<<gData<<"~~~~";

	if(graphLoop>=100){
		graphLoop=0;yMaxData[0]=0;yMinData[0]=55000000;
		for(int i=0;i<100;i++){
			xData[i]=0;
			yData[i]=yData[i+1];
		}
	}

	xData[graphLoop]=graphLoop;
	yData[graphLoop]=gData;

		if(gData>yMaxData[0]){
			for(int j=0;j<100;j++){
				yMaxData[j]=gData;
			}
		}
		if(gData<yMinData[0]){
			for(int k=0;k<100;k++){
				yMinData[k]=gData;
			}
		}

	graphLoop=graphLoop+1;

	DMMGraph->setGraphData(0,xData,yData);
	DMMGraph->setGraphData(1,xData,yMaxData);
	DMMGraph->setGraphData(2,xData,yMinData);
	DMMGraph->plotGraphWindow();

}
void DMM::CalibrateDisplay(QString value) {
    QString l_strFileName;
    l_strFileName = "DMMCalibration.xml";
    ////qDebug() << "Range:" << value;

    QString comp;
    if (Flag.r2wFlag == 1)
        comp = "R-2W";
    else if (Flag.vFlag == 1 && Flag.dcFlag == 1)
        comp = "V-DC";
    else if (Flag.iFlag == 1 && Flag.dcFlag == 1)
        comp = "I-DC";
    else if (Flag.vFlag == 1 && Flag.acFlag == 1)
        comp = "V-AC";
    else if (Flag.iFlag == 1 && Flag.acFlag == 1)
        comp = "I-AC";
    else if (Flag.continuityFlag == 1)
        comp = "R-2W";

    QString m_strTypeIndex;
    m_strTypeIndex = value;

    QFile *xmlFile = new QFile(l_strFileName);
    if (!xmlFile->open(QIODevice::ReadOnly | QIODevice::Text)) {
        //qDebug() << "file read error";
    }
    QXmlStreamReader xml(xmlFile);
    short int index = 0;
    while (!xml.atEnd() && !xml.hasError()) {
        QXmlStreamReader::TokenType token = xml.readNext();
        QXmlStreamAttributes attributes = xml.attributes();

        QString l_strValue = attributes.value("Value").toString();

        if (token == QXmlStreamReader::StartDocument) {
            continue;
        }

        if (xml.isStartElement()) {
            if (xml.name() == comp && l_strValue == m_strTypeIndex) {
                calibedSlope
                        = xml.attributes().value("Slope").toString().toDouble();
                calibedConstant
                        = xml.attributes().value("Constant").toString().toDouble();
                index++;
            }
        }

    }
    if (xml.hasError())
        //qDebug() << "xmlFile.xml Parse Error";
        xml.clear();
    xmlFile->close();

}
void DMM::Beep(bool state) {
//    qDebug()<<"Beep:"<<state;
    if (state == true) {
        //		IBackPlane->writeBackPlaneRegister(0x4, 0x32);
        //		IBackPlane->setBuzzerTone(1000, 1, 50);
        //		IBackPlane->setBuzzerVolume(20, 1, 50);
        hy3131DMM->buzzerState(true);
        showSymbol(1);
    } else if (state == false) {
        //		usleep(100);
        //		IBackPlane->writeBackPlaneRegister(0x0, 0x0E);
        //		usleep(100);
        //		IBackPlane->writeBackPlaneRegister(0x0, 0x08);
        hy3131DMM->buzzerState(false);
        showSymbol(0);
    }
}

void DMM::callMeasure(void) {
    if (!hy3131DMM->busyFlag()) {
        if (m_nADCtimer->isActive())
            m_nADCtimer->stop();
        //***********************2Wire*************************************
        if (Flag.r2wFlag == 1) {
            if (ui->label_5->text() == mapResistance.value(0)) {
                hy3131DMM->Configure(R50E);
            } else if (ui->label_5->text() == mapResistance.value(1)) {
                hy3131DMM->Configure(R500E);
            } else if (ui->label_5->text() == mapResistance.value(2)) {
                hy3131DMM->Configure(R5K);
            } else if (ui->label_5->text() == mapResistance.value(3)) {
                hy3131DMM->Configure(R50K);
            } else if (ui->label_5->text() == mapResistance.value(4)) {
                hy3131DMM->Configure(R500K);
            } else if (ui->label_5->text() == mapResistance.value(5)) {
                hy3131DMM->Configure(R5M);
            } else if (ui->label_5->text() == mapResistance.value(6)) {
                hy3131DMM->Configure(R50M);
            }
        }
        //***********************DC Voltage*************************************
        if (Flag.vFlag == 1 && Flag.dcFlag == 1) {
            if (ui->label_5->text() == mapDCVoltage.value(0))
                hy3131DMM->Configure(DC50mV);
            else if (ui->label_5->text() == mapDCVoltage.value(1))
                hy3131DMM->Configure(DC500mV);
            else if (ui->label_5->text() == mapDCVoltage.value(2))
                hy3131DMM->Configure(DC5V);
            else if (ui->label_5->text() == mapDCVoltage.value(3))
                hy3131DMM->Configure(DC50V);
            else if (ui->label_5->text() == mapDCVoltage.value(4))
                hy3131DMM->Configure(DC500V);
            else if (ui->label_5->text() == mapDCVoltage.value(5))
                hy3131DMM->Configure(DC1000V);
        }
        //***********************AC Voltage*************************************
        if (Flag.vFlag == 1 && Flag.acFlag == 1) {
            if (ui->label_5->text() == mapACVoltage.value(0))
                hy3131DMM->Configure(AC50mV);
            else if (ui->label_5->text() == mapACVoltage.value(1))
                hy3131DMM->Configure(AC500mV);
            else if (ui->label_5->text() == mapACVoltage.value(2))
                hy3131DMM->Configure(AC5V);
            else if (ui->label_5->text() == mapACVoltage.value(3))
                hy3131DMM->Configure(AC50V);
            else if (ui->label_5->text() == mapACVoltage.value(4))
                hy3131DMM->Configure(AC500V);
            else if (ui->label_5->text() == mapACVoltage.value(5))
                hy3131DMM->Configure(AC1000V);
        }
        //***********************Current*************************************
        if (Flag.iFlag == 1) {
            //qDebug() << "Inside Curent Measure";
            if (ui->label_5->text() == mapCurrent.value(0)) {
                if (Flag.acFlag == 1) {
                    hy3131DMM->Configure(AC500uA);
                } else if (Flag.dcFlag == 1) {
                    hy3131DMM->Configure(DC500uA);
                }
            } else if (ui->label_5->text() == mapCurrent.value(1)) {
                if (Flag.acFlag == 1) {
                    hy3131DMM->Configure(AC5mA);
                } else if (Flag.dcFlag == 1) {
                    hy3131DMM->Configure(DC5mA);
                }
            } else if (ui->label_5->text() == mapCurrent.value(2)) {
                if (Flag.acFlag == 1) {
                    hy3131DMM->Configure(AC50mA);
                } else if (Flag.dcFlag == 1) {
                    hy3131DMM->Configure(DC50mA);
                }
            } else if (ui->label_5->text() == mapCurrent.value(3)) {

                if (Flag.acFlag == 1) {
                    hy3131DMM->Configure(AC500mA);
                } else if (Flag.dcFlag == 1) {
                    hy3131DMM->Configure(DC500mA);
                }
            } else if (ui->label_5->text() == mapCurrent.value(4)) {

                if (Flag.acFlag == 1) {
                    hy3131DMM->Configure(AC3A);
                } else if (Flag.dcFlag == 1) {
                    hy3131DMM->Configure(DC3A);
                }
            }
            if (Flag.acFlag == 1) {
                setHighlight(2);
            } else if (Flag.dcFlag == 1) {
                setHighlight(3);
            }
        }
        //***********************Diode*************************************
        if (Flag.diodeFlag == 1) {
            hy3131DMM->Configure(DIODE);
        }
        //***********************Continuity*************************************
        if (Flag.continuityFlag == 1) {
//            if (ui->label_5->text() == mapResistance.value(1)) {
                hy3131DMM->Configure(CNTY);
//            }
        }
        //		usleep(10000);//commented on Apr 28 5PM
        if (Flag.runFlag == 1)
            m_nADCtimer->start(500);
    }
    if(graphWidget->isVisible())
    	configGraphData();
}
void DMM::case_v() {
    ////qDebug()<<"case V";


    if (Flag.acFlag == 1)
        ui->textEdit_5->setText("AC ~");

    //Value Mapping-----------------------------------------
    Flag.vFlag = 1;
    Flag.iFlag = Flag.r2wFlag = Flag.diodeFlag = Flag.continuityFlag
                                                 = Flag.buzzerFlag = 0;
    if (Flag.dcFlag == 1) {
        ui->label_6->setText(mapDCVoltage.value(nVoltagePrev));
        ui->label_5->setText(mapDCVoltage.value(nVoltageCur));
        ui->label_4->setText(mapDCVoltage.value(nVoltageNext));
        ui->label->setText(mapDCVoltage.value(nVoltageCur));
    }
    if (Flag.acFlag == 1) {
        ui->label_6->setText(mapACVoltage.value(nVoltagePrev));
        ui->label_5->setText(mapACVoltage.value(nVoltageCur));
        ui->label_4->setText(mapACVoltage.value(nVoltageNext));
        ui->label->setText(mapACVoltage.value(nVoltageCur));
    }

    //---------------------------------------------------------
    if (nVoltageCur > 0)
        ui->lineEdit_4->setText("V");
    else if (nVoltageCur == 0)
        ui->lineEdit_4->setText("mV");

}
void DMM::case_i() {
    //qDebug() << "case I";

    if (Flag.dcFlag != 1)
        ui->textEdit_5->setText("AC ~");

    //Value Mapping---------------------------------------------

    Flag.iFlag = 1;
    Flag.vFlag = Flag.r2wFlag = Flag.diodeFlag = Flag.continuityFlag
                                                 = Flag.buzzerFlag = 0;
    ;

    //setColor(1);
    ui->label_6->setText(mapCurrent.value(nCurrentPrev));
    ui->label_5->setText(mapCurrent.value(nCurrentCur));
    ui->label_4->setText(mapCurrent.value(nCurrentNext));
    ui->label->setText(mapCurrent.value(nCurrentCur));
    //------------------------------------------------------------

    if (nCurrentCur == 4)
        ui->lineEdit_4->setText("A");
    else if ((nCurrentCur == 3) || (nCurrentCur == 2) || (nCurrentCur == 1))
        ui->lineEdit_4->setText("mA");
    else if ((nCurrentCur == 0))
        ui->lineEdit_4->setText(micro + "A");
}
void DMM::case_ac() {
    //qDebug() << "case AC";
    if (Flag.vFlag == 1) {
        ui->label_6->setText(mapACVoltage.value(nVoltagePrev));
        ui->label_5->setText(mapACVoltage.value(nVoltageCur));
        ui->label_4->setText(mapACVoltage.value(nVoltageNext));
        ui->label->setText(mapACVoltage.value(nVoltageCur));
    }
    Flag.acFlag = 1;
    Flag.dcFlag = 0;
    Flag.diodeFlag = Flag.continuityFlag = Flag.buzzerFlag = 0;

    ui->textEdit_5->setText("AC ~");
}
void DMM::case_dc() {
    ////qDebug()<<"case DC";
    if (Flag.vFlag == 1) {
        ui->label_6->setText(mapDCVoltage.value(nVoltagePrev));
        ui->label_5->setText(mapDCVoltage.value(nVoltageCur));
        ui->label_4->setText(mapDCVoltage.value(nVoltageNext));
        ui->label->setText(mapDCVoltage.value(nVoltageCur));
    }
    Flag.dcFlag = 1;
    Flag.acFlag = 0;
    Flag.diodeFlag = Flag.continuityFlag = Flag.buzzerFlag = 0;

    ui->textEdit_5->setText("DC --");
}
void DMM::buttonPressed(int pPressed) {

    switch (pPressed) {
    case 0: {
            case_v();
            case_ac();
            callMeasure();
            break;
        }

    case 1: {
            case_v();
            case_dc();
            callMeasure();
            break;
        }

    case 2: {
            case_i();
            case_ac();
            callMeasure();
            break;
        }
    case 3: {
            case_i();
            case_dc();
            callMeasure();
            break;
        }
    case 4:
        if (Flag.nullFlag == 1) {
            Flag.nullFlag = 0;
            nullit = 0.0;
            ui->label_11->setText("");
        } else if (Flag.nullFlag == 0) {
            Flag.nullFlag = 1;
            nullit = display.retval2;
            //			nullit = display.retvalHY3131;
            ui->label_11->setText("NULL");
        }
        //qDebug() << "Null Value:" << nullit;
        //		display.retval2 = display.retval - nullit;
        display.retvalHY3131 = display.retvalHY3131 - nullit;

        if (Flag.diodeFlag == 1)
            ui->textEdit_5->setText("Diode");
        else if (Flag.continuityFlag == 1)
            ui->textEdit_5->setText("CNTY");

        break;

        case 5:
        ////qDebug()<<"case Continuity";
        Flag.continuityFlag = 1;
        Flag.buzzerFlag = 1;
        Flag.vFlag = Flag.iFlag = Flag.r2wFlag = Flag.dcFlag = Flag.acFlag = Flag.diodeFlag = Flag.autoFlag = 0;

        showSymbol(0);

        ui->textEdit_5->setText("CNTY");
        ui->label->setText(mapResistance.value(1));

        //Value Mapping--------------------------------------------
        ui->label_6->setText(mapResistance.value(0));
        ui->label_5->setText(mapResistance.value(0));
        ui->label_4->setText(mapResistance.value(1));
        ui->label->setText(mapResistance.value(0));
        //-----------------------------------------------------------

        if (n2WResistanceCur == 0) {
            showSymbol(7);

        } else if ((n2WResistanceCur > 0) && (n2WResistanceCur <= 3)) {
            showSymbol(3);

        } else if (n2WResistanceCur > 3) {
            showSymbol(7); //changed on 5/10/2013
        }
        callMeasure();
        break;

        case 6:
        ////qDebug() << "case Diode";
        Flag.diodeFlag = 1;
        Flag.vFlag = Flag.iFlag = Flag.r2wFlag = Flag.dcFlag = Flag.acFlag = Flag.continuityFlag = Flag.autoFlag = 0;
        Flag.buzzerFlag = 0;
        //setColor(1);
        buttonPressed(14);

        ui->textEdit_5->setText("Diode");
        ui->label->setText("");

        callMeasure();
        break;

        case 7: {
                ui->textEdit_5->setText("R");
                //Value Mapping--------------------------------------------
                Flag.r2wFlag = 1;
                Flag.vFlag = Flag.iFlag = Flag.dcFlag = Flag.acFlag = Flag.diodeFlag
                                                                      = Flag.continuityFlag = Flag.buzzerFlag = 0;

                //setColor(1);
                ui->label_6->setText(mapResistance.value(n2WResistancePrev));
                ui->label_5->setText(mapResistance.value(n2WResistanceCur));
                ui->label_4->setText(mapResistance.value(n2WResistanceNext));
                ui->label->setText(mapResistance.value(n2WResistanceCur));
                //-----------------------------------------------------------

                if (n2WResistanceCur == 0) {
                    showSymbol(7);
                } else if ((n2WResistanceCur > 0) && (n2WResistanceCur <= 3)) {
                    showSymbol(3);

                } else if (n2WResistanceCur > 3) {
                    showSymbol(5);

                }
                callMeasure();
                break;

            }
        case 8: {
            }
        case 9: {
                ////qDebug()<<"case Measure";
                if (Flag.diodeFlag == 1)
                    ui->textEdit_5->setText("Diode");
                else if (Flag.continuityFlag == 1)
                    ui->textEdit_5->setText("CNTY");
                callMeasure();
                m_nADCtimer->start(500);
//                movie = new QMovie(":/indicate1.gif");
//                //        	QSize size(150,20);
//                //            movie->setScaledSize(size);
//                movie->setSpeed(100);
//                ui->label_12->setMovie(movie);
                IGPIOPin->illuminateRunStopButton(0);

                Flag.runFlag = 1;

                break;
            }
        case 10: {
                ////qDebug()<<"case Stop";
                if (m_nADCtimer->isActive()) {
                    if (Flag.diodeFlag == 1)
                        ui->textEdit_5->setText("Diode");
                    else if (Flag.continuityFlag == 1)
                        ui->textEdit_5->setText("CNTY");
                    m_nADCtimer->stop();
//                    movie->stop();
//                    ui->label_12->clear();
                }
                IGPIOPin->illuminateRunStopButton(1);
                Beep(false);

                Flag.runFlag = 0;
                break;
            }
        case 11: {
                ////qDebug()<<"case Exit";
                //		if (!m_nADCtimer->isActive()) {
                DMM::destroy(true,true);
                IGPIOPin->illuminateRunStopButton(1);
                Beep(false);
                IBackPlane->closeObject();
                parentWidget()->close();
                //		} else {
                //			showMessageBox(true, false, "Stop the DMM and then Exit", "Ok");
                //			break;
                //		}
            }
        case 12: {
                ////qDebug()<<"case up";
                if (Flag.vFlag == 1) {
                    if (nVoltagePrev == nVoltageCur)
                        nVoltagePrev--;
                    if (nVoltagePrev < 4)
                        nVoltagePrev++;
                    else
                        nVoltagePrev = 4;
                    if (nVoltageCur < 5)
                        nVoltageCur++;
                    else
                        nVoltageCur = 5;
                    if (nVoltageNext < 5)
                        nVoltageNext++;
                    else
                        nVoltageNext = 5;

                    if (Flag.dcFlag == 1) {
                        ui->label_6->setText(mapDCVoltage.value(nVoltagePrev));
                        ui->label_5->setText(mapDCVoltage.value(nVoltageCur));
                        ui->label_4->setText(mapDCVoltage.value(nVoltageNext));
                        ui->label->setText(mapDCVoltage.value(nVoltageCur));
                    }
                    if (Flag.acFlag == 1) {
                        ui->label_6->setText(mapACVoltage.value(nVoltagePrev));
                        ui->label_5->setText(mapACVoltage.value(nVoltageCur));
                        ui->label_4->setText(mapACVoltage.value(nVoltageNext));
                        ui->label->setText(mapACVoltage.value(nVoltageCur));
                    }

                    if (nVoltageCur > 0)
                        ui->lineEdit_4->setText("V");
                    else if (nVoltageCur == 0)
                        ui->lineEdit_4->setText("mV");
                } else if (Flag.iFlag == 1) {

                    if (nCurrentPrev == nCurrentCur)
                        nCurrentPrev--;
                    if (nCurrentPrev < 3)
                        nCurrentPrev++;
                    else
                        nCurrentPrev = 3;
                    if (nCurrentCur < 4)
                        nCurrentCur++;
                    else
                        nCurrentCur = 4;
                    if (nCurrentNext < 4)
                        nCurrentNext++;
                    else
                        nCurrentNext = 4;

                    ui->label_6->setText(mapCurrent.value(nCurrentPrev));
                    ui->label_5->setText(mapCurrent.value(nCurrentCur));
                    ui->label_4->setText(mapCurrent.value(nCurrentNext));
                    ui->label->setText(mapCurrent.value(nCurrentCur));

                    if (nCurrentCur == 4)
                        ui->lineEdit_4->setText("A");
                    else if (nCurrentCur == 1 || nCurrentCur == 2 || nCurrentCur == 3)
                        ui->lineEdit_4->setText("mA");
                    else if (nCurrentCur == 0)
                        ui->lineEdit_4->setText(micro + "A");
                } else if (Flag.r2wFlag == 1) {

                    if (n2WResistancePrev == n2WResistanceCur)
                        n2WResistancePrev--;
                    if (n2WResistancePrev < 5)
                        n2WResistancePrev++;
                    else
                        n2WResistancePrev = 5;
                    if (n2WResistanceCur < 6)
                        n2WResistanceCur++;
                    else
                        n2WResistanceCur = 6;
                    if (n2WResistanceNext < 6)
                        n2WResistanceNext++;
                    else
                        n2WResistanceNext = 6;

                    ui->label_6->setText(mapResistance.value(n2WResistancePrev));
                    ui->label_5->setText(mapResistance.value(n2WResistanceCur));
                    ui->label_4->setText(mapResistance.value(n2WResistanceNext));
                    ui->label->setText(mapResistance.value(n2WResistanceCur));

                    if (n2WResistanceCur == 0) {
                        showSymbol(7);

                    } else if ((n2WResistanceCur > 0) && (n2WResistanceCur <= 3)) {
                        showSymbol(3);

                    } else if (n2WResistanceCur > 3) {
                        showSymbol(5);

                    }

                }
                callMeasure();
                break;
            }
        case 13: {
                ////qDebug()<<"case down";


                if (Flag.vFlag == 1) {

                    if (nVoltageCur == nVoltageNext)
                        nVoltageNext++;
                    if (nVoltagePrev > 0)
                        nVoltagePrev--;
                    else
                        nVoltagePrev = 0;
                    if (nVoltageCur > 0)
                        nVoltageCur--;
                    else
                        nVoltageCur = 0;
                    if (nVoltageNext > 1)
                        nVoltageNext--;
                    else
                        nVoltageNext = 1;

                    if (Flag.dcFlag == 1) {
                        ui->label_6->setText(mapDCVoltage.value(nVoltagePrev));
                        ui->label_5->setText(mapDCVoltage.value(nVoltageCur));
                        ui->label_4->setText(mapDCVoltage.value(nVoltageNext));
                        ui->label->setText(mapDCVoltage.value(nVoltageCur));
                    }
                    if (Flag.acFlag == 1) {
                        ui->label_6->setText(mapACVoltage.value(nVoltagePrev));
                        ui->label_5->setText(mapACVoltage.value(nVoltageCur));
                        ui->label_4->setText(mapACVoltage.value(nVoltageNext));
                        ui->label->setText(mapACVoltage.value(nVoltageCur));
                    }

                    if (nVoltageCur > 0)
                        ui->lineEdit_4->setText("V");
                    else if (nVoltageCur == 0)
                        ui->lineEdit_4->setText("mV");

                } else if (Flag.iFlag == 1) {

                    if (nCurrentCur == nCurrentNext)
                        nCurrentNext++;
                    if (nCurrentPrev > 0)
                        nCurrentPrev--;
                    else
                        nCurrentPrev = 0;
                    if (nCurrentCur > 0)
                        nCurrentCur--;
                    else
                        nCurrentCur = 0;
                    if (nCurrentNext > 1)
                        nCurrentNext--;
                    else
                        nCurrentNext = 1;

                    ui->label_6->setText(mapCurrent.value(nCurrentPrev));
                    ui->label_5->setText(mapCurrent.value(nCurrentCur));
                    ui->label_4->setText(mapCurrent.value(nCurrentNext));
                    ui->label->setText(mapCurrent.value(nCurrentCur));

                    if (nCurrentCur == 4)
                        ui->lineEdit_4->setText("A");
                    else if (nCurrentCur == 1 || nCurrentCur == 2 || nCurrentCur == 3)
                        ui->lineEdit_4->setText("mA");
                    else if (nCurrentCur == 0)
                        ui->lineEdit_4->setText(micro + "A");

                } else if (Flag.r2wFlag == 1) {

                    if (n2WResistanceCur == n2WResistanceNext)
                        n2WResistanceNext++;
                    if (n2WResistancePrev > 0)
                        n2WResistancePrev--;
                    else
                        n2WResistancePrev = 0;
                    if (n2WResistanceCur > 0)
                        n2WResistanceCur--;
                    else
                        n2WResistanceCur = 0;
                    if (n2WResistanceNext > 1)
                        n2WResistanceNext--;
                    else
                        n2WResistanceNext = 1;

                    ui->label_6->setText(mapResistance.value(n2WResistancePrev));
                    ui->label_5->setText(mapResistance.value(n2WResistanceCur));
                    ui->label_4->setText(mapResistance.value(n2WResistanceNext));
                    ui->label->setText(mapResistance.value(n2WResistanceCur));

                    if (n2WResistanceCur == 0) {
                        showSymbol(7);
                    } else if ((n2WResistanceCur > 0) && (n2WResistanceCur <= 3)) {
                        showSymbol(3);
                    } else if (n2WResistanceCur > 3) {
                        showSymbol(5);
                    }

                }
                callMeasure();
                break;
            }
        case 14: {
                ////qDebug()<<"case AUTO";
//                if (Flag.continuityFlag != 1) {
                    if (Flag.autoFlag == 1) {
                        if ((Flag.diodeFlag == 0) && (Flag.continuityFlag == 0)) {

                            ui->manual->setVisible(true);
                            ui->Auto->setVisible(false);

                            ui->label_7->setText("Manual");
                            Flag.autoFlag = 0;
                            //setColor(1);
                            ui->label_6->setDisabled(false);
                            ui->label_5->setDisabled(false);
                            ui->label_4->setDisabled(false);

                        }
                    } else if (Flag.autoFlag == 0) {

                        ui->manual->setVisible(false);
                        ui->Auto->setVisible(true);

                        ui->label_7->setText("Auto");
                        Flag.autoFlag = 1;
                        //setColor(1);
                        ui->label_6->setDisabled(true);
                        ui->label_5->setDisabled(true);
                        ui->label_4->setDisabled(true);

                    }
                    if (Flag.diodeFlag == 1)
                        ui->textEdit_5->setText("Diode");
                    else if (Flag.continuityFlag == 1)
                        ui->textEdit_5->setText("CNTY");
//                }
                break;
            }
        case 15:
            break;
        case 16:
            break;

        }
    if (Flag.diodeFlag == 1)
        ui->label_2->setVisible(false);
    else
        ui->label_2->setVisible(true);
    if (Flag.buzzerFlag == 0 || Flag.continuityFlag == 0)
        Beep(false);
}
void DMM::setHighlight(int fn) {
    QString	no ="QPushButton{color:white;border: 1px solid #2D5059;border-radius: 20px;background-color: qlineargradient(x1: 0, y1: 1, x2: 1, y2: 0,stop: 0 #1A74DB, stop: 0.6 #5293DE, stop:1 #FFFFFF);font:bold; }";
    QString	yes ="QPushButton {color:white;border: 1px solid #2D5059;border-radius: 20px;background-color: qlineargradient(x1: 0, y1: 1, x2: 1, y2: 0,stop: 0 #e59244, stop: 0.6 #ffa500 , stop:1 #FFFFFF);font:bold;}";
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    QString RedProbe ="border:1px solid black;border-radius:20px;image: url(:/new/prefix1/red)";
    QString BlackProbe ="border:1px solid black;border-radius:20px;image: url(:/new/prefix1/black.png)";

    QString Gray20 = "border:1px solid gray;border-radius:20px;";
    QString Gray15 = "border:1px solid gray;border-radius:15px;";
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    ui->iac->setStyleSheet(no);
    ui->idc->setStyleSheet(no);
    ui->vac->setStyleSheet(no);
    ui->vdc->setStyleSheet(no);
    ui->Continuity->setStyleSheet(no);
    ui->Diode->setStyleSheet(no);
    ui->r2w->setStyleSheet(no);
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    switch (fn) {
    case 0:
        ui->vac->setStyleSheet(yes);
        break;
    case 1:
        ui->vdc->setStyleSheet(yes);
        break;
    case 2:
        ui->iac->setStyleSheet(yes);
        break;
    case 3:
        ui->idc->setStyleSheet(yes);
        break;
    case 4:
        ui->Null->setStyleSheet(yes);
        break;
    case 5:
        ui->Continuity->setStyleSheet(yes);
        break;
    case 6:
        ui->Diode->setStyleSheet(yes);
        break;
    case 7:
        ui->r2w->setStyleSheet(yes);
        break;
    case 8:
        break;
    case 9:
        ui->hold->setStyleSheet(yes);
        break;
    case 10:
        ui->hold->setStyleSheet(yes);
        break;
    case 11:
        break;
    case 12:
        break;
    case 13:
        break;
    case 14:
        break;
    }
    {
        ui->fp_HI_inner->setVisible(true);
        ui->fp_HI_outer->setStyleSheet("border:1px solid gray;border-radius:20px;image: url(:/new/prefix1/Button-Blank-Gray-icon.png);");
        ui->fp_HI_outer->setGeometry(25,27,41,41);
        ui->fp_LO_inner->setVisible(true);
        ui->fp_LO_outer->setStyleSheet("border:1px solid gray;border-radius:20px;image: url(:/new/prefix1/Button-Blank-Gray-icon.png);");
        ui->fp_LO_outer->setGeometry(75,27,41,41);
        ui->fp_mA_inner->setVisible(true);
        ui->fp_mA_outer->setStyleSheet("border:1px solid gray;border-radius:20px;image: url(:/new/prefix1/Button-Blank-Gray-icon.png);");
        ui->fp_mA_outer->setGeometry(125,27,41,41);
        ui->fp_A_inner->setVisible(true);
        ui->fp_A_outer->setStyleSheet("border:1px solid gray;border-radius:20px;image: url(:/new/prefix1/Button-Blank-Gray-icon.png);");
        ui->fp_A_outer->setGeometry(235,27,41,41);

    }
    if (fn == 0 || fn == 1 || fn == 5 || fn == 6 || fn == 7) {
        ui->fp_HI_inner->setVisible(false);
        ui->fp_HI_outer->setStyleSheet("border:1px rgba(0,0,0,0);border-radius:20px;image: url(:/fp_images/red.png);");
        ui->fp_HI_outer->setGeometry(25,27,42,41);
        ui->fp_LO_inner->setVisible(false);
        ui->fp_LO_outer->setStyleSheet("border:1px rgba(0,0,0,0);border-radius:20px;image: url(:/fp_images/black.png);");
        ui->fp_LO_outer->setGeometry(74,23,46,50);

    } else if (fn == 2 || fn == 3) {
        if(ui->label_5->text()=="3A"){
            ui->fp_A_inner->setVisible(false);
            ui->fp_A_outer->setStyleSheet("border:1px rgba(0,0,0,0);border-radius:20px;image: url(:/fp_images/red.png);");
            ui->fp_A_outer->setGeometry(235,27,42,41);
        }else{
            ui->fp_mA_inner->setVisible(false);
            ui->fp_mA_outer->setStyleSheet("border:1px rgba(0,0,0,0);border-radius:20px;image: url(:/fp_images/red.png);");
            ui->fp_mA_outer->setGeometry(125,27,42,41);
        }
        ui->fp_LO_inner->setVisible(false);
        ui->fp_LO_outer->setStyleSheet("border:1px rgba(0,0,0,0);border-radius:20px;image: url(:/fp_images/black.png);");
        ui->fp_LO_outer->setGeometry(74,23,46,50);
    }
}

void DMM::showSymbol(unsigned char symbol) {
    if (symbol == 0) {
        ui->label_3->setVisible(false);
    } else if (symbol == 1) {
        ui->label_3->setVisible(true);
    } else if (symbol == 2) {

    } else if (symbol == 3) {
        units = "K" + ohms;
        ui->lineEdit_4->setText(units);
    } else if (symbol == 4) {

    } else if (symbol == 5) {
        units = "M" + ohms;
        ui->lineEdit_4->setText(units);
    } else if (symbol == 6) {

    } else if (symbol == 7) {
        units = ohms;
        ui->lineEdit_4->setText(units);
    } else if (symbol == 8) {
    }
}
void DMM::AutoRange() {
    //2 wire resistance auto range
    if (Flag.r2wFlag == 1) {
        if (display.retval >= 999999999) {
            buttonPressed(12);
            //qDebug() << "ADC Full Scale";
        } else {
            if ((display.retval >= 51.0 && n2WResistanceCur == 0)
                || (display.retval >= 510.0 && n2WResistanceCur == 1)
                || (display.retval >= 5100.0 && n2WResistanceCur == 2)
                || (display.retval >= 51000.0 && n2WResistanceCur == 3)
                || (display.retval >= 510000.0 && n2WResistanceCur == 4)
                || (display.retval >= 5100000.0 && n2WResistanceCur == 5))
                buttonPressed(12);
            else if ((display.retval < 4900000.0 && n2WResistanceCur == 6)
                || (display.retval < 490000.0 && n2WResistanceCur == 5)
                || (display.retval < 49000.0 && n2WResistanceCur == 4)
                || (display.retval < 4900.0 && n2WResistanceCur == 3)
                || (display.retval < 490.0 && n2WResistanceCur == 2)
                || (display.retval < 49.0 && n2WResistanceCur == 1))
                buttonPressed(13);
        }
    }

    //voltage auto range
    else if (Flag.vFlag == 1) {
        if (display.retval >= 999999999)
            buttonPressed(12);
        else {
            if (display.retval >= 0) {
                if (((display.retval > 51.0) && nVoltageCur == 0)
                    || ((display.retval >= 510.0) && nVoltageCur == 1)
                    || ((display.retval >= 5100.0) && nVoltageCur == 2)
                    || ((display.retval >= 51000.0) && nVoltageCur == 3)
                    || ((display.retval >= 510000.0) && nVoltageCur == 4))
                    buttonPressed(12);
                else if (((display.retval < 490000.0) && nVoltageCur == 5)
                    || ((display.retval < 49000.0) && nVoltageCur == 4)
                    || ((display.retval < 4900.0) && nVoltageCur == 3)
                    || ((display.retval < 490.0) && nVoltageCur == 2)
                    || ((display.retval < 49.0) && nVoltageCur == 1))
                    buttonPressed(13);
            }
            if (display.retval < 0) {
                if (((display.retval < -51.0) && nVoltageCur == 0)
                    || ((display.retval < -510.0) && nVoltageCur == 1)
                    || ((display.retval < -5100.0) && nVoltageCur == 2)
                    || ((display.retval < -51000.0) && nVoltageCur == 3)
                    || ((display.retval < -510000.0) && nVoltageCur == 4))
                    buttonPressed(12);
                else if (((display.retval >= -490000.0) && nVoltageCur == 5)
                    || ((display.retval >= -49000.0) && nVoltageCur == 4)
                    || ((display.retval >= -4900.0) && nVoltageCur == 3)
                    || ((display.retval >= -490.0) && nVoltageCur == 2)
                    || ((display.retval >= -49.0) && nVoltageCur == 1))
                    buttonPressed(13);
            }
        }
    }
    //current auto range
    else if (Flag.iFlag == 1) {
        if (display.retval >= 999999999)
            buttonPressed(12);
        else {
            if (display.retval >= 0) {
                if (((display.retval >= 510.0e-6) && nCurrentCur == 0) || ((display.retval >= 5.1e-3) && nCurrentCur == 1) || ((display.retval >= 51.0e-3) && nCurrentCur == 2) || ((display.retval >= 510.0e-3) && nCurrentCur == 3))
                    buttonPressed(12);
                else if (((display.retval < 490.0e-3) && nCurrentCur == 4) || ((display.retval < 49.0e-3) && nCurrentCur == 3) || ((display.retval < 4.9e-3) && nCurrentCur == 2) || ((display.retval < 490.0e-6) && nCurrentCur == 1))
                    buttonPressed(13);
            }
            if (display.retval < 0) {
                if (((display.retval < -500.0e-6) && nCurrentCur == 0) || ((display.retval < -5.1e-3) && nCurrentCur == 1) || ((display.retval < -51.0e-3) && nCurrentCur == 2) || ((display.retval < -510.0e-3) && nCurrentCur == 3))
                    buttonPressed(12);
                else if (((display.retval < -490.0e-3) && nCurrentCur == 4) || ((display.retval < -49.0e-3) && nCurrentCur == 3) || ((display.retval < -4.9e-3) && nCurrentCur == 2) || ((display.retval < -490.0e-6) && nCurrentCur == 1))
                    buttonPressed(13);
            }
        }
    }
    //continuity auto range
    else if (Flag.continuityFlag == 1) {
        if (display.retval >= 999999999)
            buttonPressed(12);
        else {
/*            if ((display.retval >= 51.0 && n2WResistanceCur == 0)
                || (display.retval >= 510.0 && n2WResistanceCur == 1)
                || (display.retval >= 5100.0 && n2WResistanceCur == 2)
                || (display.retval >= 51000.0 && n2WResistanceCur == 3)
                || (display.retval >= 510000.0 && n2WResistanceCur == 4)
                || (display.retval >= 5100000.0 && n2WResistanceCur == 5))
                buttonPressed(12);
            else if ((display.retval < 4900000.0 && n2WResistanceCur == 6)
                || (display.retval < 490000.0 && n2WResistanceCur == 5)
                || (display.retval < 49000.0 && n2WResistanceCur == 4)
                || (display.retval < 4900.0 && n2WResistanceCur == 3)
                || (display.retval < 490.0 && n2WResistanceCur == 2)
                || (display.retval < 49.0 && n2WResistanceCur == 1))
                buttonPressed(13);*/
        }
        if (Flag.buzzerFlag == 1) {
            if (n2WResistanceCur == 0 && display.retval < 1)
                Beep(true);

            else if (n2WResistanceCur == 1 && display.retval < 10)
                Beep(true);

            else if (n2WResistanceCur == 2 && display.retval < 100)
                Beep(true);

            else if (n2WResistanceCur == 3 && display.retval < 1000)
                Beep(true);

            else if (n2WResistanceCur == 4 && display.retval < 10000)
                Beep(true);

            else if (n2WResistanceCur == 5 && display.retval < 100000)
                Beep(true);

            else if (n2WResistanceCur == 6 && display.retval < 1000000)
                Beep(true);

            else
                Beep(false);

        }
    }

}

void DMM::closeEvent(QCloseEvent * event) {
    event->accept();

}

void DMM::on_Auto_clicked() {

    ui->manual->setStyleSheet(
            "QPushButton {color:white;border: 1px solid #2D5059;border-radius: 20px;background-color: qlineargradient(x1: 0, y1: 1, x2: 1, y2: 0,stop: 0 #e59244, stop: 0.6 #ffa500 , stop:1 #FFFFFF);font:bold;}");
    ui->rangeFrame->setVisible(true);
    ui->frame_6->setVisible(true);
    ui->label_18->setVisible(true);

    buttonPressed(14);
}
void DMM::on_manual_clicked() {
    ui->Auto->setStyleSheet(
            "QPushButton {color:white;border: 1px solid #2D5059;border-radius: 20px;background-color: qlineargradient(x1: 0, y1: 1, x2: 1, y2: 0,stop: 0 #e59244, stop: 0.6 #ffa500 , stop:1 #FFFFFF);font:bold;}");
    ui->rangeFrame->setVisible(false);
    ui->frame_6->setVisible(false);
    ui->label_18->setVisible(false);

    buttonPressed(14);
}
void DMM::on_hold_clicked() {
    if (Flag.runFlag == 1) {
        ui->holdLabel->setVisible(true);

        ui->hold->setStyleSheet(
                "QPushButton {color:white;border: 1px solid #2D5059;border-radius: 20px;background-color: qlineargradient(x1: 0, y1: 1, x2: 1, y2: 0,stop: 0 #e59244, stop: 0.6 #ffa500 , stop:1 #FFFFFF);font:bold;}");

        buttonPressed(10);
    } else {
        ui->holdLabel->setVisible(false);

        ui->hold->setStyleSheet(
                "QPushButton{color:white;border: 1px solid #2D5059;border-radius: 20px;background-color: qlineargradient(x1: 0, y1: 1, x2: 1, y2: 0,stop: 0 #1A74DB, stop: 0.6 #5293DE, stop:1 #FFFFFF);font:bold; }");

        buttonPressed(9);
    }
}

void DMM::on_vdc_clicked() {
    setHighlight(1);
    buttonPressed(1);
}

void DMM::on_vac_clicked() {
    setHighlight(0);
    buttonPressed(0);
}

void DMM::on_iac_clicked() {
    setHighlight(2);
    buttonPressed(2);
}

void DMM::on_idc_clicked() {
    setHighlight(3);
    buttonPressed(3);
}

void DMM::on_r2w_clicked() {
    setHighlight(7);
    buttonPressed(7);
}

void DMM::on_rightArrow_clicked() {
    buttonPressed(12);
}

void DMM::on_leftArrow_clicked() {
    buttonPressed(13);
}

void DMM::on_exit_clicked() {
    buttonPressed(11);
}

void DMM::on_voltMeter_clicked() {
    ui->vac->setVisible(true);
    ui->vdc->setVisible(true);
    ;
    ui->iac->setVisible(false);
    ui->idc->setVisible(false);
    ui->r2w->setVisible(false);
    ui->Diode->setVisible(false);
    ui->Continuity->setVisible(false);
    ui->selectFrame->setGeometry(701, 54, 10, 60);

    ui->voltBox->setStyleSheet(
            "QGroupBox{border:1px solid white; background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #3a5976, stop: 1 #000000);border-radius:10px;border-bottom:1px qlineargradient(x1: 0, y1: 0,stop: 0 #f6f7fa, stop: 1 #dadbde); border-bottom-right-radius: 0px;border-bottom-left-radius: 0px;}");
    ui->AmpBox->setStyleSheet(
            "QGroupBox{border:1px solid white; background-color: #dadbde;border-radius:10px;border-bottom:1px qlineargradient(x1: 0, y1: 0,stop: 0 #f6f7fa, stop: 1 #dadbde);border-bottom-right-radius: 0px; border-bottom-left-radius: 0px;border-top:1px solid gray; border-top-right-radius: 0px; border-top-left-radius: 0px;}");
    ui->OhmBox->setStyleSheet(
            "QGroupBox{border:1px solid white; background-color: #dadbde;border-radius:10px;border-top:1px qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #f6f7fa, stop: 1 #dadbde); border-top-right-radius: 0px; border-top-left-radius: 0px;border-top:1px solid gray;border-bottom-right-radius: 0px; border-bottom-left-radius: 0px;}");

    setHighlight(0);
    buttonPressed(0);

    graphLoop=100;
}

void DMM::on_ampMeter_clicked() {
    ui->vac->setVisible(false);
    ui->vdc->setVisible(false);
    ui->iac->setVisible(true);
    ui->idc->setVisible(true);
    ui->r2w->setVisible(false);
    ui->Diode->setVisible(false);
    ui->Continuity->setVisible(false);
    ui->selectFrame->setGeometry(701, 154, 10, 60);

    ui->voltBox->setStyleSheet(
            "QGroupBox{border:1px solid white; background-color: #dadbde;border-radius:10px;border-bottom:1px qlineargradient(x1: 0, y1: 0,stop: 0 #f6f7fa, stop: 1 #dadbde); border-bottom-right-radius: 0px;border-bottom-left-radius: 0px;}");
    ui->AmpBox->setStyleSheet(
            "QGroupBox{border:1px solid white; background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #3a5976, stop: 1 #000000);border-radius:10px;border-bottom:1px qlineargradient(x1: 0, y1: 0,stop: 0 #f6f7fa, stop: 1 #dadbde);border-bottom-right-radius: 0px; border-bottom-left-radius: 0px;border-top:1px solid gray; border-top-right-radius: 0px; border-top-left-radius: 0px;}");
    ui->OhmBox->setStyleSheet(
            "QGroupBox{border:1px solid white; background-color: #dadbde;border-radius:10px;border-top:1px qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #f6f7fa, stop: 1 #dadbde); border-top-right-radius: 0px; border-top-left-radius: 0px;border-top:1px solid gray;border-bottom-right-radius: 0px; border-bottom-left-radius: 0px;}");

    setHighlight(3);
    buttonPressed(3);

    graphLoop=100;
}

void DMM::on_ohmMeter_clicked() {
    ui->vac->setVisible(false);
    ui->vdc->setVisible(false);
    ;
    ui->iac->setVisible(false);
    ui->idc->setVisible(false);
    ui->r2w->setVisible(true);
    ui->Diode->setVisible(true);
    ui->Continuity->setVisible(true);
    ui->selectFrame->setGeometry(701, 254, 10, 60);

    ui->voltBox->setStyleSheet(
            "QGroupBox{border:1px solid white; background-color: #dadbde;border-radius:10px;border-bottom:1px qlineargradient(x1: 0, y1: 0,stop: 0 #f6f7fa, stop: 1 #dadbde); border-bottom-right-radius: 0px;border-bottom-left-radius: 0px;}");
    ui->AmpBox->setStyleSheet(
            "QGroupBox{border:1px solid white; background-color: #dadbde;border-radius:10px;border-bottom:1px qlineargradient(x1: 0, y1: 0,stop: 0 #f6f7fa, stop: 1 #dadbde);border-bottom-right-radius: 0px; border-bottom-left-radius: 0px;border-top:1px solid gray; border-top-right-radius: 0px; border-top-left-radius: 0px;}");
    ui->OhmBox->setStyleSheet(
            "QGroupBox{border:1px solid white; background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #3a5976, stop: 1 #000000);border-radius:10px;border-top:1px qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #f6f7fa, stop: 1 #dadbde); border-top-right-radius: 0px; border-top-left-radius: 0px;border-top:1px solid gray;border-bottom-right-radius: 0px; border-bottom-left-radius: 0px;}");

    setHighlight(7);
    buttonPressed(7);

    graphLoop=100;
}

void DMM::on_Null_clicked() {
    if (Flag.runFlag == 1) {
        if (Flag.nullFlag == 0)
            ui->Null->setStyleSheet(
                    "QPushButton {color:white;border: 1px solid #2D5059;border-radius: 20px;background-color: qlineargradient(x1: 0, y1: 1, x2: 1, y2: 0,stop: 0 #e59244, stop: 0.6 #ffa500 , stop:1 #FFFFFF);font:bold;}");
        else
            ui->Null->setStyleSheet(
                    "QPushButton{color:white;border: 1px solid #2D5059;border-radius: 20px;background-color: qlineargradient(x1: 0, y1: 1, x2: 1, y2: 0,stop: 0 #1A74DB, stop: 0.6 #5293DE, stop:1 #FFFFFF);font:bold; }");

        buttonPressed(4);
    }
}

void DMM::on_pushButton_clicked() {
    /*	QWidget *newWidget = test->getPTAppBckPsoc();
         newWidget->setWindowTitle("AppCard BackPanel PSoC Panel");
         newWidget->show();*/
}

void DMM::on_pushButton_14_clicked() {
    QWidget *newWidget = new QWidget(this);
    newWidget = calib->getCALIB();
    newWidget->setWindowTitle("General Calibration Panel");
    newWidget->show();
}

void DMM::on_pushButton_16_clicked() {
    //    hy3131DMM->on_ReadAll();
    QWidget *newWidget = DMMTestjig->getDMMSPI();
    newWidget->show();
}

void DMM::on_pushButton_13_clicked() {
    screenCalib = new DACCalibration(this);

    QPropertyAnimation *animation = new QPropertyAnimation(screenCalib,
                                                           "geometry");
    animation->setDuration(10000);
    animation->setStartValue(QRect(200, 350, 50, 50));
    animation->setEndValue(QRect(200, 150, 400, 341));
    animation->setEasingCurve(QEasingCurve::Linear);
    animation->setDuration(700);
    animation->start();
    screenCalib->show();
}

void DMM::on_haadcClose_clicked() {
}

void DMM::on_pushButton_15_clicked() {
    objDMMAcc->show();

}

void DMM::on_Continuity_clicked() {
    if (Flag.continuityFlag == 1) {
        setHighlight(7);			//RESISTANCE
        buttonPressed(7);
    } else {
        setHighlight(5);			//CONTINUITY
        buttonPressed(5);

        	Flag.autoFlag=true;
            ui->Auto->setStyleSheet(
                    "QPushButton {color:white;border: 1px solid #2D5059;border-radius: 20px;background-color: qlineargradient(x1: 0, y1: 1, x2: 1, y2: 0,stop: 0 #e59244, stop: 0.6 #ffa500 , stop:1 #FFFFFF);font:bold;}");
            ui->rangeFrame->setVisible(false);
            ui->frame_6->setVisible(false);
            ui->label_18->setVisible(false);
            ui->manual->setVisible(false);
            ui->Auto->setVisible(true);

    }
}

void DMM::on_Diode_clicked() {
    if (Flag.diodeFlag == 1) {
        setHighlight(7);			//RESISTANCE
        buttonPressed(7);
    } else {
        setHighlight(6);			//DIODE
        buttonPressed(6);

        	Flag.autoFlag=true;
            ui->Auto->setStyleSheet(
                    "QPushButton {color:white;border: 1px solid #2D5059;border-radius: 20px;background-color: qlineargradient(x1: 0, y1: 1, x2: 1, y2: 0,stop: 0 #e59244, stop: 0.6 #ffa500 , stop:1 #FFFFFF);font:bold;}");
            ui->rangeFrame->setVisible(false);
            ui->frame_6->setVisible(false);
            ui->label_18->setVisible(false);
            ui->manual->setVisible(false);
            ui->Auto->setVisible(true);

    }

}

void DMM::on_calibrateDisplay_clicked() {

}

void DMM::on_ohmMeter_2_clicked() {
    ui->selectFrame->setGeometry(701, 354, 10, 60);

    ui->voltBox->setStyleSheet(
            "QGroupBox{border:1px solid white; background-color: #dadbde;border-radius:10px;border-bottom:1px qlineargradient(x1: 0, y1: 0,stop: 0 #f6f7fa, stop: 1 #dadbde); border-bottom-right-radius: 0px;border-bottom-left-radius: 0px;}");
    ui->AmpBox->setStyleSheet(
            "QGroupBox{border:1px solid white; background-color: #dadbde;border-radius:10px;border-bottom:1px qlineargradient(x1: 0, y1: 0,stop: 0 #f6f7fa, stop: 1 #dadbde);border-bottom-right-radius: 0px; border-bottom-left-radius: 0px;border-top:1px solid gray; border-top-right-radius: 0px; border-top-left-radius: 0px;}");
    ui->OhmBox->setStyleSheet(
            "QGroupBox{border:1px solid white; background-color: #dadbde;border-radius:10px;border-bottom:1px qlineargradient(x1: 0, y1: 0,stop: 0 #f6f7fa, stop: 1 #dadbde);border-bottom-right-radius: 0px; border-bottom-left-radius: 0px;border-top:1px solid gray; border-top-right-radius: 0px; border-top-left-radius: 0px;}");
    ui->OhmBox_2->setStyleSheet(
            "QGroupBox{border:1px solid white; background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #3a5976, stop: 1 #000000);border-radius:10px;border-top:1px qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #f6f7fa, stop: 1 #dadbde); border-top-right-radius: 0px; border-top-left-radius: 0px;border-top:1px solid gray;border-bottom-right-radius: 0px; border-bottom-left-radius: 0px;}");

    //~~~~~~~~Check for debug panel~~~~~~~~~~~~~~~~~~~~~~~~
        QStringList debugPanel;
        QFile textFile2("debugPanel.txt");
        if (textFile2.open(QIODevice::ReadOnly)) {
            QTextStream textStream(&textFile2);
            while (!textStream.atEnd()) {
                debugPanel.append(textStream.readLine());
            }
        }
        textFile2.close();
   //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        if(graphWidget->isVisible())
        	graphWidget->setVisible(false);
        else{
        	graphWidget->setVisible(true);
        	graphLoop=0;
        }


}

void DMM::on_ohmMeter_3_clicked() {
    //    clickedPRSCR();
}

void DMM::on_pushButton_2_clicked() {
    unsigned short addr, data;
    addr = 0x29;
    data = 0x80;
    hy3131DMM->writeDMMSPI(addr, data);
    usleep(100);
    addr = 0x29;
    data = 0x84;
    hy3131DMM->writeDMMSPI(addr, data);
    usleep(100);
}
