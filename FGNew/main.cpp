#include <QtGui/QApplication>
#include "fg.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FG w;
    w.show();
    return a.exec();
}
