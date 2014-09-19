#ifndef QMAXMESSAGEBOX_H
#define QMAXMESSAGEBOX_H

#include <QWidget>
#include <qmessagebox.h>
#include <qdebug.h>
#include <QIcon>
#include <QPushButton>

class QmaxMessageBox : public QWidget
{
Q_OBJECT
public:
    explicit QmaxMessageBox(QWidget *parent = 0);
    bool MessageBox(bool,bool,QString, QString,QString,QWidget *parent = 0);
    QMessageBox *msgBox;
    QPushButton *connectButton,*abortButton;
    bool msgBoxLive;

    QPushButton* getAbortButton(){return abortButton;}
    QPushButton* getConnectButton(){return connectButton;}
    bool getmsgBoxLiveStatus(){return msgBoxLive;}
    void setmsgBoxLiveStatus(bool val){msgBoxLive=val;}
    void closeMessageBox(){this->close();}

signals:

public slots:

};

#endif // QMAXMESSAGEBOX_H
