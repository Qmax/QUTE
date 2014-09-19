#include "IVIWidget.h"

void IVIWidget::setVI(QWidget* parent){
	obj=new VIJig(parent);
	obj->show();
}
void IVIWidget::closeVI(){
	delete obj;
}
void IVIWidget::HardwareInitializtaion()
{

}
Q_EXPORT_PLUGIN2(IVITestJigInterface,IVIWidget);
