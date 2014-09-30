// Project by Ravivarman.R , Created 04-02-2013

#ifndef PTDMMLIBINTERFACE_H
#define PTDMMLIBINTERFACE_H
#include "DMMLibInterface.h"
#include "AppdeviceRegisterDetails.h"
#include "InterfaceFunctionalComponents.h"
#include "ad5318components.h"
#include "IPSOCCommunication.h"
#include "ad7190component.h"
#include <math.h>
#include <unistd.h>
#include <QFile>
#include <QXmlStreamReader>
#include <QDebug>
#include <qpluginloader.h>
#include "macro.h"
//#include <qlibrary.h>
#include <QtCore>
#include "CalibrationInterfaces.h"


class PTDMMLibInterface:public QObject,public IDMMLibInterface
{
    Q_OBJECT
    Q_INTERFACES(IDMMLibInterface)
public:
    PTDMMLibInterface(QObject *parent=0);
    ~PTDMMLibInterface();
    QLibrary   *serialDacCalib;
    IApplicationCardInterface *IAppCard;
    IPSOCCOMMUNICATION *IPsoc;  //PSOC Interface Plugin
    InterfaceCalibrationLib *ICALIB;

    AD5318_DACSELECT m_eSelect;
    AD5318Components *m_objAD5318Component;
    AD5318_dataTemplate l_nAD5318DW;
    double m_nDACVoltage;
    double ADCRxVoltage;

    double gainValue,rangeValue;

    AD7190Component *m_objAD7190;
    short m_nADC;

    bool iamDMM;	bool psuedoMode;

	ADC values;

	double avgRetval[500],retval;
	int noOfSamples,avg;

     unsigned int ForceCurrent(unsigned int,double);
     double MeasureResistance(unsigned int,unsigned int);
     double GetADCVoltage(unsigned int,unsigned int);
     double MeasureVoltage(unsigned int,unsigned int);
     double displayResistance(unsigned int);
     double displayVoltage(unsigned int);
     double displayCurrent(unsigned int);
     double displayDiode(unsigned int);
     double MeasureCurrent(unsigned int,unsigned int);
     unsigned char calibrateDMM();
     void ApplyDACOffset(bool);
     void ApplyDACOffset(double);
     ADC getAdcDatas();
};
#endif // PTDMMLIBINTERFACE_H
