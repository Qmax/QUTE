#include "selectprobe.h"
#include "ui_selectprobe.h"
#include "visettings.h"

SelectProbe::SelectProbe(QWidget *parent, VIModel *pObjSubject) :
    QDialog(parent,Qt::WindowSystemMenuHint),
    ui(new Ui::SelectProbe)
{
    ui->setupUi(this);
    setWindowModality(Qt::WindowModal);
    selectProbeState=true;


    //Backpanel Interface Plugin
    //QPluginLoader loader2("libBackPlaneInterface.so",this);
    //IBackPlane = qobject_cast<IntefaceBackPlane*>(loader2.instance());
    QPluginLoader loader4("libQmaxPTInterface.so",this);
    INumberPanel=qobject_cast<IQmaxNumberPanel*>(loader4.instance());
    ILineEdit = qobject_cast<IQmaxLineEdit*> (loader4.instance());

    QPluginLoader loader6("libPTKeyEventInterfaces.so",this);
    IPTKeyEvent = qobject_cast<PTEventInterface*>(loader6.instance());

//    m_strProbe = pLabel;
//    m_obVImodel = pObj;
    //m_objPTLibrary = pObjPTL;
//    m_opt1 = pOpt1;
//    m_opt2 = pOpt2;

    m_objProbeSubject = pObjSubject;
    m_objProbeSubject->registerObserver(3,this);


    connect(this,SIGNAL(closed()),this,SLOT(closeWindow()));
    connect(ui->lstProbes,SIGNAL(itemClicked(QListWidgetItem*)),this,SLOT(selectPacakage(QListWidgetItem*)));
    m_objThresholdEdit = ILineEdit->QmaxLineEdit(0,this);
    m_objThresholdEdit->setGeometry(250,92,80,40);
    m_objThresholdEdit->setText("5 %");
    //m_obVImodel->setThreshold(5.0);
    m_objProbeSubject->setProbeThreshold(5.0);
    m_objProbeSubject->setProbeDialog(1,0);
    connect(m_objThresholdEdit,SIGNAL(focussed(bool)),this,SLOT(callThresHoldEdit()));
    ui->optAverage->setChecked(true);
    ui->optAll->setChecked(true);
    //m_obVImodel->setACFIndex(4);
    //m_obVImodel->setComparisonFlag(false);
    setFocus();
    ui->lstProbes->setCurrentRow(0);
//    qDebug() << "probe Reference" << this;

     IPTKeyEvent->InvokeGPIOEvent(this,"/dev/input/event2","pt_kpp",&m_nPTKeyCode);
     ui->grpReferenceProbes->setVisible(false);
     ui->optRefProbe1->setChecked(true);
     m_objProbeSubject->setProbeDialog(4,0);
    //setWindowModality(Qt::WindowModal);

}
void SelectProbe::closeWindow(){

}
void SelectProbe::closeEvent(QCloseEvent *eve)
{
	qDebug()<<"inherted event";
	emit dialogClosed();
	eve->accept();
}
void SelectProbe::showProbeWindow()
{
	show();
}
void SelectProbe::customEvent(QEvent *e) {
	if(selectProbeState){
		if(e->type() == ((QEvent::Type)5678)) {

				doPTKeyFunction();
		}
		qDebug() << "Custom Event Probe Dialog";
		QEvent(e->type());
	}
}
void SelectProbe::doPTKeyFunction() {
	if(m_nPTKeyCode==2){
		this->close();
	}
	if(m_nPTKeyCode==9){
		if(ui->lstProbes->currentRow()==0){
			ui->lstProbes->setCurrentRow(1);
			ui->grpComparison->setDisabled(true);
			m_objThresholdEdit->setDisabled(true);
		}
		else{
			ui->lstProbes->setCurrentRow(0);
			ui->grpComparison->setDisabled(false);
			m_objThresholdEdit->setDisabled(false);
		}
		ui->lstProbes->setFocus();
	}
	else if(m_nPTKeyCode==10){
		if(ui->lstProbes->currentRow()==1){
			ui->lstProbes->setCurrentRow(0);
			ui->grpComparison->setDisabled(false);
			m_objThresholdEdit->setDisabled(false);
		}
		else{
			ui->lstProbes->setCurrentRow(1);
			ui->grpComparison->setDisabled(true);
			m_objThresholdEdit->setDisabled(true);
		}
		ui->lstProbes->setFocus();
	}
	else if(m_nPTKeyCode==11){
		if(QApplication::focusWidget()==ui->lstProbes){
			if(ui->grpComparison->isEnabled())
				ui->optLinear->setFocus();
			else
				ui->butOK->setFocus();
		}
		else if(QApplication::focusWidget()==ui->optLinear)
			ui->optAverage->setFocus();
		else if(QApplication::focusWidget()==ui->optAverage)
			m_objThresholdEdit->setFocus();
		else if(QApplication::focusWidget()==m_objThresholdEdit)
			ui->butOK->setFocus();
		else if(QApplication::focusWidget()==ui->butOK)
			ui->lstProbes->setFocus();
	}
	else if(m_nPTKeyCode==12){
	if(QApplication::focusWidget()==ui->butOK){
		if(ui->grpComparison->isEnabled())
			m_objThresholdEdit->setFocus();
		else
			ui->lstProbes->setFocus();
	}
	else if(QApplication::focusWidget()==m_objThresholdEdit)
		ui->optAverage->setFocus();
	else if(QApplication::focusWidget()==ui->optAverage)
		ui->optLinear->setFocus();
	else if(QApplication::focusWidget()==ui->optLinear)
		ui->lstProbes->setFocus();
	else if(QApplication::focusWidget()==ui->lstProbes)
		ui->butOK->setFocus();
	}
	else if(m_nPTKeyCode==13){
		if(QApplication::focusWidget()==ui->optLinear)
			ui->optLinear->animateClick(1);
		else if(QApplication::focusWidget()==ui->optAverage)
			ui->optAverage->animateClick(1);
		else if(QApplication::focusWidget()==ui->butOK)
			ui->butOK->animateClick(1);
	}
}
void SelectProbe::callThresHoldEdit()
{
        if(m_objThresholdEdit->hasFocus())
        {
                openNumKBPanel(2);
                m_nLineEditIndex = 0;
        }
}

void SelectProbe::on_optLinear_clicked()
{
//	m_obVImodel->setComparisonFlag(true);
	m_objProbeSubject->setProbeDialog(1,1);
}

void SelectProbe::on_optAverage_clicked()
{
//	m_obVImodel->setComparisonFlag(false);
	m_objProbeSubject->setProbeDialog(1,0);
}

void SelectProbe::openNumKBPanel(short int pValue)
{
//    typedef QWidget* (*pf2)(short int,QWidget*);
//    pf2 getNumKBPanel = (pf2)m_objPTLibrary->resolve("getNumKBPanel");
    QWidget *w = INumberPanel->getNumKBPanel(pValue,this);
    w->setWindowFlags(Qt::WindowCloseButtonHint|Qt::Dialog);
    w->show();
}

void SelectProbe::receiveValue(double pValue)
{
	Q_UNUSED(pValue);
//	m_obVImodel->setThreshold(pValue);
}

void SelectProbe::receiveValue(unsigned int pValue)
{
	m_objThresholdEdit->setText(QString::number(pValue, 10)+" %");
	m_objThresholdEdit->setFocusPolicy(Qt::NoFocus);
	m_objProbeSubject->setProbeThreshold((double)pValue);
}


SelectProbe::~SelectProbe()
{
	qDebug() << "Destructor SelectProbe";
//	IBackPlane->closeObject();
    delete ui;
}

void SelectProbe::hideEvent(QHideEvent *eve)
{
//	qDebug() << "Inside Select Probe Hide Event"<< eve->type();
	eve->ignore();

}

void SelectProbe::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    qDebug() << "Inside QProbe Dialog Change Event Type:" << e->type();
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }


}
void SelectProbe::selectPacakage(QListWidgetItem* pItem)
{
	 QModelIndex l_nIndex;
	 l_nIndex = ui->lstProbes->currentIndex();
	 if(l_nIndex.row()==0){
//		 m_strProbe->setText("SINGLE");
		//ui->grpComparison->setDisabled(false);
		m_objThresholdEdit->setDisabled(false);
		ui->chkCommonGnd->setDisabled(true);
		ui->grpReferenceProbes->setVisible(false);
		ui->grpComparison->setVisible(true);

	 }
	 else if(l_nIndex.row()==1){
  		    ui->grpReferenceProbes->setVisible(true);
  		    ui->grpReferenceProbes->setGeometry(166,10,261,81);
		    ui->grpComparison->setVisible(false);
		    //m_objThresholdEdit->setDisabled(true);
		    ui->chkCommonGnd->setDisabled(false);
//		 m_strProbe->setText("DUAL");
	 }
	 else if(l_nIndex.row()==2){
		    ui->grpComparison->setDisabled(false);
		    m_objThresholdEdit->setDisabled(false);
//		 m_strProbe->setText("DUAL");
	 }
}



QString SelectProbe::getProbeData() const
{
    return m_strSelectedProbe;
}

void SelectProbe::on_optResistance_clicked()
{
//	m_obVImodel->setACFIndex(0);
}

void SelectProbe::on_optCapcitance_clicked()
{
        //m_obVImodel->setACFIndex(1);
}

void SelectProbe::on_optInductance_clicked()
{
        //m_obVImodel->setACFIndex(2);
}
void SelectProbe::on_optDiode_clicked()
{
        //m_obVImodel->setACFIndex(3);
}

void SelectProbe::on_optAll_clicked()
{
        //m_obVImodel->setACFIndex(4);
}



void SelectProbe::on_butAdvSetup_clicked()
{
	VISettings *objnewSettings = new VISettings();
	objnewSettings->setGeometry(100,100,400,300);
	objnewSettings->show();
}

void SelectProbe::on_chkCommonGnd_clicked()
{
	if(ui->chkCommonGnd->isChecked() == true)
		m_objProbeSubject->setProbeDialog(3,1);
	else
		m_objProbeSubject->setProbeDialog(3,0);
}

void SelectProbe::on_butOK_clicked()
{
    QListWidgetItem* pItem = ui->lstProbes->currentItem();
       QVariant l_nData = pItem->data(Qt::DisplayRole);
       m_strSelectedProbe = l_nData.toString();
       if(m_strSelectedProbe == "SINGLE")
       {
               m_objProbeSubject->setProbeDialog(0,0);
       }
       else if(m_strSelectedProbe == "DUAL")
       {
               m_objProbeSubject->setProbeDialog(0,1);

               m_objThresholdEdit->setDisabled(true);
               if(ui->opRefProbe2->isChecked())
            	   m_objProbeSubject->setProbeDialog(4,1);
               else if(ui->optRefProbe1->isChecked())
            	   m_objProbeSubject->setProbeDialog(4,0);
//		   if(ui->chkCommonGnd->isChecked() == true)
//				m_objProbeSubject->setProbeDialog(3,1);
//			else
//				m_objProbeSubject->setProbeDialog(3,0);
       }
       else if(m_strSelectedProbe == "EXT_PRB")
       {
    	   m_objProbeSubject->setProbeDialog(0,2);
       }
       this->close();

       m_objProbeSubject->notifyProbeOserver();

}
