#ifndef PTEVENTINTERFACES_H
#define PTEVENTINTERFACES_H

#include<QWidget>
#include<QString>


class PTEventInterface
{
public:
    virtual void  InvokeGPIOEvent(QWidget *parent,QString driver, QString device,int *pKeyCode)=0;
    virtual void closefd(void)=0;
    virtual bool BlockSig(bool get)=0;
};


Q_DECLARE_INTERFACE(PTEventInterface,"pt.PTKEYEventInterface/1.0.0.1");


#endif // PTEVENTINTERFACES_H
