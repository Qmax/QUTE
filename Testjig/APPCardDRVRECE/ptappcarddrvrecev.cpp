#include "ptappcarddrvrecev.h"
#include "ui_ptappcarddrvrecev.h"
#include <QMessageBox>
using namespace APPCARD_DETAILS;

PtAppCardDrvRecev::PtAppCardDrvRecev(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PtAppCardDrvRecev)
{
    ui->setupUi(this);
    m_nDRGSR=m_nDRSER=m_nDSAR=0;
    m_nR1CR=m_nR2CR=m_nICMMGR=0;
    m_strRelayFile = "";
    InitialiseHWLibraries();
    enableRichGUI();
}

void PtAppCardDrvRecev::InitialiseHWLibraries()
{
    QPluginLoader loaderApp("libPTApplicationcardInterface.so", this);
    IAppCard = qobject_cast<IApplicationCardInterface*> (loaderApp.instance());
    qDebug() << "Appcard" << IAppCard;
    IAppCard->setDeviceName(SLOT0);
    IAppCard->enumerateAPPCard();

    QPluginLoader loader2("libBackPlaneInterface.so", this);
    IBackPlane = qobject_cast<IntefaceBackPlane*> (loader2.instance());
    IBackPlane->InitializeBpObject();

    QPluginLoader loader4("libQmaxPTInterface.so", this);
    ILineEdit = qobject_cast<IQmaxLineEdit*> (loader4.instance());
    IPTLibrary = qobject_cast<IQmaxPTLibrary*> (loader4.instance());
    INumberPanel = qobject_cast<IQmaxNumberPanel*> (loader4.instance());

    m_objLE_ADDR = ILineEdit->QmaxLineEdit(0, ui->grpGeneral);
    m_objLE_ADDR->setGeometry(38, 34, 80, 30);

    m_objLE_DATA = ILineEdit->QmaxLineEdit(1, ui->grpGeneral);
    m_objLE_DATA->setGeometry(128, 34, 80, 30);

    connect(m_objLE_ADDR, SIGNAL(focussed(bool)), this, SLOT(callAddressEdit()));
    connect(m_objLE_DATA, SIGNAL(focussed(bool)), this, SLOT(callDataEdit()));
    m_objLE_ADDR->setStyleSheet(
                    "border-width: 2px;border-style: outset;border-color: gray; border-radius: 1px;  padding: 0 8px;     background: black;     selection-background-color: yellow;   color:white;     font: bold 14px;");
    m_objLE_DATA->setStyleSheet(
                    "border-width: 2px;border-style: outset;border-color: gray; border-radius: 1px;  padding: 0 8px;     background: black;     selection-background-color: yellow;   color:white;     font: bold 14px;");

    }
void PtAppCardDrvRecev::enableRichGUI(){
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

	ui->groupBox->setParent(m_objWidget);
	ui->groupBox_4->setParent(m_objWidget);

	ui->groupBox->setGeometry(10,0,781,191);
	ui->groupBox_4->setGeometry(10,190,781,301);

	ui->lineEdit->setVisible(false);
	ui->lineEdit_2->setVisible(false);
}
void PtAppCardDrvRecev::callAddressEdit() {
        if (m_objLE_ADDR->hasFocus()) {
                openNumKBPanel(0);
                m_nLineEditIndex = 0;
        }

}

void PtAppCardDrvRecev::callDataEdit() {
        if (m_objLE_DATA->hasFocus()) {
                openNumKBPanel(0);
                m_nLineEditIndex = 1;
        }
}

void PtAppCardDrvRecev::openNumKBPanel(short int pValue) {
        QWidget *w = INumberPanel->getNumKBPanel(pValue, this);
        w->setWindowFlags(Qt::WindowCloseButtonHint | Qt::Dialog);
        w->show();
}

void PtAppCardDrvRecev::receiveValue(unsigned int pValue) {
        qDebug() << "Receive Value:" << hex << pValue;
        QMessageBox msgBox;
        if (pValue < 0) {
                msgBox.setText("Negative Value not allowed.");
                msgBox.show();
                return;
        }
        if (m_nLineEditIndex == 0) {
                m_objLE_ADDR->setText(QString::number(pValue, 16));
                m_nAddress = pValue;
        }
        else if (m_nLineEditIndex == 1) {
                m_objLE_DATA->setText(QString::number(pValue, 16));
                m_nData = pValue;
        }
}



void PtAppCardDrvRecev::receiveValue(QString pValue) {
        Q_UNUSED(pValue)
        qDebug() << m_nLineEditIndex << "pValue:" << pValue;
}

void PtAppCardDrvRecev::receiveValue(double pValue) {
        //qDebug() << m_nLineEditIndex << "pValue:" << pValue;
}
PtAppCardDrvRecev::~PtAppCardDrvRecev()
{
    delete ui;
}

void PtAppCardDrvRecev::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void PtAppCardDrvRecev::on_butDriveRelay_clicked()
{
    //IAppCard->setDriveSourceAmplitudeRegister(m_objDSAR);
    IAppCard->writeRegister(m_nDSAR,PT_APPCARD_MODULES::PT_DRRLY_APPCARD_DSAR);
    IAppCard->writeRegister(m_nDRSER,PT_APPCARD_MODULES::PT_DRRLY_APPCARD_DRSER);
    IAppCard->writeRegister(m_nDRGSR,PT_APPCARD_MODULES::PT_DRRLY_APPCARD_DRGSR);
}

void PtAppCardDrvRecev::on_butReceiveRelay_clicked()
{
    IAppCard->writeRegister(m_nR1CR,PT_APPCARD_MODULES::PT_RECERLY_APPCARD_R1CR);
    IAppCard->writeRegister(m_nR2CR,PT_APPCARD_MODULES::PT_RECERLY_APPCARD_R2CR);
    IAppCard->writeRegister(m_nICMMGR,PT_APPCARD_MODULES::PT_RECERLY_APPCARD_ICMMGR);
}

void PtAppCardDrvRecev::on_chkVIS_clicked()
{

    if(ui->chkVIS->isChecked()){
        m_nDSAR |= 1<<3;
       // m_objDSAR.m_bVIS = true;
    }
    else{
        m_nDSAR = m_nDSAR & 0XFFF7;
      //  m_objDSAR.m_bVIS = false;
    }
    qDebug() << "VIS:"<<m_nDSAR;
}

void PtAppCardDrvRecev::on_cmbIRS_currentIndexChanged(int index)
{
    unsigned short l_nIRSArray[4] = {3,2,1,0};
    m_nDSAR = m_nDSAR & 0xFFF9;
    qDebug() << "Clear IRS:"<<m_nDSAR<<index;
    m_nDSAR |= l_nIRSArray[index]<<1 ;
    qDebug() << "IRS:"<<m_nDSAR;
}

void PtAppCardDrvRecev::on_chkSRCN_clicked()
{
    if(ui->chkSRCN->isChecked()){
        m_nDSAR |= 1;
       // m_objDSAR.m_bSRCN = true;
        ui->grpSI->setEnabled(false);
    }
    else{
        m_nDSAR = m_nDSAR & 0XFFFE;
       // m_objDSAR.m_bSRCN = false;
        ui->grpSI->setEnabled(true);
    }
    qDebug() << "VIS:"<<m_nDSAR;

}

void PtAppCardDrvRecev::on_cmbSourceSelection_currentIndexChanged(int index)
{
    unsigned short l_nDriveArray[4]={0x0,0x4,0x2,0x07};
    m_nDRSER = l_nDriveArray[index];
    qDebug()<<"DRSER:"<<m_nDRSER;
    // Drive Appcard with 0x34 l_nDriveArray[index]
}

void PtAppCardDrvRecev::on_cmbVISelection_currentIndexChanged(int index)
{
    unsigned short l_nVIVoltArray[5]= {0,1,2,4,8};
    m_nDRGSR = m_nDRGSR & 0xFFF0;
    m_nDRGSR|=l_nVIVoltArray[index];
    qDebug()<<"DRGSR:"<<m_nDRGSR;
}

void PtAppCardDrvRecev::on_chkSlotOffsetEN_clicked()
{
    if(ui->chkSlotOffsetEN->isChecked())
        m_nDRGSR|=1<<4;
    else
        m_nDRGSR = m_nDRGSR & 0xFFEF;
    qDebug()<<"DRGSR:"<<m_nDRGSR;
}

void PtAppCardDrvRecev::on_cmbBPSourceImpedance_currentIndexChanged(int index)
{
    unsigned int l_nRegisterAddress = 0x26, l_nRegisterData = index;
        IBackPlane->writeBackPlaneRegister(l_nRegisterData, l_nRegisterAddress); // Initialize BP Source Impedance Selection}
}

void PtAppCardDrvRecev::on_chkRece1HSHA_clicked()
{
    if(ui->chkRece1HSHA->isChecked())
    {
        m_nR1CR |= 1;
    }
    else
    {
        m_nR1CR &=0xFFFE;
    }
}

void PtAppCardDrvRecev::on_chkRece1HAAC_clicked()
{
    if(ui->chkRece1HAAC->isChecked())
    {
        m_nR1CR |= 1<<1;
    }
    else
    {
        m_nR1CR &=0xFFFD;
    }

}

void PtAppCardDrvRecev::on_chkRece1RMSIN_clicked()
{
    if(ui->chkRece1RMSIN->isChecked())
    {
        m_nR1CR |= 1<<2;
    }
    else
    {
        m_nR1CR &=0xFFFB;
    }

}

void PtAppCardDrvRecev::on_chkRece1RMSGAIN_clicked()
{
    if(ui->chkRece1RMSGAIN->isChecked())
    {
        m_nR1CR |= 1<<3;
    }
    else
    {
        m_nR1CR &=0xFFF7;
    }

}
void PtAppCardDrvRecev::on_chkRece1RMSCAVG_clicked()
{
    if(ui->chkRece1RMSCAVG->isChecked())
    {
        m_nR1CR |= 1<<4;
    }
    else
    {
        m_nR1CR &=0xFFEF;
    }

}


void PtAppCardDrvRecev::on_chkRece1HAIPSEL_clicked()
{
    if(ui->chkRece1HAIPSEL->isChecked())
    {
        m_nR1CR |= 1<<5;
    }
    else
    {
        m_nR1CR &=0xFFDF;
    }

}

void PtAppCardDrvRecev::on_chkRece1HSVI_clicked()
{
    if(ui->chkRece1HSVI->isChecked())
    {
        m_nR1CR |= 1<<6;
    }
    else
    {
        m_nR1CR &=0xFFBF;
    }

}

void PtAppCardDrvRecev::on_cmbR1Coupling_currentIndexChanged(int index)
{
    unsigned l_nHSCoupling[3]={0,1,2};
    m_nR1CR = m_nR1CR & 0xFE7F;
    m_nR1CR |= l_nHSCoupling[index] << 7;
}

void PtAppCardDrvRecev::on_chkRece2HSHA_clicked()
{
    if(ui->chkRece2HSHA->isChecked())
    {
        m_nR2CR |= 1;
    }
    else
    {
        m_nR2CR &=0xFFFE;
    }

}

void PtAppCardDrvRecev::on_chkRece2ICMEN_clicked()
{
    if(ui->chkRece2ICMEN->isChecked())
    {
        m_nR2CR |= 1<<1;
    }
    else
    {
        m_nR2CR &=0xFFFD;
    }

}

void PtAppCardDrvRecev::on_chkRece2HAAC_clicked()
{
    if(ui->chkRece2HAAC->isChecked())
    {
        m_nR2CR |= 1<<2;
    }
    else
    {
        m_nR2CR &=0xFFFD;
    }

}

void PtAppCardDrvRecev::on_chkRece2RMSIN_clicked()
{
    if(ui->chkRece2RMSIN->isChecked())
    {
        m_nR2CR |= 1<<3;
    }
    else
    {
        m_nR2CR &=0xFFF7;
    }
}

void PtAppCardDrvRecev::on_chkRece2RMSGAIN_clicked()
{
    if(ui->chkRece2RMSGAIN->isChecked())
    {
        m_nR2CR |= 1<<4;
    }
    else
    {
        m_nR2CR &=0xFFEF;
    }
}

void PtAppCardDrvRecev::on_chkRece2RMSCAVG_clicked()
{
    if(ui->chkRece2RMSCAVG->isChecked())
    {
        m_nR2CR |= 1<<5;
    }
    else
    {
        m_nR2CR &=0xFFDF;
    }

}


void PtAppCardDrvRecev::on_chkRece2HAIPSEL_clicked()
{
    if(ui->chkRece2HAIPSEL->isChecked())
    {
        m_nR2CR |= 1<<6;
    }
    else
    {
        m_nR2CR &=0xFFBF;
    }
}

void PtAppCardDrvRecev::on_cmbR2Coupling_currentIndexChanged(int index)
{
    unsigned l_nHSCoupling[3]={0,1,2};
    m_nR2CR = m_nR2CR & 0xFE7F;
    m_nR2CR |= l_nHSCoupling[index] << 7;

}

void PtAppCardDrvRecev::on_chkICMGAIN_clicked()
{
    if(ui->chkICMGAIN->isChecked())
    {
        m_nICMMGR|=1<<3;
    }
    else
    {
        m_nICMMGR &=0xFFF7;
    }
}

void PtAppCardDrvRecev::on_chkICMIASEL_clicked()
{
    if(ui->chkICMIASEL->isChecked())
    {
        m_nICMMGR|=1<<4;
    }
    else
    {
        m_nICMMGR &=0xFFEF;
    }

}

void PtAppCardDrvRecev::on_chkICMBCAPSEL_clicked()
{
    if(ui->chkICMBCAPSEL->isChecked())
    {
        m_nICMMGR|=1<<5;
    }
    else
    {
        m_nICMMGR &=0xFFDF;
    }
}



void PtAppCardDrvRecev::on_cmbICMRange_currentIndexChanged(int index)
{
    m_nICMMGR = m_nICMMGR & 0xFFF8;
    m_nICMMGR |= index;
}

void PtAppCardDrvRecev::on_butAppRead_clicked()
{
    m_objLE_DATA->setText(QString::number(
                            IAppCard->readRegister(m_nAddress), 16));
}

void PtAppCardDrvRecev::on_butAppWrite_clicked()
{
 IAppCard->writeRegister(m_nData,m_nAddress);
}
