/*
 * IGCALIBWidget.h
 *
 *  Created on: 22-June-2013
 *      Author: Ravivarman
 */

#ifndef IGCALIBWIDGET_H_
#define IGCALIBWIDGET_H_
#include "daccalibration.h"
#include "GCALIBTestJigInterface.h"
#include <qobject.h>
#include <QtCore>

class IGCALIBWidget:public QObject,public IGCALIBTestJigInterface
{
	Q_OBJECT
    Q_INTERFACES(IGCALIBTestJigInterface)	//for interface
public:

        QWidget* getGCALIB();

protected:
    DACCalibration* obj;
};

#endif /* IGCALIBWIDGET_H_ */
