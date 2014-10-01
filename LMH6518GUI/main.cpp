#include <QtGui/QApplication>
#include "lmh6518gui.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
    //MyApp a(argc, argv);
    LMH6518GUI w;
    a.setAttribute(Qt::AA_DontCreateNativeWidgetSiblings);
    w.show();
    return a.exec();
}
