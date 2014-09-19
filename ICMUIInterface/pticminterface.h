/*
 *      Author: Ravivarman.R,Qmax
 */
#ifndef PTICMINTERFACE_H
#define PTICMINTERFACE_H

#include <QObject>

#include"interfaceHeader.h"
#include"icm.h"

class PTICMInterface : public QObject,public IPTICMInterface
{
Q_OBJECT
Q_INTERFACES(IPTICMInterface)
public:
    explicit PTICMInterface(QObject *parent = 0);
    QWidget* getPTWidget();
    unsigned int getGUID();
protected:
    ICM *m_objICMWidget;
signals:

public slots:

};

#endif // PTICMINTERFACE_H
