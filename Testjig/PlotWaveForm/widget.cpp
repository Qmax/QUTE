#include "widget.h"
#include "ui_widget.h"
#include <QPluginLoader>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    initialiseLibraries();
    waveData();
    qDebug()<<"line:12";
    m_objstAddr = ILineEdit->QmaxLineEdit(1,ui->grpAddress);
    m_objstAddr->setGeometry(110,15,100,40);
    m_objstAddr->setFont(QFont("DejaVu Sans",13,50,false));

    m_objAddrCount = ILineEdit->QmaxLineEdit(2,ui->grpAddress);
    m_objAddrCount->setGeometry(110,65,100,40);
    m_objAddrCount->setFont(QFont("DejaVu Sans",13,50,false));

    m_objReceStAddr = ILineEdit->QmaxLineEdit(3,ui->grpAddress);
	m_objReceStAddr->setGeometry(330,15,100,40);
	m_objReceStAddr->setFont(QFont("DejaVu Sans",13,50,false));

    m_objReceAddrCount = ILineEdit->QmaxLineEdit(4,ui->grpAddress);
    m_objReceAddrCount->setGeometry(330,65,100,40);
    m_objReceAddrCount->setFont(QFont("DejaVu Sans",13,50,false));

    m_objstRece1Count=ILineEdit->QmaxLineEdit(5,ui->grpReceiverDSO);
    m_objstRece1Count->setGeometry(ui->leR1Count->geometry());
    m_objstRece1Count->setStyleSheet(ui->leR1Count->styleSheet());
    connect(m_objstRece1Count,SIGNAL(focussed(bool)), this, SLOT(callR1Count()));


//    m_objstRece1Addr = ILineEdit->QmaxLineEdit(5,ui->grpReceiverDSO);
//    m_objstRece2Addr->setGeometry(10,110,100,40);
//    m_objstRece2Addr->setFont(QFont("DejaVu Sans",13,50,false));

    qDebug()<<"line:34";

    connect(m_objstAddr,   SIGNAL(focussed(bool)), this, SLOT(callstAddressEdit()));
    connect(m_objAddrCount,SIGNAL(focussed(bool)), this, SLOT(callAddrCoutEdit()));
    connect(m_objReceStAddr,   SIGNAL(focussed(bool)), this, SLOT(callstReceAddressEdit()));
    connect(m_objReceAddrCount,SIGNAL(focussed(bool)), this, SLOT(callReceAddrCoutEdit()));

    qDebug()<<"line:41";

    enableRichGUI();

    qDebug()<<"line:45";
}
void Widget::enableRichGUI() {
	QWidget *m_objWidget = new QWidget(this);
	QGraphicsScene *entireScene = new QGraphicsScene(0, 0, 600, 600);
	QGraphicsView *entireView = new QGraphicsView(m_objWidget);
	QPixmap obj1 = QPixmap(":/bg.png");
	QBrush obj2 = QBrush(obj1);
	obj2.setStyle(Qt::TexturePattern);
	obj2.setTexture(obj1);
	entireView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	entireView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	entireView->setFrameStyle(QFrame::Plain | QFrame::Sunken);
	entireView->setBackgroundBrush(obj2);
	entireView->setScene(entireScene);
	entireView->setGeometry(0, 0, 800, 600);


	PlotProduct->setParent(m_objWidget);
	PlotProduct1->setParent(m_objWidget);
    PlotProduct->setDimensions(10, 10, 600, 200);
    PlotProduct1->setDimensions(10, 210, 600, 200);


	ui->grpRAM->setParent(m_objWidget);
	ui->grpAddress->setParent(m_objWidget);
	ui->grpReceiverDSO->setParent(m_objWidget);
	ui->grpReceiverDSO->setGeometry(612, 6, 170, 400);

	ui->grpRAM->setGeometry(10, 410, 131, 110);
    ui->grpAddress->setGeometry(150, 410, 631, 110);

	m_objAddrCount->setStyleSheet(
			"border-width: 2px;border-style: outset;border-color: gray; border-radius: 10px;  padding: 0 8px;     background: black;     selection-background-color: yellow;   color:white;     font: bold 14px;");
	m_objReceAddrCount->setStyleSheet(
			"border-width: 2px;border-style: outset;border-color: gray; border-radius: 10px;  padding: 0 8px;     background: black;     selection-background-color: yellow;   color:white;     font: bold 14px;");
	m_objReceStAddr->setStyleSheet(
			"border-width: 2px;border-style: outset;border-color: gray; border-radius: 10px;  padding: 0 8px;     background: black;     selection-background-color: yellow;   color:white;     font: bold 14px;");
	m_objstAddr->setStyleSheet(
			"border-width: 2px;border-style: outset;border-color: gray; border-radius: 10px;  padding: 0 8px;     background: black;     selection-background-color: yellow;   color:white;     font: bold 14px;");
}
void Widget::waveData()
{
	   m_objWaveFactory = new WaveFormFactory();
	    PlotProduct = m_objWaveFactory->getWaveProduct("OscillaScope", this);
	    PlotProduct1 = m_objWaveFactory->getWaveProduct("OscillaScope", this);
	    PlotProduct->setDimensions(10, 10, 700, 200);
	    PlotProduct1->setDimensions(10, 210, 700, 200);
	    objVIWaveData = new stWaveData();
	    objReceData = new stWaveData();
	    m_nAdressCount = m_nReceAddrCount=0;
	    m_nStartAddress=m_nReceStartAddress=0;
	    m_nLineEditIndex=0;

}

void Widget::initialiseLibraries()
{
    QPluginLoader loader4("libQmaxPTInterface.so",this);
    ILineEdit = qobject_cast<IQmaxLineEdit*>(loader4.instance());
    INumberPanel=qobject_cast<IQmaxNumberPanel*>(loader4.instance());


    QPluginLoader loader2("libSPIMemoryInterface.so", this);
    ISPIMemory = qobject_cast<ISPIMemoryInterface*> (loader2.instance());

    QPluginLoader loaderApp("libPTApplicationcardInterface.so",this);
    IAppCard = qobject_cast<IApplicationCardInterface*>(loaderApp.instance());
    qDebug() << "Appcard" <<IAppCard;
    IAppCard->setDeviceName(SLOT0);
    qDebug()<<"PlotWaveForm:widget.cpp->Line:65";		IAppCard->enumerateAPPCard();
    qDebug()<<"PlotWaveForm:widget.cpp->Line:66";		ISPIMemory->accessSPIMemory(APPLICATIONCARD);
    qDebug()<<"PlotWaveForm:widget.cpp->Line:67";		ISPIMemory->setHardwarwObject(IAppCard);


}

Widget::~Widget()
{
    delete ui;
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

void Widget::callstAddressEdit()
{
    if (m_objstAddr->hasFocus()) {
            openNumKBPanel(0);
            m_nLineEditIndex = 1;
    }
}
void Widget::callR1Count()
{
	 if (m_objstRece1Count->hasFocus())
	    {
	            openNumKBPanel(2);
	            m_nLineEditIndex = 5;
	    }
}
void Widget::callAddrCoutEdit()
{
    if (m_objAddrCount->hasFocus())
    {
            openNumKBPanel(2);
            m_nLineEditIndex = 2;
    }
}

void Widget::callstReceAddressEdit()
{
    if (m_objReceStAddr->hasFocus()) {
            openNumKBPanel(0);
            m_nLineEditIndex = 3;
    }
}
void Widget::callReceAddrCoutEdit()
{
    if (m_objReceAddrCount->hasFocus())
    {
            openNumKBPanel(2);
            m_nLineEditIndex = 4;
    }
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

void Widget::on_butReceive_clicked()
{
	if(ui->chkDriveRAM_2->isChecked() == false)
	{
		return;
	}
	if(m_nReceAddrCount <= 0)
	    {
	        qDebug() << "Address Count is invalid";
	        return;
	    }
	    m_nRECELocations = new unsigned short int[m_nReceStartAddress+m_nReceAddrCount];
	    if(ui->chkDriveRAM_2->isChecked())
	    {
	    	ISPIMemory->accessSPIRAM(RECEIVERAM);
	    }
	    ISPIMemory->setAutoIncrement();
	    m_nRECELocations = ISPIMemory->readAppCardSRAM(m_nReceStartAddress,m_nReceStartAddress+m_nReceAddrCount);
	    objReceData->m_nAmplitude = 1.0;
	    objReceData->m_nFrequency = 1.0;
	    objReceData->m_nSteps= 1;
	    objReceData->m_nScreenAmplitude =  2.0;
	    objReceData->m_nScreenTime = 1.0; // Max Time
	    objReceData->m_nXunits = 10.0;
	    objReceData->m_nYunits = 8.0;
	    objReceData->m_nMinX =0; // Min Voltage
	    objReceData->m_nMinY =-2.0; // Min Current
	    objReceData->m_nPhase =0.0;
	    objReceData->m_nOffset =0.0;
	    objReceData->m_nDutyCycles =0;
	    objReceData->m_nCycles = 1.0;
	    objReceData->m_nPreamble =0;
	    objReceData->m_nPostamble=0;
	    objReceData->m_bUniPolar = false;
	    objReceData->m_nSteps =0.0;
	    objReceData->m_nVRef =1.0;
	    objReceData->m_bCalibChecked = false;
	    objReceData->m_nCalibrationConstant =0.0;
	    objReceData->m_nCalibrationGain=0.0;
	    objReceData->m_nResolution =14;
	    objReceData->m_nEnvelopBand=0.0;
	    qDebug()<< "Total Count:"<<m_nReceStartAddress+m_nReceAddrCount;
	    objReceData->m_nSamples = m_nReceStartAddress+m_nReceAddrCount;
		objReceData->m_nTimeperSample = 1.0/(objReceData->m_nSamples);
		qDebug()<< "Time Per Sample:"<<objReceData->m_nTimeperSample<<objReceData->m_nSamples;
		writeWaveData(1);
		PlotProduct1->LoadPlotterData("RWaveData.txt",objReceData);
		PlotProduct1->WaveSettings();
		PlotProduct1->GeneratePlotterPoints(1);
}

void Widget::on_butDSOReceive_clicked()
{
	FILE *l_nFD;
	 l_nFD = fopen("./R1FIFO.txt","w");
	  if(l_nFD == 0)
		  printf("File I/O error\n");
	unsigned short int l_nOddSample=0;
	unsigned short int l_nEvenSample=0;
	qDebug()<<"Sample Count:"<<m_nR1Samples;
	for(int l_nAddrIndex=0;l_nAddrIndex<(m_nR1Samples);l_nAddrIndex++)
	{
		l_nOddSample= IAppCard->getDSOReceiveFIFOODD_RD(R1FIFO)&0x00FF;
		l_nEvenSample = IAppCard->getDSOReceiveFIFOEVEN_RD(R1FIFO)&0x00FF;
	    fprintf(l_nFD,"%X\n",l_nOddSample);
	    fprintf(l_nFD,"%X\n",l_nEvenSample);
	    qDebug()<<"Odd Sample:"<<l_nOddSample;
	    qDebug()<<"Even Sample:"<<l_nEvenSample;
	}
	fclose(l_nFD);
    objReceData->m_nAmplitude = 1.0;
    objReceData->m_nFrequency = 1.0;
    objReceData->m_nSteps= 1;
    objReceData->m_nScreenAmplitude =  0.7;
    objReceData->m_nScreenTime = 1.0; // Max Time
    objReceData->m_nXunits = 10.0;
    objReceData->m_nYunits = 8.0;
    objReceData->m_nMinX =0; // Min Voltage
    objReceData->m_nMinY =-0.7; // Min Current
    objReceData->m_nPhase =0.0;
    objReceData->m_nOffset =0.0;
    objReceData->m_nDutyCycles =0;
    objReceData->m_nCycles = 1.0;
    objReceData->m_nPreamble =0;
    objReceData->m_nPostamble=0;
    objReceData->m_bUniPolar = false;
    objReceData->m_nSteps =0.0;
    objReceData->m_nVRef =1.0;
    objReceData->m_bCalibChecked = false;
    objReceData->m_nCalibrationConstant =0.0;
    objReceData->m_nCalibrationGain=0.0;
    objReceData->m_nResolution =8;
    objReceData->m_nEnvelopBand=0.0;
    objReceData->m_nSamples = m_nR1Samples;
	objReceData->m_nTimeperSample = 1.0/(objReceData->m_nSamples);
	qDebug()<< "Time Per Sample:"<<objReceData->m_nTimeperSample<<objReceData->m_nSamples;
	//writeWaveData(1);
	PlotProduct1->LoadPlotterData("./R1FIFO.txt",objReceData);
	PlotProduct1->WaveSettings();
	PlotProduct1->GeneratePlotterPoints(1);
}

void Widget::on_pushButton_clicked()
{
	if(ui->chkDriveRAM->isChecked() == false)
	{
		return;
	}
    if(m_nAdressCount <= 0)
    {
        qDebug() << "Address Count is invalid";
        return;
    }
    m_nMEMLOCATIONS = new unsigned short int[m_nStartAddress+m_nAdressCount];
    if(ui->chkDriveRAM->isChecked())
    {
    	ISPIMemory->accessSPIRAM(DRIVERAM);
    }
//    if(ui->chkDriveRAM_2->isChecked())
//    {
//    	ISPIMemory->accessSPIRAM(RECEIVERAM);
//    }
    ISPIMemory->setAutoIncrement();
    m_nMEMLOCATIONS = ISPIMemory->readAppCardSRAM(m_nStartAddress,m_nStartAddress+m_nAdressCount);
    unsigned short int *m_nReadLocations = new unsigned short int[m_nStartAddress+m_nAdressCount];
    m_nReadLocations = ISPIMemory->readAppCardSRAM(m_nStartAddress,m_nStartAddress+m_nAdressCount);
    for(int l_nIndex=0;l_nIndex<m_nAdressCount;l_nIndex++)
    {
    	qDebug()<< "Data:"<<hex<<m_nReadLocations[l_nIndex];
    }
    objVIWaveData->m_nAmplitude = 1.0;
    objVIWaveData->m_nFrequency = 1.0;
    objVIWaveData->m_nScreenAmplitude =  2.0;
    objVIWaveData->m_nScreenTime = 1.0; // Max Time
    objVIWaveData->m_nXunits = 10.0;
    objVIWaveData->m_nYunits = 8.0;
    objVIWaveData->m_nMinX =0; // Min Voltage
    objVIWaveData->m_nMinY =-2.0; // Min Current
    objVIWaveData->m_nPhase =0.0;
    objVIWaveData->m_nOffset =0.0;
    objVIWaveData->m_nDutyCycles =0;
    objVIWaveData->m_nCycles = 1.0;
    objVIWaveData->m_nPreamble =0;
    objVIWaveData->m_nPostamble=0;
    objVIWaveData->m_bUniPolar = false;
    objVIWaveData->m_nSteps =1.0;
    objVIWaveData->m_nVRef =1.0;
    objVIWaveData->m_bCalibChecked = false;
    objVIWaveData->m_nCalibrationConstant =0.0;
    objVIWaveData->m_nCalibrationGain=0.0;
    objVIWaveData->m_nResolution =14;
    objVIWaveData->m_nEnvelopBand=0.0;
    qDebug()<< "Total Count:"<<m_nStartAddress+m_nAdressCount;
	objVIWaveData->m_nSamples = m_nStartAddress+m_nAdressCount;
	objVIWaveData->m_nTimeperSample = 1.0/(objVIWaveData->m_nSamples);
	qDebug()<< "Time Per Sampe:"<<objVIWaveData->m_nTimeperSample<<objVIWaveData->m_nSamples;
	//writeWaveData(0);
	PlotProduct->LoadPlotterData("DWaveData.txt",objVIWaveData);
	PlotProduct->WaveSettings();
	PlotProduct->GeneratePlotterPoints(0);
}

void Widget::writeWaveData(short int pFlag)
{
    FILE *fpWaveFile;
    //QFile *l_objDataFile = new QFile("./memvalue.txt");
    unsigned short l_nWaveCount=0;
    if(pFlag ==0){
    	fpWaveFile = fopen("./DWaveData.txt","w");
    	l_nWaveCount = (m_nAdressCount+m_nStartAddress);
    }
    if(pFlag==1)
    {
    	fpWaveFile = fopen("./RWaveData.txt","w");
    	l_nWaveCount = (m_nReceStartAddress+m_nReceAddrCount);
    }


//    if(l_objDataFile->open(QFile::WriteOnly))
//    {

    	for(int l_nIndex=0;l_nIndex<l_nWaveCount;l_nIndex++)
		{
    		//qDebug()<< "Data:"<<hex<<m_nMEMLOCATIONS[l_nIndex];
    		if(pFlag == 0)
    			fprintf(fpWaveFile,"%X\n",m_nMEMLOCATIONS[l_nIndex]);
    		if(pFlag==1)
    			fprintf(fpWaveFile,"%X\n",m_nRECELocations[l_nIndex]);

		}
//    }
    fclose(fpWaveFile);
}

void Widget::receiveValue(double pValue)
{
    Q_UNUSED(pValue)
}
void Widget::receiveValue(QString pValue)
{
        Q_UNUSED(pValue)
}


void Widget::receiveValue(unsigned int pValue)
{
    if(m_nLineEditIndex==1)
    {
            m_objstAddr->setText(QString::number(pValue,16));
            m_nStartAddress=pValue;
            if(m_nAdressCount >0){
                m_nEndAddress= m_nAdressCount + m_nStartAddress;
            }

    }
    else if(m_nLineEditIndex==2)
    {
            m_objAddrCount->setText(QString::number(pValue,10));
            m_nAdressCount = pValue;
    }
    if(m_nLineEditIndex==3)
    {
            m_objReceStAddr->setText(QString::number(pValue,16));
            m_nReceStartAddress=pValue;

    }
    else if(m_nLineEditIndex==4)
    {
            m_objReceAddrCount->setText(QString::number(pValue,10));
            m_nReceAddrCount = pValue;
    }
    else if(m_nLineEditIndex==5)
    {
            m_objstRece1Count->setText(QString::number(pValue,10));
            m_nR1Samples = pValue;
    }


}
