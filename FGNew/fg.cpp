// -------------------------------------------------
// Project created by Ravivarman 2013-10-22T17:31:59
// -------------------------------------------------

#include "fg.h"
#include "ui_fg.h"

FG::FG(QWidget *parent) :
        QMainWindow(parent), ui(new Ui::FG) {
    ui->setupUi(this);
    PluginsInitialisation();
    InitialiseUIData();
    InitialiseWaveData();
    InitialiseLineEdit();
    ConnectSignalsnSlots();
    DefaultSettings();
}

FG::~FG() {
    delete ui;
}
void FG::PluginsInitialisation(){
    QPluginLoader loader1("libQmaxPTInterface.so", this);
    INumberPanel = qobject_cast<IQmaxNumberPanel*> (loader1.instance());

    QPluginLoader loader2("libBackPlaneInterface.so",this);
    IBackPlane = qobject_cast<IntefaceBackPlane*>(loader2.instance());
    IBackPlane->InitializeBpObject();

    QPluginLoader loader3("libPTPsocInterface2.so",this);
    IPsoc = qobject_cast<IPSOCCOMMUNICATION*>(loader3.instance());
    IPsoc->openSerial();

    QPluginLoader loader5("libGPIOEventInterface.so",this);
    IGPIOEvent = qobject_cast<PTGPIOEventInterface*>(loader5.instance());

    QPluginLoader loader6("libPTKeyEventInterfaces.so",this);
    IPTKeyEvent = qobject_cast<PTEventInterface*>(loader6.instance());
    IPTKeyEvent->InvokeGPIOEvent(this, "/dev/input/event2", "pt_kpp", &m_nPTKeyCode);

    QPluginLoader loader8("libPTGPIOPinInterface.so",this);
    IGPIOPin = qobject_cast<InterfaceGPIOPins*>(loader8.instance());

    QPluginLoader testing("libAppBckPsoc.so", this);
    test = qobject_cast<IPTAppBckPsocInterface*> (testing.instance());

    QPluginLoader loaderREF("libRefCalib.so",this);
    REFCalib = qobject_cast<IRefCALIBTestJigInterface*>(loaderREF.instance());

    QPluginLoader awgGUI("libArbitaryWaveform.so",this);
    AWGGUI = qobject_cast<AWGUIInterface*>(awgGUI.instance());

    QPluginLoader awgGUI2("libArbitaryWaveGen.so",this);
    AWGGUI2 = qobject_cast<AWGUIInterface2*>(awgGUI2.instance());

    AWGWidget=AWGGUI2->getAWGUIInterface2();
    AWGWidget->setWindowTitle("Arbitary Waveform Generator");

//    connect(AWGWidget,SIGNAL(triggerFGRelay(bool)),this,SLOT(switchFGRelay(bool)));

    //	IBackPlane->writeBackPlaneRegister(0x2, 0x26);
    //	qDebug()<<"Before src imp selection";
    IPsoc->srcImpedanceSelection(SRC_IMP_50E);
    //~~~~~~~~Check for debug panel~~~~~~~~~~~~~~~~~~~~~~~~
    QStringList debugPanel;
    QFile textFile2("debugPanel.txt");
    if (textFile2.open(QIODevice::ReadOnly))
    {
        QTextStream textStream(&textFile2);
        while (!textStream.atEnd())
        {
            debugPanel.append(textStream.readLine());
            if(debugPanel.value(0)=="1"){
                ui->debugPanel->setVisible(true);
                ui->frontPanel_FG->setVisible(false);
            }
            else{
                ui->debugPanel->setVisible(false);
                ui->frontPanel_FG->setVisible(true);
            }
        }
    }
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
}
void FG::customEvent(QEvent *e) {

    if (e->type() == ((QEvent::Type) 1234)) {
        //qDebug() << "Embedded Probe Not Used Here";
    }
    if (e->type() == ((QEvent::Type) 5678)) {
        doPTKeyFunction();
    }
    if (e->type() == ((QEvent::Type) 3456)) {
        //qDebug() << "Magnetic Knob Not Used Here";
    }
    QEvent(e->type());
}
void FG::readEncoderData(){
    IBackPlane->writeBackPlaneRegister(0xC00B, 0x0028);
    usleep(1000);
    while (IBackPlane->readBackPlaneRegister(0x0028) & 0x0001);
    spiData = IBackPlane->readBackPlaneRegister(0x002E);
    m_nEncoder=spiData & 0x00FF;
    m_nSwitch=spiData & 0x0100;
}
void FG::doPTKeyFunction() {
    if(m_nPTKeyCode==1){//qDebug()<<("\nMENU");
	if(AWGWidget->isVisible()){
            AWGWidget->close();
	}else{
            IBackPlane->closeObject();
            IPsoc->resetRelays();
            IPsoc->closeSerial();
            parentWidget()->close();
	}
    }
    else if(m_nPTKeyCode==2){//qDebug()<<("\nESC");
	if(AWGWidget->isVisible()){
            AWGWidget->close();
	}else{
            IBackPlane->closeObject();
            IPsoc->resetRelays();
            IPsoc->closeSerial();
            parentWidget()->close();
	}
    }
    else if(m_nPTKeyCode==3){//qDebug()<<("\nNULL");
    }
    else if(m_nPTKeyCode==4){//qDebug()<<("\nF1");
	ui->sineBut->animateClick(1);
    }
    else if(m_nPTKeyCode==5){//qDebug()<<("\nF2");
	ui->squareBut->animateClick(1);
    }
    else if(m_nPTKeyCode==6){//qDebug()<<("\nF3");
	ui->rampBut->animateClick(1);
    }
    else if(m_nPTKeyCode==7){//qDebug()<<("\nF4");
	ui->triangleBut->animateClick(1);
    }
    else if(m_nPTKeyCode==8){//qDebug()<<("\nF5");
        ui->AWGBox->animateClick(1);
    }
    else if(m_nPTKeyCode==9){//qDebug()<<("\nUP");
	ui->upBut->animateClick(1);
    }
    else if(m_nPTKeyCode==10){//qDebug()<<("\nDOWN");
	ui->downBut->animateClick(1);
    }
    else if(m_nPTKeyCode==11){//qDebug()<<("\nRIGHT");
	//qDebug()<<"rightBut_clicked";
	for(int i=0;i<8;i++){
            if(lineEdit[i]->hasFocus()){
                //			qDebug()<<"Focussed "<<i<<" LineEdit";
                if(i!=7){
                    //qDebug()<<"To Focuss "<<i+1<<" LineEdit";
                    lineEdit[i+1]->setFocus();
                    m_nLineEditIndex=i+1;
                }
                else{
                    //				qDebug()<<"To Focuss "<<0<<" LineEdit";
                    lineEdit[0]->setFocus();
                    m_nLineEditIndex=0;
                }
                break;
            }
	}
	if(lineEdit[0]->hasFocus()==false&&lineEdit[1]->hasFocus()==false&&lineEdit[2]->hasFocus()==false&&lineEdit[3]->hasFocus()==false&&lineEdit[4]->hasFocus()==false&&lineEdit[5]->hasFocus()==false&&lineEdit[6]->hasFocus()==false&&lineEdit[7]->hasFocus()==false){
            lineEdit[0]->setFocus();
            m_nLineEditIndex=0;
	}
    }
    else if(m_nPTKeyCode==12){//qDebug()<<("\nLEFT");
	//qDebug()<<"leftBut_clicked";
	for(int i=0;i<8;i++){
            if(lineEdit[i]->hasFocus()){
                //			qDebug()<<"Focussed "<<i<<" LineEdit";
                if(i!=0){
                    //				qDebug()<<"To Focuss "<<i+1<<" LineEdit";
                    lineEdit[i-1]->setFocus();
                    m_nLineEditIndex=i-1;
                }
                else{
                    //				qDebug()<<"To Focuss "<<0<<" LineEdit";
                    lineEdit[7]->setFocus();
                    m_nLineEditIndex=7;
                }
                break;
            }
	}
	if(lineEdit[0]->hasFocus()==false&&lineEdit[1]->hasFocus()==false&&lineEdit[2]->hasFocus()==false&&lineEdit[3]->hasFocus()==false&&lineEdit[4]->hasFocus()==false&&lineEdit[5]->hasFocus()==false&&lineEdit[6]->hasFocus()==false&&lineEdit[7]->hasFocus()==false){
            lineEdit[0]->setFocus();
            m_nLineEditIndex=0;
	}
    }
    else if(m_nPTKeyCode==13){//qDebug()<<("\nENTER");
    }
    else if(m_nPTKeyCode==14){//qDebug()<<("\nSETUP");
    }
    else if(m_nPTKeyCode==15){//qDebug()<<("\nDEFAULT");
    }
    else if(m_nPTKeyCode==16){//qDebug()<<("\nTOUCH");
	IGPIOPin->toggleTouchButton();
    }
    else if(m_nPTKeyCode==17){//qDebug()<<("\nFILE");
	clickedPRSCR();
    }
    else if(m_nPTKeyCode==18){//qDebug()<<("\nSCALE");
	if (fineCoarse == true) {
            fineCoarse = false;
            //qDebug() << "Coarse Activated";
            IGPIOPin->illuminateScaleButton(1);
            ui->fineCoarse->setStyleSheet("QPushButton{background-color:rgba(0,0,0,0);border:1px solid rgba(0,0,0,0);image: url(:/res/coarse.png);}");
	} else {
            fineCoarse = true;
            //qDebug() << "Fine Activated";
            IGPIOPin->illuminateScaleButton(0);
            ui->fineCoarse->setStyleSheet("QPushButton{background-color:rgba(0,0,0,0);border:1px solid rgba(0,0,0,0);image: url(:/res/fine.png);}");
	}
    }
    else if(m_nPTKeyCode==19){//qDebug()<<("\nRUN/STOP");
        ui->RUNBut->animateClick(1);
    }
}
void FG::InitialiseUIData(){

    m_strWaveType="SINE";

    ok=true;

    m_bContinuous=true;	m_bBurst=false;	m_bSingle=false;m_bGate=false;
    m_bManual=false;m_bInternal=false;m_bExternal=false;

    ui->EXTBut->setVisible(false);ui->EXTCap->setVisible(false);

    ui->ManCap->setEnabled(false);ui->INTCap->setEnabled(false);ui->EXTCap->setEnabled(false);
    ui->MANBut->setEnabled(false);ui->INTBut->setEnabled(false);ui->EXTBut->setEnabled(false);

    m_bHiZ=true;	m_bRunMode=false;
    fineCoarse = false;

    Data.Amplitude = 0.0;
    Data.offset = 0.0;

    QString deg = QChar(0x00B0);

    lineEditLabels.insert(0,"Frequency");
    lineEditLabels.insert(1,"Amplitude");
    lineEditLabels.insert(2,"Offset");
    lineEditLabels.insert(3,"Phase");
    lineEditLabels.insert(4,"Period");
    lineEditLabels.insert(5,"HLevel");
    lineEditLabels.insert(6,"LLevel");
    lineEditLabels.insert(7,"Delay");

    lineEditInitials.insert(FREQUENCY,"1KHz");
    lineEditInitials.insert(AMPLITUDE,"5Vpp");
    lineEditInitials.insert(OFFSET,"0V");
    lineEditInitials.insert(PHASE,"0"+deg);
    lineEditInitials.insert(PERIOD,"1msec");
    lineEditInitials.insert(HLEVEL,"2.5V");
    lineEditInitials.insert(LLEVEL,"-2.5V");
    lineEditInitials.insert(DELAY,"0");

    maxList.insert(FREQUENCY,5000000.0);
    maxList.insert(AMPLITUDE,20.0);
    maxList.insert(OFFSET,10.0);
    maxList.insert(PHASE,360.0);
    maxList.insert(PERIOD,100.0);
    maxList.insert(HLEVEL,10.0);
    maxList.insert(LLEVEL,10.0);
    maxList.insert(DELAY,100.0);

    maxList.insert(BURST_COUNT,100);
    maxList.insert(BURST_RATE,100);

    minList.insert(FREQUENCY,0.01);
    minList.insert(AMPLITUDE,0.01);
    minList.insert(OFFSET,-10.0);
    minList.insert(PHASE,0.0);
    minList.insert(PERIOD,5.00000e-7);
    minList.insert(HLEVEL,-10.0);
    minList.insert(LLEVEL,-10.0);
    minList.insert(DELAY,0.0);

    minList.insert(BURST_COUNT,2);
    minList.insert(BURST_RATE,5.00000e-7);

    callType.insert(FREQUENCY,'F');
    callType.insert(AMPLITUDE,'V');
    callType.insert(OFFSET,'v');
    callType.insert(PHASE,'D');
    callType.insert(PERIOD,'T');
    callType.insert(HLEVEL,'v');
    callType.insert(LLEVEL,'v');
    callType.insert(DELAY,'N');

    callType.insert(BURST_COUNT,'N');
    callType.insert(BURST_RATE,'T');

    hwInterface=new HardwareInterface();
    hwInterface->Init();

    m_nLineEditIndex=0;
}
void FG::InitialiseLineEdit(){
    for(int i=0;i<8;i++){
        lineEdit[i]=new QmaxLineEdit(i,ui->parameterPanel);
        label[i]=new QmaxLabel(i,ui->parameterPanel);

        if(i==0||i==1||i==2||i==3){
            label[i]->setGeometry(30+(i*125),10,110,30);
            lineEdit[i]->setGeometry(30+(i*125),40,110,30);
        }

        if(i==4||i==5||i==6||i==7){
            label[i]->setGeometry(30+((i-4)*125),80,110,30);
            lineEdit[i]->setGeometry(30+((i-4)*125),110,110,30);
        }

        label[i]->setText(lineEditLabels.value(i));
        lineEdit[i]->setText(lineEditInitials.value(i));

        connect(lineEdit[i],SIGNAL(focussed(bool)),label[i],SLOT(setlabelFocus(bool)));
        connect(lineEdit[i],SIGNAL(focussed(int)),this,SLOT(callLineEditInput(int)));

    }

    burstCountEdit=new QmaxLineEdit(8,ui->burstOptions);
    burstCountLabel=new QmaxLabel(8,ui->burstOptions);
    burstCountLabel->setText("Count");
    burstCountEdit->setGeometry(64,23,70,25);
    burstCountLabel->setGeometry(4,23,60,25);

    connect(burstCountEdit,SIGNAL(focussed(bool)),burstCountLabel,SLOT(setlabelFocus(bool)));
    connect(burstCountEdit,SIGNAL(focussed(int)),this,SLOT(callLineEditInput(int)));

    burstRateEdit=new QmaxLineEdit(9,ui->burstOptions);
    burstRateLabel=new QmaxLabel(9,ui->burstOptions);
    burstRateLabel->setText("Rate");
    burstRateEdit->setGeometry(180,23,70,25);
    burstRateLabel->setGeometry(133,23,50,25);

    connect(burstRateEdit,SIGNAL(focussed(bool)),burstRateLabel,SLOT(setlabelFocus(bool)));
    connect(burstRateEdit,SIGNAL(focussed(int)),this,SLOT(callLineEditInput(int)));

    burstCountEdit->setEnabled(false);
    burstCountEdit->stylesheetSet("color: rgb(255, 255, 255);""background-color: gray;border:1px solid rgba(100,100,100,255);border-radius:5px;");
    burstCountLabel->setEnabled(false);

    burstRateEdit->setEnabled(false);
    burstRateEdit->stylesheetSet("color: rgb(255, 255, 255);""background-color: gray;border:1px solid rgba(100,100,100,255);border-radius:5px;");
    burstRateLabel->setEnabled(false);

    label[7]->setVisible(false);
    lineEdit[7]->setVisible(false);
}
void FG::callLineEditInput(int leFocussed){
    QWidget *m_w;
    m_nLineEditIndex=leFocussed;
    //	qDebug()<<"LineEdit Index:"<<m_nLineEditIndex;

    if((m_bBurst==true)&&(leFocussed==0)){
        m_w = INumberPanel->getNumKBPanelIncDec(1,1,callType.value(leFocussed), maxList.value(leFocussed), ((1/m_nBurstRate)*2),this);
    }
    else{
        m_w = INumberPanel->getNumKBPanelIncDec(1,1,callType.value(leFocussed), maxList.value(leFocussed), minList.value(leFocussed),this);
    }

    m_w->setWindowFlags(Qt::WindowCloseButtonHint | Qt::Dialog);
    m_w->show();
}
void FG::SetFrequency(double l_nFrequency){
    if(m_bBurst==true){
        if(l_nFrequency<((1/m_nBurstRate)*2))
            showMessageBox(true,false,"Value is lesser than minimum value","Ok","");
        else{
//            if(m_strWaveType=="TRIANGLE"){
//                hwInterface->setFrequency(l_nFrequency*2);
//                m_nFrequency=l_nFrequency*2;
//                m_nPeriod=1/m_nFrequency;
//            }
//            else{
                hwInterface->setFrequency(l_nFrequency);
                m_nFrequency=l_nFrequency;
                m_nPeriod=1/m_nFrequency;
//            }
        }
    }else{
//        if(m_strWaveType=="TRIANGLE"){
//            hwInterface->setFrequency(l_nFrequency*2);
//            m_nFrequency=l_nFrequency*2;
//            m_nPeriod=1/m_nFrequency;
//        }
//        else{
            hwInterface->setFrequency(l_nFrequency);
            m_nFrequency=l_nFrequency;
            m_nPeriod=1/m_nFrequency;
//        }
    }
}
void FG::clickedPRSCR() {
    Pix = QPixmap();
    Pix = QPixmap::grabWindow(this->winId());
    Pix.save("FG.jpg");
    QClipboard *board = QApplication::clipboard();
    board->setPixmap(Pix);
    QWidget::showFullScreen();
}

void FG::receiveValue(double pValue){

    switch(m_nLineEditIndex){
    case FREQUENCY:
        SetFrequency(pValue);
        break;
    case AMPLITUDE:
        if(m_bHiZ==true){
            m_nAmplitude=pValue;
            hwInterface->setAmplitude(m_nAmplitude);
        }else{
            m_nAmplitude=pValue*2;
            hwInterface->setAmplitude(m_nAmplitude);
        }
        break;
    case OFFSET:
        if(m_bHiZ==true){
            m_nOffset=pValue;
            hwInterface->setOffset(m_nOffset);
        }else{
            m_nOffset=pValue*2;
            hwInterface->setOffset(m_nOffset);
        }
        break;
    case PHASE:
        hwInterface->setPhase(pValue);
        break;
    case PERIOD:
        hwInterface->setPeriod(pValue);
        break;
    case HLEVEL:
        if(m_bHiZ==true)
            hwInterface->setHlevel(pValue);
        else
            hwInterface->setHlevel(pValue*2);
        break;
    case LLEVEL:
        if(m_bHiZ==true)
            hwInterface->setLlevel(pValue);
        else
            hwInterface->setLlevel(pValue*2);
        break;
    case DELAY:
        hwInterface->setDelay(pValue);
        break;
    case BURST_COUNT:
        m_nBurstCount=pValue;
        SetBurstCount(/*m_nBurstCount*/);
        break;
    case BURST_RATE:
        m_nBurstRate=pValue;
        hwInterface->setBurstRate(m_nBurstRate);
        break;
    }
}
void FG::receiveValue(QString pValue){
    lineEdit[m_nLineEditIndex]->setText(pValue);

    switch(m_nLineEditIndex){
    case FREQUENCY:
        Frequency2Period(lineEdit[FREQUENCY]->text());
        break;
    case AMPLITUDE:
        VppOffset2HighLow(lineEdit[AMPLITUDE]->text(),lineEdit[OFFSET]->text());
        break;
    case OFFSET:
        VppOffset2HighLow(lineEdit[AMPLITUDE]->text(),lineEdit[OFFSET]->text());
        break;
    case PHASE:
        break;
    case PERIOD:
        Period2Frequency(lineEdit[PERIOD]->text());
        break;
    case HLEVEL:
        HighLow2VppOffset(lineEdit[HLEVEL]->text(),lineEdit[LLEVEL]->text());
        break;
    case LLEVEL:
        HighLow2VppOffset(lineEdit[HLEVEL]->text(),lineEdit[LLEVEL]->text());
        break;
    case DELAY:
        break;
    }
}
void FG::receiveValue(uint pValue){
    Q_UNUSED(pValue)
    }
void FG::Frequency2Period(QString l_strFrequency){
    n_frequency=convertToValues(l_strFrequency);
    n_period=1/n_frequency;
    lineEdit[PERIOD]->setText(convertToUnits(n_period)+"sec");
}
void FG::Period2Frequency(QString l_strPeriod){
    n_period=convertToValues(l_strPeriod);
    n_frequency=1/n_period;
    lineEdit[FREQUENCY]->setText(convertToUnits(n_frequency)+"Hz");
}

void FG::VppOffset2HighLow(QString l_strVpp,QString l_strOffset){
    str_vpp = l_strVpp;/*lineEdit[AMPLITUDE]->text();*/
    str_vpp.chop(3);
    str_offset =l_strOffset;/*lineEdit[OFFSET]->text();*/
    str_offset.chop(1);
    n_vpp = str_vpp.toDouble(&ok);
    n_offset = str_offset.toDouble(&ok);
    n_low = n_offset - (n_vpp / 2);
    n_high = n_low + n_vpp;
    str_high = QString::number(n_high);
    str_low = QString::number(n_low);
    lineEdit[HLEVEL]->setText(str_high + "V");
    lineEdit[LLEVEL]->setText(str_low + "V");
}
void FG::HighLow2VppOffset(QString HighLevel,QString LowLevel){
    str_high = HighLevel;/*lineEdit[HLEVEL]->text();*/
    str_high.chop(1);
    str_low = LowLevel;/*lineEdit[LLEVEL]->text();*/
    str_low.chop(1);
    n_high = str_high.toDouble(&ok);
    n_low = str_low.toDouble(&ok);
    n_vpp = n_high - n_low;
    n_offset = (n_vpp / 2) + n_low;
    str_vpp = QString::number(n_vpp);
    str_offset = QString::number(n_offset);
    lineEdit[AMPLITUDE]->setText(str_vpp + "Vpp");
    lineEdit[OFFSET]->setText(str_offset + "V");
}
QString FG::convertToUnits(double l_nvalue){
    QString unit;
    double value;

    if(l_nvalue<0){
        value=l_nvalue*-1;
    }else
        value=l_nvalue;

    if(value>=1000000&&value<1000000000){
        value=value/1000000;       unit="M";
    }
    else if(value>=1000&&value<1000000){
        value=value/1000;       unit="K";
    }
    else if((value>=1&&value<1000))
        value=value*1;
    else if((value*1000)>=1&&value<1000){
        value=value*1000;        unit="m";
    }
    else if((value*1000000)>=1&&value<1000000){
        value=value*1000000;     unit=QChar(0x00B5);
    }
    else if((value*1000000000)>=1&&value<1000000000){
        value=value*1000000000;  unit="n";
    }
    if(l_nvalue>0)
        return (QString::number(value,'f',0)+unit);
    if(l_nvalue<0)
        return (QString::number((value*-1),'f',0)+unit);
}
double FG::convertToValues(QString input){

    QString unit,value;
    double inValue;
    bool ok=true;

    int j=0;

    for(int i=0;i<=input.count();i++){
        if((input[i]>='A'&&input[i]<='Z')||(input[i]>='a'&&input[i]<='z')||(input[i]==QChar(0x2126))||(input[i]==QChar(0x00B5))){
            unit[j]=input[i];
            j++;
        }
    }
    for(int k=0;k<(input.count()-unit.count());k++)
        value[k]=input[k];

    inValue=value.toDouble(&ok);

    if(unit[0]=='n'){
        return(inValue/1000000000);
    }
    else if((unit[0]==QChar(0x00B5))||(unit[0]=='u')){
        return(inValue/1000000);
    }
    else if(unit[0]=='m'){
        return(inValue/1000);
    }
    else if(unit[0]=='K'){
        return(inValue*1000);
    }
    else if(unit[0]=='M'){
        return(inValue*1000000);
    }
    else{
        return(inValue*1);
    }
}

void FG::ConnectSignalsnSlots(){
    connect(ui->MANBut,SIGNAL(pressed()),this,SLOT(Beep()));
    connect(ui->MANBut,SIGNAL(released()),this,SLOT(Mute()));

    connect(ui->INTBut,SIGNAL(pressed()),this,SLOT(Beep()));
    connect(ui->INTBut,SIGNAL(released()),this,SLOT(Mute()));

    connect(ui->EXTBut,SIGNAL(pressed()),this,SLOT(Beep()));
    connect(ui->EXTBut,SIGNAL(released()),this,SLOT(Mute()));

    connect(ui->hiZBut,SIGNAL(pressed()),this,SLOT(Beep()));
    connect(ui->hiZBut,SIGNAL(released()),this,SLOT(Mute()));

    connect(ui->RUNBut,SIGNAL(pressed()),this,SLOT(Beep()));
    connect(ui->RUNBut,SIGNAL(released()),this,SLOT(Mute()));

    connect(ui->upBut,SIGNAL(pressed()),this,SLOT(Beep()));
    connect(ui->upBut,SIGNAL(released()),this,SLOT(Mute()));

    connect(ui->downBut,SIGNAL(pressed()),this,SLOT(Beep()));
    connect(ui->downBut,SIGNAL(released()),this,SLOT(Mute()));

    connect(ui->leftBut,SIGNAL(pressed()),this,SLOT(Beep()));
    connect(ui->leftBut,SIGNAL(released()),this,SLOT(Mute()));

    connect(ui->rightBut,SIGNAL(pressed()),this,SLOT(Beep()));
    connect(ui->rightBut,SIGNAL(released()),this,SLOT(Mute()));

    connect(ui->sineBut,SIGNAL(pressed()),this,SLOT(Beep()));
    connect(ui->sineBut,SIGNAL(released()),this,SLOT(Mute()));

    connect(ui->squareBut,SIGNAL(pressed()),this,SLOT(Beep()));
    connect(ui->squareBut,SIGNAL(released()),this,SLOT(Mute()));

    connect(ui->rampBut,SIGNAL(pressed()),this,SLOT(Beep()));
    connect(ui->rampBut,SIGNAL(released()),this,SLOT(Mute()));

    connect(ui->triangleBut,SIGNAL(pressed()),this,SLOT(Beep()));
    connect(ui->triangleBut,SIGNAL(released()),this,SLOT(Mute()));


}
void FG::DefaultSettings(){

    	m_nAmplitude=5.0;
    	m_nOffset=0.0;
    	m_nFrequency=1000.0;
    	m_nPeriod=1/m_nFrequency;

	//    hwInterface->setHighImpedance(true);
	    hwInterface->Drive(STOPDRIVE);
	    hwInterface->setOffset(m_nOffset);
	    hwInterface->setFrequency(m_nFrequency);
	    hwInterface->setPhase(0);
	    hwInterface->setAmplitude(m_nAmplitude);
}
void FG::Beep(){
    /*	IBackPlane->setBuzzerTone(1000, 0, 50);
	IBackPlane->setBuzzerVolume(20, 1, 50);
	IBackPlane->writeBackPlaneRegister(1,0x32);*/
}
void FG::Mute(){
    /*	IBackPlane->writeBackPlaneRegister(0,0x32);
	IBackPlane->writeBackPlaneRegister(0x1, 0x0E);
	IBackPlane->writeBackPlaneRegister(0x1, 0x08);*/
}
//void FG::switchFGRelay(bool state){
//	if(state==true){
//		IPsoc->FGMeasurement();
//	}else{
//		IPsoc->resetRelays();
//	}
//}

void FG::changeEvent(QEvent *e) {
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

//void FG::on_singleBut_clicked() {
//    m_bContinuous = false;
//    HighlightButtons(SINGLE);
//    GenerateWave();
//    hwInterface->setPatternLoop(false);
//    hwInterface->SingleContinuous(SINGLE_W);
//}

//void FG::on_continuousBut_clicked() {
//    m_bContinuous = true;
//    HighlightButtons(CONTINUOUS);
//    GenerateWave();
//    hwInterface->setPatternLoop(false);
//    hwInterface->SingleContinuous(CONTINUOUS_W);
//    hwInterface->Drive(STARTDRIVE);
//    IGPIOPin->illuminateRunStopButton(0);
//}

//void FG::on_burstBut_clicked() {
//    HighlightButtons(BURST);
//    GenerateWave();
//    hwInterface->SingleContinuous(BURST_W);
//    hwInterface->Drive(STARTDRIVE);
//    for (int i = 0; i < 500; i++){
//        IGPIOPin->illuminateRunStopButton(0);
//    }	IGPIOPin->illuminateRunStopButton(1);
//}

//void FG::on_GateBut_clicked()
//{
//    HighlightButtons(GATE);
//    GenerateWave();
//    hwInterface->Drive(STARTDRIVE);
//    for (int i = 0; i < 500; i++){
//        IGPIOPin->illuminateRunStopButton(0);
//    }	IGPIOPin->illuminateRunStopButton(1);
//}
void FG::SetBurstCount(/*int count*/){
//	if(m_bBurst==true){
	unsigned short b1,b2;
	b1=(unsigned int)m_nBurstCount;
	b2=b1*2;

		if(m_strWaveType=="TRIANGLE"){
			qDebug()<<"Triangle Burst Count:"<<b2;
			hwInterface->setBurstCount(b2);
		}else{
			hwInterface->setBurstCount(b1);
		}
//	}
}
void FG::on_MANBut_clicked()
{
//    if(m_bBurst==true)
//        hwInterface->setPatternLoop(true);
//    else
//        hwInterface->setPatternLoop(false);
    if(m_bContinuous!=true){
        HighlightButtons(MANUAL);
        hwInterface->setAmplitude(m_nAmplitude);
        hwInterface->Drive(STARTDRIVE);
        for (int i = 0; i < 500; i++){
            IGPIOPin->illuminateRunStopButton(0);
        }	IGPIOPin->illuminateRunStopButton(1);

//        if(m_strWaveType=="TRIANGLE"){
            hwInterface->setFrequency(m_nFrequency);
//            if(m_bBurst==true)
            	SetBurstCount(/*m_nBurstCount*/);
//            else
//            	SetBurstCount(/*m_nBurstCount*/);
//        }
    }

    if(m_bContinuous!=true){
        HighlightButtons(MANUAL);
        hwInterface->setAmplitude(m_nAmplitude);
        hwInterface->Drive(STARTDRIVE);
        for (int i = 0; i < 500; i++){
            IGPIOPin->illuminateRunStopButton(0);
        }	IGPIOPin->illuminateRunStopButton(1);

//        if(m_strWaveType=="TRIANGLE"){
            hwInterface->setFrequency(m_nFrequency);
//            if(m_bBurst==true)
            	SetBurstCount(/*m_nBurstCount*/);
//            else
//            	SetBurstCount(/*m_nBurstCount*/);
//        }
    }

}
void FG::on_INTBut_clicked()
{
    if(m_bInternal==false){
        hwInterface->setPatternLoop(true);
//        callLineEditInput(9);
        if(m_strWaveType=="TRIANGLE"){
            hwInterface->setBurstRate(m_nPeriod*8);
            burstRateEdit->setText((convertToUnits(convertToValues(lineEdit[PERIOD]->text())*8))+"sec");
        }else{
            hwInterface->setBurstRate(m_nPeriod*4);
            burstRateEdit->setText((convertToUnits(convertToValues(lineEdit[PERIOD]->text())*4))+"sec");
        }
        HighlightButtons(INT);
        hwInterface->setAmplitude(m_nAmplitude);
        hwInterface->Drive(STARTDRIVE);
        for (int i = 0; i < 500; i++){
            IGPIOPin->illuminateRunStopButton(0);
        }	IGPIOPin->illuminateRunStopButton(1);

        ui->MANBut->setEnabled(false);
        ui->modeBox->setEnabled(false);

    }else{
            hwInterface->setPatternLoop(false);
            HighlightButtons(MANUAL);
            hwInterface->Drive(STOPDRIVE);

            ui->MANBut->setEnabled(true);
            ui->modeBox->setEnabled(true);
    }

}
void FG::on_EXTBut_clicked()
{
    if(m_bContinuous!=true)
        HighlightButtons(EXT);
}
void FG::on_RUNBut_clicked(){
    HighlightButtons(RUN_STOP);
    if(m_bRunMode){
        IPsoc->FGMeasurement();
        usleep(10000);
//        hwInterface->setAmplitude(hwInterface->getAmplitude());

        if(ui->modeBox->currentIndex()==0)
            hwInterface->SingleContinuous(CONTINUOUS_W);
        else if(ui->modeBox->currentIndex()==1)
            hwInterface->SingleContinuous(SINGLE_W);
        else if(ui->modeBox->currentIndex()==2)
            hwInterface->SingleContinuous(BURST_W);

        hwInterface->Drive(STARTDRIVE);
        IGPIOPin->illuminateRunStopButton(0);
    }
    else{
        IPsoc->resetRelays();
        hwInterface->Drive(STOPDRIVE);
        IGPIOPin->illuminateRunStopButton(1);
    }
}
void FG::on_hiZBut_clicked() {
    HighlightButtons(SRCHIZ);
    if(m_bHiZ==true){
        lineEdit[AMPLITUDE]->setText(QString::number(m_nAmplitude)+"Vpp");
        lineEdit[OFFSET]->setText(QString::number(m_nOffset)+"V");
        //		hwInterface->setHighImpedance(true);
    }
    else{
        lineEdit[AMPLITUDE]->setText(QString::number(m_nAmplitude/2)+"Vpp");
        lineEdit[OFFSET]->setText(QString::number(m_nOffset/2)+"V");
        //		hwInterface->setHighImpedance(false);
    }
}
void FG::on_sineBut_clicked() {
    m_strWaveType = "SINE";
    HighlightButtons(SINE_WAVE);
    GenerateWave();
    hwInterface->SelectWaveForm(SINE_W);
    if(m_bBurst==true)
    	SetBurstCount(/*m_nBurstCount*/);
}

void FG::on_squareBut_clicked() {
    m_strWaveType = "SQUARE";
    HighlightButtons(SQUARE_WAVE);
    GenerateWave();
    hwInterface->SelectWaveForm(SQUARE_W);
    SetBurstCount(/*m_nBurstCount*/);
}
void FG::on_AWGBox_clicked()
{
//    IPsoc->resetRelays();
    hwInterface->Drive(STOPDRIVE);
    IGPIOPin->illuminateRunStopButton(1);

    AWGWidget->show();
    HighlightButtons(AWG_WAVE);
}
void FG::on_rampBut_clicked() {
    m_strWaveType = "RAMP";
    HighlightButtons(RAMP_WAVE);
    GenerateWave();
    hwInterface->SelectWaveForm(RAMPUP_W);
    SetBurstCount(/*m_nBurstCount*/);
}

void FG::on_triangleBut_clicked() {
    m_strWaveType = "TRIANGLE";
    HighlightButtons(TRIANGLE_WAVE);
    GenerateWave();
    hwInterface->SelectWaveForm(TRIANGLE_W);
    SetBurstCount(/*m_nBurstCount*/);
}

void FG::InitialiseWaveData() {
    FGProduct = (IWaveProduct*) m_objWaveFactory->getWaveProduct("Oscillator",
                                                                 this);
    FGProduct->setGeometry(14, 36, 432, 228);
    m_objWaveData = new stWaveData();

    m_objWaveData->m_nAmplitude = 0.5;
    m_objWaveData->m_nFrequency = 1.0;
    m_objWaveData->m_nSteps = 1.0;
    m_objWaveData->m_nSamples = 100;
    m_objWaveData->m_nScreenAmplitude = 1.02;
    m_objWaveData->m_nTimeperSample = 0.01;
    m_objWaveData->m_nScreenTime = 1.0;
    m_objWaveData->m_nXunits = 10.0;
    m_objWaveData->m_nYunits = 8.0;
    m_objWaveData->m_nMinX = 0.0;
    m_objWaveData->m_nMinY = -1.0;
    m_objWaveData->m_nPhase = 0.0;
    m_objWaveData->m_nOffset = 0.0;
    m_objWaveData->m_nDutyCycles = 0.5;
    m_objWaveData->m_nCycles = 1.0;
    m_objWaveData->m_nPreamble = 0;
    m_objWaveData->m_nPostamble = 0;
    m_objWaveData->m_bUniPolar = false;
    m_objWaveData->m_nSteps = 1.0;
    m_objWaveData->m_nVRef = 0.6;
    m_objWaveData->m_bCalibChecked = false;
    m_objWaveData->m_nCalibrationConstant = 0.0;
    m_objWaveData->m_nCalibrationGain = 0.0;
    m_objWaveData->m_nResolution = 14;

    on_sineBut_clicked();
}

void FG::GenerateWave() {
    if(m_bBurst){
        m_objWaveData->m_nCycles = 2.0;
        m_objWaveData->m_nSamples=50;
    }else{
        if (m_bContinuous)
            m_objWaveData->m_nCycles = 5.0;
        else
            m_objWaveData->m_nCycles = 1.0;
        m_objWaveData->m_nSamples=100;
    }

    FGProduct->isContinuous(m_bContinuous);
    FGProduct->LoadPlotterData("./25.txt", m_objWaveData);
    FGProduct->WaveSettings();
    FGProduct->GenerateOscillatorPattern(m_strWaveType, 0, false);
}
void FG::HighlightButtons(int but){
    QString ohms=QChar(0x2126);
    QString knobON2="QPushButton{background-color:rgba(0,0,0,0);border:1px solid rgba(0,0,0,0);image: url(:/res/pb-green.png);}";
    QString knobOFF2="QPushButton{background-color:rgba(0,0,0,0);border:1px solid rgba(0,0,0,0);image: url(:/res/pb-red.png);}";

    QString knobON="QPushButton{background-color:rgba(0,0,0,0);border:1px solid rgba(0,0,0,0);image: url(:/res/knob_on.svg);}";
    QString knobOFF="QPushButton{background-color:rgba(0,0,0,0);border:1px solid rgba(0,0,0,0);image: url(:/res/knob_off.svg);}";

    QString pressed="QPushButton{background-color:rgba(0,0,0,0);border:1px solid rgba(0,0,0,0);image: url(:/res/pressed.svg);}";
    QString pressedOrange="QPushButton{background-color:rgba(0,0,0,0);border:1px solid rgba(0,0,0,0);image: url(:/res/pressedOrange.png);}";
    QString normal="QPushButton{background-color:rgba(0,0,0,0);border:1px solid rgba(0,0,0,0);image: url(:/res/normal.svg);}";
    QString selectSine="QGroupBox{border:1px solid white; background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #3a5976, stop: 1 #000000);border-radius:10px;border-bottom:1px qlineargradient(x1: 0, y1: 0,stop: 0 #f6f7fa, stop: 1 #dadbde); border-bottom-right-radius: 0px;border-bottom-left-radius: 0px;}";
    QString UnSelectSine="QGroupBox{border:1px solid white; background-color: #dadbde;border-radius:10px;border-bottom:1px qlineargradient(x1: 0, y1: 0,stop: 0 #f6f7fa, stop: 1 #dadbde); border-bottom-right-radius: 0px;border-bottom-left-radius: 0px;}";
    QString selectSquare="QGroupBox{border:1px solid white; background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #3a5976, stop: 1 #000000);border-radius:10px;border-bottom:1px qlineargradient(x1: 0, y1: 0,stop: 0 #f6f7fa, stop: 1 #dadbde);border-bottom-right-radius: 0px; border-bottom-left-radius: 0px;border-top:1px solid gray; border-top-right-radius: 0px; border-top-left-radius: 0px;}";
    QString UnSelectSquare="QGroupBox{border:1px solid white; background-color: #dadbde;border-radius:10px;border-bottom:1px qlineargradient(x1: 0, y1: 0,stop: 0 #f6f7fa, stop: 1 #dadbde);border-bottom-right-radius: 0px; border-bottom-left-radius: 0px;border-top:1px solid gray; border-top-right-radius: 0px; border-top-left-radius: 0px;}";
    QString selectRamp="QGroupBox{border:1px solid white; background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #3a5976, stop: 1 #000000);border-radius:10px;border-top:1px qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #f6f7fa, stop: 1 #dadbde); border-top-right-radius: 0px; border-top-left-radius: 0px;border-top:1px solid gray;border-bottom-right-radius: 0px; border-bottom-left-radius: 0px;}";
    QString UnSelectRamp="QGroupBox{border:1px solid white; background-color: #dadbde;border-radius:10px;border-top:1px qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #f6f7fa, stop: 1 #dadbde); border-top-right-radius: 0px; border-top-left-radius: 0px;border-top:1px solid gray;border-bottom-right-radius: 0px; border-bottom-left-radius: 0px;}";
    QString selectTriangle="QGroupBox{border:1px solid white; background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #3a5976, stop: 1 #000000);border-radius:10px;border-top:1px qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #f6f7fa, stop: 1 #dadbde); border-top-right-radius: 0px; border-top-left-radius: 0px;border-top:1px solid gray;border-bottom-right-radius: 0px; border-bottom-left-radius: 0px;}";
    QString UnSelectTriangle="QGroupBox{border:1px solid white; background-color: #dadbde;border-radius:10px;border-top:1px qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #f6f7fa, stop: 1 #dadbde); border-top-right-radius: 0px; border-top-left-radius: 0px;border-top:1px solid gray;border-bottom-right-radius: 0px; border-bottom-left-radius: 0px;}";
    QString selectAWG="QGroupBox{border:1px solid white; background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #3a5976, stop: 1 #000000);border-radius:10px;border-top:1px qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #f6f7fa, stop: 1 #dadbde); border-top-right-radius: 0px; border-top-left-radius: 0px;border-top:1px solid gray;border-bottom-right-radius: 0px; border-bottom-left-radius: 0px;}";
    QString UnSelectAWG="QGroupBox{border:1px solid white; background-color: #dadbde;border-radius:10px;border-top:1px qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #f6f7fa, stop: 1 #dadbde); border-top-right-radius: 0px; border-top-left-radius: 0px;border-top:1px solid gray;border-bottom-right-radius: 0px; border-bottom-left-radius: 0px;}";

    switch(but){
    case SINE_WAVE:
        ui->sineBox->setStyleSheet(selectSine);
        ui->squareBox->setStyleSheet(UnSelectSquare);
        ui->rampBox->setStyleSheet(UnSelectRamp);
        ui->triangleBox->setStyleSheet(UnSelectTriangle);
        ui->AWG->setStyleSheet(UnSelectAWG);
        ui->selectFrame->setGeometry(701,54,10,60);
        break;
    case SQUARE_WAVE:
        ui->sineBox->setStyleSheet(UnSelectSine);
        ui->squareBox->setStyleSheet(selectSquare);
        ui->rampBox->setStyleSheet(UnSelectRamp);
        ui->triangleBox->setStyleSheet(UnSelectTriangle);
        ui->AWG->setStyleSheet(UnSelectAWG);
        ui->selectFrame->setGeometry(701,154,10,60);
        break;
    case RAMP_WAVE:
        ui->sineBox->setStyleSheet(UnSelectSine);
        ui->squareBox->setStyleSheet(UnSelectSquare);
        ui->rampBox->setStyleSheet(selectRamp);
        ui->triangleBox->setStyleSheet(UnSelectTriangle);
        ui->AWG->setStyleSheet(UnSelectAWG);
        ui->selectFrame->setGeometry(701,254,10,60);
        break;
    case TRIANGLE_WAVE:
        ui->sineBox->setStyleSheet(UnSelectSine);
        ui->squareBox->setStyleSheet(UnSelectSquare);
        ui->rampBox->setStyleSheet(UnSelectRamp);
        ui->triangleBox->setStyleSheet(selectTriangle);
        ui->AWG->setStyleSheet(UnSelectAWG);
        ui->selectFrame->setGeometry(701,354,10,60);
        break;
    case AWG_WAVE:
        ui->sineBox->setStyleSheet(UnSelectSine);
        ui->squareBox->setStyleSheet(UnSelectSquare);
        ui->rampBox->setStyleSheet(UnSelectRamp);
        ui->triangleBox->setStyleSheet(UnSelectTriangle);
        ui->AWG->setStyleSheet(selectAWG);
        ui->selectFrame->setGeometry(701,454,10,60);

    case SINGLE:
        burstCountEdit->setEnabled(false);
        burstCountEdit->stylesheetSet("color: rgb(255, 255, 255);""background-color: gray;border:1px solid rgba(100,100,100,255);border-radius:5px;");
        burstCountLabel->setEnabled(false);
        burstRateEdit->setEnabled(false);
        burstRateEdit->stylesheetSet("color: rgb(255, 255, 255);""background-color: gray;border:1px solid rgba(100,100,100,255);border-radius:5px;");
        burstRateLabel->setEnabled(false);
        burstCountEdit->setText("1");
/*
        if(m_strWaveType=="TRIANGLE")
             	m_nBurstCount=2;
             else
*/
             	m_nBurstCount=1;
             SetBurstCount(/*m_nBurstCount*/);

        m_bContinuous=false;m_bBurst=false;	m_bSingle=true;m_bGate=false;
        m_bManual=true;m_bInternal=false;m_bExternal=false;

        ui->ManCap->setEnabled(true);ui->INTCap->setEnabled(true);ui->EXTCap->setEnabled(true);
        ui->MANBut->setEnabled(true);ui->INTBut->setEnabled(true);ui->EXTBut->setEnabled(true);

        //ui->MANBut->setStyleSheet(pressed);
        ui->INTBut->setStyleSheet(knobOFF2);
        ui->EXTBut->setStyleSheet(knobOFF2);

        break;
    case CONTINUOUS:
        burstCountEdit->setEnabled(false);
        burstCountEdit->stylesheetSet("color: rgb(255, 255, 255);""background-color: gray;border:1px solid rgba(100,100,100,255);border-radius:5px;");
        burstCountLabel->setEnabled(false);
        burstRateEdit->setEnabled(false);
        burstRateEdit->stylesheetSet("color: rgb(255, 255, 255);""background-color: gray;border:1px solid rgba(100,100,100,255);border-radius:5px;");
        burstRateLabel->setEnabled(false);

        m_bContinuous=true;m_bBurst=false;	m_bSingle=false;m_bGate=false;
        m_bManual=false;m_bInternal=false;m_bExternal=false;

        ui->ManCap->setEnabled(false);ui->INTCap->setEnabled(false);ui->EXTCap->setEnabled(false);
        ui->MANBut->setEnabled(false);ui->INTBut->setEnabled(false);ui->EXTBut->setEnabled(false);

        ui->MANBut->setStyleSheet(knobOFF2);
        ui->INTBut->setStyleSheet(knobOFF2);
        ui->EXTBut->setStyleSheet(knobOFF2);

        break;
    case BURST:
        burstCountEdit->setEnabled(true);
        burstCountEdit->stylesheetSet("color: rgb(255, 255, 255);""background-color: black;border:1px solid rgba(100,100,100,255);border-radius:5px;");
        burstCountLabel->setEnabled(true);
        burstRateEdit->setEnabled(false);
        burstRateEdit->stylesheetSet("color: rgb(255, 255, 255);""background-color: gray;border:1px solid rgba(100,100,100,255);border-radius:5px;");
        burstRateLabel->setEnabled(false);
        burstCountEdit->setText("2");
/*        if(m_strWaveType=="TRIANGLE")
        	m_nBurstCount=4;
        else*/
        	m_nBurstCount=2;
        SetBurstCount(/*m_nBurstCount*/);

        m_bContinuous=false;m_bBurst=true;m_bSingle=false;m_bGate=false;
        m_bManual=true;m_bInternal=false;m_bExternal=false;

        ui->ManCap->setEnabled(true);ui->INTCap->setEnabled(true);ui->EXTCap->setEnabled(true);
        ui->MANBut->setEnabled(true);ui->INTBut->setEnabled(true);ui->EXTBut->setEnabled(true);

        //ui->MANBut->setStyleSheet(pressed);
        ui->INTBut->setStyleSheet(knobOFF2);
        ui->EXTBut->setStyleSheet(knobOFF2);

        break;
    case GATE:
        m_bContinuous=false;m_bBurst=false;	m_bSingle=false;m_bGate=true;
        m_bManual=true;m_bInternal=false;m_bExternal=false;

        ui->ManCap->setEnabled(true);ui->INTCap->setEnabled(true);ui->EXTCap->setEnabled(true);
        ui->MANBut->setEnabled(true);ui->INTBut->setEnabled(true);ui->EXTBut->setEnabled(true);

        //ui->MANBut->setStyleSheet(pressed);
        ui->INTBut->setStyleSheet(knobOFF2);
        ui->EXTBut->setStyleSheet(knobOFF2);
        break;
    case MANUAL:

        burstRateEdit->setEnabled(false);
        burstRateEdit->stylesheetSet("color: rgb(255, 255, 255);""background-color: gray;border:1px solid rgba(100,100,100,255);border-radius:5px;");
        burstRateLabel->setEnabled(false);
        m_bManual=true;m_bInternal=false;m_bExternal=false;

//        ui->MANBut->setStyleSheet(knobON);
          ui->INTBut->setStyleSheet(knobOFF2);
//        ui->EXTBut->setStyleSheet(knobOFF);
        break;
    case INT:

            burstRateEdit->setEnabled(true);
            burstRateEdit->stylesheetSet("color: rgb(255, 255, 255);""background-color: black;border:1px solid rgba(100,100,100,255);border-radius:5px;");
            burstRateLabel->setEnabled(true);

            m_bManual=false;m_bInternal=true;m_bExternal=false;

            ui->MANBut->setStyleSheet("QPushButton{background-color:rgba(0,0,0,0);border:1px solid rgba(0,0,0,0);	image: url(:/res/pb-red.png);}QPushButton::pressed{backgroundcolor:rgba(0,0,0,0);border:1px solid rgba(0,0,0,0);	image: url(:/res/pb-green.png);}QPushButton::released{background-color:rgba(0,0,0,0);border:1px solid rgba(0,0,0,0);image: url(:/res/pb-red.png);}");
            ui->INTBut->setStyleSheet(knobON2);
            ui->EXTBut->setStyleSheet(knobOFF2);
        break;
    case EXT:
        m_bManual=false;m_bInternal=false;m_bExternal=true;

        ui->MANBut->setStyleSheet(knobOFF2);
        ui->INTBut->setStyleSheet(knobOFF2);
        ui->EXTBut->setStyleSheet(knobON2);
        break;

    case SRCHIZ:
        if(m_bHiZ){
            m_bHiZ=false;
            ui->hiZCap->setText("50"+ohms);
            ui->hiZBut->setStyleSheet(pressedOrange);
        }else{
            m_bHiZ=true;
            ui->hiZCap->setText("Hi-Z");
            ui->hiZBut->setStyleSheet(pressed);
        }
        break;
	case RUN_STOP:
        if(m_bRunMode){
            m_bRunMode=false;
            ui->RUNCap->setText("OFF");
            ui->RUNBut->setStyleSheet(knobOFF);
        }else{
            m_bRunMode=true;
            ui->RUNCap->setText("ON");;
            ui->RUNBut->setStyleSheet(knobON);
        }

        break;
    }
}
void FG::on_exit_clicked()
{
    /*	bool ret=showMessageBox(true,true,"Do you want to close FG?","YES","NO");
	if(ret)
		parentWidget()->close();
	else
		msgBox->close();*/
    hwInterface->Drive(STOPDRIVE);
    IGPIOPin->illuminateRunStopButton(1);
    IBackPlane->closeObject();
    IPsoc->resetRelays();
    parentWidget()->close();
}
void FG::on_upBut_clicked() {
    bool ok = true;
    double inputNumber;
    int pIndex=m_nLineEditIndex;
    QString inputText_in = lineEdit[pIndex]->text();
    lineEdit[pIndex]->setFocus();

    if (pIndex == FREQUENCY) {
        if (inputText_in.endsWith("KHz") == true) {
            inputText_in.chop(3);
            inputNumber = inputText_in.toDouble(&ok);
            if (fineCoarse == false)
                inputNumber = inputNumber + 1;
            if (fineCoarse == true)
                inputNumber = inputNumber + 0.1;
            inputNumber = maxMinCheck(maxList.value(pIndex), minList.value(pIndex), inputNumber);
            if (inputNumber < 1000) {
                inputNumber = inputNumber * 1000;
                SetFrequency((floor(inputNumber*100)/100));
                lineEdit[pIndex]->setText(QString::number(inputNumber / 1000)+ "KHz");
                Frequency2Period(QString::number(inputNumber / 1000)+ "KHz");

            } else if (inputNumber >= 1000 && inputNumber < 1000000) {
                inputNumber = inputNumber / 1000;
                inputNumber = inputNumber * 1000000;
                SetFrequency((floor(inputNumber*100)/100));
                lineEdit[pIndex]->setText(QString::number(inputNumber / 1000000) + "MHz");
                Frequency2Period(QString::number(inputNumber / 1000000)+ "MHz");
            }
        }
        if (inputText_in.endsWith("MHz") == true) {
            inputText_in.chop(3);
            inputNumber = inputText_in.toDouble(&ok);
            if(inputNumber<=maxList.value(pIndex)){
                if (fineCoarse == false)
                    inputNumber = inputNumber + 1;
                if (fineCoarse == true)
                    inputNumber = inputNumber + 0.1;

                inputNumber = maxMinCheck(maxList.value(pIndex), minList.value(pIndex), inputNumber);

                if (inputNumber < 1000) {
                    inputNumber = inputNumber * 1000000;
                    SetFrequency((floor(inputNumber*100)/100));
                    lineEdit[pIndex]->setText(QString::number(inputNumber / 1000000) + "MHz");
                    Frequency2Period(QString::number(inputNumber / 1000000)+ "MHz");
                }
            }
        }
        if (inputText_in.endsWith("Hz") == true) {
            inputText_in.chop(2);
            inputNumber = inputText_in.toDouble(&ok);
            if (inputNumber >= 0.01 && inputNumber < 0.1) {
                inputNumber = inputNumber + 0.01;
            } else if (inputNumber >= 0.1 && inputNumber < 1) {
                inputNumber = inputNumber + 0.1;
            } else {
                if (fineCoarse == false)
                    inputNumber = inputNumber + 1;
                if (fineCoarse == true)
                    inputNumber = inputNumber + 0.1;
            }
            inputNumber = maxMinCheck(maxList.value(pIndex), minList.value(pIndex), inputNumber);

            if (inputNumber < 1000) {
                SetFrequency((floor(inputNumber*100)/100));
                lineEdit[pIndex]->setText(QString::number(inputNumber) + "Hz");
                Frequency2Period(QString::number(inputNumber)+ "Hz");
            } else if (inputNumber >= 1000 && inputNumber < 1000000) {
                //				inputNumber = inputNumber * 1000;

                SetFrequency((floor(inputNumber*100)/100));
                lineEdit[pIndex]->setText(QString::number(inputNumber / 1000)+ "KHz");
                Frequency2Period(QString::number(inputNumber / 1000)+ "KHz");

            } else if (inputNumber >= 1000000) {
                inputNumber = inputNumber * 1000000;
                SetFrequency((floor(inputNumber*100)/100));
                lineEdit[pIndex]->setText(QString::number(inputNumber / 1000000) + "MHz");
                Frequency2Period(QString::number(inputNumber / 1000000)+ "MHz");
            }
        }
    }

    else if (pIndex == AMPLITUDE) {
        if (inputText_in.endsWith("mV") == true) {
            inputText_in.chop(2);
            inputNumber = inputText_in.toDouble(&ok);
            if ((inputNumber + Data.offset) < 20) {
                if (fineCoarse == false)
                    inputNumber = inputNumber + 1;
                else if (fineCoarse == true)
                    inputNumber = inputNumber + 0.1;
            }
            inputNumber = maxMinCheck(maxList.value(pIndex), minList.value(pIndex), inputNumber);
            if (inputNumber < 1000) {


                //DDS~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                hwInterface->setAmplitude(inputNumber);
                //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                lineEdit[pIndex]->setText(QString::number(inputNumber) + "mV");
                Data.Amplitude = inputNumber;
            } else if (inputNumber >= 1000 && inputNumber < 1000000) {
                inputNumber = inputNumber / 1000;


                //DDS~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                hwInterface->setAmplitude(inputNumber);
                //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                lineEdit[pIndex]->setText(QString::number(inputNumber) + "Vpp");
                Data.Amplitude = inputNumber;
            }
        } else if (inputText_in.endsWith("uV") == true) {
            inputText_in.chop(2);
            inputNumber = inputText_in.toDouble(&ok);
            if ((inputNumber + Data.offset) < 20) {
                if (fineCoarse == false)
                    inputNumber = inputNumber + 1;
                else if (fineCoarse == true)
                    inputNumber = inputNumber + 0.1;
            }
            inputNumber
                    = maxMinCheck(maxList.value(pIndex), minList.value(pIndex), inputNumber);
            if (inputNumber < 1000) {


                //DDS~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                hwInterface->setAmplitude(inputNumber);
                //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                lineEdit[pIndex]->setText(QString::number(inputNumber) + "uV");
                Data.Amplitude = inputNumber;
            }

            else if (inputNumber >= 1000 && inputNumber < 1000000) {
                inputNumber = inputNumber / 1000;


                //DDS~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                hwInterface->setAmplitude(inputNumber);
                //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                lineEdit[pIndex]->setText(QString::number(inputNumber) + "mV");
                Data.Amplitude = inputNumber;
            } else if (inputNumber >= 1000000) {
                inputNumber = inputNumber / 1000000;


                //DDS~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                hwInterface->setAmplitude(inputNumber);
                //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                lineEdit[pIndex]->setText(QString::number(inputNumber) + "Vpp");
                Data.Amplitude = inputNumber;
            }
        }
        else if (inputText_in.endsWith("Vpp") == true) {
            inputText_in.chop(3);
            inputNumber = inputText_in.toDouble(&ok);
            if ((inputNumber + Data.offset) < 20) {
                if (fineCoarse == false){
                    if(inputNumber<1)
                        inputNumber = inputNumber + 0.1;
                    else
                        inputNumber = inputNumber + 1;
                }
                else if (fineCoarse == true)
                    inputNumber = inputNumber + 0.1;
            }
            inputNumber
                    = maxMinCheck(maxList.value(pIndex), minList.value(pIndex), inputNumber);
            if (inputNumber < 1000) {


                //DDS~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                hwInterface->setAmplitude(inputNumber);
                //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                lineEdit[pIndex]->setText(QString::number(inputNumber) + "Vpp");
                Data.Amplitude = inputNumber;
            }
        }
        m_nAmplitude=inputNumber;
        VppOffset2HighLow(lineEdit[AMPLITUDE]->text(),lineEdit[OFFSET]->text());

    } else if (pIndex == OFFSET) {
        if (inputText_in.endsWith("mV") == true) {
            inputText_in.chop(2);
            inputNumber = inputText_in.toDouble(&ok);
            if ((Data.Amplitude + inputNumber) < 20) {
                if (fineCoarse == false) {
                    if (inputNumber < 1 && inputNumber > -1)
                        inputNumber = inputNumber + 0.1;
                    else
                        inputNumber = inputNumber + 1;
                } else if (fineCoarse == true)
                    inputNumber = inputNumber + 0.1;
            }
            inputNumber = maxMinCheck(maxList.value(pIndex), minList.value(pIndex), inputNumber);
            if (inputNumber < 1000) {
                lineEdit[pIndex]->setText(QString::number(inputNumber) + "mV");
                Data.offset = inputNumber;
            } else if (inputNumber >= 1000 && inputNumber < 1000000) {
                inputNumber = inputNumber / 1000;
                lineEdit[pIndex]->setText(QString::number(inputNumber) + "V");
                Data.offset = inputNumber;
            }
        } else if (inputText_in.endsWith("uV") == true) {
            inputText_in.chop(2);
            inputNumber = inputText_in.toDouble(&ok);
            if ((Data.Amplitude + inputNumber) < 20) {
                if (fineCoarse == false) {
                    if (inputNumber < 1 && inputNumber > -1)
                        inputNumber = inputNumber + 0.1;
                    else
                        inputNumber = inputNumber + 1;
                } else if (fineCoarse == true)
                    inputNumber = inputNumber + 0.1;
            }
            inputNumber = maxMinCheck(maxList.value(pIndex), minList.value(pIndex), inputNumber);
            if (inputNumber < 1000) {
                lineEdit[pIndex]->setText(QString::number(inputNumber) + "uV");
                Data.offset = inputNumber;
            }

            else if (inputNumber >= 1000 && inputNumber < 1000000) {
                inputNumber = inputNumber / 1000;
                lineEdit[pIndex]->setText(QString::number(inputNumber) + "mV");
                Data.offset = inputNumber;
            } else if (inputNumber >= 1000000) {
                inputNumber = inputNumber / 1000000;
                lineEdit[pIndex]->setText(QString::number(inputNumber) + "V");
                Data.offset = inputNumber;
            }
        } else if (inputText_in.endsWith("V") == true) {
            inputText_in.chop(1);
            inputNumber = inputText_in.toDouble(&ok);
            if (inputNumber < 5)
                if ((Data.Amplitude + inputNumber) < 20) {
                if (fineCoarse == false) {
                    if (inputNumber < 1 && inputNumber > -1)
                        inputNumber = inputNumber + 0.1;
                    else
                        inputNumber = inputNumber + 1;
                } else if (fineCoarse == true)
                    inputNumber = inputNumber + 0.1;
            }
            inputNumber = maxMinCheck(maxList.value(pIndex), minList.value(pIndex), inputNumber);
            if (inputNumber < 1000) {
                lineEdit[pIndex]->setText(QString::number(inputNumber) + "V");
                Data.offset = inputNumber;
            }
        }
        //DDS~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        hwInterface->setOffset(inputNumber);
        //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        m_nOffset=inputNumber;
        VppOffset2HighLow(lineEdit[AMPLITUDE]->text(),lineEdit[OFFSET]->text());
    } else if (pIndex == PHASE) {
        QString deg = QChar(0x00B0);
        if (inputText_in.endsWith(deg) == true) {
            inputText_in.chop(1);
            inputNumber = inputText_in.toDouble(&ok);
            inputNumber = inputNumber + 1;
            inputNumber = maxMinCheck(maxList.value(pIndex), minList.value(pIndex), inputNumber);
            lineEdit[pIndex]->setText(QString::number(inputNumber) + deg);
        }
        //DDS-----------------------------------------------------
        hwInterface->setPhase(inputNumber);
        //--------------------------------------------------------

    } /*else if (pIndex == DUTYCYCLE) {
        inputNumber = inputText_in.toDouble(&ok);
        inputNumber = inputNumber + 1;
        inputNumber = maxMinCheck(maxList.value(pIndex)cycle, minList.value(pIndex), inputNumber);
        lineEdit[pIndex]->setText(QString::number(inputNumber));
        m_objFGmodel->setDutyCycle(inputNumber / 100.0);

    } else if (pIndex == SYMMETRY) {
        inputNumber = inputText_in.toDouble(&ok);
        inputNumber = inputNumber + 1;
        inputNumber = maxMinCheck(maxList.value(pIndex), minList.value(pIndex), inputNumber);
        lineEdit[pIndex]->setText(QString::number(inputNumber));
        m_objFGmodel->setSymmetry(inputNumber / 100.0);

    } else if (pIndex == PULSEWIDTH) {
        inputNumber = inputText_in.toDouble(&ok);
        inputNumber = inputNumber + 1;
        inputNumber = maxMinCheck(maxList.value(pIndex), minList.value(pIndex), inputNumber);
        lineEdit[pIndex]->setText(QString::number(inputNumber));
        m_objFGmodel->setPulseWidth(inputNumber);

    } else if (pIndex == DUTY) {
        inputNumber = inputText_in.toDouble(&ok);
        inputNumber = inputNumber + 1;
        inputNumber = maxMinCheck(maxList.value(pIndex), minList.value(pIndex), inputNumber);
        lineEdit[pIndex]->setText(QString::number(inputNumber));
        m_objFGmodel->setDuty(inputNumber / 100);

    } */else if (pIndex == DELAY) {
            inputNumber = inputText_in.toDouble(&ok);
            inputNumber = inputNumber + 1;
            inputNumber = maxMinCheck(maxList.value(pIndex), minList.value(pIndex), inputNumber);
            lineEdit[pIndex]->setText(QString::number(inputNumber));

        } /*else if (pIndex == TEMPERATURE) {

    }*/ else if (pIndex == PERIOD) {
            if (inputText_in.endsWith("msec") == true) {
    		inputText_in.chop(4);
    		inputNumber = inputText_in.toDouble(&ok);
    		if (fineCoarse == false) {
                    if (inputNumber < 1)
                        inputNumber = inputNumber + 0.1;
                    else
                        inputNumber = inputNumber + 1;
    		} else if (fineCoarse == true)
                    inputNumber = inputNumber + 0.1;
    		inputNumber = maxMinCheck(maxList.value(pIndex), minList.value(pIndex), inputNumber);
    		if (inputNumber < 1000) {
                    lineEdit[pIndex]->setText(QString::number(inputNumber) + "msec");
                    Period2Frequency(QString::number(inputNumber) + "msec");
                    inputNumber=inputNumber*0.001;
                    Data.period = inputNumber;

    		} else if (inputNumber >= 1000 && inputNumber < 1000000) {
                    inputNumber = inputNumber / 1000;
                    lineEdit[pIndex]->setText(QString::number(inputNumber) + "sec");
                    Period2Frequency(QString::number(inputNumber) + "sec");
                    inputNumber=inputNumber*1;
                    Data.period = inputNumber;
    		}
            } else if (inputText_in.endsWith("usec") == true) {
    		inputText_in.chop(4);
    		inputNumber = inputText_in.toDouble(&ok);
    		if (fineCoarse == false) {
                    if (inputNumber <= 1)
                        inputNumber = inputNumber + 0.1;
                    else
                        inputNumber = inputNumber + 1;
    		} else if (fineCoarse == true)
                    inputNumber = inputNumber + 0.1;

    		inputNumber = maxMinCheck(maxList.value(pIndex), minList.value(pIndex), inputNumber);
    		if (inputNumber < 1000) {
                    lineEdit[pIndex]->setText(QString::number(inputNumber) + "usec");
                    Period2Frequency(QString::number(inputNumber) + "usec");
                    inputNumber=inputNumber*0.000001;
                    Data.period = inputNumber;
    		}

    		else if (inputNumber >= 1000 && inputNumber < 1000000) {
                    inputNumber = inputNumber / 1000;
                    lineEdit[pIndex]->setText(QString::number(inputNumber) + "msec");\
                            Period2Frequency(QString::number(inputNumber) + "msec");
                    inputNumber=inputNumber*0.001;
                    Data.period = inputNumber;
    		} else if (inputNumber >= 1000000) {
                    inputNumber = inputNumber / 1000000;
                    lineEdit[pIndex]->setText(QString::number(inputNumber) + "sec");
                    Period2Frequency(QString::number(inputNumber) + "sec");
                    inputNumber=inputNumber*1;
                    Data.period = inputNumber;
    		}
            } else if (inputText_in.endsWith("sec") == true) {
    		inputText_in.chop(3);
    		inputNumber = inputText_in.toDouble(&ok);
    		if (fineCoarse == false) {
                    if (inputNumber <= 1)
                        inputNumber = inputNumber + 0.1;
                    else
                        inputNumber = inputNumber + 1;
    		} else if (fineCoarse == true)
                    inputNumber = inputNumber + 0.1;

    		inputNumber = maxMinCheck(maxList.value(pIndex), minList.value(pIndex), inputNumber);
    		if (inputNumber < 1000) {
                    lineEdit[pIndex]->setText(QString::number(inputNumber) + "sec");
                    Period2Frequency(QString::number(inputNumber) + "sec");
                    inputNumber=inputNumber*1;
                    Data.period = inputNumber;
    		}
            }

            //DDS----------------------------------------------------
            //    	hwInterface->setPeriod((floor(inputNumber*100)/100));
            hwInterface->setPeriod(inputNumber);
            //-------------------------------------------------------
            //qDebug() << "set" << Data.period;
            //qDebug() << "setDisplay" << l_nFreq;

        } else if (pIndex == HLEVEL) {
            if (inputText_in.endsWith("V") == true) {
    		inputText_in.chop(1);
    		inputNumber = inputText_in.toDouble(&ok);
    		if (fineCoarse == false) {
                    if (inputNumber < 1 && inputNumber > -1)
                        inputNumber = inputNumber + 0.1;
                    else
                        inputNumber = inputNumber + 1;
    		} else if (fineCoarse == true)
                    inputNumber = inputNumber + 0.1;
    		inputNumber = maxMinCheck(maxList.value(pIndex), minList.value(pIndex), inputNumber);

    		lineEdit[pIndex]->setText(QString::number(inputNumber) + "V");

    		l_lvl = lineEdit[6]->text();
    		l_lvl.chop(1);
    		h_level = inputNumber;
    		l_level = l_lvl.toDouble(&ok);
    		m_level = (h_level - l_level) / 2;
    		hl_offset = m_level + l_level;
    		hwInterface->setOffset(hl_offset);
    		hwInterface->setAmplitude((h_level - l_level));

            }
            m_nAmplitude=h_level-l_level;
            m_nOffset=hl_offset;
            HighLow2VppOffset(lineEdit[HLEVEL]->text(),lineEdit[LLEVEL]->text());
        } else if (pIndex == LLEVEL) {
            if (inputText_in.endsWith("V") == true) {
    		inputText_in.chop(1);
    		inputNumber = inputText_in.toDouble(&ok);

    		if (fineCoarse == false) {
                    if (inputNumber < 1 && inputNumber > -1)
                        inputNumber = inputNumber + 0.1;
                    else
                        inputNumber = inputNumber + 1;
    		} else if (fineCoarse == true)
                    inputNumber = inputNumber + 0.1;
    		inputNumber = maxMinCheck(maxList.value(pIndex), minList.value(pIndex), inputNumber);

    		lineEdit[pIndex]->setText(QString::number(inputNumber) + "V");

    		h_lvl = lineEdit[5]->text();
    		h_lvl.chop(1);
    		h_level = h_lvl.toDouble(&ok);
    		l_level = inputNumber;
    		m_level = (h_level - l_level) / 2;
    		hl_offset = m_level + l_level;

    		hwInterface->setOffset(hl_offset);
    		hwInterface->setAmplitude((h_level - l_level));
            }
            m_nAmplitude=h_level-l_level;
            m_nOffset=hl_offset;
            HighLow2VppOffset(lineEdit[HLEVEL]->text(),lineEdit[LLEVEL]->text());
        }/* else if (pIndex == VARIANCE) {

    } else if (pIndex == MEAN) {

    }*/
    }
void FG::on_downBut_clicked(){

    int pIndex=m_nLineEditIndex;

    bool ok = true;
    double inputNumber;

    QString inputText_in = lineEdit[pIndex]->text();
    //qDebug() << lineEditLabel.value(pIndex) << "down";

    lineEdit[pIndex]->setFocus();

    if (pIndex == FREQUENCY) {
        //		paraUpdate(inputText_in,DEC);
        if ((inputText_in.endsWith("KHz") == true)) {
            inputText_in.chop(3);
            inputNumber = inputText_in.toDouble(&ok);
            if (inputNumber > 0) {
                if (fineCoarse == false) {
                    if (inputNumber <= 1) {
                        inputNumber = inputNumber - 0.1;
                    } else
                        inputNumber = inputNumber - 1;
                }
                if (fineCoarse == true)
                    inputNumber = inputNumber - 0.1;

                inputNumber = maxMinCheck(maxList.value(pIndex), minList.value(pIndex), inputNumber);
            }
            if (inputNumber < 1) {
                inputNumber = (inputNumber * 1000)+99;
                SetFrequency((floor(inputNumber*100)/100));
                lineEdit[pIndex]->setText(QString::number(inputNumber)+ "Hz");
                Frequency2Period(QString::number(inputNumber)+ "Hz");

            } else if (inputNumber >= 1 && inputNumber < 1000) {
                inputNumber = inputNumber * 1000;
                SetFrequency((floor(inputNumber*100)/100));
                lineEdit[pIndex]->setText(QString::number(inputNumber / 1000)+ "KHz");
                Frequency2Period(QString::number(inputNumber / 1000)+ "KHz");

            } else if (inputNumber >= 1000 && inputNumber < 1000000) {
                inputNumber = inputNumber * 1000000;
                SetFrequency((floor(inputNumber*100)/100));
                lineEdit[pIndex]->setText(QString::number(inputNumber / 1000000) + "MHz");
                Frequency2Period(QString::number(inputNumber / 1000000)+ "MHz");
            }
        }
        if (inputText_in.endsWith("MHz") == true) {
            inputText_in.chop(3);
            inputNumber = inputText_in.toDouble(&ok);
            if (inputNumber > 0) {
                if (fineCoarse == false) {
                    if (inputNumber <= 1) {
                        inputNumber = inputNumber - 0.1;
                    } else
                        inputNumber = inputNumber - 1;
                }
                if (fineCoarse == true)
                    inputNumber = inputNumber - 0.1;
                inputNumber = maxMinCheck(maxList.value(pIndex), minList.value(pIndex), inputNumber);
            }

            if (inputNumber < 1) {
                inputNumber = (inputNumber * 1000000)+99000;
                SetFrequency((floor(inputNumber*100)/100));
                lineEdit[pIndex]->setText(QString::number(inputNumber/1000)	+ "KHz");
                Frequency2Period(QString::number(inputNumber / 1000)+ "KHz");

            } else if (inputNumber >= 1 && inputNumber < 1000) {
                inputNumber = inputNumber * 1000000;
                SetFrequency((floor(inputNumber*100)/100));
                lineEdit[pIndex]->setText(QString::number(inputNumber / 1000000) + "MHz");
                Frequency2Period(QString::number(inputNumber / 1000000)+ "MHz");
            }
        }
        if ((inputText_in.endsWith("Hz") == true)) {
            inputText_in.chop(2);
            inputNumber = inputText_in.toDouble(&ok);
            if (inputNumber > 0) {
                if (inputNumber <= 1) {
                    if (inputNumber > 0.1)
                        inputNumber = inputNumber - 0.1;
                    else
                        inputNumber = inputNumber - 0.01;
                } else {
                    if (fineCoarse == false)
                        inputNumber = inputNumber - 1;
                    if (fineCoarse == true)
                        inputNumber = inputNumber - 0.1;
                }
                inputNumber = maxMinCheck(maxList.value(pIndex), minList.value(pIndex), inputNumber);
            }
            if (inputNumber < 1000) {
                SetFrequency((floor(inputNumber*100)/100));
                lineEdit[pIndex]->setText(QString::number(inputNumber) + "Hz");
                Frequency2Period(QString::number(inputNumber)+ "Hz");
            } else if (inputNumber >= 1000 && inputNumber < 1000000) {
                inputNumber = inputNumber * 1000;
                SetFrequency((floor(inputNumber*100)/100));
                lineEdit[pIndex]->setText(QString::number(inputNumber / 1000)+ "KHz");
                Frequency2Period(QString::number(inputNumber / 1000)+ "KHz");

            } else if (inputNumber >= 1000000) {
                inputNumber = inputNumber * 1000000;
                SetFrequency((floor(inputNumber*100)/100));
                lineEdit[pIndex]->setText(QString::number(inputNumber / 1000000) + "MHz");
                Frequency2Period(QString::number(inputNumber / 1000000)+ "MHz");
            }
        }
    }

    else if (pIndex == AMPLITUDE) {
        if (inputText_in.endsWith("mV") == true) {
            inputText_in.chop(2);
            inputNumber = inputText_in.toDouble(&ok);
            if (fineCoarse == false) {
                if (inputNumber <= 1)
                    inputNumber = inputNumber - 0.1;
                else
                    inputNumber = inputNumber - 1;
            } else if (fineCoarse == true)
                inputNumber = inputNumber - 0.1;
            inputNumber
                    = maxMinCheck(maxList.value(pIndex), minList.value(pIndex), inputNumber);
            if (inputNumber < 1000) {


                //DDS~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                hwInterface->setAmplitude(inputNumber);
                //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                lineEdit[pIndex]->setText(QString::number(inputNumber) + "mV");
                Data.Amplitude = inputNumber;
            } else if (inputNumber >= 1000 && inputNumber < 1000000) {
                inputNumber = inputNumber / 1000;


                //DDS~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                hwInterface->setAmplitude(inputNumber);
                //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                lineEdit[pIndex]->setText(QString::number(inputNumber) + "Vpp");
                Data.Amplitude = inputNumber;
            }
        } else if (inputText_in.endsWith("uV") == true) {
            inputText_in.chop(2);
            inputNumber = inputText_in.toDouble(&ok);
            if (fineCoarse == false) {
                if (inputNumber <= 1)
                    inputNumber = inputNumber - 0.1;
                else
                    inputNumber = inputNumber - 1;
            } else if (fineCoarse == true)
                inputNumber = inputNumber - 0.1;

            inputNumber
                    = maxMinCheck(maxList.value(pIndex), minList.value(pIndex), inputNumber);
            if (inputNumber < 1000) {


                //DDS~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                hwInterface->setAmplitude(inputNumber);
                //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                lineEdit[pIndex]->setText(QString::number(inputNumber) + "uV");
                Data.Amplitude = inputNumber;
            }

            else if (inputNumber >= 1000 && inputNumber < 1000000) {
                inputNumber = inputNumber / 1000;


                //DDS~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                hwInterface->setAmplitude(inputNumber);
                //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                lineEdit[pIndex]->setText(QString::number(inputNumber) + "mV");
                Data.Amplitude = inputNumber;
            } else if (inputNumber >= 1000000) {
                inputNumber = inputNumber / 1000000;


                //DDS~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                hwInterface->setAmplitude(inputNumber);
                //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                lineEdit[pIndex]->setText(QString::number(inputNumber) + "Vpp");
                Data.Amplitude = inputNumber;
            }
        } else if (inputText_in.endsWith("Vpp") == true) {
            inputText_in.chop(3);
            inputNumber = inputText_in.toDouble(&ok);
            if (fineCoarse == false) {
                if (inputNumber <= 1)
                    inputNumber = inputNumber - 0.1;
                else
                    inputNumber = inputNumber - 1;
            } else if (fineCoarse == true)
                inputNumber = inputNumber - 0.1;

            inputNumber
                    = maxMinCheck(maxList.value(pIndex), minList.value(pIndex), inputNumber);
            if (inputNumber < 1000) {


                //DDS~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                hwInterface->setAmplitude(inputNumber);
                //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                lineEdit[pIndex]->setText(QString::number(inputNumber) + "Vpp");
                Data.Amplitude = inputNumber;
            }
        }m_nAmplitude=inputNumber;
    } else if (pIndex == OFFSET) {
        if (inputText_in.endsWith("mV") == true) {
            inputText_in.chop(2);
            inputNumber = inputText_in.toDouble(&ok);
            if (fineCoarse == false) {
                if (inputNumber < 1 && inputNumber > -1)
                    inputNumber = inputNumber - 1;
                else
                    inputNumber = inputNumber - 0.1;
            } else if (fineCoarse == true)
                inputNumber = inputNumber - 0.1;

            inputNumber = maxMinCheck(maxList.value(pIndex), minList.value(pIndex), inputNumber);
            if (inputNumber < 1000) {
                lineEdit[pIndex]->setText(QString::number(inputNumber) + "mV");
                Data.offset = inputNumber;
            } else if (inputNumber >= 1000 && inputNumber < 1000000) {
                inputNumber = inputNumber / 1000;
                lineEdit[pIndex]->setText(QString::number(inputNumber) + "V");
                Data.offset = inputNumber;
            }
        } else if (inputText_in.endsWith("uV") == true) {
            inputText_in.chop(2);
            inputNumber = inputText_in.toDouble(&ok);
            if (fineCoarse == false) {
                if (inputNumber < 1 && inputNumber > -1)
                    inputNumber = inputNumber - 0.1;
                else
                    inputNumber = inputNumber - 1;
            } else if (fineCoarse == true)
                inputNumber = inputNumber - 0.1;

            inputNumber = maxMinCheck(maxList.value(pIndex), minList.value(pIndex), inputNumber);
            if (inputNumber < 1000) {
                lineEdit[pIndex]->setText(QString::number(inputNumber) + "uV");
                Data.offset = inputNumber;
            }

            else if (inputNumber >= 1000 && inputNumber < 1000000) {
                inputNumber = inputNumber / 1000;
                lineEdit[pIndex]->setText(QString::number(inputNumber) + "mV");
                Data.offset = inputNumber;
            } else if (inputNumber >= 1000000) {
                inputNumber = inputNumber / 1000000;
                lineEdit[pIndex]->setText(QString::number(inputNumber) + "V");
                Data.offset = inputNumber;
            }
        } else if (inputText_in.endsWith("V") == true) {
            inputText_in.chop(1);
            inputNumber = inputText_in.toDouble(&ok);
            if (inputNumber > -5) {
                if (fineCoarse == false) {
                    if (inputNumber < 1 && inputNumber > -1)
                        inputNumber = inputNumber - 0.1;
                    else
                        inputNumber = inputNumber - 1;
                } else if (fineCoarse == true)
                    inputNumber = inputNumber - 0.1;

                inputNumber = maxMinCheck(maxList.value(pIndex), minList.value(pIndex), inputNumber);
                Data.offset = inputNumber;
            }
            if (inputNumber < 1000)
                lineEdit[pIndex]->setText(QString::number(inputNumber) + "V");
        }

        //DDS~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        hwInterface->setOffset(inputNumber);
        //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        m_nOffset=inputNumber;
    } else if (pIndex == PHASE) {
        QString deg = QChar(0x00B0);
        if (inputText_in.endsWith(deg) == true) {
            inputText_in.chop(1);
            inputNumber = inputText_in.toDouble(&ok);
            if (inputNumber > 0) {
                inputNumber = inputNumber - 1;
                inputNumber = maxMinCheck(maxList.value(pIndex), minList.value(pIndex), inputNumber);
            } else
                inputNumber = 0;
            lineEdit[pIndex]->setText(QString::number(inputNumber) + deg);
        }

        //DDS-----------------------------------------------------
        hwInterface->setPhase(inputNumber);
        //--------------------------------------------------------
    } /*else if (pIndex == DUTYCYCLE) {
        inputNumber = inputText_in.toDouble(&ok);
        inputNumber = inputNumber - 1;
        inputNumber = maxMinCheck(maxList.value(pIndex), minList.value(pIndex), inputNumber);
        lineEdit[pIndex]->setText(QString::number(inputNumber));
        m_objFGmodel->setDutyCycle(inputNumber / 100.0);

    } else if (pIndex == SYMMETRY) {
        inputNumber = inputText_in.toDouble(&ok);
        inputNumber = inputNumber - 1;
        inputNumber = maxMinCheck(maxList.value(pIndex), minList.value(pIndex), inputNumber);
        lineEdit[pIndex]->setText(QString::number(inputNumber));
        m_objFGmodel->setSymmetry(inputNumber / 100.0);

    } else if (pIndex == PULSEWIDTH) {
        inputNumber = inputText_in.toDouble(&ok);
        inputNumber = inputNumber - 1;
        inputNumber = maxMinCheck(maxList.value(pIndex), minList.value(pIndex), inputNumber);
        lineEdit[pIndex]->setText(QString::number(inputNumber));
        m_objFGmodel->setPulseWidth(inputNumber);

    } else if (pIndex == DUTY) {
        inputNumber = inputText_in.toDouble(&ok);
        inputNumber = inputNumber - 1;
        inputNumber = maxMinCheck(maxList.value(pIndex), minList.value(pIndex), inputNumber);
        lineEdit[pIndex]->setText(QString::number(inputNumber));
        m_objFGmodel->setDuty(inputNumber);

    }*/ else if (pIndex == DELAY) {
            inputNumber = inputText_in.toDouble(&ok);
            inputNumber = inputNumber - 1;
            inputNumber = maxMinCheck(maxList.value(pIndex), minList.value(pIndex), inputNumber);
            lineEdit[pIndex]->setText(QString::number(inputNumber));

        }/* else if (pIndex == TEMPERATURE) {

    }*/ else if (pIndex == PERIOD) {
            if (inputText_in.endsWith("msec") == true) {
    		inputText_in.chop(4);
    		inputNumber = inputText_in.toDouble(&ok);
    		if (fineCoarse == false) {
                    if (inputNumber <= 1)
                        inputNumber = inputNumber - 0.1;
                    else
                        inputNumber = inputNumber - 1;
    		} else if (fineCoarse == true)
                    inputNumber = inputNumber - 0.1;

    		inputNumber = maxMinCheck(maxList.value(pIndex), minList.value(pIndex), inputNumber);
    		if (inputNumber < 1000) {
                    lineEdit[pIndex]->setText(QString::number(inputNumber) + "msec");
                    Period2Frequency(QString::number(inputNumber) + "msec");
                    inputNumber=inputNumber*0.001;
                    Data.period = inputNumber;
    		} else if (inputNumber >= 1000 && inputNumber < 1000000) {
                    inputNumber = inputNumber / 1000;
                    lineEdit[pIndex]->setText(QString::number(inputNumber) + "sec");
                    Period2Frequency(QString::number(inputNumber) + "sec");
                    inputNumber=inputNumber*1;
                    Data.period = inputNumber;
    		}
            } else if (inputText_in.endsWith("usec") == true) {
    		inputText_in.chop(4);
    		inputNumber = inputText_in.toDouble(&ok);
    		if (fineCoarse == false) {
                    if (inputNumber <= 1)
                        inputNumber = inputNumber - 0.1;
                    else
                        inputNumber = inputNumber - 1;
    		} else if (fineCoarse == true)
                    inputNumber = inputNumber - 0.1;

    		inputNumber = maxMinCheck(maxList.value(pIndex), minList.value(pIndex), inputNumber);
    		if (inputNumber < 1000) {
                    lineEdit[pIndex]->setText(QString::number(inputNumber) + "usec");
                    Period2Frequency(QString::number(inputNumber) + "usec");
                    inputNumber=inputNumber*0.000001;
                    Data.period = inputNumber;
    		}

    		else if (inputNumber >= 1000 && inputNumber < 1000000) {
                    inputNumber = inputNumber / 1000;
                    lineEdit[pIndex]->setText(QString::number(inputNumber) + "msec");
                    Period2Frequency(QString::number(inputNumber) + "msec");
                    inputNumber=inputNumber*0.001;
                    Data.period = inputNumber;
    		} else if (inputNumber >= 1000000) {
                    inputNumber = inputNumber / 1000000;
                    lineEdit[pIndex]->setText(QString::number(inputNumber) + "sec");
                    Period2Frequency(QString::number(inputNumber) + "sec");
                    inputNumber=inputNumber*1;
                    Data.period = inputNumber;
    		}
            } else if (inputText_in.endsWith("sec") == true) {
    		inputText_in.chop(3);
    		inputNumber = inputText_in.toDouble(&ok);
    		if (fineCoarse == false) {
                    if (inputNumber <= 1)
                        inputNumber = inputNumber - 0.1;
                    else
                        inputNumber = inputNumber - 1;
    		} else if (fineCoarse == true)
                    inputNumber = inputNumber - 0.1;

    		inputNumber = maxMinCheck(maxList.value(pIndex), minList.value(pIndex), inputNumber);
    		inputNumber=inputNumber*1;
    		Data.period = inputNumber;
    		if (inputNumber < 1000) {
                    lineEdit[pIndex]->setText(QString::number(inputNumber) + "sec");
                    Period2Frequency(QString::number(inputNumber) + "sec");
    		}
            }

            //DDS----------------------------------------------------
            //    	hwInterface->setPeriod((floor(inputNumber*100)/100));
            hwInterface->setPeriod(inputNumber);
            //-------------------------------------------------------

        } else if (pIndex == HLEVEL) {
            if (inputText_in.endsWith("V") == true) {
    		inputText_in.chop(1);
    		inputNumber = inputText_in.toDouble(&ok);
    		if (fineCoarse == false) {
                    if (inputNumber < 1 && inputNumber > -1)
                        inputNumber = inputNumber - 0.1;
                    else
                        inputNumber = inputNumber - 1;
    		} else if (fineCoarse == true)
                    inputNumber = inputNumber - 0.1;
    		inputNumber = maxMinCheck(maxList.value(pIndex), minList.value(pIndex), inputNumber);
            }
            lineEdit[pIndex]->setText(QString::number(inputNumber) + "V");

            l_lvl = lineEdit[6]->text();
            l_lvl.chop(1);
            h_level = inputNumber;
            l_level = l_lvl.toDouble(&ok);
            m_level = (h_level - l_level) / 2;
            hl_offset = m_level + l_level;
            hwInterface->setOffset(hl_offset);
            hwInterface->setAmplitude((h_level - l_level));

        } else if (pIndex == LLEVEL) {
            if (inputText_in.endsWith("V") == true) {
    		inputText_in.chop(1);
    		inputNumber = inputText_in.toDouble(&ok);
    		if (fineCoarse == false) {
                    if (inputNumber < 1 && inputNumber > -1)
                        inputNumber = inputNumber - 0.1;
                    else
                        inputNumber = inputNumber - 1;
    		} else if (fineCoarse == true)
                    inputNumber = inputNumber - 0.1;
    		inputNumber = maxMinCheck(maxList.value(pIndex), minList.value(pIndex), inputNumber);
            }
            lineEdit[pIndex]->setText(QString::number(inputNumber) + "V");

            h_lvl = lineEdit[5]->text();
            h_lvl.chop(1);
            h_level = h_lvl.toDouble(&ok);
            l_level = inputNumber;
            m_level = (h_level - l_level) / 2;
            hl_offset = m_level + l_level;
            hwInterface->setOffset(hl_offset);
            hwInterface->setAmplitude((h_level - l_level));

        }/* else if (pIndex == VARIANCE) {

    } else if (pIndex == MEAN) {

    }*/

    }
double FG::maxMinCheck(double max, double min, double value) {
    if (value >= min && value <= max)
        return value;
    else {
        if (value > max) {
            showMessageBox(true,false,"Entered Value is greater than Maximum Value","OK","");
            return max;
        } else if (value < min) {
            showMessageBox(true,false,"Entered Value is lesser than Minimum Value","OK","");
            return min;
        }
    }
    return 0;
}

void FG::on_rightBut_clicked()
{
    //	qDebug()<<"rightBut_clicked";
    for(int i=0;i<8;i++){
        if(lineEdit[i]->hasFocus()){
            if(i!=7){
                lineEdit[i+1]->setFocus();
                m_nLineEditIndex=i+1;
            }
            else{
                lineEdit[0]->setFocus();
                m_nLineEditIndex=0;
            }
            break;
        }
    }
    if(lineEdit[0]->hasFocus()==false&&lineEdit[1]->hasFocus()==false&&lineEdit[2]->hasFocus()==false&&lineEdit[3]->hasFocus()==false&&lineEdit[4]->hasFocus()==false&&lineEdit[5]->hasFocus()==false&&lineEdit[6]->hasFocus()==false&&lineEdit[7]->hasFocus()==false){
        lineEdit[0]->setFocus();
        m_nLineEditIndex=0;
    }
}

void FG::on_leftBut_clicked()
{
    for(int i=0;i<8;i++){
        if(lineEdit[i]->hasFocus()){
            if(i!=0){
                lineEdit[i-1]->setFocus();
                m_nLineEditIndex=i-1;
            }
            else{
                lineEdit[7]->setFocus();
                m_nLineEditIndex=7;
            }
            break;
        }
    }
    if(lineEdit[0]->hasFocus()==false&&lineEdit[1]->hasFocus()==false&&lineEdit[2]->hasFocus()==false&&lineEdit[3]->hasFocus()==false&&lineEdit[4]->hasFocus()==false&&lineEdit[5]->hasFocus()==false&&lineEdit[6]->hasFocus()==false&&lineEdit[7]->hasFocus()==false){
        lineEdit[0]->setFocus();
        m_nLineEditIndex=0;
    }
}

void FG::on_fineCoarse_clicked()
{
    if (fineCoarse == true) {
        fineCoarse = false;
        IGPIOPin->illuminateScaleButton(1);
        ui->fineCoarse->setStyleSheet("QPushButton{background-color:rgba(0,0,0,0);border:1px solid rgba(0,0,0,0);image: url(:/res/coarse.png);}");
    } else {
        fineCoarse = true;
        IGPIOPin->illuminateScaleButton(0);
        ui->fineCoarse->setStyleSheet("QPushButton{background-color:rgba(0,0,0,0);border:1px solid rgba(0,0,0,0);image: url(:/res/fine.png);}");
    }
}
bool FG::showMessageBox(bool ok, bool cancel, QString text, QString okText ="Ok", QString calcelText = "Cancel") {
    msgBoxLive = true;
    msgBox = new QMessageBox(this);
    msgBox->setFont(QFont("DejaVu Sans", 15, 50, false));
    msgBox->setIcon(QMessageBox::Information);
    msgBox->setStyleSheet("color : white;background-color :rgb(88,88,87,255);");
    msgBox->setWindowIcon(QIcon(":/image.png"));
    msgBox->setText(text);
    if (ok == true) {
        connectButton = msgBox->addButton(okText, QMessageBox::YesRole);
        connectButton->setFont(QFont("DejaVu Sans", 20, 50, false));
        connectButton->setStyleSheet("width:20;height;20");
    }
    if (cancel == true) {
        abortButton = msgBox->addButton(calcelText, QMessageBox::NoRole);
        abortButton->setFont(QFont("DejaVu Sans", 20, 50, false));
        abortButton->setStyleSheet("width:20;height;20");
    }
    msgBox->exec();
    if (msgBox->clickedButton() == connectButton) {
        msgBoxLive = false;
        return true;
    }
    if (cancel == true)
        if (msgBox->clickedButton() == abortButton) {
        msgBoxLive = false;
        return false;
    }
    return true;
}

void FG::on_appBckPSoC_clicked()
{
    QWidget *newWidget = test->getPTAppBckPsoc();
    newWidget->setWindowTitle("AppCard BackPanel PSoC Panel");
    newWidget->show();
}

void FG::on_calibrate_clicked()
{
    QWidget *newWidget=REFCalib->getRefCALIB();
    newWidget->setWindowTitle("Reference Calibration Panel");
    newWidget->show();
}

void FG::on_modeBox_currentIndexChanged(int index)
{
    switch(index){
    case 0:
        m_bContinuous = true;
        HighlightButtons(CONTINUOUS);
        GenerateWave();
        hwInterface->setPatternLoop(false);
        hwInterface->SingleContinuous(CONTINUOUS_W);
        hwInterface->Drive(STARTDRIVE);
        IGPIOPin->illuminateRunStopButton(0);
        break;
    case 1:
        m_bContinuous = false;
        HighlightButtons(SINGLE);
        GenerateWave();
        hwInterface->setPatternLoop(false);
        hwInterface->SingleContinuous(SINGLE_W);
        hwInterface->Drive(STOPDRIVE);
        break;
    case 2:
    	m_bContinuous = false;
        HighlightButtons(BURST);
        GenerateWave();
        hwInterface->setPatternLoop(false);
        hwInterface->SingleContinuous(BURST_W);
        hwInterface->Drive(STOPDRIVE);
        for (int i = 0; i < 500; i++){
            IGPIOPin->illuminateRunStopButton(0);
        }	IGPIOPin->illuminateRunStopButton(1);

        if(m_strWaveType=="TRIANGLE"){
            burstRateEdit->setText((convertToUnits(convertToValues(lineEdit[PERIOD]->text())*8))+"sec");
            hwInterface->setBurstRate(m_nPeriod*8);
            SetBurstCount(/*m_nBurstCount*2*/);
        }else{
			burstRateEdit->setText((convertToUnits(convertToValues(lineEdit[PERIOD]->text())*4))+"sec");
			hwInterface->setBurstRate(m_nPeriod*4);
			SetBurstCount(/*m_nBurstCount*/);
        }
        break;
    }
}


