#ifndef FGAPPINTERFACE_H
#define FGAPPINTERFACE_H
#include <QObject>
#include <QtCore>
#include <QWidget>
class IPTFGAppInterface
{
public:
        virtual QWidget* getFGApp()=0;
};

Q_DECLARE_INTERFACE(IPTFGAppInterface,"pt.PTFGAppInterface/1.0.0.1");
#endif // FGAPPINTERFACE_H
