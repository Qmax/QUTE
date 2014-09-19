#include "testspi.h"
#include <QDebug>
#include <unistd.h>
#include <QTimer>
#include <QFile>
#include <QDir>
#include <QMessageBox>

testSPI::testSPI(QWidget *parent) :
	QWidget(parent) {
	ui.setupUi(this);

	dis = new DISPLAY(this);
	dis->selectGeometry(100, 7);

        calibPanel=new HY3131Calibration();

	QPluginLoader loaderApp("libPTApplicationcardInterface.so", this);
	IAppCard = qobject_cast<IApplicationCardInterface*> (loaderApp.instance());
	IAppCard->setDeviceName(SLOT0);
	IAppCard->enumerateAPPCard();

	QPluginLoader loader4("libQmaxPTInterface.so", this);
	ILineEdit = qobject_cast<IQmaxLineEdit*> (loader4.instance());
	INumberPanel = qobject_cast<IQmaxNumberPanel*> (loader4.instance());

	//BackPlaneInterfacePlugin
	QPluginLoader loader2("libBackPlaneInterface.so", this);
	IBackPlane = qobject_cast<IntefaceBackPlane*> (loader2.instance());
	IBackPlane->InitializeBpObject();

	selAppCard=true;

	m_nMaskData = m_nMSWData = m_nLSWData = 0;
	m_nSPIClock = 14;
	m_nMode = 0x01;
	m_nSPIAppendBit = 0xC000;
	m_nAppAddress = m_nAppData = 0;

	ui.Address->setVisible(false);
	objAddress = ILineEdit->QmaxLineEdit(1, ui.gridWidget);
	objAddress->setGeometry(ui.Address->geometry());
	objAddress->setFont(QFont("DejaVu Sans", 13, 50, false));

	ui.Data->setVisible(false);
	objData = ILineEdit->QmaxLineEdit(2, ui.gridWidget);
	objData->setGeometry(ui.Data->geometry());
	objData->setFont(QFont("DejaVu Sans", 13, 50, false));

	ui.Mask->setVisible(false);
	objMaskData = ILineEdit->QmaxLineEdit(3, ui.gridWidget);
	objMaskData->setGeometry(ui.Mask->geometry());
	objMaskData->setFont(QFont("DejaVu Sans", 13, 50, false));

	ui.SPIClock->setVisible(false);
	objSPIClock = ILineEdit->QmaxLineEdit(4, ui.gridWidget);
	objSPIClock->setGeometry(ui.SPIClock->geometry());
	objSPIClock->setFont(QFont("DejaVu Sans", 13, 50, false));

	ui.AppAddress->setVisible(false);
	objAppAddress = ILineEdit->QmaxLineEdit(5, ui.AppBox);
	objAppAddress->setGeometry(ui.AppAddress->geometry());
	objAppAddress->setFont(QFont("DejaVu Sans", 13, 50, false));

	ui.AppData->setVisible(false);
	objAppData = ILineEdit->QmaxLineEdit(6, ui.AppBox);
	objAppData->setGeometry(ui.AppData->geometry());
	objAppData->setFont(QFont("DejaVu Sans", 13, 50, false));

	ui.DMMAddrEdit->setVisible(false);
	objDMMAddr = ILineEdit->QmaxLineEdit(7, ui.gridWidget);
	objDMMAddr->setGeometry(ui.DMMAddrEdit->geometry());
	objDMMAddr->setFont(QFont("DejaVu Sans", 13, 50, false));

	ui.lineEditAvg->setVisible(false);
	objLeAvg = ILineEdit->QmaxLineEdit(8, this);
	objLeAvg->setGeometry(ui.lineEditAvg->geometry());
	objLeAvg->setFont(QFont("DejaVu Sans", 13, 50, false));

	connect(objAddress, SIGNAL(focussed(bool)), this, SLOT(callAddressEdit()));
	connect(objData, SIGNAL(focussed(bool)), this, SLOT(callDataEdit()));
	connect(objMaskData, SIGNAL(focussed(bool)), this, SLOT(callMaskDataEdit()));
	connect(objSPIClock, SIGNAL(focussed(bool)), this, SLOT(callSPIClockEdit()));
	connect(objAppAddress, SIGNAL(focussed(bool)), this,
			SLOT(callAppAddressEdit()));
	connect(objAppData, SIGNAL(focussed(bool)), this, SLOT(callAppDataEdit()));
	connect(objDMMAddr, SIGNAL(focussed(bool)), this, SLOT(callDMMAddrEdit()));
	connect(objLeAvg, SIGNAL(focussed(bool)), this, SLOT(callAvgEdit()));

	showMaximized();

	ADCTimer = new QTimer(this);
	connect(ADCTimer, SIGNAL(timeout()), this, SLOT(ADCRead()));

	reg0 = reg1 = reg2 = 0;
	ADCDigital = 0;
	ADCAnalog = 0;
	RMSData = 0;
	RMSAnalog = 0;

	m_nLeAvg = 10;
	m_nLeAvgInc = 0;
	m_nAvgSum = 0;

	m_nSampleCount=1;

}
void testSPI::ADCRead() {

	if(selAppCard)
		IAppCard->writeRegister(0x0, DMM_DATA_TX_MSW);
	else
		IBackPlane->writeBackPlaneRegister(0x0, DMM_DATA_TX_MSW_BP);

	if(selAppCard)
		IAppCard->writeRegister(0x0, DMM_DATA_TX_LSW);
	else
		IBackPlane->writeBackPlaneRegister(0x0, DMM_DATA_TX_LSW_BP);

	usleep(1000);

	switch (ui.SelectMode->currentIndex()) {

	case 1://8 Bit Mode
		switch (ui.SelectADC->currentIndex()) {
		case 0://ADC1

			unsigned int a, b, c, t, t2;
			ADCDigital = 0;
			for (int i = 0; i < m_nLeAvg; i++) {
				reg0 = (u_int8_t) readDMMSPI(0x00) & 0x000000FF;
				reg1 = (u_int8_t) readDMMSPI(0x01) & 0x000000FF;
				reg2 = (u_int8_t) readDMMSPI(0x02) & 0x000000FF;

				a = reg0;
				b = (reg1 << 8);
				c = (reg2 << 16);

				ui.Reg0->setText("0x" + QString::number(reg0, 16));
				ui.Reg1->setText("0x" + QString::number(reg1, 16));
				ui.Reg2->setText("0x" + QString::number(reg2, 16));
				ui.Reg3->setText("NA");
				ui.Reg4->setText("NA");

				t = a | b;
				t2 = t | c;

				ui.Bit24->setText("0x" + QString::number(t2, 16));
				ui.Bit24_2->setText(QString::number(t2, 10));
				if(i<m_nLeAvg-1)
					printf(" %f +",(double)t2);
				else
					printf(" %f / %d =",(double)t2,m_nLeAvg);

				ADCDigital += t2;
			}
			ADCDigital = ADCDigital / m_nLeAvg;
			printf(" %f \n\n",(double)ADCDigital);
			break;//ADC1 Case End
		case 1://ADC2
			break;//ADC2 Case End
		case 2://LPF
			break;//LPF Case End
		case 3://RMS

			u_int64_t _reg_t1, _reg_t2, _reg_t3, _reg_t4, _reg_t5, _rms;
			RMSData = 0;
//			for (int i = 0; i < m_nLeAvg; i++) {

				reg0 = (u_int8_t) readDMMSPI(0x09) & 0x000000FF;
				reg1 = (u_int8_t) readDMMSPI(0x0A) & 0x000000FF;
				reg2 = (u_int8_t) readDMMSPI(0x0B) & 0x000000FF;
				reg3 = (u_int8_t) readDMMSPI(0x0C) & 0x000000FF;
				reg4 = (u_int8_t) readDMMSPI(0x0D) & 0x000000FF;

				_reg_t1 = reg0;
				_reg_t2 = (reg1 << 8);
				_reg_t3 = (reg2 << 16);
				_reg_t4 = (reg3 << 24);
				_reg_t5 = (reg4 << 32);

				ui.Reg0->setText("0x" + QString::number(reg0, 16));
				ui.Reg1->setText("0x" + QString::number(reg1, 16));
				ui.Reg2->setText("0x" + QString::number(reg2, 16));
				ui.Reg3->setText("0x" + QString::number(reg3, 16));
				ui.Reg4->setText("0x" + QString::number(reg4, 16));

				_rms = _reg_t1;
				_rms = _rms | _reg_t2;
				_rms = _rms | _reg_t3;
				_rms = _rms | _reg_t4;
				_rms = _rms | _reg_t5;

                                _rms = _rms & 0x3FFFFFFFFF;

				ui.Bit24->setText("0x" + QString::number(_rms, 16));
				ui.Bit24_2->setText(QString::number(_rms, 10));

                                RMSData = _rms;
//			}
//			RMSData = RMSData / m_nLeAvg;

			break;//RMS Case End
		}
		break;//8 Bit Mode Case End
	case 3://24 Bit Mode
		switch (ui.SelectADC->currentIndex()) {
		case 0://ADC1

			u_int16_t reg16lsw, reg16msw;
			if (ui.SelectADC->currentIndex() == 0){
				if(selAppCard)
						IAppCard->writeRegister(0x01, DMM_ADDR);
					else
						IBackPlane->writeBackPlaneRegister(0x01, DMM_ADDR_BP);
			}
			else if (ui.SelectADC->currentIndex() == 1){
				if(selAppCard)
						IAppCard->writeRegister(0x07, DMM_ADDR);
					else
						IBackPlane->writeBackPlaneRegister(0x07, DMM_ADDR_BP);
			}

			if(selAppCard)
				IAppCard->writeRegister(0xC00D, DMM_CMD);
			else
				IBackPlane->writeBackPlaneRegister(0xC00D, DMM_CMD_BP);

			if(selAppCard)
				while ((IAppCard->readRegister(DMM_CMD) & 0x0001));
			else
				while ((IBackPlane->readBackPlaneRegister(DMM_CMD_BP) & 0x0001));


			usleep(10000);

			if(selAppCard)
				reg16lsw = (IAppCard->readRegister(DMM_DATA_RX_LSW));
			else
				reg16lsw = (IBackPlane->readBackPlaneRegister(DMM_DATA_RX_LSW_BP));

			if(selAppCard)
				reg16msw = (IAppCard->readRegister(DMM_DATA_RX_MSW));
			else
				reg16msw = (IBackPlane->readBackPlaneRegister(DMM_DATA_RX_MSW_BP));

			u_int16_t byte0, byte1;
			byte0 = byte1 = 0;
			u_int32_t byte2;
			byte2 = 0;

			byte0 = reg16msw & 0x00FF;
			byte1 = reg16lsw & 0xFF00;
			byte2 = reg16lsw & 0x00FF;

			ui.Reg0->setText("0x" + QString::number(reg16lsw, 16));
			ui.Reg1->setText("0x" + QString::number(reg16msw, 16));
			ui.Reg2->setText("NA");
			ui.Reg3->setText("NA");
			ui.Reg4->setText("NA");

			ADCDigital = byte0 | byte1 | (byte2 << 16);

			break;//ADC1 Case End
		case 1://ADC2
			break;//ADC2 Case End
		case 2://LPF
			break;//LPF Case End
		case 3://RMS
			break;//RMS Case End
		}
		break;//24 Bit Mode Case End


	}
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	switch (ui.DCVolt->currentIndex()) {
	case 1://milliVolt
		switch (ui.SelectADC->currentIndex()) {
		case 0://milliVolt DC

			if ((ADCDigital < 0) || (ADCDigital > 0x800000)) {
				ADCDigital = ~(ADCDigital | 0xFF000000);
				ui.minus->setText("-");
				ui.dSymbol->setText("-");
			} else {
				ui.minus->setText("+");
				ui.dSymbol->setText("+");
			}

			ADCAnalog = (ADCDigital - HY3131_OFFSET) / HY3131_GAIN;

			ui.ADCRead->setText(QString::number(ADCAnalog, 'f', 15));

			if (ui.testFileLoad->currentText() == "DC500mV") {
				ADCAnalog = ADCAnalog / 100000;
			} else if (ui.testFileLoad->currentText() == "DC50mV") {
				ADCAnalog = ADCAnalog / 100000;
			}
			if (((ADCAnalog >= 0) && (ADCAnalog < 1))) {
				dis->setValue(ADCAnalog * 1000);
				ui.unit->setText("mV");
			}

			ui.lineEditOutput->setText(QString::number((ADCAnalog), 'f', 5));

			break;
		case 3://milliVolt AC

                        RMSAnalog = sqrt(((double)RMSData)-RMS_ZERO_AC500mV)/RMS_GAIN_AC500mV;
			ui.ADCRead->setText(QString::number(RMSAnalog, 'f', 15));
			long double tempRMS = RMSAnalog * RMSAnalog;
			dis->setValue(RMSAnalog);
			ui.lineEditOutput->setText(QString::number((RMSAnalog), 'f', 5));

			break;
		}
		break;
	case 2://Volt
		switch (ui.SelectADC->currentIndex()) {
		case 0://Volt DC

			if ((ADCDigital < 0) || (ADCDigital > 0x800000)) {
				ADCDigital = ~(ADCDigital | 0xFF000000);
				ui.minus->setText("-");
				ui.dSymbol->setText("-");
			} else {
				ui.minus->setText("+");
				ui.dSymbol->setText("+");
			}

			ADCAnalog = (ADCDigital - HY3131_OFFSET) / HY3131_GAIN;

			ui.ADCRead->setText(QString::number(ADCAnalog, 'f', 15));

			if (ui.testFileLoad->currentText() == "DC50V") {
				ADCAnalog = ADCAnalog / 1000;
			} else if (ui.testFileLoad->currentText() == "DC5V") {
				ADCAnalog = ADCAnalog / 10000;
			}
			//                if(((ADCAnalog>=1)&&(ADCAnalog<1000))){
			dis->setValue(ADCAnalog);
			ui.unit->setText("V");
			//                }
			break;
		case 3://Volt AC

            RMSAnalog = sqrt(((double)RMSData)-RMS_ZERO_AC500mV)/RMS_GAIN_AC500mV;
			ui.ADCRead->setText(QString::number(RMSAnalog, 'f', 15));
			long double tempRMS = RMSAnalog * RMSAnalog;
			dis->setValue(RMSAnalog);
			ui.lineEditOutput->setText(QString::number((RMSAnalog), 'f', 5));

			break;
		}
		break;
	case 3://Amps
//		break;
	case 4://mA
		ui.ADCRead->setText(QString::number(ADCAnalog, 'f', 15));
		dis->setValue(ADCAnalog * 1000);
		ui.lineEditOutput->setText(QString::number((ADCAnalog), 'f', 5));

		break;
	case 5://uA
		break;
	case 6://R/C/Diode

		ADCAnalog = ADCDigital;
		ui.ADCRead->setText(QString::number(ADCAnalog, 'f', 10));
		if (ui.testFileLoad->currentText() == "R50E"
				|| ui.testFileLoad->currentText() == "R500E"
				|| ui.testFileLoad->currentText() == "R5KE"
				|| ui.testFileLoad->currentText() == "R50KE"
				|| ui.testFileLoad->currentText() == "R500KE"
				|| ui.testFileLoad->currentText() == "R5ME"
				|| ui.testFileLoad->currentText() == "R50ME"
				|| ui.testFileLoad->currentText() == "R500ME") {
			dis->setValue(ADCAnalog);
		}
		ui.lineEditOutput->setText(QString::number((ADCAnalog), 'f', 5));

		break;
	case 7://Frequency
		break;
	}
	ui.pkhmax->setText("0x" + QString::number(readPKHMAX(),16));
	ui.pkhmin->setText("0x" + QString::number(readPKHMIN(),16));
}

u_int32_t testSPI::readADC1(u_int8_t r0,u_int8_t r1,u_int8_t r2){
	//Load No of Samples from File~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	bool ok=true;
	QStringList stringList;
	QFile textFile("/home/HY3131/Samples.dat");
	if (textFile.open(QIODevice::ReadOnly))
	{
		QTextStream textStream(&textFile);
		while (!textStream.atEnd())
		{
			stringList.append(textStream.readLine());
		}
		m_nSampleCount=stringList.value(0).toInt(&ok,10);
	}
	//qDebug()<<"samples:"<<m_nSampleCount;
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	busyState=true;
	//Clear SPI RX Registors
	if(selAppCard)
		IAppCard->writeRegister(0x0, DMM_DATA_TX_MSW);
	else
		IBackPlane->writeBackPlaneRegister(0x0, DMM_DATA_TX_MSW_BP);

	if(selAppCard)
		IAppCard->writeRegister(0x0, DMM_DATA_TX_LSW);
	else
		IBackPlane->writeBackPlaneRegister(0x0, DMM_DATA_TX_LSW_BP);

	usleep(1000);

	u_int32_t a, b, c, t, t2,temp=0;

	//Read ADC1
	for(int i=0;i<m_nSampleCount;i++){
		reg0 = (u_int8_t) readDMMSPI2(r0) & 0x000000FF;
		reg1 = (u_int8_t) readDMMSPI2(r1) & 0x000000FF;
		reg2 = (u_int8_t) readDMMSPI2(r2) & 0x000000FF;

		//Shift & Combine
		a = reg0;
		b = (reg1 << 8);
		c = (reg2 << 16);

		t = a | b;
		t2 = t | c;

		temp+=t2;
	}
	temp=temp/m_nSampleCount;
//		qDebug()<<"ADC1 Read Data:"<<hex<<temp;
	busyState=false;
	return temp;
}
u_int32_t testSPI::readADC2(){
	return (readADC1(0x03,0x04,0x05));
}
u_int32_t testSPI::readLPF(){
	return (readADC1(0x06,0x07,0x08));
}
u_int32_t testSPI::readRMS(){
	busyState=true;
	u_int32_t _reg_t1, _reg_t2, _reg_t3, _reg_t4, _reg_t5, _rms;
	RMSData = 0;

	//Read Registers
	reg0 = (u_int8_t) readDMMSPI2(0x09) & 0x000000FF;
	reg1 = (u_int8_t) readDMMSPI2(0x0A) & 0x000000FF;
	reg2 = (u_int8_t) readDMMSPI2(0x0B) & 0x000000FF;
	reg3 = (u_int8_t) readDMMSPI2(0x0C) & 0x000000FF;
//	reg4 = (u_int8_t) readDMMSPI2(0x0D) & 0x000000FF;

	//Shift & Combine Registers
	_reg_t1 = reg0;
	_reg_t2 = (reg1 << 8);
	_reg_t3 = (reg2 << 16);
	_reg_t4 = (reg3 << 24);
//	_reg_t5 = (reg4 << 32);


	_rms = _reg_t1;
	_rms = _rms | _reg_t2;
	_rms = _rms | _reg_t3;
	_rms = _rms | _reg_t4;
//	_rms = _rms | _reg_t5;

	//Mask 0:37 Registers
//	_rms =_rms & 0x3FFFFFFFFFLL;
	busyState=false;
	qDebug()<<"RMS ADC Read Data:"<<hex<<_rms;

	qDebug()<<"PKHMAX:"<<hex<<readPKHMAX();	usleep(100);
	qDebug()<<"PKHMIN:"<<hex<<readPKHMIN();	usleep(100);

	return _rms;
}
u_int32_t testSPI::readPKHMIN(){
	return (readADC1(0x0E,0x0F,0x10));
}
u_int32_t testSPI::readPKHMAX(){

	return (readADC1(0x11,0x12,0x13));
}
void testSPI::writeDMMSPI2(u_int16_t _Address, u_int16_t _Data){
	busyState=true;
	unsigned int mAddr = 0, mData = 0;

	mAddr = _Address;
	mAddr = mAddr << 1;
	mAddr = mAddr & 0xFE;

	if(selAppCard)
		IAppCard->writeRegister(mAddr, DMM_ADDR);
	else
		IBackPlane->writeBackPlaneRegister(mAddr, DMM_ADDR_BP);

	mData = _Data << 8;
	if(selAppCard)
		IAppCard->writeRegister(mData, DMM_DATA_TX_MSW);
	else
		IBackPlane->writeBackPlaneRegister(mData, DMM_DATA_TX_MSW_BP);

	if(selAppCard)
		IAppCard->writeRegister(0xC001, DMM_CMD);
	else
		IBackPlane->writeBackPlaneRegister(0xC001, DMM_CMD_BP);

	if(selAppCard)
		while ((IAppCard->readRegister(DMM_CMD) & 0x0001));
	else
		while ((IBackPlane->readBackPlaneRegister(DMM_CMD_BP) & 0x0001));

	//qDebug()<<"writeDMMSPI:"<<"Address:"<<hex<<mAddr<<"Data:"<<hex<<mData;
	usleep(1000);
	busyState=false;
}
u_int32_t testSPI::readDMMSPI2(u_int16_t _Address) {
	busyState=true;
	u_int32_t mAddr = 0, mLData = 0, mMData = 0;

	if(selAppCard)
		IAppCard->writeRegister(0x0, DMM_DATA_TX_MSW);
	else
		IBackPlane->writeBackPlaneRegister(0x0, DMM_DATA_TX_MSW_BP);

	if(selAppCard)
		IAppCard->writeRegister(0x0, DMM_DATA_TX_LSW);
	else
		IBackPlane->writeBackPlaneRegister(0x0, DMM_DATA_TX_LSW_BP);

	mAddr = _Address;
	mAddr = mAddr << 1;
	mAddr = mAddr | 0x01;

	if(selAppCard)
		IAppCard->writeRegister(mAddr, DMM_ADDR);
	else
		IBackPlane->writeBackPlaneRegister(mAddr, DMM_ADDR_BP);

	if(selAppCard)
		IAppCard->writeRegister(0xC009, DMM_CMD);
	else
		IBackPlane->writeBackPlaneRegister(0xC009, DMM_CMD_BP);

	if(selAppCard)
		while ((IAppCard->readRegister(DMM_CMD) & 0x0001));
	else
		while ((IBackPlane->readBackPlaneRegister(DMM_CMD_BP) & 0x0001));

	usleep(1000);

	if(selAppCard)
			mMData = IAppCard->readRegister(DMM_DATA_RX_MSW);
	else
			mMData = IBackPlane->readBackPlaneRegister(DMM_DATA_RX_MSW_BP);

	if(selAppCard)
		mLData = IAppCard->readRegister(DMM_DATA_RX_LSW);
	else
		mLData = IBackPlane->readBackPlaneRegister(DMM_DATA_RX_LSW_BP);

	u_int32_t D32Bit = (((mMData << 16) & 0xFFFF0000)| (mLData & 0x0000FFFF));
	busyState=false;
	return D32Bit;
}
void testSPI::receiveValue(unsigned int pValue) {
	if (m_nLineEditIndex == 1) {
		m_nMSWData = (unsigned short) pValue;
		qDebug() << "MSW:" << hex << m_nMSWData;
	} else if (m_nLineEditIndex == 2) {
		m_nLSWData = (unsigned short) pValue;
		qDebug() << "LSW:" << hex << m_nLSWData;
	} else if (m_nLineEditIndex == 3) {
		m_nMaskData = (unsigned short) pValue;
	} else if (m_nLineEditIndex == 4) {
		m_nSPIClock = (unsigned short) pValue;
		IAppCard->setSPIClock(m_nSPIClock, m_mapSPISelect);
	} else if (m_nLineEditIndex == 5) {
		m_nAppAddress = (unsigned short) pValue;
	} else if (m_nLineEditIndex == 6) {
		m_nAppData = (unsigned short) pValue;
	} else if (m_nLineEditIndex == 7) {
		m_nDMMAddr = (unsigned short) pValue;
//		qDebug() << "DMM Address:" << hex << m_nDMMAddr;
	} else if (m_nLineEditIndex == 8) {
		m_nLeAvg = pValue;
		objLeAvg->setText(QString::number(pValue));
	}
}
void testSPI::receiveValue(double pValue) {
	Q_UNUSED(pValue)
}
void testSPI::receiveValue(QString pValue) {
	if (m_nLineEditIndex == 1) {
		objAddress->setText(pValue);
	} else if (m_nLineEditIndex == 2) {
		objData->setText(pValue);
	} else if (m_nLineEditIndex == 3) {
		objMaskData->setText(pValue);
	} else if (m_nLineEditIndex == 4) {
		objSPIClock->setText(pValue);
	} else if (m_nLineEditIndex == 5) {
		objAppAddress->setText(pValue);
	} else if (m_nLineEditIndex == 6) {
		objAppData->setText(pValue);
	} else if (m_nLineEditIndex == 7) {
		objDMMAddr->setText(pValue);
	} else if (m_nLineEditIndex == 8) {
		objLeAvg->setText(pValue);
	}

}
void testSPI::callAddressEdit() {
	if (objAddress->hasFocus()) {
		openNumKBPanel(0);
		m_nLineEditIndex = 1;
	}
}

void testSPI::callDataEdit() {
	if (objData->hasFocus()) {
		openNumKBPanel(0);
		m_nLineEditIndex = 2;
	}

}
void testSPI::callMaskDataEdit() {
	if (objMaskData->hasFocus()) {
		openNumKBPanel(0);
		m_nLineEditIndex = 3;
	}
}
void testSPI::callSPIClockEdit() {
	if (objSPIClock->hasFocus()) {
		openNumKBPanel(0);
		m_nLineEditIndex = 4;
	}
}
void testSPI::callAppAddressEdit() {
	if (objAppAddress->hasFocus()) {
		openNumKBPanel(0);
		m_nLineEditIndex = 5;
	}
}

void testSPI::callAppDataEdit() {
	if (objAppData->hasFocus()) {
		openNumKBPanel(0);
		m_nLineEditIndex = 6;
	}

}
void testSPI::callDMMAddrEdit() {
	if (objDMMAddr->hasFocus()) {
		openNumKBPanel(0);
		m_nLineEditIndex = 7;
	}

}
void testSPI::callAvgEdit() {
	if (objLeAvg->hasFocus()) {
		openNumKBPanel(2);
		m_nLineEditIndex = 8;
	}

}
void testSPI::openNumKBPanel(short int pValue) {

	QWidget *w = INumberPanel->getNumKBPanel(pValue, this);
	w->setWindowFlags(Qt::WindowCloseButtonHint | Qt::Dialog);
	w->show();
}
void testSPI::openNumKBPanel(short int pValue, double incRatio, char type,
		double max, double min, QWidget* parent) {

	QWidget *w = INumberPanel->getNumKBPanelIncDec(pValue, incRatio, type, max,
			min, parent);
	w->setWindowFlags(Qt::WindowCloseButtonHint | Qt::Dialog);
	w->show();
}
testSPI::~testSPI() {

}

unsigned int testSPI::readDMMSPI(unsigned short _Address) {
	unsigned int mAddr = 0, mLData = 0, mMData = 0;

	if(selAppCard)
		IAppCard->writeRegister(0x0, DMM_DATA_TX_MSW);
	else
		IBackPlane->writeBackPlaneRegister(0x0, DMM_DATA_TX_MSW_BP);

	if(selAppCard)
		IAppCard->writeRegister(0x0, DMM_DATA_TX_LSW);
	else
		IBackPlane->writeBackPlaneRegister(0x0, DMM_DATA_TX_LSW_BP);

	mAddr = _Address;
	mAddr = mAddr << 1;
	mAddr = mAddr | 0x01;

	if(selAppCard)
		IAppCard->writeRegister(mAddr, DMM_ADDR);
	else
		IBackPlane->writeBackPlaneRegister(mAddr, DMM_ADDR_BP);

	if (ui.SelectMode->currentIndex() == 1) {//8 bit
		if(selAppCard)
			IAppCard->writeRegister(0xC009, DMM_CMD);
		else
			IBackPlane->writeBackPlaneRegister(0xC009, DMM_CMD_BP);
	} else if (ui.SelectMode->currentIndex() == 2) {//16 bit
		if(selAppCard)
			IAppCard->writeRegister(0xC00B, DMM_CMD);
		else
			IBackPlane->writeBackPlaneRegister(0xC00B, DMM_CMD_BP);
	} else if (ui.SelectMode->currentIndex() == 3) {//24 bit
		if(selAppCard)
			IAppCard->writeRegister(0xC00D, DMM_CMD);
		else
			IBackPlane->writeBackPlaneRegister(0xC00D, DMM_CMD_BP);
	} else if (ui.SelectMode->currentIndex() == 4) {//32 bit
		if(selAppCard)
			IAppCard->writeRegister(0xC00F, DMM_CMD);
		else
			IBackPlane->writeBackPlaneRegister(0xC00F, DMM_CMD_BP);
	}

	if(selAppCard)
		while ((IAppCard->readRegister(DMM_CMD) & 0x0001));
	else
		while ((IBackPlane->readBackPlaneRegister(DMM_CMD_BP) & 0x0001));

		;
	usleep(1000);

	if(selAppCard)
			mMData = IAppCard->readRegister(DMM_DATA_RX_MSW);
	else
			mMData = IBackPlane->readBackPlaneRegister(DMM_DATA_RX_MSW_BP);

	if(selAppCard)
		mLData = IAppCard->readRegister(DMM_DATA_RX_LSW);
	else
		mLData = IBackPlane->readBackPlaneRegister(DMM_DATA_RX_LSW_BP);

	unsigned int D32Bit = (((mMData << 16) & 0xFFFF0000)
			| (mLData & 0x0000FFFF));
//	qDebug()<<"Address:"<<_Address<<"Data:"<<hex<<D32Bit;
	return D32Bit;
}

void testSPI::writeDMMSPI(unsigned short _Address, unsigned short _MSWData,
		unsigned short _LSWData) {
	unsigned int mAddr = 0, mData = 0;

	mAddr = _Address;
	mAddr = mAddr << 1;
	mAddr = mAddr & 0xFE;

	if(selAppCard)
		IAppCard->writeRegister(mAddr, DMM_ADDR);
	else
		IBackPlane->writeBackPlaneRegister(mAddr, DMM_ADDR_BP);


	if (ui.SelectMode->currentIndex() == 1) {//8 bit

		mData = _MSWData << 8;
		if(selAppCard)
			IAppCard->writeRegister(mData, DMM_DATA_TX_MSW);
		else
			IBackPlane->writeBackPlaneRegister(mData, DMM_DATA_TX_MSW_BP);

		if(selAppCard)
			IAppCard->writeRegister(0xC001, DMM_CMD);
		else
			IBackPlane->writeBackPlaneRegister(0xC001, DMM_CMD_BP);
	} else if (ui.SelectMode->currentIndex() == 2) {//16 bit
		if(selAppCard)
			IAppCard->writeRegister(_MSWData, DMM_DATA_TX_MSW);
		else
			IBackPlane->writeBackPlaneRegister(_MSWData, DMM_DATA_TX_MSW_BP);

		if(selAppCard)
			IAppCard->writeRegister(0xC003, DMM_CMD);
		else
			IBackPlane->writeBackPlaneRegister(0xC003, DMM_CMD_BP);

	} else if (ui.SelectMode->currentIndex() == 3) {//24 bit

		if(selAppCard)
			IAppCard->writeRegister(_MSWData, DMM_DATA_TX_MSW);
		else
			IBackPlane->writeBackPlaneRegister(_MSWData, DMM_DATA_TX_MSW_BP);
		mData = _LSWData << 8;
		if(selAppCard)
			IAppCard->writeRegister(mData, DMM_DATA_TX_LSW);
		else
			IBackPlane->writeBackPlaneRegister(mData, DMM_DATA_TX_LSW_BP);

		if(selAppCard)
			IAppCard->writeRegister(0xC005, DMM_CMD);
		else
			IBackPlane->writeBackPlaneRegister(0xC005, DMM_CMD_BP);

	} else if (ui.SelectMode->currentIndex() == 4) {//32 bit

		if(selAppCard)
			IAppCard->writeRegister(_MSWData, DMM_DATA_TX_MSW);
		else
			IBackPlane->writeBackPlaneRegister(_MSWData, DMM_DATA_TX_MSW_BP);
		if(selAppCard)
			IAppCard->writeRegister(_LSWData, DMM_DATA_TX_LSW);
		else
			IBackPlane->writeBackPlaneRegister(mData, DMM_DATA_TX_LSW_BP);
		if(selAppCard)
			IAppCard->writeRegister(0xC007, DMM_CMD);
		else
			IBackPlane->writeBackPlaneRegister(0xC007, DMM_CMD_BP);
	}
	usleep(10000);
	if(selAppCard)
		while ((IAppCard->readRegister(DMM_CMD) & 0x0001));
	else
		while ((IBackPlane->readBackPlaneRegister(DMM_CMD_BP) & 0x0001));

		;
//	qDebug() << "Address:" << hex << mAddr << "Data:" << hex
//			<< mData;

}

void testSPI::on_Execute_clicked() {
	if (ui.SelectOperation->currentIndex() == 1) {//Write

		if (ui.SelectSPI->currentIndex() == 7) {
			writeDMMSPI(m_nDMMAddr, m_nMSWData, m_nLSWData);
			/*            unsigned short mAddr=0,mData=0;

			 mAddr=m_nDMMAddr;
			 mAddr=mAddr << 1;
			 mAddr=mAddr &  0xFE;

			 IAppCard->writeRegister(mAddr,DMM_ADDR);

			 if(ui.SelectMode->currentIndex()==1){//8 bit

			 mData=m_nMSWData<<8;
			 IAppCard->writeRegister(mData,DMM_DATA_TX_MSW);
			 IAppCard->writeRegister(0xC001,DMM_CMD);
			 }
			 else if(ui.SelectMode->currentIndex()==2){//16 bit

			 IAppCard->writeRegister(m_nMSWData,DMM_DATA_TX_MSW);
			 IAppCard->writeRegister(0xC003,DMM_CMD);
			 }
			 else if(ui.SelectMode->currentIndex()==3){//24 bit

			 IAppCard->writeRegister(m_nMSWData,DMM_DATA_TX_MSW);
			 mData=m_nLSWData<<8;
			 IAppCard->writeRegister(mData,DMM_DATA_TX_LSW);
			 IAppCard->writeRegister(0xC005,DMM_CMD);
			 }
			 else if(ui.SelectMode->currentIndex()==4){//32 bit

			 IAppCard->writeRegister(m_nMSWData,DMM_DATA_TX_MSW);
			 IAppCard->writeRegister(m_nLSWData,DMM_DATA_TX_LSW);
			 IAppCard->writeRegister(0xC007,DMM_CMD);
			 }
			 usleep(10000);
			 while((IAppCard->readRegister(DMM_CMD)& 0x0001));*/

		} else {
			unsigned short pAddress = 0;

			if (ui.SelectMask->currentIndex() == 1)
				pAddress = m_nMaskData & m_nMSWData;
			else
				pAddress = m_nMaskData | m_nMSWData;

			if (ui.AppendBit->currentIndex() == 1)
				m_nSPIAppendBit = 0x8000;
			else
				m_nSPIAppendBit = 0xC000;

			IAppCard->setSPIAppendBit(m_nSPIAppendBit);
			IAppCard->setSPITXMSW(pAddress, m_mapSPISelect);
			IAppCard->setSPITXLSW(m_nLSWData, m_mapSPISelect);
			IAppCard->setSPICW(m_nMode, m_mapSPISelect);
			IAppCard->readSPIDriveDoneBit(m_mapSPISelect);

			qDebug() << "TXMSW:" << hex << pAddress << "TXLSW:" << hex
					<< m_nLSWData;
			qDebug() << "Control Word:" << hex << m_nMode;
		}
	} else if (ui.SelectOperation->currentIndex() == 2) {//Read

		if (ui.SelectSPI->currentIndex() == 7) {
			unsigned int mAddr = 0, mLData = 0, mMData = 0;

			/* IAppCard->writeRegister(0x0,DMM_DATA_TX_MSW);
			 IAppCard->writeRegister(0x0,DMM_DATA_TX_LSW);

			 mAddr=m_nDMMAddr;
			 mAddr=mAddr << 1;
			 mAddr=mAddr |  0x01;

			 IAppCard->writeRegister(mAddr,DMM_ADDR);

			 if(ui.SelectMode->currentIndex()==1){//8 bit
			 IAppCard->writeRegister(0xC009,DMM_CMD);
			 }
			 else if(ui.SelectMode->currentIndex()==2){//16 bit
			 IAppCard->writeRegister(0xC00B,DMM_CMD);
			 }
			 else if(ui.SelectMode->currentIndex()==3){//24 bit
			 IAppCard->writeRegister(0xC00D,DMM_CMD);
			 }
			 else if(ui.SelectMode->currentIndex()==4){//32 bit
			 IAppCard->writeRegister(0xC00F,DMM_CMD);
			 }


			 while((IAppCard->readRegister(DMM_CMD)& 0x0001));
			 usleep(10000);

			 mMData=IAppCard->readRegister(DMM_DATA_RX_MSW);
			 mLData=IAppCard->readRegister(DMM_DATA_RX_LSW);*/

			unsigned int Data = 0;
			Data = readDMMSPI(m_nDMMAddr);

			mMData = (Data & 0xFF00) >> 16;
			mLData = (Data & 0x00FF);

			objAddress->setText(QString::number(mMData, 16));
			objData->setText(QString::number(mLData, 16));

		} else {
			unsigned short pAddress = 0;

			if (ui.SelectApp->currentIndex() == HY3131)
				pAddress = m_nMSWData << 1;
			else
				pAddress = m_nMSWData;

			if (ui.SelectMask->currentIndex() == 2)
				pAddress = m_nMaskData | pAddress;
			else if (ui.SelectMask->currentIndex() == 1)
				pAddress = m_nMaskData & pAddress;

			if (ui.AppendBit->currentIndex() == 1)
				m_nSPIAppendBit = 0x8000;
			else
				m_nSPIAppendBit = 0xC000;

			if (ui.SelectApp->currentIndex() == HY3131
					&& ui.SelectMode->currentIndex() == 2) {
				pAddress = pAddress << 8;
			} else if (ui.SelectApp->currentIndex() == HY3131
					&& ui.SelectMode->currentIndex() == 3) {
				pAddress = pAddress << 16;
			} else if (ui.SelectApp->currentIndex() == HY3131
					&& ui.SelectMode->currentIndex() == 4) {
				pAddress = pAddress << 24;
			}

//			qDebug() << "Address:" << hex << pAddress;

			IAppCard->setSPIAppendBit(m_nSPIAppendBit);
			IAppCard->setSPITXMSW(pAddress, m_mapSPISelect);
			IAppCard->setSPICW(m_nMode, m_mapSPISelect);
			IAppCard->readSPIDriveDoneBit(m_mapSPISelect);
			usleep(1000);
			unsigned short l_nData = IAppCard->getSPIRXLSW(m_mapSPISelect);

			objData->setText(QString::number(l_nData, 16));
			qDebug() << "SPIRXLSW" << hex << l_nData;
		}
	}
}

void testSPI::on_SelectOperation_currentIndexChanged(int index) {
	switch (index) {
	case 0:
		break;
	case 1: //Write
		ui.Execute->setText("WRITE");
		if (ui.SelectApp->currentIndex() == HY3131) {
			m_nMaskData = 0xFE;
			ui.SelectMask->setCurrentIndex(1);
			objMaskData->setText("0xFE");
		}
		break;
	case 2: //Read
		ui.Execute->setText("READ");
		if (ui.SelectApp->currentIndex() == HY3131) {
			m_nMaskData = 0x1;
			ui.SelectMask->setCurrentIndex(2);
			objMaskData->setText("0x1");
		}
		break;
	}
}

void testSPI::on_SelectSPI_currentIndexChanged(int index) {
	ui.SelectPart->setEnabled(true);
	ui.SelectApp->setEnabled(true);
	ui.AppendBit->setEnabled(true);
	ui.SelectMask->setEnabled(true);
	objMaskData->setEnabled(true);

	objDMMAddr->setEnabled(false);
	ui.DMMAddrEdit->setEnabled(false);

	switch (index) {
	case 1:
		m_mapSPISelect = SPI1;

		ui.SelectPart->insertItem(0, "AD5293(POT)");
		ui.SelectPart->insertItem(1, "AD5318(POT)");
		ui.SelectPart->insertItem(2, "25PE80(Flash)");

		objSPIClock->setText(QString::number(IAppCard->readRegister(0x88), 16));

		break;
	case 2:
		m_mapSPISelect = SPI2;

		break;
	case 3:
		m_mapSPISelect = SPI3;

		break;
	case 4:
		m_mapSPISelect = SPI4;

		break;http://www.joomla.org/technical-requirements.html
	case 5:
		m_mapSPISelect = SPI5;

		ui.SelectPart->insertItem(0, "HSADC1");
		ui.SelectPart->insertItem(1, "HSADC2");
		ui.SelectPart->insertItem(2, "HSPLL");

		break;
	case 6:
		m_mapSPISelect = SPI6;
		break;

	case 7:
		ui.SelectPart->setEnabled(false);
		ui.SelectApp->setEnabled(false);
		ui.AppendBit->setEnabled(false);
		ui.SelectMask->setEnabled(false);
		objMaskData->setEnabled(false);
		ui.Mask->setEnabled(false);

		objDMMAddr->setEnabled(true);
		ui.DMMAddrEdit->setEnabled(true);

		ui.SelectMode->setCurrentIndex(1);

		if(selAppCard)
			IAppCard->writeRegister(0x17, DMM_CLK_DIV);
		else
			IBackPlane->writeBackPlaneRegister(0x17, DMM_CLK_DIV_BP);
		if(selAppCard)
			objSPIClock->setText("0X" + QString::number(IAppCard->readRegister(DMM_CLK_DIV), 16));
		else
			objSPIClock->setText("0X" + QString::number(IBackPlane->readBackPlaneRegister(DMM_CLK_DIV_BP), 16));
		break;

	}
	//    IAppCard->setSPIClock(0x32,m_mapSPISelect);
}

void testSPI::on_Exit_clicked() {
	this->close();
}

void testSPI::on_SelectMode_currentIndexChanged(int index) {
	switch (index) {
	case 0:
		break;

	case 1:
		m_nMode &= ~(1 << 1);
		m_nMode &= ~(1 << 2);
		break;

	case 3:
		m_nMode &= ~(1 << 1);
		m_nMode |= 1 << 2;
		break;

	case 2:
		m_nMode |= 1 << 1;
		m_nMode &= ~(1 << 2);
		break;

	case 4:
		m_nMode |= 1 << 1;
		m_nMode |= 1 << 2;
		break;
	}

}

void testSPI::on_SelectPart_currentIndexChanged(int index) {
	if (ui.SelectSPI->currentIndex() == 1) {
		if (index == 0) {
			m_nMode &= ~(1 << 9);
			m_nMode &= ~(1 << 8);
		} else if (index == 1) {
			m_nMode &= ~(1 << 9);
			m_nMode |= 1 << 8;
		} else if (index == 2) {
			m_nMode |= 1 << 9;
			m_nMode &= ~(1 << 8);
		}
	} else if (ui.SelectSPI->currentIndex() == 5) {
		if (index == 0) {
			m_nMode &= ~(1 << 9);
			m_nMode &= ~(1 << 8);
		} else if (index == 1) {
			m_nMode &= ~(1 << 9);
			m_nMode |= 1 << 8;
		} else if (index == 2) {
			m_nMode |= 1 << 9;
			m_nMode &= ~(1 << 8);
		}
	}
}

void testSPI::on_AppRead_clicked() {
	unsigned int readData;
	if(selAppCard)
		readData = IAppCard->readRegister(m_nAppAddress);
	else
		readData = IBackPlane->readBackPlaneRegister(m_nAppAddress);

	objAppData->setText("0x" + QString::number(readData, 16));
}

void testSPI::on_AppWrite_clicked() {
	if(selAppCard)
		IAppCard->writeRegister(m_nAppData, m_nAppAddress);
	else
		IBackPlane->writeBackPlaneRegister(m_nAppData, m_nAppAddress);
}

void testSPI::on_SelectApp_currentIndexChanged(int index) {
	switch (index) {
	case 0:
		break;
	case 1:
		ui.SelectSPI->setCurrentIndex(1);

		m_nSPIAppendBit = 0xC000;
		ui.AppendBit->setCurrentIndex(2);

		if (ui.SelectOperation->currentIndex() == 1) {
			m_nMaskData = 0xFE;
			ui.SelectMask->setCurrentIndex(1);
			objMaskData->setText("0xFE");
		} else if (ui.SelectOperation->currentIndex() == 2) {
			m_nMaskData = 0x1;
			ui.SelectMask->setCurrentIndex(2);
			objMaskData->setText("0x1");
		}
		break;
	}
}

void testSPI::on_Reset_clicked() {
	writeDMMSPI(0x37, 0x60, 0x00);
}

void testSPI::on_ReadAll_clicked() {
	unsigned int readData[56];

	unsigned short readAddr = 0x37;

	for (int i = 55; i >= 0; i--) {
		readData[i] = readDMMSPI(readAddr) & 0x00FF;
		ui.tableWidget->setItem(55 - i, 1, new QTableWidgetItem("0X"
				+ QString::number(readData[i], 16)));
		readAddr--;
	}

}

void testSPI::on_DCVolt_currentIndexChanged(int index) {
	ui.testFileLoad->clear();
	switch (index) {
	case 0:
		break;
	case 1://AC/DC-mV
		if(selAppCard)
			IAppCard->writeRegister(0x01, DMM_RLY_SEL);
		else
			IBackPlane->writeBackPlaneRegister(0x01, DMM_RLY_SEL_BP);
		switch (ui.SelectADC->currentIndex()) {
		case 0:
			path.setPath("/home/files/mV/DC/");
			break;
		case 3:
			path.setPath("/home/files/mV/AC/");
			break;
		}
		break;
	case 2://AC/DC-V
		if(selAppCard)
			IAppCard->writeRegister(0x00, DMM_RLY_SEL);
		else
			IBackPlane->writeBackPlaneRegister(0x00, DMM_RLY_SEL_BP);
		switch (ui.SelectADC->currentIndex()) {
		case 0:
			path.setPath("/home/files/V/DC/");
			break;
		case 3:
			path.setPath("/home/files/V/AC/");
			break;
		}
		break;
	case 3://AC/DC-A
		if(selAppCard)
			IAppCard->writeRegister(0x02, DMM_RLY_SEL);
		else
			IBackPlane->writeBackPlaneRegister(0x02, DMM_RLY_SEL_BP);

		switch (ui.SelectADC->currentIndex()) {
		case 0:
			path.setPath("/home/files/A/DC/");
			break;
		case 3:
			path.setPath("/home/files/A/AC/");
			break;
		}
		break;
	case 4://AC/DC-mA
		if(selAppCard)
			IAppCard->writeRegister(0x03, DMM_RLY_SEL);
		else
			IBackPlane->writeBackPlaneRegister(0x03, DMM_RLY_SEL_BP);

		switch (ui.SelectADC->currentIndex()) {
		case 0:
			path.setPath("/home/files/mA/DC/");
			break;
		case 3:
			path.setPath("/home/files/mA/AC/");
			break;
		}
		break;
	case 5://AC/DC-uA
		if(selAppCard)
			IAppCard->writeRegister(0x04, DMM_RLY_SEL);
		else
			IBackPlane->writeBackPlaneRegister(0x04, DMM_RLY_SEL_BP);

		switch (ui.SelectADC->currentIndex()) {
		case 0:
			path.setPath("/home/files/uA/DC/");
			break;
		case 3:
			path.setPath("/home/files/uA/AC/");
			break;
		}
		break;
        case 6://Resistance
    		if(selAppCard)
    			IAppCard->writeRegister(0x05, DMM_RLY_SEL);
    		else
    			IBackPlane->writeBackPlaneRegister(0x05, DMM_RLY_SEL_BP);

		path.setPath("/home/files/RCD/");
		break;
	case 7://Frequency
		if(selAppCard)
			IAppCard->writeRegister(0x06, DMM_RLY_SEL);
		else
			IBackPlane->writeBackPlaneRegister(0x06, DMM_RLY_SEL_BP);

                path.setPath("/home/files/F/");
		break;
        case 8://Capacitor
    		if(selAppCard)
    			IAppCard->writeRegister(0x05, DMM_RLY_SEL);
    		else
    			IBackPlane->writeBackPlaneRegister(0x05, DMM_RLY_SEL_BP);

                path.setPath("/home/files/C/");
                break;
        case 9://Diode
    		if(selAppCard)
    			IAppCard->writeRegister(0x05, DMM_RLY_SEL);
    		else
    			IBackPlane->writeBackPlaneRegister(0x05, DMM_RLY_SEL_BP);

                path.setPath("/home/files/D/");
                break;
        case 10://Beep
    		if(selAppCard)
    			IAppCard->writeRegister(0x05, DMM_RLY_SEL);
    		else
    			IBackPlane->writeBackPlaneRegister(0x05, DMM_RLY_SEL_BP);

                path.setPath("/home/files/B/");
                break;
	}
	RegvalFiles = path.entryList(QDir::Files);
	ui.testFileLoad->addItems(RegvalFiles);

}

void testSPI::on_horizontalSlider_valueChanged(int value) {
	if (value == 0) {
		ADCTimer->stop();
	} else {
		ADCTimer->start(200);
	}
}

void testSPI::on_testFile_clicked() {
	bool ok = true;
	if (ui.testFileLoad->currentText() != "File..." && ui.testFileLoad->currentText() != "") {
		QFile file(FileName);
		if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
			return;
		while (!file.atEnd()) {

			QByteArray line = file.readLine();
			QList<QByteArray> data = line.split('\t');

			if (data[0].endsWith('\n'))
				data[0].chop(1);
			if (data[1].endsWith('\n'))
				data[1].chop(1);

			unsigned short wrAddress = data[0].toUInt(&ok, 16);
			unsigned short wrData = data[1].toUInt(&ok, 16);

			writeDMMSPI(wrAddress, wrData, 0x0);
		}
	} else {
		QMessageBox::warning(this, tr("File Not Uploaded"), tr(
				"No Files in the Directory...\n"
					"Upload the file and write"), QMessageBox::Cancel);
	}
}

void testSPI::on_testFileLoad_currentIndexChanged(int index) {
	Q_UNUSED(index)
	if (ui.testFileLoad->currentText() != "File...") {
		switch (ui.SelectADC->currentIndex()) {
		case 0:
			switch (ui.DCVolt->currentIndex()) {
			case 1:
				FileName = "/home/files/mV/DC/"
						+ ui.testFileLoad->currentText();
				path.setPath("/home/files/mV/DC/");
				break;
			case 2:
				FileName = "/home/files/V/DC/" + ui.testFileLoad->currentText();
				path.setPath("/home/files/V/DC/");
				break;
			case 3:
				FileName = "/home/files/A/DC/" + ui.testFileLoad->currentText();
				path.setPath("/home/files/A/DC/");
				break;
			case 4:
				FileName = "/home/files/mA/DC/"
						+ ui.testFileLoad->currentText();
				path.setPath("/home/files/mA/DC/");
				break;
			case 5:
				FileName = "/home/files/uA/DC/"
						+ ui.testFileLoad->currentText();
				path.setPath("/home/files/uA/DC/");
				break;
			case 6:
				FileName = "/home/files/RCD/" + ui.testFileLoad->currentText();
				path.setPath("/home/files/RCD/");
				break;
                        case 7://Frequency
                                FileName = "/home/files/F/" + ui.testFileLoad->currentText();
                                path.setPath("/home/files/F/");
                                break;
                        case 8://Capacitor
                                FileName = "/home/files/C/" + ui.testFileLoad->currentText();
                                path.setPath("/home/files/C/");
                                break;
                        case 9://Diode
                                FileName = "/home/files/D/" + ui.testFileLoad->currentText();
                                path.setPath("/home/files/D/");
                                break;
                        case 10://Beep
                                FileName = "/home/files/B/" + ui.testFileLoad->currentText();
                                path.setPath("/home/files/B/");
                                break;
			}
			break;
		case 3:
			switch (ui.DCVolt->currentIndex()) {
			case 1:
				FileName = "/home/files/mV/AC/"
						+ ui.testFileLoad->currentText();
				path.setPath("/home/files/mV/AC/");
				break;
			case 2:
				FileName = "/home/files/V/AC/" + ui.testFileLoad->currentText();
				path.setPath("/home/files/V/AC/");
				break;
			case 3:
				FileName = "/home/files/A/AC/" + ui.testFileLoad->currentText();
				path.setPath("/home/files/A/AC/");
				break;
			case 4:
				FileName = "/home/files/mA/AC/"
						+ ui.testFileLoad->currentText();
				path.setPath("/home/files/mA/AC/");
				break;
			case 5:
				FileName = "/home/files/uA/AC/"
						+ ui.testFileLoad->currentText();
				path.setPath("/home/files/uA/AC/");
				break;
			}
			break;
		}
		qDebug() << FileName;
	}
}

void testSPI::on_SelectADC_currentIndexChanged(int index) {
	ui.testFileLoad->clear();
	switch (index) {
	case 0:
		switch (ui.DCVolt->currentIndex()) {
		case 1:
			FileName = "/home/files/mV/DC/" + ui.testFileLoad->currentText();
			break;
		case 2:
			FileName = "/home/files/V/DC/" + ui.testFileLoad->currentText();
			break;
		case 3:
			FileName = "/home/files/A/DC/" + ui.testFileLoad->currentText();
			break;
		case 4:
			FileName = "/home/files/mA/DC/" + ui.testFileLoad->currentText();
			break;
		case 5:
			FileName = "/home/files/uA/DC/" + ui.testFileLoad->currentText();
			break;
		case 6:
			FileName = "/home/files/RCD/" + ui.testFileLoad->currentText();
			break;
                case 7://Frequency
                        FileName = "/home/files/F/" + ui.testFileLoad->currentText();
                        break;
                case 8://Capacitor
                        FileName = "/home/files/C/" + ui.testFileLoad->currentText();
                        break;
                case 9://Diode
                        FileName = "/home/files/D/" + ui.testFileLoad->currentText();
                        break;
                case 10://Beep
                        FileName = "/home/files/B/" + ui.testFileLoad->currentText();
                        break;
		}
		break;
	case 1:
		break;
	case 2:
		break;
	case 3:
		switch (ui.DCVolt->currentIndex()) {
		case 1:
			FileName = "/home/files/mV/AC/" + ui.testFileLoad->currentText();
			break;
		case 2:
			FileName = "/home/files/V/AC/" + ui.testFileLoad->currentText();
			break;
		case 3:
			FileName = "/home/files/A/AC/" + ui.testFileLoad->currentText();
			break;
		case 4:
			FileName = "/home/files/mA/AC/" + ui.testFileLoad->currentText();
			break;
		case 5:
			FileName = "/home/files/uA/AC/" + ui.testFileLoad->currentText();
			break;
		}
		break;
	}
	RegvalFiles = path.entryList(QDir::Files);
	ui.testFileLoad->addItems(RegvalFiles);
}

void testSPI::on_pushButton_clicked()
{
    calibPanel->show();
}

void testSPI::on_radioButton_2_clicked(bool checked)
{
    if(checked){
        ui.AppBox->setTitle("Application Card");
        selAppCard=true;
    }

}

void testSPI::on_radioButton_clicked(bool checked)
{
    if(checked){
        ui.AppBox->setTitle("BackPanel");
        selAppCard=false;
    }
}
