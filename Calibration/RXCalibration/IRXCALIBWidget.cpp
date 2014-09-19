
#include "IRXCALIBWidget.h"

QWidget* IRXCALIBWidget::getRXCALIB(){
	obj=new DACCalibration;
	return obj;
}
Q_EXPORT_PLUGIN2(IRXCALIBTestJigInterface,IRXCALIBWidget);
