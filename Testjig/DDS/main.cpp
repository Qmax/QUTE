#include <QtGui/QApplication>
#include "ddswidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DDSWidget w;
    w.show();
    return a.exec();
}
