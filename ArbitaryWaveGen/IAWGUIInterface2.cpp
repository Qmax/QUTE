/*
 *
 *  Created on: 8-Aug-2014
 *      Author: Ravivarman
 */

#include "IAWGUIInterface2.h"

QWidget* IAWGGUIInterface2::getAWGUIInterface2(){
	obj=new MainWindow;
	return obj;
}
Q_EXPORT_PLUGIN2(AWGUIInterface2,IAWGGUIInterface2);
