/*
 *      Author: Ravivarman.R,Qmax
 */
#include "settings.h"
#include "ui_settings.h"

Settings::Settings(IPSOCCOMMUNICATION* psoc,HardwareInterface* hw,IApplicationCardInterface* app,AD7190Component* adc,QWidget *parent):
    QWidget(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Widget);

    IPsoc=psoc;    hwInterface=hw;    IAppCard=app;	m_objAD7190Component=adc;

    QPluginLoader loader4("libQmaxPTInterface.so",this);
    ILineEdit = qobject_cast<IQmaxLineEdit*>(loader4.instance());
    INumberPanel=qobject_cast<IQmaxNumberPanel*>(loader4.instance());

    QPluginLoader loader2("libBackPlaneInterface.so",this);
    IBackPlane = qobject_cast<IntefaceBackPlane*>(loader2.instance());
    IBackPlane->InitializeBpObject();

    objForceVoltage=ILineEdit->QmaxLineEdit(3,ui->groupBox);
    objForceVoltage->setGeometry(170,17,96,24);

//    objFrequency=ILineEdit->QmaxLineEdit(4,ui->groupBox);
//    objFrequency->setGeometry(150,150,105,40);

    objFrequency=ILineEdit->getLineEdit(4,160,150,125,35,"Frequency",ui->groupBox);


    connect(objForceVoltage,  SIGNAL(focussed(bool)), this, SLOT(callForceVoltageEdit()));
    connect(objFrequency,     SIGNAL(focussed(bool)), this, SLOT(callFrequencyEdit()));
    connect(this,     SIGNAL(FrequencyChange(double)), parent, SLOT(callFrequencyChange(double)));

    objForceVoltage->setStyleSheet(	"border-width: 2px;border-style: outset;border-color: gray; 					    padding: 0 8px;     background: black;     selection-background-color: yellow;   color:white;     font: bold 14px;"    );
    objFrequency->setStyleSheet("border-width: 2px;border-style: outset;border-color: gray; 						padding: 0 8px;     background: black;     selection-background-color: yellow;   color:white;     font: bold 14px;"    );

    //
	objAddress=ILineEdit->QmaxLineEdit(1, ui->groupBox);
	objAddress->setGeometry(83, 278, 61, 24);

	objData=ILineEdit->QmaxLineEdit(2, ui->groupBox);
	objData->setGeometry(197, 278, 61, 24);

	connect(objAddress,       SIGNAL(focussed(bool)), this, SLOT(callAddressEdit()));
	connect(objData,          SIGNAL(focussed(bool)), this, SLOT(callDataEdit()));

	objAddress->setStyleSheet(	"border-width: 2px;border-style: outset;border-color: gray; 					    padding: 0 8px;     background: black;     selection-background-color: yellow;   color:white;     font: bold 14px;"    );
	objData->setStyleSheet("border-width: 2px;border-style: outset;border-color: gray; 						padding: 0 8px;     background: black;     selection-background-color: yellow;   color:white;     font: bold 14px;"    );
    //

    //
	objBPAddress=ILineEdit->QmaxLineEdit(1, ui->groupBox);
	objBPAddress->setGeometry(83, 346, 61, 24);

	objBPData=ILineEdit->QmaxLineEdit(2, ui->groupBox);
	objBPData->setGeometry(197, 346, 61, 24);

	connect(objBPAddress,       SIGNAL(focussed(bool)), this, SLOT(callBPAddressEdit()));
	connect(objBPData,          SIGNAL(focussed(bool)), this, SLOT(callBPDataEdit()));

	objBPAddress->setStyleSheet(	"border-width: 2px;border-style: outset;border-color: gray; 					    padding: 0 8px;     background: black;     selection-background-color: yellow;   color:white;     font: bold 14px;"    );
	objBPData->setStyleSheet("border-width: 2px;border-style: outset;border-color: gray; 						padding: 0 8px;     background: black;     selection-background-color: yellow;   color:white;     font: bold 14px;"    );
    //

    //
	objOffset=ILineEdit->QmaxLineEdit(1, ui->groupBox);
        objOffset->setGeometry(170,44,96,24);

	connect(objOffset,       SIGNAL(focussed(bool)), this, SLOT(callOffset()));
	connect(this,SIGNAL(OffsetChange(double)),parent,SLOT(callOffsetChange(double)));
    connect(this,SIGNAL(FeedbackChange(int)),parent,SLOT(callFeedBackChange(int)));

	objOffset->setStyleSheet(	"border-width: 2px;border-style: outset;border-color: gray; 					    padding: 0 8px;     background: black;     selection-background-color: yellow;   color:white;     font: bold 14px;"    );
    //
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        objDCVoltage=ILineEdit->QmaxLineEdit(1, ui->groupBox);
        objDCVoltage->setGeometry(170,98,96,24);
        objDCVoltage->setStyleSheet(	"border-width: 2px;border-style: outset;border-color: gray; 					    padding: 0 8px;     background: black;     selection-background-color: yellow;   color:white;     font: bold 14px;"    );
        connect(objDCVoltage,       SIGNAL(focussed(bool)), this, SLOT(callDCVoltage()));
   //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    m_nICMMGR=0;
}
void Settings::receiveValue(double pValue){
        if(m_nLineEditIndex==3){
//                objForceVoltage->setText(QString::number(pValue,'f',2));
                m_nForceVoltage = pValue;
                IAppCard->setSPIAppendBit(0x8000);
                hwInterface->setAmplitude(m_nForceVoltage/2);
        }
        else if(m_nLineEditIndex==4){
                objFrequency->setText(QString::number(pValue));
                m_nFrequency= pValue;
                hwInterface->setFrequency(m_nFrequency);
                emit FrequencyChange(m_nFrequency);
                }
    	else if(m_nLineEditIndex==7){
                m_nOffset=pValue;
                emit OffsetChange(m_nOffset);
    	}
        else if(m_nLineEditIndex==8){
                m_nDCVoltage=pValue;
                hwInterface->setOffset(m_nDCVoltage);
        }
 }
void Settings::receiveValue(unsigned int pValue){
	if(m_nLineEditIndex==1){
		objAddress->setText(QString::number(pValue,16));
		m_nAddress=pValue;
	}
	else if(m_nLineEditIndex==2){
		objData->setText(QString::number(pValue,16));
		m_nData=pValue;
	}
	if(m_nLineEditIndex==5){
		objBPAddress->setText(QString::number(pValue,16));
		m_nBPAddress=pValue;
	}
	else if(m_nLineEditIndex==6){
		objBPData->setText(QString::number(pValue,16));
		m_nBPData=pValue;
	}

}
void Settings::receiveValue(QString pValue){
    if(m_nLineEditIndex==3){
            objForceVoltage->setText(pValue);
    }
    else if(m_nLineEditIndex==4){
//                objFrequency->setText(pValue);
   }
    else if(m_nLineEditIndex==7){
            objOffset->setText(pValue);
    }
    else if(m_nLineEditIndex==8){
            objDCVoltage->setText(pValue);
    }
}
void Settings::callOffset(){
	if (objOffset->hasFocus()) {
		openNumKBPanel(1, 1, 'A', 10000000, -1000000000,this);
		m_nLineEditIndex = 7;
	}
}
void Settings::callDCVoltage(){
        if (objDCVoltage->hasFocus()) {
                openNumKBPanel(1, 1, 'v', 5, -5,this);
                m_nLineEditIndex = 8;
        }
}
void Settings::callAddressEdit() {
	if (objAddress->hasFocus()) {
		openNumKBPanel(0);
		m_nLineEditIndex = 1;
	}
}

void Settings::callDataEdit() {
	if (objData->hasFocus()) {
		openNumKBPanel(0);
		m_nLineEditIndex = 2;
	}

}
void Settings::callBPAddressEdit() {
	if (objBPAddress->hasFocus()) {
		openNumKBPanel(0);
		m_nLineEditIndex = 5;
	}
}

void Settings::callBPDataEdit() {
	if (objBPData->hasFocus()) {
		openNumKBPanel(0);
		m_nLineEditIndex = 6;
	}

}
void Settings::callForceVoltageEdit(){
        if (objForceVoltage->hasFocus()) {
                openNumKBPanel(1, 1, 'v', 1000, 0,this);
                m_nLineEditIndex = 3;
        }
}

void Settings::callFrequencyEdit(){
        if (objFrequency->hasFocus()) {
                openNumKBPanel(1, 1, 'F', 2000000, 0.01,this);
                m_nLineEditIndex = 4;
        }
}
void Settings::openNumKBPanel(short int pValue) {

        QWidget *w = INumberPanel->getNumKBPanel(pValue, this);
        w->setStyleSheet("border:1px solid rgba(0,0,0,0); color:black;");
        w->setWindowFlags(Qt::WindowCloseButtonHint | Qt::Dialog);
        w->show();
}
void Settings::openNumKBPanel(short int pValue,double incRatio,char type,double max,double min,QWidget* parent) {

        QWidget *w = INumberPanel->getNumKBPanelIncDec(pValue,incRatio,type,max,min,parent);
        w->setStyleSheet("border:1px solid rgba(0,0,0,0); color:black;");
        w->setWindowFlags(Qt::WindowCloseButtonHint | Qt::Dialog);
        w->show();
}
Settings::~Settings()
{
    delete ui;
}

void Settings::changeEvent(QEvent *e)
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

void Settings::on_pushButton_clicked()
{
    this->close();
}



void Settings::on_chkCapSet_clicked(bool checked)
{
	m_nICMMGR=IAppCard->readRegister(0x3A);
    if(checked)
                {
                    m_nICMMGR|=1<<5;
                }
                else
                {
                    m_nICMMGR &=0xFFDF;
                }
            IAppCard->writeRegister(m_nICMMGR,0x3A);
}

void Settings::on_chkPOTSel_clicked(bool checked)
{
	m_nICMMGR=IAppCard->readRegister(0x3A);
    if(checked)
        {
            m_nICMMGR|=1<<4;
        }
        else
        {
            m_nICMMGR &=0xFFEF;
        }
    IAppCard->writeRegister(m_nICMMGR,0x3A);
}

void Settings::on_chkDivSel_clicked(bool checked)
{
	m_nICMMGR=IAppCard->readRegister(0x3A);
    if(checked)
                {
                    m_nICMMGR|=1<<3;
                }
                else
                {
                    m_nICMMGR &=0xFFF7;
                }
            IAppCard->writeRegister(m_nICMMGR,0x3A);
}

void Settings::on_R1RMSCAVG_clicked(bool checked)
{
	m_nR1RMSCAVG=IAppCard->readRegister(0x36);
    if(checked){
        m_nR1RMSCAVG|=1<<4;
    }else{
        m_nR1RMSCAVG&=0xFFEF;
    }
     IAppCard->writeRegister(m_nR1RMSCAVG,0x36);
}

void Settings::on_R1RMSGAIN_clicked(bool checked)
{
	m_nR1RMSGAIN=IAppCard->readRegister(0x36);
    if(checked){
        m_nR1RMSGAIN|=1<<3;
    }else{
        m_nR1RMSGAIN &= 0xFFF7;
    }
     IAppCard->writeRegister(m_nR1RMSGAIN,0x36);
}

void Settings::on_R1RMSIN_clicked(bool checked)
{
	m_nR1RMSIN=IAppCard->readRegister(0x36);
    if(checked){
        m_nR1RMSIN|=1<<2;
    }else{
        m_nR1RMSIN&= 0xFFFB;
    }
     IAppCard->writeRegister(m_nR1RMSIN,0x36);
}

void Settings::on_R2RMSCAVG_clicked(bool checked)
{
	m_nR2RMSCAVG=IAppCard->readRegister(0x38);
    if(checked){
        m_nR2RMSCAVG|=1<<5;
    }else{
        m_nR2RMSCAVG&=0xFFDF;
    }
     IAppCard->writeRegister(m_nR2RMSCAVG,0x38);

}

void Settings::on_R2RMSGAIN_clicked(bool checked)
{
	m_nR2RMSGAIN=IAppCard->readRegister(0x38);
    if(checked){
        m_nR2RMSGAIN|=1<<4;
    }else{
        m_nR2RMSGAIN&=0xFFEF;
    }
     IAppCard->writeRegister(m_nR2RMSGAIN,0x38);
}

void Settings::on_R2RMSIN_clicked(bool checked)
{
	m_nR2RMSIN=IAppCard->readRegister(0x38);
    if(checked){
        m_nR2RMSIN|=1<<3;
    }else{
        m_nR2RMSIN&=0xFFF7;
    }
     IAppCard->writeRegister(m_nR2RMSIN,0x38);
}

void Settings::on_ExtInt_clicked(bool checked)
{
	if(checked){
		qDebug()<<"External Measurement";
		IPsoc->resetRelays();
		IPsoc->writeSerial(0x42);
		IPsoc->writeSerial(0x9);
		usleep(1000);
		IPsoc->writeSerial(0x42);
		IPsoc->writeSerial(0x15);
		usleep(1000);
		IPsoc->writeSerial(0x42);
		IPsoc->writeSerial(0x13);

	}
	else{
		qDebug()<<"Internal Measurement";
		IPsoc->resetRelays();
		IPsoc->icmMeasurement();
	}
}

void Settings::on_ReadAppCard_clicked()
{
	objData->setText(QString::number(IAppCard->readRegister(m_nAddress), 16));
}

void Settings::on_WriteAppCard_clicked()
{
	IAppCard->writeRegister(m_nData,m_nAddress);
}

void Settings::on_adc1_clicked()
{
	IAppCard->setSPIAppendBit(0xC000);
		m_objAD7190Component->resetADC(1);
		m_objAD7190Component->writeADCConfigurationRegister(1,0x110);
		m_objAD7190Component->writeADCModeRegister(1,0x80060);

		qDebug()<<"ADC1 Config"<<m_objAD7190Component->readADCConfigurationRegister(1)<<"Mode"<<m_objAD7190Component->readADCModeRegister(1);

}

void Settings::on_adc2_clicked()
{
	IAppCard->setSPIAppendBit(0xC000);
			m_objAD7190Component->resetADC(2);
			m_objAD7190Component->writeADCConfigurationRegister(2,0x110);
			m_objAD7190Component->writeADCModeRegister(2,0x80060);

			qDebug()<<"ADC2 Config"<<m_objAD7190Component->readADCConfigurationRegister(2)<<"Mode"<<m_objAD7190Component->readADCModeRegister(2);
}

void Settings::on_ReadAppCard_2_clicked()
{
	objBPData->setText(QString::number(IBackPlane->readBackPlaneRegister(m_nBPAddress), 16));
}

void Settings::on_WriteAppCard_2_clicked()
{
	IBackPlane->writeBackPlaneRegister(m_nBPData,m_nBPAddress);
}

void Settings::on_up_clicked()
{
//    if((m_nFrequency/1000)>=1&&(m_nFrequency/1000)<1000){
//        objFrequency->setText(QString::number((m_nFrequency+1000),'f',2));
//        m_nFrequency= m_nFrequency+1000;
//    }
//    if((m_nFrequency)>=1&&(m_nFrequency)<1000){
//        objFrequency->setText(QString::number((m_nFrequency+1),'f',2));
//    	m_nFrequency= m_nFrequency+1;
//    }
    bool ok=true;
    QString str=objFrequency->text();
    double value=str.toDouble(&ok);
    short curPos=objFrequency->cursorPosition();
    m_nFrequency=validateCursorPosition(curPos-1,value,1);
    objFrequency->setText(QString::number(m_nFrequency));
    objFrequency->setCursorPosition(curPos);
    //qDebug<<"Cursor Position"<<ui->lineEdit->cursorPosition()<<"Value:"<<value;

    hwInterface->setFrequency(m_nFrequency);
    emit FrequencyChange(m_nFrequency);
}

void Settings::on_down_clicked()
{
//    if((m_nFrequency/2000)>=1&&(m_nFrequency/1000)<1000){
//        objFrequency->setText(QString::number((m_nFrequency-1000),'f',2));
//        m_nFrequency= m_nFrequency-1000;
//    }
//    if((m_nFrequency)>=2&&(m_nFrequency)<1000){
//        objFrequency->setText(QString::number((m_nFrequency-1),'f',2));
//    	m_nFrequency= m_nFrequency-1;
//    }
    bool ok=true;
    QString str=objFrequency->text();
    double value=str.toDouble(&ok);
    short curPos=objFrequency->cursorPosition();
    m_nFrequency=validateCursorPosition(curPos-1,value,0);
    objFrequency->setText(QString::number(m_nFrequency));
    objFrequency->setCursorPosition(curPos);
    //qDebug<<"Cursor Position"<<ui->lineEdit->cursorPosition()<<"Value:"<<value;

    hwInterface->setFrequency(m_nFrequency);
    emit FrequencyChange(m_nFrequency);
}
double Settings::validateCursorPosition(short pos,double value,short incDec){

    double one,ten,hundred,thousand,ten_thousand,hundred_thousand,mega;
    if(incDec==1){
        one=1;ten=10;hundred=100;thousand=1000;ten_thousand=10000;hundred_thousand=100000;mega=1000000;
    }
    if(incDec==0){
        one=-1;ten=-10;hundred=-100;thousand=-1000;ten_thousand=-10000;hundred_thousand=-100000;mega=-1000000;
    }

    if((value/1000000)>=1&&(value/1000000)<=10){
        //qDebug<<"1000000 Range";
        if(pos==0)
            value=value+mega;
        if(pos==1)
            value=value+hundred_thousand;
        if(pos==2)
            value=value+ten_thousand;
        if(pos==3)
            value=value+thousand;
        if(pos==4)
            value=value+hundred;
        if(pos==5)
            value=value+ten;
        if(pos==6)
            value=value+one;
    }
    else if((value/100000)>=1&&(value/100000)<=10){
        //qDebug<<"100000 Range";
        if(pos==0)
            value=value+hundred_thousand;
        if(pos==1)
            value=value+ten_thousand;
        if(pos==2)
            value=value+thousand;
        if(pos==3)
            value=value+hundred;
        if(pos==4)
            value=value+ten;
        if(pos==5)
            value=value+one;
    }
    else if((value/10000)>=1&&(value/10000)<=10){
        //qDebug<<"10000 Range";
        if(pos==0)
            value=value+ten_thousand;
        if(pos==1)
            value=value+thousand;
        if(pos==2)
            value=value+hundred;
        if(pos==3)
            value=value+ten;
        if(pos==4)
            value=value+one;
    }
    else if((value/1000)>=1&&(value/1000)<=10){
        //qDebug<<"1000 Range";
        if(pos==0)
            value=value+thousand;
        if(pos==1)
            value=value+hundred;
        if(pos==2)
            value=value+ten;
        if(pos==3)
            value=value+one;
    }
    else if((value/100)>=1&&(value/100)<=10){
        //qDebug<<"100 Range";
        if(pos==0)
            value=value+hundred;
        if(pos==1)
            value=value+ten;
        if(pos==2)
            value=value+one;
    }
    else if((value/10)>=1&&(value/10)<=10){
        //qDebug<<"10 Range";
        if(pos==0)
            value=value+ten;
        if(pos==1)
            value=value+one;
    }

    else if((value)>=1&&(value)<=10){
        //qDebug<<"1 Range";
        if(value==1&&one==-1)
            one=0;
        else
            value=value+one;
    }else{
        //qDebug<<"out of Range";
    }

    return value;
}

void Settings::on_left_clicked()
{
    objFrequency->setCursorPosition(objFrequency->cursorPosition()-1);
    //qDebug<<"cursor position:"<<ui->lineEdit->cursorPosition();
}

void Settings::on_right_clicked()
{
    objFrequency->setCursorPosition(objFrequency->cursorPosition()+1);
    //qDebug<<"cursor position:"<<ui->lineEdit->cursorPosition();
}

void Settings::on_comboBox_currentIndexChanged(int index)
{
    unsigned short m_nICMMGR=0;

    m_nICMMGR = m_nICMMGR & 0xFFF8;
    m_nICMMGR |= (unsigned short)index;
    IAppCard->writeRegister(m_nICMMGR,0x3A);
    emit FeedbackChange(index);
}
