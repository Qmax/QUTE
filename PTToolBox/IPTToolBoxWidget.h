/*
 * IPTToolBoxWidget.h
 *
 *  Created on: 19-Sep-2014
 *      Author: Ravivarman
 */

#ifndef ITOOLBOXWIDGET_H_
#define ITOOLBOXWIDGET_H_
#include "toolbox.h"
#include "PTToolBoxInterface.h"
#include <qobject.h>
#include <QtCore>

class IPTToolBoxWidget:public QObject,public IPTToolBoxInterface
{
	Q_OBJECT
    Q_INTERFACES(IPTToolBoxInterface)	//for interface
public:

        QWidget* getPTToolBox();

protected:
        ToolBox* obj;
};

#endif /* ITOOLBOXWIDGET_H_ */
