#ifndef RAMINTERFACE_H
#define RAMINTERFACE_H
#include <QObject>
#include <QWidget>
class IRAMTestJigInterface
{
public:
    virtual void setRAM(QWidget*)=0;
    virtual void closeRAM()=0;
    virtual void HardwareInitializtaion()=0;
    virtual void showWidget()=0;
};

Q_DECLARE_INTERFACE(IRAMTestJigInterface,"pt.RAMTestJigInterface/1.0.0.1");
#endif // RAMINTERFACE_H
