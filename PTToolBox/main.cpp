#include <QtGui/QApplication>
#include "toolbox.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ToolBox w;
    w.show();
    return a.exec();
}
