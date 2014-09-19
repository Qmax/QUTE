#ifndef DDSINTERFACE_H
#define DDSINTERFACE_H
#include <QObject>
#include <QWidget>
class IDDSTestJigInterface
{
public:
    virtual void setDDS(QWidget*)=0;
    virtual void closeDDS()=0;
    virtual void HardwareInitializtaion()=0;
    virtual void showWidget()=0;
};

Q_DECLARE_INTERFACE(IDDSTestJigInterface,"pt.DDSTestJigInterface/1.0.0.1");
#endif // DDSINTERFACE_H
