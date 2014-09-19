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
    virtual unsigned int viTrace(unsigned int)=0;
    virtual unsigned int checkBusy()=0;
    virtual unsigned int readPsocCodeID()=0;
    virtual unsigned int dmmMeasurement(unsigned int,int,unsigned int)=0;
    virtual unsigned int dmmVoltage(unsigned int)=0;
    virtual unsigned int dmmCurrent(unsigned int)=0;
    virtual unsigned int dmm2Wire(unsigned int)=0;
    virtual unsigned int dmm4Wire(unsigned int)=0;
    virtual void shLocatorDetection()=0;
    virtual void icmMeasurement()=0;

    virtual unsigned int externalMuxMeasurement(unsigned int,unsigned int)=0;
    virtual bool readMuxStatus()=0;
    virtual unsigned int changeBaudRate(unsigned int baudRate)=0;
    virtual unsigned int switchRef(unsigned int refChannel)=0;
    virtual unsigned int switchTest(unsigned int testChannel)=0;
    virtual unsigned int muxDetection()=0;

    virtual unsigned int scopeMeasurement(unsigned int,unsigned int)=0;
    virtual void FGMeasurement()=0;
    virtual unsigned int embeddedProbe()=0;
    virtual unsigned int embeddedProbeStatus()=0;
    virtual unsigned int embeddedProbeInterrupt()=0;
    virtual unsigned int resetRelays()=0;
    virtual unsigned int onTopRelay(unsigned int)=0;
    virtual unsigned int offTopRelay(unsigned int)=0;
    virtual unsigned int onBottomRelay(unsigned int)=0;
    virtual unsigned int offBottomRelay(unsigned int)=0;
    virtual unsigned int readRelay()=0;

    //Combination functions
    virtual void createObject(QObject* parent)=0;

    virtual void	dmm_voltage(unsigned int select)=0;
    virtual void dmm_current(unsigned int select)=0;
    virtual void	dmm_2wire(unsigned int select)=0;
    virtual void dmm_4wire(unsigned int select)=0;
    virtual unsigned int scope_channels(unsigned int channel,unsigned int range)=0;
    virtual unsigned int PWMStart()=0;
    virtual unsigned int PWMStop()=0;
    virtual void vi_channels(unsigned int ch)=0;
    virtual unsigned int Vi12_Scope2(unsigned int vi_ch,unsigned int scope_range)=0;
    virtual unsigned int ShLoc_Scope2(unsigned int shloc_state,unsigned int scope_range)=0;
    virtual unsigned int DMM_Scope2(unsigned int dmm_select,unsigned int dmm_range,unsigned int scope_range)=0;
    virtual void Fg_state(unsigned int state)=0;
    virtual unsigned int FG_Scope12(unsigned int fg_state,unsigned int scope1_range,unsigned int scope2_range)=0;
    virtual unsigned int Scope1_FG_Scope2(unsigned int scope1_range,unsigned int fg_state,unsigned int scope2_range)=0;
    virtual unsigned int Scope2_FG_Scope1(unsigned int scope2_range,unsigned int fg_state,unsigned int scope1_range)=0;
};
Q_DECLARE_INTERFACE(IPSOCCOMMUNICATION,"pt.PSoCInterface/1.0.0.1");

#endif // IPSOCCOMMUNICATION_H
