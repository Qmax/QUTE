#include "ptdmminterface.h"
#include "dmm.h"

PTDMMInterface::PTDMMInterface(QObject *parent):QObject(parent)
{
//   qDebug()<< "Inside PTDMM Interfaces";
//   m_objDMMWidget = new DMM;
}

QWidget* PTDMMInterface::getPTWidget()
{
    return new DMM;
}

unsigned int PTDMMInterface::getGUID()
{
    return m_objDMMWidget->getDMMID();
}
Q_EXPORT_PLUGIN2(PTDMMInterface, PTDMMInterface)
