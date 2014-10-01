/*
 * IPTDACFWidget.h
 *
 *  Created on: 30-Sep-2014
 *      Author: Ravivarman
 */

#ifndef IDACFWIDGET_H_
#define IDACFWIDGET_H_
#include "dacfwidget.h"
#include "PTDACFInterface.h"
#include <qobject.h>
#include <QtCore>

class IPTDACFWidget:public QObject,public IPTDACFInterface
{
	Q_OBJECT
    Q_INTERFACES(IPTDACFInterface)	//for interface
public:

        QWidget* getPTDACF();

protected:
        DACFWidget* obj;
};

#endif /* IDACFWIDGET_H_ */
