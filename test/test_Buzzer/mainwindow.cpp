#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <unistd.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPluginLoader loader2("libBackPlaneInterface.so", this);
    IBackPlane = qobject_cast<IntefaceBackPlane*> (loader2.instance());
    IBackPlane->InitializeBpObject();

    t1=1000;    t2=1;    t3=50;
    v1=20;      v2=1;    v3=50;

    volume=4;   buzzerFlag=false;


}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::Beep(bool state) {
    if (state == true) {
        IBackPlane->writeBackPlaneRegister(volume, 0x16);
        BuzzerTone(t1, t2, t3);
        BuzzerVolume(v1, v2, v3);
    } else if (state == false) {
        usleep(100);
        IBackPlane->writeBackPlaneRegister(0x1, 0x0E);
        ui->lineEdit_10->setText("1");
        ui->spinBox_6->setValue(0);

        usleep(100);
        IBackPlane->writeBackPlaneRegister(0x1, 0x08);
        ui->lineEdit_9->setText("1");
        ui->spinBox_2->setValue(0);
    }
}
void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void MainWindow::on_spinBox_2_valueChanged(int val)
{
    v2=val;
    BuzzerVolume(v1, v2, v3);
}

void MainWindow::on_spinBox_4_valueChanged(int val)
{
    v3=val;
    BuzzerVolume(v1, v2, v3);
}

void MainWindow::on_spinBox_7_valueChanged(int val)
{
    t1=val;
    BuzzerTone(t1, t2, t3);
}

void MainWindow::on_spinBox_6_valueChanged(int val)
{
    t2=val;
    BuzzerTone(t1, t2, t3);
}

void MainWindow::on_spinBox_5_valueChanged(int val)
{
    t3=val;
    BuzzerTone(t1, t2, t3);
}

void MainWindow::on_spinBox_3_valueChanged(int val)
{
    volume=val;
    IBackPlane->writeBackPlaneRegister(volume, 0x16);
}

void MainWindow::on_pushButton_clicked()
{
    if(buzzerFlag==true){
        buzzerFlag=false;
        Beep(buzzerFlag);
    }
    else{
        buzzerFlag=true;
        Beep(buzzerFlag);
    }
}
void MainWindow::BuzzerVolume(unsigned int pFrequency,
		unsigned short pPWMFlag, unsigned int pPercentage) {

	IBackPlane->setBuzzerVolume(pFrequency,pPWMFlag,pPercentage);
/*	double l_nTime = 0.0;
	unsigned int l_nPeriodCounts = 0, l_nPercentage = pPercentage,
			l_nDutycyclecount = 0, l_nPWMValue = BP_BVCER_ENABLE_PERIOD;

	l_nTime = (double) (1.0 / pFrequency);
	ui->lineEdit->setText(QString::number(l_nTime));
	l_nPeriodCounts = l_nTime * 50000;  Period Count Value 50ms
	ui->lineEdit_2->setText(QString::number(l_nPeriodCounts,10));
	l_nDutycyclecount = (l_nPeriodCounts / 100) * l_nPercentage; Duty Cycle Count
	ui->lineEdit_3->setText(QString::number(l_nDutycyclecount,10));

	IBackPlane->writeBackPlaneRegister(l_nPeriodCounts, BP_BVCPR);  Buzzer volume control period register
	ui->lineEdit_7->setText(QString::number(l_nPeriodCounts,16));
	IBackPlane->writeBackPlaneRegister(l_nDutycyclecount, BP_BVCDCR);  Buzzer volume control duty cycle register
	ui->lineEdit_8->setText(QString::number(l_nDutycyclecount,16));

	if (pPWMFlag == 1) {
		l_nPWMValue |= BP_BVCER_ENABLE_PWM;
	}
	IBackPlane->writeBackPlaneRegister(l_nPWMValue, BP_BVCER);  Buzzer volume control Enable Register
	ui->lineEdit_9->setText(QString::number(l_nPWMValue,16));*/


}

void MainWindow::BuzzerTone(unsigned int pFrequency,
		unsigned short pPWMFlag, unsigned int pPercentage) {
	IBackPlane->setBuzzerTone(pFrequency,pPWMFlag,pPercentage);
/*	double l_nTime = 0.0;
	unsigned int l_nPeriodCounts = 0, l_nPercentage = pPercentage,
			l_nDutycyclecount = 0, l_nPWMValue = BP_BTCER_ENABLE_PERIOD;

	l_nTime = (double) (1.0 / pFrequency);
	ui->lineEdit_6->setText(QString::number(l_nTime));
	l_nPeriodCounts = l_nTime * 50000;  Period Count Value 50ms
	ui->lineEdit_5->setText(QString::number(l_nPeriodCounts,10));
	l_nDutycyclecount = (l_nPeriodCounts / 100) * l_nPercentage; Duty Cycle Count
	ui->lineEdit_4->setText(QString::number(l_nDutycyclecount,10));

	IBackPlane->writeBackPlaneRegister(l_nPeriodCounts, BP_BTCPR);  Buzzer tone control period register
	ui->lineEdit_12->setText(QString::number(l_nPeriodCounts,16));
	IBackPlane->writeBackPlaneRegister(l_nDutycyclecount, BP_BTCDCR);  Buzzer tone control duty cycle register
	ui->lineEdit_11->setText(QString::number(l_nDutycyclecount,16));

	if (pPWMFlag == 1) {
		l_nPWMValue |= BP_BTCER_ENABLE_PWM;
	}
	IBackPlane->writeBackPlaneRegister(l_nPWMValue, BP_BTCER);  Buzzer tone control Enable Register
	ui->lineEdit_10->setText(QString::number(l_nPWMValue,16));*/


}

void MainWindow::on_doubleSpinBox_valueChanged(double val)
{
    v1=(int)val;
    BuzzerVolume(v1, v2, v3);
}
