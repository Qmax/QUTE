#include "vijig.h"
#include "ui_vijig.h"
#include <QClipboard>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QBrush>

VIJig::VIJig(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VIJig)
{
    ui->setupUi(this);
//    QPixmap Pix = QPixmap();
//    Pix = QPixmap::grabWidget(this,0,0,800,600);
//    Pix.save("VIJig.jpg");
//    QClipboard *board = QApplication::clipboard();
//    board->setPixmap(Pix);
    QPluginLoader loader4("libQmaxPTInterface.so",this);
    ILineEdit = qobject_cast<IQmaxLineEdit*>(loader4.instance());
    INumberPanel=qobject_cast<IQmaxNumberPanel*>(loader4.instance());


    Initialization();

    qDebug()<< "VI Loaded";
    QPluginLoader loader5("libWaveformTestjigInterface.so",this);
    objWaveProduct = qobject_cast<IQmaxWaveProduct*>(loader5.instance());

    objWaveProduct->ICreateWaveProduct("Oscillator",this->ui->grpWaveWindow);
    objWaveProduct->IsetDimensions(0,10,360,350);

    GenerateWaveform();
}

void VIJig::GenerateWaveform(){
    l_objReceive1Data=showVITrace(1);

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
stWaveData* VIJig::showVITrace(int pWaveTrace)
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

//void VIJig::HardwareInitializtaion(){
//	qDebug()<<"VI Hardware Initialisation";
//}
void VIJig::enableRichGUI(){
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
	ui->grpGeneral->setParent(m_objWidget);
	ui->grpSettings->setParent(m_objWidget);
	ui->grpWaveConfiguration->setParent(m_objWidget);
	ui->grpWaveWindow->setParent(m_objWidget);

	ui->groupBox->            setGeometry(680,170,101,350);
	ui->grpGeneral->          setGeometry(20,0,271,171);
	ui->grpSettings->         setGeometry(310,0,471,150);
	ui->grpWaveConfiguration->setGeometry(20,190,271,330);
	ui->grpWaveWindow->       setGeometry(310,160,361,360);

}
void VIJig::Initialization(){
	ui->edAddress->setVisible(false);
	objAddress=ILineEdit->QmaxLineEdit(1, ui->grpGeneral);
	objAddress->setGeometry(90, 15, 120, 35);
	objAddress->setStyleSheet("border-width: 2px;border-style: outset;border-color: gray; border-radius: 10px;  padding: 0 8px;     background: black;     selection-background-color: yellow;   color:white;     font: bold 14px;"    );

	ui->edData->setVisible(false);
	objData=ILineEdit->QmaxLineEdit(2, ui->grpGeneral);
	objData->setGeometry(90, 60, 120, 35);
	objData->setStyleSheet("border-width: 2px;border-style: outset;border-color: gray; border-radius: 10px;  padding: 0 8px;     background: black;     selection-background-color: yellow;   color:white;     font: bold 14px;"    );

	ui->edOffset->setVisible(false);
	objOffset=ILineEdit->QmaxLineEdit(3,ui->grpWaveConfiguration);
	objOffset->setGeometry(120,160,120,35);

	ui->edFrequency->setVisible(false);
	objFrequency=ILineEdit->QmaxLineEdit(4,ui->grpWaveConfiguration);
	objFrequency->setGeometry(120,230,120,35);

	connect(objAddress,  SIGNAL(focussed(bool)), this, SLOT(callAddressEdit()));
	connect(objData,     SIGNAL(focussed(bool)), this, SLOT(callDataEdit()));
	connect(objOffset,   SIGNAL(focussed(bool)), this, SLOT(callOffsetEdit()));
	connect(objFrequency,SIGNAL(focussed(bool)), this, SLOT(callFrequencyEdit()));

	objData->setStyleSheet(		"border-width: 2px;border-style: outset;border-color: gray; border-radius: 10px;  padding: 0 8px;     background: black;     selection-background-color: yellow;   color:white;     font: bold 14px;"    );
	objAddress->setStyleSheet(	"border-width: 2px;border-style: outset;border-color: gray; border-radius: 10px;  padding: 0 8px;     background: black;     selection-background-color: yellow;   color:white;     font: bold 14px;"    );
	objOffset->setStyleSheet(	"border-width: 2px;border-style: outset;border-color: gray; 					    padding: 0 8px;     background: black;     selection-background-color: yellow;   color:white;     font: bold 14px;"    );
	objFrequency->setStyleSheet("border-width: 2px;border-style: outset;border-color: gray; 						padding: 0 8px;     background: black;     selection-background-color: yellow;   color:white;     font: bold 14px;"    );

	enableRichGUI();
}
void VIJig::receiveValue(unsigned int pValue){
	if(m_nLineEditIndex==1){
		objAddress->setText(QString::number(pValue,16));
	}
	else if(m_nLineEditIndex==2){
		objData->setText(QString::number(pValue,16));
	}
}
void VIJig::receiveValue(double pValue){
	if(m_nLineEditIndex==3){
		objOffset->setText(QString::number(pValue,'f',5));
	}
	else if(m_nLineEditIndex==4){
		objFrequency->setText(QString::number(pValue,'f',5));
	}
}
void VIJig::receiveValue(QString pValue){
	Q_UNUSED(pValue)
}
void VIJig::callAddressEdit() {
	if (objAddress->hasFocus()) {
		openNumKBPanel(0);
		m_nLineEditIndex = 1;
	}
}

void VIJig::callDataEdit() {
	if (objData->hasFocus()) {
		openNumKBPanel(0);
		m_nLineEditIndex = 2;
	}

}

void VIJig::callOffsetEdit(){
	if (objOffset->hasFocus()) {
		openNumKBPanel(1, 1, 'v', 20, -20,this);
		m_nLineEditIndex = 3;
	}
}

void VIJig::callFrequencyEdit(){
	if (objFrequency->hasFocus()) {
		openNumKBPanel(1, 1, 'F', 2000000, 0.01,this);
		m_nLineEditIndex = 3;
	}
}

void VIJig::openNumKBPanel(short int pValue) {

	QWidget *w = INumberPanel->getNumKBPanel(pValue, this);
	w->setWindowFlags(Qt::WindowCloseButtonHint | Qt::Dialog);
	w->show();
}
void VIJig::openNumKBPanel(short int pValue,double incRatio,char type,double max,double min,QWidget* parent) {

	QWidget *w = INumberPanel->getNumKBPanelIncDec(pValue,incRatio,type,max,min,parent);
	w->setWindowFlags(Qt::WindowCloseButtonHint | Qt::Dialog);
	w->show();
}
VIJig::~VIJig()
{
	qDebug()<<"VI Destroyed";
    delete ui;
}

void VIJig::changeEvent(QEvent *e)
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
//Q_EXPORT_PLUGIN2(IVITestJigInterface,VIJig);
