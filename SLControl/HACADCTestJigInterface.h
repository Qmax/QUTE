#ifndef HACADCINTERFACE_H
#define HACADCINTERFACE_H
#include <QObject>
#include <QWidget>
class IHACADCTestJigInterface
{
public:
    virtual void setHACADC(QWidget*)=0;
    virtual void closeHACADC()=0;
    virtual void HardwareInitializtaion()=0;
    virtual void showWidget()=0;
};

Q_DECLARE_INTERFACE(IHACADCTestJigInterface,"pt.HACADCTestJigInterface/1.0.0.1");
#endif // HACADCINTERFACE_H
