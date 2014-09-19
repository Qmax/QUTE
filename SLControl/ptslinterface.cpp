#include "ptslinterface.h"
#include "shortlocater.h"

PTSLInterface::PTSLInterface(QObject *parent):QObject(parent)
{
//   m_objSLWidget = new ShortLocater;
}

QWidget* PTSLInterface::getPTWidget()
{
    return new ShortLocater;;
}

unsigned int PTSLInterface::getGUID()
{
    return m_objSLWidget->getSLID();
}
Q_EXPORT_PLUGIN2(PTSLInterface, PTSLInterface)
