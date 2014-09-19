#ifndef APPRXDRVINTERFACE_H
#define APPRXDRVINTERFACE_H
#include <QObject>
#include <QWidget>
class IAPPRXDRVTestJigInterface
{
public:
    virtual void setAPPRXDRV(QWidget*)=0;
    virtual void closeAPPRXDRV()=0;
    virtual void HardwareInitializtaion()=0;
    virtual void showWidget()=0;
};

Q_DECLARE_INTERFACE(IAPPRXDRVTestJigInterface,"pt.APPRXDRVTestJigInterface/1.0.0.1");
#endif // APPRXDRVINTERFACE_H
