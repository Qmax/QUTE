#include "widget.h"
#include "ui_widget.h"
#include <QPixmap>
#include <QClipboard>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QBrush>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
//QPixmap Pix = QPixmap();
//Pix = QPixmap::grabWidget(this,0,0,800,600);
//Pix.save("ICMJig.jpg");
//QClipboard *board = QApplication::clipboard();
//board->setPixmap(Pix);
    initialiseHWLibraries();
    Initialization();
    initialiseFeedBackResistance();
    qDebug()<< "ICM Loaded";
    QPluginLoader loader5("libWaveformTestjigInterface.so",this);
    objWaveProduct = qobject_cast<IQmaxWaveProduct*>(loader5.instance());

    objWaveProduct->ICreateWaveProduct("Oscillator",this->ui->groupBox_3);
    objWaveProduct->IsetDimensions(0,10,294,290);

    GenerateWaveform();
    m_nImpedanceValue=10.0;
    m_nICMMGR=0;
    ui->optDifferential->setChecked(true);
}

void Widget::initialiseFeedBackResistance()
{
	// Resistance Feedback
	m_lstRFResistance.insert(0,10.0);
	m_lstRFResistance.insert(1,100.0);
	m_lstRFResistance.insert(2,1000.0);
	m_lstRFResistance.insert(3,10000.0);
	m_lstRFResistance.insert(4,100000.0);
	m_lstRFResistance.insert(5,1000000.0);

	//Inductance Feedback
	m_lstRFInductance.insert(0,100.0);
	m_lstRFInductance.insert(1,100.0);
	m_lstRFInductance.insert(2,1000.0);
	m_lstRFInductance.insert(3,1000.0);
	m_lstRFInductance.insert(4,10000.0);
	m_lstRFInductance.insert(5,10000.0);
	m_lstRFInductance.insert(6,100000.0);

	//Capcitance Feedback
	m_lstRFCapcitance.insert(0,100000.0);
	m_lstRFCapcitance.insert(1,100000.0);
	m_lstRFCapcitance.insert(2,10000.0);
	m_lstRFCapcitance.insert(3,10000.0);
	m_lstRFCapcitance.insert(4,1000.0);
	m_lstRFCapcitance.insert(5,1000.0);
	m_lstRFCapcitance.insert(6,100.0);
	m_lstRFCapcitance.insert(7,100.0);
	m_lstRFCapcitance.insert(8,10.0);
}

void Widget::initialiseHWLibraries()
{
    QPluginLoader loader4("libQmaxPTInterface.so",this);
    ILineEdit = qobject_cast<IQmaxLineEdit*>(loader4.instance());
    INumberPanel=qobject_cast<IQmaxNumberPanel*>(loader4.instance());
	QPluginLoader loaderApp("libPTApplicationcardInterface.so", this);
	IAppCard = qobject_cast<IApplicationCardInterface*> (loaderApp.instance());
	qDebug() << "Appcard" << IAppCard;
	IAppCard->setDeviceName(SLOT0);
	IAppCard->enumerateAPPCard();
	IAppCard->setSPIAppendBit(0xC000);
	QPluginLoader loader2("libSPIMemoryInterface.so", this);
	ISPIMemory = qobject_cast<ISPIMemoryInterface*> (loader2.instance());
	ISPIMemory->setHardwarwObject(IAppCard);
	m_objAD7190Component = new AD7190Component(IAppCard);
	m_objAD5318Component = new AD5318Components(IAppCard);
	resetDAC();
	m_objAD7190Component->resetADC(1);
	m_objAD7190Component->resetADC(2);
	m_nFrequency=1000.0;
	m_nAVGSamples=1.0;
	ADCtimer = new QTimer(this);
	connect(ADCtimer, SIGNAL(timeout()), this, SLOT(readADC()));


}

void Widget::resetDAC()
{
	//IAppCard->setSPIAppendBit(0x1000);
	m_objAD5318Component->resetDAC5318(true);
	m_eSelect = DACF;
	m_objAD5318Component->configureADC5318CW();
	updateDAC(0.0);
	m_eSelect = DACG;
	m_objAD5318Component->configureADC5318CW();
	updateDAC(0.0);
}

void Widget::updateDAC(double pVolt)
{
	 AD5318_dataTemplate l_nAD5318DW;
	    l_nAD5318DW.m_eDACSelect = m_eSelect;
	    l_nAD5318DW.m_bCtrlBit = 0;
	    l_nAD5318DW.m_nVout = pVolt;
	    l_nAD5318DW.m_nVRef = 2.5;
	    l_nAD5318DW.m_bUniPolor = true;
	    if(m_eSelect == DACE || m_eSelect ==DACH)
	    	l_nAD5318DW.m_nVRef = 5.0;
	    if(m_eSelect == DACF || m_eSelect == DACG)
	    	l_nAD5318DW.m_bUniPolor = false;
	    m_objAD5318Component->configureADC5318Data(l_nAD5318DW);
}

void Widget::GenerateWaveform(){
    l_objReceive1Data=showICMTrace(1);

    double l_nBTU = (9 + 1.0) * 10.0;
    double l_nBD = (1 + 1.0);
    double l_nTotalTime = ((100) * (l_nBTU * l_nBD)) * 1.0/ 1000000000.0;
    l_objReceive1Data->m_nTimeperSample = 1.0 / (100/ 1);
    l_objReceive1Data->m_nCycles = 1;
    double m_nTime = 100 * l_objReceive1Data->m_nTimeperSample;
    l_objReceive1Data->m_nFrequency = 1 /(100 * (1.0 / (100/ 1)));//1 / m_nTime;
    l_objReceive1Data->m_nSamples = 100;
    l_objReceive1Data->m_nScreenTime = m_nTime;
    l_objReceive1Data->m_nXunits = 10.0;
    l_objReceive1Data->m_nYunits = 8.0;
    l_objReceive1Data->m_nMinX = 0.0;
    l_objReceive1Data->m_nOffset = 0.0;
    l_objReceive1Data->m_nSteps = 1.0;
    l_objReceive1Data->m_nAmplitude=0.9/0.6;
    l_objReceive1Data->m_nDutyCycles = (50 / 100.0);

objWaveProduct->ILoadPlotterData("./25.txt",l_objReceive1Data);
objWaveProduct->IWaveSettings();
objWaveProduct->IGenerateOscillatorPattern("SINE",0);

}
stWaveData* Widget::showICMTrace(int pWaveTrace)
{

    if(pWaveTrace==1)
    {
        m_objWaveData = new stWaveData();

        m_objWaveData->m_nAmplitude = 0.6;
        m_objWaveData->m_nFrequency = 1.0;
        m_objWaveData->m_nSteps= 0;
        m_objWaveData->m_nSamples = 1000;
        m_objWaveData->m_nScreenAmplitude = 1.0;
        m_objWaveData->m_nTimeperSample = 0.01;
        m_objWaveData->m_nScreenTime = 1.0;
        m_objWaveData->m_nXunits = 10.0;
        m_objWaveData->m_nYunits = 8.0;
        m_objWaveData->m_nMinX =0.0;
        m_objWaveData->m_nMinY =-1.0;
        m_objWaveData->m_nPhase =0.0;
        m_objWaveData->m_nOffset =0.0;
        m_objWaveData->m_nDutyCycles =0.0;
        m_objWaveData->m_nCycles = 5.0;
        m_objWaveData->m_nPreamble =0;
        m_objWaveData->m_nPostamble=0;
        m_objWaveData->m_bUniPolar = false;
        m_objWaveData->m_nSteps =0.0;
        m_objWaveData->m_nVRef =0.6;
        m_objWaveData->m_bCalibChecked = false;
        m_objWaveData->m_nCalibrationConstant =0.0;
        m_objWaveData->m_nCalibrationGain=0.0;
        m_objWaveData->m_nResolution =14;
        return m_objWaveData;
    }
    return 0;
}
//void Widget::HardwareInitializtaion(){
//qDebug()<<"ICM Hardware Initialisation";
//}
void Widget::enableRichGUI(){
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
	ui->groupBox->setParent(m_objWidget);
	ui->grpSettings->setParent(m_objWidget);
	ui->groupBox_2->setParent(m_objWidget);
	ui->groupBox_4->setParent(m_objWidget);
	ui->groupBox_3->setParent(m_objWidget);


	ui->grpGeneral->setGeometry  (20,  0,   271, 161);
	ui->groupBox->setGeometry    (20,  160, 271, 360);
	ui->grpSettings->setGeometry (309, 0,   474, 131);
	ui->groupBox_2->setGeometry  (309, 130, 474, 91 );
	ui->groupBox_4->setGeometry  (310, 230, 171, 290);
	ui->groupBox_3->setGeometry  (489, 220, 294, 300);

}
void Widget::Initialization(){
	ui->edAddress->setVisible(false);
	objAddress=ILineEdit->QmaxLineEdit(1, ui->grpGeneral);
	objAddress->setGeometry(90, 15, 120, 35);

	ui->edData->setVisible(false);
	objData=ILineEdit->QmaxLineEdit(2, ui->grpGeneral);
	objData->setGeometry(90, 60, 120, 35);

	ui->edAddress_2->setVisible(false);
	objForceVoltage=ILineEdit->QmaxLineEdit(3,ui->groupBox);
	objForceVoltage->setGeometry(130,30,91,41);

	ui->edAddress_3->setVisible(false);
	objFrequency=ILineEdit->QmaxLineEdit(4,ui->groupBox);
	objFrequency->setGeometry(130,80,111,35);

	ui->edAddress_6->setVisible(false);
	objAverageSamples=ILineEdit->QmaxLineEdit(5,ui->groupBox);
	objAverageSamples->setGeometry(140,320,111,35);

	//ui->edAddress_8->setVisible(false);
	objVoltage=ILineEdit->QmaxLineEdit(6,ui->groupBox_2);
	objVoltage->setGeometry(30,41,100,35);

	//ui->edAddress_4->setVisible(false);
	objResistance=ILineEdit->QmaxLineEdit(7,ui->groupBox_2);
	objResistance->setGeometry(140,41,100,35);

	//ui->edAddress_5->setVisible(false);
	objCapacitance=ILineEdit->QmaxLineEdit(8,ui->groupBox_2);
	objCapacitance->setGeometry(250,41,100,35);

	//ui->edAddress_7->setVisible(false);
	objInductance=ILineEdit->QmaxLineEdit(9,ui->groupBox_2);
	objInductance->setGeometry(360,41,100,35);

	connect(objAddress,       SIGNAL(focussed(bool)), this, SLOT(callAddressEdit()));
	connect(objData,          SIGNAL(focussed(bool)), this, SLOT(callDataEdit()));
	connect(objForceVoltage,  SIGNAL(focussed(bool)), this, SLOT(callForceVoltageEdit()));
	connect(objFrequency,     SIGNAL(focussed(bool)), this, SLOT(callFrequencyEdit()));
	connect(objAverageSamples,SIGNAL(focussed(bool)), this, SLOT(callAverageSamplesEdit()));

	objData->setStyleSheet(		"border-width: 2px;border-style: outset;border-color: gray; border-radius: 10px;  padding: 0 8px;     background: black;     selection-background-color: yellow;   color:white;     font: bold 14px;"    );
	objAddress->setStyleSheet(	"border-width: 2px;border-style: outset;border-color: gray; border-radius: 10px;  padding: 0 8px;     background: black;     selection-background-color: yellow;   color:white;     font: bold 14px;"    );
	objForceVoltage->setStyleSheet(	"border-width: 2px;border-style: outset;border-color: gray; 					    padding: 0 8px;     background: black;     selection-background-color: yellow;   color:white;     font: bold 14px;"    );
	objFrequency->setStyleSheet("border-width: 2px;border-style: outset;border-color: gray; 						padding: 0 8px;     background: black;     selection-background-color: yellow;   color:white;     font: bold 14px;"    );
	objAverageSamples->setStyleSheet(		"border-width: 2px;border-style: outset;border-color: gray; 						padding: 0 8px;     background: black;     selection-background-color: yellow;   color:white;     font: bold 14px;"    );
	objVoltage->setStyleSheet(	"border-width: 2px;border-style: outset;border-color: gray; 						padding: 0 8px;     background: black;     selection-background-color: yellow;   color:white;     font: bold 14px;"    );
	objResistance->setStyleSheet(	"border-width: 2px;border-style: outset;border-color: gray;						padding: 0 8px;     background: black;     selection-background-color: yellow;   color:white;     font: bold 14px;"    );
	objCapacitance->setStyleSheet(	"border-width: 2px;border-style: outset;border-color: gray;						padding: 0 8px;     background: black;     selection-background-color: yellow;   color:white;     font: bold 14px;"    );
	objInductance->setStyleSheet(	"border-width: 2px;border-style: outset;border-color: gray;						padding: 0 8px;     background: black;     selection-background-color: yellow;   color:white;     font: bold 14px;"    );

	enableRichGUI();
	ui->optDifferential->setChecked(true);

	m_lstReistance.insert(0,10);
	m_lstReistance.insert(0,100);
	m_lstReistance.insert(0,1000);
	m_lstReistance.insert(0,10000);
	m_lstReistance.insert(0,1000000);
	m_nSamples=100;
	ui->optResistance->setChecked(true);
	//m_nAVGSamples=1;

}
void Widget::receiveValue(unsigned int pValue){
	if(m_nLineEditIndex==1){
		objAddress->setText(QString::number(pValue,16));
		m_nAddress=pValue;
	}
	else if(m_nLineEditIndex==2){
		objData->setText(QString::number(pValue,16));
		m_nData=pValue;
	}
}
void Widget::receiveValue(double pValue){
	if(m_nLineEditIndex==3){
		objForceVoltage->setText(QString::number(pValue,'f',5));
		m_nForceVoltage = pValue;
	}
	else if(m_nLineEditIndex==4){
		objFrequency->setText(QString::number(pValue,'f',5));
		m_nFrequency= pValue;
		if(ui->chkDDSFreq->isChecked())
		{
			//m_nFrequency= validateFrequency(pValue);
			calculateDDSFrequency();
		}
		else
		{
			calculateFrequency();
		}


	}
	else if(m_nLineEditIndex==5){
		objAverageSamples->setText(QString::number(pValue,'f',5));
		m_nAVGSamples=pValue;
	}
}


double Widget::validateFrequency(double pFrequency) {
	double l_nFrequency = pFrequency;
	//qDebug()<<"Check:"<<pFrequency;
	QString l_strFreqUnit = QString("hz");
	if (l_nFrequency >= 1000000.0) {
		l_nFrequency = l_nFrequency / 1000000.0;
		l_strFreqUnit = QString("Mhz");
	} else if (l_nFrequency >= 1000.0) {
		l_nFrequency = l_nFrequency / 1000.0;
		l_strFreqUnit = QString("Khz");
	}
	qDebug() << "Frequency:" << l_nFrequency << l_strFreqUnit;
	return l_nFrequency;
}


void Widget::calculateDDSFrequency()
{
	double l_nFTWOutputFrequency, l_nOutputTime;
	l_nFTWOutputFrequency = (m_nFrequency / 50000000);
	l_nFTWOutputFrequency = l_nFTWOutputFrequency * pow(2, 32);
	l_nOutputTime = 1 / l_nFTWOutputFrequency;
	qDebug() << "FTW Output Frequency:" << l_nFTWOutputFrequency;
	qDebug() << "FTW Output Time:" << l_nOutputTime;
	unsigned int l_nFTW_LSW = ((unsigned int) l_nFTWOutputFrequency << 16) >> 16;
	unsigned int l_nFTW_MSW = (unsigned int) l_nFTWOutputFrequency >> 16;
	qDebug() << "FTW_LSW" << hex << l_nFTW_LSW;
	qDebug() << "FTW_MSW" << hex << l_nFTW_MSW;
	IAppCard->setDDSFTW_LSW(l_nFTW_LSW);
	IAppCard->setDDSFTW_MSW(l_nFTW_MSW);

}
void Widget::receiveValue(QString pValue){
	Q_UNUSED(pValue)
}
void Widget::callAddressEdit() {
	if (objAddress->hasFocus()) {
		openNumKBPanel(0);
		m_nLineEditIndex = 1;
	}
}

void Widget::callDataEdit() {
	if (objData->hasFocus()) {
		openNumKBPanel(0);
		m_nLineEditIndex = 2;
	}

}

void Widget::callForceVoltageEdit(){
	if (objForceVoltage->hasFocus()) {
		openNumKBPanel(1, 1, 'v', 1000, 0,this);
		m_nLineEditIndex = 3;
	}
}

void Widget::callFrequencyEdit(){
	if (objFrequency->hasFocus()) {
		openNumKBPanel(1, 1, 'F', 2000000, 0.01,this);
		m_nLineEditIndex = 4;
	}
}

void Widget::callAverageSamplesEdit(){
	if (objAverageSamples->hasFocus()) {
		openNumKBPanel(1);
		m_nLineEditIndex = 5;
	}
}

void Widget::openNumKBPanel(short int pValue) {

	QWidget *w = INumberPanel->getNumKBPanel(pValue, this);
	w->setWindowFlags(Qt::WindowCloseButtonHint | Qt::Dialog);
	w->show();
}
void Widget::openNumKBPanel(short int pValue,double incRatio,char type,double max,double min,QWidget* parent) {

	QWidget *w = INumberPanel->getNumKBPanelIncDec(pValue,incRatio,type,max,min,parent);
	w->setWindowFlags(Qt::WindowCloseButtonHint | Qt::Dialog);
	w->show();
}

Widget::~Widget()
{
	qDebug()<<"ICM Destroyed";
    delete ui;
}

void Widget::changeEvent(QEvent *e)
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

void Widget::on_butRead_clicked()
{
	objData->setText(QString::number(
			IAppCard->readRegister(m_nAddress), 16));

}

void Widget::on_butWrite_clicked()
{
    IAppCard->writeRegister(m_nData,m_nAddress);
}


void Widget::on_chkCapSet_clicked()
{

	if(ui->chkCapSet->isChecked())
	    {
	        m_nICMMGR|=1<<5;
	    }
	    else
	    {
	        m_nICMMGR &=0xFFDF;
	    }
	IAppCard->writeRegister(m_nICMMGR,0x3A);


}
void Widget::on_chkPOTSel_clicked()
{
	if(ui->chkPOTSel->isChecked())
	    {
	        m_nICMMGR|=1<<4;
	    }
	    else
	    {
	        m_nICMMGR &=0xFFEF;
	    }
	IAppCard->writeRegister(m_nICMMGR,0x3A);

}
void Widget::on_chkDivSel_clicked()
{
	if(ui->chkDivSel->isChecked())
	    {
	        m_nICMMGR|=1<<3;
	    }
	    else
	    {
	        m_nICMMGR &=0xFFF7;
	    }
	IAppCard->writeRegister(m_nICMMGR,0x3A);

}

void Widget::calculateFrequency()
{
//	double l_nTimePerSample = (m_nFrequency) /m_nSamples;
    double l_nTimePerSample = (1.0/m_nFrequency);
    double l_nConvertedinNS= l_nTimePerSample * 1000000000.0;
  //  double l_nTickTime = l_nTimePerSample / (1/100000000);
    double l_nBD = l_nConvertedinNS / m_nSamples;

    unsigned short l_nBTUR,l_nBDR;
    l_nBTUR = (l_nBD /10)-1;
    l_nBDR = 0;
    qDebug()<< "BTUR"<<l_nBTUR;
    qDebug()<< "BDR"<<l_nBDR;
    IAppCard->basicTimeUnit(l_nBTUR);
    IAppCard->basicDuration(l_nBDR);
//	qDebug()<<"Frequency:"<<m_nFrequency;
//	qDebug()<<"TimeperSample:"<<l_nTimePerSample;
//	unsigned short l_nTotalCount = (unsigned short)((l_nTimePerSample) / (1/100000000.0));
//	qDebug()<<"Frequency:"<<m_nFrequency;
//	qDebug()<<"TimeperSample:"<<l_nTimePerSample;
//	qDebug()<<"Total TimeCount:"<<l_nTotalCount;
//	unsigned short l_nQuotient = 0;
}

void Widget::on_chkDDSFreq_clicked()
{
	if(ui->chkDDSFreq->isChecked())
	{
		ui->chkP1V->setDisabled(true);
		ui->chkP2V->setDisabled(true);
	}
	else
	{
		ui->chkP1V->setDisabled(false);
		ui->chkP2V->setDisabled(false);
	}
//	calculateDDSFrequency();
	IAppCard->basicTimeUnit(1);
	IAppCard->basicDuration(1);
	IAppCard->setDrivePeriod(1);
	IAppCard->setStartStop(10, 0);
	IAppCard->setDDSWaveSelect(DDS);
	IAppCard->writeRegister(0x81,0x68);
	//IAppCard->startDrive(1);

}
void Widget::on_butMeasure_clicked()
{
	qDebug()<<"Inside Measure";
	IAppCard->startDrive(1);
	//calculateFrequency();
	//IAppCard->writeRegister(1,0x16);
	ADCtimer->start(300);
}
void Widget::on_butStop_clicked()
{
	IAppCard->stopDrive();
	ADCtimer->stop();
}
void Widget::on_butDCDrive_clicked()
{
	IAppCard->basicTimeUnit(1);
	IAppCard->basicDuration(1);
	IAppCard->setDrivePeriod(1);
	IAppCard->setStartStop(0, 0);
	IAppCard->setDDSWaveSelect(DC_SIGNAL);
	unsigned int m_nHexCode=(unsigned int)(((m_nForceVoltage+0.6)*(pow(2,14)-1))/(2*0.6));
	qDebug()<<"Hex Code:"<<m_nHexCode;
	IAppCard->setDDSDACDCdrive(m_nHexCode);
	IAppCard->startDrive(1);

}

void Widget::on_chkReceiver1_clicked()
{
	if(ui->chkReceiver1->isChecked())
	{
		m_objAD7190Component->writeADCConfigurationRegister(1,0x110);
		m_objAD7190Component->writeADCModeRegister(1,0x80060);
		IAppCard->writeRegister(0x22,0x36);
		IAppCard->writeRegister(0x1,0x16); // Soruce Impedance Disable
		IAppCard->writeRegister(0x7,0x34);
		IAppCard->writeRegister(0,0x3A);
//		IAppCard->writeRegister()
	}
}
void Widget::on_chkReceiver2_clicked()
{
	if(ui->chkReceiver1->isChecked())
	{
		m_objAD7190Component->writeADCConfigurationRegister(2,0x110);
		m_objAD7190Component->writeADCModeRegister(2,0x80060);
		IAppCard->writeRegister(0x46,0x38);
		IAppCard->writeRegister(0x1,0x16); // Soruce Impedance Disable
		IAppCard->writeRegister(0x7,0x34);
		IAppCard->writeRegister(0,0x3A);

	}
}

void Widget::on_optDifferential_clicked()
{

}
void Widget::on_optPseudo_clicked()
{

}
void Widget::readADC()
{
	short int l_nResoulution = 23;
	double l_nGain = 1.0, l_nVREF = 2.048;
	double l_nFactor1 = 0.0, l_nFactor2 = 0.0, l_nAIN1 = 0.0,l_nAIN2;
	short int l_nLoopIndex=0;
	if(ui->chkReceiver1->isChecked())
	{
		while(l_nLoopIndex<m_nAVGSamples){
			m_nADC1Voltage=m_objAD7190Component->readADCDataRegister(1) & 0xFFFFFF;
			l_nLoopIndex++;
		}
		m_nADC1Voltage = m_nADC1Voltage/m_nAVGSamples;
		qDebug()<<"Hex ADC1 Code:"<<hex<<m_nADC1Voltage;
		if(ui->optDifferential->isChecked()){
			l_nFactor1 = (m_nADC1Voltage / pow(2, l_nResoulution)) - 1;
			l_nFactor2 = (l_nGain / l_nVREF);
			l_nAIN1 = l_nFactor1 / l_nFactor2;
		}
		else if(ui->optPseudo->isChecked())
		{
			l_nFactor1 = (m_nADC1Voltage * l_nVREF) / (pow(2, l_nResoulution)) * l_nGain;
			l_nAIN1=l_nFactor1;
		}
		qDebug()<<"Converted ADC1 Code:"<<l_nAIN1;
		ui->lblADC1->setText(QString::number(l_nAIN1,'f',8));
	}
	else
	{
		ui->lblADC1->setText("0");
	}
	l_nLoopIndex=0;
	if(ui->chkReceiver1->isChecked())
	{
		while(l_nLoopIndex<m_nAVGSamples){
			m_nADC2Voltage=m_objAD7190Component->readADCDataRegister(2) & 0xFFFFFF;
			l_nLoopIndex++;
		}
		m_nADC2Voltage = m_nADC2Voltage/m_nAVGSamples;
		qDebug()<<"Hex ADC2 Code:"<<hex<<m_nADC2Voltage;
		if(ui->optDifferential->isChecked()){
			l_nFactor1 = (m_nADC2Voltage / pow(2, l_nResoulution)) - 1;
			l_nFactor2 = (l_nGain / l_nVREF);
			l_nAIN2 = l_nFactor1 / l_nFactor2;
		}
		else if(ui->optPseudo->isChecked())
		{
			l_nFactor1 = (m_nADC2Voltage * l_nVREF) / (pow(2, l_nResoulution)) * l_nGain;
			l_nAIN2=l_nFactor1;
		}


		qDebug()<<"Converted ADC2 Code:"<<l_nAIN2;
		ui->lblADC2->setText(QString::number(l_nAIN2,'f',8));
	}
	else
	{
		ui->lblADC2->setText("0");
	}
	double l_nImpedanceValue=m_nImpedanceValue;
	qDebug()<<"Impedance Value:"<<l_nImpedanceValue;
	double l_n1 = (l_nImpedanceValue/l_nAIN2);
	qDebug()<< "Division:"<<l_n1;
	m_nResistance = (l_n1 * l_nAIN1);
	qDebug()<< "MUL:"<<m_nResistance;
	//qDebug() << "Resistance:"<<m_nResistance;
	double l_RMSDiv =(2 * (3.14) *m_nFrequency * m_nResistance);
	m_nCapacitance = 1 / l_RMSDiv;
	//GetRange(m_nCapcitance,ui->cmbCapcitance->currentIndex());
	//if(m_nCapacitance < 1 / 1000000000000.0)
	//m_nCapacitance = m_nCapacitance * 1000000000000.0;
	double l_RMSDiv1 =(2 * (3.14) *m_nFrequency);
	m_nInductance = m_nResistance / l_RMSDiv1;
	qDebug()<<"Capacitance:"<<m_nCapacitance;
	if(ui->optResistance->isChecked()){
		GetDisplayResistance(m_nResistance,l_nImpedanceValue);
		ui->lblResistance->setText(QString::number(m_nResistance,'f',5));
	}
	else if(ui->optCapacitance->isChecked()){
		//objCapacitance->setText(QString::number(m_nCapacitance,'f',4));
		GetDisplayCapcitance(m_nCapacitance,ui->cmbCapcitance->currentIndex());
		ui->lblResistance->setText(QString::number(m_nCapacitance,'f',15));
	}
	else if(ui->optInductance->isChecked()){
		GetDisplayInductance(m_nInductance,ui->cmbInductance->currentIndex());
		ui->lblResistance->setText(QString::number(m_nInductance,'f',15));
	}
}

void Widget::GetDisplayResistance(double pResistanceValue,double pRangeValue)
{
	QString l_strResistanceValue("");
	if(pResistanceValue <1000.0)
	{
		if(pRangeValue == 10.0 || pRangeValue==10000.0)
		{
			l_strResistanceValue = QString::number(pResistanceValue,'f',2) + " E";
		}
		else if(pRangeValue == 100.0 || pRangeValue==100000.0)
		{
			l_strResistanceValue = QString::number(pResistanceValue,'f',1) + " E";
		}
		else
		{
			l_strResistanceValue = QString::number(pResistanceValue,'f',3) + " E";
		}
	}
	else if(pResistanceValue >=1000.0 && pResistanceValue<1000000)
	{
		if(pRangeValue == 1000.0 || pRangeValue==1000000.0)
		{
			l_strResistanceValue = QString::number((pResistanceValue/1000.0),'f',3) + " K";
		}
		else if(pRangeValue == 10000.0 || pRangeValue==10.0)
		{
			l_strResistanceValue = QString::number((pResistanceValue/1000.0),'f',2) + " K";
		}
		else if(pRangeValue == 100000.0 || pRangeValue==100.0)
		{
			l_strResistanceValue = QString::number((pResistanceValue/1000.0),'f',1) + " K";
		}
	}
	else if(pResistanceValue >= 1000000.0 )
	{
		l_strResistanceValue = QString::number((pResistanceValue/1000000.0),'f',3) + " M";

	}
	objResistance->setText(l_strResistanceValue);
}

void Widget::GetDisplayCapcitance(double p_nData,short int p_nRange)
{
	QString l_sDisplayData("");
	if (p_nRange == 0)
	{
		p_nData = p_nData * 1000000000000.0;
		l_sDisplayData = QString::number((p_nData),'f',2) + " pF";
	}
    else if (p_nRange == 1)
    {
        p_nData = p_nData * 1000000000000.0;
        l_sDisplayData = QString::number((p_nData),'f',2) + " pF";
    }
    else if (p_nRange == 2)
    {
        p_nData = p_nData * 1000000000.0;
        l_sDisplayData = QString::number((p_nData),'f',2) + " nF";
    }
    else if (p_nRange == 3)
    {
        p_nData = p_nData * 1000000000.0;
        l_sDisplayData = QString::number((p_nData),'f',2) + " nF";
    }
    else if (p_nRange == 4)
    {
        p_nData = p_nData * 1000000000.0;
        l_sDisplayData = QString::number((p_nData),'f',2) + " nF";
    }
    else if (p_nRange == 5)
    {
        p_nData = p_nData * 1000000.0;
        l_sDisplayData = QString::number((p_nData),'f',2) + " uF";
    }
    else if (p_nRange == 6)
    {
        p_nData = p_nData * 1000000.0;
        l_sDisplayData = QString::number((p_nData),'f',2) + " uF";
    }
    else if (p_nRange == 7)
    {
        p_nData = p_nData * 1000000.0;
        l_sDisplayData = QString::number((p_nData),'f',2) + " uF";
    }
    else if (p_nRange == 8)
    {
        p_nData = p_nData * 1000.0;
        l_sDisplayData = QString::number((p_nData),'f',2) + " mF";
    }
	objCapacitance->setText(l_sDisplayData);
}
void Widget::GetDisplayInductance(double p_nData,short int p_nRange)
{
	QString l_sDisplayData("");
	if (p_nRange == 0) // 300nH - 3uH
	{
		 p_nData = p_nData * 1000000000;
		 l_sDisplayData = QString::number((p_nData),'f',1) + " nH";
	}
	else if(p_nRange == 1) // 3uH - 30uH
	{
		 p_nData = p_nData * 1000000;
		 l_sDisplayData = QString::number((p_nData),'f',2) + " uH";
	}
	else if(p_nRange == 2) // 30uH - 300 uH
	{
		 p_nData = p_nData * 1000000;
		 l_sDisplayData = QString::number((p_nData),'f',2) + " uH";
	}
	else if(p_nRange == 3) // 300uH - 3mH
	{
		 p_nData = p_nData * 1000000;
		 l_sDisplayData = QString::number((p_nData),'f',2) + " uH";
	}
	else if(p_nRange == 4) // 3mH - 30mH
	{
		 p_nData = p_nData * 1000;
		 l_sDisplayData = QString::number((p_nData),'f',2) + " mH";
	}
	else if(p_nRange == 5) // 30mH - 300mH
	{
		 p_nData = p_nData * 1000;
		 l_sDisplayData = QString::number((p_nData),'f',2) + " mH";
	}
	else if(p_nRange == 6) // 300mH - 3H
	{
		 p_nData = p_nData * 1000;
		 l_sDisplayData = QString::number((p_nData),'f',2) + " mH";
	}
	else if(p_nRange == 7) // 3H - 30H
	{
		 l_sDisplayData = QString::number((p_nData),'f',2) + " H";
	}
	objInductance->setText(l_sDisplayData);
}


void Widget::GetRange(double p_nValue,short int pIndex)
{
	Q_UNUSED(pIndex);
//	 switch (pIndex)
//	 {
//	 case 0:		// 10pF - 100 pF
//	 {
//
//	 }
//	 break;
//	 case 1:		// 100pF - 1nF
//	 {
//
//	 }
//	 break;
//	 case 2:		// 1nF - 10nF
//	 {
//
//	 }
//	 break;
//	 case 3:		// 10nF - 100nF
//	 {
//
//	 }
//	 break;
//	 case 4:		// 100nF - 1uF
//	 {
//
//	 }
//	 break;
//	 case 5:		// 1uF - 10uF
//	 {
//
//	 }
//	 break;
//	 case 6:		// 10ufF - 100uF
//	 {
//
//	 }
//	 break;
//	 case 7:		// 100pF - 1nF
//	 {
//
//	 }
//	 break;
//	 }
}

void Widget::on_optResistance_clicked()
{
	objCapacitance->setDisabled(true);
	objInductance->setDisabled(true);
	objResistance->setDisabled(false);
	ui->cmbCapcitance->setDisabled(true);
	ui->cmbInductance->setDisabled(true);
	ui->cmbResistance->setDisabled(false);
}
void Widget::on_optCapacitance_clicked()
{
	objCapacitance->setDisabled(false);
	objInductance->setDisabled(true);
	objResistance->setDisabled(true);
	ui->cmbCapcitance->setDisabled(false);
	ui->cmbInductance->setDisabled(true);
	ui->cmbResistance->setDisabled(true);

}
void Widget::on_optInductance_clicked()
{
	objCapacitance->setDisabled(true);
	objInductance->setDisabled(false);
	objResistance->setDisabled(true);
	ui->cmbCapcitance->setDisabled(true);
	ui->cmbInductance->setDisabled(false);
	ui->cmbResistance->setDisabled(true);
}


void Widget::on_cmbICMRange_currentIndexChanged(int index)
{
	 m_nICMMGR = m_nICMMGR & 0xFFF8;
	 m_nICMMGR |= index;
	 qDebug()<<"Resistance Range Selection:"<<hex<<m_nICMMGR<<index;
	 IAppCard->writeRegister(m_nICMMGR,0x3A);
	 m_nImpedanceValue = m_lstRFResistance.value(index);
}

void Widget::on_cmbResistance_currentIndexChanged(int index)
{
	//m_nImpedanceValue = m_lstRFResistance.value(index);

}
void Widget::on_cmbCapcitance_currentIndexChanged(int index)
{
	//m_nImpedanceValue = m_lstRFResistance.value(index);
}
void Widget::on_cmbInductance_currentIndexChanged(int index)
{
	//m_nImpedanceValue = m_lstRFResistance.value(index);
}

void Widget::GenerateSINEPattern(double pValue)
{

	m_nData1.clear();
    unsigned int l_nSampleIndex=0;
    unsigned int l_nIndex =0;
    unsigned int l_nSamples=0;
   // unsigned int l_nRemainder =0;
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
    l_nPhaseAngle = (l_nDegree*(3.14)) / 180.0;
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
            l_nPhaseAngle = (l_nPhaseAngle +(2*3.14) / (l_nSamples/l_nCycles));
            l_nXPoint += l_nTimerPerSamples;
            if(l_nPhaseAngle > (2*3.14))
                l_nPhaseAngle = l_nPhaseAngle - (2*3.14);

        }
        l_nSamples += l_nTemp;
        l_nSampleIndex++;
    }
    GenerateHexPattern();
}

void Widget::on_chkP1V_clicked()
{
	if(ui->chkP1V->isChecked()){
		GenerateSINEPattern(0.2);
		ISPIMemory->accessSPIRAM(DRIVERAM);
		ISPIMemory->setAutoIncrement();
		ISPIMemory->writeAppCardSRAM(0,100,&mValues[0]);
		usleep(1000);
		IAppCard->setDDSWaveSelect(RAM_DATA);
		RAMACCESS pRAMSelect;
		pRAMSelect.m_bDRAMMODE=true;
		pRAMSelect.m_bRRAM1MODE=true;
		IAppCard->setRAMModeAccess(pRAMSelect);
		IAppCard->setDriveRAMStarAddress(0);
		IAppCard->setDriveRAMEndAddress(0x63);
		calculateFrequency();
		IAppCard->setDrivePatternCount(false,0);
		IAppCard->startDrive(1);
		usleep(1000);
		IAppCard->setDrivePatternCount(true,0);
		IAppCard->startDrive(1);
//		IAppCard->writeRegister(0,0x82);
//		IAppCard->writeRegister(0x63,0x84);
		//IAppCard->writeRegister(0x3,0x86);

	}

}

void Widget::on_chkP2V_clicked()
{
	if(ui->chkP2V->isChecked()){
		GenerateSINEPattern(0.4);
		ISPIMemory->accessSPIRAM(DRIVERAM);
		ISPIMemory->setAutoIncrement();
		ISPIMemory->writeAppCardSRAM(0,100,&mValues[0]);
		IAppCard->writeRegister(0,0x82);
		IAppCard->writeRegister(0x63,0x84);
		IAppCard->writeRegister(0x3,0x86);
		IAppCard->writeRegister(0x0,0x72); // RAM MODE
	}
}

 void Widget::GenerateHexPattern()
 {
	 mValues = new unsigned short int[100];
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
        mValues[l_nIndex] = l_nHexValue;
        QString l_strHexValue;
        fprintf(fpWaveFile,"%X\n",l_nHexValue);
    }
    fclose(fpWaveFile);
}
//Q_EXPORT_PLUGIN2(IICMTestJigInterface,Widget);
