#ifndef RLCINTERFACE_H
#define RLCINTERFACE_H

#include<QObject>


class RLCInterface{
public:
    virtual double getCapacitance()=0;
    virtual double getResistance()=0;
    virtual double getInductance()=0;
    virtual void stopMeasurement()=0;
};

Q_DECLARE_INTERFACE(RLCInterface,"pt.RLCInterface/1.0.0.1");

#endif // RLCINTERFACE_H
