
#include "IPTDACFWidget.h"

QWidget* IPTDACFWidget::getPTDACF(){
        obj=new DACFWidget;
	return obj;
}
Q_EXPORT_PLUGIN2(IPTDACFTestJigInterface,IPTDACFWidget);
