#include "muxjig.h"
#include "ui_muxjig.h"
#include <unistd.h>

#include <qgraphicsscene.h>
#include <qgraphicsview.h>


MuxJig::MuxJig(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MuxJig)
{
    ui->setupUi(this);

    QPluginLoader loader("libAppBckPsoc.so",this);
    test = qobject_cast<IPTAppBckPsocInterface*>(loader.instance());

    QPluginLoader loader3("libPTPsocInterface2.so",this);
    IPsoc = qobject_cast<IPSOCCOMMUNICATION*>(loader3.instance());
    IPsoc->openSerial();

	QPluginLoader loaderApp("libPTApplicationcardInterface.so", this);
	IAppCard = qobject_cast<IApplicationCardInterface*> (loaderApp.instance());
	IAppCard->setDeviceName(SLOT0);
	IAppCard->enumerateAPPCard();
	IAppCard->setSPIAppendBit(0xC000);

//    QPluginLoader backplane("libBackPlaneInterface.so",this);
//    IBackPlane = qobject_cast<IntefaceBackPlane*>(backplane.instance());
//    IBackPlane->InitializeBpObject();

//    IBackPlane->writeBackPlaneRegister(1,0x26);

    m_objAD5318Component = new AD5318Components(IAppCard);
	m_objAD5318Component->resetDAC5318(true);
	m_eSelect=DACF;
	m_objAD5318Component->configureADC5318CW();
    AD5318_dataTemplate l_nAD5318DW;
    l_nAD5318DW.m_eDACSelect = m_eSelect;
    l_nAD5318DW.m_bCtrlBit = 0;
    l_nAD5318DW.m_nVout = 0;
    l_nAD5318DW.m_nVRef = 2.5;
    l_nAD5318DW.m_bUniPolor = true;
    l_nAD5318DW.m_bUniPolor = false;
    m_objAD5318Component->configureADC5318Data(l_nAD5318DW);

    m_eSelect=DACG;
    l_nAD5318DW.m_eDACSelect = m_eSelect;
    m_objAD5318Component->configureADC5318Data(l_nAD5318DW);

    IAppCard->writeRegister(0x0001,0x0036);
	IAppCard->writeRegister(0x0007,0x0034);
	IAppCard->writeRegister(0x0000,0x0016);
	IAppCard->writeRegister(0,0x48);

	 IAppCard->setStartStop(1,1);
	 IAppCard->basicTimeUnit(999);
	 IAppCard->basicDuration(0);
	 IAppCard->setDrivePeriod(3);

//    QMessageBox msgBox;
//    if( IPsoc->muxDetection() == 0x00)
//        msgBox.setText("MuxCard Not detected");
//     else
//    	 msgBox.setText("MuxCard detected");
//    msgBox.exec();

//    IPsoc->resetRelays();
//    usleep(1000);
//    IPsoc->writeSerial(0x42);
//    IPsoc->writeSerial(0x9);
//    usleep(1000);
//    IPsoc->writeSerial(0x42);
//    IPsoc->writeSerial(0x15);
//    qDebug()<<"External Measurement Relays Switched";

    for(int testCh=0;testCh<16;testCh++){
        testBut[testCh]=new customRadioButton(testCh,ui->testChannel);
        testBut[testCh]->setGeometry(16+(testCh*47),20,42,40);
        testBut[testCh]->setText(QString::number(testCh,10));
    }
    for(int testCh2=0;testCh2<16;testCh2++){
        testBut[testCh2+16]=new customRadioButton(testCh2+16,ui->testChannel);
        testBut[testCh2+16]->setGeometry(16+(testCh2*47),70,42,40);
        testBut[testCh2+16]->setText(QString::number(testCh2+16,10));
    }
    for(int testCh3=0;testCh3<16;testCh3++){
        testBut[testCh3+32]=new customRadioButton(testCh3+32,ui->testChannel);
        testBut[testCh3+32]->setGeometry(16+(testCh3*47),120,42,40);
        testBut[testCh3+32]->setText(QString::number(testCh3+32,10));
    }
    for(int testCh4=0;testCh4<16;testCh4++){
        testBut[testCh4+48]=new customRadioButton(testCh4+48,ui->testChannel);
        testBut[testCh4+48]->setGeometry(16+(testCh4*47),170,42,40);
        testBut[testCh4+48]->setText(QString::number(testCh4+48,10));
    }

    for(int refCh=0;refCh<16;refCh++){
        refBut[refCh]=new customRadioButton(refCh,ui->refChannel);
        refBut[refCh]->setGeometry(16+(refCh*47),20,42,40);
        refBut[refCh]->setText(QString::number(refCh,10));
    }
    for(int refCh2=0;refCh2<16;refCh2++){
        refBut[refCh2+16]=new customRadioButton(refCh2+16,ui->refChannel);
        refBut[refCh2+16]->setGeometry(16+(refCh2*47),70,42,40);
        refBut[refCh2+16]->setText(QString::number(refCh2+16,10));
    }
    for(int refCh3=0;refCh3<16;refCh3++){
        refBut[refCh3+32]=new customRadioButton(refCh3+32,ui->refChannel);
        refBut[refCh3+32]->setGeometry(16+(refCh3*47),120,42,40);
        refBut[refCh3+32]->setText(QString::number(refCh3+32,10));
    }
    for(int refCh4=0;refCh4<16;refCh4++){
        refBut[refCh4+48]=new customRadioButton(refCh4+48,ui->refChannel);
        refBut[refCh4+48]->setGeometry(16+(refCh4*47),170,42,40);
        refBut[refCh4+48]->setText(QString::number(refCh4+48,10));
    }

    for(int i=0;i<64;i++)
        connect(testBut[i],SIGNAL(customClicked(int)),this,SLOT(switchTestChannel(int)));

    for(int j=0;j<64;j++)
        connect(refBut[j],SIGNAL(customClicked(int)),this,SLOT(switchRefChannel(int)));

    enableRichGUI();
    showFullScreen();

}

void MuxJig::switchTestChannel(int pIndex){

	        	if(ui->extMux->isChecked()){
	        		testSelected=pIndex;
	        		qDebug()<<"Test Channel"<<pIndex<<" selected";
	        	}else{
	        		IPsoc->switchTest(pIndex);
	        		qDebug()<<"Test Channel"<<pIndex<<" switched";
	        	}

}
void MuxJig::switchRefChannel(int pIndex){
	if(ui->extMux->isChecked()){
		refSelected=pIndex;
		qDebug()<<"Reference Channel"<<pIndex<<" selected";
	}else{
		IPsoc->switchRef(pIndex);
		qDebug()<<"Reference Channel"<<pIndex<<" switched";
	}
}

MuxJig::~MuxJig()
{
    delete ui;
}

void MuxJig::changeEvent(QEvent *e)
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

void MuxJig::on_pushButton_clicked()
{
//	IPsoc->externalMuxMeasurement(testSelected,refSelected);
//	QMessageBox msgBox;
//	if(IPsoc->readMuxStatus()==true)
//	        msgBox.setText("Ext Mux Switched");
//	     else
//	    	 msgBox.setText("Ext Mux Not Switched");
//	    msgBox.exec();
	IPsoc->switchTest(testSelected);
	IPsoc->switchRef(refSelected);

}

void MuxJig::on_pushButton_2_clicked()
{
	short l_nHexValue = (0.5+0.6) * ((pow(2,14))-1) / (2 * (0.6));
	unsigned int readRegisterValue;
	IAppCard->setDDSWaveSelect(DC_SIGNAL);
	qDebug()<<"Hex Value:"<<hex<<l_nHexValue;
	for(unsigned int ref=0;ref<1;ref++){
		for(unsigned int test=1;test<2;test++){
			IPsoc->externalMuxMeasurement(test,ref);
			if(IPsoc->readMuxStatus()==true){
				IAppCard->writeRegister(l_nHexValue,0x76);
				IAppCard->startDrive(1);
				usleep(20000);
				while(!IAppCard->readRegister(0x12)&0x0001);
			}
			else
			{

			}
		}
	}
	readRegisterValue=IAppCard->readRegister(0x96);
	qDebug()<<"Receive value:"<<hex<<readRegisterValue;

}

void MuxJig::on_reset_clicked()
{
    QByteArray psocData;

            QMessageBox failure;
            failure.setText("PSOC RESET FAILURE");
            IPsoc->writeSerial(0xff);
            IPsoc->writeSerial(0xff);
            psocData = IPsoc->readSerByte();
            if (psocData.endsWith("*?") == true) {
                    qDebug() << "PSOC RESET DONE on 1st try";
            } else {
                    IPsoc->writeSerial(0xff);
                    psocData = IPsoc->readSerByte();
                    if (psocData.endsWith("*?") == true) {
                            qDebug() << "PSOC RESET DONE on 2nd try";
                    } else {
                            IPsoc->writeSerial(0xff);
                            psocData = IPsoc->readSerByte();
                            if (psocData.endsWith("*?") == true) {
                                    qDebug() << "PSOC RESET DONE on 3rd try";
                            } else {
                                    failure.exec();
                            }

                    }
            }

            qDebug() << "RESET DATA:" << psocData;
}

void MuxJig::on_reset_2_clicked()
{
    QWidget *newWidget=test->getPTAppBckPsoc();
                        newWidget->setWindowTitle("AppCard BackPanel PSoC Panel");
                        newWidget->show();
}

void MuxJig::on_resetTestCh_clicked()
{
    IPsoc->switchTest(0xff);
}

void MuxJig::on_resetRefCh_clicked()
{
    IPsoc->switchRef(0xff);
}

void MuxJig::on_resetBothCh_clicked()
{
    IPsoc->externalMuxMeasurement(0xff,0xff);
	QMessageBox msgBox;
    if(IPsoc->readMuxStatus()==true)
    	        msgBox.setText("Both Mux Reset Done");
    	     else
    	    	 msgBox.setText("Both Mux Reset Not Done");
    	    msgBox.exec();
}

void MuxJig::on_pushButton_5_clicked()
{
    this->close();
}
void MuxJig::enableRichGUI(){
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
	ui->refChannel->setParent(m_objWidget);
	ui->testChannel->setParent(m_objWidget);

	ui->groupBox->setGeometry(10,	450,	780,	121);
	ui->refChannel->setGeometry(10,	230,	780,	220);
	ui->testChannel->setGeometry(10,	10,	780,	220);


}

void MuxJig::on_switchExtMux_clicked()
{
    qDebug()<<"External Measurement Relays Switched";
                IPsoc->resetRelays();
                usleep(1000);
                IPsoc->writeSerial(0x42);
                IPsoc->writeSerial(0x9);
                usleep(1000);
                IPsoc->writeSerial(0x42);
                IPsoc->writeSerial(0x15);
}

void MuxJig::on_readCodeId_clicked()
{
    QMessageBox msgBox;
    unsigned int rxMux=IPsoc->muxDetection();
    if( rxMux==0x00){
    	qDebug()<<"Received:"<<hex<<rxMux;
    	msgBox.setText("CodeID Failure");
    }
     else{
    	msgBox.setText("CodeID Sucess");
     }
    msgBox.exec();
}
