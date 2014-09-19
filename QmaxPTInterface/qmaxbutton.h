#ifndef QMAXBUTTON_H
#define QMAXBUTTON_H

#include "colors.h"
#include <QtGui>




class QmaxButton:public QWidget {
    Q_OBJECT
public:
    enum BUTTONTYPE { SIDEBAR,PANEL,UP,DOWN };
    enum STATE {ON,OFF,HIGHLIGHT,DISABLED};

    QmaxButton(QString pText,QSize buttonSize,QString pImage,int type = 0,int pUserCode=0,QWidget *parent = 0);
    void setState(int);
    void changeStatus(bool);
    bool readStatus() const;
    void refresh();
    void setText(QString);
    //virtual void setDisabled(bool);
public slots:
    //void updateUserCode(int);
    //void buttonPressed(int);
    //virtual void setDisabled(bool);
signals:
    void clicked(int);
protected:
    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    virtual void paintEvent(QPaintEvent *event);
    void createButton(QPainter&) ;
    void createSideButton(QPainter&) ;
    void createArrowBackground(QPainter &painter);
    void refreshButton();

    QMatrix matrix;
    QImage pixImage,backImage;
    QString m_strText,m_strImage;
    int m_nPressed;
    int m_nHighlight;
    QSize logicalSize;
    bool m_nStatus;
    int m_nUserCode;
    short m_nType;
    short m_nType2;

};




#endif // QMAXBUTTON_H
