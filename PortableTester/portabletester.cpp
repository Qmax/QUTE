#include "portabletester.h"
#include "ui_portabletester.h"
#include "mainwindowview.h"


void customMessageHandler(QtMsgType type, const char *msg)
{
	QString dt = QDateTime::currentDateTime().toString("dd/MM/yyyy hh:mm:ss");
	QString txt = QString("[%1] ").arg(dt);

	switch (type)
	{
	case QtDebugMsg:
		txt += QString("{Debug} \t\t %1").arg(msg);
		break;
	case QtWarningMsg:
		txt += QString("{Warning} \t %1").arg(msg);
		break;
	case QtCriticalMsg:
		txt += QString("{Critical} \t %1").arg(msg);
		break;
	case QtFatalMsg:
		txt += QString("{Fatal} \t\t %1").arg(msg);
		abort();
		break;
	}

	QFile outFile("PT6LogFile.log");
	outFile.open(QIODevice::WriteOnly | QIODevice::Append);

	QTextStream textStream(&outFile);
	textStream << txt << endl;
        outFile.close();
}

PortableTester::PortableTester(QWidget *parent) :
        		QMainWindow(parent, Qt::FramelessWindowHint | Qt::WindowSystemMenuHint),
        		ui(new Ui::PortableTester) {

	ui->setupUi(this);
	/*    LoginDialog* loginDialog = new LoginDialog( this );
    connect(loginDialog,SIGNAL(acceptLogin(QString&,QString&,int&)),this,SLOT(slotAcceptUserLogin(QString&,QString&)));
    do{
        loginDialog->exec();
    }while(!m_nPassword);*/
	//qDebug()
	//<< "----------------------------PORTABLE TESTER STARTS----------------------------";

	//Set home Directory as Current Directory
	QDir::setCurrent("/home");

	//PT6 Application Interface Library
	QPluginLoader apploader1("libPTComponentsInterface.so", this);
	QObject *AppPlugin1 = apploader1.instance();
	IPT = qobject_cast<IPTComponentsInterface*> (AppPlugin1);

	//Application Card Interface Library
	QPluginLoader loaderApp("libPTApplicationcardInterface.so", this);
	IAppCard = qobject_cast<IApplicationCardInterface*> (loaderApp.instance());
	IAppCard->setDeviceName(SLOT0);
	IAppCard->enumerateAPPCard();

	//Backplane Interface Library
	QPluginLoader loader2("libBackPlaneInterface.so", this);
	IBackPlane = qobject_cast<IntefaceBackPlane*> (loader2.instance());
	IBackPlane->InitializeBpObject();

	//PSOC Interface Library
	QPluginLoader loader3("libPTPsocInterface2.so", this);
	IPsoc = qobject_cast<IPSOCCOMMUNICATION*> (loader3.instance());
	IPsoc->openSerial();
	objTimer = new QTimer(this);
	connect(objTimer, SIGNAL(timeout()), this, SLOT(checkButton()));

	//	idleTimer=new QTimer(this);
	//	connect(idleTimer, SIGNAL(timeout()),this,SLOT(idleScreen()));
	//	idleTimer->setInterval(23000);
	//	idleTimer->start();
	//QMax PT Interface Library
	QPluginLoader loader4("libQmaxPTInterface.so", this);
	IptLib = qobject_cast<IQmaxPTLibrary*> (loader4.instance());
	//GPIO Event Interface Library
	QPluginLoader loader5("libGPIOEventInterface.so", this);
	IGPIOEvent = qobject_cast<PTGPIOEventInterface*> (loader5.instance());
	//PT Keypad Interface Library
	QPluginLoader loader6("libPTKeyEventInterfaces.so", this);
	IPTKeyEvent = qobject_cast<PTEventInterface*> (loader6.instance());
	//GPIO PIN Interface Library for toggle touch and kill
	QPluginLoader loader7("libPTGPIOPinInterface.so", this);
	IGPIOPin = qobject_cast<InterfaceGPIOPins*> (loader7.instance());
	//    //Hardware Identification Library
	//    QPluginLoader loader8("libPTHWIDInterface.so", this);
	//    IHWID = qobject_cast<IHWIDInterface*> (loader8.instance());
	//
	//    //Utility Panel Interface Library
	//    QPluginLoader loader9("libUtilityPanel.so", this);
	//    IUtility = qobject_cast<UtilityInterface*> (loader9.instance());


	IBackPlane->writeBackPlaneRegister(0x03, 0x14); // Initialize LCD Control
	//    IptLib->InitPTLibrary("./PTUI.xml", "MainWindow");
	initialitation();
	IPTKeyEvent->InvokeGPIOEvent(this, "/dev/input/event2", "pt_kpp",&m_nPTKeyCode);
	//    IGPIOEvent->InvokeGPIOEvent(this, "/dev/input/event3", "gpioshutdown", &m_nPTShutDown);//do not uncomment VI will not work properly

	//qDebug() << "PT win Id" << this->winId();
	isWindowOpen = false;

	msgBoxLive = false;
	/*
	QByteArray psocData;

	QMessageBox failure;
	IPsoc->writeSerial(0xff);
	IPsoc->writeSerial(0xff);
	psocData = IPsoc->readSerByte();
	if (psocData.endsWith("*?") == true) {
		qDebug() << "PSOC RESET DONE on 1st try";
	} else {
		IPsoc->writeSerial(0xff);
		psocData = IPsoc->readSerByte();
		if (psocData.endsWith("*?") == true) {
			qDebug() << "PSOC RESET DONE on 2nd try";
		} else {
			IPsoc->writeSerial(0xff);
			psocData = IPsoc->readSerByte();
			if (psocData.endsWith("*?") == true) {
				qDebug() << "PSOC RESET DONE on 3rd try";
			} else {
				failure.setText("PSOC RESET FAILURE");
				failure.exec();
			}

		}
	}

	qDebug() << "RESET DATA:" << psocData;
	 */

	QMessageBox testing;
	if (IAppCard->readAppCardCodeId() != 0x1982) {
		testing.setText("Check Appcard !!!");
		testing.exec();
	}
	if (IBackPlane->readBackPlaneCodeID() != 0x2704) {
		testing.setText("Check Backpanel !!!");
		testing.exec();
	}
	//	IAppCard->resetADC(1);
	dmmPlugin = viPlugin = fgPlugin = slPlugin = icmPlugin = false;
	m_bTouchFlag = true;

	//~~~~~~~~~~~Transparent OM Symbol Splash~~~~~~~~~~~
	/*	QPixmap pixmap(":/images/Tamil_ohm2.png");
	QSplashScreen splash(pixmap);
	splash.setMask(pixmap.mask());
	splash.show();
	splash.close();*/
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//~~~~~~~~~~~~~~Digital Clock~~~~~~~~~~~~~~~~~~~~~~~
	clock=new QDigitalClock(this);
	clock->setGeometry(620,0,170,30);
	clock->m_TextColor=QColor(255,255,255,255);
	clock->setFont(QFont("DejaVu Sans",14,50,false));
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	myID=0;
	//	 qInstallMsgHandler(customMessageHandler);
}
void PortableTester::slotAcceptUserLogin(QString& name,QString& password){
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

void PortableTester::idleScreen(){
	if (splashIdle->isEnabled()==true) {
		splashIdle->setEnabled(false);
		splashIdle->close();
		//		idleTimer->start();
	} else {
		//		idleTimer->stop();
		splashIdle->setEnabled(true);
		splashIdle->show();
	}
}
char PortableTester::showMessageBox(bool connect, bool abort,bool cancel, QString text,QString okText="Ok", QString NoText="Cancel",QString cancelText="Abort") {
	msgBoxLive = true;
	msgBox = new QMessageBox(this);
	msgBox->setFont(QFont("DejaVu Sans", 15, 50, false));
	msgBox->setIcon(QMessageBox::Information);
	msgBox->setWindowIcon(QIcon(":/images/image.png"));
	msgBox->setStyleSheet("color : white;background-color :rgb(88,88,87,255);");
	msgBox->setText(text);
	if (connect == true){
		connectButton = msgBox->addButton(okText, QMessageBox::YesRole);
		connectButton->setFont(QFont("DejaVu Sans", 18, 50, false));
		//qDebug()<<"163";
	}
	if (abort == true){
		abortButton = msgBox->addButton(NoText, QMessageBox::NoRole);
		abortButton	 ->setFont(QFont("DejaVu Sans", 18, 50, false));
		//qDebug()<<"167";
	}
	if (cancel==true){
		cancelButton =msgBox->addButton(cancelText, QMessageBox::RejectRole);
		cancelButton ->setFont(QFont("DejaVu Sans", 18, 50, false));
		//qDebug()<<"171";
	}
	msgBox->exec();
	//qDebug()<<"176";
	if (msgBox->clickedButton() == connectButton){
		//qDebug()<<"178";
		return 'Y';
	}
	if (abort == true){
		//qDebug()<<"182";
		if (msgBox->clickedButton() == abortButton)
			return 'N';
	}
	if (cancel == true){
		//qDebug()<<"187";
		if (msgBox->clickedButton() == cancelButton)
			return 'A';
	}
}

void PortableTester::clickedPRSCR() {

	QPixmap Pix = QPixmap();
	Pix = QPixmap::grabWindow(QApplication::desktop()->winId());
	Pix.save("mainscreen.jpg");
	QClipboard *board = QApplication::clipboard();
	board->setPixmap(Pix);
	QWidget::showFullScreen();

}

void PortableTester::checkButton() {
	QTime objTime = QTime::currentTime();
	l_objMainView->m_objDate = QDateTime::currentDateTime();
	l_objMainView->m_strTime = l_objMainView->m_objDate.toString(Qt::TextDate);
	l_objMainView->InitHeaderView(1, "PT6-QUTE");
}
void PortableTester::poweroff() {
	//qDebug()<<"poweroff";
	IGPIOPin->killSystem();
	//    QProcess::execute("poweroff");

}
void PortableTester::houseKeeping() {
	//qDebug()<<"houseKeeping";
	IBackPlane->closeObject();
	IPsoc->closeSerial();
	objTimer->stop();

	//    delete *AppButtons;
	//    delete *FunctionalButtons;
	//    delete l_objMainView;
}
void PortableTester::CreateButton() {

	QString icon = ":/Desktop/app";
	for (int i = 0; i < APPLICATIONS; i++) {
		if(i<APPLICATIONS){
			//            			glowButton[i] = new QPushButton(this);//~~~~~~~~~~~~~
			AppButton[i] = new QmaxPushButton(i, this);

			//            			glowButton[i]->setStyleSheet("border:0.2px rgba(0,0,0,20);border-radius:10px;border-style: outset;background-color: rgba(255,255,255,150);");//~~~~~~~~~~~~~
			//            			glowButton[i]->setFocusPolicy(Qt::NoFocus);//~~~~~~~~~~~~~

			/*if (i == 0 || i == 1 || i == 2){///*~~~~~~~~~~~~~
				glowButton[i]->setGeometry(172 + (125 * i), 142, 57, 57);
				AppButton[i]->setGeometry(165 + (125 * i), 135, 70, 70);
			}
			if (i == 3 || i == 4 || i == 5){
				glowButton[i]->setGeometry(172 + (125 * (i - 3)), 237, 57, 57);
				AppButton[i]->setGeometry(165 + (125 * (i - 3)), 230, 70, 70);
			}*///*/~~~~~~~~~~~~~
			if (i == 0 || i == 1 || i == 2 || i== 3){

				AppButton[i]->setGeometry(50*((i+1)*3), 100, 80, 80);
			}
			if (i == 4 || i == 5 ){

				AppButton[i]->setGeometry(50*((i-3)*3), 250, 80, 80);
			}
			if (i==6 ||i==7 || i == 8){

				AppButton[i]->setGeometry(120*((i-4)*1)+65, 480, 70, 70);
			}

			AppButton[i]->setIcon(QIcon(QPixmap(icon + QString::number(i, 10)+ ".png")));
		}
		connect(AppButton[i],SIGNAL(CClicked(int)),this,SLOT(buttonPressed(int)));
	}

	shutDownButton = new QmaxPushButton(15, this);
	shutDownButton->setGeometry(165, 480, 70, 70);
	shutDownButton->setIcon(QIcon(QPixmap(":/Desktop/Power.png")));
	connect(shutDownButton,SIGNAL(CClicked(int)),this,SLOT(buttonPressed(int)));

	shlocButton = new QmaxPushButton(16, this);
	shlocButton->setGeometry(50*((6-3)*3), 250, 80, 80);
	shlocButton->setIcon(QIcon(QPixmap(":/Desktop/app3.png")));
	connect(shlocButton,SIGNAL(CClicked(int)),this,SLOT(buttonPressed(int)));
	shlocButton->setVisible(false);

}

void PortableTester::CreateButtons(QWidget *pWidget, QString strPanel) {
	QList<PT_MENU*> l_lstWindowParams = IptLib->ReadPanel(strPanel);
	for (int l_nIndex = 0; l_nIndex < l_lstWindowParams.count(); l_nIndex++) {
		PT_MENU *l_obj = l_lstWindowParams.at(l_nIndex);
		QSize l_tempSize(l_obj->m_nWidth, l_obj->m_nHeight);
		if (strPanel == "ApplicationPanel") {
			//qDebug() << l_obj->m_strImageName;
			AppButtons[l_nIndex] = new QmaxButton(l_obj->m_strButtonCaption,
					l_tempSize, l_obj->m_strImageName, 0, l_nIndex, pWidget);
			AppButtons[l_nIndex]->setGeometry(l_obj->m_nXPos, l_obj->m_nYPos,
					l_obj->m_nWidth, l_obj->m_nHeight);
			connect((QmaxButton*) AppButtons[l_nIndex], SIGNAL(clicked(int)),
					pWidget, SLOT(buttonPressed(int)));
		} else if (strPanel == "FunctionPanel") {
			FunctionalButtons[l_nIndex] = new QmaxButton(
					l_obj->m_strButtonCaption, l_tempSize,
					l_obj->m_strImageName, 2, l_nIndex, pWidget);
			FunctionalButtons[l_nIndex]->setGeometry(l_obj->m_nXPos,
					l_obj->m_nYPos, l_obj->m_nWidth, l_obj->m_nHeight);
			connect(FunctionalButtons[l_nIndex], SIGNAL(clicked(int)), pWidget,
					SLOT(buttonPressed(int)));
		}
	}
}

PortableTester::~PortableTester() {

	IBackPlane->closeObject();
	IPsoc->closeSerial();
	//delete ui;
	objTimer->stop();
	//qDebug()
	//<< "----------------------------PORTABLE TESTER ENDS----------------------------";
	delete *AppButtons;
	delete *FunctionalButtons;
	delete l_objMainView;
}

void PortableTester::initialitation() {
	//ui->subwindow->setWindowFlags(Qt::FramelessWindowHint);
	/*
	 1. Creating Application View
	 2. Creating Navigation View
	 3. Creating Functional Keys View
	 4. Creating Header View
	 */
	l_objMainView = new MainWindowView(this);
	ui->mdiArea->addSubWindow(l_objMainView, Qt::FramelessWindowHint);
	l_objMainView->showMaximized();

	setCentralWidget(ui->mdiArea);
	l_objMainView->InitPrimaryView();
	//	l_objMainView->InitMainPane();	//Hiding Applications Panel
	//	l_objMainView->InitSidePane();
	//	l_objMainView->InitBasePane();
	baseFrame=new QFrame(this);
	baseFrame->setGeometry(100,470,600,145);
	baseFrame->setStyleSheet("QFrame{image: url(:/images/gradient_oval1.png);}");
	baseFrame->setVisible(true);



	l_objMainView->m_objDate = QDateTime::currentDateTime();
	l_objMainView->m_strTime = l_objMainView->m_objDate.toString(Qt::TextDate);
	l_objMainView->timer = new QTimer(this);
	l_objMainView->InitHeaderView(1, "PT6-QUTE");

	//	CreateButtons(this, "ApplicationPanel");
	//	CreateButtons(this, "FunctionPanel");

	CreateButton();

	splashIdle = new QSplashScreen;
	splashIdle->setPixmap(QPixmap(":/images/imageIdle.png").scaled(790, 590));
	splashIdle->setEnabled(false);
}
void PortableTester::on_shutDownButton_clicked() {
	//qDebug()<<"on_shutDownButton_clicked";
	char ret = showMessageBox(true, true,true,"Are you sure to shut down/Restart the system?", "Shutdown","Reboot","Cancel");
	if (ret == 'Y') {
		l_objMainView->hideWindows();
		closeButtons();
		QSplashScreen *splash = new QSplashScreen;
		splash->setPixmap(QPixmap(":/images/image93.png").scaled(790, 590));
		splash->show();
		QTimer::singleShot(2000, this, SLOT(houseKeeping()));
		QTimer::singleShot(5000, this, SLOT(poweroff()));

	}
	else if(ret=='N') {
		l_objMainView->hideWindows();
		closeButtons();
		QTimer::singleShot(2000, this, SLOT(houseKeeping()));
		QApplication::exit();
		QProcess::execute("reboot");
	}
	else if(ret=='A'){
		msgBox->close();
	}
}

void PortableTester::on_testjigButton_clicked() {
	QDir::setCurrent("/home");
	QProcess::execute("./PortableTesterTestJig2 -qws");
	QApplication::exit();
	QDir::setCurrent("/home");
	QProcess::execute("./PortableTester -qws");
}
void PortableTester::changeEvent(QEvent *e) {
	//qDebug() << "Inside PortableTester Change Event" << e->type();
	switch (e->type()) {
	case QEvent::LanguageChange:
		ui->retranslateUi(this);
		break;
	default:
		break;
	}
}

void PortableTester::closeButtons() {

	//	for(int i=0;i<6;i++)
	//		AppButtons[i]->close();

	//	for(int i=0;i<6;i++)
	//		FunctionalButtons[i]->close();

	for (int i = 0; i < APPLICATIONS; i++)
		AppButton[i]->setVisible(false);

	//	for (int i = 0; i < FUNCTIONS; i++)
	//		FunctionalButton[i]->setVisible(false);

	//    	for(int i=0;i<6;i++)//~~~~~~~~~~~~~~
	//    		glowButton[i]->setVisible(false);//~~~~~~~~~~~~~~

	//	prevButton->setVisible(false);
	//	nextButton->setVisible(false);

	shutDownButton->setVisible(false);
	shlocButton->setVisible(false);

	//	testjigButton->setVisible(false);



}

void PortableTester::showButtons() {
	//	for(int i=0;i<6;i++)
	//		AppButtons[i]->show();

	//	for(int i=0;i<6;i++)
	//		FunctionalButtons[i]->show();

	for (int i = 0; i < APPLICATIONS; i++)
		AppButton[i]->setVisible(true);

	//	for (int i = 0; i < FUNCTIONS; i++){
	//		if(FunctionalButton[i]->geometry().y()>=70&&FunctionalButton[i]->geometry().y()<=470)
	//			FunctionalButton[i]->setVisible(true);
	//	}

	//    	for(int i=0;i<6;i++)//~~~~~~~~~~~~~~~
	//    		glowButton[i]->setVisible(true);//~~~~~~~~~~~~~

	//	if(FunctionalButton[0]->geometry().y()==70){
	//		nextButton->setVisible(true);
	//		prevButton->setVisible(false);
	//	}
	//	else{
	//		nextButton->setVisible(false);
	//		prevButton->setVisible(true);
	//	}


	shutDownButton->setVisible(true);
	shlocButton->setVisible(false);
	//	testjigButton->setVisible(true);
}

void PortableTester::customEvent(QEvent* e) {
	//qDebug() << "Portable Tester-Custom Event";
	if(myID==0){
		if (e->type() == ShutDownEvent) {
			//qDebug() << "GPIO Shutdown Application Layer";
			/*            houseKeeping();
            QSplashScreen *splash = new QSplashScreen;
            splash->setPixmap(QPixmap(":/images/image93.png").scaled(790, 590));
            splash->show();
            poweroff();*/
			on_shutDownButton_clicked();
		}
		if (e->type() == ((QEvent::Type) 5678)) {
			//qDebug() << "Portable Tester-PT-Key Event";
			if (isWindowOpen == true)
				return;
			if (m_nPTKeyCode == 1) {
				//qDebug() << ("\nMENU");
				idleScreen();

			}
			if (m_nPTKeyCode == 4) {
				//qDebug() << ("\nF1");
				buttonPressed(0);
				//			for(int i=0;i<6;i++){
				//				if(FunctionalButton[i]->geometry().y()==70)
				//					Functions(i);
				//			}
			} else if (m_nPTKeyCode == 5) {
				//qDebug() << ("\nF2");
				buttonPressed(1);
				//			for(int i=0;i<6;i++){
				//				if(FunctionalButton[i]->geometry().y()==170)
				//					Functions(i);
				//			}

			} else if (m_nPTKeyCode == 6) {
				//qDebug() << ("\nF3");
				buttonPressed(2);
				//			for(int i=0;i<6;i++){
				//				if(FunctionalButton[i]->geometry().y()==270)
				//					Functions(i);
				//			}

			} else if (m_nPTKeyCode == 7) {
				//qDebug() << ("\nF4");
				buttonPressed(3);
				//			for(int i=0;i<6;i++){
				//				if(FunctionalButton[i]->geometry().y()==370)
				//					Functions(i);
				//			}

			} else if (m_nPTKeyCode == 8) {
				//qDebug() << ("\nF5");
				buttonPressed(4);
				//			for(int i=0;i<6;i++){
				//				if(FunctionalButton[i]->geometry().y()==470)
				//					Functions(i);
				//			}

			} else if (m_nPTKeyCode == 2) {
				//qDebug() << ("\nESC");
				if (msgBoxLive == true) {
					cancelButton->animateClick(1);
				} else
					buttonPressed(15);
			}
			else if(m_nPTKeyCode == 9){
				//qDebug() << ("\nUP");
				//			UpDownButton(_UP_);
			}
			else if(m_nPTKeyCode == 10){
				//qDebug() << ("\nDOWN");
				//			UpDownButton(_DOWN_);
			}
			else if (m_nPTKeyCode == 11) {
				//qDebug() << ("\nRIGHT");
				if (msgBoxLive != true) {

				}
				else if (msgBoxLive == true) {
					if (connectButton->hasFocus())
						abortButton->setFocus();
					else if(abortButton->hasFocus())
						cancelButton->setFocus();
					else if(cancelButton->hasFocus())
						connectButton->setFocus();

				}
			} else if (m_nPTKeyCode == 12) {
				//qDebug() << ("\nLEFT");
				if (msgBoxLive != true) {

				}
				else if (msgBoxLive == true) {
					if (connectButton->hasFocus())
						cancelButton->setFocus();
					else if(abortButton->hasFocus())
						connectButton->setFocus();
					else if(cancelButton->hasFocus())
						abortButton->setFocus();
				}
			}

			else if (m_nPTKeyCode == 13) {
				//qDebug() << ("\nENTER");
				if (msgBoxLive == true) {
					if (connectButton->hasFocus())
						connectButton->animateClick(1);
					else if(abortButton->hasFocus())
						abortButton->animateClick(1);
					else if(cancelButton->hasFocus())
						cancelButton->animateClick(1);
					msgBoxLive = false;
				}
			} else if (m_nPTKeyCode == 16) {
				IGPIOPin->toggleTouchButton();

				if (m_bTouchFlag == false) {
					QProcessEnvironment env =
							QProcessEnvironment::systemEnvironment();

					if (env.contains("TSLIB_TSDEVICE"))
						env.remove("TSLIB_TSDEVICE");
					if (env.contains("QWS_MOUSE_PROTO"))
						env.remove("QWS_MOUSE_PROTO");

					process.setProcessEnvironment(env);

					env.insert("TSLIB_TSDEVICE", "/dev/input/ts0");
					env.insert("QWS_MOUSE_PROTO", "tslib:/dev/input/ts0");

					process.setProcessEnvironment(env);

					//qDebug() << "Touch Command exported";

					m_bTouchFlag == true;
				} else if (m_bTouchFlag == true) {
					QProcessEnvironment env =
							QProcessEnvironment::systemEnvironment();

					if (env.contains("TSLIB_TSDEVICE"))
						env.remove("TSLIB_TSDEVICE");
					if (env.contains("QWS_MOUSE_PROTO"))
						env.remove("QWS_MOUSE_PROTO");

					process.setProcessEnvironment(env);

					env.insert("TSLIB_TSDEVICE", "/dev/event1");
					env.insert("QWS_MOUSE_PROTO", "IntelliMouse:/dev/input/mouse1");

					process.setProcessEnvironment(env);

					//qDebug() << "Mouse Command exported";

					m_bTouchFlag == false;
				}
			} else if (m_nPTKeyCode == 17) {
				clickedPRSCR();
				this->close();
			} else if (m_nPTKeyCode == 18){this->close();}

		}
		QEvent(e->type());
	}
}
void PortableTester::UpDownButton(int pValue){
	if(pValue==_UP_){
		if(FunctionalButton[0]->geometry().y()!=70){
			for(int i=0;i<6;i++){
				int yAxis=FunctionalButton[i]->geometry().y();

				QPropertyAnimation *animation = new QPropertyAnimation(FunctionalButton[i], "geometry");
				animation->setStartValue(QRect(720,yAxis, 70,70));
				animation->setEndValue(QRect(720,yAxis+100, 70,70));
				animation->setEasingCurve(QEasingCurve::Linear);
				animation->setDuration(500);
				animation->start();

				FunctionalButton[i]->setGeometry(720, yAxis+100, 70, 70);
				if(FunctionalButton[i]->geometry().y()<70 || FunctionalButton[i]->geometry().y()>470)
					FunctionalButton[i]->setVisible(false);
				else
					FunctionalButton[i]->setVisible(true);
			}
			if(FunctionalButton[0]->geometry().y()==70){
				prevButton->setVisible(false);
				nextButton->setVisible(true);
			}
		}
	}
	else if(pValue==_DOWN_){
		if(FunctionalButton[5]->geometry().y()!=470){
			for(int i=0;i<6;i++){
				int yAxis=FunctionalButton[i]->geometry().y();

				QPropertyAnimation *animation = new QPropertyAnimation(FunctionalButton[i], "geometry");
				animation->setStartValue(QRect(720,yAxis, 70,70));
				animation->setEndValue(QRect(720,yAxis-100, 70,70));
				animation->setEasingCurve(QEasingCurve::Linear);
				animation->setDuration(500);
				animation->start();
				FunctionalButton[i]->setGeometry(720, yAxis-100, 70, 70);
				if(FunctionalButton[i]->geometry().y()<70 || FunctionalButton[i]->geometry().y()>470)
					FunctionalButton[i]->setVisible(false);
				else
					FunctionalButton[i]->setVisible(true);
			}
			if(FunctionalButton[5]->geometry().y()==470){
				prevButton->setVisible(true);
				nextButton->setVisible(false);
			}
		}
	}
}
void PortableTester::Functions(int pValue){
	// 0-DMM,1-VI,2-FG,3-SL,4-ICM,5-SCOPE

	QString l_strValue = "";
	l_strValue.setNum(pValue);
	l_objMainView->hideWindows();
	baseFrame->setVisible(false);
	closeButtons();
	isWindowOpen = true;

	if (pValue == _DMM_) {
		//		char connectStatus=showMessageBox(true,true,false,"Ensure proper DMM cables connected.");
		//		if(connectStatus=='Y'){
		IPT->LoadDMMPlugins();
		myID = 0x444D4D;
		QWidget *DMM = IPT->InvokeApplication(myID);
		l_objMainView->InitHeaderView(0, "DIGITAL MULTIMETER");
		connect(DMM, SIGNAL(destroyed()), this, SLOT(UnHide()));
		ui->mdiArea->addSubWindow(DMM, Qt::FramelessWindowHint);
		DMM->show();
		//		}
	//		else if(connectStatus=='N'){
		//			msgBox->close();
		//		}
	}
	else if (pValue == _VI_) {
		//		char connectStatus=showMessageBox(true,true,false,"Ensure proper VI cables connected.");
		//		if(connectStatus=='Y'){
		//qDebug()<<"VI Application";
		IPT->LoadVIPlugins();
		myID = 0x56494D;
		QWidget *VI = IPT->InvokeApplication(myID);
		l_objMainView->InitHeaderView(0, "QSM-VI");
		connect(VI, SIGNAL(destroyed()), this, SLOT(UnHide()));
		ui->mdiArea->addSubWindow(VI, Qt::FramelessWindowHint);
		VI->show();
		//		}
	//		else if(connectStatus=='N'){
		//			msgBox->close();
		//		}
	}
	else if (pValue == _FG_) {
		//		char connectStatus=showMessageBox(true,true,false,"Ensure proper FG cables connected.");
		//		if(connectStatus=='Y'){
		IPT->LoadFGPlugins();
		myID = 0x46474D;
		QWidget *FG = IPT->InvokeApplication(myID);
		l_objMainView->InitHeaderView(0, "ARBITARY WAVEFORM GENERATOR");
		connect(FG, SIGNAL(destroyed()), this, SLOT(UnHide()));
		ui->mdiArea->addSubWindow(FG, Qt::FramelessWindowHint);
		FG->show();
		//		}
	//		else if(connectStatus=='N'){
		//			msgBox->close();
		//		}
	}
	else if (pValue == _SL_) {
		//		char connectStatus=showMessageBox(true,true,false,"Ensure proper Short Locator cables connected.");
		//		if(connectStatus=='Y'){
		IPT->LoadSLPlugins();
		myID = 0x534C4D;
		QWidget *SL = IPT->InvokeApplication(myID);
		l_objMainView->InitHeaderView(0, "SHORT LOCATOR");
		connect(SL, SIGNAL(destroyed()), this, SLOT(UnHide()));
		ui->mdiArea->addSubWindow(SL, Qt::FramelessWindowHint);
		SL->show();
		//		}
	//		else if(connectStatus=='N'){
		//			msgBox->close();
		//		}
	}

	else if (pValue == _ICM_) {
		//		char connectStatus=showMessageBox(true,true,false,"Ensure proper ICM cables connected.");
		//		if(connectStatus=='Y'){
		IPT->LoadICMPlugins();
		myID = 0x49434D;
		QWidget *ICM = IPT->InvokeApplication(myID);
		l_objMainView->InitHeaderView(0, "ICM");
		connect(ICM, SIGNAL(destroyed()), this, SLOT(UnHide()));
		ui->mdiArea->addSubWindow(ICM, Qt::FramelessWindowHint);
		ICM->show();
		//		}
	//		else if(connectStatus=='N'){
		//			msgBox->close();
		//		}

	}
	else if (pValue == _DSO_) {
		//		char connectStatus=showMessageBox(true,true,false,"Ensure proper Scope cables connected.");
		//		if(connectStatus=='Y'){
		IPT->LoadDSOPlugins();
		myID=0x44534F;
		QWidget *DSO = IPT->InvokeApplication(myID);
		l_objMainView->InitHeaderView(0, "DIGITAL STORAGE OSCILLOSCOPE");
		connect(DSO, SIGNAL(destroyed()), this, SLOT(UnHide()));
		ui->mdiArea->addSubWindow(DSO, Qt::FramelessWindowHint);
		DSO->show();
		//			QDir::setCurrent("/home");
		//
		//			QProcess::execute("./DSOUIx -qws");
		//			QApplication::exit();
		//			QDir::setCurrent("/home");
		//			QProcess::execute("./PortableTester -qws");
		//		}
		//		else if(connectStatus=='N'){
		//			msgBox->close();
		//		}
	}
	else if(pValue == 16){
		//qDebug()<<"SHORT LOCATOR TESTJIG";
		IPT->LoadSHLPlugins();
		myID = 0x999999;
		QWidget *SHL = IPT->InvokeApplication(myID);
		l_objMainView->InitHeaderView(0, "SHORT LOCATOR TEST UI");
		connect(SHL, SIGNAL(destroyed()), this, SLOT(UnHide()));
		ui->mdiArea->addSubWindow(SHL, Qt::FramelessWindowHint);
		SHL->show();
	}

}
void PortableTester::buttonPressed(int pValue) {
	//qDebug() << "pValue:" << pValue;
	//~~~~~~~~~~~~~MAIN 6 FUNCTIONS~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	if (pValue == 0) {
		Functions(_DMM_);
	}
	else if (pValue == 1) {
		Functions(_VI_);
	}
	else if (pValue == 2) {
		Functions(_FG_);
	}
	else if (pValue == 3) {
		Functions(_SL_);
	}
	else if (pValue == 4) {
		Functions(_ICM_);
	}
	else if (pValue == 5) {
		Functions(_DSO_);
	}
	else if (pValue == 6) {
		on_testjigButton_clicked();
	}
	else if (pValue == 7) {
            QProcess::execute("/usr/bin/qt-embedded/ts_calibrate");
            QApplication::exit();
            QDir::setCurrent("/home");
            QProcess::execute("./PortableTester -qws");
	}
	else if(pValue == 8){
		QDir::setCurrent("/home");
		QProcess::execute("./fm -qws");
		QApplication::exit();
		QDir::setCurrent("/home");
		QProcess::execute("./PortableTester -qws");
	}
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	else if (pValue == 15) {
		on_shutDownButton_clicked();
	}
	else if(pValue == 16){
		Functions(16);
	}
	else if(pValue == 18){
		//		UpDownButton(_DOWN_);
	}
	else if(pValue == 17){
		//		UpDownButton(_UP_);
	}

}

void PortableTester::paintEvent(QPaintEvent *pEvent) {
	QPainter* pPainter = new QPainter(this);
	pPainter->drawPixmap(rect(), QPixmap(":/images/PTFront.png"));
	delete pPainter;

	QStylePainter painter(this);
	QColor l_objColor;
	painter.drawPixmap(0, 0, QPixmap(":/images/PTFront.png"));
	if (hasFocus()) {
		QStyleOptionFocusRect option;
		option.initFrom(this);
		option.backgroundColor = palette().dark().color();
		painter.drawPrimitive(QStyle::PE_FrameFocusRect, option);
	}
	QWidget::paintEvent(pEvent);
}
void PortableTester::UnHide() {
	//    qDebug() << "UnHide";
	l_objMainView->InitHeaderView(0, "PT6-QUTE");
	l_objMainView->showWindows();
	baseFrame->setVisible(true);
	showButtons();
	isWindowOpen = false;
	IPT->removePlugin(myID);
	myID=0;
}

