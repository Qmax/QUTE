
#include "IAD5318Widget.h"

void IAD5318Widget::setAD5318(QWidget* parent){
	obj=new AD5318(parent);
	obj->show();
}
void IAD5318Widget::closeAD5318(){
	delete obj;
}
void IAD5318Widget::HardwareInitializtaion()
{

}
Q_EXPORT_PLUGIN2(IAD5318TestJigInterface,IAD5318Widget);
