#ifndef DSOCARDINTERFACE_H
#define DSOCARDINTERFACE_H


#include <QObject>

class IDSOCardInterface
{
public:
	virtual void setDeviceName()=0;
	virtual void enumerateDSOCard()=0;
	virtual unsigned int readDSOCardCodeId()=0;
	virtual void writeScratchpad(unsigned int)=0;
	virtual unsigned int readScratchPad()=0;
	virtual unsigned int readRegister(unsigned int)=0;
	virtual void writeRegister(unsigned int,unsigned int)=0;
};
Q_DECLARE_INTERFACE(IDSOCardInterface,"pt.DSOCardInterface/1.0.0.1");

#endif // DSOCARDINTERFACE_H
