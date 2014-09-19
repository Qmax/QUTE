#include <QtGui/QApplication>
#include "arbitary.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Arbitary w;
    w.show();
    return a.exec();
}
