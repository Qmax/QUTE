#ifndef PTCOMPONENTSINTERFACE_H
#define PTCOMPONENTSINTERFACE_H

#include <QtCore>
#include <QObject>
#include <qmap.h>
#include "IPTComponentsInterfaces.h"
#include "PTInterfaceHeaders.h"

//class IPTComponentsInterface;

class PTComponentsInterface:public QObject,public IPTComponentsInterface
{
    Q_OBJECT
    Q_INTERFACES(IPTComponentsInterface)
public:
    PTComponentsInterface(QObject *parent = 0);
    ~PTComponentsInterface(){}
    void RegisterPTWidget(unsigned int);
    void LoadPTPlugins();
    void LoadDMMPlugins();
    void LoadFGPlugins();
    void LoadSLPlugins();
    void LoadVIPlugins();
    void LoadSHLPlugins();
    void LoadICMPlugins();
    void LoadDSOPlugins();
    void removePlugin(unsigned int);
    virtual QWidget* InvokeApplication(unsigned int);

    QPluginLoader *pluginDMM,*pluginFG,*pluginVI,*pluginSL,*pluginICM,*pluginDSO,*pluginSHL;
    QObject *ptDMM,*ptFG,*ptVI,*ptSL,*ptICM,*ptDSO,*ptSHL;
    QMap<int,QWidget*> m_PTFactories;
    IPTDMMInterface *IDMM;
    IPTFGInterface *IFG;
    IPTSLInterface *ISL;
    IPTSHLInterface *ISHL;
    IPTVIInterface *IVI;
    IPTICMInterface *IICM;
    IPTDSOInterface *IDSO;
};

#endif // PTCOMPONENTSINTERFACE_H
