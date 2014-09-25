/***********************************************************
***************Created by Ravivarman.R,Qmax*****************
***********************************************************/
#include "hy3131calibinterface.h"


QWidget* HY3131CALIBINTERFACE::getCALIB(){
        obj=new HY3131Calibration;
        return obj;
}

Q_EXPORT_PLUGIN2(IHY3131CalibInterface, HY3131CALIBINTERFACE)
