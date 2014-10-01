#ifndef HARDWAREINTERFACE_H
#define HARDWAREINTERFACE_H

#include <ApplicationCardInterface.h>
#include <QPluginLoader>
#include <QtCore>
#include <QObject>
#include "AppdeviceRegisterDetails.h"
#include "PTSPIMemoryInterface.h"
#include "ad5293.h"
#include "ad5318components.h"
#include "Waveformclass.h"


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

    HardwareInterface(){

        QPluginLoader loaderSPI("libSPIMemoryInterface.so", this);
        ISPIMemory = qobject_cast<ISPIMemoryInterface*> (loaderSPI.instance());

        QPluginLoader loaderApp("libPTApplicationcardInterface.so", this);
        IAppCard = qobject_cast<IApplicationCardInterface*> (loaderApp.instance());

        IAppCard->setDeviceName(SLOT0);
        IAppCard->enumerateAPPCard();

        m_objAD5293Component = new AD5293(IAppCard);
        m_objAD5318Component = new AD5318Components(IAppCard);




    }
    
    void Init(){
		IAppCard->setSPIAppendBit(0xC000);
        m_objAD5318Component->resetDAC5318(true);

    	setDAC(DACF,0.0);
        setDAC(DACG,0.0);

	    IAppCard->writeRegister(0x0001,0x0034);
	    IAppCard->writeRegister(0x0000,0x0016);

        for(int i=0;i<5;i++) {m_nRangeSlope[i]=1.0;m_nRangeConstant[i]=0.0;}

    	qDebug()<<"HardwareInterface Initialized";
		 IAppCard->writeRegister(0x01,0x94);//DDS Path Selection added july 30th
    }
    void setDAC(AD5318_DACSELECT m_eSelect,double dacVoltage){
    	IAppCard->setSPIAppendBit(0xC000);

    	m_objAD5318Component->configureADC5318CW();
        AD5318_dataTemplate l_nAD5318DW;
         l_nAD5318DW.m_eDACSelect = m_eSelect;
         l_nAD5318DW.m_bCtrlBit = 0;
         l_nAD5318DW.m_nVout = dacVoltage;
         l_nAD5318DW.m_nVRef = 2.5;
         l_nAD5318DW.m_bUniPolor = true;
         if(m_eSelect == DACE || m_eSelect ==DACH)
         	l_nAD5318DW.m_nVRef = 5.0;
         if(m_eSelect == DACF || m_eSelect == DACG)
         	l_nAD5318DW.m_bUniPolor = false;
         m_objAD5318Component->configureADC5318Data(l_nAD5318DW);

         if(m_eSelect==DACA)  qDebug()<<"Set DAC A Done with "<<dacVoltage<<" Voltage";
         if(m_eSelect==DACB)  qDebug()<<"Set DAC B Done with "<<dacVoltage<<" Voltage";
         if(m_eSelect==DACC)  qDebug()<<"Set DAC C Done with "<<dacVoltage<<" Voltage";
         if(m_eSelect==DACD)  qDebug()<<"Set DAC D Done with "<<dacVoltage<<" Voltage";
         if(m_eSelect==DACE)  qDebug()<<"Set DAC E Done with "<<dacVoltage<<" Voltage";
         if(m_eSelect==DACF)  qDebug()<<"Set DAC F Done with "<<dacVoltage<<" Voltage";
         if(m_eSelect==DACG)  qDebug()<<"Set DAC G Done with "<<dacVoltage<<" Voltage";
    }
    void set_BTUR_BDR(unsigned short l_nBTUR,unsigned short l_nBDR){
    	IAppCard->basicTimeUnit(l_nBTUR - 1);
    	IAppCard->basicDuration(l_nBDR - 1);

    	//qDebug()<<"Basic Time Unit :"<<l_nBTUR<<"Basic Duration:"<<l_nBDR;
    }
    void set_START_STOP(unsigned short l_nSTART,unsigned short l_nSTOP){
    	m_nSTART = l_nSTART;
    	m_nSTOP = l_nSTOP;

    	//qDebug()<<"Start :"<<l_nSTART<<"Stop :"<<l_nSTOP;
    }
    void set_DrivePeriod(unsigned int l_nWDP){

    	IAppCard->setDrivePeriod(l_nWDP - 1);

    	//qDebug()<<"Drive Period:"<<l_nWDP;
    }
     void Drive(DRIVE_MODE drvmode){
    	 switch(drvmode){
    	 case STARTDRIVE:
    		 IAppCard->startDrive(1);
    		 qDebug()<<"HardwareInterface Start Drive";
    		 break;
    	 case STOPDRIVE:
    		 setDAC(DACF,0);
    		 updateParallelDAC(0.0);
    		 IAppCard->stopDrive();
//    		 if(DDSLoop==true){
//    			 m_nDDSCycle=m_nDDSCycle & 0x7F;
//    			 Update();
//    		 	 IAppCard->stopDrive();
//    		 }
//    		  else{
//    			  IAppCard->stopDrive();
//    		  }
    		 //qDebug()<<"HardwareInterface Stop Drive";
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
    	     		 //qDebug()<<"HardwareInterface Single Drive";
    	     		 break;
    	     	 case CONTINUOUS:

    	     		 if(IAppCard->readRegister(0x72)==0){
    	     			setPatternLoop(true);
    	     			//qDebug()<<"HardwareInterface Continuous RAMDrive";
    	     		 }else{
    	     		   setPatternLoop(false);
    	     		   DDSLoop=true;
                       m_nDDSCycle=(1<<8)|0x1;
    	    	       temp=m_nDDSCycle|0x80;
    	    	       IAppCard->writeRegister(temp,0x0068);
    	    	       //qDebug()<<"HardwareInterface Continuous DDS Drive";
    	     		 }

    	     		 break;
    	    	 case BURST:
    	    		 DDSLoop=false;
    	    		 //qDebug()<<"HardwareInterface Burst Drive";
    	    		 break;

    	 }
     }
     void SelectOperatingMode(OPERATING_MODE opMode){
    	 switch(opMode){
    	 case DDS_Signal:
    		 IAppCard->setDDSWaveSelect(DDS);
    		 IAppCard->writeRegister(0x01,0x94);//DDS Path Selection added july 30th
    		 //qDebug()<<"HardwareInterface DDS Mode";
    		 break;
    	 case RAM:
    		 IAppCard->setDDSWaveSelect(RAM_DATA);
    		 //qDebug()<<"HardwareInterface RAM Mode";
    		 break;
    	 }
     }
     void SelectWaveForm(SELECT_WAVE selWave){
    	 if(selWave!=PULSE_W){
    		IAppCard->setStartStop(0,0);
 		 	set_BTUR_BDR(2,1);
		    set_DrivePeriod(50000);
		    setPatternLoop(false);
    	 }
    	 else{
    		set_BTUR_BDR(1000,1);
 		    IAppCard->setStartStop(1,1);
     		IAppCard->setDrivePeriod(100);
     		setPatternLoop(true);
	    	//qDebug()<<"START/STOP for Pulse is set";
    	 }
    	 switch(selWave){
    	 case SINE_W:
    		 IAppCard->setDDSWaveSelect(DDS);
    		 //qDebug()<<"HardwareInterface Sine Wave";
    		 break;
    	 case SQUARE_W:
    		 IAppCard->setDDSWaveSelect(SAW_TOOTH);
    	     IAppCard->setDDSSawtooth(_ASYMMETRIC);
    	     //qDebug()<<"HardwareInterface Square Wave";
    	    break;
    	 case RAMPUP_W:
    		 IAppCard->setDDSWaveSelect(SAW_TOOTH);
    		 IAppCard->setDDSSawtooth(_RAMP_UP);
    		 //qDebug()<<"HardwareInterface Ramp Up Wave";
    		 break;
    	 case RAMPDOWN_W:
    		 IAppCard->setDDSWaveSelect(SAW_TOOTH);
    		 IAppCard->setDDSSawtooth(_RAMP_DOWN);
    		 //qDebug()<<"HardwareInterface Ramp Down Wave";
    		 break;
    	 case TRIANGLE_W:
    		 IAppCard->setDDSWaveSelect(SAW_TOOTH);
    		 IAppCard->setDDSSawtooth(_TRIANGLE);
    		 //qDebug()<<"HardwareInterface Triangle Wave";
    		 break;
    	 case DC_W:
   			IAppCard->setDDSWaveSelect(DC_SIGNAL);
   			initParallelDAC();
   			//qDebug()<<"HardwareInterface DC Wave";
    		 break;
    	 case PULSE_W:
    	 {
    		 IAppCard->setDDSWaveSelect(RAM_DATA);
    		 //qDebug()<<"HardwareInterface PULSE Wave";

    		 IAppCard->writeRegister(0x0000,0x86);

    		 loadRAM();

    		 IAppCard->writeRegister(0,0x82);
    		 IAppCard->writeRegister(0x63,0x84);

    		 IAppCard->writeRegister(0x0003,0x86);
    	 }
    		 break;
    	 }

     }

     void loadRAM()
     {
    	 	ISPIMemory->accessSPIMemory(APPLICATIONCARD);
    	 	ISPIMemory->setHardwarwObject(IAppCard);
     		FILE *l_nFD;
     	    unsigned short int *m_nWriteData;
   		    unsigned int l_nFileData=0,l_nIndex=0;

   		    m_nWriteData = new unsigned short int[100];
     		l_nFD = fopen(DFIFODRIVE,"r");
     		 if(l_nFD == 0)
     		    printf("File I/O error\n");

     		  //qDebug()<<"SRAM Load Started...";

//     		    while(!feof(l_nFD)){
     		  while(l_nIndex<100){
     		        fscanf(l_nFD,"%x",&l_nFileData);
     		        if(feof(l_nFD))
     		        	l_nFileData =0;
     		        m_nWriteData[l_nIndex]=l_nFileData;
//     				//qDebug() << "FILE Data:" << l_nFileData;
     		        l_nIndex = l_nIndex + 1;
     		    }
     		    fclose(l_nFD);
     		   //qDebug()<<"SRAM Data Acquired...index:"<<l_nIndex;
     		   ISPIMemory->accessSPIRAM(DRIVERAM);
     		   ISPIMemory->writeAppCardSRAM(0x0000, l_nIndex, &m_nWriteData[0]);
     		  //qDebug()<<"SRAM Loaded...";
     }
     void setBurstCount(unsigned short burstCount){
    	 DDSLoop=false;
    	 burstCount=(burstCount<<8)|0x1;
  	     IAppCard->writeRegister(burstCount,0x0068);
  	   //qDebug()<<"Write Register 68 with"<<hex<<burstCount;
  	   //qDebug()<<"HardwareInterface setBurstCount";
     }
     void setBurstRate(double burstRate){

    	 m_nWDP=(unsigned int)burstRate;
    	 m_nWDP_LSW=(m_nWDP<<16) >> 16;
    	 m_nWDP_MSW=m_nWDP >> 16;
    	 //qDebug()<<"Split Data"<<hex<<m_nWDP<<"and Write in Register 18 with"<<hex<<m_nWDP_LSW<<" and Register 14 with"<<hex<<m_nWDP_MSW;
    	 IAppCard->setDrivePeriod(m_nWDP_LSW);
    	 IAppCard->writeRegister(m_nWDP_MSW,0x14);
     }
     void setPatternLoop(bool loop){
    	 if(loop){
     	     IAppCard->setDrivePatternCount(true, 0);
     	     //qDebug()<<"set Drive Pattern Count";
    	 }else{
    		 IAppCard->setDrivePatternCount(false, 0);
    		 //qDebug()<<"set Drive Pattern Count";
    	 }
     }
     void setFrequency(double fValue){
    	if(IAppCard->readRegister(0x72)==0){
//    		l_objDriveData = m_objFGData->getDriveData();
    		//qDebug()<<"Frequency :"<<fValue<<"BTUR :"<<l_objDriveData->m_nBTUR<<"BD :"<<l_objDriveData->m_nBDR;
//    		IAppCard->basicTimeUnit(l_objDriveData->m_nBTUR);
//    		IAppCard->basicDuration(l_objDriveData->m_nBDR);
    		//qDebug()<<"HardwareInterface Set RAM frequency";
    	}else{
        m_nOutputFrequency=fValue;
     	m_nFTWOutputFrequency = (m_nOutputFrequency / 50000000);
     	m_nFTWOutputFrequency = m_nFTWOutputFrequency * pow(2, 32);

     	m_nFTW_LSW = ((unsigned int) m_nFTWOutputFrequency << 16) >> 16;
     	m_nFTW_MSW = (unsigned int) m_nFTWOutputFrequency >> 16;

    	IAppCard->setDDSFTW_LSW(m_nFTW_LSW);
    	IAppCard->setDDSFTW_MSW(m_nFTW_MSW);

    	//qDebug()<<"HardwareInterface Set DDS frequency";
    	}
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

 		//qDebug()<<"HardwareInterface Set Phase";
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
//    		double m_nVoltRangeArray[5]={0.6,1.5,3.5,7.0,13.0};//Aug,30,2013
    	 	double m_nVoltRangeArray[5]={0.6,2,4,8,14.0};
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
    		}else if(ampValue<=0.6){
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
    		//qDebug()<<"Calibration Slope:"<<dec<<m_nRangeSlope<<" Constant:"<<m_nRangeConstant;
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
    	    setDAC(DACF,-offValue);
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
     void initParallelDAC(){

    	 setDAC(DACG,0.0);setDAC(DACF,0.0);

    	 IAppCard->writeRegister(0x0010,0x4);
    	 IAppCard->writeRegister(0x0000,0x6);
    	 IAppCard->writeRegister(0x0000,0x14);
    	 IAppCard->writeRegister(0x0001,0x18);
    	 IAppCard->writeRegister(0x0000,0x1c);
    	 IAppCard->writeRegister(0x0100,0x1a);
    	 IAppCard->writeRegister(0x0001,0x94);

   	    m_objAD5293Component->setAD5293Voltage(1600); //For Full Scale Drive
   	    m_objAD5293Component->writeAD5293(SPI1);

    	 updateParallelDAC(0.0);

     }
     void updateParallelDAC(double ampValue){


 		double m_nVoltRangeArray[5]={0.6,1.5,3.5,7.0,13.0};
 		int index=0;
 		double compValue;

 		if(ampValue<0)
 			compValue=ampValue*-1;
 		else
 			compValue=ampValue;

 		if(compValue>0.6&&compValue<=1.5){
 			index=1;
 			qDebug()<<"Range : 1.5, Value:"<<ampValue;
 		}else if(compValue>1.5&&compValue<=3.5){
 			index=2;
 			qDebug()<<"Range : 3.5, Value:"<<ampValue;
 		}else if(compValue>3.5&&compValue<=7){
 			index=3;
 			qDebug()<<"Range : 7, Value:"<<ampValue;
 		}else if(compValue>7&&compValue<=13){
 			index=4;
 			qDebug()<<"Range : 13, Value:"<<ampValue;
 		}else if(compValue<=0.6){
 			index=0;
 			qDebug()<<"Range : 0.6, Value:"<<ampValue;
 		}

		short int l_nAmpValue=0;
	  	if (index > 0){
            l_nAmpValue = pow(2, index - 1);
            IAppCard->writeRegister(l_nAmpValue, 0x48);
		 }
	  	else
		    IAppCard->writeRegister(l_nAmpValue, 0x48);

   	 m_nParallelDACOutput=ampValue/(m_nVoltRangeArray[index]/0.6);
   	 m_nParallelDACHexCode=(unsigned int)(((m_nParallelDACOutput+0.6)*(pow(2,14)-1))/(2*0.6));
   	 qDebug()<<"m_nParallelDACHexCode :"<<hex<<m_nParallelDACHexCode;
   	 IAppCard->writeRegister(m_nParallelDACHexCode,0x76);
     IAppCard->writeRegister(0x01,0x12);

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
	ISPIMemoryInterface *ISPIMemory;

    double m_nBTURVALUE,m_nTickTime,m_nTickFrequency,m_nSystemFrequency;
    double m_nOutputFrequency,m_nFTWOutputFrequency,m_nPTWPhase;
    double m_nOutputPhase,m_nOutputTime,m_nAmplitude;

    unsigned short m_nAddress,m_nData,m_nBTUR,m_nBDR;
    unsigned short m_nSTOP,m_nSTART,m_nDPC;

    unsigned int m_nWDP,m_nWDP_LSW,m_nWDP_MSW;
    unsigned short m_nFTW_LSW,m_nFTW_MSW,m_nPTW_LSW,m_nPTW_MSW;
    unsigned short m_nDDSCycle,temp;

    double m_nRangeSlope[5],m_nRangeConstant[5];

    unsigned int m_nParallelDACHexCode;
    double m_nParallelDACOutput;

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
