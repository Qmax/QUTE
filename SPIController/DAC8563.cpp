#include "DAC8563.h"

DAC8563::DAC8563(IApplicationCardInterface *pobj){
    objAppcard = pobj;
    m_nSPIAppendBit = 0xC000;
}

void DAC8563::writeDAC8563(unsigned short msw,unsigned short lsw){

    unsigned short msw2,lsw2;

	msw2 = (( msw << 8 )   | ( lsw >> 8)  ) ;
	lsw2 = lsw & 0x00FF;

	objAppcard->setSPITXMSW(msw2,SPI1);
    objAppcard->setSPITXLSW(lsw2,SPI1);
    objAppcard->setSPICW(0xC005,SPI1);
    objAppcard->readSPIDriveDoneBit(SPI1);
}

void DAC8563::PowerUp(unsigned short powerup){
	if(powerup==DAC_A){
		writeDAC8563(POWERUP_DACA_CMD_ADDR,POWERUP_DACA_DATA);
	}else if(powerup==DAC_B){
		writeDAC8563(POWERUP_DACB_CMD_ADDR,POWERUP_DACB_DATA);
	}else if(powerup==DAC_AnB){
		writeDAC8563(POWERUP_DACAB_CMD_ADDR,POWERUP_DACAB_DATA);
	}
}
void DAC8563::PowerDown(unsigned short powerdwn,unsigned short state){
	if(powerdwn==DAC_A){
		if(state==GND_1KE){
			writeDAC8563(POWERDWN_DACA_1K_GND_CMD_ADDR,POWERDWN_DACA_1K_GND_DATA);
		}else if(state==GND_100KE){
			writeDAC8563(POWERDWN_DACA_100K_GND_CMD_ADDR,POWERDWN_DACA_100K_GND_DATA);
		}else if(state==GND_HIZ){
			writeDAC8563(POWERDWN_DACA_HIZ_CMD_ADDR,POWERDWN_DACA_HIZ_DATA);
		}
	}else if(powerdwn==DAC_B){
		if(state==GND_1KE){
			writeDAC8563(POWERDWN_DACB_1K_GND_CMD_ADDR,POWERDWN_DACB_1K_GND_DATA);
		}else if(state==GND_100KE){
			writeDAC8563(POWERDWN_DACB_100K_GND_CMD_ADDR,POWERDWN_DACB_100K_GND_DATA);
		}else if(state==GND_HIZ){
			writeDAC8563(POWERDWN_DACB_HIZ_CMD_ADDR,POWERDWN_DACB_HIZ_DATA);
		}
	}else if(powerdwn==DAC_AnB){
		if(state==GND_1KE){
			writeDAC8563(POWERDWN_DACAB_1K_GND_CMD_ADDR,POWERDWN_DACAB_1K_GND_DATA);
		}else if(state==GND_100KE){
			writeDAC8563(POWERDWN_DACAB_100K_GND_CMD_ADDR,POWERDWN_DACAB_100K_GND_DATA);
		}else if(state==GND_HIZ){
			writeDAC8563(POWERDWN_DACAB_HIZ_CMD_ADDR,POWERDWN_DACAB_HIZ_DATA);
		}
	}
}
void DAC8563::SetGain(unsigned short DACAG,unsigned short DACBG){
	if(DACAG==1){
		if(DACBG==1){
			writeDAC8563(DACA_GAIN1_DACB_GAIN1_CMD_ADDR,DACA_GAIN1_DACB_GAIN1_DATA);
		}else if(DACBG==2){
			writeDAC8563(DACA_GAIN1_DACB_GAIN2_CMD_ADDR,DACA_GAIN1_DACB_GAIN2_DATA);
		}
	}else{
		if(DACBG==1){
			writeDAC8563(DACA_GAIN2_DACB_GAIN1_CMD_ADDR,DACA_GAIN2_DACB_GAIN1_DATA);
		}else if(DACBG==2){
			writeDAC8563(DACA_GAIN2_DACB_GAIN2_CMD_ADDR,DACA_GAIN2_DACB_GAIN2_DATA);
		}
	}
}
void DAC8563::SetLDAC(unsigned short DAC){
	if(DAC==DAC_A){
		writeDAC8563(LDAC_PIN_DACA_ACTIVE_DACB_INACTIVE_CMD_ADDR,LDAC_PIN_DACA_ACTIVE_DACB_INACTIVE_DATA);
	}else if(DAC==DAC_B){
		writeDAC8563(LDAC_PIN_DACA_INACTIVE_DACB_ACTIVE_CMD_ADDR,LDAC_PIN_DACA_INACTIVE_DACB_ACTIVE_DATA);
	}else if(DAC==DAC_AnB){
		writeDAC8563(LDAC_PIN_DACA_ACTIVE_DACB_ACTIVE_CMD_ADDR,LDAC_PIN_DACA_ACTIVE_DACB_ACTIVE_DATA);
	}else if(DAC==OFF){
		writeDAC8563(LDAC_PIN_DACA_INACTIVE_DACB_INACTIVE_CMD_ADDR,LDAC_PIN_DACA_INACTIVE_DACB_INACTIVE_DATA);
	}
}
void DAC8563::ResetDAC(){
	writeDAC8563(RESET_DACAB_UPDATE_ALL_CMD_ADDR,RESET_DACAB_UPDATE_ALL_DATA);
}
void DAC8563::PowerOnResetUpdate(){
	writeDAC8563(RESET_ALL_REG_UPDATE_ALL_CMD_ADDR,RESET_ALL_REG_UPDATE_ALL_DATA);
}
void DAC8563::EnableINTRef(bool refState){
	if(refState){
		writeDAC8563(EN_INT_REF_RES_DAC_GAIN2_CMD_ADDR,EN_INT_REF_RES_DAC_GAIN2_DATA);
	}else{
		writeDAC8563(DIS_INT_REF_RES_DAC_GAIN1_CMD_ADDR,DIS_INT_REF_RES_DAC_GAIN1_DATA);
	}
}
void DAC8563::WriteUpdateData(unsigned short write,unsigned short update,unsigned short data){
	if(update==OFF){
		if(update==DAC_A){
			writeDAC8563(WR_DACA_INP_REG,data);
		}else if(update==DAC_B){
			writeDAC8563(WR_DACB_INP_REG,data);
		}else if(update==DAC_AnB){
			writeDAC8563(WR_DACAB_INP_REG,data);
		}
	}
	else if(write==OFF){
		if(write==DAC_A){
			writeDAC8563(UPDATE_DACA_CMD_ADDR,UPDATE_DACA_DATA);
		}else if(write==DAC_B){
			writeDAC8563(UPDATE_DACB_CMD_ADDR,UPDATE_DACB_DATA);
		}else if(write==DAC_AnB){
			writeDAC8563(UPDATE_DAC_ALL_CMD_ADDR,UPDATE_DAC_ALL_DATA);
		}
	}
	else if(update==DAC_AnB){
		if(write==DAC_A){
			writeDAC8563(WR_DACA_INP_REG_UPDATE_DAC_ALL,data);
		}else if(write==DAC_B){
			writeDAC8563(WR_DACB_INP_REG_UPDATE_DAC_ALL,data);
		}else if(write==DAC_AnB){
			writeDAC8563(WR_DACAB_INP_REG_UPDATE_DAC_ALL,data);
		}
	}
	else if(update==DAC_A && write==DAC_A){
		writeDAC8563(WR_DACA_INP_REG_UPDATE_DACA,data);
	}
	else if(update==DAC_B && write==DAC_B){
		writeDAC8563(WR_DACB_INP_REG_UPDATE_DACB,data);
	}
}
