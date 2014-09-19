
#ifndef IFMWIDGET_H_
#define IFMWIDGET_H_
#include "flashMemory.h"
#include "FMTestJigInterface.h"
#include <qobject.h>
#include <QtCore>


class IFMWidget:public QObject,public IFMTestJigInterface
{
	Q_OBJECT
    Q_INTERFACES(IFMTestJigInterface)	//for interface
public:
    void setFM(QWidget* parent);
    void closeFM();
    void HardwareInitializtaion();
protected:
    Widget* obj;
};

#endif /* IFMWIDGET_H_ */
