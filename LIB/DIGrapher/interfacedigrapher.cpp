// -------------------------------------------------
// Project created by Ravivarman.R 2014-09-09T14:08:47
// -------------------------------------------------
#include "interfacedigrapher.h"

QWidget* InterfaceDIGrapher::getDIGraph(){
        obj=new DIGrapher;
        return obj;
}
Q_EXPORT_PLUGIN2(DIGrapherInterface,InterfaceDIGrapher);
