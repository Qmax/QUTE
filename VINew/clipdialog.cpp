#include "clipdialog.h"
#include "ui_clipdialog.h"

ClipDialog::ClipDialog(QWidget *parent, VIModel *pObjSubject) :
    QDialog(parent,Qt::WindowSystemMenuHint),
    ui(new Ui::ClipDialog)
{
    ui->setupUi(this);
    //qDebug()<<"DP-11";
    QPluginLoader loader4("libQmaxPTInterface.so", this);
    INumberPanel = qobject_cast<IQmaxNumberPanel*> (loader4.instance());
    ILineEdit = qobject_cast<IQmaxLineEdit*> (loader4.instance());
    QPluginLoader loader6("libPTKeyEventInterfaces.so",this);
    IPTKeyEvent = qobject_cast<PTEventInterface*>(loader6.instance());
    m_objClipDialogSubject = pObjSubject;
    m_objClipDialogSubject->registerObserver(2,this);

    m_objPinsEdit = ILineEdit->QmaxLineEdit(0,this);//new MyLineEdit(0,this);
    m_objPinsEdit->setGeometry(330,54,120,40);
    m_objPinsEdit->setFocusPolicy(Qt::NoFocus);

    m_objRefChannelEdit = ILineEdit->QmaxLineEdit(1,this);//new MyLineEdit(1,this);
    m_objRefChannelEdit->setGeometry(400,158,80,38);
    m_objThresholdEdit = ILineEdit->QmaxLineEdit(2,ui->grpCompare);
    m_objThresholdEdit->setGeometry(102,96,80,38);
    m_objThresholdEdit->setText("5");
    m_objClipDialogSubject->setClipThreshold(5.0);
    m_objClipDialogSubject->setChipDialog(5,0);
    //m_objProbeSubject->setProbeThreshold(5.0);
	//m_objProbeSubject->setProbeDialog(1,0);
	connect(m_objThresholdEdit,SIGNAL(focussed(bool)),this,SLOT(callThresHoldEdit()));
	ui->optAverage->setChecked(true);
//    m_objPinsEdit1 = ILineEdit->QmaxLineEdit(2,this);//new MyLineEdit(2,this);
//    m_objPinsEdit1->setGeometry(330,250,121,41);
//    m_objPinsEdit1->setVisible(false);
//    ui->objFixedOption->setCheckable(true);
//    m_objRefChannelEdit->setDisabled(true);
//    ui->listWidget->setCurrentRow(0);
    LoadClipDefaultValues();

//    connect(m_objPinsEdit,SIGNAL(focussed(bool)),this,SLOT(callPinsEdit()));
    connect(m_objRefChannelEdit,SIGNAL(focussed(bool)),this,SLOT(callRefChannelEdit()));
    connect(ui->listWidget,SIGNAL(itemClicked(QListWidgetItem*)),this,SLOT(selectClip(QListWidgetItem*)));
    IPTKeyEvent->InvokeGPIOEvent(this,"/dev/input/event2","pt_kpp",&m_nPTKeyCode);
    msgBoxLive=false;
    ui->chkStoponFail->setVisible(false);
    clipDialogState=true;	//added for PTkey

}

void ClipDialog::on_chkStoponFail_clicked()
{
	if(ui->chkStoponFail->isChecked()== true)
		m_objClipDialogSubject->setIndexTemplate(6,1);
	else
		m_objClipDialogSubject->setIndexTemplate(6,0);
}

void ClipDialog::LoadClipDefaultValues()
{
    ui->listWidget->setCurrentRow(m_objClipDialogSubject->getChipDialog(0));
    m_objPinsEdit->setText(QString::number(m_objClipDialogSubject->getChipDialog(1),10));
   if(m_objClipDialogSubject->getChipDialog(2) == 0)
   {
       ui->objFixedOption->setChecked(true);
       m_objRefChannelEdit->setText(QString::number(m_objClipDialogSubject->getChipDialog(3),10));
   }
   else
   {
       ui->objFixedOption_2->setChecked(true);
   }
   ui->lblCombinations->setText(QString::number(m_objClipDialogSubject->getChipDialog(4),10));
}

void ClipDialog::clickedPRSCR()
{
	QPixmap Pix;
    Pix = QPixmap();
    //Pix = QPixmap::grabWidget(ui->FGSubwindow,0,0,800,600);
    Pix = QPixmap::grabWindow(this->parentWidget()->winId());
    Pix.save("ClipDialog.jpg");
    QClipboard *board = QApplication::clipboard();
    board->setPixmap(Pix);
    QWidget::showFullScreen();
}
void ClipDialog::customEvent(QEvent *e)
{
	if(clipDialogState){
		QMessageBox msg;
		if(e->type() == ((QEvent::Type)5678))
		{

			doPTKeyFunction();
		}

		QEvent(e->type());
		qDebug() << "Custom Event Clip Dialog";

	}
}
void ClipDialog::doPTKeyFunction()
{
		 if(m_nPTKeyCode==2){				//ESC
		        ClipDialog::close();
		}

		 else if(m_nPTKeyCode==9){		//UP
			 if(msgBoxLive!=true){
//			 if(QApplication::focusWidget()==ui->listWidget)
				 	 if(ui->listWidget->currentRow()>0&&ui->listWidget->currentRow()<=3)
				 		 ui->listWidget->setCurrentRow(ui->listWidget->currentRow()-1);
				 	 ui->listWidget->setFocus();
			 }
		 }

		 else if(m_nPTKeyCode==10){	//DOWN
			 if(msgBoxLive!=true){
	//		 if(QApplication::focusWidget()==ui->listWidget)
				 	 if(ui->listWidget->currentRow()>=0&&ui->listWidget->currentRow()<3)
				 		 ui->listWidget->setCurrentRow(ui->listWidget->currentRow()+1);
				 	ui->listWidget->setFocus();
			 }
		 }

		 else if(m_nPTKeyCode==11){	//RIGHT
			 if(msgBoxLive!=true){
			 if(QApplication::focusWidget()==ui->listWidget)
				 	 m_objPinsEdit->setFocus();
			 else if(QApplication::focusWidget()==m_objPinsEdit)
				 	 ui->objFixedOption->setFocus();
			 else if(QApplication::focusWidget()==ui->objFixedOption)
				 	 ui->objFixedOption_2->setFocus();
			 else if(QApplication::focusWidget()==ui->objFixedOption_2){
				if(m_objRefChannelEdit->isEnabled())
					m_objRefChannelEdit->setFocus();
				else
					 ui->butOK->setFocus();
			 }
			 else if(QApplication::focusWidget()==m_objRefChannelEdit)
				 	 ui->butOK->setFocus();
			 else if(QApplication::focusWidget()==ui->butOK)
				 	 ui->butClose->setFocus();
			 else if(QApplication::focusWidget()==ui->butClose)
				 	 ui->listWidget->setFocus();
			 }
				else if(msgBoxLive==true){
					if(connectButton->hasFocus())
						abortButton->setFocus();
					else
						connectButton->setFocus();
					}
		 }
		 else if(m_nPTKeyCode==12){	//LEFT
			 if(msgBoxLive!=true){
			 if(QApplication::focusWidget()==ui->listWidget)
				 ui->butOK->setFocus();
			 else if(QApplication::focusWidget()==ui->butOK)
				 ui->butClose->setFocus();
			 else if(QApplication::focusWidget()==ui->butClose){
				if(m_objRefChannelEdit->isEnabled())
					m_objRefChannelEdit->setFocus();
				else
					ui->objFixedOption_2->setFocus();
			 }
			 else if(QApplication::focusWidget()==m_objRefChannelEdit)
				 ui->objFixedOption_2->setFocus();
			  else if(QApplication::focusWidget()==ui->objFixedOption_2)
				  ui->objFixedOption->setFocus();
			  else if(QApplication::focusWidget()==ui->objFixedOption)
				  ui->listWidget->setFocus();
			 }
				else if(msgBoxLive==true){
					if(connectButton->hasFocus())
						abortButton->setFocus();
					else
						connectButton->setFocus();
					}

		 }
		 else if(m_nPTKeyCode==13){	//ENTER
			 if(msgBoxLive!=true){
			 if(QApplication::focusWidget()==ui->objFixedOption)
				 ui->objFixedOption->animateClick(1);
			 else if(QApplication::focusWidget()==ui->objFixedOption_2)
				 ui->objFixedOption_2->animateClick(1);
			 else if(QApplication::focusWidget()==ui->butOK)
				 ui->butOK->animateClick(1);
			 else if(QApplication::focusWidget()==ui->butClose)
				 ui->butClose->animateClick(1);
			 }
			 else		if(msgBoxLive==true){
					if(connectButton->hasFocus())
						connectButton->animateClick(1);
					else
						abortButton->animateClick(1);
					//connectButton->animateClick(1);
					msgBoxLive=false;
				}
		 }
}
bool ClipDialog::showMessageBox(bool ok,bool cancel,QString text, QString okText="Ok",QString calcelText="Cancel")
{
//	QMessageBox *msgBox = new QMessageBox(this);
	msgBoxLive=true;
	msgBox = new QMessageBox(this);
//	QPushButton *connectButton,*abortButton;
	if(ok==true)
	{
		connectButton = msgBox->addButton(okText,QMessageBox::YesRole);
		connectButton->setFont(QFont("DejaVu Sans",20,50,false));
	}
	if(cancel == true)
	{
		abortButton = msgBox->addButton(calcelText,QMessageBox::NoRole);
		abortButton->setFont(QFont("DejaVu Sans",20,50,false));
	}
	msgBox->setFont(QFont("DejaVu Sans",15,50,false));
	msgBox->setIcon(QMessageBox::Information);
	msgBox->setStyleSheet("color : white;background-color :rgb(88,88,87,255);");
	msgBox->setWindowIcon(QIcon(":/image.png"));
	msgBox->setText(text);
	msgBox->exec();
	if (msgBox->clickedButton() == connectButton)//(l_bTrue == true)//
	 {
		return true;
	 }
	if(cancel == true)
		 if (msgBox->clickedButton() == abortButton) //(l_bTrue == false) //
		 {
			 return false;
		 }
	return true;
}
void ClipDialog::on_optLinear_clicked()
{
//	qDebug()<<"Envelop";
	m_objClipDialogSubject->setChipDialog(5,1);
}

void ClipDialog::on_optAverage_clicked()
{
//	qDebug()<<"Average";
	m_objClipDialogSubject->setChipDialog(5,0);
}
ClipDialog::~ClipDialog()
{
    delete ui;
}

void ClipDialog::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
    //qDebug() << "Inside QClip Dialog Change Event Type:" << e->type();

}


void ClipDialog::callPinsEdit()
{
        if(m_objPinsEdit->hasFocus())
        {
                openNumKBPanel(2);
                m_nLineEditIndex = 0;
        }
}

void ClipDialog::callThresHoldEdit()
{
    if(m_objThresholdEdit->hasFocus())
    {
            openNumKBPanel(2);
            m_nLineEditIndex = 2;
    }

}

void ClipDialog::callRefChannelEdit()
{
        if(m_objRefChannelEdit->hasFocus())
        {
                openNumKBPanel(2);
                m_nLineEditIndex = 1;
        }
}

void ClipDialog::selectClip(QListWidgetItem* pItem)
{
		Q_UNUSED(pItem);
        QModelIndex l_nIndex;
        l_nIndex = ui->listWidget->currentIndex();
        QString l_strClip ="";
        if( l_nIndex.row() == 0){
                m_nPins = 14;
        }
        else if ( l_nIndex.row() == 1)
        {
                m_nPins = 20;
        }
        else if ( l_nIndex.row() == 2)
        {
                m_nPins = 24;
        }
        else if ( l_nIndex.row() == 3)
        {
                m_nPins = 28;
        }
        m_objClipDialogSubject->setChipDialog(0,l_nIndex.row());
        m_objClipDialogSubject->setChipDialog(1,m_nPins);
        m_objPinsEdit->setText(QString::number(m_nPins,10));
        if(ui->objFixedOption->isChecked()== true)
        	on_objFixedOption_clicked();
        else if(ui->objFixedOption_2->isChecked() == true)
        	on_objFixedOption_2_clicked();
        //qDebug() << "Select Coloumn" << l_nIndex.column() << l_nIndex.row()<<m_nPins;

        //m_lblClip->setText(l_strClip);
}

void ClipDialog::openNumKBPanel(short int pValue)
{
//    typedef QWidget* (*pf2)(short int,QWidget*);
//    pf2 getNumKBPanel = (pf2)m_objPTLib->resolve("getNumKBPanel");

//    QWidget *w = INumberPanel->getNumKBPanel(pValue,this);
    QWidget *w = INumberPanel->getNumKBPanelIncDec(pValue,1,'N',99,1,this);
    w->setWindowFlags(Qt::WindowCloseButtonHint|Qt::Dialog);
    w->show();
}

void ClipDialog::on_butOK_clicked()
{
        //m_objVIModel->setProbeStatus("CLIP");

//        if(m_objVIModel->getPins() == 0 ) //&& m_objVIModel->getFixedReference() > 0)
//        {
//            showMessageBox(true,false,"Please Enter Pins.","OK");
//            return;
//
//        }
//        if(ui->objFixedOption->isChecked() && m_objVIModel->getFixedReference() ==0 )
//        {
//            showMessageBox(true,false,"Please Enter Fixed Reference Pins.","OK");
//            return;
//        }
//        m_grpClip->setEnabled(true);
        this->close();
        m_objClipDialogSubject->notifyClipObserver();
}

void ClipDialog::on_objFixedOption_clicked()
{
        //m_objVIModel->setPinCombStatus(true);
        m_objRefChannelEdit->setDisabled(false);
        m_objClipDialogSubject->setChipDialog(2,0);
        int l_nPins = m_objClipDialogSubject->getChipDialog(1)-1;
//        qDebug() << "Pin Combinations:"<< l_nPins;
        m_objClipDialogSubject->setChipDialog(4,l_nPins);
        ui->lblCombinations->setText(QString::number(l_nPins,10));
}

void ClipDialog::on_objFixedOption_2_clicked()
{
        //m_objVIModel->setPinCombStatus(false);
        m_objRefChannelEdit->setDisabled(true);
        m_objClipDialogSubject->setChipDialog(2,1);
        int l_nPins = (m_objClipDialogSubject->getChipDialog(1)*(m_objClipDialogSubject->getChipDialog(1)-1))/2;
//        qDebug() << "Pin Combinations:"<< l_nPins;
        m_objClipDialogSubject->setChipDialog(4,l_nPins);
        ui->lblCombinations->setText(QString::number(l_nPins,10));

        //m_objVIModel->generateMovingReference(m_objVIModel->getPins(),m_objVIModel->getFixedReference(),0);
        //ui->lblCombinations->setText(QString::number(m_objVIModel->getNoofCombinations(),10));
}

void ClipDialog::receiveValue(unsigned int pValue)
{
        if(m_nLineEditIndex ==0)
        {
                if(pValue%2 !=0)
                {
                        QMessageBox msgBox;
                        msgBox.setText("Enter Valid Pin Numbers.");
                        msgBox.exec();
                        return;

                }
                //qDebug() << "Pins:" << m_nPins << "Value:" <<pValue;

//		if(pValue < m_nPins)
//		{
//			QMessageBox msgBox;
//			msgBox.setText("Select Appropriate Clip for assigned pins.");
//			msgBox.exec();
//			return;
//		}
                m_objPinsEdit->setText(QString::number(pValue,10));
                m_objClipDialogSubject->setChipDialog(1,pValue);
                on_objFixedOption_clicked();
              //  m_objPinsEdit->setFocusPolicy(Qt::NoFocus);
               // m_objVIModel->setPins(pValue);
             //   m_objVIModel->generateChannels(pValue);
        }
        else if(m_nLineEditIndex ==1)
        {
                if(pValue<=0)
                {
                        QMessageBox msgBox;
                        msgBox.setText("Enter Valid Reference Pin Number.");
                        msgBox.exec();
                        return;
                }
//                if(pValue > m_objVIModel->getPins()){
//                        QMessageBox msgBox;
//                        msgBox.setText("Assigned Reference Pin is Incorrect.");
//                        msgBox.exec();
//                        return;
//
//                }
                m_objRefChannelEdit->setText(QString::number(pValue,10));
                m_objClipDialogSubject->setChipDialog(3,pValue);
            //    m_objRefChannelEdit->setFocusPolicy(Qt::NoFocus);
                //m_objVIModel->setFixedReference((short int)pValue);

//                if(m_objVIModel->getPinCombStatus() == true)
//                    {
//                        m_objVIModel->generateFixedReference(m_objVIModel->getPins(),m_objVIModel->getFixedReference(),0);
//                        ui->lblCombinations->setText(QString::number(m_objVIModel->getNoofCombinations(),10));
//                    }
//                    else
//                    {
//                        m_objVIModel->generateMovingReference(m_objVIModel->getPins(),m_objVIModel->getFixedReference(),0);
//                        ui->lblCombinations->setText(QString::number(m_objVIModel->getNoofCombinations(),10));
//                    }
        }
        else if(m_nLineEditIndex == 2)
    	{
    		m_objThresholdEdit->setText(QString::number(pValue,10));
    		//m_objThresholdEdit->setFocusPolicy(Qt::NoFocus);
    		m_objClipDialogSubject->setClipThreshold(pValue);
    	}

}

void ClipDialog::on_butClose_clicked()
{
	clipDialogState=false;
    this->close();
}

void ClipDialog::receiveValue(double pValue)
{
	Q_UNUSED(pValue);
}



