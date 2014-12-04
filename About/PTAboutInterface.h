#ifndef ABOUTBOXINTERFACE_H
#define ABOUTBOXINTERFACE_H
#include <QObject>
#include <QtCore>
#include <QWidget>
class IPTAboutBoxInterface
{
public:
        virtual QWidget* getPTAboutBox()=0;
};

Q_DECLARE_INTERFACE(IPTAboutBoxInterface,"pt.PTAboutBoxInterface/1.0.0.1");
#endif // ABOUTBOXINTERFACE_H
