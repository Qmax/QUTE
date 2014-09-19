#ifndef PTVIINTERFACE_H
#define PTVIINTERFACE_H

#include <QObject>
#include"interfaceHeader.h"
#include"mainwindow.h"




class PTVIInterface:public QObject,public IPTVIInterface
{
    Q_OBJECT
    Q_INTERFACES(IPTVIInterface)

public:
    PTVIInterface(QObject *parent = 0);
    QWidget* getPTWidget();
    unsigned int getGUID();
protected:
   MainWindow *m_objVIWidget;

};
#endif // PTVIINTERFACE_H
