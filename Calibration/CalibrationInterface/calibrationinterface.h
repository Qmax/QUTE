    /*
     * Library - Calibration Library
     * Author  - Ravivarman.R
     * Last Updated - 15th Jan 2013
     * Converted into Interface - 5th March 2013
    */

#ifndef CALIBRATIONINTERFACE_H
#define CALIBRATIONINTERFACE_H

#include "CalibrationInterfaces.h"
#include <QObject>
#include <QtCore>

    //~~~~~Header Files~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    #include <QMap>
    #include <QXmlStreamReader>
    #include <QXmlStreamAttributes>
    #include <QXmlStreamReader>
    #include <QFile>
    #include <QDebug>
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    //~~~~~Macros~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    //SerialDACCalibration
    #define R200E   1
    #define R2K     2
    #define R20K    3
    #define R200K   4
    #define R2M     5
    #define R20M    6
    #define R2E		7
    #define R200mE	8
    #define SLR200E 9

    #define milli	(1/1000)
    #define K   1000
    #define M   1000000

    #define SERIALDAC 0

    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

class CalibrationInterface : public QObject,public InterfaceCalibrationLib{
    Q_OBJECT
    Q_INTERFACES(InterfaceCalibrationLib)
public:
    //~~~~Declarations~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    QMap<short,double>Ix;       //Uncalibrated current
    QMap<short,double>Rf;       //FeedBack Resistance

    QMap<short,double>RxGain;
    QMap<short,double>RxConstant;

//    struct CALIB
//    {
//    	double m_nGain;
//    	double m_nConstant;
//    };
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    //~~~~Local Functions~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    void Mapping(int);
    CalibrationInterface();
    ~CalibrationInterface();
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    //~~~~Shared Functions~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        CALIB* ParallelDACCalibration(short range);
        double SerialDACCalibration(short range);
        void readXmlFile(QString fileName,QString startElement);
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
};

#endif // CALIBRATIONINTERFACE_H
