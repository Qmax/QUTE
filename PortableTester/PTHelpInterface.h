#ifndef HELPBOXINTERFACE_H
#define HELPBOXINTERFACE_H
#include <QObject>
#include <QtCore>
#include <QWidget>
class IPTHelpBoxInterface
{
public:
        virtual QWidget* getPTHelpBox()=0;
};

Q_DECLARE_INTERFACE(IPTHelpBoxInterface,"pt.PTHelpBoxInterface/1.0.0.1");
#endif // HELPBOXINTERFACE_H
