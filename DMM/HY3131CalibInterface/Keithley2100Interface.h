/*
 * hy3131dmmlib.cpp
 *
 *  Created on: 11-Mar-2014
 *      Author: Ravivarman.R
 */

#ifndef KEITHLEY2100INTERFACE_H
#define KEITHLEY2100INTERFACE_H

class IKeithley2100Interface
{
public:
    virtual void clearKeithley()=0;
    virtual void resetKeithley()=0;

	virtual double MeasureResistance(int)=0;
	virtual void ConfigureResistance(int)=0;
        virtual void ConfigureDCVoltage(int)=0;
        virtual double MeasureDCVoltage(int)=0;
        virtual void ConfigureACVoltage(int)=0;
        virtual double MeasureACVoltage(int)=0;
        virtual void ConfigureDCCurrent(int)=0;
        virtual double MeasureDCCurrent(int)=0;
        virtual void ConfigureACCurrent(int)=0;
        virtual double MeasureACCurrent(int)=0;
        virtual void ConfigureDiode(int)=0;
        virtual double MeasureDiode(int)=0;
        virtual void ConfigureContinuity(int)=0;
        virtual double MeasureContinuity(int)=0;
};
Q_DECLARE_INTERFACE(IKeithley2100Interface,"pt.Keithley2100Interface/1.0.0.1");

#endif // KEITHLEY2100INTERFACE_H
