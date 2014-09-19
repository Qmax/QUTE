
#ifndef IVIWIDGET_H_
#define IVIWIDGET_H_
#include "vijig.h"
#include "VITestJigInterface.h"
#include <qobject.h>

class IVIWidget:public QObject,public IVITestJigInterface
{
	Q_OBJECT
    Q_INTERFACES(IVITestJigInterface)	//for interface
public:
    void setVI(QWidget* parent);
    void closeVI();
    void HardwareInitializtaion();
protected:
    VIJig* obj;
};

#endif /* IVIWIDGET_H_ */
