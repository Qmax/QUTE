#include <QtGui/QApplication>
#include "adhighaccuracy.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ADHighAccuracy w;
    w.show();
    return a.exec();
}
