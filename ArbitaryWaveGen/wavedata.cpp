#include "wavedata.h"
#include "ui_wavedata.h"

WaveData::WaveData(short waveNumber,QWidget *parent) :
        QDialog(parent),
        ui(new Ui::WaveData)
{
    ui->setupUi(this);
    m_nWaveNumber=waveNumber;

    QPluginLoader loader4("libQmaxPTInterface.so",this);
    ILineEdit = qobject_cast<IQmaxLineEdit*>(loader4.instance());
    INumberPanel=qobject_cast<IQmaxNumberPanel*>(loader4.instance());

    ui->le_Samples->setVisible(false);
    m_objSamples=ILineEdit->QmaxLineEdit(1, this);
    m_objSamples->setGeometry(ui->le_Samples->geometry());
    m_objSamples->setFont(QFont("DejaVu Sans",13,50,false));
    connect(m_objSamples,SIGNAL(focussed(bool)), this, SLOT(callSamplesEdit()));

    ui->le_StartTick->setVisible(false);
    m_objStartTick=ILineEdit->QmaxLineEdit(2, this);
    m_objStartTick->setGeometry(ui->le_StartTick->geometry());
    m_objStartTick->setFont(QFont("DejaVu Sans",13,50,false));
    connect(m_objStartTick,SIGNAL(focussed(bool)), this, SLOT(callStartTickEdit()));

    ui->le_EndTick->setVisible(false);
    m_objStoptick=ILineEdit->QmaxLineEdit(3, this);
    m_objStoptick->setGeometry(ui->le_EndTick->geometry());
    m_objStoptick->setFont(QFont("DejaVu Sans",13,50,false));
    connect(m_objStoptick,SIGNAL(focussed(bool)), this, SLOT(callStopTickEdit()));

    ui->le_DutyCycle->setVisible(false);
    m_objDutyCycle=ILineEdit->QmaxLineEdit(4, this);
    m_objDutyCycle->setGeometry(ui->le_DutyCycle->geometry());
    m_objDutyCycle->setFont(QFont("DejaVu Sans",13,50,false));
    connect(m_objDutyCycle,SIGNAL(focussed(bool)), this, SLOT(callDutyCylceEdit()));

    connect(this,SIGNAL(SendSamples(int)), parent, SLOT(RxSamples(int)));
    connect(this,SIGNAL(SendStartTick(int)), parent, SLOT(RxStartTick(int)));
    connect(this,SIGNAL(SendStopTick(int)), parent, SLOT(RxStopTick(int)));
    connect(this,SIGNAL(SendDutyCycle(int)), parent, SLOT(RxDutyCycle(int)));
    connect(parent,SIGNAL(SendTotalSamples(int)),this,SLOT(RxTotalSamples(int)));

    if(m_nWaveNumber!=6){
        m_objDutyCycle->setVisible(false);
        ui->lbl_DutyCycles->setVisible(false);
    }

    if(m_nWaveNumber==1) ui->lbl_Title->setText("Random Wave Settings");
    if(m_nWaveNumber==2) ui->lbl_Title->setText("Sine Wave Settings");
    if(m_nWaveNumber==3) ui->lbl_Title->setText("Square Wave Settings");
    if(m_nWaveNumber==4) ui->lbl_Title->setText("Triangle Wave Settings");
    if(m_nWaveNumber==5) ui->lbl_Title->setText("Sawtooth Wave Settings");
    if(m_nWaveNumber==6) ui->lbl_Title->setText("Pulse Wave Settings");


    m_nLineEditIndex=0;
    m_nDutyCycle=m_nSamples=m_nStartTick=m_nStoptick=0;
}
void WaveData::RxTotalSamples(int data){
    m_nTotalSamples=data;
    qDebug()<<"Rxd Total Samples :"<<m_nTotalSamples;
}

void WaveData::receiveValue(unsigned int pValue){
    Q_UNUSED(pValue)
    }

void WaveData::receiveValue(double pValue){
    QMessageBox msgbox;
    msgbox.setWindowFlags(Qt::Widget | Qt::FramelessWindowHint);
    msgbox.setFont(QFont("DejaVu Sans", 15, 50, false));
    msgbox.setIcon(QMessageBox::Warning);


    if(m_nLineEditIndex==1){
        if(pValue>m_nTotalSamples){
            msgbox.setText("Entered no of Samples is greater than Total no of Samples.Click OK for Maximum no of Samples.");
            msgbox.setStandardButtons(QMessageBox::Ok|QMessageBox::Cancel);
            int ret = msgbox.exec();
            if(ret==QMessageBox::Ok)
                m_nSamples=m_nTotalSamples;
            else
                m_nSamples=0;
        }
        else
            m_nSamples=(int)pValue;

        m_objSamples->setText(QString::number(m_nSamples));

    }
    else if(m_nLineEditIndex==2){
        if(pValue>m_nSamples){
            msgbox.setText("Start Tick is greater than no of Samples.Click OK to Start with Minimum no of Ticks.");
            msgbox.setStandardButtons(QMessageBox::Ok|QMessageBox::Cancel);
            int ret = msgbox.exec();
            if(ret==QMessageBox::Ok)
                m_nStartTick=m_nSamples;
            else
                m_nStartTick=0;
        }else
            m_nStartTick=(int)pValue;
    }
    else if(m_nLineEditIndex==3){
        if(pValue>m_nSamples){
            msgbox.setText("Stop Tick is greater than no of Samples.Click OK to End with Maximum no of Ticks.");
            msgbox.setStandardButtons(QMessageBox::Ok|QMessageBox::Cancel);
            int ret = msgbox.exec();
            if(ret==QMessageBox::Ok)
                m_nStoptick=m_nSamples;
            else
                m_nStoptick=0;
        }else
            m_nStoptick=(int)pValue;
    }
    else if(m_nLineEditIndex==4){
        if(pValue>100){
            msgbox.setText("Duty Cycle should be less than 100.");
            msgbox.setStandardButtons(QMessageBox::Ok);
            msgbox.exec();
        }else
            m_nDutyCycle=(int)pValue;
    }
}

void WaveData::receiveValue(QString pText){
    if(m_nLineEditIndex==1){
//        m_objSamples->setText(pText);
    }
    else if(m_nLineEditIndex==2){
        m_objStartTick->setText(pText);
    }
    else if(m_nLineEditIndex==3){
        m_objStoptick->setText(pText);
    }
    else if(m_nLineEditIndex==4){
        m_objDutyCycle->setText(pText);
    }
}

void WaveData::callSamplesEdit(){

    if (m_objSamples->hasFocus()) {
//        openNumKBPanelminmax(1,double(m_nTotalSamples),1);
    	openNumKBPanel(1);
        m_nLineEditIndex = 1;
    }
}

void WaveData::callStartTickEdit(){
    if (m_objStartTick->hasFocus()) {
//        openNumKBPanelminmax(1,double(m_nTotalSamples),1);
    	openNumKBPanel(1);
        m_nLineEditIndex = 2;
    }
}

void WaveData::callStopTickEdit(){
    if (m_objStoptick->hasFocus()) {
//        openNumKBPanelminmax(1,double(m_nTotalSamples),1);
    	openNumKBPanel(1);
        m_nLineEditIndex = 3;
    }
}

void WaveData::callDutyCylceEdit(){
    if (m_objDutyCycle->hasFocus()) {
//        openNumKBPanelminmax(1,100,1);
    	openNumKBPanel(1);
        m_nLineEditIndex = 4;
    }
}
void WaveData::openNumKBPanel(short int pValue) {
    QWidget *w = INumberPanel->getNumKBPanel(pValue, this);
    w->setWindowFlags(Qt::WindowCloseButtonHint | Qt::Dialog);
    w->setStyleSheet("color: #333;background: qradialgradient(cx: 0.3, cy: -0.4,fx: 0.3, fy: -0.4,radius: 1.35, stop: 0 #fff, stop: 1 #888);");
    w->show();
}
void WaveData::openNumKBPanelminmax(short int pValue, double pMax, double pMin) {
    QWidget *w = INumberPanel->getNumKBPanelIncDec(pValue, 1, 'X', pMax, pMin,this);
    w->setWindowFlags(Qt::WindowCloseButtonHint | Qt::Dialog);
    w->setStyleSheet("color: #333;background: qradialgradient(cx: 0.3, cy: -0.4,fx: 0.3, fy: -0.4,radius: 1.35, stop: 0 #fff, stop: 1 #888);");
    w->show();
}
WaveData::~WaveData()
{
    delete ui;
}

void WaveData::changeEvent(QEvent *e)
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

void WaveData::on_pb_Ok_clicked()
{
    emit SendSamples(m_nSamples);
    emit SendStartTick(m_nStartTick);
    emit SendStopTick(m_nStoptick);
    emit SendDutyCycle(m_nDutyCycle);

    this->close();
}

void WaveData::on_pb_Cancel_clicked()
{
    this->close();
}
