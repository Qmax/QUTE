/*
 * AD5260.cpp
 *
 *  Created on: 05-May-2014
 *      Author: ravivarman
 */

#include "AD5260.h"

AD5260::AD5260(IApplicationCardInterface *pobj) {
    objAppcard = pobj;
    m_nSPIAppendBit = 0xC000;
}

AD5260::~AD5260() {
}

void AD5260::writeAD5260(unsigned short data){

	unsigned short mData;
	mData = data << 8;

	objAppcard->setSPITXMSW(mData,SPI2);
    objAppcard->setSPICW(0xC001,SPI2);
    objAppcard->readSPIDriveDoneBit(SPI2);
}
