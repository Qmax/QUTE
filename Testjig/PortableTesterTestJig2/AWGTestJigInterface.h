#ifndef AWGINTERFACE_H
#define AWGINTERFACE_H
#include <QObject>
#include <QWidget>
class IAWGTestJigInterface
{
public:
    virtual void setAWG(QWidget*)=0;
    virtual void closeAWG()=0;
    virtual void HardwareInitializtaion()=0;
};

Q_DECLARE_INTERFACE(IAWGTestJigInterface,"pt.AWGTestJigInterface/1.0.0.1");
#endif // AWGINTERFACE_H
