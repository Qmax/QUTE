#include "IPSoCWidget.h"

void IPSOCWidget::setPSOC(QWidget* parent){
	obj=new PTPSoCTestJigInterface2(parent);
	obj->show();
}
void IPSOCWidget::closePSOC(){
	delete obj;
}
void IPSOCWidget::HardwareInitializtaion()
{

}
Q_EXPORT_PLUGIN2(IPSOCTestJigInterface2,IPSOCWidget);
