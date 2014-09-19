#ifndef AD9102_H
#define AD9102_H

#include <ApplicationCardInterface.h>
#include <QMap>
#include <unistd.h>
#include <qdebug.h>

class AD9102Component
{

public:
    AD9102Component(IApplicationCardInterface *pobj);

    void writeAD9102SPI(unsigned short pAddress,unsigned short pData);
    unsigned short readAD9102SPI(unsigned short pAddress);

    unsigned short SPIControlRegister(unsigned short pIndex);
    unsigned short PowerStatusRegister(unsigned short pIndex);
    unsigned short ClockControlRegister(unsigned short pIndex);
    unsigned short ReferenceResistorRegister(unsigned short pIndex);
    unsigned short DACAnalogGainRegister(unsigned short pIndex);
    unsigned short DACAnalogGainRangeRegister(unsigned short pIndex);
    unsigned short FSADJRegister(unsigned short pIndex);
    unsigned short CalibrationRegister(unsigned short pIndex);
    unsigned short CompOffsetRegister(unsigned short pIndex);
    unsigned short UpdatePatternRegister(unsigned short pIndex);
    unsigned short PatternStatusCommandStatusRegister(unsigned short pIndex);
    unsigned short PatternTypeCommandStatusRegister(unsigned short pIndex);
    unsigned short TriggerStartRealPatternDelayRegister(unsigned short pIndex);
    unsigned short DACDigitalOffsetRegister(unsigned short pIndex);
    unsigned short WaveSelectRegister(unsigned short pIndex);
    unsigned short DACTimeControlRegister(unsigned short pIndex);
    unsigned short PatternPeriodRegister(unsigned short pIndex);
    unsigned short DACPatternRepeatCyclesRegister(unsigned short pIndex);
    unsigned short TriggerStartDoutSignalRegister(unsigned short pIndex);
    unsigned short DoutConfigRegister(unsigned short pIndex);
    unsigned short DACConstantValueRegister(unsigned short pIndex);
    unsigned short DACDigitalGainRegister(unsigned short pIndex);
    unsigned short DACSawtoothConfigRegister(unsigned short pIndex);
    unsigned short DDSTuningWordMSBRegister(unsigned short pIndex);
    unsigned short DDSTuningWordLSBRegister(unsigned short pIndex);
    unsigned short DDSPhaseOffsetRegister(unsigned short pIndex);
    unsigned short PatternControl1Register(unsigned short pIndex);
    unsigned short PatternControl2Register(unsigned short pIndex);
    unsigned short TWRamConfigRegister(unsigned short pIndex);
    unsigned short StartDelayRegister(unsigned short pIndex);
    unsigned short StartAddressRegister(unsigned short pIndex);
    unsigned short StopAddressRegister(unsigned short pIndex);
    unsigned short DDSCyclesRegister(unsigned short pIndex);
    unsigned short ConfigurationErrorRegister(unsigned short pIndex);

protected:
    QMap<short int,SPI_SELECT> m_mapSPISelect;
    IApplicationCardInterface *objAppcard;
    unsigned short int m_nSPIAppendBit;
};

#endif // AD9102_H
