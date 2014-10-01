#include "lmh6518gui.h"
#include "ui_lmh6518gui.h"
#include "qwsevent_qws.h"



unsigned int LMH6518GUI::m_nMouseMoveCouter =0;

LMH6518GUI::LMH6518GUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LMH6518GUI)
{
    ui->setupUi(this);
    this->installEventFilter(this);

    QPluginLoader loaderApp("libPTApplicationcardInterface.so", this);
    IAppCard = qobject_cast<IApplicationCardInterface*> (loaderApp.instance());
    IAppCard->setDeviceName(SLOT0);
    IAppCard->enumerateAPPCard();
    IAppCard->setSPIAppendBit(0xC000);
    m_objLMH6518Component=new LMH6518(IAppCard);

	QPluginLoader testing("libAppBckPsoc.so", this);
	test = qobject_cast<IPTAppBckPsocInterface*> (testing.instance());

	m_eDataTemplateCH2.m_eChannelSel = CH2;
	m_eDataTemplateCH2.m_eLAttenuation=MINUS20_ATTENUATION;
	m_eDataTemplateCH2.m_eFilter=BW_FULL;
	m_eDataTemplateCH2.m_bPower=false;
	m_eDataTemplateCH2.m_nbPreAmp=false;
	m_eCH2Voltage = MV20;

    m_eDataTemplate.m_eChannelSel=CH1;
    m_eDataTemplate.m_eLAttenuation=MINUS20_ATTENUATION;
    m_eDataTemplate.m_eFilter=BW_FULL;
    m_eDataTemplate.m_bPower=false;
    m_eDataTemplate.m_nbPreAmp=false;
    m_eVoltage=MV20;

    m_mapAttenuation.insert(0,"0dB");   m_mapAttenuation.insert(1,"-2dB");
    m_mapAttenuation.insert(2,"-4dB");  m_mapAttenuation.insert(3,"-6dB");
    m_mapAttenuation.insert(4,"-8dB");  m_mapAttenuation.insert(5,"-10dB");
    m_mapAttenuation.insert(6,"-12dB"); m_mapAttenuation.insert(7,"-14dB");
    m_mapAttenuation.insert(8,"-16dB"); m_mapAttenuation.insert(9,"-18dB");
    m_mapAttenuation.insert(10,"-20dB");m_mapAttenuation.insert(11,"X1dB");
    m_mapAttenuation.insert(12,"X2dB"); m_mapAttenuation.insert(13,"X3dB");
    m_mapAttenuation.insert(14,"X4dB");	m_mapAttenuation.insert(15,"X5dB");

    ui->ladder->setText("-20dB");
    ui->Attenuater->setValue(10);

    m_objDSOWaveSettings = new DSOWaveSettings();
    m_objOffsetWindow = new OffsetWindow();
    connect(m_objOffsetWindow,SIGNAL(passDACValue(short int,double)),this,SLOT(doDACDrive(short int,double)));
    InitializeHardwareLibs();
    qDebug()<<"1:#######################################################################";
    initializeWaveForm();
    qDebug()<<"2:#######################################################################";
    InitLineEditSIGSnSLOTS();
    qDebug()<<"3:#######################################################################";
    initializeWaveSettingsLineEdit();
    qDebug()<<"4:#######################################################################";
    InitializeFGVariables();
    qDebug()<<"5:#######################################################################";

    unsigned int lValue=0;

    m_objTimerInterrupt = new QTimer(this);
    connect(m_objTimerInterrupt,SIGNAL(timeout()),this,SLOT(on_setForceTrigger()));
    setMouseTracking(true);

//    installEventFilter(IDSODisplay);





}

bool LMH6518GUI::evenFilter(QObject *target,QEvent *e)
{
//	qDebug()<<"Mouse Filter in LMH Main APP";
	QCoreApplication::processEvents(QEventLoop::ExcludeSocketNotifiers, 100);
	if(e->type() == QEvent::MouseMove)
	{
		//qDebug()<<"Mouse Filter in LMH Main APP";
		return evenFilter(target,e);
	}
}
bool LMH6518GUI::qwsEventFilter(QWSEvent *e)
{
	//   qDebug() <<"Inside QWS Filter"<< e->type;

	    return false;
}
//bool LMH6518GUI::qwsEvent(QWSEvent *event)
//{
//	if(event->type == QWSEvent::Mouse)
//	{
//		event->window();
//		//qDebug()<<"Mouse";
//		//initializeWaveForm();
//		//update();
//	}
//
//	QWidget::qwsEvent(event);
//	return true;
//}

void LMH6518GUI::openNumKBPanel(short int pValue)
{
        QWidget *w = INumberPanel->getNumKBPanel(pValue, this);
        w->setWindowFlags(Qt::WindowCloseButtonHint | Qt::Dialog);
        w->show();
}

void LMH6518GUI::initializeWaveSettingsLineEdit()
{
//	ui->leBDR->setVisible(false);
	ui->leBTUR->setVisible(false);
	ui->lePreTrigger->setVisible(false);

    m_obBTUR=ILineEdit->QmaxLineEdit(5,ui->grpTimeSettings);
    m_obBTUR->setGeometry(ui->leBTUR->geometry());
    m_obBTUR->setStyleSheet(ui->leBTUR->styleSheet());
    connect(m_obBTUR,SIGNAL(focussed(bool)), this, SLOT(callBTUREdit()));

    m_obBD=ILineEdit->QmaxLineEdit(6,ui->grpTimeSettings);
    m_obBD->setVisible(false);
//    m_obBD->setGeometry(ui->leBDR->geometry());
//    m_obBD->setStyleSheet(ui->leBDR->styleSheet());
    //connect(m_obBD,SIGNAL(focussed(bool)), this, SLOT(callBDREdit())); //commented by RRV


  //  m_objDSOWaveSettings = new DSOWaveSettings();
    //~~~~~~~~~~added by RRV~~~~~~~~~~
    m_nSystemFrequency=400000000;
    m_obBTUR->setText("400MHz");
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    on_cmbLMHVoltage_currentIndexChanged(2);
    on_cmbSamplingType_currentIndexChanged(0);

    ui->cmbMemory->setVisible(false);
    ui->cmbSamples->setVisible(false);
    ui->cmbTimeBase->setVisible(false);
    ui->cmbTimeUnit->setVisible(false);
	}


void LMH6518GUI::InitializeHardwareLibs(){

        QPluginLoader backplane("libBackPlaneInterface.so",this);
        IBackPlane = qobject_cast<IntefaceBackPlane*>(backplane.instance());
        IBackPlane->InitializeBpObject();

        QPluginLoader psoc("libPTPsocInterface2.so",this);
        IPsoc = qobject_cast<IPSOCCOMMUNICATION*>(psoc.instance());
        IPsoc->openSerial();

        QPluginLoader qmaxlib("libQmaxPTInterface.so",this);
        ILineEdit = qobject_cast<IQmaxLineEdit*>(qmaxlib.instance());
        INumberPanel=qobject_cast<IQmaxNumberPanel*>(qmaxlib.instance());

        // GPIO Events
        QPluginLoader loader3("libGPIOEventInterface.so",this);
        IGPIOEvent = qobject_cast<PTGPIOEventInterface*>(loader3.instance());
        m_nKeyCode=12;

    	QPluginLoader loader6("libPTKeyEventInterfaces.so", this);
    	IPTKeyEvent = qobject_cast<PTEventInterface*> (loader6.instance());
    	IPTKeyEvent->InvokeGPIOEvent(this, "/dev/input/event2", "pt_kpp",&m_nPTKeyCode);

    	m_bRunStop=false;

        hwInterface=new HardwareInterface();
        hwInterface->Init();

        IGPIOEvent->InvokeGPIOEvent(this, "/dev/input/event7", "gpioevent", &m_nKeyCode);
        IGPIOEvent->setApplicationID(DSO);
        connect(IGPIOEvent->getGPIOObject(),SIGNAL(postAPP(QList<unsigned char>,QList<unsigned char>)),this,SLOT(doIntPlot(QList<unsigned char>,QList<unsigned char>)));
        //commented by rrv on sep30,2014,commented as in DSOApp module
//        QMetaObject::invokeMethod(this,"doIntPlot(QList<unsigned char>,QList<unsigned char>))", Qt::DirectConnection);
        m_objDSOWaveSettings->disableInterrupt();
        m_objDSOWaveSettings->enableInterrupt();
        m_nIntFlag=false;
        m_objDSOWaveSettings->ReceiverConfiguration();
        m_nPrecount=5;
        m_eReceConf = RECEIVER1;
        m_eTrigger = EDGE_RISING;
		m_objDSOWaveSettings->configureReceiverAndTrigger(m_eReceConf,m_eTrigger);
}
void LMH6518GUI::KeyFunction() {
	if (m_nPTKeyCode == 1) {
		qDebug() << ("\nMENU");
	} else if (m_nPTKeyCode == 2) {
		qDebug() << ("\nESC");
		this->close();
	} else if (m_nPTKeyCode == 3) {
		qDebug() << ("\nNULL");
	} else if (m_nPTKeyCode == 4)
	{
		qDebug() << ("\nF1");
		setDefaultColor();
		ui->cmbChannel->setStyleSheet("background-color: #ffaa00");
		m_nComboCounter = ui->cmbChannel->count()-1;
		m_nUpCounter=0;
		m_nLeftMove=-1;
		m_nTriggerSelect=-1;
		m_nChannelSelect=1;
	}
	else if (m_nPTKeyCode == 5)
	{
		qDebug() << ("\nF2");
		setDefaultColor();
		m_nComboCounter = ui->cmbTriggerSoruce->count()-1;
		m_nUpCounter=0;
		ui->cmbTriggerSoruce->setStyleSheet("background-color: #ffaa00");
		m_nLeftMove=-1;
		m_nChannelSelect=-1;
		m_nTriggerSelect=1;

	} else if (m_nPTKeyCode == 6)
	{
		qDebug() << ("\nF3");
		on_butForceTrigger_clicked();
	} else if (m_nPTKeyCode == 7) {
		qDebug() << ("\nF4");
	} else if (m_nPTKeyCode == 8) {
		qDebug() << ("\nF5");
	} else if (m_nPTKeyCode == 9) {
		qDebug() << ("\nUP");
		if(m_nUpCounter>0)
			m_nUpCounter--;
		else
			m_nUpCounter=m_nComboCounter;
		moveUp();

	} else if (m_nPTKeyCode == 10)
	{
		qDebug() << ("\nDOWN");
		//qDebug() << "Up Counter:"<<m_nUpCounter<<m_nComboCounter;
		if(m_nUpCounter<m_nComboCounter)
			m_nUpCounter++;
		else
			m_nUpCounter=0;
		moveDown();
	} else if (m_nPTKeyCode == 11)
	{
		m_nChannelSelect=0;
		m_nTriggerSelect=0;

		qDebug() << ("\nRIGHT");
		if(m_nLeftMove<8)
			m_nLeftMove++;
		else
			m_nLeftMove=0;
		moveLeft();

	} else if (m_nPTKeyCode == 12)
	{
		if(m_nLeftMove >0)
			m_nLeftMove--;
		moveLeft();
		qDebug() << ("\nLEFT");

	} else if (m_nPTKeyCode == 13) {
		qDebug() << ("\nENTER");
	} else if (m_nPTKeyCode == 14) {
		qDebug() << ("\nSETUP");
	} else if (m_nPTKeyCode == 15) {
		qDebug() << ("\nDEFAULT");
	} else if (m_nPTKeyCode == 16) {
		qDebug() << ("\nTOUCH");
	} else if (m_nPTKeyCode == 17)
	{
		qDebug() << ("\nFILE");
		clickedPRSCR();
	} else if (m_nPTKeyCode == 18) {
		qDebug() << ("\nSCALE");
	} else if (m_nPTKeyCode == 19) {
		qDebug() << ("\nRUN/STOP");
		if(m_bRunStop==false)
			on_butRUN_clicked();
		else
			on_butSTOP_clicked();
	}
}
void LMH6518GUI::InitLineEditSIGSnSLOTS(){

    LEfrequency=ILineEdit->QmaxLineEdit(1,ui->PARAMETRS);
    LEfrequency->setGeometry(ui->lefrequency->geometry());
    LEfrequency->setStyleSheet(ui->lefrequency->styleSheet());
    connect(LEfrequency,SIGNAL(focussed(bool)), this, SLOT(callFrequencyedit(bool)));

    LEamplitude=ILineEdit->QmaxLineEdit(2,ui->PARAMETRS);
    LEamplitude->setGeometry(ui->leamplitude->geometry());
    LEamplitude->setStyleSheet(ui->leamplitude->styleSheet());
    connect(LEamplitude,SIGNAL(focussed(bool)), this, SLOT(callAmplitudeedit(bool)));

    LEoffset=ILineEdit->QmaxLineEdit(3,ui->PARAMETRS);
    LEoffset->setGeometry(ui->leoffset->geometry());
    LEoffset->setStyleSheet(ui->leoffset->styleSheet());
    connect(LEoffset,SIGNAL(focussed(bool)), this, SLOT(callOffsetedit(bool)));

    LEphase=ILineEdit->QmaxLineEdit(4,ui->PARAMETRS);
    LEphase->setGeometry(ui->lephase->geometry());
    LEphase->setStyleSheet(ui->lephase->styleSheet());
    connect(LEphase,SIGNAL(focussed(bool)), this, SLOT(callPhaseedit(bool)));

    LEDACValue=ILineEdit->QmaxLineEdit(8,ui->m_tabDAC);
    LEDACValue->setGeometry(ui->m_leDACValue->geometry());
    LEDACValue->setStyleSheet(ui->m_leDACValue->styleSheet());
    connect(LEDACValue,SIGNAL(focussed(bool)), this, SLOT(callDACValue(bool)));

//    QPluginLoader loaderAD9102("libAD9102GUI.so", this);
//    AD9102 = qobject_cast<IAD9102TestJigInterface*> (loaderAD9102.instance());
//    AD9102->setAD9102(ui->tab_4);
}
void LMH6518GUI::InitializeFGVariables(){

        hwInterface->Drive(STOPDRIVE);
        IPsoc->FGMeasurement();
        IBackPlane->writeBackPlaneRegister(0x2, 0x26);

        QString deg = QChar(0x00B0);

        LEfrequency->setText("1KHz");
        LEamplitude->setText("0.4Vpp");
        LEoffset->setText("0V");
        LEphase->setText("0"+deg);

        ui->sine->setChecked(true);
        on_sine_clicked();

        hwInterface->setFrequency(1000);
        hwInterface->setAmplitude(0.2);
        hwInterface->setOffset(0);
        hwInterface->setPhase(0);
        IAppCard->writeRegister(0x7,0x34);
        IAppCard->writeRegister(0x41,0x36);
        IAppCard->writeRegister(0x1,0x38);

        ui->cmbSamplingType->setCurrentIndex(0);
}
void LMH6518GUI::openNumKBPanel(short int pValue, double incDec, char type,double max, double min) {
        QWidget *m_w = INumberPanel->getNumKBPanelIncDec(pValue, incDec, type, max,min, this);
        m_w->setWindowFlags(Qt::WindowCloseButtonHint | Qt::Dialog);
        m_w->show();
}
void LMH6518GUI::callFrequencyedit(bool value){
    Q_UNUSED(value)
                if (LEfrequency->hasFocus()) {
                        openNumKBPanel(1,1.0,'F',20000000.0,0.01);
                        m_nLineEditIndex = 1;
                }
}
void LMH6518GUI::callAmplitudeedit(bool value){
    Q_UNUSED(value)
            if (LEamplitude->hasFocus()) {
            		if(ui->chkInt_Ext->isChecked() == false)
            			openNumKBPanel(1,0.1,'V',1.0,0.01);
            		else
            			openNumKBPanel(1,0.1,'V',10.0,0.01);
                    m_nLineEditIndex = 2;
            }
}
void LMH6518GUI::callOffsetedit(bool value){
    Q_UNUSED(value)
            if (LEoffset->hasFocus()) {
                    openNumKBPanel(1,1.0,'v',5.0,-5.0);
                    m_nLineEditIndex = 3;
            }
}
void LMH6518GUI::callPhaseedit(bool value){
    Q_UNUSED(value)
                        if (LEphase->hasFocus()) {
                     openNumKBPanel(1,1.0,'D',360,0);
                      m_nLineEditIndex = 4;
            }
}
void LMH6518GUI::callDACValue(bool value){
    Q_UNUSED(value)
                if (LEDACValue->hasFocus()) {
                     openNumKBPanel(1,0.1,'v',2.5,0);
                      m_nLineEditIndex = 8;
            }
}
void LMH6518GUI::updatePrecount(unsigned short pValue)
{
	m_obPreTriggerCount->setText(QString::number(pValue,10));
	m_objDSOWaveSettings->setPreSampleCount(pValue);
	m_objDSOWaveSettings->setPostSampleCount((m_nSamples-pValue));
	ui->lePosTrigger->setText(QString::number((m_nSamples-pValue),10));

}
void LMH6518GUI::receiveValue(uint pValue) {
    //Q_UNUSED(pValue)
	if(m_nLineEditIndex==7)
	{
//		qDebug()<<"Count :"<<pValue;
		m_obPreTriggerCount->setText(QString::number(pValue,10));
		m_objDSOWaveSettings->setPreSampleCount(pValue);
		m_objDSOWaveSettings->setPostSampleCount((m_nSamples-pValue));
		ui->lePosTrigger->setText(QString::number((m_nSamples-pValue),10));
	}


}
void LMH6518GUI::receiveValue(QString pValue) {
	//qDebug()<<pValue;
    if(m_nLineEditIndex==1)
        LEfrequency->setText(pValue);
    if(m_nLineEditIndex==2)
        LEamplitude->setText(pValue);
    if(m_nLineEditIndex==3)
        LEoffset->setText(pValue);
    if(m_nLineEditIndex==4)
        LEphase->setText(pValue);
    if(m_nLineEditIndex==5)
    	m_obBTUR->setText(pValue);
    if(m_nLineEditIndex==8)
    	LEDACValue->setText(pValue);
}
void LMH6518GUI::receiveValue(double pValue) {
//	qDebug()<<pValue;
    if(m_nLineEditIndex==1){
//    qDebug()<<"Frequency :"<<pValue;
    m_nFrequency=pValue;
    hwInterface->setFrequency(m_nFrequency);
    }
    if(m_nLineEditIndex==2){
       // qDebug()<<"Amplitude :"<<pValue;
        m_nAmplitude=pValue;
        hwInterface->setAmplitude(m_nAmplitude/2);
    }
    if(m_nLineEditIndex==3){
       // qDebug()<<"Offset :"<<pValue;
        hwInterface->setOffset(pValue);
    }
    if(m_nLineEditIndex==4){
       // qDebug()<<"Phase :"<<pValue;
        hwInterface->setPhase(pValue);
    }
    if(m_nLineEditIndex==5){
       // qDebug()<<"BTUR :"<<pValue;
        m_obBTUR->setText(QString::number(pValue,'f',2));
//        m_objDSOWaveSettings->setDSOBTUR(pValue);			//commented by RRV

        //~~~~~~~~~~~~~~~~added by RRV~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        m_nSystemFrequency=pValue;

        m_nFTW=pow(2,32)*((m_nOutputFrequency)/m_nSystemFrequency);
        ui->leBDR->setText(QString::number(m_nFTW,16));
		m_nFTW_LSB = ((unsigned int) m_nFTW << 16) >> 16;
		m_nFTW_MSB = (unsigned int) m_nFTW >> 16;
		m_objDSOWaveSettings->setDSOBTUR(m_nFTW_MSB);
		m_objDSOWaveSettings->setDSOBDR(m_nFTW_LSB);
		//IAppCard->writeRegister(m_nFTW_MSB,0x98);
		//IAppCard->writeRegister(m_nFTW_LSB,0x9A);
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    }
    if(m_nLineEditIndex==6){
        qDebug()<<"BDR :"<<pValue;
        m_obBD->setText(QString::number(pValue,'f',2));
        m_objDSOWaveSettings->setDSOBDR(pValue);
        //hwInterface->setPhase(pValue);
    }
    if(m_nLineEditIndex==8){
    //	qDebug()<<"DAC Value:"<<pValue;
    	if(ui->m_rbDACA->isChecked())
    		hwInterface->setDAC(DACA,pValue);
    	if(ui->m_rbDACB->isChecked())
    	    hwInterface->setDAC(DACB,pValue);
    	if(ui->m_rbDACC->isChecked())
    	    hwInterface->setDAC(DACC,pValue);
    	if(ui->m_rbDACD->isChecked())
    	    hwInterface->setDAC(DACD,pValue);
    	if(ui->m_rbDACE->isChecked())
    	    hwInterface->setDAC(DACE,pValue);

    }

}
void LMH6518GUI::initializeWaveForm()
{
    m_nMaxRecordLength = 1000;
    m_nSampleIndex=9;
    m_nSampleUnit=0;
    m_nCmbampleIndex=0;

    m_nVoltPerDivision=0.0;
    m_nTimebaseTriggerPoint=0.0;
    m_nVoltageTriggerPoint=0.0;
    m_nTimeUnitIndex=0;
    m_nSampleRate[0]=1.0;
    m_nSampleRate[1]=2.0;
    m_nSampleRate[2]=2.5;
    m_nSampleRate[3]=5.0;
    m_nSampleRate[4]=10.0;
    m_nSampleRate[5]=25.0;
    m_nSampleRate[6]=50.0;
    m_nSampleRate[7]=100.0;
    m_nSampleRate[8]=250.0;
    m_nSampleRate[9]=500.0;
    m_nSamples=0;
    m_nLeftMove = m_nRightMove=0;
    m_nUpCounter=m_nDownCounter=0;
    m_nPrecount=m_nPostCount=0;

    m_obPreTriggerCount=ILineEdit->QmaxLineEdit(7,ui->grpSamples);
    m_obPreTriggerCount->setGeometry(ui->lePreTrigger->geometry());
    m_obPreTriggerCount->setStyleSheet(ui->lePreTrigger->styleSheet());
    connect(m_obPreTriggerCount,SIGNAL(focussed(bool)), this, SLOT(callPreTriggerCount()));


	QPluginLoader loader2("libDISPLAYWidgetInterface.so",this);
	IDSODisplay = qobject_cast<DisplayWidgetInterface*>(loader2.instance());
	QRect rect(0,0,675,310);

	IDSODisplay->getDisplayWidget()->setParent(ui->graphW);
//    //rect = this->geometry();
	IDSODisplay->getDisplayWidget()->setGeometry(rect);
//  //  qDebug()<<"X:"<<rect.x()<<"Y:"<<rect.y()<<"W:"<<rect.width()<<"H:"<<rect.height();
//	//rect.setX(0);rect.setY(0);rect.setWidth(700);rect.setHeight(300);
	IDSODisplay->initializeWaveDisplay(rect);
    IDSODisplay->setBorderGeometry(rect.x(),rect.y(),rect.width(),rect.height());
    IDSODisplay->hideHorizontalCursors(0,true);
    IDSODisplay->hideHorizontalCursors(1,true);
   IDSODisplay->hideVerticalCursors(0,true);
   IDSODisplay->hideVerticalCursors(1,true);
//   //qDebug()<<"Time";
    IDSODisplay->setTimePerDivision(10,NANOSECONDS,CHANNEL1);
    IDSODisplay->setTimePerDivision(10,NANOSECONDS,CHANNEL3);
    IDSODisplay->setMaxRecordLength(m_nMaxRecordLength,0);
    IDSODisplay->setMaximumSampleRate(m_nSampleRate[m_nSampleIndex],MEGAS);
    IDSODisplay->setVoltPerDivision(0.1,CHANNEL1);
    IDSODisplay->setVoltPerDivision(0.1,CHANNEL3);


    //for checking purpose
    //QRect rect(0,0,1,1);
//    QRect rect1(0,0,635,300);
//    view = new QGraphicsView(ui->graphW);
//    view->setOptimizationFlags(QGraphicsView::DontSavePainterState);
//    view->setViewportUpdateMode(QGraphicsView::SmartViewportUpdate);
//    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
//    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
//    view->setRenderHints(QPainter::SmoothPixmapTransform);
//    view->setFrameStyle(QFrame::NoFrame);
//
//    view->setGeometry(rect1);
//    scene = new QGraphicsScene();
//    view->setScene(scene);
//    view->setBackgroundBrush(QBrush(QColor(Qt::black),Qt::SolidPattern));
//    QColor color(Qt::white);
//    item = new checkItem(color, 0, 0);
//    QColor chColor(Qt::yellow);
//    chItem = new channelItem(chColor);
//    item->setBorderRect(rect1);
//    item->setPlotSettings(new PlotXYSettings(0.0,0.0000001,10.0,8.0,0.0,-0.5,0.5));
//    chItem->setBorderRect(rect1);
//    chItem->setPlotSettings(new PlotXYSettings(0.0,0.0000001,10.0,8.0,0.0,-0.5,0.5));
//    //item->setPos(QPointF(100, 10));
//    item->setEnabled(false);
//    scene->addItem(item);
//    scene->addItem(chItem);




//    QRectF rectF(0,0,600,310);
//    PlotXYSettings* l_objSettings = new PlotXYSettings(0.0,0.0000001,10.0,8.0,0.0,-0.5,0.5);
//
//    m_objDSOGridView = new DSOXYGridView(ui->graphW);
//    m_objDSOGridView->constructDSOPlane(rectF,l_objSettings);
    qDebug()<<"---Finished";
//    m_objChannelDataView = new DSOChannelDataView(ui->graphW);
//    m_objChannelDataView->intializeChannelData(rectF,l_objSettings);

    //qDebug()<<"DSO Display";
    ui->cmbTimeUnit->setCurrentIndex(0);

    ui->cmbTimeBase->setCurrentIndex(8);
    ui->cmbMemory->setCurrentIndex(4);
    ui->cmbSamples->setCurrentIndex(1);
    ui->cmbCouplingR1->setCurrentIndex(0);
    ui->cmbCouplingR2->setCurrentIndex(0);



    ui->cmbChannel->setCurrentIndex(0);
    ui->cmbTriggerSoruce->setCurrentIndex(0);
    ui->optAuto->setChecked(true);
    ui->chkR1->setChecked(true);

    ui->chkCH1Even->setChecked(true);
    ui->chkCH1Odd->setChecked(true);
    ui->chkCH2Even->setChecked(true);
    ui->chkCH2Odd->setChecked(true);

//    on_cmbTimeBase_currentIndexChanged(8);
//    on_cmbTimeUnit_currentIndexChanged(m_nTimeUnitIndex);
//    on_cmbSamples_currentIndexChanged(1);
//    on_cmbMemory_currentIndexChanged(4);
    initializeTimeBaseList();
    initializeMemoryList();

    on_timebaseDial_sliderMoved(19);
    on_memoryDial_sliderMoved(2);
   // ui->timebaseDial->set
    ui->timebaseDial->setSingleStep(19);
    ui->memoryDial->setSingleStep(2);

    moveLeft();

    connect(ui->cmbTimeBase, SIGNAL(activated(int)), this, SLOT(getComboIndex(int)));
}

LMH6518GUI::~LMH6518GUI()
{
    delete ui;
}

void LMH6518GUI::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void LMH6518GUI::on_Exit_clicked()
{
    this->close();
}

void LMH6518GUI::on_Attenuater_valueChanged(int value)
{
	m_eDataTemplate.m_eLAttenuation=LM6518_LADDER_ATTENUATION(value);
    ui->ladder->setText(m_mapAttenuation.value(value));
}


void LMH6518GUI::on_LMHFilter_currentIndexChanged(int index)
{
	if(ui->cmbChannel->currentIndex() ==0){
		m_eDataTemplate.m_eFilter=LMH6518_FILTER(index);
		m_objLMH6518Component->configureLMH6518DW(m_eDataTemplate);
	}
	else if(ui->cmbChannel->currentIndex() ==1)
	{
		m_eDataTemplateCH2.m_eFilter=LMH6518_FILTER(index);
		m_objLMH6518Component->configureLMH6518DW(m_eDataTemplateCH2);

	}

}
void LMH6518GUI::on_LMHPowerMode_currentIndexChanged(int index)
{
	if(ui->cmbChannel->currentIndex() ==0){
		if(index==0)
			m_eDataTemplate.m_bPower=false;
		else
			m_eDataTemplate.m_bPower=true;
		m_objLMH6518Component->configureLMH6518DW(m_eDataTemplate);
	}
	else if(ui->cmbChannel->currentIndex() ==1)
	{
		if(index==0)
			m_eDataTemplateCH2.m_bPower=false;
		else
			m_eDataTemplateCH2.m_bPower=true;
		m_objLMH6518Component->configureLMH6518DW(m_eDataTemplateCH2);

	}

}


void LMH6518GUI::on_PowerMode_currentIndexChanged(int index)
{
		if(index==0)
			m_eDataTemplate.m_bPower=false;
		else
			m_eDataTemplate.m_bPower=true;
		m_objLMH6518Component->configureLMH6518DW(m_eDataTemplate);
}

void LMH6518GUI::on_PreAmpGain_currentIndexChanged(int index)
{
		if(index==0)
			m_eDataTemplate.m_nbPreAmp=false;
		else
			m_eDataTemplate.m_nbPreAmp=true;

}

void LMH6518GUI::on_Filter_currentIndexChanged(int index)
{
	m_eDataTemplate.m_eFilter=LMH6518_FILTER(index);
}

void LMH6518GUI::on_Write_clicked()
{

	   unsigned short l_nData =0;
	   l_nData |= m_eDataTemplate.m_eFilter<<6;//added by RRV
	   if(m_eDataTemplate.m_nbPreAmp == true)
		   l_nData |=0x10;//added by RRV
	   l_nData |= m_eDataTemplate.m_eLAttenuation;//added by RRV
	   if(m_eDataTemplate.m_bPower == true)
		   l_nData |=0x200;//added by RRV
	   ui->Data->setText("0x"+QString::number(l_nData,16));

	   on_Calculate_clicked();

    m_objLMH6518Component->configureLMH6518DW(m_eDataTemplate);
}

void LMH6518GUI::on_Voltage_currentIndexChanged(int index)
{
	if(ui->cmbChannel->currentIndex() ==0 )
		m_eVoltage=VOLTAGEPERDIVISION(index);
	else
		m_eCH2Voltage=VOLTAGEPERDIVISION(index);
}

void LMH6518GUI::on_chkInt_Ext_clicked()
{
	if(ui->chkInt_Ext->isChecked()==true)
	{
		IAppCard->writeRegister(0x7,0x34);
	}
	else
	{
		IAppCard->writeRegister(0x4,0x34);
	}
}


void LMH6518GUI::on_cmbSamplingType_currentIndexChanged(int index)
{
	m_objDSOWaveSettings->setSamplingType(SAMPLING_TYPE(index));
	updateValues();
	//IDSODisplay->setSamplesCount(m_nPrecount,(m_nSamples-m_nPrecount),SAMPLING_TYPE(index));
	//m_objDSOGridView->setSamplesCount(m_nSamples,SAMPLING_TYPE(index));
}

void LMH6518GUI::on_cmbLMHVoltage_currentIndexChanged(int index)
{
//	qDebug()<<"Select Voltage:"<<ui->cmbLMHVoltage->currentText();
	double l_nVoltDivArray[9]={0.002,0.002,0.002,0.002,0.002,0.01,0.01,0.01,0.1};

	//qDebug()<<"Current Index:"<<ui->cmbChannel->currentIndex();
	if(ui->cmbChannel->currentIndex()==0){
		m_eVoltage=VOLTAGEPERDIVISION(index);
		m_objLMH6518Component->calculateSignalPathGain(m_eVoltage);
		IDSODisplay->setFPAtteunationFactor(m_objLMH6518Component->getFPAttennation(),CHANNEL1);
		Data=m_objLMH6518Component->calculateGain();
		IDSODisplay->setFSSettings(Data.m_sOutput,CHANNEL1);
		IDSODisplay->setVoltPerDivision(m_objLMH6518Component->getVoltPerDivision(index),CHANNEL1);
		IGPIOEvent->setFSSettings(m_objLMH6518Component->getVoltPerDivision(index),IDSODisplay->getFSSettings(CHANNEL1),m_nSamples,IDSODisplay->getRectWidth(),0);
	}

	else
	{
		m_eCH2Voltage =VOLTAGEPERDIVISION(index);
		m_objLMH6518Component->calculateSignalPathGain(m_eCH2Voltage);
		IDSODisplay->setFPAtteunationFactor(m_objLMH6518Component->getFPAttennation(),CHANNEL3);
		DataCH2=m_objLMH6518Component->calculateGain();
		IDSODisplay->setFSSettings(DataCH2.m_sOutput,CHANNEL3);
		IDSODisplay->setVoltPerDivision(m_objLMH6518Component->getVoltPerDivision(index),CHANNEL3);
		IGPIOEvent->setFSSettings(m_objLMH6518Component->getVoltPerDivision(index),IDSODisplay->getFSSettings(CHANNEL3),m_nSamples,IDSODisplay->getRectWidth(),0);
	}


//	qDebug()<<"CH1 Voltage:"<<IDSODisplay->getVoltPerDivsion(CHANNEL1);
//	qDebug()<<"CH2 Voltage:"<<IDSODisplay->getVoltPerDivsion(CHANNEL3);
  // qDebug()<<"FP Attenuator:"<<m_objLMH6518Component->getFPAttennation();
   //qDebug()<<"Signal Gain:" <<m_objLMH6518Component->getSignalGain();
  // qDebug()<<"Ladder Atteunator:"<<m_objLMH6518Component->getLadderAtteunator(0);


   if(m_objLMH6518Component->getPreAmp()==true)
      qDebug()<<"HG";
   else
	   qDebug()<<"LG";
   //qDebug()<<"Data Output:"<<Data.m_sOutput;
  // qDebug()<<"Data FSADC:"<<Data.m_sFullScaleADC;
   double l_nTotalGain=0.0;

//	if(ui->cmbChannel->currentIndex()==0)
//	{
//		m_objDSOWaveSettings->convertToDecimation(IDSODisplay->getVoltPerDivsion(CHANNEL1),Data.m_sOutput,IDSODisplay->getRectWidth(),R1FIFO,m_nSamples,ui->chkCH1Odd->isChecked(),ui->chkCH1Even->isChecked());
//	}
//	else if(ui->cmbChannel->currentIndex()==1)
//	{
//		m_objDSOWaveSettings->convertToDecimation(IDSODisplay->getVoltPerDivsion(CHANNEL3),DataCH2.m_sOutput,IDSODisplay->getRectWidth(),R2FIFO,m_nSamples,ui->chkCH2Odd->isChecked(),ui->chkCH2Even->isChecked());
//	}
	//qDebug()<<"Volt Per Division:"<<IDSODisplay->getVoltPerDivsion();
	if(ui->cmbChannel->currentIndex()==0){
		m_eDataTemplate.m_eChannelSel=CH1;
		m_eDataTemplate.m_eLAttenuation=m_objLMH6518Component->getLadderAtteunator();
		m_eDataTemplate.m_eFilter=LMH6518_FILTER(ui->LMHFilter->currentIndex());
		m_eDataTemplate.m_bPower=false;
		if(m_objLMH6518Component->getPreAmp()==true)
			m_eDataTemplate.m_nbPreAmp=true;
		else
			m_eDataTemplate.m_nbPreAmp=false;
		if(m_objLMH6518Component->getPreAmp()==true)
			m_eDataTemplate.m_nbPreAmp=true;
		else
			m_eDataTemplate.m_nbPreAmp=false;
		if(m_eDataTemplate.m_nbPreAmp==true)
		{
			l_nTotalGain=m_objLMH6518Component->getLadderAtteunator(0)+38.86;
		}
		else
		{
			l_nTotalGain=m_objLMH6518Component->getLadderAtteunator(0)+18.86;
		}
		m_objLMH6518Component->configureLMH6518DW(m_eDataTemplate);
		unsigned short l_nData=m_objLMH6518Component->ReadLM6518(m_eDataTemplate2);
		qDebug()<<"LMH6518Data:"<<hex<<l_nData;

	//	qDebug()<<"Channel 1 Updated.";
	}
	else if(ui->cmbChannel->currentIndex()==1)
	{
			m_eDataTemplateCH2.m_eChannelSel=CH2;
			m_eDataTemplateCH2.m_eLAttenuation=m_objLMH6518Component->getLadderAtteunator();
			m_eDataTemplateCH2.m_eFilter=LMH6518_FILTER(ui->LMHFilter->currentIndex());
			m_eDataTemplateCH2.m_bPower=false;
			if(m_objLMH6518Component->getPreAmp()==true)
				m_eDataTemplateCH2.m_nbPreAmp=true;
			else
				m_eDataTemplateCH2.m_nbPreAmp=false;
			if(m_objLMH6518Component->getPreAmp()==true)
				m_eDataTemplateCH2.m_nbPreAmp=true;
			else
				m_eDataTemplateCH2.m_nbPreAmp=false;
			if(m_eDataTemplateCH2.m_nbPreAmp==true)
			{
				l_nTotalGain=m_objLMH6518Component->getLadderAtteunator(0)+38.86;
			}
			else
			{
				l_nTotalGain=m_objLMH6518Component->getLadderAtteunator(0)+18.86;
			}
			m_objLMH6518Component->configureLMH6518DW(m_eDataTemplateCH2);
			unsigned short l_nData=m_objLMH6518Component->ReadLM6518(m_eDataTemplate2);
			qDebug()<<"LMH6518Data:"<<hex<<l_nData;
		//	qDebug()<<"Channel 2 Updated.";
		}
	//qDebug()<<"PreAmp:"<<m_eDataTemplate.m_nbPreAmp;
//	qDebug()<<"Total Gain:"<<l_nTotalGain;
	ui->leGainDB->setText(QString::number(l_nTotalGain));
	ui->leTotalV->setText(QString::number(pow(10,l_nTotalGain/20)));

	// LM6518 Switching
	// Scope Switching
	if(ui->chkR1->isChecked()==true)
	{
	//	qDebug()<<"ATT Factor CH1:"<<IDSODisplay->getFPAtteunationFactor(CHANNEL1);
		if(ui->chkInt_Ext->isChecked()==false){
			//commented by rrv on sep30,2014
//			IPsoc->FG_Scope12(0,IDSODisplay->getFPAtteunationFactor(CHANNEL1),0xF);
		}
		else{
			//commented by rrv on sep30,2014
//			IPsoc->FG_Scope12(1,IDSODisplay->getFPAtteunationFactor(CHANNEL1),0xF);
		}
	}
	if(ui->chkR2->isChecked()==true)
	{
		//qDebug()<<"ATT Factor CH2:"<<IDSODisplay->getFPAtteunationFactor(CHANNEL3);
		if(ui->chkInt_Ext->isChecked()==false){
			//commented by rrv on sep30,2014
//			IPsoc->FG_Scope12(0,0xF,IDSODisplay->getFPAtteunationFactor(CHANNEL3));
		}
		else{
			//commented by rrv on sep30,2014
//			IPsoc->FG_Scope12(1,0xF,IDSODisplay->getFPAtteunationFactor(CHANNEL3));
		}
	}
//	qDebug()<<"Volt Per Division:"<<m_objLMH6518Component->getVoltPerDivision(index);
	ui->dblVerticalTrigger->setMaximum(m_objLMH6518Component->getVoltPerDivision(index)*4);
	ui->dblVerticalTrigger->setMinimum(m_objLMH6518Component->getVoltPerDivision(index)*-4);
	ui->dblVerticalTrigger->setSingleStep(l_nVoltDivArray[index]);
	ui->dblVerticalTrigger->setValue(0.0);
}
void LMH6518GUI::on_Read_clicked()
{
	unsigned short l_nData=0;
	if(ui->ChannelSel->currentIndex()==0)
		m_eDataTemplate2.m_eChannelSel=CH1;
	else
		m_eDataTemplate2.m_eChannelSel=CH2;
    l_nData=m_objLMH6518Component->ReadLM6518(m_eDataTemplate2);
    ui->Data->setText("0x"+QString::number(l_nData,16));
}
void LMH6518GUI::on_Calculate_clicked()
{
	if(ui->cmbChannel->currentIndex()==0)
		m_objLMH6518Component->calculateSignalPathGain(m_eVoltage);
	else
		m_objLMH6518Component->calculateSignalPathGain(m_eCH2Voltage);
	Data=m_objLMH6518Component->calculateGain();

	ui->TotalGain->setText(QString::number(Data.m_sOutput));
	double l_nTotalGain;
	bool ok=true;
	QString l_strAttenuatorValue=m_mapAttenuation.value(ui->Attenuater->value());
	l_strAttenuatorValue.chop(2);

	if(m_eDataTemplate.m_nbPreAmp==true){
		l_nTotalGain=l_strAttenuatorValue.toDouble(&ok)+30+8.86;
	}else{
		l_nTotalGain=l_strAttenuatorValue.toDouble(&ok)+10+8.86;
	}
	ui->totalGaindB->setText(QString::number(l_nTotalGain));
	ui->totalGainV->setText(QString::number(pow(10,l_nTotalGain/20)));
}
void LMH6518GUI::on_ChannelSel_currentIndexChanged(int index)
{
	if(index==0)
		m_eDataTemplate.m_eChannelSel=CH1;
	else
		m_eDataTemplate.m_eChannelSel=CH2;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~FG~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void LMH6518GUI::on_sine_clicked()
{
     hwInterface->SelectWaveForm(SINE_W);
}

void LMH6518GUI::on_square_clicked()
{
    hwInterface->SelectWaveForm(SQUARE_W);
}

void LMH6518GUI::on_ramp_clicked()
{
    hwInterface->SelectWaveForm(RAMPUP_W);
}

void LMH6518GUI::on_triangle_clicked()
{
    hwInterface->SelectWaveForm(TRIANGLE_W);
}

void LMH6518GUI::on_singleWave_clicked()
{
    hwInterface->SingleContinuous(SINGLE);
}

void LMH6518GUI::on_continuousWave_clicked()
{
    hwInterface->SingleContinuous(CONTINUOUS);
}

void LMH6518GUI::on_burstWave_clicked()
{

}

void LMH6518GUI::on_butSerialPanel_clicked()
{
	QWidget *newWidget = test->getPTAppBckPsoc();
	newWidget->setWindowTitle("AppCard BackPanel PSoC Panel");
	newWidget->show();

}

void LMH6518GUI::on_butTest_clicked()
{
	qDebug()<<"Test Voltage Selected";

}

void LMH6518GUI::on_startDrive_clicked()
{
	hwInterface->setAmplitude(m_nAmplitude/2);
	hwInterface->setFrequency(m_nFrequency);
    hwInterface->Drive(STARTDRIVE);
}

void LMH6518GUI::on_stopDrive_clicked()
{
    hwInterface->Drive(STOPDRIVE);
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/* DSO Wave Settings Tab
 *
 */


void LMH6518GUI::doDACDrive(short int pnDACSEL,double pnDACValue)
{
	qDebug()<<"Received DAC Sel:"<<pnDACSEL<<"Voltage:"<<pnDACValue;
    double l_nOffsetVoltage=0.0,l_nADCFS=0.75;
    double l_nScreenVoltage = 0.0;
    double l_nMidVoltage=0.0,l_nActVoltage=0.0;
//    qDebug()<<"Voltage Trigger Point:"<<m_nVoltageTriggerPoint;
   	l_nScreenVoltage = l_nActVoltage * 4.0;
    l_nOffsetVoltage = (m_nVoltageTriggerPoint * l_nADCFS) / l_nScreenVoltage;
//    double l_nDACOffset = 1.2 + l_nOffsetVoltage;
//
//    if(ui->cmbChannel->currentIndex() == 1)
//    	hwInterface->setDAC(DACB,l_nDACOffset); // CH1 Trigger - DAC
//    else if (ui->cmbChannel->currentIndex() == 1)
//    	hwInterface->setDAC(DACD,l_nDACOffset); // CH2 Trigger - DAC
//    else if(ui->cmbChannel->currentIndex() == 2)
//    	hwInterface->setDAC(DACE,l_nDACOffset); // EXT  Trigger - DAC

	if(pnDACSEL == 0)
	{
		hwInterface->setDAC(DACA,pnDACValue);
	}
	if(pnDACSEL == 2)
	{
		hwInterface->setDAC(DACC,pnDACValue);
	}

}

void LMH6518GUI::on_cmbTimeBase_currentIndexChanged(int index)
{
	Q_UNUSED(index);
	m_nTimePerSample = ui->cmbTimeBase->currentText().toDouble();
	ui->dblHorizontalTrigger->setMaximum(m_nTimePerSample*5);
	ui->dblHorizontalTrigger->setMinimum(m_nTimePerSample*-5);
	ui->dblHorizontalTrigger->setSingleStep(m_nTimePerSample/10.0);
	ui->dblHorizontalTrigger->setValue(0.0);
	//ui->dblHorizontalTrigger->value();
    IDSODisplay->setMaximumSampleRate(m_nSampleRate[9],MEGAS);
 //   qDebug()<<"Time Per Sample:"<<m_nTimePerSample;
	updateValues();
}

void LMH6518GUI::on_cmbTimeUnit_currentIndexChanged(int index)
{
	m_nTimeUnitIndex = index;
	ui->dblHorizontalTrigger->setMaximum(m_nTimePerSample*5);
	ui->dblHorizontalTrigger->setMinimum(m_nTimePerSample*-5);
	ui->dblHorizontalTrigger->setSingleStep(m_nTimePerSample);
	ui->dblHorizontalTrigger->setValue(0.0);
    IDSODisplay->setMaximumSampleRate(m_nSampleRate[9],MEGAS);
//	qDebug()<<"Time Per Sample:"<<m_nTimePerSample<<ui->cmbTimeUnit->currentText();
	updateValues();
}

void LMH6518GUI::on_cmbMemory_currentIndexChanged(int index)
{
	Q_UNUSED(index);
	double l_nSampleLength = ui->cmbMemory->currentText().toDouble();
//	qDebug()<<"Selected Memory Depth:"<<l_nSampleLength<<ui->cmbSamples->currentIndex();
	if(ui->cmbSamples->currentIndex() == 0)
		m_nMaxRecordLength = l_nSampleLength*1;
	else if(ui->cmbSamples->currentIndex() == 1)
		m_nMaxRecordLength = l_nSampleLength*1000;
	IDSODisplay->setMaxRecordLength(m_nMaxRecordLength,0);
    IDSODisplay->setMaximumSampleRate(m_nSampleRate[9],MEGAS);

	//IDSODisplay->setTimePerDivision()
	updateValues();

}

void LMH6518GUI::on_cmbChannel_currentIndexChanged(int index)
{

	if(index==0)
		m_eReceConf = RECEIVER1;
	else if(index ==1)
		m_eReceConf = RECEIVER2;
	else if(index ==2)
		m_eReceConf = EXTERNAL;
	m_objDSOWaveSettings->configureReceiverAndTrigger(m_eReceConf,m_eTrigger);
}

void LMH6518GUI::on_cmbTriggerSoruce_currentIndexChanged(int index)
{
	if(index==0)
		m_eTrigger = EDGE_RISING;
	else if(index ==1)
		m_eTrigger = EDGE_FALLING;
	else if(index == 2)
		m_eTrigger = PULSE_POSITIVE;
	else if(index ==3)
		m_eTrigger = PULSE_NEGATIVE;
	m_objDSOWaveSettings->configureReceiverAndTrigger(m_eReceConf,m_eTrigger);
}

void LMH6518GUI::updateValues()
{
	double l_nHTValue = -(ui->dblHorizontalTrigger->value());
	DSO_CHANNEL l_nChannel = (ui->cmbChannel->currentIndex()==0)?CHANNEL1:CHANNEL3;
	if(m_nTimeUnitIndex ==0)
	{

		IDSODisplay->setTimePerDivision(m_nTimePerSample,NANOSECONDS,l_nChannel);
		 m_nTimebaseTriggerPoint = l_nHTValue*(1/1000000000.0);
	}
	else if(m_nTimeUnitIndex ==2){
		IDSODisplay->setTimePerDivision(m_nTimePerSample,MILLISECONDS,l_nChannel);
		m_nTimebaseTriggerPoint = l_nHTValue*(1/1000.0);
	}
	else if(m_nTimeUnitIndex ==1)
	{
		IDSODisplay->setTimePerDivision(m_nTimePerSample,MICROSECONDS,l_nChannel);
		 m_nTimebaseTriggerPoint = l_nHTValue*(1/1000000.0);
	}
	else if(m_nTimeUnitIndex ==3){
		IDSODisplay->setTimePerDivision(m_nTimePerSample,SECONDS,l_nChannel);
		 m_nTimebaseTriggerPoint = l_nHTValue*(1/1.0);
	}

	IDSODisplay->calculateAcquisitionTime(l_nChannel);
	m_nVoltPerDivision=IDSODisplay->getVoltPerDivsion(l_nChannel);
	m_nVoltageTriggerPoint = ui->dblVerticalTrigger->value();
//	qDebug()<<"Voltage Trigger Point:"<<m_nVoltageTriggerPoint;
	 double l_nAcutualLength = IDSODisplay->calculateRecordLength();
	 qDebug()<<"-----Acutal Record Length-----:"<<l_nAcutualLength<<"Max Length:"<<m_nMaxRecordLength;
	 double l_nSampleRate=0.0;
	 unsigned int l_nRecordLength = 0;
	    if(l_nAcutualLength <= m_nMaxRecordLength){
	    //	qDebug()<<"Inside Max Memory";
	        l_nRecordLength = l_nAcutualLength;
	        m_nSamples = l_nAcutualLength;
	        l_nSampleRate = IDSODisplay->getMaximumSampleRate();
	        if(l_nSampleRate >500000000.0)
	        {
	        	l_nSampleRate = 500000000.0;
	        	IDSODisplay->setMaximumSampleRate(500,MEGAS);
	        }
	    }
	    else
	    {
	   // 	qDebug()<<"Greater than Max Memory";
	    	l_nRecordLength = validateSampleRate();
	    	l_nSampleRate = IDSODisplay->getMaximumSampleRate();
	        m_nSamples = l_nRecordLength;
	    }

	    //~~~~~~~~~~~~~~~~added by RRV~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	    m_nOutputFrequency=l_nSampleRate;

        m_nFTW=pow(2,32)*((m_nOutputFrequency)/m_nSystemFrequency);
        if(m_nFTW==0xFFFFFFFF)
        {

        }
        qDebug()<<hex<<"FTW:"<<m_nFTW<<m_nOutputFrequency<<m_nSystemFrequency;
        ui->leBDR->setText(QString::number(m_nFTW,16));
		m_nFTW_LSB = ((unsigned int) m_nFTW << 16) >> 16;
		m_nFTW_MSB = (unsigned int) m_nFTW >> 16;
		m_objDSOWaveSettings->setDSOBTUR(m_nFTW_MSB);
		m_objDSOWaveSettings->setDSOBDR(m_nFTW_LSB);

//		IAppCard->writeRegister(m_nFTW_MSB,0x98);
//		IAppCard->writeRegister(m_nFTW_LSB,0x9A);
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	   // short l_nPreCountSample = 5;
//		if(ui->cmbSamplingType->currentIndex() ==0 )
//			m_nSamples=IDSODisplay->getRectWidth();
	    InitializeTriggers();
    	double l_nSIndex = ui->dblHorizontalTrigger->value() / m_nTimePerSample;
		if(ui->chkR1->isChecked()==true)
		{
			//m_objDSOWaveSettings->convertToDecimation(IDSODisplay->getVoltPerDivsion(CHANNEL1),IDSODisplay->getFSSettings(CHANNEL1),IDSODisplay->getRectWidth(),R1FIFO,m_nSamples,ui->chkCH1Odd->isChecked(),ui->chkCH1Even->isChecked());
			m_objDSOWaveSettings->convertToDecimation(IDSODisplay->getVoltPerDivsion(CHANNEL1),IDSODisplay->getFSSettings(CHANNEL1),IDSODisplay->getRectWidth(),R1FIFO,m_nSamples,m_LstOdd,m_LstEven);
		}
		if(ui->chkR2->isChecked()==true)
		{
			//m_objDSOWaveSettings->convertToDecimation(IDSODisplay->getVoltPerDivsion(CHANNEL1),IDSODisplay->getFSSettings(CHANNEL1),IDSODisplay->getRectWidth(),R2FIFO,m_nSamples,ui->chkCH1Odd->isChecked(),ui->chkCH1Even->isChecked());
			m_objDSOWaveSettings->convertToDecimation(IDSODisplay->getVoltPerDivsion(CHANNEL1),IDSODisplay->getFSSettings(CHANNEL1),IDSODisplay->getRectWidth(),R2FIFO,m_nSamples,m_LstOdd,m_LstEven);
		}

    	unsigned int l_nTriggerSamples=m_objDSOWaveSettings->getTriggerSamples();
//    		if(ui->cmbSamplingType->currentIndex() ==0 )
//    			l_nTriggerSamples=IDSODisplay->getRectWidth();
		double l_nSamplesperPixel = (double)floor((double)l_nTriggerSamples/(double)IDSODisplay->getRectWidth());


    	unsigned int l_nPreSamples=0;
    	if(l_nTriggerSamples==0 || m_nSamples<l_nTriggerSamples)
    		l_nTriggerSamples = m_nSamples;
    	qDebug()<<"Trigger Samples:"<<l_nTriggerSamples;

	    if(l_nSIndex >0)
	    {
	    	//qDebug()<<"Index>0:"<<l_nSIndex;
	    	m_nPrecount = (l_nTriggerSamples/2)+((l_nTriggerSamples/10.0) * l_nSIndex);
	    	l_nPreSamples = (m_nSamples/2)+((m_nSamples/10.0) * l_nSIndex);
	    }
	    else if(l_nSIndex <0)
	    {
	    	//qDebug()<<"Index<0:"<<l_nSIndex;
	    	m_nPrecount = (l_nTriggerSamples/2)-((l_nTriggerSamples/10.0) * (-l_nSIndex));
	    	l_nPreSamples = (m_nSamples/2)-((m_nSamples/10.0) * (-l_nSIndex));
	    }
	    else if(l_nSIndex==0)
	    {
	    	m_nPrecount = (l_nTriggerSamples/2);
	    	l_nPreSamples = (m_nSamples/2);
	    }
	   // updatePrecount(l_nPrecountValue);
	   /* qDebug()<<"----------------------------------------------------";
	    qDebug()<<"Precount Samples:"<<m_nPrecount<<"PostCount Samples:"<<(m_nSamples-m_nPrecount);
		qDebug()<<"DSOUI:Time Per Division Values"<<m_nTimePerSample;
		qDebug()<<"Maximum Memory Length:"<<m_nMaxRecordLength;
	    qDebug()<<"Sample Rate:"<<l_nSampleRate;
	    qDebug()<<"Actual Record Length:"<<l_nRecordLength;
	    qDebug()<<"----------------------------------------------------";*/
	    IGPIOEvent->setFSSettings(m_nVoltPerDivision,IDSODisplay->getFSSettings(l_nChannel),m_nSamples,IDSODisplay->getRectWidth(),0);
	    IGPIOEvent->setSamplingType(SAMPLING_TYPE(ui->cmbSamplingType->currentIndex()));
	    ui->leDispFreq->setText(QString::number(l_nSampleRate,'f',2));
	    ui->leDispTSamples->setText(QString::number(l_nRecordLength,10));
		m_objDSOWaveSettings->setPreSampleCount(m_nPrecount);
		m_objDSOWaveSettings->setPostSampleCount((m_nSamples-l_nPreSamples));
		ui->lePosTrigger->setText(QString::number((m_nSamples-l_nPreSamples),10));
		ui->lePreTrigger->setText(QString::number(l_nPreSamples,10));
		m_obPreTriggerCount->setText(QString::number(l_nPreSamples,10));
		IDSODisplay->setSamplesCount(m_nPrecount,(m_nSamples-l_nPreSamples),SAMPLING_TYPE(ui->cmbSamplingType->currentIndex()));
		IDSODisplay->LoadOddEvenData(m_nVoltageTriggerPoint,m_nAcutalTriggertimeBase,true,true,l_nChannel,(l_nTriggerSamples-m_nPrecount),m_nPrecount);
		//chItem->setPlotData(m_objDSOWaveSettings->getYVectorPoints(CHANNEL1));
		IDSODisplay->setCH1VectorData(m_objDSOWaveSettings->getYVectorPoints(CHANNEL1));
		IDSODisplay->setCH2VectorData(m_objDSOWaveSettings->getYVectorPoints(CHANNEL2));
		IDSODisplay->setCH3VectorData(m_objDSOWaveSettings->getYVectorPoints(CHANNEL3));
		IDSODisplay->setCH4VectorData(m_objDSOWaveSettings->getYVectorPoints(CHANNEL4));
		//qDebug()<<"Update Values End............";
}


unsigned int LMH6518GUI::validateSampleRate()
{
	DSO_CHANNEL l_nChannel = (ui->cmbChannel->currentIndex()==0)?CHANNEL1:CHANNEL3;
	for(int l_nSampleUnit=0;l_nSampleUnit<3;l_nSampleUnit++)
	{
		for(int l_nSampleIndex=m_nSampleIndex-1;l_nSampleIndex>=0;l_nSampleIndex--)
		{
	    	if(l_nSampleUnit==0)
	    		IDSODisplay->setMaximumSampleRate(m_nSampleRate[l_nSampleIndex],MEGAS);
	    	else if(l_nSampleUnit==1)
	    		IDSODisplay->setMaximumSampleRate(m_nSampleRate[l_nSampleIndex],KILOS);
	    	else if(l_nSampleUnit==2)
	    		IDSODisplay->setMaximumSampleRate(m_nSampleRate[l_nSampleIndex],ONES);
	    	IDSODisplay->calculateAcquisitionTime(l_nChannel);
	    	double l_nAcutualLength = IDSODisplay->calculateRecordLength();
	    	 //qDebug()<<"-----Acutal Record Length-----:"<<l_nAcutualLength<<"Max Length:"<<m_nMaxRecordLength;
	    	if(l_nAcutualLength < m_nMaxRecordLength)
	    		return l_nAcutualLength;
		}
	}
	return 0;
}

void LMH6518GUI::callBTUREdit()
{
	 if (m_obBTUR->hasFocus())
	 {
//		openNumKBPanel(1);	//commented by RRV

		 QWidget *w = INumberPanel->getNumKBPanelIncDec(1,1,'F',500000000,1, this);
		         w->setWindowFlags(Qt::WindowCloseButtonHint | Qt::Dialog);
		         w->show();

		m_nLineEditIndex = 5;
	 }
}

void LMH6518GUI::callBDREdit()
{
	 if (m_obBD->hasFocus())
	 {
		openNumKBPanel(1);
		m_nLineEditIndex = 6;
	 }

}

void LMH6518GUI::callPreTriggerCount()
{
	if (m_obPreTriggerCount->hasFocus())
	{
		openNumKBPanel(2);
		m_nLineEditIndex = 7;
	}
}

void LMH6518GUI::on_optAuto_clicked()
{
//	//if(ui->optAuto->isChecked())
//	qDebug()<<"AutoClicked";
//	if(m_nIntFlag== false)
//	{
//		m_objDSOWaveSettings->enableInterrupt();
//		m_nIntFlag=true;
//	}
//	m_objDSOWaveSettings->DriveInterrupt();
}

void LMH6518GUI::on_butOffset_clicked()
{
	m_objOffsetWindow->show();
}

void LMH6518GUI::on_butRUN_clicked()
{
	if(ui->optSingle->isChecked()==true)
	{
		//m_objDSOWaveSettings->disableInterrupt();
		ui->leStatus->setText("Armed");
		if(m_nIntFlag== false)
		{
			m_objDSOWaveSettings->disableInterrupt();
			m_objDSOWaveSettings->enableInterrupt();
			m_nIntFlag=true;
		}

		//m_objDSOWaveSettings->Drive(true);
		m_objDSOWaveSettings->DriveInterrupt(true);
		m_nIntFlag=false;
	}
	if(ui->optAuto->isChecked()==true)
	{
		qDebug()<<"AutoClicked"<<m_nIntFlag;
	//	m_objTimerInterrupt->start(10);
		if(m_nIntFlag== false)
		{
			m_objDSOWaveSettings->disableInterrupt();
			m_objDSOWaveSettings->enableInterrupt();
			m_nIntFlag=true;
		}
		m_objDSOWaveSettings->DriveInterrupt();
	}
	if(ui->optNormal->isChecked() == true)
	{
		qDebug()<<"Normal Clicked"<<m_eReceConf<<m_eTrigger;
		ui->leStatus->setText("Armed");
		if(m_nIntFlag== false)
		{
			m_objDSOWaveSettings->disableInterrupt();
			m_objDSOWaveSettings->enableInterrupt();
			m_nIntFlag=true;
		}
		m_objDSOWaveSettings->DriveInterrupt(true);
	}
	m_bRunStop=true;
}

void LMH6518GUI::on_butSTOP_clicked()
{

	m_objDSOWaveSettings->Drive(false);
	if(m_nIntFlag==true && ( ui->optAuto->isChecked()==true || ui->optNormal->isChecked() == true))
	{
		m_objDSOWaveSettings->disableInterrupt();
		m_nIntFlag=false;
	}
	m_bRunStop=false;
}
void LMH6518GUI::InitializeTriggers()
{
	DSO_CHANNEL l_nChannel = (ui->cmbChannel->currentIndex()==0)?CHANNEL1:CHANNEL3;
    double l_nMidTimeBase = (IDSODisplay->getTimePerDivision(l_nChannel) * 10.0)/2.0;
    double l_nMidVoltage=0.0,l_nActVoltage=0.0;
	l_nMidVoltage = (IDSODisplay->getVoltPerDivsion(l_nChannel)*8.0)/2.0;
	l_nActVoltage = IDSODisplay->getVoltPerDivsion(l_nChannel);
   // qDebug()<<"Mid Voltage:"<<l_nMidVoltage<<"VoltageTriggerPoint:"<<m_nVoltageTriggerPoint;
    //qDebug()<<"Mid Time Base:"<<l_nMidTimeBase<<m_nTimebaseTriggerPoint;
    if(m_nTimebaseTriggerPoint >0)
        m_nAcutalTriggertimeBase = l_nMidTimeBase - m_nTimebaseTriggerPoint;
    else if(m_nTimebaseTriggerPoint <0)
        m_nAcutalTriggertimeBase = l_nMidTimeBase + (-m_nTimebaseTriggerPoint);
   // qDebug()<<"Rect Height:"<<IDSODisplay->getRectHeight();
  //  qDebug()<<"Rect Width:"<<IDSODisplay->getRectWidth();
    double l_nVTPosition = -(IDSODisplay->getRectHeight()/8.0)*(m_nVoltageTriggerPoint/(l_nActVoltage));
    double l_nHTPosition  = -(IDSODisplay->getRectWidth()/10.0)*(m_nTimebaseTriggerPoint/(IDSODisplay->getTimePerDivision(l_nChannel)));
   // qDebug()<<"Trigger Info----------------------------------------------------------------------------";
   // qDebug()<<"Actual Trigger Point"<<m_nAcutalTriggertimeBase;
   // qDebug()<<"Voltage Per Division:"<<m_nVoltPerDivision<<"Voltage Trigger Pos:"<<m_nVoltageTriggerPoint;
   // qDebug()<<"Timer Per Division:"<<IDSODisplay->getTimePerDivision()<<"Time Trigger Pos:"<<m_nTimebaseTriggerPoint;
  //  qDebug()<<"Vertical Trigger Position:"<<l_nVTPosition<<"Horizontal Trigger Position:"<<l_nHTPosition;
   // qDebug()<<"----------------------------------------------------------------------------------------";
    IDSODisplay->moveHorizontalTriggerPointer(l_nHTPosition);
   // qDebug()<<"HT COunt:"<<IDSODisplay->getRectWidth()/l_nHTPosition;
    IDSODisplay->moveVerticalTriggerPointer(l_nVTPosition);

    //Offset Voltage Calculation Equating current Voltage Screen to ADC Voltage (0.7V)
    // DAC Offset 1.2
    // offset Voltage = volt Per Divsion * ADC Ref(0.7) / Max Screen Voltage

    double l_nOffsetVoltage=0.0,l_nADCFS=0.75;
    double l_nScreenVoltage = 0.0;

    qDebug()<<"Voltage Trigger Point:"<<m_nVoltageTriggerPoint;
   	l_nScreenVoltage = l_nActVoltage * 4.0;
    l_nOffsetVoltage = (m_nVoltageTriggerPoint * l_nADCFS) / l_nScreenVoltage;
    double l_nDACOffset = 1.2 + l_nOffsetVoltage;
    //qDebug()<<"Offset Voltage to be loaded:"<<l_nOffsetVoltage<<l_nScreenVoltage;
   // qDebug()<<"Offset DAC:"<<l_nDACOffset<<"Channel Index"<<ui->cmbChannel->currentIndex();
    if(ui->cmbChannel->currentIndex() == 0)
    	hwInterface->setDAC(DACB,l_nDACOffset); // CH1 Trigger - DAC
    else if (ui->cmbChannel->currentIndex() == 1)
    	hwInterface->setDAC(DACD,l_nDACOffset); // CH2 Trigger - DAC
    else if(ui->cmbChannel->currentIndex() == 2)
    	hwInterface->setDAC(DACE,l_nDACOffset); // EXT  Trigger - DAC

}
void LMH6518GUI::on_butForceTrigger_clicked()
{
	m_objDSOWaveSettings->setForceTrigger(true);
	on_butRUN_clicked();
//	if(ui->optSingle->isChecked()&& m_nIntFlag==false)
//		m_objDSOWaveSettings->Drive(false);

//	m_objDSOWaveSettings->convertToDecimation(m_nVoltPerDivision,IDSODisplay->getFSSettings(),IDSODisplay->getRectWidth(),R1FIFO,m_nSamples,ui->chkCH1Odd->isChecked(),ui->chkCH1Even->isChecked());
	//m_objDSOWaveSettings->DSODrive(R1FIFO);
//	IDSODisplay->moveChannelOffset(CHANNEL2,0.0);
//	IDSODisplay->moveChannelOffset(CHANNEL1,0.0);
//	//m_objDSOWaveSettings->DSODrive(R2FIFO);
//	IDSODisplay->moveChannelOffset(CHANNEL4,0.0);
//	IDSODisplay->moveChannelOffset(CHANNEL3,0.2);
//
//	if(ui->chkR1->isChecked()==true)
//		m_objDSOWaveSettings->convertToDecimation(IDSODisplay->getVoltPerDivsion(CHANNEL1),IDSODisplay->getFSSettings(CHANNEL1),IDSODisplay->getRectWidth(),R1FIFO,m_nSamples,ui->chkCH1Odd->isChecked(),ui->chkCH1Even->isChecked());
//	if(ui->chkR2->isChecked()==true)
//		m_objDSOWaveSettings->convertToDecimation(IDSODisplay->getVoltPerDivsion(CHANNEL3),IDSODisplay->getFSSettings(CHANNEL3),IDSODisplay->getRectWidth(),R2FIFO,m_nSamples,ui->chkCH2Odd->isChecked(),ui->chkCH2Even->isChecked());
//	IDSODisplay->LoadOddEvenData(m_nVoltageTriggerPoint,m_nAcutalTriggertimeBase,true,true,ui->cmbChannel->currentIndex()==0?CHANNEL1:CHANNEL3,(m_objDSOWaveSettings->getTriggerSamples()-m_nPrecount),m_nPrecount);
//	//SODisplay->LoadOddEvenData(m_nVoltageTriggerPoint,m_nAcutalTriggertimeBase,true,true,l_nChannel,(m_nSamples-m_nPrecount),m_nPrecount);
//
//
//	IDSODisplay->setCH1VectorData(m_objDSOWaveSettings->getYVectorPoints(CHANNEL1));
//	IDSODisplay->setCH2VectorData(m_objDSOWaveSettings->getYVectorPoints(CHANNEL2));
//	IDSODisplay->setCH3VectorData(m_objDSOWaveSettings->getYVectorPoints(CHANNEL3));
//	IDSODisplay->setCH4VectorData(m_objDSOWaveSettings->getYVectorPoints(CHANNEL4));

}

void LMH6518GUI::on_pushButton_clicked()
{
	QWidget *newWidget = test->getPTAppBckPsoc();
	newWidget->setWindowTitle("AppCard BackPanel PSoC Panel");
	newWidget->show();
}

void LMH6518GUI::doIntPlot(QList<unsigned char> pLstOdd,QList<unsigned char> pLstEven)
{
	//qDebug()<<"Even Count:"<<pLstEven.count();
//	qDebug()<<"Odd Count:"<<pLstOdd.count();
//	ui->leStatus->setText("Trig'd");
//	ui->leStatus->setText(" ");
//	if(ui->chkR1->isChecked() == true)
//	{
//	}
//	if(ui->chkR2->isChecked() == true)
//	{
//	}
//
	m_LstEven = pLstEven;
	m_LstOdd = pLstOdd;
	IGPIOEvent->BlockSig(true);
	IPTKeyEvent->BlockSig(true);
//		IDSODisplay->moveChannelOffset(CHANNEL2,0.0);
//		IDSODisplay->moveChannelOffset(CHANNEL1,0.2);
//		IDSODisplay->moveChannelOffset(CHANNEL4,0.0);
//		IDSODisplay->moveChannelOffset(CHANNEL3,0.2);
	if(ui->chkR1->isChecked()==true )
	{
		m_objDSOWaveSettings->convertToDecimation(IDSODisplay->getVoltPerDivsion(CHANNEL1),IDSODisplay->getFSSettings(CHANNEL1),IDSODisplay->getRectWidth(),R1FIFO,m_nSamples,pLstOdd,pLstEven);
		IDSODisplay->LoadOddEvenData(m_nVoltageTriggerPoint,m_nAcutalTriggertimeBase,true,true,CHANNEL1,(m_objDSOWaveSettings->getTriggerSamples()-m_nPrecount),m_nPrecount);

	}
	if(ui->chkR2->isChecked()==true)
	{
		m_objDSOWaveSettings->convertToDecimation(IDSODisplay->getVoltPerDivsion(CHANNEL1),IDSODisplay->getFSSettings(CHANNEL1),IDSODisplay->getRectWidth(),R1FIFO,m_nSamples,pLstOdd,pLstEven);
		IDSODisplay->LoadOddEvenData(m_nVoltageTriggerPoint,m_nAcutalTriggertimeBase,true,true,CHANNEL3,(m_objDSOWaveSettings->getTriggerSamples()-m_nPrecount),m_nPrecount);

	}
	//qDebug()<<"Sample Count:"<<m_objDSOWaveSettings->getYVectorPoints(CHANNEL1).count();
//
//	item->setEnabled(false);
//	chItem->setPlotData(m_objDSOWaveSettings->getYVectorPoints(CHANNEL1));
	//scene->update();
//	usleep(10000);
	IDSODisplay->setCH1VectorData(m_objDSOWaveSettings->getYVectorPoints(CHANNEL1));
	IDSODisplay->setCH2VectorData(m_objDSOWaveSettings->getYVectorPoints(CHANNEL2));
	IDSODisplay->setCH3VectorData(m_objDSOWaveSettings->getYVectorPoints(CHANNEL3));
	IDSODisplay->setCH4VectorData(m_objDSOWaveSettings->getYVectorPoints(CHANNEL4));
//
	IGPIOEvent->BlockSig(false);
	IPTKeyEvent->BlockSig(false);
	if(ui->optNormal->isChecked()){
			IGPIOEvent->driveDSO(true);
			ui->leStatus->setText("Ready");
		}
		if(ui->optAuto->isChecked()){
			IGPIOEvent->driveDSO(false);
			ui->leStatus->setText("Ready");
		}
	if(ui->optSingle->isChecked()==true)
	{
		m_objDSOWaveSettings->disableInterrupt();
		return;
	}
}


void LMH6518GUI::clickedPRSCR() {

	QPixmap Pix = QPixmap();
	Pix = QPixmap::grabWindow(QApplication::desktop()->winId());
	Pix.save("mainscreen.jpg");
	QClipboard *board = QApplication::clipboard();
	board->setPixmap(Pix);
	QWidget::showFullScreen();
}




void LMH6518GUI::customEvent(QEvent *e)
{
	//qDebug()<<"Inside CustomEvent";

	if (e->type() == ((QEvent::Type)7894))
	{
		IGPIOEvent->BlockSig(true);
	//	qDebug()<<"Mouse Move"<<m_nMouseMoveCouter++;
		//QWidget::event(e);
		e->ignore();
		IGPIOEvent->BlockSig(false);
		return;
	}
	if(e->type() == QEvent::MouseMove)
	{
		qDebug()<<"Mouse Move";
		IGPIOEvent->BlockSig(true);
		IPTKeyEvent->BlockSig(true);
		e->ignore();
		IGPIOEvent->BlockSig(false);
		IPTKeyEvent->BlockSig(false);
		return;
	}
	if (e->type() == ((QEvent::Type) 5678)) {
		qDebug() << "PT Keypad";
		KeyFunction();
	}
	if(e->type() == ((QEvent::Type)7892))
	{
		//qDebug()<<"Interrupt Raised"<<m_nMouseMoveCouter;
		m_objTimerInterrupt->stop();
		ui->leStatus->setText("Trig'd");
		ui->leStatus->setText(" ");
		if(ui->chkR1->isChecked() == true)
		{
		}
		if(ui->chkR2->isChecked() == true)
		{
		}

		IGPIOEvent->BlockSig(true);
		IPTKeyEvent->BlockSig(true);
//		IDSODisplay->moveChannelOffset(CHANNEL2,0.0);
//		IDSODisplay->moveChannelOffset(CHANNEL1,0.2);
//		IDSODisplay->moveChannelOffset(CHANNEL4,0.0);
//		IDSODisplay->moveChannelOffset(CHANNEL3,0.2);
		if(ui->chkR1->isChecked()==true )
		{
			//m_objDSOWaveSettings->convertToDecimation(IDSODisplay->getVoltPerDivsion(CHANNEL1),IDSODisplay->getFSSettings(CHANNEL1),objTempPlotter->geometry().width(),R1FIFO,m_nSamples,ui->chkCH1Odd->isChecked(),ui->chkCH1Even->isChecked());
			//m_objDSOWaveSettings->convertToDecimation(IDSODisplay->getVoltPerDivsion(CHANNEL1),IDSODisplay->getFSSettings(CHANNEL1),ui->ch1Widget->width(),R1FIFO,m_nSamples,ui->chkCH1Odd->isChecked(),ui->chkCH1Even->isChecked());
			m_objDSOWaveSettings->convertToDecimation(IDSODisplay->getVoltPerDivsion(CHANNEL1),IDSODisplay->getFSSettings(CHANNEL1),IDSODisplay->getRectWidth(),R1FIFO,m_nSamples,ui->chkCH1Odd->isChecked(),ui->chkCH1Even->isChecked());
			IDSODisplay->LoadOddEvenData(m_nVoltageTriggerPoint,m_nAcutalTriggertimeBase,true,true,CHANNEL1,(m_objDSOWaveSettings->getTriggerSamples()-m_nPrecount),m_nPrecount);


		}
		if(ui->chkR2->isChecked()==true){
			//m_objDSOWaveSettings->convertToDecimation(IDSODisplay->getVoltPerDivsion(CHANNEL3),IDSODisplay->getFSSettings(CHANNEL3),objTempPlotter->geometry().width(),R2FIFO,m_nSamples,ui->chkCH2Odd->isChecked(),ui->chkCH2Even->isChecked());
			m_objDSOWaveSettings->convertToDecimation(IDSODisplay->getVoltPerDivsion(CHANNEL1),IDSODisplay->getFSSettings(CHANNEL1),IDSODisplay->getRectWidth(),R1FIFO,m_nSamples,ui->chkCH1Odd->isChecked(),ui->chkCH1Even->isChecked());
			IDSODisplay->LoadOddEvenData(m_nVoltageTriggerPoint,m_nAcutalTriggertimeBase,true,true,CHANNEL3,(m_objDSOWaveSettings->getTriggerSamples()-m_nPrecount),m_nPrecount);
		}

		//IDSODisplay->LoadOddEvenData(m_nVoltageTriggerPoint,m_nAcutalTriggertimeBase,true,true,ui->cmbChannel->currentIndex()==0?CHANNEL1:CHANNEL3);

		//m_objDSOGridView->setChannelVectorData(m_objDSOWaveSettings->getYVectorPoints(CHANNEL2),CHANNEL1);
		IDSODisplay->setCH1VectorData(m_objDSOWaveSettings->getYVectorPoints(CHANNEL1));
		IDSODisplay->setCH2VectorData(m_objDSOWaveSettings->getYVectorPoints(CHANNEL2));
		IDSODisplay->setCH3VectorData(m_objDSOWaveSettings->getYVectorPoints(CHANNEL3));
		IDSODisplay->setCH4VectorData(m_objDSOWaveSettings->getYVectorPoints(CHANNEL4));
//		qDebug()<<"Count:"<<m_objDSOWaveSettings->getYVectorPoints(CHANNEL2).count();
		//objTempPlotter->setSamplesCount(m_nSamples);
	  //  objTempPlotter->setChannelData(m_objDSOWaveSettings->getYVectorPoints(CHANNEL2));
	   // objTempPlotter->refreshPixmap(DRAW_GRID);


		IGPIOEvent->BlockSig(false);
		IPTKeyEvent->BlockSig(false);

		if(ui->optSingle->isChecked()==true)
		{
			m_objDSOWaveSettings->disableInterrupt();
			return;
		}
		//IAppCard->readAppCardCodeId();
		m_objDSOWaveSettings->enableInterrupt();
		if(ui->optAuto->isChecked()){
		//	m_objTimerInterrupt->start(10);
			m_objDSOWaveSettings->DriveInterrupt();
			ui->leStatus->setText("Ready");
		}
		if(ui->optNormal->isChecked()){
			m_objDSOWaveSettings->DriveInterrupt(true);
			ui->leStatus->setText("Ready");
		}
		m_nIntFlag=true;
	}
}

void LMH6518GUI::on_dblHorizontalTrigger_clicked()
{
//	updateValues();
}

void LMH6518GUI::on_dblHorizontalTrigger_valueChanged(double pValue)
{
	Q_UNUSED(pValue);
	//m_nTimebaseTriggerPoint=-pValue;
	updateValues();
}

void LMH6518GUI::on_dblVerticalTrigger_valueChanged(double pValue)
{
	Q_UNUSED(pValue);
	//m_nTimebaseTriggerPoint=-pValue;
	updateValues();

}

void LMH6518GUI::on_cmbSamples_currentIndexChanged(int index)
{
	m_nCmbampleIndex = index;
	on_cmbMemory_currentIndexChanged(ui->cmbMemory->currentIndex());
}

void LMH6518GUI:: on_chkCH1Odd_clicked()
{
	if(ui->chkCH1Odd->isChecked())
	{
		IDSODisplay->HideDSOChannel(CHANNEL1,false);
	}
	else
	{
		IDSODisplay->HideDSOChannel(CHANNEL1,true);
	}
}
void LMH6518GUI:: on_chkCH1Even_clicked()
{
	if(ui->chkCH1Even->isChecked())
		IDSODisplay->HideDSOChannel(CHANNEL2,false);
	else
		IDSODisplay->HideDSOChannel(CHANNEL2,true);

}
void LMH6518GUI:: on_chkCH2Odd_clicked()
{
	if(ui->chkCH2Odd->isChecked())
		IDSODisplay->HideDSOChannel(CHANNEL3,false);
	else
		IDSODisplay->HideDSOChannel(CHANNEL3,true);

}
void LMH6518GUI:: on_chkCH2Even_clicked()
{
	if(ui->chkCH2Even->isChecked())
		IDSODisplay->HideDSOChannel(CHANNEL4,false);
	else
		IDSODisplay->HideDSOChannel(CHANNEL4,true);

}

//void moveLeft();
//void moveRight();
//void moveUp();
//void moveDown();
void LMH6518GUI::setDefaultColor()
{
	ui->cmbTimeBase->setStyleSheet("background-color: white");
	ui->cmbTimeUnit->setStyleSheet("background-color: white");
	ui->cmbLMHVoltage->setStyleSheet("background-color: white");
	ui->cmbMemory->setStyleSheet("background-color: white");
	ui->dblVerticalTrigger->setStyleSheet("background-color: white");
	ui->dblHorizontalTrigger->setStyleSheet("background-color: white");
	ui->cmbSamples->setStyleSheet("background-color: white");
	ui->cmbChannel->setStyleSheet("background-color: white");
	ui->cmbTriggerSoruce->setStyleSheet("background-color: white");
	ui->LMHFilter->setStyleSheet("background-color: white");
	ui->LMHPowerMode->setStyleSheet("background-color: white");


}
void LMH6518GUI::moveLeft()
{
	setDefaultColor();
	m_nComboCounter=0;
	m_nUpCounter=0;
	if(m_nLeftMove == 0)
	{
		ui->cmbTimeBase->setFocus();
		m_nComboCounter = ui->cmbTimeBase->count()-1;
		ui->cmbTimeBase->setStyleSheet("background-color: #ffaa00");
	}
	else if(m_nLeftMove == 1)
	{
		ui->cmbTimeUnit->setFocus();
		m_nComboCounter = ui->cmbTimeUnit->count()-1;
		ui->cmbTimeUnit->setStyleSheet("background-color: #ffaa00");
	}
	else if(m_nLeftMove == 2)
	{
		ui->cmbMemory->setFocus();
		m_nComboCounter = ui->cmbMemory->count()-1;
		ui->cmbMemory->setStyleSheet("background-color: #ffaa00");
	}
	else if(m_nLeftMove == 3)
	{
		ui->cmbSamples->setFocus();
		ui->cmbSamples->setStyleSheet("background-color: #ffaa00");
		m_nComboCounter = ui->cmbSamples->count()-1;
	}

	else if(m_nLeftMove == 4)
	{
		ui->dblHorizontalTrigger->setFocus();
		ui->dblHorizontalTrigger->setStyleSheet("background-color: #ffaa00");
	}
	else if(m_nLeftMove == 5)
	{
		ui->cmbLMHVoltage->setFocus();
		ui->cmbLMHVoltage->setStyleSheet("background-color: #ffaa00");
		m_nComboCounter = ui->cmbLMHVoltage->count()-1;
	}
	else if(m_nLeftMove == 6)
	{
		ui->dblVerticalTrigger->setFocus();
		ui->dblVerticalTrigger->setStyleSheet("background-color: #ffaa00");
	}
	else if(m_nLeftMove == 7)
	{
		m_nComboCounter = ui->LMHFilter->count()-1;
		ui->LMHFilter->setStyleSheet("background-color: #ffaa00");
	}
	else if(m_nLeftMove == 8)
	{
		m_nComboCounter = ui->LMHPowerMode->count()-1;
		ui->LMHPowerMode->setStyleSheet("background-color: #ffaa00");
	}



}

void LMH6518GUI::moveRight()
{

}

void LMH6518GUI::moveUp()
{
	if(m_nLeftMove==0)
	{
		ui->cmbTimeBase->setCurrentIndex(m_nUpCounter);
		on_cmbTimeBase_currentIndexChanged(m_nUpCounter);

	}
	else if(m_nLeftMove==1)
	{
		ui->cmbTimeUnit->setCurrentIndex(m_nUpCounter);
		on_cmbTimeUnit_currentIndexChanged(m_nUpCounter);
	}
	else if(m_nLeftMove==2)
	{
		ui->cmbMemory->setCurrentIndex(m_nUpCounter);
		on_cmbMemory_currentIndexChanged(m_nUpCounter);
	}
	else if(m_nLeftMove==3)
	{
		ui->cmbSamples->setCurrentIndex(m_nUpCounter);
		on_cmbSamples_currentIndexChanged(m_nUpCounter);
	}
	else if(m_nLeftMove == 4)
	{
		ui->dblHorizontalTrigger->stepUp();
	}
	else if(m_nLeftMove ==5)
	{
		ui->cmbLMHVoltage->setCurrentIndex(m_nUpCounter);
		on_cmbLMHVoltage_currentIndexChanged(m_nUpCounter);
	}
	else if(m_nLeftMove == 6)
	{
		ui->dblVerticalTrigger->stepUp();
	}
	else if(m_nLeftMove == 7)
	{
		ui->LMHFilter->setCurrentIndex(m_nUpCounter);
		on_LMHFilter_currentIndexChanged(m_nUpCounter);
	}
	else if(m_nLeftMove == 8)
	{
		ui->LMHPowerMode->setCurrentIndex(m_nUpCounter);
		on_LMHPowerMode_currentIndexChanged(m_nUpCounter);
	}

	if(m_nChannelSelect==1)
	{
		ui->cmbChannel->setCurrentIndex(m_nUpCounter);
		on_cmbChannel_currentIndexChanged(m_nUpCounter);
	}
	else if(m_nTriggerSelect==1)
	{
		ui->cmbTriggerSoruce->setCurrentIndex(m_nUpCounter);
		on_cmbTriggerSoruce_currentIndexChanged(m_nUpCounter);
	}

}

void LMH6518GUI::moveDown()
{
	if(m_nLeftMove==0)
	{
		ui->cmbTimeBase->setCurrentIndex(m_nUpCounter);
		on_cmbTimeBase_currentIndexChanged(m_nUpCounter);
	}
	else if(m_nLeftMove==1)
	{
		ui->cmbTimeUnit->setCurrentIndex(m_nUpCounter);
		on_cmbTimeUnit_currentIndexChanged(m_nUpCounter);
	}
	else if(m_nLeftMove==2)
	{
		ui->cmbMemory->setCurrentIndex(m_nUpCounter);
		on_cmbMemory_currentIndexChanged(m_nUpCounter);
	}
	else if(m_nLeftMove==3)
	{
		ui->cmbSamples->setCurrentIndex(m_nUpCounter);
		on_cmbSamples_currentIndexChanged(m_nUpCounter);
	}
	else if(m_nLeftMove == 4)
	{
		ui->dblHorizontalTrigger->stepDown();
	}
	else if(m_nLeftMove ==5)
	{
		ui->cmbLMHVoltage->setCurrentIndex(m_nUpCounter);
		on_cmbLMHVoltage_currentIndexChanged(m_nUpCounter);

	}
	else if(m_nLeftMove == 6)
	{
		ui->dblVerticalTrigger->stepDown();
	}
	else if(m_nLeftMove == 7)
	{
		ui->LMHFilter->setCurrentIndex(m_nUpCounter);
		on_LMHFilter_currentIndexChanged(m_nUpCounter);
	}
	else if(m_nLeftMove == 8)
	{
		ui->LMHPowerMode->setCurrentIndex(m_nUpCounter);
		on_LMHPowerMode_currentIndexChanged(m_nUpCounter);
	}

	if(m_nChannelSelect==1)
	{
		ui->cmbChannel->setCurrentIndex(m_nUpCounter);
		on_cmbChannel_currentIndexChanged(m_nUpCounter);
	}
	else if(m_nTriggerSelect==1)
	{
		ui->cmbTriggerSoruce->setCurrentIndex(m_nUpCounter);
		on_cmbTriggerSoruce_currentIndexChanged(m_nUpCounter);
	}


}


void LMH6518GUI::on_memoryDial_sliderMoved(int value)
{
  //  double l_nValue = value / 10.0;
    short l_nMemoryValueCounter=0;
    short l_nUnitValue=0;

    if(value>0 && value <=6){
        l_nMemoryValueCounter = (value-1);
        l_nUnitValue=0;
    }
    else
    {
        l_nMemoryValueCounter = (value)-1;
        l_nUnitValue=1;
    }

	double l_nSampleLength =m_lstMemoryValues.value(l_nMemoryValueCounter);
//	qDebug()<<"Selected Memory Depth:"<<l_nSampleLength<<ui->cmbSamples->currentIndex();
	if(l_nUnitValue == 1)
		m_nMaxRecordLength = l_nSampleLength*1;
	else if(l_nUnitValue == 0)
		m_nMaxRecordLength = l_nSampleLength*1000;
	IDSODisplay->setMaxRecordLength(m_nMaxRecordLength,0);
    IDSODisplay->setMaximumSampleRate(m_nSampleRate[9],MEGAS);

	//IDSODisplay->setTimePerDivision()
    ui->lblSamples->setText(QString::number(m_lstMemoryValues.value(l_nMemoryValueCounter),'f',0)+m_lstMemoryUnit.value(l_nUnitValue));
	updateValues();


    //ui->leValue_2->setText(QString::number(m_lstMemoryValues.value(l_nMemoryValueCounter),'f',3)+m_lstMemoryUnit.value(l_nUnitValue));
    qDebug()<<"Memory Value:"<<QString::number(m_lstMemoryValues.value(l_nMemoryValueCounter),'f',0)+m_lstMemoryUnit.value(l_nUnitValue);
}

void LMH6518GUI::on_timebaseDial_sliderMoved(int value)
{
    double l_nValue = value / 9.0;
    short l_nTimeBaseValueCounter=0;
    short l_nUnitValue=0;
    if(l_nValue>0 && l_nValue <=1){
        l_nTimeBaseValueCounter = (value-1);
        l_nUnitValue=0;
    }
    else if(l_nValue>1 && l_nValue <=2)
    {
        l_nTimeBaseValueCounter = (value-9)-1;
        l_nUnitValue=1;
    }
    else if(l_nValue>2 && l_nValue <=3)
    {
        l_nTimeBaseValueCounter = (value-18)-1;
        l_nUnitValue=2;
    }
    else if(l_nValue>3 && l_nValue <=4)
    {
        l_nTimeBaseValueCounter = (value-27)-1;
        l_nUnitValue=3;
    }
   // qDebug()<<"Value Divisor:"<<l_nValue<<"ArrayValue"<<m_lstTimebaseValues.value(l_nTimeBaseValueCounter);
    //if(value )
     //    ui->leValue->setText(QString::number(m_lstTimebaseValues.value(l_nTimeBaseValueCounter),10)+m_lstTimebaseUnit.value(l_nUnitValue));

	m_nTimePerSample = m_lstTimebaseValues.value(l_nTimeBaseValueCounter);
	m_nTimeUnitIndex = l_nUnitValue;
	ui->dblHorizontalTrigger->setMaximum(m_nTimePerSample*5);
	ui->dblHorizontalTrigger->setMinimum(m_nTimePerSample*-5);
	ui->dblHorizontalTrigger->setSingleStep(m_nTimePerSample/10.0);
	ui->dblHorizontalTrigger->setValue(0.0);
    IDSODisplay->setMaximumSampleRate(m_nSampleRate[9],MEGAS);
    ui->lblTimeBase->setText(QString::number(m_lstTimebaseValues.value(l_nTimeBaseValueCounter),'f',0)+m_lstTimebaseUnit.value(l_nUnitValue));
	updateValues();
    qDebug()<<"Timebase Value:"<<QString::number(m_lstTimebaseValues.value(l_nTimeBaseValueCounter),'f',2)+m_lstTimebaseUnit.value(l_nUnitValue);
}


void LMH6518GUI::initializeTimeBaseList()
{
    m_lstTimebaseValues.insert(0,1);m_lstTimebaseValues.insert(1,2);
    m_lstTimebaseValues.insert(2,5);m_lstTimebaseValues.insert(3,10);
    m_lstTimebaseValues.insert(4,20);m_lstTimebaseValues.insert(5,50);
    m_lstTimebaseValues.insert(6,100);m_lstTimebaseValues.insert(7,200);
    m_lstTimebaseValues.insert(8,500);


    m_lstTimebaseUnit.insert(0,"nS");m_lstTimebaseUnit.insert(1,"uS");
    m_lstTimebaseUnit.insert(2,"mS");m_lstTimebaseUnit.insert(3,"S");


}

void LMH6518GUI::initializeMemoryList()
{
    m_lstMemoryValues.insert(0,1);      m_lstMemoryValues.insert(1,2);
    m_lstMemoryValues.insert(2,2.5);    m_lstMemoryValues.insert(3,5);
    m_lstMemoryValues.insert(4,10);     m_lstMemoryValues.insert(5,25);
    m_lstMemoryValues.insert(6,1);      m_lstMemoryValues.insert(7,2);
    m_lstMemoryValues.insert(8,2.5);    m_lstMemoryValues.insert(9,5);
    m_lstMemoryValues.insert(10,10);    m_lstMemoryValues.insert(11,50);
    m_lstMemoryValues.insert(12,100);   m_lstMemoryValues.insert(13,250);
    m_lstMemoryValues.insert(14,500);

    m_lstMemoryUnit.insert(0,"KS");m_lstMemoryUnit.insert(1,"S");
}

void LMH6518GUI::on_setForceTrigger()
{
	m_objDSOWaveSettings->setForceTrigger(true);
}
