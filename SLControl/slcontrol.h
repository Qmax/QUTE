#ifndef SLCONTROL_H
#define SLCONTROL_H

#include "SLControl_global.h"
#include "shortlocater.h"

class SLCONTROLSHARED_EXPORT SLControl:public QWidget {
public:
    SLControl(QWidget *p=0);
    ShortLocater* m_objSL;
};
SLControl *g_objSLControl;

extern "C"
{
SLCONTROLSHARED_EXPORT ShortLocater* InvokeSL(QWidget *);
}

#endif // SLCONTROL_H
