#ifndef DMMUTILITY_H
#define DMMUTILITY_H

#include <QDialog>

namespace Ui {
    class DMMUtility;
}

class DMMUtility : public QDialog {
    Q_OBJECT
public:
    DMMUtility(QWidget *parent = 0);
    ~DMMUtility();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::DMMUtility *ui;

private slots:
    void on_pushButton_13_clicked();
    void on_pushButton_12_clicked();
};

#endif // DMMUTILITY_H
