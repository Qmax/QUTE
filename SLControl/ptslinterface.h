#ifndef PTSLINTERFACE_H
#define PTSLINTERFACE_H

#include <QObject>
#include"interfaceHeader.h"
#include"shortlocater.h"




class PTSLInterface:public QObject,public IPTSLInterface
{
    Q_OBJECT
    Q_INTERFACES(IPTSLInterface)

public:
    PTSLInterface(QObject *parent = 0);
    QWidget* getPTWidget();
    unsigned int getGUID();
protected:
    ShortLocater *m_objSLWidget;

};
#endif // PTSLINTERFACE_H
