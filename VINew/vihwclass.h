#ifndef VIHWCLASS_H
#define VIHWCLASS_H

#include <BackPlaneInterface.h>
#include <PTEventInterfaces.h>
#include <CalibrationInterfaces.h>
#include <IPSOCCommunication.h>
#include "ApplicationCardInterface.h"
#include <QPluginLoader>
#include <vimodelview.h>
#include "PTSPIMemoryInterface.h"
#include "ad5318components.h"
#include "ad5293.h"
#include <math.h>
#include <unistd.h>



class VIHWClass
{
public:
    VIHWClass();
    ~VIHWClass()
    {
    	qDebug()<<"HWClass Destructor";
    	IPsoc->closeSerial();
    	IBackPlane->closeObject();

    }
    void initializeHWLibraries();
    unsigned short checkProbeStatus();
    void initializeInterruptSequeces();
    bool checkMUXDetection();
    void switchExternalMux(short int,short int);
    bool readMUXStatus();
    void readTestandRefChannel();
    bool checkSPIMemoryCodeID();
    unsigned int readPSOCID();
    unsigned int switchTestMuxChannel(short int pTestPinChannel);
    unsigned int switchRefMuxChannel(short int pRefPinChannel);
    void switchVoltageRegister(unsigned int);
    void setVoltageConstant(double pVolt);
    void setVoltageGain(double pGain);
    void switchFrequencyRegister(unsigned int);
    void switchPROBE(PROBESELECTION m_eSelection);
    void switchImpedanceRegister(unsigned int);
    void driveRAM(unsigned short int *pData);
    void driveDDS();
    void calculateDDSFrequency(unsigned int);
    void performDrive();
    void performReceive();
    void peformDriveConfiguration();
    void setDriveCount(unsigned short pSamples,unsigned short pPrePostCount);
    unsigned int getDriveCount();
    void writeSPIMemory(unsigned int,unsigned int,short unsigned int *);
    short unsigned int* ReadSPIData(unsigned int,unsigned int);
    void setPSOCDelay();

    void enableInterrupt();
    void disableInterrupt();
    void clearInterrupt();
    unsigned int readEmbKeyValue();
    unsigned int  readAPPCardInterruptValue();
    void writeReceiveRAM();
    void writePSOC(unsigned int);
    void onGNDRelay(bool);
    void resetPSOC();//added by ravivarman 31st july
    unsigned int readPSOC();
    void resetDAC();
    void updateDAC(double pVolt);
    void stopDrive();
    void checkforDriveDoneBit();
    void changePSOCBaudRate(unsigned int);

protected:
    IApplicationCardInterface *IAppCard;
    ISPIMemoryInterface *ISPIMemory;
    IntefaceBackPlane *IBackPlane;
    IPSOCCOMMUNICATION *IPsoc;
    PTEventInterface *IPTKeyEvent;
    AD5318Components *m_objAD5318Component;
    AD5293 *m_objAD5293Component;
    unsigned short int *m_nReceiveData;
    AD5318_DACSELECT m_eSelect;
    double m_nVGain,m_nVConst;
    unsigned int m_nInterruptValue;

private:
    unsigned int m_nDriveCount;



};

#endif // VIHWCLASS_H
