/*
 * IPTHelpBoxWidget.h
 *
 *  Created on: 03-Dec-2014
 *      Author: Ravivarman
 */

#ifndef IHELPBOXWIDGET_H_
#define IHELPBOXWIDGET_H_
#include "mainwindow.h"
#include "PTHelpInterface.h"
#include <qobject.h>
#include <QtCore>

class IPTHelpBoxWidget:public QObject,public IPTHelpBoxInterface
{
	Q_OBJECT
    Q_INTERFACES(IPTHelpBoxInterface)	//for interface
public:

        QWidget* getPTHelpBox();

protected:
        MainWindow* obj;
};

#endif /* IHELPBOXWIDGET_H_ */
