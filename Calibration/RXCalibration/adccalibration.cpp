/***********************************************************
***************Created by Ravivarman.R,Qmax*****************
***********************************************************/
#include "adccalibration.h"

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

	m_objAD7190 = new AD7190Component(IAppCard);
    IAppCard->setSPIAppendBit(0xC000);
    m_objAD5318Component = new AD5318Components(IAppCard);

    AD5318_dataTemplate l_nAD5318DW;
   	m_objAD5318Component->resetDAC5318(true);

    m_eSelect = DACF;
    m_objAD5318Component->configureADC5318CW();
    l_nAD5318DW.m_eDACSelect = m_eSelect;
    l_nAD5318DW.m_bCtrlBit = 0;
    l_nAD5318DW.m_nVout = 0.0;
    l_nAD5318DW.m_nVRef = 2.5;
    l_nAD5318DW.m_bUniPolor = true;
    l_nAD5318DW.m_bUniPolor = false;
    m_objAD5318Component->configureADC5318Data(l_nAD5318DW);

    m_eSelect = DACG;
    m_objAD5318Component->configureADC5318CW();
    l_nAD5318DW.m_eDACSelect = m_eSelect;
    m_objAD5318Component->configureADC5318Data(l_nAD5318DW);

    double l_dbDACVoltage;
    l_dbDACVoltage = 1600;
    IAppCard->setSPIAppendBit(0x8000);
   	m_objAD5293Component = new AD5293(IAppCard);
   	m_objAD5293Component->setAD5293Voltage(l_dbDACVoltage);
    m_objAD5293Component->writeAD5293(SPI1);

    IAppCard->setSPIAppendBit(0xC000);

}
void DACCalibration::InitializeLineEditControls(){

    m_objLE_NoOfPoints = ILineEdit->QmaxLineEdit(0, ui.CalibBox);
    m_objLE_DriveVoltage = ILineEdit->QmaxLineEdit(1, ui.CalibBox);
//    m_objLE_RxedVoltage = ILineEdit->QmaxLineEdit(2, ui.CalibBox);
    m_objLE_TestVoltage = ILineEdit->QmaxLineEdit(2, ui.CalibBox);

    m_objLE_NoOfPoints->setGeometry(91, 88, 70, 25);
    m_objLE_DriveVoltage->setGeometry(91,146, 90, 25);
//    m_objLE_RxedVoltage->setGeometry(111, 192, 70, 25);
    m_objLE_TestVoltage->setGeometry(40,314,90,25);

    m_objLE_NoOfPoints->setStyleSheet("border-width: 2px;border-style: outset;border-color: gray; border-radius: 8px;  padding: 0 8px;     background: white;     selection-background-color: dark gray;   color:black;     font: bold 12px;");
    m_objLE_DriveVoltage->setStyleSheet("border-width: 2px;border-style: outset;border-color: gray; border-radius: 8px;  padding: 0 8px;     background: white;     selection-background-color: dark gray;   color:black;     font: bold 12px;");
//    m_objLE_RxedVoltage->setStyleSheet("border-width: 2px;border-style: outset;border-color: gray; border-radius: 8px;  padding: 0 8px;     background: white;     selection-background-color: dark gray;   color:black;     font: bold 12px;");
    m_objLE_TestVoltage->setStyleSheet("border-width: 2px;border-style: outset;border-color: gray; border-radius: 8px;  padding: 0 8px;     background: white;     selection-background-color: dark gray;   color:black;     font: bold 12px;");

    connect(m_objLE_NoOfPoints, SIGNAL(focussed(bool)), this, SLOT(callNoOfPointsEdit()));
    connect(m_objLE_DriveVoltage, SIGNAL(focussed(bool)), this, SLOT(callDriveVoltageEdit()));
//    connect(m_objLE_RxedVoltage, SIGNAL(focussed(bool)), this, SLOT(callRxedVoltageEdit()));
    connect(m_objLE_TestVoltage, SIGNAL(focussed(bool)), this, SLOT(callTestVoltageEdit()));

    m_nConstant=m_nDriveRange=m_nDriveVoltage=m_nRxedVoltage=m_nSlope=0.0;
    m_nNoOfPoints=m_nNoOfSamples=0;

    for(int x=0;x<4;x++)
    	for(int y=0;y<5;y++){
    		m_nXVoltage[x][y]=m_nYVoltage[x][y]=0.0;
    	}

    for(int x=0;x<4;x++)
    	for(int y=0;y<5;y++){
    		m_nRangeSlope[x][y]=1.0;
    		m_nRangeConstant[x][y]=0.0;
    	}

    for(int w=0;w<4;w++)
    	for(int x=0;x<5;x++)
    		for(int y=0;y<5;y++){
    			XVoltage[w][x][y]=0.0;
    			YVoltage[w][x][y]=0.0;
    		}

    for(int i=0;i<5;i++){
    	m_nDrvSlope[i]=1.0;
    	m_nDrvConstant[i]=0.0;
    }

    m_nRangeSlopeRx=1.0;
    m_nRangeConstantRx=0.0;
}
void DACCalibration::GetDriveSlopeConstant(){

    QFile *xmlFile= new QFile("ParallelDACDriveCalibration.xml");
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
                                   if(xml.name() == "VoltageRange") {
                                	   	   m_nDrvSlope[index]=xml.attributes().value("Slope").toString().toDouble();
                                	   	   m_nDrvConstant[index]=xml.attributes().value("Constant").toString().toDouble();
                                	   	   qDebug()<<"DrvSlope:"<<m_nDrvSlope[index]<<"DrvConstant:"<<m_nDrvConstant[index];
                                            index++;
                                        }
                }
            }
    if(xml.hasError())
            qDebug()<<"xmlFile.xml Parse Error";

    //close reader and flush file
    xml.clear();
    xmlFile->close();

}
void DACCalibration::InitializeCalibration(){
    //Switch the relay using PSoC

    //DGGSR,for SL offset disable+0.6Vpp
    IAppCard->writeRegister(0x0000,PT_APPCARD_MODULES::PT_DRRLY_APPCARD_DRGSR);

    //DRSER,Source,Rx1&2 connected to A.H(0,1,2,3,6&7)
    IAppCard->writeRegister(0x0007,PT_APPCARD_MODULES::PT_DRRLY_APPCARD_DRSER);

    //DSAR,Force V+Source Impedance disable
    IAppCard->writeRegister(0x0001,PT_APPCARD_MODULES::PT_DRRLY_APPCARD_DSAR);

    //RAMR,for RAM based drive mode
    IAppCard->writeRegister(0x0000,PT_APPCARD_MODULES::PT_SRAM_APPCARD_RAMR);

    //BTUR,to specify the LSW of basic time unit
    IAppCard->writeRegister(0x0063,PT_APPCARD_MODULES::PT_DRIVE_APPCARD_BTUR);

    //BDR,to specify time of per drive
    IAppCard->writeRegister(0x0009,PT_APPCARD_MODULES::PT_DRIVE_APPCARD_BDR);

    //WDPR,to specify the drive period count
    IAppCard->writeRegister(0x0002,PT_APPCARD_MODULES::PT_DRIVE_APPCARD_DPR);

    //DDSWSELR, for direct DC drive
    IAppCard->writeRegister(0x0001,PT_APPCARD_MODULES::PT_DDS_APPCARD_DDSWSELR);

    //Added on 16thAugust
        IAppCard->writeRegister(0x0000,0x1C);
        IAppCard->writeRegister(0x0000,0x1A);//Loop drive mode
        IAppCard->writeRegister(0x0001,0x94);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(LoopDrive()));

    //RX
    m_nADC=1;
    m_nADCGain=1;
    m_objAD7190->resetADC(m_nADC);
    l_nFactor1 = 0.0;l_nFactor2 = 0.0;l_nAIN = 0.0;

    on_loopbck_clicked(false);

}
void DACCalibration::on_driveBut_clicked()
{
    bool ok;
    whichDrive=CALIBDRIVE;
    //Drive
    m_nGain=(ui.comboBox->currentText().toDouble(&ok))/0.6;

    if(ui.enableDrive->isChecked()){
//    m_nDACOutput=m_nDriveVoltage/m_nGain;
//
//    if(ui.Calibrated_2->isChecked()){
//    	qDebug()<<"Applied Drive Constant:"<<m_nDrvConstant[ui.comboBox->currentIndex()]<<"& Drive Slope:"<<m_nDrvSlope[ui.comboBox->currentIndex()];
//          m_nDACOutput=(m_nDACOutput-(m_nDrvConstant[ui.comboBox->currentIndex()]))/(m_nDrvSlope[ui.comboBox->currentIndex()]);
//      }
//    m_nHexCode=(unsigned int)(((m_nDACOutput+0.6)*(pow(2,14)-1))/(2*0.6));
//
//    qDebug()<<"Gain"<<m_nGain<<"DAC Output"<<m_nDACOutput<<"HexCode"<<hex<<m_nHexCode;
//    //Drive
//	IAppCard->writeRegister(m_nHexCode,0x76);
//    IAppCard->writeRegister(0x0001,PT_APPCARD_MODULES::PT_DRIVE_APPCARD_DCR);
//    sleep(1);
    }
    if(ui.comboBox_3->currentIndex()==0||ui.comboBox_3->currentIndex()==1){
    if(ui.enableReceive->isChecked()){
    //Receive
    m_nModeRegister=0x80060;
    if(m_nADCGain==1)
        m_nConfigurationRegister=0x110;
    else if(m_nADCGain==8)
        m_nConfigurationRegister=0x113;	//Gain 200E,ADC Mea range 256mV
    else if(m_nADCGain==64){
        m_nConfigurationRegister=0x4016; //Gain 2E,ADC Mea range 32mV
    }
    else if(m_nADCGain==128){
        m_nConfigurationRegister=0x4017;//Gain 0.2E,ADC Mea range 16mV
    }
    m_objAD7190->writeADCConfigurationRegister(m_nADC,m_nConfigurationRegister);
    m_objAD7190->writeADCModeRegister(m_nADC,m_nModeRegister);

    IAppCard->writeRegister(0x0020,0x0036);//RX1
    }
    }
    else if(ui.comboBox_3->currentIndex()==4){
    	IAppCard->writeRegister(0x0001,0x0036);//RX1
    }
//Start timer
//    if(timer->isActive()) timer->stop();
    timer->start(100);
}
void DACCalibration::on_driveBut_2_clicked()
{
    bool ok;
    whichDrive=TESTDRIVE;
    //Drive
    m_nGain=(ui.comboBox->currentText().toDouble(&ok))/0.6;
    if(ui.enableDrive->isChecked()){
       m_nDACOutput=m_nDriveVoltage/m_nGain;

       if(ui.Calibrated_2->isChecked()){
             m_nDACOutput=(m_nDACOutput-(m_nDrvConstant[ui.comboBox->currentIndex()]))/(m_nDrvSlope[ui.comboBox->currentIndex()]);
         }

       m_nHexCode=(unsigned int)(((m_nDACOutput+0.6)*(pow(2,14)-1))/(2*0.6));

       qDebug()<<"Gain"<<m_nGain<<"DAC Output"<<m_nDACOutput<<"HexCode"<<m_nHexCode;
    //Drive
	IAppCard->writeRegister(m_nHexCode,PT_APPCARD_MODULES::PT_DDS_APPCARD_DCDR);
    IAppCard->writeRegister(0x0001,PT_APPCARD_MODULES::PT_DRIVE_APPCARD_DCR);
    }
    if(ui.comboBox_3->currentIndex()==0||ui.comboBox_3->currentIndex()==1){
    if(ui.enableReceive->isChecked()){
    //Receive
    m_nModeRegister=0x80060;
    if(m_nADCGain==1)
        m_nConfigurationRegister=0x110;
    else if(m_nADCGain==8)
        m_nConfigurationRegister=0x113;	//Gain 200E,ADC Mea range 256mV
    else if(m_nADCGain==64){
        m_nConfigurationRegister=0x4016; //Gain 2E,ADC Mea range 32mV
    }
    else if(m_nADCGain==128){
        m_nConfigurationRegister=0x4017;//Gain 0.2E,ADC Mea range 16mV
    }
    m_objAD7190->writeADCConfigurationRegister(m_nADC,m_nConfigurationRegister);
    m_objAD7190->writeADCModeRegister(m_nADC,m_nModeRegister);

    IAppCard->writeRegister(0x0020,0x0036);//RX1
    }
    } else if(ui.comboBox_3->currentIndex()==4){
    	IAppCard->writeRegister(0x0001,0x0036);//RX1
    }

//Start timer
     timer->start(100);

}
void DACCalibration::LoopDrive(){
	if(ui.enableReceive->isChecked()){
//	if(ui.loopbck->isChecked()==false){
	//Receive
	if(ui.comboBox_3->currentIndex()==0||ui.comboBox_3->currentIndex()==1){
		m_nADC1Voltage=m_objAD7190->readADCDataRegister(m_nADC) & 0xFFFFFF;
	    qDebug()<<"Hex ADC Code:"<<hex<<m_nADC1Voltage;
	    l_nFactor1 = (m_nADC1Voltage / pow(2, 23)) - 1;
	    l_nFactor2 = (m_nADCGain / 2.048);
	    l_nAIN = l_nFactor1 / l_nFactor2;
	    qDebug()<<"ADC DATA"<<l_nAIN;
	    qDebug()<<"Converted ADC Code:"<<l_nAIN;

	}
	else if(ui.comboBox_3->currentIndex()==4){
		m_nADC1Voltage=IAppCard->readRegister(0x96);

	    qDebug()<<"Hex ADC Code:"<<hex<<m_nADC1Voltage;
	    l_nAIN = ((2*m_nADC1Voltage*0.6)/(pow(2,14)-1))-0.6;
	    qDebug()<<"ADC DATA"<<l_nAIN;
	    bool ok=true;
	    l_nAIN=(ui.comboBox->currentText().toDouble(&ok)/0.6)*l_nAIN;
	    qDebug()<<"Converted ADC Code:"<<l_nAIN;

	}


    if(ui.Calibrated->isChecked()){
    		readADCCalibrationFile(m_nADCGain,m_nDriveRange);
    		l_nAIN=(l_nAIN-(m_nRangeConstantRx))/(m_nRangeSlopeRx);
    }

    m_nRxedVoltage=l_nAIN;

    	if(whichDrive==CALIBDRIVE)
    		ui.lineEdit_3->setText(QString::number(l_nAIN,'f',5));
    	else if(whichDrive==TESTDRIVE)
    		ui.lineEdit_5->setText(QString::number(l_nAIN,'f',5));
//    }else{
//    	ui.lineEdit_3->clear();
//		ui.lineEdit_5->clear();
//    }
	}
}
void DACCalibration::on_nextBut_clicked()
{
    m_nNoOfPoints--;

    if(m_nNoOfPoints>=0){

    	m_nXVoltage[ui.comboBox_2->currentIndex()][m_nNoOfSamples-(m_nNoOfPoints+1)]=m_nDriveVoltage;
        qDebug()<<"m_nXVoltage"<<m_nXVoltage[ui.comboBox_2->currentIndex()][m_nNoOfSamples-m_nNoOfPoints];
        m_nYVoltage[ui.comboBox_2->currentIndex()][m_nNoOfSamples-(m_nNoOfPoints+1)]=m_nRxedVoltage;
        qDebug()<<"m_nYVoltage"<<m_nYVoltage[ui.comboBox_2->currentIndex()][m_nNoOfSamples-m_nNoOfPoints];

        m_objLE_DriveVoltage->clear();
        ui.lineEdit_3->clear();

        if(m_nNoOfPoints==0){

        //Calibration Formula
        double Ex,Ey,Exy,Ex2;
        Ex=Ey=Exy=Ex2=0.0;

        for(int index=0;index<m_nNoOfSamples;index++){
            Ex=Ex+m_nXVoltage[ui.comboBox_2->currentIndex()][index];
            Ey=Ey+m_nYVoltage[ui.comboBox_2->currentIndex()][index];
            Exy=Exy+(m_nXVoltage[ui.comboBox_2->currentIndex()][index]*m_nYVoltage[ui.comboBox_2->currentIndex()][index]);
            Ex2=Ex2+(m_nXVoltage[ui.comboBox_2->currentIndex()][index]*m_nXVoltage[ui.comboBox_2->currentIndex()][index]);
            qDebug()<<index<<" Iterartion :Ex"<<Ex<<"Ey"<<Ey<<"Exy"<<Exy<<"Ex2"<<Ex2;
        }

        qDebug()<<"Final Ex"<<Ex<<"Ey"<<Ey<<"Exy"<<Exy<<"Ex2"<<Ex2;

        m_nSlope= ((m_nNoOfSamples*Exy)-(Ex*Ey))/((m_nNoOfSamples*Ex2)-(Ex*Ex));
        m_nConstant=(Ey-(m_nSlope*Ex))/m_nNoOfSamples;

        qDebug()<<"m_nSlope"<<m_nSlope<<"m_nConstant"<<m_nConstant;

        m_nRangeSlope[ui.comboBox_2->currentIndex()][ui.comboBox->currentIndex()]=m_nSlope;
        m_nRangeConstant[ui.comboBox_2->currentIndex()][ui.comboBox->currentIndex()]=m_nConstant;

        qDebug()<<"Range"<<ui.comboBox->currentIndex()<<":"<<m_nRangeSlope[ui.comboBox_2->currentIndex()][ui.comboBox->currentIndex()]<<","<<m_nRangeConstant[ui.comboBox_2->currentIndex()][ui.comboBox->currentIndex()];

        ui.slope->setText(QString::number(m_nSlope,'f',5));
        ui.constant->setText(QString::number(m_nConstant,'f',5));

        m_objLE_DriveVoltage->clear();
        ui.lineEdit_3->clear();
    }
        XVoltage[ui.comboBox_2->currentIndex()][ui.comboBox->currentIndex()][m_nNoOfPoints]=m_nDriveVoltage;
        YVoltage[ui.comboBox_2->currentIndex()][ui.comboBox->currentIndex()][m_nNoOfPoints]=m_nRxedVoltage;
        ui.samples->setText(QString::number((m_nNoOfSamples-m_nNoOfPoints),10));
  }
    timer->stop();
//    IAppCard->writeRegister(0x02,0x12);
    ui.lineEdit_3->clear();

}
void DACCalibration::on_saveBut_clicked()
{
    QString l_strFileName;
    if(ui.comboBox_3->currentIndex()==0)
            l_strFileName = "./HAADC1.xml";
    else if(ui.comboBox_3->currentIndex()==1)
    		l_strFileName = "./HAADC2.xml";
    else if(ui.comboBox_3->currentIndex()==4)
    	l_strFileName = "VIADC1.xml";

    QFile *file = new QFile(l_strFileName);
    if (!file->open(QIODevice::WriteOnly | QIODevice::Text)) {
            return;
    }
    QXmlStreamWriter objCalibration(file);

    objCalibration.setAutoFormatting(true);
    objCalibration.writeStartDocument();

    objCalibration.writeStartElement("RXCalibration");
    if(ui.comboBox_3->currentIndex()==4){
//    	  for(int l_nGainIndex=0;l_nGainIndex<ui.comboBox_2->count();l_nGainIndex++)
    	     for (int l_nValueIndex = 0; l_nValueIndex< ui.comboBox->count(); l_nValueIndex++) {
    	                    objCalibration.writeStartElement("VoltageRange");

    	                    objCalibration.writeAttribute("Gain", ui.comboBox_2->itemText(0));
    	                    qDebug()<<"Gain"<<ui.comboBox_2->itemText(0);

    	                    objCalibration.writeAttribute("Value", ui.comboBox->itemText(l_nValueIndex));
    	                    qDebug()<<"Value"<<ui.comboBox->itemText(l_nValueIndex);

    	                    objCalibration.writeAttribute("Slope", QString::number(m_nRangeSlope[0][l_nValueIndex],'f',5));
    	                    qDebug()<<"Slope"<<QString::number(m_nRangeSlope[0][l_nValueIndex],'f',5);;

    	                    objCalibration.writeAttribute("Constant", QString::number(m_nRangeConstant[0][l_nValueIndex],'f',5));
    	                    qDebug()<<"Constant"<<QString::number(m_nRangeConstant[0][l_nValueIndex],'f',5);

    	                    for (int l_nElementIndex = 0; l_nElementIndex < m_nNoOfSamples; l_nElementIndex++) {
    	                            objCalibration.writeStartElement("Voltage");

    	                            objCalibration.writeAttribute("XVoltage", QString::number(XVoltage[0][l_nValueIndex][l_nElementIndex],'f',5));
    	                            qDebug()<<"File-XVoltage:"<<QString::number((XVoltage[0][l_nValueIndex][l_nElementIndex]),'f',5);

    	                            objCalibration.writeAttribute("YVoltage", QString::number(YVoltage[0][l_nValueIndex][l_nElementIndex],'f',5));
    	                            qDebug()<<"File-YVoltage:"<<QString::number((YVoltage[0][l_nValueIndex][l_nElementIndex]),'f',5);

    	                            objCalibration.writeEndElement();
    	                    }

    	                    objCalibration.writeEndElement();
    	            }

    }else{
  for(int l_nGainIndex=0;l_nGainIndex<ui.comboBox_2->count();l_nGainIndex++)
     for (int l_nValueIndex = 0; l_nValueIndex< ui.comboBox->count(); l_nValueIndex++) {
                    objCalibration.writeStartElement("VoltageRange");

                    objCalibration.writeAttribute("Gain", ui.comboBox_2->itemText(l_nGainIndex));
                    qDebug()<<"Gain"<<ui.comboBox_2->itemText(l_nGainIndex);

                    objCalibration.writeAttribute("Value", ui.comboBox->itemText(l_nValueIndex));
                    qDebug()<<"Value"<<ui.comboBox->itemText(l_nValueIndex);

                    objCalibration.writeAttribute("Slope", QString::number(m_nRangeSlope[l_nGainIndex][l_nValueIndex],'f',5));
                    qDebug()<<"Slope"<<QString::number(m_nRangeSlope[l_nGainIndex][l_nValueIndex],'f',5);;

                    objCalibration.writeAttribute("Constant", QString::number(m_nRangeConstant[l_nGainIndex][l_nValueIndex],'f',5));
                    qDebug()<<"Constant"<<QString::number(m_nRangeConstant[l_nGainIndex][l_nValueIndex],'f',5);

                    for (int l_nElementIndex = 0; l_nElementIndex < m_nNoOfSamples; l_nElementIndex++) {
                            objCalibration.writeStartElement("Voltage");

                            objCalibration.writeAttribute("XVoltage", QString::number(XVoltage[l_nGainIndex][l_nValueIndex][l_nElementIndex],'f',5));
                            qDebug()<<"File-XVoltage:"<<QString::number((XVoltage[l_nGainIndex][l_nValueIndex][l_nElementIndex]),'f',5);

                            objCalibration.writeAttribute("YVoltage", QString::number(YVoltage[l_nGainIndex][l_nValueIndex][l_nElementIndex],'f',5));
                            qDebug()<<"File-YVoltage:"<<QString::number((YVoltage[l_nGainIndex][l_nValueIndex][l_nElementIndex]),'f',5);

                            objCalibration.writeEndElement();
                    }

                    objCalibration.writeEndElement();
            }
    }
    objCalibration.writeEndElement();
    objCalibration.writeEndDocument();
    file->close();

    ui.slope->clear();
    ui.constant->clear();
    m_objLE_NoOfPoints->clear();
    timer->stop();
}
void DACCalibration::readADCCalibrationFile(double gainValue,double rangeValue){
    bool ok;
    QString l_strFilename;
    if(ui.comboBox_3->currentIndex()==0)
        l_strFilename = "HAADC1.xml";
    else if(ui.comboBox_3->currentIndex()==1)
        l_strFilename = "HAADC2.xml";
    else if(ui.comboBox_3->currentIndex()==4)
    	l_strFilename = "VIADC1.xml";

    QFile *xmlFile= new QFile(l_strFilename);
            if (!xmlFile->open(QIODevice::ReadOnly | QIODevice::Text)) {
                 qDebug()<<"calibration file read error";
            }
            QXmlStreamReader xml(xmlFile);
            while(!xml.atEnd() &&  !xml.hasError())
            {
                QXmlStreamReader::TokenType token = xml.readNext();
                QXmlStreamAttributes attributes = xml.attributes();
                QString l_strValue = attributes.value("Value").toString();
                QString l_strGain =  attributes.value("Gain").toString();
                if(token == QXmlStreamReader::StartDocument)
                {
                    continue;
                }
                if(l_strGain.toDouble(&ok)==gainValue&&l_strValue.toDouble(&ok)==rangeValue){
                     if(xml.isStartElement()){
                            if(xml.name() == "VoltageRange") {
                                             m_nRangeSlopeRx=xml.attributes().value("Slope").toString().toDouble();
                                             m_nRangeConstantRx=xml.attributes().value("Constant").toString().toDouble();
                                        }
                            }
                 }
            }
    if(xml.hasError())
            qDebug()<<"xmlFile.xml Parse Error";

    //close reader and flush file
    xml.clear();
    xmlFile->close();
}
void DACCalibration::callNoOfPointsEdit(){
    if (m_objLE_NoOfPoints->hasFocus()) {
            openNumKBPanelminmax(1, 'A',10, 0);
            m_nLineEditIndex = 0;
    }
}

void DACCalibration::callDriveVoltageEdit(){
    if (m_objLE_DriveVoltage->hasFocus()) {
            openNumKBPanelminmax(1, 'v',15, -15);
            m_nLineEditIndex = 1;
    }
}

//void DACCalibration::callRxedVoltageEdit(){
//    if (m_objLE_RxedVoltage->hasFocus()) {
//            openNumKBPanelminmax(1, 'v',15, -15);
//            m_nLineEditIndex = 2;
//    }
//}

void DACCalibration::callTestVoltageEdit(){
    if (m_objLE_TestVoltage->hasFocus()) {
            openNumKBPanelminmax(1, 'v',15, -15);
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
        break;
    case 1:
        m_nDriveVoltage=pValue;
        break;
    case 2:
        m_nRxedVoltage=pValue;
        break;
    case 3:
        m_nTestVoltage=pValue;
        break;
    }
}

void DACCalibration::receiveValue(QString pValue){
    switch(m_nLineEditIndex){
    case 0:
        break;
    case 1:
        m_objLE_DriveVoltage->setText(pValue);
        break;
    case 2:
//        m_objLE_RxedVoltage->setText(pValue);
        break;
    case 3:
        m_objLE_TestVoltage->setText(pValue);
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
    if(timer->isActive()) timer->stop();
    this->close();
}

void DACCalibration::on_comboBox_currentIndexChanged(int index)
{
    qDebug()<<"Gain index:"<<index;
	DRGSR setGain;
    switch(index){
    case 0:
    	setGain.m_eVRanges=VOLT_0P5;
        m_nDriveRange=0.6;
        break;
    case 1:
    	setGain.m_eVRanges=VOLT_1P5;
        m_nDriveRange=1.5;
        break;
    case 2:
    	setGain.m_eVRanges=VOLT_3P5;
        m_nDriveRange=3.5;
        break;
    case 3:
    	setGain.m_eVRanges=VOLT_7P0;
        m_nDriveRange=7;
        break;
    case 4:
    	setGain.m_eVRanges=VOLT_13P0;
        m_nDriveRange=13;
        break;
    }
    setGain.m_bSlotFFS=false;

    IAppCard->setDriveReceiveGainRegister(setGain);

    m_nNoOfPoints=m_nNoOfSamples;

    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        double m_nVoltRangeArray[5]={0.6,1.5,3.5,7.0,13.0};
    	double temp=m_nDriveRange;
        if(ui.Calibrated_4->isChecked()){
        	temp=(m_nDriveRange-(m_nRefRangeConstant[ui.comboBox->currentIndex()]))/(m_nRefRangeSlope[ui.comboBox->currentIndex()]);
        }
        double m_nVoltage = 1600/(((temp*0.6)/m_nVoltRangeArray[ui.comboBox->currentIndex()])/0.6);
        IAppCard->setSPIAppendBit(0x8000);
        m_objAD5293Component->setAD5293Voltage(m_nVoltage);
        m_objAD5293Component->writeAD5293(SPI1);
        qDebug()<<"ROut:"<<m_nVoltage;
        IAppCard->setSPIAppendBit(0xC000);

    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
}

void DACCalibration::on_comboBox_2_currentIndexChanged(int index)
{
	switch(index){
	case 0:
		m_nADCGain=1;
		break;
	case 1:
		m_nADCGain=8;
		break;
	case 2:
		m_nADCGain=64;
		break;
	case 3:
		m_nADCGain=128;
		break;
	}


}

void DACCalibration::on_comboBox_3_currentIndexChanged(int index)
{
		ui.label_10->setEnabled(true);
		ui.comboBox_2->setEnabled(true);

	switch(index){
		case HAADC1:
			m_nADC=1;
			break;
		case HAADC2:
			m_nADC=2;
			break;
		case HSADC1:

			break;
		case HSADC2:

			break;
		case VIADC:
			ui.label_10->setEnabled(false);
			ui.comboBox_2->setEnabled(false);
			break;
		}
}

void DACCalibration::on_Calibrated_2_clicked(bool checked)
{
	if(checked){
		qDebug()<<"Drive Calibration Applied";
		GetDriveSlopeConstant();
	}
	else{
		qDebug()<<"Drive Calibration Removed";

	}
}

void DACCalibration::on_loopbck_clicked(bool checked)
{
	if(checked){
		IAppCard->writeRegister(0x0007,0x0034);//RX External Drive
	}
	else{
		if(ui.comboBox_3->currentIndex()==0)
			IAppCard->writeRegister(0x0007,0x0034);//RX1 Loopback with Drive
		else if(ui.comboBox->currentIndex()==1){
			IAppCard->writeRegister(0x0007,0x0034);//RX2 Loopback with Drive
		}
	}
}

void DACCalibration::on_stopBut_clicked()
{
    if(timer->isActive()) timer->stop();
}
void DACCalibration::on_Calibrated_clicked(bool checked)
{
	bool ok;
	if(checked){
	readADCCalibrationFile((ui.comboBox_2->currentText().toDouble(&ok)),(ui.comboBox->currentText().toDouble(&ok)));
	    qDebug()<<"Slope :"<<m_nRangeSlopeRx;
	    qDebug()<<"Constant :"<<m_nRangeConstantRx;
	}

}



void DACCalibration::on_Calibrated_3_clicked(bool checked)
{

}

void DACCalibration::on_checkBox_2_clicked(bool checked)
{

}
void DACCalibration::readRefCalibrationFile(){

    QString l_strFilename="ReferenceDriveCalibration.xml";

    QFile *xmlFile= new QFile(l_strFilename);
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
                                   if(xml.name() == "VoltageRange") {
                                            m_nRefRangeSlope[index]=xml.attributes().value("Slope").toString().toDouble();
                                            m_nRefRangeConstant[index]=xml.attributes().value("Constant").toString().toDouble();
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
        qDebug()<<"Ref Gain :"<<m_nRefRangeSlope[i];
        qDebug()<<"Ref Constant"<<m_nRefRangeConstant[i];
    }

}

void DACCalibration::on_Calibrated_4_clicked(bool checked)
{
	if(checked)
		readRefCalibrationFile();
	else{
		for(int i=0;i<5;i++){
		       	m_nRefRangeConstant[i]=0.0;
		    	m_nRefRangeSlope[i]=1.0;
		    }
	}
}
