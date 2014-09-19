#include <QtGui/QApplication>
#include "muxjig.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MuxJig w;
    w.show();
    return a.exec();
}
