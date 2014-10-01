/*
 * Library - Calibration Library
 * Author  - Ravivarman.R
 * Last Updated - 15th Jan 2013
 * Converted into Interface- 5th March 2013
*/

#include "calibrationinterface.h"

CalibrationInterface::CalibrationInterface()
{
	Mapping(SERIALDAC);
    readXmlFile("CurrentCalibration.xml","CurrentRange");

	qDebug()<<"----------------------------CALIBRATION INTERFACE START----------------------------";
}
CalibrationInterface::~CalibrationInterface()
{
	qDebug()<<"----------------------------CALIBRATION INTERFACE ENDS----------------------------";
}
void CalibrationInterface::Mapping(int device){
    if(device==SERIALDAC){
            Ix.insert(R200E,1e-3);
            Ix.insert(R2K,100e-6);
            Ix.insert(R20K,10e-6);
            Ix.insert(R200K,1e-6);
            Ix.insert(R2M,500e-9);
            Ix.insert(R20M,250e-9);

            Ix.insert(R2E,10e-3);
            Ix.insert(R200mE,10e-3);
            Ix.insert(SLR200E,1e-3);

            Rf.insert(R200E,200);
            Rf.insert(R2K,20000);
            Rf.insert(R20K,20000);
            Rf.insert(R200K,2000000);
            Rf.insert(R2M,2000000);
            Rf.insert(R20M,2000000);
            Rf.insert(R2E,200);
            Rf.insert(R200mE,200);
            Rf.insert(SLR200E,200);
   }
}


struct CALIB* CalibrationInterface::ParallelDACCalibration(short range)
{
//	qDebug()<< "Parallel DAC Calibration..";
	CALIB* objCalib = new CALIB();
	objCalib->m_nGain = RxGain.value(range);
	objCalib->m_nConstant = RxConstant.value(range);
	return objCalib;
}

double CalibrationInterface::SerialDACCalibration(short range){
//	qDebug()<<"Inside SerialDACCalibration";
//    Mapping(SERIALDAC);
    double Vout,Vx;
    readXmlFile("CurrentCalibration.xml","CurrentRange");

//    qDebug()<<"Force Current :"<<Ix.value(range)<<"Feedback Resistance :"<<Rf.value(range);

    switch(range){
    case SLR200E:
    case R200E:
    case R2E:
    case R200mE:
//    	Vx=Ix.value(range)*Rf.value(range);
//    	Vout=(Vx-RxConstant.value(0))/RxGain.value(0);
//    	qDebug()<<"Vx:"<<Vx<<"Vout :"<<Vout<<"Gain:"<<RxGain.value(0)<<"Constant:"<<RxConstant.value(0);

    	Vx=(Ix.value(range)-RxConstant.value(0))/RxGain.value(0);
    	Vout=Vx*Rf.value(range);
    	qDebug()<<"Vout :"<<Vout<<"Gain:"<<RxGain.value(0)<<"Constant:"<<RxConstant.value(0);


    	break;
    case R2K:
    case R20K:
//    	Vx=Ix.value(range)*Rf.value(range);
//    	Vout=(Vx-RxConstant.value(1))/RxGain.value(1);
//    	qDebug()<<"Vx:"<<Vx<<"Vout :"<<Vout<<"Gain:"<<RxGain.value(1)<<"Constant:"<<RxConstant.value(1);
    	Vx=(Ix.value(range)-RxConstant.value(1))/RxGain.value(1);
    	Vout=Vx*Rf.value(range);
    	qDebug()<<"Vout :"<<Vout<<"Gain:"<<RxGain.value(1)<<"Constant:"<<RxConstant.value(1);
        break;
    case R200K:
    case R2M:
    case R20M:
//    	Vx=Ix.value(range)*Rf.value(range);
//    	Vout=(Vx-RxConstant.value(2))/RxGain.value(2);
//    	qDebug()<<"Vx:"<<Vx<<"Vout :"<<Vout<<"Gain:"<<RxGain.value(2)<<"Constant:"<<RxConstant.value(2);
    	Vx=(Ix.value(range)-RxConstant.value(2))/RxGain.value(2);
    	Vout=Vx*Rf.value(range);
    	qDebug()<<"Vout :"<<Vout<<"Gain:"<<RxGain.value(2)<<"Constant:"<<RxConstant.value(2);
        break;

}

    return Vout;

}
void CalibrationInterface::readXmlFile(QString fileName,QString startElement){

//    qDebug()<<"FileName"<<fileName<<endl<<"StartElement"<<startElement;
    short int l_nIndex=0;
    QString l_strGain ="";
    QString l_strConstant ="";
    l_strGain = "Slope";l_strConstant = "Constant";
    QFile *xmlFile= new QFile(fileName);
            if (!xmlFile->open(QIODevice::ReadOnly | QIODevice::Text)) {
                 qDebug()<<fileName<<" file read error";
            }
            if(fileName=="CurrentCalibration.xml")
            	l_nIndex = 3;
            else if(fileName=="FGParallelDACCalibration.xml" || fileName=="HSADC1.xml"){
				 l_nIndex = 5;
				 l_strGain = "Gain0_5";l_strConstant = "Constant0_5";
            }
//            qDebug() << "Gain" <<l_strGain <<"Constant:" <<l_strConstant;
                for(short index=0;index<l_nIndex;index++){
                   RxGain.insert(index,1);
                   RxConstant.insert(index,0);
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
                                   if(xml.name() == startElement) {
//                                	   qDebug() << "name:" <<xml.name();
                                            RxGain.insert(index,xml.attributes().value(l_strGain).toString().toDouble());
                                            RxConstant.insert(index,xml.attributes().value(l_strConstant).toString().toDouble());
                                            index++;
                                        }
                }
            }
    if(xml.hasError())
            qDebug()<<fileName<<" Parse Error";

    //close reader and flush file
    xml.clear();
    xmlFile->flush();xmlFile->close();

    for(int i=0;i<RxGain.count();i++){
//        qDebug()<<"Gain :"<<RxGain.value(i);
//        qDebug()<<"Constant"<<RxConstant.value(i);
    }

}

Q_EXPORT_PLUGIN2(InterfaceCalibrationLib, CalibrationInterface);
