/*
 * hy3131dmmlib.cpp
 *
 *  Created on: 04-Mar-2014
 *      Author: Ravivarman.R
 */

#include "hy3131dmmlib.h"


HY3131DMMLib::HY3131DMMLib(QObject *parent):QObject(parent){
	QPluginLoader loaderApp("libPTApplicationcardInterface.so", this);
	IAppCard = qobject_cast<IApplicationCardInterface*> (loaderApp.instance());
	IAppCard->setDeviceName(SLOT0);
	IAppCard->enumerateAPPCard();

	//BackPlaneInterfacePlugin
	QPluginLoader loader2("libBackPlaneInterface.so", this);
	IBackPlane = qobject_cast<IntefaceBackPlane*> (loader2.instance());
	IBackPlane->InitializeBpObject();

	selAppCard=false;

//	if(selAppCard)
//			IAppCard->writeRegister(0x20, DMM_CLK_DIV);//DMM SPI Clock Settings 1MHz
//	else
			IBackPlane->writeBackPlaneRegister(0x20,DMM_CLK_DIV_BP);

	D32Bit=0;
	reg0 = reg1 = reg2 = 0;
	ADCDigital = 0;
	RMSData=0;
	ReadData = RawData=0;
	minus=false;
	buzState=false;
	busyState=false;

	//Read Gain & Offset from file~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	bool ok=true;
	int index=0;
	//qDebug()<<"dp:26";
	QFile file("/home/HY3131/GainOffset.dat");
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
		return;
	while (!file.atEnd()) {

		QByteArray line = file.readLine();
		QList<QByteArray> data = line.split('\t');

		if (data[0].endsWith('\n'))
			data[0].chop(1);
		if (data[1].endsWith('\n'))
			data[1].chop(1);
		if (data[2].endsWith('\n'))
			data[2].chop(1);

		m_strRange[index]=data[0];
		m_nGain[index]=data[1].toDouble(&ok);
		m_nOffset[index]=data[2].toDouble(&ok);
		index++;
	}
	file.close();
	//qDebug()<<"dp:48";
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


	//Load No of Samples from File~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	m_nSampleCount=25;
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
        textFile.close();
	//qDebug()<<"samples:"<<m_nSampleCount;
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


}
HY3131DMMLib::~HY3131DMMLib(){

}
bool HY3131DMMLib::busyFlag(){
	return busyState;
}
void HY3131DMMLib::resetDMMSPI(){
	//qDebug()<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~RESET DMM SPI ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	writeDMMSPI(0x37,0x60);
	usleep(1000);
}
void HY3131DMMLib::on_ReadAll() {
	unsigned int readData[56];

	unsigned short readAddr = 0x37;

	for (int i = 55; i >= 0; i--) {
		readData[i] = readDMMSPI(readAddr) & 0x000000FF;
		//qDebug()<<"Read Address:"<<hex<<readAddr<<"Read Data:"<<hex<<readData[i];
		readAddr--;
	}

}
void HY3131DMMLib::Configure(int8_t index){
	busyState=true;
	//qDebug()<<"Range:"<<m_strRange[index];
	//Reset DMMSPI
	//	resetDMMSPI();
	//Relay Switching
	if(index==R50E||index==R500E||index==R5K||index==R50K||index==R500K||index==R5M||index==R50M||index==CNTY||index==DIODE){
//		if(selAppCard)
//			IAppCard->writeRegister(0x05, DMM_RLY_SEL);
//		else
			IBackPlane->writeBackPlaneRegister(0x05, DMM_RLY_SEL_BP);
	}
	else if(index==AC50mV||index==AC500mV||index==DC50mV||index==DC500mV){
//		if(selAppCard)
//			IAppCard->writeRegister(0x01, DMM_RLY_SEL);
//		else
			IBackPlane->writeBackPlaneRegister(0x01, DMM_RLY_SEL_BP);
	}
	else if(index==AC5V||index==AC50V||index==AC500V||index==AC1000V||index==DC5V||index==DC50V||index==DC500V||index==DC1000V){
//		if(selAppCard)
//			IAppCard->writeRegister(0x00, DMM_RLY_SEL);
//		else
			IBackPlane->writeBackPlaneRegister(0x00, DMM_RLY_SEL_BP);
	}
	else if(index==DC10A||index==AC10A){
//		if(selAppCard)
//			IAppCard->writeRegister(0x02, DMM_RLY_SEL);
//		else
			IBackPlane->writeBackPlaneRegister(0x02, DMM_RLY_SEL_BP);
	}
	else if(index==AC50mA||index==AC500mA||index==DC50mA||index==DC500mA){
//		if(selAppCard)
//			IAppCard->writeRegister(0x03, DMM_RLY_SEL);
//		else
			IBackPlane->writeBackPlaneRegister(0x03, DMM_RLY_SEL_BP);
	}
	else if(index==AC500uA||index==DC500uA||index==AC5mA||index==DC5mA){
//		if(selAppCard)
//			IAppCard->writeRegister(0x04, DMM_RLY_SEL);
//		else
			IBackPlane->writeBackPlaneRegister(0x04, DMM_RLY_SEL_BP);
	}

	//Load Register Configuration
	bool ok = true;
	QFile file("/home/HY3131/"+QString::number(index));
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
			writeDMMSPI(wrAddress, wrData);
/*			qDebug()<<"Address: "<<hex<<wrAddress;
			qDebug()<<"Data   : "<<hex<<wrData;*/
			usleep(1000);
		}
	file.close();

	busyState=false;

/*	unsigned short addr,data;
	if(index==AC500mV||index==DC500mV){
		//ENPKH = 0
		addr=0x29;	data=0x80;	writeDMMSPI(addr, data);	usleep(100);
		//PKHMAX<18:0> = 0x40000
		addr=0x13;	data=0x04;	writeDMMSPI(addr, data);	usleep(100);
		addr=0x12;	data=0x00;	writeDMMSPI(addr, data);	usleep(100);
		addr=0x11;	data=0x00;	writeDMMSPI(addr, data);	usleep(100);
		//PKHMIN<18:0> = 0x3FFFF
		addr=0x10;	data=0x03;	writeDMMSPI(addr, data);	usleep(100);
		addr=0x0F;	data=0xFF;	writeDMMSPI(addr, data);	usleep(100);
		addr=0x0E;	data=0xFF;	writeDMMSPI(addr, data);	usleep(100);
		//ENPKH = 1
		addr=0x29;	data=0x84;	writeDMMSPI(addr, data);	usleep(100);

//		qDebug()<<"PKHMAX:"<<hex<<readPKHMAX();	usleep(100);
//		qDebug()<<"PKHMIN:"<<hex<<readPKHMIN();	usleep(100);

	}*/
}
double HY3131DMMLib::Measure(int8_t index){
	busyState=true;
	if(index==AC50mV || index==AC500mV ||index==AC5V || index==AC50V ||index==AC500V ||index==AC1000V || index==AC500uA || index==AC5mA ||index==AC50mA || index==AC500mA ||index==AC10A){
		double rawData =Measure2(index);
		double temp = rawData-m_nOffset[index];
		double temp1= sqrt(temp);
		if(rawData==999999999)
			ReadData= rawData;
		else
			ReadData = temp1/m_nGain[index];
		if(temp<0)
			ReadData=0;
	}
	else{
		double temp=Measure2(index);
		if(temp==999999999)
			ReadData= temp;
		else
			ReadData=(temp-m_nOffset[index])/m_nGain[index];
	}
	busyState=false;
        qDebug()<<"Measured Data:"<<ReadData;
	return ReadData;
}
double HY3131DMMLib::Measure2(int8_t index){
	busyState=true;
	RawData=0.0;ADCDigital=0;
	if(index==AC50mV || index==AC500mV ||index==AC5V || index==AC50V ||index==AC500V ||index==AC1000V || index==AC500uA || index==AC5mA ||index==AC50mA || index==AC500mA || index==AC10A){
		if(minus==true)
			minus=false;
		RMSData=readRMS();

		if(reg4>0)// && index!=AC5V && index!=AC500uA && index!=AC5mA && index!=AC50mA && index!=AC500mA && index!=AC10A)
			return 999999999;
		else
			RawData = (double)RMSData;
	}
	else{
		ADCDigital=readADC1();

		if ((ADCDigital < 0) || (ADCDigital > 0x800000)) {
			ADCDigital = ~(ADCDigital | 0xFF000000);
			minus=true;
		}else
			minus=false;

		if(ADCDigital==0x7ffffe)
			return 999999999;
		else
			RawData=(double)ADCDigital;
	}

	if(minus==true)
		RawData=RawData*-1;

	busyState=false;
	qDebug()<<"Raw Data- Before GAin & Offset:"<<RawData;
	return RawData;
}
void HY3131DMMLib::buzzerState(bool state){
	if(buzState!=state){
		buzState=state;
		if(state){
//			if(selAppCard)
//				IAppCard->writeRegister(0x07, DMM_RLY_SEL);
//			else
				IBackPlane->writeBackPlaneRegister(0x07, DMM_RLY_SEL_BP);
			//qDebug()<<"Buzzer ON";
		}
		else{
//			if(selAppCard)
//				IAppCard->writeRegister(0x05, DMM_RLY_SEL);
//			else
				IBackPlane->writeBackPlaneRegister(0x05, DMM_RLY_SEL_BP);
			usleep(1000);
			//qDebug()<<"Buzzer OFF";
		}
	}
}
void HY3131DMMLib::writeDMMSPI(u_int16_t _Address, u_int16_t _Data){
	busyState=true;
	unsigned int mAddr = 0, mData = 0;

	mAddr = _Address;
	mAddr = mAddr << 1;
	mAddr = mAddr & 0xFE;

//	if(selAppCard)
//		IAppCard->writeRegister(mAddr, DMM_ADDR);
//	else
		IBackPlane->writeBackPlaneRegister(mAddr, DMM_ADDR_BP);

	mData = _Data << 8;
//	if(selAppCard)
//		IAppCard->writeRegister(mData, DMM_DATA_TX_MSW);
//	else
		IBackPlane->writeBackPlaneRegister(mData, DMM_DATA_TX_MSW_BP);

//	if(selAppCard)
//		IAppCard->writeRegister(0xC001, DMM_CMD);
//	else
		IBackPlane->writeBackPlaneRegister(0xC001, DMM_CMD_BP);

//	if(selAppCard)
//		while ((IAppCard->readRegister(DMM_CMD) & 0x0001));
//	else
		while ((IBackPlane->readBackPlaneRegister(DMM_CMD_BP) & 0x0001));

	//qDebug()<<"writeDMMSPI:"<<"Address:"<<hex<<mAddr<<"Data:"<<hex<<mData;
	usleep(5000);
	busyState=false;
}
u_int32_t HY3131DMMLib::readDMMSPI(u_int16_t _Address) {
	busyState=true;
	u_int32_t mAddr = 0, mLData = 0, mMData = 0;

//	if(selAppCard)
//		IAppCard->writeRegister(0x0, DMM_DATA_TX_MSW);
//	else
		IBackPlane->writeBackPlaneRegister(0x0, DMM_DATA_TX_MSW_BP);

//	if(selAppCard)
//		IAppCard->writeRegister(0x0, DMM_DATA_TX_LSW);
//	else
		IBackPlane->writeBackPlaneRegister(0x0, DMM_DATA_TX_LSW_BP);

	mAddr = _Address;
	mAddr = mAddr << 1;
	mAddr = mAddr | 0x01;

//	if(selAppCard)
//		IAppCard->writeRegister(mAddr, DMM_ADDR);
//	else
		IBackPlane->writeBackPlaneRegister(mAddr, DMM_ADDR_BP);

//	if(selAppCard)
//		IAppCard->writeRegister(0xC009, DMM_CMD);
//	else
		IBackPlane->writeBackPlaneRegister(0xC009, DMM_CMD_BP);

//	if(selAppCard)
//		while ((IAppCard->readRegister(DMM_CMD) & 0x0001));
//	else
		while ((IBackPlane->readBackPlaneRegister(DMM_CMD_BP) & 0x0001));

	usleep(1000);

//	if(selAppCard)
//			mMData = IAppCard->readRegister(DMM_DATA_RX_MSW);
//	else
			mMData = IBackPlane->readBackPlaneRegister(DMM_DATA_RX_MSW_BP);

//	if(selAppCard)
//		mLData = IAppCard->readRegister(DMM_DATA_RX_LSW);
//	else
		mLData = IBackPlane->readBackPlaneRegister(DMM_DATA_RX_LSW_BP);

	D32Bit = (((mMData << 16) & 0xFFFF0000)| (mLData & 0x0000FFFF));
	busyState=false;
	return D32Bit;
}

u_int32_t HY3131DMMLib::readADC1(u_int8_t r0,u_int8_t r1,u_int8_t r2){
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
		textStream.flush();
	}
     textFile.close();
	//qDebug()<<"samples:"<<m_nSampleCount;
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	busyState=true;
	//Clear SPI RX Registors
//	if(selAppCard)
//		IAppCard->writeRegister(0x0, DMM_DATA_TX_MSW);
//	else
		IBackPlane->writeBackPlaneRegister(0x0, DMM_DATA_TX_MSW_BP);
//	if(selAppCard)
//		IAppCard->writeRegister(0x0, DMM_DATA_TX_LSW);
//	else
		IBackPlane->writeBackPlaneRegister(0x0, DMM_DATA_TX_LSW_BP);
	usleep(1000);

	u_int32_t a, b, c, t, t2,temp=0;

	//Read ADC1
	for(int i=0;i<m_nSampleCount;i++){
		reg0 = (u_int8_t) readDMMSPI(r0) & 0x000000FF;
		reg1 = (u_int8_t) readDMMSPI(r1) & 0x000000FF;
		reg2 = (u_int8_t) readDMMSPI(r2) & 0x000000FF;

		//Shift & Combine
		a = reg0;
		b = (reg1 << 8);
		c = (reg2 << 16);

		t = a | b;
		t2 = t | c;

		temp+=t2;
	}
	temp=temp/m_nSampleCount;
	//qDebug()<<"_______________________________________________________________";
        qDebug()<<"ADC Read Data:"<<hex<<temp;
	busyState=false;

	return temp;
}
u_int32_t HY3131DMMLib::readADC2(){
	return (readADC1(0x03,0x04,0x05));
}
u_int32_t HY3131DMMLib::readLPF(){
	return (readADC1(0x06,0x07,0x08));
}
/*(20062014)u_int64_t*/u_int32_t HY3131DMMLib::readRMS(){
	busyState=true;
	/*(20062014)u_int64_t*/u_int32_t _reg_t1=0, _reg_t2=0, _reg_t3=0, _reg_t4=0, _reg_t5=0, _rms=0;
	RMSData = 0;

	//Read Registers
	reg0 = (u_int8_t) readDMMSPI(0x09) & 0x000000FF;
	reg1 = (u_int8_t) readDMMSPI(0x0A) & 0x000000FF;
	reg2 = (u_int8_t) readDMMSPI(0x0B) & 0x000000FF;
	reg3 = (u_int8_t) readDMMSPI(0x0C) & 0x000000FF;
	reg4 = (u_int8_t) readDMMSPI(0x0D) & 0x000000FF;

	//Shift & Combine Registers
	_reg_t1 = reg0;
	_reg_t2 = (reg1 << 8);
	_reg_t3 = (reg2 << 16);
	_reg_t4 = (reg3 << 24);
	/*(20062014)_reg_t5 = (reg4 << 32);*/


	_rms = _reg_t1;
	_rms = _rms | _reg_t2;
	_rms = _rms | _reg_t3;
	_rms = _rms | _reg_t4;

	/*(20062014)_rms = _rms | _reg_t5;*/
	//qDebug()<<"======================================================================";
//	qDebug()<<"RMS ADC Read Data-Before Mask:"<<QString::number(_rms,16);

	//Mask 0:37 Registers
	/*_rms =_rms & 0x3FFFFFFFFFLL;*/
	busyState=false;
	//qDebug()<<"reg-0x9:"<<hex<<reg0<<endl<<"reg-0xA:"<<hex<<reg1<<endl<<"reg-0xB:"<<hex<<reg2<<endl<<"reg-0xC:"<<hex<<reg3<<endl<<"reg-0xD:"<<hex<<reg4<<endl
	//qDebug()<<"hy3131dmmlib.cpp-RMS ADC Read Data:"<<QString::number(_rms,16);
//	qDebug()<<"PKHMAX:"<<hex<<readPKHMAX();	usleep(100);
//	qDebug()<<"PKHMIN:"<<hex<<readPKHMIN();	usleep(100);
		qDebug()<<"RMS<39:32>     :"<<hex<<reg4;
        qDebug()<<"RMS Data       :"<<hex<<_rms;
	return _rms;
}
u_int32_t HY3131DMMLib::readPKHMIN(){
	return (readADC1(0x0E,0x0F,0x10));
}
u_int32_t HY3131DMMLib::readPKHMAX(){

	return (readADC1(0x11,0x12,0x13));
}


Q_EXPORT_PLUGIN2(IHY3131DMMLibInterface, HY3131DMMLib)
