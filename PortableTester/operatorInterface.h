#ifndef OPERATORINTERFACE_H
#define OPERATORINTERFACE_H
#include <QString>
#include <QWidget>
class OperatorInterface
{
public:
    virtual double operation(double,double)=0;
};

extern "C" __attribute__((visibility("default"))) OperatorInterface *getInterface();
typedef OperatorInterface *(*GetInterfacePointer)();


class ToolInterface
{
public:
    virtual QString toolName() const =0;
};
Q_DECLARE_INTERFACE(ToolInterface,"in.forwardbias.tool/1.0");

class IPTComponentsInterface
{
    public:
        virtual QWidget* InvokeApplication(unsigned int)=0;
        virtual void RegisterPTWidget(unsigned int)=0;
        virtual void LoadPTPlugins()=0;
        virtual void LoadDMMPlugins()=0;
        virtual void LoadFGPlugins()=0;
        virtual void LoadSLPlugins()=0;
        virtual void LoadVIPlugins()=0;
        virtual void LoadSHLPlugins()=0;
        virtual void LoadICMPlugins()=0;
        virtual void LoadDSOPlugins()=0;
        virtual void removePlugin(unsigned int)=0;
};
Q_DECLARE_INTERFACE(IPTComponentsInterface,"pt.componentInterface/1.0.0.1");


#endif // OPERATORINTERFACE_H
