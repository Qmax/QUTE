/*
 *      Author: Ravivarman.R,Qmax
 */
#include <QObject>
#include <QtCore>
#include <QWidget>
class IPTAppBckPsocInterface
{
public:
	virtual QWidget* getPTAppBckPsoc()=0;
};

Q_DECLARE_INTERFACE(IPTAppBckPsocInterface,"pt.PTAppBckPsocInterface/1.0.0.1");
