/*
 * IPTAboutBoxWidget.h
 *
 *  Created on: 03-Dec-2014
 *      Author: Ravivarman
 */

#ifndef IABOUTBOXWIDGET_H_
#define IABOUTBOXWIDGET_H_
#include "about.h"
#include "PTAboutInterface.h"
#include <qobject.h>
#include <QtCore>

class IPTAboutBoxWidget:public QObject,public IPTAboutBoxInterface
{
	Q_OBJECT
    Q_INTERFACES(IPTAboutBoxInterface)	//for interface
public:

        QWidget* getPTAboutBox();

protected:
        About* obj;
};

#endif /* IABOUTBOXWIDGET_H_ */
