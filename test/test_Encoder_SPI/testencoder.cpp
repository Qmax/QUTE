#include "testencoder.h"
#include "ui_testencoder.h"

TestEncoder::TestEncoder(QWidget *parent) :
QMainWindow(parent), ui(new Ui::TestEncoder) {
	ui->setupUi(this);

	QPluginLoader loader4("libQmaxPTInterface.so", this);
	ILineEdit = qobject_cast<IQmaxLineEdit*> (loader4.instance());
	IPTLibrary = qobject_cast<IQmaxPTLibrary*> (loader4.instance());
	INumberPanel = qobject_cast<IQmaxNumberPanel*> (loader4.instance());

	QPluginLoader loader3("libGPIOEventInterface.so",this);
	IGPIOEvent = qobject_cast<PTGPIOEventInterface*>(loader3.instance());
	IGPIOEvent->InvokeGPIOEvent(this, "/dev/input/event1", "gpioevent", &m_nKeyCode);

	QPluginLoader loader2("libBackPlaneInterface.so", this);
	IBackPlane = qobject_cast<IntefaceBackPlane*> (loader2.instance());
	IBackPlane->InitializeBpObject();
	IBackPlane->writeBackPlaneRegister(0x00, 0x48);

	SPItimer = new QTimer(this);
	connect(SPItimer, SIGNAL(timeout()), this, SLOT(readSPI()));

	m_objLE_ADDR = ILineEdit->QmaxLineEdit(0, ui->gridGroupBox_2);
	m_objLE_ADDR->setGeometry(ui->leAddr->geometry());
	m_objLE_ADDR->setStyleSheet(ui->leAddr->styleSheet());

	m_objLE_DATA = ILineEdit->QmaxLineEdit(1,ui->gridGroupBox_2);
	m_objLE_DATA->setGeometry(ui->leData->geometry());
	m_objLE_DATA->setStyleSheet(ui->leData->styleSheet());

	connect(m_objLE_ADDR, SIGNAL(focussed(bool)), this, SLOT(callAddressEdit()));
	connect(m_objLE_DATA, SIGNAL(focussed(bool)), this, SLOT(callDataEdit()));

	m_nAddress=m_nData=0;

	this->setGeometry( QStyle::alignedRect(Qt::LeftToRight,Qt::AlignCenter,this->size(),qApp->desktop()->availableGeometry()));
}

TestEncoder::~TestEncoder() {
	delete ui;
}
void TestEncoder::customEvent(QEvent *e)
{
	if(e->type() == ((QEvent::Type)KnobEvent))
	{
		qDebug()<<"Event Raised";
	}
	QEvent(e->type());
}
void TestEncoder::callAddressEdit() {
	if (m_objLE_ADDR->hasFocus()) {
		openNumKBPanel(0);
		m_nLineEditIndex = 0;
	}

}

void TestEncoder::callDataEdit() {
	if (m_objLE_DATA->hasFocus()) {
		openNumKBPanel(0);
		m_nLineEditIndex = 1;
	}
}
void TestEncoder::openNumKBPanelminmax(short int pValue, double pMax, double pMin) {
	QWidget *w = INumberPanel->getNumKBPanelIncDec(pValue, 1, 'T', pMax, pMin,
			this);
	w->setWindowFlags(Qt::WindowCloseButtonHint | Qt::Dialog);
	w->show();

}

void TestEncoder::openNumKBPanel(short int pValue) {
	QWidget *w = INumberPanel->getNumKBPanel(pValue, this);
	w->setWindowFlags(Qt::WindowCloseButtonHint | Qt::Dialog);
	w->show();
}

void TestEncoder::receiveValue(unsigned int pValue) {
	if (m_nLineEditIndex == 0) {
		m_nAddress = pValue;
	} else if (m_nLineEditIndex == 1) {
		m_nData = pValue;
	}
}
void TestEncoder::receiveValue(QString pValue) {
	if (m_nLineEditIndex == 0) {
		m_objLE_ADDR->setText(pValue);
	} else if (m_nLineEditIndex == 1) {
		m_objLE_DATA->setText(pValue);
	}
}
void TestEncoder::receiveValue(double pValue) {
	Q_UNUSED(pValue)
}

void TestEncoder::changeEvent(QEvent *e) {
	QMainWindow::changeEvent(e);
	switch (e->type()) {
	case QEvent::LanguageChange:
		ui->retranslateUi(this);
		break;
	default:
		break;
	}
}

void TestEncoder::on_exit_clicked() {
	this->close();
}

void TestEncoder::on_stop_clicked() {
	ui->status->setStyleSheet("background-color: rgb(255,0, 0);border-radius:9px;");
	SPItimer->stop();
}

void TestEncoder::on_pushButton_clicked() {
	ui->status->setStyleSheet("background-color: rgb(0, 255, 0);border-radius:9px;");
	SPItimer->start(250);
}
void TestEncoder::readSPI() {

	IBackPlane->writeBackPlaneRegister(0xC00B, 0x0028);
	usleep(1000);
	while (IBackPlane->readBackPlaneRegister(0x0028) & 0x0001);
	spiData = IBackPlane->readBackPlaneRegister(0x002E);
	m_nEncoder=spiData & 0x00FF;
	m_nSwitch=spiData & 0x0100;

	qDebug()<<"spiData:"<<hex<<spiData;
	ui->dial->setValue(m_nEncoder);
	ui->dataHex->setText(QString::number(m_nEncoder,16));
	ui->dataDec->setText(QString::number(m_nEncoder,10));
	if(m_nSwitch==0x0100)
		ui->swStatus->setText("ON");
	else
		ui->swStatus->setText("OFF");
}

void TestEncoder::on_pbAddr_clicked()
{
	IBackPlane->writeBackPlaneRegister(m_nData, m_nAddress);
}

void TestEncoder::on_pbData_clicked()
{
	m_objLE_DATA->setText(QString::number(IBackPlane->readBackPlaneRegister(m_nAddress), 16));
}
