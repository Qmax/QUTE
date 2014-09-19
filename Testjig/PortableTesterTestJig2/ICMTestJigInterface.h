#ifndef ICMINTERFACE_H
#define ICMINTERFACE_H
#include <QObject>
#include <QWidget>
class IICMTestJigInterface
{
public:
    virtual void setICM(QWidget* parent)=0;
    virtual void closeICM()=0;
    virtual void HardwareInitializtaion()=0;
    virtual void showWidget()=0;
};

Q_DECLARE_INTERFACE(IICMTestJigInterface,"pt.ICMTestJigInterface/1.0.0.1");
#endif // ICMINTERFACE_H
