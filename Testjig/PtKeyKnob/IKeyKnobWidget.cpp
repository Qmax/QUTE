
#include "IKeyKnobWidget.h"

void IKeyKnobWidget::setKeyKnob(QWidget* parent){
	obj=new PtKeyKnob(parent);
	obj->show();
}
void IKeyKnobWidget::closeKeyKnob(){
	delete obj;
}
void IKeyKnobWidget::HardwareInitializtaion()
{

}
Q_EXPORT_PLUGIN2(IKeyKnobTestJigInterface,IKeyKnobWidget);
