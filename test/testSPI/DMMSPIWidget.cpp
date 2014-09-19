
#include "DMMSPIWidget.h"

QWidget* DMMSPIWidget::getDMMSPI(){
	obj=new testSPI;
	return obj;
}
Q_EXPORT_PLUGIN2(DMMSPITestJigInterface,DMMSPIWidget);
