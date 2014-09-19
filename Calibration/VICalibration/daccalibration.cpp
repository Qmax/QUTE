#include "daccalibration.h"
#include <qmessagebox.h>
DACCalibration::DACCalibration(QWidget *parent)
    : QWidget(parent)
{

        ui.setupUi(this);
        makeScreenCenter();
        setWindowFlags(Qt::Widget);
        loadQmaxPlugins();
        InitializeLineEditControls();
        InitializeCalibration();
        QMessageBox msgBox;
        msgBox.setText("Switch the PSoC as per connector connected.");
        msgBox.setWindowTitle("Voltage Calibration");
        msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Discard | QMessageBox::Cancel);
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setStyleSheet("background-color:white;grey: black;");
        int ret=msgBox.exec();
        switch (ret) {
          case QMessageBox::Ok:

              break;
          case QMessageBox::Discard:
              msgBox.close();
              break;
          case QMessageBox::Cancel:
        	  this->close();
              break;
          default:
              // should never be reached
              break;
        }

}

DACCalibration::~DACCalibration()
{
	qDebug()<<"VI Calibration Panel Closed";
    IAppCard->writeRegister(0x0002,PT_APPCARD_MODULES::PT_DRIVE_APPCARD_DCR);

}
void DACCalibration::loadQmaxPlugins(){
    QPluginLoader loader4("libQmaxPTInterface.so", this);
    ILineEdit = qobject_cast<IQmaxLineEdit*> (loader4.instance());
    INumberPanel = qobject_cast<IQmaxNumberPanel*> (loader4.instance());

    QPluginLoader loaderApp("libPTApplicationcardInterface.so", this);
    IAppCard = qobject_cast<IApplicationCardInterface*> (loaderApp.instance());
//    qDebug() << "Appcard" << IAppCard;
    IAppCard->setDeviceName(SLOT0);
    IAppCard->enumerateAPPCard();
//    qDebug() << "Code ID:" << hex << IAppCard->readAppCardCodeId();
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
    m_objLE_RxedVoltage = ILineEdit->QmaxLineEdit(2, ui.CalibBox);
    m_objLE_TestVoltage = ILineEdit->QmaxLineEdit(2, ui.CalibBox);

    m_objLE_NoOfPoints->setGeometry(110, 40, 70, 25);
    m_objLE_DriveVoltage->setGeometry(110, 90, 70, 25);
    m_objLE_RxedVoltage->setGeometry(110, 140, 70, 25);
    m_objLE_TestVoltage->setGeometry(110,244,70,25);

    m_objLE_NoOfPoints->setStyleSheet("border-width: 2px;border-style: outset;border-color: gray; border-radius: 8px;  padding: 0 8px;     background: white;     selection-background-color: dark gray;   color:black;     font: bold 12px;");
    m_objLE_DriveVoltage->setStyleSheet("border-width: 2px;border-style: outset;border-color: gray; border-radius: 8px;  padding: 0 8px;     background: white;     selection-background-color: dark gray;   color:black;     font: bold 12px;");
    m_objLE_RxedVoltage->setStyleSheet("border-width: 2px;border-style: outset;border-color: gray; border-radius: 8px;  padding: 0 8px;     background: white;     selection-background-color: dark gray;   color:black;     font: bold 12px;");
    m_objLE_TestVoltage->setStyleSheet("border-width: 2px;border-style: outset;border-color: gray; border-radius: 8px;  padding: 0 8px;     background: white;     selection-background-color: dark gray;   color:black;     font: bold 12px;");

    connect(m_objLE_NoOfPoints, SIGNAL(focussed(bool)), this, SLOT(callNoOfPointsEdit()));
    connect(m_objLE_DriveVoltage, SIGNAL(focussed(bool)), this, SLOT(callDriveVoltageEdit()));
    connect(m_objLE_RxedVoltage, SIGNAL(focussed(bool)), this, SLOT(callRxedVoltageEdit()));
    connect(m_objLE_TestVoltage, SIGNAL(focussed(bool)), this, SLOT(callTestVoltageEdit()));

    connect(ui.comboBox,SIGNAL(currentIndexChanged(int)),ui.comboBox_2,SLOT(setCurrentIndex(int)));
    connect(ui.comboBox_2,SIGNAL(currentIndexChanged(int)),ui.comboBox,SLOT(setCurrentIndex(int)));

    m_nConstant=m_nDriveRange=m_nDriveVoltage=m_nRxedVoltage=m_nSlope=0.0;



    m_nNoOfPoints=m_nNoOfSamples=0;

    for(int i=0;i<5;i++){
    	m_nRangeSlope[i]=m_nRangeConstant[i]=m_nXVoltage[i]=m_nYVoltage[i]=0.0;
    	m_nRefRangeConstant[i]=0.0;
    	m_nRefRangeSlope[i]=1.0;
    }
    for(int x=0;x<5;x++)for(int y=0;y<5;y++){XVoltage[x][y]=0.0;YVoltage[x][y]=0.0;}

    m_objLE_RxedVoltage->setVisible(false);

    on_CalibratedRef_clicked(true);
    on_comboBox_currentIndexChanged(0);
}

void DACCalibration::InitializeCalibration(){
    //Switch the relay using PSoC

    //DGGSR,for SL offset disable+0.6Vpp
    IAppCard->writeRegister(0x0000,PT_APPCARD_MODULES::PT_DRRLY_APPCARD_DRGSR);

    //DRSER,Source,Rx1&2 connected to A.H(0,1,2,3,6&7)
    IAppCard->writeRegister(0x0007,PT_APPCARD_MODULES::PT_DRRLY_APPCARD_DRSER);

    //DSAR,Force V+Source Impedance enable
    IAppCard->writeRegister(0x0001,PT_APPCARD_MODULES::PT_DRRLY_APPCARD_DSAR);

    //RAMR,for RAM based drive mode
    IAppCard->writeRegister(0x0000,PT_APPCARD_MODULES::PT_SRAM_APPCARD_RAMR);

    //BTUR,to specify the LSW of basic time unit
    IAppCard->writeRegister(0x0063,PT_APPCARD_MODULES::PT_DRIVE_APPCARD_BTUR);

    //BDR,to specify time of per drive
    IAppCard->writeRegister(0x0009,PT_APPCARD_MODULES::PT_DRIVE_APPCARD_BDR);

    //WDPR,to specify the drive period count
    IAppCard->writeRegister(0x0001,PT_APPCARD_MODULES::PT_DRIVE_APPCARD_DPR);

    //DDSWSELR, for direct DC drive
    IAppCard->writeRegister(0x0001,PT_APPCARD_MODULES::PT_DDS_APPCARD_DDSWSELR);

    IAppCard->writeRegister(0x0001,0x36);

    //Added on 14thAugust
    IAppCard->writeRegister(0x0000,0x1C);
    IAppCard->writeRegister(0x0100,0x1A);//Loop drive mode
    IAppCard->writeRegister(0x0001,0x94);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(LoopDrive()));

}
void DACCalibration::on_driveBut_clicked()
{
    bool ok;
    IAppCard->setSPIAppendBit(0xC000);

    if(ui.comboBox->currentIndex()!=0)
        	m_nGain=(ui.comboBox->currentText().toDouble(&ok))/0.6;
        else
        	m_nGain=(ui.comboBox->currentText().toDouble(&ok))/0.6;

    m_nDACOutput=m_nDriveVoltage/m_nGain;
    m_nHexCode=(unsigned int)(((m_nDACOutput+0.6)*(pow(2,14)-1))/(2*0.6));

    qDebug()<<"Gain"<<m_nGain<<"DAC Output"<<m_nDACOutput<<"HexCode"<<m_nHexCode;

    if(timer->isActive()) timer->stop();
    timer->start(100);
}
void DACCalibration::on_driveBut_2_clicked()
{
    bool ok;
    IAppCard->setSPIAppendBit(0xC000);

    if(ui.comboBox->currentIndex()!=0)
    	m_nGain=(ui.comboBox->currentText().toDouble(&ok))/0.6;
    else
    	m_nGain=(ui.comboBox->currentText().toDouble(&ok))/0.6;

    m_nDACOutput=m_nTestVoltage/m_nGain;

    m_nHexCode=(unsigned int)(((m_nDACOutput+0.6)*(pow(2,14)-1))/(2*0.6));
    qDebug()<<"Gain"<<m_nGain<<"DAC Output"<<m_nDACOutput<<"HexCode"<<hex<<m_nHexCode;
    if(timer->isActive())
    	timer->stop();
    timer->start(100);
}
void DACCalibration::LoopDrive()
{

    //DCDR, to enter the parallel DAC value(hex code obtained)
    IAppCard->writeRegister(m_nHexCode,PT_APPCARD_MODULES::PT_DDS_APPCARD_DCDR);
    IAppCard->writeRegister(0x0001,PT_APPCARD_MODULES::PT_DRIVE_APPCARD_DCR);

	unsigned int m_nADC1Voltage=IAppCard->readRegister(0x96);

    qDebug()<<"Hex ADC Code:"<<hex<<m_nADC1Voltage;
    double AIN = ((2*m_nADC1Voltage*0.5)/(pow(2,14)-1))-0.5;
    qDebug()<<"ADC DATA"<<AIN;
    ui.label_10->setText(QString::number(AIN,'f',8));
    bool ok=true;
    AIN=(ui.comboBox_2->currentText().toDouble(&ok)/0.4)*AIN;
   qDebug()<<"ADC DATA SCALED"<<AIN;

     if(ui.Calibrated->isChecked()){
          AIN=(AIN-(m_nRangeConstant[ui.comboBox->currentIndex()]))/(m_nRangeSlope[ui.comboBox->currentIndex()]);
          qDebug()<<"ADC Scaled Calibrated Data:"<<AIN;
        }

    if(ui.driveBut_2->hasFocus())
    	ui.lineEdit_5->setText(QString::number(AIN,'f',5));
    else if(ui.driveBut->hasFocus())
    	ui.lineEdit_3->setText(QString::number(AIN,'f',5));
    m_nRxedVoltage=AIN;

}

void DACCalibration::on_nextBut_clicked()
{
    m_nNoOfPoints--;
    if(m_nNoOfPoints>=0)
    {
    	//m_nXVoltage[m_nNoOfSamples-(m_nNoOfPoints+1)]=m_nDriveVoltage;
    	//[[ Elangovan------
    	qDebug()<<"Drive Range:"<<m_nDriveRange;
    	qDebug()<<"XVoltage:"<<m_nDriveVoltage;
    	qDebug()<<"YVoltage:"<<m_nRxedVoltage;
		m_nXVoltage[m_nNoOfSamples-(m_nNoOfPoints+1)]=(m_nDriveVoltage/m_nDriveRange)*0.4;
    	//m_nXVoltage[m_nNoOfSamples-(m_nNoOfPoints+1)]=m_nDriveVoltage;
        qDebug()<<"m_nXVoltage"<<m_nXVoltage[m_nNoOfSamples-m_nNoOfPoints];
        m_nYVoltage[m_nNoOfSamples-(m_nNoOfPoints+1)]=(m_nRxedVoltage/m_nDriveRange)*0.4;
        //m_nYVoltage[m_nNoOfSamples-(m_nNoOfPoints+1)]=m_nRxedVoltage;
        qDebug()<<"m_nYVoltage"<<m_nYVoltage[m_nNoOfSamples-m_nNoOfPoints];
        m_objLE_DriveVoltage->clear();
        m_objLE_RxedVoltage->clear();
        ui.lineEdit_3->clear();

        if(m_nNoOfPoints==0){

        //Calibration Formula
        double Ex,Ey,Exy,Ex2;
        Ex=Ey=Exy=Ex2=0.0;

        for(int index=0;index<m_nNoOfSamples;index++){
            Ex=Ex+m_nXVoltage[index];
            Ey=Ey+m_nYVoltage[index];
            Exy=Exy+(m_nXVoltage[index]*m_nYVoltage[index]);
            Ex2=Ex2+(m_nXVoltage[index]*m_nXVoltage[index]);
            qDebug()<<index<<" Iterartion :Ex"<<Ex<<"Ey"<<Ey<<"Exy"<<Exy<<"Ex2"<<Ex2;
        }

        qDebug()<<"Final Ex"<<Ex<<"Ey"<<Ey<<"Exy"<<Exy<<"Ex2"<<Ex2;

        m_nSlope= ((m_nNoOfSamples*Exy)-(Ex*Ey))/((m_nNoOfSamples*Ex2)-(Ex*Ex));
        m_nConstant=(Ey-(m_nSlope*Ex))/m_nNoOfSamples;

        qDebug()<<"m_nSlope"<<m_nSlope<<"m_nConstant"<<m_nConstant;

        m_nRangeSlope[ui.comboBox->currentIndex()]=m_nSlope;
        m_nRangeConstant[ui.comboBox->currentIndex()]=m_nConstant;

        qDebug()<<"Range"<<ui.comboBox->currentIndex()<<":"<<m_nRangeSlope[ui.comboBox->currentIndex()]<<","<<m_nRangeConstant[ui.comboBox->currentIndex()];

        ui.slope->setText(QString::number(m_nSlope,'f',5));
        ui.constant->setText(QString::number(m_nConstant,'f',5));

        m_objLE_DriveVoltage->clear();
        m_objLE_RxedVoltage->clear();
    }
        //XVoltage[ui.comboBox->currentIndex()][m_nNoOfPoints]=m_nDriveVoltage;
        //YVoltage[ui.comboBox->currentIndex()][m_nNoOfPoints]=m_nRxedVoltage;
        XVoltage[ui.comboBox->currentIndex()][m_nNoOfPoints]=(m_nDriveVoltage/m_nDriveRange)*0.4;
        YVoltage[ui.comboBox->currentIndex()][m_nNoOfPoints]=(m_nRxedVoltage/m_nDriveRange)*0.4;

        ui.samples->setText(QString::number((m_nNoOfSamples-m_nNoOfPoints),10));
  }
    timer->stop();
}
void DACCalibration::on_saveBut_clicked()
{
    QString l_strFileName;
            l_strFileName = "./VIADC1.xml";

    QFile *file = new QFile(l_strFileName);
    if (!file->open(QIODevice::WriteOnly | QIODevice::Text)) {
            return;
    }
    QXmlStreamWriter objCalibration(file);

    objCalibration.setAutoFormatting(true);
    objCalibration.writeStartDocument();

    objCalibration.writeStartElement("VICalibration");

     for (int l_nGainIndex = 0; l_nGainIndex< 5; l_nGainIndex++) {
                    objCalibration.writeStartElement("VoltageRange");

                    objCalibration.writeAttribute("Value", ui.comboBox->itemText(l_nGainIndex));
                    qDebug()<<"Value"<<ui.comboBox->itemText(l_nGainIndex);
                    objCalibration.writeAttribute("Slope", QString::number(m_nRangeSlope[l_nGainIndex],'f',5));
                    qDebug()<<"Gain"<<QString::number(m_nRangeSlope[l_nGainIndex],'f',5);;
                    objCalibration.writeAttribute("Constant", QString::number(m_nRangeConstant[l_nGainIndex],'f',5));
                    qDebug()<<"Constant"<<QString::number(m_nRangeConstant[l_nGainIndex],'f',5);

                    for (int l_nElementIndex = 0; l_nElementIndex < m_nNoOfSamples; l_nElementIndex++) {
                            objCalibration.writeStartElement("Voltage");

                            objCalibration.writeAttribute("XVoltage", QString::number(XVoltage[l_nGainIndex][l_nElementIndex],'f',5));
                            qDebug()<<"File-XVoltage:"<<QString::number((XVoltage[l_nGainIndex][l_nElementIndex]),'f',5);

                            objCalibration.writeAttribute("YVoltage", QString::number(YVoltage[l_nGainIndex][l_nElementIndex],'f',5));
                            qDebug()<<"File-YVoltage:"<<QString::number((YVoltage[l_nGainIndex][l_nElementIndex]),'f',5);

                            objCalibration.writeEndElement();
                    }

                    objCalibration.writeEndElement();
            }

    objCalibration.writeEndElement();
    objCalibration.writeEndDocument();
    file->close();

    ui.slope->clear();
    ui.constant->clear();
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

void DACCalibration::callRxedVoltageEdit(){
    if (m_objLE_RxedVoltage->hasFocus()) {
            openNumKBPanelminmax(1, 'v',15, -15);
            m_nLineEditIndex = 2;
    }
}
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
        m_objLE_RxedVoltage->setText(pValue);
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
//    if(timer->isActive()) timer->stop();
	IAppCard->writeRegister(0x02,0x12);
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
        m_nDriveRange=2;
        break;
    case 2:
    	setGain.m_eVRanges=VOLT_3P5;
        m_nDriveRange=4;
        break;
    case 3:
    	setGain.m_eVRanges=VOLT_7P0;
        m_nDriveRange=8;
        break;
    case 4:
    	setGain.m_eVRanges=VOLT_13P0;
        m_nDriveRange=14;
        break;
    }
    setGain.m_bSlotFFS=false;

    IAppCard->setDriveReceiveGainRegister(setGain);

    m_nNoOfPoints=m_nNoOfSamples;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	double m_nVoltRangeArray[5]={0.6,2,4,8,14};
	double temp=m_nDriveRange;
    if(ui.CalibratedRef->isChecked()){
    	temp=(m_nDriveRange-(m_nRefRangeConstant[ui.comboBox->currentIndex()]))/(m_nRefRangeSlope[ui.comboBox->currentIndex()]);
    	m_nRefYValue=(m_nRefRangeSlope[ui.comboBox->currentIndex()]*0.6)+m_nRefRangeConstant[ui.comboBox->currentIndex()];
//    	qDebug()<<"Ref Y-Value:"<<m_nRefYValue;
    }
    double m_nVoltage = 1600/(((temp*0.6)/m_nVoltRangeArray[ui.comboBox->currentIndex()])/0.6);
    IAppCard->setSPIAppendBit(0x8000);
    m_objAD5293Component->setAD5293Voltage(m_nVoltage);
    m_objAD5293Component->writeAD5293(SPI1);
    qDebug()<<"ROut:"<<m_nVoltage;
    usleep(10000);
    IAppCard->setSPIAppendBit(0xC000);

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
}
void DACCalibration::readParallelDACCalibrationFile(){

    QString l_strFilename="VIADC1.xml";

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

void DACCalibration::on_Calibrated_clicked(bool checked)
{
    if(checked){
           readParallelDACCalibrationFile();
       }
//       else{
//           for(int i=0;i<5;i++){
//               m_nRangeSlope[i]=1.0;
//               m_nRangeConstant[i]=0.0;
//           }
//       }
}

void DACCalibration::on_CalibratedRef_clicked(bool checked)
{
	if(checked)
		readRefCalibrationFile();
//	else{
//		for(int i=0;i<5;i++){
//		       	m_nRefRangeConstant[i]=0.0;
//		    	m_nRefRangeSlope[i]=1.0;
//		    }
//	}
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

void DACCalibration::on_driveBut_3_clicked()
{
    timer->stop();
}
