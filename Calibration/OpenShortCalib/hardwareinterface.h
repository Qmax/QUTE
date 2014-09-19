#ifndef HARDWAREINTERFACE_H
#define HARDWAREINTERFACE_H

#include <ApplicationCardInterface.h>
#include <QPluginLoader>
#include <QtCore>
#include <QObject>
#include "AppdeviceRegisterDetails.h"
#include "ad5293.h"
#include "ad5318components.h"


enum DRIVE_MODE{
    SINGLE,CONTINUOUS,BURST,STARTDRIVE,STOPDRIVE
};

enum OPERATING_MODE{
	DDS_Signal,RAM
};

enum SELECT_WAVE{
	SINE_W,SQUARE_W,RAMPUP_W,RAMPDOWN_W,TRIANGLE_W,DC_W,PULSE_W
};

class HardwareInterface:public QObject
{
	Q_OBJECT
public:

    HardwareInterface(IApplicationCardInterface *app){
//        QPluginLoader loaderApp("libPTApplicationcardInterface.so", this);
        IAppCard = app;//qobject_cast<IApplicationCardInterface*> (loaderApp.instance());
//        IAppCard->setDeviceName(SLOT0);
//        IAppCard->enumerateAPPCard();
        m_objAD5293Component = new AD5293(IAppCard);
        m_objAD5318Component = new AD5318Components(IAppCard);
        qDebug() << "Code ID:" << hex << IAppCard->readAppCardCodeId();
     	qDebug()<<"HardwareInterface";

    }
    
    void Init(){
    	m_nBTUR = 2;
    	m_nBTURVALUE = (m_nBTUR) * 10.0;
    	m_nBDR = 1;
    	m_nSTART = 10;
    	m_nSTOP = 1;
    	m_nDPC = 1;
    	m_nWDP = 50000;
    	m_nOutputFrequency = 1000;
    	m_nSystemFrequency=50000000;
    	m_nOutputPhase=0;
    	m_nDDSCycle=1;

    	DRVRxGain.m_bDSE=true;
    	DRVSRCAMPREG.m_bSRCN=true;
    	VRange=VOLT_3P5;
    	DRVRXGSRCREG.m_eVRanges=VRange;

    	DDSLoop=true;
    	PatternLoop=false;


    	IAppCard->writeRegister(0x0000,PT_APPCARD_MODULES::PT_SRAM_APPCARD_RAMR);
        IAppCard->writeRegister(0x0000,PT_APPCARD_MODULES::PT_DRIVE_APPCARD_DPR);
        IAppCard->writeRegister(0x000D,PT_APPCARD_MODULES::PT_DDS_APPCARD_DDSWSELR);


        m_objAD5318Component->resetDAC5318(true);

        m_eSelect = DACF;
       	m_objAD5318Component->configureADC5318CW();

        AD5318_dataTemplate l_nAD5318DW;
         l_nAD5318DW.m_eDACSelect = m_eSelect;
         l_nAD5318DW.m_bCtrlBit = 0;
         l_nAD5318DW.m_nVout = 0.0;
         qDebug()<<"DAC voltage F"<<l_nAD5318DW.m_nVout;
         l_nAD5318DW.m_nVRef = 2.5;
         l_nAD5318DW.m_bUniPolor = true;
         l_nAD5318DW.m_bUniPolor = false;
         m_objAD5318Component->configureADC5318Data(l_nAD5318DW);

       	m_eSelect = DACG;
       	m_objAD5318Component->configureADC5318CW();
       	l_nAD5318DW.m_eDACSelect = m_eSelect;
        l_nAD5318DW.m_nVout = 0.0;
        qDebug()<<"DAC voltage G"<<l_nAD5318DW.m_nVout;
        m_objAD5318Component->configureADC5318Data(l_nAD5318DW);

        for(int i=0;i<5;i++) {m_nRangeSlope[i]=1.0;m_nRangeConstant[i]=0.0;}

    	qDebug()<<"HardwareInterface Initialized";
    }
    void Configure(){
    	m_nFTWOutputFrequency = (m_nOutputFrequency / 50000000);
    	m_nFTWOutputFrequency = m_nFTWOutputFrequency * pow(2, 32);
    	m_nFTW_LSW = ((unsigned int) m_nFTWOutputFrequency << 16) >> 16;
    	m_nFTW_MSW = (unsigned int) m_nFTWOutputFrequency >> 16;

		m_nPTWPhase = (((pow(2,32))-1)*m_nOutputPhase)/360;
    	m_nPTW_LSW = ((unsigned int) m_nOutputPhase << 16) >> 16;
    	m_nPTW_MSW = (unsigned int) m_nOutputPhase >> 16;

    	qDebug()<<"HardwareInterface Configured";
    }
     void Update(){
    	 IAppCard->basicTimeUnit(m_nBTUR - 1);
    	 IAppCard->basicDuration(m_nBDR - 1);
    	 IAppCard->setDrivePeriod(m_nWDP - 1);
    	 IAppCard->setStartStop(m_nSTART, m_nSTOP);

    	 IAppCard->setDDSFTW_LSW(m_nFTW_LSW);
    	 IAppCard->setDDSFTW_MSW(m_nFTW_MSW);

    	 IAppCard->setDDSPTW_LSW(m_nPTW_LSW);
    	 IAppCard->setDDSPTW_MSW(m_nPTW_MSW);

    	 IAppCard->setDrivePatternCount(false, m_nDPC - 1);

//    	 if(PatternLoop==false){
//    	    IAppCard->setDrivePatternCount(false, m_nDPC - 1);
//    	  }else
//    	  {
//    	     temp=m_nDPC-1;
//    	     temp=temp|0X100;
//    	     IAppCard->setDrivePatternCount(false, temp);
//    	  }

    	      m_nDDSCycle=(1<<8)|0x1;
    	      temp=m_nDDSCycle|0x80;
    	      IAppCard->writeRegister(temp,0x0068);

//    	 if(DDSLoop==false){
//    	    if(m_nDDSCycle==0)
//    	         m_nDDSCycle=(1<<8)|0x1;
//    	         IAppCard->writeRegister(m_nDDSCycle,0x0068);
//    	  }else{
//    	       if(m_nDDSCycle==0)
//    	          m_nDDSCycle=(1<<8)|0x1;
//    	          temp=m_nDDSCycle|0x80;
//    	          IAppCard->writeRegister(temp,0x0068);
//    	  }

//    	 IAppCard->setDriveReceiveSourceSelect(DRVRxGain);
    	      IAppCard->writeRegister(0x0001,0x0034);
//    	 IAppCard->setDriveSourceAmplitudeRegister(DRVSRCAMPREG);
    	      IAppCard->writeRegister(0x0001,0x0016);
//    	 IAppCard->setDriveReceiveGainRegister(DRVRXGSRCREG);
    	      IAppCard->writeRegister(0x0002,0x0048);


    	 qDebug()<<"HardwareInterface Updated";

     }
     void Drive(DRIVE_MODE drvmode){
    	 switch(drvmode){
    	 case STARTDRIVE:
    		 IAppCard->startDrive(1);
    		 qDebug()<<"HardwareInterface Start Drive";
    		 break;
    	 case STOPDRIVE:
    		 IAppCard->stopDrive();
//    		 if(DDSLoop==true){
//    			 m_nDDSCycle=m_nDDSCycle & 0x7F;
//    			 Update();
//    		 	 IAppCard->stopDrive();
//    		 }
//    		  else{
//    			  IAppCard->stopDrive();
//    		  }
    		 qDebug()<<"HardwareInterface Stop Drive";
    		 break;
    	 }
     }
     void SingleContinuous(DRIVE_MODE drvmode){
    	 switch(drvmode){
    	     	 case SINGLE:
    	     		 DDSLoop=false;
    	     	    if(m_nDDSCycle==0)
    	     	     m_nDDSCycle=(1<<8)|0x1;
    	     	     IAppCard->writeRegister(m_nDDSCycle,0x0068);

    	     		 qDebug()<<"HardwareInterface Single Drive";
    	     		 break;
    	     	 case CONTINUOUS:
    	     		 DDSLoop=true;
    	    	       if(m_nDDSCycle==0)
    	    	    	  m_nDDSCycle=(1<<8)|0x1;
    	    	       temp=m_nDDSCycle|0x80;
    	    	       IAppCard->writeRegister(temp,0x0068);
    	     		 qDebug()<<"HardwareInterface Continuous Drive";
    	     		 break;
    	    	 case BURST:
    	    		 DDSLoop=false;
    	    		 qDebug()<<"HardwareInterface Burst Drive";
    	    		 break;

    	 }
     }
     void SelectOperatingMode(OPERATING_MODE opMode){
    	 switch(opMode){
    	 case DDS_Signal:

    		 qDebug()<<"HardwareInterface DDS Mode";
    		 break;
    	 case RAM:
    		 IAppCard->setDDSWaveSelect(RAM_DATA);
    		 break;
    	 }
     }
     void SelectWaveForm(SELECT_WAVE selWave){
    	 switch(selWave){
    	 case SINE_W:
    		 IAppCard->setDDSWaveSelect(DDS);
    		 qDebug()<<"HardwareInterface Sine Wave";
    		 break;
    	 case SQUARE_W:
    		 IAppCard->setDDSWaveSelect(SAW_TOOTH);
    	     IAppCard->setDDSSawtooth(_ASYMMETRIC);
    	     qDebug()<<"HardwareInterface Square Wave";
    	    break;
    	 case RAMPUP_W:
    		 IAppCard->setDDSWaveSelect(SAW_TOOTH);
    		 IAppCard->setDDSSawtooth(_RAMP_UP);
    		 qDebug()<<"HardwareInterface Ramp Up Wave";
    		 break;
    	 case RAMPDOWN_W:
    		 IAppCard->setDDSWaveSelect(SAW_TOOTH);
    		 IAppCard->setDDSSawtooth(_RAMP_DOWN);
    		 qDebug()<<"HardwareInterface Ramp Down Wave";
    		 break;
    	 case TRIANGLE_W:
    		 IAppCard->setDDSWaveSelect(SAW_TOOTH);
    		 IAppCard->setDDSSawtooth(_TRIANGLE);
    		 qDebug()<<"HardwareInterface Triangle Wave";
    		 break;
    	 case DC_W:
   			IAppCard->setDDSWaveSelect(DC_SIGNAL);
   			qDebug()<<"HardwareInterface DC Wave";
    		 break;
    	 case PULSE_W:
    		 break;
    	 }

     }
     void setBurstCount(unsigned short burstCount){
    	 DDSLoop=false;
    	 burstCount=(burstCount<<8)|0x1;
  	     IAppCard->writeRegister(burstCount,0x0068);
  	   qDebug()<<"HardwareInterface setBurstCount";
     }
     void setPatternLoop(bool loop){
    	 if(loop){
     	     temp=m_nDPC-1;
     	     temp=temp|0X100;
     	     IAppCard->setDrivePatternCount(false, temp);
    	 }else{
    		 IAppCard->setDrivePatternCount(false, m_nDPC - 1);
    	 }
     }
     void setFrequency(double fValue){
        m_nOutputFrequency=fValue;
     	m_nFTWOutputFrequency = (m_nOutputFrequency / 50000000);
     	m_nFTWOutputFrequency = m_nFTWOutputFrequency * pow(2, 32);

     	m_nFTW_LSW = ((unsigned int) m_nFTWOutputFrequency << 16) >> 16;
     	m_nFTW_MSW = (unsigned int) m_nFTWOutputFrequency >> 16;

    	IAppCard->setDDSFTW_LSW(m_nFTW_LSW);
    	IAppCard->setDDSFTW_MSW(m_nFTW_MSW);

    	qDebug()<<"HardwareInterface Set frequency"<<fValue;
     }
     double getFrequency(){
    	 return 0;
     }
     void setPhase(double phValue){
    	 m_nOutputPhase=phValue;
 		m_nPTWPhase = (((pow(2,32))-1)*m_nOutputPhase)/360;

     	m_nPTW_LSW = ((unsigned int) m_nPTWPhase << 16) >> 16;
     	m_nPTW_MSW = (unsigned int) m_nPTWPhase >> 16;

 		IAppCard->setDDSPTW_LSW(m_nPTW_LSW);
 		IAppCard->setDDSPTW_MSW(m_nPTW_MSW);

 		qDebug()<<"HardwareInterface Set Phase";
     }
     double getPhase(){
    	 return 0;
     }

    
     void setPeriod(double pdValue){
    	 Q_UNUSED(pdValue)
     }
     double getPeriod(){
    	 return 0;
     }
    
     void setAmplitude(double ampValue){
//    	 Q_UNUSED(ampValue)
    		double m_nVoltRangeArray[5]={0.6,1.5,3.0,7.0,13.0};
    		double m_nDDSVoltage,temp=ampValue;
    		int index=0;

    		qDebug()<<"Vin"<<ampValue;

    		if(ampValue>0.5&&ampValue<=1.5){
    			qDebug()<<"1.5 Range";
    			index=1;
    		}else if(ampValue>1.5&&ampValue<=3.5){
    			qDebug()<<"3.5 Range";
    			index=2;
    		}else if(ampValue>3.5&&ampValue<=7){
    			qDebug()<<"7 Range";
    			index=3;
    		}else if(ampValue>7&&ampValue<=13){
    			qDebug()<<"13 Range";
    			index=4;
    		}else if(ampValue<=0.5){
    			qDebug()<<"0.5 Range";
    			index=0;
    		}

    		short int l_nAmpValue = pow(2, index);
    	    		unsigned int l_nRegisterAddress = 0x48;
    		 if (index > 0){
                l_nAmpValue = pow(2, index - 1);
                IAppCard->writeRegister(l_nAmpValue, l_nRegisterAddress);
    		 } else {
    		    IAppCard->writeRegister(0x00, l_nRegisterAddress);
    		 }

    		readReferenceCalibrationFile();
    		qDebug()<<"Calibration Slope:"<<m_nRangeSlope<<" Constant:"<<m_nRangeConstant;
    		temp=(ampValue-(m_nRangeConstant[index]))/(m_nRangeSlope[index]);
    	    m_nDDSVoltage = 1600/(((temp*0.6)/m_nVoltRangeArray[index])/0.6);
    		IAppCard->setSPIAppendBit(0x8000);
    	    m_objAD5293Component->setAD5293Voltage(m_nDDSVoltage);
    	    m_objAD5293Component->writeAD5293(SPI1);

    	    m_nAmplitude=ampValue;

    	    qDebug()<<"ROut:"<<m_nDDSVoltage;
     }
     double getAmplitude(){
    	 return m_nAmplitude;
     }
    
     void setOffset(double offValue){
    	    IAppCard->setSPIAppendBit(0xC000);
//    	 Q_UNUSED(offValue)
         m_eSelect = DACG;
        	m_objAD5318Component->configureADC5318CW();

         AD5318_dataTemplate l_nAD5318DW;
          l_nAD5318DW.m_eDACSelect = m_eSelect;
          l_nAD5318DW.m_bCtrlBit = 0;
          l_nAD5318DW.m_nVout = 0.0;
          l_nAD5318DW.m_nVRef = 2.5;
          l_nAD5318DW.m_bUniPolor = true;
          l_nAD5318DW.m_bUniPolor = false;
          m_objAD5318Component->configureADC5318Data(l_nAD5318DW);

        	m_eSelect = DACF;
        	m_objAD5318Component->configureADC5318CW();
        	l_nAD5318DW.m_eDACSelect = m_eSelect;
        	l_nAD5318DW.m_nVout = offValue;
         m_objAD5318Component->configureADC5318Data(l_nAD5318DW);
     }
     double getOffset(){
    	 return 0;
     }
    
     void setHlevel(double hValue){
    	 Q_UNUSED(hValue)
     }
     double getHlevel(){
    	 return 0;
     }

     void setLlevel(double lValue){
    	 Q_UNUSED(lValue)
     }
     double getLlevel(){
    	 return 0;
     }
     void setSymmetry(double syValue){
    	 Q_UNUSED(syValue)
     }
     double getSymmetry(){
    	 return 0;
     }

     void setPulsewidth(double pwValue){
    	 Q_UNUSED(pwValue)
     }
     double getPulsewidth(){
    	 return 0;
     }

     void setDelay(double dlyValue){
    	 Q_UNUSED(dlyValue)
     }
     double getDelay(){
    	 return 0;
     }

     void readReferenceCalibrationFile(){

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
//             qDebug()<<"Gain :"<<m_nRangeSlope[i];
//             qDebug()<<"Constant"<<m_nRangeConstant[i];
         }

     }
protected:
	IApplicationCardInterface *IAppCard;

    double m_nBTURVALUE,m_nTickTime,m_nTickFrequency,m_nSystemFrequency;
    double m_nOutputFrequency,m_nFTWOutputFrequency,m_nPTWPhase;
    double m_nOutputPhase,m_nOutputTime,m_nAmplitude;

    unsigned short m_nAddress,m_nData,m_nBTUR,m_nBDR;
    unsigned short m_nSTOP,m_nSTART,m_nDPC,m_nWDP;

    unsigned short m_nFTW_LSW,m_nFTW_MSW,m_nPTW_LSW,m_nPTW_MSW;
    unsigned short m_nDDSCycle,temp;

    double m_nRangeSlope[5],m_nRangeConstant[5];

    AD5293 *m_objAD5293Component;
    AD5318Components *m_objAD5318Component;
    AD5318_DACSELECT m_eSelect;

    bool DDSLoop,PatternLoop;

    DRSER DRVRxGain;
    DSAR DRVSRCAMPREG;IRS irs;
    DRGSR DRVRXGSRCREG;
    VRAGNE VRange;

};
#endif // HARDWAREINTERFACE_H
