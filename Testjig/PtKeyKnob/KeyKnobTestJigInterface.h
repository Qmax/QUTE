#ifndef KeyKnobINTERFACE_H
#define KeyKnobINTERFACE_H
#include <QObject>
#include <QWidget>
class IKeyKnobTestJigInterface
{
public:
    virtual void setKeyKnob(QWidget*)=0;
    virtual void closeKeyKnob()=0;
    virtual void HardwareInitializtaion()=0;
};

Q_DECLARE_INTERFACE(IKeyKnobTestJigInterface,"pt.KeyKnobTestJigInterface/1.0.0.1");
#endif // KeyKnobINTERFACE_H
