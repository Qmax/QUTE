/***********************************************************
***************Created by Ravivarman.R,Qmax*****************
***********************************************************/
#ifndef VCALIBINTERFACE_H
#define VCALIBINTERFACE_H
#include <QObject>
#include <QWidget>
class IVCALIBTestJigInterface
{
public:
	virtual QWidget* getVICALIB()=0;
};

Q_DECLARE_INTERFACE(IVCALIBTestJigInterface,"pt.VCALIBTestJigInterface/1.0.0.1");
#endif // VCALIBINTERFACE_H
