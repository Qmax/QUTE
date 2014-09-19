/*
 * IPWFWidget.h
 *
 *  Created on: 27-May-2013
 *      Author: Ravivarman
 */

#ifndef IPWFWIDGET_H_
#define IPWFWIDGET_H_
#include "widget.h"
#include "PWFTestJigInterface.h"
#include <qobject.h>
#include <QtCore>

class IPWFWidget:public QObject,public IPWFTestJigInterface
{
	Q_OBJECT
    Q_INTERFACES(IPWFTestJigInterface)	//for interface
public:
    void setPWF(QWidget* parent);
    void closePWF();
    void HardwareInitializtaion();
protected:
    Widget* obj;
};

#endif /* IPWFWIDGET_H_ */
