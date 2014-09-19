
#include "IPTAppBckPsocWidget.h"

QWidget* IPTAppBckPsocWidget::getPTAppBckPsoc(){
	obj=new PTPSoCTestJigInterface;
	return obj;
}
Q_EXPORT_PLUGIN2(IPTAppBckPsocTestJigInterface,IPTAppBckPsocWidget);
