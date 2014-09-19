#include "slcontrol.h"


SLControl::SLControl(QWidget *pWidget)
{
	 m_objSL = new ShortLocater(pWidget);
}

ShortLocater* InvokeSL(QWidget *pWidget)
{
    g_objSLControl = new SLControl(pWidget);

    return g_objSLControl->m_objSL;
}
