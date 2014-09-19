#ifndef PTEVENTINTERFACES_H
#define PTEVENTINTERFACES_H

#include<QWidget>
#include<QString>
enum APPID{VI,DSO};

enum SAMPLING_TYPE{NORMAL=0,MIN_MAX,AVERAGE,MOVING_AVERAGE,LINEAR_INTERPOLATION,MOVING_LINEAR,WAVEFORM_MEMORY};

class PTGPIOEventInterface
{
public:
    virtual void  InvokeGPIOEvent(QWidget *parent,QString driver, QString device,int *pKeyCode)=0;
    virtual void closefd(void)=0;
    virtual bool BlockSig(bool get)=0;
    virtual void setStopFlag(bool)=0;
    virtual void setProbeFlag(short int)=0;
    virtual  void setApplicationID(APPID)=0;
    virtual QObject* getGPIOObject()=0;
    virtual void setFSSettings(double,double,int,int,int)=0;
    virtual void setSamplingType(SAMPLING_TYPE pRece)=0;
    virtual void setFIFOMode(int)=0;
    virtual void driveDSO(bool)=0;
};


Q_DECLARE_INTERFACE(PTGPIOEventInterface,"pt.PTEventInterface/1.0.0.1");


#endif // PTEVENTINTERFACES_H
