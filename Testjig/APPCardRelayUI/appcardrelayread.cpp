#include "appcardrelayread.h"
#include "ui_appcardrelayread.h"

AppCardRelayRead::AppCardRelayRead(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AppCardRelayRead)
{
    ui->setupUi(this);
    //background-color: rgb(170, 0, 0);
    connect(this,SIGNAL(bitSelected(bool,short)),this,SLOT(changeColor(bool,short)));

    setRelayPanel();
    m_nICMVIrlyDetails =0;
    m_nRelayDetails=0;

    Initialization();
	//updateRelayStatus(0);

}
void AppCardRelayRead::Initialization(){
    QPluginLoader loaderLib("libQmaxPTInterface.so",this);
    ILineEdit = qobject_cast<IQmaxLineEdit*>(loaderLib.instance());
    INumberPanel=qobject_cast<IQmaxNumberPanel*>(loaderLib.instance());

    qDebug()<< "Application Card Relay Loaded";
     QPluginLoader loaderApp("libPTApplicationcardInterface.so",this);
     IAppCard = qobject_cast<IApplicationCardInterface*>(loaderApp.instance());
     qDebug() << "Appcard" <<IAppCard;
     IAppCard->setDeviceName(SLOT0);
     IAppCard->enumerateAPPCard();
     qDebug() << "Code ID:"<<hex<< IAppCard->readAppCardCodeId();

	//ui->objADDR->setVisible(false);
	objAddress=ILineEdit->QmaxLineEdit(1, ui->groupBox_3);
	objAddress->setGeometry(120, 20, 161, 41);
	objAddress->setFont(QFont("DejaVu Sans",13,50,false));

	//ui->objDATA->setVisible(false);
	objData=ILineEdit->QmaxLineEdit(2, ui->groupBox_3);
	objData->setGeometry(120, 80, 161, 41);
	objData->setFont(QFont("DejaVu Sans",13,50,false));

	objData->setStyleSheet(		"border-width: 2px;border-style: outset;border-color: gray; border-radius: 10px;  padding: 0 8px;     background: black;     selection-background-color: yellow;   color:white;     font: bold 14px;"    );
	objAddress->setStyleSheet(	"border-width: 2px;border-style: outset;border-color: gray; border-radius: 10px;  padding: 0 8px;     background: black;     selection-background-color: yellow;   color:white;     font: bold 14px;"    );

	connect(objAddress,   SIGNAL(focussed(bool)), this, SLOT(callAddressEdit()));
	connect(objData,      SIGNAL(focussed(bool)), this, SLOT(callDataEdit()));

	enableRichGUI();
}
void AppCardRelayRead::enableRichGUI(){
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

	ui->grpReceRly  -> setParent(m_objWidget);
	ui->grpdrvRelays-> setParent(m_objWidget);
	ui->groupBox_3  -> setParent(m_objWidget);
	ui->grpICMVIRly -> setParent(m_objWidget);
	ui->butReadRelay->setParent(m_objWidget);

	ui->grpReceRly  -> setGeometry(20,10,381,221);
	ui->grpdrvRelays-> setGeometry(20,240,381,151);
	ui->groupBox_3  -> setGeometry(460,10,291,201);
	ui->grpICMVIRly -> setGeometry(410,240,381,151);
	ui->butReadRelay->setGeometry(340,410,141,51);
}
void AppCardRelayRead::receiveValue(unsigned int pValue){
	if(m_nLineEditIndex==1){
		objAddress->setText(QString::number(pValue,16));
		m_nAddressValue = pValue;
	}
	if(m_nLineEditIndex==2){
		objData->setText(QString::number(pValue,16));
		m_nDataValue = pValue;
	}
}
void AppCardRelayRead::receiveValue(double pValue){
	Q_UNUSED(pValue)

}
void AppCardRelayRead::receiveValue(QString pValue){
	Q_UNUSED(pValue)
}
void AppCardRelayRead::callAddressEdit() {
	if (objAddress->hasFocus()) {
		openNumKBPanel(0);
		m_nLineEditIndex = 1;
	}
}

void AppCardRelayRead::callDataEdit() {
	if (objData->hasFocus()) {
		openNumKBPanel(0);
		m_nLineEditIndex = 2;
	}

}
void AppCardRelayRead::openNumKBPanel(short int pValue) {

	QWidget *w = INumberPanel->getNumKBPanel(pValue, this);
	w->setWindowFlags(Qt::WindowCloseButtonHint | Qt::Dialog);
	w->show();
}
void AppCardRelayRead::openNumKBPanel(short int pValue,double incRatio,char type,double max,double min,QWidget* parent) {

	QWidget *w = INumberPanel->getNumKBPanelIncDec(pValue,incRatio,type,max,min,parent);
	w->setWindowFlags(Qt::WindowCloseButtonHint | Qt::Dialog);
	w->show();
}
void AppCardRelayRead::setRelayPanel()
{
    int l_nXPos=0,l_nYPos=0;
    int l_nRowIndex=1;
    //Loop for Drive Relay
    for(int l_nButtonIndex=0;l_nButtonIndex<9;l_nButtonIndex++)
    {
        m_objPushButtons[l_nButtonIndex] = new QPushButton(ui->grpdrvRelays);
        m_objPushButtons[l_nButtonIndex]->setGeometry(20+l_nXPos,20+l_nYPos,50,50);
        m_objPushButtons[l_nButtonIndex]->setText("RL" +QString::number(l_nRowIndex,10));
        m_objPushButtons[l_nButtonIndex]->setStyleSheet("background-color: rgb(170, 0, 0);color: rgb(85, 255, 255);");
        m_objPushButtons[l_nButtonIndex]->setDisabled(true);
        if(l_nRowIndex%6==0)
        {
            l_nXPos =0;
            l_nYPos +=70;
        }
        else
        {
            l_nXPos +=60;
        }
        l_nRowIndex++;
    }
    l_nRowIndex=1;
    l_nXPos=0;l_nYPos=0;
    // Loop for Receive Relay
    for(int l_nButtonIndex=9;l_nButtonIndex<28;l_nButtonIndex++)
    {
        m_objPushButtons[l_nButtonIndex] = new QPushButton(ui->grpReceRly);
        m_objPushButtons[l_nButtonIndex]->setGeometry(20+l_nXPos,20+l_nYPos,50,50);
        m_objPushButtons[l_nButtonIndex]->setText("RL" +QString::number(l_nRowIndex+9,10));
        m_objPushButtons[l_nButtonIndex]->setStyleSheet("background-color: rgb(170, 0, 0);color: rgb(85, 255, 255);");
        m_objPushButtons[l_nButtonIndex]->setDisabled(true);


        if(l_nRowIndex%6==0)
        {
            l_nXPos =0;
            l_nYPos +=70;
        }
        else
        {
            l_nXPos +=60;
        }
        l_nRowIndex++;
    }
    // Loop for ICM/VI Piggy
    l_nRowIndex=1;
    l_nXPos=0;l_nYPos=0;
    // Loop for Receive Relay
    for(int l_nButtonIndex=0;l_nButtonIndex<9;l_nButtonIndex++)
    {
        m_objICMVIButtons[l_nButtonIndex] = new QPushButton(ui->grpICMVIRly);
        m_objICMVIButtons[l_nButtonIndex]->setGeometry(20+l_nXPos,20+l_nYPos,50,50);
        m_objICMVIButtons[l_nButtonIndex]->setText("RL" +QString::number(l_nRowIndex,10));
        m_objICMVIButtons[l_nButtonIndex]->setStyleSheet("background-color: rgb(170, 0, 0);color: rgb(85, 255, 255);");
        m_objICMVIButtons[l_nButtonIndex]->setDisabled(true);


        if(l_nRowIndex%6==0)
        {
            l_nXPos =0;
            l_nYPos +=70;
        }
        else
        {
            l_nXPos +=60;
        }
        l_nRowIndex++;
    }

}


AppCardRelayRead::~AppCardRelayRead()
{
//    delete []m_objPushButtons;
//    delete []m_objICMVIButtons;
    qDebug()<< "Application Card Relay Destroyed";
    delete ui;
}

void AppCardRelayRead::changeEvent(QEvent *e)
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

void AppCardRelayRead::readICMVIPiggyRelays()
{
    // Sequence of ICM/VI Piggy Reads
    //[[----------------------------- Drive Relay Status-------------------------------------
    // 1. Read Register - 0x3A
    unsigned short l_nReadRegister = IAppCard->getICMRangeGain();
    if((l_nReadRegister & 0x0020) == 0x0020)
    {
        m_nICMVIrlyDetails = 1; // RL1
    }
    /* RL2 - RL7 - Source Impednace Selection Bit[2:0] - 0x3A
       [2 1 0]
        0 0 0  - 10 E
        0 0 1  - 100 E
        0 1 0  - 1 KE
        0 1 1  - 10 KE
        1 0 0  - 100 KE
        1 0 1  - 1 ME
        1 1 0  - RESERVED
        1 1 1  - RESERVED
    */
    for(int l_nSImpIndex=0;l_nSImpIndex<6;l_nSImpIndex++)
    {
        if((l_nReadRegister & 0x0007) == l_nSImpIndex)
        {
            m_nICMVIrlyDetails |= 1<<(l_nSImpIndex+1);
            qDebug() << "Relay Selected:"<<"RLY"<<l_nSImpIndex+2;
            break;
        }
    }
    if((l_nReadRegister & 0x0010) == 0x0010)
    {
        m_nICMVIrlyDetails |= 1<<7; // RL8
    }
    if((l_nReadRegister & 0x0008) == 0x0008)
    {
        m_nICMVIrlyDetails |= 1<<8; // RL9
    }
//--------------------------------------------------------------------------------------]]
}

void AppCardRelayRead::readDrvRecvRelays()
{
    // Sequence of Relay Reads
    //[[----------------------------- Drive Relay Status-------------------------------------
    // 1. Read Drive Source Amplitude Register - 0x16
    unsigned short l_nReadRegister = IAppCard->getDriveSourceAmplitudeRegister();
    m_nRelayDetails=0;
    qDebug() << "DSAR:"<<l_nReadRegister;
    // D[0] -- RL1
    // D[3] -- RL2
    if((l_nReadRegister & 0x0001) == 0x1)
        m_nRelayDetails = 1;
    if((l_nReadRegister & 0x0008) == 0x8)
        m_nRelayDetails |= 1<<1;
    qDebug() << " DSAR RelayDetails:"<<m_nRelayDetails;
    // 2. Read Drive and Receive source Select Register - 0x34
    // D[0] -- RL3
    // D[1] -- RL4
    // D[2] -- RL5
    l_nReadRegister = IAppCard->getDriveReceiveSourceSelect();
    if((l_nReadRegister & 0x0001) == 0x1)
        m_nRelayDetails |= 1<<2;
     //qDebug() << " RelayDetails:"<<hex<<m_nRelayDetails<<(l_nReadRegister & 0x2);
    if((l_nReadRegister & 0x0002) == 0x2)
        m_nRelayDetails |= 1<<3;
    //qDebug() << " RelayDetails:"<<hex<<m_nRelayDetails;

    if((l_nReadRegister & 0x0004) == 0x4)
        m_nRelayDetails |= 1<<4;

    qDebug() << " DRSR RelayDetails:"<<hex<<m_nRelayDetails;
    // D[2:1] -- RL6 to RL9
    /*
        00  -- RL6
        01  -- RL7
        10  -- RL8
        11  -- RL9
     */
    l_nReadRegister =IAppCard->getDriveSourceAmplitudeRegister(); //IAppCard->getDriveReceiveGainRegister();
    if((l_nReadRegister & 0x0006)== 0x00){
        qDebug() << "RL6";
        m_nRelayDetails |= 1<<5;
    }
    else if((l_nReadRegister & 0x0006) == 0x2){
        qDebug() << "RL7";
        m_nRelayDetails |= 1<<6;
    }
    else if((l_nReadRegister & 0x0006) == 0x4)
    {
        qDebug() << "RL8";
        m_nRelayDetails |= 1<<7;
    }
    else if((l_nReadRegister & 0x0006) == 0x6)
    {
        qDebug() << "RL9";
        m_nRelayDetails |= 1<<8;
    }
    qDebug() << " DRGR RelayDetails:"<<hex<<m_nRelayDetails<<(l_nReadRegister & 0x0)<<(l_nReadRegister & 0x20);
    //---------------------------------------------------------------------------------------]]

    //[[----------------------------- Receive Relay Status-------------------------------------
        // 1. Read Drive Source Amplitude Register - 0x36 & 0x38
        /* RL10 -- D[0] -0X36
           RL11 -- D[6]- 0x36
           RL12 -- D[8:7] 00 - AC & 01 - DC -0X36
           RL13 -- D[8:7] 1X - GND -0X36
           -------------------------
           RL14 -- D[1] -- 0x38
           RL15 -- D[0] -- 0x38
           RL16 -- D[8:7] 00 -- DC Coup & 01 AC Coup
           RL17 -- D[1] -- 0x38
           RL18 -- D[8:7] -- 0x38 1X -- Gnd Coup
           ---------------------------------
           RL20 -- D[5] -- 0x36
           RL21 -- D[6] -- 0x38
           RL22 -- D[1] -- 0x36
           RL23 -- D[1] -- 0x36
           ---------------------------------
           RL24 -- D[2] -- 0x38
           RL25 -- D[2] -- 0x38
           RL26 -- D[2] -- 0x36
           RL27 -- D[3] -- 0x38
         */
    l_nReadRegister = IAppCard->getReceiversConfiguration(RECEIVER1);
    if((l_nReadRegister & 0x0001) == 0x0001) // RL10
    {
        m_nRelayDetails |= 1<<9;
    }
    if((l_nReadRegister & 0x0040) == 0x0040) // RL11
    {
        m_nRelayDetails |= 1<<10;
    }
    if((l_nReadRegister & 0x0100) == 0x0000) // RL12
    {
        m_nRelayDetails |= 0<<11;
        qDebug() << "DC";
    }
    else if((l_nReadRegister & 0x0100) == 0x0100) // RL12
    {
        m_nRelayDetails |= 1<<11;
        qDebug() << "AC";
    }
    if((l_nReadRegister & 0x0180) == 0x0180 || (l_nReadRegister & 0x0100) == 0x0100) // RL13
    {
        m_nRelayDetails |= 1<<12;
    }
    if((l_nReadRegister & 0x0020) == 0x0020) // RL20
    {
        m_nRelayDetails |= 1<<19;
    }
    if((l_nReadRegister & 0x0002) == 0x0002) // RL22 & RL23
    {
        m_nRelayDetails |= 1<<21;
        m_nRelayDetails |= 1<<22;
    }
    if((l_nReadRegister & 0x0004) == 0x0004) // RL26
    {
        m_nRelayDetails |= 1<<25;
    }



    l_nReadRegister = IAppCard->getReceiversConfiguration(RECEIVER2);// 0x38
    if((l_nReadRegister & 0x0002) == 0x0002) // RL14 & RL17
    {
        m_nRelayDetails |= 1<<13;
        m_nRelayDetails |= 1<<16;
    }
    if((l_nReadRegister & 0x0001) == 0x0001) // RL15
    {
        m_nRelayDetails |= 1<<14;
    }
    if((l_nReadRegister & 0x0100) == 0x0000) // RL16
    {
        m_nRelayDetails |= 0<<15;
        qDebug() << "DC";
    }
    else if((l_nReadRegister & 0x0100) == 0x0100) // RL16
    {
        m_nRelayDetails |= 1<<15;
        qDebug() << "AC";
    }
    if((l_nReadRegister & 0x0180) == 0x0180 || (l_nReadRegister & 0x0100) == 0x0100) // RL18
    {
        m_nRelayDetails |= 1<<17;
    }
    if((l_nReadRegister & 0x0040) == 0x0040) // RL21
    {
        m_nRelayDetails |= 1<<20;
    }
    if((l_nReadRegister & 0x0004) == 0x0004) // RL24 & RL25
    {
        m_nRelayDetails |= 1<<23;
        m_nRelayDetails |= 1<<24;
    }
    if((l_nReadRegister & 0x0008) == 0x0008) // RL27
    {
        m_nRelayDetails |= 1<<26;
    }
    l_nReadRegister = IAppCard->getDriveReceiveGainRegister(); // Read 0x48 Register
    if((l_nReadRegister & 0x0010) == 0x0010) // RL19
    {
        m_nRelayDetails |= 1<<18;
    }
    qDebug() << "Relay Details:"<<hex<<m_nRelayDetails;
}


void AppCardRelayRead::on_butREAD_clicked()
{
	qDebug()<<"inside read relay";
	unsigned int l_nValue = IAppCard->readRegister(m_nAddressValue);
	qDebug()<< "RAddress:"<<hex<<m_nAddressValue<<"RData:"<<l_nValue;
    objData->setText(QString::number(l_nValue,16));

}

void AppCardRelayRead::on_butWrite_clicked()
{
	qDebug()<<"inside relay write";
	qDebug()<< "Address:"<<hex<<m_nAddressValue<<"Data:"<<m_nDataValue;
	IAppCard->writeRegister(m_nDataValue,m_nAddressValue);
}

void AppCardRelayRead::on_butReadRelay_clicked()
{
	//updateICMVIRelayStatus(0);
    readDrvRecvRelays();
    readICMVIPiggyRelays();
    // update the Relay Status
    m_nRelayPoint = false;
    updateRelayStatus(m_nRelayDetails);
    //update the ICM / VI Piggy relay status
    m_nRelayPoint = true;
    updateICMVIRelayStatus(m_nICMVIrlyDetails);
}

void AppCardRelayRead::updateICMVIRelayStatus(unsigned int pRlyStatus)
{
    for(short l_nIndex=0;l_nIndex<9;l_nIndex++)
    {
        unsigned int l_nBitValue = pRlyStatus &  (1 << l_nIndex);
        if( l_nBitValue )
        {
            emit bitSelected(true,l_nIndex);
        }
        else
        {
            emit bitSelected(false,l_nIndex);
        }
    }
}

void AppCardRelayRead::updateRelayStatus(unsigned int pRlyStatus)
{
    for(short l_nIndex=0;l_nIndex<28;l_nIndex++)
    {
        unsigned int l_nBitValue = pRlyStatus &  (1 << l_nIndex);

        if( l_nBitValue )
        {
        	//qDebug() << "Bit Value True:"<<l_nBitValue<<l_nIndex;
            emit bitSelected(true,l_nIndex);
        }
        else
        {
        	//qDebug() << "Bit Value false:"<<l_nBitValue<<l_nIndex;
            emit bitSelected(false,l_nIndex);
        }
        //qDebug() << "Rly Index:"<<hex<<l_nBitValue;
    }
}

void AppCardRelayRead::changeColor(bool pValue, short pIndex)
{
   // qDebug() << "Flag and Index:"<<pValue<<pIndex;
    if(pValue == true)
        if(m_nRelayPoint == false)
            m_objPushButtons[pIndex]->setStyleSheet("background-color: rgb(0, 170, 0);color: rgb(85, 255, 255);");
        else
            m_objICMVIButtons[pIndex]->setStyleSheet("background-color: rgb(0, 170, 0);color: rgb(85, 255, 255);");
    else
        if(m_nRelayPoint == false)
            m_objPushButtons[pIndex]->setStyleSheet("background-color: rgb(170, 0, 0);color: rgb(85, 255, 255);");
        else
            m_objICMVIButtons[pIndex]->setStyleSheet("background-color: rgb(170, 0, 0);color: rgb(85, 255, 255);");
}
