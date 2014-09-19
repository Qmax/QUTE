#ifndef IRAMWIDGET_H_
#define IRAMWIDGET_H_
#include "widget.h"
#include "RAMTestJigInterface.h"
#include <QtCore>
#include <qobject.h>

class IRAMWidget:public QObject,public IRAMTestJigInterface
{
	Q_OBJECT
    Q_INTERFACES(IRAMTestJigInterface)	//for interface
public:
    void setRAM(QWidget* parent);
    void closeRAM();
    void HardwareInitializtaion();
    void showWidget();
protected:
    Widget* obj;
};

#endif /* IRAMWIDGET_H_ */
