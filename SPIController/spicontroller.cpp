#include "spicontroller.h"

SPIController::SPIController(QObject *parent) :QObject(parent)
{
    QPluginLoader loaderApp("libPTApplicationcardInterface.so", this);
    IAppCard = qobject_cast<IApplicationCardInterface*> (loaderApp.instance());
    IAppCard->setDeviceName(SLOT0);
    IAppCard->enumerateAPPCard();
    IAppCard->setSPIAppendBit(0xC000);

    objAD5260 = new AD5260(IAppCard);
    objAD5293 = new AD5293(IAppCard);
    objAD5318 = new AD5318(IAppCard);
    objDAC8563 = new DAC8563(IAppCard);
    objISLA118P50 = new ISLA118P50(IAppCard);
    objLMH6518 = new LMH6518(IAppCard);
    objDSOPSOC = new DSOPSOC(IAppCard);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~AD5260~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  void SPIController::writeAD5260(unsigned short data){
    objAD5260->writeAD5260(data);
  }

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~AD5293~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  void SPIController::configureADC5293CW(SPI1_CONFIGURATION config){
    objAD5293->configureADC5293CW(config);
  }
  void SPIController::resetDAC5293(bool bDCRReset){
    objAD5293->resetDAC5293(bDCRReset);
  }
  void SPIController::calculateADC5293DATA(AD5293_Template pObjstAD5293){
    objAD5293->calculateADC5293DATA(pObjstAD5293);
  }
  unsigned short SPIController::readADC5293(){
    return objAD5293->readADC5293();
  }
  void SPIController::powerDownmode(){
    objAD5293->powerDownmode();
  }
  void SPIController::writeAD5293(SPI_SELECT peSelect){
    objAD5293->writeAD5293(peSelect);
  }
  void SPIController::setAD5293Voltage(double volt){
    objAD5293->setAD5293Voltage(volt);
  }

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~AD5318~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  void SPIController::configureADC5318CW(){
    objAD5318->configureADC5318CW();
  }
  void SPIController::configureADC5318Data(AD5318_dataTemplate obj){
    objAD5318->configureADC5318Data(obj);
  }
  void SPIController::resetDAC5318(bool bDCRReset){
    objAD5318->resetDAC5318(bDCRReset);
  }

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~DAC8563~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  void SPIController::writeDAC8563(unsigned short msw,unsigned short lsw){
    objDAC8563->writeDAC8563(msw,lsw);
  }

  void SPIController::WriteUpdateData(unsigned short write,unsigned short update,unsigned short data){
    objDAC8563->WriteUpdateData(write,update,data);
  }
  void SPIController::PowerUp(unsigned short power){
    objDAC8563->PowerUp(power);
  }
  void SPIController::PowerDown(unsigned short power,unsigned short state){
    objDAC8563->PowerDown(power,state);
  }
  void SPIController::SetGain(unsigned short a,unsigned short b){
    objDAC8563->SetGain(a,b);
  }
  void SPIController::SetLDAC(unsigned short dac){
    objDAC8563->SetLDAC(dac);
  }
  void SPIController::ResetDAC(){
    objDAC8563->ResetDAC();
  }
  void SPIController::PowerOnResetUpdate(){
    objDAC8563->PowerOnResetUpdate();
  }
  void SPIController::EnableINTRef(bool state){
    objDAC8563->EnableINTRef(state);
  }


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~LMH6518~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  void SPIController::configureLMH6518CW(CHANNELS_SELECTION eCHSelect){
    objLMH6518->configureLMH6518CW(eCHSelect);
  }
  void SPIController::configureLMH6518DW(LMH6518_DataTemplate dTemp){
    objLMH6518->configureLMH6518DW(dTemp);
  }
  unsigned int SPIController::ReadLM6518(LMH6518_DataTemplate readData){
    return objLMH6518->ReadLM6518(readData);
  }
  void SPIController::calculateSignalPathGain(VOLTAGEPERDIVISION pEVoltageSelect){
    objLMH6518->calculateSignalPathGain(pEVoltageSelect);
  }

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ISLA118P50~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  void SPIController::configureADCChip(){
    objISLA118P50->configureADCChip();
}
  unsigned short SPIController::readChipVersion(){
  objISLA118P50->readChipVersion();
}
  unsigned short SPIController::readChipID(){
  objISLA118P50->readChipID();
}
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~DSO PSOC~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    void SPIController::updateDSOPSOC(){
    	objDSOPSOC->updateDSOPSOC();
    }

 	void SPIController::functionSelect(FUNSEL wrData){
 		objDSOPSOC->functionSelect(wrData);
    }
 	FUNSEL SPIController::readFunction(){
 		return objDSOPSOC->readFunction();
 	}

 	void SPIController::calibEnable(bool wrData){
 		objDSOPSOC->calibEnable(wrData);
 	}
 	bool SPIController::calibStatus(){
 		return objDSOPSOC->calibStatus();
 	}

 	void SPIController::channelSelect(CHSEL wrData){
 		objDSOPSOC->channelSelect(wrData);
 	}
 	CHSEL SPIController::readCHSel(){
 		return objDSOPSOC->readCHSel();
 	}

 	void SPIController::frontAttenuation(FRONT_ATTN wrData){
 		objDSOPSOC->frontAttenuation(wrData);
 	}
 	FRONT_ATTN SPIController::readFrontAttn(){
 		return objDSOPSOC->readFrontAttn();
 	}

 	void SPIController::couplingSelect(COUPLING wrData){
 		objDSOPSOC->couplingSelect(wrData);
 	}
 	COUPLING SPIController::readCoupling(){
 		return objDSOPSOC->readCoupling();
 	}

 	void SPIController::samplingMode(SMODE wrData){
 		objDSOPSOC->samplingMode(wrData);
 	}
 	SMODE SPIController::readSMODESel(){
 		return objDSOPSOC->readSMODESel();
 	}

 	void SPIController::triggerSelect(CHSEL wrData){
 		objDSOPSOC->triggerSelect(wrData);
 	}
 	CHSEL SPIController::readTriggerCh(){
 		return objDSOPSOC->readTriggerCh();
 	}

 	void SPIController::filterSelect(FSEL wrData){
 		objDSOPSOC->filterSelect(wrData);
 	}
 	FSEL SPIController::readFilterSel(){
 		return objDSOPSOC->readFilterSel();
 	}

 	void SPIController::selectAttenuation(ATTN_SEL wrData){
 		objDSOPSOC->selectAttenuation(wrData);
 	}
 	ATTN_SEL SPIController::readAttnSel(){
 		return objDSOPSOC->readAttnSel();
 	}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  Q_EXPORT_PLUGIN2(ISPIInterface, SPIController);
