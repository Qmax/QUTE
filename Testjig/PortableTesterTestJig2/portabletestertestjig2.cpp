#include "portabletestertestjig2.h"
#include "qdebug.h"

PortableTesterTestJig2::PortableTesterTestJig2(QWidget *parent) :
QWidget(parent) {
	ui.setupUi(this);
	m_bAPPDRVRECEUI=false;
	m_bICMVI=false;
	m_bADCUI=false;
	m_bDDSUI=false;
	currentIndex = 0;
	checkIndex(0);
	connect(ui.tabWidget, SIGNAL(currentChanged(int)), this,SLOT(checkIndex(int)));
	showMaximized();

}

void PortableTesterTestJig2::checkIndex(int index) {
    qDebug()<<"Index:"<<index;
	if (currentIndex != index) {
		switch (currentIndex) {
		case 0:
			FMGUI->closeFM();
			break;
		case 1:
			PSOCUI->closePSOC();
			break;
		case 2:
			KPKBBLUI->closeKeyKnob();
			break;
		case 3:
			DDS->closeDDS();
			break;
		case 4:
			PWF->closePWF();
			break;
		case 5:
			HAADC->closeHACADC();
			break;
		case 6:
			APPDRVRX->closeAPPRXDRV();
			break;
		case 7:
			AD5318->closeAD5318();
			break;
		}
	}
	switch (index) {
	case 0: {
		qDebug() << "**********Flash Memory**********";
		currentIndex=0;
		QPluginLoader loaderFM("libFLASHMEMORY.so", this);
		FMGUI = qobject_cast<IFMTestJigInterface*> (loaderFM.instance());
		FMGUI->setFM(ui.FM);
	}
	break;
	case 1: {
		qDebug() << "**********PSoC Relays**********";
		currentIndex=1;
		QPluginLoader loaderPSOC("libPTPSoCTestJigInterface2.so", this);
		PSOCUI = qobject_cast<IPSOCTestJigInterface2*> (loaderPSOC.instance());
		PSOCUI->setPSOC(ui.PSOC);
	}
	break;
	case 2: {
		qDebug() << "**********KeyPad/Knob/BackLight**********";
		currentIndex=2;
		QPluginLoader loaderkeyknob("libPtKeyKnob.so", this);
		KPKBBLUI = qobject_cast<IKeyKnobTestJigInterface*> (loaderkeyknob.instance());
		KPKBBLUI->setKeyKnob(ui.KeyKnob);
	}
	break;
	case 3: {
			qDebug() << "**********DDS**********";
			currentIndex=3;
			if(m_bDDSUI==false)
			{
				QPluginLoader loaderdds("libDDS.so", this);
				DDS = qobject_cast<IDDSTestJigInterface*> (loaderdds.instance());
				DDS->setDDS(ui.DDS);
				DDS->showWidget();
				m_bDDSUI= true;
			}
			else
			{
				DDS->showWidget();
			}
		}
		break;
		case 4: {
			qDebug() << "**********Plot Waveform**********";
			currentIndex=4;
			QPluginLoader loaderpwf("libPlotWaveForm.so", this);
			PWF = qobject_cast<IPWFTestJigInterface*> (loaderpwf.instance());
			PWF->setPWF(ui.Plot);
		}
		break;
		case 5: {
			qDebug() << "**********High Accuracy ADC**********";
			currentIndex=5;
			if(m_bADCUI==false)
			{
				QPluginLoader loaderhaadc("libADCHighAccuracy.so", this);
				HAADC = qobject_cast<IHACADCTestJigInterface*> (loaderhaadc.instance());
				HAADC->setHACADC(ui.HAADC);
				HAADC->showWidget();
				m_bADCUI=true;
			}
			else
			{
				HAADC->showWidget();
			}
		}
		break;
		case 6: {
			qDebug() << "**********Application Card drive Receive**********";
			currentIndex=6;
			if(m_bAPPDRVRECEUI==false){
			QPluginLoader loaderappdrvrx("libAPPCardDRVRECE.so", this);
			APPDRVRX = qobject_cast<IAPPRXDRVTestJigInterface*> (loaderappdrvrx.instance());
			APPDRVRX->setAPPRXDRV(ui.APPDRVRX);
			APPDRVRX->showWidget();
			m_bAPPDRVRECEUI=true;
			}
			else
			{
				APPDRVRX->showWidget();
			}
		}
		break;
		case 7: {
			qDebug() << "**********AD5318**********";
			currentIndex=7;
			QPluginLoader loaderad5318("libAD5318.so", this);
			AD5318 = qobject_cast<IAD5318TestJigInterface*> (loaderad5318.instance());
			AD5318->setAD5318(ui.AD5318);
		}
		break;
		}
}

PortableTesterTestJig2::~PortableTesterTestJig2() {
}

//PDf VIEWER


//void PortableTesterTestJig2::openFile()
//{
//    QString path = QFileDialog::getOpenFileName(this, tr("Open PDF File"),
//        lastPath, tr("PDF files (*.pdf)"));
//
//    if (path.isEmpty())
//        return;
//
//    if (documentWidget->setDocument(path)) {
//        lastPath = path;
////        searchLineEdit->setEnabled(true);
////        searchComboBox->setEnabled(true);
////        findButton->setEnabled(true);
////        clearButton->setEnabled(true);
//        ui.scaleComboBox->setEnabled(true);
//        ui.pageSpinBox->setEnabled(true);
//        ui.pageSpinBox->setMinimum(1);
//        ui.pageSpinBox->setMaximum(documentWidget->document()->numPages());
//        ui.pageSpinBox->setValue(1);
//    } else
//        QMessageBox::warning(this, tr("PDF Viewer - Failed to Open File"),
//                             tr("The specified file could not be opened."));
//}
//void PortableTesterTestJig2::setPageValue(){
//	ui.lineEdit->setText(ui.pageSpinBox->text());
//}
//void PortableTesterTestJig2::scaleDocument(int index)
//{
//    documentWidget->setScale(scaleFactors[index]);
//}
//
//void PortableTesterTestJig2::on_pushButton_2_clicked()
//{
//	 QString path = "APP_RegisterDetails_V1.00.pdf";
//
//	    if (path.isEmpty())
//	        return;
//
//	    if (documentWidget->setDocument(path)) {
//	        lastPath = path;
//	        ui.scaleComboBox->setEnabled(true);
//	        ui.pageSpinBox->setEnabled(true);
//	        ui.pageSpinBox->setMinimum(1);
//	        ui.pageSpinBox->setMaximum(documentWidget->document()->numPages());
//	        ui.pageSpinBox->setValue(1);
//	    } else
//	        QMessageBox::warning(this, tr("PDF Viewer - Failed to Open File"),
//	                             tr("The specified file could not be opened."));
//}
//
//void PortableTesterTestJig2::on_pushButton_3_clicked()
//{
//	 QString path = "BP_RegisterDetails_V1R3.pdf";
//
//	    if (path.isEmpty())
//	        return;
//
//	    if (documentWidget->setDocument(path)) {
//	        lastPath = path;
//	        ui.scaleComboBox->setEnabled(true);
//	        ui.pageSpinBox->setEnabled(true);
//	        ui.pageSpinBox->setMinimum(1);
//	        ui.pageSpinBox->setMaximum(documentWidget->document()->numPages());
//	        ui.pageSpinBox->setValue(1);
//	    } else
//	        QMessageBox::warning(this, tr("PDF Viewer - Failed to Open File"),
//	                             tr("The specified file could not be opened."));
//}
//
//void PortableTesterTestJig2::on_pushButton_4_clicked()
//{
//    QString path = "Front_Panel_Specification.pdf";
//
//       if (path.isEmpty())
//           return;
//
//       if (documentWidget->setDocument(path)) {
//           lastPath = path;
//           ui.scaleComboBox->setEnabled(true);
//           ui.pageSpinBox->setEnabled(true);
//           ui.pageSpinBox->setMinimum(1);
//           ui.pageSpinBox->setMaximum(documentWidget->document()->numPages());
//           ui.pageSpinBox->setValue(1);
//       } else
//           QMessageBox::warning(this, tr("PDF Viewer - Failed to Open File"),
//                                tr("The specified file could not be opened."));
//}
//
//void PortableTesterTestJig2::on_pushButton_5_clicked()
//{
//    int index;
//    if(ui.scaleComboBox->currentIndex()<8){
//        index=ui.scaleComboBox->currentIndex()+1;
//       ui.scaleComboBox->setCurrentIndex(index);
//    }
//}
//
//void PortableTesterTestJig2::on_pushButton_clicked()
//{
//    int index;
//    if(ui.scaleComboBox->currentIndex()>0){
//        index=ui.scaleComboBox->currentIndex()-1;
//       ui.scaleComboBox->setCurrentIndex(index);
//    }
//}


void PortableTesterTestJig2::slotAcceptUserLogin(QString& name,QString& password){
        if(name=="root" && password=="root"){
                m_nPassword=true;
        }else{
                QMessageBox msg;
                msg.setText("Login Error");
                msg.setInformativeText("Invalid Username/Password");
                msg.exec();
                m_nPassword=false;
                //        this->close();
        }

}
