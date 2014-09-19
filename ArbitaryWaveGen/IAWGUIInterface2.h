/*
 *
 *  Created on: 8-Aug-2014
 *      Author: Ravivarman
 */

#ifndef IAWGUIINTERFACE2_H_
#define IAWGUIINTERFACE2_H_
#include "mainwindow.h"
#include "AWGUIInterface2.h"
#include <qobject.h>
#include <QtCore>

class IAWGGUIInterface2:public QObject,public AWGUIInterface2
{
	Q_OBJECT
    Q_INTERFACES(AWGUIInterface2)	//for interface
public:

	QWidget* getAWGUIInterface2();

protected:
    MainWindow* obj;
};

#endif /* IAWGUIINTERFACE2_H_ */
