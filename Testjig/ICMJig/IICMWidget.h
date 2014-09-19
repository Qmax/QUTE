
#ifndef ICMWIDGET_H_
#define ICMWIDGET_H_
#include "widget.h"
#include "ICMTestJigInterface.h"
#include <qobject.h>

class IICMWidget:public QObject,public IICMTestJigInterface
{
	Q_OBJECT
    Q_INTERFACES(IICMTestJigInterface)	//for interface
public:
    void setICM(QWidget* parent);
    void closeICM();
    void HardwareInitializtaion();
    void showWidget();
protected:
    Widget* obj;
};

#endif
