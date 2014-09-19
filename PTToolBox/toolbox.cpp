#include "toolbox.h"
#include "ui_toolbox.h"

ToolBox::ToolBox(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ToolBox)
{
    ui->setupUi(this);

    QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry");
    animation->setStartValue(QRect(200, 100, 0, 0));
    animation->setEndValue(QRect(300, 200, 286, 252));
    animation->setEasingCurve(QEasingCurve::OutCirc);
    animation->setDuration(500);
    animation->start();
}

ToolBox::~ToolBox()
{
    delete ui;
}

void ToolBox::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
