#ifndef PTINTERFACEHEADERS_H
#define PTINTERFACEHEADERS_H
#include <QtCore>

class IPTDMMInterface
{
public:
    virtual QWidget* getPTWidget()=0;
    virtual unsigned int getGUID()=0;
};
class IPTFGInterface
{
public:
    virtual QWidget* getPTWidget()=0;
    virtual unsigned int getGUID()=0;
};
class IPTVIInterface
{
public:
    virtual QWidget* getPTWidget()=0;
    virtual unsigned int getGUID()=0;
};
class IPTSLInterface
{
public:
    virtual QWidget* getPTWidget()=0;
    virtual unsigned int getGUID()=0;
};
class IPTSHLInterface
{
public:
    virtual QWidget* getPTWidget()=0;
    virtual unsigned int getGUID()=0;
};
class IPTICMInterface
{
public:
    virtual QWidget* getPTWidget()=0;
    virtual unsigned int getGUID()=0;
};
class IPTDSOInterface
{
public:
    virtual QWidget* getPTWidget()=0;
    virtual unsigned int getGUID()=0;
};


Q_DECLARE_INTERFACE(IPTSLInterface, "pt.SLInterfaces/1.0.0.1");
Q_DECLARE_INTERFACE(IPTSHLInterface, "pt.SHLInterfaces/1.0.0.1");
Q_DECLARE_INTERFACE(IPTVIInterface, "pt.VIInterfaces/1.0.0.1");
Q_DECLARE_INTERFACE(IPTFGInterface, "pt.FGInterfaces/1.0.0.1");
Q_DECLARE_INTERFACE(IPTDMMInterface,"pt.DMMInterfaces/1.0.0.1");
Q_DECLARE_INTERFACE(IPTICMInterface,"pt.ICMInterfaces/1.0.0.1");
Q_DECLARE_INTERFACE(IPTDSOInterface,"pt.DSOInterfaces/1.0.0.1");

#endif // PTINTERFACEHEADERS_H
