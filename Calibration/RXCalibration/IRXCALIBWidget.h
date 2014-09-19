/*
 * IRXCALIBWidget.h
 *
 *  Created on: 04-Apr-2013
 *      Author: Ravivarman
 */

#ifndef IRXCALIBWIDGET_H_
#define IRXCALIBWIDGET_H_
#include "adccalibration.h"
#include "RXCALIBTestJigInterface.h"
#include <qobject.h>
#include <QtCore>

class IRXCALIBWidget:public QObject,public IRXCALIBTestJigInterface
{
	Q_OBJECT
    Q_INTERFACES(IRXCALIBTestJigInterface)	//for interface
public:

	QWidget* getRXCALIB();

protected:
    DACCalibration* obj;
};

#endif /* IRXCALIBWIDGET_H_ */
