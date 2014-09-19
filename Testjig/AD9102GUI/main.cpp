#include <QtGui/QApplication>
#include "ad9102ui.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AD9102UI w;
    w.show();
    return a.exec();
}
