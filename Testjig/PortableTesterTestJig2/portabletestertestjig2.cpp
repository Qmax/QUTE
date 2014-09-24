#include "portabletestertestjig2.h"
#include "qdebug.h"

PortableTesterTestJig2::PortableTesterTestJig2(QWidget *parent) :
QWidget(parent) {
	ui.setupUi(this);
//        LoginDialog* loginDialog = new LoginDialog( this );
//        int retryloop=0;
//           connect(loginDialog,SIGNAL(acceptLogin(QString&,QString&,int&)),this,SLOT(slotAcceptUserLogin(QString&,QString&)));
//           do{
//               loginDialog->exec();
//               retryloop++;
//               if(retryloop==3){
//                   break;
//                   parentWidget()->close();
//               }
//           }while(!m_nPassword);
	m_bAPPDRVRECEUI=false;
	m_bICMVI=false;
	m_bADCUI=false;
	m_bDDSUI=false;
	currentIndex = 6;
	checkIndex(6);
	connect(ui.tabWidget, SIGNAL(currentChanged(int)), this,SLOT(checkIndex(int)));



//	//PDF VIEWER
//	scaleFactors << 0.25 << 0.5 << 0.75 << 1. << 1.25 << 1.5 << 2. << 3. << 4.;
//
//    documentWidget = new DocumentWidget();
//    ui.scrollArea->setWidget(documentWidget);
//
//    connect(ui.LOADpushButton, SIGNAL(clicked()), this, SLOT(openFile()));
//    connect(ui.pageSpinBox, SIGNAL(valueChanged(int)),documentWidget, SLOT(setPage(int)));
//    connect(ui.pageSpinBox, SIGNAL(valueChanged(int)),this, SLOT(setPageValue()));
//    connect(documentWidget, SIGNAL(pageChanged(int)),ui.pageSpinBox, SLOT(setValue(int)));
//    connect(ui.scaleComboBox, SIGNAL(currentIndexChanged(int)),this, SLOT(scaleDocument(int)));
	showMaximized();

}

void PortableTesterTestJig2::checkIndex(int index) {
        ui.pushButton_6->setVisible(false);
	if (currentIndex != index) {
		switch (currentIndex) {
		case 0:
			AWGUI->closeAWG();
			break;
		case 1:
			DMMSLGUI->closeDMM();
			break;
		case 2:
			ICMGUI->closeICM();
			break;
		case 3:
			VIGUI->closeVI();
			break;
		case 4:
			FMGUI->closeFM();
			break;
		case 5:
			ACRUI->closeACR();
			break;
		case 6:
			PSOCUI->closePSOC();
			break;
		case 7:
			KPKBBLUI->closeKeyKnob();
			break;
		case 8:
			DDS->closeDDS();
			break;
		case 9:
			PWF->closePWF();
			break;
		case 10:
			HAADC->closeHACADC();
			break;
		case 11:
			APPDRVRX->closeAPPRXDRV();
			break;
		case 12:
			AD5318->closeAD5318();
			break;
		case 13:
			RAMData->closeRAM();
			break;
		case 14:
			AD9102->closeAD9102();
			break;
		}
	}
	switch (index) {
	case 0: {

		qDebug() << "**********AWG**********";
		currentIndex=0;
		QPluginLoader loaderAWG("libAWG.so", this);
		AWGUI = qobject_cast<IAWGTestJigInterface*> (loaderAWG.instance());
		AWGUI->setAWG(ui.AWG);

	}
	break;
	case 1: {

		qDebug() << "**********DMM/SL**********";
		currentIndex=1;
		QPluginLoader loaderDMMSL("libDMM.so", this);
		DMMSLGUI = qobject_cast<IDMMTestJigInterface*> (loaderDMMSL.instance());
		DMMSLGUI->setDMM(ui.DMMSL);
	}
	break;
	case 2: {
		qDebug() << "**********ICM**********";
		currentIndex=2;
		if(m_bICMVI==false){
			QPluginLoader loaderICM("libICMJig.so", this);
			ICMGUI = qobject_cast<IICMTestJigInterface*> (loaderICM.instance());
			ICMGUI->setICM(ui.ICM);
			ICMGUI->showWidget();
			m_bICMVI=true;
		}
		else
		{
			ICMGUI->showWidget();
			//m_bICMVI=false;
		}
	}
	break;
	case 3: {
		qDebug() << "**********VI**********";
		currentIndex=3;
		QPluginLoader loaderVI("libVI.so", this);
		VIGUI = qobject_cast<IVITestJigInterface*> (loaderVI.instance());
		VIGUI->setVI(ui.VI);
	}
	break;
	case 4: {
		qDebug() << "**********Flash Memory**********";
		currentIndex=4;
		QPluginLoader loaderFM("libFLASHMEMORY.so", this);
		FMGUI = qobject_cast<IFMTestJigInterface*> (loaderFM.instance());
		FMGUI->setFM(ui.FM);
	}
	break;
	case 5: {
		qDebug() << "**********Application Card Relays**********";
		currentIndex=5;
		QPluginLoader loaderACR("libAPPCardRelayUI.so", this);
		ACRUI = qobject_cast<IACRTestJigInterface*> (loaderACR.instance());
		ACRUI->setACR(ui.ACR);
	}
	break;
	case 6: {
		qDebug() << "**********PSoC Relays**********";
		currentIndex=6;
		QPluginLoader loaderPSOC("libPTPSoCTestJigInterface2.so", this);
		PSOCUI = qobject_cast<IPSOCTestJigInterface2*> (loaderPSOC.instance());
		PSOCUI->setPSOC(ui.PSOC);
	}
	break;
	case 7: {
		qDebug() << "**********KeyPad/Knob/BackLight**********";
		currentIndex=7;
		QPluginLoader loaderkeyknob("libPtKeyKnob.so", this);
		KPKBBLUI = qobject_cast<IKeyKnobTestJigInterface*> (loaderkeyknob.instance());
		KPKBBLUI->setKeyKnob(ui.KeyKnob);
	}
	break;
	case 8: {
			qDebug() << "**********DDS**********";
			currentIndex=8;
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
		case 9: {
			qDebug() << "**********Plot Waveform**********";
			currentIndex=9;
			QPluginLoader loaderpwf("libPlotWaveForm.so", this);
			PWF = qobject_cast<IPWFTestJigInterface*> (loaderpwf.instance());
			PWF->setPWF(ui.Plot);
		}
		break;
		case 10: {
			qDebug() << "**********High Accuracy ADC**********";
			currentIndex=10;
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
		case 11: {
			qDebug() << "**********Application Card drive Receive**********";
			currentIndex=11;
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
		case 12: {
			qDebug() << "**********AD5318**********";
			currentIndex=12;
			QPluginLoader loaderad5318("libAD5318.so", this);
			AD5318 = qobject_cast<IAD5318TestJigInterface*> (loaderad5318.instance());
			AD5318->setAD5318(ui.AD5318);
		}
		break;
		case 13: {
			qDebug() << "**********RAM Data**********";
			currentIndex=13;
			QPluginLoader loaderadRAMData("libRAMData.so", this);
			RAMData = qobject_cast<IRAMTestJigInterface*> (loaderadRAMData.instance());
			RAMData->setRAM(ui.RAMData);
		}
		break;
		case 14: {
			qDebug() << "**********AD9102**********";
			currentIndex=14;
			QPluginLoader loaderAD9102("libAD9102GUI.so", this);
			AD9102 = qobject_cast<IAD9102TestJigInterface*> (loaderAD9102.instance());
			AD9102->setAD9102(ui.AD9102);
		}
		break;
		case 15:
			qDebug() << "**********PDF Viewer**********";
			ui.pushButton_6->setVisible(true);
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


void PortableTesterTestJig2::on_pushButton_6_clicked()
{
    this->close();
}
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
