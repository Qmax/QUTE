#ifndef PTSPLASHINTERFACE_H
#define PTSPLASHINTERFACE_H

#include <QSplashScreen>
#include <QApplication>
#include <QTimer>
#include <PTSplashScreen.h>

#include <qlabel.h>
#include <qregion.h>
#include <qmovie.h>

#include <qobject.h>
#include <QtCore>

class SplashScreen : public QSplashScreen
{
    Q_OBJECT
public:
    explicit SplashScreen(QApplication *app, QWidget *parent = 0);
    ~SplashScreen();
    int m_progress;
    QApplication *app;
    int ImageNumber;
    QString LoadingText;
    void makeScreenCenter();

    QRegion *maskedRegion;
    QLabel *processLabel;
	QMovie *movie;

public slots:
    void setProgress(int value)
    {
      m_progress = value;
      if (m_progress > 100)
        m_progress = 100;
      if (m_progress < 0)
        m_progress = 0;
      update();
    }

protected:
    void drawContents(QPainter *painter);
};
class InterfaceClass:public QObject,public PTSplashScreen{
    Q_OBJECT
    Q_INTERFACES(PTSplashScreen)
    public:

        QSplashScreen* getSplashWidget(QWidget *parent){
             spla=new SplashScreen(NULL,parent);
        }
        void ShowSplash(){
            spla->movie->setSpeed(200);
//            spla->movie->start();
            spla->processLabel->show();
//            spla->show();
        }
        void setSplashSpan(int timerValue){
            QTimer::singleShot(timerValue, spla, SLOT(close()));
        }
        void setLoadingText(QString text="Loading..."){
        	spla->LoadingText=text;
        }
        void selectSplashImage(int no=1){
        	spla->ImageNumber=no;
        	switch(no){
        	case 0:
        		spla->processLabel->setText(spla->LoadingText);
        		spla->processLabel->setAlignment(Qt::AlignCenter);
        		break;
        	case 1:
        		spla->movie=new QMovie(":/splashImages/splashImage1.gif");
        		spla->processLabel->setMovie(spla->movie);
        		qDebug()<<spla->movie->fileName();
        		break;
        	case 2:
        		spla->movie=new QMovie(":/splashImages/splashImage2.gif");
        		spla->processLabel->setMovie(spla->movie);
        		qDebug()<<spla->movie->fileName();
        		break;
        	}

        }
        void closeSplash(){
        	qDebug()<<"inside splash close";
        	spla->movie->stop();
        	spla->processLabel->close();
        	spla->close();
        }
        void setPos(int x=325,int y=290,int w=150,int h=20){
        	if(spla->ImageNumber==0){
        		spla->maskedRegion=new QRegion(x,y,w,h,QRegion::Rectangle);
        		spla->processLabel->setGeometry(x,y,w,h);
        		spla->setMask(*(spla->maskedRegion));
        		spla->movie->setScaledSize(QSize(w,h));
        	}
        	else if(spla->ImageNumber==1){
            spla->maskedRegion=new QRegion(x,y,150,20,QRegion::Rectangle);
            spla->processLabel->setGeometry(x,y,150,20);
            spla->setMask(*(spla->maskedRegion));
            spla->movie->setScaledSize(QSize(150,20));
        	}
        	else if(spla->ImageNumber==2){
            spla->maskedRegion=new QRegion(x,y,70,70,QRegion::Rectangle);
            spla->processLabel->setGeometry(x,y,70,70);
            spla->setMask(*(spla->maskedRegion));
            spla->movie->setScaledSize(QSize(70,70));
        	}

        }
        void setSplashStyle(QString style="border: 2px solid white;"){
        	spla->processLabel->setStyleSheet(style);
        }
    protected:
         SplashScreen *spla;
};

#endif // PTSPLASHINTERFACE_H
