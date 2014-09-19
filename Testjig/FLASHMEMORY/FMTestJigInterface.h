#ifndef FMINTERFACE_H
#define FMINTERFACE_H
#include <QObject>
#include <QWidget>
class IFMTestJigInterface
{
public:
    virtual void setFM(QWidget*)=0;
    virtual void closeFM()=0;
    virtual void HardwareInitializtaion()=0;
};

Q_DECLARE_INTERFACE(IFMTestJigInterface,"pt.FMTestJigInterface/1.0.0.1");
#endif // FMINTERFACE_H
