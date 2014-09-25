/***********************************************************
***************Created by Ravivarman.R,Qmax*****************
***********************************************************/
#include <QtGui/QApplication>
#include "ptcalibration.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PTCalibration w;
    w.show();
    return a.exec();
}
