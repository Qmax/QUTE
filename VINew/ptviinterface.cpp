#include "ptviinterface.h"

PTVIInterface::PTVIInterface(QObject *parent):QObject(parent)
{
//   m_objVIWidget = new VIMainWindow;
	qDebug()<<"inside PT VI Interface header";
}

QWidget* PTVIInterface::getPTWidget()
{
	qDebug()<<"Inside getPTWidget VI";

    return new MainWindow;//m_objVIWidget;
}

unsigned int PTVIInterface::getGUID()
{
	qDebug()<<"Inside getGUID VI";
    return m_objVIWidget->getVIID();
}
Q_EXPORT_PLUGIN2(PTVIInterface, PTVIInterface)
