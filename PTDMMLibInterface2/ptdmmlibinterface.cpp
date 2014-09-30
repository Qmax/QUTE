
// Project by Ravivarman.R , Created 04-02-2013

#include "ptdmmlibinterface.h"
#include "math.h"

struct calib{
	double gain,constant;
	bool flag;
}calib_value;

PTDMMLibInterface::PTDMMLibInterface(QObject *parent):QObject(parent)
{
	//    qDebug()<<"----------------------------PTDMM INTERFACE STARTS----------------------------";

	//Library Initializations

	QPluginLoader loaderApp("libPTApplicationcardInterface.so", this);
	IAppCard = qobject_cast<IApplicationCardInterface*> (loaderApp.instance());
	IAppCard->setDeviceName(SLOT0);
	IAppCard->enumerateAPPCard();
	IAppCard->setSPIAppendBit(0xC000);
	m_objAD5318Component = new AD5318Components(IAppCard);
	m_objAD7190 = new AD7190Component(IAppCard);

	QPluginLoader loader7("libCalibrationInterface.so",this);
	ICALIB = qobject_cast<InterfaceCalibrationLib*>(loader7.instance());

		IAppCard->writeRegister(0x0010,0x0048);

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	//Drive initializations

	m_objAD5318Component->resetDAC5318(true);   //RESET DAC

	m_eSelect = DACF;
	m_objAD5318Component->configureADC5318CW();
	m_nDACVoltage=0.0;
	ForceCurrent(0,m_nDACVoltage);

	m_eSelect = DACG;
	m_objAD5318Component->configureADC5318CW();
	m_nDACVoltage=0.0;
	ForceCurrent(0,m_nDACVoltage);

	//Receive initializations
	m_nADC=1;
	m_objAD7190->resetADC(1);

	calib_value.flag=false;

	ADCRxVoltage=0.0;

	values.Data=0.0;
	values.ConvertedData=0.0;

	noOfSamples=1;

	for(int i=0;i<noOfSamples;i++)
		avgRetval[i]=0.0;

	avg=0;
	retval=0;

	qDebug()<<"----------------------------PTDMM INTERFACE STARTS----------------------------";
}
PTDMMLibInterface::~PTDMMLibInterface()
{
	//    qDebug()<<"----------------------------PTDMM INTERFACE ENDS----------------------------";
}
unsigned char PTDMMLibInterface::calibrateDMM(){

	calib_value.gain=1.0;
	calib_value.constant=0.0;

	bool ok;

	QFile *xmlFile= new QFile("HAADC1.xml");
	if (!xmlFile->open(QIODevice::ReadOnly | QIODevice::Text)) {
		qDebug()<<"receive calibration file not available";
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
					calib_value.gain=xml.attributes().value("Slope").toString().toDouble();
					calib_value.constant=xml.attributes().value("Constant").toString().toDouble();
				}
			}
		}
	}
	if(xml.hasError())
		qDebug()<<"receive calibration file error";

	//close reader and flush file
	xml.clear();
	xmlFile->close();

}
void PTDMMLibInterface::ApplyDACOffset(bool apply){
	IAppCard->setSPIAppendBit(0xC000);
	if(iamDMM==false){
		if(apply==true){
			l_nAD5318DW.m_nVout=ADCRxVoltage;//*(-1);
			qDebug()<<"Applied Offset of "<<l_nAD5318DW.m_nVout<<"V";
		}
		else{
			l_nAD5318DW.m_nVout=0.0;
			qDebug()<<"Applied Offset of "<<l_nAD5318DW.m_nVout<<"V";
		}
                m_eSelect = DACF;
		l_nAD5318DW.m_eDACSelect = m_eSelect;
		l_nAD5318DW.m_bCtrlBit = 0;
		l_nAD5318DW.m_nVRef = 2.5;
		l_nAD5318DW.m_bUniPolor = false;
		m_objAD5318Component->configureADC5318CW();
		m_objAD5318Component->configureADC5318Data(l_nAD5318DW);
	}

}
void PTDMMLibInterface::ApplyDACOffset(double apply){
	IAppCard->setSPIAppendBit(0xC000);
	if(iamDMM==false){
		qDebug()<<"Applied Offset of "<<apply<<"V";
		l_nAD5318DW.m_nVout=apply;
                    m_eSelect = DACF;
		l_nAD5318DW.m_eDACSelect = m_eSelect;
		l_nAD5318DW.m_bCtrlBit = 0;
		l_nAD5318DW.m_nVRef = 2.5;
                    l_nAD5318DW.m_bUniPolor = false;
		m_objAD5318Component->configureADC5318CW();
		m_objAD5318Component->configureADC5318Data(l_nAD5318DW);
	}
}
unsigned int PTDMMLibInterface::ForceCurrent(unsigned int irs,double vout){
	Q_UNUSED(irs)
    		//qDebug()<<"Inside Force Current"<<"vout"<<vout;
			IAppCard->setSPIAppendBit(0xC000);
	IAppCard->writeRegister(0x0007,0x0034);
	m_eSelect = DACG;
	m_nDACVoltage=vout;
	l_nAD5318DW.m_eDACSelect = m_eSelect;
	l_nAD5318DW.m_bCtrlBit = 0;
	l_nAD5318DW.m_nVout = m_nDACVoltage;
	l_nAD5318DW.m_nVRef = 2.5;
	l_nAD5318DW.m_bUniPolor = false;
	m_objAD5318Component->configureADC5318CW();
	m_objAD5318Component->configureADC5318Data(l_nAD5318DW);

	return 0;

}
double PTDMMLibInterface::GetADCVoltage(unsigned int type,unsigned int Gain){

	//qDebug()<<"Inside getADCVoltage"<<"Gain"<<Gain;

	short m_nADC=1;
	unsigned int m_nModeRegister=0x88460,m_nConfigurationRegister;

	IAppCard->setSPIAppendBit(0xC000);

	//Configure--------------------------------------------------------------------------
	if(Gain==1){
		if(iamDMM==false)
				m_nConfigurationRegister=0x110;//4010;
		else
			m_nConfigurationRegister=0x110;	//Gain 200E,ADC Mea range 256mV
	}
	else if(Gain==8){
		if(iamDMM==false)
			m_nConfigurationRegister=0x113;//0x4013;
		else
			m_nConfigurationRegister=0x113;	//Gain 200E,ADC Mea range 256mV
	}
	else if(Gain==64){
		if(iamDMM==false)
			m_nConfigurationRegister=0x4016; //Gain 2E,ADC Mea range 32mV
		else
			m_nConfigurationRegister=0x116;
	}
	else if(Gain==128){
		if(iamDMM==false)
			m_nConfigurationRegister=0x117;//0x4017;//Gain 0.2E,ADC Mea range 16mV
		else
			m_nConfigurationRegister=0x117;
	}
	m_objAD7190->writeADCConfigurationRegister(m_nADC,m_nConfigurationRegister);
	m_objAD7190->writeADCModeRegister(m_nADC,m_nModeRegister);
	double l_nGain;
	l_nGain = Gain;
	unsigned int m_nADC1Voltage=m_objAD7190->readADCDataRegister(m_nADC) & 0xFFFFFF;
	unsigned int AIN=0.0;
	double l_nFactor1=0.0,l_nFactor2=0.0,l_nAIN=0.0,c_nAIN=0.0;

		l_nFactor1 = (m_nADC1Voltage / pow(2, 23)) - 1;
		l_nFactor2 = (l_nGain/ 2.048);
		l_nAIN = l_nFactor1 / l_nFactor2;

	ADCRxVoltage=l_nAIN;
	return 0;//AIN;

}
double PTDMMLibInterface::displayResistance(unsigned int rValue)
{
	double ret=999999999;
	unsigned int AIN=0.0;
	double l_nFactor1=0.0,l_nFactor2=0.0,l_nAIN=0.0,c_nAIN=0.0;
	double Resistance=0.0,Resistance1=0.0,Resistance2=0.0;
	double test=0.0;

        //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Force Current~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	IAppCard->writeRegister(0x000F,0x0016);
	if(rValue==SLR200E)
		test=ICALIB->SerialDACCalibration(SLR200E);
	else if(rValue==R2E)
		test=ICALIB->SerialDACCalibration(R2E);
	else if(rValue==R200mE)
		test=ICALIB->SerialDACCalibration(R200mE);
	ForceCurrent(1,test);
	//----------------------------------------------------------------------------------

	usleep(1000);

	for(avg=0;avg<noOfSamples;avg++){

		//05092014//
		AIN=m_objAD7190->readADCDataRegister(m_nADC) & 0xFFFFFF;
		qDebug("ADC Data : %x",AIN);
		if(AIN==overRange){
			return ret;
		}
			l_nFactor1 = (AIN/pow(2,23))-1;
			l_nFactor2 = (1.0 / 2.048);
			l_nAIN = l_nFactor1 / l_nFactor2;
			gainValue=1;rangeValue=3.5;
		avgRetval[avg]=l_nAIN;
		retval=retval+avgRetval[avg];
	}
	avg=0;
	l_nAIN=retval/noOfSamples;
	retval=0;
	qDebug("Converted Data : %f",l_nAIN);

	values.Data=AIN;
	values.ConvertedData=l_nAIN;

	if(calib_value.flag==true){
		calibrateDMM();
		c_nAIN = (l_nAIN - calib_value.constant) / calib_value.gain;
		values.ConvertedData=c_nAIN;
		//qDebug()<<"Calibrated Value :"<<c_nAIN;
	}
	else if(calib_value.flag==false){
		c_nAIN = l_nAIN;
	}

	ADCRxVoltage=l_nAIN;

	//Display Resistance-----------------------------------------------------------------
	//R=V/I		Resistance=ADC Voltage/Forced Current
	if (rValue==R200mE)     Resistance1 = (c_nAIN /10.005e-3 );
	else if (rValue==R2E)  		 Resistance1 = c_nAIN /10.005e-3 ;
	else if (rValue==SLR200E)	 Resistance1 = c_nAIN /0.992e-3;

	//-------------------------------------------------------------------------------------

	qDebug()<<"Resistance-1:"<<qSetRealNumberPrecision(7)<<Resistance1;


            //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Force Current~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    if(rValue==SLR200E){
    	//05092014//
    	IAppCard->writeRegister(0x000F,0x0016);
    	//05092014//
    	test=ICALIB->SerialDACCalibration(SLR200E);
        //05092014//
    	ForceCurrent(1,test*-1);
    }
    else if(rValue==R2E){
    	//05092014//
    	IAppCard->writeRegister(0x000F,0x0016);
    	//05092014//
    	test=ICALIB->SerialDACCalibration(R2E);
        //05092014//
    	ForceCurrent(1,test*-1);
    }
    else if(rValue==R200mE){
    	//05092014//
    	IAppCard->writeRegister(0x000F,0x0016);
    	//05092014//
    	test=ICALIB->SerialDACCalibration(R200mE);
        //05092014//
    	ForceCurrent(1,test*-1);
    }
    //----------------------------------------------------------------------------------

    usleep(1000);

	if(rValue==SLR200E||rValue==R2E){
    	for(avg=0;avg<noOfSamples;avg++){

    		//05092014//
    		AIN=m_objAD7190->readADCDataRegister(m_nADC) & 0xFFFFFF;
    	    qDebug("ADC Data : %x",AIN);
    	    if(AIN==overRange){
    	        return ret;
    	    }
    	    if(rValue==SLR200E){
    	        l_nFactor1 = (AIN/pow(2,23))-1;
    	        l_nFactor2 = (1.0 / 2.048);
    	        l_nAIN = l_nFactor1 / l_nFactor2;
    			gainValue=1;rangeValue=3.5;
    	    }
    	    else if(rValue==R2E){
    	        l_nFactor1 = (AIN/pow(2,23))-1;
    	        l_nFactor2 = (1.0 / 2.048);
    	        l_nAIN = l_nFactor1 / l_nFactor2;
    			gainValue=1;rangeValue=3.5;
    	    }

    	    avgRetval[avg]=l_nAIN;
    	    retval=retval+avgRetval[avg];
    	}
    	avg=0;
    	l_nAIN=retval/noOfSamples;
    	retval=0;
    	 qDebug("Converted Data : %f",l_nAIN);

    }
    else if(rValue==R200mE){
    	for(avg=0;avg<(noOfSamples*2);avg++){

    		//05092014//
    		AIN=m_objAD7190->readADCDataRegister(m_nADC) & 0xFFFFFF;
    		qDebug("ADC Data : %x",AIN);
    	    if(AIN==overRange){
    	        return ret;
    	    }
   	        l_nFactor1 = (AIN/pow(2,23))-1;
   	        l_nFactor2 = (1.0 / 2.048);
   	        l_nAIN = l_nFactor1 / l_nFactor2;
   	        gainValue=1;rangeValue=3.5;
    	    avgRetval[avg]=l_nAIN;
    	    retval=retval+avgRetval[avg];
    	}
    	avg=0;
    	l_nAIN=retval/(noOfSamples*2);
    	retval=0;
    }
    values.Data=AIN;
    values.ConvertedData=l_nAIN;

    if(calib_value.flag==true){
    calibrateDMM();
    c_nAIN = (l_nAIN - calib_value.constant) / calib_value.gain;
    values.ConvertedData=c_nAIN;
    //qDebug()<<"Calibrated Value :"<<c_nAIN;
    }
    else if(calib_value.flag==false){
    	c_nAIN = l_nAIN;
    }

    ADCRxVoltage=l_nAIN;

    //Display Resistance-----------------------------------------------------------------
    //R=V/I		Resistance=ADC Voltage/Forced Current
    if (rValue==R200mE)     Resistance2 = (c_nAIN /-10.005e-3 );
    else if (rValue==R2E)  		 Resistance2 = c_nAIN /-10.005e-3 ;
	else if (rValue==SLR200E)	 Resistance2 = c_nAIN /-0.992e-3;

    //-------------------------------------------------------------------------------------
    qDebug()<<"Resistance-2:"<<qSetRealNumberPrecision(7)<<Resistance2;

        Resistance =  (Resistance1 - Resistance2)/2;
        qDebug()<<"Resistance-1:"<<qSetRealNumberPrecision(7)<<Resistance1;
        qDebug()<<"Resistance-2:"<<qSetRealNumberPrecision(7)<<Resistance2;
	qDebug()<<"Resistance  :"<<qSetRealNumberPrecision(7)<<Resistance;

	//    Resistance=static_cast<double>(static_cast<int>(Resistance*10000000))/10000000.0;
	return Resistance;

}
double PTDMMLibInterface::displayDiode(unsigned int rValue){

	unsigned int AIN=0.0;
	double l_nFactor1=0.0,l_nFactor2=0.0,l_nAIN=0.0,c_nAIN=0.0;

	AIN=m_objAD7190->readADCDataRegister(m_nADC) & 0xFFFFFF;
	qDebug("ADC Data : %x",AIN);

	double ret=999999999;
	if(AIN==overRange){
		return ret;
		//   return overRange;
	}

	if(rValue==DIODE){
		l_nFactor1 = (AIN/pow(2,23))-1;
		l_nFactor2 = (1.0 / 2.048);
		l_nAIN = l_nFactor1 / l_nFactor2;
		gainValue=1;rangeValue=0.6;
	}

	qDebug("Converted Data : %f",l_nAIN);
	values.Data=AIN;
	values.ConvertedData=l_nAIN;

	if(calib_value.flag==true){
		calibrateDMM();
		c_nAIN = (l_nAIN - calib_value.constant) / calib_value.gain;
		values.ConvertedData=c_nAIN;
	}
	else if(calib_value.flag==false)
		c_nAIN=l_nAIN;
	//qDebug()<<"Calibrated Value :"<<c_nAIN;
	return c_nAIN*1000;
}
double PTDMMLibInterface::displayVoltage(unsigned int vValue)
{
	/*	unsigned int AIN=0.0;
	double l_nFactor1=0.0,l_nFactor2=0.0,l_nAIN=0.0,c_nAIN=0.0;

    AIN=m_objAD7190->readADCDataRegister(m_nADC) & 0xFFFFFF;
    qDebug("DMM Lib ADC Data : %x",AIN);

    double ret=999999999;

    if(vValue==V200mV||vValue==V2V||vValue==V20V){
        l_nFactor1 = (AIN/pow(2,23))-1;
        l_nFactor2 = (8.0 / 2.048);
        l_nAIN = l_nFactor1 / l_nFactor2;
        gainValue=8;rangeValue=0.6;
    }
    else if(vValue==V200V){
        l_nFactor1 = (AIN/pow(2,23))-1;
        l_nFactor2 = (8.0 / 2.048);
        l_nAIN = l_nFactor1 / l_nFactor2;
        gainValue=8;rangeValue=0.6;
    }
    else if(vValue==V1000V){
        l_nFactor1 = (AIN/pow(2,23))-1;
        l_nFactor2 = (1.0 / 2.048);
        l_nAIN = l_nFactor1 / l_nFactor2;
        gainValue=1;rangeValue=1.5;
    }
//    else if(vValue==V2V){
//        l_nFactor1 = (AIN/pow(2,23))-1;
//        l_nFactor2 = (1.0 / 2.048);
//        l_nAIN = l_nFactor1 / l_nFactor2;
//        gainValue=1;rangeValue=0.6;
//    }

    qDebug("DMM Lib Converted Data : %f",l_nAIN);
    `.Data=AIN;
    values.ConvertedData=l_nAIN;

    if(calib_value.flag==true){
    calibrateDMM();
    c_nAIN = (l_nAIN - calib_value.constant) / calib_value.gain;
    //qDebug()<<"Calibrated Value :"<<c_nAIN;
    values.ConvertedData=c_nAIN;

    }
    else if(calib_value.flag==false)
        c_nAIN=l_nAIN;


    //Display Voltage--------------------------------------------------------------------
    //qDebug()<<"Inside MeasureVoltage - Display";
    double Voltage=0.0;

    if (vValue==V200mV)   	   Voltage = c_nAIN*1;
    else if (vValue==V2V)      Voltage = c_nAIN*10.0;
    else if (vValue==V20V)     Voltage = c_nAIN*100.0;
    else if (vValue==V200V)    Voltage = c_nAIN*1000.0;
    else if (vValue==V1000V)   Voltage = c_nAIN*1000.0;


    //qDebug()<<"Voltage :"<<Voltage;
    //-----------------------------------------------------------------------------------------
    if(AIN==overRange){
        return ret;
    }

        return (Voltage*1000);*///commented on 12062014
}
double PTDMMLibInterface::displayCurrent(unsigned int iValue)
{
	/*
	unsigned int AIN=0.0;
	double l_nFactor1=0.0,l_nFactor2=0.0,l_nAIN=0.0,c_nAIN=0.0;

	AIN=m_objAD7190->readADCDataRegister(m_nADC) & 0xFFFFFF;
    qDebug("DMM Lib ADC Data : %x",AIN);

    double ret=999999999;


    if(iValue==I2mA){
        l_nFactor1 = (AIN/pow(2,23))-1;
        l_nFactor2 = (1.0 / 2.048);
        l_nAIN = l_nFactor1 / l_nFactor2;
        gainValue=8;rangeValue=0.6;
    }
    else if(iValue==I20mA||iValue==I200mA){
        l_nFactor1 = (AIN/pow(2,23))-1;
        l_nFactor2 = (8.0 / 2.048);
        l_nAIN = l_nFactor1 / l_nFactor2;
        gainValue=8;rangeValue=0.6;
    }
    else if(iValue==I3A){
        l_nFactor1 = (AIN/pow(2,23))-1;
        l_nFactor2 = (1.0 / 2.048);
        l_nAIN = l_nFactor1 / l_nFactor2;
        gainValue=1;rangeValue=1.5;
    }

    //qDebug("DMM Lib Converted Data : %f",l_nAIN);
    values.Data=AIN;
    values.ConvertedData=l_nAIN;

    if(calib_value.flag==true){
    calibrateDMM();
    //qDebug()<<"Slope :"<<calib_value.gain<<"Constant :"<<calib_value.constant;
    c_nAIN = (l_nAIN - calib_value.constant) / calib_value.gain;
    //qDebug()<<"Calibrated Value :"<<c_nAIN;
    values.ConvertedData=c_nAIN;
    }
    else if(calib_value.flag==false)
        c_nAIN=l_nAIN;

    //Display Current--------------------------------------------------------------------
    //qDebug()<<"Inside MeasureCurrent - Display";
    double Current=0.0;

    if (iValue==I2mA)      		Current = (c_nAIN/100)*1;
    else if (iValue==I20mA)     Current = (c_nAIN/100)*10;
    else if (iValue==I200mA)    Current = (c_nAIN/1)*1;
    else if (iValue==I3A)       Current = (c_nAIN/0.1)*1;

    //-----------------------------------------------------------------------------------------
    if(AIN==overRange){
        return ret;
    }
    return Current*1000;
	 *///commented on 12062014

}

double PTDMMLibInterface::MeasureResistance(unsigned int rValue,unsigned int rType){
	Q_UNUSED(rType);

	double Resistance=0.0;

	if(rValue==R200mE||rValue==R2E||rValue==SLR200E){
		iamDMM=false;
			IAppCard->writeRegister(0x0016,0x0036);//testing//changed to 6 from 0 for via rms2dc
			IAppCard->writeRegister(0x0010,0x0048);
	}
	IAppCard->setSPIAppendBit(0x0c000);
	double test=0.0;
	m_eSelect = DACG;
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	double DACDriveVoltage[7];
	QFile *xmlFile= new QFile("DACDriveVoltage.xml");
	if (!xmlFile->open(QIODevice::ReadOnly | QIODevice::Text)) { //qDebug()<<"DACDriveVoltage file read error";
	}
	QXmlStreamReader xml(xmlFile);
	short int index=0;
	while(!xml.atEnd() &&  !xml.hasError())
	{
		QXmlStreamReader::TokenType token = xml.readNext();
		QXmlStreamAttributes attributes = xml.attributes();
		if(token == QXmlStreamReader::StartDocument){ continue;  }
		if(xml.isStartElement())                {
			if(xml.name() == "VoltageDrive") {
				DACDriveVoltage[index]=xml.attributes().value("Voltage").toString().toDouble();
				qDebug()<<xml.attributes().value("Range").toString()<<DACDriveVoltage[index];
				index++;
			}
		}
	}
	if(xml.hasError())        qDebug()<<"xmlFile.xml Parse Error";
	xml.clear();    xmlFile->close();
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Force Current~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	if(rValue==SLR200E){
		IAppCard->writeRegister(0x000F,0x0016);
		test=ICALIB->SerialDACCalibration(SLR200E);
		ForceCurrent(1,test);
	}
	else if(rValue==R2E){
		IAppCard->writeRegister(0x000F,0x0016);
		test=ICALIB->SerialDACCalibration(R2E);
		ForceCurrent(1,test);
	}
	else if(rValue==R200mE){
		IAppCard->writeRegister(0x000F,0x0016);
		test=ICALIB->SerialDACCalibration(R200mE);
		ForceCurrent(1,test);
	}
	//----------------------------------------------------------------------------------
    double l_dbAIN;

    if(rValue==SLR200E){
    	l_dbAIN=GetADCVoltage(typeDC,1);
    	m_objAD7190->writeADCGPConRegister(1,0x34);
    }
    else if(rValue==R2E){
    	l_dbAIN=GetADCVoltage(typeDC,1);
    	m_objAD7190->writeADCGPConRegister(1,0x34);//7);
    }
    else if(rValue==R200mE){
    	l_dbAIN=GetADCVoltage(typeDC,1);
    	m_objAD7190->writeADCGPConRegister(1,0x34);//a);
    }
    //-------------------------------------------------------------------------------------
             if (rValue==R200mE)     Resistance = (l_dbAIN /10e-3 );
        else if (rValue==R2E)  		 Resistance = l_dbAIN /10e-3 ;
        else if (rValue==SLR200E)	 Resistance = l_dbAIN /1e-3;

    //-------------------------------------------------------------------------------------

	return 1;//Resistance;

}

double PTDMMLibInterface::MeasureVoltage(unsigned int vValue,unsigned int vType){

	//    serialLibrary=new QLibrary("./libseriallib.so");

	//    typedef int(*OPEN)();

	//qDebug()<<"Inside MeasureVoltage";
	//Declarations----------------------------------------------------------------------------
	//    typedef unsigned int(*DMM_VOLTAGE)(unsigned int);
	//    DMM_VOLTAGE  dmmVoltage = (DMM_VOLTAGE)serialLibrary->resolve("dmmVoltage");
	//----------------------------------------------------------------------------------------

	//PSOC switching--------------------------------------------------------------------------
	//qDebug()<<"Inside MeasureVoltage - PSOC Switching";
	/*	iamDMM=true;
	if(vType==typeDC)
		IAppCard->writeRegister(0,0x36);
	else if(vType==typeAC)
		IAppCard->writeRegister(2,0x36);

	IAppCard->writeRegister(0,0x16);*///commented on 12062014

	/*if(vValue==V200mV)     		IPsoc->dmmVoltage(5);
    else if(vValue==V2V)        IPsoc->dmmVoltage(4);
    else if(vValue==V20V)       IPsoc->dmmVoltage(3);
    else if(vValue==V200V)      IPsoc->dmmVoltage(2);
    else if(vValue==V1000V)     IPsoc->dmmVoltage(1);*///commented on 12062014

	//    	IPsoc->onTopRelay(24);
	//if(vValue==V200V||vValue==V1000V){ commented for testing purpose - Elangovan
	//IPsoc->onTopRelay(19);
	//IPsoc->offTopRelay(20);
	//}

	//-----------------------------------------------------------------------------------

	//Mode, Configure & Get Voltage------------------------------------------------------

	/*    double l_dbAIN;
    if(vValue==V200mV||vValue==V2V||vValue==V20V)
    	l_dbAIN=GetADCVoltage(vType,8);
    else if(vValue==V200V)
    	l_dbAIN=GetADCVoltage(vType,8);
    else if(vValue==V1000V)
    	l_dbAIN=GetADCVoltage(vType,1);*///commented on 12062014
	//    else if(vValue==V2V)
	//    	l_dbAIN=GetADCVoltage(vType,1);

	//qDebug("Inside MeasureVoltage ADC Raw Value %f ",AIN);
	//-----------------------------------------------------------------------------------

	//Display Voltage--------------------------------------------------------------------
	//qDebug()<<"Inside MeasureVoltage - Display";
	/*    double Voltage=0.0;

    if (vValue==V200mV)   Voltage = l_dbAIN*1;
    else if (vValue==V2V)      Voltage = l_dbAIN*10;
    else if (vValue==V20V)     Voltage = l_dbAIN*100;
    else if (vValue==V200V)    Voltage = l_dbAIN*1000;
    else if (vValue==V1000V)   Voltage = l_dbAIN*1000;

    //-----------------------------------------------------------------------------------------
    return Voltage;*///commented on 12062014
}


double PTDMMLibInterface::MeasureCurrent(unsigned int iValue,unsigned int iType){

	//    serialLibrary=new QLibrary("./libseriallib.so");
	//    typedef int(*OPEN)();
	//    OPEN  openSerial = (OPEN)serialLibrary->resolve("openSerial");
	//    openSerial();

	//qDebug()<<"Inside MeasureCurrent";
	//Declarations----------------------------------------------------------------------------
	//    typedef unsigned int(*DMM_CURRENT)(unsigned int);
	//    DMM_CURRENT  dmmCurrent = (DMM_CURRENT)serialLibrary->resolve("dmmCurrent");
	//----------------------------------------------------------------------------------------
	/*	iamDMM=true;
		if(iType==typeDC)
			IAppCard->writeRegister(0,0x36);
		else if(iType==typeAC)
			IAppCard->writeRegister(2,0x36);

		IAppCard->writeRegister(0x1,0x16);
		IAppCard->writeRegister(0x0007,0x0034);*///commented on 12062014
	//PSOC switching--------------------------------------------------------------------------

	//qDebug()<<"Inside MeasureCurrent - PSOC Switching";
	/*if(iValue==I2mA)      	   IPsoc->dmmCurrent(4);
    else if(iValue==I20mA){
    	IPsoc->dmmCurrent(3);
    	IPsoc->onTopRelay(0x17);
    	IPsoc->offTopRelay(0x19);
    }
    else if(iValue==I200mA)    IPsoc->dmmCurrent(2);
    else if(iValue==I3A)       IPsoc->dmmCurrent(1);*///commented on 12062014

	//-----------------------------------------------------------------------------------

	//Mode, Configure & Get Voltage------------------------------------------------------
	/*    double l_dbAIN;
    if(iValue==I2mA)
    	l_dbAIN=GetADCVoltage(iType,1);
    else if(iValue==I20mA||iValue==I200mA)
    	l_dbAIN=GetADCVoltage(iType,8);
    else if(iValue==V200V||iValue==V1000V)
    	l_dbAIN=GetADCVoltage(iType,1);*///commented on 12062014
	//qDebug()<<"Inside MeasureCurrent ADC Raw Value : "<<AIN;
	//-----------------------------------------------------------------------------------

	//Display Current--------------------------------------------------------------------
	//qDebug()<<"Inside MeasureCurrent - Display";
	/*    double Current=0.0;

    if (iValue==I2mA)      Current = (l_dbAIN/100)*1;
    else if (iValue==I20mA)     Current = (l_dbAIN/100)*10;
    else if (iValue==I200mA)    Current = (l_dbAIN/1)*1;
    else if (iValue==I3A)       Current = (l_dbAIN/0.1)*1;

    //-----------------------------------------------------------------------------------------
    return Current;*///commented on 12062014
}
ADC PTDMMLibInterface::getAdcDatas(){

	return values;
}
Q_EXPORT_PLUGIN2(IDMMLibInterface, PTDMMLibInterface);
