/*
 * DMMSPIWidget.h
 *
 *  Created on: 26-May-2014
 *      Author: Ravivarman
 */

#ifndef DMMSPIWIDGET_H_
#define DMMSPIWIDGET_H_
#include "testspi.h"
#include "DMMSPITestJigInterface.h"
#include <qobject.h>
#include <QtCore>

class DMMSPIWidget:public QObject,public DMMSPITestJigInterface
{
	Q_OBJECT
    Q_INTERFACES(DMMSPITestJigInterface)	//for interface
public:

	QWidget* getDMMSPI();

protected:
	testSPI* obj;
};

#endif /* DMMSPIWIDGET_H_ */
