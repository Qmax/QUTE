#ifndef GPIOEVENTINTERFACE_H
#define GPIOEVENTINTERFACE_H

#include<QtCore>
#include<PTGPIOEventInterfaces.h>
#include<BackPlaneInterface.h>
#include "ApplicationCardInterface.h"
#include "AppdeviceRegisterDetails.h"
#include "IPSOCCommunication.h"
#include "PTSPIMemoryInterface.h"
#include <QtGui>
#include <QWSKeyboardHandler>

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>


#include <linux/input.h>
#include <linux/kd.h>
#include  <QMessageBox>

#include <qdebug.h>

#if 1
#define qLog(x) qDebug()
#else
#define qLog(x) while (0) qDebug()
#endif


const QEvent::Type GpioEvent = (QEvent::Type) 1234;//embedded probe
const QEvent::Type KnobEvent=  (QEvent::Type) 3456;//magnetic knob
const QEvent::Type ShutDownEvent=  (QEvent::Type) 7890;//shutdown
const QEvent::Type APPCARDDRIVEEVENT = (QEvent::Type) 7892;//Appcard drive Event
const QEvent::Type MouseEvent=  (QEvent::Type) 7894;//mouse


class GPIOEvent;

class GpioEventInterface:public QObject,public PTGPIOEventInterface {
    Q_OBJECT
    Q_INTERFACES(PTGPIOEventInterface)
public:
    ~GpioEventInterface(){}
    void  InvokeGPIOEvent(QWidget *parent,QString driver, QString device,int *pKeyCode);
    void closefd(void);
    void setStopFlag(bool);
    bool BlockSig(bool get);
    void setProbeFlag(short int);
    void setApplicationID(APPID);
    void driveDSO(bool);
    QObject* getGPIOObject() { return (QObject*)g_objGPIOevent;}
    //void convertToDecimation(double pVolt,double pFSSettings,int pRectWidth,DSO_RECEIVE_FIFO pSelFIFO,int pSampleCount,bool pOdd,bool pEven)
    void setFSSettings(double pVoltage,double pFSSettings,int pSamples,int pRectWidth,int pReceFIFO);
    void setFIFOMode(int);
    void setSamplingType(SAMPLING_TYPE pType);

protected:
    GPIOEvent *g_objGPIOevent;
    private slots:

};


class GPIOEvent:public QWidget,public QWSKeyboardHandler {
    Q_OBJECT
public:

    GPIOEvent(QWidget *parent=0,int *pKey=0);
    ~GPIOEvent();
    int callclosefd();
    void create(QString driver, QString device);
    void startKnobDrive();

    void setStopEvent(bool pFlag);
    void setProbeFlag(short int);
    void driveDSO(bool);
    void setForceTrigger(bool);
    void setAPPID(APPID pAPPID);
    void setFSSettings(double,double);

    QLibrary *backPlaneLibrary;
    unsigned int l_nRegisterValue;
    QWidget *m_TW;
    void performReceive(QString);
    void writeReceiveRAM();
    void enableInterrupt();
    unsigned short int *m_nReceiveData;
    QString m_strReceiveName;
    void setFSSettings(double pVoltage,double pFSsettings,int pSamples,int pRectWidth,int pReceFIFO)
    {
    	m_nSamples = pSamples;
    	m_nVolt = pVoltage;
    	m_nFSSettings = pFSsettings;
    	m_eReceFIFO = pReceFIFO;
    	m_nRectWidth = pRectWidth;
    	qDebug()<<"GPIO-EVENT-------------------------------";
    		qDebug()<<"SAMPLES:"<<m_nSamples;
    		qDebug()<<"Voltage:"<<m_nVolt;
    		qDebug()<<"FSSettings:"<<m_nFSSettings;
    		qDebug()<<"Receive FIFO:"<<m_eReceFIFO;
    		qDebug()<<"Rect Width:"<<m_nRectWidth;
    		qDebug()<<"Sample Type"<<m_eSamplesType;
    	qDebug()<<"-------------------------------------------";
    }
    void setSamplingType(SAMPLING_TYPE pType)
    {
    	m_eSamplesType=pType;
    }

    void setFIFOMode(int pReceFIFO)
    {
    	m_eReceFIFO = pReceFIFO;
    }

    void readFIFORegister();
protected:
    	unsigned char findMaxPoint(QList<unsigned char> plstPoints);
    	unsigned char findMinPoint(QList<unsigned char> plstPoints);
    	unsigned char calculateAveragePoints(QList<unsigned char> plstPoints);
    	QList<unsigned char> calcuateMovingAverage(QList<unsigned char> plstPoints);
        IntefaceBackPlane *IBackPlane;	//BackPanel Interface
        IApplicationCardInterface *IAppCard;
        ISPIMemoryInterface *ISPIMemory;
        IPSOCCOMMUNICATION *IPsoc;
        bool m_stopFlag;
        short int m_nProbeValue;
        unsigned int m_nInterruptValue;
        APPID m_eAPPID;
        QEvent *m_objEvent;
        double m_nMinPoint,m_nMaxPoint,m_nAveragePoint;
        QList<unsigned char> m_lstOddPoints,m_lstEvenPoints;
        signals:
        	void postAPP(QList<unsigned char>,QList<unsigned char>);
private:
    QSocketNotifier *m_notify;
    int shutDownFD;
    int  kbdFD;
    int mouseFD;
    bool shift;
    int *m_nKey;
    double m_nVolt,m_nFSSettings;
    int m_nSamples;
    int m_eReceFIFO;
    SAMPLING_TYPE m_eSamplesType;
    int m_nRectWidth;
private Q_SLOTS:
    void readKbdData();
    void readMouseData();



};



class PTKeyPressEvent:public QEvent
{
public:
        //static const QEvent::Type myType = static_cast<QEvent::Type>(2000);
        PTKeyPressEvent(int pKbdData):QEvent((QEvent::Type)1236)
        {
                //PTKeyPressEvent = (QEvent::Type)1234;
                m_nKeycode = pKbdData;
                qLog() << "PTKEYCODE" << hex << pKbdData;
        }
        int m_nKeycode;
public slots:

protected:

};


#endif // GPIOEVENTINTERFACE_H
