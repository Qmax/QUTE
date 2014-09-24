/*
 * IPTTestjigWidget.h
 *
 *  Created on: 20-Sep-2014
 *      Author: Ravivarman
 */

#ifndef ITESTJIGWIDGET_H_
#define ITESTJIGWIDGET_H_
#include "portabletestertestjig2.h"
#include "PTTestjigInterface.h"
#include <qobject.h>
#include <QtCore>

class IPTTestjigWidget:public QObject,public IPTTestjigInterface
{
	Q_OBJECT
    Q_INTERFACES(IPTTestjigInterface)	//for interface
public:

        QWidget* getPTTestjig();

protected:
        PortableTesterTestJig2* obj;
};

#endif /* ITESTJIGWIDGET_H_ */
