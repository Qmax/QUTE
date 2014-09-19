#ifndef PROBESTATUS_H
#define PROBESTATUS_H

#include <QWidget>
#include <QPainter>

namespace Ui {
    class ProbeStatus;
}

class ProbeStatus : public QWidget {
    Q_OBJECT
public:
    ProbeStatus(QWidget *parent = 0);
    ~ProbeStatus();

protected:
    void changeEvent(QEvent *e);
    void paintEvent(QPaintEvent *);
private:
    Ui::ProbeStatus *ui;
    QPainter *painter;

private slots:
    void on_toolButton_clicked();
};

#endif // PROBESTATUS_H
