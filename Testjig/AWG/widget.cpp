#include "widget.h"
#include "ui_widget.h"
#include <QClipboard>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPixmap>
#include <QBrush>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QPluginLoader loader4("libQmaxPTInterface.so",this);
    ILineEdit = qobject_cast<IQmaxLineEdit*>(loader4.instance());
    INumberPanel=qobject_cast<IQmaxNumberPanel*>(loader4.instance());

    QPluginLoader loader5("libWaveformTestjigInterface.so",this);
    objWaveProduct = qobject_cast<IQmaxWaveProduct*>(loader5.instance());

    objWaveProduct->ICreateWaveProduct("Oscillator",this->ui->grpWaveWindow);
    objWaveProduct->IsetDimensions(0,10,470,235);


    Initialization();
    qDebug()<< "AWG Loaded";





}
void Widget::GenerateWaveform(){

	l_objReceive1Data=showAWGTrace(1);

	qDebug()<<"n_duration:"<<n_duration<<"n_samples:"<<n_samples<<"n_cycles:"<<n_cycles
			<<"n_offset:"<<n_offset<<"n_frequency:"<<n_frequency;

	double l_nBTU = (9 + 1.0) * 10.0;
	double l_nBD = n_duration;
	double l_nTotalTime = ((n_samples) * (l_nBTU * l_nBD)) * 1.0/ 1000000000.0;
	l_objReceive1Data->m_nTimeperSample = 1.0 / (n_samples/ 1);
	l_objReceive1Data->m_nCycles = n_cycles;
	double m_nTime = 100 * l_objReceive1Data->m_nTimeperSample;
	l_objReceive1Data->m_nFrequency = n_frequency;//1 / m_nTime;
	l_objReceive1Data->m_nSamples = 100;
	l_objReceive1Data->m_nScreenTime = m_nTime;
	l_objReceive1Data->m_nXunits = 10.0;
	l_objReceive1Data->m_nYunits = 8.0;
	l_objReceive1Data->m_nMinX = 0.0;
	l_objReceive1Data->m_nOffset = n_offset;
	l_objReceive1Data->m_nSteps = 1.0;
	l_objReceive1Data->m_nAmplitude=0.9/0.6;
	l_objReceive1Data->m_nDutyCycles = (50 / 100.0);

    objWaveProduct->ILoadPlotterData("./25.txt",l_objReceive1Data);
    objWaveProduct->IWaveSettings();
    objWaveProduct->IGenerateOscillatorPattern(m_strSelectWaveForm,0);

}
stWaveData* Widget::showAWGTrace(int pWaveTrace)
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
//qDebug()<<"AWG Hardware Initialisation";
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

	ui->groupBox->setParent(m_objWidget);
	ui->groupBox_2->setParent(m_objWidget);
	ui->groupBox_3->setParent(m_objWidget);
	ui->grpGeneral->setParent(m_objWidget);
	ui->grpSettings->setParent(m_objWidget);
	ui->grpWaveConfiguration->setParent(m_objWidget);
	ui->grpWaveWindow->setParent(m_objWidget);

	ui->grpGeneral->setGeometry(20,0,271,160);
	ui->groupBox->setGeometry(510,430,271,90);
	ui->groupBox_2->setGeometry(310,350,191,170);
	ui->grpSettings->setGeometry(310,0,471,101);
	ui->grpWaveConfiguration->setGeometry(20,164,271,356);
	ui->groupBox_3->setGeometry(510,360,271,77);
	ui->grpWaveWindow->setGeometry(310,100,471,250);

}
void Widget::Initialization(){
	ui->edAddress->setVisible(false);
	objAddress=ILineEdit->QmaxLineEdit(1, ui->grpGeneral);
	objAddress->setGeometry(90, 15, 120, 35);
	objAddress->setFont(QFont("DejaVu Sans",13,50,false));

	ui->edData->setVisible(false);
	objData=ILineEdit->QmaxLineEdit(2, ui->grpGeneral);
	objData->setGeometry(90, 60, 120, 35);
	objData->setFont(QFont("DejaVu Sans",13,50,false));


	ui->edOffset->setVisible(false);
	objOffset=ILineEdit->QmaxLineEdit(3,ui->grpWaveConfiguration);
	objOffset->setGeometry(100,62,120,35);
	objOffset->setFont(QFont("DejaVu Sans",13,50,false));

	ui->edFrequency->setVisible(false);
	objFrequency=ILineEdit->QmaxLineEdit(4,ui->grpWaveConfiguration);
	objFrequency->setGeometry(100,112,120,35);
	objFrequency->setFont(QFont("DejaVu Sans",13,50,false));

	ui->edFrequency_2->setVisible(false);
	objTime=ILineEdit->QmaxLineEdit(5,ui->grpWaveConfiguration);
	objTime->setGeometry(100,162,120,35);
	objTime->setFont(QFont("DejaVu Sans",13,50,false));


	ui->edFrequency_3->setVisible(false);
	objTimeBase=ILineEdit->QmaxLineEdit(6,ui->grpWaveConfiguration);
	objTimeBase->setGeometry(100,212,120,35);
	objTimeBase->setFont(QFont("DejaVu Sans",13,50,false));

	ui->edFrequency_4->setVisible(false);
	objDuration=ILineEdit->QmaxLineEdit(7,ui->grpWaveConfiguration);
	objDuration->setGeometry(100,262,120,35);
	objDuration->setFont(QFont("DejaVu Sans",13,50,false));

	ui->edFrequency_5->setVisible(false);
	objSamples=ILineEdit->QmaxLineEdit(8,ui->grpWaveConfiguration);
	objSamples->setGeometry(100,312,120,35);
	objSamples->setFont(QFont("DejaVu Sans",13,50,false));

	objData->setStyleSheet(		"border-width: 2px;border-style: outset;border-color: gray; border-radius: 10px;  padding: 0 8px;     background: black;     selection-background-color: yellow;   color:white;     font: bold 14px;"    );
	objAddress->setStyleSheet(	"border-width: 2px;border-style: outset;border-color: gray; border-radius: 10px;  padding: 0 8px;     background: black;     selection-background-color: yellow;   color:white;     font: bold 14px;"    );
	objOffset->setStyleSheet(	"border-width: 2px;border-style: outset;border-color: gray; 					    padding: 0 8px;     background: black;     selection-background-color: yellow;   color:white;     font: bold 14px;"    );
	objFrequency->setStyleSheet("border-width: 2px;border-style: outset;border-color: gray; 						padding: 0 8px;     background: black;     selection-background-color: yellow;   color:white;     font: bold 14px;"    );
	objTime->setStyleSheet(		"border-width: 2px;border-style: outset;border-color: gray; 						padding: 0 8px;     background: black;     selection-background-color: yellow;   color:white;     font: bold 14px;"    );
	objTimeBase->setStyleSheet(		"border-width: 2px;border-style: outset;border-color: gray; 						padding: 0 8px;     background: black;     selection-background-color: yellow;   color:white;     font: bold 14px;"    );
	objDuration->setStyleSheet(	"border-width: 2px;border-style: outset;border-color: gray;						padding: 0 8px;     background: black;     selection-background-color: yellow;   color:white;     font: bold 14px;"    );
	objSamples->setStyleSheet(	"border-width: 2px;border-style: outset;border-color: gray;						padding: 0 8px;     background: black;     selection-background-color: yellow;   color:white;     font: bold 14px;"    );


	connect(objAddress,   SIGNAL(focussed(bool)), this, SLOT(callAddressEdit()));
	connect(objData,      SIGNAL(focussed(bool)), this, SLOT(callDataEdit()));
	connect(objOffset,    SIGNAL(focussed(bool)), this, SLOT(callOffsetEdit()));
	connect(objFrequency, SIGNAL(focussed(bool)), this, SLOT(callFrequencyEdit()));
	connect(objTime,      SIGNAL(focussed(bool)), this, SLOT(callTimeEdit()));
	connect(objTimeBase,  SIGNAL(focussed(bool)), this, SLOT(callTimeBaseEdit()));
	connect(objDuration,  SIGNAL(focussed(bool)), this, SLOT(callDurationEdit()));
	connect(objSamples,   SIGNAL(focussed(bool)), this, SLOT(callSamplesEdit()));

	enableRichGUI();

	//waveform initialization

    m_strSelectWaveForm="SINE";
	ui->cmbDriveMode->setCurrentIndex(0);

	n_offset=0.0;
	objOffset->setText(QString::number(n_offset));

	n_frequency=1 /(100 * (1.0 / (100/ 1)));
	objFrequency->setText(QString::number(n_frequency));

	n_duration=(1 + 1.0);
	objDuration->setText(QString::number(n_duration));

	n_samples=100;
	objSamples->setText(QString::number(n_samples));

	n_cycles=1;

	GenerateWaveform();
}
void Widget::receiveValue(unsigned int pValue){
	if(m_nLineEditIndex==1){
		objAddress->setText(QString::number(pValue,16));
	}
	else if(m_nLineEditIndex==2){
		objData->setText(QString::number(pValue,16));
	}
}
void Widget::receiveValue(double pValue){
	if(m_nLineEditIndex==3){
		objOffset->setText(QString::number(pValue,'f',5));
		n_offset=pValue;
	}
	else if(m_nLineEditIndex==4){
		objFrequency->setText(QString::number(pValue,'f',5));
		n_frequency=pValue;
	}
	else if(m_nLineEditIndex==5){
		objTime->setText(QString::number(pValue,'f',5));
		n_time=pValue;
	}
	else if(m_nLineEditIndex==6){
		objTimeBase->setText(QString::number(pValue,'f',5));
		n_timeBase=pValue;
	}
	else if(m_nLineEditIndex==7){
		objDuration->setText(QString::number(pValue,'f',5));
		n_duration=pValue;
	}
	else if(m_nLineEditIndex==8){
		objSamples->setText(QString::number(pValue,'f',5));
		n_samples=pValue;
	}
	GenerateWaveform();
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

void Widget::callOffsetEdit(){
	if (objOffset->hasFocus()) {
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

void Widget::callTimeEdit(){
	if (objTime->hasFocus()) {
		openNumKBPanel(1);
		m_nLineEditIndex = 5;
	}
}
void Widget::callTimeBaseEdit(){
	if (objTimeBase->hasFocus()) {
		openNumKBPanel(1);
		m_nLineEditIndex = 6;
	}
}

void Widget::callDurationEdit(){
	if (objDuration->hasFocus()) {
		openNumKBPanel(1);
		m_nLineEditIndex = 7;
	}
}

void Widget::callSamplesEdit(){
	if (objSamples->hasFocus()) {
		openNumKBPanel(1);
		m_nLineEditIndex = 8;
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
	qDebug()<<"AWG Destroyed";
    delete ui;
}

void Widget::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type())
    {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

//Q_EXPORT_PLUGIN2(IAWGTestJigInterface,IWidget);

void Widget::on_cmbPatterns_currentIndexChanged(QString waveType )
{
    m_strSelectWaveForm=waveType;
    GenerateWaveform();
}

void Widget::on_cmbDriveMode_currentIndexChanged(int index)
{
	if(index==0){
		n_cycles=1;
	}
	else if(index==1){
		n_cycles=5;
	}
	GenerateWaveform();
}
void Widget::on_pushButton_clicked()
{
	GenerateWaveform();
}

void Widget::on_cmbDrvVoltage_currentIndexChanged(int index)
{

}

void Widget::on_cmbImpedance_currentIndexChanged(int index)
{

}
