#ifndef PTDSOCARDPLUGIN_H
#define PTDSOCARDPLUGIN_H

#include <QtCore>
#include <QObject>
#include <fcntl.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <qdebug.h>
#include <sys/syscall.h>
#include "DSOCardInterface.h"


class PTDSOCardPlugin:public QObject,public IDSOCardInterface
{
    Q_OBJECT
    Q_INTERFACES(IDSOCardInterface)
public:
    void setDeviceName();
    void enumerateDSOCard();
    unsigned int readDSOCardCodeId();
    void writeScratchpad(unsigned int);
    unsigned int readScratchPad();
    unsigned int readRegister(unsigned int);
    void writeRegister(unsigned int,unsigned int);
protected:
    unsigned int tempAddr;
    unsigned int baseAddr;
    int m_nDSOFD;
    const char *m_strdevice;
    QMap<int,const char*> mapDeviceString;
};

#endif // PTDSOCARDPLUGIN_H
