/*
 * HY3131DMMLibInterface.h
 *
 *  Created on: 04-Mar-2014
 *      Author: Ravivarman.R
 */
#ifndef HY3131DMMLIBINTERFACE_H
#define HY3131DMMLIBINTERFACE_H

#include <QObject>


class IHY3131DMMLibInterface
{
public:
    virtual void Configure(int8_t)=0;
    virtual double Measure(int8_t)=0;
    virtual double Measure2(int8_t)=0;
    virtual void buzzerState(bool)=0;
    virtual bool busyFlag()=0;
    virtual void on_ReadAll()=0;

    virtual u_int32_t readPKHMIN()=0;
    virtual u_int32_t readPKHMAX()=0;

    virtual u_int32_t readDMMSPI(u_int16_t)=0;
    virtual void writeDMMSPI(u_int16_t,u_int16_t)=0;
};
Q_DECLARE_INTERFACE(IHY3131DMMLibInterface,"pt.HY3131DMMLibInterface/1.0.0.1");


#endif // HY3131DMMLIBINTERFACE_H