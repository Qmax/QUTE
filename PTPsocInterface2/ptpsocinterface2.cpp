#include "ptpsocinterface2.h"

struct serial_struct serinfo;
Seriallib *obj;
unsigned int readData = 0, writeData = 0;
int fdSerial, comport = 3, baudRate;
BaudRateType baudRateValue;

Seriallib::Seriallib() {
	QString portName = QLatin1String("ttyS2");
	baudRateValue = BAUD38400;
	PortListener(portName);
	if (port->open(QIODevice::ReadWrite) == true) {
		if (!(port->lineStatus() & LS_DSR))
			Q_UNUSED(port->lineStatus())
	} else {
		qDebug() << "ptpsocinterface : device failed to open:" << port->errorString();
	}
}
Seriallib::Seriallib(QObject *p) {
	QObject::connect(obj, SIGNAL(Error(bool)), p, SLOT(psocError(bool)));
}
void Seriallib::PortListener(const QString & portName) {
	this->port = new QextSerialPort(portName, QextSerialPort::EventDriven);
	port->setBaudRate(baudRateValue);
	port->setFlowControl(FLOW_OFF);
	port->setParity(PAR_NONE);
	port->setDataBits(DATA_8);
	port->setStopBits(STOP_1);
	port->setTimeout(10);
}
unsigned int Seriallib::onReadyRead() {
	unsigned int l_nValue = 0;
	int counterLoop = 0;
	while (1) {
		counterLoop++;
		if (port->bytesAvailable()) {
			QByteArray l_arrValue = port->readAll();
			l_nValue = l_arrValue.toHex().toUInt(0, 16);
			break;
		}
		if (counterLoop == 50000) {
			break;
		}
		usleep(100);
//		qDebug() << "ptpsocinterface : PSoC Read Loop :"<<counterLoop;
	}
//	qDebug() << "ptpsocinterface : Counter Loop :" << counterLoop << "Read-Status :" <<hex<<l_nValue;
	return l_nValue;
}
QByteArray Seriallib::onReadyRead(QByteArray l_arrValue) {
	int counterLoop = 0;
	while (1) {
		counterLoop++;
		if (port->bytesAvailable()) {
			l_arrValue = port->readAll();
			break;
		}
		if (counterLoop == 50000) {
			break;
		}
		usleep(100);
	}
	//qDebug() << "ptpsocinterface : Counter Loop :" << counterLoop;
	//qDebug()<<"ptpsocinterface : onReadyRead:QByteArray : "<<l_arrValue;
	return l_arrValue;
}
unsigned int Seriallib::onReadyWrite(unsigned int cmd) {
	QByteArray xData;
	xData.append(cmd);
	port->write(xData);
	xData.clear();
	return 1;
}
unsigned int Seriallib::onCloseSerial() {
	port->close();
	return 1;
}
bool Seriallib::rxAck() {
	unsigned int rAck = onReadyRead();
	if (rAck == 0x2a2a2a23)
		return true;
	else if (rAck == 0x2a2a2a3f)
		return false;
	return false;
}
void Seriallib::openPort(QObject *parent) {
	Q_UNUSED(parent);
}
void PTPsocInterface2::createObject(QObject *parent) {
	Seriallib con(parent);
}
bool PTPsocInterface2::getAck() {
	return obj->rxAck();
}
int PTPsocInterface2::openSerial() {
	obj = new Seriallib();
//	qDebug() << "ptpsocinterface : ~~~~~~~~~~PSoC Interface Opened~~~~~~~~~~~";
	writeSerial(0xD0);
	quint16 ver_rev = readSerial();
	quint8 ver = (ver_rev >> 8);
	quint8 rev = ver_rev;
	qDebug() << "ptpsocinterface :  PSoC Firmware Version :" << hex << ver << "Revision :" << rev;


	src_impedance.insert(SRC_IMP_0E,"SRC0E");
	src_impedance.insert(SRC_IMP_10E,"SR10E");
	src_impedance.insert(SRC_IMP_20E,"SR20E");
	src_impedance.insert(SRC_IMP_50E,"SR50E");
	src_impedance.insert(SRC_IMP_100E,"S100E");
	src_impedance.insert(SRC_IMP_200E,"S200E");
	src_impedance.insert(SRC_IMP_500E,"S500E");
	src_impedance.insert(SRC_IMP_1KE,"SRC1K");
	src_impedance.insert(SRC_IMP_2KE,"SRC2K");
	src_impedance.insert(SRC_IMP_5KE,"SRC5K");
	src_impedance.insert(SRC_IMP_10KE,"SR10K");
	src_impedance.insert(SRC_IMP_20KE,"SR20K");
	src_impedance.insert(SRC_IMP_50KE,"SR50K");
	src_impedance.insert(SRC_IMP_100KE,"S100K");
	src_impedance.insert(SRC_IMP_200KE,"S200K");
	src_impedance.insert(SRC_IMP_500KE,"S500K");
	src_impedance.insert(SRC_IMP_1ME,"SRC1M");
	src_impedance.insert(SRC_IMP_1E,"SREX1");
	src_impedance.insert(SRC_IMP_2E,"SREX2");
	src_impedance.insert(SRC_IMP_3E,"SREX3");
	src_impedance.insert(SRC_IMP_4E,"SREX4");
	src_impedance.insert(SRC_IMP_5E,"SREX5");
	src_impedance.insert(SRC_IMP_6E,"SREX6");
	src_impedance.insert(SRC_IMP_7E,"SREX7");

	return 1;
}
int PTPsocInterface2::configSerial(int fd, int nSpeed, int nBits, char nEvent,
		int nStop) {
	Q_UNUSED(fd);
	Q_UNUSED(nSpeed);
	Q_UNUSED(nBits);
	Q_UNUSED(nEvent);
	Q_UNUSED(nStop);
	return 0;
}
unsigned int PTPsocInterface2::readSerial() {
	bool ok;
	unsigned int ret;
	QByteArray l_arrValue, readArray;
	QList<QByteArray> lines;
	readArray = obj->onReadyRead(l_arrValue);
	if (readArray.startsWith("***#") == true) {
		lines = readArray.split('#');
//		qDebug() << "ptpsocinterface : Command executed by PSOC";
		QString str = lines.at(1).toHex();
		ret = str.toUInt(&ok, 16);
		return ret;
	} else if (readArray.startsWith("***?") == true) {
		lines = readArray.split('?');
		qDebug() << "ptpsocinterface : Command not executed by PSOC";
		QString str = lines.at(1).toHex();
		ret = str.toUInt(&ok, 16);
		return ret;
	} else {
		qDebug() << "ptpsocinterface : PSOC Communication Failure";
		return 0;
	}
}
QByteArray PTPsocInterface2::readSerByte() {
	QByteArray l_arrValue;
	return obj->onReadyRead(l_arrValue);
}
unsigned int PTPsocInterface2::writeSerial(unsigned int writeData) {
	obj->onReadyWrite(writeData);
	return 0;
}
int PTPsocInterface2::closeSerial() {
	obj->onCloseSerial();
//	qDebug() << "ptpsocinterface : ~~~~~~~~~~PSoC Interface Closed~~~~~~~~~~~";
	return 1;
}
unsigned int PTPsocInterface2::readPsocCodeID() {
	int l_nCodeIdAck;
	writeSerial(Psoc_CodeId);
	usleep(1000);
	l_nCodeIdAck = readSerial();
	return l_nCodeIdAck;
}
void PTPsocInterface2::icmMeasurement() {
//	qDebug("\nicm called");
	writeSerial(l_nIcmValue);

	QByteArray ackData,readData;
	readData=obj->onReadyRead(ackData);
	if(readData=="ICMSL"){
//		qDebug() << "ptpsocinterface : ICM Switched.";
	}
	else
		qDebug() << "ptpsocinterface : Command Not Executed by PSoC:"<<readData;

//	if (getAck() == true)
//		qDebug() << "ptpsocinterface : icmMeasurement Command executed by PSOC";
//	else
//		qDebug() << "ptpsocinterface : Acknowledgement Failure....";
}
//External Mux Measurement Functions--------------------------------------------------------
void PTPsocInterface2::switchFly(){
//	qDebug("\nSwitch Fly Channel");
	writeSerial(l_nSwitchFly);

	QByteArray ackData,readData;
	readData=obj->onReadyRead(ackData);
	if(readData=="FLYCH"){
//		qDebug() << "ptpsocinterface : Flying External Channel Switched";
	}
	else
		qDebug() << "ptpsocinterface : Command Not Executed by PSoC:"<<readData;

//	if (getAck() == true)
//		qDebug() << "ptpsocinterface : Flying Channel Command executed by PSOC";
//	else
//		qDebug() << "ptpsocinterface : Acknowledgement Failure....";
}
unsigned int PTPsocInterface2::externalMuxMeasurement(unsigned int testInput,
		unsigned int refInput) {
	writeSerial(l_nExternalMuxValue);
	usleep(5000);
 	if (getAck() == true){
//		qDebug() << "ptpsocinterface : externalMuxMeasurement Command Received by PSOC.";
 	}
	else
		qDebug() << "ptpsocinterface : externalMuxMeasurement Command Not Received by PSOC.";
	writeSerial(testInput);
	writeSerial(refInput);
	return 1;
}
bool PTPsocInterface2::readMuxStatus() {
	qDebug("\nread mux called");
	if (readSerByte() == "SUCCESS"){
//		qDebug() << "ptpsocinterface : read mux status success";
		return true;
	}
	else{
		qDebug() << "ptpsocinterface : read mux status failure";
		return false;
	}
}
unsigned int PTPsocInterface2::muxDetection() {
	unsigned int det;
	writeSerial(0x0A);
	usleep(10000);
	det=readSerial();
//	qDebug() << "ptpsocinterface : mux detection:"<<hex<<det;
	return det;

}
unsigned int PTPsocInterface2::switchTest(unsigned int testChannel) {
//	qDebug() << "ptpsocinterface : switchTest Command 0x0B" << testChannel;
	writeSerial(0x0B);//added on 25th Apr 2013
	usleep(5000);

	if (getAck() == true){
//		qDebug() << "ptpsocinterface : Command Received by PSOC.";
	}
	else
		qDebug() << "ptpsocinterface : Command Not Received by PSOC.";
	writeSerial(testChannel);
	usleep(5000);

	if (getAck() == true) {
		//qDebug() << "ptpsocinterface : switchTest Command executed by PSOC";
		return 1;
	} else {
		qDebug() << "ptpsocinterface : switchTest Acknowledgement Failure....";
		return 0;
	}
	return 0;
}
unsigned int PTPsocInterface2::switchRef(unsigned int refChannel) {
	//qDebug() << "ptpsocinterface : switchRef Command 0x0c" << refChannel;
	writeSerial(0x0C);//added on 25th Apr 2013
	usleep(5000);

	if (getAck() == true){
		//qDebug() << "ptpsocinterface : Command Received by PSOC.";
	}
	else
		qDebug() << "ptpsocinterface : Command Not Received by PSOC.";
	writeSerial(refChannel);
	usleep(5000);

	if (getAck() == true) {
		//qDebug() << "ptpsocinterface : switchRef Command executed by PSOC";
		return 1;
	} else {
		qDebug() << "ptpsocinterface : switchRef Acknowledgement Failure....";
		return 0;
	}
	return 0;
}
void PTPsocInterface2::srcImpedanceEnable(bool enableDisable){
//	qDebug("\nSource Impedance Enable/Disable \n");
	if(enableDisable==true){
		writeSerial(l_nSRCIMPEnable);
		usleep(1000);

		QByteArray ackData,readData;
		readData=obj->onReadyRead(ackData);
		if(readData=="SRCEN"){
			//qDebug() << "ptpsocinterface : Source Impedance Enabled.";
		}
		else
			qDebug() << "ptpsocinterface : Command Not Executed by PSoC:"<<readData;

//		if (getAck() == true)
//			qDebug() << "ptpsocinterface : Source Impedance Enabled";
//		else
//			qDebug() << "ptpsocinterface : Source Impedance Not Enabled";
	}
	else if(enableDisable==false){
		writeSerial(l_nSRCIMPDisable);
		usleep(2000);

		QByteArray ackData,readData;
		readData=obj->onReadyRead(ackData);
		if(readData=="SRCDS"){
			//qDebug() << "ptpsocinterface : Source Impedance Disabled.";
		}
		else
			qDebug() << "ptpsocinterface : Command Not Executed by PSoC:"<<readData;

//		if (getAck() == true)
//			qDebug() << "ptpsocinterface : Source Impedance Disabled";
//		else
//			qDebug() << "ptpsocinterface : Source Impedance Not Disabled";
	}
}

void PTPsocInterface2::srcImpedanceSelection(unsigned int src_imp_value) {
	qDebug()<<"\nSource Impedance Selection:"<<src_impedance.value(src_imp_value);//for delay dont delete
	writeSerial(0x51);
	usleep(5000);

	if (getAck() == true){
			//qDebug() << "ptpsocinterface : Command Received by PSOC.";
	}
		else
			qDebug() << "ptpsocinterface : Command Not Received by PSOC.";

	writeSerial(src_imp_value);
	usleep(2000);

	QByteArray ackData,readData;
	readData=obj->onReadyRead(ackData);
	if(readData==src_impedance.value(src_imp_value)){
		//qDebug() << "ptpsocinterface : Source Impedance "<<readData<<" Selected";
	}
	else
		qDebug() << "ptpsocinterface : Source Impedance Not Selected:"<<readData;

//	if (getAck() == true)
//		qDebug() << "ptpsocinterface : Src_imp Command executed by PSOC";
//	else
//		qDebug() << "ptpsocinterface : Src_imp Acknowledgement Failure....";

}

unsigned int PTPsocInterface2::changeBaudRate(unsigned int baudRate) {
	//1-9600 2-19200 3-38400 4-57600 5-115200
	writeSerial(0x50);
	if (getAck() == true){
//		qDebug() << "ptpsocinterface : Command Received by PSOC.";
	}
	else
		qDebug() << "ptpsocinterface : Command Not Received by PSOC.";
	writeSerial(baudRate);

	if (getAck() == true){
//		qDebug() << "ptpsocinterface : changeBaudRate Command executed by PSOC";
	}
	else
		qDebug() << "ptpsocinterface : Acknowledgement Failure....";

//	qDebug() << "ptpsocinterface : PSoC Baud Rate Changed";

	switch (baudRate) {
	case 1:
		baudRateValue = BAUD9600;
		break;
	case 2:
		baudRateValue = BAUD19200;
		break;
	case 3:
		baudRateValue = BAUD38400;
		break;
	case 4:
		baudRateValue = BAUD57600;
		break;
	case 5:
		baudRateValue = BAUD115200;
		break;
	}
	obj->port->close();
	QString portName = QLatin1String("ttyS2");// update this to use your port of choice
	obj->PortListener(portName);
	if (obj->port->open(QIODevice::ReadWrite) == true) {
		if (!(obj->port->lineStatus() & LS_DSR))
			Q_UNUSED(obj->port->lineStatus())
	} else {
		qDebug() << "ptpsocinterface : device failed to open:" << obj->port->errorString();
	}
//	qDebug() << "ptpsocinterface : ttyS2 Baud Rate Changed";
	return 0;
}
void PTPsocInterface2::FGMeasurement() {
//	qDebug("\nFG called\n");
	writeSerial(l_nFgValue);

	QByteArray ackData,readData;
	readData=obj->onReadyRead(ackData);
	if(readData=="FGSEL"){
		qDebug() << "ptpsocinterface : FG Switched.";
	}
	else
		qDebug() << "ptpsocinterface : FG Not Switched:"<<readData;

//	if (getAck() == true)
//		qDebug() << "ptpsocinterface : FGMeasurement Command executed by PSOC";
//	else
//		qDebug() << "ptpsocinterface : Acknowledgement Failure....";
}
unsigned int PTPsocInterface2::embeddedProbe() {
	int l_nProbeAck;
	writeSerial(embeddedKey);
	usleep(1000);
	l_nProbeAck = readSerial();
	return l_nProbeAck;
}
unsigned int PTPsocInterface2::embeddedProbeStatus() {
	int l_nProbeAck;
	writeSerial(0x18); //read embedded probe status
	usleep(1000);
	l_nProbeAck = readSerial();
	usleep(1000);
	qDebug() << "~~~~~~~~~~~~embedded probe status : "<<hex<<l_nProbeAck;
	return l_nProbeAck;
}
unsigned int PTPsocInterface2::embeddedProbeInterrupt() {
	int l_nProbeAck;
	writeSerial(embeddedKey);
	usleep(1000);
	l_nProbeAck = readSerial();
	return l_nProbeAck;
}
unsigned int PTPsocInterface2::resetRelays() {
//	qDebug("\nreset relay called");
	writeSerial(reset_relay);
	if (getAck() == true){
//		qDebug() << "ptpsocinterface : resetRelays Command executed by PSOC";
	}
	else
		qDebug() << "ptpsocinterface : Acknowledgement Failure....";
	return 1;
}
unsigned int PTPsocInterface2::readRelay() {
//	qDebug("\nread relay called");
	unsigned int l_nRl = 0;
	writeSerial(l_nReadRlyStatus);
	usleep(1000);
	l_nRl = readSerial();
	return l_nRl;
}
unsigned int PTPsocInterface2::readSRCIMPRelay(){
//	qDebug("\nread src imp relay called");
	unsigned int l_nRl = 0;
	writeSerial(l_nReadRlySRCStatus);
	usleep(1000);
	l_nRl = readSerial();
	return l_nRl;
}
unsigned int PTPsocInterface2::viTrace(unsigned int ch) {
//	qDebug("\nvi trace called");
	QByteArray ackData,readData;
	if (ch == 1){
		writeSerial(0xf1);
		usleep(1000);

		readData=obj->onReadyRead(ackData);
		if(readData=="VICH1"){
//			qDebug() << "ptpsocinterface : VI Channel-1 Switched";
		}
		else
			qDebug() << "ptpsocinterface : VI Channel-1 Not Switched:"<<readData;

	}

	else if (ch == 2){
		writeSerial(0xf2);
		usleep(1000);

		readData=obj->onReadyRead(ackData);
		if(readData=="VICH2"){
//			qDebug() << "ptpsocinterface : VI Channel-2 Switched";
		}
		else
			qDebug() << "ptpsocinterface : VI Channel-2 Not Switched:"<<readData;
	}
//	if (getAck() == true)
//		qDebug() << "ptpsocinterface : viTrace Command executed by PSOC";
//	else
//		qDebug() << "ptpsocinterface : Acknowledgement Failure....";
	return 1;
}
void PTPsocInterface2::vi_channels(unsigned int ch) {
	if (ch == 1){
		writeSerial(0xf1);
		usleep(1000);
	}
	else if (ch == 2){
		writeSerial(0xf2);
		usleep(1000);
	}
	else{
		writeSerial(No_Change);
		usleep(1000);
	}
}
Q_EXPORT_PLUGIN2(PTPsocInterface2, PTPsocInterface2)
