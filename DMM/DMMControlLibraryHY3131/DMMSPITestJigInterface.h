#ifndef DMMSPIINTERFACE_H
#define DMMSPIINTERFACE_H
#include <QObject>
#include <QWidget>
class DMMSPITestJigInterface
{
public:
	virtual QWidget* getDMMSPI()=0;
};

Q_DECLARE_INTERFACE(DMMSPITestJigInterface,"pt.DMMSPITestJigInterface/1.0.0.1");
#endif // DMMSPIINTERFACE_H
