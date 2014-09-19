#ifndef TOOLBOX_H
#define TOOLBOX_H

#include <QWidget>
#include <QPropertyAnimation>

namespace Ui {
    class ToolBox;
}

class ToolBox : public QWidget {
    Q_OBJECT
public:
    ToolBox(QWidget *parent = 0);
    ~ToolBox();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::ToolBox *ui;
};

#endif // TOOLBOX_H
