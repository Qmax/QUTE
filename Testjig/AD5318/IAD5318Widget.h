/*
 * IAD5318Widget.h
 *
 *  Created on: 04-Apr-2013
 *      Author: Ravivarman
 */

#ifndef IAD5318WIDGET_H_
#define IAD5318WIDGET_H_
#include "ad5318.h"
#include "AD5318TestJigInterface.h"
#include <qobject.h>
#include <QtCore>

class IAD5318Widget:public QObject,public IAD5318TestJigInterface
{
	Q_OBJECT
    Q_INTERFACES(IAD5318TestJigInterface)	//for interface
public:
    void setAD5318(QWidget* parent);
    void closeAD5318();
    void HardwareInitializtaion();
protected:
    AD5318* obj;
};

#endif /* IAD5318WIDGET_H_ */
