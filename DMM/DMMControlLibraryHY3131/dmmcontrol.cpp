#include "dmmcontrol.h"


DMMControl::DMMControl(QWidget *pWidget)
{
    m_objDMM = new DMM(pWidget);

    //m_objDMM->show();
}

DMM* InvokeDMM(QWidget *pWidget)
{
    g_objDMMControl = new DMMControl(pWidget);

    return g_objDMMControl->m_objDMM;
}
