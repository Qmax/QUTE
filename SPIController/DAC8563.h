#ifndef DAC8563_H
#define DAC8563_H

#include <ApplicationCardInterface.h>
#include "Macros.h"

#define OFF			0
#define DAC_A		1
#define DAC_B		2
#define DAC_AnB		3

#define GND_1KE		0
#define GND_100KE	1
#define GND_HIZ		2

class DAC8563
{
public:
    DAC8563(IApplicationCardInterface *pobj);

    void writeDAC8563(unsigned short,unsigned short);

    void WriteUpdateData(unsigned short,unsigned short,unsigned short);
    void PowerUp(unsigned short);
    void PowerDown(unsigned short,unsigned short);
    void SetGain(unsigned short,unsigned short);
    void SetLDAC(unsigned short);
    void ResetDAC();
    void PowerOnResetUpdate();
    void EnableINTRef(bool);

protected:
    IApplicationCardInterface *objAppcard;
    unsigned short int m_nSPIAppendBit;

};

#endif // DAC8563_H
