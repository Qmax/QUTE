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


	//~~~~~~~~~~~~~Reading cursor state~~~~~~~~~~~~~~~~~~~~~~
		QStringList stringList;		QFile textFile;		QString m_strState;
		textFile.setFileName("cursorState.txt");
		if (textFile.open(QIODevice::ReadOnly)) {
			QTextStream textStream(&textFile);
			while (!textStream.atEnd()) {
				stringList.append(textStream.readLine());
			}
			m_strState= stringList.value(0);
		}
		if(m_strState=="true"){
			#ifdef Q_WS_QWS
				QWSServer::setCursorVisible( true );
			#endif
		}
		else{
			#ifdef Q_WS_QWS
				QWSServer::setCursorVisible( false );
			#endif
		}
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


    PortableTester w;
    w.show();
    return a.exec();
}




