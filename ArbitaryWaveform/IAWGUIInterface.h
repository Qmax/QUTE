/*
 *
 *  Created on: 29-July-2013
 *      Author: Ravivarman
 */

#ifndef IAWGUIINTERFACE_H_
#define IAWGUIINTERFACE_H_
#include "arbitary.h"
#include "AWGUIInterface.h"
#include <qobject.h>
#include <QtCore>

class IAWGGUIInterface:public QObject,public AWGUIInterface
{
	Q_OBJECT
    Q_INTERFACES(AWGUIInterface)	//for interface
public:

	QWidget* getAWGUIInterface();

protected:
    Arbitary* obj;
};

#endif /* IAWGUIINTERFACE_H_ */
