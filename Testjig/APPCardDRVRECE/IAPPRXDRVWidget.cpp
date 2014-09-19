
#include "IAPPRXDRVWidget.h"

void IAPPRXDRVWidget::setAPPRXDRV(QWidget* parent)
{


	obj=new PtAppCardDrvRecev(parent);
	//obj->show();
}
void IAPPRXDRVWidget::closeAPPRXDRV(){
	//delete obj;
}

void IAPPRXDRVWidget::showWidget()
{
	obj->show();
}
void IAPPRXDRVWidget::HardwareInitializtaion()
{

}
Q_EXPORT_PLUGIN2(IAPPRXDRVTestJigInterface,IAPPRXDRVWidget);
