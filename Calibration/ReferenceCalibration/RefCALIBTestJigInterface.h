/***********************************************************
***************Created by Ravivarman.R,Qmax*****************
***********************************************************/
#ifndef RefCALIBINTERFACE_H
#define RefCALIBINTERFACE_H
#include <QObject>
#include <QWidget>
class IRefCALIBTestJigInterface
{
public:
	virtual QWidget* getRefCALIB()=0;
};

Q_DECLARE_INTERFACE(IRefCALIBTestJigInterface,"pt.RefCALIBTestJigInterface/1.0.0.1");
#endif // RefCALIBINTERFACE_H
