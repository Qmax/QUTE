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
        readCalibrationFile();


}

DACCalibration::~DACCalibration()
{

}
void DACCalibration::loadQmaxPlugins(){
    QPluginLoader loader4("libQmaxPTInterface.so", this);
    ILineEdit = qobject_cast<IQmaxLineEdit*> (loader4.instance());
    INumberPanel = qobject_cast<IQmaxNumberPanel*> (loader4.instance());

}
void DACCalibration::InitializeLineEditControls(){

    m_objLE_NoOfPoints  = ILineEdit->QmaxLineEdit(0, ui.CalibBox);
    m_objLE_ActualValue = ILineEdit->QmaxLineEdit(1, ui.CalibBox);
    m_objLE_RxedValue   = ILineEdit->QmaxLineEdit(2, ui.CalibBox);

    m_objLE_NoOfPoints->setGeometry(110, 50, 70, 25);
    m_objLE_ActualValue->setGeometry(130, 117, 150, 25);
    m_objLE_RxedValue->setGeometry(130, 177, 150, 25);

    m_objLE_NoOfPoints->setStyleSheet("border-width: 2px;border-style: outset;border-color: gray; border-radius: 8px;  padding: 0 8px;     background: white;     selection-background-color: dark gray;   color:black;     font: bold 12px;");
    m_objLE_ActualValue->setStyleSheet("border-width: 2px;border-style: outset;border-color: gray; border-radius: 8px;  padding: 0 8px;     background: white;     selection-background-color: dark gray;   color:black;     font: bold 12px;");
    m_objLE_RxedValue->setStyleSheet("border-width: 2px;border-style: outset;border-color: gray; border-radius: 8px;  padding: 0 8px;     background: white;     selection-background-color: dark gray;   color:black;     font: bold 12px;");

    connect(m_objLE_NoOfPoints, SIGNAL(focussed(bool)), this, SLOT(callNoOfPointsEdit()));
    connect(m_objLE_ActualValue, SIGNAL(focussed(bool)), this, SLOT(callActualValueEdit()));
    connect(m_objLE_RxedValue, SIGNAL(focussed(bool)), this, SLOT(callRxedValueEdit()));

    m_nNoOfPoints=m_nNoOfSamples=0;
    m_nActualValue,m_nRxedValue=0.0;
    m_nslope=m_nconstant=0.0;


    ui.ICM->clear();
    ui.ICM->insertItem(0,"10E");
    ui.ICM->insertItem(1,"100E");
    ui.ICM->insertItem(2,"1KE");
    ui.ICM->insertItem(3,"10KE");
    ui.ICM->insertItem(4,"100KE");
    ui.ICM->insertItem(5,"1ME");

    m_nNoOfSamples=2;
}

void DACCalibration::InitializeCalibration(){
}

void DACCalibration::on_saveBut_clicked()
{
    QString l_strFileName;
            l_strFileName = "ICMCalibration.xml";

    QFile *file = new QFile(l_strFileName);
    if (!file->open(QIODevice::WriteOnly | QIODevice::Text)) {
            return;
    }
    QXmlStreamWriter objCalibration(file);

    objCalibration.setAutoFormatting(true);
    objCalibration.writeStartDocument();

    objCalibration.writeStartElement("Calibration");

    int ICM_Current_Index=ui.ICM->currentIndex();

     for (int l_nGainIndex = 0; l_nGainIndex<ui.comboBox->count(); l_nGainIndex++) {

         for (int l_nValueIndex = 0; l_nValueIndex<(ui.ICM->count()); l_nValueIndex++) {

                 if(ui.comboBox->itemText(l_nGainIndex)=="ICM-R")
                                on_comboBox_currentIndexChanged(0);
                 if(ui.comboBox->itemText(l_nGainIndex)=="ICM-L")
                                on_comboBox_currentIndexChanged(1);
                 if(ui.comboBox->itemText(l_nGainIndex)=="ICM-C")
                        on_comboBox_currentIndexChanged(2);

                    objCalibration.writeStartElement(ui.comboBox->itemText(l_nGainIndex));

                    objCalibration.writeAttribute("Value", ui.ICM->itemText(l_nValueIndex));
                    qDebug()<<"Value"<<ui.ICM->itemText(l_nValueIndex);

                    objCalibration.writeAttribute("Slope", QString::number(m_nSlope[l_nGainIndex][l_nValueIndex],'f',10));
                    qDebug()<<"Gain"<<QString::number(m_nSlope[l_nGainIndex][l_nValueIndex],'f',10);;

                    objCalibration.writeAttribute("Constant", QString::number(m_nConstant[l_nGainIndex][l_nValueIndex],'f',10));
                    qDebug()<<"Constant"<<QString::number(m_nConstant[l_nGainIndex][l_nValueIndex],'f',10);

                    objCalibration.writeStartElement("range");
                    for (int l_nElementIndex = 0; l_nElementIndex < m_nNoOfSamples; l_nElementIndex++) {

                              QString xValue="X"+QString::number(l_nElementIndex+1)+"Value";
                              objCalibration.writeAttribute(xValue, QString::number(XVoltage[l_nGainIndex][l_nValueIndex][l_nElementIndex],'f',15));
                              qDebug()<<"File-XValue:"<<QString::number((XVoltage[l_nGainIndex][l_nValueIndex][l_nElementIndex]),'f',15);

                              QString yValue="Y"+QString::number(l_nElementIndex+1)+"Value";
                              objCalibration.writeAttribute(yValue, QString::number(YVoltage[l_nGainIndex][l_nValueIndex][l_nElementIndex],'f',15));
                              qDebug()<<"File-YValue:"<<QString::number((YVoltage[l_nGainIndex][l_nValueIndex][l_nElementIndex]),'f',15);


                      }
                    objCalibration.writeEndElement();
                    objCalibration.writeEndElement();
                }

            }

    objCalibration.writeEndElement();
    objCalibration.writeEndDocument();

    file->close();

    ui.slope->clear();
    ui.constant->clear();
    m_objLE_NoOfPoints->clear();

    on_comboBox_currentIndexChanged(ICM_Current_Index);
}
void DACCalibration::readCalibrationFile(){

    QString l_strFilename="ICMCalibration.xml";

    QFile *xmlFile= new QFile(l_strFilename);
            if (!xmlFile->open(QIODevice::ReadOnly | QIODevice::Text)) {
                 qDebug()<<"calibration file read error";
            }
            if(!xmlFile->exists()){
                for(int x=0;x<5;x++){           m_nXVoltage[x]=0.0; m_nYVoltage[x]=0.0;
                    for(int y=0;y<9;y++){
                        for(int z=0;z<5;z++){   XVoltage[x][y][z]=0.0;YVoltage[x][y][z]=0.0;
                        } } }


                for(int x=0;x<5;x++){
                       for(int y=0;y<9;y++){       m_nSlope[x][y]=1.0; m_nConstant[x][y]=0.0;
                           for(int z=0;z<5;z++){
                           } } }
            }

            QXmlStreamReader xml(xmlFile);
            short int index=0,RIndex=0,LIndex=0,CIndex=0;
            while(!xml.atEnd() &&  !xml.hasError())
            {
                QXmlStreamReader::TokenType token = xml.readNext();
                QXmlStreamAttributes attributes = xml.attributes();

                if(token == QXmlStreamReader::StartDocument)
                {
                    continue;
                }
                if(xml.isStartElement())
                {

                    if(xml.name()=="ICM-R"){
                                        m_nSlope[0][RIndex]=xml.attributes().value("Slope").toString().toDouble();
                                        m_nConstant[0][RIndex]=xml.attributes().value("Constant").toString().toDouble();

                                        xml.readNextStartElement();
                                        if(xml.isStartElement())
                                        {
                                            if(xml.name()=="range"){
                                                XVoltage[0][RIndex][0]=xml.attributes().value("X1Value").toString().toDouble();
                                                YVoltage[0][RIndex][0]=xml.attributes().value("Y1Value").toString().toDouble();
                                                XVoltage[0][RIndex][1]=xml.attributes().value("X2Value").toString().toDouble();
                                                YVoltage[0][RIndex][1]=xml.attributes().value("Y2Value").toString().toDouble();

                                            }
                                        }

                                        RIndex++;

                                   }
                    if(xml.name()=="ICM-L"){
                                        m_nSlope[1][LIndex]=xml.attributes().value("Slope").toString().toDouble();
                                        m_nConstant[1][LIndex]=xml.attributes().value("Constant").toString().toDouble();
                                        xml.readNextStartElement();
                                        if(xml.isStartElement())
                                        {
                                            if(xml.name()=="range"){
                                                XVoltage[1][LIndex][0]=xml.attributes().value("X1Value").toString().toDouble();
                                                YVoltage[1][LIndex][0]=xml.attributes().value("Y1Value").toString().toDouble();
                                                XVoltage[1][LIndex][1]=xml.attributes().value("X2Value").toString().toDouble();
                                                YVoltage[1][LIndex][1]=xml.attributes().value("Y2Value").toString().toDouble();
                                            }
                                        }
                                        LIndex++;

                                   }
                    if(xml.name()=="ICM-C"){
                                        m_nSlope[2][CIndex]=xml.attributes().value("Slope").toString().toDouble();
                                        m_nConstant[2][CIndex]=xml.attributes().value("Constant").toString().toDouble();
                                        xml.readNextStartElement();
                                        if(xml.isStartElement())
                                        {
                                            if(xml.name()=="range"){
                                                XVoltage[2][CIndex][0]=xml.attributes().value("X1Value").toString().toDouble();
                                                YVoltage[2][CIndex][0]=xml.attributes().value("Y1Value").toString().toDouble();
                                                XVoltage[2][CIndex][1]=xml.attributes().value("X2Value").toString().toDouble();
                                                YVoltage[2][CIndex][1]=xml.attributes().value("Y2Value").toString().toDouble();
                                            }
                                        }
                                        CIndex++;
                                   }

                }
            }
    if(xml.hasError())
            qDebug()<<"xmlFile.xml Parse Error";

    xml.clear();
    xmlFile->close();

    for(int x=0;x<6;x++){
            qDebug()<<"m_nSlope"<<m_nSlope[0][x];
            qDebug()<<"m_nConstant"<<m_nConstant[0][x];
            for(int y=0;y<2;y++){
                qDebug()<<"XVoltage"<<XVoltage[0][x][y];
                qDebug()<<"YVoltage"<<YVoltage[0][x][y];
            }
    }
    for(int x=0;x<7;x++){
            qDebug()<<"m_nSlope"<<m_nSlope[1][x];
            qDebug()<<"m_nConstant"<<m_nConstant[1][x];
            for(int y=0;y<2;y++){
                qDebug()<<"XVoltage"<<XVoltage[1][x][y];
                qDebug()<<"YVoltage"<<YVoltage[1][x][y];
            }
    }
    for(int x=0;x<9;x++){
            qDebug()<<"m_nSlope"<<m_nSlope[2][x];
            qDebug()<<"m_nConstant"<<m_nConstant[2][x];
            for(int y=0;y<2;y++){
                qDebug()<<"XVoltage"<<XVoltage[2][x][y];
                qDebug()<<"YVoltage"<<YVoltage[2][x][y];
            }
    }


}
void DACCalibration::callNoOfPointsEdit(){
    if (m_objLE_NoOfPoints->hasFocus()) {
            openNumKBPanelminmax(1, 'A',10, 0);
            m_nLineEditIndex = 0;
    }
}

void DACCalibration::callActualValueEdit(){
    if (m_objLE_ActualValue->hasFocus()) {
            openNumKBPanelminmax(1, 'A',2000000, 0);
            m_nLineEditIndex = 1;
    }
}

void DACCalibration::callRxedValueEdit(){
    if (m_objLE_RxedValue->hasFocus()) {
            openNumKBPanelminmax(1, 'A',2000000, 0);
            m_nLineEditIndex = 2;
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
        m_nNoOfPoints=m_nNoOfSamples=pValue;
        break;
    case 1:
        m_nActualValue=pValue;
        break;
    case 2:
        m_nRxedValue=pValue;
        break;
    }
}

void DACCalibration::receiveValue(QString pValue){
    switch(m_nLineEditIndex){
    case 0:
    	m_objLE_NoOfPoints->setText(pValue);
        break;
    case 1:
        m_objLE_ActualValue->setText(pValue);
        break;
    case 2:
        m_objLE_RxedValue->setText(pValue);
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
     this->close();
}

void DACCalibration::on_comboBox_currentIndexChanged(int index)
{
    qDebug()<<ui.comboBox->currentText();

    switch(index){
    case 0:
        ui.ICM->clear();
        ui.ICM->insertItem(0,"10E");
        ui.ICM->insertItem(1,"100E");
        ui.ICM->insertItem(2,"1KE");
        ui.ICM->insertItem(3,"10KE");
        ui.ICM->insertItem(4,"100KE");
        ui.ICM->insertItem(5,"1ME");

        break;
    case 1:
        ui.ICM->clear();
        ui.ICM->insertItem(0,"30uH");
        ui.ICM->insertItem(1,"300uH");
        ui.ICM->insertItem(2,"3mH");
        ui.ICM->insertItem(3,"30mH");
        ui.ICM->insertItem(4,"300mH");
        ui.ICM->insertItem(5,"3H");
        ui.ICM->insertItem(6,"30H");

        break;
    case 2:
        ui.ICM->clear();
        ui.ICM->insertItem(0,"100pF");
        ui.ICM->insertItem(1,"1nF");
        ui.ICM->insertItem(2,"10nF");
        ui.ICM->insertItem(3,"100nF");
        ui.ICM->insertItem(4,"1uF");
        ui.ICM->insertItem(5,"10uF");
        ui.ICM->insertItem(6,"100uF");
        ui.ICM->insertItem(7,"1mF");
        ui.ICM->insertItem(8,"10mF");

        break;
    case 3:
        break;
    case 4:
        break;
    }

    m_nNoOfPoints=m_nNoOfSamples;
}


void DACCalibration::on_nextBut_clicked()
{
	   m_nNoOfPoints--;

	    if(m_nNoOfPoints>=0){

	    	m_nXVoltage[m_nNoOfSamples-(m_nNoOfPoints+1)]=m_nActualValue;
	        qDebug()<<"m_nXVoltage"<<m_nXVoltage[m_nNoOfSamples-m_nNoOfPoints];
	        m_nYVoltage[m_nNoOfSamples-(m_nNoOfPoints+1)]=m_nRxedValue;
	        qDebug()<<"m_nYVoltage"<<m_nYVoltage[m_nNoOfSamples-m_nNoOfPoints];

	        m_objLE_ActualValue->clear();
	        m_objLE_RxedValue->clear();

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

	        m_nslope= ((m_nNoOfSamples*Exy)-(Ex*Ey))/((m_nNoOfSamples*Ex2)-(Ex*Ex));
	        m_nconstant=(Ey-(m_nslope*Ex))/m_nNoOfSamples;

	        qDebug()<<"m_nSlope"<<m_nslope<<"m_nConstant"<<m_nconstant;

                m_nSlope[ui.comboBox->currentIndex()][ui.ICM->currentIndex()]=m_nslope;
                m_nConstant[ui.comboBox->currentIndex()][ui.ICM->currentIndex()]=m_nconstant;

                qDebug()<<"Range"<<ui.comboBox->currentIndex()<<":"<<m_nSlope[ui.comboBox->currentIndex()][ui.ICM->currentIndex()]<<","<<m_nConstant[ui.comboBox->currentIndex()][ui.ICM->currentIndex()];

	        ui.slope->setText(QString::number(m_nslope,'f',5));
	        ui.constant->setText(QString::number(m_nconstant,'f',5));

	        m_objLE_ActualValue->clear();
	        m_objLE_RxedValue->clear();
	    }
                XVoltage[ui.comboBox->currentIndex()][ui.ICM->currentIndex()][m_nNoOfPoints]=m_nActualValue;
                YVoltage[ui.comboBox->currentIndex()][ui.ICM->currentIndex()][m_nNoOfPoints]=m_nRxedValue;
	        ui.samples->setText(QString::number((m_nNoOfSamples-m_nNoOfPoints),10));
	  }
	    if(m_nNoOfPoints==0)
	        m_nNoOfPoints=m_nNoOfSamples;
}

void DACCalibration::on_comboBox_2_currentIndexChanged(int index)
{

}
