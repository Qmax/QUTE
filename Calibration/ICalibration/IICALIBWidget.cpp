
#include "IICALIBWidget.h"

QWidget* IICALIBWidget::getIICALIB(){
	obj=new DACCalibration;
	return obj;
}
Q_EXPORT_PLUGIN2(IICALIBTestJigInterface,IICALIBWidget);
