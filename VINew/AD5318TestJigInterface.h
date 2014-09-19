#ifndef AD5318INTERFACE_H
#define AD5318INTERFACE_H
#include <QObject>
#include <QWidget>
class IAD5318TestJigInterface
{
public:
    virtual void setAD5318(QWidget*)=0;
    virtual void closeAD5318()=0;
    virtual void HardwareInitializtaion()=0;
};

Q_DECLARE_INTERFACE(IAD5318TestJigInterface,"pt.AD5318TestJigInterface/1.0.0.1");
#endif // AD5318INTERFACE_H
