#ifndef CHANNELWIDGET_H
#define CHANNELWIDGET_H

#include <QWidget>

namespace Ui {
    class ChannelWidget;
}

class ChannelWidget : public QWidget {
    Q_OBJECT
public:
    ChannelWidget(QWidget *parent = 0);
    ~ChannelWidget();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::ChannelWidget *ui;

private slots:
    void on_butClose_clicked();
};

#endif // CHANNELWIDGET_H
