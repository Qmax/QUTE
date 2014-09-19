#ifndef IHWIDINTERFACE_H
#define IHWIDINTERFACE_H
#include <QString>
class IHWIDInterface{
public:
  virtual  void HwIDInterface(QString)=0;
};
Q_DECLARE_INTERFACE(IHWIDInterface,"pt.hwidInterface/1.0.0.1");
#endif // IHWIDINTERFACE_H
