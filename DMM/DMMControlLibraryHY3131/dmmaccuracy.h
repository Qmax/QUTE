#ifndef DMMACCURACY_H
#define DMMACCURACY_H

#include <QWidget>
#include <QProcess>
#include <QDate>
#include <QDebug>
#include <QFile>
#include <QTimer>
#include <math.h>
#include <QTextStream>
#include <QDesktopWidget>

#define MAX_SAMPLES 50

namespace Ui {
    class DMMAccuracy;
}

class DMMAccuracy : public QWidget {
    Q_OBJECT
public:
    DMMAccuracy(QWidget *parent = 0);
    ~DMMAccuracy();

    void executeSystemCommand(QString,QString);
    double digitsLimiter();

protected:
    QTimer *m_nACCuTimer;
    void changeEvent(QEvent *e);
    double rxData,m_nSampleData[MAX_SAMPLES];
    int m_nInterval,m_nSamples,m_nIteration;
    QString rxRange;

private:
    Ui::DMMAccuracy *ui;

private slots:
    void on_spinBox_2_valueChanged(int );
    void on_spinBox_valueChanged(int );
    void saveToFile();

    void on_dateTimeEdit_dateTimeChanged(QDateTime date);
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();

    void getData(double,QString);
};

#endif // DMMACCURACY_H
