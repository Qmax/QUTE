/*
 * IACRWidget.cpp
 *
 *  Created on: 04-Apr-2013
 *      Author: elangovan
 */
//--------------------------

#include "IACRWidget.h"

void IACRWidget::setACR(QWidget* parent){
	obj=new AppCardRelayRead(parent);
	obj->show();
}
void IACRWidget::closeACR(){
	delete obj;
}
void IACRWidget::HardwareInitializtaion()
{

}
Q_EXPORT_PLUGIN2(IACRTestJigInterface,IACRWidget);
