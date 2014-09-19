
#include "IPWFWidget.h"

void IPWFWidget::setPWF(QWidget* parent){
	obj=new Widget(parent);
	obj->show();
}
void IPWFWidget::closePWF(){
	delete obj;
}
void IPWFWidget::HardwareInitializtaion()
{

}
Q_EXPORT_PLUGIN2(IPWFTestJigInterface,IPWFWidget);
