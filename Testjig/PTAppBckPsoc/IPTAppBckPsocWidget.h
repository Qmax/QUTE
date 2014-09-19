/*
 * IPTAppBckPsocWidget.h
 *
 *  Created on: 9-July-2013
 *      Author: Ravivarman
 */

#ifndef IRXCALIBWIDGET_H_
#define IRXCALIBWIDGET_H_
#include "ptpsoctestjiginterface.h"
#include "PTAppBckPsocInterface.h"
#include <qobject.h>
#include <QtCore>

class IPTAppBckPsocWidget:public QObject,public IPTAppBckPsocInterface
{
	Q_OBJECT
    Q_INTERFACES(IPTAppBckPsocInterface)	//for interface
public:

	QWidget* getPTAppBckPsoc();

protected:
	PTPSoCTestJigInterface* obj;
};

#endif /* IRXCALIBWIDGET_H_ */
