#include <QtGui/QApplication>
#include "ad5318.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AD5318 w;
    w.show();
    return a.exec();
}
