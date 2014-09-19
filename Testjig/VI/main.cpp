#include <QtGui/QApplication>
#include "vijig.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    VIJig w;
    w.show();
    return a.exec();
}
