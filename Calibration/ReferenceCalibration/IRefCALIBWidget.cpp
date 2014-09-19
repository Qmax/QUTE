
#include "IRefCALIBWidget.h"

QWidget* IRefCALIBWidget::getRefCALIB(){
	obj=new DACCalibration;
	return obj;
}
Q_EXPORT_PLUGIN2(IRefCALIBTestJigInterface,IRefCALIBWidget);
