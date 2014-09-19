#include <QtGui/QApplication>
#include "icm.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ICM w;
    w.show();
    return a.exec();
}
