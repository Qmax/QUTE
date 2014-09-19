/*
 * IAWGWidget.h
 *
 *  Created on: 04-Apr-2013
 *      Author: Ravivarman
 */

#ifndef IAWGWIDGET_H_
#define IAWGWIDGET_H_
#include "widget.h"
#include "AWGTestJigInterface.h"
#include <qobject.h>

class IAWGWidget:public QObject,public IAWGTestJigInterface
{
	Q_OBJECT
    Q_INTERFACES(IAWGTestJigInterface)	//for interface
public:
    void setAWG(QWidget* parent);
    void closeAWG();
    void HardwareInitializtaion();
protected:
    Widget* obj;
};

#endif /* IAWGWIDGET_H_ */
