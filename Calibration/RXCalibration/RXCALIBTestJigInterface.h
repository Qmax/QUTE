/***********************************************************
***************Created by Ravivarman.R,Qmax*****************
***********************************************************/
#ifndef RXCALIBINTERFACE_H
#define RXCALIBINTERFACE_H
#include <QObject>
#include <QWidget>
class IRXCALIBTestJigInterface
{
public:
	virtual QWidget* getRXCALIB()=0;
};

Q_DECLARE_INTERFACE(IRXCALIBTestJigInterface,"pt.RXCALIBTestJigInterface/1.0.0.1");
#endif // RXCALIBINTERFACE_H
