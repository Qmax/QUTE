/***********************************************************
***************Created by Ravivarman.R,Qmax*****************
***********************************************************/
#include <QtGui/QApplication>
#include "openshortcalib.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    OpenShortCalib w;
    w.show();
    return a.exec();
}
