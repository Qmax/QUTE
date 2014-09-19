
#include "IAWGUIInterface.h"

QWidget* IAWGGUIInterface::getAWGUIInterface(){
	obj=new Arbitary;
	return obj;
}
Q_EXPORT_PLUGIN2(AWGUIInterface,IAWGGUIInterface);
