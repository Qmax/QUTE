#include <QtGui/QApplication>
#include <QtGui/QWSServer>

#include <QtDebug>
#include <QFile>
#include <QTextStream>

#include "portabletester.h"
#include "mainwindowview.h"
//#include "menumanager.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


	#ifdef Q_WS_QWS
    QWSServer::setCursorVisible( true );
    #endif
    PortableTester w;
    w.show();
    return a.exec();
}




