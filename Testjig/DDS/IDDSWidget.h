/*
 * IDDSWidget.h
 *
 *  Created on: 17-May-2013
 *      Author: Ravivarman
 */

#ifndef IDDSWIDGET_H_
#define IDDSWIDGET_H_
#include "ddswidget.h"
#include "DDSTestJigInterface.h"
#include <qobject.h>

class IDDSWidget:public QObject,public IDDSTestJigInterface
{
	Q_OBJECT
    Q_INTERFACES(IDDSTestJigInterface)	//for interface
public:
    void setDDS(QWidget* parent);
    void closeDDS();
    void HardwareInitializtaion();
    void showWidget();
protected:
    DDSWidget* obj;
};

#endif /* IDDSWIDGET_H_ */
