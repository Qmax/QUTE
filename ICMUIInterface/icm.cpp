/*
 * icm.cpp
 *      Author: Ravivarman.R,Qmax
 */
#include "icm.h"
#include "ui_icm.h"

#define config_delay 500000

ICM::ICM(QWidget *parent) :
        QMainWindow(parent), ui(new Ui::ICM) {
    ui->setupUi(this);

    dis=new DISPLAY(ui->displayBox);
    dis->selectGeometry(150,30);
    initialiseHWLibraries();
    Intialize();
    initialiseFeedBackResistance();
    //	ui->calibrateDisplay->setChecked(true);
    msgBoxLive=false;
    ui->holdCap->setVisible(false);
    ui->R10E->setVisible(false);
    ui->ONOFF->animateClick(1);
    m_bRacRdc=true;
    //	IPsoc->switchFly();
    //	m_bExternal = true;
    IPsoc->icmMeasurement();
    m_bExternal = false;
    on_pushButton_clicked();//external selection

    ui->label_X->setVisible(false);
    ui->label_LC->setVisible(false);
    ui->value_XLXC->setVisible(false);

    //	loopOut = 0;//graphing
    ui->plottingWindow->setVisible(false);
    ui->graphPlotting->setVisible(false);
    ui->graphPlot->setVisible(false);
    //	m_nSweepStartFrequency=m_nSweepEndFrequency=m_nSweepStartFrequency2=m_nSweepEndFrequency2=0;
    //	m_nSweepStartFrequencyUnit=m_nSweepEndFrequencyUnit=m_nSweepIntervalUnit=1;
    //    graphSetup(ui->graphPlot);
    ui->label_RELCap->setVisible(false);
    ui->label_RELValue->setVisible(false);

    ui->AutoManual->setVisible(false);
    ui->label_24->setVisible(false);

    ui->ONOFF->setVisible(false);
    ui->label_25->setVisible(false);

    ui->settings->setVisible(false);
    ui->label_22->setVisible(false);

    ui->NULL_2->setVisible(false);
    ui->label_26->setVisible(false);

    ui->ResistanceRanges->setVisible(false);
    ui->CapacitanceRanges->setVisible(false);
    ui->Inductorranges->setVisible(false);
}
void ICM::slotAcceptUserLogin(QString& name,QString& password){
    if(name=="root" && password=="root"){
        m_nPassword=true;
    }else{
        QMessageBox msg;
        msg.setText("Login Error");
        msg.setInformativeText("Invalid Username/Password");
        msg.exec();
        m_nPassword=false;
        //        this->close();
    }

}
void ICM::checkProbeConnect() {
    //Check Probe~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    IPsoc->writeSerial(0x01);
    usleep(1000);
    if(m_bExternal==false){
        if((IPsoc->readSerial()&0x08)!=0x08)
            checkPrbStatus=showMessageBox(true,false,"Connect Internal Probe","OK","Cancel");
    }
    else if(m_bExternal==true)
        checkPrbStatus=showMessageBox(true,false,"Please Ensure External Probes are Connected","OK","Cancel");


    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
}
void ICM::ToolBox(bool hide) {
    ui->calibrateDisplay->setVisible(hide);
    ui->lblfrequency->setVisible(hide);
    ui->checkBox->setVisible(hide);
    ui->chkLoad->setVisible(hide);
    ui->pushButton_2->setVisible(hide);
    ui->label->setVisible(hide);
    ui->label_10->setVisible(hide);
    ui->label_11->setVisible(hide);
    ui->label_12->setVisible(hide);
    ui->label_13->setVisible(hide);
    ui->label_14->setVisible(hide);
    ui->label_15->setVisible(hide);
    ui->label_16->setVisible(hide);
    ui->label_17->setVisible(hide);
    ui->label_2->setVisible(hide);
    ui->label_9->setVisible(hide);
    ui->label_8->setVisible(hide);
    ui->label_7->setVisible(hide);
    ui->label_6->setVisible(hide);
    ui->label_3->setVisible(hide);
    ui->label_4->setVisible(hide);
    ui->label_5->setVisible(hide);
    leActual->setVisible(hide);
    leMeasured->setVisible(hide);
    ui->spinBox_2->setVisible(hide);
    ui->pushButton_3->setVisible(hide);
    ui->RacRdc->setVisible(hide);

}
/*void ICM::graphSetup(QCustomPlot *customPlot){
    customPlot->addGraph();
    QPen pen;
    int minRange, maxRange;

    pen.setColor(QColor(0, 0, 255, 200));
    customPlot->graph()->setLineStyle(QCPGraph::lsLine);
    customPlot->graph()->setPen(pen);

    customPlot->xAxis->setLabel("Time-->");
    QString str = m_strRLC;

    bool ok=true;
    QString str_yRangeMax;
    if(ui->rangeLabel->text().endsWith("pF")){
            customPlot->yAxis->setLabel(str+"(in pF)");
            str_yRangeMax=ui->rangeLabel->text();
            str_yRangeMax.chop(2);
            yRangeMax=str_yRangeMax.toInt(&ok,10);
    }else if(ui->rangeLabel->text().endsWith("nF")){
            customPlot->yAxis->setLabel(str+"(in nF)");
            str_yRangeMax=ui->rangeLabel->text();
            str_yRangeMax.chop(2);    	yRangeMax=str_yRangeMax.toInt(&ok,10);
    }else if(ui->rangeLabel->text().endsWith("uF")){
            customPlot->yAxis->setLabel(str+"(in uF)");
            str_yRangeMax=ui->rangeLabel->text();
            str_yRangeMax.chop(2);    	yRangeMax=str_yRangeMax.toInt(&ok,10);
    }else if(ui->rangeLabel->text().endsWith("uH")){
            customPlot->yAxis->setLabel(str+"(in uH)");
            str_yRangeMax=ui->rangeLabel->text();
            str_yRangeMax.chop(2);    	yRangeMax=str_yRangeMax.toInt(&ok,10);
    }else if(ui->rangeLabel->text().endsWith("mF")){
            customPlot->yAxis->setLabel(str+"(in mF)");
            str_yRangeMax=ui->rangeLabel->text();
            str_yRangeMax.chop(2);    	yRangeMax=str_yRangeMax.toInt(&ok,10);
    }else if(ui->rangeLabel->text().endsWith("mH")){
            customPlot->yAxis->setLabel(str+"(in mH)");
            str_yRangeMax=ui->rangeLabel->text();
            str_yRangeMax.chop(2);    	yRangeMax=str_yRangeMax.toInt(&ok,10);
    }else if(ui->rangeLabel->text().endsWith("KE")){
            customPlot->yAxis->setLabel(str+"(in KE)");
            str_yRangeMax=ui->rangeLabel->text();
            str_yRangeMax.chop(2);    	yRangeMax=str_yRangeMax.toInt(&ok,10);
    }else if(ui->rangeLabel->text().endsWith("ME")){
            customPlot->yAxis->setLabel(str+"(in ME)");
            str_yRangeMax=ui->rangeLabel->text();
            str_yRangeMax.chop(2);    	yRangeMax=str_yRangeMax.toInt(&ok,10);
    }else if(ui->rangeLabel->text().endsWith("E")){
            customPlot->yAxis->setLabel(str+"(in E)");
            str_yRangeMax=ui->rangeLabel->text();
            str_yRangeMax.chop(1);    	yRangeMax=str_yRangeMax.toInt(&ok,10);
    }else if(ui->rangeLabel->text().endsWith("H")){
            customPlot->yAxis->setLabel(str+"(in H)");
            str_yRangeMax=ui->rangeLabel->text();
            str_yRangeMax.chop(1);    	yRangeMax=str_yRangeMax.toInt(&ok,10);
    }

    // set axes ranges, so we see all data:

    customPlot->xAxis->setRange(-10, xSize*2);
    QString str2 = ui->rangeLabel->text();

    if (str2.endsWith("F") || str2.endsWith("H") || str2.endsWith("E"))
            str2.chop(1);
    if (str2.endsWith("m") || str2.endsWith("n") || str2.endsWith("K") || str2.endsWith("M") || str2.endsWith("u"))
            str2.chop(1);

    minRange = -50;
    maxRange = str2.toInt(&ok, 10);


    customPlot->yAxis->setRange(minRange, yRangeMax*2);
    //	customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    customPlot->setInteractions(QCP::iRangeZoom | QCP::iMultiSelect
                    | QCP::iSelectPlottables | QCP::iSelectAxes | QCP::iSelectLegend
                    | QCP::iSelectItems | QCP::iSelectOther);
}*/

/*void ICM::graphPlotter(QCustomPlot *customPlot){
    customPlot->graph(0)->setData(x, y);
    customPlot->graph(0)->rescaleAxes();
}*/

/*void ICM::setupSimpleDemo(QCustomPlot *customPlot) {
	customPlot->addGraph();
	QPen pen;
	int minRange, maxRange;

	pen.setColor(QColor(0, 0, 255, 200));
	customPlot->graph()->setLineStyle(QCPGraph::lsLine);
	customPlot->graph()->setPen(pen);

	customPlot->xAxis->setLabel("Frequency-->");
	QString str = m_strRLC;

	bool ok=true;
	QString str_yRangeMax;
	if(ui->rangeLabel->text().endsWith("pF")){
		customPlot->yAxis->setLabel(str+"(in pF)");
		str_yRangeMax=ui->rangeLabel->text();
		str_yRangeMax.chop(2);
		yRangeMax=str_yRangeMax.toInt(&ok,10);
	}else if(ui->rangeLabel->text().endsWith("nF")){
		customPlot->yAxis->setLabel(str+"(in nF)");
		str_yRangeMax=ui->rangeLabel->text();
		str_yRangeMax.chop(2);    	yRangeMax=str_yRangeMax.toInt(&ok,10);
	}else if(ui->rangeLabel->text().endsWith("uF")){
		customPlot->yAxis->setLabel(str+"(in uF)");
		str_yRangeMax=ui->rangeLabel->text();
		str_yRangeMax.chop(2);    	yRangeMax=str_yRangeMax.toInt(&ok,10);
	}else if(ui->rangeLabel->text().endsWith("uH")){
		customPlot->yAxis->setLabel(str+"(in uH)");
		str_yRangeMax=ui->rangeLabel->text();
		str_yRangeMax.chop(2);    	yRangeMax=str_yRangeMax.toInt(&ok,10);
	}else if(ui->rangeLabel->text().endsWith("mF")){
		customPlot->yAxis->setLabel(str+"(in mF)");
		str_yRangeMax=ui->rangeLabel->text();
		str_yRangeMax.chop(2);    	yRangeMax=str_yRangeMax.toInt(&ok,10);
	}else if(ui->rangeLabel->text().endsWith("mH")){
		customPlot->yAxis->setLabel(str+"(in mH)");
		str_yRangeMax=ui->rangeLabel->text();
		str_yRangeMax.chop(2);    	yRangeMax=str_yRangeMax.toInt(&ok,10);
	}else if(ui->rangeLabel->text().endsWith("KE")){
		customPlot->yAxis->setLabel(str+"(in KE)");
		str_yRangeMax=ui->rangeLabel->text();
		str_yRangeMax.chop(2);    	yRangeMax=str_yRangeMax.toInt(&ok,10);
	}else if(ui->rangeLabel->text().endsWith("ME")){
		customPlot->yAxis->setLabel(str+"(in ME)");
		str_yRangeMax=ui->rangeLabel->text();
		str_yRangeMax.chop(2);    	yRangeMax=str_yRangeMax.toInt(&ok,10);
	}else if(ui->rangeLabel->text().endsWith("E")){
		customPlot->yAxis->setLabel(str+"(in E)");
		str_yRangeMax=ui->rangeLabel->text();
		str_yRangeMax.chop(1);    	yRangeMax=str_yRangeMax.toInt(&ok,10);
	}else if(ui->rangeLabel->text().endsWith("H")){
		customPlot->yAxis->setLabel(str+"(in H)");
		str_yRangeMax=ui->rangeLabel->text();
		str_yRangeMax.chop(1);    	yRangeMax=str_yRangeMax.toInt(&ok,10);
	}

	// set axes ranges, so we see all data:

	customPlot->xAxis->setRange(-10, xSize*2);
	QString str2 = ui->rangeLabel->text();

	if (str2.endsWith("F") || str2.endsWith("H") || str2.endsWith("E"))
		str2.chop(1);
	if (str2.endsWith("m") || str2.endsWith("n") || str2.endsWith("K") || str2.endsWith("M") || str2.endsWith("u"))
		str2.chop(1);

	minRange = -50;
	maxRange = str2.toInt(&ok, 10);


	customPlot->yAxis->setRange(minRange, yRangeMax*2);
	//	customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
	customPlot->setInteractions(QCP::iRangeZoom | QCP::iMultiSelect
			| QCP::iSelectPlottables | QCP::iSelectAxes | QCP::iSelectLegend
			| QCP::iSelectItems | QCP::iSelectOther);
}*/
/*void ICM::plotSimpleDemo(QCustomPlot *customPlot) {
	QDateTime dateTime = QDateTime::currentDateTime();
    QString dateTimeString = dateTime.toString();

    //Save to File START ~~~~~~~~~~~~~~~~~~~~~~~
    QFile outFile("ICMGraph.log");
    if (outFile.size() > 1298368)
        outFile.open(QIODevice::WriteOnly | QIODevice::Text);
    else
        outFile.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append);
    QTextStream ts(&outFile);
	//Save to File END ~~~~~~~~~~~~~~~~~~~~~~~

	    if (loopOut != 250) {
        if (loopOut > 60) {
            customPlot->xAxis->setRange(loopOut - 60, loopOut);
        }

        x[loopOut] = loopOut;

        if (ui->ResistanceRanges->isVisible()) {
                y[loopOut] = m_nResistance;
            ts << QString("time") << "\t" << dateTimeString << "\t"
                      << m_strRLC << "\t"
                      << m_nResistance << endl;
        }else if(ui->Inductorranges->isVisible()){
                y[loopOut] = m_nInductance;
            ts << QString("time") << "\t" << dateTimeString << "\t"
                      << m_strRLC << "\t"
                      << m_nInductance << endl;
        }else if(ui->CapacitanceRanges->isVisible()){
                y[loopOut] = m_nCapacitance;
            ts << QString("time") << "\t" << dateTimeString << "\t"
                      << m_strRLC << "\t"
                      << m_nCapacitance << endl;
        }


        loopOut++;
    } else {
        for (int k = 0; k < 60; k++) {
            x[k] = x[190 + k];
            y[k] = y[190 + k];
        }

        loopOut = 59;
    }

	customPlot->graph(0)->setData(x, y);
	customPlot->graph(0)->rescaleAxes();

}*/

void ICM::GCalib2ICM(double value, QString comp) {
    //	if(comp=="ICM-R")
    //		m_nResistance=value;
    //	else if(comp=="ICM-L")
    //		m_nInductance=value;
    //	else if(comp=="ICM-C")
    //		m_nCapacitance=value;
}
void ICM::receiveValue(double pValue) {
    if (m_nLineEditIndex == 1) {
        Actual = pValue;
    }
    if (m_nLineEditIndex == 2) {
        Measured = pValue;
    }
}
void ICM::receiveValue(QString pValue) {
    if (m_nLineEditIndex == 1) {
        leActual->setText(pValue);
    }
    if (m_nLineEditIndex == 2) {
        leMeasured->setText(pValue);
    }
}
void ICM::receiveValue(unsigned int pValue) {
}
void ICM::callActualEdit() {
    if (leActual->hasFocus()) {
        openNumKBPanel(1, 1, 'A', 2000000000000, -2000000000000, this);
        m_nLineEditIndex = 1;
    }
}
void ICM::callMeasuredEdit() {
    if (leMeasured->hasFocus()) {
        openNumKBPanel(1, 1, 'A', 2000000000000, -2000000000000, this);
        m_nLineEditIndex = 2;
    }
}
void ICM::openNumKBPanel(short int pValue) {

    QWidget *w = INumberPanel->getNumKBPanel(pValue, this);
    w->setStyleSheet("border:1px solid rgba(0,0,0,0); color:black;");
    w->setWindowFlags(Qt::WindowCloseButtonHint | Qt::Dialog);
    w->show();
}
void ICM::openNumKBPanel(short int pValue, double incRatio, char type,double max, double min, QWidget* parent) {

    QWidget *w = INumberPanel->getNumKBPanelIncDec(pValue, incRatio, type, max,min, parent);
    w->setStyleSheet("border:1px solid rgba(0,0,0,0); color:black;");
    w->setWindowFlags(Qt::WindowCloseButtonHint | Qt::Dialog);
    w->show();
}

void ICM::initialiseHWLibraries() {

    loginDialog = new LoginDialog( this );
    connect(loginDialog,SIGNAL(acceptLogin(QString&,QString&,int&)),this,SLOT(slotAcceptUserLogin(QString&,QString&)));

    //_______________________________________________________________________
    QPluginLoader graphLoader("libDIGrapher.so", this);
    ICMGraph = qobject_cast<DIGrapherInterface*> (graphLoader.instance());
    graphWidget = ICMGraph->getDIGraph();
    graphWidget->setParent(this);
    graphWidget->setVisible(false);
    ICMGraph->setGraphGeometry(0,424,713,180);
    ICMGraph->setZoomOutGraphGeometry(0,424,713,180);
    ICMGraph->setZoomInGraphGeometry(0,192,713,412);
    ICMGraph->setGraphCount(3);
    ICMGraph->setLegendVisible(false);
    ICMGraph->setupGraphWindow();

    xData.resize(110);yData.resize(110);yMaxData.resize(110);yMinData.resize(110);
    graphLoop=0;

    //_______________________________________________________________________

    setWidget = new QWidget(this);
    setWidget->setGeometry(150,210,400,200);
    setWidget->setStyleSheet("QWidget{background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #3a5976, stop: 1 #000000); border: 2px solid white; border-radius: 5px;  margin-top: 1ex; /* leave space at the top for the title */}");
    setWidget->setVisible(false);

    QLabel *settLabel = new QLabel(setWidget);
    settLabel->setStyleSheet("QLabel{border:1px solid white;            border-radius:5px;         subcontrol-origin: margin;         subcontrol-position: top center; /* position at the top center */         padding: 0 3px;             color:white;         background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #3a5976, stop: 1 #000000);}");
    settLabel->setGeometry(156,7,90,30);
    settLabel->setFont(QFont("DejaVu Sans", 15, 50, false));
    settLabel->setText("SETTINGS");

    ui->ACDC->setParent(setWidget);
    ui->ACDC->setGeometry(210,40,55,55);

    QLabel *acDcLabel = new QLabel(setWidget);
    acDcLabel->setGeometry(200,90,90,50);
    acDcLabel->setStyleSheet("QLabel{border:0px solid white;            border-radius:0px;         subcontrol-origin: margin;         subcontrol-position: top center; /* position at the top center */               color:white;         background-color: rgba(0,0,0,0);}");
    acDcLabel->setFont(QFont("DejaVu Sans", 12, 50, false));
    acDcLabel->setText("Resistance\nStimulus");
    acDcLabel->setAlignment(Qt::AlignHCenter);

    //	ui->pushButton->setParent(setWidget);
    //	ui->pushButton->setGeometry(120,40,55,55);
    ui->pushButton->setVisible(false);

    QPushButton *advSet = new QPushButton(setWidget);
    advSet->setGeometry(30,40,65,65);
    advSet->setFocusPolicy(Qt::NoFocus);
    advSet->setStyleSheet("QPushButton { image: url(:/Symbols/settings.png); border: 2px solid rgba(0,0,0,0); border-radius: 25px; background-color: rgba(0,0,0,0); }");
    connect(advSet,SIGNAL(clicked()),this,SLOT(advSettings()));

    QLabel *advSetLabel = new QLabel(setWidget);
    advSetLabel->setGeometry(23,90,90,50);
    advSetLabel->setStyleSheet("QLabel{border:0px solid white;            border-radius:0px;         subcontrol-origin: margin;         subcontrol-position: top center; /* position at the top center */               color:white;         background-color: rgba(0,0,0,0);}");
    advSetLabel->setFont(QFont("DejaVu Sans", 12, 50, false));
    advSetLabel->setText("Advanced\nSettings");
    advSetLabel->setAlignment(Qt::AlignHCenter);

    QPushButton *shortProbe = new QPushButton(setWidget);
    shortProbe->setGeometry(120,40,55,55);
    shortProbe->setFocusPolicy(Qt::NoFocus);
    shortProbe->setStyleSheet("QPushButton { image: url(:/Symbols/short-icon.png); border: 2px solid rgba(0,0,0,0); border-radius: 25px; background-color: rgba(0,0,0,0); }");
    //	connect(shortProbe,SIGNAL(clicked()),this,SLOT(shortCalibration()));
    QLabel *shortProbeLabel = new QLabel(setWidget);
    shortProbeLabel->setGeometry(105,90,90,50);
    shortProbeLabel->setStyleSheet("QLabel{border:0px solid white;            border-radius:0px;         subcontrol-origin: margin;         subcontrol-position: top center; /* position at the top center */               color:white;         background-color: rgba(0,0,0,0);}");
    shortProbeLabel->setFont(QFont("DejaVu Sans", 12, 50, false));
    shortProbeLabel->setText("Short\nCalibration");
    shortProbeLabel->setAlignment(Qt::AlignHCenter);

    QPushButton *closeBut = new QPushButton(setWidget);
    closeBut->setGeometry(310,140,70,40);
    closeBut->setFocusPolicy(Qt::NoFocus);
    closeBut->setStyleSheet("QPushButton {       color:white;                border: 1px solid #2D5059;                border-radius: 20px;                background-color: qlineargradient(x1: 0, y1: 1, x2: 1, y2: 0,stop: 0 #1A74DB, stop: 0.6 #5293DE, stop:1 #FFFFFF);                font:bold;                }");
    closeBut->setText("CLOSE");
    connect(closeBut,SIGNAL(clicked()),setWidget,SLOT(hide()));
     //_____________________________________________________________________________________________________________________________________________________________________________

    QPluginLoader loader4("libQmaxPTInterface.so", this);
    ILineEdit = qobject_cast<IQmaxLineEdit*> (loader4.instance());
    INumberPanel = qobject_cast<IQmaxNumberPanel*> (loader4.instance());
    //	IPTMessageBox = qobject_cast<IQmaxMessageBox*> (loader4.instance());

    leActual = ILineEdit->QmaxLineEdit(1, ui->debugPanel);
    leActual->setGeometry(212, 120, 60, 25);
    leMeasured = ILineEdit->QmaxLineEdit(2, ui->debugPanel);
    leMeasured->setGeometry(343, 120, 60, 25);
    leMeasured->setStyleSheet(
            "border-width: 2px;border-style: outset;border-color: gray; 					    padding: 0 8px;     background: black;     selection-background-color: yellow;   color:white;     font: bold 14px;");
    leActual->setStyleSheet(
            "border-width: 2px;border-style: outset;border-color: gray; 						padding: 0 8px;     background: black;     selection-background-color: yellow;   color:white;     font: bold 14px;");

    connect(leActual, SIGNAL(focussed(bool)), this, SLOT(callActualEdit()));
    connect(leMeasured, SIGNAL(focussed(bool)), this, SLOT(callMeasuredEdit()));

    QPluginLoader loader3("libPTPsocInterface2.so", this);
    IPsoc = qobject_cast<IPSOCCOMMUNICATION*> (loader3.instance());
    IPsoc->openSerial();

    QPluginLoader loaderBck("libBackPlaneInterface.so", this);
    IBackPlane = qobject_cast<IntefaceBackPlane*> (loaderBck.instance());
    IBackPlane->InitializeBpObject();

    QPluginLoader loader5("libGPIOEventInterface.so", this);
    IGPIOEvent = qobject_cast<PTGPIOEventInterface*> (loader5.instance());

    QPluginLoader loader6("libPTKeyEventInterfaces.so", this);
    IPTKeyEvent = qobject_cast<PTEventInterface*> (loader6.instance());

    QPluginLoader loader8("libPTGPIOPinInterface.so", this);
    IGPIOPin = qobject_cast<InterfaceGPIOPins*> (loader8.instance());

    QPluginLoader loaderApp("libPTApplicationcardInterface.so", this);
    IAppCard = qobject_cast<IApplicationCardInterface*> (loaderApp.instance());
    IAppCard->setDeviceName(SLOT0);
    IAppCard->enumerateAPPCard();

    //	hwInterface=new HardwareInterface(IAppCard);
    IAppCard->setDDSWaveSelect(DDS);
    hwInterface = new HardwareInterface();
    hwInterface->Init();
    //	hwInterface->Configure();
    //	hwInterface->Update();
    hwInterface->setOffset(0);
    hwInterface->setPhase(0);
    IAppCard->setSPIAppendBit(0x8000);
    hwInterface->setAmplitude(0.15);
    hwInterface->SingleContinuous(CONTINUOUS);

    QPluginLoader loader2("libSPIMemoryInterface.so", this);
    ISPIMemory = qobject_cast<ISPIMemoryInterface*> (loader2.instance());
    ISPIMemory->setHardwarwObject(IAppCard);

    QPluginLoader loaderGeneral("libGCalib.so", this);
    GCALIB = qobject_cast<IGCALIBTestJigInterface*> (loaderGeneral.instance());


    QPluginLoader testing("libAppBckPsoc.so", this);
    test = qobject_cast<IPTAppBckPsocInterface*> (testing.instance());


    //        panelStatus.dPanel=panelStatus.fPanel=panelStatus.sPanel=panelStatus.gPanel=false;

    //~~~~~~~~Check for debug panel~~~~~~~~~~~~~~~~~~~~~~~~
    QStringList debugPanel;
    QFile textFile2("debugPanel.txt");
    if (textFile2.open(QIODevice::ReadOnly))
    {
        QTextStream textStream(&textFile2);
        while (!textStream.atEnd())
        {
            debugPanel.append(textStream.readLine());
            if(debugPanel.value(0)=="1"){
                panelStatus.dPanel=true;
            }
            else{
                panelStatus.dPanel=false;
            }
        }
    }
    textFile2.close();
    if(panelStatus.dPanel){
        ui->frontPanel_ICM->setVisible(false);
        ui->debugPanel->setVisible(true);
    }
    else{
        ui->frontPanel_ICM->setVisible(true);
        ui->debugPanel->setVisible(false);
    }
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    IAppCard->setSPIAppendBit(0xC000);
    m_objAD7190Component = new AD7190Component(IAppCard);
    m_objAD7190Component->resetADC(1);
    m_objAD7190Component->writeADCConfigurationRegister(1, 0x110);
    m_objAD7190Component->writeADCModeRegister(1, 0x80060);

    m_objAD7190Component->resetADC(2);
    m_objAD7190Component->writeADCConfigurationRegister(2, 0x110);
    m_objAD7190Component->writeADCModeRegister(2, 0x80060);

    IAppCard->writeRegister(0x02, 0x36);
    IAppCard->writeRegister(0x06, 0x38);
    IAppCard->writeRegister(0x1, 0x16);
    IPsoc->srcImpedanceSelection(SRC_IMP_0E);//added for 0E selection
    ui->label_Rs->setText("0"+ohms);
    IAppCard->writeRegister(0x7, 0x34);
    IAppCard->writeRegister(0, 0x3A);

    IAppCard->writeRegister(0x0063,PT_APPCARD_MODULES::PT_DRIVE_APPCARD_BTUR);
    IAppCard->writeRegister(0x0009,	PT_APPCARD_MODULES::PT_DRIVE_APPCARD_BDR);
    IAppCard->writeRegister(0x0001,	PT_APPCARD_MODULES::PT_DRIVE_APPCARD_DPR);
    IAppCard->writeRegister(0x0000, 0x1C);
    IAppCard->writeRegister(0x0100, 0x1A);

    ADCtimer = new QTimer(this);
    connect(ADCtimer, SIGNAL(timeout()), this, SLOT(readADC()));

    _100pF = _1nF = _10nF = _100nF = _1uF = _10uF = _100uF = _1mF = _10mF = 0;

    for (int i = 0; i < 10; i++)
        capSamples[i] = 0.0;
    capInc = 0;
    m_bNull = false;
    //	m_bExternal = false;

    cbdR=0.0;cbdL=0.0;cbdC=0.0;
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    IBackPlane->writeBackPlaneRegister(0x0FFF, 0x001E);//clear all interrupts
    IBackPlane->writeBackPlaneRegister(0x0000, 0x0020);//disable all interrupts
    IBackPlane->writeBackPlaneRegister(0x0000, 0x0024);//disable global interrupt
    IBackPlane->writeBackPlaneRegister(0x0100, 0x0020);//enabling psoc INT0embedded key interrupt)

    IPTKeyEvent->InvokeGPIOEvent(this, "/dev/input/event2", "pt_kpp",
                                 &m_nPTKeyCode);
    IGPIOEvent->InvokeGPIOEvent(this, "/dev/input/event7", "gpioevent",
                                &m_nGPIOCode);

    IBackPlane->writeBackPlaneRegister(0x0001, 0x0024);

}
void ICM::configGraphData(){
    QString str=ui->rangeLabel->text();
    if(str.endsWith("H")||str.endsWith("E")||str.endsWith("F"))
        str.chop(1);
    if(str.endsWith("p")||str.endsWith("n")||str.endsWith("u")||str.endsWith("m")||str.endsWith("K")||str.endsWith("M"))
        str.chop(1);
    bool ok=true;
    double rang=str.toDouble(&ok);
    ICMGraph->setGraphRange("Time",0,99,ui->rangeLabel->text()+" Range",0,rang);
}
void ICM::InsertGraphData(double gData){
    qDebug()<<"~~~~ GrapLoop"<<graphLoop<<"~~~~ Range:"<<ui->rangeLabel->text()<<"~~~~ Value:"<<gData<<"~~~~";

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

    ICMGraph->setGraphData(0,xData,yData);
    ICMGraph->setGraphData(1,xData,yMaxData);
    ICMGraph->setGraphData(2,xData,yMinData);
    ICMGraph->plotGraphWindow();

}
void ICM::KnobFunction() {

}
void ICM::changeByKnob(double Angle, double totalSteps) {

}
void ICM::ProbeFunction() {
    unsigned int l_nRegisterValue = 0, reads;
    IBackPlane->readBackPlaneRegister(0x001E);
    qDebug() << "data read at 1E" << l_nRegisterValue;
    IBackPlane->writeBackPlaneRegister(0x0100, 0x001E);
    IPsoc->writeSerial(0x01);
    usleep(1000);
    reads = IPsoc->readSerial();
    qDebug() << "Embedded Probe reads:" << hex << reads;
    changeByProbe(reads);
    IBackPlane->writeBackPlaneRegister(0x0001, 0x0024);
}
void ICM::changeByProbe(unsigned int key) {
    if (key == 0x90 || key == 0x98) {
        on_ONOFF_clicked();

    } else if (key == 0xA0 || key == 0xA8) {
        //		if(ui->R->isChecked())
        //			ui->L->setChecked(true);
        //		else if(ui->L->isChecked())
        //			ui->C->setChecked(true);
        //		else
        //			ui->R->setChecked(true);


    } else if (key == 0xC0 || key == 0xC8) {
        ui->AutoManual->click();
        on_AutoManual_clicked();
    }
}

bool ICM::showMessageBox(bool ok, bool cancel, QString text, QString okText ="Ok", QString calcelText = "Cancel") {
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
        //qDebug()<<"abort button clicked";
        msgBoxLive = false;
        return false;
    }
    return true;
}

void ICM::KeyFunction() {
    if (m_nPTKeyCode == 1) {
        qDebug() << ("\nMENU");
        if(msgBoxLive!=true){
            on_Exit_clicked();

        }
    } else if (m_nPTKeyCode == 2) {
        qDebug() << ("\nESC");
        if(msgBoxLive!=true){
            on_Exit_clicked();
        }
    } else if (m_nPTKeyCode == 3) {
        qDebug() << ("\nNULL");
        if(msgBoxLive!=true){
            ui->NULL_2->animateClick(1);
        }
    } else if (m_nPTKeyCode == 4) {
        qDebug() << ("\nF1");
        if(msgBoxLive!=true){
            //		ui->R->setChecked(true);
            on_R_clicked();
        }
    } else if (m_nPTKeyCode == 5) {
        qDebug() << ("\nF2");
        if(msgBoxLive!=true){
            //		ui->L->setChecked(true);
            on_L_clicked();
        }
    } else if (m_nPTKeyCode == 6) {
        qDebug() << ("\nF3");
        if(msgBoxLive!=true){
            //		ui->C->setChecked(true);
            on_C_clicked();
        }
    } else if (m_nPTKeyCode == 7) {
        qDebug() << ("\nF4");
        if(msgBoxLive!=true){

        }
    } else if (m_nPTKeyCode == 8) {
        qDebug() << ("\nF5");
        if(msgBoxLive!=true){

        }
    } else if (m_nPTKeyCode == 9) {
        qDebug() << ("\nUP");
        if(msgBoxLive!=true){
            if(rFlag==true){
                if(ui->R10KE->isChecked())
                    ui->R10E->setChecked(true);
                else if(ui->R100KE->isChecked())
                    ui->R100E->setChecked(true);
                else if(ui->R1ME->isChecked())
                    ui->R1KE->setChecked(true);
            }else if(lFlag==true){
                if(ui->L300mH->isChecked())
                    ui->L30uH->setChecked(true);
                else if(ui->L3H->isChecked())
                    ui->L300uH->setChecked(true);
                else if(ui->L30H->isChecked())
                    ui->L3mH->setChecked(true);
            }else if((cFlag==true)){
                if(ui->C10uF->isChecked())
                    ui->C100pF->setChecked(true);
                else if(ui->C100uF->isChecked())
                    ui->C1nF->setChecked(true);
                else if(ui->C1mF->isChecked())
                    ui->C10nF->setChecked(true);
                else if(ui->C10mF->isChecked())
                    ui->C100nF->setChecked(true);
            }
        }

    } else if (m_nPTKeyCode == 10) {
        qDebug() << ("\nDOWN");
        if(msgBoxLive!=true){
            if(rFlag==true){
                if(ui->R10E->isChecked())
                    ui->R10KE->setChecked(true);
                else if(ui->R100E->isChecked())
                    ui->R100KE->setChecked(true);
                else if(ui->R1KE->isChecked())
                    ui->R1ME->setChecked(true);
            }else if(lFlag==true){
                if(ui->L30uH->isChecked())
                    ui->L300mH->setChecked(true);
                else if(ui->L300uH->isChecked())
                    ui->L3H->setChecked(true);
                else if(ui->L3mH->isChecked())
                    ui->L30H->setChecked(true);
            }else if(cFlag==true){
                if(ui->C100pF->isChecked())
                    ui->C10uF->setChecked(true);
                else if(ui->C1nF->isChecked())
                    ui->C100uF->setChecked(true);
                else if(ui->C10nF->isChecked())
                    ui->C1mF->setChecked(true);
                else if(ui->C100nF->isChecked())
                    ui->C10mF->setChecked(true);
            }
        }
    } else if (m_nPTKeyCode == 11) {
        qDebug() << ("\nRIGHT");
        if(msgBoxLive){
            if(connectButton/*IPTMessageBox->GetConnectButton()*/->hasFocus())
                abortButton/*IPTMessageBox->GetAbortButton()*/->setFocus();
            else
                connectButton/*IPTMessageBox->GetConnectButton()*/->setFocus();
        }
        else{
            if(rFlag==true){
                if(ui->R10E->isChecked())
                    ui->R100E->setChecked(true);
                else if(ui->R100E->isChecked())
                    ui->R1KE->setChecked(true);
                else if(ui->R1KE->isChecked())
                    ui->R10KE->setChecked(true);
                else if(ui->R10KE->isChecked())
                    ui->R100KE->setChecked(true);
                else if(ui->R100KE->isChecked())
                    ui->R1ME->setChecked(true);
            }else if(lFlag==true){
                if(ui->L30uH->isChecked())
                    ui->L300uH->setChecked(true);
                else if(ui->L300uH->isChecked())
                    ui->L3mH->setChecked(true);
                else if(ui->L3mH->isChecked())
                    ui->L30mH->setChecked(true);
                else if(ui->L30mH->isChecked())
                    ui->L300mH->setChecked(true);
                else if(ui->L300mH->isChecked())
                    ui->L3H->setChecked(true);
                else if(ui->L3H->isChecked())
                    ui->L30H->setChecked(true);
            }else if(cFlag==true){
                if(ui->C100pF->isChecked())
                    ui->C1nF->setChecked(true);
                else if(ui->C1nF->isChecked())
                    ui->C10nF->setChecked(true);
                else if(ui->C10nF->isChecked())
                    ui->C100nF->setChecked(true);
                else if(ui->C100nF->isChecked())
                    ui->C1uF->setChecked(true);
                else if(ui->C1uF->isChecked())
                    ui->C10uF->setChecked(true);
                else if(ui->C10uF->isChecked())
                    ui->C100uF->setChecked(true);
                else if(ui->C100uF->isChecked())
                    ui->C1mF->setChecked(true);
                else if(ui->C1mF->isChecked())
                    ui->C10mF->setChecked(true);
            }
        }

    } else if (m_nPTKeyCode == 12) {
        qDebug() << ("\nLEFT");
        if(msgBoxLive){
            if(connectButton/*IPTMessageBox->GetConnectButton()*/->hasFocus())
                abortButton/*IPTMessageBox->GetAbortButton()*/->setFocus();
            else
                connectButton/*IPTMessageBox->GetConnectButton()*/->setFocus();
        }else{
            if(rFlag==true){
                if(ui->R1ME->isChecked())
                    ui->R100KE->setChecked(true);
                else if(ui->R100KE->isChecked())
                    ui->R10KE->setChecked(true);
                else if(ui->R10KE->isChecked())
                    ui->R1KE->setChecked(true);
                else if(ui->R1KE->isChecked())
                    ui->R100E->setChecked(true);
                else if(ui->R100E->isChecked())
                    ui->R10E->setChecked(true);
            }else if(lFlag==true){
                if(ui->L30H->isChecked())
                    ui->L3H->setChecked(true);
                else if(ui->L3H->isChecked())
                    ui->L300mH->setChecked(true);
                else if(ui->L300mH->isChecked())
                    ui->L30mH->setChecked(true);
                else if(ui->L30mH->isChecked())
                    ui->L3mH->setChecked(true);
                else if(ui->L3mH->isChecked())
                    ui->L300uH->setChecked(true);
                else if(ui->L300uH->isChecked())
                    ui->L30uH->setChecked(true);
            }else if(cFlag==true){
                if(ui->C10mF->isChecked())
                    ui->C1mF->setChecked(true);
                else if(ui->C1mF->isChecked())
                    ui->C100uF->setChecked(true);
                else if(ui->C100uF->isChecked())
                    ui->C10uF->setChecked(true);
                else if(ui->C10uF->isChecked())
                    ui->C1uF->setChecked(true);
                else if(ui->C1uF->isChecked())
                    ui->C100nF->setChecked(true);
                else if(ui->C100nF->isChecked())
                    ui->C10nF->setChecked(true);
                else if(ui->C10nF->isChecked())
                    ui->C1nF->setChecked(true);
                else if(ui->C1nF->isChecked())
                    ui->C100pF->setChecked(true);
            }
        }

    } else if (m_nPTKeyCode == 13) {
        qDebug() << ("\nENTER");
        if(msgBoxLive){
            if(connectButton/*IPTMessageBox->GetConnectButton()*/->hasFocus())
                connectButton/*IPTMessageBox->GetConnectButton()*/->animateClick(1);
            else
                abortButton/*IPTMessageBox->GetAbortButton()*/->animateClick(1);
        }else{

        }

    } else if (m_nPTKeyCode == 14) {
        qDebug() << ("\nSETUP");
        //		if(ui->frontPanel->isVisible())
        //			ui->frontPanel->setVisible(false);
        //		else
        //			ui->frontPanel->setVisible(true);

    } else if (m_nPTKeyCode == 15) {
        qDebug() << ("\nDEFAULT");

    } else if (m_nPTKeyCode == 16) {
        qDebug() << ("\nTOUCH");
        IGPIOPin->toggleTouchButton();
    } else if (m_nPTKeyCode == 17) {
        qDebug() << ("\nFILE");
        on_printImage_clicked();
    } else if (m_nPTKeyCode == 18) {
        qDebug() << ("\nSCALE");
    } else if (m_nPTKeyCode == 19) {
        qDebug() << ("\nRUN/STOP");
        if(msgBoxLive!=true)
            on_ONOFF_clicked();

    }
}
void ICM::customEvent(QEvent *e) {
    qDebug()<<"ICMM Custom Event";
    if (e->type() == ((QEvent::Type) 1234)) {
        qDebug() << "Embedded Probe";
        ProbeFunction();
    }
    if (e->type() == ((QEvent::Type) 5678)) {
        qDebug() << "PT Keypad";
        KeyFunction();
    }
    if (e->type() == ((QEvent::Type) 3456)) {
        qDebug() << "Magnetic Knob";
        KnobFunction();
    }

    QEvent(e->type());
}

void ICM::callFrequencyChange(double value) {

    m_nFrequency = value;

}
void ICM::callOffsetChange(double value) {
    m_dOffset = value;
    //qDebug()<<"Offset Received :"<<m_dOffset;
}
void ICM::callSrcImpChange(QString str){
    ui->label_Rs->setText(str);
}

void ICM::callFeedBackChange(int index) {

    //qDebug()<<"feedback resistance index:"<<index;

    if (rFlag==true)
        m_lstRFResistance.insert(R_Index, m_lstRFResistance.value(index));

    if (lFlag==true)
        m_lstRFInductance.insert(L_Index, m_lstRFResistance.value(index));

    if (cFlag==true)
        m_lstRFCapcitance.insert(C_Index, m_lstRFResistance.value(index));

}
void    ICM::readADC(){
    //	if(checkPrbStatus==false)
    //		checkProbeConnect();

    //    showMessageBox(true,false,QDateTime::currentDateTime().toString());
    //	if(ui->ResistanceRanges->isVisible()){
    if(rFlag==true){
        if( autoFlag == true && scanFlag == true )
            AutoRangeR3();//Auto
        else{//Manual
            m_nResistance = readADCR(ui->rangeLabel->text())/*-rShortValues[R_Index]*/;
            DisplayR();
            usleep(config_delay);
            usleep(config_delay);
        }
        ui->lblfrequency->setText(QString::number(m_nFrequency, 'f', 0));
        if(autoFlag==true){
            m_nResistance = readADCR(ui->rangeLabel->text())/*-rShortValues[R_Index]*/;
            DisplayR();

            if((m_nRange==30 && m_nResistance>0.5)){
                qDebug()<<"30E Break";
                scanFlag=true;
            }
            else if((m_nRange==300 && m_nResistance<1)||(m_nRange==300 && m_nResistance>110)){
                qDebug()<<"300E Break";
                scanFlag=true;
            }
            else if((m_nRange==3000 && m_nResistance<110)||(m_nRange==3000 && m_nResistance>1100)){
                qDebug()<<"3KE Break";
                scanFlag=true;
            }
            else if((m_nRange==30000)){// && m_nResistance<900)||(m_nRange==30000 && m_nResistance>10000)){
                qDebug()<<"30KE Break";
                scanFlag=true;
            }
            else if((m_nRange==300000 && m_nResistance<10000)||(m_nRange==300000 && m_nResistance>330000)){
                qDebug()<<"300KE Break";
                scanFlag=true;
            }
            else if((m_nRange==1000000 && m_nResistance<330000)||(m_nRange==1000000 && m_nResistance>1100000)){
                qDebug()<<"1ME Break";
                scanFlag=true;
            }else
                scanFlag=false;
        }
    }
    //	if(ui->Inductorranges->isVisible()){
    if(lFlag==true){
        readADC2();
    }
    //	if(ui->CapacitanceRanges->isVisible()){
    if(cFlag==true){
        //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        /*            if( (C_Index == 3 )&& (m_nCapacitance < 0.000000012) && (autoFlag ==true)){

                on_C10nF_clicked();
                ui->C10nF->animateClick(1);

                usleep(5000);

                double c5nFValue = readADCC("10nF");
                if(c5nFValue > 0.00000001){
                    on_C100nF_clicked();
                    ui->C100nF->animateClick(1);
                }
                else{
                    on_C100pF_clicked();
                    ui->C100pF->animateClick(1);
                }

            }*/
        //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        readADC2();
    }
    if(panelStatus.dPanel){
        ui->frontPanel_ICM->setVisible(false);
        ui->debugPanel->setVisible(true);
    }
    else{
        ui->frontPanel_ICM->setVisible(true);
        ui->debugPanel->setVisible(false);
    }
    //QApplication::processEvents();
}
void ICM::DisplayR(){
    ui->label_X->setVisible(false);
    ui->label_LC->setVisible(false);
    ui->value_XLXC->setVisible(false);

    double pResistanceValue=0.0;
    pResistanceValue = m_nResistance;
    pResistanceValue = pResistanceValue + m_dOffset;

    if (ui->calibrateDisplay->isChecked()) {
        CalibrateDisplay("ICM-R");

        double y, x, c, m;
        x = pResistanceValue;
        c = calibedConstant;
        m = calibedSlope;

        y = (x - c) / m;

        pResistanceValue = y;
        cbdR=y;
    }
    if (m_bNull == true) {
        pResistanceValue =pResistanceValue - m_dRNull;
    }

    if(pResistanceValue>1100000){
        dis->setValue("OL");
    }else{
        //Passing Range to display class~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        bool ok=true;
        QString str_value = convertToUnits(pResistanceValue);
        QString str_range = ui->rangeLabel->text();
        double dbl_value;int int_range;

        if(ui->rangeLabel->text().endsWith("KE") || ui->rangeLabel->text().endsWith("ME")){
            str_range.chop(2);
            dbl_value=str_value.toDouble(&ok);
            if(dbl_value>=0 && dbl_value<9.9)
                int_range=9;
            else if(dbl_value>=10 && dbl_value<99.9)
                int_range=99;
            else if(dbl_value>=100 && dbl_value<999.9)
                int_range=999;
        }
        else if(ui->rangeLabel->text().endsWith("E")){
            str_range.chop(1);
            dbl_value=str_value.toDouble(&ok);
            int_range=str_range.toInt(&ok,10);
        }
        dis->setRange(int_range);
        dis->setValue(dbl_value);
        ui->scrDisplay->setText(QString::number(dbl_value));
        if(dbl_value<12000000)
            InsertGraphData(dbl_value);

        //        qDebug()<<"strRange:"<<str_range<<"str_value:"<<str_value;
        //        qDebug()<<"intRange:"<<int_range<<"dbl_value:"<<dbl_value;
        //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    }

    ui->rangeLabel->setText(m_mapResistance.value(R_Index));
    configGraphData();//~~~~~~~~~~~~~~Graph Configuration~~~~~~~~~~
    emit ICM2GCalib(m_nResistance, "ICM-R");
    //QApplication::processEvents();
}
void ICM::readADC2() {

    usleep(10000);

    short int l_nResoulution = 23;
    double l_nGain = 1.0, l_nVREF = 2.048;
    double l_nFactor1 = 0.0, l_nFactor2 = 0.0;
    IAppCard->setSPIAppendBit(0xC000);

    noOFsamples = ui->spinBox_2->value();
    ui->noOFSamples->setText(QString::number(noOFsamples));
    double avgOut = 0.0;
    //	if (ui->CapacitanceRanges->isVisible())
    if (cFlag==true)
        m_nImpedanceValue = m_lstRFCapcitance.value(C_Index);
    //	if (ui->Inductorranges->isVisible())
    if (lFlag==true)
        m_nImpedanceValue = m_lstRFInductance.value(L_Index);


    for (int i = 0; i < noOFsamples; i++) {
        m_nADC1Voltage = m_objAD7190Component->readADCDataRegister(1)
                         & 0xFFFFFF;
        l_nFactor1 = (m_nADC1Voltage / pow(2, l_nResoulution)) - 1;
        l_nFactor2 = (l_nGain / l_nVREF);
        l_nAIN1 = l_nFactor1 / l_nFactor2;
        ui->label_2->setText(QString::number(l_nAIN1, 'f', 8));
        m_nADC2Voltage = m_objAD7190Component->readADCDataRegister(2)
                         & 0xFFFFFF;
        l_nFactor1 = (m_nADC2Voltage / pow(2, l_nResoulution)) - 1;
        l_nFactor2 = (l_nGain / l_nVREF);
        l_nAIN2 = l_nFactor1 / l_nFactor2;
        ui->label_4->setText(QString::number(l_nAIN2, 'f', 8));
        double l_nImpedanceValue = m_nImpedanceValue;
        ui->label_6->setText(QString::number(l_nImpedanceValue, 'f', 1));
        double l_n1 = (l_nImpedanceValue / l_nAIN2);
        m_nResistance = (l_n1 * l_nAIN1);
        avgOut = avgOut + m_nResistance;
    }
    m_nResistance = avgOut / noOFsamples;

    ui->label_7->setText(QString::number(m_nResistance, 'f', 12));

    double l_RMSDiv = (2 * (3.14) * m_nFrequency * m_nResistance);
    if (l_RMSDiv != 0)
        m_nCapacitance = 1 / l_RMSDiv;

    ui->label_11->setText(QString::number(m_nCapacitance, 'f', 15));

    double l_RMSDiv1 = (2 * (3.14) * m_nFrequency);
    if (l_RMSDiv1 != 0)
        m_nInductance = m_nResistance / l_RMSDiv1;
    ui->label_9->setText(QString::number(m_nInductance, 'f', 12));

    ui->lblfrequency->setText(QString::number(m_nFrequency, 'f', 0));


    m_nActualGain = m_nImpedanceValue / m_nResistance;

    m_nInductance = m_nInductance/*-lShortValues[L_Index]*/;
    m_nCapacitance = m_nCapacitance/*-cShortValues[C_Index]*/;

    //        if (ui->CapacitanceRanges->isVisible()) {
    if (cFlag==true) {
        ui->label_X->setVisible(true);
        ui->label_LC->setVisible(true);
        ui->value_XLXC->setVisible(true);
        ui->label_LC->setText("C:");
        ui->value_XLXC->setText(QString::number(m_nResistance,'f',6));

        GetDisplayCapcitance(m_nCapacitance, C_Index);
        ui->rangeLabel->setText(m_mapCapacitance.value(C_Index));
        configGraphData();//~~~~~~~~~~~~~~Graph Configuration~~~~~~~~~~
        emit ICM2GCalib(m_nCapacitance, "ICM-C");
    }

    //	else if (ui->Inductorranges->isVisible()) {
    else if (lFlag==true) {
        ui->label_X->setVisible(true);
        ui->label_LC->setVisible(true);
        ui->value_XLXC->setVisible(true);
        ui->label_LC->setText("L:");
        ui->value_XLXC->setText(QString::number(m_nResistance,'f',6));

        GetDisplayInductance(m_nInductance, L_Index);
        ui->rangeLabel->setText(m_mapInductance.value(L_Index));
        configGraphData();//~~~~~~~~~~~~~~Graph Configuration~~~~~~~~~~
        emit ICM2GCalib(m_nInductance, "ICM-L");
    }
}
double ICM::readADCR(QString str) {
    usleep(10000);
    double l_nResistance=0.0;
    short int l_nResoulution = 23;
    double l_nGain = 1.0, l_nVREF = 2.048;
    double l_nFactor1 = 0.0, l_nFactor2 = 0.0;
    IAppCard->setSPIAppendBit(0xC000);

    noOFsamples = ui->spinBox_2->value();
    ui->noOFSamples->setText(QString::number(noOFsamples));
    double avgOut = 0.0;

    m_nImpedanceValue = m_lstRFResistance.value(R_Index);

    for (int i = 0; i < noOFsamples; i++) {
        m_nADC1Voltage = m_objAD7190Component->readADCDataRegister(1)& 0xFFFFFF;
        l_nFactor1 = (m_nADC1Voltage / pow(2, l_nResoulution)) - 1;
        l_nFactor2 = (l_nGain / l_nVREF);
        l_nAIN1 = l_nFactor1 / l_nFactor2;
        ui->label_2->setText(QString::number(l_nAIN1, 'f', 8));

        m_nADC2Voltage = m_objAD7190Component->readADCDataRegister(2)& 0xFFFFFF;
        l_nFactor1 = (m_nADC2Voltage / pow(2, l_nResoulution)) - 1;
        l_nFactor2 = (l_nGain / l_nVREF);
        l_nAIN2 = l_nFactor1 / l_nFactor2;
        ui->label_4->setText(QString::number(l_nAIN2, 'f', 8));

        double l_nImpedanceValue = m_nImpedanceValue;
        ui->label_6->setText(QString::number(l_nImpedanceValue, 'f', 1));
        double l_n1 = (l_nImpedanceValue / l_nAIN2);
        l_nResistance = (l_n1 * l_nAIN1);
        avgOut = avgOut + l_nResistance;
    }
    l_nResistance = avgOut / noOFsamples;

    ui->label_7->setText(QString::number(l_nResistance, 'f', 12));

    ui->rangeLabel->setText(m_mapResistance.value(R_Index));
    configGraphData();//~~~~~~~~~~~~~~Graph Configuration~~~~~~~~~~
    qDebug()<<"ReadADC Resistance for"<<str<<":"<<l_nResistance;
    m_nResistance = l_nResistance;
    return l_nResistance;
}
double ICM::readADCL(QString str) {
    usleep(10000);
    double l_nResistance=0.0;
    short int l_nResoulution = 23;
    double l_nGain = 1.0, l_nVREF = 2.048;
    double l_nFactor1 = 0.0, l_nFactor2 = 0.0;
    IAppCard->setSPIAppendBit(0xC000);

    noOFsamples = ui->spinBox_2->value();
    ui->noOFSamples->setText(QString::number(noOFsamples));
    double avgOut = 0.0;

    m_nImpedanceValue = m_lstRFInductance.value(L_Index);

    for (int i = 0; i < noOFsamples; i++) {
        m_nADC1Voltage = m_objAD7190Component->readADCDataRegister(1)& 0xFFFFFF;
        l_nFactor1 = (m_nADC1Voltage / pow(2, l_nResoulution)) - 1;
        l_nFactor2 = (l_nGain / l_nVREF);
        l_nAIN1 = l_nFactor1 / l_nFactor2;
        ui->label_2->setText(QString::number(l_nAIN1, 'f', 8));

        m_nADC2Voltage = m_objAD7190Component->readADCDataRegister(2)& 0xFFFFFF;
        l_nFactor1 = (m_nADC2Voltage / pow(2, l_nResoulution)) - 1;
        l_nFactor2 = (l_nGain / l_nVREF);
        l_nAIN2 = l_nFactor1 / l_nFactor2;
        ui->label_4->setText(QString::number(l_nAIN2, 'f', 8));

        double l_nImpedanceValue = m_nImpedanceValue;
        ui->label_6->setText(QString::number(l_nImpedanceValue, 'f', 1));
        double l_n1 = (l_nImpedanceValue / l_nAIN2);
        l_nResistance = (l_n1 * l_nAIN1);
        avgOut = avgOut + l_nResistance;
    }
    l_nResistance = avgOut / noOFsamples;

    ui->label_7->setText(QString::number(l_nResistance, 'f', 12));
    ui->rangeLabel->setText(m_mapInductance.value(L_Index));

    double l_RMSDiv = (2 * (3.14) * m_nFrequency * m_nResistance);
    if (l_RMSDiv != 0)
        m_nCapacitance = 1 / l_RMSDiv;

    ui->label_11->setText(QString::number(m_nCapacitance, 'f', 15));

    double l_RMSDiv1 = (2 * (3.14) * m_nFrequency);
    if (l_RMSDiv1 != 0)
        m_nInductance = m_nResistance / l_RMSDiv1;

    ui->label_9->setText(QString::number(m_nInductance, 'f', 12));
    ui->lblfrequency->setText(QString::number(m_nFrequency, 'f', 0));

    m_nActualGain = m_nImpedanceValue / m_nResistance;

    qDebug()<<"ReadADC Inductance for"<<str<<":"<<m_nInductance;

    return m_nInductance;
}
double ICM::readADCC(QString str) {
    usleep(200000);
    double l_nResistance=0.0;
    short int l_nResoulution = 23;
    double l_nGain = 1.0, l_nVREF = 2.048;
    double l_nFactor1 = 0.0, l_nFactor2 = 0.0;
    double l_AIN1,l_AIN2;
    double l_nCapacitance=0;

    IAppCard->setSPIAppendBit(0xC000);

    noOFsamples = ui->spinBox_2->value();
    ui->noOFSamples->setText(QString::number(noOFsamples));
    double avgOut = 0.0;
    unsigned int l_nADC1Voltage,l_nADC2Voltage;
    double l_nImpedanceValue = m_lstRFCapcitance.value(C_Index);

    for (int i = 0; i < noOFsamples; i++) {
        l_nADC1Voltage = m_objAD7190Component->readADCDataRegister(1)& 0xFFFFFF;
        l_nFactor1 = (l_nADC1Voltage / pow(2, l_nResoulution)) - 1;
        l_nFactor2 = (l_nGain / l_nVREF);
        l_AIN1 = l_nFactor1 / l_nFactor2;
        ui->label_2->setText(QString::number(l_AIN1, 'f', 8));

        l_nADC2Voltage = m_objAD7190Component->readADCDataRegister(2)& 0xFFFFFF;
        l_nFactor1 = (l_nADC2Voltage / pow(2, l_nResoulution)) - 1;
        l_nFactor2 = (l_nGain / l_nVREF);
        l_AIN2 = l_nFactor1 / l_nFactor2;
        ui->label_4->setText(QString::number(l_AIN2, 'f', 8));


        ui->label_6->setText(QString::number(l_nImpedanceValue, 'f', 1));
        double l_n1 = (l_nImpedanceValue / l_AIN2);
        l_nResistance = (l_n1 * l_AIN1);
        avgOut = avgOut + l_nResistance;
    }
    l_nResistance = avgOut / noOFsamples;

    ui->label_7->setText(QString::number(l_nResistance, 'f', 12));
    ui->rangeLabel->setText(m_mapCapacitance.value(C_Index));

    double l_RMSDiv = (2 * (3.14) * m_nFrequency * l_nResistance);
    if (l_RMSDiv != 0)
        l_nCapacitance = 1 / l_RMSDiv;

    ui->label_11->setText(QString::number(l_nCapacitance, 'f', 15));

    double l_RMSDiv1 = (2 * (3.14) * m_nFrequency);
    if (l_RMSDiv1 != 0)
        m_nInductance = l_nResistance / l_RMSDiv1;

    ui->label_9->setText(QString::number(m_nInductance, 'f', 12));
    ui->lblfrequency->setText(QString::number(m_nFrequency, 'f', 0));

    m_nActualGain = l_nImpedanceValue / l_nResistance;

    qDebug()<<"ReadADC Capacitance for"<<str<<":"<<m_nCapacitance;

    l_nCapacitance = l_nCapacitance/*-cShortValues[C_Index]*/;

    return l_nCapacitance;
}
void ICM::AutoRangeR3(){
    double r300,r3K,r30K,r300K,r1M;
    double r300_2,r3K_2,r30K_2,r300K_2,r1M_2;
    double r300Per,r3KPer,r30KPer,r300KPer,r1MPer;
    QString swRange;

    //FullScan
    qDebug()<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";

    on_R100E_clicked();     r300 = readADCR("300E")/*-rShortValues[R_Index]*/; if(r300 < 0 || r300 >5000) r300 = 5000000;

    //    on_R1KE_clicked();      r3K = fabs(readADCR("3KE"));

    on_R10KE_clicked();     r30K = fabs(readADCR("30KE"))/*-rShortValues[R_Index]*/;

    on_R100KE_clicked();    r300K = fabs(readADCR("300KE"))/*-rShortValues[R_Index]*/;

    on_R1ME_clicked();      r1M = fabs(readADCR("1ME"))/*-rShortValues[R_Index]*/;
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    r300_2 = fabs(r30K-r300);        qDebug()<<"300E : "<<r300;
    //    r300_2 = fabs(r3K-r300);        qDebug()<<"300E : "<<r300;
    //    r3K_2 = fabs(r30K-r3K);         qDebug()<<"3KE : "<<r3K;
    //    r30K_2 = fabs(r300K-r300);      qDebug()<<"30KE : "<<r30K;
    r30K_2 = fabs(r300K-r30K);      qDebug()<<"30KE : "<<r30K;
    r300K_2 = fabs(r1M-r300K);      qDebug()<<"300KE : "<<r300K;
    r1M_2 = fabs(r1M - r300);       qDebug()<<"1ME : "<<r1M;

    int index=0;
    //    double array[5] = {r300_2,r3K_2,r30K_2,r300K_2,r1M_2};
    double array[4] = {r300_2,r30K_2,r300K_2,r1M_2};
    double smallest =array[0];
    //    for(int i = 0; i < 5; i++){
    for(int i = 0; i < 4; i++){
        if(array[i] < smallest){
            smallest = array[i];
            index = i;
        }
    }
    //    qDebug()<<"Index:"<<index<<"Smallest of 5 values :"<<smallest;
    qDebug()<<"Index:"<<index<<"Smallest of 4 values :"<<smallest;

    switch(index){
    case 0:
        //        if(r3K>r300)
        if(r30K>r300){
            if(r300>1 && r300 < 110){
                swRange="300E";
            }
            else if(r300 > 110 && r300 < 1100)
                swRange="3KE";
            else if(r300 > 900 && r300 < 3300)
                swRange="30KE";
            else{
                qDebug()<<"______________30E";
                swRange="30E";
            }
        }
        else
            swRange="30KE";
        //            swRange="3KE";
        break;

	case 1:
        //        if(r30K>r3K)
        if(r300K>r30K){
            //            swRange="3KE";
            if(r30K > 10000)
                swRange="300KE";
            else
                swRange="30KE";
        }
        else
            swRange="300KE";
        //            swRange="30KE";
        break;

	case 2:
        //        if(r300K>r30K)
        if(r1M>r300K){
            //            swRange="30KE";
            if(r1M < 330000)
                swRange="300KE";
            else
                swRange="1ME";
        }
        else{
            if(r300K < 330000)
                swRange="300KE";
            else
                swRange="1ME";
            //            swRange="300KE";
        }
        break;
        //    case 3:
        //        if(r1M>r300K)
        //            swRange="300KE";
        //        else{
        //            if(r300K < 330000)
        //                swRange="300KE";
        //            else
        //                swRange="1ME";
        //        }
        //        break;
        //    case 4:
	case 3:
        swRange="1ME";
        break;
    }
    qDebug()<<"swRange after Validation :"<<swRange;

    //    if( ((r3K >(r300-r300Per)) && r3K < (r300+r300Per))){
    //        if(r3K < r300)
    //            swRange = "3KE";
    //        else
    //            swRange = "300E";
    //    }
    //    else if( ((r30K >(r300-r300Per)) && r30K < (r300+r300Per))){
    //        if(r30K < r300)
    //            swRange = "30KE";
    //        else
    //            swRange = "300E";
    //    }
    //    else if( ((r300K >(r300-r300Per)) && r300K < (r300+r300Per))){
    //        if(r300K < r300)
    //            swRange = "300KE";
    //        else
    //            swRange = "300E";
    //    }
    //    else if( ((r1M >(r300-r300Per)) && r1M < (r300+r300Per))){
    //        if(r1M < r300)
    //            swRange = "1ME";
    //        else
    //            swRange = "300E";
    //    }
    //
    //    qDebug()<<"swRange after 300E Validation :"<<swRange;
    ////~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    //    if( ((r300 >(r3K-r3KPer)) && r300 < (r3K+r3KPer))){
    //        if(r300 < r3K)
    //            swRange = "300E";
    //        else
    //            swRange = "3KE";
    //    }
    //    else if( ((r30K >(r3K-r3KPer)) && r30K < (r3K+r3KPer))){
    //        if(r30K < r3K)
    //            swRange = "30KE";
    //        else
    //            swRange = "3KE";
    //    }
    //    else if( ((r300K >(r3K-r3KPer)) && r300K < (r3K+r3KPer))){
    //        if(r300K < r3K)
    //            swRange = "300KE";
    //        else
    //            swRange = "3KE";
    //    }
    //    else if( ((r1M >(r3K-r3KPer)) && r1M < (r3K+r3KPer))){
    //        if(r1M < r3K)
    //            swRange = "1ME";
    //        else
    //            swRange = "3KE";
    //    }
    //    qDebug()<<"swRange after 3KE Validation :"<<swRange;
    ////~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    //    if( ((r300 >(r30K-r30KPer)) && r300 < (r30K+r30KPer))){
    //        if(r300 < r30K)
    //            swRange = "300E";
    //        else
    //            swRange = "30KE";
    //    }
    //    else if( ((r3K >(r30K-r30KPer)) && r3K < (r30K+r30KPer))){
    //        if(r3K < r30K)
    //            swRange = "3KE";
    //        else
    //            swRange = "30KE";
    //    }
    //    else if( ((r300K >(r30K-r30KPer)) && r300K < (r30K+r30KPer))){
    //        if(r300K < r30K)
    //            swRange = "300KE";
    //        else
    //            swRange = "30KE";
    //    }
    //    else if( ((r1M >(r30K-r30KPer)) && r1M < (r30K+r30KPer))){
    //        if(r1M < r30K)
    //            swRange = "3KE";
    //        else
    //            swRange = "1ME";
    //    }
    //    qDebug()<<"swRange after 30KE Validation :"<<swRange;
    ////~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    //    if( ((r300 >(r300K-r300KPer)) && r300 < (r300K+r300KPer))){
    //        if(r300 < r300K)
    //            swRange = "300E";
    //        else
    //            swRange = "300KE";
    //    }
    //    else if( ((r3K >(r300K-r300KPer)) && r3K < (r300K+r300KPer))){
    //        if(r3K < r300K)
    //            swRange = "3KE";
    //        else
    //            swRange = "300KE";
    //    }
    //    else if( ((r30K >(r300K-r300KPer)) && r30K < (r300K+r300KPer))){
    //        if(r30K < r300K)
    //            swRange = "30KE";
    //        else
    //            swRange = "300KE";
    //    }
    //    else if( ((r1M >(r300K-r300KPer)) && r1M < (r300K+r300KPer))){
    //        if(r1M < r300K)
    //            swRange = "1ME";
    //        else
    //            swRange = "300KE";
    //    }
    //    qDebug()<<"swRange after 300KE Validation :"<<swRange;
    ////~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    //    if( ((r300 >(r1M-r1MPer)) && r300 < (r1M+r1MPer))){
    //        if(r300 < r1M)
    //            swRange = "300E";
    //        else
    //            swRange = "1ME";
    //    }
    //    else if( ((r3K >(r1M-r1MPer)) && r3K < (r1M+r1MPer))){
    //        if(r3K < r1M)
    //            swRange = "3KE";
    //        else
    //            swRange = "1ME";
    //    }
    //    else if( ((r30K >(r1M-r1MPer)) && r30K < (r1M+r1MPer))){
    //        if(r30K < r1M)
    //            swRange = "30KE";
    //        else
    //            swRange = "1ME";
    //    }
    //    else if( ((r300K >(r1M-r1MPer)) && r300K < (r1M+r1MPer))){
    //        if(r300K < r1M)
    //            swRange = "300KE";
    //        else
    //            swRange = "1ME";
    //    }
    //    qDebug()<<"swRange after 1ME Validation :"<<swRange;
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    if(swRange == "30E"){
        ui->R10E->setChecked(true);
        on_R10E_clicked();
    }
    else if(swRange == "300E"){
        ui->R100E->setChecked(true);
        on_R100E_clicked();
    }
    else if(swRange == "3KE"){
        ui->R1KE->setChecked(true);
        on_R1KE_clicked();
    }
    else if(swRange == "30KE"){
        ui->R10KE->setChecked(true);
        on_R10KE_clicked();
    }
    else if(swRange == "300KE"){
        ui->R100KE->setChecked(true);
        on_R100KE_clicked();
    }
    else if(swRange == "1ME"){
        ui->R1ME->setChecked(true);
        on_R1ME_clicked();
    }
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    /*m_nResistance = readADCR(swRange);
    DisplayR();*/
}

void ICM::AutoRangeR2(){

    /*    if(m_nRange == 300){
        if(l_nAIN2 < 0.02 || l_nAIN2 > 0.45){
            ui->R1KE->setChecked(true);
                on_R1KE_clicked();
        }
    }
    else if(m_nRange == 3000){
        if(l_nAIN2 < 0.02 || l_nAIN2 > 0.45){
            ui->R10KE->setChecked(true);
                on_R10KE_clicked();
        }
    }
    else if(m_nRange == 30000){
        if(l_nAIN2 < 0.02 || l_nAIN2 > 0.45){
            ui->R100KE->setChecked(true);
                on_R100KE_clicked();
        }
    }
    else if(m_nRange == 300000){
        if(l_nAIN2 < 0.02 || l_nAIN2 > 0.45){
            ui->R1ME->setChecked(true);
                on_R1ME_clicked();
        }
    }
    else if(m_nRange == 1000000){
        if(l_nAIN2 < 0.02 || l_nAIN2 > 0.45){
            dis->setValue("OL");
        }
    }
	 */

    if(m_nRange == 300){
        if(l_nAIN2 < 0.02 || l_nAIN2 > 0.45){
            ui->R1KE->setChecked(true);
            on_R1KE_clicked();
        }
    }
    else if(m_nRange == 3000){
        if(l_nAIN2 < 0.03 || l_nAIN2 > 0.30){
            ui->R10KE->setChecked(true);
            on_R10KE_clicked();
        }
    }
    else if(m_nRange == 30000){
        if(l_nAIN2 < 0.03 || l_nAIN2 > 0.32){
            ui->R100KE->setChecked(true);
            on_R100KE_clicked();
        }
    }
    else if(m_nRange == 300000){
        if(l_nAIN2 < 0.03 || l_nAIN2 > 0.32){
            ui->R100KE->setChecked(true);
            on_R100KE_clicked();
        }
    }
    else if(m_nRange == 1000000){
        if(l_nAIN2 < 0.04 || l_nAIN2 > 0.14){
            dis->setValue("OL");
        }
    }
    m_nResistance = readADCR(ui->rangeLabel->text());
    DisplayR();
}

void ICM::AutoRangeR(){

    double prevRangeValue,curRangeValue,nextRangeValue;
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    //Switch 1M Range
    ui->R1ME->setChecked(true);
    on_R1ME_clicked();
    curRangeValue = readADCR("1ME");
    if(curRangeValue > 1000000){
        dis->setValue("OL");
    }else{
        if(curRangeValue>300000 && curRangeValue<=1000000){
            //Switch 300K Range for Lower Range Value
            ui->R100KE->setChecked(true);
            on_R100KE_clicked();
            prevRangeValue = readADCR("300KE");
            if(prevRangeValue>300000 && prevRangeValue <=1000000){
                if(curRangeValue < prevRangeValue){
                    ui->R100KE->setChecked(true);
                    on_R100KE_clicked();
                }else{
                    ui->R1ME->setChecked(true);
                    on_R1ME_clicked();
                }
            }else{
                ui->R1ME->setChecked(true);
                on_R1ME_clicked();
            }
        }
        //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        else{
            //Switch 300K Range
            ui->R100KE->setChecked(true);
            on_R100KE_clicked();
            curRangeValue=readADCR("300KE");
            if(curRangeValue>30000 && curRangeValue<=300000){
                //Switch 30K Range for Lower Range Value
                ui->R10KE->setChecked(true);
                on_R10KE_clicked();
                prevRangeValue = readADCR("30KE");

                if(prevRangeValue>30000 && prevRangeValue <= 300000){
                    if(curRangeValue < prevRangeValue){
                        ui->R10KE->setChecked(true);
                        on_R10KE_clicked();
                    }else{
                        ui->R100KE->setChecked(true);
                        on_R100KE_clicked();
                    }
                }else{
                    ui->R100KE->setChecked(true);
                    on_R100KE_clicked();
                }
                //Switch 1M Range for Higher Range Value
                ui->R1ME->setChecked(true);
                on_R1ME_clicked();
                nextRangeValue = readADCR("1ME");
                if(nextRangeValue>30000 && nextRangeValue <= 300000){
                    if(curRangeValue < nextRangeValue){
                        ui->R1ME->setChecked(true);
                        on_R1ME_clicked();
                    }else{
                        ui->R100KE->setChecked(true);
                        on_R100KE_clicked();
                    }
                }else{
                    ui->R100KE->setChecked(true);
                    on_R100KE_clicked();
                }
            }
            //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
            else{
                //Switch 30K Range
                ui->R10KE->setChecked(true);
                on_R10KE_clicked();
                curRangeValue=readADCR("30KE");
                if(curRangeValue>300 && curRangeValue<=30000){
                    //Switch 300E Range for Lower Range Value
                    ui->R100E->setChecked(true);
                    on_R100E_clicked();
                    prevRangeValue = readADCR("300E");
                    if(prevRangeValue>300 && prevRangeValue <= 30000){
                        if((curRangeValue > prevRangeValue)){
                            ui->R100E->setChecked(true);
                            on_R100E_clicked();
                        }else{
                            ui->R10KE->setChecked(true);
                            on_R10KE_clicked();
                        }
                    }else{
                        ui->R10KE->setChecked(true);
                        on_R10KE_clicked();
                    }
                    //Switch 300KE Range for Higher Range Value
                    ui->R100KE->setChecked(true);
                    on_R100KE_clicked();
                    nextRangeValue = readADCR("300KE");
                    if(nextRangeValue>300 && nextRangeValue <= 30000){
                        if(curRangeValue>nextRangeValue){
                            ui->R100KE->setChecked(true);
                            on_R100KE_clicked();
                        }else{
                            ui->R10KE->setChecked(true);
                            on_R10KE_clicked();
                        }
                    }else{
                        ui->R10KE->setChecked(true);
                        on_R10KE_clicked();
                    }
                }
                //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                else{
                    //Switch 300E Range
                    ui->R100E->setChecked(true);
                    on_R100E_clicked();
                    curRangeValue=readADCR("300E");

                    if(curRangeValue>0 && curRangeValue<=300){
                        //Switch 30KE Range for Higher Range Value
                        //					ui->R10KE->setChecked(true);
                        //					on_R10KE_clicked();
                        //					nextRangeValue = readADCR("10KE");
                        //					if(nextRangeValue>0 && nextRangeValue <= 300){
                        //						if((curRangeValue - nextRangeValue)<=(curRangeValue*0.1)){
                        //							ui->R10KE->setChecked(true);
                        //							on_R10KE_clicked();
                        //						}else{
                        ui->R100E->setChecked(true);
                        on_R100E_clicked();
                        //						}
                        //					}else{
                        //						ui->R100E->setChecked(true);
                        //						on_R100E_clicked();
                        //					}
                    }
                }
            }
        }
    }
}
double ICM::calibC(double p_nData){
    p_nData = p_nData + m_dOffset;

    if (ui->calibrateDisplay->isChecked()) {
        CalibrateDisplay("ICM-C");

        double y, x, c, m;
        x = p_nData;
        c = calibedConstant;
        m = calibedSlope;

        y = (x - c) / m;

        p_nData = y;
        cbdC=y;

    }
    if (m_bNull == true) {
        p_nData = p_nData - m_dCNull;
    }

    return p_nData;
}

int ICM::AutoRangeC1(){
    double localVar=m_nCapacitance_2;
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    if(AutoCFlag==0){
        if (localVar>=0 && localVar <= 0.00000000011) {
            if (C_Index != 0) {
                ui->C100pF->setChecked(true);
                on_C100pF_clicked();
                usleep(50000);
            }
        }else{
            if (C_Index != 1) {
                ui->C1nF->setChecked(true);
                on_C1nF_clicked();
                usleep(50000);
            }
            AutoCFlag=1;
        }
        localVar = calibC(readADCC("1nF"));
    }
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    if(AutoCFlag==1){
        if (localVar > 0.00000000009 && localVar<= 0.0000000011) {
            if (C_Index != 1) {
                ui->C1nF->setChecked(true);
                on_C1nF_clicked();
                usleep(50000);
            }
            if (l_nAIN1 >= 2.047 || l_nAIN2 >= 2.047) {
                if (C_Index != 2) {
                    ui->C10nF->setChecked(true);
                    on_C10nF_clicked();
                    usleep(50000);
                }
            }
        }
        else{
            if (C_Index != 2) {
                ui->C10nF->setChecked(true);
                on_C10nF_clicked();
                usleep(50000);
            }
            AutoCFlag=2;
        }
        localVar = calibC(readADCC("10nF"));
    }
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    if(AutoCFlag==2){
        if (localVar > 0.0000000009 && localVar <= 0.000000011) {
            if (C_Index != 2) {
                ui->C10nF->setChecked(true);
                on_C10nF_clicked();
                usleep(50000);
            }
            if (l_nAIN1 >= 2.047 || l_nAIN2 >= 2.047) {
                if (C_Index != 3) {
                    ui->C100nF->setChecked(true);
                    on_C100nF_clicked();
                    usleep(50000);
                }
            }
        }
        else{
            if (C_Index != 5) {
                ui->C10uF->setChecked(true);
                on_C10uF_clicked();
                usleep(50000);
            }
            AutoCFlag=5;
        }
        localVar = calibC(readADCC("10uF"));
    }
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    if(AutoCFlag==3){
        if (localVar > 0.000000009 && localVar <= 0.00000011) {

            if(localVar < 0.000000015){

                on_C10nF_clicked();
                usleep(50000);
                localVar = calibC(readADCC("10nF"));

                if(localVar < 0.0000000005){
                    ui->C100pF->setChecked(true);
                    on_C100pF_clicked();
                    usleep(50000);
                    AutoCFlag=0;
                }else{
                    ui->C100nF->setChecked(true);
                    on_C100nF_clicked();
                    usleep(50000);
                }
            }



            //            if (C_Index != 3) {
            //                    ui->C100nF->setChecked(true);
            //                    on_C100nF_clicked();
            //                    usleep(50000);
            //            }
            //            if (l_nAIN1 >= 2.047 || l_nAIN2 >= 2.047) {
            //                    if (C_Index != 4) {
            //                            ui->C1uF->setChecked(true);
            //                            on_C1uF_clicked();
            //                            usleep(50000);
            //                    }
            //            }
        }
        else {
            if (C_Index != 4) {
                ui->C1uF->setChecked(true);
                on_C1uF_clicked();
                usleep(50000);
            }
            AutoCFlag=4;
        }
        localVar = calibC(readADCC("1uF"));
    }
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    if(AutoCFlag==4){
        if (localVar > 0.00000009 && localVar<= 0.0000011) {
            if(localVar < 0.0000003){

                on_C100nF_clicked();
                usleep(50000);
                localVar = calibC(readADCC("100nF"));

                if(localVar < 0.00000005){
                    ui->C100pF->setChecked(true);
                    on_C100pF_clicked();
                    usleep(50000);
                    AutoCFlag=0;
                }else{
                    ui->C1uF->setChecked(true);
                    on_C1uF_clicked();
                    usleep(50000);
                }
            }
            //            if (C_Index != 4) {
            //                    ui->C1uF->setChecked(true);
            //                    on_C1uF_clicked();
            //                    usleep(50000);
            //            }
            //            if (l_nAIN1 >= 2.047 || l_nAIN2 >= 2.047) {
            //                    if (C_Index != 5) {
            //                            ui->C10uF->setChecked(true);
            //                            on_C10uF_clicked();
            //                            usleep(50000);
            //                    }
            //            }
        }
        else {
            if (C_Index != 5) {
                ui->C100pF->setChecked(true);
                on_C100pF_clicked();
                usleep(50000);
            }
            AutoCFlag=0;
        }
        localVar = calibC(readADCC("100pF"));
    }
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    if(AutoCFlag==5){
        if (localVar > 0.0000009 && localVar <= 0.0000065) {
            if (C_Index != 5) {
                ui->C10uF->setChecked(true);
                on_C10uF_clicked();
                usleep(50000);
            }
            if (l_nAIN1 >= 2.047 || l_nAIN2 >= 2.047) {
                if (C_Index != 6) {
                    ui->C100uF->setChecked(true);
                    on_C100uF_clicked();
                    usleep(50000);
                }
            }
        }
        else {
            if (C_Index != 6) {
                ui->C100uF->setChecked(true);
                on_C100uF_clicked();
                usleep(50000);
            }
            AutoCFlag=6;
        }
        localVar = calibC(readADCC("100uF"));

    }
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    if(AutoCFlag==6){
        if (localVar > 0.0000060 && localVar <= 0.00011) {
            if (C_Index != 6) {
                ui->C100uF->setChecked(true);
                on_C100uF_clicked();
                usleep(50000);
            }
            if (l_nAIN1 >= 2.047 || l_nAIN2 >= 2.047) {
                if (C_Index != 7) {
                    ui->C1mF->setChecked(true);
                    on_C1mF_clicked();
                    usleep(50000);
                }
            }
        }
        else {
            if (C_Index != 7) {
                ui->C1mF->setChecked(true);
                on_C1mF_clicked();
                usleep(50000);
            }
            AutoCFlag=7;
        }
        localVar = calibC(readADCC("1mF"));
    }
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    if(AutoCFlag==7){
        if (localVar > 0.00009 && localVar <= 0.0011) {
            if (C_Index != 7) {
                ui->C1mF->setChecked(true);
                on_C1mF_clicked();
                usleep(50000);
            }
            if (l_nAIN1 >= 2.047 || l_nAIN2 >= 2.047) {
                if (C_Index != 8) {
                    ui->C10mF->setChecked(true);
                    on_C10mF_clicked();
                    usleep(50000);
                }
            }
        }
        else {
            if (C_Index != 8) {
                ui->C10mF->setChecked(true);
                on_C10mF_clicked();
                usleep(50000);
            }
            AutoCFlag=8;
        }
        localVar = calibC(readADCC("10mF"));
    }
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    if(AutoCFlag==8){
        if (localVar > 0.0009 && localVar <= 0.020) {
            if (C_Index != 8) {
                ui->C10mF->setChecked(true);
                on_C10mF_clicked();
                usleep(50000);
            }
            //            if (l_nAIN1 >= 2.048 || l_nAIN2 >= 2.048) {
            //                    dis->setValue("OL");
            //                    ui->Unit->setText("");
            //            }
        } else {
            if (C_Index != 3) {
                ui->C100nF->setChecked(true);
                on_C100nF_clicked();
                usleep(50000);
            }
            AutoCFlag =3;
        }
        localVar = calibC(readADCC("100nF"));
    }
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    if (localVar > 0.020) {
        dis->setValue("OL");
        ui->Unit->setText("");
    }
    m_nCapacitance=localVar;
}

void ICM::AutoRange() {
    //    if (ui->ResistanceRanges->isVisible()) {
    if (rFlag==true) {/*
		if (m_nResistance_2 > 1100000) {
			qDebug()<<"greater than 1.1M";
			dis->setValue("OL");
			ui->Unit->setText("");
		}
		if (m_nResistance_2 > 290000 && m_nResistance_2 <= 1100000) {
			qDebug()<<"greater than 290K & less than 1.1M";
			ui->R1ME->setChecked(true);
			on_R1ME_clicked();
			if (l_nAIN1 >= 2.048 || l_nAIN2 >= 2.048) {
				ui->R10E->setChecked(true);
				on_R10E_clicked();
			}
		}
		if (m_nResistance_2 > 29000 && m_nResistance_2 <= 310000) {
			qDebug()<<"greater than 29K & less than 3.1K";
			ui->R100KE->setChecked(true);
			on_R100KE_clicked();
			if (l_nAIN1 >= 2.047 || l_nAIN2 >= 2.047) {
				ui->R10E->setChecked(true);
				on_R10E_clicked();
			}
		}
		if (m_nResistance_2 > 2900 && m_nResistance_2 <= 31000) {
			qDebug()<<"greater than 2.9K & less than 31K";
			ui->R10KE->setChecked(true);
			on_R10KE_clicked();
			if (l_nAIN1 >= 2.047 || l_nAIN2 >= 2.047) {
				ui->R10E->setChecked(true);
				on_R10E_clicked();
			}
		}
		if (m_nResistance_2 > 290 && m_nResistance_2 <= 3100) {
			qDebug()<<"greater than 29E & less than 3.1K";
			ui->R10KE->setChecked(true);
			on_R10KE_clicked();
			if (l_nAIN1 >= 2.047 || l_nAIN2 >= 2.047) {
				ui->R10E->setChecked(true);
				on_R10E_clicked();
			}
		}
		if (m_nResistance_2 > 1 && m_nResistance_2 <= 310) {
			qDebug()<<"greater than 1E & less than 31E";
			ui->R100E->setChecked(true);
			on_R100E_clicked();
			if (l_nAIN1 >= 2.047 || l_nAIN2 >= 2.047) {
				ui->R10E->setChecked(true);
				on_R10E_clicked();
			}
		}
		if (m_nResistance_2 <= 1) {
			qDebug()<<"less than 1E";
			ui->R100E->setChecked(true);
			on_R10E_clicked();
			if (l_nAIN1 >= 2.047 || l_nAIN2 >= 2.047) {
				ui->R10E->setChecked(true);
				on_R10E_clicked();
			}
                }*/

        //	} else if (ui->Inductorranges->isVisible()) {
    } else if (lFlag==true) {
        if (m_nInductance_2 >=0 && m_nInductance_2 <= 0.000033) {
            if (L_Index != 0) {
                ui->L30uH->setChecked(true);
                on_L30uH_clicked();
            }
            if (l_nAIN1 >= 2.047 || l_nAIN2 >= 2.047) {
                if (L_Index != 1) {
                    //				 ui->L300uH->setChecked(true);
                    //				 on_L300uH_clicked();
                    ui->L30uH->setChecked(true);
                    on_L30uH_clicked();
                }
            }
        } else if (m_nInductance_2 > 0.000027 && m_nInductance_2 <= 0.00033) {
            if (L_Index != 1) {
                ui->L300uH->setChecked(true);
                on_L300uH_clicked();
            }
            if (l_nAIN1 >= 2.047 || l_nAIN2 >= 2.047) {
                if (L_Index != 2) {
                    //				 ui->L3mH->setChecked(true);
                    //				 on_L3mH_clicked();
                    ui->L30uH->setChecked(true);
                    on_L30uH_clicked();
                }
            }
        } else if (m_nInductance_2 > 0.00027 && m_nInductance_2 <= 0.0033) {
            if (L_Index != 2) {
                ui->L3mH->setChecked(true);
                on_L3mH_clicked();
            }
            if (l_nAIN1 >= 2.047 || l_nAIN2 >= 2.047) {
                if (L_Index != 3) {
                    //				 ui->L30mH->setChecked(true);
                    //				 on_L30mH_clicked();
                    ui->L30uH->setChecked(true);
                    on_L30uH_clicked();
                }
            }
        } else if (m_nInductance_2 > 0.0027 && m_nInductance_2 <= 0.033) {
            if (L_Index != 3) {
                ui->L30mH->setChecked(true);
                on_L30mH_clicked();
            }
            if (l_nAIN1 >= 2.047 || l_nAIN2 >= 2.047) {
                if (L_Index != 4) {
                    //				 ui->L300mH->setChecked(true);
                    //				 on_L300mH_clicked();
                    ui->L30uH->setChecked(true);
                    on_L30uH_clicked();
                }
            }
        } else if (m_nInductance_2 > 0.027 && m_nInductance_2 <= 0.33) {
            if (L_Index != 4) {
                ui->L300mH->setChecked(true);
                on_L300mH_clicked();
            }
            if (l_nAIN1 >= 2.047 || l_nAIN2 >= 2.047) {
                if (L_Index != 5) {
                    //				 ui->L3H->setChecked(true);
                    //				 on_L3H_clicked();
                    ui->L30uH->setChecked(true);
                    on_L30uH_clicked();
                }
            }
        } else if (m_nInductance_2 > 0.27 && m_nInductance_2 <= 3.3) {
            if (L_Index != 5) {
                ui->L3H->setChecked(true);
                on_L3H_clicked();
            }
            if (l_nAIN1 >= 2.047 || l_nAIN2 >= 2.047) {
                if (L_Index != 6) {
                    //				 ui->L30H->setChecked(true);
                    //				 on_L30H_clicked();
                    ui->L30uH->setChecked(true);
                    on_L30uH_clicked();
                }
            }
        } else if (m_nInductance_2 > 2.7 && m_nInductance_2 <= 33) {
            if (L_Index != 6) {
                ui->L30H->setChecked(true);
                on_L30H_clicked();
            }
            if (l_nAIN1 >= 2.047 || l_nAIN2 >= 2.047) {
                ui->L30uH->setChecked(true);
                on_L30uH_clicked();
            }
        } else if (m_nInductance_2 > 30) {
            dis->setValue("OL");
            ui->Unit->setText("");
        }
        //        } else if (ui->CapacitanceRanges->isVisible()) {/*
    } else if (cFlag==true) {/*
		if (m_nCapacitance_2 <= 0.00000000009) {
			if (C_Index != 0) {
				ui->C100pF->setChecked(true);
				on_C100pF_clicked();
			}
		}
                else if (m_nCapacitance_2 > 0.000000000090000000000000 && m_nCapacitance_2
				<= 0.0000000009) {
			if (C_Index != 1) {
				ui->C1nF->setChecked(true);
				on_C1nF_clicked();
			}
			if (l_nAIN1 >= 2.047 || l_nAIN2 >= 2.047) {
				if (C_Index != 2) {
					ui->C10nF->setChecked(true);
					on_C10nF_clicked();
					//					 ui->C100pF->setChecked(true);
					//					 on_C100pF_clicked();
				}
			}
		}
                else if (m_nCapacitance_2 > 0.000000000909999999999999 && m_nCapacitance_2
				<= 0.000000009) {
			if (C_Index != 2) {
				ui->C10nF->setChecked(true);
				on_C10nF_clicked();
			}
			if (l_nAIN1 >= 2.047 || l_nAIN2 >= 2.047) {
				if (C_Index != 3) {
					ui->C100nF->setChecked(true);
					on_C100nF_clicked();
					//					 ui->C100pF->setChecked(true);
					//					 on_C100pF_clicked();
				}
			}
		}
                else if (m_nCapacitance_2 > 0.00000000909 && m_nCapacitance_2 <= 0.00000009) {
			if (C_Index != 3) {
				ui->C100nF->setChecked(true);
				on_C100nF_clicked();
			}
			if (l_nAIN1 >= 2.047 || l_nAIN2 >= 2.047) {
				if (C_Index != 4) {
                                        ui->C1uF->setChecked(true);
                                        on_C1uF_clicked();
					//					 ui->C100pF->setChecked(true);
					//					 on_C100pF_clicked();
				}
			}
		}
                else if (m_nCapacitance_2 > 0.0000000909100000000001 && m_nCapacitance_2
				<= 0.0000009) {
			if (C_Index != 4) {
				ui->C1uF->setChecked(true);
				on_C1uF_clicked();
			}
			if (l_nAIN1 >= 2.047 || l_nAIN2 >= 2.047) {
				if (C_Index != 5) {
					ui->C10uF->setChecked(true);
					on_C10uF_clicked();
					//					 ui->C100pF->setChecked(true);
					//					 on_C100pF_clicked();
				}
			}
                }
                else if (m_nCapacitance_2 > 0.000000909090000000001 && m_nCapacitance_2
                                <= 0.0000065) {
			if (C_Index != 5) {
				ui->C10uF->setChecked(true);
				on_C10uF_clicked();
			}
			if (l_nAIN1 >= 2.047 || l_nAIN2 >= 2.047) {
				if (C_Index != 6) {
					ui->C100uF->setChecked(true);
					on_C100uF_clicked();
					//					 ui->C100pF->setChecked(true);
					//					 on_C100pF_clicked();
				}
			}
		}
                else if (m_nCapacitance_2 > 0.0000065 && m_nCapacitance_2 <= 0.00009) {
			if (C_Index != 6) {
				ui->C100uF->setChecked(true);
				on_C100uF_clicked();
			}
			if (l_nAIN1 >= 2.047 || l_nAIN2 >= 2.047) {
				if (C_Index != 7) {
					ui->C1mF->setChecked(true);
					on_C1mF_clicked();
					//					 ui->C100pF->setChecked(true);
					//					 on_C100pF_clicked();
				}
			}
		}
                else if (m_nCapacitance_2 > 0.00009090909 && m_nCapacitance_2 <= 0.0009) {
			if (C_Index != 7) {
				ui->C1mF->setChecked(true);
				on_C1mF_clicked();
			}
			if (l_nAIN1 >= 2.047 || l_nAIN2 >= 2.047) {
				if (C_Index != 8) {
					ui->C10mF->setChecked(true);
					on_C10mF_clicked();
					//					 ui->C100pF->setChecked(true);
					//					 on_C100pF_clicked();
				}
			}
		}
                else if (m_nCapacitance_2 > 0.000909090909999999 && m_nCapacitance_2
				<= 0.010) {
			if (C_Index != 8) {
				ui->C10mF->setChecked(true);
				on_C10mF_clicked();
			}
			if (l_nAIN1 >= 2.048 || l_nAIN2 >= 2.048) {
				//				 ui->C100pF->setChecked(true);
				//				 on_C100pF_clicked();
				dis->setValue("OL");
				ui->Unit->setText("");
			}
		} else if (m_nCapacitance_2 > 0.010) {
			dis->setValue("OL");
			ui->Unit->setText("");
                }*/
    }
}
void ICM::initialiseFeedBackResistance() {
    // Resistance Feedback
    m_lstRFResistance.insert(0, 10.0);
    m_lstRFResistance.insert(1, 100.0);
    m_lstRFResistance.insert(2, 1000.0);
    m_lstRFResistance.insert(3, 10000.0);
    m_lstRFResistance.insert(4, 100000.0);
    m_lstRFResistance.insert(5, 400000);//1000000.0);

    //Inductance Feedback
    m_lstRFInductance.insert(0, 100.0); //30uH
    m_lstRFInductance.insert(1, 100.0); //300uH
    //	m_lstRFInductance.insert(1, 10.0); //300uH
    m_lstRFInductance.insert(2, 100.0); //3mH
    m_lstRFInductance.insert(3, 1000.0); //30mH
    m_lstRFInductance.insert(4, 1000.0); //300mH
    m_lstRFInductance.insert(5, 10000.0); //3H
    m_lstRFInductance.insert(6, 10000.0); //30H

    //Capcitance Feedback
    //	m_lstRFCapcitance.insert(0, 1000000.0);
    //	m_lstRFCapcitance.insert(1, 1000000.0);
    m_lstRFCapcitance.insert(0, 100000.0);
    m_lstRFCapcitance.insert(1, 100000.0);
    m_lstRFCapcitance.insert(2, 100000.0);
    m_lstRFCapcitance.insert(3, 10000.0);
    //	m_lstRFCapcitance.insert(4, 10000.0);//commented on 2ndDec2014
    m_lstRFCapcitance.insert(4, 1000.0);
    m_lstRFCapcitance.insert(5, 1000.0);
    m_lstRFCapcitance.insert(6, 10.0);
    m_lstRFCapcitance.insert(7, 10.0);
    m_lstRFCapcitance.insert(8, 10.0);
}

void ICM::Intialize() {
    //units
    micro = QChar(0x00B5);
    ohms = QChar(0x2126);
    kiloOhms = "K" + ohms;
    picoFarad = "pF";
    nanoFarad = "nF";
    microFarad = micro + "F";
    milliFarad = "mF";
    microHenry = micro + "H";
    milliHenry = "mH";
    Henry = "H";

    //	ui->R->setChecked(true);
    ui->rBut->animateClick(1);
    on_R_clicked();

    R_Index = 0;
    C_Index = 0;
    L_Index = 0;
    ui->R10E->setChecked(true);

    on_OnOffSlider_valueChanged(0);
    autoFlag=true;
    checkPrbStatus=false;

    m_nICMMGR = 0;
    m_nFrequency = 1000;

    calibedSlope = 1.0;
    calibedConstant = 0.0;

    m_mapResistance.insert(0, "30E");
    m_mapResistance.insert(1, "300E");
    m_mapResistance.insert(2, "3KE");
    m_mapResistance.insert(3, "30KE");
    m_mapResistance.insert(4, "300KE");
    m_mapResistance.insert(5, "1ME");

    m_mapCapacitance.insert(0, "100pF");
    m_mapCapacitance.insert(1, "1nF");
    m_mapCapacitance.insert(2, "10nF");
    m_mapCapacitance.insert(3, "100nF");
    m_mapCapacitance.insert(4, "1uF");
    m_mapCapacitance.insert(5, "10uF");
    m_mapCapacitance.insert(6, "100uF");
    m_mapCapacitance.insert(7, "1mF");
    m_mapCapacitance.insert(8, "10mF");

    m_mapInductance.insert(0, "30uH");
    m_mapInductance.insert(1, "300uH");
    m_mapInductance.insert(2, "3mH");
    m_mapInductance.insert(3, "30mH");
    m_mapInductance.insert(4, "300mH");
    m_mapInductance.insert(5, "3H");
    m_mapInductance.insert(6, "30H");

    m_dOffset = 0.0;
    m_dRNull=0.0;m_dLNull=0.0;m_dCNull=0.0;

    for (int i = 0; i < 9; i++) {
        if (i <= 5) {
            avgRValueSh[i] = 0;
            avgRValueOpen[i] = 0;
        }
        if (i <= 6) {
            avgLValueSh[i] = 0;
            avgLValueOpen[i] = 0;
        }
        if (i <= 8) {
            avgCValueSh[i] = 0;
            avgCValueOpen[i] = 0;
        }
    }

    Zdut = 0;

    for (int i = 0; i < 100; i++)
        avgRetval[i] = 0.0;

    avg = 0;
    noOFsamples = 10;


    runFlag=false;
    scanFlag=true;


    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    QStringList stringList;
    bool ok = true;
    QFile textFile;
    /*	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~R~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	textFile.setFileName("icmRShortValues.txt");
	if (textFile.open(QIODevice::ReadOnly)) {
		QTextStream textStream(&textFile);
		while (!textStream.atEnd())
			stringList.append(textStream.readLine());
		for(int i=0;i<6;i++)
			rShortValues[i] = stringList.value(i).toDouble(&ok);
	} else {
		for(int i=0;i<6;i++)
			rShortValues[i] = 0.0;
	}
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~L~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	textFile.setFileName("icmLShortValues.txt");
	if (textFile.open(QIODevice::ReadOnly)) {
		QTextStream textStream(&textFile);
		while (!textStream.atEnd())
			stringList.append(textStream.readLine());
		for(int i=0;i<7;i++)
			lShortValues[i] = stringList.value(i).toDouble(&ok);
	} else {
		for(int i=0;i<7;i++)
			lShortValues[i] = 0.0;
	}
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~C~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	textFile.setFileName("icmCShortValues.txt");
	if (textFile.open(QIODevice::ReadOnly)) {
		QTextStream textStream(&textFile);
		while (!textStream.atEnd())
			stringList.append(textStream.readLine());
		for(int i=0;i<9;i++)
			cShortValues[i] = stringList.value(i).toDouble(&ok);
	} else {
		for(int i=0;i<9;i++)
			cShortValues[i] = 0.0;
	}
        //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
        AutoCFlag=0;
}

ICM::~ICM() {
	delete ui;
}

void ICM::changeEvent(QEvent *e) {
	QMainWindow::changeEvent(e);
	switch (e->type()) {
	case QEvent::LanguageChange:
		ui->retranslateUi(this);
		break;
	default:
		break;
	}
}

void ICM::on_R_clicked() {
//	if (rFlag==true) {
//		ui->ResistanceRanges->setVisible(true);
//		ui->Inductorranges->setVisible(false);
//		ui->CapacitanceRanges->setVisible(false);
//	}
	rFlag=true;lFlag=false;cFlag=false;
	//        on_R10E_clicked();
            ui->ACDC->setEnabled(true);


        IPsoc->srcImpedanceSelection(SRC_IMP_20E);
        ui->label_Rs->setText("20"+ohms);
	//        m_nRange = 300;
	//        ui->R100E->setChecked(true);
	//        on_R100E_clicked();
        //QApplication::processEvents();
}

void ICM::on_L_clicked() {
//	if (lFlag==true) {
//		ui->ResistanceRanges->setVisible(false);
//		ui->Inductorranges->setVisible(true);
//		ui->CapacitanceRanges->setVisible(false);
//	}
	rFlag=false;lFlag=true;cFlag=false;
	on_L30uH_clicked();

	ui->ACDC->setEnabled(false);

	if(m_bRacRdc==false)
		on_RacRdc_clicked();
    //QApplication::processEvents();
}

void ICM::on_C_clicked() {

//	if (cFlag==true) {
//		ui->ResistanceRanges->setVisible(false);
//		ui->Inductorranges->setVisible(false);
//		ui->CapacitanceRanges->setVisible(true);
//	}
	rFlag=false;lFlag=false;cFlag=true;
	on_C100pF_clicked();

	ui->ACDC->setEnabled(false);

	if(m_bRacRdc==false)
		on_RacRdc_clicked();
    //QApplication::processEvents();
}

void ICM::on_OnOffSlider_valueChanged(int value) {
	if (value == 0) {
		if (ADCtimer->isActive()) {
			IAppCard->stopDrive();
			ADCtimer->stop();
		}
	} else {
		IAppCard->startDrive(1);
		ADCtimer->start(300);
		timer.start();
	}
}

//void ICM::on_AutoManualSlider_valueChanged(int value) {
//	if (value == 0) {
//
//	} else {
//	}
//}

void ICM::on_Exit_clicked() {

	hwInterface->Drive(STOPDRIVE);
	IBackPlane->closeObject();
	IPsoc->closeSerial();
	parentWidget()->close();
}

void ICM::on_C100pF_clicked() {
	_100pF++;
	milliSec = timer.elapsed();
	timer.restart();
	//	qDebug()<<"time elapsed to reach 100pF:"<<milliSec<<"milliSeconds"<<"and its iterated "<<_100pF<<"times";

	C_Index = 0;
	m_nICMMGR = m_nICMMGR & 0xFFF8;
	m_nICMMGR |= 4;
	IAppCard->writeRegister(m_nICMMGR, 0x3A);

	IAppCard->writeRegister(0x1, 0x16);
	IPsoc->srcImpedanceSelection(SRC_IMP_10E);

	hwInterface->setFrequency(8000);
	m_nFrequency = 8000;

	//	m_nSweepStartFrequency=m_nSweepEndFrequency=m_nFrequency;
	//ui->sweep_startfreq->setValue(8);
	//ui->sweep_endfreq->setValue(8);
	//ui->sweep_startfreq_unit->setCurrentIndex(1);
	//ui->sweep_endfreq_unit->setCurrentIndex(1);

	m_nRange = 0.0000000001;
	qDebug()<<"100pF Switched";
        //QApplication::processEvents();
}
void ICM::on_C1nF_clicked() {
	_1nF++;
	milliSec = timer.elapsed();
	timer.restart();
	//	qDebug()<<"time elapsed to reach 1nF:"<<milliSec<<"milliSeconds"<<"and its iterated "<<_1nF<<"times";

	C_Index = 1;
	m_nICMMGR = m_nICMMGR & 0xFFF8;
	m_nICMMGR |= 4;
	IAppCard->writeRegister(m_nICMMGR, 0x3A);
	hwInterface->setFrequency(8000);
	m_nFrequency = 8000;

	//	m_nSweepStartFrequency=m_nSweepEndFrequency=m_nFrequency;
	//ui->sweep_startfreq->setValue(8);
	//ui->sweep_endfreq->setValue(8);
	//ui->sweep_startfreq_unit->setCurrentIndex(1);
	//ui->sweep_endfreq_unit->setCurrentIndex(1);

	m_nRange = 0.000000001;
	qDebug()<<"1nF Switched";
        //QApplication::processEvents();
}
void ICM::on_C10nF_clicked() {
	_10nF++;
	milliSec = timer.elapsed();
	timer.restart();
	//	qDebug()<<"time elapsed to reach 10nF:"<<milliSec<<"milliSeconds"<<"and its iterated "<<_10nF<<"times";

	C_Index = 2;
	m_nICMMGR = m_nICMMGR & 0xFFF8;
	m_nICMMGR |= 4;
	IAppCard->writeRegister(m_nICMMGR, 0x3A);
	hwInterface->setFrequency(2400);
	m_nFrequency = 2400;

	//	m_nSweepStartFrequency=m_nSweepEndFrequency=m_nFrequency;
	//ui->sweep_startfreq->setValue(2);
	//ui->sweep_endfreq->setValue(2);
	//ui->sweep_startfreq_unit->setCurrentIndex(1);
	//ui->sweep_endfreq_unit->setCurrentIndex(1);

	m_nRange = 0.00000001;
	qDebug()<<"10nF Switched";
        //QApplication::processEvents();
}
void ICM::on_C100nF_clicked() {
	_100nF++;
	milliSec = timer.elapsed();
	timer.restart();
	//	qDebug()<<"time elapsed to reach 100nF:"<<milliSec<<"milliSeconds"<<"and its iterated "<<_100nF<<"times";

	C_Index = 3;
	m_nICMMGR = m_nICMMGR & 0xFFF8;
	m_nICMMGR |= 3;
	IAppCard->writeRegister(m_nICMMGR, 0x3A);
	hwInterface->setFrequency(2400);
	m_nFrequency = 2400;

	//	m_nSweepStartFrequency=m_nSweepEndFrequency=m_nFrequency;
	//ui->sweep_startfreq->setValue(2);
	//ui->sweep_endfreq->setValue(2);
	//ui->sweep_startfreq_unit->setCurrentIndex(1);
	//ui->sweep_endfreq_unit->setCurrentIndex(1);

	m_nRange = 0.0000001;
	qDebug()<<"100nF Switched";
        //QApplication::processEvents();
}
void ICM::on_C1uF_clicked() {
	_1uF++;
	milliSec = timer.elapsed();
	timer.restart();
	//	qDebug()<<"time elapsed to reach 1uF:"<<milliSec<<"milliSeconds"<<"and its iterated "<<_1uF<<"times";

	C_Index = 4;
	m_nICMMGR = m_nICMMGR & 0xFFF8;
	m_nICMMGR |= 2/*3*/;//commented on 2nDec2014
	IAppCard->writeRegister(m_nICMMGR, 0x3A);
	hwInterface->setFrequency(454);
	m_nFrequency = 454;

	//	m_nSweepStartFrequency=m_nSweepEndFrequency=m_nFrequency;
	//ui->sweep_startfreq->setValue(m_nFrequency);
	//ui->sweep_endfreq->setValue(m_nFrequency);
	//ui->sweep_startfreq_unit->setCurrentIndex(0);
	//ui->sweep_endfreq_unit->setCurrentIndex(0);

	m_nRange = 0.000001;
	qDebug()<<"1uF Switched";
        //QApplication::processEvents();
}
void ICM::on_C10uF_clicked() {
	_10uF++;
	milliSec = timer.elapsed();
	timer.restart();
	//	qDebug()<<"time elapsed to reach 10uF:"<<milliSec<<"milliSeconds"<<"and its iterated "<<_10uF<<"times";

	C_Index = 5;
	m_nICMMGR = m_nICMMGR & 0xFFF8;
	m_nICMMGR |= 2;
	IAppCard->writeRegister(m_nICMMGR, 0x3A);
	hwInterface->setFrequency(454);
	m_nFrequency = 454;

	//	m_nSweepStartFrequency=m_nSweepEndFrequency=m_nFrequency;
	//ui->sweep_startfreq->setValue(m_nFrequency);
	//ui->sweep_endfreq->setValue(m_nFrequency);
	//ui->sweep_startfreq_unit->setCurrentIndex(0);
	//ui->sweep_endfreq_unit->setCurrentIndex(0);

	m_nRange = 0.00001;
	qDebug()<<"10uF Switched";
        //QApplication::processEvents();
}
void ICM::on_C100uF_clicked() {
	_100uF++;
	milliSec = timer.elapsed();
	timer.restart();
	//	qDebug()<<"time elapsed to reach 100uF:"<<milliSec<<"milliSeconds"<<"and its iterated "<<_100uF<<"times";

	C_Index = 6;
	m_nICMMGR = m_nICMMGR & 0xFFF8;
	m_nICMMGR |= 0;
	IAppCard->writeRegister(m_nICMMGR, 0x3A);

	IAppCard->writeRegister(0x1, 0x16);
	IPsoc->srcImpedanceSelection(SRC_IMP_10E);

	hwInterface->setFrequency(2200);
	m_nFrequency = 2200;

	//	m_nSweepStartFrequency=m_nSweepEndFrequency=m_nFrequency;
	//ui->sweep_startfreq->setValue(2);
	//ui->sweep_endfreq->setValue(2);
	//ui->sweep_startfreq_unit->setCurrentIndex(1);
	//ui->sweep_endfreq_unit->setCurrentIndex(1);

	m_nRange = 0.0001;
	qDebug()<<"100uF Switched";
        //QApplication::processEvents();
}
void ICM::on_C1mF_clicked() {
	_1mF++;
	milliSec = timer.elapsed();
	timer.restart();
	//	qDebug()<<"time elapsed to reach 1mF:"<<milliSec<<"milliSeconds"<<"and its iterated "<<_1mF<<"times";

	C_Index = 7;
	m_nICMMGR = m_nICMMGR & 0xFFF8;
	m_nICMMGR |= 0;
	IAppCard->writeRegister(m_nICMMGR, 0x3A);

	IAppCard->writeRegister(0x1, 0x16);
	IPsoc->srcImpedanceSelection(SRC_IMP_10E);

	hwInterface->setFrequency(220);
	m_nFrequency = 220;

	//	m_nSweepStartFrequency=m_nSweepEndFrequency=m_nFrequency;
	//ui->sweep_startfreq->setValue(m_nFrequency);
	//ui->sweep_endfreq->setValue(m_nFrequency);
	//ui->sweep_startfreq_unit->setCurrentIndex(0);
	//ui->sweep_endfreq_unit->setCurrentIndex(0);

	m_nRange = 0.001;
	qDebug()<<"1mF Switched";
        //QApplication::processEvents();
}
void ICM::on_C10mF_clicked() {
	_10mF++;
	milliSec = timer.elapsed();
	timer.restart();
	//	qDebug()<<"time elapsed to reach 10mF:"<<milliSec<<"milliSeconds"<<"and its iterated "<<_10mF<<"times";

	C_Index = 8;
	m_nICMMGR = m_nICMMGR & 0xFFF8;
	m_nICMMGR |= 0;
	IAppCard->writeRegister(m_nICMMGR, 0x3A);

	IAppCard->writeRegister(0x1, 0x16);
	IPsoc->srcImpedanceSelection(SRC_IMP_10E);

	hwInterface->setFrequency(20);
	m_nFrequency = 20;


	//	m_nSweepStartFrequency=m_nSweepEndFrequency=m_nFrequency;
	//ui->sweep_startfreq->setValue(m_nFrequency);
	//ui->sweep_endfreq->setValue(m_nFrequency);
	//ui->sweep_startfreq_unit->setCurrentIndex(0);
	//ui->sweep_endfreq_unit->setCurrentIndex(0);

	m_nRange = 0.01;
	qDebug()<<"10mF Switched";
        //QApplication::processEvents();
}

void ICM::on_R10E_clicked() {
	R_Index = 0;
	m_nICMMGR = m_nICMMGR & 0xFFF8;
	m_nICMMGR |= 0;
	IAppCard->writeRegister(m_nICMMGR, 0x3A);
	IAppCard->writeRegister(0x1, 0x16);
	//	IBackPlane->writeBackPlaneRegister(0x1, 0x26);
	//    IPsoc->srcImpedanceSelection(SRC_IMP_20E);
	//	//qDebug()<<"Range:"<<m_mapResistance.value(R_Index)<<"m_nICMMGR:"<<m_nICMMGR<<"Frequency:"<<m_nFrequency<<"Feedback:"<<m_lstRFResistance.value(R_Index);
	hwInterface->setFrequency(1000);
	m_nFrequency = 1000;

	//	m_nSweepStartFrequency=m_nSweepEndFrequency=m_nFrequency;
	//ui->sweep_startfreq->setValue(1);
	//ui->sweep_endfreq->setValue(1);
	//ui->sweep_startfreq_unit->setCurrentIndex(1);
	//ui->sweep_endfreq_unit->setCurrentIndex(1);

	m_nRange=30;
	//        showMessageBox(true,false,"10E Switched");
	qDebug()<<"10E Switched";
        //QApplication::processEvents();
	usleep(config_delay);
}
void ICM::on_R100E_clicked() {
	R_Index = 1;
	m_nICMMGR = m_nICMMGR & 0xFFF8;
	m_nICMMGR |= 1;
	IAppCard->writeRegister(m_nICMMGR, 0x3A);
	IAppCard->writeRegister(0x1, 0x16);//changed to 0x1 on 12062014
	//	IBackPlane->writeBackPlaneRegister(0x1, 0x26);
	//    IPsoc->srcImpedanceSelection(SRC_IMP_20E);
	//	//qDebug()<<"Range:"<<m_mapResistance.value(R_Index)<<"m_nICMMGR:"<<m_nICMMGR<<"Frequency:"<<m_nFrequency<<"Feedback:"<<m_lstRFResistance.value(R_Index);
	hwInterface->setFrequency(1000);
	m_nFrequency = 1000;

	//	m_nSweepStartFrequency=m_nSweepEndFrequency=m_nFrequency;
	//ui->sweep_startfreq->setValue(1);
	//ui->sweep_endfreq->setValue(1);
	//ui->sweep_startfreq_unit->setCurrentIndex(1);
	//ui->sweep_endfreq_unit->setCurrentIndex(1);

	m_nRange=300;
	//        showMessageBox(true,false,"300E Switched");
	qDebug()<<"300E Switched";
        //QApplication::processEvents();
	usleep(config_delay);
    }
void ICM::on_R1KE_clicked() {
    R_Index = 2;
    m_nICMMGR = m_nICMMGR & 0xFFF8;
    m_nICMMGR |= 2;
    IAppCard->writeRegister(m_nICMMGR, 0x3A);

    IAppCard->writeRegister(0x1, 0x16); //changed to 0x1 on 12062014
    //	IBackPlane->writeBackPlaneRegister(0x1, 0x26);
    //    IPsoc->srcImpedanceSelection(SRC_IMP_20E);
    //qDebug()<<"Range:"<<m_mapResistance.value(R_Index)<<"m_nICMMGR:"<<m_nICMMGR<<"Frequency:"<<m_nFrequency<<"Feedback:"<<m_lstRFResistance.value(R_Index);
    hwInterface->setFrequency(1000);
    m_nFrequency = 1000;

    //	m_nSweepStartFrequency=m_nSweepEndFrequency=m_nFrequency;
    //ui->sweep_startfreq->setValue(1);
    //ui->sweep_endfreq->setValue(1);
    //ui->sweep_startfreq_unit->setCurrentIndex(1);
    //ui->sweep_endfreq_unit->setCurrentIndex(1);

    m_nRange=3000;
    //        showMessageBox(true,false,"3KE Switched");
    qDebug()<<"3KE Switched";
    //QApplication::processEvents();
    usleep(config_delay);
}
void ICM::on_R10KE_clicked() {
    R_Index = 3;
    m_nICMMGR = m_nICMMGR & 0xFFF8;
    m_nICMMGR |= 3;
    IAppCard->writeRegister(m_nICMMGR, 0x3A);

    IAppCard->writeRegister(0x1, 0x16);//changed to 0x1 on 12062014
    //	IBackPlane->writeBackPlaneRegister(0x1, 0x26);
    //    IPsoc->srcImpedanceSelection(SRC_IMP_20E);
    //qDebug()<<"Range:"<<m_mapResistance.value(R_Index)<<"m_nICMMGR:"<<m_nICMMGR<<"Frequency:"<<m_nFrequency<<"Feedback:"<<m_lstRFResistance.value(R_Index);
    hwInterface->setFrequency(1000);
    m_nFrequency = 1000;

    //	m_nSweepStartFrequency=m_nSweepEndFrequency=m_nFrequency;
    //ui->sweep_startfreq->setValue(1);
    //ui->sweep_endfreq->setValue(1);
    //ui->sweep_startfreq_unit->setCurrentIndex(1);
    //ui->sweep_endfreq_unit->setCurrentIndex(1);

    m_nRange=30000;
    //        showMessageBox(true,false,"30KE Switched");
    qDebug()<<"30KE Switched";
    //QApplication::processEvents();
    usleep(config_delay);

}
void ICM::on_R100KE_clicked() {
    R_Index = 4;
    m_nICMMGR = m_nICMMGR & 0xFFF8;
    m_nICMMGR |= 4;
    IAppCard->writeRegister(m_nICMMGR, 0x3A);

    IAppCard->writeRegister(0x1, 0x16);//changed to 0x01 on 12062014
    //	IBackPlane->writeBackPlaneRegister(0x1, 0x26);
    //    IPsoc->srcImpedanceSelection(SRC_IMP_20E);
    //qDebug()<<"Range:"<<m_mapResistance.value(R_Index)<<"m_nICMMGR:"<<m_nICMMGR<<"Frequency:"<<m_nFrequency<<"Feedback:"<<m_lstRFResistance.value(R_Index);
    hwInterface->setFrequency(1000);
    m_nFrequency = 1000;

    //	m_nSweepStartFrequency=m_nSweepEndFrequency=m_nFrequency;
    //ui->sweep_startfreq->setValue(1);
    //ui->sweep_endfreq->setValue(1);
    //ui->sweep_startfreq_unit->setCurrentIndex(1);
    //ui->sweep_endfreq_unit->setCurrentIndex(1);

    m_nRange=300000;
    //        showMessageBox(true,false,"300KE Switched");
    qDebug()<<"300KE Switched";
    //QApplication::processEvents();
    usleep(config_delay);
}
void ICM::on_R1ME_clicked() {
    R_Index = 5;
    m_nICMMGR = m_nICMMGR & 0xFFF8;
    m_nICMMGR |= 5;
    IAppCard->writeRegister(m_nICMMGR, 0x3A);

    IAppCard->writeRegister(0x1, 0x16);//changed to 0x1 on 12062014
    //	IBackPlane->writeBackPlaneRegister(0x1, 0x26);
    //    IPsoc->srcImpedanceSelection(SRC_IMP_20E);
    //qDebug()<<"Range:"<<m_mapResistance.value(R_Index)<<"m_nICMMGR:"<<m_nICMMGR<<"Frequency:"<<m_nFrequency<<"Feedback:"<<m_lstRFResistance.value(R_Index);
    hwInterface->setFrequency(1000);
    m_nFrequency = 1000;

    //	m_nSweepStartFrequency=m_nSweepEndFrequency=m_nFrequency;
    //ui->sweep_startfreq->setValue(1);
    //ui->sweep_endfreq->setValue(1);
    //ui->sweep_startfreq_unit->setCurrentIndex(1);
    //ui->sweep_endfreq_unit->setCurrentIndex(1);

    m_nRange=1000000;
    //        showMessageBox(true,false,"1ME Switched");
    qDebug()<<"1ME Switched";
    //QApplication::processEvents();
    usleep(config_delay);
}

void ICM::on_L30uH_clicked() {
    L_Index = 0;
    m_nICMMGR = m_nICMMGR & 0xFFF8;
    m_nICMMGR |= 1;
    IAppCard->writeRegister(m_nICMMGR, 0x3A);
    hwInterface->setFrequency(200000);
    m_nFrequency = 200000;//50000

    IAppCard->writeRegister(0x1, 0x16);//changed to 0x1 on 12062014
    //	IBackPlane->writeBackPlaneRegister(0x3, 0x26);
    IPsoc->srcImpedanceSelection(SRC_IMP_100E);
    ui->label_Rs->setText("100"+ohms);
    //	m_nSweepStartFrequency=m_nSweepEndFrequency=m_nFrequency;
    //ui->sweep_startfreq->setValue(200);
    //ui->sweep_endfreq->setValue(200);
    //ui->sweep_startfreq_unit->setCurrentIndex(1);
    //ui->sweep_endfreq_unit->setCurrentIndex(1);

    m_nRange = 0.00003;
    qDebug()<<"30uH Switched";
    //QApplication::processEvents();

}
void ICM::on_L300uH_clicked() {
    /*	L_Index = 1;
        m_nICMMGR = m_nICMMGR & 0xFFF8;
        m_nICMMGR |= 0;//changed
        IAppCard->writeRegister(m_nICMMGR, 0x3A);
        hwInterface->setFrequency(7812);
        //	m_nFrequency=390625;
        m_nFrequency = 7812;

        IAppCard->writeRegister(1, 0x16);*/
    L_Index = 1;
    m_nICMMGR = m_nICMMGR & 0xFFF8;
    m_nICMMGR |= 1;
    IAppCard->writeRegister(m_nICMMGR, 0x3A);
    m_nFrequency = 155000;//160000;//150000;//200000;//50000
    hwInterface->setFrequency(m_nFrequency);
    IAppCard->writeRegister(0x1, 0x16);//changed to 0x1 on 12062014
    //	IBackPlane->writeBackPlaneRegister(0x3, 0x26);
    IPsoc->srcImpedanceSelection(SRC_IMP_100E);
    ui->label_Rs->setText("100"+ohms);
    //	m_nSweepStartFrequency=m_nSweepEndFrequency=m_nFrequency;
    //ui->sweep_startfreq->setValue(200);
    //ui->sweep_startfreq_unit->setCurrentIndex(1);
    //ui->sweep_endfreq->setValue(200);
    //ui->sweep_endfreq_unit->setCurrentIndex(1);

    m_nRange = 0.0003;
    qDebug()<<"300uH Switched";
    //QApplication::processEvents();
}
void ICM::on_L3mH_clicked() {
    L_Index = 2;
    m_nICMMGR = m_nICMMGR & 0xFFF8;
    m_nICMMGR |= 1;//changed
    IAppCard->writeRegister(m_nICMMGR, 0x3A);
    //	m_nFrequency=390625;
    m_nFrequency = 2500;
    hwInterface->setFrequency(m_nFrequency);
    IAppCard->writeRegister(0x1, 0x16);
    IPsoc->srcImpedanceSelection(SRC_IMP_0E);//added for 0E Selection
    ui->label_Rs->setText("0"+ohms);
    //	m_nSweepStartFrequency=m_nSweepEndFrequency=m_nFrequency;
    //ui->sweep_startfreq->setValue(2);
    //ui->sweep_endfreq->setValue(2);
    //ui->sweep_startfreq_unit->setCurrentIndex(1);
    //ui->sweep_endfreq_unit->setCurrentIndex(1);

    m_nRange = 	0.003;
    qDebug()<<"3mH Switched";
    //QApplication::processEvents();
}
void ICM::on_L30mH_clicked() {
    L_Index = 3;
    m_nICMMGR = m_nICMMGR & 0xFFF8;
    m_nICMMGR |= 2;//changed
    IAppCard->writeRegister(m_nICMMGR, 0x3A);
    hwInterface->setFrequency(1200);
    m_nFrequency = 1200;

    IAppCard->writeRegister(0x1, 0x16);//changed to 0x1 on 12062014
    //	IBackPlane->writeBackPlaneRegister(0x4, 0x26);
    IPsoc->srcImpedanceSelection(SRC_IMP_200E);
    ui->label_Rs->setText("200"+ohms);

    //	m_nSweepStartFrequency=m_nSweepEndFrequency=m_nFrequency;
    //ui->sweep_startfreq->setValue(1);
    //ui->sweep_endfreq->setValue(1);
    //ui->sweep_startfreq_unit->setCurrentIndex(1);
    //ui->sweep_endfreq_unit->setCurrentIndex(1);

    m_nRange = 0.03;
    qDebug()<<"30mH Switched";
    //QApplication::processEvents();
}
void ICM::on_L300mH_clicked() {
    L_Index = 4;
    m_nICMMGR = m_nICMMGR & 0xFFF8;
    m_nICMMGR |= 2;
    IAppCard->writeRegister(m_nICMMGR, 0x3A);
    hwInterface->setFrequency(120);
    m_nFrequency = 120; // Prev.Value : 1000
    //changed D.Elangovan 1-sep-2013 as per Anbu feedback
    IAppCard->writeRegister(0x1, 0x16);//changed to 0x1 on 12062014
    //	IBackPlane->writeBackPlaneRegister(0x4, 0x26);
    IPsoc->srcImpedanceSelection(SRC_IMP_200E);
    ui->label_Rs->setText("200"+ohms);

    //	m_nSweepStartFrequency=m_nSweepEndFrequency=m_nFrequency;
    //ui->sweep_startfreq->setValue(m_nFrequency);
    //ui->sweep_endfreq->setValue(m_nFrequency);
    //ui->sweep_startfreq_unit->setCurrentIndex(0);
    //ui->sweep_endfreq_unit->setCurrentIndex(0);

    m_nRange = 0.3;
    qDebug()<<"300mH Switched";
    //QApplication::processEvents();
}
void ICM::on_L3H_clicked() {
    L_Index = 5;
    m_nICMMGR = m_nICMMGR & 0xFFF8;
    m_nICMMGR |= 3;
    IAppCard->writeRegister(m_nICMMGR, 0x3A);
    hwInterface->setFrequency(120);
    m_nFrequency = 120;

    IAppCard->writeRegister(0x1, 0x16);//changed to 0x1 on 12062014
    //	IBackPlane->writeBackPlaneRegister(0x6, 0x26);
    IPsoc->srcImpedanceSelection(SRC_IMP_1KE);
    ui->label_Rs->setText("1K"+ohms);

    //	m_nSweepStartFrequency=m_nSweepEndFrequency=m_nFrequency;
    //ui->sweep_startfreq->setValue(m_nFrequency);
    //ui->sweep_endfreq->setValue(m_nFrequency);
    //ui->sweep_startfreq_unit->setCurrentIndex(0);
    //ui->sweep_endfreq_unit->setCurrentIndex(0);

    m_nRange = 3;
    qDebug()<<"3H Switched";
    //QApplication::processEvents();
}
void ICM::on_L30H_clicked() {
    L_Index = 6;
    m_nICMMGR = m_nICMMGR & 0xFFF8;
    m_nICMMGR |= 3;
    IAppCard->writeRegister(m_nICMMGR, 0x3A);
    hwInterface->setFrequency(20);
    m_nFrequency = 20;//changed from 120 to 20 on 04122014

    IAppCard->writeRegister(0x1, 0x16);//changed to 0x1 on 12062014
    //	IBackPlane->writeBackPlaneRegister(0x6, 0x26);
    IPsoc->srcImpedanceSelection(SRC_IMP_1KE);
    ui->label_Rs->setText("1K"+ohms);

    //	m_nSweepStartFrequency=m_nSweepEndFrequency=m_nFrequency;
    //ui->sweep_startfreq->setValue(m_nFrequency);
    //ui->sweep_endfreq->setValue(m_nFrequency);
    //ui->sweep_startfreq_unit->setCurrentIndex(0);
    //ui->sweep_endfreq_unit->setCurrentIndex(0);

    m_nRange = 30;
    qDebug()<<"30H Switched";
    //QApplication::processEvents();
}
void ICM::shortCalibration(){
    bool prevAutoState = false;
    bool prevRunState=false;
    int prevComp = 0;
    for(int i=0;i<6;i++)            rShortValues[i]=0.0;
    for(int i=0;i<7;i++)            lShortValues[i]=0.0;
    for(int i=0;i<9;i++)            cShortValues[i]=0.0;

    bool retR = showMessageBox(true, true, "Short the probes and press OK.","OK", "Cancel");
    if(retR == true){
        if(runFlag == true) {ui->ONOFF->animateClick(1);prevRunState=true;}
        if(autoFlag == true) { ui->AutoManual->animateClick(1); prevAutoState =true; }
        if(rFlag == true) prevComp = 0;
        if(lFlag == true) prevComp = 1;
        if(cFlag == true) prevComp = 2;

        qDebug()<<"**********************************************************";
        on_rBut_clicked();
        sleep(1);

        on_R10E_clicked();      rShortValues[0] = readADCR("30E");

        on_R100E_clicked();     rShortValues[1] = readADCR("300E");

        on_R1KE_clicked();      rShortValues[2] = readADCR("3KE");

        on_R10KE_clicked();     rShortValues[3] = readADCR("30KE");

        on_R100KE_clicked();    rShortValues[4] = readADCR("300KE");

        on_R1ME_clicked();      rShortValues[5] = readADCR("1ME");

        /*		on_R10E_clicked();
		for(int i=0;i<5;i++){
			rShortValues[0] = readADCR("30E");
			qDebug()<<"Short Value for "<<m_mapResistance[0]<<":"<<rShortValues[0];
		}
                sleep(1);

		on_R100E_clicked();
		for(int i=0;i<10;i++){
			rShortValues[1] = readADCR("300E");
			qDebug()<<"Short Value for "<<m_mapResistance[1]<<":"<<rShortValues[1];
			sleep(1);
		}
		sleep(1);

                on_R1KE_clicked();
		for(int i=0;i<5;i++){
			rShortValues[2] = readADCR("3KE");
			qDebug()<<"Short Value for "<<m_mapResistance[2]<<":"<<rShortValues[2];
		}
		sleep(1);

		on_R10KE_clicked();
		for(int i=0;i<5;i++){
			rShortValues[3] = readADCR("30KE");
			qDebug()<<"Short Value for "<<m_mapResistance[3]<<":"<<rShortValues[3];
		}
		sleep(1);

		on_R100KE_clicked();
		for(int i=0;i<5;i++){
			rShortValues[4] = readADCR("300KE");
			qDebug()<<"Short Value for "<<m_mapResistance[4]<<":"<<rShortValues[4];
		}
		sleep(1);

		on_R1ME_clicked();
		for(int i=0;i<5;i++){
			rShortValues[5] = readADCR("1ME");
			qDebug()<<"Short Value for "<<m_mapResistance[5]<<":"<<rShortValues[5];
		}
		sleep(1);*/

        QFile outFileR;
        outFileR.setFileName("icmRShortValues.txt");
        outFileR.open(QIODevice::WriteOnly);
        QTextStream tsR(&outFileR);
        for(int i=0;i<6;i++){
            tsR << rShortValues[i] << endl;
        }

        bool retL = showMessageBox(true, true, "Short calibration for Resistance is done.\nPress OK for Inductance.","OK", "Cancel");

        if(retL ==true ){
            qDebug()<<"**********************************************************";
            /*			on_lBut_clicked();
			sleep(1);

                        lShortValues[0]=readADCL("30uH");
                        sleep(1);

                        on_L300uH_clicked();
                        sleep(1);
                        lShortValues[1]=readADCL("300uH");
                        sleep(1);

                        on_L3mH_clicked();
                        sleep(1);
                        lShortValues[2]=readADCL("3mH");
                        sleep(1);

                        on_L30mH_clicked();
                        sleep(1);
                        lShortValues[3]=readADCL("30mH");
                        sleep(1);

                        on_L300mH_clicked();
                        sleep(1);
                        lShortValues[4]=readADCL("300mH");
                        sleep(1);

                        on_L3H_clicked();
                        sleep(1);
                        lShortValues[5]=readADCL("3H");
                        sleep(1);

                        on_L30H_clicked();
                        sleep(1);
                        lShortValues[6]=readADCL("30H");
                        sleep(1);

			QFile outFileL;
			outFileL.setFileName("icmLShortValues.txt");
			outFileL.open(QIODevice::WriteOnly);
			QTextStream tsL(&outFileL);
			for(int i=0;i<7;i++)
				tsL << lShortValues[i] << endl;

                        bool retC = showMessageBox(true, true, "Short calibration for Inductance is done.\nPress OK for Capacitance.","OK", "Cancel");

			if(retC == true){
                                qDebug()<<"**********************************************************";
				on_cBut_clicked();
				sleep(1);

                                cShortValues[0]=readADCC("100pF");
                                sleep(1);

                                on_C1nF_clicked();
                                sleep(1);
                                cShortValues[1]=readADCC("1nF");
                                sleep(1);

                                on_C10nF_clicked();
                                sleep(1);
                                cShortValues[2]=readADCC("10nF");
                                sleep(1);

                                on_C100nF_clicked();
                                sleep(1);
                                cShortValues[3]=readADCC("100nF");
                                sleep(1);

                                on_C1uF_clicked();
                                sleep(1);
                                cShortValues[4]=readADCC("1uF");
                                sleep(1);

                                on_C10uF_clicked();
                                sleep(1);
                                cShortValues[5]=readADCC("10uF");
                                sleep(1);

                                on_C100uF_clicked();
                                sleep(1);
                                cShortValues[6]=readADCC("100uF");
                                sleep(1);

                                on_C1mF_clicked();
                                sleep(1);
                                cShortValues[7]=readADCC("1mF");
                                sleep(1);

                                on_C10mF_clicked();
                                sleep(1);
                                cShortValues[8]=readADCC("10mF");
                                sleep(1);

				QFile outFileC;
				outFileC.setFileName("icmCShortValues.txt");
				outFileC.open(QIODevice::WriteOnly);
				QTextStream tsC(&outFileC);
				for(int i=0;i<9;i++)
					tsC << cShortValues[i] << endl;
			}
		}
                bool exit = showMessageBox(true, false, "Short calibration for Capacitance is done.\nPress OK to Exit","OK","Cancel");
		if(exit ==true){
                        qDebug()<<"**********************************************************";*/
            if(prevRunState==true)
                ui->ONOFF->animateClick(1);
            if(prevAutoState == true )
                ui->AutoManual->animateClick(1);

            if(prevComp == 0)       on_rBut_clicked();
            else if(prevComp == 1)  on_lBut_clicked();
            else if(prevComp ==2)   on_cBut_clicked();
        }
    }
    else
        showMessageBox(true, false, "Short calibration Aborted.","OK","Cancel");

}

void ICM::advSettings(){

    int retryloop=0;
    do{
        loginDialog->exec();
        retryloop++;
        if(retryloop==3){
            break;
        }
    }while(!m_nPassword);

    if(m_nPassword==false/* && retryloop!=3*/){
        obj = new Settings(IPsoc, hwInterface, IAppCard, m_objAD7190Component,this);
        //	obj->setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);
        obj->setWindowFlags(Qt::Dialog);
        obj->setStyleSheet(
                "border:3px solid #45596f; border-style: groove; background-color:qlineargradient(x1:0, y1:0, x2:0, y2:1,stop:0 lightgray, stop:1 darkgray);");
        obj->setGeometry(150,115,525,425);
        //    QPropertyAnimation *animation = new QPropertyAnimation(obj, "geometry");
        //    animation->setDuration(10000);
        //    animation->setStartValue(QRect(150, 350, 525, 50));
        //    animation->setEndValue(QRect(150, 115, 525, 404));
        //    animation->setEasingCurve(QEasingCurve::Linear);
        //    animation->setDuration(300);
        //    animation->start();
        obj->show();
    }
}

void ICM::on_settings_clicked() {
    //    if(panelStatus.dPanel==true){
    //        advSettings();
    //    }else{
    setWidget->show();
    //    }
}

void ICM::on_ONOFF_clicked() {
    if(!scanFlag)scanFlag=true;
    //	if (ui->OnOffSlider->value() == 1) {
    if(runFlag==false){
        ui->ONOFF->setIcon(QIcon(QPixmap(":/Symbols/Button-Play-icon.png")));
        ui->holdCap->setVisible(false);
        //		ui->OnOffSlider->setValue(0);
        on_OnOffSlider_valueChanged(1);
        IGPIOPin->illuminateRunStopButton(0);
        dis->setValue("OL");
        ui->Unit->setText("");
        runFlag=true;
    }else if(runFlag==true){
        //	} else if (ui->OnOffSlider->value() == 0) {
        ui->ONOFF->setIcon(QIcon(QPixmap(":/Symbols/Button-Stop-icon.png")));
        ui->holdCap->setVisible(true);
        //		ui->OnOffSlider->setValue(1);
        on_OnOffSlider_valueChanged(0);
        IGPIOPin->illuminateRunStopButton(1);
        runFlag=false;
    }
    //	}

}
void ICM::CalibrateDisplay(QString comp) {
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    QString l_strFileName;
    l_strFileName = "ICMCalibration.xml";
    //		 qDebug()<<l_strFileName;

    QString m_strTypeIndex;
    if (rFlag==true)
        m_strTypeIndex = m_mapResistance.value(R_Index);
    if (lFlag==true)
        m_strTypeIndex = m_mapInductance.value(L_Index);
    if (cFlag==true)
        m_strTypeIndex = m_mapCapacitance.value(C_Index);

    QFile *xmlFile = new QFile(l_strFileName);
    if (!xmlFile->open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "file read error";
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
        qDebug() << "xmlFile.xml Parse Error";
    xml.clear();
    xmlFile->close();

    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    //qDebug()<<"Calibrated "<<comp<<"Slope :"<<calibedSlope<<"Constant :"<<calibedConstant;
}

void ICM::GetDisplayResistance(double pResistanceValue, double pRangeValue) {
    pResistanceValue = pResistanceValue + m_dOffset;

    //qDebug()<<"Resistance:"<<pResistanceValue<<"Range:"<<pRangeValue;
    if (ui->calibrateDisplay->isChecked()) {
        CalibrateDisplay("ICM-R");

        double y, x, c, m;
        x = pResistanceValue;
        c = calibedConstant;
        m = calibedSlope;

        y = (x - c) / m;

        pResistanceValue = y;
        cbdR=y;
    }
    if (m_bNull == true) {
        pResistanceValue =pResistanceValue - m_dRNull;
    }

    m_nResistance_2 = pResistanceValue;

    if (autoFlag == true){
        AutoRangeR();
    }

    if (ui->checkBox->isChecked()) {
        if (ui->chkLoad->isChecked())
            Zdut = (((avgRValueSh[R_Index] - pResistanceValue) * (Measured
                                                                  - avgRValueOpen[R_Index])) / ((pResistanceValue
                                                                                                 - avgRValueOpen[R_Index]) * (avgRValueSh[R_Index]
                                                                                                                              - Measured))) * Actual;
        else
            Zdut = ((avgRValueSh[R_Index] - pResistanceValue)
                    / (pResistanceValue - avgRValueOpen[R_Index]))
                   * (avgRValueOpen[R_Index]);

        pResistanceValue = Zdut;
    }
    //	QString l_strResistanceValue("");
    /*if(pResistanceValue <1000.0)
         {
         if(pRangeValue == 10.0 || pRangeValue==10000.0)
         {
         l_strResistanceValue = QString::number(pResistanceValue,'f',2) + ohms;
         }
         else if(pRangeValue == 100.0 || pRangeValue==100000.0)
         {
         l_strResistanceValue = QString::number(pResistanceValue,'f',1) + ohms;
         }
         else
         {
         l_strResistanceValue = QString::number(pResistanceValue,'f',3) + ohms;
         }
         }
         else if(pResistanceValue >=1000.0 && pResistanceValue<1000000)
         {
         if(pRangeValue == 1000.0 || pRangeValue==1000000.0)
         {
         l_strResistanceValue = QString::number((pResistanceValue/1000.0),'f',3) + kiloOhms;
         }
         else if(pRangeValue == 10000.0 || pRangeValue==10.0)
         {
         l_strResistanceValue = QString::number((pResistanceValue/1000.0),'f',2) + kiloOhms;
         }
         else if(pRangeValue == 100000.0 || pRangeValue==100.0)
         {
         l_strResistanceValue = QString::number((pResistanceValue/1000.0),'f',1) + kiloOhms;
         }
         }
         else if(pResistanceValue >= 1000000.0 )
         {
         l_strResistanceValue = QString::number((pResistanceValue/1000000.0),'f',3) + "M"+ohms;

         }

         ui->display->setText(l_strResistanceValue);*/
    //	dis->setValue(convertToUnits(pResistanceValue));

    //Passing Range to display class~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    bool ok=true;
    QString str_value = convertToUnits(pResistanceValue);
    QString str_range = ui->rangeLabel->text();
    double dbl_value;int int_range;

    if(ui->rangeLabel->text().endsWith("KE") || ui->rangeLabel->text().endsWith("ME")){
        str_range.chop(2);
        dbl_value=str_value.toDouble(&ok);
        if(dbl_value>=0 && dbl_value<9.9)
            int_range=9;
        else if(dbl_value>=10 && dbl_value<99.9)
            int_range=99;
        else if(dbl_value>=100 && dbl_value<999.9)
            int_range=999;
    }
    else if(ui->rangeLabel->text().endsWith("E")){
        str_range.chop(1);
        dbl_value=str_value.toDouble(&ok);
        int_range=str_range.toInt(&ok,10);
    }

    dis->setRange(int_range);
    dis->setValue(dbl_value);
    ui->scrDisplay->setText(QString::number(dbl_value));
    if(dbl_value<12000000)
        InsertGraphData(dbl_value);

    qDebug()<<"strRange:"<<str_range<<"str_value:"<<str_value;
    qDebug()<<"intRange:"<<int_range<<"dbl_value:"<<dbl_value;
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
}

void ICM::GetDisplayCapcitance(double p_nData, short int p_nRange) {
    p_nData = p_nData + m_dOffset;

    //qDebug()<<fixed<<"Capacitance:"<<p_nData<<"Range:"<<p_nRange;

    if (ui->calibrateDisplay->isChecked()) {
        CalibrateDisplay("ICM-C");

        double y, x, c, m;
        x = p_nData;
        c = calibedConstant;
        m = calibedSlope;

        y = (x - c) / m;

        p_nData = y;
        cbdC=y;

    }
    if (m_bNull == true) {
        p_nData = p_nData - m_dCNull;
    }
    m_nCapacitance_2 = p_nData;

    if (autoFlag==true)
        AutoRangeC1();
    //		AutoRange();

    //	if (ui->checkBox->isChecked()) {
    //		if (ui->chkLoad->isChecked())
    //			Zdut = (((avgCValueSh[C_Index] - p_nData) * (Measured
    //					- avgCValueOpen[C_Index])) / ((p_nData
    //							- avgCValueOpen[C_Index]) * (avgCValueSh[C_Index]
    //							                                         - Measured))) * Actual;
    //		else
    //			Zdut = ((avgCValueSh[C_Index] - p_nData) / (p_nData
    //					- avgCValueOpen[C_Index])) * (avgCValueOpen[C_Index]);
    //		p_nData = Zdut;
    //		//            qDebug()<<"Zdut Value :"<<Zdut;
    //	}
    /*	QString l_sDisplayData("");

	if (p_nRange == 0) {
		p_nData = p_nData * 1000000000000.0;

		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		//		double d = ( (double) ( (int) (p_nData * 100.0) ) ) / 100.0 ;
		//		capSamples[capInc]=d; qDebug()<<"capSamples["<<capInc<<"]"<<capSamples[capInc];		if(capInc<9)capInc++;else capInc=0;
		//		if(capSamples[0]==capSamples[1])if(capSamples[1]==capSamples[2])if(capSamples[2]==capSamples[3])
		//		if(capSamples[3]==capSamples[4])if(capSamples[4]==capSamples[5])if(capSamples[5]==capSamples[6])
		//		if(capSamples[6]==capSamples[7])if(capSamples[7]==capSamples[8])if(capSamples[8]==capSamples[9])
		//		qDebug()<<"Last 10 samples are constant";
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

		l_sDisplayData = QString::number((p_nData), 'f', 2);// + picoFarad;
		ui->Unit->setText(picoFarad);
		//		dis->setValue(l_sDisplayData);


	} else if (p_nRange == 1) {
		if ((p_nData * 1000000000) >= 1) {
			p_nData = p_nData * 1000000000.0;
			l_sDisplayData = QString::number((p_nData), 'f', 2);// + nanoFarad;
			ui->Unit->setText(nanoFarad);
			dis->setValue(l_sDisplayData);
		} else if ((p_nData * 1000000000000) >= 1) {
			p_nData = p_nData * 1000000000000.0;
			l_sDisplayData = QString::number((p_nData), 'f', 2);// + picoFarad;
			ui->Unit->setText(picoFarad);
			//			dis->setValue(l_sDisplayData);

		}
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		//		double d = ( (double) ( (int) (p_nData * 100.0) ) ) / 100.0 ;
		//		capSamples[capInc]=d; qDebug()<<"capSamples["<<capInc<<"]"<<capSamples[capInc];		if(capInc<9)capInc++;else capInc=0;
		//		if(capSamples[0]==capSamples[1])if(capSamples[1]==capSamples[2])if(capSamples[2]==capSamples[3])
		//		if(capSamples[3]==capSamples[4])if(capSamples[4]==capSamples[5])if(capSamples[5]==capSamples[6])
		//		if(capSamples[6]==capSamples[7])if(capSamples[7]==capSamples[8])if(capSamples[8]==capSamples[9])
		//		qDebug()<<"Last 10 samples are constant";
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


	} else if (p_nRange == 2) {
		p_nData = p_nData * 1000000000.0;
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		//		double d = ( (double) ( (int) (p_nData * 100.0) ) ) / 100.0 ;
		//		capSamples[capInc]=d; qDebug()<<"capSamples["<<capInc<<"]"<<capSamples[capInc];		if(capInc<9)capInc++;else capInc=0;
		//		if(capSamples[0]==capSamples[1])if(capSamples[1]==capSamples[2])if(capSamples[2]==capSamples[3])
		//		if(capSamples[3]==capSamples[4])if(capSamples[4]==capSamples[5])if(capSamples[5]==capSamples[6])
		//		if(capSamples[6]==capSamples[7])if(capSamples[7]==capSamples[8])if(capSamples[8]==capSamples[9])
		//		qDebug()<<"Last 10 samples are constant";
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		l_sDisplayData = QString::number((p_nData), 'f', 2);// + nanoFarad;
		ui->Unit->setText(nanoFarad);
		//		dis->setValue(l_sDisplayData);

	}
         else if (p_nRange == 3)
         {
         p_nData = p_nData * 1000000000.0;
         //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
         //		double d = ( (double) ( (int) (p_nData * 100.0) ) ) / 100.0 ;
         //		capSamples[capInc]=d; qDebug()<<"capSamples["<<capInc<<"]"<<capSamples[capInc];		if(capInc<9)capInc++;else capInc=0;
         //		if(capSamples[0]==capSamples[1])if(capSamples[1]==capSamples[2])if(capSamples[2]==capSamples[3])
         //		if(capSamples[3]==capSamples[4])if(capSamples[4]==capSamples[5])if(capSamples[5]==capSamples[6])
         //		if(capSamples[6]==capSamples[7])if(capSamples[7]==capSamples[8])if(capSamples[8]==capSamples[9])
         //		qDebug()<<"Last 10 samples are constant";
         //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
         l_sDisplayData = QString::number((p_nData),'f',2) + nanoFarad;
         }
         else if (p_nRange == 4)
         {
         p_nData = p_nData * 1000000000.0;
         //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
         //		double d = ( (double) ( (int) (p_nData * 100.0) ) ) / 100.0 ;
         //		capSamples[capInc]=d; qDebug()<<"capSamples["<<capInc<<"]"<<capSamples[capInc];		if(capInc<9)capInc++;else capInc=0;
         //		if(capSamples[0]==capSamples[1])if(capSamples[1]==capSamples[2])if(capSamples[2]==capSamples[3])
         //		if(capSamples[3]==capSamples[4])if(capSamples[4]==capSamples[5])if(capSamples[5]==capSamples[6])
         //		if(capSamples[6]==capSamples[7])if(capSamples[7]==capSamples[8])if(capSamples[8]==capSamples[9])
         //		qDebug()<<"Last 10 samples are constant";
         //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
         l_sDisplayData = QString::number((p_nData),'f',2) + nanoFarad;
         }
         else if (p_nRange == 5)
         {
         p_nData = p_nData * 1000000.0;
         //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
         //		double d = ( (double) ( (int) (p_nData * 100.0) ) ) / 100.0 ;
         //		capSamples[capInc]=d; qDebug()<<"capSamples["<<capInc<<"]"<<capSamples[capInc];		if(capInc<9)capInc++;else capInc=0;
         //		if(capSamples[0]==capSamples[1])if(capSamples[1]==capSamples[2])if(capSamples[2]==capSamples[3])
         //		if(capSamples[3]==capSamples[4])if(capSamples[4]==capSamples[5])if(capSamples[5]==capSamples[6])
         //		if(capSamples[6]==capSamples[7])if(capSamples[7]==capSamples[8])if(capSamples[8]==capSamples[9])
         //		qDebug()<<"Last 10 samples are constant";
         //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
         l_sDisplayData = QString::number((p_nData),'f',2) + microFarad;
         }
         else if (p_nRange == 6)
         {
         p_nData = p_nData * 1000000.0;
         //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
         //		double d = ( (double) ( (int) (p_nData * 100.0) ) ) / 100.0 ;
         //		capSamples[capInc]=d; qDebug()<<"capSamples["<<capInc<<"]"<<capSamples[capInc];		if(capInc<9)capInc++;else capInc=0;
         //		if(capSamples[0]==capSamples[1])if(capSamples[1]==capSamples[2])if(capSamples[2]==capSamples[3])
         //		if(capSamples[3]==capSamples[4])if(capSamples[4]==capSamples[5])if(capSamples[5]==capSamples[6])
         //		if(capSamples[6]==capSamples[7])if(capSamples[7]==capSamples[8])if(capSamples[8]==capSamples[9])
         //		qDebug()<<"Last 10 samples are constant";
         //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
         l_sDisplayData = QString::number((p_nData),'f',2) + microFarad;
         }
         else if (p_nRange == 7)
         {
         p_nData = p_nData * 1000000.0;
         //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
         //		double d = ( (double) ( (int) (p_nData * 100.0) ) ) / 100.0 ;
         //		capSamples[capInc]=d; qDebug()<<"capSamples["<<capInc<<"]"<<capSamples[capInc];		if(capInc<9)capInc++;else capInc=0;
         //		if(capSamples[0]==capSamples[1])if(capSamples[1]==capSamples[2])if(capSamples[2]==capSamples[3])
         //		if(capSamples[3]==capSamples[4])if(capSamples[4]==capSamples[5])if(capSamples[5]==capSamples[6])
         //		if(capSamples[6]==capSamples[7])if(capSamples[7]==capSamples[8])if(capSamples[8]==capSamples[9])
         //		qDebug()<<"Last 10 samples are constant";
         //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
         l_sDisplayData = QString::number((p_nData),'f',2) + microFarad;
         }
         else if (p_nRange == 8)
         {
         p_nData = p_nData * 1000.0;
         //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
         //		double d = ( (double) ( (int) (p_nData * 100.0) ) ) / 100.0 ;
         //		capSamples[capInc]=d; qDebug()<<"capSamples["<<capInc<<"]"<<capSamples[capInc];		if(capInc<9)capInc++;else capInc=0;
         //		if(capSamples[0]==capSamples[1])if(capSamples[1]==capSamples[2])if(capSamples[2]==capSamples[3])
         //		if(capSamples[3]==capSamples[4])if(capSamples[4]==capSamples[5])if(capSamples[5]==capSamples[6])
         //		if(capSamples[6]==capSamples[7])if(capSamples[7]==capSamples[8])if(capSamples[8]==capSamples[9])
         //		qDebug()<<"Last 10 samples are constant";
         //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
         l_sDisplayData = QString::number((p_nData),'f',2) + microFarad;
         }
	else {
		l_sDisplayData = convertToUnits(p_nData);// + "F";
		//		ui->Unit->setText("F");
		//		dis->setValue(l_sDisplayData);

	}*/
    //Passing Range to display class~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    bool ok=true;
    QString str_value = convertToUnits(p_nData);
    qDebug()<<"convertToUnits output:"<<str_value;
    QString str_range = ui->rangeLabel->text();

    if(ui->rangeLabel->text().endsWith("pF")||ui->rangeLabel->text().endsWith("nF")||ui->rangeLabel->text().endsWith("uF")||ui->rangeLabel->text().endsWith("uH")||ui->rangeLabel->text().endsWith("mF") || ui->rangeLabel->text().endsWith("mH")||ui->rangeLabel->text().endsWith("KE")||ui->rangeLabel->text().endsWith("ME"))
        str_range.chop(2);
    else if(ui->rangeLabel->text().endsWith("E")||ui->rangeLabel->text().endsWith("H"))
        str_range.chop(1);

    int int_range=str_range.toInt(&ok,10);
    dis->setRange(int_range);


    double dbl_value;

    if(str_value=="OL"){
        ui->Unit->setText("mF");
        dis->setValue("OL");
    }
    else if(str_value=="UL"){
        ui->Unit->setText("pF");
        dis->setValue(0.0);
    }else{
        dbl_value=str_value.toDouble(&ok);
        dis->setValue(dbl_value);
    }

    ui->scrDisplay->setText(QString::number(dbl_value));
    qDebug()<<"strRange:"<<str_range<<"str_value:"<<str_value;
    qDebug()<<"intRange:"<<int_range<<"dbl_value:"<<dbl_value;
    if(dbl_value<12000000)
        InsertGraphData(dbl_value);
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
}
void ICM::GetDisplayInductance(double p_nData, short int p_nRange) {
    p_nData = p_nData + m_dOffset;

    //qDebug()<<"Inductance:"<<p_nData<<"Range:"<<p_nRange;
    if (ui->calibrateDisplay->isChecked()) {
        CalibrateDisplay("ICM-L");

        double y, x, c, m;
        x = p_nData;
        c = calibedConstant;
        m = calibedSlope;

        y = (x - c) / m;

        p_nData = y;
        cbdL=y;

    }
    if (m_bNull == true) {
        p_nData = p_nData -m_dLNull;

    }
    m_nInductance_2 = p_nData;

    if (autoFlag == true)
        AutoRange();

    if (ui->checkBox->isChecked()) {
        if (ui->chkLoad->isChecked())
            Zdut = (((avgLValueSh[L_Index] - p_nData) * (Measured
                                                         - avgLValueOpen[L_Index])) / ((p_nData
                                                                                        - avgLValueOpen[L_Index]) * (avgLValueSh[L_Index]
                                                                                                                     - Measured))) * Actual;
        else
            Zdut = ((avgCValueSh[L_Index] - p_nData) / (p_nData
                                                        - avgCValueOpen[L_Index])) * (avgCValueOpen[L_Index]);

        p_nData = Zdut;
    }
    /*	QString l_sDisplayData("");

	if (p_nRange == 0) // 300nH - 3uH
	{
		p_nData = p_nData * 1000000;
		l_sDisplayData = QString::number((p_nData), 'f', 2) ;//+ microHenry;//"n"+Henry;			//?
		ui->Unit->setText(microHenry);
		//		dis->setValue(l_sDisplayData);
	} else if (p_nRange == 1) // 3uH - 30uH
	{
		p_nData = p_nData * 1000000;
		l_sDisplayData = QString::number((p_nData), 'f', 2);// + microHenry;
		ui->Unit->setText(microHenry);
		//		dis->setValue(l_sDisplayData);
	}
	     else if(p_nRange == 2) // 30uH - 300 uH
         {
         p_nData = p_nData * 1000000;
//         l_sDisplayData = QString::number((p_nData),'f',2) + microHenry;
         }
         else if(p_nRange == 3) // 300uH - 3mH
         {
         p_nData = p_nData * 1000000;
//         l_sDisplayData = QString::number((p_nData),'f',2) + microHenry;				//?
         }
         else if(p_nRange == 4) // 3mH - 30mH
         {
         p_nData = p_nData * 1000;
//         l_sDisplayData = QString::number((p_nData),'f',2) + milliHenry;
         }
         else if(p_nRange == 5) // 30mH - 300mH
         {
         p_nData = p_nData * 1000;
//         l_sDisplayData = QString::number((p_nData),'f',2) + milliHenry;
         }
         else if(p_nRange == 6) // 300mH - 3H
         {
         p_nData = p_nData * 1000;
//         l_sDisplayData = QString::number((p_nData),'f',2) + milliHenry;				//?
         }
         else if(p_nRange == 7) // 3H - 30H
         {
//         l_sDisplayData = QString::number((p_nData),'f',2) + Henry;
         }
	else {
//		l_sDisplayData = convertToUnits(p_nData);// + "H";
		//		ui->Unit->setText("H");
		//		dis->setValue(l_sDisplayData);
	}*/
    //Passing Range to display class~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    bool ok=true;
    QString str_value = convertToUnits(p_nData);
    QString str_range = ui->rangeLabel->text();
    if(ui->rangeLabel->text().endsWith("pF")||ui->rangeLabel->text().endsWith("nF")||ui->rangeLabel->text().endsWith("uF")||ui->rangeLabel->text().endsWith("uH")||ui->rangeLabel->text().endsWith("mF") || ui->rangeLabel->text().endsWith("mH")||ui->rangeLabel->text().endsWith("KE")||ui->rangeLabel->text().endsWith("ME"))
        str_range.chop(2);
    else if(ui->rangeLabel->text().endsWith("E")||ui->rangeLabel->text().endsWith("H"))
        str_range.chop(1);
    int int_range=str_range.toInt(&ok,10);
    dis->setRange(int_range);

    double dbl_value=0.0;
    if(str_value=="UL")
        dis->setValue("OL");
    else{
        dbl_value=str_value.toDouble(&ok);
        ui->scrDisplay->setText(QString::number(dbl_value));
        dis->setValue(dbl_value);
        if(dbl_value<12000000)
            InsertGraphData(dbl_value);
    }
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    qDebug()<<"############p_nData:"<<p_nData<<"str_value:"<<str_value<<"str_range:"<<str_range<<"int_range:"<<int_range<<"dbl_value:"<<dbl_value;
}
double ICM::convertToValues(QString input) {

    QString unit, value;
    double inValue;
    bool ok = true;

    int j = 0;

    for (int i = 0; i <= input.count(); i++) {
        if ((input[i] >= 'A' && input[i] <= 'Z') || (input[i] >= 'a' && input[i] <= 'z') || (input[i] == QChar(0x2126)) || (input[i]== QChar(0x00B5))) {
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
QString ICM::convertToUnits(double l_nvalue) {
    qDebug()<<"convertToUnits input:"<<l_nvalue;
    QString unit;
    double value;
    if (l_nvalue < 0) {
        if (rFlag==true && (l_nvalue < -0.1)) //<-100mOhms
            return (QString("UL"));
        else if (lFlag==true && (l_nvalue < -0.000001)) //<-1uH
            return (QString("UL"));
        else if (cFlag==true && (l_nvalue < -0.00000000001)) //<-10pF
            return (QString("UL"));
        else
            value = l_nvalue * -1;
    } else
        value = l_nvalue;

    if(cFlag==true && value >0.015)
        return (QString("OL"));

    if (value >= 1000000 && value < 1000000000) {
        if(m_nRange == 0.0000000001){
            value = value * 1000000000000;
            unit = "p";
        }
        else if(m_nRange == 0.0000001 || m_nRange == 0.00000001 || m_nRange == 0.000000001){
            value = value * 1000000000;
            unit = "n";
        }
        else if(m_nRange == 0.00003 || m_nRange == 0.0003 || m_nRange == 0.0001 || m_nRange == 0.00001 || m_nRange == 0.000001){
            value = value * 1000000;
            unit = QChar(0x00B5);
        }else if(m_nRange == 0.003 || m_nRange == 0.03 || m_nRange == 0.3 || m_nRange == 0.001 || m_nRange == 0.01){
            value = value * 1000;
            unit = "m";
        }else if(m_nRange == 3 || m_nRange == 30 || m_nRange == 300){
            value = value;
            unit = "";
        }else if(m_nRange == 3000 || m_nRange == 30000 || m_nRange == 300000){
            value = value / 1000;
            unit = "K";
        }else if(m_nRange == 1000000){
            value = value / 1000000;
            unit = "M";
        }
    } else if (value >= 1000 && value < 1000000) {
        if(m_nRange == 0.0000000001){
            value = value * 1000000000000;
            unit = "p";
        }
        else if(m_nRange == 0.0000001 || m_nRange == 0.00000001 || m_nRange == 0.000000001){
            value = value * 1000000000;
            unit = "n";
        }
        else if(m_nRange == 0.00003 || m_nRange == 0.0003 || m_nRange == 0.0001 || m_nRange == 0.00001 || m_nRange == 0.000001){
            value = value * 1000000;
            unit = QChar(0x00B5);
        }else if(m_nRange == 0.003 || m_nRange == 0.03 || m_nRange == 0.3 || m_nRange == 0.001 || m_nRange == 0.01){
            value = value * 1000;
            unit = "m";
        }else if(m_nRange == 3 || m_nRange == 30 || m_nRange == 300){
            value = value;
            unit = "";
        }else if(m_nRange == 3000 || m_nRange == 30000 || m_nRange == 300000){
            value = value / 1000;
            unit = "K";
        }else if(m_nRange == 1000000){
            value = value / 1000000;
            unit = "M";
        }
    } else if ((value >= 1 && value < 1000)) {
        if(m_nRange == 0.0000000001){
            value = value * 1000000000000;
            unit = "p";
        }
        else if(m_nRange == 0.0000001 || m_nRange == 0.00000001 || m_nRange == 0.000000001){
            value = value * 1000000000;
            unit = "n";
        }
        else if(m_nRange == 0.00003 || m_nRange == 0.0003 || m_nRange == 0.0001 || m_nRange == 0.00001 || m_nRange == 0.000001){
            value = value * 1000000;
            unit = QChar(0x00B5);
        }else if(m_nRange == 0.003 || m_nRange == 0.03 || m_nRange == 0.3 || m_nRange == 0.001 || m_nRange == 0.01){
            value = value * 1000;
            unit = "m";
        }else if(m_nRange == 3 || m_nRange == 30 || m_nRange == 300){
            value = value;
            unit = "";
        }else if(m_nRange == 3000 || m_nRange == 30000 || m_nRange == 300000){
            value = value / 1000;
            unit = "K";
        }else if(m_nRange == 1000000){
            value = value / 1000000;
            unit = "M";
        }
    } else if ((value * 1000) >= 1 && value < 1000) {
        if(m_nRange == 0.0000000001){
            value = value * 1000000000000;
            unit = "p";
        }
        else if(m_nRange == 0.0000001 || m_nRange == 0.00000001 || m_nRange == 0.000000001){
            value = value * 1000000000;
            unit = "n";
        }
        else if(m_nRange == 0.00003 || m_nRange == 0.0003 || m_nRange == 0.0001 || m_nRange == 0.00001 || m_nRange == 0.000001){
            value = value * 1000000;
            unit = QChar(0x00B5);
        }else if(m_nRange == 0.003 || m_nRange == 0.03 || m_nRange == 0.3 || m_nRange == 0.001 || m_nRange == 0.01){
            value = value * 1000;
            unit = "m";
        }else if(m_nRange == 3 || m_nRange == 30 || m_nRange == 300){
            value = value;
            unit = "";
        }else if(m_nRange == 3000 || m_nRange == 30000 || m_nRange == 300000){
            value = value / 1000;
            unit = "K";
        }else if(m_nRange == 1000000){
            value = value / 1000000;
            unit = "M";
        }
    } else if ((value * 1000000) >= 1 && value < 1000000) {
        if(m_nRange == 0.0000000001){
            value = value * 1000000000000;
            unit = "p";
        }
        else if(m_nRange == 0.0000001 || m_nRange == 0.00000001 || m_nRange == 0.000000001){
            value = value * 1000000000;
            unit = "n";
        }
        else if(m_nRange == 0.00003 || m_nRange == 0.0003 || m_nRange == 0.0001 || m_nRange == 0.00001 || m_nRange == 0.000001){
            value = value * 1000000;
            unit = QChar(0x00B5);
        }else if(m_nRange == 0.003 || m_nRange == 0.03 || m_nRange == 0.3 || m_nRange == 0.001 || m_nRange == 0.01){
            value = value * 1000;
            unit = "m";
        }else if(m_nRange == 3 || m_nRange == 30 || m_nRange == 300){
            value = value;
            unit = "";
        }else if(m_nRange == 3000 || m_nRange == 30000 || m_nRange == 300000){
            value = value / 1000;
            unit = "K";
        }else if(m_nRange == 1000000){
            value = value / 1000000;
            unit = "M";
        }
    } else if ((value * 1000000000) >= 1 && value < 1000000000) {
        if(m_nRange == 0.0000000001){
            value = value * 1000000000000;
            unit = "p";
        }
        else if(m_nRange == 0.0000001 || m_nRange == 0.00000001 || m_nRange == 0.000000001){
            value = value * 1000000000;
            unit = "n";
        }
        else if(m_nRange == 0.00003 || m_nRange == 0.0003 || m_nRange == 0.0001 || m_nRange == 0.00001 || m_nRange == 0.000001){
            value = value * 1000000;
            unit = QChar(0x00B5);
        }else if(m_nRange == 0.003 || m_nRange == 0.03 || m_nRange == 0.3 || m_nRange == 0.001 || m_nRange == 0.01){
            value = value * 1000;
            unit = "m";
        }else if(m_nRange == 3 || m_nRange == 30 || m_nRange == 300){
            value = value;
            unit = "";
        }else if(m_nRange == 3000 || m_nRange == 30000 || m_nRange == 300000){
            value = value / 1000;
            unit = "K";
        }else if(m_nRange == 1000000){
            value = value / 1000000;
            unit = "M";
        }
    } else if ((value * 1000000000000) >= 1 && value < 1000000000000) {
        if(m_nRange == 0.0000000001){
            value = value * 1000000000000;
            unit = "p";
        }
        else if(m_nRange == 0.0000001 || m_nRange == 0.00000001 || m_nRange == 0.000000001){
            value = value * 1000000000;
            unit = "n";
        }
        else if(m_nRange == 0.00003 || m_nRange == 0.0003 || m_nRange == 0.0001 || m_nRange == 0.00001 || m_nRange == 0.000001){
            value = value * 1000000;
            unit = QChar(0x00B5);
        }else if(m_nRange == 0.003 || m_nRange == 0.03 || m_nRange == 0.3 || m_nRange == 0.001 || m_nRange == 0.01){
            value = value * 1000;
            unit = "m";
        }else if(m_nRange == 3 || m_nRange == 30 || m_nRange == 300){
            value = value;
            unit = "";
        }else if(m_nRange == 3000 || m_nRange == 30000 || m_nRange == 300000){
            value = value / 1000;
            unit = "K";
        }else if(m_nRange == 1000000){
            value = value / 1000000;
            unit = "M";
        }
    }
    if (l_nvalue >= 0){
        if(rFlag)ui->Unit->setText(unit+ohms);
        if(lFlag)ui->Unit->setText(unit+"H");
        if(cFlag)ui->Unit->setText(unit+"F");
        return (QString::number(value, 'f', 5));// + unit);
    }
    if (l_nvalue < 0){
        if(rFlag)ui->Unit->setText(unit+ohms);
        if(lFlag)ui->Unit->setText(unit+"H");
        if(cFlag)ui->Unit->setText(unit+"F");
        return (QString::number(value * -1, 'f', 5));// + unit);
    }

}

void ICM::on_AutoManual_clicked() {
    if(!scanFlag)scanFlag=true;

    if (autoFlag==true) {
        ui->AutoManual->setIcon(QIcon(QPixmap(":/Symbols/hand-icon.png")));
        autoFlag=false;
        ui->autoManualCAp->setText("Manual");

    } else if (autoFlag==false) {
        ui->AutoManual->setIcon(QIcon(QPixmap(":/Symbols/Time-Machine-icon.png")));
        autoFlag=true;
        ui->autoManualCAp->setText("Auto");
    }
}

void ICM::on_ExitBut_clicked() {
    on_Exit_clicked();
}

void ICM::on_calibrate_clicked() {
    //	QWidget *newWidget=new QWidget(this);
    //	newWidget=GCALIB->getGCALIB();
    //	newWidget->setWindowTitle("General Calibration Panel");
    //	newWidget->show();

    objGCalib = new DACCalibration(this);

    //		objGCalib->setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);
    //		objGCalib->setStyleSheet("border:3px solid #45596f; border-style: groove; background-color:qlineargradient(x1:0, y1:0, x2:0, y2:1,stop:0 lightgray, stop:1 darkgray);");

    QPropertyAnimation *animation = new QPropertyAnimation(objGCalib,
                                                           "geometry");
    animation->setDuration(10000);
    animation->setStartValue(QRect(200, 350, 50, 50));
    animation->setEndValue(QRect(200, 200, 400, 341));
    animation->setEasingCurve(QEasingCurve::Linear);
    animation->setDuration(1000);
    animation->start();

    objGCalib->show();
}

void ICM::on_pushButton_clicked() {
    checkPrbStatus=false;
    /*	    QWidget *newWidget=test->getPTAppBckPsoc();
                            newWidget->setWindowTitle("AppCard BackPanel PSoC Panel");
                            newWidget->show();*/
    if(!scanFlag)scanFlag=true;

    if (m_bExternal == false) {
        ui->ah0_inner->setVisible(false);
        ui->ah1_inner->setVisible(false);
        ui->ah_inner->setVisible(false);
        ui->ah2_inner->setVisible(false);
        //qDebug()<<"External Measurement";
        /*		IPsoc->resetRelays();
                usleep(1000);
                IPsoc->onBottomRelay(0x9);
                usleep(1000);
                IPsoc->onBottomRelay(0x15);
                usleep(1000);
                IPsoc->onBottomRelay(0x13);*///commnted on 12062014 by RRV
		//		IPsoc->resetRelays();
		IPsoc->switchFly();
		m_bExternal = true;
		ui->pushButton->setIcon(QIcon(QPixmap(":/Symbols/Letter-E-icon.png")));
		//		ui->fp_VI1_ICM_SL->setGeometry(24,20,41,41);
		//		ui->fp_VI1_ICM_SL->setStyleSheet("border:1px solid gray;border-radius:20px;image: url(:/new/prefix1/Button-Blank-Gray-icon.png);");
		//
		//		ui->fp_VI2_EXT->setGeometry(105,20,53,49);
		//		ui->fp_VI2_EXT->setStyleSheet("border:1px rgba(0,0,0,0);border-radius:20px;image: url(:/fp_images/VI_SL_ICM.png);");

	} else {
		//qDebug()<<"Internal Measurement";
		//		IPsoc->resetRelays();
		IPsoc->icmMeasurement();
		m_bExternal = false;
		ui->pushButton->setIcon(QIcon(QPixmap(":/Symbols/Letter-I-icon.png")));
		//		ui->fp_VI1_ICM_SL->setGeometry(24,20,53,49);
		//		ui->fp_VI1_ICM_SL->setStyleSheet("border:1px rgba(0,0,0,0);border-radius:20px;image: url(:/fp_images/VI_SL_ICM.png);");
		//
		//		ui->fp_VI2_EXT->setGeometry(110,20,41,41);
		//		ui->fp_VI2_EXT->setStyleSheet("border:1px solid gray;border-radius:20px;image: url(:/new/prefix1/Button-Blank-Gray-icon.png);");
	}

}

void ICM::on_NULL_2_clicked() {
	if (m_bNull == false) {
		if (lFlag==true) {
			if(ui->calibrateDisplay->isChecked())
				m_dLNull=cbdL;
			else
				m_dLNull = m_nInductance;
			qDebug()<<"Null the Inductance with "<<m_dLNull;
			ui->label_RELValue->setText(convertToUnits(m_dLNull)+ui->Unit->text());
		}
		if (rFlag==true) {
			if(ui->calibrateDisplay->isChecked())
				m_dRNull=cbdR;
			else
				m_dRNull = m_nResistance;
			qDebug()<<"Null the Impedance with "<<m_dRNull;
			ui->label_RELValue->setText(convertToUnits(m_dRNull)+ui->Unit->text());
		}
		if (cFlag==true) {
			if(ui->calibrateDisplay->isChecked())
				m_dCNull=cbdC;
			else
				m_dCNull = m_nCapacitance;
			qDebug()<<"Null the Capacitance with "<<m_dCNull;
			ui->label_RELValue->setText(convertToUnits(m_dCNull)+ui->Unit->text());
		}
		m_bNull = true;
		ui->NULL_2->setIcon(QIcon(QPixmap(":/Symbols/Number-0-icon-green.png")));
		ui->label_RELCap->setVisible(true);
		ui->label_RELValue->setVisible(true);

	} else {
		m_bNull = false;
		ui->label_RELCap->setVisible(false);
		ui->label_RELValue->setVisible(false);
		ui->NULL_2->setIcon(QIcon(QPixmap(":/Symbols/Number-0-icon.png")));
	}
}

void ICM::on_external_clicked(bool checked) {
	if (checked) {
		//qDebug()<<"External Measurement";
		IPsoc->resetRelays();
		IPsoc->writeSerial(0x42);
		IPsoc->writeSerial(0x9);
		usleep(1000);
		IPsoc->writeSerial(0x42);
		IPsoc->writeSerial(0x15);
		usleep(1000);
		IPsoc->writeSerial(0x42);
		IPsoc->writeSerial(0x13);

	} else {
		//qDebug()<<"Internal Measurement";
		IPsoc->resetRelays();
		IPsoc->icmMeasurement();
	}
}

void ICM::on_pushButton_2_clicked() {

	QMessageBox *open = new QMessageBox(this);
	open->setWindowTitle("Open Calibration");
	open->setText("Open your probes and click OK");
	open->exec();

	double openCValues[50], openRValues[50], openLValues[50];

	if (rFlag==true) {
		for (int i = 0; i < 50; i++) {
			openRValues[i] = m_nResistance;
			//qDebug()<<"Open Value"<<i+1<<openRValues[i];
			usleep(1000);
		}
		for (int j = 0; j < 50; j++)
			avgRValueOpen[R_Index] = avgRValueOpen[R_Index] + openRValues[j];

		avgRValueOpen[R_Index] = avgRValueOpen[R_Index] / 50;

		//qDebug()<<"Averaged Resistance Open Value of"<<m_mapResistance.value(R_Index)<<":"<<avgRValueOpen[R_Index];
	}
	if (lFlag==true) {
		for (int i = 0; i < 50; i++) {
			openLValues[i] = m_nInductance;
			//qDebug()<<"Open Value"<<i+1<<openLValues[i];
			usleep(1000);
		}
		for (int j = 0; j < 50; j++)
			avgLValueOpen[L_Index] = avgLValueOpen[L_Index] + openLValues[j];

		avgLValueOpen[L_Index] = avgLValueOpen[L_Index] / 50;
		//qDebug()<<"Averaged Inductance Open Value of"<<m_mapInductance.value(L_Index)<<":"<<avgLValueOpen[L_Index];
	}
	if (cFlag==true) {
		for (int i = 0; i < 50; i++) {
			openCValues[i] = m_nCapacitance;
			//qDebug()<<"Open Value"<<i<<openCValues[i];
			usleep(1000);
		}
		for (int j = 0; j < 50; j++)
			avgCValueOpen[C_Index] = avgCValueOpen[C_Index] + openCValues[j];

		avgCValueOpen[C_Index] = avgCValueOpen[C_Index] / 50;

		//qDebug()<<"Averaged Capacitance Open Value of"<<m_mapInductance.value(C_Index)<<":"<<avgCValueOpen[C_Index];
	}

	//qDebug()<<"Open Calibration done";

	QMessageBox *shrt = new QMessageBox(this);
	shrt->setWindowTitle("Short Calibration");
	shrt->setText("Short your probes and click OK");
	shrt->exec();

	double shortCValues[50], shortRValues[50], shortLValues[50];

	if (rFlag==true) {
		for (int i = 0; i < 50; i++) {
			shortRValues[i] = m_nResistance;
			//qDebug()<<"Short Value"<<i<<shortRValues[i];
			usleep(10);
		}
		for (int j = 0; j < 50; j++)
			avgRValueSh[R_Index] = avgRValueSh[R_Index] + shortRValues[j];

		avgRValueSh[R_Index] = avgRValueSh[R_Index] / 50;
		//qDebug()<<"Averaged Resistance Short Value of"<<m_mapResistance.value(R_Index)<<":"<<avgRValueSh[R_Index];
	}
	if (lFlag==true) {
		for (int i = 0; i < 50; i++) {
			shortLValues[i] = m_nInductance;
			usleep(10);
		}
		for (int j = 0; j < 50; j++)
			avgLValueSh[L_Index] = avgLValueSh[L_Index] + shortLValues[j];

		avgLValueSh[L_Index] = avgLValueSh[L_Index] / 50;
		//qDebug()<<"Averaged Inductance Short Value of"<<m_mapInductance.value(L_Index)<<":"<<avgLValueSh[L_Index];
	}
	if (cFlag==true) {
		for (int i = 0; i < 50; i++) {
			shortCValues[i] = m_nCapacitance;
			//qDebug()<<"Short Value"<<i<<shortCValues[i];
			usleep(10);
		}
		for (int j = 0; j < 50; j++)
			avgCValueSh[C_Index] = avgCValueSh[C_Index] + shortCValues[j];

		avgCValueSh[C_Index] = avgCValueSh[C_Index] / 50;
		//qDebug()<<"Averaged Capacitance Short Value of"<<m_mapInductance.value(C_Index)<<":"<<avgCValueSh[C_Index];
	}
	//qDebug()<<"Short Calibration done";

}

void ICM::on_checkBox_clicked() {

}

void ICM::on_chkLoad_clicked() {
	if (rFlag==true) {
		//qDebug()<<"Range :"<<m_mapResistance[R_Index];
		//qDebug()<<"Zs  :"<<avgRValueSh[R_Index];
		//qDebug()<<"Zo  :"<<avgRValueOpen[R_Index];
		//qDebug()<<"Zxm :"<<m_nResistance;
		//qDebug()<<"Zsm :"<<Measured;
		//qDebug()<<"Zstd:"<<Actual;
		double Zdut2 = (((avgRValueSh[R_Index] - m_nResistance) * (Measured
				- avgRValueOpen[R_Index])) / ((m_nResistance
						- avgRValueOpen[R_Index]) * (avgRValueSh[R_Index] - Measured)))
						* Actual;
		//qDebug()<<"Zdut:"<<Zdut2;

	}
	if (lFlag==true) {
		//qDebug()<<"Range :"<<m_mapInductance[L_Index];
		//qDebug()<<"Zs  :"<<avgLValueSh[L_Index];
		//qDebug()<<"Zo  :"<<avgLValueOpen[L_Index];
		//qDebug()<<"Zxm :"<<m_nInductance;
		//qDebug()<<"Zsm :"<<Measured;
		//qDebug()<<"Zstd:"<<Actual;
		double Zdut2 = (((avgLValueSh[L_Index] - m_nInductance) * (Measured
				- avgLValueOpen[L_Index])) / ((m_nInductance
						- avgLValueOpen[L_Index]) * (avgLValueSh[L_Index] - Measured)))
						* Actual;
		//qDebug()<<"Zdut:"<<Zdut2;
	}
	if (cFlag==true) {
		//qDebug()<<"Range :"<<m_mapCapacitance[C_Index];
		//qDebug()<<"Zs  :"<<avgCValueSh[C_Index];
		//qDebug()<<"Zo  :"<<avgCValueOpen[C_Index];
		//qDebug()<<"Zxm :"<<m_nCapacitance;
		//qDebug()<<"Zsm :"<<Measured;
		//qDebug()<<"Zstd:"<<Actual;
		double Zdut2 = (((avgCValueSh[C_Index] - m_nCapacitance) * (Measured
				- avgCValueOpen[C_Index])) / ((m_nCapacitance
						- avgCValueOpen[C_Index]) * (avgCValueSh[C_Index] - Measured)))
						* Actual;
		//qDebug()<<"Zdut:"<<Zdut2;

	}

}

void ICM::on_printImage_clicked() {
	QPixmap Pix = QPixmap();
	Pix = QPixmap::grabWindow(this->winId());
	Pix.save("icm.jpg");
}

/*void ICM::on_hideSettings_clicked() {
	//	if (m_bToolboxFlag == false) {
	//		ToolBox(true);
	//		m_bToolboxFlag = true;
	//	} else {
	//		ToolBox(false);
	//		m_bToolboxFlag = false;
	//	}
}*/

void ICM::on_pushButton_3_clicked() {
    QWidget *newWidget = test->getPTAppBckPsoc();
    newWidget->setWindowTitle("AppCard BackPanel PSoC Panel");
    newWidget->show();
}

void ICM::on_RacRdc_clicked() {
    unsigned short m_nR1RMSIN,m_nR2RMSIN;
    if (m_bRacRdc) {
        IAppCard->setSPIAppendBit(0xC000);
        IAppCard->writeRegister(0x1, 0x16); //Rs Bypassed
        IAppCard->writeRegister(0x02, 0x36);
        IAppCard->writeRegister(0x06, 0x38);
        IAppCard->setDDSWaveSelect(DC_SIGNAL);
        hwInterface->Init();

        //DGGSR,for SL offset disable+0.6Vpp
        IAppCard->writeRegister(0x0000,PT_APPCARD_MODULES::PT_DRRLY_APPCARD_DRGSR);
        //DRSER,Source,Rx1&2 connected to A.H(0,1,2,3,6&7)
        IAppCard->writeRegister(0x0007,PT_APPCARD_MODULES::PT_DRRLY_APPCARD_DRSER);
        //DSAR,Force V+Source Impedance enable
        IAppCard->writeRegister(0x0001,PT_APPCARD_MODULES::PT_DRRLY_APPCARD_DSAR);
        //RAMR,for RAM based drive mode
        IAppCard->writeRegister(0x0000,PT_APPCARD_MODULES::PT_SRAM_APPCARD_RAMR);
        //BTUR,to specify the LSW of basic time unit
        IAppCard->writeRegister(0x0063,PT_APPCARD_MODULES::PT_DRIVE_APPCARD_BTUR);
        //BDR,to specify time of per drive
        IAppCard->writeRegister(0x0009,	PT_APPCARD_MODULES::PT_DRIVE_APPCARD_BDR);
        //WDPR,to specify the drive period count
        IAppCard->writeRegister(0x0001,	PT_APPCARD_MODULES::PT_DRIVE_APPCARD_DPR);
        //DDSWSELR, for direct DC drive
        IAppCard->writeRegister(0x0001,PT_APPCARD_MODULES::PT_DDS_APPCARD_DDSWSELR);

        //Added on 14thAugust
        IAppCard->writeRegister(0x0000, 0x1C);
        IAppCard->writeRegister(0x0100, 0x1A);//Loop drive mode
        IAppCard->writeRegister(0x0001, 0x94);

        IAppCard->setSPIAppendBit(0x8000);
        hwInterface->initParallelDAC();
        IAppCard->setSPIAppendBit(0xC000);
        hwInterface->updateParallelDAC(-0.1);

        m_bRacRdc = false;
        ui->RacRdc->setIcon(QIcon(QPixmap(":/dc.png")));
        ui->ACDC->setIcon(QIcon(QPixmap(":/Symbols/Letter-dc-icon.png")));
        ui->acDcLabel->setText("DC");
        qDebug() << "DC Measurement";

        m_nR1RMSIN=IAppCard->readRegister(0x36);
        m_nR1RMSIN|=1<<2;
        IAppCard->writeRegister(m_nR1RMSIN,0x36);

        m_nR2RMSIN=IAppCard->readRegister(0x38);
        m_nR2RMSIN|=1<<3;
        IAppCard->writeRegister(m_nR2RMSIN,0x38);

    } else {
        IAppCard->setDDSWaveSelect(DDS);

        hwInterface->Init();
        hwInterface->setOffset(0);
        hwInterface->setPhase(0);
        IAppCard->setSPIAppendBit(0x8000);
        hwInterface->setAmplitude(0.1);
        hwInterface->SingleContinuous(CONTINUOUS);

        IAppCard->writeRegister(0x02, 0x36);
        IAppCard->writeRegister(0x06, 0x38);
        IAppCard->writeRegister(0x1, 0x16);
        IAppCard->writeRegister(0x7, 0x34);
        IAppCard->writeRegister(0, 0x3A);

        m_bRacRdc = true;
        ui->RacRdc->setIcon(QIcon(QPixmap(":/ac.png")));
        ui->ACDC->setIcon(QIcon(QPixmap(":/Symbols/Letter-ac-icon.png")));
        ui->acDcLabel->setText("AC");


        qDebug() << "AC Measurement";

        m_nR1RMSIN=IAppCard->readRegister(0x36);
        m_nR1RMSIN&= 0xFFFB;
        IAppCard->writeRegister(m_nR1RMSIN,0x36);

        m_nR2RMSIN=IAppCard->readRegister(0x38);
        m_nR2RMSIN&=0xFFF7;
        IAppCard->writeRegister(m_nR2RMSIN,0x38);
    }
    if(ui->R10E->isChecked())ui->R10E->animateClick(1);
    else if(ui->R100E->isChecked())ui->R100E->animateClick(1);
    else if(ui->R1KE->isChecked())ui->R1KE->animateClick(1);
    else if(ui->R10KE->isChecked())ui->R10KE->animateClick(1);
    else if(ui->R100KE->isChecked())ui->R100KE->animateClick(1);
    else if(ui->R1ME->isChecked())ui->R1ME->animateClick(1);

}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void ICM::on_exit_clicked()
{
    on_Exit_clicked();
}

void ICM::on_rBut_clicked()
{
    //	m_strRLC = "Resistance";
    ui->selectFrame->setGeometry(701,54,10,60);
    ui->rBox->setStyleSheet("QGroupBox{border:1px solid white; background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #3a5976, stop: 1 #000000);border-radius:10px;border-bottom:1px qlineargradient(x1: 0, y1: 0,stop: 0 #f6f7fa, stop: 1 #dadbde); border-bottom-right-radius: 0px;border-bottom-left-radius: 0px;}");
    ui->lBox->setStyleSheet("QGroupBox{border:1px solid white; background-color: #dadbde;border-radius:10px;border-bottom:1px qlineargradient(x1: 0, y1: 0,stop: 0 #f6f7fa, stop: 1 #dadbde);border-bottom-right-radius: 0px; border-bottom-left-radius: 0px;border-top:1px solid gray; border-top-right-radius: 0px; border-top-left-radius: 0px;}");
    ui->cBox->setStyleSheet("QGroupBox{border:1px solid white; background-color: #dadbde;border-radius:10px;border-top:1px qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #f6f7fa, stop: 1 #dadbde); border-top-right-radius: 0px; border-top-left-radius: 0px;border-top:1px solid gray;border-bottom-right-radius: 0px; border-bottom-left-radius: 0px;}");
    rFlag=true;lFlag=false;cFlag=false;
    on_R_clicked();
}

void ICM::on_lBut_clicked()
{
    //	m_strRLC = "Inductance";
    ui->selectFrame->setGeometry(701,154,10,60);
    ui->rBox->setStyleSheet("QGroupBox{border:1px solid white; background-color: #dadbde;border-radius:10px;border-bottom:1px qlineargradient(x1: 0, y1: 0,stop: 0 #f6f7fa, stop: 1 #dadbde); border-bottom-right-radius: 0px;border-bottom-left-radius: 0px;}");
    ui->lBox->setStyleSheet("QGroupBox{border:1px solid white; background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #3a5976, stop: 1 #000000);border-radius:10px;border-bottom:1px qlineargradient(x1: 0, y1: 0,stop: 0 #f6f7fa, stop: 1 #dadbde);border-bottom-right-radius: 0px; border-bottom-left-radius: 0px;border-top:1px solid gray; border-top-right-radius: 0px; border-top-left-radius: 0px;}");
    ui->cBox->setStyleSheet("QGroupBox{border:1px solid white; background-color: #dadbde;border-radius:10px;border-top:1px qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #f6f7fa, stop: 1 #dadbde); border-top-right-radius: 0px; border-top-left-radius: 0px;border-top:1px solid gray;border-bottom-right-radius: 0px; border-bottom-left-radius: 0px;}");
    rFlag=false;lFlag=true;cFlag=false;
    on_L_clicked();
}

void ICM::on_cBut_clicked()
{
    //	m_strRLC = "Capacitance";
    ui->selectFrame->setGeometry(701,254,10,60);
    ui->rBox->setStyleSheet("QGroupBox{border:1px solid white; background-color: #dadbde;border-radius:10px;border-bottom:1px qlineargradient(x1: 0, y1: 0,stop: 0 #f6f7fa, stop: 1 #dadbde); border-bottom-right-radius: 0px;border-bottom-left-radius: 0px;}");
    ui->lBox->setStyleSheet("QGroupBox{border:1px solid white; background-color: #dadbde;border-radius:10px;border-bottom:1px qlineargradient(x1: 0, y1: 0,stop: 0 #f6f7fa, stop: 1 #dadbde);border-bottom-right-radius: 0px; border-bottom-left-radius: 0px;border-top:1px solid gray; border-top-right-radius: 0px; border-top-left-radius: 0px;}");
    ui->cBox->setStyleSheet("QGroupBox{border:1px solid white; background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #3a5976, stop: 1 #000000);border-radius:10px;border-top:1px qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #f6f7fa, stop: 1 #dadbde); border-top-right-radius: 0px; border-top-left-radius: 0px;border-top:1px solid gray;border-bottom-right-radius: 0px; border-bottom-left-radius: 0px;}");
    rFlag=false;lFlag=false;cFlag=true;
    on_C_clicked();
}

void ICM::on_ACDC_clicked()
{
    on_RacRdc_clicked();
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Frequency Sweep~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void ICM::on_graphBut_clicked()
{
    if(graphWidget->isVisible()){
        graphWidget->setVisible(false);
        if(panelStatus.dPanel){
            ui->frontPanel_ICM->setVisible(false);
            ui->debugPanel->setVisible(true);
        }
        else{
            ui->frontPanel_ICM->setVisible(true);
            ui->debugPanel->setVisible(false);
        }
    }
    else{
        ui->frontPanel_ICM->setVisible(false);
        ui->debugPanel->setVisible(false);
        graphWidget->setVisible(true);
        graphLoop=0;
    }
}

void ICM::on_sweep_capture_clicked()
{

    /*
	x.clear();y.clear();
	QFile outFile("ICMGraph.log");
	//    if (outFile.size() > 1298368)
	outFile.open(QIODevice::WriteOnly | QIODevice::Text);
	//    else
	//        outFile.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append);
	QTextStream ts(&outFile);
	int loop=0;
	xSize = ySize = m_nSweepEndFrequency;

	if(ui->rangeLabel->text().endsWith("pF")){
                ySize = convertToValues(ui->rangeLabel->text())*10e12;
        }else if(ui->rangeLabel->text().endsWith("nF")){
                ySize = convertToValues(ui->rangeLabel->text())*10e9;
        }else if(ui->rangeLabel->text().endsWith("uF") || ui->rangeLabel->text().endsWith("uH")){
                ySize = convertToValues(ui->rangeLabel->text())*10e6;
        }else if(ui->rangeLabel->text().endsWith("mF") || ui->rangeLabel->text().endsWith("mH")){
                ySize = convertToValues(ui->rangeLabel->text())*10e3;
        }else if(ui->rangeLabel->text().endsWith("KE")){
                ySize = convertToValues(ui->rangeLabel->text());
        }else if(ui->rangeLabel->text().endsWith("ME")){
                ySize = convertToValues(ui->rangeLabel->text());
        }

	setupSimpleDemo(ui->customPlot);
	qDebug()<<"xSize"<<xSize<<"ySize"<<ySize;
	x.resize(xSize);
	y.resize(ySize);

	qDebug()<<"SweepStartFrequency:"<<m_nSweepStartFrequency;
	qDebug()<<"SweepEndFrequency:"<<m_nSweepEndFrequency;
	qDebug()<<"SweepInterval:"<<m_nSweepInterval;
	loop=0;
	for(int i=m_nSweepStartFrequency;i<=m_nSweepEndFrequency;i=i+m_nSweepInterval){
		hwInterface->setFrequency((double)i);
		m_nFrequency = (double)i;
		sleep(1);
		readADC();
		x[loop]=(double)i;
		if (ui->ResistanceRanges->isVisible()) {
			y[loop]=(m_nResistance);
			qDebug()<<"Frequency:"<<i<<"Resistance:"<<(m_nResistance);
			ts << QString("Frequency:") << "\t" << m_nFrequency<< "\t"<<QString("Resistance:") << "\t" << m_nResistance<<"\n";
		}else if(ui->CapacitanceRanges->isVisible()){
			y[loop]=(m_nCapacitance);
			//			y[loop]=m_nResistance;
			qDebug()<<"Frequency:"<<i<<"Capacitance:"<<m_nResistance;//(m_nCapacitance);
			ts << QString("Frequency:") << "\t" << m_nFrequency<< "\t"<<QString("Capacitance:") << "\t" << m_nCapacitance<<"\n";
		}else if(ui->Inductorranges->isVisible()){
			y[loop]=(m_nInductance);
			//			y[loop]=m_nResistance;
			qDebug()<<"Frequency:"<<i<<"Indcuctance:"<<m_nResistance;//(m_nInductance);
			ts << QString("Frequency:") << "\t" << m_nFrequency<< "\t"<<QString("Inductance:") << "\t" << m_nInductance<<"\n";
		}
		loop++;
                //QApplication::processEvents();
	}
	plotSimpleDemo(ui->customPlot);
	ui->customPlot->replot();*/
}

void ICM::on_sweep_startfreq_valueChanged(int value )
{
    /*	m_nSweepStartFrequency2=value;
	m_nSweepStartFrequency=m_nSweepStartFrequency2*m_nSweepStartFrequencyUnit;*/
}

void ICM::on_sweep_startfreq_unit_currentIndexChanged(int index)
{
    /*
	if(index==0)		m_nSweepStartFrequencyUnit=1;
	else if(index==1)	m_nSweepStartFrequencyUnit=1000;
	m_nSweepStartFrequency=m_nSweepStartFrequency2*m_nSweepStartFrequencyUnit;

	 */

}

void ICM::on_sweep_endfreq_valueChanged(int value )
{
    /*	m_nSweepEndFrequency2=value;
	m_nSweepEndFrequency=m_nSweepEndFrequency2*m_nSweepEndFrequencyUnit;*/
}

void ICM::on_sweep_endfreq_unit_currentIndexChanged(int index)
{
    /*	if(index==0)		m_nSweepEndFrequencyUnit=1;
	else if(index==1)	m_nSweepEndFrequencyUnit=1000;
	m_nSweepEndFrequency=m_nSweepEndFrequency2*m_nSweepEndFrequencyUnit;*/

}

void ICM::on_sweep_interval_valueChanged(int value)
{
    /*	m_nSweepInterval2=value;
	m_nSweepInterval=m_nSweepInterval2*m_nSweepIntervalUnit;*/
}

void ICM::on_sweep_interval_unit_currentIndexChanged(int index)
{
    /*	if(index==0)		m_nSweepIntervalUnit=1;
	else if(index==1)	m_nSweepIntervalUnit=1000;
	m_nSweepInterval=m_nSweepInterval2*m_nSweepIntervalUnit;*/
}



void ICM::on_butZoom_clicked()
{
    /*    QPropertyAnimation *animation = new QPropertyAnimation(ui->graphPlot, "geometry");
    animation->setEasingCurve(QEasingCurve::Linear);
    animation->setDuration(200);
    QPropertyAnimation *animation2 = new QPropertyAnimation(ui->graphPlotting, "geometry");
    animation2->setEasingCurve(QEasingCurve::Linear);
    animation2->setDuration(200);

    if(ui->butZoom->geometry().height()==147){
        ui->butZoom->setGeometry(2,7,690,385);
        animation->setStartValue(QRect(2,7,690,147));
        animation->setEndValue(QRect(2,7,690,385));
        animation2->setStartValue(QRect(10,434,690,147));
        animation2->setEndValue(QRect(10,204,690,385));
        animation->start();
        animation2->start();
    }else{
        ui->butZoom->setGeometry(2,7,690,147);
        animation->setStartValue(QRect(2,7,690,385));
        animation->setEndValue(QRect(2,7,690,147));
        animation2->setStartValue(QRect(10,204,690,385));
        animation2->setEndValue(QRect(10,434,690,147));
        animation->start();
        animation2->start();
    }*/
}

void ICM::on_pbHold_clicked()
{
    on_ONOFF_clicked();
}

void ICM::on_pbRel_clicked()
{
    on_NULL_2_clicked();
    if (m_bNull==true)
        ui->pbRel->setStyleSheet(
                "QPushButton {color:white;border: 1px solid #2D5059;border-radius: 20px;background-color: qlineargradient(x1: 0, y1: 1, x2: 1, y2: 0,stop: 0 #e59244, stop: 0.6 #ffa500 , stop:1 #FFFFFF);font:bold;}");
    else
        ui->pbRel->setStyleSheet(
                "QPushButton{color:white;border: 1px solid #2D5059;border-radius: 20px;background-color: qlineargradient(x1: 0, y1: 1, x2: 1, y2: 0,stop: 0 #1A74DB, stop: 0.6 #5293DE, stop:1 #FFFFFF);font:bold; }");

}

void ICM::on_pbSettings_clicked()
{
    on_settings_clicked();
}
