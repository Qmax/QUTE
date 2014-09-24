#ifndef TESTJIGINTERFACE_H
#define TESTJIGINTERFACE_H
#include <QObject>
#include <QtCore>
#include <QWidget>
class IPTTestjigInterface
{
public:
        virtual QWidget* getPTTestjig()=0;
};

Q_DECLARE_INTERFACE(IPTTestjigInterface,"pt.PTTestjigInterface/1.0.0.1");
#endif // TESTJIGINTERFACE_H
