
#include "ptkeyknob.h"

PtKeyKnob::PtKeyKnob(QWidget *parent)
    : QWidget(parent)
{
	ui.setupUi(this);

	QPluginLoader loader2("libBackPlaneInterface.so", this);
	IBackPlane = qobject_cast<IntefaceBackPlane*> (loader2.instance());
	IBackPlane->InitializeBpObject();

    QPluginLoader loader5("libGPIOEventInterface.so",this);
    IGPIOEvent = qobject_cast<PTGPIOEventInterface*>(loader5.instance());

    QPluginLoader loader6("libPTKeyEventInterfaces.so",this);
    IPTKeyEvent = qobject_cast<PTEventInterface*>(loader6.instance());

	//~~~~~~~~~~~~Magnetic Rotary Knob~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	IBackPlane->writeOtpLsb(0x00);//to initialize read angle to 0 REG-0x18
	IBackPlane->setTimer(0xf9);  //to set timer interval -> (249*.001)+.001=.01Sec REG-0x1C
	ui.lineEdit_32->setText("250ms");
	IBackPlane->setKnobCommandRegsiter(0x03);//to start drive in loop.for single drive 0x01 REG-0x16
	ui.lineEdit_33->setText("loop");
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	IGPIOEvent->InvokeGPIOEvent(this, "/dev/input/event1", "gpioevent", &m_nGPIOCode);
	IPTKeyEvent->InvokeGPIOEvent(this, "/dev/input/event2", "pt_kpp", &m_nPTKeyCode);

	QLabel *dummy = new QLabel();
	IndicateKeyPressed(dummy);

	//interrupt initialization
	IBackPlane->writeBackPlaneRegister(0x0FFF, 0x001E); //clear all interrupts
	IBackPlane->writeBackPlaneRegister(0x0000, 0x0020); //disable all interrupts
	IBackPlane->writeBackPlaneRegister(0x0000, 0x0024); //disable global interrupt

	IBackPlane->writeBackPlaneRegister(0x0001, 0x0024); //disable global interrupt

	delay=2;

	enableRichGUI();
}
void PtKeyKnob::on_groupBox_24_clicked() {
	if (ui.groupBox_24->isChecked()) {
		IBackPlane->writeBackPlaneRegister(KNOBINT, 0x0020);
		ui.groupBox_24->setStyleSheet("QGroupBox::indicator {  width: 25px;  height: 25px;  border: 2px solid white; border-radius: 10px;color:red; background-color: green;font:14px bold;}QGroupBox{background-color: light gray;border: 2px solid black; border-radius: 10px; margin-top: 1ex; font:bold 14px;}QGroupBox::title { subcontrol-origin: margin; subcontrol-position: top center; /* position at the top center */ padding: 0 3px; background-color: border: 2px solid black; }");
		qDebug() << "Magnetic Knob Interrupt Enanbled";
	}
	 if(ui.groupBox_24->isChecked()==false) {
		IBackPlane->writeBackPlaneRegister(NOINT, 0x0020);
		ui.groupBox_24->setStyleSheet("QGroupBox::indicator {  width: 25px;  height: 25px;  border: 2px solid white; border-radius: 10px;color:red; background-color: gray;font:14px bold}QGroupBox{background-color: light gray;border: 2px solid black; border-radius: 10px; margin-top: 1ex; font:bold 14px;}QGroupBox::title { subcontrol-origin: margin; subcontrol-position: top center; /* position at the top center */ padding: 0 3px; background-color: border: 2px solid black;}");
		qDebug() << "Magnetic Knob Interrupt Disabled";
	}

}

void PtKeyKnob::customEvent(QEvent *eve) {

	QString strred = "background-color:rgb(255,0,0);border: 2px solid white;text-align: center;font:bold 14px;";
	QString strgreen = "background-color:rgb(0,170,0);border: 2px solid white;text-align: center;font:bold 14px;";
	QString strorange = "background-color:rgb(255,170,0);border: 2px solid white;text-align: center;font:bold 14px;";
	unsigned int l_nRegisterValue;

	if (eve->type() == KnobEvent) {
		l_nRegisterValue = IBackPlane->readBackPlaneRegister(0x001E);
		IBackPlane->writeBackPlaneRegister(0x0900, 0x001E);
		//~~~~~~~Magnetic Rotary Knob~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		unsigned int readData, maskedAngle, maskedGain, dataValidity;
		int decAngle, decGain;
		double degree, strength;
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		readData = IBackPlane->readAngle();
		maskedAngle = readData & 0x00FF;
		maskedGain = (readData & 0xFF00) >> 8;
		decAngle = maskedAngle;
		decGain = maskedGain;
		dataValidity = (maskedGain & 0x40) >> 6;
		degree = (double) decAngle * 1.411;
		strength = 37 + (maskedGain ^ 0xff) - 128;
		ui.dial->setValue(decAngle);
		ui.lineEdit_28->setText(QString::number(decGain, 10));
		ui.lineEdit_29->setText(QString::number(maskedGain, 16));
		ui.lineEdit_30->setText(QString::number(decAngle, 10));
		ui.lineEdit_31->setText(QString::number(maskedAngle, 16));
		ui.lineEdit_34->setText(QString::number(degree, 'f', 1)
		+ QChar(0x00B0));
		ui.lineEdit_35->setText(QString::number(dataValidity, 16));
		if (dataValidity == 0x01)
			ui.lineEdit_35->setStyleSheet(strgreen);
		else
			ui.lineEdit_35->setStyleSheet(strred);
		ui.progressBar->setValue(strength);
		if (strength <= 37) {
			ui.progressBar->setStyleSheet(strred);
			ui.label_159->setText("No Signal");
		} else if (strength > 37 && strength <= 54) {
			ui.progressBar->setStyleSheet(strorange);
			ui.label_159->setText("Weak Signal");
		} else if (strength > 54 && strength <= 100) {
			ui.progressBar->setStyleSheet(strgreen);
			ui.label_159->setText("Strong Signal");
		} else {
			ui.progressBar->setStyleSheet(strred);
			ui.label_159->setText("Invalid Data");
		}
		IBackPlane->writeBackPlaneRegister(0x0001, 0x0024);
	}

	if (eve->type() == PTKeyEvent) {
		if (m_nPTKeyCode == 1) {
			qDebug() << ("\nMENU_KEY Pressed");
			IndicateKeyPressed(ui.label_160);
		} else if (m_nPTKeyCode == 2) {
			qDebug() << ("\nESC_KEY Pressed");
			IndicateKeyPressed(ui.label_170);
		} else if (m_nPTKeyCode == 3) {
			qDebug() << ("\nNULL_KEY Pressed");

		} else if (m_nPTKeyCode == 4) {
			qDebug() << ("\nF1_KEY Pressed");
			IndicateKeyPressed(ui.label_165);
		} else if (m_nPTKeyCode == 5) {
			qDebug() << ("\nF2_KEY Pressed");
			IndicateKeyPressed(ui.label_166);
		} else if (m_nPTKeyCode == 6) {
			qDebug() << ("\nF3_KEY Pressed");
			IndicateKeyPressed(ui.label_167);
		} else if (m_nPTKeyCode == 7) {
			qDebug() << ("\nF4_KEY Pressed");
			IndicateKeyPressed(ui.label_168);
		} else if (m_nPTKeyCode == 8) {
			qDebug() << ("\nF5_KEY Pressed");
			IndicateKeyPressed(ui.label_169);
		} else if (m_nPTKeyCode == 9) {
			qDebug() << ("\nUP_KEY Pressed");
			IndicateKeyPressed(ui.label_171);
		} else if (m_nPTKeyCode == 10) {
			qDebug() << ("\nDOWN_KEY Pressed");
			IndicateKeyPressed(ui.label_172);
		} else if (m_nPTKeyCode == 11) {
			qDebug() << ("\nRIGHT_KEY Pressed");
			IndicateKeyPressed(ui.label_174);
		} else if (m_nPTKeyCode == 12) {
			qDebug() << ("\nLEFT_KEY Pressed");
			IndicateKeyPressed(ui.label_173);
		} else if (m_nPTKeyCode == 13) {
			qDebug() << ("\nENTER__KEY Pressed");
			IndicateKeyPressed(ui.label_175);
		} else if (m_nPTKeyCode == 14) {
			qDebug() << ("\nSETUP_KEY Pressed");
			IndicateKeyPressed(ui.label_161);
		} else if (m_nPTKeyCode == 15) {
			qDebug() << ("\nDEFAULT_KEY Pressed");
			IndicateKeyPressed(ui.label_162);
		} else if (m_nPTKeyCode == 16) {
			qDebug() << ("\nTOUCH_KEY Pressed");
			IndicateKeyPressed(ui.label_163);
		} else if (m_nPTKeyCode == 17) {
			qDebug() << ("\nFILE_KEY Pressed");
			IndicateKeyPressed(ui.label_164);
		} else if (m_nPTKeyCode == 18) {
			qDebug() << ("\nSCALE_KEY Pressed");
			IndicateKeyPressed(ui.label_176);
		} else if (m_nPTKeyCode == 19) {
			qDebug() << ("\nRUN/STOP_KEY Pressed");
			IndicateKeyPressed(ui.label_177);
		}
	}
	QEvent(eve->type());
}
void PtKeyKnob::IndicateKeyPressed(QLabel *label) {
	QString strred =
			"font: bold 14px;color: rgb(255, 255, 255);background-color:rgb(88,88,88);border: 1px solid white;border-radius: 23px;";
	QString strgreen =
			"font: bold 14px;color: rgb(5, 5, 90);background-color:rgb(0,170,0);border: 1px solid white;border-radius: 23px;";

	ui.label_160->setStyleSheet(strred);
	ui.label_161->setStyleSheet(strred);
	ui.label_162->setStyleSheet(strred);
	ui.label_163->setStyleSheet(strred);
	ui.label_164->setStyleSheet(strred);
	ui.label_165->setStyleSheet(strred);
	ui.label_166->setStyleSheet(strred);
	ui.label_167->setStyleSheet(strred);
	ui.label_168->setStyleSheet(strred);
	ui.label_169->setStyleSheet(strred);
	ui.label_170->setStyleSheet(strred);
	ui.label_171->setStyleSheet(strred);
	ui.label_172->setStyleSheet(strred);
	ui.label_173->setStyleSheet(strred);
	ui.label_174->setStyleSheet(strred);
	ui.label_175->setStyleSheet(strred);
	ui.label_176->setStyleSheet(strred);
	ui.label_177->setStyleSheet(strred);

	ui.label_160->setFrameShadow(QFrame::Sunken);
	ui.label_161->setFrameShadow(QFrame::Sunken);
	ui.label_162->setFrameShadow(QFrame::Sunken);
	ui.label_163->setFrameShadow(QFrame::Sunken);
	ui.label_164->setFrameShadow(QFrame::Sunken);
	ui.label_165->setFrameShadow(QFrame::Sunken);
	ui.label_166->setFrameShadow(QFrame::Sunken);
	ui.label_167->setFrameShadow(QFrame::Sunken);
	ui.label_168->setFrameShadow(QFrame::Sunken);
	ui.label_169->setFrameShadow(QFrame::Sunken);
	ui.label_170->setFrameShadow(QFrame::Sunken);
	ui.label_171->setFrameShadow(QFrame::Sunken);
	ui.label_172->setFrameShadow(QFrame::Sunken);
	ui.label_173->setFrameShadow(QFrame::Sunken);
	ui.label_174->setFrameShadow(QFrame::Sunken);
	ui.label_175->setFrameShadow(QFrame::Sunken);
	ui.label_176->setFrameShadow(QFrame::Sunken);
	ui.label_177->setFrameShadow(QFrame::Sunken);

	label->setStyleSheet(strgreen);
	label->setFrameShadow(QFrame::Raised);
}
PtKeyKnob::~PtKeyKnob()
{
IBackPlane->closeObject();
}
void PtKeyKnob::enableRichGUI(){
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

	ui.groupBox->setParent(m_objWidget);
	ui.groupBox_24->setParent(m_objWidget);
	ui.groupBox_25->setParent(m_objWidget);


	ui.groupBox->setGeometry(420,10,371,281);
	ui.groupBox_24->setGeometry(10,10,401,281);
	ui.groupBox_25->setGeometry(10,310,781,201);


}

void PtKeyKnob::changeDelay(int value){
    delay=value;
}

void PtKeyKnob::on_pushButton_clicked()
{
    qDebug()<<"ON/OFF Started with delay "<<delay<<"sec";
    IBackPlane->writeBackPlaneRegister(0x0,0x14);
    sleep(delay);
    IBackPlane->writeBackPlaneRegister(0x3,0x14);
    sleep(delay);
    IBackPlane->writeBackPlaneRegister(0x0,0x14);
    sleep(delay);
    IBackPlane->writeBackPlaneRegister(0x3,0x14);
    sleep(delay);
    IBackPlane->writeBackPlaneRegister(0x0,0x14);
    sleep(delay);
    IBackPlane->writeBackPlaneRegister(0x3,0x14);
    sleep(delay);
    IBackPlane->writeBackPlaneRegister(0x0,0x14);
    sleep(delay);
    IBackPlane->writeBackPlaneRegister(0x3,0x14);
    sleep(delay);
    IBackPlane->writeBackPlaneRegister(0x0,0x14);
    sleep(delay);
    IBackPlane->writeBackPlaneRegister(0x3,0x14);
    qDebug()<<"ON/OFF Tested 5 times....";
}

void PtKeyKnob::on_spinBox_2_valueChanged(int val )
{
    IBackPlane->writeBackPlaneRegister(val,0x12);
    qDebug()<<"Duty Cycle :"<<val;
}

void PtKeyKnob::on_spinBox_valueChanged(int val)
{
    IBackPlane->writeBackPlaneRegister(val,0x10);
    qDebug()<<"Period :"<<val;
}

void PtKeyKnob::on_spinBox_3_valueChanged(int val)
{
    changeDelay(val);
}
