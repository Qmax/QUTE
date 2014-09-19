/*
 * AD5260.h
 *
 *  Created on: 05-May-2014
 *      Author: ravivarman
 */

#ifndef AD5260_H_
#define AD5260_H_

#include <ApplicationCardInterface.h>


class AD5260 {
public:
	AD5260(IApplicationCardInterface *pobj);
	~AD5260();
	void writeAD5260(unsigned short data);
protected:
    IApplicationCardInterface *objAppcard;
    unsigned short int m_nSPIAppendBit;

};

#endif /* AD5260_H_ */
