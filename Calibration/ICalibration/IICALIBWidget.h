/*
 * IICALIBWidget.h
 *
 *  Created on: 04-Apr-2013
 *      Author: Ravivarman
 */

#ifndef IICALIBWIDGET_H_
#define IICALIBWIDGET_H_
#include "daccalibration.h"
#include "ICALIBTestJigInterface.h"
#include <qobject.h>
#include <QtCore>

class IICALIBWidget:public QObject,public IICALIBTestJigInterface
{
	Q_OBJECT
    Q_INTERFACES(IICALIBTestJigInterface)	//for interface
public:

	QWidget* getIICALIB();

protected:
    DACCalibration* obj;
};

#endif /* IICALIBWIDGET_H_ */
