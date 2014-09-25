/***********************************************************
***************Created by Ravivarman.R,Qmax*****************
***********************************************************/

#include "IVCALIBWidget.h"

QWidget* IVCALIBWidget::getVICALIB(){
	obj=new DACCalibration;
	return obj;
}
Q_EXPORT_PLUGIN2(IVCALIBTestJigInterface,IVCALIBWidget);
