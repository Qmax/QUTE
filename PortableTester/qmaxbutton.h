#ifndef QMAXBUTTON_H
#define QMAXBUTTON_H

#include "colors.h"
#include <QtGui>


class IQmaxPTProduct
{
public:
    virtual void refreshButton()=0;
    virtual void createButton(QPainter&)=0;
    virtual void setGeometry(int,int,int,int)=0;
    virtual ~IQmaxPTProduct(){    }
};
struct PT_BMENU
{
    QString m_strButtonCaption;
    double m_nXPos;
    double m_nYPos;
    int m_nHeight;
    int m_nWidth;
    QString m_strDescription;
    QString m_strImageName;
};

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

};




#endif // QMAXBUTTON_H
