
#include "IPTToolBoxWidget.h"

QWidget* IPTToolBoxWidget::getPTToolBox(){
        obj=new ToolBox;
	return obj;
}
Q_EXPORT_PLUGIN2(IPTToolBoxTestJigInterface,IPTToolBoxWidget);
