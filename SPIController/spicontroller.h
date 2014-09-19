#ifndef SPICONTROLLER_H
#define SPICONTROLLER_H

#include "SPIInterface.h"
#include <QtCore>
#include <qpluginloader.h>
#include <InterfaceFunctionalComponents.h>

#include "AD5260.h"
#include "AD5293.h"
#include "AD5318.h"
#include "DAC8563.h"
#include "ISLA118P50.h"
#include "LMH6518.h"
#include "DSOPSOC.h"


class SPIController : public QObject,public ISPIInterface
{
    Q_OBJECT
    Q_INTERFACES(ISPIInterface)

public:
    SPIController(QObject *parent = 0);
   ~SPIController();

   //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~AD5260~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

     void writeAD5260(unsigned short data);

   //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~AD5293~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

     void configureADC5293CW(SPI1_CONFIGURATION);
     void resetDAC5293(bool bDCRReset);
     void calculateADC5293DATA(AD5293_Template pObjstAD5293);
     unsigned short readADC5293();
     void powerDownmode();
     void writeAD5293(SPI_SELECT peSelect);
     void setAD5293Voltage(double);

   //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~AD5318~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

     void configureADC5318CW();
     void configureADC5318Data(AD5318_dataTemplate obj);
     void resetDAC5318(bool bDCRReset);

   //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~DAC8563~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

     void writeDAC8563(unsigned short,unsigned short);

     void WriteUpdateData(unsigned short,unsigned short,unsigned short);
     void PowerUp(unsigned short);
     void PowerDown(unsigned short,unsigned short);
     void SetGain(unsigned short,unsigned short);
     void SetLDAC(unsigned short);
     void ResetDAC();
     void PowerOnResetUpdate();
     void EnableINTRef(bool);


   //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~LMH6518~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

     void configureLMH6518CW(CHANNELS_SELECTION eCHSelect);
     void configureLMH6518DW(LMH6518_DataTemplate);
     unsigned int ReadLM6518(LMH6518_DataTemplate);
     void calculateSignalPathGain(VOLTAGEPERDIVISION pEVoltageSelect);

   //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ISLA118P50~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

     void configureADCChip();
     unsigned short readChipVersion();
     unsigned short readChipID();

  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~DSO PSOC~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    void updateDSOPSOC();

 	void functionSelect(FUNSEL);
 	FUNSEL readFunction();

 	void calibEnable(bool);
 	bool calibStatus();

 	void channelSelect(CHSEL);
 	CHSEL readCHSel();

 	void frontAttenuation(FRONT_ATTN);
 	FRONT_ATTN readFrontAttn();

 	void couplingSelect(COUPLING);
 	COUPLING readCoupling();

 	void samplingMode(SMODE);
 	SMODE readSMODESel();

 	void triggerSelect(CHSEL);
 	CHSEL readTriggerCh();

 	void filterSelect(FSEL);
 	FSEL readFilterSel();

 	void selectAttenuation(ATTN_SEL);
 	ATTN_SEL readAttnSel();

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
protected:
     IApplicationCardInterface *IAppCard;

     AD5260 *objAD5260;
     AD5293 *objAD5293;
     AD5318 *objAD5318;
     DAC8563 *objDAC8563;
     ISLA118P50 *objISLA118P50;
     LMH6518 *objLMH6518;
     DSOPSOC *objDSOPSOC;

};

#endif // SPICONTROLLER_H
