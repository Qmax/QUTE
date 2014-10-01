#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent,Qt::FramelessWindowHint),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //qDebug()<<"11";
    initialiseDSOGraphicsItems();
    //qDebug()<<"22";
    initChannelWidget();
   // qDebug()<<"33";
    createDynamicSubItems();
   // qDebug()<<"44";
    defaultSidePane(CHANNEL_1,"DSONavigation","Channel");
    initConfiguration();
    InitializeHardwareLibs();
   // qDebug()<<"55";
}

void MainWindow::initConfiguration()
{
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
    //m_nSamples = 2500;
    m_objDSOWaveSettings = new DSOWaveSettings();
	m_objLMH6518Component->configureLMH6518DW(m_eDataTemplate);
	m_objLMH6518Component->configureLMH6518DW(m_eDataTemplateCH2);

	//changeChannel1Widget(CHANNEL_1);


}
void MainWindow::doIntPlot(QList<unsigned char> pLstOdd,QList<unsigned char> pLstEven)
{
  //  DSO_CHANNEL l_nChannel = (m_nChannelValue==1)?CHANNEL1:CHANNEL3;
	//qDebug()<<"Do Plot";
	mLstEven = pLstEven;mLstOdd=pLstOdd;
    IGPIOEvent->BlockSig(true);
    IPTKeyEvent->BlockSig(true);
    m_objDSOWaveSettings->convertToDecimation(m_objDSODataSettings->getVoltPerDivsion(CHANNEL_1),m_objDSODataSettings->getFSSettings(CHANNEL_1),m_objBoundaryRect.width()-(2*dsoMargin),R1FIFO,m_nSamples,pLstOdd,pLstEven);
    m_objch1Item->setPlotData(m_objDSOWaveSettings->getYVectorPoints(0));
    double yMaxPosition = m_objch1Item->getYPosition(m_objDSOWaveSettings->m_objCH1Measurements.getNinentyPercentPeak());
    double yMinPosition = m_objch1Item->getYPosition(m_objDSOWaveSettings->m_objCH1Measurements.getTenPercentPeak());
    m_nV1CursorPosition = m_objDSOWaveSettings->m_objCH1Measurements.getX2Pos();
    m_nV2CursorPosition = m_objDSOWaveSettings->m_objCH1Measurements.getX1Pos();
    m_objMaxPeakPointer->setCursorPosition(yMaxPosition);
    m_objMinPeakPointer->setCursorPosition(yMinPosition);

    if(ui->chk1ShowTrace->isChecked() == false)
    	m_objch1Item->setVisible(false);
    else
    	m_objch1Item->setVisible(true);
    if(ui->chk2ShowTrace->isChecked() == false)
    	m_objch2Item->setVisible(false);
    else
    	m_objch2Item->setVisible(true);

   m_bH1Cursor = true; m_bH2Cursor=true;
   on_butLEFT_clicked();

   // m_objTR10Pointer->setSoruceDestPoint(m_nV1CursorPosition,m_nV2CursorPosition);
   // qDebug()<<"Max Peak Position:"<<yMaxPosition<<"Min Peak Position:"<<yMinPosition;
    m_objDSOWaveSettings->convertToDecimation(m_objDSODataSettings->getVoltPerDivsion(CHANNEL_2),m_objDSODataSettings->getFSSettings(CHANNEL_2),m_objBoundaryRect.width()-(2*dsoMargin),R2FIFO,m_nSamples,pLstOdd,pLstEven);
    m_objch2Item->setPlotData(m_objDSOWaveSettings->getYVectorPoints(1));
    IGPIOEvent->BlockSig(false);
    IPTKeyEvent->BlockSig(false);
    if(ui->optNormal->isChecked()){
	IGPIOEvent->driveDSO(true);
	//ui->leStatus->setText("Ready");
	}
	if(ui->optAuto->isChecked()){
		IGPIOEvent->driveDSO(false);
		//ui->leStatus->setText("Ready");
	}
}


void MainWindow::InitializeHardwareLibs(){

        QPluginLoader backplane("libBackPlaneInterface.so",this);
        IBackPlane = qobject_cast<IntefaceBackPlane*>(backplane.instance());
        IBackPlane->InitializeBpObject();
        qDebug()<<"BackPlane initialized";

        QPluginLoader psoc("libPTPsocInterface2.so",this);
        IPsoc = qobject_cast<IPSOCCOMMUNICATION*>(psoc.instance());
        IPsoc->openSerial();
        qDebug()<<"PSoC initialized";

        // GPIO Events
        QPluginLoader loader3("libGPIOEventInterface.so",this);
        IGPIOEvent = qobject_cast<PTGPIOEventInterface*>(loader3.instance());
        m_nKeyCode=12;

        QPluginLoader loader6("libPTKeyEventInterfaces.so", this);
        IPTKeyEvent = qobject_cast<PTEventInterface*> (loader6.instance());
        IPTKeyEvent->InvokeGPIOEvent(this, "/dev/input/event2", "pt_kpp",&m_nPTKeyCode);


        hwInterface=new HardwareInterface();
        hwInterface->Init();

        IGPIOEvent->InvokeGPIOEvent(this, "/dev/input/event7", "gpioevent", &m_nKeyCode);
        IGPIOEvent->setApplicationID(DSO);
        connect(IGPIOEvent->getGPIOObject(),SIGNAL(postAPP(QList<unsigned char>,QList<unsigned char>)),this,SLOT(doIntPlot(QList<unsigned char>,QList<unsigned char>)));
     //   QMetaObject::invokeMethod(this,"doIntPlot(QList<unsigned char>,QList<unsigned char>))", Qt::DirectConnection);

        m_objDSOWaveSettings->disableInterrupt();
        m_objDSOWaveSettings->enableInterrupt();
        m_objDSOWaveSettings->ReceiverConfiguration();
        m_nPrecount=5;
        m_eReceConf = RECEIVER1;
        m_eTrigger = EDGE_RISING;
        m_objDSOWaveSettings->configureReceiverAndTrigger(m_eReceConf,m_eTrigger);
        m_eReceConf = RECEIVER2;
        m_eTrigger = EDGE_RISING;
        m_objDSOWaveSettings->configureReceiverAndTrigger(m_eReceConf,m_eTrigger);

        //IGPIOEvent->setFSSettings(m_nVoltPerDivision,m_objDSODataSettings->getFSSettings(CHANNEL1),m_nSamples,m_objBoundaryRect.width(),0);
//        m_objDSODataSettings->setFSSettings(0.731609,CHANNEL_1);
//        IGPIOEvent->setFSSettings(0.1,m_objDSODataSettings->getFSSettings(CHANNEL_1),1000,m_objBoundaryRect.width(),0);
//        m_objDSODataSettings->setFSSettings(0.731609,CHANNEL_2);
//        IGPIOEvent->setFSSettings(0.1,m_objDSODataSettings->getFSSettings(CHANNEL_2),1000,m_objBoundaryRect.width(),0);

        IGPIOEvent->setSamplingType(SAMPLING_TYPE(0));
        m_objDSOWaveSettings->setSamplingType(SAMPLING_TYPE(0));
        m_nTimePerSample = m_lstTimebaseValues.value(0);
        m_nV1TimebasePostion = 0.0;
        m_nV2TimebasePostion=0.0;
        m_nTimeUnitIndex = 2;
        IAppCard->writeRegister(0x7,0x34);
        IAppCard->writeRegister(0x41,0x36);
        IAppCard->writeRegister(0x1,0x38);
        m_nChannel1Value=1;m_nChannel2Value=1;
        on_cmbLMHVoltage_currentIndexChanged(2);
        m_nH2VoltagePostion =m_objDSODataSettings->getVoltPerDivsion(CHANNEL_1)*4.0;
        m_nH1VoltagePostion=m_objDSODataSettings->getVoltPerDivsion(CHANNEL_1)*4.0;

    	ui->lblX1Value->setText(QString::number(m_nH1VoltagePostion,'f',4));
    	ui->lblX2Value->setText(QString::number(m_nH2VoltagePostion,'f',4));

        updateValues();

        //on_pushButton_clicked();
        //on_butRUNSTOP_clicked();
        //connect(ui->butRUNSTOP,SIGNAL(clicked()),this,SLOT(on_butRUNSTOP_clicked()));

}


QList<QString> MainWindow::parseXML(QString pRootElement,QString pstrChildElement)
{
    QList<QString> l_lstValues;
    QString filePath = "./DSONavigation.xml";
    if (!filePath.isEmpty()) {
        QFile file(filePath);
        if (file.open(QIODevice::ReadOnly)) {
            QDomDocument domDocument;
           if (domDocument.setContent(&file))
            {
                QDomNodeList panelList = domDocument.elementsByTagName(pRootElement);
                QDomNodeList panel = panelList.at(0).firstChildElement(pstrChildElement).childNodes();
                 for(int l_nChildIndex=0;l_nChildIndex<panel.count();l_nChildIndex++)
                 {
                    // qDebug()<<"Panel:"<<panel.at(l_nChildIndex).toElement().attribute("DisplayValue");
                     l_lstValues.insert(l_nChildIndex,panel.at(l_nChildIndex).toElement().attribute("DisplayValue"));
                 }

            }
        }
    }
    return l_lstValues;
}

//void MainWindow::openFile()
//{
//    QString filePath = "/home/sountharya/DSOAppProjects/DSOApp1/DSONavigation.xml";
//
//    if (!filePath.isEmpty()) {
//        QFile file(filePath);
//        if (file.open(QIODevice::ReadOnly)) {
//            QDomDocument document;
//            if (document.setContent(&file)) {
//                DomModel *newModel = new DomModel(document, this);
//                //view->setModel(newModel);
//                delete model;
//                model = newModel;
//                //xmlPath = filePath;
//            }
//            file.close();
//        }
//    }
//
//}



void MainWindow::createDynamicSubItems()
{
    //m_objSubItems = QToolButton(ui->topFrame);
    signalMapper = new QSignalMapper(this);
    //QString l_strValue = "QPushButton { color:black; background-color:rgb(108,108,107);font:12px;border:0px solid #3a5976;    border-radius:0px;}";
    QString l_strValue ="QPushButton{ color:black;   	border:1px solid white; background-color: #dadbde;border-radius:0px;    	border-top:1px qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #f6f7fa, stop: 1 #dadbde); border-top-right-radius: 0px;    	 border-top-left-radius: 0px;    	border-top:1px solid gray;    	;border-bottom-right-radius: 0px;    	 border-bottom-left-radius: 0px;    	border-top:1px solid gray; border-top-right-radius: 0px;    	 border-top-left-radius: 0px;    	}";

    qDebug()<<"Dynamic Sub Items";
    int l_nXpos=0,l_nYPos=0;
    for(int l_nCreateIndex=0;l_nCreateIndex<6;l_nCreateIndex++)
    {
        m_objSubItems[l_nCreateIndex] = new QPushButton(ui->topFrame);
        m_objSubItems[l_nCreateIndex]->setGeometry(l_nXpos,l_nYPos,100,90);
        m_objSubItems[l_nCreateIndex]->setFocusPolicy(Qt::NoFocus);
        m_objSubItems[l_nCreateIndex]->setStyleSheet(l_strValue);
        //m_objSubItems[l_nCreateIndex]->setPalette(QColor(108,108,107));
        connect(m_objSubItems[l_nCreateIndex],SIGNAL(clicked()),signalMapper,SLOT(map()));
        signalMapper->setMapping(m_objSubItems[l_nCreateIndex],l_nCreateIndex);
        l_nYPos+=90;
    }
    connect(signalMapper,SIGNAL(mapped(int)),this,SLOT(doNavigation(int)));

}

void MainWindow::defaultSidePane(BASEWIDGET pBase,QString pRootItem,QString pNavigate)
{
    QString l_strRootItem = pRootItem;
    if(pBase == CHANNEL_1)
    {
        ui->rootItem->setText("CH1");
        ui->rootItem->setStyleSheet("QToolButton{color:black;background-color: rgb(255, 255, 0);border:0px solid #3a5976;border-radius:0px;}");
     //   l_strRootItem = "DSONavigation";
       // pNavigate = "Channel";
    }
    else if(pBase == CHANNEL_2)
    {
       ui->rootItem->setText("CH2");
       ui->rootItem->setStyleSheet("QToolButton{color:black;background-color: rgb(255, 0, 255);border:0px solid #3a5976;border-radius:0px;}");
       //l_strRootItem = "DSONavigation";
      // pNavigate = "Channel";
    }
    else if(pBase == TRIGGER)
    {
        ui->rootItem->setText("Trigger");
        ui->rootItem->setStyleSheet("QToolButton{color:white;background-color: rgb(108, 108, 107,255);border:0px solid #3a5976;border-radius:0px;}");

    }
    else if(pBase == DSONAVIGATION)
    {
        ui->rootItem->setText("Menu");
        ui->rootItem->setStyleSheet("QToolButton{color:white;background-color: rgb(108, 108, 107,255);border:0px solid #3a5976;border-radius:0px;}");
    }
    else if(pBase == CURSORS)
    {
        ui->rootItem->setText("Cursors");
        ui->rootItem->setStyleSheet("QToolButton{color:white;background-color: rgb(108, 108, 107,255);border:0px solid #3a5976;border-radius:0px;}");
    }
    else if(pBase == TIMEBASE)
    {
        ui->rootItem->setText("Timebase");
        ui->rootItem->setStyleSheet("QToolButton{color:white;background-color: rgb(108, 108, 107,255);border:0px solid #3a5976;border-radius:0px;}");
    }
    else if(pBase == MEASUREMENTS)
    {
        ui->rootItem->setText("Measure");
        ui->rootItem->setStyleSheet("QToolButton{color:white;background-color: rgb(108, 108, 107,255);border:0px solid #3a5976;border-radius:0px;}");
    }

    qDebug()<<"Root Item:"<<l_strRootItem<<"ChildItem:"<<pNavigate;
    m_strChildItem = pNavigate;
    QList<QString> l_lstSubItems;
    l_lstSubItems.clear();
    l_lstSubItems =parseXML(l_strRootItem,pNavigate);
    doFunction(pBase,pNavigate);
    if(l_lstSubItems.count()==0) return;
    clearCommandButtons();
    for(int l_nIndex=0;l_nIndex<5;l_nIndex++)
    {
        m_objSubItems[l_nIndex]->setText(l_lstSubItems.value(l_nIndex));
    }
    if(l_lstSubItems.count()<=5)
        m_objSubItems[5]->setText("Close");
    else
        m_objSubItems[5]->setText("Next");

}

void MainWindow::doFunction(BASEWIDGET pBase,QString pStrChild)
{
	qDebug()<<"Do Function";

	if(pBase == TIMEBASE)
	{
		if(pStrChild == "Mode")
		{
			m_bModeSelected = true;
		}
		if(pStrChild == "MaxMemory")
		{
			m_bMaxMemorySelected = true;
		}
		if(m_bMaxMemorySelected == true)
		{
			if(pStrChild == "500S")
			{
				m_nMaxRecordLength = 500;
			}
			else if(pStrChild == "1K")
			{
				m_nMaxRecordLength = 1000;
			}
			else if(pStrChild == "2K")
			{
				m_nMaxRecordLength = 2000;
			}
			else if(pStrChild == "5K")
			{
				m_nMaxRecordLength = 5000;
			}
			else if(pStrChild == "10K")
			{
				m_nMaxRecordLength = 10000;
			}
			updateValues();
		}
		if(m_bModeSelected == true)
		{
			if(pStrChild == "Normal")
			{
				m_objDSOWaveSettings->setSamplingType(SAMPLING_TYPE(0));
	            IGPIOEvent->setSamplingType(SAMPLING_TYPE(0));
				m_objch1Item->setSamplingType(SAMPLING_TYPE(0),m_nSamples);
				m_objch2Item->setSamplingType(SAMPLING_TYPE(0),m_nSamples);
			}
			if(pStrChild == "PeakDetect")
			{
				m_objDSOWaveSettings->setSamplingType(SAMPLING_TYPE(1));
	            IGPIOEvent->setSamplingType(SAMPLING_TYPE(1));
				m_objch1Item->setSamplingType(SAMPLING_TYPE(1),m_nSamples);
				m_objch2Item->setSamplingType(SAMPLING_TYPE(1),m_nSamples);

			}
			if(pStrChild == "HiRes")
			{
				m_objDSOWaveSettings->setSamplingType(SAMPLING_TYPE(2));
	            IGPIOEvent->setSamplingType(SAMPLING_TYPE(2));
				m_objch1Item->setSamplingType(SAMPLING_TYPE(2),m_nSamples);
				m_objch2Item->setSamplingType(SAMPLING_TYPE(2),m_nSamples);
			}
			if(pStrChild == "WaveMemory")
			{
				m_objDSOWaveSettings->setSamplingType(SAMPLING_TYPE(7));
	            IGPIOEvent->setSamplingType(SAMPLING_TYPE(7));
				m_objch1Item->setSamplingType(SAMPLING_TYPE(7),m_nSamples);
				m_objch2Item->setSamplingType(SAMPLING_TYPE(7),m_nSamples);
			}

		}
	}
	if(pBase == CURSORS)
	{
		if(pStrChild == "Time")
		{
			m_bTimeSelected = true;
			m_bAmpSelected = false;
			m_bV1Cursor=m_bV2Cursor = false;
		}
		if(pStrChild == "Amplitude")
		{
			m_bTimeSelected = false;
			m_bAmpSelected = true;
			m_bH1Cursor=m_bH2Cursor=false;
		}
		qDebug()<<"Time :"<<m_bTimeSelected<<"Cursor:"<<pStrChild;
		if(pStrChild == "Cursor1" && m_bTimeSelected == true)
		{
			m_bH1Cursor = true;
			m_bH2Cursor = false;

		}
		else if(pStrChild == "Cursor2" && m_bTimeSelected == true)
		{
			m_bH1Cursor = false;
			m_bH2Cursor = true;

		}
		else if(pStrChild == "TrackCursors" && m_bTimeSelected == true)
		{
			m_bH1Cursor = true;
			m_bH2Cursor = true;
		}
		else if(pStrChild == "ON/OFF" && m_bTimeSelected == true)
		{
			if(m_bShowH1 == true)
			{
				m_objDSOV1Cursor->setVisible(true);
				m_objDSOV2Cursor->setVisible(true);

				m_bShowH1 = false;
			}
			else if(m_bShowH1 == false)
			{
				m_objDSOV1Cursor->setVisible(false);
				m_objDSOV2Cursor->setVisible(false);

				m_bShowH1 = true;
			}
		}
		if(pStrChild == "Cursor1" && m_bAmpSelected == true)
		{
			m_bV1Cursor = true;
			m_bV2Cursor = false;

		}
		else if(pStrChild == "Cursor2" && m_bAmpSelected == true)
		{
			m_bV1Cursor = false;
			m_bV2Cursor = true;

		}
		else if(pStrChild == "TrackCursors" && m_bAmpSelected == true)
		{
			m_bV1Cursor = true;
			m_bV2Cursor = true;
		}
		else if(pStrChild == "ON/OFF" && m_bAmpSelected == true)
		{
			if(m_bShowV1 == true)
			{
				m_objDSOH2Cursor->setVisible(true);
				m_objDSOH1Cursor->setVisible(true);
				m_bShowV1 = false;
			}
			else if(m_bShowV1 == false)
			{
				m_objDSOH2Cursor->setVisible(false);
				m_objDSOH1Cursor->setVisible(false);

				m_bShowV1 = true;
			}
		}

	}
}

void MainWindow::clearCommandButtons()
{
    for(int l_nIndex=0;l_nIndex<6;l_nIndex++)
    {
        m_objSubItems[l_nIndex]->setText("");
    }
}

void MainWindow::doNavigation(int pCommandID)
{
    qDebug()<<"CommandID:"<<pCommandID<<"Command String:"<<m_objSubItems[pCommandID]->text();
    QString l_strValue = "QPushButton {color:white;border:1px solid white;background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #3a5976, stop: 1 #000000);border-radius:0px;border-bottom:1px qlineargradient(x1: 0, y1: 0,stop: 0 #f6f7fa, stop: 1 #dadbde);border-bottom-right-radius: 0px;border-bottom-left-radius: 0px;}";
    QString l_strValue1 ="QPushButton{ color:black;	border:1px solid white; background-color: #dadbde;border-radius:0px;    	border-top:1px qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #f6f7fa, stop: 1 #dadbde); border-top-right-radius: 0px;    	 border-top-left-radius: 0px;    	border-top:1px solid gray;    	;border-bottom-right-radius: 0px;    	 border-bottom-left-radius: 0px;    	border-top:1px solid gray; border-top-right-radius: 0px;    	 border-top-left-radius: 0px;    	}";

    for(int l_nCreateIndex=0;l_nCreateIndex<6;l_nCreateIndex++)
        {
    	if(pCommandID != l_nCreateIndex)
    		m_objSubItems[l_nCreateIndex]->setStyleSheet(l_strValue1);
    	else
    		 m_objSubItems[pCommandID]->setStyleSheet(l_strValue);
        }
    m_objSubItems[pCommandID]->setPalette(QColor(0,108,107));
    //m_objSubItems[pCommandID]->setStyleSheet(l_strValue);
    if(ui->rootItem->text() == "CH1")
    {
        if(m_objSubItems[pCommandID]->text() == "Close")
        {
            if(m_strChildItem !="Channel")
                defaultSidePane(CHANNEL_1,"DSONavigation","Channel");
            else
                 on_pushButton_clicked();
             
            return;
        }
        defaultSidePane(CHANNEL_1,"Channel",m_objSubItems[pCommandID]->text());
    }

    if(ui->rootItem->text() == "CH2")
    {
        if(m_objSubItems[pCommandID]->text() == "Close")
        {
            if(m_strChildItem !="Channel")
                defaultSidePane(CHANNEL_2,"DSONavigation","Channel");
            else
                 on_pushButton_clicked();
            return;
        }

        defaultSidePane(CHANNEL_2,"Channel",m_objSubItems[pCommandID]->text());
    }
    if(ui->rootItem->text() == "Trigger")
    {
        if(m_objSubItems[pCommandID]->text() == "Close")
        {
            if(m_strChildItem !="Trigger")
                defaultSidePane(TRIGGER,"DSONavigation","Trigger");
            else
                 on_pushButton_clicked();
            return;
        }

        defaultSidePane(TRIGGER,"Trigger",m_objSubItems[pCommandID]->text());
    }
    if(ui->rootItem->text() == "Cursors")
    {
        if(m_objSubItems[pCommandID]->text() == "Close")
        {
            if(m_strChildItem !="Cursors")
                defaultSidePane(CURSORS,"DSONavigation","Cursors");
            else
                 on_pushButton_clicked();
            return;
        }
        defaultSidePane(CURSORS,"Cursors",m_objSubItems[pCommandID]->text());
    }
    if(ui->rootItem->text() == "Timebase")
    {
        if(m_objSubItems[pCommandID]->text() == "Close")
        {
            if(m_strChildItem !="Timebase")
                defaultSidePane(TIMEBASE,"DSONavigation","Timebase");
            else
                 on_pushButton_clicked();
            return;
        }
        defaultSidePane(TIMEBASE,"Timebase",m_objSubItems[pCommandID]->text());
    }
    if(ui->rootItem->text() == "Measure")
    {
        if(m_objSubItems[pCommandID]->text() == "Close")
        {
            if(m_strChildItem !="Measurements")
                defaultSidePane(MEASUREMENTS,"DSONavigation","Measurements");
            else
                 on_pushButton_clicked();
            return;
        }
        if(m_strChildItem =="MeasureItem")
        {
            defaultSidePane(MEASUREMENTS,"MeasureItem",m_objSubItems[pCommandID]->text());
            return;
        }
        if(m_objSubItems[pCommandID]->text() == "Next")
        {

        }

        defaultSidePane(MEASUREMENTS,"Measurements",m_objSubItems[pCommandID]->text());
    }

    if(ui->rootItem->text() == "Menu")
    {
        if(m_objSubItems[pCommandID]->text() == "Close")
        {
            ui->topFrame->setVisible(false);
            ui->rootItem->setVisible(false);
            return;
        }
        if(m_objSubItems[pCommandID]->text() == "Trigger")
        {
            ui->rootItem->setText("Trigger");
            defaultSidePane(TRIGGER,"DSONavigation","Trigger");

        }
        if(m_objSubItems[pCommandID]->text() == "Channel")
        {
            ui->rootItem->setText("CH1");
            defaultSidePane(CHANNEL_1,"DSONavigation","Channel");
        }
        if(m_objSubItems[pCommandID]->text() == "Cursors")
        {
            ui->rootItem->setText("Cursors");
            defaultSidePane(CURSORS,"DSONavigation","Cursors");
        }
        if(m_objSubItems[pCommandID]->text() == "Timebase")
        {
            ui->rootItem->setText("Timebase");
            defaultSidePane(TIMEBASE,"DSONavigation","Timebase");
        }
        if(m_objSubItems[pCommandID]->text() == "Measure")
        {
            ui->rootItem->setText("Measure");
            defaultSidePane(MEASUREMENTS,"DSONavigation","Measurements");
        }

    }
}

void MainWindow::initChannelWidget()
{
    channel1Widget =new ChannelItemWidget(gStrDnCH1Widget,CHANNEL_1,this);
    channel2Widget = new ChannelItemWidget(gStrDnCH2Widget,CHANNEL_2,this);
    timeBaseWidget = new ChannelItemWidget(gStrDnTriggerWidget,TIMEBASE,this);
    triggerWidget = new ChannelItemWidget(gStrDnTriggerWidget,TRIGGER,this);
    cursorsWidget = new ChannelItemWidget(gStrDnTriggerWidget,CURSORS,this);
    channel1Widget->setGeometry(7,520,115,80);
    channel2Widget->setGeometry(130,520,115,80);
    timeBaseWidget ->setGeometry(450,510,115,90);
    triggerWidget->setGeometry(570,520,116,72);
    cursorsWidget->setGeometry(260,520,171,72);
    connect(channel1Widget,SIGNAL(clicked(BASEWIDGET)),this,SLOT(changeChannel1Widget(BASEWIDGET)));
    connect(channel2Widget,SIGNAL(clicked(BASEWIDGET)),this,SLOT(changeChannel2Widget(BASEWIDGET)));
    connect(timeBaseWidget,SIGNAL(clicked(BASEWIDGET)),this,SLOT(changeTimeBaseWidget(BASEWIDGET)));
    connect(triggerWidget,SIGNAL(clicked(BASEWIDGET)),this,SLOT(changeTriggerWidget(BASEWIDGET)));
    connect(cursorsWidget,SIGNAL(clicked(BASEWIDGET)),this,SLOT(changeCursorsWidget(BASEWIDGET)));

    ui->CH1widget->setVisible(false);
    ui->ch2Widget->setVisible(false);
    ui->TriggerWidget->setVisible(false);
    ui->Timebase->setVisible(false);
    ui->Cursors->setVisible(false);

    //channel 1 Settings
    ui->channel1No->setParent(channel1Widget);
    ui->channel1No->setGeometry(6,6,101,21);
    ui->ch1Coupling->setParent(channel1Widget);
    ui->ch1Coupling->setGeometry(51,9,51,16);
    ui->ch1labelVpD->setParent(channel1Widget);
    ui->ch1labelVpD->setGeometry(55,30,51,19);
    ui->ch1VperDiv->setParent(channel1Widget);
    ui->ch1VperDiv->setGeometry(12,30,40,19);
    ui->ch1lblOffset->setParent(channel1Widget);
    ui->ch1lblOffset->setGeometry(55,48,51,19);
    ui->ch1Voffset->setParent(channel1Widget);
    ui->ch1Voffset->setGeometry(12,50,28,16);
    ui->lblCH1DelX->setParent(channel1Widget);
    ui->lblCH1DelX->setGeometry(6,61,41,19);
    ui->lblCH1DelValue->setParent(channel1Widget);
    ui->lblCH1DelValue->setGeometry(46,63,61,20);


    //channel 2 Settings
    ui->channel2No->setParent(channel2Widget);
    ui->channel2No->setGeometry(6,6,101,21);
    ui->ch2Coupling->setParent(channel2Widget);
    ui->ch2Coupling->setGeometry(51,10,51,16);
    ui->ch2labelVpD->setParent(channel2Widget);
    ui->ch2labelVpD->setGeometry(51,30,51,19);
    ui->ch2VperDiv->setParent(channel2Widget);
    ui->ch2VperDiv->setGeometry(12,28,40,19);
    ui->ch2lblOffset->setParent(channel2Widget);
    ui->ch2lblOffset->setGeometry(55,48,51,19);
    ui->ch2Voffset->setParent(channel2Widget);
    ui->ch2Voffset->setGeometry(12,50,28,16);
    ui->lblCH2DelX->setParent(channel2Widget);
    ui->lblCH2DelX->setGeometry(6,61,41,19);
    ui->lblCH2DelValue->setParent(channel2Widget);
    ui->lblCH2DelValue->setGeometry(46,63,61,20);

    channel1Widget->modifyStyleSheet(true,CHANNEL_1);


    //trigger Widget
    ui->TriggerTitle->setParent(triggerWidget);
    ui->TriggerTitle->setGeometry(6,6,101,21);
    ui->lblHorTValue->setParent(triggerWidget);
    ui->lblHorTValue->setGeometry(50,30,61,20);
    ui->lblHort->setParent(triggerWidget);
    ui->lblHort->setGeometry(6,30,51,20);
    ui->lblVertT->setParent(triggerWidget);
    ui->lblVertT->setGeometry(6,50,51,20);
    ui->lblVertTValue->setParent(triggerWidget);
    ui->lblVertTValue->setGeometry(50,50,61,20);
    //
    ui->TimebaseTitle->setParent(timeBaseWidget);
    ui->TimebaseTitle->setGeometry(6,6,101,21);

	ui->labelTimePerDiv->setParent(timeBaseWidget);
	ui->labelTimePerDiv->setGeometry(6,30,101,20);

	ui->lblMemory->setParent(timeBaseWidget);
	ui->lblMemory->setGeometry(8,50,80,20);
	ui->lblSamplingRate->setParent(timeBaseWidget);
	ui->lblSamplingRate->setGeometry(6,68,80,20);
	//ui->lblDelY->setParent(timeBaseWidget);
	//ui->lblDelY->setGeometry(6,50,40,20);
	//ui->lblDelYValue->setParent(timeBaseWidget);
	//ui->lblDelYValue->setGeometry(48,48,60,20);

	ui->cursorsTitle->setParent(cursorsWidget);
	ui->cursorsTitle->setGeometry(6,6,160,20);

	ui->lblX1->setParent(cursorsWidget);
	ui->lblX1->setGeometry(6,30,20,19);
	ui->lblX1Value->setParent(cursorsWidget);
	ui->lblX1Value->setGeometry(30,30,51,20);

	ui->lblX2->setParent(cursorsWidget);
	ui->lblX2->setGeometry(90,30,20,19);
	ui->lblX2Value->setParent(cursorsWidget);
	ui->lblX2Value->setGeometry(99,30,51,20);

	ui->lblY1->setParent(cursorsWidget);
	ui->lblY1->setGeometry(6, 50,21,19);
	ui->lblY1Value->setParent(cursorsWidget);
	ui->lblY1Value->setGeometry(32,50,51,20);

	ui->lblY2->setParent(cursorsWidget);
	ui->lblY2->setGeometry(90,50,21,19);
	ui->lblY2Value->setParent(cursorsWidget);
	ui->lblY2Value->setGeometry(99,49,51,20);

    // Dial Widget
    //m_objDialWidget = new dialWidget(ui->dialFrame);
//    m_objVoltageDial = new PotentioMeter(ui->grpVoltDiv);
//    m_objVoltageDial->setRotationRange(9);
//    m_objVoltageDial->setRange(0,9);
//    m_objVoltageDial->setGeometry(15,25,140,140);

   // m_objTimeDial = new PotentioMeter(ui->grpTimeDiv);
   // m_objTimeDial->setRotationRange(30);
   // m_objTimeDial->setRange(0,30);
   // m_objTimeDial->setGeometry(15,25,140,140);

    qDebug()<<"1";

	ui->VoltageDialWheel->setSingleStep(10);
	ui->VoltageDialWheel->setParent(ui->grpVoltDiv);
	ui->VoltageDialWheel->setSliderPosition(2);
    ui->timebaseDialWheel->setParent(ui->grpTimeDiv);
    ui->timebaseDialWheel->setSliderPosition(19);

    ui->dblHorizontalTrigger->setSingleStep(0.0);
    ui->dblVerticalTrigger->setSingleStep(0.0);

    //m_objTimeDial->setValue(19);
   // incrementTimeDial();

    ui->grpTimeDiv->setVisible(false);
    ui->grpVoltDiv->setVisible(false);
    ui->grpTriggers->setVisible(false);
    ui->grpCursors->setVisible(false);
    initialiseDSODataSet();

}

void MainWindow::initialiseDSODataSet()
{
    m_objDSODataSettings = new DSODataSettings();
    m_nMaxRecordLength = 10000;
    m_nSampleIndex=9;
    m_nSampleUnit=0;

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
    m_nSystemFrequency=400000000;
    m_objDSODataSettings->setTimePerDivision(1,MILLISECONDS,CHANNEL_1);
    m_objDSODataSettings->setTimePerDivision(1,MILLISECONDS,CHANNEL_2);
    m_objDSODataSettings->setMaxRecordLength(m_nMaxRecordLength,0);
    m_objDSODataSettings->setMaximumSampleRate(m_nSampleRate[m_nSampleIndex],MEGAS);
    m_objDSODataSettings->setVoltPerDivision(m_objDSODataSettings->getVoltPerDivsion(CHANNEL_1),CHANNEL_1);
    m_objDSODataSettings->setVoltPerDivision(m_objDSODataSettings->getVoltPerDivsion(CHANNEL_1),CHANNEL_2);
    initializeTimeBaseList();
    //initializeMemoryList();
    initializeVoltageList();
    m_bRUNFlag = true;
    m_nCH1VoltIndex = m_nCH1VoltIndex =0;
    m_bShowH1 = m_bShowV1 =false;
    m_bCH1TriggerSource = true;
    m_bCH2TriggerSource = false;
    m_bCH1Offset = true;
    m_bCH2Offset = false;

    //on_timebaseDial_sliderMoved(19);
    //on_memoryDial_sliderMoved(2);
//    ui->timebaseDial->setSingleStep(19);
//    ui->memoryDial->setSingleStep(2);

//     m_objVoltageDial->setSingleStep(19);
//     m_objTimeDial->setSingleStep(19);

     connect(ui->VoltageDialWheel,SIGNAL(sliderMoved(int)),this,SLOT(on_VoltageDialWheel_sliderMoved(int)));
     connect(ui->timebaseDialWheel,SIGNAL(sliderMoved(int)),this,SLOT(on_timebaseDialWheel_sliderMoved(int)));
     connect(ui->triggerWheel,SIGNAL(sliderMoved(int)),this,SLOT(on_triggerWheel_sliderMoved(int)));
     qDebug()<<"End DSO Data Widget";
//	connect(m_objVoltageDial,SIGNAL(valueInc()),this,SLOT(incrementVoltageDial()));
//	connect(m_objVoltageDial,SIGNAL(valueDec()),this,SLOT(decrementVoltageDial()));

	//connect(m_objTimeDial,SIGNAL(valueInc()),this,SLOT(incrementTimeDial()));
//	connect(m_objTimeDial,SIGNAL(valueDec()),this,SLOT(decrementTimeDial()));
//    m_objTimeDial->setValue(19);
   // m_objVoltageDial->setValue(2);
    //incrementTimeDial();

}

void MainWindow::InitializeTriggers()
{
    BASEWIDGET l_nChannel = (m_nChannel1Value==1)?CHANNEL_1:CHANNEL_2;
    double l_nMidTimeBase = (m_objDSODataSettings->getTimePerDivision(l_nChannel) * 10.0)/2.0;
    double l_nMidVoltage=0.0,l_nActVoltage=0.0;
	l_nMidVoltage = (m_objDSODataSettings->getVoltPerDivsion(l_nChannel)*8.0)/2.0;
	l_nActVoltage = m_objDSODataSettings->getVoltPerDivsion(l_nChannel);
   // qDebug()<<"Mid Voltage:"<<l_nMidVoltage<<"VoltageTriggerPoint:"<<m_nVoltageTriggerPoint;
    //qDebug()<<"Mid Time Base:"<<l_nMidTimeBase<<m_nTimebaseTriggerPoint;
    if(m_nTimebaseTriggerPoint >0)
        m_nAcutalTriggertimeBase = l_nMidTimeBase - m_nTimebaseTriggerPoint;
    else if(m_nTimebaseTriggerPoint <0)
        m_nAcutalTriggertimeBase = l_nMidTimeBase + (-m_nTimebaseTriggerPoint);
   // qDebug()<<"Rect Height:"<<IDSODisplay->getRectHeight();
  //  qDebug()<<"Rect Width:"<<IDSODisplay->getRectWidth();
    double l_nVTPosition = -((m_objBoundaryRect.height()-(2*dsoMargin))/8.0)*(m_nVoltageTriggerPoint/(l_nActVoltage));
    double l_nHTPosition  = -((m_objBoundaryRect.width()-(2*dsoMargin))/10.0)*(m_nTimebaseTriggerPoint/(m_objDSODataSettings->getTimePerDivision(l_nChannel)));
    //if(ui->dblHorizontalTrigger->value() >0) l_nHTPosition +=dsoMargin; else l_nHTPosition -=dsoMargin;
    m_objHorizontalTrigger->setTriggerPostion(l_nHTPosition);
    m_objVerticalTrigger->setTriggerPostion(l_nVTPosition);
   // qDebug()<<"Trigger Info----------------------------------------------------------------------------";
   // qDebug()<<"Actual Trigger Point"<<m_nAcutalTriggertimeBase;
   // qDebug()<<"Voltage Per Division:"<<m_nVoltPerDivision<<"Voltage Trigger Pos:"<<m_nVoltageTriggerPoint;
   // qDebug()<<"Timer Per Division:"<<IDSODisplay->getTimePerDivision()<<"Time Trigger Pos:"<<m_nTimebaseTriggerPoint;
  //  qDebug()<<"Vertical Trigger Position:"<<l_nVTPosition<<"Horizontal Trigger Position:"<<l_nHTPosition;
   // qDebug()<<"----------------------------------------------------------------------------------------";
    //m_objDSODataSettings->moveHorizontalTriggerPointer(l_nHTPosition);
   // qDebug()<<"HT COunt:"<<IDSODisplay->getRectWidth()/l_nHTPosition;
   // m_objDSODataSettings->moveVerticalTriggerPointer(l_nVTPosition);

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
    if(m_nChannel1Value == 1)
        hwInterface->setDAC(DACB,l_nDACOffset); // CH1 Trigger - DAC
    else if (m_nChannel2Value==2)
        hwInterface->setDAC(DACD,l_nDACOffset); // CH2 Trigger - DAC
    else
        hwInterface->setDAC(DACE,l_nDACOffset); // EXT  Trigger - DAC
}

void MainWindow::updateValues()
{
        double l_nHTValue = -(ui->dblHorizontalTrigger->value());
        BASEWIDGET l_nChannel = (m_nChannel1Value==1)?CHANNEL_1:CHANNEL_2;
        if(m_nTimeUnitIndex ==0)
        {

                m_objDSODataSettings->setTimePerDivision(m_nTimePerSample,NANOSECONDS,l_nChannel);
                 m_nTimebaseTriggerPoint = l_nHTValue*(1/1000000000.0);
        }
        else if(m_nTimeUnitIndex ==2)
        {
                m_objDSODataSettings->setTimePerDivision(m_nTimePerSample,MILLISECONDS,l_nChannel);
                m_nTimebaseTriggerPoint = l_nHTValue*(1/1000.0);
        }
        else if(m_nTimeUnitIndex ==1)
        {
                m_objDSODataSettings->setTimePerDivision(m_nTimePerSample,MICROSECONDS,l_nChannel);
                 m_nTimebaseTriggerPoint = l_nHTValue*(1/1000000.0);
        }
        else if(m_nTimeUnitIndex ==3)
        {
                m_objDSODataSettings->setTimePerDivision(m_nTimePerSample,SECONDS,l_nChannel);
                 m_nTimebaseTriggerPoint = l_nHTValue*(1/1.0);
        }

        m_objDSODataSettings->calculateAcquisitionTime(l_nChannel);
        m_nVoltPerDivision=m_objDSODataSettings->getVoltPerDivsion(l_nChannel);
      	m_nVoltageTriggerPoint = ui->dblVerticalTrigger->value();
      	ui->lblHorTValue->setText(QString::number(-(l_nHTValue),'f',2));
      	ui->lblVertTValue->setText(QString::number(m_nVoltageTriggerPoint,'f',2));
//	qDebug()<<"Voltage Trigger Point:"<<m_nVoltageTriggerPoint;
         double l_nAcutualLength = m_objDSODataSettings->calculateRecordLength();
         qDebug()<<"-----Acutal Record Length-----:"<<l_nAcutualLength<<"Max Length:"<<m_nMaxRecordLength;
         double l_nSampleRate=0.0;
         unsigned int l_nRecordLength = 0;
         if(l_nAcutualLength <= m_nMaxRecordLength)
         {
            //	qDebug()<<"Inside Max Memory";
                l_nRecordLength = l_nAcutualLength;
                m_nSamples = l_nAcutualLength;
                l_nSampleRate = m_objDSODataSettings->getMaximumSampleRate();
                if(l_nSampleRate >500000000.0)
                {
                        l_nSampleRate = 500000000.0;
                        m_objDSODataSettings->setMaximumSampleRate(500,MEGAS);
                }
            }
            else
            {
           // 	qDebug()<<"Greater than Max Memory";
                l_nRecordLength = validateSampleRate();
                l_nSampleRate = m_objDSODataSettings->getMaximumSampleRate();
                m_nSamples = l_nRecordLength;
            }

            //~~~~~~~~~~~~~~~~added by RRV~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
            m_nOutputFrequency=l_nSampleRate;

        m_nFTW=pow(2,32)*((m_nOutputFrequency)/m_nSystemFrequency);
        qDebug()<<hex<<"FTW:"<<m_nFTW<<m_nOutputFrequency<<m_nSystemFrequency;
        if(m_nFTW==0xFFFFFFFF)
        {
        	ui->lblSysFreqValue->setText("OverFlow");
           return;
        }
	    ui->lblSamplingRate->setText(QString::number(l_nSampleRate,'f',2));

                //ui->leBDR->setText(QString::number(m_nFTW,16));
        		ui->lblSysFreqValue->setText(QString::number(m_nFTW,16));
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
		double l_nSamplesperPixel = (double)floor((double)m_nSamples/(double)m_objBoundaryRect.width() - (2*dsoMargin));

        unsigned int l_nTriggerSamples= l_nSamplesperPixel * (double)m_objBoundaryRect.width() - (2*dsoMargin);
//    		if(ui->cmbSamplingType->currentIndex() ==0 )
//    			l_nTriggerSamples=IDSODisplay->getRectWidth();


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
            if(m_eChannelSelected == CHANNEL_1)
            	IGPIOEvent->setFSSettings(m_objDSODataSettings->getVoltPerDivsion(CHANNEL_1),m_objDSODataSettings->getFSSettings(l_nChannel),m_nSamples,m_objBoundaryRect.width()-(2*dsoMargin),0);
            else
            	IGPIOEvent->setFSSettings(m_objDSODataSettings->getVoltPerDivsion(CHANNEL_1),m_objDSODataSettings->getFSSettings(l_nChannel),m_nSamples,m_objBoundaryRect.width()-(2*dsoMargin),1);
            qDebug()<<m_nPrecount<<m_nSamples<<l_nPreSamples;

            m_objDSOWaveSettings->setPreSampleCount(m_nPrecount);
            m_objDSOWaveSettings->setPostSampleCount((m_nSamples-l_nPreSamples));
            m_objDSODataSettings->setSamplesCount(m_nPrecount,(m_nSamples-l_nPreSamples),SAMPLING_TYPE(0));
			m_objch1Item->setSamples(m_nSamples);
			m_objch2Item->setSamples(m_nSamples);
		    m_objDSOWaveSettings->convertToDecimation(m_objDSODataSettings->getVoltPerDivsion(CHANNEL_1),m_objDSODataSettings->getFSSettings(CHANNEL_1),m_objBoundaryRect.width()-(2*dsoMargin),R1FIFO,m_nSamples,mLstOdd,mLstEven);
		    m_objch1Item->setPlotData(m_objDSOWaveSettings->getYVectorPoints(0));
		    m_objDSOWaveSettings->convertToDecimation(m_objDSODataSettings->getVoltPerDivsion(CHANNEL_2),m_objDSODataSettings->getFSSettings(CHANNEL_2),m_objBoundaryRect.width()-(2*dsoMargin),R2FIFO,m_nSamples,mLstOdd,mLstEven);
		    m_objch2Item->setPlotData(m_objDSOWaveSettings->getYVectorPoints(1));
		    ui->lblMemory->setText(QString::number(l_nRecordLength,10)+ " Samps");

}


unsigned int MainWindow::validateSampleRate()
{
       BASEWIDGET l_nChannel = (m_nChannel1Value==1)?CHANNEL_1:CHANNEL_2;
        for(int l_nSampleUnit=0;l_nSampleUnit<3;l_nSampleUnit++)
        {
                for(int l_nSampleIndex=m_nSampleIndex-1;l_nSampleIndex>=0;l_nSampleIndex--)
                {
                if(l_nSampleUnit==0)
                        m_objDSODataSettings->setMaximumSampleRate(m_nSampleRate[l_nSampleIndex],MEGAS);
                else if(l_nSampleUnit==1)
                        m_objDSODataSettings->setMaximumSampleRate(m_nSampleRate[l_nSampleIndex],KILOS);
                else if(l_nSampleUnit==2)
                        m_objDSODataSettings->setMaximumSampleRate(m_nSampleRate[l_nSampleIndex],ONES);
                m_objDSODataSettings->calculateAcquisitionTime(l_nChannel);
                double l_nAcutualLength = m_objDSODataSettings->calculateRecordLength();
                 //qDebug()<<"-----Acutal Record Length-----:"<<l_nAcutualLength<<"Max Length:"<<m_nMaxRecordLength;
                if(l_nAcutualLength < m_nMaxRecordLength)
                        return l_nAcutualLength;
                }
        }
        return 0;
}

void MainWindow::incrementVoltageDial()
{
    double value = m_objVoltageDial->value();
    double l_nValue = m_objVoltageDial->value() / 9.0;
 //   short l_nVoltageBaseValueCounter=0;

    qDebug()<<"Increment Voltage Counter:"<<value<<l_nValue<<m_lstVoltageValues.value(value);
    //on_cmbLMHVoltage_currentIndexChanged(value);
}

void MainWindow::decrementVoltageDial()
{
    double value = m_objVoltageDial->value();
    double l_nValue = m_objVoltageDial->value() / 9.0;
    //short l_nVoltageBaseValueCounter=0;

    qDebug()<<"Decrement Voltage Counter:"<<value<<l_nValue<<m_lstVoltageValues.value(value);
    //on_cmbLMHVoltage_currentIndexChanged(value);
}


void MainWindow::incrementTimeDial()
{
    double value = m_objTimeDial->value();
    double l_nValue = m_objTimeDial->value() / 9.0;
    short l_nTimeBaseValueCounter=0;
    short l_nUnitValue=0;
    if(l_nValue>0 && l_nValue <=1)
    {
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
    m_nTimePerSample = m_lstTimebaseValues.value(l_nTimeBaseValueCounter);
    m_nTimeUnitIndex = l_nUnitValue;
    m_objDSODataSettings->setMaximumSampleRate(m_nSampleRate[9],MEGAS);
    updateValues();
    ui->labelTimePerDiv->setText(QString::number(m_lstTimebaseValues.value(l_nTimeBaseValueCounter),'f',2)+" "+ m_lstTimebaseUnit.value(l_nUnitValue)+" /div");
    qDebug()<<"Timebase Value:"<<QString::number(m_lstTimebaseValues.value(l_nTimeBaseValueCounter),'f',2)+m_lstTimebaseUnit.value(l_nUnitValue);

}

void MainWindow::decrementTimeDial()
{
    double value = m_objTimeDial->value();
    double l_nValue = m_objTimeDial->value() / 9.0;
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
    m_nTimePerSample = m_lstTimebaseValues.value(l_nTimeBaseValueCounter);
    m_nTimeUnitIndex = l_nUnitValue;
    m_objDSODataSettings->setMaximumSampleRate(m_nSampleRate[9],MEGAS);
    updateValues();
    ui->labelTimePerDiv->setText(QString::number(m_lstTimebaseValues.value(l_nTimeBaseValueCounter),'f',2)+" "+ m_lstTimebaseUnit.value(l_nUnitValue)+" /div");
    qDebug()<<"Timebase Value:"<<QString::number(m_lstTimebaseValues.value(l_nTimeBaseValueCounter),'f',2)+m_lstTimebaseUnit.value(l_nUnitValue);
}


void MainWindow::checkTimeDial()
{
}

//void MainWindow::on_memoryDial_sliderMoved(int position)
//{
//
//}

void MainWindow::on_triggerWheel_sliderMoved(int value)
{
	//if(ui->optHorTrigger->isChecked())
	//	qDebug()<<"Horizontal Trigger Value:"<<value<<"Time Per Div:"<<m_nTimePerSample;
//	updateValues();
}

void MainWindow::on_dblHorizontalTrigger_valueChanged(double value)
{
	updateValues();
}

void MainWindow::on_dblVerticalTrigger_valueChanged(double pValue)
{
	updateValues();
}
void MainWindow::on_timebaseDialWheel_sliderMoved(int value)
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
    m_nTimePerSample = m_lstTimebaseValues.value(l_nTimeBaseValueCounter);
    m_nV1TimebasePostion = m_nTimePerSample/10.0;
    m_nTimeUnitIndex = l_nUnitValue;
    m_objDSODataSettings->setMaximumSampleRate(m_nSampleRate[9],MEGAS);
	ui->dblHorizontalTrigger->setMaximum(m_nTimePerSample*5);
	ui->dblHorizontalTrigger->setMinimum(m_nTimePerSample*-5);
	ui->dblHorizontalTrigger->setSingleStep(m_nTimePerSample/10.0);
    updateValues();
    ui->labelTimePerDiv->setText(QString::number(m_lstTimebaseValues.value(l_nTimeBaseValueCounter),'f',2)+" "+ m_lstTimebaseUnit.value(l_nUnitValue)+" /div");
    ui->chTperDiv->setText(QString::number(m_lstTimebaseValues.value(l_nTimeBaseValueCounter),'f',2)+" "+ m_lstTimebaseUnit.value(l_nUnitValue)+" /div");

    //qDebug()<<"Timebase Value:"<<QString::number(m_lstTimebaseValues.value(l_nTimeBaseValueCounter),'f',2)+m_lstTimebaseUnit.value(l_nUnitValue);
}

void MainWindow::on_VoltageDialWheel_sliderMoved(int value)
{
    m_nVoltPerDivision = m_lstVoltageValues.value(value-1);
    qDebug()<<"VoltPerDivision:"<<m_nVoltPerDivision<<value;

    on_cmbLMHVoltage_currentIndexChanged(value-1);
}

void MainWindow::initializeVoltageList()
{
    m_lstVoltageValues.insert(0,0.02);m_lstVoltageValues.insert(1,0.05);
    m_lstVoltageValues.insert(2,0.1);m_lstVoltageValues.insert(3,0.2);
    m_lstVoltageValues.insert(4,0.5);m_lstVoltageValues.insert(5,1.0);
    m_lstVoltageValues.insert(6,2.0);m_lstVoltageValues.insert(7,5.0);
    m_lstVoltageValues.insert(8,10.0);
}

void MainWindow::initializeMemoryList()
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

void MainWindow::initializeTimeBaseList()
{
    m_lstTimebaseValues.insert(0,1);m_lstTimebaseValues.insert(1,2);
    m_lstTimebaseValues.insert(2,5);m_lstTimebaseValues.insert(3,10);
    m_lstTimebaseValues.insert(4,20);m_lstTimebaseValues.insert(5,50);
    m_lstTimebaseValues.insert(6,100);m_lstTimebaseValues.insert(7,200);
    m_lstTimebaseValues.insert(8,500);


    m_lstTimebaseUnit.insert(0,"nS");m_lstTimebaseUnit.insert(1,"uS");
    m_lstTimebaseUnit.insert(2,"mS");m_lstTimebaseUnit.insert(3,"S");


}

void MainWindow::initialiseDSOGraphicsItems()
{
    m_objBoundaryRect.setX(0);
    m_objBoundaryRect.setY(0);
    m_objBoundaryRect.setHeight(460);
    m_objBoundaryRect.setWidth(700);

    m_objCh1PlotSettings = new PlotXYSettings(0.0,0.0000001,10.0,8.0,0.0,-0.5,0.5);
    m_objCh2PlotSettings = new PlotXYSettings(0.0,0.0000001,10.0,8.0,0.0,-0.5,0.5);
    m_objDSOview = new QGraphicsView(ui->DSODisplayWidget);
    //m_objDSOview->setDragMode(QGraphicsView::RubberBandDrag);
    m_objDSOview->setOptimizationFlags(QGraphicsView::DontSavePainterState);
    m_objDSOview->setViewportUpdateMode(QGraphicsView::SmartViewportUpdate);
    m_objDSOview->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_objDSOview->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_objDSOview->setRenderHints(QPainter::SmoothPixmapTransform);
    m_objDSOview->setFrameStyle(QFrame::NoFrame);

    m_objDSOview->setGeometry(m_objBoundaryRect.x(),m_objBoundaryRect.y(),m_objBoundaryRect.width(),m_objBoundaryRect.height());
    m_objDSOscene = new QGraphicsScene();
    m_objDSOview->setScene(m_objDSOscene);
    m_objDSOview->setBackgroundBrush(QBrush(QColor(0,0,0,255),Qt::SolidPattern));
    QColor color(Qt::white);
    m_objDSOXYGridItem = new DSOXYPlane(color, 0, 0);
    m_objDSOXYGridItem->setBorderRect(m_objBoundaryRect);
    m_objDSOXYGridItem->setPlotSettings(m_objCh1PlotSettings);
    m_objDSOXYGridItem->setEnabled(false);
    m_objDSOscene->addItem(m_objDSOXYGridItem);

    // Horizontal Cursor Item Initialization
    m_nV1CursorPosition =0.0;
    m_nV2CursorPosition = 10.0;

    m_nH1CursorPosition =0.0;
    m_nH2CursorPosition =10.0;

    m_nV1TimebasePostion =0.0;

    m_nV1dxFactor = (m_objBoundaryRect.width()-(2*dsoMargin))/100.0;
    m_nV2dxFactor = (m_objBoundaryRect.width()-(2*dsoMargin))/100.0;
    m_nV2CursorPosition = m_nV2dxFactor;

    m_nH1dxFactor = (m_objBoundaryRect.height()-(2*dsoMargin))/80.0;
    m_nH2dxFactor = (m_objBoundaryRect.height()-(2*dsoMargin))/80.0;
    m_nH2CursorPosition = m_nH2dxFactor;

    m_objMaxPeakPointer = new HCursorItem(QColor(108,108,107,255),0,0);
    m_objMinPeakPointer = new HCursorItem(QColor(108,108,107,255),0,0);
    m_objTR10Pointer = new LineItem(QColor(108,108,107,255),0,0);


    QVector<qreal>l_dashes,l_Vdashes,l_peakDashes;
    l_peakDashes << 1<<1;


    m_objDSOH1Cursor = new HCursorItem(color, 0, 0);
    m_objDSOH1Cursor->setBorderRect(m_objBoundaryRect);
    m_objDSOH1Cursor->setCursorPosition(m_nH1CursorPosition);


    qreal space = 6;
     l_dashes << 20 << space ;

    m_objDSOH1Cursor->changeDashes(l_dashes);
    m_objDSOscene->addItem(m_objDSOH1Cursor);
    l_dashes.clear();
    m_objDSOH2Cursor = new HCursorItem(color, 0, 0);
    m_objDSOH2Cursor->setBorderRect(m_objBoundaryRect);
    m_objDSOH2Cursor->setCursorPosition(m_nH2CursorPosition);
    l_dashes << 10<<space;
    m_objDSOH2Cursor->changeDashes(l_dashes);
    m_objDSOscene->addItem(m_objDSOH2Cursor);
    //---------------------------------------------
    // Vertical Cursor Item Initialization
    m_objDSOV1Cursor = new VCursorItem(color,0,0);
    m_objDSOV1Cursor->setBorderRect(m_objBoundaryRect);

    l_Vdashes.clear();
    l_Vdashes << 20 << space ;
    m_objDSOV1Cursor->changeDashes(l_Vdashes);
    m_objDSOV1Cursor->setCursorPosition(m_nV1CursorPosition);
    m_objDSOscene->addItem(m_objDSOV1Cursor);
    l_Vdashes.clear();
    m_objDSOV2Cursor = new VCursorItem(color,0,0);
    m_objDSOV2Cursor->setBorderRect(m_objBoundaryRect);
    l_Vdashes << 10 <<space;
    m_objDSOV2Cursor->changeDashes(l_Vdashes);
    m_objDSOV2Cursor->setCursorPosition(m_nV2CursorPosition);
    m_objDSOscene->addItem(m_objDSOV2Cursor);

//--------------------------------------------------------
//-------- Vertical Trigger Item Implementation--------------------
    m_objVerticalTrigger = new VTriggerItem(color,0,0);
    m_objVerticalTrigger->setBorderRect(m_objBoundaryRect);
    m_objVerticalTrigger->setTriggerPostion(0.0);
    m_objDSOscene->addItem(m_objVerticalTrigger);
//--------------------------------------------------------

//-------- Vertical Trigger Item Implementation--------------------
    m_objHorizontalTrigger = new HTriggerItem(QColor(0,0,255),0,0);
    m_objHorizontalTrigger->setBorderRect(m_objBoundaryRect);
    m_objHorizontalTrigger->setTriggerPostion(0.0);

    m_objDSOscene->addItem(m_objHorizontalTrigger);
//--------------------------------------------------------
    m_objVerticalTrigger->changeColor(QColor(255, 255,0));
    m_objHorizontalTrigger->changeColor(QColor(255, 255,0));
//channel1 item implementation
    m_objch1Item = new channelItem(QColor(255, 255, 0));
    m_objch1Item->setBorderRect(m_objBoundaryRect);
    m_objch1Item->setPlotSettings(m_objCh1PlotSettings);
    m_objch1Item->moveOffsetPostion(0.0);
    m_objDSOscene->addItem(m_objch1Item);
//channel2 item implementation
        m_objch2Item = new channelItem(QColor(255, 0, 255));
        m_objch2Item->setBorderRect(m_objBoundaryRect);
        m_objch2Item->setPlotSettings(m_objCh2PlotSettings);
        m_objch2Item->moveOffsetPostion(0.0);
        m_objDSOscene->addItem(m_objch2Item);


        m_objMaxPeakPointer->changeDashes(l_peakDashes);
        m_objMaxPeakPointer->setBorderRect(m_objBoundaryRect);
        m_objMaxPeakPointer->setCursorPosition(0.0);
        m_objDSOscene->addItem(m_objMaxPeakPointer);

        m_objMinPeakPointer->setBorderRect(m_objBoundaryRect);
        m_objMinPeakPointer->changeDashes(l_peakDashes);
        m_objMinPeakPointer->setCursorPosition(0.0);
        m_objDSOscene->addItem(m_objMinPeakPointer);

        m_objTR10Pointer->setBorderRect(m_objBoundaryRect);
        m_objTR10Pointer->setSoruceDestPoint(0.0,0.0);
        m_objDSOscene->addItem(m_objTR10Pointer);

        ui->chk1ShowTrace->setChecked(true);
        isCH1tblChecked = true;
    //    changeChannel1Widget(CHANNEL_1);
        m_nCH1dxOffsetPosition = m_nCH2dxOffsetPosition=0.0;
        m_objCH1OffsetPointer =new offsetItem(QColor(255,255,0,255),0,0);
        m_objCH1OffsetPointer->setBorderRect(m_objBoundaryRect);
        m_objDSOscene->addItem(m_objCH1OffsetPointer);

        m_objCH2OffsetPointer =new offsetItem(QColor(255,0,255,255),0,0);
        m_objCH2OffsetPointer->setBorderRect(m_objBoundaryRect);
        m_objCH1OffsetPointer->setOffsetPosition(m_objch1Item->getOffsetPostion());
        m_objCH2OffsetPointer->setOffsetPosition(m_objch2Item->getOffsetPostion());
        m_objDSOscene->addItem(m_objCH2OffsetPointer);



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeEvent(QEvent *e)
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



void MainWindow::changeChannel1Widget(BASEWIDGET pFlag)
{
	ui->chk1ShowTrace->setVisible(true);
	ui->chk2ShowTrace->setVisible(false);
	m_bCH1Offset =true;
	m_bCH2Offset = false;
	if(m_bCH1TriggerSource == true)
	{
		m_bCH2TriggerSource = false;
		m_objVerticalTrigger->changeColor(QColor(255, 255,0));
		m_objHorizontalTrigger->changeColor(QColor(255, 255,0));
	}
	//m_objVerticalTrigger->changeColor(QColor((255, 255, 0)));
    if(channel1Widget->isPressed() == true)
    {
        channel1Widget->modifyStyleSheet(true,CHANNEL_1);
        ui->grpVoltDiv->setVisible(true);
        m_nChannel1Value=1;
        m_nChannel2Value=0;
    }
    else if(channel1Widget->isPressed() == false)
    {
        channel1Widget->modifyStyleSheet(false,CHANNEL_1);
        ui->grpVoltDiv->setVisible(false);
        m_nChannel1Value=0;
        m_nChannel2Value=0;
    }
    ui->chlabel->setText("CH1");
    QString l_strValue = "QLabel{color:yellow;border-radius:0px;border:0px solid black;background-color:rgba(0,0,0,0);font:14px,bold;};";
    ui->chlabel->setStyleSheet(l_strValue);
    defaultSidePane(CHANNEL_1,"DSONavigation","Channel");
    //channel2Widget->modifyStyleSheet(false,CHANNEL_2);
    ui->VoltageDialWheel->setSliderPosition(m_nCH1VoltIndex);
    on_cmbLMHVoltage_currentIndexChanged(m_nCH1VoltIndex);
    m_eChannelSelected = CHANNEL_1;
    m_nH1CursorPosition=0.0;
    m_nH2CursorPosition=0.0;
    m_nH2VoltagePostion =m_objDSODataSettings->getVoltPerDivsion(CHANNEL_1)*4.0;
    m_nH1VoltagePostion=m_objDSODataSettings->getVoltPerDivsion(CHANNEL_1)*4.0;
}

void MainWindow::changeChannel2Widget(BASEWIDGET pFlag)
{
	ui->chk1ShowTrace->setVisible(false);
	ui->chk2ShowTrace->setVisible(true);
	m_bCH1Offset =false;
	m_bCH2Offset = true;

	if(m_bCH2TriggerSource == true)
	{
		m_bCH1TriggerSource = false;
		m_objVerticalTrigger->changeColor(QColor(255,0,255));
		m_objHorizontalTrigger->changeColor(QColor(255,0,255));
	}

	//m_objVerticalTrigger->changeColor(QColor((255, 0, 255)));

    if(channel2Widget->isPressed() == true)
    {
        channel2Widget->modifyStyleSheet(true,CHANNEL_2);
        ui->grpVoltDiv->setVisible(true);
        m_nChannel2Value=1;
        m_nChannel1Value=0;
    }
    else if(channel2Widget->isPressed() == false)
    {
        channel2Widget->modifyStyleSheet(false,CHANNEL_2);
        ui->grpVoltDiv->setVisible(false);
        m_nChannel2Value=0;
        m_nChannel1Value=0;
    }
    ui->chlabel->setText("CH2");
    QString l_strValue = "QLabel{color:pink;border-radius:0px;border:0px solid black;background-color:rgba(0,0,0,0);font:14px,bold;};";
    ui->chlabel->setStyleSheet(l_strValue);

    defaultSidePane(CHANNEL_2,"DSONavigation","Channel");
    ui->VoltageDialWheel->setSliderPosition(m_nCH2VoltIndex);
    on_cmbLMHVoltage_currentIndexChanged(m_nCH2VoltIndex);
    m_eChannelSelected = CHANNEL_2;
   // m_nH1CursorPosition=0.0;
   // m_nH2CursorPosition=0.0;

    m_nH2VoltagePostion =m_objDSODataSettings->getVoltPerDivsion(CHANNEL_2)*4.0;
    m_nH1VoltagePostion=m_objDSODataSettings->getVoltPerDivsion(CHANNEL_2)*4.0;


}

void MainWindow::changeTimeBaseWidget(BASEWIDGET pFlag)
{
    if(timeBaseWidget->isPressed() == true)
    {
    	timeBaseWidget->modifyStyleSheet(true,TIMEBASE);
        ui->grpTimeDiv->setVisible(true);
    }
    else if(timeBaseWidget->isPressed() == false)
    {
    	timeBaseWidget->modifyStyleSheet(false,TIMEBASE);
        ui->grpTimeDiv->setVisible(false);
    }
    //m_nV1CursorPosition =m_nV2CursorPosition=0.0;
    defaultSidePane(TIMEBASE,"DSONavigation","Timebase");
    //timeBaseWidget->modifyStyleSheet(false,TIMEBASE);

}


void MainWindow::changeTriggerWidget(BASEWIDGET pFlag)
{
    if(triggerWidget->isPressed() == true)
    {
        triggerWidget->modifyStyleSheet(true,TRIGGER);
        ui->grpTriggers->setVisible(true);
    }
    else if(triggerWidget->isPressed() == false)
    {
        triggerWidget->modifyStyleSheet(false,TRIGGER);
        ui->grpTriggers->setVisible(false);
    }
    defaultSidePane(TRIGGER,"DSONavigation","Trigger");
   // triggerWidget->modifyStyleSheet(false,TRIGGER);
}

void MainWindow::changeCursorsWidget(BASEWIDGET pFlag)
{
	if(cursorsWidget->isPressed() == true)
	{
		cursorsWidget->modifyStyleSheet(true,CURSORS);
		ui->grpCursors->setVisible(true);
	}
	else if(cursorsWidget->isPressed() == false)
	{
		cursorsWidget->modifyStyleSheet(false,CURSORS);
		ui->grpCursors->setVisible(false);
	}
	defaultSidePane(CURSORS,"DSONavigation","Cursors");
}


void MainWindow::on_pushButton_clicked()
{
    ui->topFrame->setVisible(true);
    ui->rootItem->setVisible(true);
    qDebug()<<"Menu-Clicked";
   defaultSidePane(DSONAVIGATION,"PortableTester","DSONavigation");
//	m_objDSOWaveSettings->disableInterrupt();
//	m_objDSOWaveSettings->enableInterrupt();
//	m_objDSOWaveSettings->DriveInterrupt();

   //m_objDialWidget->show();
}


void MainWindow::on_butRUNSTOP_clicked()
{

//	if(ui->optAuto->isChecked()==true)
//	{
//		qDebug()<<"AutoClicked"<<m_nIntFlag;
//	//	m_objTimerInterrupt->start(10);
//		if(m_nIntFlag== false)
//		{
//			m_objDSOWaveSettings->disableInterrupt();
//			m_objDSOWaveSettings->enableInterrupt();
//			m_nIntFlag=true;
//		}
//		m_objDSOWaveSettings->DriveInterrupt();
//	}
//	if(ui->optNormal->isChecked() == true)
//	{
//		qDebug()<<"Normal Clicked"<<m_eReceConf<<m_eTrigger;
//		ui->leStatus->setText("Armed");
//		if(m_nIntFlag== false)
//		{
//			m_objDSOWaveSettings->disableInterrupt();
//			m_objDSOWaveSettings->enableInterrupt();
//			m_nIntFlag=true;
//		}
//		m_objDSOWaveSettings->DriveInterrupt(true);
//	}


	qDebug()<<"RUN Flag:"<<m_bRUNFlag;
	if(m_bRUNFlag == true)
	{
		if(ui->optAuto->isChecked()==true)
		{
			qDebug()<<"Auto Clicked";
			m_objDSOWaveSettings->disableInterrupt();
			m_objDSOWaveSettings->enableInterrupt();
			m_objDSOWaveSettings->DriveInterrupt();
		}
		if(ui->optNormal->isChecked() == true)
		{
			qDebug()<<"Normal Clicked";
			m_objDSOWaveSettings->disableInterrupt();
			m_objDSOWaveSettings->enableInterrupt();
			m_objDSOWaveSettings->DriveInterrupt(true);
		}
		m_bRUNFlag = false;
	}
	else if(m_bRUNFlag == false)
	{
		m_objDSOWaveSettings->disableInterrupt();
		m_objDSOWaveSettings->Drive(false);
		m_bRUNFlag = true;
	}

}


void MainWindow::on_cmbLMHVoltage_currentIndexChanged(int index)
{
//	qDebug()<<"Select Voltage:"<<ui->cmbLMHVoltage->currentText();
        double l_nVoltDivArray[9]={0.002,0.002,0.002,0.002,0.002,0.01,0.01,0.01,0.1};

        //qDebug()<<"Current Index:"<<ui->cmbChannel->currentIndex();
        if(m_nChannel1Value == 1){
                m_eVoltage=VOLTAGEPERDIVISION(index);
                m_objLMH6518Component->calculateSignalPathGain(m_eVoltage);
                m_objDSODataSettings->setFPAtteunationFactor(m_objLMH6518Component->getFPAttennation(),CHANNEL_1);
                Data=m_objLMH6518Component->calculateGain();
                m_objDSODataSettings->setFSSettings(Data.m_sOutput,CHANNEL_1);
                m_objDSODataSettings->setVoltPerDivision(m_objLMH6518Component->getVoltPerDivision(index),CHANNEL_1);
                IGPIOEvent->setFSSettings(m_objLMH6518Component->getVoltPerDivision(index),m_objDSODataSettings->getFSSettings(CHANNEL_1),m_nSamples,m_objBoundaryRect.width()-(2*dsoMargin),0);
                if(index>=0 && index <5)
                {
                	ui->ch1VperDiv->setText(QString::number(m_objLMH6518Component->getVoltPerDivision(index)*1000.0,'f',1));
                	ui->ch1labelVpD->setText("mV/div");
                	ui->chVperDiv->setText(QString::number(m_objLMH6518Component->getVoltPerDivision(index)*1000.0,'f',1)+ QString(" mv/div"));
                }
                else
                {
                	ui->ch1VperDiv->setText(QString::number(m_objLMH6518Component->getVoltPerDivision(index),'f',1));
                	ui->ch1labelVpD->setText("V/div");
                	ui->chVperDiv->setText(QString::number(m_objLMH6518Component->getVoltPerDivision(index),'f',1)+ QString(" V/div"));

                }
                m_objCh1PlotSettings->setMaxVoltageDivision(m_objLMH6518Component->getVoltPerDivision(index));
                m_objCh1PlotSettings->setMinVoltageDivision(-m_objLMH6518Component->getVoltPerDivision(index));
                m_objch1Item->setPlotSettings(m_objCh1PlotSettings);
                m_nCH1VoltIndex = index;
                m_nCH1dxOffsetPosition = l_nVoltDivArray[index];
        }
        if( m_nChannel2Value == 1)
        {
                m_eCH2Voltage =VOLTAGEPERDIVISION(index);
                m_objLMH6518Component->calculateSignalPathGain(m_eCH2Voltage);
                m_objDSODataSettings->setFPAtteunationFactor(m_objLMH6518Component->getFPAttennation(),CHANNEL_2);
                DataCH2=m_objLMH6518Component->calculateGain();
                m_objDSODataSettings->setFSSettings(DataCH2.m_sOutput,CHANNEL_2);
                m_objDSODataSettings->setVoltPerDivision(m_objLMH6518Component->getVoltPerDivision(index),CHANNEL_2);
                IGPIOEvent->setFSSettings(m_objLMH6518Component->getVoltPerDivision(index),m_objDSODataSettings->getFSSettings(CHANNEL_2),m_nSamples,m_objBoundaryRect.width()-(2*dsoMargin),1);
                if(index>=0 && index <5)
                {
                	ui->ch2VperDiv->setText(QString::number(m_objLMH6518Component->getVoltPerDivision(index)*1000.0,'f',1));
                	ui->ch2labelVpD->setText("mV/div");
                	ui->chVperDiv->setText(QString::number(m_objLMH6518Component->getVoltPerDivision(index)*1000.0,'f',1)+ QString(" mv/div"));

                }
                else
                {
                	ui->ch2VperDiv->setText(QString::number(m_objLMH6518Component->getVoltPerDivision(index),'f',1));
                	ui->ch2labelVpD->setText("V/div");
                	ui->chVperDiv->setText(QString::number(m_objLMH6518Component->getVoltPerDivision(index),'f',1)+ QString(" V/div"));

                }
                m_objCh2PlotSettings->setMaxVoltageDivision(m_objLMH6518Component->getVoltPerDivision(index));
                m_objCh2PlotSettings->setMinVoltageDivision(-m_objLMH6518Component->getVoltPerDivision(index));
                m_objch2Item->setPlotSettings(m_objCh2PlotSettings);
                m_nCH2VoltIndex = index;
                m_nCH2dxOffsetPosition = l_nVoltDivArray[index];
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
        if(m_nChannel1Value==1){
                m_eDataTemplate.m_eChannelSel=CH1;
                m_eDataTemplate.m_eLAttenuation=m_objLMH6518Component->getLadderAtteunator();
                m_eDataTemplate.m_eFilter=LMH6518_FILTER(BW_FULL);
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
        if(m_nChannel2Value==1)
        {
                        m_eDataTemplateCH2.m_eChannelSel=CH2;
                        m_eDataTemplateCH2.m_eLAttenuation=m_objLMH6518Component->getLadderAtteunator();
                        m_eDataTemplateCH2.m_eFilter=LMH6518_FILTER(BW_FULL);
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
        if(m_nChannel1Value == 1)
        {
        	//commented by rrv sep30,2014
//            IPsoc->FG_Scope12(0,m_objDSODataSettings->getFPAtteunationFactor(CHANNEL_1),0xF);
        }
        if(m_nChannel2Value == 1)
        {
        	//commented by rrv sep30,2014
//            IPsoc->FG_Scope12(0,0xF,m_objDSODataSettings->getFPAtteunationFactor(CHANNEL_2));
        }
    	ui->dblVerticalTrigger->setMaximum(m_objLMH6518Component->getVoltPerDivision(index)*4);
    	ui->dblVerticalTrigger->setMinimum(m_objLMH6518Component->getVoltPerDivision(index)*-4);
    	ui->dblVerticalTrigger->setSingleStep(l_nVoltDivArray[index]);
    	updateValues();
}


//void MainWindow::on_optHorTrigger_clicked()
//{
//	ui->triggerWheel->setRange(m_nTimePerSample*-5,m_nTimePerSample*5);
//	ui->triggerWheel->setSingleStep(m_nTimePerSample/10.0);
//	ui->triggerWheel->setValue(0);

//	updateValues();
//}

//void MainWindow::on_optVerticalTrigger_clicked()
//{

//}

void MainWindow::on_butLEFT_clicked()
{
	if(m_bH1Cursor == true)
	{
		if( m_nV1CursorPosition >= (m_objBoundaryRect.left()+dsoMargin))
		{
			m_nV1CursorPosition -=m_nV1dxFactor;
			double m_nV1TimebasePos= ((m_objBoundaryRect.width()-(2*dsoMargin))/m_nV1CursorPosition );
			m_nV1TimebasePostion = ((m_nTimePerSample*10.0)/m_nV1TimebasePos);
		}
		else
		{
			m_nV1CursorPosition = 0.0;
			m_nV1TimebasePostion =0.0;
		}
		m_objDSOV1Cursor->setCursorPosition(m_nV1CursorPosition);
	}
	if(m_bH2Cursor == true)
	{
		if( m_nV2CursorPosition >= (m_objBoundaryRect.left()+dsoMargin))
		{
			m_nV2CursorPosition -=m_nV2dxFactor;
			double m_nV2TimebasePos= ((m_objBoundaryRect.width()-(2*dsoMargin))/m_nV2CursorPosition );
			m_nV2TimebasePostion = ((m_nTimePerSample*10.0)/m_nV2TimebasePos);

		}
		else
		{
			m_nV2CursorPosition = 0.0;
			m_nV2TimebasePostion =0.0;
		}
		m_objDSOV2Cursor->setCursorPosition(m_nV2CursorPosition);
	}
	ui->lblY1Value->setText(QString::number(m_nV1TimebasePostion,'f',2));
	ui->lblY2Value->setText(QString::number(m_nV2TimebasePostion,'f',2));
	double l_nDelY = (m_nV1TimebasePostion - m_nV2TimebasePostion);
	double l_nDelYFreq=0.0;
	if(l_nDelY !=0)
	{
		if(l_nDelY < 0)
			l_nDelYFreq = 1.0 / (l_nDelY)*-1.0;
		else
			l_nDelYFreq = 1.0 / (l_nDelY);
	}
	qDebug()<<"Delta Frequency:"<<l_nDelYFreq;
	ui->lblDelYValue->setText(QString::number(l_nDelY,'f',2));
	QString unitFactor="";
		double l_nMulFactor=0.0;
		if(m_nTimeUnitIndex == 0)
		{
			l_nMulFactor = 1000000.0;
			unitFactor = "Mhz";
		}
		if(m_nTimeUnitIndex == 1)
		{
			l_nMulFactor = 1000.0;
			unitFactor = "Khz";
		}
		if(m_nTimeUnitIndex == 2)
		{
			l_nMulFactor = 1.0;
			unitFactor = "Khz";
		}
		if(m_nTimeUnitIndex == 3)
		{
			l_nMulFactor = 1.0;
			unitFactor = "hz";
		}


		ui->lblDelFreqValue->setText(QString::number(l_nDelYFreq*l_nMulFactor,'f',2)+unitFactor);


}

void MainWindow::on_butUP_clicked()
{
	//qDebug()<<"H1 Cursor Position:"<<m_nH1CursorPosition<<"Rect Height:"<<m_objBoundaryRect.height()<<m_nH1dxFactor;
	//qDebug()<<"H2 Cursor Position:"<<m_nH2CursorPosition<<"Cursor Bool:"<<m_bV1Cursor<<m_bV2Cursor;
//	BASEWIDGET l_nChannel = (m_nChannel1Value == 1) ? CHANNEL_1: CHANNEL_2;
//	qDebug()<<"Voltage-Up:"<<m_objDSODataSettings->getVoltPerDivsion(l_nChannel);
	double l_nVoltageDxFactor = m_objDSODataSettings->getVoltPerDivsion(m_eChannelSelected)/10.0;
	qDebug()<< "Voltage DOWN:"<<m_objDSODataSettings->getVoltPerDivsion(m_eChannelSelected);
	if(m_bV1Cursor == true)
	{
		if(m_nH1CursorPosition > (m_objBoundaryRect.top() + dsoMargin))
		{
			m_nH1CursorPosition -=m_nH1dxFactor;
			m_nH1VoltagePostion += l_nVoltageDxFactor;

		}
		else
		{
			m_nH1CursorPosition = 0.0;
			m_nH1VoltagePostion=m_objDSODataSettings->getVoltPerDivsion(m_eChannelSelected)*4.0;;
		}
		m_objDSOH1Cursor->setCursorPosition(m_nH1CursorPosition);
	}
	if(m_bV2Cursor == true)
	{
		if(m_nH2CursorPosition > (m_objBoundaryRect.top() + dsoMargin))
		{
			m_nH2CursorPosition -=m_nH2dxFactor;
			m_nH2VoltagePostion += l_nVoltageDxFactor;

		}
		else
		{
			m_nH2CursorPosition = 0.0;
			m_nH2VoltagePostion=m_objDSODataSettings->getVoltPerDivsion(m_eChannelSelected)*4.0;;
		}
		m_objDSOH2Cursor->setCursorPosition(m_nH2CursorPosition);
	}
	ui->lblX1Value->setText(QString::number(m_nH1VoltagePostion,'f',4));
	ui->lblX2Value->setText(QString::number(m_nH2VoltagePostion,'f',4));
	double l_ndelX = m_nH1VoltagePostion - m_nH2VoltagePostion;
	if(m_eChannelSelected == CHANNEL_1)
		ui->lblCH1DelValue->setText(QString::number(l_ndelX,'f',4));
	else if(m_eChannelSelected == CHANNEL_2)
		ui->lblCH2DelValue->setText(QString::number(l_ndelX,'f',4));

}

void MainWindow::on_butDOWN_clicked()
{
	//qDebug()<<"H1 Cursor Position:"<<m_nH1CursorPosition<<"Rect Height:"<<m_objBoundaryRect.height()<<m_nH1dxFactor;
	//qDebug()<<"H2 Cursor Position:"<<m_nH2CursorPosition<<"Cursor Bool:"<<m_bV1Cursor<<m_bV2Cursor;
	//BASEWIDGET l_nChannel = (m_nChannel1Value == 1) ? CHANNEL_1: CHANNEL_2;
//	qDebug()<<"Voltage-Down:"<<m_objDSODataSettings->getVoltPerDivsion(l_nChannel);
    double l_nVoltageDxFactor = m_objDSODataSettings->getVoltPerDivsion(m_eChannelSelected)/10.0;
    qDebug()<< "Voltage DOWN:"<<m_objDSODataSettings->getVoltPerDivsion(m_eChannelSelected);

    //m_nH1VoltagePostion = l_nPositivePeakVoltage;
	if(m_bV1Cursor == true)
	{
		if(m_nH1CursorPosition < m_objBoundaryRect.height() -(2* dsoMargin))
		{
			m_nH1CursorPosition +=m_nH1dxFactor;
			m_nH1VoltagePostion -= l_nVoltageDxFactor;
		}
		else
		{
			m_nH1CursorPosition = m_objBoundaryRect.height() -(2* dsoMargin);
			m_nH1VoltagePostion = m_objDSODataSettings->getVoltPerDivsion(m_eChannelSelected)*-4.0;
		}
		m_objDSOH1Cursor->setCursorPosition(m_nH1CursorPosition);
	}
	if(m_bV2Cursor == true)
	{
		if(m_nH2CursorPosition < m_objBoundaryRect.height() -(2* dsoMargin))
		{
			m_nH2CursorPosition +=m_nH2dxFactor;
			m_nH2VoltagePostion -= l_nVoltageDxFactor;

		}
		else
		{
			m_nH2CursorPosition = m_objBoundaryRect.height() -(2* dsoMargin);
			m_nH2VoltagePostion = m_objDSODataSettings->getVoltPerDivsion(m_eChannelSelected)*-4.0;
		}
		m_objDSOH2Cursor->setCursorPosition(m_nH2CursorPosition);
	}
	ui->lblX1Value->setText(QString::number(m_nH1VoltagePostion,'f',4));
	ui->lblX2Value->setText(QString::number(m_nH2VoltagePostion,'f',4));
	double l_ndelX = m_nH1VoltagePostion - m_nH2VoltagePostion;
	if(m_eChannelSelected == CHANNEL_1)
		ui->lblCH1DelValue->setText(QString::number(l_ndelX,'f',4));
	else if(m_eChannelSelected == CHANNEL_2)
		ui->lblCH2DelValue->setText(QString::number(l_ndelX,'f',4));
}

void MainWindow::on_butRIGHT_clicked()
{
	//qDebug()<<"V1 Curson Position:"<<m_nV1CursorPosition<<"Rect Width:"<<m_objBoundaryRect.width()<<m_nV1dxFactor<<m_nV1TimebasePostion;
	if(m_bH1Cursor == true)
	{
		if( m_nV1CursorPosition < m_objBoundaryRect.width()-(2*dsoMargin))
		{
			m_nV1CursorPosition +=m_nV1dxFactor;
			double m_nV1TimebasePos= ((m_objBoundaryRect.width()-(2*dsoMargin))/m_nV1CursorPosition );
			m_nV1TimebasePostion = ((m_nTimePerSample*10.0)/m_nV1TimebasePos);

		}
		else
		{
			m_nV1CursorPosition = m_objBoundaryRect.width()-(2*dsoMargin);
			m_nV1TimebasePostion = m_nTimePerSample*10.0;
		}
		m_objDSOV1Cursor->setCursorPosition(m_nV1CursorPosition);
	}
	if(m_bH2Cursor == true)
	{
		if( m_nV2CursorPosition < m_objBoundaryRect.width()-(2*dsoMargin))
		{
			m_nV2CursorPosition +=m_nV2dxFactor;
			double m_nV2TimebasePos= ((m_objBoundaryRect.width()-(2*dsoMargin))/m_nV2CursorPosition );
			m_nV2TimebasePostion = ((m_nTimePerSample*10.0)/m_nV2TimebasePos);
		}
		else
		{
			m_nV2CursorPosition = m_objBoundaryRect.width()-(2*dsoMargin);
			m_nV2TimebasePostion = m_nTimePerSample*10.0;
		}
		m_objDSOV2Cursor->setCursorPosition(m_nV2CursorPosition);
	}
	ui->lblY1Value->setText(QString::number(m_nV1TimebasePostion,'f',2));
	ui->lblY2Value->setText(QString::number(m_nV2TimebasePostion,'f',2));
	double l_nDelY = (m_nV1TimebasePostion - m_nV2TimebasePostion);
	double l_nDelYFreq=0.0;
	if(l_nDelY !=0)
	{
		if(l_nDelY < 0)
			l_nDelYFreq = 1.0 / (l_nDelY)*-1.0;
		else
			l_nDelYFreq = 1.0 / (l_nDelY);
	}

	qDebug()<<"Delta Frequency:"<<l_nDelYFreq;
	ui->lblDelYValue->setText(QString::number(l_nDelY,'f',2));
	QString unitFactor="";
	double l_nMulFactor=0.0;
	if(m_nTimeUnitIndex == 0)
	{
		l_nMulFactor = 1000000.0;
		unitFactor = "Mhz";
	}
	if(m_nTimeUnitIndex == 1)
	{
		l_nMulFactor = 1000.0;
		unitFactor = "Khz";
	}
	if(m_nTimeUnitIndex == 2)
	{
		l_nMulFactor = 1.0;
		unitFactor = "Khz";
	}
	if(m_nTimeUnitIndex == 3)
	{
		l_nMulFactor = 1.0;
		unitFactor = "hz";
	}


	ui->lblDelFreqValue->setText(QString::number(l_nDelYFreq*l_nMulFactor,'f',2)+unitFactor);
	//qDebug()<<"Time Position:"<<m_nV1TimebasePostion<<m_objDSODataSettings->getTimePerDivision(CHANNEL_1)<<m_nV1CursorPosition;
}

void MainWindow::on_butOffset_plus_clicked()
{
	//qDebug()<<"Offset Plus:"<<m_nCH1dxOffsetPosition<<m_objch1Item->getOffsetPostion();
	double l_nTempValue=0.0;
	if(m_bCH1Offset == true)
	{
		l_nTempValue = m_objch1Item->getOffsetPostion()+m_nCH1dxOffsetPosition;
	    double l_nVTOffsetPosition = -((m_objBoundaryRect.height()-(2*dsoMargin))/8.0)*(l_nTempValue/(m_objDSODataSettings->getVoltPerDivsion(CHANNEL_1)));
		m_objch1Item->moveOffsetPostion(l_nTempValue);
		m_objCH1OffsetPointer->setOffsetPosition(l_nVTOffsetPosition);
		ui->ch1Voffset->setText(QString::number(l_nTempValue,'f',2));
	}
	else if(m_bCH2Offset == true)
	{
		l_nTempValue =m_objch2Item->getOffsetPostion()+m_nCH2dxOffsetPosition;
	    double l_nVTOffsetPosition = -((m_objBoundaryRect.height()-(2*dsoMargin))/8.0)*(l_nTempValue/(m_objDSODataSettings->getVoltPerDivsion(CHANNEL_2)));
		m_objch2Item->moveOffsetPostion(l_nTempValue);
		m_objCH2OffsetPointer->setOffsetPosition(l_nVTOffsetPosition);
		ui->ch2Voffset->setText(QString::number(l_nTempValue,'f',2));

	}

}
void MainWindow::on_butOffset_minus_clicked()
{
	//qDebug()<<"Offset Minus:"<<m_nCH1dxOffsetPosition;
	double l_nTempValue=0.0;
	if(m_bCH1Offset == true)
	{
		l_nTempValue = m_objch1Item->getOffsetPostion()-m_nCH1dxOffsetPosition;
		m_objch1Item->moveOffsetPostion(l_nTempValue);
	    double l_nVTOffsetPosition = -((m_objBoundaryRect.height()-(2*dsoMargin))/8.0)*(l_nTempValue/(m_objDSODataSettings->getVoltPerDivsion(CHANNEL_1)));
		ui->ch1Voffset->setText(QString::number(l_nTempValue,'f',2));
		m_objCH1OffsetPointer->setOffsetPosition(l_nVTOffsetPosition);

	}
	else if(m_bCH2Offset == true)
	{
		l_nTempValue =m_objch2Item->getOffsetPostion()-m_nCH2dxOffsetPosition;
	    double l_nVTOffsetPosition = -((m_objBoundaryRect.height()-(2*dsoMargin))/8.0)*(l_nTempValue/(m_objDSODataSettings->getVoltPerDivsion(CHANNEL_2)));
		m_objch2Item->moveOffsetPostion(l_nTempValue);
		m_objCH2OffsetPointer->setOffsetPosition(l_nVTOffsetPosition);
		ui->ch2Voffset->setText(QString::number(l_nTempValue,'f',2));
	}

}

void MainWindow::on_butOffset_zero_clicked()
{
	if(m_bCH1Offset == true){
		m_objch1Item->moveOffsetPostion(0.0);
		ui->ch1Voffset->setText(QString::number(m_objch1Item->getOffsetPostion(),'f',2));
		m_objCH1OffsetPointer->setOffsetPosition(0.0);
	}
	else if(m_bCH2Offset == true)
	{
		m_objch2Item->moveOffsetPostion(0.0);
		ui->ch1Voffset->setText(QString::number(m_objch2Item->getOffsetPostion(),'f',2));
	}

}

