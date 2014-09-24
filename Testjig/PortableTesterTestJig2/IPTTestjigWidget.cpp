
#include "IPTTestjigWidget.h"

QWidget* IPTTestjigWidget::getPTTestjig(){
        obj=new PortableTesterTestJig2;
	return obj;
}
Q_EXPORT_PLUGIN2(IPTTestjigInterface,IPTTestjigWidget);
