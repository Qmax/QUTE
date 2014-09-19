
#include "IHACADCWidget.h"

void IHACADCWidget::setHACADC(QWidget* parent){
	obj=new ADHighAccuracy(parent);

}
void IHACADCWidget::closeHACADC(){
	//delete obj;
}
void IHACADCWidget::HardwareInitializtaion()
{

}
void IHACADCWidget::showWidget()
{
	obj->loadSPIBIT();
	obj->show();

}
Q_EXPORT_PLUGIN2(IHACADCTestJigInterface,IHACADCWidget);
