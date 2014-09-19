/*
 * IAPPRXDRVWidget.h
 *
 *  Created on: 28-May-2013
 *      Author: Ravivarman
 */

#ifndef IAPPRXDRVWIDGET_H_
#define IAPPRXDRVWIDGET_H_
#include "ptappcarddrvrecev.h"
#include "APPRXDRVTestJigInterface.h"
#include <qobject.h>
#include <QtCore>

class IAPPRXDRVWidget:public QObject,public IAPPRXDRVTestJigInterface
{
	Q_OBJECT
    Q_INTERFACES(IAPPRXDRVTestJigInterface)	//for interface
public:
    void setAPPRXDRV(QWidget* parent);
    void showWidget();
    void closeAPPRXDRV();
    void HardwareInitializtaion();
protected:
    PtAppCardDrvRecev* obj;
};

#endif /* IAPPRXDRVWIDGET_H_ */
