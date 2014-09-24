#ifndef TOOLBOXINTERFACE_H
#define TOOLBOXINTERFACE_H
#include <QObject>
#include <QtCore>
#include <QWidget>
class IPTToolBoxInterface
{
public:
        virtual QWidget* getPTToolBox()=0;
};

Q_DECLARE_INTERFACE(IPTToolBoxInterface,"pt.PTToolBoxInterface/1.0.0.1");
#endif // TOOLBOXINTERFACE_H
