/*
 * hy3131dmmlib.cpp
 *
 *  Created on: 12-Mar-2014
 *      Author: Ravivarman.R
 */
#ifndef HY3131CALIB_H
#define HY3131CALIB_H

class IHY3131CalibInterface
{
public:
	virtual QWidget* getCALIB()=0;
};
Q_DECLARE_INTERFACE(IHY3131CalibInterface,"pt.HY3131CalibInterface/1.0.0.1");


#endif // HY3131CALIB_H
