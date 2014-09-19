#ifndef DMMINTERFACE_H
#define DMMINTERFACE_H
#include <QObject>
#include <QWidget>
class IDMMTestJigInterface
{
public:
    virtual void setDMM(QWidget* parent)=0;
    virtual void closeDMM()=0;
    virtual void HardwareInitializtaion()=0;
};

Q_DECLARE_INTERFACE(IDMMTestJigInterface,"pt.DMMTestJigInterface/1.0.0.1");
#endif // DMMINTERFACE_H
