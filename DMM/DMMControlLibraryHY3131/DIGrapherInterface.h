// -------------------------------------------------
// Project created by Ravivarman.R 2014-09-09T14:08:47
// -------------------------------------------------
#ifndef DIGRAPHERINTERFACE_H
#define DIGRAPHERINTERFACE_H

#include <QObject>
#include <QtCore>
#include <QWidget>

class DIGrapherInterface
{
public:
        virtual QWidget* getDIGraph()=0;
        virtual void setGraphGeometry(int,int,int,int)=0;
        virtual void setZoomInGraphGeometry(int,int,int,int)=0;
        virtual void setZoomOutGraphGeometry(int,int,int,int)=0;
        virtual void setGraphCount(int)=0;
        virtual void setGraphTitle(QStringList)=0;
        virtual void setLegendVisible(bool)=0;
        virtual void setupGraphWindow()=0;
        virtual void plotGraphWindow()=0;
        virtual void setGraphData(int,QVector<double>,QVector<double>)=0;
        virtual void setGraphRange(QString,double,double,QString,double,double)=0;
};

Q_DECLARE_INTERFACE(DIGrapherInterface,"pt.DIGrapherInterface/1.0.0.1");
#endif // DIGRAPHERINTERFACE_H
