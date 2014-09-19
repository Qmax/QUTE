
#include "IICMWidget.h"

void IICMWidget::setICM(QWidget* parent){
	obj=new Widget(parent);
	//obj->show();
}
void IICMWidget::closeICM(){
	//delete obj;
}
void IICMWidget::HardwareInitializtaion()
{

}
void IICMWidget::showWidget()
{
	obj->show();
}
Q_EXPORT_PLUGIN2(IICMTestJigInterface,IICMWidget);
