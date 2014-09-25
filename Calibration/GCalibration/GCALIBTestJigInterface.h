/***********************************************************
***************Created by Ravivarman.R,Qmax*****************
***********************************************************/
#ifndef GCALIBINTERFACE_H
#define GCALIBINTERFACE_H
#include <QObject>
#include <QWidget>
class IGCALIBTestJigInterface
{
public:
        virtual QWidget* getGCALIB()=0;
};

Q_DECLARE_INTERFACE(IGCALIBTestJigInterface,"pt.GCALIBTestJigInterface/1.0.0.1");
#endif // GCALIBINTERFACE_H
