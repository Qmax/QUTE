/*
 *      Author: Ravivarman.R,Qmax
 */
#ifndef IPSOCCOMMUNICATION_H
#define IPSOCCOMMUNICATION_H
#include <QByteArray>
#include <QObject>

class IPSOCCOMMUNICATION
{
public:
    virtual int openSerial()=0;
    virtual int configSerial(int fd,int nSpeed, int nBits, char nEvent, int nStop)=0;
    virtual unsigned int readSerial()=0;
    virtual QByteArray readSerByte()=0;
    virtual unsigned int writeSerial(unsigned int)=0;
    virtual int closeSerial()=0;
    virtual bool getAck()=0;
    //Functions
    virtual void vi_channels(unsigned int ch)=0;
    virtual	unsigned int viTrace(unsigned int)=0;
    virtual unsigned int readPsocCodeID()=0;
    virtual void icmMeasurement()=0;
    virtual void switchFly()=0;
    virtual unsigned int externalMuxMeasurement(unsigned int,unsigned int)=0;
    virtual bool readMuxStatus()=0;
    virtual unsigned int changeBaudRate(unsigned int baudRate)=0;
    virtual unsigned int switchRef(unsigned int refChannel)=0;
    virtual unsigned int switchTest(unsigned int testChannel)=0;
    virtual unsigned int muxDetection()=0;
    virtual void FGMeasurement()=0;
    virtual unsigned int embeddedProbe()=0;
    virtual unsigned int embeddedProbeStatus()=0;
    virtual unsigned int embeddedProbeInterrupt()=0;
    virtual unsigned int resetRelays()=0;
    virtual unsigned int readRelay()=0;
    virtual unsigned int readSRCIMPRelay()=0;
    virtual void createObject(QObject *parent)=0;
    virtual void srcImpedanceSelection(unsigned int)=0;
    virtual void srcImpedanceEnable(bool)=0;

};
Q_DECLARE_INTERFACE(IPSOCCOMMUNICATION,"pt.PSoCInterface/1.0.0.1");

#endif // IPSOCCOMMUNICATION_H
