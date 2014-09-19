
#include "IAD9102Widget.h"

void IAD9102Widget::setAD9102(QWidget* parent){
	obj=new AD9102UI(parent);
	obj->show();
}
void IAD9102Widget::closeAD9102(){
	delete obj;
}
void IAD9102Widget::HardwareInitializtaion()
{

}
Q_EXPORT_PLUGIN2(IAD9102TestJigInterface,IAD9102Widget);
