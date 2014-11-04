#include "ad5318.h"
#include "ui_ad5318.h"
#include <unistd.h>

AD5318::AD5318(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AD5318)
{
    ui->setupUi(this);
    initialiseHWLibraries();
    initialiseLineEdits();
    initialiseValues();
    ui->chkDACA->setChecked(true);
   // on_chkDACA_clicked();
    enableRichGUI();
}
void AD5318::enableRichGUI(){
	QWidget *m_objWidget=new QWidget(this);
	QGraphicsScene *entireScene = new QGraphicsScene(0,0,800,600);
    QGraphicsView  *entireView =  new QGraphicsView(m_objWidget);
	QPixmap obj1 = QPixmap(":/bg.png");
	QBrush obj2 = QBrush(obj1);
	obj2.setStyle(Qt::TexturePattern);
	obj2.setTexture(obj1);

	entireView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	entireView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	entireView->setFrameStyle(QFrame::Plain|QFrame::Sunken);
	entireView->setBackgroundBrush(obj2);
	entireView->setScene(entireScene);
	entireView->setGeometry(0,0,800,600);

	ui->grpGeneral->setParent(m_objWidget);
	ui->grpGeneral->setGeometry(10,1,260,190);

	ui->grpDACSelection->setParent(m_objWidget);
	ui->grpDACSelection->setGeometry(300,0,500,130);

	ui->grpDACSettings->setParent(m_objWidget);
	ui->grpDACSettings->setGeometry(300,119,491,71);

	ui->grpDCDrive->setParent(m_objWidget);
	ui->grpDCDrive->setGeometry(10,190,221,171);

	ui->grpAD7190->setParent(m_objWidget);
	ui->grpAD7190->setGeometry(240,190,261,171);
	ui->grpGain->setParent(m_objWidget);
	ui->grpGain->setGeometry(510,190,151,181);

	ui->grpAD5293->setParent(m_objWidget);
	ui->grpAD5293->setGeometry(10,370,260,130);

	ui->calibrationBox->setParent(m_objWidget);
	ui->calibrationBox->setGeometry(280,370,280,160);

	ui->butFileManager->setParent(m_objWidget);
	ui->butFileManager->setGeometry(560,410,111,50);

	ui->butLMH6518->setParent(m_objWidget);
	ui->butLMH6518->setGeometry(680,410,111,50);

        ui->pushButton_2->setParent(m_objWidget);
        ui->pushButton_2->setGeometry(680,270,110,41);
        ui->pushButton_2->setVisible(false);

        ui->pushButton->setParent(m_objWidget);
        ui->pushButton->setGeometry(680,210,110,41);

        ui->appBck->setParent(m_objWidget);
        ui->appBck->setGeometry(730,340,61,61);

        ui->butHY3131->setParent(m_objWidget);
        ui->butHY3131->setGeometry(680,460,111,50);
}
void AD5318::initialiseValues()
{
	m_eSelect = DACA;
	m_nAddress=m_nData=0;
	m_nDACVoltage=0.0;
	m_nDCVoltage=0.0;
	m_nGainFactor=1.0;
	m_nAD5293Voltage=0.0;
//	on_butRstDAC_clicked();
//	// Applying Zero Voltage to DACF and DACG
//	m_eSelect = DACF;
//	m_objAD5318Component->configureADC5318CW();
//	on_butUpdateDAC_clicked();
//	m_eSelect = DACG;
//	m_objAD5318Component->configureADC5318CW();
//	m_nDCVoltage=0.0;
//	on_butUpdateDAC_clicked();
	ADCtimer = new QTimer(this);
	DriveDoneTimer = new QTimer(this);
	RLYTimer = new QTimer(this);
    testTimer = new QTimer(this);

	connect(ADCtimer, SIGNAL(timeout()), this, SLOT(readADC()));
	connect(RLYTimer, SIGNAL(timeout()), this, SLOT(switchRLY()));
	connect(DriveDoneTimer, SIGNAL(timeout()), this, SLOT(switchDACVoltages()));
	connect(testTimer, SIGNAL(timeout()), this, SLOT(switchRelays()));

	//m_objAD7190Component->resetADC(1);
//	m_objAD7190Component->resetADC(2);
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
                                ui->pushButton->setText("Disable Debug \nPanel");
                        }
                        else{
                                ui->pushButton->setText("Enable Debug \nPanel");
                        }
                }
        }else{
                ui->pushButton->setText("Enable Debug \nPanel");
        }
        //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
}

void AD5318::initialiseLineEdits()
{
    m_objLE_ADDR = ILineEdit->QmaxLineEdit(0, ui->grpGeneral);
    m_objLE_ADDR->setGeometry(90, 18, 161, 30);

    m_objLE_DATA = ILineEdit->QmaxLineEdit(1, ui->grpGeneral);
    m_objLE_DATA->setGeometry(90, 68, 161, 30);

    m_objLE_DACVoltage = ILineEdit->QmaxLineEdit(2, ui->grpDACSettings);
    m_objLE_DACVoltage->setGeometry(110,16,113,40);

    m_objLE_DCVoltage = ILineEdit->QmaxLineEdit(3, ui->grpDCDrive);
    m_objLE_DCVoltage->setGeometry(76,37,113,40);

    m_objLE_AD5293Voltage = ILineEdit->QmaxLineEdit(4, ui->grpAD5293);
    m_objLE_AD5293Voltage->setGeometry(80,70,113,40);


    connect(m_objLE_ADDR, SIGNAL(focussed(bool)), this, SLOT(callAddressEdit()));
    connect(m_objLE_DATA, SIGNAL(focussed(bool)), this, SLOT(callDataEdit()));
    connect(m_objLE_DACVoltage, SIGNAL(focussed(bool)), this, SLOT(callDACVoltageEdit()));
    connect(m_objLE_DCVoltage, SIGNAL(focussed(bool)), this, SLOT(callDCVoltageEdit()));
    connect(m_objLE_AD5293Voltage, SIGNAL(focussed(bool)), this, SLOT(callAD5293VoltageEdit()));
	m_objLE_ADDR->setStyleSheet(
			"border-width: 2px;border-style: outset;border-color: gray; border-radius: 1px;  padding: 0 8px;     background: black;     selection-background-color: yellow;   color:white;     font: bold 14px;");
	m_objLE_DATA->setStyleSheet(
			"border-width: 2px;border-style: outset;border-color: gray; border-radius: 1px;  padding: 0 8px;     background: black;     selection-background-color: yellow;   color:white;     font: bold 14px;");
	m_objLE_DACVoltage->setStyleSheet(
			"border-width: 2px;border-style: outset;border-color: gray; border-radius: 1px;  padding: 0 8px;     background: black;     selection-background-color: yellow;   color:white;     font: bold 14px;");
	ui->leADC1->setStyleSheet(
			"border-width: 2px;border-style: outset;border-color: gray; border-radius: 1px;  padding: 0 8px;     background: black;     selection-background-color: yellow;   color:white;     font: bold 14px;");
	ui->leADC2->setStyleSheet(
			"border-width: 2px;border-style: outset;border-color: gray; border-radius: 1px;  padding: 0 8px;     background: black;     selection-background-color: yellow;   color:white;     font: bold 14px;");

}

void AD5318::initialiseHWLibraries()
{
    QPluginLoader loaderDMMTESTJIG("libtestSPI.so", this);
    DMMTestjig = qobject_cast<DMMSPITestJigInterface*> (
    loaderDMMTESTJIG.instance());

    QPluginLoader loader4("libQmaxPTInterface.so", this);
    ILineEdit = qobject_cast<IQmaxLineEdit*> (loader4.instance());
    IPTLibrary = qobject_cast<IQmaxPTLibrary*> (loader4.instance());
    INumberPanel = qobject_cast<IQmaxNumberPanel*> (loader4.instance());
    QPluginLoader loaderApp("libPTApplicationcardInterface.so", this);
    IAppCard = qobject_cast<IApplicationCardInterface*> (loaderApp.instance());
    qDebug() << "Appcard" << IAppCard;
    IAppCard->setDeviceName(SLOT0);
    IAppCard->enumerateAPPCard();
    IAppCard->setSPIAppendBit(0xC000);
    m_objAD5318Component = new AD5318Components(IAppCard);
    m_objAD7190Component = new AD7190Component(IAppCard);
    m_objAD5293Component = new AD5293(IAppCard);

    QPluginLoader loaderCurrent("libICalib.so",this);
     ICalib = qobject_cast<IICALIBTestJigInterface*>(loaderCurrent.instance());

     QPluginLoader loaderVoltage("libVICalib.so",this);
     VCalib = qobject_cast<IVCALIBTestJigInterface*>(loaderVoltage.instance());

     QPluginLoader loaderRX("libRXCalib.so",this);
     RXCalib = qobject_cast<IRXCALIBTestJigInterface*>(loaderRX.instance());

     QPluginLoader loaderREF("libRefCalib.so",this);
     REFCalib = qobject_cast<IRefCALIBTestJigInterface*>(loaderREF.instance());

     QPluginLoader loaderLMH("libLMH6518GUI.so",this);
     LMH6518 = qobject_cast<IPTLMH6518Interface*>(loaderLMH.instance());

     QPluginLoader testing("libAppBckPsoc.so", this);
     test = qobject_cast<IPTAppBckPsocInterface*> (testing.instance());

     //BackPanel Interface Plugin
	QPluginLoader loader2("libBackPlaneInterface.so");
	IBackPlane = qobject_cast<IntefaceBackPlane*> (loader2.instance());
	IBackPlane->InitializeBpObject();

}

void AD5318::callAddressEdit() {
        if (m_objLE_ADDR->hasFocus()) {
                openNumKBPanel(0);
                m_nLineEditIndex = 0;
        }

}

void AD5318::callDataEdit() {
        if (m_objLE_DATA->hasFocus()) {
                openNumKBPanel(0);
                m_nLineEditIndex = 1;
        }
}

void AD5318::callDACVoltageEdit()
{
    if (m_objLE_DACVoltage->hasFocus()) {
            openNumKBPanel(1);
            m_nLineEditIndex = 2;
    }
}

void AD5318::callDCVoltageEdit()
{
    if (m_objLE_DCVoltage->hasFocus()) {
            openNumKBPanel(1);
            m_nLineEditIndex = 3;
    }

}

void AD5318::callAD5293VoltageEdit()
{
    if (m_objLE_AD5293Voltage->hasFocus()) {
            openNumKBPanel(1);
            m_nLineEditIndex = 4;
    }

}


AD5318::~AD5318()
{
    delete ui;
}

void AD5318::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void AD5318::on_butRead_clicked()
{
	m_objLE_DATA->setText(QString::number(
			IAppCard->readRegister(m_nAddress), 16));

}

void AD5318::on_butWrite_clicked()
{
    IAppCard->writeRegister(m_nAddress,m_nData);
}

void AD5318::on_butUpdateDAC_clicked()
{
	qDebug()<< "Update DAC"<<m_eSelect;
    AD5318_dataTemplate l_nAD5318DW;
    l_nAD5318DW.m_eDACSelect = m_eSelect;
    l_nAD5318DW.m_bCtrlBit = 0;
    l_nAD5318DW.m_nVout = m_nDACVoltage;
    l_nAD5318DW.m_nVRef = 2.5;
    // DAC A - DAC B 2.5 V
    // DAC E - DAC H 5.0 V
    // DAC F - DAC G Ignore Ref
    l_nAD5318DW.m_bUniPolor = true;
    if(m_eSelect == DACE || m_eSelect ==DACH)
    	l_nAD5318DW.m_nVRef = 5.0;
    if(m_eSelect == DACF || m_eSelect == DACG)
    	l_nAD5318DW.m_bUniPolor = false;
    /*if(l_nAD5318DW.m_bUniPolor == false)
      l_nAD5318DW.m_nVout = l_nAD5318DW.m_nVout/2.0;*/
    m_objAD5318Component->configureADC5318Data(l_nAD5318DW);

}

void AD5318::on_butRstDAC_clicked()
{
	m_objAD5318Component->resetDAC5318(true);
	m_eSelect = DACF;
	m_objAD5318Component->configureADC5318CW();
	on_butUpdateDAC_clicked();
	m_eSelect = DACG;
	m_objAD5318Component->configureADC5318CW();
	m_nDCVoltage=0.0;
	on_butUpdateDAC_clicked();

}


void AD5318::openNumKBPanelminmax(short int pValue, double pMax, double pMin) {
        QWidget *w = INumberPanel->getNumKBPanelIncDec(pValue, 1, 'T', pMax, pMin,
                        this);
        w->setWindowFlags(Qt::WindowCloseButtonHint | Qt::Dialog);
        w->show();

}

void AD5318::openNumKBPanel(short int pValue) {
        QWidget *w = INumberPanel->getNumKBPanel(pValue, this);
        w->setWindowFlags(Qt::WindowCloseButtonHint | Qt::Dialog);
        w->show();
}

void AD5318::receiveValue(unsigned int pValue) {
        qDebug() << "Receive Value:" << hex << pValue;
        QMessageBox msgBox;
        if (pValue < 0) {
                msgBox.setText("Negative Value not allowed.");
                msgBox.show();
                return;
        }
        if (m_nLineEditIndex == 0) {
                m_objLE_ADDR->setText(QString::number(pValue, 16));
                m_nAddress = pValue;
        }
        else if (m_nLineEditIndex == 1) {
                m_objLE_DATA->setText(QString::number(pValue, 16));
                m_nData = pValue;
        }
}



void AD5318::receiveValue(QString pValue) {
        Q_UNUSED(pValue)
        qDebug() << m_nLineEditIndex << "pValue:" << pValue;
}

void AD5318::receiveValue(double pValue) {
        //qDebug() << m_nLineEditIndex << "pValue:" << pValue;
        if (m_nLineEditIndex == 2)
        {
            m_objLE_DACVoltage->setText(QString::number(pValue,'f',5));
            m_nDACVoltage = pValue;
        }
        if (m_nLineEditIndex == 3)
        {
            m_objLE_DCVoltage->setText(QString::number(pValue,'f',2));
            m_nDCVoltage = pValue;
        }
        if (m_nLineEditIndex ==4)
        {
            m_objLE_AD5293Voltage->setText(QString::number(pValue,'f',2));
            m_nAD5293Voltage = pValue;
        }

}

void AD5318::on_butDriveDC_clicked()
{
	IAppCard->basicTimeUnit(1);
	IAppCard->basicDuration(1);
	IAppCard->setDrivePeriod(1);
	IAppCard->setStartStop(0, 0);
	IAppCard->setDDSWaveSelect(DC_SIGNAL);
	unsigned int m_nHexCode=(unsigned int)(((m_nDCVoltage+0.6)*(pow(2,14)-1))/(2*0.6));
	qDebug()<<"Hex Code:"<<m_nHexCode;
	IAppCard->setDDSDACDCdrive(m_nHexCode);
	IAppCard->startDrive(1);
}

void AD5318::on_butStartADC_clicked()
{

	ADCtimer->start(200);
}

void AD5318::on_butStopADC_clicked()
{
	ADCtimer->stop();
}

void AD5318::on_chkADC1_clicked()
{
	//m_objAD7190Component->resetADC(1);
	//m_objAD7190Component->writeADCConfigurationRegister(1,0x110);
	//m_objAD7190Component->writeADCModeRegister(1,0x80060);
	//IAppCard->writeRegister(0x20,0x36);
	//IAppCard->writeRegister(0x04,0x34);
	//IAppCard->writeRegister(0x0,0x16);
}

void AD5318::on_chkADC2_clicked()
{
	//m_objAD7190Component->resetADC(2);
	//m_objAD7190Component->writeADCConfigurationRegister(2,0x110);
	//m_objAD7190Component->writeADCModeRegister(2,0x80060);
	//IAppCard->writeRegister(0x0,0x38);
	//IAppCard->writeRegister(0x03,0x34);
	//IAppCard->writeRegister(0x0,0x16);

}

void AD5318::readADC()
{
	short int l_nResoulution = 23;
	double l_nGain = m_nGainFactor, l_nVREF = 2.048;
	double l_nFactor1 = 0.0, l_nFactor2 = 0.0, l_nAIN = 0.0;

	if(ui->chkADC1->isChecked())
	{
		m_nADC1Voltage=m_objAD7190Component->readADCDataRegister(1) & 0xFFFFFF;
		qDebug()<<"Hex ADC1 Code:"<<hex<<m_nADC1Voltage;

		l_nFactor1 = (m_nADC1Voltage / pow(2, l_nResoulution)) - 1;
		// AnalogVolage * VRef / 2 n * Gain
		l_nFactor2 = (l_nGain / l_nVREF);
		l_nAIN = l_nFactor1 / l_nFactor2;
		if(ui->chkPseudo->isChecked())
		{
			l_nFactor1 = (m_nADC1Voltage * l_nVREF) / (pow(2, l_nResoulution)) * l_nGain;
			l_nAIN=l_nFactor1;
		}
		qDebug()<<"Converted ADC1 Code:"<<l_nAIN;
		ui->leADC1->setText(QString::number(l_nAIN,'f',8));
	}
	else
	{
		ui->leADC1->setText("0");
	}
	if(ui->chkADC2->isChecked())
	{
		m_nADC2Voltage=m_objAD7190Component->readADCDataRegister(2) & 0xFFFFFF;
		qDebug()<<"Hex ADC2 Code:"<<hex<<m_nADC2Voltage;
		l_nFactor1 = (m_nADC2Voltage / pow(2, l_nResoulution)) - 1;
		l_nFactor2 = (l_nGain / l_nVREF);
		l_nAIN = l_nFactor1 / l_nFactor2;
		if(ui->chkPseudo->isChecked())
		{
			l_nFactor1 = (m_nADC2Voltage * l_nVREF) / (pow(2, l_nResoulution)) * l_nGain;
			l_nAIN=l_nFactor1;
		}
		qDebug()<<"Converted ADC2 Code:"<<l_nAIN;
		ui->leADC2->setText(QString::number(l_nAIN,'f',8));
	}
	else
	{
		ui->leADC2->setText("0");
	}
}

void AD5318::on_chkDACA_clicked()
{
	if(ui->chkDACA->isChecked()){
		m_eSelect = DACA;
		m_objAD5318Component->configureADC5318CW();
	}
}

void AD5318::on_chkDACB_clicked()
{

	if(ui->chkDACB->isChecked())
	{
		m_eSelect = DACB;
		m_objAD5318Component->configureADC5318CW();
	}
}

void AD5318::on_chkDACC_clicked()
{
	if(ui->chkDACC->isChecked())
	{
		m_eSelect = DACC;
		m_objAD5318Component->configureADC5318CW();
	}
}

void AD5318::on_chkDACD_clicked()
{
	if(ui->chkDACD->isChecked())
	{
		m_eSelect = DACD;
		m_objAD5318Component->configureADC5318CW();
	}
}

void AD5318::on_chkDACE_clicked()
{
	if(ui->chkDACE->isChecked())
	{
		m_eSelect = DACE;
		m_objAD5318Component->configureADC5318CW();
	}
}

void AD5318::on_chkDACF_clicked()
{
	if(ui->chkDACF->isChecked())
	{
		m_eSelect = DACF;
		m_objAD5318Component->configureADC5318CW();
	}
    //objAppcard->setSPITXLSW(DACCRWORD,SPI1);

}

void AD5318::on_chkDACG_clicked()
{
	if(ui->chkDACG->isChecked())
	{
		m_eSelect = DACG;
		m_objAD5318Component->configureADC5318CW();
	}
}

void AD5318::on_chkDACH_clicked()
{
	if(ui->chkDACH->isChecked())
	{
		m_eSelect = DACH;
		m_objAD5318Component->configureADC5318CW();
	}
}



void AD5318::GenerateSINEPattern(double pValue)
{

	m_nData1.clear();
    unsigned int l_nSampleIndex=0;
    unsigned int l_nIndex =0;
    unsigned int l_nSamples=0;
    unsigned int l_nRemainder =0;
    unsigned int l_nTemp=0;
    unsigned int l_nCycles=1;

    double l_nVRef=0.6;
    //stWaveData *l_objWaveData = showVITrace(1,m_objVISubject->getIndexTemplate(0));
    double l_nYPoint =0.0,l_nDegree =0,l_nXPoint =0.0;

    l_nSamples = 100;//l_objWaveData->m_nSamples / l_objWaveData->m_nCycles;
   // l_nRemainder = (l_objWaveData->m_nSamples%(int)l_objWaveData->m_nCycles)/l_nSamples;
    l_nTemp = l_nSamples;
    double l_nTimerPerSamples = 1/l_nSamples;
    double l_nPhaseAngle=0.0;
    l_nPhaseAngle = (l_nDegree*PI) / 180.0;
    double l_nAmplitude =  pValue * l_nVRef;//(l_objWaveData->m_nAmplitude)*l_objWaveData->m_nVRef;
    qDebug() << "Inside Sine Pattern:" << l_nAmplitude ;//<< l_objWaveData->m_nAmplitude;
    double l_nTempYPoint=0.0;
    while(l_nSampleIndex < l_nCycles)
    {
        for(;l_nIndex<l_nSamples;l_nIndex++)
        {
            l_nTempYPoint = l_nAmplitude*sin(l_nPhaseAngle);
            l_nYPoint = l_nTempYPoint * l_nVRef;
            l_nYPoint = l_nTempYPoint;
            //if( l_objWaveData->m_bUniPolar == true)
             //   l_nYPoint = l_nYPoint + 1.0;
            m_nData1.append(QPointF(l_nXPoint,l_nYPoint));
            l_nPhaseAngle = (l_nPhaseAngle +(2*PI) / (l_nSamples/l_nCycles));
            l_nXPoint += l_nTimerPerSamples;
            if(l_nPhaseAngle > (2*PI))
                l_nPhaseAngle = l_nPhaseAngle - (2*PI);

        }
        l_nSamples += l_nTemp;
        l_nSampleIndex++;
    }
    GenerateHexPattern();
}

void AD5318::on_chkP1V_clicked()
{
	if(ui->chkP1V->isChecked())
		GenerateSINEPattern(0.2);
}

void AD5318::on_chkP2V_clicked()
{
	if(ui->chkP2V->isChecked())
		GenerateSINEPattern(0.4);
}

void AD5318::on_chkPseudo_clicked()
{

}

 void AD5318::GenerateHexPattern()
 {
    FILE *fpWaveFile;
    if(ui->chkP1V->isChecked())
    	fpWaveFile = fopen("./SINEP1V.txt","w");
    if(ui->chkP2V->isChecked())
    	fpWaveFile = fopen("./SINEP2V.txt","w");
    double l_nAmplitude =0.1,l_nVref=0.6;
    short l_nHexValue = 0;
        if(fpWaveFile == 0)
            printf("File I/O error\n");
    for(int l_nIndex=0;l_nIndex<m_nData1.count();l_nIndex++)
    {
        QPointF m_nPointValue = m_nData1.at(l_nIndex);
        if( 0)
        {
            l_nHexValue = (m_nPointValue.y()) *((pow(2,13)))/(l_nAmplitude*2.0);
            l_nHexValue = l_nHexValue + 8192;
        }
        else
        {
            double l_nRefPoint = 0.0;
            if(0)
            {
                    //l_nRefPoint =  (m_nPointValue.y() - m_objWaveData->m_nCalibrationConstant) /m_objWaveData->m_nCalibrationGain;
                    l_nRefPoint = m_nPointValue.y();
            }
            else
            {
                    l_nRefPoint = m_nPointValue.y();
            }
            l_nHexValue = ((l_nRefPoint)+l_nVref) * ((pow(2,14))-1) / (2 * (l_nVref));
        }
        QString l_strHexValue;
        fprintf(fpWaveFile,"%X\n",l_nHexValue);
    }
    fclose(fpWaveFile);
}

 void AD5318::on_butGain1_clicked()
 {
	 m_nGainFactor=1.0;
 }
 void AD5318::on_butGain8_clicked()
 {
	 m_nGainFactor=8.0;
 }
 void AD5318::on_butGain16_clicked()
 {
	 m_nGainFactor=16.0;
 }
 void AD5318::on_butGain32_clicked()
 {
	 m_nGainFactor=32.0;
 }
 void AD5318::on_butGain64_clicked()
 {
	 m_nGainFactor=64.0;
 }
 void AD5318::on_butGain128_clicked()
 {
	 m_nGainFactor=128.0;
 }

 void AD5318::on_butAD5293Drive_clicked()
 {
	 //m_objAD5293Component->resetDAC5293(true);
	 double Rout = 1600/(m_nAD5293Voltage/0.6);
	 m_objAD5293Component->setAD5293Voltage(Rout);
	 m_objAD5293Component->writeAD5293(SPI1);

 }

 void AD5318::on_butSwitchRly_clicked()
 {
	 if(RLYTimer->isActive())
		 RLYTimer->stop();
	 else
		 RLYTimer->start(200);

 }

 void AD5318::on_butCheckDriveDone_clicked()
 {
	 if(DriveDoneTimer->isActive())
		 DriveDoneTimer->stop();
	 else
		 DriveDoneTimer->start(100);
 }


 void AD5318::switchRLY(unsigned short pIndex)
 {

	    unsigned int l_nRegisterAddress = 0x26, l_nRegisterData = pIndex;
	    IBackPlane->writeBackPlaneRegister(l_nRegisterData, l_nRegisterAddress); // Initialize BP Source Impedance Selection

 }

 void AD5318::switchDACVoltages()
 {
 	m_objAD5318Component->resetDAC5318(true);
 }


 void AD5318::on_butFileManager_clicked()
 {
		QDir::setCurrent("/home");
		QProcess::execute("./fm -qws");

 }

void AD5318::on_DriveCurrent_clicked()
{
    QWidget *newWidget=ICalib->getIICALIB();
                            newWidget->setWindowTitle("Current Calibration Panel");
                            newWidget->show();
}

void AD5318::on_DriveVoltage_clicked()
{
    QWidget *newWidget=VCalib->getVICALIB();
                            newWidget->setWindowTitle("Voltage Calibration Panel");
                            newWidget->show();
}

void AD5318::on_Receiver_clicked()
{
    QWidget *newWidget=RXCalib->getRXCALIB();
                    newWidget->setWindowTitle("Receive Calibration Panel");
                    newWidget->show();
}

void AD5318::on_Reference_clicked()
{
    QWidget *newWidget=REFCalib->getRefCALIB();
                newWidget->setWindowTitle("Reference Calibration Panel");
                newWidget->show();
}
void AD5318::on_butStart_clicked()
{
//	if(testTimer->isActive())
//	{
//		qDebug()<<"Times Stop";
//		testTimer->stop();
//	}
//	else{
//		testTimer->start(1);
//		qDebug()<<"Times Start";
//	}
	m_nData=0;
	while(1)
	{
		if(ui->chkAddrWrite->isChecked())
		{
			//qDebug()<<"WriteData"<<m_nData;
			usleep(1000);
			IAppCard->writeRegister(m_nData,0x2);
			m_nData++;
			m_nData = m_nData&0xF;
		}
		else{
			qDebug()<<"ReadData:"<<hex<<IAppCard->readRegister(m_nAddress);
		}
	}


}

void AD5318::switchRelays()
{
	if(ui->chkAddrWrite->isChecked())
		IAppCard->writeRegister(m_nData,m_nAddress);
	else
		qDebug()<<"ReadData:"<<hex<<IAppCard->readRegister(m_nAddress);
}

void AD5318::on_butLMH6518_clicked()
{
    QWidget *newWidget=LMH6518->getPTLMH6518();
                            newWidget->setWindowTitle("LMH 6518 Panel");
                            newWidget->show();
}

void AD5318::on_pushButton_2_clicked()
{
}

void AD5318::on_pushButton_clicked()
{
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
                            dPanelData="0";
                            ui->pushButton->setText("Enable Debug \nPanel");
                    }
                    else{
                            dPanelData="1";
                            ui->pushButton->setText("Disable Debug \nPanel");
                    }
            }
    }else{
            dPanelData="1";
            ui->pushButton->setText("Enable Debug \nPanel");
    }
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    QFile outFile("debugPanel.txt");
    outFile.open(QIODevice::WriteOnly);
    QTextStream ts(&outFile);
    ts <<dPanelData;
}

void AD5318::on_appBck_clicked()
{
    QWidget *newWidget = test->getPTAppBckPsoc();
    newWidget->setWindowTitle("AppCard BackPanel PSoC Panel");
    newWidget->show();
}

void AD5318::on_butHY3131_clicked()
{
    QWidget *newWidget = DMMTestjig->getDMMSPI();
    newWidget->show();
}
