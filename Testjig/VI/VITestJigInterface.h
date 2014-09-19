#ifndef VIINTERFACE_H
#define VIINTERFACE_H
#include <QObject>
#include <QWidget>
class IVITestJigInterface
{
public:
    virtual void setVI(QWidget* parent)=0;
    virtual void closeVI()=0;
    virtual void HardwareInitializtaion()=0;
};

Q_DECLARE_INTERFACE(IVITestJigInterface,"pt.VITestJigInterface/1.0.0.1");
#endif // VIINTERFACE_H
