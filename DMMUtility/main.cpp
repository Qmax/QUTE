#include <QtGui/QApplication>
#include "dmmutility.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DMMUtility w;
    w.show();
    return a.exec();
}
