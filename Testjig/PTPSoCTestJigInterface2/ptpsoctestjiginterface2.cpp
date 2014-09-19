
#include "ptpsoctestjiginterface2.h"

PTPSoCTestJigInterface2::PTPSoCTestJigInterface2(QWidget *parent)
    : QWidget(parent)
{
	ui.setupUi(this);
        LoadPlugins();
        Initialization();
        SignalsAndSlots();
        enableRichGUI();
}

PTPSoCTestJigInterface2::~PTPSoCTestJigInterface2()
{

}
void PTPSoCTestJigInterface2::psocError(bool){

}
void PTPSoCTestJigInterface2::LoadPlugins(){
    QPluginLoader loader3("libPTPsocInterface2.so",this);
    IPsoc = qobject_cast<IPSOCCOMMUNICATION*>(loader3.instance());

    QPluginLoader loader2("libBackPlaneInterface.so", this);
    IBackPlane = qobject_cast<IntefaceBackPlane*> (loader2.instance());

	QPluginLoader loader4("libQmaxPTInterface.so", this);
	ILineEdit = qobject_cast<IQmaxLineEdit*> (loader4.instance());
	INumberPanel = qobject_cast<IQmaxNumberPanel*> (loader4.instance());

    QPluginLoader loader5("libGPIOEventInterface.so",this);
    IGPIOEvent = qobject_cast<PTGPIOEventInterface*>(loader5.instance());

}
void PTPSoCTestJigInterface2::Initialization(){

   source_impedance=0x0;

	MuxRefLineEdit	= ILineEdit->QmaxLineEdit(1,ui.groupBox_14);
	MuxRefLineEdit->setGeometry(135, 30, 40, 25);

	MuxTestLineEdit	= ILineEdit->QmaxLineEdit(2,ui.groupBox_14);
	MuxTestLineEdit->setGeometry(92, 30, 40, 25);

	CommandLineEdit = ILineEdit->QmaxLineEdit(3,ui.groupBox_13);
	CommandLineEdit->setGeometry(220,30, 40, 25);

	IPsoc->openSerial();
    IBackPlane->InitializeBpObject();

	IBackPlane->writeBackPlaneRegister(0x0FFF, 0x001E); //clear all interrupts
	IBackPlane->writeBackPlaneRegister(0x0000, 0x0020); //disable all interrupts
	IBackPlane->writeBackPlaneRegister(0x0000, 0x0024); //disable global interrupt

    IGPIOEvent->InvokeGPIOEvent(this, "/dev/input/event1", "gpioevent", &m_nGPIOCode);
    IBackPlane->writeBackPlaneRegister(0x0001, 0x0024); //Enable Global Interrupts

    IPsoc->createObject(this);

    disableAllComboBox();

	if (ui.groupBox_10->isChecked())
		IGPIOEvent->BlockSig(false);
	else
		IGPIOEvent->BlockSig(true);
}
void PTPSoCTestJigInterface2::customEvent(QEvent *eve) {

	unsigned int l_nRegisterValue;
	unsigned int reads;

	if (eve->type() == GpioEvent) {
		l_nRegisterValue = IBackPlane->readBackPlaneRegister(0x001E);
		IBackPlane->writeBackPlaneRegister(0x0900, 0x001E);
		qDebug() << "data read at 1E is" << hex << l_nRegisterValue;
		IPsoc->writeSerial(0x01);
		usleep(1000);
		reads = IPsoc->readSerial();
		convertToBits((unsigned char) reads, 5);
		qDebug() << "Inside GPIO EMBEDDED PROBE" << hex << m_nGPIOCode;
		IBackPlane->writeBackPlaneRegister(0x0001, 0x0024);
	}	QEvent(eve->type());
}

void PTPSoCTestJigInterface2::SignalsAndSlots(){

    connect(ui.pushButton,   SIGNAL(clicked()),this,SLOT(TestButton()));
    connect(ui.pushButton_2,SIGNAL(clicked()),this,SLOT(ReadCodeID()));
    connect(ui.pushButton_3,SIGNAL(clicked()),this,SLOT(ReadRelays()));
    connect(ui.pushButton_4,SIGNAL(clicked()),this,SLOT(ResetRelays()));
    connect(ui.pushButton_5,SIGNAL(clicked()),this,SLOT(SwitchMux()));
    connect(ui.pushButton_6,SIGNAL(clicked()),this,SLOT(SendCommand()));

    connect(ui.groupBox_3,SIGNAL(clicked()),this,SLOT(VoltageCurrent()));
    connect(ui.groupBox_4,SIGNAL(clicked()),this,SLOT(FunctionGenerator()));
    connect(ui.groupBox_6,SIGNAL(clicked()),this,SLOT(InCircuitMeasurement()));
    connect(ui.groupBox_10,SIGNAL(clicked()),this,SLOT(EmbeddedKey()));

    connect(ui.comboBox_8,SIGNAL(currentIndexChanged(int)),this,SLOT(VoltageCurrent2(int)));
    connect(ui.comboBox_9,SIGNAL(currentIndexChanged(int)),this,SLOT(FunctionGenerater(int)));
    connect(ui.comboBox_11,SIGNAL(currentIndexChanged(int)),this,SLOT(InCircuitMeasureMent(int)));
    connect(ui.comboBox_12,SIGNAL(currentIndexChanged(int)),this,SLOT(MuxInputs(int)));
    connect(ui.comboBox_13,SIGNAL(currentIndexChanged(int)),this,SLOT(CommandSelection(int)));

    connect(MuxTestLineEdit, SIGNAL(focussed(bool)), this, SLOT(callMuxTestInput()));
    connect(MuxRefLineEdit, SIGNAL(focussed(bool)), this, SLOT(callMuxRefInput()));
    connect(CommandLineEdit, SIGNAL(focussed(bool)), this, SLOT(callCommandInput()));

    connect(ui.groupBox_15,SIGNAL(clicked(bool)),this,SLOT(EnDisSRCIM(bool)));
}

void PTPSoCTestJigInterface2::enableRichGUI(){
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


	ui.groupBox_3->setParent(m_objWidget);
	ui.groupBox_4->setParent(m_objWidget);
	ui.groupBox_6->setParent(m_objWidget);
	ui.groupBox_7->setParent(m_objWidget);
	ui.groupBox_10->setParent(m_objWidget);
	ui.groupBox_11->setParent(m_objWidget);
	ui.groupBox_12->setParent(m_objWidget);
	ui.groupBox_13->setParent(m_objWidget);
	ui.groupBox_14->setParent(m_objWidget);
	ui.groupBox_15->setParent(m_objWidget);
	ui.label_9->setParent(m_objWidget);
    ui.comboBox_10->setParent(m_objWidget);
    ui.switchSRCIMP->setParent(m_objWidget);
    ui.switchFLY->setParent(m_objWidget);;

	ui.groupBox_3->setGeometry(10,10,161,70);
	ui.groupBox_4->setGeometry(180,10,161,71);
	ui.groupBox_6->setGeometry(350,10,161,70);
	ui.groupBox_7->setGeometry(10,180,771,211);
	ui.groupBox_10->setGeometry(10,90,391,80);
	ui.groupBox_11->setGeometry(420,90,151,80);
	ui.groupBox_12->setGeometry(590,90,191,80);
	ui.groupBox_13->setGeometry(590,200,170,61);
	ui.groupBox_14->setGeometry(520,10,261,70);
	ui.groupBox_15->setGeometry(10,400,321,80);
	ui.label_9->setGeometry(500,410,251,20);
    ui.comboBox_10->setGeometry(40,430,125,30);
    ui.switchSRCIMP->setGeometry(210,426,84,40);
    ui.switchFLY->setGeometry(350,426,111,40);

    m_objWidget->setStyleSheet("QLabel{color:white;}");

}
void PTPSoCTestJigInterface2::TestButton(){

			if (ui.comboBox_8->currentIndex() == 1)
				IPsoc->viTrace(1);
			else if (ui.comboBox_8->currentIndex() == 2)
				IPsoc->viTrace(2);
			else if (ui.comboBox_11->currentIndex() == 1)
            	 IPsoc->icmMeasurement();
			else if (ui.comboBox_9->currentIndex() == 1)
				IPsoc->FGMeasurement();
			else
				IPsoc->resetRelays();

			if(ui.groupBox_3->isChecked()==false && ui.groupBox_4->isChecked()==false && ui.groupBox_6->isEnabled()==false)
				IPsoc->resetRelays();

 }
void PTPSoCTestJigInterface2::ReadCodeID(){
		ui.lineEdit_56->setText(QString::number(IPsoc->readPsocCodeID(), 16));
}
void PTPSoCTestJigInterface2::SendCommand(){
		unsigned int com;
		bool ok = true;

		if (ui.comboBox_13->currentIndex() == 1) {
			com = CommandLineEdit->text().toUInt(&ok, 16);
//			IPsoc->onTopRelay(com);
		}

		else if (ui.comboBox_13->currentIndex() == 2) {
			com = CommandLineEdit->text().toUInt(&ok, 16);
//			IPsoc->offTopRelay(com);
		}

		else if (ui.comboBox_13->currentIndex() == 3) {
			com = CommandLineEdit->text().toUInt(&ok, 16);
//			IPsoc->onBottomRelay(com);
		}

		else if (ui.comboBox_13->currentIndex() == 4) {
			com = CommandLineEdit->text().toUInt(&ok, 16);
//			IPsoc->offBottomRelay(com);
		}
		else if (ui.comboBox_13->currentIndex() == 5) {
			com = CommandLineEdit->text().toUInt(&ok, 16);
			IPsoc->writeSerial(com);
			usleep(1000);
			CommandLineEdit->setText(QString::number(IPsoc->readSerial(), 16));
		}
}
void PTPSoCTestJigInterface2::ReadRelays(){

		unsigned int read1 = 0,read2 = 0;
		unsigned char byte1,byte2;

		QString strred = " QLineEdit {  border: 2px solid gray;   border-radius: 8px;   padding: 0 8px;    background-color:rgb(255,0,0); selection-background-color: darkgray; color:white; font: bold 14px; }";
		QString strgreen = " QLineEdit {  border: 2px solid gray;   border-radius: 8px;   padding: 0 8px;    background-color:rgb(0,170,0); selection-background-color: darkgray; color:white; font: bold 14px; }";

		read1=IPsoc->readRelay();
        qDebug() << "Read Data " << hex << read1;
		byte1 = (unsigned char) read1;

		ui.lineEdit->setStyleSheet(strred); 		ui.lineEdit_2->setStyleSheet(strred);
		ui.lineEdit_3->setStyleSheet(strred);		ui.lineEdit_4->setStyleSheet(strred);
		ui.lineEdit_5->setStyleSheet(strred);		ui.lineEdit_6->setStyleSheet(strred);
		ui.lineEdit_7->setStyleSheet(strred);		ui.lineEdit_8->setStyleSheet(strred);
		ui.lineEdit_9->setStyleSheet(strred);		ui.lineEdit_10->setStyleSheet(strred);
		ui.lineEdit_11->setStyleSheet(strred);		ui.lineEdit_12->setStyleSheet(strred);
		ui.lineEdit_13->setStyleSheet(strred);		ui.lineEdit_14->setStyleSheet(strred);
		ui.lineEdit_15->setStyleSheet(strred);		ui.lineEdit_16->setStyleSheet(strred);
		ui.lineEdit_17->setStyleSheet(strred);		ui.lineEdit_18->setStyleSheet(strred);
		ui.lineEdit_19->setStyleSheet(strred);		ui.lineEdit_20->setStyleSheet(strred);
		ui.lineEdit_21->setStyleSheet(strred);		ui.lineEdit_22->setStyleSheet(strred);
		ui.lineEdit_23->setStyleSheet(strred);		ui.lineEdit_24->setStyleSheet(strred);
		ui.lineEdit_25->setStyleSheet(strred);		ui.lineEdit_26->setStyleSheet(strred);
		ui.lineEdit_27->setStyleSheet(strred);		ui.lineEdit_28->setStyleSheet(strred);
		ui.lineEdit_29->setStyleSheet(strred);		ui.lineEdit_30->setStyleSheet(strred);
		ui.lineEdit_31->setStyleSheet(strred);

		if(byte1==3){
			ui.lineEdit_2->setStyleSheet(strgreen);
			ui.lineEdit_5->setStyleSheet(strgreen);
		}else if(byte1==4){
			ui.lineEdit_7->setStyleSheet(strgreen);
		}else if(byte1==8){
			ui.lineEdit->setStyleSheet(strgreen);
		}else if(byte1==10){
			ui.lineEdit_3->setStyleSheet(strgreen);
			ui.lineEdit_6->setStyleSheet(strgreen);
		}

		read2=IPsoc->readSRCIMPRelay();
        qDebug() << "Read SRC IMP Data " << hex << read2;
		byte2 = (unsigned char) read2;

		switch(read2){
		case 0x0:
			ui.lineEdit_8->setStyleSheet(strgreen);
			break;
		case 0x1:
			ui.lineEdit_11->setStyleSheet(strgreen);
			break;
		case 0x2:
			ui.lineEdit_14->setStyleSheet(strgreen);
			break;
		case 0x3:
			ui.lineEdit_17->setStyleSheet(strgreen);
			break;
		case 0x4:
			ui.lineEdit_20->setStyleSheet(strgreen);
			break;
		case 0x5:
			ui.lineEdit_23->setStyleSheet(strgreen);
			break;
		case 0x6:
			ui.lineEdit_26->setStyleSheet(strgreen);
			break;
		case 0x7:
			ui.lineEdit_29->setStyleSheet(strgreen);
			break;
		case 0x8:
			ui.lineEdit_31->setStyleSheet(strgreen);
			break;
		case 0x9:
			ui.lineEdit_9->setStyleSheet(strgreen);
			break;
		case 0xA:
			ui.lineEdit_12->setStyleSheet(strgreen);
			break;
		case 0xB:
			ui.lineEdit_15->setStyleSheet(strgreen);
			break;
		case 0xC:
			ui.lineEdit_18->setStyleSheet(strgreen);
			break;
		case 0xD:
			ui.lineEdit_21->setStyleSheet(strgreen);
			break;
		case 0xE:
			ui.lineEdit_24->setStyleSheet(strgreen);
			break;
		case 0xF:
			ui.lineEdit_27->setStyleSheet(strgreen);
			break;
		case 0x10:
			ui.lineEdit_30->setStyleSheet(strgreen);
			break;
		case 0x11:
			ui.lineEdit_10->setStyleSheet(strgreen);
			break;
		case 0x12:
			ui.lineEdit_13->setStyleSheet(strgreen);
			break;
		case 0x13:
			ui.lineEdit_16->setStyleSheet(strgreen);
			break;
		case 0x14:
			ui.lineEdit_19->setStyleSheet(strgreen);
			break;
		case 0x15:
			ui.lineEdit_22->setStyleSheet(strgreen);
			break;
		case 0x16:
			ui.lineEdit_25->setStyleSheet(strgreen);
			break;
		case 0x17:
			ui.lineEdit_28->setStyleSheet(strgreen);
			break;
		}
		if(read2>=0x20 && read2<=0x37){
			ui.lineEdit_4->setStyleSheet(strgreen);
		}

}
void PTPSoCTestJigInterface2::ResetRelays(){
	IPsoc->resetRelays();
}
void PTPSoCTestJigInterface2::SwitchMux(){
		bool ok = true;


			if (ui.comboBox_12->currentIndex() == 0)
				IPsoc->externalMuxMeasurement(MuxTestLineEdit->text().toUInt(&ok, 16),
						MuxRefLineEdit->text().toUInt(&ok, 16));

			else if (ui.comboBox_12->currentIndex() == 1)
				IPsoc->switchTest(MuxTestLineEdit->text().toUInt(&ok, 16));

			else if (ui.comboBox_12->currentIndex() == 2)
				IPsoc->switchRef(MuxRefLineEdit->text().toUInt(&ok, 16));

}
void PTPSoCTestJigInterface2::disableAllComboBox() {
	ui.comboBox_9->setDisabled(true);
	ui.comboBox_11->setDisabled(true);
	ui.comboBox_8->setDisabled(true);

}
void PTPSoCTestJigInterface2::convertToBits(unsigned char n, int byte) {
        int i, k, andmask;
        unsigned char a[8];
        for (i = 7; i >= 0; i--) {
                andmask = 1 << i;
                k = n & andmask;
                k == 0 ? (a[i] = 0) : (a[i] = 1);
        }

        QString strred = " QLineEdit { border: 1px solid white;border-radius: 14px;color:white;image: url(:/Button-Blank-Red-icon.png);  }";
        QString strgreen = " QLineEdit {border: 1px solid white;border-radius: 14px;color:white;image: url(:/Button-Blank-Green-icon.png); }";

        QString strred1=" QLineEdit {border: 2px solid white;border-radius: 14px;color:white;image: url(:/Button-Blank-Yellow-icon.png); }";
        QString strgreen1=" QLineEdit {border: 2px solid white;border-radius: 14px;color:white;image: url(:/Button-Blank-Blue-icon.png); }";

        switch (byte) {
        case 5: {
                ui.lineEdit_54->setText("0x" + QString::number(n, 16));


                if (a[7] == 1) {
                        ui.lineEdit_53->setStyleSheet(strgreen1);
                } else if (a[7] == 0) {
                        ui.lineEdit_53->setStyleSheet(strred1);
                }
                if (a[6] == 1) {
                        ui.lineEdit_52->setStyleSheet(strgreen1);
                } else if (a[6] == 0) {
                        ui.lineEdit_52->setStyleSheet(strred1);
                }
                if (a[5] == 1) {
                        ui.lineEdit_51->setStyleSheet(strgreen1);
                } else if (a[5] == 0) {
                        ui.lineEdit_51->setStyleSheet(strred1);
                }
                if (a[4] == 1) {
                        ui.lineEdit_50->setStyleSheet(strgreen1);
                } else if (a[4] == 0) {
                        ui.lineEdit_50->setStyleSheet(strred1);
                }

                if (a[3] == 1) {
                        ui.lineEdit_49->setStyleSheet(strgreen1);
                } else if (a[3] == 0) {
                        ui.lineEdit_49->setStyleSheet(strred1);
                }
                if (a[2] == 1) {
                        ui.lineEdit_46->setStyleSheet(strgreen1);
                } else if (a[2] == 0) {
                        ui.lineEdit_46->setStyleSheet(strred1);
                }
                if (a[1] == 1) {
                        ui.lineEdit_47->setStyleSheet(strgreen1);
                } else if (a[1] == 0) {
                        ui.lineEdit_47->setStyleSheet(strred1);
                }
                if (a[0] == 1) {
                        ui.lineEdit_48->setStyleSheet(strgreen1);
                } else if (a[0] == 0) {
                        ui.lineEdit_48->setStyleSheet(strred1);
                }
        }
        break;

        case 6: {
                if (a[0] == 1)
                        ui.lineEdit_49->setStyleSheet(strgreen1);
                else if (a[0] == 0)
                        ui.lineEdit_49->setStyleSheet(strred1);
                if (a[1] == 1)
                        ui.lineEdit_47->setStyleSheet(strgreen1);
                else if (a[1] == 0)
                        ui.lineEdit_47->setStyleSheet(strred1);
                if (a[2] == 1)
                        ui.lineEdit_48->setStyleSheet(strgreen1);
                else if (a[2] == 0)
                        ui.lineEdit_48->setStyleSheet(strred1);
                if (a[3] == 1)
                        ui.lineEdit_46->setStyleSheet(strgreen1);
                else if (a[3] == 0)
                        ui.lineEdit_46->setStyleSheet(strred1);
                if (a[4] == 1)
                        ui.lineEdit_53->setStyleSheet(strgreen1);
                else if (a[4] == 0)
                        ui.lineEdit_53->setStyleSheet(strred1);
                if (a[5] == 1)
                        ui.lineEdit_50->setStyleSheet(strgreen1);
                else if (a[5] == 0)
                        ui.lineEdit_50->setStyleSheet(strred1);
                if (a[6] == 1)
                        ui.lineEdit_52->setStyleSheet(strgreen1);
                else if (a[6] == 0)
                        ui.lineEdit_52->setStyleSheet(strred1);
                if (a[7] == 1)
                        ui.lineEdit_51->setStyleSheet(strgreen1);
                else if (a[7] == 0)
                        ui.lineEdit_51->setStyleSheet(strred1);
        }
        break;

        }

}
void PTPSoCTestJigInterface2::Multimeter() {

}

void PTPSoCTestJigInterface2::Oscilloscope() {
}

void PTPSoCTestJigInterface2::FunctionGenerator() {
	if (ui.groupBox_4->isChecked()) {
			ui.label_9->setText("Function generator is Enabled");
			function += FG;
			ui.comboBox_9->setEnabled(true);
	} else {
		ui.label_9->setText("Fucntion Generator is Disabled");
		function -= FG;
		ui.comboBox_9->setEnabled(false);
	}
}

void PTPSoCTestJigInterface2::ShortLocator() {
}
void PTPSoCTestJigInterface2::InCircuitMeasurement(){
    if(ui.groupBox_6->isChecked()){
        ui.label_9->setText("ICM is Enabled");
        function += ICM;
        ui.comboBox_11->setEnabled(true);

		ui.groupBox_4->setEnabled(false); //FG disabled
		ui.groupBox_4->setChecked(false);
		ui.groupBox_3->setEnabled(false); //VI disabled
		ui.groupBox_3->setChecked(false);
    }else{
        ui.label_9->setText("ICM is Disabled");
        function -= ICM;
        ui.comboBox_11->setCurrentIndex(0);
        ui.comboBox_11->setEnabled(false);

        ui.groupBox_4->setEnabled(true); //FG enabled
        ui.groupBox_3->setEnabled(true); //VI enabled
    }
}
void PTPSoCTestJigInterface2::VoltageCurrent() {
	if (ui.groupBox_3->isChecked()) {
		ui.label_9->setText("VI Enabled");
		ui.groupBox_4->setEnabled(false);
		ui.groupBox_4->setChecked(false);
		ui.comboBox_8->setEnabled(true);
	} else {
		ui.label_9->setText("VI Disabled");

		if (already3 != 0) {
			function -= VI1;
			already3 = 0;

		}

		if (ui.comboBox_8->currentIndex() != 0) {
			ui.comboBox_8->setCurrentIndex(0);
		}
		if (already4 != 0) {
			function -= VI2;
			already4 = 0;
		}

		ui.groupBox_4->setEnabled(true);

		ui.comboBox_8->setEnabled(false);
	}

}

void PTPSoCTestJigInterface2::Voltage(int index) {
}

void PTPSoCTestJigInterface2::R2Wire(int index) {
}

void PTPSoCTestJigInterface2::R4Wire(int index) {
}

void PTPSoCTestJigInterface2::Current(int index) {
}

void PTPSoCTestJigInterface2::Oscilloscope1(int index) {
}

void PTPSoCTestJigInterface2::Oscilloscope2(int index) {
}

void PTPSoCTestJigInterface2::FunctionGenerater(int index) {

	if (index == 1) {
		ui.label_9->setText("Function generator turned ON");
		function += FG;
	} else if (index == 2) {
		ui.label_9->setText("Function generator turned OFF");
	}

}

void PTPSoCTestJigInterface2::ShortLocater(int index) {
	if (index == 1) {
		ui.label_9->setText("Short Locater turned ON");
		function += SL;
	} else if (index == 2) {
		ui.label_9->setText("Short Locater turned OFF");
	}

}
void PTPSoCTestJigInterface2::InCircuitMeasureMent(int index){
    if(index==1){
        ui.label_9->setText("ICM turned ON");
        function += ICM;
    }else if(index==2){
        ui.label_9->setText("ICM turned OFF");
    }
}
void PTPSoCTestJigInterface2::VoltageCurrent1(int index) {

	if (index == 1) {
		ui.label_9->setText("V-1turned ON");
		if (ui.comboBox_8->currentIndex() != 0) {
			ui.comboBox_8->setCurrentIndex(0);
			if (already4 != 0) {
				function -= VI2;
				already4 = 0;
			}

		}
	} else if (index == 2) {
		ui.label_9->setText("VI-1 turned OFF");
		if (already3 != 0) {
			function -= VI1;
			already3 = 0;
		}
	}
}

void PTPSoCTestJigInterface2::VoltageCurrent2(int index) {
	if (index == 1) {
		ui.label_9->setText("V-2turned ON");
		if (ui.comboBox_8->currentIndex() != 0) {
			if (already4 != 1) {
				function += VI2;
				already4 = 1;
			}
		}
	} else if (index == 2) {
		ui.label_9->setText("VI-2 turned OFF");
		if (already4 != 0) {
			function -= VI2;
			already4 = 0;
		}
	}

}
void PTPSoCTestJigInterface2::callMuxTestInput() {
	if (MuxTestLineEdit->hasFocus()) {
		openNumKBPanel(0);
		m_nLineEditIndex = 1;
	}
}
void PTPSoCTestJigInterface2::callMuxRefInput() {
	if (MuxRefLineEdit->hasFocus()) {
		openNumKBPanel(0);
		m_nLineEditIndex = 2;
	}
}
void PTPSoCTestJigInterface2::callCommandInput() {
	if (CommandLineEdit->hasFocus()) {
		openNumKBPanel(0);
		m_nLineEditIndex = 3;
	}
}
void PTPSoCTestJigInterface2::MuxInputs(int index){

		Q_UNUSED(index)
		if (ui.comboBox_12->currentIndex() == 0) {
			ui.lineEdit_57->setEnabled(true);
			ui.lineEdit_58->setEnabled(true);
		} else if (ui.comboBox_12->currentIndex() == 1) {
			ui.lineEdit_57->setEnabled(true);
			ui.lineEdit_58->setEnabled(false);
		} else if (ui.comboBox_12->currentIndex() == 2) {
			ui.lineEdit_57->setEnabled(true);
			ui.lineEdit_58->setEnabled(false);
		}

}
void PTPSoCTestJigInterface2::CommandSelection(int index) {

	if (ui.comboBox_13->currentIndex() == 1)
		ui.label_9->setText("ON Selected");
	else if (ui.comboBox_13->currentIndex() == 2)
		ui.label_9->setText("OFF Selected");
	else if (ui.comboBox_13->currentIndex() == 3)
		ui.label_9->setText("Raw Command Selected");

	index = index;
}
void PTPSoCTestJigInterface2::EmbeddedKey(){
	if (ui.groupBox_10->isChecked()) {
		IBackPlane->writeBackPlaneRegister(GPIOINT, 0x0020);
		qDebug() << "Embedded probe Enanbled";
	}
	 else {
		IBackPlane->writeBackPlaneRegister(NOINT, 0x0020);
		qDebug() << "Embedded probe Disabled";
	}

}
void PTPSoCTestJigInterface2::receiveValue(unsigned int pValue)
{
    if(m_nLineEditIndex==1){
    	MuxTestLineEdit->setText(QString::number(pValue,16));
        }
    else if(m_nLineEditIndex==2){
    	MuxRefLineEdit->setText(QString::number(pValue,16));
        }
    else if(m_nLineEditIndex==3){
    	CommandLineEdit->setText(QString::number(pValue,16));
        }
}
void PTPSoCTestJigInterface2::receiveValue(QString pValue) {
	Q_UNUSED(pValue)
}
void PTPSoCTestJigInterface2::receiveValue(double pValue)
{
	Q_UNUSED(pValue)
}
void PTPSoCTestJigInterface2::openNumKBPanel(short int pValue) {
	QWidget *w = INumberPanel->getNumKBPanel(pValue, this);
	w->setWindowFlags(Qt::WindowCloseButtonHint | Qt::Dialog);
	w->show();
}

void PTPSoCTestJigInterface2::on_comboBox_10_currentIndexChanged(int index)
{
    source_impedance=(unsigned int)index;
    qDebug()<<hex<<"impedance index:"<<source_impedance;
}

void PTPSoCTestJigInterface2::on_switchSRCIMP_clicked()
{
    IPsoc->srcImpedanceSelection(source_impedance);

}
void PTPSoCTestJigInterface2::EnDisSRCIM(bool val)
{
    ui.comboBox_10->setEnabled(!val);
    ui.switchSRCIMP->setEnabled(!val);

    IPsoc->srcImpedanceEnable(val);

}

void PTPSoCTestJigInterface2::on_switchFLY_clicked()
{
    IPsoc->switchFly();
}
