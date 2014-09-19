#include "ad9102ui.h"
#include "ui_ad9102ui.h"

#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>
#include <QFile>
#include <QGraphicsScene>
#include <QGraphicsView>

AD9102UI::AD9102UI(QWidget *parent) :
QWidget(parent),
ui(new Ui::AD9102UI)
{
	ui->setupUi(this);

	QPluginLoader loaderApp("libPTApplicationcardInterface.so", this);
	IAppCard = qobject_cast<IApplicationCardInterface*> (loaderApp.instance());
	IAppCard->setDeviceName(SLOT0);
	IAppCard->enumerateAPPCard();
	AD9102=new AD9102Component(IAppCard);

	QPluginLoader loader4("libQmaxPTInterface.so",this);
	ILineEdit = qobject_cast<IQmaxLineEdit*>(loader4.instance());
	INumberPanel=qobject_cast<IQmaxNumberPanel*>(loader4.instance());

	ui->le_Address->setVisible(false);
	objAddress=ILineEdit->QmaxLineEdit(1, ui->grpBox_ReadWrite);
	objAddress->setGeometry(ui->le_Address->geometry());
	objAddress->setFont(QFont("DejaVu Sans",13,50,false));

	ui->le_Data->setVisible(false);
	objData=ILineEdit->QmaxLineEdit(2, ui->grpBox_ReadWrite);
	objData->setGeometry(ui->le_Data->geometry());
	objData->setFont(QFont("DejaVu Sans",13,50,false));

	ui->le_AppAddress->setVisible(false);
	objAppAddress=ILineEdit->QmaxLineEdit(3, ui->grpBox_AppReadWrite);
	objAppAddress->setGeometry(ui->le_AppAddress->geometry());
	objAppAddress->setFont(QFont("DejaVu Sans",13,50,false));

	ui->le_AppData->setVisible(false);
	objAppData=ILineEdit->QmaxLineEdit(4, ui->grpBox_AppReadWrite);
	objAppData->setGeometry(ui->le_AppData->geometry());
	objAppData->setFont(QFont("DejaVu Sans",13,50,false));

	ui->le_Delay->setVisible(false);
	objDelay=ILineEdit->QmaxLineEdit(5, ui->grpBox_Test);
	objDelay->setGeometry(ui->le_Delay->geometry());
	objDelay->setFont(QFont("DejaVu Sans",13,50,false));

        ui->le_SRAMAddress->setVisible(false);
        objSRAMAddress=ILineEdit->QmaxLineEdit(6, ui->grpBox_SRAMReadWrite);
        objSRAMAddress->setGeometry(ui->le_SRAMAddress->geometry());
        objSRAMAddress->setFont(QFont("DejaVu Sans",13,50,false));

        ui->le_SRAMData->setVisible(false);
        objSRAMData=ILineEdit->QmaxLineEdit(7, ui->grpBox_SRAMReadWrite);
        objSRAMData->setGeometry(ui->le_SRAMData->geometry());
        objSRAMData->setFont(QFont("DejaVu Sans",13,50,false));

        ui->le_SRAMStartAddress->setVisible(false);
        objSRAMStartddress=ILineEdit->QmaxLineEdit(8, ui->grpBox_SRAMUpdate);
        objSRAMStartddress->setGeometry(ui->le_SRAMStartAddress->geometry());
        objSRAMStartddress->setFont(QFont("DejaVu Sans",13,50,false));

        ui->le_SRAMCount->setVisible(false);
        objSRAMCount=ILineEdit->QmaxLineEdit(9, ui->grpBox_SRAMUpdate);
        objSRAMCount->setGeometry(ui->le_SRAMCount->geometry());
        objSRAMCount->setFont(QFont("DejaVu Sans",13,50,false));

        ui->le_Frequency->setVisible(false);
        objFrequency=ILineEdit->QmaxLineEdit(10, ui->grpBox_Parameters);
        objFrequency->setGeometry(ui->le_Frequency->geometry());
        objFrequency->setFont(QFont("DejaVu Sans",13,50,false));

        ui->le_Phase->setVisible(false);
        objPhase=ILineEdit->QmaxLineEdit(11, ui->grpBox_Parameters);
        objPhase->setGeometry(ui->le_Phase->geometry());
        objPhase->setFont(QFont("DejaVu Sans",13,50,false));

        connect(objAddress,         SIGNAL(focussed(bool)), this, SLOT(callAddressEdit()));
        connect(objData,            SIGNAL(focussed(bool)), this, SLOT(callDataEdit()));
        connect(objAppAddress,      SIGNAL(focussed(bool)), this, SLOT(callAppAddressEdit()));
        connect(objAppData,         SIGNAL(focussed(bool)), this, SLOT(callAppDataEdit()));
        connect(objDelay,           SIGNAL(focussed(bool)), this, SLOT(callDelay()));
        connect(objSRAMAddress,     SIGNAL(focussed(bool)), this, SLOT(callSRAMAddress()));
        connect(objSRAMData,        SIGNAL(focussed(bool)), this, SLOT(callSRAMData()));
        connect(objSRAMStartddress, SIGNAL(focussed(bool)), this, SLOT(callSRAMStartAddress()));
        connect(objSRAMCount,       SIGNAL(focussed(bool)), this, SLOT(callSRAMCount()));
        connect(objFrequency,       SIGNAL(focussed(bool)), this, SLOT(callFrequency()));
        connect(objPhase,           SIGNAL(focussed(bool)), this, SLOT(callPhase()));

//	IAppCard->writeRegister(0x03,0xDE);
	m_bTriggerState=true;
        m_bRunStop=false;
	m_nAddress=m_nData=m_nAppAddress=m_nAppData=m_nLineEditIndex=0.0;
	m_nDelay=1000;

	QDir path("/home/regval_files");
	RegvalFiles = path.entryList(QDir::Files);
	ui->comboBox->addItems(RegvalFiles);

	m_nSRAMStartddress=0x6000;
	m_nSRAMCount=4095;

	enableRichGUI();
}
void AD9102UI::enableRichGUI(){
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

	ui->grpBox_AppReadWrite->setParent(m_objWidget);
        ui->grpBox_AppReadWrite->setGeometry(273,0,250,210);

	ui->grpBox_ReadWrite->setParent(m_objWidget);
        ui->grpBox_ReadWrite->setGeometry(10,0,250,210);

	ui->grpBox_Test->setParent(m_objWidget);
        ui->grpBox_Test->setGeometry(10,220,511,210);

        ui->grpBox_SRAMReadWrite->setParent(m_objWidget);
        ui->grpBox_SRAMReadWrite->setGeometry(535,0,250,211);

        ui->grpBox_SRAMUpdate->setParent(m_objWidget);
        ui->grpBox_SRAMUpdate->setGeometry(535,220,250,211);

        ui->grpBox_Parameters->setParent(m_objWidget);
        ui->grpBox_Parameters->setGeometry(10,440,773,80);

}
void AD9102UI::receiveValue(unsigned int pValue){
	if(m_nLineEditIndex==1){
		m_nAddress=(unsigned short)pValue;
	}
	else if(m_nLineEditIndex==2){
		m_nData=(unsigned short)pValue;
	}
        else if(m_nLineEditIndex==3){
		m_nAppAddress=pValue;
	}
	else if(m_nLineEditIndex==4){
		m_nAppData=pValue;
	}
        else if(m_nLineEditIndex==6){
                m_nSRAMAddress=(unsigned short)pValue;
        }
        else if(m_nLineEditIndex==7){
                m_nSRAMData=(unsigned short)pValue;
        }
        else if(m_nLineEditIndex==8){
                m_nSRAMStartddress=(unsigned short)pValue;
        }

}
void AD9102UI::receiveValue(double pValue){
	if(m_nLineEditIndex==5){
		m_nDelay=pValue*1000000;
	}
        else if(m_nLineEditIndex==9){
                m_nSRAMCount=pValue;
        }
        else if(m_nLineEditIndex==10){
                m_nFrequency=pValue;
                qDebug()<<"Frequency:"<<m_nFrequency;

                unsigned int m_nFTW_LSW,m_nFTW_MSW;
                double OutputFrequency=(m_nFrequency/180e6)*pow(2,24);

                qDebug()<<"Frequency Tunning Word:"<<OutputFrequency <<"Hex:"<<hex<<OutputFrequency;

                ui->lbl_HexFrequency->setText("0X"+QString::number((unsigned int)OutputFrequency,16));

                m_nFTW_LSW = (unsigned int) OutputFrequency << 8 & 0xFFFF;
                m_nFTW_MSW = (unsigned int) OutputFrequency >> 8 ;

                qDebug() << "FTW_MSW" << hex << m_nFTW_MSW;
                qDebug() << "FTW_LSW" << hex << m_nFTW_LSW;

                AD9102->writeAD9102SPI(0x3E,m_nFTW_MSW);
                AD9102->writeAD9102SPI(0x3F,m_nFTW_LSW);
                AD9102->writeAD9102SPI(0x001D,0x01);
        }
        else if(m_nLineEditIndex==11){
                m_nPhase=pValue;
                qDebug()<<"Phase:"<<m_nPhase;

                unsigned int m_nPTW;
        		double m_nOutputPhase = (((pow(2,24))-1)*m_nPhase)/360;

        		qDebug()<<"Phase Tunning Word:"<<m_nOutputPhase <<"Hex:"<<hex<<m_nOutputPhase;

        		m_nPTW=(unsigned int)m_nOutputPhase >> 8;

        		ui->lbl_HexPhase->setText("0X"+QString::number(m_nPTW,16));

        		AD9102->writeAD9102SPI(0x43,m_nPTW);
        		AD9102->writeAD9102SPI(0x001D,0x01);
        }
}
void AD9102UI::receiveValue(QString pValue){
	if(m_nLineEditIndex==1){
		objAddress->setText(pValue);
	}
	else if(m_nLineEditIndex==2){
		objData->setText(pValue);
	}
        else if(m_nLineEditIndex==3){
		objAppAddress->setText(pValue);
	}
	else if(m_nLineEditIndex==4){
		objAppData->setText(pValue);
	}
	else if(m_nLineEditIndex==5){
		objDelay->setText(pValue);
	}
        else if(m_nLineEditIndex==6){
                objSRAMAddress->setText(pValue);
        }
        else if(m_nLineEditIndex==7){
                objSRAMData->setText(pValue);
        }
        else if(m_nLineEditIndex==8){
                objSRAMStartddress->setText(pValue);
        }
        else if(m_nLineEditIndex==9){
                objSRAMCount->setText(pValue);
        }
        else if(m_nLineEditIndex==10){
                objFrequency->setText(pValue);
        }
        else if(m_nLineEditIndex==11){
                objPhase->setText(pValue);
        }

}

void AD9102UI::callAddressEdit() {
	if (objAddress->hasFocus()) {
		openNumKBPanel(0);
		m_nLineEditIndex = 1;
	}
}

void AD9102UI::callDataEdit() {
	if (objData->hasFocus()) {
		openNumKBPanel(0);
		m_nLineEditIndex = 2;
	}

}
void AD9102UI::callAppAddressEdit() {
	if (objAppAddress->hasFocus()) {
		openNumKBPanel(0);
		m_nLineEditIndex = 3;
	}
}

void AD9102UI::callAppDataEdit() {
	if (objAppData->hasFocus()) {
		openNumKBPanel(0);
		m_nLineEditIndex = 4;
	}

}
void AD9102UI::callDelay() {
	if (objDelay->hasFocus()) {
		openNumKBPanel(1,1,'T',1000,0,this);
		m_nLineEditIndex = 5;
	}

}
void AD9102UI::callSRAMAddress(){
        if (objSRAMAddress->hasFocus()) {
                openNumKBPanel(0);
                m_nLineEditIndex = 6;
        }

}
void AD9102UI::callSRAMData() {
        if (objSRAMData->hasFocus()) {
                openNumKBPanel(0);
                m_nLineEditIndex = 7;
        }
}

void AD9102UI::callSRAMStartAddress(){
        if (objSRAMStartddress->hasFocus()) {
                openNumKBPanel(0);
                m_nLineEditIndex = 8;
        }

}
void AD9102UI::callSRAMCount() {
        if (objSRAMCount->hasFocus()) {
                openNumKBPanel(1);
                m_nLineEditIndex = 9;
        }

}
void AD9102UI::callFrequency() {
        if (objFrequency->hasFocus()) {
                openNumKBPanel(1,1,'F',20000000,0,this);
                m_nLineEditIndex = 10;
        }

}
void AD9102UI::callPhase() {
        if (objPhase->hasFocus()) {
                openNumKBPanel(1,1,'D',5000000,0,this);
                m_nLineEditIndex = 11;
        }

}
void AD9102UI::openNumKBPanel(short int pValue) {

	QWidget *w = INumberPanel->getNumKBPanel(pValue, this);
	w->setWindowFlags(Qt::WindowCloseButtonHint | Qt::Dialog);
	w->show();
}
void AD9102UI::openNumKBPanel(short int pValue,double incRatio,char type,double max,double min,QWidget* parent) {

	QWidget *w = INumberPanel->getNumKBPanelIncDec(pValue,incRatio,type,max,min,parent);
	w->setWindowFlags(Qt::WindowCloseButtonHint | Qt::Dialog);
	w->show();
}

AD9102UI::~AD9102UI()
{
	delete ui;
}

void AD9102UI::changeEvent(QEvent *e)
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

void AD9102UI::on_pb_Read_clicked()
{
	unsigned short l_nData=AD9102->readAD9102SPI(m_nAddress);
	objData->setText(QString::number(l_nData,16));
}

void AD9102UI::on_pb_Write_clicked()
{
	AD9102->writeAD9102SPI(m_nAddress,m_nData);
}

void AD9102UI::on_pb_AppRead_clicked()
{
	objAppData->setText(QString::number(IAppCard->readRegister(m_nAppAddress), 16));

}

void AD9102UI::on_pb_AppWrite_clicked()
{
	IAppCard->writeRegister(m_nAppData,m_nAppAddress);
}

void AD9102UI::on_pb_Test_clicked()
{

	FileName = QFileDialog::getOpenFileName(this, tr("Open File"),tr("Files (*.*)"));
}

void AD9102UI::on_pb_Reset_clicked()
{
	IAppCard->writeRegister(0x2,0xDE);
	usleep(100);
	IAppCard->writeRegister(0x3,0xDE);
}

void AD9102UI::on_pb_Trigger_clicked()
{
	if(m_bTriggerState==true){
		IAppCard->writeRegister(0x1,0xDE);
		m_bTriggerState=false;
		ui->pb_Trigger->setText("Trigger Low");
	}
	else{
		IAppCard->writeRegister(0x3,0xDE);
		m_bTriggerState=true;
		ui->pb_Trigger->setText("Trigger High");
	}

}

void AD9102UI::on_pb_TestWrite_clicked()
{
	bool ok=true;
	if(ui->comboBox->currentText()!=""){
		QFile file(FileName);
		if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
			return;
		while (!file.atEnd()) {

			QByteArray line = file.readLine();
                        QList<QByteArray> data=line.split('\t');

			if(data[0].endsWith('\n'))
				data[0].chop(2);
			else
				data[0].chop(1);
			if(data[1].endsWith('\n'))
				data[1].chop(2);
			else
				data[1].chop(1);

			unsigned short wrAddress = data[0].toUInt(&ok,16);
			unsigned short wrData=data[1].toUInt(&ok,16);

			qDebug()<<"Address:"<<hex<<wrAddress<<"Data:"<<hex<<wrData;
                        if(wrAddress==0x5F)
                            break;
                        else
                            AD9102->writeAD9102SPI(wrAddress,wrData);usleep(m_nDelay);
		}
	}else{
		QMessageBox::warning(this, tr("File Not Uploaded"),tr("No Files in the Directory...\n"
		                                   "Upload the file and write"),QMessageBox::Cancel);
	}
}

void AD9102UI::on_comboBox_currentIndexChanged(int index)
{
	Q_UNUSED(index)
	if(ui->comboBox->currentText()!="other"){
		FileName="/home/regval_files/"+ui->comboBox->currentText();
		qDebug()<<FileName;
	}
	else{
		FileName = QFileDialog::getOpenFileName(this, tr("Open File"),tr("Files (*.*)"));
		qDebug()<<FileName;
	}
}

void AD9102UI::on_pb_Update_clicked()
{
    AD9102->writeAD9102SPI(0x001D,0x01);
}
void AD9102UI::on_pb_TestRUN_clicked()
{
    if(m_bRunStop){
        AD9102->writeAD9102SPI(0x001E,0x00);
        m_bRunStop=false;
        ui->pb_TestRUN->setText("RUN");
    }
    else{
        AD9102->writeAD9102SPI(0x001E,0x01);
        m_bRunStop=true;
        ui->pb_TestRUN->setText("STOP");
    }
}
void AD9102UI::on_pb_SRAMRead_clicked()
{
    AD9102->writeAD9102SPI(0x1E,0x0C);
    unsigned short l_nData=AD9102->readAD9102SPI(m_nSRAMAddress);
    objSRAMData->setText(QString::number(l_nData,16));
}

void AD9102UI::on_pb_SRAMWrite_clicked()
{
     AD9102->writeAD9102SPI(0x1E,0x04);
     AD9102->writeAD9102SPI(m_nSRAMAddress,m_nSRAMData);
}

void AD9102UI::on_pb_SRAMLoad_clicked()
{
    SRAMFileName = QFileDialog::getOpenFileName(this, tr("Open File"),tr("Files (*.*)"));
    qDebug()<<SRAMFileName;
}

void AD9102UI::on_pb_SRAMUpdate_clicked()
{
    bool ok=true;
    if(SRAMFileName.isNull()){
        QMessageBox::warning(this, tr("File Not Uploaded"),tr("SRAM Not Loaded...\n"
                                           "Upload the file and write"),QMessageBox::Cancel);
    }else{
            QFile file(SRAMFileName);
            if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
                    return;

            unsigned int wrAddress=0x0,wrData=0x0;
            int IncAddr=0;

            AD9102->writeAD9102SPI(0x1E,0x04);
            while (!file.atEnd()) {
            	QByteArray line = file.readLine();
            	QList<QByteArray> data=line.split('\n');
  				wrData=data[0].toUInt(&ok,10);
                wrAddress =m_nSRAMStartddress+IncAddr ;
      			qDebug()<<"Address:"<<hex<<wrAddress<<"Data:"<<hex<<wrData;

                AD9102->writeAD9102SPI(wrAddress,wrData);

      			if(wrAddress==0x6FFF||IncAddr==m_nSRAMCount)
      				break;
      			else
      				IncAddr++;
            }
    }
}



void AD9102UI::on_pb_TestRead_clicked()
{
    unsigned int wrAddress=0x0,wrData=0x0;

    QFile file("ReadData.regval");
       file.open(QIODevice::WriteOnly | QIODevice::Text);
       QTextStream out(&file);
       while(wrAddress!=0x61){
    	   if(wrAddress==0x0||wrAddress==0x01||wrAddress==0x02||wrAddress==0x03||wrAddress==0x07||wrAddress==0x08||wrAddress==0x0c||wrAddress==0x0d||wrAddress==0x0e||wrAddress==0x1d||wrAddress==0x1e||wrAddress==0x1f||wrAddress==0x20||wrAddress==0x25||wrAddress==0x27||wrAddress==0x28||wrAddress==0x29||wrAddress==0x2b||wrAddress==0x2c||wrAddress==0x2d||wrAddress==0x31||wrAddress==0x35||wrAddress==0x37||wrAddress==0x3e||wrAddress==0x3f||wrAddress==0x43||wrAddress==0x44||wrAddress==0x45||wrAddress==0x47||wrAddress==0x5c||wrAddress==0x5d||wrAddress==0x5e||wrAddress==0x5f||wrAddress==0x60){
    		   wrData=AD9102->readAD9102SPI(wrAddress);
    		   out <<hex<<wrAddress<<"h"<<"\t"<<hex<<wrData<<"h"<<"\n";
    		   qDebug()<<hex<<wrAddress<<"h"<<"\t"<<hex<<wrData<<"h"<<"\n";
    	   }
    		   wrAddress++;
       }
       file.close();
}

void AD9102UI::on_pushButton_clicked()
{
    unsigned int wrAddress=0x6000,wrData=0x0;
    int IncAddr=0;

    AD9102->writeAD9102SPI(0x1E,0x04);
    while (IncAddr!=101) {
        wrAddress =m_nSRAMStartddress+IncAddr ;
        AD9102->writeAD9102SPI(wrAddress,wrData);
        qDebug()<<"Address:"<<hex<<wrAddress<<"Data:"<<hex<<wrData;
        IncAddr++;wrData++;
    }
}

void AD9102UI::on_pushButton_2_clicked()
{
    unsigned int wrAddress=0x6000,wrData=0x0;
    int IncAddr=0;

    AD9102->writeAD9102SPI(0x1E,0x04);
    while (IncAddr!=4096) {
        wrAddress =m_nSRAMStartddress+IncAddr ;
        AD9102->writeAD9102SPI(wrAddress,wrData);
        qDebug()<<"Address:"<<hex<<wrAddress<<"Data:"<<hex<<wrData;
        IncAddr++;
    }
}

void AD9102UI::on_pushButton_3_clicked()
{
    unsigned int wrAddress=0x6000,wrData=0xFFFF;
    int IncAddr=0;

    AD9102->writeAD9102SPI(0x1E,0x04);
    while (IncAddr!=4096) {
        wrAddress =m_nSRAMStartddress+IncAddr ;
        AD9102->writeAD9102SPI(wrAddress,wrData);
        qDebug()<<"Address:"<<hex<<wrAddress<<"Data:"<<hex<<wrData;
        IncAddr++;
    }
}
