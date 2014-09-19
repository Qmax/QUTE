#ifndef PTSPLASHSCREEN_H
#define PTSPLASHSCREEN_H

#include <QObject>
#include <QSplashScreen>

class PTSplashScreen{

public:
    virtual QSplashScreen* getSplashWidget(QWidget*)=0;
    virtual void ShowSplash()=0;
    virtual void setSplashSpan(int)=0;
    virtual void selectSplashImage(int)=0;
    virtual void closeSplash()=0;
    virtual void setPos(int,int,int,int)=0;
    virtual void setSplashStyle(QString)=0;
    virtual void setLoadingText(QString)=0;
};

Q_DECLARE_INTERFACE(PTSplashScreen,"pt.ptsplashscreen/1.0.0.1");


#endif // PTSPLASHSCREEN_H
