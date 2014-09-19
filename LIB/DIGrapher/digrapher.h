// -------------------------------------------------
// Project created by Ravivarman.R 2014-09-09T14:08:47
// -------------------------------------------------
#ifndef DIGRAPHER_H
#define DIGRAPHER_H

#include <QWidget>
#include <qcustomplot.h>
#include <QPropertyAnimation>

namespace Ui {
    class DIGrapher;
}

class DIGrapher : public QWidget {
    Q_OBJECT
public:
    DIGrapher(QWidget *parent = 0);
    ~DIGrapher();

    void setGraphGeometry(int x,int y,int w,int h);

    void setGraphCount(int count){
        m_nGraphCount=count;
    }

    void setGraphTitle(QStringList strList)    {
        m_strGraphTitle=strList;
    }

    void setLegendVisible(bool state){
        m_bLegendState=state;
    }

    void setZoomInGraphGeometry(int x,int y,int w,int h){
        ziX=x;ziY=y;ziW=w;ziH=h;
    }

    void setZoomOutGraphGeometry(int x,int y,int w,int h){
        zoX=x;zoY=y;zoW=w;zoH=h;
    }

    void setGraphData(int index,QVector<double> x,QVector<double> y){
        xData[index]=x;
        yData[index]=y;
    }

    void setGraphRange(QString xN,double xL,double xH,QString yN,double yL,double yH){
        xName=xN;yName=yN;
        xLRange=xL;yLRange=yL;xHRange=xH;yHRange=yH;
    }

    void setupGraphWindow();
    void setup(QCustomPlot *customPlot);

    void plotGraphWindow();
    void plot(QCustomPlot *customPlot);

protected:
    void changeEvent(QEvent *e);

    int m_nGraphCount,ziX,ziY,ziW,ziH,zoX,zoY,zoW,zoH;
    double xLRange,yLRange,xHRange,yHRange;
    QString xName,yName;
    QStringList m_strGraphTitle;
    QVector<double> xData[3],yData[3];


    bool m_bLegendState;

private:
    Ui::DIGrapher *ui;

private slots:
    void on_Refresh_clicked();
    void on_ZoomIn_clicked();
    void on_ZoomOut_clicked();
};

#endif // DIGRAPHER_H
