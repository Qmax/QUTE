#include "ptfginterface.h"
#include "fg.h"

PTFGInterface::PTFGInterface(QObject *parent):QObject(parent)
{
//   m_objFGWidget = new FGWindow;
}

QWidget* PTFGInterface::getPTWidget()
{
    return new FG;
}

unsigned int PTFGInterface::getGUID()
{
    return m_objFGWidget->getFGID();
}
Q_EXPORT_PLUGIN2(PTFGInterface, PTFGInterface)
