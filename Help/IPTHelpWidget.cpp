
#include "IPTHelpWidget.h"

QWidget* IPTHelpBoxWidget::getPTHelpBox(){
        obj=new MainWindow;
	return obj;
}
Q_EXPORT_PLUGIN2(IPTHelpBoxInterface,IPTHelpBoxWidget);
