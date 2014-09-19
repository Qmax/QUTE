#include <QtGui/QApplication>
#include "dmmjig.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DMMJig w;
    w.show();
    return a.exec();
}
