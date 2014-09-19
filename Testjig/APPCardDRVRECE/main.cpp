#include <QtGui/QApplication>
#include "ptappcarddrvrecev.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PtAppCardDrvRecev w;
    w.show();
    return a.exec();
}
