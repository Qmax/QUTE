#ifndef MESSAGEWIDGET_H
#define MESSAGEWIDGET_H

#include <QtGui/QWidget>
#include "ui_messagewidget.h"

class MessageWidget : public QWidget
{
    Q_OBJECT

public:
    MessageWidget(QWidget *parent = 0);
    ~MessageWidget();
    void setText(QString);
private:
    Ui::MessageWidgetClass ui;
};

#endif // MESSAGEWIDGET_H
