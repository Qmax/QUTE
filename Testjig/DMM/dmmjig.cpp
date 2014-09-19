#include "dmmjig.h"
#include "ui_dmmjig.h"
#include <QClipboard>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPixmap>
#include <QBrush>


DMMJig::DMMJig(QWidget *parent) :   QWidget(parent),   ui(new Ui::DMMJig)
{
    ui->setupUi(this);

    QPluginLoader loader4("libQmaxPTInterface.so",this);
    ILineEdit = qobject_cast<IQmaxLineEdit*>(loader4.instance());
    INumberPanel=qobject_cast<IQmaxNumberPanel*>(loader4.instance());

    Initialization();
    InitializeHardwareLibraries();
    InitializeHardwareValues();

    qDebug()<< "DMM Loaded";

	/*QPixmap Pix = QPixmap();//ScreenShot Code
    Pix = QPixmap::grabWidget(this,0,0,800,600);
    Pix.save("DMMJig.jpg");
    QClipboard *board = QApplication::clipboard();
    board->setPixmap(Pix);*/
    QPluginLoader loader5("libWaveformTestjigInterface.so",this);
    objWaveProduct = qobject_cast<IQmaxWaveProduct*>(loader5.instance());
    objWaveProduct->ICreateWaveProduct("Oscillator",this->ui->groupBox_5);
    objWaveProduct->IsetDimensions(0,10,450,210);
    GenerateWaveform();
}
void DMMJig::GenerateWaveform(){
    l_objReceive1Data=showDMMTrace(1);

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
stWaveData* DMMJig::showDMMTrace(int pWaveTrace)
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
//void DMMJig::HardwareInitializtaion(){
//	qDebug()<<"DMM Hardware Initialisation";
//
//}
void DMMJig::enableRichGUI(){
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
	ui->groupBox_2->setParent(m_objWidget);
	ui->groupBox_3->setParent(m_objWidget);
	ui->groupBox_4->setParent(m_objWidget);
	ui->groupBox_5->setParent(m_objWidget);
	ui->grpSettings->setParent(m_objWidget);

	ui->grpGeneral->setGeometry(20,0,291,184);
	ui->groupBox->setGeometry(20,180,291,271);
	ui->groupBox_2->setGeometry(330,210,451,91);
	ui->groupBox_3->setGeometry(20,451,291,69);
	ui->groupBox_4->setGeometry(330,0,451,101);
	ui->groupBox_5->setGeometry(330,300,451,220);
	ui->grpSettings->setGeometry(330,100,451,101);


}
void DMMJig::Initialization(){
	ui->edAddress->setVisible(false);
	objAddress=ILineEdit->QmaxLineEdit(1, ui->grpGeneral);
	objAddress->setGeometry(90, 15, 120, 35);
	objAddress->setFont(QFont("DejaVu Sans",13,50,false));

	ui->edData->setVisible(false);
	objData=ILineEdit->QmaxLineEdit(2, ui->grpGeneral);
	objData->setGeometry(90, 60, 120, 35);
	objData->setFont(QFont("DejaVu Sans",13,50,false));

	ui->edAddress_2->setVisible(false);
	objForceCurrent=ILineEdit->QmaxLineEdit(3,ui->groupBox);
	objForceCurrent->setGeometry(140,47,111,35);
	objForceCurrent->setFont(QFont("DejaVu Sans",13,50,false));

	ui->edAddress_6->setVisible(false);
	objAvgSamples=ILineEdit->QmaxLineEdit(4,ui->groupBox_3);
	objAvgSamples->setGeometry(140,20,111,35);
	objAvgSamples->setFont(QFont("DejaVu Sans",13,50,false));

	objDACVoltage=ILineEdit->QmaxLineEdit(4,ui->grpGeneral);
	objDACVoltage->setGeometry(100,155,111,35);
	objDACVoltage->setFont(QFont("DejaVu Sans",13,50,false));


//	ui->edAddress_3->setVisible(false);
//	objVoltage=ILineEdit->QmaxLineEdit(5,ui->groupBox_2);
//	objVoltage->setGeometry(10,40,120,35);
//	objVoltage->setFont(QFont("DejaVu Sans",13,50,false));
//
//	ui->edAddress_4->setVisible(false);
//	objCurrent=ILineEdit->QmaxLineEdit(6,ui->groupBox_2);
//	objCurrent->setGeometry(160,40,120,35);
//	objCurrent->setFont(QFont("DejaVu Sans",13,50,false));
//
//	ui->edAddress_5->setVisible(false);
//	objResistance=ILineEdit->QmaxLineEdit(7,ui->groupBox_2);
//	objResistance->setGeometry(310,40,120,35);
//	objResistance->setFont(QFont("DejaVu Sans",13,50,false));

	connect(objAddress, SIGNAL(focussed(bool)), this,SLOT(callAddressEdit()));
	connect(objData, SIGNAL(focussed(bool)), this, SLOT(callDataEdit()));
	connect(objForceCurrent, SIGNAL(focussed(bool)), this, SLOT(callForceCurrentEdit()));
	connect(objDACVoltage, SIGNAL(focussed(bool)), this, SLOT(callDACVoltage()));
	connect(objAvgSamples, SIGNAL(focussed(bool)), this, SLOT(callSamplesEdit()));

	objData->setStyleSheet(		"border-width: 2px;border-style: outset;border-color: gray; border-radius: 10px;  padding: 0 8px;     background: black;     selection-background-color: yellow;   color:white;     font: bold 14px;"    );
	objAddress->setStyleSheet(	"border-width: 2px;border-style: outset;border-color: gray; border-radius: 10px;  padding: 0 8px;     background: black;     selection-background-color: yellow;   color:white;     font: bold 14px;"    );
	objForceCurrent->setStyleSheet(	"border-width: 2px;border-style: outset;border-color: gray; 					    padding: 0 8px;     background: black;     selection-background-color: yellow;   color:white;     font: bold 14px;"    );
	objAvgSamples->setStyleSheet("border-width: 2px;border-style: outset;border-color: gray; 						padding: 0 8px;     background: black;     selection-background-color: yellow;   color:white;     font: bold 14px;"    );
	objDACVoltage->setStyleSheet("border-width: 2px;border-style: outset;border-color: gray; 						padding: 0 8px;     background: black;     selection-background-color: yellow;   color:white;     font: bold 14px;"    );
//	objVoltage->setStyleSheet(		"border-width: 2px;border-style: outset;border-color: gray; 						padding: 0 8px;     background: black;     selection-background-color: yellow;   color:white;     font: bold 14px;"    );
//	objCurrent->setStyleSheet(	"border-width: 2px;border-style: outset;border-color: gray; 						padding: 0 8px;     background: black;     selection-background-color: yellow;   color:white;     font: bold 14px;"    );
//	objResistance->setStyleSheet(	"border-width: 2px;border-style: outset;border-color: gray;						padding: 0 8px;     background: black;     selection-background-color: yellow;   color:white;     font: bold 14px;"    );


	enableRichGUI();

}
void DMMJig::InitializeHardwareLibraries(){
    QPluginLoader loaderApp("libPTApplicationcardInterface.so", this);
    IAppCard = qobject_cast<IApplicationCardInterface*> (loaderApp.instance());
    IAppCard->setDeviceName(SLOT0);
    IAppCard->enumerateAPPCard();
    qDebug()<<"App Card Code ID:"<<hex<<IAppCard->readAppCardCodeId();
    IAppCard->setSPIAppendBit(0xC000);
    m_objAD5318Component = new AD5318Components(IAppCard);
    m_objAD7190Component = new AD7190Component(IAppCard);


    QPluginLoader loader3("libPTPsocInterface2.so",this);
    IPsoc = qobject_cast<IPSOCCOMMUNICATION*>(loader3.instance());
    IPsoc->openSerial();

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(LoopDrive()));
}
void DMMJig::InitializeHardwareValues(){


    AD5318_dataTemplate l_nAD5318DW;
	m_objAD5318Component->resetDAC5318(true);

    m_eSelect = DACF;
   	m_objAD5318Component->configureADC5318CW();
    l_nAD5318DW.m_eDACSelect = m_eSelect;
    l_nAD5318DW.m_bCtrlBit = 0;
    l_nAD5318DW.m_nVout = 0.0;
    l_nAD5318DW.m_nVRef = 2.5;
    l_nAD5318DW.m_bUniPolor = true;
    l_nAD5318DW.m_bUniPolor = false;
    m_objAD5318Component->configureADC5318Data(l_nAD5318DW);

   	m_eSelect = DACG;
   	m_objAD5318Component->configureADC5318CW();
   	l_nAD5318DW.m_eDACSelect = m_eSelect;
    m_objAD5318Component->configureADC5318Data(l_nAD5318DW);

    for(int i=0;i<5;i++){
        m_nRangeSlope[i]=1.0;
        m_nRangeConstant[i]=0.0;
    }
    readCurrentCalibrationFile();

    unsigned int m_nModeRegister=0x80060,m_nConfigurationRegister=0x4010;
    m_objAD7190Component->writeADCConfigurationRegister(1,m_nConfigurationRegister);
    m_objAD7190Component->writeADCModeRegister(1,m_nModeRegister);

    m_objAD7190Component->writeADCGPConRegister(1,0x31);

    IAppCard->writeRegister(0x0010,0x0048);
    IAppCard->writeRegister(0x000F,0x0016);
	IAppCard->writeRegister(0x0007,0x0034);
	IAppCard->writeRegister(0x0020,0x0036);

	DACVoltage=true;

	nullify=0.0;

}
void DMMJig::receiveValue(unsigned int pValue){
	if(m_nLineEditIndex==1){
		objAddress->setText(QString::number(pValue,16));
		m_nAddress=pValue;
	}
	else if(m_nLineEditIndex==2){
		objData->setText(QString::number(pValue,16));
		m_nData=pValue;
	}
}
void DMMJig::receiveValue(double pValue){

	if(m_nLineEditIndex==3){
		objForceCurrent->setText(QString::number(pValue,'f',6));
		m_nForceCurrent=pValue;
	}
	else if(m_nLineEditIndex==4){
		objAvgSamples->setText(QString::number(pValue,'f',6));
	}
	else if(m_nLineEditIndex==5){
		objDACVoltage->setText(QString::number(pValue,'f',6));
		m_nDACFVoltage=pValue;

		qDebug()<< "Update DAC"<<m_eSelect;
			    AD5318_dataTemplate l_nAD5318DW;
			    m_eSelect = DACF;
			    l_nAD5318DW.m_eDACSelect = m_eSelect;
			    l_nAD5318DW.m_bCtrlBit = 0;
			    l_nAD5318DW.m_nVout = m_nDACFVoltage;
			    l_nAD5318DW.m_nVRef = 2.5;
			    l_nAD5318DW.m_bUniPolor = true;
		    	l_nAD5318DW.m_bUniPolor = false;
			    m_objAD5318Component->configureADC5318Data(l_nAD5318DW);
	}
}
void DMMJig::receiveValue(QString pValue){
	Q_UNUSED(pValue)
}
void DMMJig::callAddressEdit() {
	if (objAddress->hasFocus()) {
		openNumKBPanel(0);
		m_nLineEditIndex = 1;
	}
}

void DMMJig::callDataEdit() {
	if (objData->hasFocus()) {
		openNumKBPanel(0);
		m_nLineEditIndex = 2;
	}

}
void DMMJig::callForceCurrentEdit() {
	if (objForceCurrent->hasFocus()) {
		openNumKBPanel(1);
		m_nLineEditIndex = 3;
	}

}
void DMMJig::callDACVoltage() {
	if (objDACVoltage->hasFocus()) {
		openNumKBPanel(1);
		m_nLineEditIndex = 5;
	}

}
void DMMJig::callSamplesEdit() {
	if (objAvgSamples->hasFocus()) {
		openNumKBPanel(1);
		m_nLineEditIndex = 4;
	}
}
void DMMJig::openNumKBPanel(short int pValue) {

	QWidget *w = INumberPanel->getNumKBPanel(pValue, this);
	w->setWindowFlags(Qt::WindowCloseButtonHint | Qt::Dialog);
	w->show();
}

DMMJig::~DMMJig()
{
	qDebug()<<"DMM Destroyed";
    delete ui;
}

void DMMJig::changeEvent(QEvent *e)
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
//Q_EXPORT_PLUGIN2(IDMMTestJigInterface,DMMJig);


void DMMJig::on_radioButton_clicked(bool checked)
{

}

void DMMJig::on_radioButton_2_clicked(bool checked)
{
	if(checked)IPsoc->shLocatorDetection();
}

void DMMJig::on_pushButton_clicked()
{
    bool ok;

    double y,m,x,c;

    x=m_nForceCurrent;

    m=m_nRangeSlope[ui->cmbDrvVoltage->currentIndex()];
    c=m_nRangeConstant[ui->cmbDrvVoltage->currentIndex()];
  	y=(x-c)/m;
  	qDebug()<<"y=(x-c)/m =(("<<x<<")-("<<c<<"))/("<<m<<")="<<y;

  	switch(ui->cmbDrvVoltage->currentIndex()){

    case 0:
       	m_nDACVoltage=y*200;
        IAppCard->writeRegister(0x000F,0x0016);
        break;
    case 1:
       	m_nDACVoltage=y*20000;
    	IAppCard->writeRegister(0x000D,0x0016);
        break;
    case 2:
       	m_nDACVoltage=y*2000000;
    	IAppCard->writeRegister(0x000B,0x0016);
        break;
   	}

  	m_eSelect = DACG;
    l_nAD5318DW.m_eDACSelect = m_eSelect;
    l_nAD5318DW.m_bCtrlBit = 0;
    l_nAD5318DW.m_nVout = m_nDACVoltage;
    l_nAD5318DW.m_nVRef = 2.5;
    l_nAD5318DW.m_bUniPolor = false;

    m_objAD5318Component->configureADC5318Data(l_nAD5318DW);


    IAppCard->writeRegister(0x0001,PT_APPCARD_MODULES::PT_DRIVE_APPCARD_DCR);

    if(timer->isActive()){ timer->stop();
    timer->start(100);}else timer->start(100);
}
void DMMJig::LoopDrive(){
	readADC();
}
void DMMJig::readADC()
{
	bool ok;
	short int l_nResoulution = 23;
	double l_nGain = 1, l_nVREF = 2.048;
	double l_nFactor1 = 0.0, l_nFactor2 = 0.0, l_nAIN = 0.0;

		m_nADC1Voltage=m_objAD7190Component->readADCDataRegister(1) & 0xFFFFFF;
		qDebug()<<"Hex ADC1 Code:"<<hex<<m_nADC1Voltage;

		l_nFactor1 = (m_nADC1Voltage / pow(2, l_nResoulution)) - 1;
		l_nFactor2 = (l_nGain / l_nVREF);
		l_nAIN = (l_nFactor1 / l_nFactor2)-nullify;
		if(ui->radioButton_6->isChecked())
		{
			l_nFactor1 = (m_nADC1Voltage * l_nVREF) / (pow(2, l_nResoulution)) * l_nGain;
			l_nAIN=l_nFactor1;
		}
		qDebug()<<"Converted ADC1 Code:"<<l_nAIN;
		ui->edAddress_3->setText(QString::number((l_nAIN),'f',6));
		ui->edAddress_5->setText(QString::number(((l_nAIN)/(objForceCurrent->text().toDouble(&ok))),'f',6));
}
void DMMJig::readCurrentCalibrationFile(){

    QFile *xmlFile= new QFile("CurrentCalibration.xml");
            if (!xmlFile->open(QIODevice::ReadOnly | QIODevice::Text)) {
                 qDebug()<<"calibration file read error";
            }

            QXmlStreamReader xml(xmlFile);
            short int index=0;
            while(!xml.atEnd() &&  !xml.hasError())
            {
                QXmlStreamReader::TokenType token = xml.readNext();
                QString l_strName = xml.name().toString();
                QXmlStreamAttributes attributes = xml.attributes();
                QString l_strValue = attributes.value("Value").toString();
                if(token == QXmlStreamReader::StartDocument)
                {
                    continue;
                }
                if(xml.isStartElement())
                {
                                   if(xml.name() == "CurrentRange") {
                                            m_nRangeSlope[index]=xml.attributes().value("Slope").toString().toDouble();
                                            m_nRangeConstant[index]=xml.attributes().value("Constant").toString().toDouble();
                                            index++;
                                        }
                }
            }
    if(xml.hasError())
            qDebug()<<"xmlFile.xml Parse Error";

    //close reader and flush file
    xml.clear();
    xmlFile->close();

    for(int i=0;i<index;i++){
        qDebug()<<"Gain :"<<m_nRangeSlope[i];
        qDebug()<<"Constant"<<m_nRangeConstant[i];
    }

}
void DMMJig::on_pushButton_2_clicked()
{
	timer->stop();
}

void DMMJig::on_cmbDrvVoltage_currentIndexChanged(int index)
{
	Q_UNUSED(index)
}

void DMMJig::on_cmbImpedance_currentIndexChanged(int index)
{
	Q_UNUSED(index)
}

void DMMJig::on_cmbImpedance_2_currentIndexChanged(int index)
{
	Q_UNUSED(index)
}

void DMMJig::on_cmbImpedance_3_currentIndexChanged(int index)
{
	Q_UNUSED(index)
}

void DMMJig::on_radioButton_3_clicked(bool checked)
{
	Q_UNUSED(checked)
}

void DMMJig::on_radioButton_5_clicked(bool checked)
{
	Q_UNUSED(checked)
}

void DMMJig::on_radioButton_4_clicked(bool checked)
{
	Q_UNUSED(checked)
}

void DMMJig::on_radioButton_6_clicked(bool checked)
{
	Q_UNUSED(checked)
}

void DMMJig::on_butRead_clicked()
{
	objData->setText(QString::number(
	                            IAppCard->readRegister(m_nAddress), 16));
}

void DMMJig::on_butWrite_clicked()
{
	IAppCard->writeRegister(m_nData,m_nAddress);
}

void DMMJig::on_cmbOffset_currentIndexChanged(int index)
{
	Q_UNUSED(index)
}

void DMMJig::on_checkBox_2_clicked(bool checked)
{
	   AD5318_dataTemplate l_nAD5318DW;
		    m_eSelect = DACF;
		    l_nAD5318DW.m_eDACSelect = m_eSelect;
		    l_nAD5318DW.m_bCtrlBit = 0;
		    l_nAD5318DW.m_nVRef = 2.5;
		    l_nAD5318DW.m_bUniPolor = true;
	    	l_nAD5318DW.m_bUniPolor = false;

	if(checked)    {
		bool ok;

		m_nDACFVoltage2= ((ui->edAddress_3->text().toDouble(&ok))*-1);
		qDebug()<<"DAC F Voltage 1"<<m_nDACFVoltage2;
		l_nAD5318DW.m_nVout=m_nDACFVoltage2;
	    m_objAD5318Component->configureADC5318Data(l_nAD5318DW);

	}
	else{
		l_nAD5318DW.m_nVout=0.0;
	    m_objAD5318Component->configureADC5318Data(l_nAD5318DW);
	}

}

void DMMJig::on_checkBox_3_clicked(bool checked)
{
	bool ok;
	if(checked){
		nullify=ui->edAddress_3->text().toDouble(&ok);
	}else
		nullify=0.0;
}
