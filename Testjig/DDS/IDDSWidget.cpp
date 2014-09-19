
#include "IDDSWidget.h"

void IDDSWidget::setDDS(QWidget* parent){
	obj=new DDSWidget(parent);

}
void IDDSWidget::closeDDS(){
	//delete obj;
}
void IDDSWidget::HardwareInitializtaion()
{

}

void IDDSWidget::showWidget()
{
	obj->show();
}
Q_EXPORT_PLUGIN2(IDDSTestJigInterface,IDDSWidget);

