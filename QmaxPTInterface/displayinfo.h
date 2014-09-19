#ifndef DISPLAYINFO_H
#define DISPLAYINFO_H

#include <QWidget>

namespace Ui {
    class DisplayInfo;
}

class DisplayInfo : public QWidget {
    Q_OBJECT
public:
    DisplayInfo(QWidget *parent = 0);
    ~DisplayInfo();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::DisplayInfo *ui;
};

#endif // DISPLAYINFO_H
