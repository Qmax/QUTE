
#include "IDMMWidget.h"

void IDMMWidget::setDMM(QWidget* parent){
	obj=new DMMJig(parent);
	obj->show();
}
void IDMMWidget::closeDMM(){
	delete obj;
}
void IDMMWidget::HardwareInitializtaion()
{

}
Q_EXPORT_PLUGIN2(IDMMTestJigInterface,IDMMWidget);
