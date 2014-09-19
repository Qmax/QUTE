#ifndef AWGUIINTERFACE_H
#define AWGUIINTERFACE_H
#include <QObject>
#include <QWidget>
class AWGUIInterface
{
public:
	virtual QWidget* getAWGUIInterface()=0;
};

Q_DECLARE_INTERFACE(AWGUIInterface,"pt.AWGUIInterface/1.0.0.1");
#endif // AWGUIINTERFACE_H
