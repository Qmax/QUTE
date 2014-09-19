/*
 * IHACADCWidget.h
 *
 *  Created on: 28-May-2013
 *      Author: Ravivarman
 */

#ifndef IHACADCWIDGET_H_
#define IHACADCWIDGET_H_
#include "adhighaccuracy.h"
#include "HACADCTestJigInterface.h"
#include <qobject.h>
#include <QtCore>

class IHACADCWidget:public QObject,public IHACADCTestJigInterface
{
	Q_OBJECT
    Q_INTERFACES(IHACADCTestJigInterface)	//for interface
public:
    void setHACADC(QWidget* parent);
    void closeHACADC();
    void HardwareInitializtaion();
    void showWidget();
protected:
    ADHighAccuracy* obj;
};

#endif /* IHACADCWIDGET_H_ */
