#ifndef DMMLIBINTERFACE_H
#define DMMLIBINTERFACE_H
#include <QObject>
#include <qpluginloader.h>
#include <qlibrary.h>

struct ADC{
	unsigned int Data;
	double ConvertedData,CalibratedData;
};

class IDMMLibInterface
{
public:
//	QLibrary   *serialDacCalib;
//     IApplicationCardInterface *IAppCard; //ApplicationInterfacePlugin
//     IPSOCCOMMUNICATION *IPsoc;  //PSOC Interface Plugin
     virtual unsigned int ForceCurrent(unsigned int,double)=0;
     virtual double MeasureResistance(unsigned int,unsigned int)=0;
     virtual double GetADCVoltage(unsigned int,unsigned int)=0;
     virtual double MeasureVoltage(unsigned int,unsigned int)=0;
     virtual double displayResistance(unsigned int)=0;
     virtual double displayVoltage(unsigned int)=0;
     virtual double displayCurrent(unsigned int)=0;
     virtual double displayDiode(unsigned int)=0;
     virtual double MeasureCurrent(unsigned int,unsigned int)=0;
     virtual unsigned char calibrateDMM()=0;
     virtual void ApplyDACOffset(bool)=0;
     virtual void ApplyDACOffset(double)=0;
     virtual ADC getAdcDatas()=0;

};
Q_DECLARE_INTERFACE(IDMMLibInterface,"pt.DMMLibInterface/1.0.0.1");
#endif // DMMLIBINTERFACE_H
