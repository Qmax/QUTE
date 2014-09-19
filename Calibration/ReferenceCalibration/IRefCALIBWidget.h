/*
 * IRefCALIBWidget.h
 *
 *  Created on: 03-June-2013
 *      Author: Ravivarman
 */

#ifndef IRefCALIBWIDGET_H_
#define IRefCALIBWIDGET_H_
#include "daccalibration.h"
#include "RefCALIBTestJigInterface.h"
#include <qobject.h>
#include <QtCore>

class IRefCALIBWidget:public QObject,public IRefCALIBTestJigInterface
{
	Q_OBJECT
    Q_INTERFACES(IRefCALIBTestJigInterface)	//for interface
public:

	QWidget* getRefCALIB();

protected:
    DACCalibration* obj;
};

#endif /* IRefCALIBWIDGET_H_ */
