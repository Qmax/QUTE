#ifndef DMMACCURACY_H
#define DMMACCURACY_H

#include <QWidget>
#include <QProcess>
#include <QDate>
#include <QDebug>
#include <iostream>

namespace Ui {
    class DMMAccuracy;
}

class DMMAccuracy : public QWidget {
    Q_OBJECT
public:
    DMMAccuracy(QWidget *parent = 0);
    ~DMMAccuracy();

    void executeSystemCommand(QString,QString);

protected:
    void changeEvent(QEvent *e);

private:
    Ui::DMMAccuracy *ui;

private slots:

    void on_dateTimeEdit_dateTimeChanged(QDateTime date);
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
};

#endif // DMMACCURACY_H
