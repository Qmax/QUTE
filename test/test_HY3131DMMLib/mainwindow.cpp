#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFile>
#include <qpluginloader.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
	ADCTimer = new QTimer(this);
	connect(ADCTimer, SIGNAL(timeout()), this, SLOT(ADCRead()));

	QPluginLoader loader4("libHY3131DMMLib.so", this);
	hy3131dmm = qobject_cast<IHY3131DMMLibInterface*> (loader4.instance());

    ui->setupUi(this);

    dis=new DISPLAY(this);
    dis->selectGeometry(10,5);
    ui->lineEdit->setVisible(false);
    //Read Gain & Offset~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    int index=0;

    QFile file("/home/HY3131/GainOffset.dat");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
            return;
    while (!file.atEnd()) {

            QByteArray line = file.readLine();
            QList<QByteArray> data = line.split('\t');

            if (data[0].endsWith('\n'))
                    data[0].chop(1);

            ui->comboBox->addItem(data[0]);

            index++;
    }
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
}
void MainWindow::ADCRead(){
	double data=0;
	for(int i=0;i<16;i++){
		data+=hy3131dmm->Measure(ui->comboBox->currentIndex());
	}
	data/=16;
	if(data==999999999)
		dis->setValue("OL");
	else
		dis->setValue(data);
//	ui->lineEdit->setText(QString::number(data));

}
MainWindow::~MainWindow()
{
    delete ui;
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

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
	if(ADCTimer->isActive()){
		ADCTimer->stop();
		hy3131dmm->Configure(index);
		ADCTimer->start(100);
	}
	else
		hy3131dmm->Configure(index);

}

void MainWindow::on_pushButton_clicked()
{
    ADCTimer->start(100);
}

void MainWindow::on_pushButton_2_clicked()
{
    ADCTimer->stop();
}
