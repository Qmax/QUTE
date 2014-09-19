// -------------------------------------------------
// Project created by Ravivarman.R 2014-09-09T14:08:47
// -------------------------------------------------
#ifndef INTERFACEDIGRAPHER_H
#define INTERFACEDIGRAPHER_H

#include <DIGrapherInterface.h>
#include <digrapher.h>

class InterfaceDIGrapher:public QObject,public DIGrapherInterface
{
    Q_OBJECT
    Q_INTERFACES(DIGrapherInterface)
public:
    QWidget* getDIGraph();
    void setGraphGeometry(int x,int y,int w,int h){
        obj->setGraphGeometry(x,y,w,h);
    }
    void setGraphCount(int count){
        obj->setGraphCount(count);
    }

    void setGraphTitle(QStringList strList)    {
        obj->setGraphTitle(strList);
    }

    void setLegendVisible(bool state){
        obj->setLegendVisible(state);
    }
    void setupGraphWindow(){
        obj->setupGraphWindow();
    }
    void setZoomInGraphGeometry(int x,int y,int w,int h){
        obj->setZoomInGraphGeometry(x,y,w,h);
    }
    void setZoomOutGraphGeometry(int x,int y,int w,int h){
        obj->setZoomOutGraphGeometry(x,y,w,h);
    }
    void plotGraphWindow(){
        obj->plotGraphWindow();
    }
    void setGraphData(int index,QVector<double> x,QVector<double> y){
        obj->setGraphData(index,x,y);
    }
    void setGraphRange(QString xN,double xL,double xH,QString yN,double yL,double yH){
        obj->setGraphRange(xN,xL,xH,yN,yL,yH);
    }
protected:
    DIGrapher* obj;
};

#endif // INTERFACEDIGRAPHER_H
