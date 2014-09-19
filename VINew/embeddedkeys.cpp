#include "embeddedkeys.h"

EmbeddedKeys::EmbeddedKeys(QWidget *parent,VIModel *pObj)
    : QMainWindow(parent,Qt::WindowSystemMenuHint)
{
	ui.setupUi(this);
        m_objSubject = pObj;
        m_objSubject->registerObserver(1,this);
    QPluginLoader loader6("libPTKeyEventInterfaces.so",this);
    IPTKeyEvent = qobject_cast<PTEventInterface*>(loader6.instance());

	IPTKeyEvent->InvokeGPIOEvent(this,"/dev/input/event2","pt_kpp",&m_nPTKeyCode);
	hightlight(ui.butLeft);
	whoIsActive=LEFT;
	ui.lstKeyOperations->setCurrentRow(0);
	ui.lstKeyOperations->setFocus();
	initialiseKeyCombinations();
}
void EmbeddedKeys::customEvent(QEvent *e)
{
//	QMessageBox msg;
	if(e->type() == ((QEvent::Type)5678))	{
		doPTKeyFunction();
	}
        QEvent(e->type());
}
void EmbeddedKeys::hightlight(QWidget* but){
	ui.butClose->setStyleSheet("QPushButton {color:black;font:14px;border: 2px solid #8f8f91;border-radius: 20px;background-color: qlineargradient(x1:0, y1: 0, x2: 0, y2: 1,stop: 0 #f6f7fa, stop: 1 #dadbde);min-width: 80px;}QPushButton:pressed {background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #dadbde, stop: 1 #f6f7fa);}QPushButton:flat {border: none; }QPushButton:default {border-color:navy; }");
	ui.butLeft->setStyleSheet("QPushButton {color:black;font:12px;border: 2px solid #8f8f91;border-radius: 20px;background-color: qlineargradient(x1:0, y1: 0, x2: 0, y2: 1,stop: 0 #f6f7fa, stop: 1 #dadbde);min-width: 80px;}QPushButton:pressed {background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #dadbde, stop: 1 #f6f7fa);}QPushButton:flat {border: none; }QPushButton:default {border-color:navy; }");
	ui.butMiddle->setStyleSheet("QPushButton {color:black;font:12px;border: 2px solid #8f8f91;border-radius: 20px;background-color: qlineargradient(x1:0, y1: 0, x2: 0, y2: 1,stop: 0 #f6f7fa, stop: 1 #dadbde);min-width: 80px;}QPushButton:pressed {background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #dadbde, stop: 1 #f6f7fa);}QPushButton:flat {border: none; }QPushButton:default {border-color:navy; }");
	ui.butRigth->setStyleSheet("QPushButton {color:black;font:12px;border: 2px solid #8f8f91;border-radius: 20px;background-color: qlineargradient(x1:0, y1: 0, x2: 0, y2: 1,stop: 0 #f6f7fa, stop: 1 #dadbde);min-width: 80px;}QPushButton:pressed {background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #dadbde, stop: 1 #f6f7fa);}QPushButton:flat {border: none; }QPushButton:default {border-color:navy; }");

	but->setStyleSheet("QPushButton {color:white;font:12px;border: 2px solid white;border-radius: 20px;background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #6a6ea9, stop: 1 #888dd9);}QPushButton:pressed {background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #dadbde, stop: 1 #f6f7fa);}QPushButton:flat {border: none; }QPushButton:default {border-color:navy; }");
}

void EmbeddedKeys::initialiseKeyCombinations()
{
	// Function Defines Key combinations

	// 1. VOL/FREQ/IMP - INC/DEC
	QList<QString> l_lstIncrDecKeys;
	l_lstIncrDecKeys.insert(0,"INCREASE");
	l_lstIncrDecKeys.insert(1,"DECREASE");
	QList<QString> l_lstStoreDeleteKeys;
	l_lstStoreDeleteKeys.insert(0,"STORE");
	l_lstStoreDeleteKeys.insert(1,"DELETE");

	m_lstKeyCombinations.insert("RUN/STOP",l_lstStoreDeleteKeys);
	m_lstKeyCombinations.insert("RUN",l_lstStoreDeleteKeys);
	m_lstKeyCombinations.insert("STOP",l_lstStoreDeleteKeys);

	m_lstKeyCombinations.insert("VOLTAGE",l_lstIncrDecKeys);
	m_lstKeyCombinations.insert("FREQUENCY",l_lstIncrDecKeys);
	m_lstKeyCombinations.insert("IMPEDANCE",l_lstIncrDecKeys);
	m_lstKeyCombinations.insert("VOL/FQ/IMP",l_lstIncrDecKeys);

	ui.cmbCombinationKeys->addItems(m_lstKeyCombinations.keys());
	//ui.cmbCombinationKeys->setForegroundRole(Qt::white);
	ui.cmbCombinationKeys->setCurrentIndex(3);

}

void EmbeddedKeys::on_cmbCombinationKeys_currentIndexChanged(QString pString)
{
	ui.lstKeyOperations->clear();
	ui.lstKeyOperations->addItem(pString);
	ui.lstKeyOperations->addItems(m_lstKeyCombinations.value(pString));
	ui.lstKeyOperations->setCurrentRow(0);
	ui.lstKeyOperations->setFocus();

}
void EmbeddedKeys::doPTKeyFunction()
{
//	qDebug()<<"PT-Key Fucntion:VI_Embedded_Probe - Value:"<<m_nPTKeyCode;
	switch(whoIsActive){
	case 0:
		//qDebug()<<"whoIsActive"<<"LEFT";
		break;
	case 1:
		//qDebug()<<"whoIsActive"<<"MIDDLE";
		break;
	case 2:
		//qDebug()<<"whoIsActive"<<"RIGHT";
		break;
	}

		 if(m_nPTKeyCode==2){				//ESC
		        this->close();
		}

		 else if(m_nPTKeyCode==9){		//UP
			 if(ui.lstKeyOperations->hasFocus()){
				if(ui.lstKeyOperations->currentRow()>0&&ui.lstKeyOperations->currentRow()<=10){
					ui.lstKeyOperations->setCurrentRow(ui.lstKeyOperations->currentRow()-1);
					 ui.lstKeyOperations->setFocus();
				}
			 }
				else if(ui.butLeft->hasFocus()){
					ui.butRigth->setFocus();
					hightlight(ui.butRigth);
					whoIsActive=RIGHT;
				}
				else if(ui.butRigth->hasFocus()){
					ui.butMiddle->setFocus();
					hightlight(ui.butMiddle);
					whoIsActive=MIDDLE;

				}
				else if(ui.butMiddle->hasFocus()){
					ui.butLeft->setFocus();
					hightlight(ui.butLeft);
					whoIsActive=LEFT;

				}
		 }

		 else if(m_nPTKeyCode==10){	//DOWN
			 if(ui.lstKeyOperations->hasFocus()){
				if(ui.lstKeyOperations->currentRow()>=0&&ui.lstKeyOperations->currentRow()<10){
					ui.lstKeyOperations->setCurrentRow(ui.lstKeyOperations->currentRow()+1);
					ui.lstKeyOperations->setFocus();
				}
			 }
				else if(ui.butLeft->hasFocus()){
					ui.butMiddle->setFocus();
					hightlight(ui.butMiddle);
					whoIsActive=MIDDLE;
					//ui.butMiddle->setStyleSheet(" color:white;background-color:qlineargradient(x1:0,y1:0,x2:0,y2:1,stop:0#18080a,stop:1#16777a); border:6pxsolidwhite;border-style:sunken;border-width:2px;border-radius6px;border-color:white;	" );
				}
				else if(ui.butMiddle->hasFocus()){
					ui.butRigth->setFocus();
					hightlight(ui.butRigth);
					whoIsActive=RIGHT;
				}
				else if(ui.butRigth->hasFocus()){
					ui.butLeft->setFocus();
					hightlight(ui.butLeft);
					whoIsActive=LEFT;
				}
		 }

		 else if(m_nPTKeyCode==11){	//RIGHT
			 if(QApplication::focusWidget()==ui.lstKeyOperations){

				 if(ui.lblLeftText->text()==""||whoIsActive==LEFT){
						 	 ui.butLeft->setFocus();
						 	hightlight(ui.butLeft);
						 	whoIsActive=LEFT;
				 }
				 else if(ui.lblMiddleText->text()==""||whoIsActive==MIDDLE){
					 	 	 ui.butMiddle->setFocus();
					 	 	hightlight(ui.butMiddle);
					 	 	whoIsActive=MIDDLE;
				 }
				 else if(ui.lblRightText->text()==""||whoIsActive==RIGHT){
					 	 	 ui.butRigth->setFocus();
					 	 	hightlight(ui.butRigth);
					 	 	whoIsActive=RIGHT;
				 }
				 else{
				 	 	 	 ui.butLeft->setFocus();
				 	 	 	hightlight(ui.butLeft);
				 	 	 	whoIsActive=LEFT;
				 }
			 }
			 else if(ui.butLeft->hasFocus()||ui.butMiddle->hasFocus()||ui.butRigth->hasFocus()){
				 ui.butClose->setFocus();
				 hightlight(ui.butClose);
			 }
		 }
		 else if(m_nPTKeyCode==12){	//LEFT
			 if(QApplication::focusWidget()==ui.butClose){
				 if(whoIsActive==LEFT){
					 ui.butLeft->setFocus();
					 hightlight(ui.butLeft);
					 whoIsActive=LEFT;
				 }
				 else if(whoIsActive==MIDDLE){
					 ui.butMiddle->setFocus();
					 hightlight(ui.butMiddle);
					 whoIsActive=MIDDLE;
				 }
				 else{
					 ui.butRigth->setFocus();
					 hightlight(ui.butRigth);
					 whoIsActive=RIGHT;
				 }

			 }
			 else if(ui.butLeft->hasFocus()||ui.butMiddle->hasFocus()||ui.butRigth->hasFocus()){
				 ui.lstKeyOperations->setFocus();

			 }
			 else if(QApplication::focusWidget()==ui.lstKeyOperations){
				 ui.butClose->setFocus();
				 hightlight(ui.butClose);
			 }
		 }
		 else if(m_nPTKeyCode==13){	//ENTER
			 if(ui.butClose->hasFocus())
				 ui.butClose->animateClick(1);
			 else if(ui.butLeft->hasFocus())
				 ui.butLeft->animateClick(1);
			 else if(ui.butMiddle->hasFocus())
				 ui.butMiddle->animateClick(1);
			 else if(ui.butRigth->hasFocus())
				 ui.butRigth->animateClick(1);
			 else{
				 if(whoIsActive==LEFT)
					 ui.butLeft->animateClick(1);
				 else if(whoIsActive==MIDDLE)
					 ui.butMiddle->animateClick(1);
				 else
					 ui.butRigth->animateClick(1);
			 }
		 }
}

void EmbeddedKeys::clickedPRSCR()
{
	QPixmap Pix;
    Pix = QPixmap();
    //Pix = QPixmap::grabWidget(ui->FGSubwindow,0,0,800,600);
    Pix = QPixmap::grabWindow(this->parentWidget()->winId());
    Pix.save("EmbeddedKeys.jpg");
    QClipboard *board = QApplication::clipboard();
    board->setPixmap(Pix);
    QWidget::showFullScreen();
}
EmbeddedKeys::~EmbeddedKeys()
{
    qDebug() << "Embedded Key Destructor";

}
void EmbeddedKeys::on_butLeft_clicked()
{
    ui.lblLeftText->clear();
    QString l_strLeftKey = ui.lstKeyOperations->currentItem()->data(Qt::DisplayRole).toString();
    ui.lblLeftText->setText(l_strLeftKey);
    m_objSubject->setIndexTemplate(0,l_strLeftKey);
    hightlight(ui.butLeft);
}

void EmbeddedKeys::on_butMiddle_clicked()
{
    ui.lblMiddleText->clear();
    QString l_strMiddleKey = ui.lstKeyOperations->currentItem()->data(Qt::DisplayRole).toString();
    ui.lblMiddleText->setText(l_strMiddleKey);
    m_objSubject->setIndexTemplate(1,l_strMiddleKey);
    hightlight(ui.butMiddle);
}

void EmbeddedKeys::on_butRigth_clicked()
{
    ui.lblRightText->clear();
    QString l_strRigthKey = ui.lstKeyOperations->currentItem()->data(Qt::DisplayRole).toString();
    ui.lblRightText->setText(l_strRigthKey);
    m_objSubject->setIndexTemplate(2,l_strRigthKey);
    hightlight(ui.butRigth);
}

void EmbeddedKeys::on_butClose_clicked()
{
    //clickedPRSCR();
    this->close();
    m_objSubject->notifyEmbeddedKeysObserver();
}
