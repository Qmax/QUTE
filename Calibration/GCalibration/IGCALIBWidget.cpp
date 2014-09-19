
#include "IGCALIBWidget.h"

QWidget* IGCALIBWidget::getGCALIB(){
	qDebug()<<"IGCALIBWidget.cpp-Line:5";
	obj=new DACCalibration;
	qDebug()<<"IGCALIBWidget.cpp-Line:7";
	return obj;
}
Q_EXPORT_PLUGIN2(IGCALIBTestJigInterface,IGCALIBWidget);
