/*
 * hy3131calibration.cpp
 *
 *  Created on: 06-Mar-2014
 *      Author: Ravivarman.R
 */
#include "hy3131calibration.h"
#include "ui_hy3131calibration.h"

HY3131Calibration::HY3131Calibration(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HY3131Calibration)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);

    ADCTimer = new QTimer(this);
    connect(ADCTimer, SIGNAL(timeout()), this, SLOT(ADCRead()));

    QPluginLoader loaderApp("libPTApplicationcardInterface.so", this);
    IAppCard = qobject_cast<IApplicationCardInterface*> (loaderApp.instance());
    IAppCard->setDeviceName(SLOT0);
    IAppCard->enumerateAPPCard();

    QPluginLoader loader4("libQmaxPTInterface.so", this);
    ILineEdit = qobject_cast<IQmaxLineEdit*> (loader4.instance());
    INumberPanel = qobject_cast<IQmaxNumberPanel*> (loader4.instance());

    QPluginLoader loader5("libHY3131DMMLib.so", this);
    hy3131dmm = qobject_cast<IHY3131DMMLibInterface*> (loader5.instance());

    ui->leOffsetValue->setVisible(false);
    objOffsetValue = ILineEdit->QmaxLineEdit(0, ui->CalibBox);
    objOffsetValue->setGeometry(90,117,206,30);
    objOffsetValue->setStyleSheet(ui->leOffset->styleSheet());
    connect(objOffsetValue, SIGNAL(focussed(bool)), this, SLOT(callOffsetEdit()));

    ui->leMaxValue->setVisible(false);
    objMaxValue = ILineEdit->QmaxLineEdit(1, ui->CalibBox);
    objMaxValue->setGeometry(80,226,217,30);
    objMaxValue->setStyleSheet(ui->leMaxValue->styleSheet());
    connect(objMaxValue, SIGNAL(focussed(bool)), this, SLOT(callMaxEdit()));

    ui->cmbComponent->addItem("Select...");
    ui->cmbComponent->addItem(QIcon(QPixmap(":/Images/R1.png")),"Resistance");
    ui->cmbComponent->addItem(QIcon(QPixmap(":/Images/dc.png")),"DC Voltage");
    ui->cmbComponent->addItem(QIcon(QPixmap(":/Images/ac.png")),"AC Volatge");
    ui->cmbComponent->addItem(QIcon(QPixmap(":/Images/dc.png")),"DC Current");
    ui->cmbComponent->addItem(QIcon(QPixmap(":/Images/ac.png")),"AC Current");
    ui->cmbComponent->addItem(QIcon(QPixmap(":/Images/D1.png")),"Diode");
    ui->cmbComponent->addItem(QIcon(QPixmap(":/Images/C1.png")),"Capacitor");
    ui->cmbComponent->addItem(QIcon(QPixmap(":/Images/sp.png")),"Beep");
    ui->cmbComponent->addItem(QIcon(QPixmap(":/Images/freq.png")),"Frequency");


    //Read Gain & Offset from file~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    bool ok=true;
    int index=0;

    QFile file("/home/HY3131/GainOffset2.dat");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
            return;
    while (!file.atEnd()) {

            QByteArray line = file.readLine();
            QList<QByteArray> data = line.split('\t');

            if (data[0].endsWith('\n'))
                    data[0].chop(1);
            if (data[1].endsWith('\n'))
                    data[1].chop(1);
            if (data[2].endsWith('\n'))
                    data[2].chop(1);

            m_strRange[index]=data[0];
            m_nGain[index]=data[1].toDouble(&ok);
            m_nOffset[index]=data[2].toDouble(&ok);
            index++;
    }
    file.close();
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    //enableDisable(0,false);
    //enableDisable(1,false);
    //enableDisable(2,false);
    //enableDisable(3,false);
    //enableDisable(4,false);
}
void HY3131Calibration::enableDisable(char group, bool state){
    switch(group){
    case 0:
        ui->lblRange->setEnabled(state);
        ui->cmbRange->setEnabled(state);
        break;
    case 1:
        ui->lblOffsetInfo->setEnabled(state);
        ui->lblOffsetValue->setEnabled(state);
        objOffsetValue->setEnabled(state);
        ui->lblOffsetMeasured->setEnabled(state);
        ui->leOffsetMeasured->setEnabled(state);
        ui->pbMeasureMin->setEnabled(state);
        ui->pbStopMin->setEnabled(state);
        break;
    case 2:
        ui->lblMaxInfo->setEnabled(state);
        ui->lblMaxValue->setEnabled(state);
        objMaxValue->setEnabled(state);
        ui->lblMaxMeasured->setEnabled(state);
        ui->leMaxMeasured->setEnabled(state);
        ui->pbMeasureMax->setEnabled(state);
        ui->pbStopMax->setEnabled(state);
        break;
    case 3:
        ui->lblGain->setEnabled(state);
        ui->leGain->setEnabled(state);
        ui->lblOffset->setEnabled(state);
        ui->leOffset->setEnabled(state);
        break;
    case 4:
        ui->lblCalibrated->setEnabled(state);
        ui->leCalibrated->setEnabled(state);
        ui->pbMeasureCalibrated->setEnabled(state);
        break;
    }
}

HY3131Calibration::~HY3131Calibration()
{
    delete ui;
}

void HY3131Calibration::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void HY3131Calibration::on_exitBut_clicked()
{
    this->close();
}

void HY3131Calibration::on_cmbComponent_currentIndexChanged(int index)
{
    stopADC();
    ui->cmbRange->clear();
    switch(index){
    case 0:
         break;
    case 1:
         ui->cmbRange->addItem("50E");
         ui->cmbRange->addItem("500E");
         ui->cmbRange->addItem("5KE");
         ui->cmbRange->addItem("50KE");
         ui->cmbRange->addItem("500KE");
         ui->cmbRange->addItem("5ME");
         ui->cmbRange->addItem("50ME");
        break;
    case 2:
    case 3:
        ui->cmbRange->addItem("50mV");
        ui->cmbRange->addItem("500mV");
        ui->cmbRange->addItem("5V");
        ui->cmbRange->addItem("50V");
        ui->cmbRange->addItem("500V");
        ui->cmbRange->addItem("1000V");
        break;
    case 4:
    case 5:
    	ui->cmbRange->addItem("500uA");
    	ui->cmbRange->addItem("5mA");
        ui->cmbRange->addItem("50mA");
        ui->cmbRange->addItem("500mA");
        ui->cmbRange->addItem("3A");
        break;
    case 6:
        ui->cmbRange->addItem("Diode");
        break;
    case 7:
        break;
    case 8:
        ui->cmbRange->addItem("Continuity");
        break;

    }
    if(ui->cmbComponent->currentIndex()!=0){
        //enableDisable(0,true);
        //enableDisable(1,true);
    }
    else{
        //enableDisable(0,false);
        //enableDisable(1,false);
        //enableDisable(2,false);
        //enableDisable(3,false);
        //enableDisable(4,false);
    }
}

void HY3131Calibration::on_cmbRange_currentIndexChanged(int index)
{
    stopADC();
    switch(ui->cmbComponent->currentIndex()){
    case 1:{
        switch(index){
        case 0:
            ui->lblOffsetInfo->setText("Short the Probes and Click Measure");
            ui->lblMaxInfo->setText("Connect 50 ohms and Click Measure");
            m_nMacroValue=R50E;
            break;
        case 1:
            ui->lblOffsetInfo->setText("Short the Probes and Click Measure");
            ui->lblMaxInfo->setText("Connect 500 ohms and Click Measure");
            m_nMacroValue=R500E;
            break;
        case 2:
            ui->lblOffsetInfo->setText("Short the Probes and Click Measure");
            ui->lblMaxInfo->setText("Connect 5K ohms and Click Measure");
            m_nMacroValue=R5K;
            break;
        case 3:
            ui->lblOffsetInfo->setText("Short the Probes and Click Measure");
            ui->lblMaxInfo->setText("Connect 50K ohms and Click Measure");
            m_nMacroValue=R50K;
            break;
        case 4:
            ui->lblOffsetInfo->setText("Short the Probes and Click Measure");
            ui->lblMaxInfo->setText("Connect 500K ohms and Click Measure");
            m_nMacroValue=R500K;
            break;
        case 5:
            ui->lblOffsetInfo->setText("Short the Probes and Click Measure");
            ui->lblMaxInfo->setText("Connect 5M ohms and Click Measure");
            m_nMacroValue=R5M;
            break;
        case 6:
            ui->lblOffsetInfo->setText("Short the Probes and Click Measure");
            ui->lblMaxInfo->setText("Connect 50M ohms and Click Measure");
            m_nMacroValue=R50M;
            break;
        }
    }
        break;
    case 2:{
            switch(index){
            case 0:
                ui->lblOffsetInfo->setText("Connect 0V DC and Click Measure");
                ui->lblMaxInfo->setText("Connect 50mV DC and Click Measure");
                m_nMacroValue=DC50mV;
                break;
            case 1:
                ui->lblOffsetInfo->setText("Connect 0V DC and Click Measure");
                ui->lblMaxInfo->setText("Connect 500mV DC and Click Measure");
                m_nMacroValue=DC500mV;
                break;
            case 2:
                ui->lblOffsetInfo->setText("Connect 0V DC and Click Measure");
                ui->lblMaxInfo->setText("Connect 5V DC and Click Measure");
                m_nMacroValue=DC5V;
                break;
            case 3:
                ui->lblOffsetInfo->setText("Connect 0V DC and Click Measure");
                ui->lblMaxInfo->setText("Connect 50V DC and Click Measure");
                m_nMacroValue=DC50V;
                break;
            case 4:
                ui->lblOffsetInfo->setText("Connect 0V DC and Click Measure");
                ui->lblMaxInfo->setText("Connect 500V DC and Click Measure");
                m_nMacroValue=DC500V;
                break;
            case 5:
                ui->lblOffsetInfo->setText("Connect 0V DC and Click Measure");
                ui->lblMaxInfo->setText("Connect 1000V DC and Click Measure");
                m_nMacroValue=DC1000V;
                break;
            }
        }
        break;
    case 3:{
            switch(index){
            case 0:
                ui->lblOffsetInfo->setText("Connect 0V AC and Click Measure");
                ui->lblMaxInfo->setText("Connect 50mV AC and Click Measure");
                m_nMacroValue=AC50mV;
                break;
            case 1:
                ui->lblOffsetInfo->setText("Connect 0V AC and Click Measure");
                ui->lblMaxInfo->setText("Connect 500mV AC and Click Measure");
                m_nMacroValue=AC500mV;
                break;
            case 2:
                ui->lblOffsetInfo->setText("Connect 0V AC and Click Measure");
                ui->lblMaxInfo->setText("Connect 5V ACand Click Measure");
                m_nMacroValue=AC5V;
                break;
            case 3:
                ui->lblOffsetInfo->setText("Connect 0V AC and Click Measure");
                ui->lblMaxInfo->setText("Connect 50V AC and Click Measure");
                m_nMacroValue=AC50V;
                break;
            case 4:
                ui->lblOffsetInfo->setText("Connect 0V AC and Click Measure");
                ui->lblMaxInfo->setText("Connect 500V AC and Click Measure");
                m_nMacroValue=AC500V;
                break;
            case 5:
                ui->lblOffsetInfo->setText("Connect 0V AC and Click Measure");
                ui->lblMaxInfo->setText("Connect 1000V AC and Click Measure");
                m_nMacroValue=AC1000V;
                break;
            }
        }
        break;
    case 4:{
        switch(index){
        case 0:
            ui->lblOffsetInfo->setText("Connect 0A DC and Click Measure");
            ui->lblMaxInfo->setText("Connect 500uA DC and Click Measure");
            m_nMacroValue=DC500uA;
            break;
        case 1:
            ui->lblOffsetInfo->setText("Connect 0A DC and Click Measure");
            ui->lblMaxInfo->setText("Connect 5mA DC and Click Measure");
            m_nMacroValue=DC5mA;
            break;
        case 2:
            ui->lblOffsetInfo->setText("Connect 0A DC and Click Measure");
            ui->lblMaxInfo->setText("Connect 50mA DC and Click Measure");
            m_nMacroValue=DC50mA;
            break;
        case 3:
            ui->lblOffsetInfo->setText("Connect 0A DC and Click Measure");
            ui->lblMaxInfo->setText("Connect 500mA DCand Click Measure");
            m_nMacroValue=DC500mA;
            break;
        case 4:
            ui->lblOffsetInfo->setText("Connect 0A DC and Click Measure");
            ui->lblMaxInfo->setText("Connect 3A DC and Click Measure");
            m_nMacroValue=DC10A;
            break;
        }

    }
    break;
    case 5:{
        switch(index){
        case 0:
            ui->lblOffsetInfo->setText("Connect 0A AC and Click Measure");
            ui->lblMaxInfo->setText("Connect 500uA AC and Click Measure");
            m_nMacroValue=AC500uA;
            break;
        case 1:
            ui->lblOffsetInfo->setText("Connect 0A AC and Click Measure");
            ui->lblMaxInfo->setText("Connect 5mA AC and Click Measure");
            m_nMacroValue=DC5mA;
            break;
        case 2:
            ui->lblOffsetInfo->setText("Connect 0A AC and Click Measure");
            ui->lblMaxInfo->setText("Connect 50mA AC and Click Measure");
            m_nMacroValue=AC50mA;
            break;
        case 3:
            ui->lblOffsetInfo->setText("Connect 0A AC and Click Measure");
            ui->lblMaxInfo->setText("Connect 500mA ACand Click Measure");
            m_nMacroValue=AC500mA;
            break;
        case 4:
            ui->lblOffsetInfo->setText("Connect 0A AC and Click Measure");
            ui->lblMaxInfo->setText("Connect 3A AC and Click Measure");
            m_nMacroValue=AC10A;
            break;
        }

    }
    break;

    }
    hy3131dmm->Configure(m_nMacroValue);
    ui->leGain->setText(QString::number(m_nGain[m_nMacroValue],'g',10));
    ui->leOffset->setText(QString::number(m_nOffset[m_nMacroValue],'g',10));
    //enableDisable(2,false);
    //enableDisable(3,false);
    //enableDisable(4,false);
}

void HY3131Calibration::on_pbMeasureMin_clicked()
{
    stopADC();
    m_dOffsetMeasured=hy3131dmm->Measure2(m_nMacroValue);
    ui->leOffsetMeasured->setText(QString::number(m_dOffsetMeasured,'g',10));
}

void HY3131Calibration::on_pbMeasureMax_clicked()
{
    stopADC();
    m_dMaxMeasured=hy3131dmm->Measure2(m_nMacroValue);
    ui->leMaxMeasured->setText(QString::number(m_dMaxMeasured,'g',10));
}
void HY3131Calibration::ADCRead(){
    m_dCalibrated=hy3131dmm->Measure(m_nMacroValue);
    if(m_dCalibrated==999999)
        ui->leCalibrated->setText("OPEN");
    else
        ui->leCalibrated->setText(QString::number(m_dCalibrated,'g',10));
}

void HY3131Calibration::on_calibrateBut_clicked()
{
    stopADC();
    if((m_nMacroValue>=9 && m_nMacroValue<=14)||(m_nMacroValue>=9 && m_nMacroValue<=14)||(m_nMacroValue==28)||(m_nMacroValue==30))
        m_dCalculatedGain=sqrt((m_dMaxMeasured-m_dOffsetMeasured))/m_dMaxInput;
    else
        m_dCalculatedGain=(m_dMaxMeasured-m_dOffsetMeasured)/m_dMaxInput;
    m_dCalculatedOffset=m_dOffsetMeasured;

    ui->leGain->setText(QString::number(m_dCalculatedGain,'g',10));
    ui->leOffset->setText(QString::number(m_dCalculatedOffset,'g',10));

    //enableDisable(4,true);
}
void HY3131Calibration::receiveValue(unsigned int pValue){
Q_UNUSED(pValue)
}

void HY3131Calibration::receiveValue(double pValue){
    if (m_nLineEditIndex == 0) {
        m_dOffsetInput=pValue;
    } else if (m_nLineEditIndex == 1) {
        m_dMaxInput=pValue;
    }
}

void HY3131Calibration::receiveValue(QString pValue){
    if (m_nLineEditIndex == 0) {
        objOffsetValue->setText(pValue);
    } else if (m_nLineEditIndex == 1) {
        objMaxValue->setText(pValue);
    }
}

void HY3131Calibration::callOffsetEdit(){
    if (objOffsetValue->hasFocus()) {

        if(ui->cmbComponent->currentIndex()==1)
            openNumKBPanel(1,1.0,'R',100000000,0,this);
        else if(ui->cmbComponent->currentIndex()==2||ui->cmbComponent->currentIndex()==3)
            openNumKBPanel(1,1.0,'v',1000,-1000,this);
        else if(ui->cmbComponent->currentIndex()==4||ui->cmbComponent->currentIndex()==5)
            openNumKBPanel(1,1.0,'I',3,-3,this);
        else if(ui->cmbComponent->currentIndex()==6)
            openNumKBPanel(1,1.0,'v',5,-5,this);
        else if(ui->cmbComponent->currentIndex()==7)
            openNumKBPanel(1,1.0,'C',100,0,this);
        else if(ui->cmbComponent->currentIndex()==8)
            openNumKBPanel(1,1.0,'R',10000,0,this);
        else if(ui->cmbComponent->currentIndex()==9)
            openNumKBPanel(1,1.0,'F',10000000,0,this);

            m_nLineEditIndex = 0;
    }
}

void HY3131Calibration::callMaxEdit(){
    if (objMaxValue->hasFocus()) {

        if(ui->cmbComponent->currentIndex()==1)
            openNumKBPanel(1,1.0,'R',100000000,0,this);
        else if(ui->cmbComponent->currentIndex()==2||ui->cmbComponent->currentIndex()==3)
            openNumKBPanel(1,1.0,'v',1000,-1000,this);
        else if(ui->cmbComponent->currentIndex()==4||ui->cmbComponent->currentIndex()==5)
            openNumKBPanel(1,1.0,'I',3,-3,this);
        else if(ui->cmbComponent->currentIndex()==6)
            openNumKBPanel(1,1.0,'v',5,-5,this);
        else if(ui->cmbComponent->currentIndex()==7)
            openNumKBPanel(1,1.0,'C',100,0,this);
        else if(ui->cmbComponent->currentIndex()==8)
            openNumKBPanel(1,1.0,'R',10000,0,this);
        else if(ui->cmbComponent->currentIndex()==9)
            openNumKBPanel(1,1.0,'F',10000000,0,this);

            m_nLineEditIndex = 1;
    }
}
void HY3131Calibration::openNumKBPanel(short int pValue) {

        QWidget *w = INumberPanel->getNumKBPanel(pValue, this);
        w->setWindowFlags(Qt::WindowCloseButtonHint | Qt::Dialog);
        w->show();
}
void HY3131Calibration::openNumKBPanel(short int pValue, double incRatio, char type,
                double max, double min, QWidget* parent) {

        QWidget *w = INumberPanel->getNumKBPanelIncDec(pValue, incRatio, type, max,
                        min, parent);
        w->setWindowFlags(Qt::WindowCloseButtonHint | Qt::Dialog);
        w->show();
}

void HY3131Calibration::on_pbMeasureCalibrated_clicked()
{
    if(ui->pbMeasureCalibrated->text()=="Measure"){
       ui->pbMeasureCalibrated->setText("Stop");
       ADCTimer->start(100);
    }
    else{
       ui->pbMeasureCalibrated->setText("Measure");
       ADCTimer->stop();
    }
}

void HY3131Calibration::on_saveBut_clicked()
{
    m_nGain[m_nMacroValue]=m_dCalculatedGain;
    m_nOffset[m_nMacroValue]=m_dCalculatedOffset;

    //Write Gain & Offset to file~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    QFile outFile("/home/HY3131/GainOffset2.dat");
    outFile.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream ts(&outFile);
    for(int i=0;i<27;i++)
        ts <<m_strRange[i]<<"\t"<<fixed<<m_nGain[i]<<"\t"<<m_nOffset[i]<<endl;
    outFile.close();

}
void HY3131Calibration::stopADC(){
    if(ADCTimer->isActive()){
        ui->pbMeasureCalibrated->setText("Measure");
        ADCTimer->stop();
    }
}

void HY3131Calibration::on_pbStopMin_clicked()
{
    //enableDisable(2,true);
}

void HY3131Calibration::on_pbStopMax_clicked()
{
    //enableDisable(3,true);
}
