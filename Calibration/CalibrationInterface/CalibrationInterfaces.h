/***********************************************************
***************Created by Ravivarman.R,Qmax*****************
***********************************************************/
#ifndef CALIBRATIONINTERFACES_H
#define CALIBRATIONINTERFACES_H
#include<QObject>

    struct CALIB
    {
    	double m_nGain;
    	double m_nConstant;
    };

class InterfaceCalibrationLib
{
public:
        virtual CALIB* ParallelDACCalibration(short )=0;
        virtual double SerialDACCalibration(short )=0;
        virtual void readXmlFile(QString ,QString )=0;
};
Q_DECLARE_INTERFACE(InterfaceCalibrationLib,"pt.calibrationInterface/1.0.0.1");
#endif // CALIBRATIONINTERFACES_H
