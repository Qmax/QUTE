#ifndef AD9102INTERFACE_H
#define AD9102INTERFACE_H
#include <QObject>
#include <QWidget>
class IAD9102TestJigInterface
{
public:
    virtual void setAD9102(QWidget*)=0;
    virtual void closeAD9102()=0;
    virtual void HardwareInitializtaion()=0;
};

Q_DECLARE_INTERFACE(IAD9102TestJigInterface,"pt.AD9102TestJigInterface/1.0.0.1");
#endif // AD9102INTERFACE_H
