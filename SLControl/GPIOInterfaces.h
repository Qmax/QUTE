/*
 * GPIOInterfaces.h
 *
 *  Created on: 20-Mar-2013
 *      Author: Ravivarman R
 */

#ifndef GPIOINTERFACES_H_
#define GPIOINTERFACES_H_

#include<QObject>

class InterfaceGPIOPins
{
public:
    virtual int toggleTouchButton()=0;
    virtual int illuminateScaleButton(int val)=0;
    virtual int illuminateRunStopButton(int val)=0;
    virtual int killSystem()=0;
};
Q_DECLARE_INTERFACE(InterfaceGPIOPins,"pt.gpiopinInterface/1.0.0.1");



#endif /* GPIOINTERFACES_H_ */
