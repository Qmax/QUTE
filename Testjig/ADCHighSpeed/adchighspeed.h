#ifndef ADCHIGHSPEED_H
#define ADCHIGHSPEED_H

#include <QWidget>
#include <QDebug>
#include <QPluginLoader>

#include "isla118p50component.h"
#include "ApplicationCardInterface.h"

namespace Ui {
    class ADCHighSpeed;
}

class ADCHighSpeed : public QWidget {
    Q_OBJECT
public:
    ADCHighSpeed(QWidget *parent = 0);
    ~ADCHighSpeed();

protected:
    ISLA118P50Component *objISLA118P50;
    IApplicationCardInterface *IAppCard;
    void changeEvent(QEvent *e);

private:
    Ui::ADCHighSpeed *ui;

private slots:
    void on_readVersion_3_clicked();
    void on_readVersion_2_clicked();
    void on_readVersion_clicked();
    void on_readCodeID_clicked();
};

#endif // ADCHIGHSPEED_H
