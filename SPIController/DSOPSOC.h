/*
 * DSOPSOC.h
 *
 *  Created on: 06-May-2014
 *      Author: ravivarman
 */

#ifndef DSOPSOC_H_
#define DSOPSOC_H_

#include <ApplicationCardInterface.h>
#include <unistd.h>
#include "Macros.h"

class DSOPSOC {
public:
	DSOPSOC(IApplicationCardInterface *pobj);
	~DSOPSOC();

	unsigned short readDSOPSOC();
	void writeDSOPSOC(unsigned short);
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

protected:
    IApplicationCardInterface *objAppcard;
    unsigned short int m_nSPIAppendBit;
    unsigned short WR_DATA,RD_DATA;
};

#endif /* DSOPSOC_H_ */
