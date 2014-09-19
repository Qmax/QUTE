#ifndef KEYOBJECT_H
#define KEYOBJECT_H
#include <QObject>
#include <QEvent>
#include "stdio.h"

class KeyObject:public QObject
{
        Q_OBJECT
public:
        KeyObject();
protected:
        bool eventFilter(QObject *obj, QEvent *event);
public Q_SLOTS:
        void receiveData(int pData);
signals:
	void keyPressed(int pData);
};



#endif // KEYOBJECT_H
