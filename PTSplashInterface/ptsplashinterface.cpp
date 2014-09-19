#include "ptsplashinterface.h"
#include <QStyleOptionProgressBarV2>
#include <QLabel>
#include <QMovie>
#include <QDesktopWidget>
#include <QDebug>
#include <QKeyEvent>
#include <QMoveEvent>

SplashScreen::SplashScreen(QApplication *aApp, QWidget *parent) :
    QSplashScreen(parent), app(aApp), m_progress(0)
{
	movie = new QMovie(":/splashImages/splashImage1.gif");
	processLabel = new QLabel(parent);

    processLabel->setMovie(movie);
//    processLabel->setStyleSheet("border: 2px solid white;");

    maskedRegion=new QRegion(325,290,150,20,QRegion::Rectangle);
    QSize size(150,20);
    processLabel->setGeometry(325,290,150,20);
    setMask(*maskedRegion);
    movie->setScaledSize(size);

    movie->setSpeed(200);
//    movie->start();

    this->setCursor(Qt::BusyCursor);
    this->showMessage("Loading", Qt::AlignBottom);
    this->setGeometry(parent->pos().x(),parent->pos().y(),parent->width(),parent->height());

    makeScreenCenter();

    this->setWindowModality(Qt::WindowModal);
}
SplashScreen::~SplashScreen(){
}

void SplashScreen::makeScreenCenter(){
    QDesktopWidget *desktop = QApplication::desktop();

    int screenWidth, width;
    int screenHeight, height;
    int x, y;
    QSize windowSize;

    screenWidth = desktop->width();
    screenHeight = desktop->height();

    windowSize = size();
    width = windowSize.width();
    height = windowSize.height();


    x = (screenWidth - width) / 2;
    y = (screenHeight - height) / 2;
    y -= 50;


   move ( x, y );

    setFixedSize(windowSize.width(), windowSize.height());
}
void SplashScreen::drawContents(QPainter *painter)
{
  QSplashScreen::drawContents(painter);

  // Set style for progressbar...
  QStyleOptionProgressBarV2 pbstyle;
  pbstyle.initFrom(this);
  pbstyle.state = QStyle::State_Enabled;
  pbstyle.textVisible = false;
  pbstyle.minimum = 0;
  pbstyle.maximum = 100;
  pbstyle.progress = m_progress;
  pbstyle.invertedAppearance = false;
  pbstyle.rect = QRect(0, 265, 380, 19); // Where is it.

  // Draw it...
  style()->drawControl(QStyle::CE_ProgressBar, &pbstyle, painter, this);
}

Q_EXPORT_PLUGIN2(PTSplashScreen,InterfaceClass);
