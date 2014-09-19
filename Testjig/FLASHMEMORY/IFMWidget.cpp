
#include "IFMWidget.h"

void IFMWidget::setFM(QWidget* parent){
	obj=new Widget(parent);
	obj->show();
}
void IFMWidget::closeFM(){
	delete obj;
}
void IFMWidget::HardwareInitializtaion()
{

}
Q_EXPORT_PLUGIN2(IFMTestJigInterface,IFMWidget);
