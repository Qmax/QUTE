
#include "IPTAboutWidget.h"

QWidget* IPTAboutBoxWidget::getPTAboutBox(){
        obj=new About;
	return obj;
}
Q_EXPORT_PLUGIN2(IPTAboutBoxInterface,IPTAboutBoxWidget);
