#include "flashMemory.h"
#include "ui_flashMemory.h"
#include "qdebug.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    initializeHWInterfaces();
    m_strFillValue = QString("0");
    m_strFLASHSettingsFile = "FlashSettings.ini";
    initializeTable();
    initializeLineEdits();
    initialiseDataValues();
    if(QFile().exists(m_strFLASHSettingsFile))
    	loadSettings();
    changeTableIndex(false);
    //connect(ui->butSaveFile,SIGNAL(clicked),this,SLOT(on_butSaveFile_clicked()));

    qDebug()<< "Flash Memory Loaded";
}
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

	//ui->grpADDRSEQ->setParent(m_objWidget);
//	ui->grpFILE->setParent(m_objWidget);
	ui->grpFLASHRW->setParent(m_objWidget);
	ui->grpMEMErase->setParent(m_objWidget);
//	ui->grpMEMSeque->setParent(m_objWidget);
	ui->grpSELECTCARD->setParent(m_objWidget);
	ui->grpdrvBulkMEM->setParent(m_objWidget);
	ui->grpSYSTEMMEMORY->setParent(m_objWidget);
	ui->grpCODEID->setParent(m_objWidget);
	ui->grpSYSTEM->setParent(m_objWidget);
	ui->grpMEMfill->setParent(m_objWidget);



	//ui->grpADDRSEQ->setGeometry(570,380,221,140);
//	ui->grpFILE->setGeometry();
	ui->grpFLASHRW->setGeometry(10,10,781,371);
	ui->grpMEMErase->setGeometry(290,380,271,141);
//	ui->grpMEMSeque->setGeometry();
	ui->grpSELECTCARD->setGeometry(160,380,121,140);
	ui->grpdrvBulkMEM->setGeometry(535,160,251,67);
	ui->grpSYSTEMMEMORY->setGeometry(570,380,221,141);
	ui->grpCODEID->setGeometry(290,470,271,51);
	ui->grpSYSTEM->setGeometry(10,380,141,141);
	ui->grpMEMfill->setGeometry(715,230,61,131);

      //  ui->grpSYSTEMMEMORY->setDisabled(true);

}
void Widget::initializeHWInterfaces()
{
    QPluginLoader loader4("libQmaxPTInterface.so",this);
    ILineEdit = qobject_cast<IQmaxLineEdit*>(loader4.instance());
    INumberPanel=qobject_cast<IQmaxNumberPanel*>(loader4.instance());

    QPluginLoader loader2("libSPIMemoryInterface.so", this);
    ISPIMemory = qobject_cast<ISPIMemoryInterface*> (loader2.instance());

    QPluginLoader loader1("libPTSplashInterface.so",ui->grpSYSTEMMEMORY);
    ISplashScreen = qobject_cast<PTSplashScreen*>(loader1.instance());
    ISplashScreen->getSplashWidget(ui->grpSYSTEMMEMORY);

    QPluginLoader loader3("libBackPlaneInterface.so", this);
    IBackPlane = qobject_cast<IntefaceBackPlane*> (loader3.instance());
    IBackPlane->InitializeBpObject();

    QPluginLoader loaderApp("libPTApplicationcardInterface.so",this);
	IAppCard = qobject_cast<IApplicationCardInterface*>(loaderApp.instance());
	qDebug() << "Appcard" <<IAppCard;
	IAppCard->setDeviceName(SLOT0);
	IAppCard->enumerateAPPCard();
	IAppCard->setSPIAppendBit(0xC000);
	ISPIMemory->setHardwarwObject(IAppCard);
	qDebug() << "Code ID:"<<hex<< IAppCard->readAppCardCodeId();
}

void Widget::initialiseDataValues()
{
    m_nAdressCount=m_nDataCount=m_nEndAddress=m_nEraseAddress=m_nIndexLocation=m_nLineEditIndex=m_nStartAddress=0;
    on_cmbHWSelect_currentIndexChanged(1);
    ui->optRAM->setChecked(true);
    on_optRAM_clicked();

}

void Widget::saveSettings()
{

    QSettings settings(m_strFLASHSettingsFile, QSettings::NativeFormat);
    settings.setValue("StartAddress",m_nStartAddress);
    settings.setValue("AddressCount",m_nAdressCount);
    settings.setValue("EndAddress",m_nEndAddress);
    if(ui->optSystemMemory->isChecked())
    	settings.setValue("Memory",0);
    else if(ui->optFlash->isChecked())
    	settings.setValue("Memory",1);
    else if(ui->optDDR->isChecked())
    	settings.setValue("Memory",2);
    else if(ui->optRAM->isChecked())
    	settings.setValue("Memory",3);
    else if(ui->optReceiveRAM->isChecked())
    	settings.setValue("Memory",4);

}

void Widget::loadSettings()
{

	//bool ok=true;
	QSettings settings(m_strFLASHSettingsFile, QSettings::NativeFormat);
	m_nStartAddress = settings.value("StartAddress",0).toUInt();
	m_nEndAddress = settings.value("EndAddress",0).toUInt();
	m_nAdressCount = settings.value("AddressCount",0).toUInt();

	m_objstAddr->setText(QString::number(m_nStartAddress,16));
	m_objAddrCount->setText(QString::number(m_nAdressCount,10));
	m_objendAddr->setText("0x"+QString::number(m_nEndAddress,16));

	unsigned short l_nMemIndex = settings.value("Memory",0).toUInt();

	if(l_nMemIndex==0)
	{
		ui->optSystemMemory->setChecked(true);
		on_optSystemMemory_clicked();
	}
	else if(l_nMemIndex==1)
	{
		ui->optFlash->setChecked(true);
		on_optFlash_clicked();
	}
	else if(l_nMemIndex==2)
	{
		ui->optDDR->setChecked(true);
		on_optDDR_clicked();
	}
	else if(l_nMemIndex==3)
	{
		ui->optRAM->setChecked(true);
		on_optRAM_clicked();
	}
	else if(l_nMemIndex == 4)
	{
		ui->optReceiveRAM->setChecked(true);
		on_optReceiveRAM_clicked();
	}
	//on_butRead_clicked();
	//LoadSettingsData();

}

void Widget::LoadSettingsData()
{
	m_lstWaveData.clear();

	for(int l_nWaveIndex=0;l_nWaveIndex<m_nAdressCount;l_nWaveIndex++)
	{
		m_lstWaveData.insert(l_nWaveIndex,QString::number(m_nMEMLOCATIONS[l_nWaveIndex],16));
	}
}

Widget::~Widget()
{
    qDebug()<< "Flash Memory Destroyed";
    saveSettings();
    delete []m_nMEMLOCATIONS,m_nMEMLOCATIONS=NULL;
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

void Widget::initializeTable()
{
    m_nMEMLOCATIONS = new unsigned short int[MAX_MEM_SIZE];
    ui->tableWidget->resizeColumnsToContents();
    ui->tableWidget->resizeRowsToContents();
    ui->tableWidget->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    short int l_nTempIndex=0;
    for(int l_nTableRowIndex=0;l_nTableRowIndex<16;l_nTableRowIndex++)
    {

        for(int l_nTableColumnIndex=0;l_nTableColumnIndex<16;l_nTableColumnIndex++)
        {
            ui->tableWidget->setItem(l_nTableRowIndex,l_nTableColumnIndex,new QTableWidgetItem(m_strFillValue));
            m_nMEMLOCATIONS[l_nTempIndex++]=0;
        }
    }
    connect(ui->tableWidget,SIGNAL(cellClicked(int,int)),this,SLOT(setAddressIndex(int,int)));
}

void Widget::clearTableWidget()
{
	//m_lstWaveData.clear();
    for(int l_nTableRowIndex=0;l_nTableRowIndex<16;l_nTableRowIndex++)
    {

        for(int l_nTableColumnIndex=0;l_nTableColumnIndex<16;l_nTableColumnIndex++)
        {
        	QTableWidgetItem *item = ui->tableWidget->item(l_nTableRowIndex,l_nTableColumnIndex);
        	 item->setText(m_strFillValue);
        	// m_lstWaveData.insert(l_nTableColumnIndex,m_strFillValue);
        }
    }

}

void Widget::updateTableWidget()
{
    short int l_nTempIndex=0;
    qDebug()<<"Address Count:"<<m_nAdressCount;
    for(int l_nTableRowIndex=0;l_nTableRowIndex<16;l_nTableRowIndex++)
    {

        for(int l_nTableColumnIndex=0;l_nTableColumnIndex<16;l_nTableColumnIndex++)
        {
            QTableWidgetItem *item = ui->tableWidget->item(l_nTableRowIndex,l_nTableColumnIndex);
           // qDebug()<<"Column Count:"<<l_nTableColumnIndex <<" Row Count:"<<l_nTableRowIndex;
            if(l_nTempIndex < m_nAdressCount){
            	item->setText(QString::number(m_nMEMLOCATIONS[l_nTempIndex++],16).toUpper());
            }
            else
            	item->setText("0");
        }
    }
    qDebug() <<"Table Updated";
}


void Widget::initializeLineEdits()
{
    m_objstAddr = ILineEdit->QmaxLineEdit(1,ui->grpMEMSeque);
    m_objstAddr->setGeometry(12,20,113,41);
    m_objstAddr->setFont(QFont("DejaVu Sans",13,50,false));

    m_objAddrCount = ILineEdit->QmaxLineEdit(2,ui->grpMEMSeque);
    m_objAddrCount->setGeometry(135,20,113,41);
    m_objAddrCount->setFont(QFont("DejaVu Sans",13,50,false));

    m_objendAddr = ILineEdit->QmaxLineEdit(3,ui->grpMEMSeque);
    m_objendAddr->setGeometry(12,80,80,41);
    m_objendAddr->setFont(QFont("DejaVu Sans",13,50,false));
    m_objendAddr->setReadOnly(true);

    m_objIndexLocation = ILineEdit->QmaxLineEdit(4,ui->grpMEMSeque);
    m_objIndexLocation->setGeometry(100,80,55,41);
    m_objIndexLocation->setFont(QFont("DejaVu Sans",13,50,false));
    m_objIndexLocation->setReadOnly(true);

    m_objEditData = ILineEdit->QmaxLineEdit(6,ui->grpMEMSeque);
    m_objEditData->setGeometry(165,80,80,41);
    m_objEditData->setFont(QFont("DejaVu Sans",13,50,false));


//----------------------------------------------------
    m_objEraseAddr = ILineEdit->QmaxLineEdit(5,ui->grpMEMErase);
    m_objEraseAddr->setGeometry(15,28,113,41);
    m_objEraseAddr->setFont(QFont("DejaVu Sans",13,50,false));
//----------------------------------------------------
//    m_objDataCount = ILineEdit->QmaxLineEdit(6,ui->grpdrvBulkMEM);
//    m_objDataCount->setGeometry(140,32,113,41);
//    m_objDataCount->setFont(QFont("DejaVu Sans",13,50,false));


    connect(m_objstAddr,   SIGNAL(focussed(bool)), this, SLOT(callstAddressEdit()));
    connect(m_objAddrCount,      SIGNAL(focussed(bool)), this, SLOT(callAddrCoutEdit()));
    connect(m_objendAddr,    SIGNAL(focussed(bool)), this, SLOT(callEndAddrEdit()));
    connect(m_objIndexLocation, SIGNAL(focussed(bool)), this, SLOT(callIndexLocEdit()));
    connect(m_objEraseAddr,      SIGNAL(focussed(bool)), this, SLOT(callPageEraseEdit()));
    connect(m_objEditData,      SIGNAL(focussed(bool)), this, SLOT(callDataEdit()));

   // connect(m_objDataCount,  SIGNAL(focussed(bool)), this, SLOT(callDataCountEdit()));

    m_nLineEditIndex=0;

	m_objAddrCount->setStyleSheet(	  "border-width: 2px;border-style: outset;border-color: gray;    padding: 0 8px;     background: black;     selection-background-color: yellow;   color:white;     font: bold 14px;" );
//	m_objDataCount->setStyleSheet("border-width: 2px;border-style: outset;border-color: gray; 	   padding: 0 8px;     background: black;     selection-background-color: yellow;"    );
	m_objEraseAddr->setStyleSheet(	  "border-width: 2px;border-style: outset;border-color: gray;    padding: 0 8px;     background: black;     selection-background-color: yellow; 	color:white;     font: bold 14px;" );
	m_objIndexLocation->setStyleSheet("border-width: 2px;border-style: outset;border-color: gray;    padding: 0 8px;     background: black;     selection-background-color: yellow;   color:white;     font: bold 14px;" );
	m_objEditData->setStyleSheet("border-width: 2px;border-style: outset;border-color: gray;    padding: 0 8px;     background: black;     selection-background-color: yellow;   color:white;     font: bold 14px;" );
	m_objendAddr->setStyleSheet(	  "border-width: 2px;border-style: outset;border-color: gray;	   padding: 0 8px;     background: black;     selection-background-color: yellow;   color:white;     font: bold 14px;" );
	m_objstAddr->setStyleSheet(	      "border-width: 2px;border-style: outset;border-color: gray;	   padding: 0 8px;     background: black;     selection-background-color: yellow;   color:white;     font: bold 14px;" );
	ui->lecodeID->setStyleSheet(	  "border-width: 2px;border-style: outset;border-color: gray;	   padding: 0 8px;     background: black;     selection-background-color: yellow;   color:white;     font: bold 14px;" );
    enableRichGUI();
    ui->cmbHWSelect->setCurrentIndex(1);
    ui->grpSYSTEMMEMORY->setVisible(true);
    ui->optSlot0->setChecked(true);
}


void Widget::callAddrCoutEdit()
{
    if (m_objAddrCount->hasFocus())
    {
            openNumKBPanel(2);
            m_nLineEditIndex = 2;
    }

}

void Widget::callDataCountEdit()
{
//    if (m_objDataCount->hasFocus()) {
//            openNumKBPanel(0);
//            m_nLineEditIndex = 6;
//    }

}

void Widget::callEndAddrEdit()
{
    m_nLineEditIndex = 3;
    /*if (m_objendAddr->hasFocus()) {
            openNumKBPanel(0);
            m_nLineEditIndex = 3;
    }*/

}

void Widget::callIndexLocEdit()
{
//    if (m_objIndexLocation->hasFocus()) {
//            openNumKBPanel(0);
//            m_nLineEditIndex = 4;
//    }

}

void Widget::callPageEraseEdit()
{
    if (m_objEraseAddr->hasFocus()) {
            openNumKBPanel(0);
            m_nLineEditIndex = 5;
    }
}

void Widget::callstAddressEdit()
{
    if (m_objstAddr->hasFocus()) {
            openNumKBPanel(0);
            m_nLineEditIndex = 1;
    }
}

void Widget::callDataEdit()
{
    if (m_objEditData->hasFocus()) {
            openNumKBPanel(0);
            m_nLineEditIndex = 6;
    }
}

void Widget::setAddressIndex(int row,int col)
{
	qDebug()<<"Row:"<<row<<"Col:"<<col;
	m_nRow = row;
	m_nCol = col;
	QString l_strAddress;
	if(ui->optFlash->isChecked()|| ui->optRAM->isChecked()){
		l_strAddress = "0x"+QString::number(((row*16)+(col)),16);
		m_nIndexLocation = ((row*16)+(col));
	}
	else
	{
		l_strAddress = "0x"+QString::number((((row*2)*16)+(col*2)),16);
		m_nIndexLocation = (((row*2)*16)+(col*2));
	}
	m_objIndexLocation->setText(l_strAddress);
	unsigned int l_nAddressIndex;
	if(m_nHWIndex==0)
		l_nAddressIndex = 0xB8000000 + m_nIndexLocation + m_nStartAddress;
	else
		l_nAddressIndex = 0xB0000000 + m_nIndexLocation + m_nStartAddress;
	ui->lblIndex->setText("0x"+QString::number(l_nAddressIndex,16).toUpper());

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



void Widget::receiveValue(unsigned int pValue)
{
    if(m_nLineEditIndex==1)
    {
            m_objstAddr->setText(QString::number(pValue,16));
            m_nStartAddress=pValue;
            if(m_nAdressCount >0){
                m_nEndAddress= m_nAdressCount + m_nStartAddress;
                m_objendAddr->setText("0x"+QString::number(m_nEndAddress,16).toUpper());
            }

    }
    else if(m_nLineEditIndex==2)
    {
            m_objAddrCount->setText(QString::number(pValue,10));
            m_nAdressCount = pValue;
            m_nEndAddress= m_nAdressCount + m_nStartAddress;
            m_objendAddr->setText("0x"+QString::number(m_nEndAddress,16).toUpper());

    }
    else if(m_nLineEditIndex==3)
    {
           // m_objendAddr->setText(QString::number(pValue,16));
           // m_nEndAddress= pValue;
    }
    else if(m_nLineEditIndex==4)
    {
            m_objIndexLocation->setText(QString::number(pValue,16).toUpper());
            m_nIndexLocation = pValue;
            qDebug() << "Selected Index Location:" <<m_nIndexLocation;
    }
    else if(m_nLineEditIndex==5)
    {
            m_objEraseAddr->setText(QString::number(pValue,16).toUpper());
            m_nEraseAddress = pValue;
    }
    else if(m_nLineEditIndex==6)
    {
            m_objEditData->setText(QString::number(pValue,16));
            m_nEditData = pValue;

    }
}

void Widget::callSingleDrive()
{
	unsigned short int *m_nWriteData = new unsigned short int[1];
	qDebug() << "Index Location:" <<m_nStartAddress+m_nIndexLocation;

	m_nWriteData[0] =m_nEditData;
	if(ui->optFlash->isChecked() == true)
		ISPIMemory->writeSPIMemory(m_nStartAddress+m_nIndexLocation, 1, &m_nWriteData[0]);
	else if(ui->optRAM->isChecked() == true )
	{
		qDebug() << "Data:"<<m_nEditData;
		ISPIMemory->SingleWriteAPPCardSRAM(m_nStartAddress+m_nIndexLocation,m_nEditData);
	}
	else if(ui->optSystemMemory->isChecked() == true)
	{
		if(m_nHWIndex == 0)
			ISPIMemory->writeBackPanelSystemMemory(m_nStartAddress+m_nIndexLocation, 1, &m_nWriteData[0]);
		else
			ISPIMemory->writeAppCardSystemMemory(m_nStartAddress+m_nIndexLocation, 1, &m_nWriteData[0]);
	}
}

void Widget::callSingleRead()
{
	unsigned short int *m_nReadData = new unsigned short int[1];
	qDebug() << "OnSingle Read:"<<m_nStartAddress+m_nIndexLocation;
	if(ui->optFlash->isChecked() == true)
		m_nReadData = ISPIMemory->ReadSPI(m_nStartAddress+m_nIndexLocation,1);
	else if(ui->optRAM->isChecked() == true )
	{
		m_nReadData[0] = ISPIMemory->SingleReadAPPCardSRAM(m_nStartAddress+m_nIndexLocation);
	}
	else if(ui->optFlash->isChecked() == true)
	{
		if(m_nHWIndex == 0)
			m_nReadData = ISPIMemory->ReadSPI(m_nStartAddress+m_nIndexLocation,1);
		else
			m_nReadData = ISPIMemory->ReadSPI(m_nStartAddress+m_nIndexLocation,1);
	}
	else if(ui->optSystemMemory->isChecked() == true)
	{
		if(m_nHWIndex == 0)
			m_nReadData =ISPIMemory->readBackPanelCardSystemMemory(m_nStartAddress+m_nIndexLocation, 1);
		else
			m_nReadData = ISPIMemory->readAppCardSystemMemory(m_nStartAddress+m_nIndexLocation, 1);
	}

	QTableWidgetItem *item = ui->tableWidget->item(m_nRow,m_nCol);
    item->setText(QString::number(m_nReadData[0],16).toUpper());
    QMessageBox::information(this,"Read","Read Operation done.",QMessageBox::Ok);
}
void Widget::receiveValue(double pValue)
{
    Q_UNUSED(pValue)
}
void Widget::receiveValue(QString pValue)
{
        Q_UNUSED(pValue)
}

void Widget::on_butErase_clicked()
{
//	ISplashScreen->setLoadingText("Bulk Erase in Progress...");
//	ISplashScreen->selectSplashImage(0);
//	ISplashScreen->setPos(10,40,150,30);
//	ISplashScreen->ShowSplash();
	ISPIMemory->bulkErase();
//	ISplashScreen->closeSplash();
        QMessageBox::information(this,"Erase","Erase Operation done.",QMessageBox::Ok);
}

void Widget::on_butCODEID_clicked()
{
//	ui->lblMEMStatus->setText("CODE ID..");
    ui->lecodeID->setText(QString::number(ISPIMemory->getSPICodeID(),16));
//    ui->lblMEMStatus->setText("");
}

void Widget::on_butLoadFile_clicked()
{
//	ui->lblMEMStatus->setText("LOADING FILE..");
    QString l_strFileName = QFileDialog::getOpenFileName(this,"Select files to open","/home","Text (*.txt)");
    qDebug() << "FileName Selected"<<l_strFileName;
    LoadFile(l_strFileName);
//    ui->lblMEMStatus->setText("");
    QMessageBox::information(this,"File Load","File Loaded....",QMessageBox::Ok);
}

void Widget::on_butSaveFile_clicked()
{
//	ISplashScreen->setLoadingText("Saving File in Progress...");
//	ISplashScreen->selectSplashImage(0);
//	ISplashScreen->setPos(350,325,300,30);
//	ISplashScreen->ShowSplash();
	qDebug()<<"File Save";
    QFile *l_objDataFile = new QFile("./memvalue.txt");
    FILE *fpWaveFile;
	fpWaveFile = fopen("./memvalue.txt","w");

    if(l_objDataFile->open(QFile::WriteOnly))
    {
    	for(int l_nIndex=0;l_nIndex<MAX_MEM_SIZE;l_nIndex++)
		{
			//l_objDataFile->write(QString::number(m_nMEMLOCATIONS[l_nIndex],16),4);
			//l_objDataFile->write("\n",1);
    		qDebug()<< "Data:"<<hex<<m_nMEMLOCATIONS[l_nIndex];

			fprintf(fpWaveFile,"%X\n",m_nMEMLOCATIONS[l_nIndex]);
		}
    }
    //l_objDataFile->close();
    fclose(fpWaveFile);
    qDebug()<<"File Save Completed";
    QMessageBox::information(this,"Save","File Save Completed.",QMessageBox::Ok);
    //ISplashScreen->closeSplash();
    //ui->lblStatus->setText("File Saved..");

}

void Widget::on_butPageErase_clicked()
{
	//ui->lblStatus->setText("Page Erase..");
	ISPIMemory->pageErase(m_nEraseAddress);
	//ui->lblStatus->setText("Page Erase Completed..");
}

void Widget::on_butReadSave_clicked()
{
	on_butSaveFile_clicked();
}
//
//void Widget::on_butWRLoadData_clicked()
//{
//
//}
//
//void Widget::on_butConfigureAddr_clicked()
//{
//
//}
//
//void Widget::on_butConfigureMem_clicked()
//{
//
//}

void Widget::on_butRead_clicked()
{
//	ISplashScreen->setLoadingText("Reading Memory in Progress...");
//	ISplashScreen->selectSplashImage(0);
//	ISplashScreen->setSplashStyle("border: 2px solid white;");
//	ISplashScreen->setPos(10,40,150,30);
//	ISplashScreen->ShowSplash();

	clearMemLocations(MAX_MEM_SIZE);
    if(m_nAdressCount <= 0)
    {
        qDebug() << "Address Count is invalid";
       // ui->lblStatus->setText("Address Count is invalid");
        return;
    }

//    ui->lblMEMStatus->setText("Reading..");
   // ui->lblStatus->setText("Reading..");
   // ui->grpSYSTEMMEMORY->setDisabled(false);
    short int l_nAdrCount=0;

    if(ui->chkSingle->isChecked() == true)
    {
 	   callSingleRead();
 	   return;
    }

    if( m_nAdressCount > 255)
    	l_nAdrCount = 255;
    else
    	l_nAdrCount = m_nAdressCount;
    unsigned short int *m_nReadLocations = new unsigned short int[m_nStartAddress+l_nAdrCount];
    if(ui->optSystemMemory->isChecked() == true){
    	if(m_nHWIndex==1)
    		m_nReadLocations = ISPIMemory->readAppCardSystemMemory(m_nStartAddress,l_nAdrCount);
    	else if(m_nHWIndex==0)
    		m_nReadLocations = ISPIMemory->readBackPanelCardSystemMemory(m_nStartAddress,l_nAdrCount);
    	//ui->grpSYSTEMMEMORY->setDisabled(true);
    }
    else if(ui->optFlash->isChecked() == true){
    	//ISPIMemory->checkSPIMemoryRead();
    	m_nReadLocations = ISPIMemory->ReadSPI(m_nStartAddress,l_nAdrCount);
    }
    else if (ui->optRAM->isChecked() == true || ui->optReceiveRAM->isChecked() == true)
    {
    	ISPIMemory->setAutoIncrement();
    	m_nReadLocations = ISPIMemory->readAppCardSRAM(m_nStartAddress,l_nAdrCount);
    }
    for(unsigned short int l_nWaveIndex=0;l_nWaveIndex<MAX_MEM_SIZE;l_nWaveIndex++)
	{
		if(l_nWaveIndex < (m_nStartAddress+l_nAdrCount))
			m_nMEMLOCATIONS[l_nWaveIndex] = m_nReadLocations[l_nWaveIndex];
		else
			m_nMEMLOCATIONS[l_nWaveIndex]=0;
	}
    //clearMemLocations(m_nAdressCount);
    updateTableWidget();
//    ui->lblMEMStatus->setText("");
    //ui->lblStatus->setText("Read Completed.");
  //  ISplashScreen->closeSplash();
   // on_butSaveFile_clicked();
}

void Widget::clearMemLocations(short int pCount)
{
	for(short int l_nIndex=0;l_nIndex<MAX_MEM_SIZE;l_nIndex++)
	{
		if(l_nIndex > pCount)
			m_nMEMLOCATIONS[l_nIndex] =0;
	}
}

void Widget::on_butWrite_clicked()
{
	//ui->lblStatus->setText("Writing..");
//	ISplashScreen->setLoadingText("Writing Memory in Progress...");
//	ISplashScreen->selectSplashImage(0);
//	ISplashScreen->setPos(350,325,300,30);
//	ISplashScreen->ShowSplash();

       if(m_nAdressCount <= 0)
       {
           qDebug() << "Address Count is invalid";
          // ui->lblStatus->setText("Address Count is invalid");
           return;
       }
       if(ui->chkSingle->isChecked() == true)
       {
    	   callSingleDrive();
    	   return;
       }
       unsigned short int *m_nWriteData;
       m_nWriteData = new unsigned short int[m_lstWaveData.count()];

       bool ok=true;
//       ui->lblMEMStatus->setText("Writing..");
       for(int l_nAddressIndex=0;l_nAddressIndex<m_lstWaveData.count();l_nAddressIndex++)
       {
    	  // qDebug() << "Value:"<<l_nAddressIndex;
           QString l_nValue = m_lstWaveData[l_nAddressIndex];
           if (ui->optRAM->isChecked() == true && ui->optSystemMemory->isChecked() == true)
        	   m_nWriteData[l_nAddressIndex] = l_nValue.toUShort(&ok,16) & 0x3FFF;
           else
        	   m_nWriteData[l_nAddressIndex] = l_nValue.toUShort(&ok,16);
          // qDebug()<< "Data:"<<hex<<m_nWriteData[l_nAddressIndex]<<"  "<<l_nValue;
       }
       if(ui->optSystemMemory->isChecked() == true){
    	   if(m_nHWIndex==1)
    		   ISPIMemory->writeAppCardSystemMemory(m_nStartAddress, m_nAdressCount/*m_lstWaveData.count()*/, &m_nWriteData[0]);
    	   else if(m_nHWIndex == 0)
    		   ISPIMemory->writeBackPanelSystemMemory(m_nStartAddress, m_nAdressCount/*m_lstWaveData.count()*/, &m_nWriteData[0]);
       //	ui->grpSYSTEMMEMORY->setDisabled(true);
       }
       else if (ui->optRAM->isChecked() == true || ui->optReceiveRAM->isChecked() == true)
           {
           	ISPIMemory->setAutoIncrement();
           	ISPIMemory->writeAppCardSRAM(m_nStartAddress, m_nAdressCount/*m_lstWaveData.count()*/, &m_nWriteData[0]);
           }
       else if(ui->optFlash->isChecked() == true){
    	   //ISPIMemory->checkSPIMemoryWrite();
    	   qDebug() << "Start Address:"<<m_nStartAddress;
    	   ISPIMemory->writeSPIMemory(m_nStartAddress, m_nAdressCount/*m_lstWaveData.count()*/, &m_nWriteData[0]);
       }
//       ui->lblMEMStatus->setText("");
    //   qDebug()<<"Write Finished";
     //  ui->lblStatus->setText("Write Completed.");
 //      ISplashScreen->closeSplash();
       QMessageBox::information(this,"Write","Write Operation done.",QMessageBox::Ok);
}


void Widget::LoadFile(QString pStrFileName)
{
	//ui->lblStatus->setText("Loading..");
	//qDebug()<<"1";
//	ISplashScreen->setLoadingText("Loading File in Progress...");
//	ISplashScreen->selectSplashImage(0);
//	ISplashScreen->setPos(350,325,300,30);
//	ISplashScreen->ShowSplash();
	try
	{
		m_lstWaveData.clear();
		QFile *l_objDataFile = new QFile(pStrFileName);
		char data[5];
		qint64 l_nLineLength=0;
		QString l_strWaveData;
		bool ok=true;
		//qDebug()<<"2";
		if(l_objDataFile->open(QFile::ReadOnly))
		{
			while(l_nLineLength !=-1)
			{
				l_nLineLength = l_objDataFile->readLine(data,5);
				l_strWaveData.append(data);

				l_strWaveData.remove("\n");
				l_strWaveData.remove("\r");
				//l_strWaveData = l_strWaveData.trimmed();
				if(!l_strWaveData.isEmpty() && l_strWaveData.count() > 0)
					m_lstWaveData.append(l_strWaveData);
				l_strWaveData ="";

		   }
		}
		l_objDataFile->close();
		qDebug()<<"List Loaded";
		for(unsigned short int l_nWaveIndex=0;l_nWaveIndex<MAX_MEM_SIZE;l_nWaveIndex++)
		{
			if(l_nWaveIndex < m_lstWaveData.count())
				m_nMEMLOCATIONS[l_nWaveIndex] = m_lstWaveData.value(l_nWaveIndex).toUShort(&ok,16);
			else
				m_nMEMLOCATIONS[l_nWaveIndex]=0;
			//qDebug()<<"WaveIndex:"<<l_nWaveIndex;

		}
		qDebug() << "File Count:"<<m_lstWaveData.count();

	}
	catch(std::exception& e)
	{
		qDebug()<<"Error";
	}

	//ISplashScreen->closeSplash();
        QMessageBox::information(this,"Load","File Loaded.....",QMessageBox::Ok);

    updateTableWidget();
    //delete data;

}

void Widget::on_cmbHWSelect_currentIndexChanged(int index)
{
    if(index == 0)
    {
        m_nHWIndex=0;
        ISPIMemory->accessSPIMemory(BACKPLANE);
//        qDebug() << "Open for Back Panel";
//        IBackPlane->InitializeBpObject();
//        qDebug()<< "CODE ID:"<< hex<<IBackPlane->readBackPlaneCodeID();

        ui->grpSYSTEMMEMORY->setDisabled(true);
        ui->optDDR->setDisabled(true);
        ui->optRAM->setDisabled(true);
        ui->optReceiveRAM->setDisabled(true);

    	ui->lblIndex->setText("B8000000");

    }
    else if(index == 1)
    {
        m_nHWIndex=1;
        qDebug() << "Open for AppCard";
        ISPIMemory->accessSPIMemory(APPLICATIONCARD);
//        IBackPlane->InitializeBpObject();
//        qDebug()<< "CODE ID:"<< hex<<IBackPlane->readBackPlaneRegister(0);
        ISPIMemory->setHardwarwObject(IAppCard);
        ui->grpSYSTEMMEMORY->setDisabled(false);
        ui->optDDR->setDisabled(true);
        ui->optRAM->setDisabled(false);
        ui->optReceiveRAM->setDisabled(false);
    	ui->lblIndex->setText("B0000000");

    }
}

void Widget::on_optSystemMemory_clicked()
{
    if(m_nHWIndex == 1)
    {
    	qDebug()<< "System Memory check";
    }
    else
    {
    	qDebug() << "Select APP card";
    }
    changeTableIndex(true);
}

void Widget::changeTableIndex(bool pFlag)
{
	short int l_nHeaderCount=0;
	if(pFlag == true)
		l_nHeaderCount = 32;
	else
		l_nHeaderCount = 16;
	QStringList l_lstHeaderLabels;
	for(int l_nIndex=0;l_nIndex<l_nHeaderCount;)
	{
		l_lstHeaderLabels.append(QString::number(l_nIndex,16));
		if(pFlag==true)
			l_nIndex+=2;
		else
			l_nIndex++;
	}
	ui->tableWidget->setHorizontalHeaderLabels(l_lstHeaderLabels);
	ui->tableWidget->setVerticalHeaderLabels(l_lstHeaderLabels);
}

void Widget::on_optFlash_clicked()
{
//	ui->grpSYSTEMMEMORY->setDisabled(true);
	clearTableWidget();
	changeTableIndex(false);
	ui->grpCODEID->setEnabled(true);
	ui->grpMEMErase->setEnabled(true);
	IBackPlane->writeBackPlaneRegister(0x01,0x48);
}

void Widget::on_optRAM_clicked()
{
  //  ui->grpSYSTEMMEMORY->setDisabled(true);
	ISPIMemory->accessSPIRAM(DRIVERAM);
	clearTableWidget();
	changeTableIndex(true);
	ui->grpCODEID->setEnabled(false);
	ui->grpMEMErase->setEnabled(false);
}
void Widget::on_optReceiveRAM_clicked()
{
	ISPIMemory->accessSPIRAM(RECEIVERAM);
	clearTableWidget();
	changeTableIndex(true);
	ui->grpCODEID->setEnabled(false);
	ui->grpMEMErase->setEnabled(false);

}

void Widget::on_optDDR_clicked()
{
    //ui->grpSYSTEMMEMORY->setDisabled(true);
}

void Widget::on_optSlot0_clicked()
{
	IAppCard->setDeviceName(SLOT0);
	IAppCard->enumerateAPPCard();
	ui->lblIndex->setText("B0000000");
}

void Widget::on_optSlot1_clicked()
{
	IAppCard->setDeviceName(SLOT1);
	//IAppCard->enumerateAPPCard();
}

void Widget::on_optSlot2_clicked()
{
	IAppCard->setDeviceName(SLOT2);
	//IAppCard->enumerateAPPCard();

}
void Widget::on_optSlot3_clicked()
{
	IAppCard->setDeviceName(SLOT3);
	//IAppCard->enumerateAPPCard();
}

void Widget::on_optZeros_clicked()
{
	if(ui->optFlash->isChecked() == true)
		m_strFillValue = QString("00");
	else
		m_strFillValue = QString("0000");
	clearTableWidget();
}

void Widget::on_optFFs_clicked()
{
	if(ui->optFlash->isChecked() == true)
		m_strFillValue = QString("FF");
	else
		m_strFillValue = QString("FFFF");

	clearTableWidget();
}

void Widget::on_chkSingle_clicked()
{

}
