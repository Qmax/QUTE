#ifndef ICALIBINTERFACE_H
#define ICALIBINTERFACE_H
#include <QObject>
#include <QWidget>
class IICALIBTestJigInterface
{
public:
	virtual QWidget* getIICALIB()=0;
};

Q_DECLARE_INTERFACE(IICALIBTestJigInterface,"pt.ICALIBTestJigInterface/1.0.0.1");
#endif // ICALIBINTERFACE_H
