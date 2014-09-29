/*
 * IPTToolBoxWidget.h
 *
 *  Created on: 19-Sep-2014
 *      Author: Ravivarman
 */

#ifndef IPTFGAPP_H_
#define IPTFGAPP_H_

#include "FGAppInterface.h"
#include "fg.h"
#include <qobject.h>
#include <QtCore>

class IPTFGApp:public QObject,public IPTFGAppInterface
{
	Q_OBJECT
    Q_INTERFACES(IPTFGAppInterface)	//for interface
public:

        QWidget* getFGApp();

protected:
        FG* obj;
};

#endif /* IPTFGAPP_H_ */
