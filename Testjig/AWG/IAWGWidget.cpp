
#include "IAWGWidget.h"

void IAWGWidget::setAWG(QWidget* parent){
	obj=new Widget(parent);
	obj->show();
}
void IAWGWidget::closeAWG(){
	delete obj;
}
void IAWGWidget::HardwareInitializtaion()
{

}
Q_EXPORT_PLUGIN2(IAWGTestJigInterface,IAWGWidget);
