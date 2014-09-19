/*
 * DSOPSOC.cpp
 *
 *  Created on: 06-May-2014
 *      Author: ravivarman
 */

#include "DSOPSOC.h"

DSOPSOC::DSOPSOC(IApplicationCardInterface *pobj) {
    objAppcard = pobj;
    m_nSPIAppendBit = 0xC000;
	WR_DATA = 0x0000;
}

DSOPSOC::~DSOPSOC() {
}

unsigned short DSOPSOC::readDSOPSOC(){
	objAppcard->setSPITXMSW(0x8000,SPI1);
    objAppcard->setSPICW(0xC00B,SPI1);
    objAppcard->readSPIDriveDoneBit(SPI1);
	usleep(1000);
	return objAppcard->getSPIRXLSW(SPI1);
}

void DSOPSOC::writeDSOPSOC(unsigned short data){

	objAppcard->setSPITXMSW(data,SPI1);
    objAppcard->setSPICW(0xC003,SPI1);
    objAppcard->readSPIDriveDoneBit(SPI1);
}

void DSOPSOC::updateDSOPSOC(){
	writeDSOPSOC(WR_DATA);
}

void DSOPSOC::functionSelect(FUNSEL wrData){
	WR_DATA = 0x0000;
	WR_DATA = WR_DATA | (wrData << 13);
}

FUNSEL DSOPSOC::readFunction(){
	if((readDSOPSOC() & 0x6000)==DSO)
		return DSO;
	else if((readDSOPSOC() & 0x6000)==TRIGGER)
		return TRIGGER;
	else if((readDSOPSOC() & 0x6000)==AWG)
		return AWG;
}

void DSOPSOC::calibEnable(bool wrData){
	WR_DATA = WR_DATA | (wrData << 7);
}

bool DSOPSOC::calibStatus(){
	return (readDSOPSOC() & 0x0080);
}

void DSOPSOC::channelSelect(CHSEL wrData){
	WR_DATA = WR_DATA | (wrData << 5);
}

CHSEL DSOPSOC::readCHSel(){
	if((readDSOPSOC() & 0x0080)==CH1)
		return CH1;
	else if((readDSOPSOC() & 0x0080)==CH2)
		return CH2;
	else if((readDSOPSOC() & 0x0080)==EXT)
		return EXT;
}

void DSOPSOC::frontAttenuation(FRONT_ATTN wrData){
	if(readCHSel() == EXT){
		if(wrData == DIV_10 || wrData == DIV_1)
			WR_DATA = WR_DATA | (wrData << 3);
	}else
			WR_DATA = WR_DATA | (wrData << 3);
}

FRONT_ATTN DSOPSOC::readFrontAttn(){
	if((readDSOPSOC() & 0x0060)==DIV_100)
		return DIV_100;
	else if((readDSOPSOC() & 0x0060)==DIV_10)
		return DIV_10;
	else if((readDSOPSOC() & 0x0060)==DIV_5)
		return DIV_5;
	else if((readDSOPSOC() & 0x0060)==DIV_1)
		return DIV_1;
}

void DSOPSOC::couplingSelect(COUPLING wrData){
	WR_DATA = WR_DATA | (wrData << 1);
}

COUPLING DSOPSOC::readCoupling(){
	if((readDSOPSOC() & 0x0006)==AC_COUPLING)
		return AC_COUPLING;
	else 	if((readDSOPSOC() & 0x0006)==DC_COUPLING)
		return DC_COUPLING;
}

void DSOPSOC::samplingMode(SMODE wrData){
	WR_DATA = WR_DATA | wrData ;
}

SMODE DSOPSOC::readSMODESel(){
	if((readDSOPSOC() & 0x0001)==NORMAL)
		return NORMAL;
	else if((readDSOPSOC() & 0x0001)==INTERLACED)
		return INTERLACED;
}

void DSOPSOC::triggerSelect(CHSEL wrData){
	WR_DATA = WR_DATA | wrData;
}

CHSEL DSOPSOC::readTriggerCh(){
	if((readDSOPSOC() & 0x0003)==CH1)
		return CH1;
	if((readDSOPSOC() & 0x0003)==CH2)
		return CH2;
	if((readDSOPSOC() & 0x0003)==EXT)
		return EXT;
}

void DSOPSOC::filterSelect(FSEL wrData){
	WR_DATA = WR_DATA | (wrData << 4);
}

FSEL DSOPSOC::readFilterSel(){
	if((readDSOPSOC() & 0x0010)==BEZZEL)
		return BEZZEL;
	else if((readDSOPSOC() & 0x0010)==ELIPTICAL)
			return ELIPTICAL;
}

void DSOPSOC::selectAttenuation(ATTN_SEL wrData){
	WR_DATA = WR_DATA | wrData;
}

ATTN_SEL DSOPSOC::readAttnSel(){
	if((readDSOPSOC() & 0x0007)==_0dB)
		return _0dB;
	else if((readDSOPSOC() & 0x0007)==_6dB)
		return _6dB;
	else if((readDSOPSOC() & 0x0007)==_12dB)
		return _12dB;
	else if((readDSOPSOC() & 0x0007)==_18dB)
		return _18dB;
	else if((readDSOPSOC() & 0x0007)==_24dB)
		return _24dB;
	else if((readDSOPSOC() & 0x0007)==_30dB)
		return _30dB;
}
