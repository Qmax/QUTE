/*
 * IKeyKnobWidget.h
 *
 *  Created on: 04-Apr-2013
 *      Author: Ravivarman
 */

#ifndef IKeyKnobWIDGET_H_
#define IKeyKnobWIDGET_H_
#include "ptkeyknob.h"
#include "KeyKnobTestJigInterface.h"
#include <qobject.h>

class IKeyKnobWidget:public QObject,public IKeyKnobTestJigInterface
{
	Q_OBJECT
    Q_INTERFACES(IKeyKnobTestJigInterface)	//for interface
public:
    void setKeyKnob(QWidget* parent);
    void closeKeyKnob();
    void HardwareInitializtaion();
protected:
    PtKeyKnob* obj;
};

#endif /* IKeyKnobWIDGET_H_ */
