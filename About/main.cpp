#include <QtGui/QApplication>
#include "about.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    About w;
    w.show();
    return a.exec();
}
