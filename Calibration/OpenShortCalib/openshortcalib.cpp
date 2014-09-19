#include "openshortcalib.h"
#include "ui_openshortcalib.h"
#include <QPropertyAnimation>

OpenShortCalib::OpenShortCalib(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OpenShortCalib)
{
    ui->setupUi(this);

    QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry");
    animation->setDuration(10000);
    animation->setStartValue(QRect(150, 350, 400, 100));
    animation->setEndValue(QRect(150, 115, 400, 300));
    animation->setEasingCurve(QEasingCurve::Linear);
    animation->setDuration(300);
    animation->start();

    HardwareInitialization();
    Initialization();
}
void OpenShortCalib::HardwareInitialization(){
    QPluginLoader loaderBck("libBackPlaneInterface.so",this);
    IBackPlane = qobject_cast<IntefaceBackPlane*>(loaderBck.instance());
    IBackPlane->InitializeBpObject();

    QPluginLoader loaderApp("libPTApplicationcardInterface.so", this);
    IAppCard = qobject_cast<IApplicationCardInterface*> (loaderApp.instance());
    IAppCard->setDeviceName(SLOT0);
    IAppCard->enumerateAPPCard();

    hwInterface=new HardwareInterface(IAppCard);
    hwInterface->Init();
    hwInterface->Configure();
    hwInterface->Update();
    IAppCard->setSPIAppendBit(0x8000);
    hwInterface->setAmplitude(0.1);
    hwInterface->SingleContinuous(CONTINUOUS);

    IAppCard->setSPIAppendBit(0xC000);
    m_objAD7190Component = new AD7190Component(IAppCard);
    m_objAD7190Component->resetADC(1);
    m_objAD7190Component->writeADCConfigurationRegister(1,0x110);
    m_objAD7190Component->writeADCModeRegister(1,0x80060);

    m_objAD7190Component->resetADC(2);
    m_objAD7190Component->writeADCConfigurationRegister(2,0x110);
    m_objAD7190Component->writeADCModeRegister(2,0x80060);

    IAppCard->writeRegister(0x02,0x36);
    IAppCard->writeRegister(0x06,0x38);
    IAppCard->writeRegister(0x1,0x16);
    IAppCard->writeRegister(0x7,0x34);
    IAppCard->writeRegister(0,0x3A);

    ADCtimer = new QTimer(this);
    connect(ADCtimer, SIGNAL(timeout()), this, SLOT(readADC()));

}
void OpenShortCalib::Initialization(){

    micro=QChar(0x00B5); ohms=QChar(0x2126);
    kiloOhms="K"+ohms;
    picoFarad="pF";nanoFarad="nF";microFarad=micro+"F";milliFarad="mF";
    microHenry=micro+"H";milliHenry="mH";Henry="H";

    on_cmbCompnt_currentIndexChanged(0);    //Select Resistance Range by Default
    R_Index=0;    C_Index=0;    L_Index=0;
    m_nICMMGR=0;    m_nFrequency=1000;
    m_dOffset=0.0;    m_dNull=0.0;


}
void OpenShortCalib::initialiseFeedBackResistance(){
    // Resistance Feedback
    m_lstRFResistance.insert(0,10.0);
    m_lstRFResistance.insert(1,100.0);
    m_lstRFResistance.insert(2,1000.0);
    m_lstRFResistance.insert(3,10000.0);
    m_lstRFResistance.insert(4,100000.0);
    m_lstRFResistance.insert(5,1000000.0);

    //Inductance Feedback
    m_lstRFInductance.insert(0,100.0);			//30uH
    m_lstRFInductance.insert(1,10.0);			//300uH
    m_lstRFInductance.insert(2,100.0);			//3mH
    m_lstRFInductance.insert(3,1000.0);			//30mH
    m_lstRFInductance.insert(4,1000.0);			//300mH
    m_lstRFInductance.insert(5,1000.0);			//3H
    m_lstRFInductance.insert(6,10000.0);		//30H

    //Capcitance Feedback
    m_lstRFCapcitance.insert(0,1000000.0);
    m_lstRFCapcitance.insert(1,1000000.0);
    m_lstRFCapcitance.insert(2,100000.0);
    m_lstRFCapcitance.insert(3,10000.0);
    m_lstRFCapcitance.insert(4,10000.0);
    m_lstRFCapcitance.insert(5,1000.0);
    m_lstRFCapcitance.insert(6,10.0);
    m_lstRFCapcitance.insert(7,10.0);
    m_lstRFCapcitance.insert(8,10.0);
}
void OpenShortCalib::readADC(){
    short int l_nResoulution = 23;
    double l_nGain = 1.0, l_nVREF = 2.048;
    double l_nFactor1 = 0.0, l_nFactor2 = 0.0;

    m_nADC1Voltage=m_objAD7190Component->readADCDataRegister(1) & 0xFFFFFF;
    l_nFactor1 = (m_nADC1Voltage / pow(2, l_nResoulution)) - 1;
    l_nFactor2 = (l_nGain / l_nVREF);
    l_nAIN1 = l_nFactor1 / l_nFactor2;

    m_nADC2Voltage=m_objAD7190Component->readADCDataRegister(2) & 0xFFFFFF;
    l_nFactor1 = (m_nADC2Voltage / pow(2, l_nResoulution)) - 1;
    l_nFactor2 = (l_nGain / l_nVREF);
    l_nAIN2 = l_nFactor1 / l_nFactor2;

    if(ui->cmbCompnt->currentIndex()==2)
            m_nImpedanceValue=m_lstRFCapcitance.value(C_Index);
    if(ui->cmbCompnt->currentIndex()==1)
            m_nImpedanceValue=m_lstRFInductance.value(L_Index);
    if(ui->cmbCompnt->currentIndex()==0)
            m_nImpedanceValue=m_lstRFResistance.value(R_Index);

    double l_nImpedanceValue=m_nImpedanceValue;
    double l_n1 = (l_nImpedanceValue/l_nAIN2);
    m_nResistance = (l_n1 * l_nAIN1);
    double l_RMSDiv =(2 * (3.14) *m_nFrequency * m_nResistance);
    m_nCapacitance = 1 / l_RMSDiv;
    double l_RMSDiv1 =(2 * (3.14) *m_nFrequency);
    m_nInductance = m_nResistance / l_RMSDiv1;

    if(ui->cmbCompnt->currentIndex()==0){
    GetDisplayResistance((m_nResistance),m_lstRFResistance.value(R_Index));
    }

    else if(ui->cmbCompnt->currentIndex()==2){
    GetDisplayCapcitance(m_nCapacitance,C_Index);
    }

    else if(ui->cmbCompnt->currentIndex()==1){
     GetDisplayInductance(m_nInductance,L_Index);
    }
}
void OpenShortCalib::GetDisplayResistance(double pResistanceValue,double pRangeValue)
{
        pResistanceValue=pResistanceValue+m_dOffset;
        if(m_bNull==true){
                pResistanceValue=pResistanceValue-m_dNull;
        }
        qDebug()<<"Resistance:"<<pResistanceValue<<"Range:"<<pRangeValue;

        QString l_strResistanceValue("");
        if(pResistanceValue <1000.0)
        {
                if(pRangeValue == 10.0 || pRangeValue==10000.0)
                {
                        l_strResistanceValue = QString::number(pResistanceValue,'f',2) + ohms;
                }
                else if(pRangeValue == 100.0 || pRangeValue==100000.0)
                {
                        l_strResistanceValue = QString::number(pResistanceValue,'f',1) + ohms;
                }
                else
                {
                        l_strResistanceValue = QString::number(pResistanceValue,'f',3) + ohms;
                }
        }
        else if(pResistanceValue >=1000.0 && pResistanceValue<1000000)
        {
                if(pRangeValue == 1000.0 || pRangeValue==1000000.0)
                {
                        l_strResistanceValue = QString::number((pResistanceValue/1000.0),'f',3) + kiloOhms;
                }
                else if(pRangeValue == 10000.0 || pRangeValue==10.0)
                {
                        l_strResistanceValue = QString::number((pResistanceValue/1000.0),'f',2) + kiloOhms;
                }
                else if(pRangeValue == 100000.0 || pRangeValue==100.0)
                {
                        l_strResistanceValue = QString::number((pResistanceValue/1000.0),'f',1) + kiloOhms;
                }
        }
        else if(pResistanceValue >= 1000000.0 )
        {
                l_strResistanceValue = QString::number((pResistanceValue/1000000.0),'f',3) + "M"+ohms;

        }
        ui->leMeasured->setText(l_strResistanceValue);
}

void OpenShortCalib::GetDisplayCapcitance(double p_nData,short int p_nRange)
{
        p_nData=p_nData+m_dOffset;
        if(m_bNull==true){
                p_nData=p_nData-m_dNull;
        }
        qDebug()<<fixed<<"Capacitance:"<<p_nData<<"Range:"<<p_nRange;


        QString l_sDisplayData("");
        if (p_nRange == 0)
        {
                p_nData = p_nData * 1000000000000.0;
                l_sDisplayData = QString::number((p_nData),'f',2) + picoFarad;
        }
        else if (p_nRange == 1)
        {
                p_nData = p_nData * 1000000000000.0;
                l_sDisplayData = QString::number((p_nData),'f',2) + picoFarad;
        }
        else if (p_nRange == 2)
        {
                p_nData = p_nData * 1000000000.0;
                l_sDisplayData = QString::number((p_nData),'f',2) + nanoFarad;
        }
        else if (p_nRange == 3)
        {
                p_nData = p_nData * 1000000000.0;
                l_sDisplayData = QString::number((p_nData),'f',2) + nanoFarad;
        }
        else if (p_nRange == 4)
        {
                p_nData = p_nData * 1000000000.0;
                l_sDisplayData = QString::number((p_nData),'f',2) + nanoFarad;
        }
        else if (p_nRange == 5)
        {
                p_nData = p_nData * 1000000.0;
                l_sDisplayData = QString::number((p_nData),'f',2) + microFarad;
        }
        else if (p_nRange == 6)
        {
                p_nData = p_nData * 1000000.0;
                l_sDisplayData = QString::number((p_nData),'f',2) + microFarad;
        }
        else if (p_nRange == 7)
        {
                p_nData = p_nData * 1000000.0;
                l_sDisplayData = QString::number((p_nData),'f',2) + microFarad;
        }
        else if (p_nRange == 8)
        {
                p_nData = p_nData * 1000.0;
                l_sDisplayData = QString::number((p_nData),'f',2) + microFarad;
        }
        ui->leMeasured->setText(l_sDisplayData);
}
void OpenShortCalib::GetDisplayInductance(double p_nData,short int p_nRange)
{
        p_nData=p_nData+m_dOffset;
        if(m_bNull==true){
                p_nData=p_nData-m_dNull;
        }
        qDebug()<<"Inductance:"<<p_nData<<"Range:"<<p_nRange;

        QString l_sDisplayData("");
        if (p_nRange == 0) // 300nH - 3uH
        {
                p_nData = p_nData * 1000000000;
                l_sDisplayData = QString::number((p_nData),'f',1) + "n"+Henry;
        }
        else if(p_nRange == 1) // 3uH - 30uH
        {
                p_nData = p_nData * 1000000;
                l_sDisplayData = QString::number((p_nData),'f',2) + microHenry;
        }
        else if(p_nRange == 2) // 30uH - 300 uH
        {
                p_nData = p_nData * 1000000;
                l_sDisplayData = QString::number((p_nData),'f',2) + microHenry;
        }
        else if(p_nRange == 3) // 300uH - 3mH
        {
                p_nData = p_nData * 1000000;
                l_sDisplayData = QString::number((p_nData),'f',2) + microHenry;
        }
        else if(p_nRange == 4) // 3mH - 30mH
        {
                p_nData = p_nData * 1000;
                l_sDisplayData = QString::number((p_nData),'f',2) + milliHenry;
        }
        else if(p_nRange == 5) // 30mH - 300mH
        {
                p_nData = p_nData * 1000;
                l_sDisplayData = QString::number((p_nData),'f',2) + milliHenry;
        }
        else if(p_nRange == 6) // 300mH - 3H
        {
                p_nData = p_nData * 1000;
                l_sDisplayData = QString::number((p_nData),'f',2) + milliHenry;
        }
        else if(p_nRange == 7) // 3H - 30H
        {
                l_sDisplayData = QString::number((p_nData),'f',2) + Henry;
        }
        ui->leMeasured->setText(l_sDisplayData);
}
OpenShortCalib::~OpenShortCalib()
{
    delete ui;
}

void OpenShortCalib::changeEvent(QEvent *e)
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


void OpenShortCalib::on_pbClose_clicked()
{
    this->close();
}

void OpenShortCalib::on_cmbCompnt_currentIndexChanged(int index)
{
    switch(index){
    case 0:
        ui->cmbRRange->setVisible(true);ui->cmbLRange->setVisible(false);ui->cmbCRange->setVisible(false);
        break;
    case 1:
        ui->cmbRRange->setVisible(false);ui->cmbLRange->setVisible(true);ui->cmbCRange->setVisible(false);
        break;
    case 2:
        ui->cmbRRange->setVisible(false);ui->cmbLRange->setVisible(false);ui->cmbCRange->setVisible(true);
        break;
    }
}

void OpenShortCalib::on_chkOpen_clicked(bool checked)
{

}

void OpenShortCalib::on_chkShort_clicked(bool checked)
{

}

void OpenShortCalib::on_chkLoad_clicked(bool checked)
{

}

void OpenShortCalib::on_chkCalibrated_clicked(bool checked)
{

}

void OpenShortCalib::on_cmbCRange_currentIndexChanged(int index)
{
    switch(index){
    case 0:
        C_Index=0;
        m_nICMMGR = m_nICMMGR & 0xFFF8;
        m_nICMMGR |= 5;
        IAppCard->writeRegister(m_nICMMGR,0x3A);
        hwInterface->setFrequency(2400);
        m_nFrequency=2400;
        break;
    case 1:
        C_Index=1;
        m_nICMMGR = m_nICMMGR & 0xFFF8;
        m_nICMMGR |= 5;
        IAppCard->writeRegister(m_nICMMGR,0x3A);
        hwInterface->setFrequency(2400);
        m_nFrequency=2400;
        break;
    case 2:
        C_Index=2;
        m_nICMMGR = m_nICMMGR & 0xFFF8;
        m_nICMMGR |= 4;
        IAppCard->writeRegister(m_nICMMGR,0x3A);
        hwInterface->setFrequency(2400);
        m_nFrequency=2400;
        break;
    case 3:
        C_Index=3;
        m_nICMMGR = m_nICMMGR & 0xFFF8;
        m_nICMMGR |= 3;
        IAppCard->writeRegister(m_nICMMGR,0x3A);
        hwInterface->setFrequency(2400);
        m_nFrequency=2400;
        break;
    case 4:
        C_Index=4;
        m_nICMMGR = m_nICMMGR & 0xFFF8;
        m_nICMMGR |= 3;
        IAppCard->writeRegister(m_nICMMGR,0x3A);
        hwInterface->setFrequency(454);
        m_nFrequency=454;
        break;
    case 5:
        C_Index=5;
        m_nICMMGR = m_nICMMGR & 0xFFF8;
        m_nICMMGR |= 2;
        IAppCard->writeRegister(m_nICMMGR,0x3A);
        hwInterface->setFrequency(454);
        m_nFrequency=454;
        break;
    case 6:
        C_Index=6;
        m_nICMMGR = m_nICMMGR & 0xFFF8;
        m_nICMMGR |= 0;
        IAppCard->writeRegister(m_nICMMGR,0x3A);
        hwInterface->setFrequency(2200);
        m_nFrequency=2200;
        break;
    case 7:
        C_Index=7;
        m_nICMMGR = m_nICMMGR & 0xFFF8;
        m_nICMMGR |= 0;
        IAppCard->writeRegister(m_nICMMGR,0x3A);
        hwInterface->setFrequency(220);
        m_nFrequency=220;
        break;
    case 8:
        C_Index=8;
        m_nICMMGR = m_nICMMGR & 0xFFF8;
        m_nICMMGR |= 0;
        IAppCard->writeRegister(m_nICMMGR,0x3A);
        hwInterface->setFrequency(44);
        m_nFrequency=44;
        break;

    }
}

void OpenShortCalib::on_cmbLRange_currentIndexChanged(int index)
{
    switch(index){
    case 0:
        L_Index=0;
        m_nICMMGR = m_nICMMGR & 0xFFF8;
        m_nICMMGR |= 1;
        IAppCard->writeRegister(m_nICMMGR,0x3A);
        hwInterface->setFrequency(100000);
        m_nFrequency=100000;

        IAppCard->writeRegister(1,0x16);
        break;
    case 1:
        L_Index=1;
        m_nICMMGR = m_nICMMGR & 0xFFF8;
        m_nICMMGR |= 0;//changed
        IAppCard->writeRegister(m_nICMMGR,0x3A);
        hwInterface->setFrequency(7812);
//	m_nFrequency=390625;
        m_nFrequency=7812;

        IAppCard->writeRegister(1,0x16);
        break;
    case 2:
        L_Index=2;
        m_nICMMGR = m_nICMMGR & 0xFFF8;
        m_nICMMGR |= 1;//changed
        IAppCard->writeRegister(m_nICMMGR,0x3A);
        hwInterface->setFrequency(4000);
//	m_nFrequency=390625;
        m_nFrequency=4000;

        IAppCard->writeRegister(1,0x16);
        break;
    case 3:
        L_Index=3;
        m_nICMMGR = m_nICMMGR & 0xFFF8;
        m_nICMMGR |= 2;//changed
        IAppCard->writeRegister(m_nICMMGR,0x3A);
        hwInterface->setFrequency(1200);
        m_nFrequency=1200;

        IAppCard->writeRegister(0,0x16);
        IBackPlane->writeBackPlaneRegister(0x4,0x26);
        break;
    case 4:
        L_Index=4;
        m_nICMMGR = m_nICMMGR & 0xFFF8;
        m_nICMMGR |= 2;
        IAppCard->writeRegister(m_nICMMGR,0x3A);
        hwInterface->setFrequency(1000);
        m_nFrequency=1000;

        IAppCard->writeRegister(0,0x16);
        IBackPlane->writeBackPlaneRegister(0x4,0x26);
        break;
    case 5:
        L_Index=5;
        m_nICMMGR = m_nICMMGR & 0xFFF8;
        m_nICMMGR |= 2;
        IAppCard->writeRegister(m_nICMMGR,0x3A);
        hwInterface->setFrequency(20);
        m_nFrequency=20;

        IAppCard->writeRegister(0,0x16);
        IBackPlane->writeBackPlaneRegister(0x3,0x26);
        break;
    case 6:
        L_Index=6;
        m_nICMMGR = m_nICMMGR & 0xFFF8;
        m_nICMMGR |= 3;
        IAppCard->writeRegister(m_nICMMGR,0x3A);
        hwInterface->setFrequency(20);
        m_nFrequency=20;

        IAppCard->writeRegister(0,0x16);
        IBackPlane->writeBackPlaneRegister(0x6,0x26);
        break;
    }
}

void OpenShortCalib::on_cmbRRange_currentIndexChanged(int index)
{
    switch(index){
    case 0:
        R_Index=0;
        m_nICMMGR = m_nICMMGR & 0xFFF8;
        m_nICMMGR |= 0;
        IAppCard->writeRegister(m_nICMMGR,0x3A);
        hwInterface->setFrequency(1000);
        m_nFrequency=1000;
        break;

    case 1:
        R_Index=1;
        m_nICMMGR = m_nICMMGR & 0xFFF8;
        m_nICMMGR |= 1;
        IAppCard->writeRegister(m_nICMMGR,0x3A);
        break;

    case 2:
        R_Index=2;
        m_nICMMGR = m_nICMMGR & 0xFFF8;
        m_nICMMGR |= 2;
        IAppCard->writeRegister(m_nICMMGR,0x3A);
        break;

    case 3:
        R_Index=3;
        m_nICMMGR = m_nICMMGR & 0xFFF8;
        m_nICMMGR |= 3;
        IAppCard->writeRegister(m_nICMMGR,0x3A);
        break;

    case 4:
        R_Index=4;
        m_nICMMGR = m_nICMMGR & 0xFFF8;
        m_nICMMGR |= 4;
        IAppCard->writeRegister(m_nICMMGR,0x3A);
        break;

    case 5:
        R_Index=5;
        m_nICMMGR = m_nICMMGR & 0xFFF8;
        m_nICMMGR |= 5;
        IAppCard->writeRegister(m_nICMMGR,0x3A);
        break;

    }
}


void OpenShortCalib::on_pbMeasure_clicked()
{
    IAppCard->startDrive(1);
    ADCtimer->start(300);
}

void OpenShortCalib::on_pbStop_clicked()
{
    if(ADCtimer->isActive()){
            qDebug()<<"Stop Drive";
            IAppCard->stopDrive();
            ADCtimer->stop();
    }
}

void OpenShortCalib::on_pbCalibrate_clicked()
{

}

void OpenShortCalib::on_pbMeasure_pressed()
{
    ui->pbMeasure->setStyleSheet("QPushButton{color:white;border: 1px solid #2D5059;border-radius: 10px;background-color: qlineargradient(x1: 0, y1: 1, x2: 1, y2: 0,stop: 0 #3293DE,stop: 0.6 #3293DE, stop:1 #3293DE);min-width: 80px;font:bold 14px;}");
}

void OpenShortCalib::on_pbMeasure_released()
{
    ui->pbMeasure->setStyleSheet("QPushButton{color:white;border: 1px solid #2D5059;border-radius: 10px;background-color: qlineargradient(x1: 0, y1: 1, x2: 1, y2: 0,stop: 0 #1A74DB,stop: 0.6 #5293DE, stop:1 #FFFFFF);min-width: 80px;font:12px;}");
}

void OpenShortCalib::on_pbStop_pressed()
{
    ui->pbStop->setStyleSheet("QPushButton{color:white;border: 1px solid #2D5059;border-radius: 10px;background-color: qlineargradient(x1: 0, y1: 1, x2: 1, y2: 0,stop: 0 #3293DE,stop: 0.6 #3293DE, stop:1 #3293DE);min-width: 80px;font:bold 14px;}");

}

void OpenShortCalib::on_pbStop_released()
{
    ui->pbStop->setStyleSheet("QPushButton{color:white;border: 1px solid #2D5059;border-radius: 10px;background-color: qlineargradient(x1: 0, y1: 1, x2: 1, y2: 0,stop: 0 #1A74DB,stop: 0.6 #5293DE, stop:1 #FFFFFF);min-width: 80px;font:12px;}");

}

void OpenShortCalib::on_pbCalibrate_pressed()
{
    ui->pbCalibrate->setStyleSheet("QPushButton{color:white;border: 1px solid #2D5059;border-radius: 10px;background-color: qlineargradient(x1: 0, y1: 1, x2: 1, y2: 0,stop: 0 #3293DE,stop: 0.6 #3293DE, stop:1 #3293DE);min-width: 80px;font:bold 14px;}");

}

void OpenShortCalib::on_pbCalibrate_released()
{
    ui->pbCalibrate->setStyleSheet("QPushButton{color:white;border: 1px solid #2D5059;border-radius: 10px;background-color: qlineargradient(x1: 0, y1: 1, x2: 1, y2: 0,stop: 0 #1A74DB,stop: 0.6 #5293DE, stop:1 #FFFFFF);min-width: 80px;font:12px;}");

}

void OpenShortCalib::on_pbClose_pressed()
{
    ui->pbClose->setStyleSheet("QPushButton{color:white;border: 1px solid #2D5059;border-radius: 10px;background-color: qlineargradient(x1: 0, y1: 1, x2: 1, y2: 0,stop: 0 #3293DE,stop: 0.6 #3293DE, stop:1 #3293DE);min-width: 80px;font:bold 14px;}");

}

void OpenShortCalib::on_pbClose_released()
{
    ui->pbClose->setStyleSheet("QPushButton{color:white;border: 1px solid #2D5059;border-radius: 10px;background-color: qlineargradient(x1: 0, y1: 1, x2: 1, y2: 0,stop: 0 #1A74DB,stop: 0.6 #5293DE, stop:1 #FFFFFF);min-width: 80px;font:12px;}");

}
