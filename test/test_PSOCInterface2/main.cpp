#include <QtGui/QApplication>
#include "testpsocinterface2.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    testPSOCInterface2 w;
    w.show();
    return a.exec();
}
