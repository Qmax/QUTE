#ifndef VIDATACLAS_H
#define VIDATACLAS_H


#include <QMap>
#include <QList>
#include <QString>
#include <QDebug>


template <class T,class U =short int>
class DataClass
{
public:
    DataClass(U pSize=3)
    {
       // qDebug()<<"Data Class Constructor";
        m_nData = new T[pSize];
    }
    DataClass(const DataClass& pObj);
    DataClass& operator=(const DataClass& pObj);
    ~DataClass()
    {
        //qDebug()<<"Data Class Destructor";
        delete []m_nData,m_nData=NULL;
    }

    void setIndex(short int pIndex,T pData)
    {
        //qDebug()<< "Data:"<<pData<<"Index:"<<pIndex;
        m_nData[pIndex] = pData;
    }
    T getIndex(short int pIndex) const
    {
        //qDebug()<<"Index:"<<m_nData[pIndex];
        return m_nData[pIndex];
    }
protected:
    T *m_nData;
};



class InteractiveData
{
public:
    QString getVoltageMap(short int);
    QString getFrequencyMap(short int);
    QString getImpedanceMap(short int);
    void InitialiseMap();
protected:
    QMap <short,QString> m_mapVoltage;
    QMap <short,QString> m_mapFrequency;
    QMap <short,QString> m_mapImpedance;

};

#endif // VIDATACLAS_H
