/*
 * IACRWidget.h
 *
 *  Created on: 04-Apr-2013
 *      Author: elangovan
 */

#ifndef IACRWIDGET_H_
#define IACRWIDGET_H_
#include "appcardrelayread.h"
#include "ACRTestJigInterface.h"
#include <qobject.h>
#include <QtCore>


class IACRWidget:public QObject,public IACRTestJigInterface
{
	Q_OBJECT
    Q_INTERFACES(IACRTestJigInterface)	//for interface
public:
    void setACR(QWidget* parent);
    void closeACR();
    void HardwareInitializtaion();
protected:
    AppCardRelayRead* obj;
};

#endif /* IACRWIDGET_H_ */
