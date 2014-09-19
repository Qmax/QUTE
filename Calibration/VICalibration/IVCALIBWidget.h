/*
 * IVCALIBWidget.h
 *
 *  Created on: 04-Apr-2013
 *      Author: Ravivarman
 */

#ifndef IVCALIBWIDGET_H_
#define IVCALIBWIDGET_H_
#include "daccalibration.h"
#include "VCALIBTestJigInterface.h"
#include <qobject.h>
#include <QtCore>

class IVCALIBWidget:public QObject,public IVCALIBTestJigInterface
{
	Q_OBJECT
    Q_INTERFACES(IVCALIBTestJigInterface)	//for interface
public:

	QWidget* getVICALIB();

protected:
    DACCalibration* obj;
};

#endif /* IVCALIBWIDGET_H_ */
