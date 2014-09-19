#include <QtGui/QApplication>
#include "adchighspeed.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ADCHighSpeed w;
    w.show();
    return a.exec();
}
