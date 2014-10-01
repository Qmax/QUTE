#include <QtGui/QApplication>
#include "dsodisplay.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DSODisplay w;
    w.show();
    return a.exec();
}
