#include <QtGui/QApplication>
#include "testencoder.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TestEncoder w;
    w.show();
    return a.exec();
}
