#ifndef IPSOCWIDGET_H_
#define IPSOCWIDGET_H_
#include "ptpsoctestjiginterface2.h"
#include "PSoCTestJigInterface2.h"
#include <qobject.h>

class IPSOCWidget:public QObject,public IPSOCTestJigInterface2
{
	Q_OBJECT
    Q_INTERFACES(IPSOCTestJigInterface2)	//for interface
public:
    void setPSOC(QWidget* parent);
    void closePSOC();
    void HardwareInitializtaion();
protected:
    PTPSoCTestJigInterface2* obj;
};

#endif /* IPSOCWIDGET_H_ */
