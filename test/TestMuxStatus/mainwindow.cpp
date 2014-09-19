#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qpluginloader.h>
#include <qmessagebox.h>
#include <unistd.h>
#include <qdebug.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPluginLoader loader3("libPTPsocInterface.so",this);
    IPsoc = qobject_cast<IPSOCCOMMUNICATION*>(loader3.instance());
    IPsoc->openSerial();
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

void MainWindow::on_pushButton_clicked()
{
	QMessageBox msgBox;
	qDebug()<<"Top Loop Code ID:"<<hex<<IPsoc->readPsocCodeID();
	int j=0;
	for(int i=0;i<ui->spinBox->value();i++)
	{
		IPsoc->writeSerial(0x55);
		//usleep(2000);
		unsigned int l_nLoopBack = IPsoc->readSerial();
		qDebug()<<"Loop Back:"<<hex<<l_nLoopBack;
		if(l_nLoopBack!=0x55)
		{
			ui->lineEdit->setText("FAILURE");
			break;
		}
		ui->lineEdit_2->setText(QString::number(i+1,10));
		if(j==10)
		{
			unsigned int l_nCodeValue = IPsoc->readRelay();
			usleep(1000);
			qDebug()<<"Inside Read Relay:"<<hex<<l_nCodeValue;
			if( l_nCodeValue != 0x40100010)
			{
				ui->lineEdit->setText("RELAY FAIL.");
				break;
			}
			j=0;
		}
		j++;
		if(i==ui->spinBox->value()-1)
		{
			ui->lineEdit->setText("SUCCESS");
			//msgBox.setText("Pass");
		}

	}
//	for(int i=0;i<ui->spinBox->value();i++){
//		unsigned int l_nMuxCodeID= IPsoc->muxDetection();
//		if(l_nMuxCodeID== 0x15)
//		{
//			qDebug()<<"Pass CodeID:"<<hex<<l_nMuxCodeID;
//		}
//		else
//		{
//			qDebug()<<"Fail CodeID:"<<hex<<l_nMuxCodeID;
//			break;
//		}
//
//		IPsoc->externalMuxMeasurement(ui->spinTest->value(),ui->spinRef->value());
//		 //IPsoc->externalMuxMeasurement(0xff,0xff);
////		 if( !IPsoc->switchRef(ui->spinRef->value()))
////		 {
////	    	 ui->lineEdit->setText("FAILURE");
////	    	 break;
////		 }
////		 usleep(15000);
////		 if(!IPsoc->switchTest(ui->spinTest->value()))
////		 {
////	    	 ui->lineEdit->setText("FAILURE");
////	    	 break;
////		 }
////		 usleep(15000);
//		if(IPsoc->readMuxStatus()==false){
//			 ui->lineEdit->setText("FAILURE");
//			 msgBox.setText("Both Mux Switching Not Done for given loop..");
//			 break;
//		}
//			ui->lineEdit_2->setText(QString::number(i+1,10));
//		   ui->lineEdit->setText("SUCCESS");
//		   if(i==ui->spinBox->value()-1)
//				  msgBox.setText("Both Mux Switching Done for given loop...");
//	}
   // msgBox.exec();
}
