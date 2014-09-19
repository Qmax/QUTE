#ifndef ACRINTERFACE_H
#define ACRINTERFACE_H
#include <QObject>
#include <QWidget>
#include <QtCore>

class IACRTestJigInterface
{
public:
    virtual void setACR(QWidget*)=0;
    virtual void closeACR()=0;
    virtual void HardwareInitializtaion()=0;
};

Q_DECLARE_INTERFACE(IACRTestJigInterface,"pt.ACRTestJigInterface/1.0.0.1");
#endif // ACRINTERFACE_H
