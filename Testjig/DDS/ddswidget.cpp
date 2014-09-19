#include "ddswidget.h"
#include "ui_ddswidget.h"
#include <qmessagebox.h>
#include <QGraphicsScene>
#include <QGraphicsView>

DDSWidget::DDSWidget(QWidget *parent) :
	QWidget(parent), ui(new Ui::DDSWidget) {
	ui->setupUi(this);
	initializeValues();
	loadQmaxPlugins();
	initialiseLineEditControls();
	enableRichGUI();
	loadSettings();
}
/*
 *
 */

void DDSWidget::customEvent(QEvent *e)
{
	QMessageBox msg;
	if(e->type() == ((QEvent::Type)7892))
	{
		qDebug()<<"Event Raised";
	}
	QEvent(e->type());
}

void DDSWidget::on_cmbVoltRanges_currentIndexChanged(int pIndex)
{
	  short int l_nAmpValue = pow(2, pIndex);
	    unsigned int l_nRegisterAddress = 0x48;
	    if (pIndex > 0)
	    {
	            l_nAmpValue = pow(2, pIndex - 1);
	            IAppCard->writeRegister(l_nAmpValue, l_nRegisterAddress);
	    }
	    else
	    {
	            IAppCard->writeRegister(0x00, l_nRegisterAddress);
	    }
}
void DDSWidget::initializeValues() {
	m_nAddress = m_nBDR = m_nBTUR = m_nData = m_nWDP=m_nWDP_LSW=m_nWDP_MSW = m_nSTART = m_nSTOP
                        = m_nDPC =m_nDDSCycle= 0;
	m_nTickFrequency = m_nTickTime = m_nSystemFrequency = m_nOutputFrequency
			= m_nOutputTime = m_nDDSVoltage=0.0;
	m_nDPC = m_nWDP = 1;
	m_nBTUR = 2;
	m_nBDR = 1;
	m_nBTURVALUE = (m_nBTUR) * 10.0;
        m_nWS1=0;m_nWS2=0;m_nWS3=0;


}
void DDSWidget::enableRichGUI() {
	QWidget *m_objWidget = new QWidget(this);
	QGraphicsScene *entireScene = new QGraphicsScene(0, 0, 800, 600);
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

	ui->grpBarRep->setParent(m_objWidget);
	ui->grpDDS->setParent(m_objWidget);
	ui->grpDrive->setParent(m_objWidget);
	ui->grpGeneral->setParent(m_objWidget);
	ui->grpPPT->setParent(m_objWidget);
	ui->grpTimeBase->setParent(m_objWidget);
	ui->grpAD5293->setParent(m_objWidget);

	ui->grpGeneral->setGeometry(10, 10, 280, 121);
        ui->grpTimeBase->setGeometry(310, 10, 471, 187);
        ui->grpDDS->setGeometry(10, 200, 280, 320);
        ui->grpPPT->setGeometry(310, 200, 470, 130);
        ui->grpDrive->setGeometry(310, 460, 470, 60);
        ui->grpBarRep->setGeometry(310, 333, 470, 130);
        ui->grpAD5293->setGeometry(10, 130, 281, 71);

	m_objLE_ADDR->setStyleSheet(
			"border-width: 2px;border-style: outset;border-color: gray; border-radius: 10px;  padding: 0 8px;     background: black;     selection-background-color: yellow;   color:white;     font: bold 14px;");
	m_objLE_DATA->setStyleSheet(
			"border-width: 2px;border-style: outset;border-color: gray; border-radius: 10px;  padding: 0 8px;     background: black;     selection-background-color: yellow;   color:white;     font: bold 14px;");
	m_objLE_BTU->setStyleSheet(
			"border-width: 2px;border-style: outset;border-color: gray; border-radius: 10px;  padding: 0 8px;     background: black;     selection-background-color: yellow;   color:white;     font: bold 14px;");
	m_objLE_BD->setStyleSheet(
			"border-width: 2px;border-style: outset;border-color: gray; border-radius: 10px;  padding: 0 8px;     background: black;     selection-background-color: yellow;   color:white;     font: bold 14px;");
	m_objLE_OPFreq->setStyleSheet(
			"border-width: 2px;border-style: outset;border-color: gray; border-radius: 10px;  padding: 0 8px;     background: black;     selection-background-color: yellow;   color:white;     font: bold 14px;");
	m_objLE_OPPhase->setStyleSheet(
			"border-width: 2px;border-style: outset;border-color: gray; border-radius: 10px;  padding: 0 8px;     background: black;     selection-background-color: yellow;   color:white;     font: bold 14px;");
	m_objLE_STDLY->setStyleSheet(
			"border-width: 2px;border-style: outset;border-color: gray; border-radius: 10px;  padding: 0 8px;     background: black;     selection-background-color: yellow;   color:white;     font: bold 14px;");
	m_objLE_WDP->setStyleSheet(
                "QLineEdit{border-width: 2px;border-style: outset;border-color: gray; border-radius: 10px;  padding: 0 8px;     background: black;     selection-background-color: yellow;   color:white;     font: bold 14px;}QLineEdit::disabled{border-width: 2px;border-style: outset;border-color: gray; border-radius: 10px;  padding: 0 8px;     background: dark gray;     selection-background-color: yellow;   color:white;     font: bold 14px;}");
	m_objLE_STOPDLY->setStyleSheet(
			"border-width: 2px;border-style: outset;border-color: gray; border-radius: 10px;  padding: 0 8px;     background: black;     selection-background-color: yellow;   color:white;     font: bold 14px;");
	m_objLE_DPC->setStyleSheet(
			"border-width: 2px;border-style: outset;border-color: gray; border-radius: 10px;  padding: 0 8px;     background: black;     selection-background-color: yellow;   color:white;     font: bold 14px;");
        m_objLE_DDSCycle->setStyleSheet(
                "QLineEdit{border-width: 2px;border-style: outset;border-color: gray; border-radius: 10px;  padding: 0 8px;     background: black;     selection-background-color: yellow;   color:white;     font: bold 14px;}QLineEdit::disabled{border-width: 2px;border-style: outset;border-color: gray; border-radius: 10px;  padding: 0 8px;     background: dark gray;     selection-background-color: yellow;   color:white;     font: bold 14px;}");
        m_objLE_DDSVoltage->setStyleSheet(
                "QLineEdit{border-width: 2px;border-style: outset;border-color: gray; border-radius: 10px;  padding: 0 8px;     background: black;     selection-background-color: yellow;   color:white;     font: bold 14px;}QLineEdit::disabled{border-width: 2px;border-style: outset;border-color: gray; border-radius: 10px;  padding: 0 8px;     background: dark gray;     selection-background-color: yellow;   color:white;     font: bold 14px;}");
	ui->leFS->setStyleSheet(
			"border-width: 2px;border-style: outset;border-color: gray; border-radius: 10px;  padding: 0 8px;     background: gray;     selection-background-color: yellow;   color:yellow;     font: bold 14px;");
	ui->leOutputTime->setStyleSheet(
			"border-width: 2px;border-style: outset;border-color: gray; border-radius: 10px;  padding: 0 8px;     background: gray;     selection-background-color: yellow;   color:yellow;     font: bold 14px;");
	ui->leTickFrequency->setStyleSheet(
			"border-width: 2px;border-style: outset;border-color: gray; border-radius: 10px;  padding: 0 8px;     background: gray;     selection-background-color: yellow;   color:yellow;     font: bold 14px;");
	ui->leTickTime->setStyleSheet(
			"border-width: 2px;border-style: outset;border-color: gray; border-radius: 10px;  padding: 0 8px;     background: gray;     selection-background-color: yellow;   color:yellow;     font: bold 14px;");

}

void DDSWidget::loadQmaxPlugins() {
	QPluginLoader loader4("libQmaxPTInterface.so", this);
	ILineEdit = qobject_cast<IQmaxLineEdit*> (loader4.instance());
	IPTLibrary = qobject_cast<IQmaxPTLibrary*> (loader4.instance());
	INumberPanel = qobject_cast<IQmaxNumberPanel*> (loader4.instance());

	QPluginLoader loaderApp("libPTApplicationcardInterface.so", this);
	IAppCard = qobject_cast<IApplicationCardInterface*> (loaderApp.instance());
	qDebug() << "Appcard" << IAppCard;
	IAppCard->setDeviceName(SLOT0);
	IAppCard->enumerateAPPCard();
	m_objAD5293Component = new AD5293(IAppCard);
    qDebug() << "Code ID:" << hex << IAppCard->readAppCardCodeId();

	QPluginLoader loader2("libBackPlaneInterface.so", this);
	IBackPlane = qobject_cast<IntefaceBackPlane*> (loader2.instance());
	IBackPlane->InitializeBpObject();

    // GPIO Envet
    QPluginLoader loader3("libGPIOEventInterface.so",this);
    IGPIOEvent = qobject_cast<PTGPIOEventInterface*>(loader3.instance());
    IGPIOEvent->InvokeGPIOEvent(this, "/dev/input/event1", "gpioevent", &m_nKeyCode);
	// Enable Interrupt
//	IBackPlane->writeBackPlaneRegister(0x40,0x20);
//	IBackPlane->writeBackPlaneRegister(0x0FFF,0x1E);
//	IBackPlane->writeBackPlaneRegister(0x1,0x24);
//
//	IGPIOEvent->setProbeFlag(-1);

}

void DDSWidget::initialiseLineEditControls() {
	m_objLE_ADDR = ILineEdit->QmaxLineEdit(0, ui->grpGeneral);
	m_objLE_ADDR->setGeometry(90, 10, 100, 30);

	m_objLE_DATA = ILineEdit->QmaxLineEdit(1, ui->grpGeneral);
	m_objLE_DATA->setGeometry(90, 60, 100, 30);

	m_objLE_BTU = ILineEdit->QmaxLineEdit(2, ui->grpTimeBase);
	m_objLE_BTU->setGeometry(110, 30, 100, 30);

	m_objLE_BD = ILineEdit->QmaxLineEdit(3, ui->grpTimeBase);
	m_objLE_BD->setGeometry(110, 100, 100, 30);

	m_objLE_OPFreq = ILineEdit->QmaxLineEdit(4, ui->grpDDS);
	m_objLE_OPFreq->setGeometry(140, 60, 100, 30);

	m_objLE_STDLY = ILineEdit->QmaxLineEdit(5, ui->grpPPT);
	m_objLE_STDLY->setGeometry(80, 20, 100, 30);

	m_objLE_STOPDLY = ILineEdit->QmaxLineEdit(6, ui->grpPPT);
	m_objLE_STOPDLY->setGeometry(312, 20, 100, 30);

	m_objLE_WDP = ILineEdit->QmaxLineEdit(7, ui->grpPPT);
	m_objLE_WDP->setGeometry(80, 70, 100, 30);

	m_objLE_DPC = ILineEdit->QmaxLineEdit(8, ui->grpPPT);
	m_objLE_DPC->setGeometry(320, 70, 100, 30);

	m_objLE_OPPhase = ILineEdit->QmaxLineEdit(9, ui->grpDDS);
	m_objLE_OPPhase->setGeometry(140, 100, 100, 30);

        m_objLE_DDSCycle=ILineEdit->QmaxLineEdit(10,ui->grpDDS);
        m_objLE_DDSCycle->setGeometry(90, 187, 100, 30);

    m_objLE_DDSVoltage=ILineEdit->QmaxLineEdit(11,ui->grpAD5293);
    m_objLE_DDSVoltage->setGeometry(70, 20, 113, 30);


	connect(m_objLE_ADDR, SIGNAL(focussed(bool)), this, SLOT(callAddressEdit()));
	connect(m_objLE_DATA, SIGNAL(focussed(bool)), this, SLOT(callDataEdit()));
	connect(m_objLE_BTU, SIGNAL(focussed(bool)), this, SLOT(callBTUEdit()));
	connect(m_objLE_BD, SIGNAL(focussed(bool)), this, SLOT(callBDEdit()));
	connect(m_objLE_OPFreq, SIGNAL(focussed(bool)), this, SLOT(callOPFrequencyEdit()));
	connect(m_objLE_OPPhase, SIGNAL(focussed(bool)), this,SLOT(callOPPhaseEdit()));
	connect(m_objLE_STDLY, SIGNAL(focussed(bool)), this,SLOT(callSTARTDLYEdit()));
	connect(m_objLE_STOPDLY, SIGNAL(focussed(bool)), this,SLOT(callSTOPDLYEdit()));
	connect(m_objLE_WDP, SIGNAL(focussed(bool)), this, SLOT(callWDPEdit()));
	connect(m_objLE_DPC, SIGNAL(focussed(bool)), this, SLOT(callDPCEdit()));
	connect(m_objLE_DDSCycle,SIGNAL(focussed(bool)),this,SLOT(callDDSCycle()));
	connect(m_objLE_DDSVoltage,SIGNAL(focussed(bool)),this,SLOT(callDDSVoltageEdit()));

	m_objLE_STDLY->setText("0");
	m_objLE_STOPDLY->setText("0");
	m_objLE_WDP->setText("1");
	m_objLE_DPC->setText("1");
	m_objLE_BTU->setText("2");
	m_objLE_BD->setText("1");

	 timer = new QTimer(this);
	 connect(timer, SIGNAL(timeout()), this, SLOT(LoopDrive()));
}

void DDSWidget::callSTARTDLYEdit() {
	if (m_objLE_STDLY->hasFocus()) {
		//openNumKBPanel(2);
		openNumKBPanelminmax(2, 255, 0);
		m_nLineEditIndex = 5;
	}

}

void DDSWidget::callSTOPDLYEdit() {
	if (m_objLE_STOPDLY->hasFocus()) {
		//openNumKBPanel(2);
		openNumKBPanelminmax(2, 255, 0);
		m_nLineEditIndex = 6;
	}

}

void DDSWidget::callWDPEdit() {
	if (m_objLE_WDP->hasFocus()) {
		//openNumKBPanel(2);
		openNumKBPanelminmax(2, 65536, 1);
		m_nLineEditIndex = 7;
	}

}

void DDSWidget::callDPCEdit() {
	if (m_objLE_DPC->hasFocus()) {
		//            openNumKBPanel(2);
		openNumKBPanelminmax(2, 4294967296, 1);
		m_nLineEditIndex = 8;
	}

}

void DDSWidget::callAddressEdit() {
	if (m_objLE_ADDR->hasFocus()) {
		openNumKBPanel(0);
		m_nLineEditIndex = 0;
	}

}

void DDSWidget::callDataEdit() {
	if (m_objLE_DATA->hasFocus()) {
		openNumKBPanel(0);
		m_nLineEditIndex = 1;
	}
}

void DDSWidget::callBTUEdit() {
	if (m_objLE_BTU->hasFocus()) {
		//openNumKBPanel(2);
		openNumKBPanelminmax(2, 65536, 2);
		m_nLineEditIndex = 2;
	}
}

void DDSWidget::callBDEdit() {
	if (m_objLE_BD->hasFocus()) {
		//openNumKBPanel(2);
		openNumKBPanelminmax(2, 65536, 1);
		m_nLineEditIndex = 3;
	}
}

void DDSWidget::callOPFrequencyEdit() {
	if (m_objLE_OPFreq->hasFocus()) {
		//          openNumKBPanel(2);
		QWidget *w = INumberPanel->getNumKBPanelIncDec(1, 1, 'F', 10000000, 0,
				this);
		w->setWindowFlags(Qt::WindowCloseButtonHint | Qt::Dialog);
		w->show();
		m_nLineEditIndex = 4;
	}

}
void DDSWidget::callOPPhaseEdit() {
	if (m_objLE_OPPhase->hasFocus()) {
		QWidget *w = INumberPanel->getNumKBPanelIncDec(1, 1, 'D', 360, 0, this);
		w->setWindowFlags(Qt::WindowCloseButtonHint | Qt::Dialog);
		w->show();
		m_nLineEditIndex = 9;
	}
}
void DDSWidget::callDDSCycle(){
    if (m_objLE_DDSCycle->hasFocus()) {
    	QWidget *w = INumberPanel->getNumKBPanelIncDec(2, 1, 'A', 255, 1,this);
    	w->setWindowFlags(Qt::WindowCloseButtonHint | Qt::Dialog);
    	w->show();
         m_nLineEditIndex = 10;
    }
}

void DDSWidget::callDDSVoltageEdit()
{
	double m_nVoltRangeArray[5]={0.6,1.5,3.5,7.0,13.0};
	QWidget *w = INumberPanel->getNumKBPanelIncDec(1, 1, 'V', m_nVoltRangeArray[ui->cmbVoltRanges->currentIndex()], 0,this);
	w->setWindowFlags(Qt::WindowCloseButtonHint | Qt::Dialog);
	w->show();
	m_nLineEditIndex = 11;
}

void DDSWidget::openNumKBPanelminmax(short int pValue, double pMax, double pMin) {
	QWidget *w = INumberPanel->getNumKBPanelIncDec(pValue, 1, 'T', pMax, pMin,
			this);
	w->setWindowFlags(Qt::WindowCloseButtonHint | Qt::Dialog);
	w->show();

}

void DDSWidget::openNumKBPanel(short int pValue) {
	QWidget *w = INumberPanel->getNumKBPanel(pValue, this);
	w->setWindowFlags(Qt::WindowCloseButtonHint | Qt::Dialog);
	w->show();
}

void DDSWidget::receiveValue(unsigned int pValue) {
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
	} else if (m_nLineEditIndex == 1) {
		m_objLE_DATA->setText(QString::number(pValue, 16));
		m_nData = pValue;
	} else if (m_nLineEditIndex == 2) {
		m_objLE_BTU->setText(QString::number(pValue, 10));
		m_nBTUR = (pValue);
		m_nBTURVALUE = (m_nBTUR) * 10.0;
	} else if (m_nLineEditIndex == 3) {
		m_objLE_BD->setText(QString::number(pValue, 10));
		m_nBDR = (pValue);
	}
	//    else if(m_nLineEditIndex ==4){
	//        m_objLE_OPFreq->setText(QString::number(pValue,10));
	//        m_nOutputFrequency = pValue;
	//    }
	else if (m_nLineEditIndex == 5) {
		m_objLE_STDLY->setText(QString::number(pValue, 10));
		m_nSTART = pValue;
	} else if (m_nLineEditIndex == 6) {
		m_objLE_STOPDLY->setText(QString::number(pValue, 10));
		m_nSTOP = pValue;
	} else if (m_nLineEditIndex == 7) {
		m_objLE_WDP->setText(QString::number(pValue, 10));
		m_nDPC = pValue;
	} else if (m_nLineEditIndex == 8) {
		m_objLE_DPC->setText(QString::number(pValue, 10));
		m_nWDP = pValue;

//		m_nWDP_LSW = ((unsigned int) m_nWDP << 16) >> 16;
//		m_nWDP_MSW =  (unsigned int) m_nWDP >> 16;

//		IAppCard->setDrivePeriod(m_nWDP_LSW - 1);
//		IAppCard->writeRegister(m_nWDP_MSW,0x14);
       }else if(m_nLineEditIndex==10){
        m_objLE_DDSCycle->setText(QString::number(pValue,10));
        m_nDDSCycle=pValue;
        m_nDDSCycle=(m_nDDSCycle<<8)|0x1;
    }
}



void DDSWidget::receiveValue(QString pValue) {
	Q_UNUSED(pValue)
	qDebug() << m_nLineEditIndex << "pValue:" << pValue;
}

void DDSWidget::receiveValue(double pValue) {
	double m_nVoltRangeArray[5]={0.6,1.5,3.5,7.0,13.0};
	qDebug() << m_nLineEditIndex << "pValue:" << pValue;
	if (m_nLineEditIndex == 4) {
		m_nOutputFrequency = validateFrequency(pValue);
		qDebug() << "validated frequency:" << m_nOutputFrequency
				<< m_strFreqUnit;
		m_objLE_OPFreq->setText(QString::number(m_nOutputFrequency, 'f', 3));
		ui->FoUnit->setText(m_strFreqUnit);
		m_nOutputFrequency = pValue;
		ui->leOutputTime->setText(QString::number((validateTime((1 / pValue))),
				'f', 3));
		ui->opUnit->setText(m_strTimeUnit);

		//update on value change---------------------------------------
		double l_nFTWOutputFrequency, l_nOutputTime;
		l_nFTWOutputFrequency = (m_nOutputFrequency / 50000000);
		l_nFTWOutputFrequency = l_nFTWOutputFrequency * pow(2, 32);
		l_nOutputTime = 1 / l_nFTWOutputFrequency;
		qDebug() << "FTW Output Frequency:" << l_nFTWOutputFrequency;
		qDebug() << "FTW Output Time:" << l_nOutputTime;
		m_nFTW_LSW = ((unsigned int) l_nFTWOutputFrequency << 16) >> 16;
		m_nFTW_MSW = (unsigned int) l_nFTWOutputFrequency >> 16;
		qDebug() << "FTW_LSW" << hex << m_nFTW_LSW;
		qDebug() << "FTW_MSW" << hex << m_nFTW_MSW;
		IAppCard->setDDSFTW_LSW(m_nFTW_LSW);
		IAppCard->setDDSFTW_MSW(m_nFTW_MSW);
		//---------------------------------------------------------------
	} else if (m_nLineEditIndex == 9) {
		m_nOutputPhase = pValue;
		m_objLE_OPPhase->setText(QString::number(m_nOutputPhase, 'f', 2));
		QString deg = QChar(0x00B0);
		ui->phaseUnit->setText(deg);
		m_nOutputPhase = (((pow(2,32))-1)*pValue)/360;
        }
	else if(m_nLineEditIndex == 11)
	{
		m_nDDSVoltage = pValue;
		m_objLE_DDSVoltage->setText(QString::number(m_nDDSVoltage, 'f', 2));
		m_nDDSVoltage = 1600/(pValue/m_nVoltRangeArray[ui->cmbVoltRanges->currentIndex()]);
		IAppCard->setSPIAppendBit(0x8000);
		m_objAD5293Component->setAD5293Voltage(m_nDDSVoltage);
	    m_objAD5293Component->writeAD5293(SPI1);
		qDebug()<<"ROut:"<<m_nDDSVoltage;
	}
}

DDSWidget::~DDSWidget() {
	saveSettings();
	delete ui;
}

void DDSWidget::changeEvent(QEvent *e) {
	QWidget::changeEvent(e);
	switch (e->type()) {
	case QEvent::LanguageChange:
		ui->retranslateUi(this);
		break;
	default:
		break;
	}
}

void DDSWidget::on_butRead_clicked() {
	if (ui->appSelection->isChecked())
		m_objLE_DATA->setText(QString::number(
				IAppCard->readRegister(m_nAddress), 16));
	else if (ui->bkpanelSelection->isChecked())
		m_objLE_DATA->setText(QString::number(
				IBackPlane->readBackPlaneRegister(m_nAddress), 16));
}

void DDSWidget::on_butWrite_clicked() {
	if (ui->appSelection->isChecked())
		IAppCard->writeRegister(m_nData, m_nAddress);
	else if (ui->bkpanelSelection->isChecked())
		IBackPlane->writeBackPlaneRegister(m_nData, m_nAddress);
}

double DDSWidget::validateFrequency(double pFrequency) {
	double l_nFrequency = pFrequency;
	//qDebug()<<"Check:"<<pFrequency;
	m_strFreqUnit = QString("hz");
	if (l_nFrequency >= 1000000.0) {
		l_nFrequency = l_nFrequency / 1000000.0;
		m_strFreqUnit = QString("Mhz");
	} else if (l_nFrequency >= 1000.0) {
		l_nFrequency = l_nFrequency / 1000.0;
		m_strFreqUnit = QString("Khz");
	}
	qDebug() << "Frequency:" << l_nFrequency << m_strFreqUnit;
	return l_nFrequency;
}

double DDSWidget::validateTime(double pTime) {
	double l_nTickTime = pTime;

	if (l_nTickTime >= (1 / 1000.0)) {
		l_nTickTime *= 1000.0;
		m_strTimeUnit = "ms";
	} else if (l_nTickTime >= (1 / 1000000.0)) {
		l_nTickTime *= 1000000.0;
		m_strTimeUnit = "us";
	} else if (l_nTickTime >= (1 / 1000000000.0)) {
		l_nTickTime *= 1000000000.0;
		m_strTimeUnit = "ns";
	}
	qDebug() << "TT:" << l_nTickTime << m_strTimeUnit;
	return l_nTickTime;
}

void DDSWidget::on_butCalculate_clicked() {
	QMap<QString, double> l_mapTime;
	l_mapTime.insert("ms", 1 / 1000.0);
	l_mapTime.insert("us", 1 / 1000000.0);
	l_mapTime.insert("ns", 1 / 1000000000.0);
	qDebug() << "DPC:" << m_nWDP << "WDP:" << m_nDPC << m_nBTURVALUE;
	if (m_nDPC == 0 || m_nWDP == 0) {
		qDebug() << "Check Pattern Count & Wave Pattern Count";
		return;
	}
	//qDebug() << "Clicked";
	double l_nTotalTime = ((m_nWDP) * (m_nBTURVALUE * (m_nBDR))) * 1.0
			/ 1000000000.0;
	double l_ntickFrequency = 1 / (((m_nBTURVALUE * (m_nBDR))) * 1.0
			/ 1000000000.0);//ravi

	qDebug() << "TOTAL TIME1:" << l_nTotalTime;
	qDebug() << "Tick Frequency:" << l_ntickFrequency;
	double l_nFrequency = 1.0 / l_nTotalTime;
	double l_nTickTime = (l_nTotalTime / m_nWDP);
	qDebug() << "TickTime:" << l_nTickTime;
	l_nTickTime = validateTime(l_nTickTime);
	ui->lblTimeUnits->setText(m_strTimeUnit);
	l_nFrequency = validateFrequency(l_nFrequency);
	l_ntickFrequency = validateFrequency(l_ntickFrequency);
	ui->lblUnits->setText(m_strFreqUnit);
	//ui->leTickFrequency->setText(QString::number((l_nFrequency)/m_nWDP,'f',3));
	ui->leTickFrequency->setText(QString::number(l_ntickFrequency,
			'f', 3));
	ui->leTickTime->setText(QString::number(l_nTickTime, 'f', 2));

	ui->lblSTDLY->setText(QString::number(m_nSTART * l_nTickTime, 'f', 3) + " "
			+ m_strTimeUnit);
	ui->lblSTOPDLY->setText(QString::number(m_nSTOP * l_nTickTime, 'f', 3)
			+ " " + m_strTimeUnit);
	//    ui->lbl_WDP->setText(QString::number((m_nDPC*l_nTickTime*m_nWDP),'f',3)+" "+m_strTimeUnit);
	ui->lbl_WDP->setText(QString::number((l_nTickTime * m_nWDP), 'f', 3) + " "
			+ m_strTimeUnit);
	//    double l_nWDPTime = (m_nDPC*l_nTickTime*m_nWDP);//ravi
	double l_nWDPTime = (l_nTickTime * m_nWDP);//ravi
	double l_nWDPFrequency = 1 / (l_nWDPTime * l_mapTime.value(m_strTimeUnit));
	qDebug() << "l_nWDPTime:" << l_nWDPTime << validateFrequency(
			l_nWDPFrequency);
	ui->lblWDPFreq->setText(QString("( ") + QString::number(validateFrequency(
			l_nWDPFrequency), 'f', 3) + " " + m_strFreqUnit + QString(" )"));
	//    double l_nTTime = (m_nSTART*l_nTickTime) +(m_nDPC*l_nTickTime*m_nWDP)+(m_nSTOP*l_nTickTime);
	double l_nTTime = ((m_nSTART * l_nTickTime) + (l_nTickTime * m_nWDP)
			+ (m_nSTOP * l_nTickTime)) * m_nDPC;
	qDebug() << "TOTAL TIME2:" << l_nTTime * l_mapTime.value(m_strTimeUnit);
	ui->lblTotalTime->setText(QString::number(l_nTTime, 'f', 2) + m_strTimeUnit);
	double l_nTFrequency = 1.0 / (l_nTTime * l_mapTime.value(m_strTimeUnit));
	ui->lblTotalFrequency->setText(QString::number(validateFrequency(
			l_nTFrequency), 'f', 3) + m_strFreqUnit);

	// 	  double l_nOutputTime= 1/m_nOutputFrequency;
	//    l_nOutputTime = validateTime(l_nOutputTime);
	//    qDebug() << "Output Frequency:"<< m_nOutputFrequency << "Output Time:"
	//    		<< l_nOutputTime;
	//    ui->leOutputTime->setText(QString::number(l_nOutputTime,'f',2));

	m_nSystemFrequency = validateFrequency(50000000);
	ui->leFS->setText(QString::number(m_nSystemFrequency, 'f', 2));
	ui->FsUnit->setText(m_strFreqUnit);

	double l_nFTWOutputFrequency;//rravi
	double l_nOutputTime;
	l_nFTWOutputFrequency = (m_nOutputFrequency / 50000000);
	l_nFTWOutputFrequency = l_nFTWOutputFrequency * pow(2, 32);
	l_nOutputTime = 1 / l_nFTWOutputFrequency;

	qDebug() << "FTW Output Frequency:" << l_nFTWOutputFrequency;
	qDebug() << "FTW Output Time:" << l_nOutputTime;

	m_nFTW_LSW = ((unsigned int) l_nFTWOutputFrequency << 16) >> 16;
	m_nFTW_MSW = (unsigned int) l_nFTWOutputFrequency >> 16;

	qDebug() << "FTW_LSW" << hex << m_nFTW_LSW;
	qDebug() << "FTW_MSW" << hex << m_nFTW_MSW;

	m_nPTW_LSW = ((unsigned int) m_nOutputPhase << 16) >> 16;
	m_nPTW_MSW = (unsigned int) m_nOutputPhase >> 16;

	qDebug() << "PTW_LSW" << hex << m_nPTW_LSW;
	qDebug() << "PTW_MSW" << hex << m_nPTW_MSW;

	// Calcuation for RAM Period

	unsigned short int l_nRAMCount = IAppCard->readRegister(0x84);
	qDebug()<< "Ram Count:"<<l_nRAMCount<<"  "<<l_nTickTime;
	double l_nRAMPeriod = l_nTickTime * (l_nRAMCount+1);
	qDebug() << "RAM Period1:"<<l_nRAMPeriod;
	double l_nRAMFrequency = 1/l_nRAMPeriod;
	l_nRAMPeriod = validateTime(l_nRAMPeriod);
	qDebug() << "RAM Period2:"<<l_nRAMPeriod;
	ui->leRamPeriod->setText(QString::number(l_nRAMPeriod,
			'f', 3)+" "+m_strTimeUnit);
	l_nRAMFrequency = validateFrequency(l_nRAMFrequency);
	qDebug() << "RAM Frequency:"<<l_nRAMFrequency;
	ui->leRamFrequency->setText(QString::number(l_nRAMFrequency,
			'f', 3)+" "+m_strFreqUnit);



}

void DDSWidget::on_comboBox_currentIndexChanged(int index) {
    qDebug()<<"Predefined Selection"<<index;

    m_nWS1=(unsigned short int)index;
    IAppCard->writeRegister(m_nWS1,0x74);
}
void DDSWidget::on_comboBox_2_currentIndexChanged(int index){
    qDebug()<<"Waveform Selection"<<index;

    m_nWS2=(unsigned short int)index;
    m_nWS=(m_nWS2<<2)|m_nWS3;
    IAppCard->writeRegister(m_nWS,0x72);
}
void DDSWidget::on_comboBox_3_currentIndexChanged(int index){
    qDebug()<<"Drive Mode"<<index;

    m_nWS3=(unsigned short int)index;
    m_nWS=(m_nWS2<<2)|m_nWS3;
    IAppCard->writeRegister(m_nWS,0x72);
}
void DDSWidget::on_comboBox_4_currentIndexChanged(int index)
{
	qDebug()<<"Drive Path"<<index;
	m_nWS4=(unsigned short int)index;
    IAppCard->writeRegister(m_nWS4,0x94);
}
void DDSWidget::on_chkLoop_clicked(bool checked) {
    m_objLE_WDP->setEnabled(!checked);
}

void DDSWidget::on_butUpdate_clicked() {
	IAppCard->basicTimeUnit(m_nBTUR - 1);
	IAppCard->basicDuration(m_nBDR - 1);
	IAppCard->setDrivePeriod(m_nWDP - 1);
//	IAppCard->setDrivePeriod(m_nWDP_LSW - 1);
//	IAppCard->writeRegister(m_nWDP_MSW,0x14);
	IAppCard->setStartStop(m_nSTART, m_nSTOP);
        if(ui->chkLoop->isChecked()==false){
            IAppCard->setDrivePatternCount(false, m_nDPC - 1);
        }else{
            temp=m_nDPC-1;
//            temp=temp|0X100;
            qDebug()<<"With count loop checked"<<hex<<temp;
            IAppCard->setDrivePatternCount(true, temp);
        }
	IAppCard->setDDSFTW_LSW(m_nFTW_LSW);
	IAppCard->setDDSFTW_MSW(m_nFTW_MSW);

	IAppCard->setDDSPTW_LSW(m_nPTW_LSW);
	IAppCard->setDDSPTW_MSW(m_nPTW_MSW);

	//IAppCard->writeRegister(0x0001,PT_APPCARD_MODULES::PT_DRRLY_APPCARD_DRSER);
	IAppCard->writeRegister(0x0001,PT_APPCARD_MODULES::PT_DRRLY_APPCARD_DSAR);

        if(ui->countLoop->isChecked()==false){
            if(m_nDDSCycle==0)
                m_nDDSCycle=(1<<8)|0x1;

            qDebug()<<"DDS Cycle Write"<<hex<<m_nDDSCycle;
            IAppCard->writeRegister(m_nDDSCycle,PT_APPCARD_MODULES::PT_DDS_APPCARD_CR);
        }else{
            if(m_nDDSCycle==0)
                m_nDDSCycle=(1<<8)|0x1;

            temp=m_nDDSCycle|0x80;
            qDebug()<<"DDS Loop Cycle Write"<<hex<<temp;
            IAppCard->writeRegister(temp,PT_APPCARD_MODULES::PT_DDS_APPCARD_CR);
        }

}

void DDSWidget::on_butDrive_clicked() {
	//IGPIOEvent->setStopFlag(false);
//	IAppCard->startDrive(1);
	if (ui->checkBox->isChecked() == false) {
		if(timer->isActive()){
			timer->stop();
			IAppCard->stopDrive();
		}
		else{
			IAppCard->startDrive(1);
		}
	} else if (ui->checkBox->isChecked() == true) {
			timer->start(100);
	}

}
void DDSWidget::LoopDrive(){
	qDebug()<<"In LoopDrive";
	IAppCard->startDrive(1);

	while(ret!=1){
		ret = IAppCard->readRegister(PT_APPCARD_MODULES::PT_DRIVE_APPCARD_DCR);
		IAppCard->startDrive(1);
	}

}
void DDSWidget::on_butStop_clicked() {
	//IGPIOEvent->setStopFlag(true);
			if(timer->isActive()){
				timer->stop();
				IAppCard->stopDrive();
		}else
				IAppCard->stopDrive();
}

void DDSWidget::on_appSelection_clicked(bool checked) {

}

void DDSWidget::on_bkpanelSelection_clicked(bool checked) {

}

void DDSWidget::on_checkBox_clicked(bool checked) {
	if (checked == false){
			if(timer->isActive())
					timer->stop();
			IAppCard->stopDrive();
	}

}

void DDSWidget::on_pushButton_clicked()
{
    DACCalibration *objDAC=new DACCalibration(this);
    objDAC->show();
}
void DDSWidget::on_countLoop_clicked()
{

}

void DDSWidget::saveSettings() {
        ddsSetFile = "ddSettings.ini";
        QSettings settings(ddsSetFile, QSettings::NativeFormat);
        //LineEdits
        QString le1 = (ui->leFS) ? ui->leFS->text() : "";
        settings.setValue("leFS", le1);
        QString le2 = (ui->leOutputTime) ? ui->leOutputTime->text() : "";
        settings.setValue("leOutputTime", le2);
        QString le3 = (ui->leTickFrequency) ? ui->leTickFrequency->text() : "";
        settings.setValue("leTickFrequency", le3);
        QString le4 = (ui->leTickTime) ? ui->leTickTime->text() : "";
        settings.setValue("leTickTime", le4);

        QString le5 = (m_objLE_ADDR) ? m_objLE_ADDR->text() : "";
        settings.setValue("m_objLE_ADDR", le5);
        QString le6 = (m_objLE_DATA) ? m_objLE_DATA->text() : "";
        settings.setValue("m_objLE_DATA", le6);
        QString le7 = (m_objLE_BTU) ? m_objLE_BTU->text() : "";
        settings.setValue("m_objLE_BTU", le7);
        QString le8 = (m_objLE_BD) ? m_objLE_BD->text() : "";
        settings.setValue("m_objLE_BD", le8);
        QString le9 = (m_objLE_OPFreq) ? m_objLE_OPFreq->text() : "";
        settings.setValue("m_objLE_OPFreq", le9);
        QString le10 = (m_objLE_OPPhase) ? m_objLE_OPPhase->text() : "";
        settings.setValue("m_objLE_OPPhase", le10);
        QString le11 = (m_objLE_STDLY) ? m_objLE_STDLY->text() : "";
        settings.setValue("m_objLE_STDLY", le11);
        QString le12 = (m_objLE_STOPDLY) ? m_objLE_STOPDLY->text() : "";
        settings.setValue("m_objLE_STOPDLY", le12);
        QString le13 = (m_objLE_WDP) ? m_objLE_WDP->text() : "";
        settings.setValue("m_objLE_WDP", le13);
        QString le14 = (m_objLE_DPC) ? m_objLE_DPC->text() : "";
        settings.setValue("m_objLE_DPC", le14);
        QString le15 = (m_objLE_DDSCycle) ? m_objLE_DDSCycle->text() : "";
        settings.setValue("m_objLE_DDSCycle", le15);

        //ComboBox
        QString cmb1 = (ui->comboBox) ? QString::number(
                        ui->comboBox->currentIndex(), 10) : "";
        settings.setValue("comboBox", cmb1);

        //labels
        QString lbl1 = (ui->FsUnit) ? ui->FsUnit->text() : "";
        settings.setValue("FsUnit", lbl1);
        QString lbl2 = (ui->FoUnit) ? ui->FoUnit->text() : "";
        settings.setValue("FoUnit", lbl2);
        QString lbl3 = (ui->phaseUnit) ? ui->phaseUnit->text() : "";
        settings.setValue("phaseUnit", lbl3);
        QString lbl4 = (ui->opUnit) ? ui->opUnit->text() : "";
        settings.setValue("opUnit", lbl4);
        QString lbl5 = (ui->lblSTDLY) ? ui->lblSTDLY->text() : "";
        settings.setValue("lblSTDLY", lbl5);
        QString lbl6 = (ui->lblSTOPDLY) ? ui->lblSTOPDLY->text() : "";
        settings.setValue("lblSTOPDLY", lbl6);
        QString lbl7 = (ui->lblTimeUnits) ? ui->lblTimeUnits->text() : "";
        settings.setValue("lblTimeUnits", lbl7);
        QString lbl8 = (ui->lblTotalFrequency) ? ui->lblTotalFrequency->text() : "";
        settings.setValue("lblTotalFrequency", lbl8);
        QString lbl9 = (ui->lblTotalTime) ? ui->lblTotalTime->text() : "";
        settings.setValue("lblTotalTime", lbl9);
        QString lbl10 = (ui->lblUnits) ? ui->lblUnits->text() : "";
        settings.setValue("lblUnits", lbl10);
        QString lbl11 = (ui->lblWDPFreq) ? ui->lblWDPFreq->text() : "";
        settings.setValue("lblWDPFreq", lbl11);
        QString lbl12 = (ui->lbl_WDP) ? ui->lbl_WDP->text() : "";
        settings.setValue("lbl_WDP", lbl12);

        qDebug()<<"Settings Saved.";
}
void DDSWidget::loadSettings() {
        bool ok;
        ddsSetFile = "ddSettings.ini";
        QSettings settings(ddsSetFile, QSettings::NativeFormat);
        //LineEdits
        QString le1 = settings.value("leFS", "").toString();
        QString le2 = settings.value("leOutputTime", "").toString();
        QString le3 = settings.value("leTickFrequency", "").toString();
        QString le4 = settings.value("leTickTime", "").toString();

        QString le5 = settings.value("m_objLE_ADDR", "").toString();
        QString le6 = settings.value("m_objLE_DATA", "").toString();
        QString le7 = settings.value("m_objLE_BTU", "").toString();
        QString le8 = settings.value("m_objLE_BD", "").toString();
        QString le9 = settings.value("m_objLE_OPFreq", "").toString();
        QString le10 = settings.value("m_objLE_OPPhase", "").toString();
        QString le11 = settings.value("m_objLE_STDLY", "").toString();
        QString le12 = settings.value("m_objLE_STOPDLY", "").toString();
        QString le13 = settings.value("m_objLE_WDP", "").toString();
        QString le14 = settings.value("m_objLE_DPC", "").toString();
        QString le15 = settings.value("m_objLE_DDSCycle", "").toString();

        if (ui->leFS) {
                ui->leFS->setText(le1);
        }
        if (ui->leOutputTime) {
                ui->leOutputTime->setText(le2);
        }
        if (ui->leTickFrequency) {
                ui->leTickFrequency->setText(le3);
        }
        if (ui->leTickTime) {
                ui->leTickTime->setText(le4);
        }

        if (m_objLE_ADDR) {
                m_objLE_ADDR->setText(le5);
                        m_nAddress=le5.toUInt(&ok,10);
        }
        if (m_objLE_DATA) {
                m_objLE_DATA->setText(le6);
                        m_nData=le6.toUInt(&ok,10);
        }
        if (m_objLE_BTU) {
                m_objLE_BTU->setText(le7);
                        m_nBTUR=le7.toUInt(&ok,10);
                        m_nBTURVALUE = (m_nBTUR) * 10.0;
        }
        if (m_objLE_BD) {
                m_objLE_BD->setText(le8);
                        m_nBDR=le8.toUInt(&ok,10);
        }
        if (m_objLE_OPFreq) {
                m_objLE_OPFreq->setText(le9);
                        m_nOutputFrequency=le9.toUInt(&ok,10);
        }
        if (m_objLE_OPPhase) {
                m_objLE_OPPhase->setText(le10);
                        m_nOutputPhase=le10.toUInt(&ok,10);
        }
        if (m_objLE_STDLY) {
                m_objLE_STDLY->setText(le11);
                        m_nSTART=le11.toUInt(&ok,10);
        }
        if (m_objLE_STOPDLY) {
                m_objLE_STOPDLY->setText(le12);
                        m_nSTOP=le12.toUInt(&ok,10);
        }
        if (m_objLE_WDP) {
                m_objLE_WDP->setText(le13);
                        m_nDPC=le13.toUInt(&ok,10);
        }
        if (m_objLE_DPC) {
                m_objLE_DPC->setText(le14);
                        m_nWDP=le14.toUInt(&ok,10);
        }
    if (m_objLE_DDSCycle){
        m_objLE_DDSCycle->setText(le15);
            m_nDDSCycle=le15.toUInt(&ok,10);
            m_nDDSCycle=(m_nDDSCycle<<8)|0x1;
    }

        //comboBox
        QString cmb1 = settings.value("comboBox", "").toString();

        if (ui->comboBox) {
                ui->comboBox->setCurrentIndex(cmb1.toInt(&ok, 10));
        }

        //labels
        QString lbl1 = settings.value("FsUnit", "").toString();
        if (ui->FsUnit) {
                ui->FsUnit->setText(lbl1);
        }
        QString lbl2 = settings.value("FoUnit", "").toString();
        if (ui->FoUnit) {
                ui->FoUnit->setText(lbl2);
        }
        QString lbl3 = settings.value("phaseUnit", "").toString();
        if (ui->phaseUnit) {
                ui->phaseUnit->setText(lbl3);
        }
        QString lbl4 = settings.value("opUnit", "").toString();
        if (ui->opUnit) {
                ui->opUnit->setText(lbl4);
        }
        QString lbl5 = settings.value("lblSTDLY", "").toString();
        if (ui->lblSTDLY) {
                ui->lblSTDLY->setText(lbl5);
        }
        QString lbl6 = settings.value("lblSTOPDLY", "").toString();
        if (ui->lblSTOPDLY) {
                ui->lblSTOPDLY->setText(lbl6);
        }
        QString lbl7 = settings.value("lblTimeUnits", "").toString();
        if (ui->lblTimeUnits) {
                ui->lblTimeUnits->setText(lbl7);
        }
        QString lbl8 = settings.value("lblTotalFrequency", "").toString();
        if (ui->lblTotalFrequency) {
                ui->lblTotalFrequency->setText(lbl8);
        }
        QString lbl9 = settings.value("lblTotalTime", "").toString();
        if (ui->lblTotalTime) {
                ui->lblTotalTime->setText(lbl9);
        }
        QString lbl10 = settings.value("lblUnits", "").toString();
        if (ui->lblUnits) {
                ui->lblUnits->setText(lbl10);
        }
        QString lbl11 = settings.value("lblWDPFreq", "").toString();
        if (ui->lblWDPFreq) {
                ui->lblWDPFreq->setText(lbl11);
        }
        QString lbl12 = settings.value("lbl_WDP", "").toString();
        if (ui->lbl_WDP) {
                ui->lbl_WDP->setText(lbl12);
        }
        qDebug()<<"Settings Loaded.";
        on_cmbVoltRanges_currentIndexChanged(0);
}


void DDSWidget::on_countLoop_clicked(bool checked)
{
    m_objLE_DDSCycle->setEnabled(!checked);
}






