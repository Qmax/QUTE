#ifndef DACFINTERFACE_H
#define DACFINTERFACE_H
#include <QObject>
#include <QtCore>
#include <QWidget>
class IPTDACFInterface
{
public:
        virtual QWidget* getPTDACF()=0;
};

Q_DECLARE_INTERFACE(IPTDACFInterface,"pt.PTDACFInterface/1.0.0.1");
#endif // DACFINTERFACE_H
