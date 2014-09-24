#ifndef DATETIME_H
#define DATETIME_H

#include <QWidget>
#include <qdatetime.h>
#include <QPropertyAnimation>
#include <qdebug.h>
#include <QProcess>
#include <QDesktopWidget>

namespace Ui {
    class DateTime;
}

class DateTime : public QWidget {
    Q_OBJECT
public:
    DateTime(QWidget *parent = 0);
    ~DateTime();
    void executeSystemCommand(QString Command,QString args);
protected:
    void changeEvent(QEvent *e);
  QString cmd;
private:
    Ui::DateTime *ui;

private slots:

    void on_pb_Apply_clicked();
    void on_dateTimeEdit_dateTimeChanged(QDateTime date);
    void on_pb_exit_clicked();
};

#endif // DATETIME_H
