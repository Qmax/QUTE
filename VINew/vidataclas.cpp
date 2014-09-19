#include "vidataclas.h"


void InteractiveData::InitialiseMap()
{
    //set Voltage
    m_mapVoltage.insert(0,"0.2 V");
    m_mapVoltage.insert(1,"2.5 V");
    m_mapVoltage.insert(2,"8.0 V");
    m_mapVoltage.insert(3,"13.0 V");
//
//    // set Frequency
    m_mapFrequency.insert(0,"10 Hz");
    m_mapFrequency.insert(1,"20 Hz");
    m_mapFrequency.insert(2,"50 Hz");
    m_mapFrequency.insert(3,"100 Hz");
    m_mapFrequency.insert(4,"200 Hz");
    m_mapFrequency.insert(5,"500 Hz");
    m_mapFrequency.insert(6,"1 KHz");
    m_mapFrequency.insert(7,"2 KHz");
    m_mapFrequency.insert(8,"5 KHz");
    m_mapFrequency.insert(9,"10 KHz");
    m_mapFrequency.insert(10,"20 KHz");
    m_mapFrequency.insert(11,"50 KHz");
    m_mapFrequency.insert(12,"100 KHz");

//    // set Impedance
    m_mapImpedance.insert(0,"10 E");
    m_mapImpedance.insert(1,"20 E");
    m_mapImpedance.insert(2,"50 E");
    m_mapImpedance.insert(3,"100 E");
    m_mapImpedance.insert(4,"200 E");
    m_mapImpedance.insert(5,"500 E");
    m_mapImpedance.insert(6,"1 K");
    m_mapImpedance.insert(7,"2 K");
    m_mapImpedance.insert(8,"5 K");
    m_mapImpedance.insert(9,"10 K");
    m_mapImpedance.insert(10,"20 K");
    m_mapImpedance.insert(11,"50 K");
    m_mapImpedance.insert(12,"100 K");
    m_mapImpedance.insert(13,"200 K");
    m_mapImpedance.insert(14,"500 K");
    //m_mapImpedance.insert(15,"1 M");
}

QString InteractiveData::getFrequencyMap(short int pIndex)
{
    return m_mapFrequency.value(pIndex);
}

QString InteractiveData::getImpedanceMap(short int pIndex)
{
    return m_mapImpedance.value(pIndex);
}

QString InteractiveData::getVoltageMap(short int pIndex)
{
    return m_mapVoltage.value(pIndex);
}





