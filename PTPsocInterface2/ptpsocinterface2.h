#ifndef PTPSOCINTERFACE_H
#define PTPSOCINTERFACE_H

/*
 * Library - Serial Library
 * Author  - Ravivarman.R
 * Updated - 15th Jan 2013
 * Updated - 23rd Oct 2013
 * Updated - 15th May 2014 (Modified for New Front Panel)
 */
#include     <sys/ioctl.h>
#include <linux/ioctl.h>
#include <linux/serial.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>
#include <stdlib.h>
#include<sys/file.h>
#include"serialdevice.h"
#include "qextserialport.h"
#include <QtCore>
#include <QDebug>
#include <qobject.h>
#include <qobjectdefs.h>
#include <IPSOCCommunication.h>



class  Seriallib: public QObject {
        Q_OBJECT
public:
        Seriallib();
        Seriallib(QObject*);
        QByteArray xData;
        void PortListener(const QString & portName);
        QLibrary *Q_EXTSERIAL_LIB;
        unsigned int onReadyRead();
        QByteArray onReadyRead(QByteArray l_arrValue);
        unsigned int onReadyWrite(unsigned int);
        void openPort(QObject*);
        unsigned int onCloseSerial();
        bool rxAck();
        QextSerialPort *port;

private:
        signals:
        void Error(bool);
};



class PTPsocInterface2:public QObject,public IPSOCCOMMUNICATION
{
    Q_OBJECT
    Q_INTERFACES(IPSOCCOMMUNICATION)
public:
   // PTPsocInterface(QObject *parent = 0);
    int openSerial();
    int configSerial(int fd,int nSpeed, int nBits, char nEvent, int nStop);
    unsigned int readSerial();
    QByteArray readSerByte();
    unsigned int writeSerial(unsigned int);
    int closeSerial();
    bool getAck();
    //Functions
    void createObject(QObject *parent);
    unsigned int viTrace(unsigned int);
    void vi_channels(unsigned int ch);
    unsigned int readPsocCodeID();
    void icmMeasurement();
    void switchFly();
    unsigned int externalMuxMeasurement(unsigned int,unsigned int);
    bool readMuxStatus();
    unsigned int changeBaudRate(unsigned int baudRate);
    unsigned int switchRef(unsigned int refChannel);
    unsigned int switchTest(unsigned int testChannel);
    unsigned int muxDetection();
    void FGMeasurement();
    unsigned int embeddedProbe();
    unsigned int embeddedProbeStatus();
    unsigned int embeddedProbeInterrupt();
    unsigned int resetRelays();
    unsigned int readRelay();
    unsigned int readSRCIMPRelay();
    void srcImpedanceSelection(unsigned int);
    void srcImpedanceEnable(bool);

    QMap<unsigned int,QByteArray>src_impedance;

};

#endif // PTPSOCINTERFACE_H
