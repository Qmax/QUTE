#ifndef DIALWIDGET_H
#define DIALWIDGET_H

#include <QWidget>
#include <dial.h>

namespace Ui {
    class dialWidget;
}

class dialWidget : public QWidget {
    Q_OBJECT
public:
    dialWidget(QWidget *parent = 0);
    ~dialWidget();

protected:
    void changeEvent(QEvent *e);
    PotentioMeter *m_objVoltageDial;
private:
    Ui::dialWidget *ui;

private slots:
    void on_butClose_clicked();
};

#endif // DIALWIDGET_H
