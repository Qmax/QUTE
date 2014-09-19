
#include "IRAMWidget.h"

void IRAMWidget::setRAM(QWidget* parent){
	obj=new Widget(parent);

}
void IRAMWidget::closeRAM(){
	//delete obj;
}
void IRAMWidget::HardwareInitializtaion()
{

}

void IRAMWidget::showWidget()
{
	obj->show();
}
Q_EXPORT_PLUGIN2(IRAMTestJigInterface,IRAMWidget);

