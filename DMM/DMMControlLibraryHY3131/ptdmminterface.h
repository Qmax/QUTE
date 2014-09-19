#ifndef PTDMMINTERFACE_H
#define PTDMMINTERFACE_H

#include <QObject>
#include"interfaceHeader.h"
#include"dmm.h"




class PTDMMInterface:public QObject,public IPTDMMInterface
{
    Q_OBJECT
    Q_INTERFACES(IPTDMMInterface)

public:
    PTDMMInterface(QObject *parent = 0);
    QWidget* getPTWidget();
    unsigned int getGUID();
protected:
    DMM *m_objDMMWidget;

};
#endif // PTDMMINTERFACE_H
