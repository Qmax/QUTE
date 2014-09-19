/*
 * IAD9102Widget.h
 *
 *  Created on: 02-Jan-2014
 *      Author: Ravivarman
 */

#ifndef IAD9102WIDGET_H_
#define IAD9102WIDGET_H_
#include "ad9102ui.h"
#include "AD9102TestJigInterface.h"
#include <qobject.h>
#include <QtCore>

class IAD9102Widget:public QObject,public IAD9102TestJigInterface
{
	Q_OBJECT
    Q_INTERFACES(IAD9102TestJigInterface)	//for interface
public:
    void setAD9102(QWidget* parent);
    void closeAD9102();
    void HardwareInitializtaion();
protected:
    AD9102UI* obj;
};

#endif /* IAD9102WIDGET_H_ */
