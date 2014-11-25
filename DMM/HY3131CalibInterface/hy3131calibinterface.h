#ifndef HY3131CALIBINTERFACE_H
#define HY3131CALIBINTERFACE_H

#include <QtCore>
#include <QObject>
#include "HY3131Calib.h"
#include "hy3131calibration.h"


class HY3131CALIBINTERFACE : public QObject, IHY3131CalibInterface{
    Q_OBJECT
    Q_INTERFACES(IHY3131CalibInterface)
public:
   QWidget* getCALIB();
protected:
    HY3131Calibration *obj;
};

#endif // HY3131CALIBINTERFACE_H
