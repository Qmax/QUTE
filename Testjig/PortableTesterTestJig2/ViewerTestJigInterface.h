#ifndef VIEWERINTERFACE_H
#define VIEWERINTERFACE_H
#include <QObject>
#include <QWidget>
class IViewerTestJigInterface
{
public:
    virtual void setViewer(QWidget*)=0;
    virtual void closeViewer()=0;
};

Q_DECLARE_INTERFACE(IViewerTestJigInterface,"pt.ViewerTestJigInterface/1.0.0.1");
#endif
