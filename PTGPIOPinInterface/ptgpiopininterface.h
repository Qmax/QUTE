#ifndef PTGPIOPININTERFACE_H
#define PTGPIOPININTERFACE_H


#include <qdebug.h>
#include <qpluginloader.h>
#include <QObject>
#include <QtCore>

#include "GPIOInterfaces.h"
#include "gpio.h"

class PTGPIOPinInterface:public QObject,public InterfaceGPIOPins
{
    Q_OBJECT
    Q_INTERFACES(InterfaceGPIOPins)
public:
    PTGPIOPinInterface();
    ~PTGPIOPinInterface();

    int touch_value;

    int toggleTouchButton();
    int illuminateScaleButton(int val);
    int illuminateRunStopButton(int val);
    int killSystem();
};

#endif // PTGPIOPININTERFACE_H

Q_DECLARE_INTERFACE(PTGPIOPinInterface,"pt.gpiopinInterface/1.0.0.1");
