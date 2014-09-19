/*
 *
 *  Created on: 8-Aug-2014
 *      Author: Ravivarman
 */

#ifndef AWGUIINTERFACE2_H
#define AWGUIINTERFACE2_H
#include <QObject>
#include <QWidget>
class AWGUIInterface2
{
public:
	virtual QWidget* getAWGUIInterface2()=0;
};

Q_DECLARE_INTERFACE(AWGUIInterface2,"pt.AWGUIInterface2/1.0.0.1");
#endif // AWGUIINTERFACE2_H
