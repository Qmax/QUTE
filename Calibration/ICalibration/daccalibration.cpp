/***********************************************************
***************Created by Ravivarman.R,Qmax*****************
***********************************************************/
#include "daccalibration.h"

DACCalibration::DACCalibration(QWidget *parent)
    : QWidget(parent)
{

        ui.setupUi(this);
        makeScreenCenter();
        setWindowFlags(Qt::Widget);
        loadQmaxPlugins();
        InitializeLineEditControls();
        InitializeCalibration();

}

DACCalibration::~DACCalibration()
{

}
void DACCalibration::loadQmaxPlugins(){
    QPluginLoader loader4("libQmaxPTInterface.so", this);
    ILineEdit = qobject_cast<IQmaxLineEdit*> (loader4.instance());
    INumberPanel = qobject_cast<IQmaxNumberPanel*> (loader4.instance());

    QPluginLoader loaderApp("libPTApplicationcardInterface.so", this);
    IAppCard = qobject_cast<IApplicationCardInterface*> (loaderApp.instance());
    IAppCard->setDeviceName(SLOT0);
    IAppCard->enumerateAPPCard();
    qDebug()<<"App Card Code ID:"<<hex<<IAppCard->readAppCardCodeId();
    IAppCard->setSPIAppendBit(0xC000);
    m_objAD5318Component = new AD5318Components(IAppCard);

}
void DACCalibration::InitializeLineEditControls(){

    m_objLE_NoOfPoints = ILineEdit->QmaxLineEdit(0, ui.CalibBox);
    m_objLE_DriveCurrent = ILineEdit->QmaxLineEdit(1, ui.CalibBox);
    m_objLE_RxedCurrent = ILineEdit->QmaxLineEdit(2, ui.CalibBox);
    m_objLE_TestCurrent = ILineEdit->QmaxLineEdit(2, ui.CalibBox);

    m_objLE_RxedCurrent2 = ILineEdit->QmaxLineEdit(4, ui.CalibBox);
    m_objLE_RxedCurrent3 = ILineEdit->QmaxLineEdit(5, ui.CalibBox);

    m_objLE_NoOfPoints->setGeometry(110, 40, 70, 25);
    m_objLE_DriveCurrent->setGeometry(110, 90, 150, 25);
    m_objLE_RxedCurrent->setGeometry(110, 140, 150, 25);
    m_objLE_TestCurrent->setGeometry(70,244,140,25);

    m_objLE_RxedCurrent2->setGeometry(130, 352, 150, 25);
    m_objLE_RxedCurrent3->setGeometry(130, 393, 150, 25);

    m_objLE_NoOfPoints->setStyleSheet("border-width: 2px;border-style: outset;border-color: gray; border-radius: 8px;  padding: 0 8px;     background: white;     selection-background-color: dark gray;   color:black;     font: bold 12px;");
    m_objLE_DriveCurrent->setStyleSheet("border-width: 2px;border-style: outset;border-color: gray; border-radius: 8px;  padding: 0 8px;     background: white;     selection-background-color: dark gray;   color:black;     font: bold 12px;");
    m_objLE_RxedCurrent->setStyleSheet("border-width: 2px;border-style: outset;border-color: gray; border-radius: 8px;  padding: 0 8px;     background: white;     selection-background-color: dark gray;   color:black;     font: bold 12px;");
    m_objLE_TestCurrent->setStyleSheet("border-width: 2px;border-style: outset;border-color: gray; border-radius: 8px;  padding: 0 8px;     background: white;     selection-background-color: dark gray;   color:black;     font: bold 12px;");

    m_objLE_RxedCurrent2->setStyleSheet("border-width: 2px;border-style: outset;border-color: gray; border-radius: 8px;  padding: 0 8px;     background: white;     selection-background-color: dark gray;   color:black;     font: bold 12px;");
    m_objLE_RxedCurrent3->setStyleSheet("border-width: 2px;border-style: outset;border-color: gray; border-radius: 8px;  padding: 0 8px;     background: white;     selection-background-color: dark gray;   color:black;     font: bold 12px;");

    connect(m_objLE_NoOfPoints, SIGNAL(focussed(bool)), this, SLOT(callNoOfPointsEdit()));
    connect(m_objLE_DriveCurrent, SIGNAL(focussed(bool)), this, SLOT(callDriveCurrentEdit()));
    connect(m_objLE_RxedCurrent, SIGNAL(focussed(bool)), this, SLOT(callRxedCurrentEdit()));
    connect(m_objLE_TestCurrent, SIGNAL(focussed(bool)), this, SLOT(callTestCurrentEdit()));

    connect(m_objLE_RxedCurrent2, SIGNAL(focussed(bool)), this, SLOT(callRxedCurrentEdit2()));
    connect(m_objLE_RxedCurrent3, SIGNAL(focussed(bool)), this, SLOT(callRxedCurrentEdit3()));

    m_nConstant=m_nDriveRange=m_nDriveCurrent=m_nRxedCurrent=m_nSlope=0.0;
    m_nNoOfPoints=m_nNoOfSamples=0;

    for(int i=0;i<5;i++) {m_nRangeSlope[i]=1.0;m_nRangeConstant[i]=0.0;m_nXCurrent[i]=m_nYCurrent[i]=0.0;}
    for(int x=0;x<5;x++)for(int y=0;y<5;y++){XCurrent[x][y]=0.0;YCurrent[x][y]=0.0;}

    micro=QChar(0x00B5);

    m_mapResistance.insert(0, 200);
    m_mapResistance.insert(1, 20000);
    m_mapResistance.insert(2, 2000000);

    DACDriveRange.insert(0,"200E");
    DACDriveRange.insert(1,"2KE");
    DACDriveRange.insert(2,"20KE");
    DACDriveRange.insert(3,"200KE");
    DACDriveRange.insert(4,"2ME");
    DACDriveRange.insert(5,"20ME");
    DACDriveRange.insert(6,"2E");
}

void DACCalibration::InitializeCalibration(){

	IAppCard->writeRegister(0x000F,0x0016);
	IAppCard->writeRegister(0x0007,0x0034);

    m_objAD5318Component->resetDAC5318(true);   //RESET DAC

    m_eSelect = DACG;
    m_objAD5318Component->configureADC5318CW(); //SELECT DAC
    m_nDACVoltage=0.0;
    LoopDrive();

//    timer = new QTimer(this);
//    connect(timer, SIGNAL(timeout()), this, SLOT(LoopDrive()));

}
void DACCalibration::on_driveBut_clicked()
{
    bool ok;

    switch(ui.comboBox->currentIndex()){
    case 0:
        m_nDACVoltage=(m_objLE_DriveCurrent->text().toDouble(&ok))*200;
    	IAppCard->writeRegister(0x000F,0x0016);

        break;
    case 1:
        m_nDACVoltage=(m_objLE_DriveCurrent->text().toDouble(&ok))*20000;
    	IAppCard->writeRegister(0x000D,0x0016);

        break;
    case 2:
        m_nDACVoltage=(m_objLE_DriveCurrent->text().toDouble(&ok))*2000000;
    	IAppCard->writeRegister(0x000B,0x0016);


        break;
    }

//    if(timer->isActive()) timer->stop();
//    timer->start(100);
    IAppCard->writeRegister(0x0007,0x0034);
    LoopDrive();

}
void DACCalibration::on_driveBut_2_clicked()
{
    bool ok;

    double y,m,x,c;

    x=m_objLE_TestCurrent->text().toDouble(&ok);

    if(ui.Calibrated->isChecked()){
        m=m_nRangeSlope[ui.comboBox->currentIndex()];
        c=m_nRangeConstant[ui.comboBox->currentIndex()];
     	y=(x-c)/m;
    }
    else
    	y=x;

    switch(ui.comboBox->currentIndex()){
    case 0:
       	m_nDACVoltage=y*200;
        IAppCard->writeRegister(0x000F,0x0016);
        break;
    case 1:
       	m_nDACVoltage=y*20000;
    	IAppCard->writeRegister(0x000D,0x0016);
        break;
    case 2:
       	m_nDACVoltage=y*2000000;
    	IAppCard->writeRegister(0x000B,0x0016);
        break;
   	}

//    if(timer->isActive()) timer->stop();
//    timer->start(100);
    IAppCard->writeRegister(0x0007,0x0034);
    LoopDrive();
}
void DACCalibration::readCurrentCalibrationFile(){

    QFile *xmlFile= new QFile("CurrentCalibration.xml");
            if (!xmlFile->open(QIODevice::ReadOnly | QIODevice::Text)) {
                 qDebug()<<"calibration file read error";
            }

            QXmlStreamReader xml(xmlFile);
            short int index=0;
            while(!xml.atEnd() &&  !xml.hasError())
            {
                QXmlStreamReader::TokenType token = xml.readNext();
                QString l_strName = xml.name().toString();
                QXmlStreamAttributes attributes = xml.attributes();
                QString l_strValue = attributes.value("Value").toString();
                if(token == QXmlStreamReader::StartDocument)
                {
                    continue;
                }
                if(xml.isStartElement())
                {
                                   if(xml.name() == "CurrentRange") {
                                            m_nRangeSlope[index]=xml.attributes().value("Slope").toString().toDouble();
                                            m_nRangeConstant[index]=xml.attributes().value("Constant").toString().toDouble();
                                            index++;
                                        }
                }
            }
    if(xml.hasError())
            qDebug()<<"xmlFile.xml Parse Error";

    //close reader and flush file
    xml.clear();
    xmlFile->close();

    for(int i=0;i<index;i++){
        qDebug()<<"Gain :"<<m_nRangeSlope[i];
        qDebug()<<"Constant"<<m_nRangeConstant[i];
    }

}
void DACCalibration::LoopDrive(){
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        if(m_strDriveCurrent=="1m"||m_strDriveCurrent=="1.0m"){
		qDebug()<<DACDriveRange.value(0);
		DACDriveVoltage[0]=m_nDACVoltage;
	}
	if(m_strDriveCurrent=="0.1m"||m_strDriveCurrent==".1m"){
		qDebug()<<DACDriveRange.value(1);
		DACDriveVoltage[1]=m_nDACVoltage;
	}
	if(m_strDriveCurrent=="10u"){
		qDebug()<<DACDriveRange.value(2);
		DACDriveVoltage[2]=m_nDACVoltage;
	}
	if(m_strDriveCurrent=="1u"){
		qDebug()<<DACDriveRange.value(3);
		DACDriveVoltage[3]=m_nDACVoltage;
	}
	if(m_strDriveCurrent=="500n"){
		qDebug()<<DACDriveRange.value(4);
		DACDriveVoltage[4]=m_nDACVoltage;
	}
	if(m_strDriveCurrent=="250n"){
		qDebug()<<DACDriveRange.value(5);
		DACDriveVoltage[5]=m_nDACVoltage;
	}
        if(m_strDriveCurrent=="10m"||m_strDriveCurrent=="10m"){
		qDebug()<<DACDriveRange.value(6);
			DACDriveVoltage[6]=m_nDACVoltage;
	}
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    l_nAD5318DW.m_eDACSelect = m_eSelect;
    l_nAD5318DW.m_bCtrlBit = 0;
    l_nAD5318DW.m_nVout = m_nDACVoltage;
    l_nAD5318DW.m_nVRef = 2.5;
    l_nAD5318DW.m_bUniPolor = false;
    m_objAD5318Component->configureADC5318Data(l_nAD5318DW);
}
void DACCalibration::on_nextBut_clicked()
{
    m_nNoOfPoints--;

    if(m_nNoOfPoints>=0){

    	m_nXCurrent[m_nNoOfSamples-(m_nNoOfPoints+1)]=m_nDriveCurrent;
        qDebug()<<"m_nXCurrent"<<m_nXCurrent[m_nNoOfSamples-m_nNoOfPoints];
        m_nYCurrent[m_nNoOfSamples-(m_nNoOfPoints+1)]=m_nRxedCurrent;
        qDebug()<<"m_nYCurrent"<<m_nYCurrent[m_nNoOfSamples-m_nNoOfPoints];

        m_objLE_DriveCurrent->clear();
        m_objLE_RxedCurrent->clear();

        if(m_nNoOfPoints==0){

        //Calibration Formula
        double Ex,Ey,Exy,Ex2;
        Ex=Ey=Exy=Ex2=0.0;

        for(int index=0;index<m_nNoOfSamples;index++){
            Ex=Ex+m_nXCurrent[index];
            Ey=Ey+m_nYCurrent[index];
            Exy=Exy+(m_nXCurrent[index]*m_nYCurrent[index]);
            Ex2=Ex2+(m_nXCurrent[index]*m_nXCurrent[index]);
            qDebug()<<index<<" Iterartion :Ex"<<Ex<<"Ey"<<Ey<<"Exy"<<Exy<<"Ex2"<<Ex2;
        }

        qDebug()<<"Final Ex"<<Ex<<"Ey"<<Ey<<"Exy"<<Exy<<"Ex2"<<Ex2;

        m_nSlope= ((m_nNoOfSamples*Exy)-(Ex*Ey))/((m_nNoOfSamples*Ex2)-(Ex*Ex));
        m_nConstant=(Ey-(m_nSlope*Ex))/m_nNoOfSamples;

        qDebug()<<"m_nSlope"<<m_nSlope<<"m_nConstant"<<m_nConstant;

        m_nRangeSlope[ui.comboBox->currentIndex()]=m_nSlope;
        m_nRangeConstant[ui.comboBox->currentIndex()]=m_nConstant;

        qDebug()<<"Range"<<ui.comboBox->currentIndex()<<":"<<m_nRangeSlope[ui.comboBox->currentIndex()]<<","<<m_nRangeConstant[ui.comboBox->currentIndex()];

        ui.slope->setText(QString::number(m_nSlope,'f',10));
        ui.constant->setText(QString::number(m_nConstant,'f',10));

        m_objLE_NoOfPoints->clear();
        m_objLE_DriveCurrent->clear();
        m_objLE_RxedCurrent->clear();
    }
        XCurrent[ui.comboBox->currentIndex()][m_nNoOfPoints]=m_nDriveCurrent;
        YCurrent[ui.comboBox->currentIndex()][m_nNoOfPoints]=m_nRxedCurrent;
        ui.samples->setText(QString::number((m_nNoOfSamples-m_nNoOfPoints),10));
  }

}
void DACCalibration::on_saveBut_clicked()
{
    QString l_strFileName;
    l_strFileName = "./CurrentCalibration.xml";

    QFile *file = new QFile(l_strFileName);
    if (!file->open(QIODevice::WriteOnly | QIODevice::Text)) {
            return;
    }
    QXmlStreamWriter objCalibration(file);

    objCalibration.setAutoFormatting(true);
    objCalibration.writeStartDocument();

    objCalibration.writeStartElement("ICalibration");

     for (int l_nGainIndex = 0; l_nGainIndex< 3; l_nGainIndex++) {
    	 	 	 	 objCalibration.writeStartElement("CurrentRange");

                    objCalibration.writeAttribute("Value", ui.comboBox->itemText(l_nGainIndex));
                    qDebug()<<"Value"<<ui.comboBox->itemText(l_nGainIndex);
                    objCalibration.writeAttribute("Slope", QString::number(m_nRangeSlope[l_nGainIndex],'f',10));
                    qDebug()<<"Gain"<<QString::number(m_nRangeSlope[l_nGainIndex],'f',10);;
                    objCalibration.writeAttribute("Constant", QString::number(m_nRangeConstant[l_nGainIndex],'f',10));
                    qDebug()<<"Constant"<<QString::number(m_nRangeConstant[l_nGainIndex],'f',10);

                    for (int l_nElementIndex = 0; l_nElementIndex < m_nNoOfSamples; l_nElementIndex++) {
                            objCalibration.writeStartElement("Current");

                            objCalibration.writeAttribute("XCurrent", QString::number(XCurrent[l_nGainIndex][l_nElementIndex],'f',10));
                            qDebug()<<"File-XCurrent:"<<QString::number((XCurrent[l_nGainIndex][l_nElementIndex]),'f',10);

                            objCalibration.writeAttribute("YCurrent", QString::number(YCurrent[l_nGainIndex][l_nElementIndex],'f',10));
                            qDebug()<<"File-YCurrent:"<<QString::number((YCurrent[l_nGainIndex][l_nElementIndex]),'f',10);

                            objCalibration.writeEndElement();
                    }

                    objCalibration.writeEndElement();
            }

    objCalibration.writeEndElement();
    objCalibration.writeEndDocument();
    file->close();

    ui.slope->clear();
    ui.constant->clear();
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    QFile *file2 = new QFile("DACDriveVoltage.xml");
    if (!file2->open(QIODevice::WriteOnly | QIODevice::Text)) {  return;   }
    QXmlStreamWriter obj(file2);
    obj.setAutoFormatting(true);
    obj.writeStartDocument();
    obj.writeStartElement("DACDriveVoltage");
    for (int Index = 0; Index<= 6; Index++) {
    	obj.writeStartElement("VoltageDrive");
    	obj.writeAttribute("Range", DACDriveRange.value(Index));
    	obj.writeAttribute("Voltage", QString::number(DACDriveVoltage[Index],'f',10));
    	obj.writeEndElement();
    }
    obj.writeEndElement();
    obj.writeEndDocument();
    file2->close();

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
}
void DACCalibration::callNoOfPointsEdit(){
    if (m_objLE_NoOfPoints->hasFocus()) {
            openNumKBPanelminmax(1, 'A',10, 0);
            m_nLineEditIndex = 0;
    }
}

void DACCalibration::callDriveCurrentEdit(){
    if (m_objLE_DriveCurrent->hasFocus()) {
            openNumKBPanelminmax(1, 'A',15, -15);
            m_nLineEditIndex = 1;
    }
}

void DACCalibration::callRxedCurrentEdit(){
    if (m_objLE_RxedCurrent->hasFocus()) {
            openNumKBPanelminmax(1, 'A',15, -15);
            m_nLineEditIndex = 2;
    }
}

void DACCalibration::callRxedCurrentEdit2(){
    if (m_objLE_RxedCurrent2->hasFocus()) {
            openNumKBPanelminmax(1, 'A',15, -15);
            m_nLineEditIndex = 4;
    }
}

void DACCalibration::callRxedCurrentEdit3(){
    if (m_objLE_RxedCurrent3->hasFocus()) {
            openNumKBPanelminmax(1, 'A',15, -15);
            m_nLineEditIndex = 5;
    }
}

void DACCalibration::callTestCurrentEdit(){
    if (m_objLE_TestCurrent->hasFocus()) {
            openNumKBPanelminmax(1, 'A',15, -15);
            m_nLineEditIndex = 3;
    }

}

void DACCalibration::receiveValue(unsigned int pValue){
	Q_UNUSED(pValue)
    switch(m_nLineEditIndex){
    case 0:
        break;
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    }
}

void DACCalibration::receiveValue(double pValue){
    switch(m_nLineEditIndex){
    case 0:
        m_objLE_NoOfPoints->setText(QString::number(pValue,'f',0));
        m_nNoOfPoints=m_nNoOfSamples=pValue;

        ui.slope->clear();
        ui.constant->clear();
        break;
    case 1:
    	m_objLE_DriveCurrent->setText(QString::number(pValue,'f',10));
        m_nDriveCurrent=pValue;
        break;
    case 2:
    	m_objLE_RxedCurrent->setText(QString::number(pValue,'f',10));
        m_nRxedCurrent=pValue;
        break;
    case 3:
    	m_objLE_TestCurrent->setText(QString::number(pValue,'f',10));
        m_nTestCurrent=pValue;
        break;
    case 4:
        m_objLE_RxedCurrent2->setText(QString::number(pValue,'f',10));
        m_nRxedCurrent2=pValue;
        break;
    case 5:
        m_objLE_RxedCurrent3->setText(QString::number(pValue,'f',10));
        m_nRxedCurrent3=pValue;
        break;
    }
}

void DACCalibration::receiveValue(QString pValue){
    switch(m_nLineEditIndex){
    case 0:
        break;
    case 1:
    	m_strDriveCurrent=pValue;
    	qDebug()<<"Drive Current :"<<m_strDriveCurrent<<"A";
        break;
    case 2:

        break;
    case 3:
        break;

    }
}
void DACCalibration::openNumKBPanelminmax(short int pValue, char type,double pMax, double pMin) {
        QWidget *w = INumberPanel->getNumKBPanelIncDec(pValue, 1, type, pMax, pMin,
                        this);
        w->setWindowFlags(Qt::WindowCloseButtonHint | Qt::Dialog);
        w->setStyleSheet("QWidget{background-color:gray;}QLineEdit{border-width: 2px;border-style: outset;border-color: gray; border-radius: 8px;  padding: 0 8px;     background: white;     selection-background-color: dark gray;   color:black;     font: bold 12px;}QPushButton{border: 2px solid #8f8f91;border-radius: 10px;background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #f6f7fa, stop: 1 #dadbde);min-width: 80px;}");
        w->show();

}

void DACCalibration::openNumKBPanel(short int pValue) {
        QWidget *w = INumberPanel->getNumKBPanel(pValue, this);
        w->setWindowFlags(Qt::WindowCloseButtonHint | Qt::Dialog);
        w->show();
}
void DACCalibration::makeScreenCenter(){
    QDesktopWidget *desktop = QApplication::desktop();
    int screenWidth, width;
    int screenHeight, height; int x, y;
    QSize windowSize; screenWidth = desktop->width();
    screenHeight = desktop->height();
    windowSize = size();
    width = windowSize.width();
    height = windowSize.height();
    x = (screenWidth - width) / 2;
    y = (screenHeight - height) / 2;
    y -= 50; move ( x, y );
    setFixedSize(windowSize.width(), windowSize.height());
}

void DACCalibration::on_exitBut_clicked()
{
//    if(timer->isActive()) timer->stop();
    this->close();
}

void DACCalibration::on_comboBox_currentIndexChanged(int index)
{
    qDebug()<<"Index:"<<index;
    switch(index){
    case 0:

        ui.label_7->setText("mA");
        break;
    case 1:

        ui.label_7->setText(micro+"A");
        break;
    case 2:

        ui.label_7->setText(micro+"A");
        break;

    }

    m_nNoOfPoints=m_nNoOfSamples;
}

void DACCalibration::on_Calibrated_clicked(bool checked)
{
    if(checked){
        readCurrentCalibrationFile();
    }
    else{
        for(int i=0;i<5;i++){
            m_nRangeSlope[i]=1.0;
            m_nRangeConstant[i]=0.0;
        }
    }
}

void DACCalibration::on_saveSl_clicked()
{
    QFile outFile;
    outFile.setFileName("slCurValues.txt");
    outFile.open(QIODevice::WriteOnly);
    QTextStream ts(&outFile);
    ts << m_nRxedCurrent3 << endl<< m_nRxedCurrent2 << endl<< m_nRxedCurrent2 << endl;
    QMessageBox::information(this,"Saved","Calibration constant saved.",QMessageBox::Ok);
}

void DACCalibration::on_drive10mA_clicked()
{
    m_nDACVoltage=0.01*200;
    IAppCard->writeRegister(0x000F,0x0016);
    IAppCard->writeRegister(0x0007,0x0034);
    LoopDrive();
}

void DACCalibration::on_drive1mA_clicked()
{
    m_nDACVoltage=0.001*200;
    IAppCard->writeRegister(0x000F,0x0016);
    IAppCard->writeRegister(0x0007,0x0034);
    LoopDrive();
}
