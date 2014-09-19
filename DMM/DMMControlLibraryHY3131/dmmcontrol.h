#ifndef DMMCONTROL_H
#define DMMCONTROL_H

#include "DMMControl_global.h"
#include "dmm.h"

class DMMCONTROLSHARED_EXPORT DMMControl:public QWidget {
public:
    DMMControl(QWidget *p=0);
    DMM* m_objDMM;
protected:

};

DMMControl *g_objDMMControl;

extern "C"
{
    DMMCONTROLSHARED_EXPORT DMM* InvokeDMM(QWidget *);
}

#endif // DMMCONTROL_H
