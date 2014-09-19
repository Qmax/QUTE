#include <QtGui/QApplication>
#include "dmmaccuracy.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DMMAccuracy w;
    w.show();
    return a.exec();
}
