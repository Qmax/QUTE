/*
 *      Author: Ravivarman.R,Qmax
 */
#include "pticminterface.h"

PTICMInterface::PTICMInterface(QObject *parent) : QObject(parent)
{
    qDebug()<< "Inside PTICM Interfaces";
}

QWidget* PTICMInterface::getPTWidget()
{
    return new ICM;
}

unsigned int PTICMInterface::getGUID()
{
    return m_objICMWidget->getICMID();
}
Q_EXPORT_PLUGIN2(PTICMInterface, PTICMInterface)

