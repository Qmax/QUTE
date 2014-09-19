
#include "ptpsoctestjiginterface.h"
#include <QPropertyAnimation>

PTPSoCTestJigInterface::PTPSoCTestJigInterface(QWidget *parent)
    : QWidget(parent)
{
	ui.setupUi(this);
        LoadPlugins();
        Initialization();
        SignalsAndSlots();
        enableRichGUI();
        setWindowFlags(Qt::Widget);
        QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry");
        animation->setStartValue(QRect(400, 300, 0, 0));
        animation->setEndValue(QRect(120, 100, 600, 230));
        animation->setEasingCurve(QEasingCurve::OutCirc);
        animation->setDuration(500);
        animation->start();
        setFont(QFont("DejaVu Sans"));
        ui.topRelay24->setVisible(false);
}

PTPSoCTestJigInterface::~PTPSoCTestJigInterface()
{

}
void PTPSoCTestJigInterface::psocError(bool){

}
void PTPSoCTestJigInterface::LoadPlugins(){
    QPluginLoader loader3("libPTPsocInterface2.so",this);
    IPsoc = qobject_cast<IPSOCCOMMUNICATION*>(loader3.instance());

    QPluginLoader loader2("libBackPlaneInterface.so", this);
    IBackPlane = qobject_cast<IntefaceBackPlane*> (loader2.instance());

	QPluginLoader loader4("libQmaxPTInterface.so", this);
	ILineEdit = qobject_cast<IQmaxLineEdit*> (loader4.instance());
	INumberPanel = qobject_cast<IQmaxNumberPanel*> (loader4.instance());

	QPluginLoader loaderApp("libPTApplicationcardInterface.so", this);
	IAppCard = qobject_cast<IApplicationCardInterface*> (loaderApp.instance());
	IAppCard->setDeviceName(SLOT0);
	IAppCard->enumerateAPPCard();

        QPluginLoader loaderGen("libPTGenericInterface.so", this);
        IGenCard = qobject_cast<IGenericInterface*> (loaderGen.instance());
        IGenCard->setDeviceName(SLOT0);
        IGenCard->enumerateAPPCard();
}
void PTPSoCTestJigInterface::Initialization(){

	IPsoc->openSerial();
    IBackPlane->InitializeBpObject();

	CommandLineEdit = ILineEdit->QmaxLineEdit(3,ui.groupBox_13);
	CommandLineEdit->setGeometry(ui.leRawCmd->geometry());

        AppAddr = ILineEdit->QmaxLineEdit(4,ui.groupBox);
	AppAddr->setGeometry(ui.leAppAddr->geometry());

        AppData = ILineEdit->QmaxLineEdit(5,ui.groupBox);
	AppData->setGeometry(ui.leAppData->geometry());

        BckAddr = ILineEdit->QmaxLineEdit(6,ui.groupBox_2);
	BckAddr->setGeometry(ui.leBckAddr->geometry());

        BckData = ILineEdit->QmaxLineEdit(7,ui.groupBox_2);
	BckData->setGeometry(ui.leBckData->geometry());

        GenData = ILineEdit->QmaxLineEdit(8,ui.groupBox_3);
        GenData->setGeometry(ui.leGenData->geometry());

        GenAddr = ILineEdit->QmaxLineEdit(9,ui.groupBox_3);
        GenAddr->setGeometry(ui.leGenAddr->geometry());

        GenBaseAddr = ILineEdit->QmaxLineEdit(1,ui.groupBox_3);
        GenBaseAddr->setGeometry(ui.leGenBaseAddr->geometry());
        GenBaseAddr->setText("0x00000000");
}
void PTPSoCTestJigInterface::customEvent(QEvent *eve) {

}

void PTPSoCTestJigInterface::SignalsAndSlots(){
	connect(CommandLineEdit, SIGNAL(focussed(bool)), this, SLOT(callCommandInput()));
	connect(AppAddr, SIGNAL(focussed(bool)), this, SLOT(callAppAddr()));
	connect(AppData, SIGNAL(focussed(bool)), this, SLOT(callAppData()));
	connect(BckAddr, SIGNAL(focussed(bool)), this, SLOT(callBckAddr()));
	connect(BckData, SIGNAL(focussed(bool)), this, SLOT(callBckData()));
        connect(GenData, SIGNAL(focussed(bool)), this, SLOT(callGenData()));
        connect(GenAddr, SIGNAL(focussed(bool)), this, SLOT(callGenAddr()));
        connect(GenBaseAddr, SIGNAL(focussed(bool)), this, SLOT(callBaseAddr()));
}

void PTPSoCTestJigInterface::enableRichGUI(){
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
	ui.groupBox_2->setParent(m_objWidget);
        ui.groupBox_3->setParent(m_objWidget);
	ui.groupBox_7->setParent(m_objWidget);
	ui.groupBox_8->setParent(m_objWidget);
	ui.groupBox_13->setParent(m_objWidget);
	ui.pushButton_5->setParent(m_objWidget);


	ui.groupBox_13->setGeometry(10,-70,580,70);
	ui.groupBox->setGeometry(10,7,520,60);
	ui.groupBox_2->setGeometry(10,67,520,60);
        ui.groupBox_3->setGeometry(10,130,520,91);
	ui.groupBox_7->setGeometry(10,-317,390,247);
	ui.groupBox_8->setGeometry(400,-317,190,247);
        ui.pushButton_5->setGeometry(538,10,50,210);

}
void PTPSoCTestJigInterface::SendCommand(){
		unsigned int com;
		bool ok = true;

		if (ui.comboBox_13->currentIndex() == 1) {
//			IPsoc->writeSerial(l_nonTopRelay);
			com = CommandLineEdit->text().toUInt(&ok, 16);
//			IPsoc->writeSerial(com);
			IPsoc->onTopRelay(com);
		}

		else if (ui.comboBox_13->currentIndex() == 2) {
//			IPsoc->writeSerial(l_noffTopRelay);
			com = CommandLineEdit->text().toUInt(&ok, 16);
//			IPsoc->writeSerial(com);
			IPsoc->offTopRelay(com);
		}

		else if (ui.comboBox_13->currentIndex() == 3) {
//			IPsoc->writeSerial(l_nonBottomRelay);
			com = CommandLineEdit->text().toUInt(&ok, 16);
//			IPsoc->writeSerial(com);
			IPsoc->onBottomRelay(com);
		}

		else if (ui.comboBox_13->currentIndex() == 4) {
//			IPsoc->writeSerial(l_noffBottomRelay);
			com = CommandLineEdit->text().toUInt(&ok, 16);
//			IPsoc->writeSerial(com);
			IPsoc->offBottomRelay(com);
		}
		else if (ui.comboBox_13->currentIndex() == 5) {
			com = CommandLineEdit->text().toUInt(&ok, 16);
			IPsoc->writeSerial(com);
			usleep(1000);
			CommandLineEdit->setText(QString::number(IPsoc->readSerial(), 16));
		}
}
void PTPSoCTestJigInterface::ReadRelays(){

		unsigned int read = 0;
		unsigned char byte1, byte2, byte3, byte4;

		IPsoc->readRelay();
		read = IPsoc->readSerial();
		byte1 = (unsigned char) read;
		byte2 = (unsigned char) (read >> 8);
		byte3 = (unsigned char) (read >> 16);
		byte4 = (unsigned char) (read >> 24);

		qDebug() << "byte 1" << hex << byte4;
		convertToBits(byte4, 1);
		qDebug() << "byte 2" << hex << byte3;
		convertToBits(byte3, 2);
		qDebug() << "byte 3" << hex << byte2;
		convertToBits(byte2, 3);
		qDebug() << "byte 4" << hex << byte1;
		convertToBits(byte1, 4);

}
void PTPSoCTestJigInterface::ResetRelays(){
//		IPsoc->writeSerial(reset_relay);
	IPsoc->resetRelays();
}


void PTPSoCTestJigInterface::convertToBits(unsigned char n, int byte) {
	int i, k, andmask;
	unsigned char a[8];
	for (i = 7; i >= 0; i--) {
		andmask = 1 << i;
		k = n & andmask;
		k == 0 ? (a[i] = 0) : (a[i] = 1);
	}
	QString strred = " QLineEdit {  border: 2px solid gray;   border-radius: 8px;   padding: 0 8px;    background-color:rgb(255,0,0); selection-background-color: darkgray; color:white; font: bold 14px; }";
	QString strgreen = " QLineEdit {  border: 2px solid gray;   border-radius: 8px;   padding: 0 8px;    background-color:rgb(0,170,0); selection-background-color: darkgray; color:white; font: bold 14px; }";

	QString strred1=" QLineEdit {border: 2px solid gray; border-radius: 15px; padding: 0 8px; background-color:rgb(255,0,0); selection-background-color: darkgray; color:white;font: bold 14px; }";
	QString strgreen1=" QLineEdit {border: 2px solid gray; border-radius: 15px; padding: 0 8px; background-color:rgb(0,170,0); selection-background-color: darkgray; color:white;font: bold 14px; }";

	switch (byte) {
	case 1: {
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//		ui.lineEdit_42->setText("0x" + QString::number(n, 16));
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		ui.lineEdit_38->setText("   "+QString::number(a[0], 16));
		if (a[0] == 1)
			ui.lineEdit_38->setStyleSheet(strgreen);
		else if (a[0] == 0)
			ui.lineEdit_38->setStyleSheet(strred);
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		ui.lineEdit_7->setText("   "+QString::number(a[1], 16));
//		ui.lineEdit_8->setText(ui.lineEdit_7->text());
		if (a[1] == 1) {
			ui.lineEdit_7->setStyleSheet(strgreen);
//			ui.lineEdit_8->setStyleSheet(strgreen);
		}
		else if (a[1] == 0) {
//			ui.lineEdit_7->setStyleSheet(strred);
			ui.lineEdit_7->setStyleSheet(strred);
		}
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		ui.lineEdit_28->setText("   "+QString::number(a[2], 16));
		if (a[2] == 1)
			ui.lineEdit_28->setStyleSheet(strgreen);
		else if (a[2] == 0)
			ui.lineEdit_28->setStyleSheet(strred);

//		ui.lineEdit_30->setText(ui.lineEdit_28->text());
//		if (a[2] == 1)
//			ui.lineEdit_30->setStyleSheet(strgreen);
//		else if (a[2] == 0)
//			ui.lineEdit_30->setStyleSheet(strred);
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		ui.lineEdit->setText("   "+QString::number(a[3], 16));
		if (a[3] == 1)
			ui.lineEdit->setStyleSheet(strgreen);
		else if (a[3] == 0)
			ui.lineEdit->setStyleSheet(strred);

//		ui.lineEdit_2->setText(ui.lineEdit->text());
//		if (a[3] == 1)
//			ui.lineEdit_2->setStyleSheet(strgreen);
//		else if (a[3] == 0)
//			ui.lineEdit_2->setStyleSheet(strred);
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		ui.lineEdit_3->setText("   "+QString::number(a[4], 16));
		ui.lineEdit_4->setText("   "+QString::number(a[4], 16));
		ui.lineEdit_5->setText("   "+QString::number(a[4], 16));
		ui.lineEdit_6->setText("   "+QString::number(a[4], 16));
		if (a[4] == 1) {
			ui.lineEdit_3->setStyleSheet(strgreen);
			ui.lineEdit_4->setStyleSheet(strgreen);
			ui.lineEdit_5->setStyleSheet(strgreen);
			ui.lineEdit_6->setStyleSheet(strgreen);
		} else if (a[4] == 0) {
			ui.lineEdit_3->setStyleSheet(strred);
			ui.lineEdit_4->setStyleSheet(strred);
			ui.lineEdit_5->setStyleSheet(strred);
			ui.lineEdit_6->setStyleSheet(strred);
		}
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		ui.lineEdit_33->setText("   "+QString::number(a[5], 16));
		if (a[5] == 1)
			ui.lineEdit_33->setStyleSheet(strgreen);
		else if (a[5] == 0)
			ui.lineEdit_33->setStyleSheet(strred);

		ui.lineEdit_35->setText(ui.lineEdit_33->text());
		if (a[5] == 1)
			ui.lineEdit_35->setStyleSheet(strgreen);
		else if (a[5] == 0)
			ui.lineEdit_35->setStyleSheet(strred);

		ui.lineEdit_36->setText(ui.lineEdit_33->text());
		if (a[5] == 1)
			ui.lineEdit_36->setStyleSheet(strgreen);
		else if (a[5] == 0)
			ui.lineEdit_36->setStyleSheet(strred);

		ui.lineEdit_39->setText(ui.lineEdit_33->text());
		if (a[5] == 1)
			ui.lineEdit_39->setStyleSheet(strgreen);
		else if (a[5] == 0)
			ui.lineEdit_39->setStyleSheet(strred);
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		ui.lineEdit_24->setText("   "+QString::number(a[6], 16));
		if (a[6] == 1)
			ui.lineEdit_24->setStyleSheet(strgreen);
		else if (a[6] == 0)
			ui.lineEdit_24->setStyleSheet(strred);
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		ui.lineEdit_14->setText("   "+QString::number(a[7], 16));
		if (a[7] == 1)
			ui.lineEdit_14->setStyleSheet(strgreen);
		else if (a[7] == 0)
			ui.lineEdit_14->setStyleSheet(strred);

		ui.lineEdit_61->setText(ui.lineEdit_14->text());
		if (a[7] == 1)
			ui.lineEdit_61->setStyleSheet(strgreen);
		else if (a[7] == 0)
			ui.lineEdit_61->setStyleSheet(strred);
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	}
	break;

	case 2: {
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//		ui.lineEdit_43->setText("0x" + QString::number(n, 16));
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		ui.lineEdit_23->setText("   "+QString::number(a[0], 16));
		if (a[0] == 1)
			ui.lineEdit_23->setStyleSheet(strgreen);
		else if (a[0] == 0)
			ui.lineEdit_23->setStyleSheet(strred);
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		ui.lineEdit_22->setText("   "+QString::number(a[1], 16));
		if (a[1] == 1)
			ui.lineEdit_22->setStyleSheet(strgreen);
		else if (a[1] == 0)
			ui.lineEdit_22->setStyleSheet(strred);
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		ui.lineEdit_21->setText("   "+QString::number(a[2], 16));
		if (a[2] == 1)
			ui.lineEdit_21->setStyleSheet(strgreen);
		else if (a[2] == 0)
			ui.lineEdit_21->setStyleSheet(strred);
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

		ui.lineEdit_20->setText("   "+QString::number(a[4], 16));
		if (a[4] == 1)
			ui.lineEdit_20->setStyleSheet(strgreen);
		else if (a[4] == 0)
			ui.lineEdit_20->setStyleSheet(strred);
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		ui.lineEdit_19->setText("   "+QString::number(a[5], 16));
		if (a[5] == 1)
			ui.lineEdit_19->setStyleSheet(strgreen);
		else if (a[5] == 0)
			ui.lineEdit_19->setStyleSheet(strred);
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		ui.lineEdit_17->setText("   "+QString::number(a[6], 16));
		if (a[6] == 1)
			ui.lineEdit_17->setStyleSheet(strgreen);
		else if (a[6] == 0)
			ui.lineEdit_17->setStyleSheet(strred);
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		ui.lineEdit_15->setText("   "+QString::number(a[7], 16));
		if (a[7] == 1)
			ui.lineEdit_15->setStyleSheet(strgreen);
		else if (a[7] == 0)
			ui.lineEdit_15->setStyleSheet(strred);
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	}
	break;

	case 3: {
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//		ui.lineEdit_44->setText("0x" + QString::number(n, 16));
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		ui.lineEdit_25->setText("   "+QString::number(a[0], 16));
		if (a[0] == 1)
			ui.lineEdit_25->setStyleSheet(strgreen);
		else if (a[0] == 0)
			ui.lineEdit_25->setStyleSheet(strred);
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		ui.lineEdit_12->setText("   "+QString::number(a[1], 16));
		if (a[1] == 1)
			ui.lineEdit_12->setStyleSheet(strgreen);
		else if (a[1] == 0)
			ui.lineEdit_12->setStyleSheet(strred);

		ui.lineEdit_60->setText(ui.lineEdit_12->text());
		if (a[1] == 1)
			ui.lineEdit_60->setStyleSheet(strgreen);
		else if (a[1] == 0)
			ui.lineEdit_60->setStyleSheet(strred);

		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		ui.lineEdit_40->setText("   "+QString::number(a[2], 16));
		if (a[2] == 1)
			ui.lineEdit_40->setStyleSheet(strgreen);
		else if (a[2] == 0)
			ui.lineEdit_40->setStyleSheet(strred);

		ui.lineEdit_41->setText(ui.lineEdit_40->text());
		if (a[2] == 1)
			ui.lineEdit_41->setStyleSheet(strgreen);
		else if (a[2] == 0)
			ui.lineEdit_41->setStyleSheet(strred);
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		ui.lineEdit_34->setText("   "+QString::number(a[3], 16));
		if (a[3] == 1)
			ui.lineEdit_34->setStyleSheet(strgreen);
		else if (a[3] == 0)
			ui.lineEdit_34->setStyleSheet(strred);

		ui.lineEdit_37->setText(ui.lineEdit_34->text());
		if (a[3] == 1)
			ui.lineEdit_37->setStyleSheet(strgreen);
		else if (a[3] == 0)
			ui.lineEdit_37->setStyleSheet(strred);
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		ui.lineEdit_63->setText("   "+QString::number(a[4], 16));
		if (a[4] == 1)
			ui.lineEdit_63->setStyleSheet(strgreen);
		else if (a[4] == 0)
			ui.lineEdit_63->setStyleSheet(strred);
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		ui.lineEdit_26->setText("   "+QString::number(a[5], 16));
		if (a[5] == 1)
			ui.lineEdit_26->setStyleSheet(strgreen);
		else if (a[5] == 0)
			ui.lineEdit_26->setStyleSheet(strred);
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		ui.lineEdit_30->setText("   "+QString::number(a[6], 16));
		if (a[6] == 1)
			ui.lineEdit_30->setStyleSheet(strgreen);
		else if (a[6] == 0)
			ui.lineEdit_30->setStyleSheet(strred);

		ui.lineEdit_27->setText(ui.lineEdit_30->text());
		if (a[6] == 1)
			ui.lineEdit_27->setStyleSheet(strgreen);
		else if (a[6] == 0)
			ui.lineEdit_27->setStyleSheet(strred);
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		ui.lineEdit_29->setText("   "+QString::number(a[7], 16));
		if (a[7] == 1)
			ui.lineEdit_29->setStyleSheet(strgreen);
		else if (a[7] == 0)
			ui.lineEdit_29->setStyleSheet(strred);

		ui.lineEdit_31->setText(ui.lineEdit_29->text());
		if (a[7] == 1)
			ui.lineEdit_31->setStyleSheet(strgreen);
		else if (a[7] == 0)
			ui.lineEdit_31->setStyleSheet(strred);
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	}
	break;
	case 4: {
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//		ui.lineEdit_45->setText("0x" + QString::number(n, 16));
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

		ui.lineEdit_9->setText("   "+QString::number(a[4], 16));
		if (a[4] == 1)
			ui.lineEdit_9->setStyleSheet(strgreen);
		else if (a[4] == 0)
			ui.lineEdit_9->setStyleSheet(strred);

		ui.lineEdit_10->setText(ui.lineEdit_9->text());
		if (a[4] == 1)
			ui.lineEdit_10->setStyleSheet(strgreen);
		else if (a[4] == 0)
			ui.lineEdit_10->setStyleSheet(strred);

		ui.lineEdit_13->setText(ui.lineEdit_9->text());
		if (a[4] == 1)
			ui.lineEdit_13->setStyleSheet(strgreen);
		else if (a[4] == 0)
			ui.lineEdit_13->setStyleSheet(strred);

		ui.lineEdit_18->setText(ui.lineEdit_9->text());
		if (a[4] == 1)
			ui.lineEdit_18->setStyleSheet(strgreen);
		else if (a[4] == 0)
			ui.lineEdit_18->setStyleSheet(strred);
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		ui.lineEdit_16->setText("   "+QString::number(a[5], 16));
		if (a[5] == 1)
			ui.lineEdit_16->setStyleSheet(strgreen);
		else if (a[5] == 0)
			ui.lineEdit_16->setStyleSheet(strred);
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		ui.lineEdit_66->setText("   "+QString::number(a[7], 16));
		if (a[7] == 1)
			ui.lineEdit_66->setStyleSheet(strgreen);
		else if (a[7] == 0)
			ui.lineEdit_66->setStyleSheet(strred);

		ui.lineEdit_64->setText(ui.lineEdit_66->text());
		if (a[7] == 1)
			ui.lineEdit_64->setStyleSheet(strgreen);
		else if (a[7] == 0)
			ui.lineEdit_64->setStyleSheet(strred);
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		ui.lineEdit_62->setText("   "+QString::number(a[2], 16));
		if (a[2] == 1)
			ui.lineEdit_62->setStyleSheet(strgreen);
		else if (a[2] == 0)
			ui.lineEdit_62->setStyleSheet(strred);

		ui.lineEdit_65->setText(ui.lineEdit_62->text());
		if (a[2] == 1)
			ui.lineEdit_65->setStyleSheet(strgreen);
		else if (a[2] == 0)
			ui.lineEdit_65->setStyleSheet(strred);

		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		ui.lineEdit_11->setText("   "+QString::number(a[3], 16));
		if (a[3] == 1)
			ui.lineEdit_11->setStyleSheet(strgreen);
		else if (a[3] == 0)
			ui.lineEdit_11->setStyleSheet(strred);
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	}
	break;
	case 5: {
//		ui.lineEdit_54->setText("0x" + QString::number(n, 16));
//
//
//		if (a[7] == 1) {
//			ui.lineEdit_53->setStyleSheet(strgreen1);
//		} else if (a[7] == 0) {
//			ui.lineEdit_53->setStyleSheet(strred1);
//		}
//		if (a[6] == 1) {
//			ui.lineEdit_52->setStyleSheet(strgreen1);
//		} else if (a[6] == 0) {
//			ui.lineEdit_52->setStyleSheet(strred1);
//		}
//		if (a[5] == 1) {
//			ui.lineEdit_51->setStyleSheet(strgreen1);
//		} else if (a[5] == 0) {
//			ui.lineEdit_51->setStyleSheet(strred1);
//		}
//		if (a[4] == 1) {
//			ui.lineEdit_50->setStyleSheet(strgreen1);
//		} else if (a[4] == 0) {
//			ui.lineEdit_50->setStyleSheet(strred1);
//		}
//
//		if (a[3] == 1) {
//			ui.lineEdit_49->setStyleSheet(strgreen1);
//		} else if (a[3] == 0) {
//			ui.lineEdit_49->setStyleSheet(strred1);
//		}
//		if (a[2] == 1) {
//			ui.lineEdit_46->setStyleSheet(strgreen1);
//		} else if (a[2] == 0) {
//			ui.lineEdit_46->setStyleSheet(strred1);
//		}
//		if (a[1] == 1) {
//			ui.lineEdit_47->setStyleSheet(strgreen1);
//		} else if (a[1] == 0) {
//			ui.lineEdit_47->setStyleSheet(strred1);
//		}
//		if (a[0] == 1) {
//			ui.lineEdit_48->setStyleSheet(strgreen1);
//		} else if (a[0] == 0) {
//			ui.lineEdit_48->setStyleSheet(strred1);
//		}
	}
	break;

	case 6: {
//		if (a[0] == 1)
//			ui.lineEdit_49->setStyleSheet(strgreen1);
//		else if (a[0] == 0)
//			ui.lineEdit_49->setStyleSheet(strred1);
//		if (a[1] == 1)
//			ui.lineEdit_47->setStyleSheet(strgreen1);
//		else if (a[1] == 0)
//			ui.lineEdit_47->setStyleSheet(strred1);
//		if (a[2] == 1)
//			ui.lineEdit_48->setStyleSheet(strgreen1);
//		else if (a[2] == 0)
//			ui.lineEdit_48->setStyleSheet(strred1);
//		if (a[3] == 1)
//			ui.lineEdit_46->setStyleSheet(strgreen1);
//		else if (a[3] == 0)
//			ui.lineEdit_46->setStyleSheet(strred1);
//		if (a[4] == 1)
//			ui.lineEdit_53->setStyleSheet(strgreen1);
//		else if (a[4] == 0)
//			ui.lineEdit_53->setStyleSheet(strred1);
//		if (a[5] == 1)
//			ui.lineEdit_50->setStyleSheet(strgreen1);
//		else if (a[5] == 0)
//			ui.lineEdit_50->setStyleSheet(strred1);
//		if (a[6] == 1)
//			ui.lineEdit_52->setStyleSheet(strgreen1);
//		else if (a[6] == 0)
//			ui.lineEdit_52->setStyleSheet(strred1);
//		if (a[7] == 1)
//			ui.lineEdit_51->setStyleSheet(strgreen1);
//		else if (a[7] == 0)
//			ui.lineEdit_51->setStyleSheet(strred1);
	}
	break;

	}

}
void PTPSoCTestJigInterface::callCommandInput() {
	if (CommandLineEdit->hasFocus()) {
		openNumKBPanel(0);
		m_nLineEditIndex = 3;
	}
}
void PTPSoCTestJigInterface::callAppAddr() {
	if (AppAddr->hasFocus()) {
		openNumKBPanel(0);
		m_nLineEditIndex = 4;
	}
}
void PTPSoCTestJigInterface::callAppData() {
	if (AppData->hasFocus()) {
		openNumKBPanel(0);
		m_nLineEditIndex = 5;
	}
}
void PTPSoCTestJigInterface::callBckAddr() {
	if (BckAddr->hasFocus()) {
		openNumKBPanel(0);
		m_nLineEditIndex = 6;
	}
}
void PTPSoCTestJigInterface::callBckData() {
	if (BckData->hasFocus()) {
		openNumKBPanel(0);
		m_nLineEditIndex = 7;
	}
}
void PTPSoCTestJigInterface::callGenData() {
        if (GenData->hasFocus()) {
                openNumKBPanel(0);
                m_nLineEditIndex = 8;
        }
}
void PTPSoCTestJigInterface::callGenAddr() {
        if (GenAddr->hasFocus()) {
                openNumKBPanel(0);
                m_nLineEditIndex = 9;
        }
}
void PTPSoCTestJigInterface::callBaseAddr() {
        if (GenBaseAddr->hasFocus()) {
                openNumKBPanel(0);
                m_nLineEditIndex = 1;
        }
}

void PTPSoCTestJigInterface::CommandSelection(int index) {

	if (ui.comboBox_13->currentIndex() == 1)
		ui.label_9->setText("ON TOP Selected");
	else if (ui.comboBox_13->currentIndex() == 2)
		ui.label_9->setText("OFF TOP Selected");
	else if (ui.comboBox_13->currentIndex() == 3)
		ui.label_9->setText("ON Bottom Selected");
	else if (ui.comboBox_13->currentIndex() == 4)
		ui.label_9->setText("OFF Bottom Selected");

	index = index;
}

void PTPSoCTestJigInterface::receiveValue(unsigned int pValue)
{
if(m_nLineEditIndex==3){
    	CommandLineEdit->setText(QString::number(pValue,16));
        }
if(m_nLineEditIndex==4){
    	AppAddr->setText(QString::number(pValue,16));
        }
if(m_nLineEditIndex==5){
    	AppData->setText(QString::number(pValue,16));
        }
if(m_nLineEditIndex==6){
    	BckAddr->setText(QString::number(pValue,16));
        }
if(m_nLineEditIndex==7){
    	BckData->setText(QString::number(pValue,16));
        }
if(m_nLineEditIndex==8){
        GenData->setText(QString::number(pValue,16));
        }
if(m_nLineEditIndex==9){
        GenAddr->setText(QString::number(pValue,16));
        }
if(m_nLineEditIndex==1){
        GenBaseAddr->setText(QString::number(pValue,16));
        IGenCard->writeBaseAddress(pValue);
        }
}
void PTPSoCTestJigInterface::receiveValue(QString pValue) {
	Q_UNUSED(pValue)
}
void PTPSoCTestJigInterface::receiveValue(double pValue)
{
	Q_UNUSED(pValue)
}
void PTPSoCTestJigInterface::openNumKBPanel(short int pValue) {
	QWidget *w = INumberPanel->getNumKBPanel(pValue, this);
	w->setWindowFlags(Qt::WindowCloseButtonHint | Qt::Dialog);
	w->show();
}

void PTPSoCTestJigInterface::on_pushButton_5_clicked()
{
    this->close();
}

void PTPSoCTestJigInterface::on_pushButton_clicked()
{
	unsigned int com;
		bool ok = true;
		com = AppAddr->text().toUInt(&ok, 16);
		AppData->setText(QString::number(IAppCard->readRegister(com),16));
}

void PTPSoCTestJigInterface::on_pushButton_2_clicked()
{
	unsigned int com1,com2;
		bool ok = true;
		com1 = AppAddr->text().toUInt(&ok, 16);
		com2 = AppData->text().toUInt(&ok, 16);
		IAppCard->writeRegister(com2,com1);
}

void PTPSoCTestJigInterface::on_pushButton_9_clicked()
{
	unsigned int com;
		bool ok = true;
		com = BckAddr->text().toUInt(&ok, 16);
		BckData->setText(QString::number(IBackPlane->readBackPlaneRegister(com),16));
}

void PTPSoCTestJigInterface::on_pushButton_8_clicked()
{
	unsigned int com1,com2;
		bool ok = true;
		com1 = BckAddr->text().toUInt(&ok, 16);
		com2 = BckData->text().toUInt(&ok, 16);
		IBackPlane->writeBackPlaneRegister(com2,com1);
}

void PTPSoCTestJigInterface::on_pushButton_3_clicked()
{
    ReadRelays();
}

void PTPSoCTestJigInterface::on_pushButton_4_clicked()
{
    ResetRelays();
}

void PTPSoCTestJigInterface::on_pushButton_6_clicked()
{
    SendCommand();
}

void PTPSoCTestJigInterface::on_comboBox_13_currentIndexChanged(int index)
{
    CommandSelection(index);
}

void PTPSoCTestJigInterface::on_topRelay24_clicked()
{
	QString strred = " QLineEdit {  border: 2px solid gray;   border-radius: 8px;   padding: 0 8px;    background-color:rgb(255,0,0,255); selection-background-color: darkgray; color:white; font: bold 14px; }";
	QString strgreen = " QLineEdit {  border: 2px solid gray;   border-radius: 8px;   padding: 0 8px;    background-color:rgb(0,170,0,255); selection-background-color: darkgray; color:white; font: bold 14px; }";

    if(ui.topRelay24->text()=="1"){
        IPsoc->offTopRelay(24);
        ui.topRelay24->setText("0");
        ui.topRelay24->setStyleSheet(strred);
    }
    else if(ui.topRelay24->text()=="0"){
        IPsoc->onTopRelay(24);
        ui.topRelay24->setText("1");
        ui.topRelay24->setStyleSheet(strgreen);
    }
}

void PTPSoCTestJigInterface::on_pushButton_7_clicked()
{
	IPsoc->FG_Scope12(1,1,1);
}

void PTPSoCTestJigInterface::on_pbGenRead_clicked()
{
    unsigned int com;
            bool ok = true;
            com = GenAddr->text().toUInt(&ok, 16);
            GenData->setText(QString::number(IGenCard->readRegister(com),16));
}

void PTPSoCTestJigInterface::on_pbGenWrite_clicked()
{
    unsigned int com1,com2;
            bool ok = true;
            com1 = GenAddr->text().toUInt(&ok, 16);
            com2 = GenData->text().toUInt(&ok, 16);
            IGenCard->writeRegister(com2,com1);
}
