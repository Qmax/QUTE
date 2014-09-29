
#include "IPTFGApp.h"

QWidget* IPTFGApp::getFGApp(){
        obj=new FG;
	return obj;
}
Q_EXPORT_PLUGIN2(IPTFGAppInterface,IPTFGApp);
