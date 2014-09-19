
#ifndef IDMMWIDGET_H_
#define IDMMWIDGET_H_
#include "dmmjig.h"
#include "DMMTestJigInterface.h"
#include <qobject.h>

class IDMMWidget:public QObject,public IDMMTestJigInterface
{
	Q_OBJECT
    Q_INTERFACES(IDMMTestJigInterface)	//for interface
public:
    void setDMM(QWidget* parent);
    void closeDMM();
    void HardwareInitializtaion();
protected:
    DMMJig* obj;
};

#endif
