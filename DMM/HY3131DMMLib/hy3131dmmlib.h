/*
 * hy3131dmmlib.h
 *
 *  Created on: 04-Mar-2014
 *      Author: Ravivarman.R
 */

/*(20062014)      changed on Jun 20,2014 for AC Measurement correction    */

#ifndef HY3131DMMLIB_H
#define HY3131DMMLIB_H

#include <unistd.h>
#include <QtCore>
#include <QPluginLoader>
#include <QFile>
#include <qdebug.h>
#include "ApplicationCardInterface.h"
#include "BackPlaneInterface.h"
#include "HY3131DMMLibInterface.h"
#include "HY3131Macro.h"


class HY3131DMMLib :public QObject,public IHY3131DMMLibInterface {
    Q_OBJECT
    Q_INTERFACES(IHY3131DMMLibInterface)

public:
    HY3131DMMLib(QObject *parent = 0);
    ~HY3131DMMLib();

    void Configure(int8_t);
    double Measure(int8_t);
    double Measure2(int8_t);
    void buzzerState(bool);
    bool busyFlag();
    void on_ReadAll();
    u_int32_t readPKHMIN();
    u_int32_t readPKHMAX();
    u_int32_t readDMMSPI(u_int16_t);
    void writeDMMSPI(u_int16_t,u_int16_t);

    void resetDMMSPI();
//    u_int32_t readDMMSPI(u_int16_t);
//    void writeDMMSPI(u_int16_t,u_int16_t);

    u_int32_t readADC1(u_int8_t r0=0x00,u_int8_t r1=0x01,u_int8_t r2=0x02);
    u_int32_t readADC2();
    u_int32_t readLPF();
    /*(20062014)u_int64_t readRMS();*/u_int32_t readRMS();
//    u_int32_t readPKHMIN();
//    u_int32_t readPKHMAX();


protected:
    SPI_SELECT m_mapSPISelect;
    IApplicationCardInterface *IAppCard;
    IntefaceBackPlane *IBackPlane;			//BackPlaneInterfacePlugin

	u_int8_t reg0,reg1,reg2,reg3;
	/*(20062014)u_int64_t*/ u_int32_t reg4;
	u_int32_t ADCDigital;
	/*(20062014)u_int64_t*/ u_int32_t RMSData;
	double ReadData,RawData;
	u_int32_t D32Bit;

    QString m_strRange[31];
    double m_nGain[31],m_nOffset[31];

    int m_nSampleCount;

    bool minus;
    bool buzState;
    bool busyState;
    bool selAppCard;
};

#endif // HY3131DMMLIB_H
