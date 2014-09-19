/*
 * SPIInterface.h
 *
 *  Created on: 30-Apr-2014
 *      Author: ravivarman
 */

#ifndef SPIINTERFACE_H_
#define SPIINTERFACE_H_

#include <QObject>
#include <qpluginloader.h>
#include "Macros.h"
#include "InterfaceFunctionalComponents.h"

class ISPIInterface
{
public:
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~AD5260~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

 virtual void writeAD5260(unsigned short data);

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~AD5293~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

 virtual void configureADC5293CW(SPI1_CONFIGURATION);
 virtual void resetDAC5293(bool bDCRReset);
 virtual void calculateADC5293DATA(AD5293_Template pObjstAD5293);
 virtual unsigned short readADC5293();
 virtual void powerDownmode();
 virtual void writeAD5293(SPI_SELECT peSelect);
 virtual void setAD5293Voltage(double);

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~AD5318~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

 virtual void configureADC5318CW();
 virtual void configureADC5318Data(AD5318_dataTemplate obj);
 virtual void resetDAC5318(bool bDCRReset);

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~DAC8563~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

 virtual void writeDAC8563(unsigned short,unsigned short);

 virtual void WriteUpdateData(unsigned short,unsigned short,unsigned short);
 virtual void PowerUp(unsigned short);
 virtual void PowerDown(unsigned short,unsigned short);
 virtual void SetGain(unsigned short,unsigned short);
 virtual void SetLDAC(unsigned short);
 virtual void ResetDAC();
 virtual void PowerOnResetUpdate();
 virtual void EnableINTRef(bool);


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~LMH6518~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

 virtual void configureLMH6518CW(CHANNELS_SELECTION eCHSelect);
 virtual void configureLMH6518DW(LMH6518_DataTemplate);
 virtual unsigned int ReadLM6518(LMH6518_DataTemplate);
 virtual void calculateSignalPathGain(VOLTAGEPERDIVISION pEVoltageSelect);

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ISLA118P50~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

 virtual void configureADCChip();
 virtual unsigned short readChipVersion();
 virtual unsigned short readChipID();

 //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~DSO PSOC~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

 virtual void updateDSOPSOC();

 virtual void functionSelect(FUNSEL);
 virtual FUNSEL readFunction();

 virtual void calibEnable(bool);
 virtual bool calibStatus();

 virtual void channelSelect(CHSEL);
 virtual CHSEL readCHSel();

 virtual void frontAttenuation(FRONT_ATTN);
 virtual FRONT_ATTN readFrontAttn();

 virtual void couplingSelect(COUPLING);
 virtual COUPLING readCoupling();

 virtual void samplingMode(SMODE);
 virtual SMODE readSMODESel();

 virtual void triggerSelect(CHSEL);
 virtual CHSEL readTriggerCh();

 virtual void filterSelect(FSEL);
 virtual FSEL readFilterSel();

 virtual void selectAttenuation(ATTN_SEL);
 virtual ATTN_SEL readAttnSel();
 //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
};
Q_DECLARE_INTERFACE(ISPIInterface,"pt.SPIInterface/1.0.0.1");
#endif /* SPIINTERFACE_H_ */
