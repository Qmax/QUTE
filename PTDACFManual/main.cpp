#include <QtGui/QApplication>
#include "dacfwidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DACFWidget w;
    w.show();
    return a.exec();
}
