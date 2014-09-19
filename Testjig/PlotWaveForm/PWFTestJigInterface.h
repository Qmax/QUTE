#ifndef PWFINTERFACE_H
#define PWFINTERFACE_H
#include <QObject>
#include <QWidget>
class IPWFTestJigInterface
{
public:
    virtual void setPWF(QWidget*)=0;
    virtual void closePWF()=0;
    virtual void HardwareInitializtaion()=0;
};

Q_DECLARE_INTERFACE(IPWFTestJigInterface,"pt.PWFTestJigInterface/1.0.0.1");
#endif // PWFINTERFACE_H
