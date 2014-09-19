#ifndef ISLA118P50COMPONENT_H
#define ISLA118P50COMPONENT_H

//INCLUDES

#include <ApplicationCardInterface.h>
#include <unistd.h>
#include <qdebug.h>

//MACROS

#define ACTIVE_LOW_CLKPOL		0xC000
#define ACTIVE_HIGH_CLKPOL		0x8000

#define WRITE_MODE		0x7FFF
#define READ_MODE		0x8000

#define ONE_BYTE        0x0000
#define TWO_BYTE        0x2000
#define THREE_BYTE      0x4000
#define FOUR_BYTE       0x6000

#define DRIVE_8BIT		0x1
#define DRIVE_16BIT		0x3
#define DRIVE_24BIT		0x5
#define DRIVE_32BIT		0x7

#define CHIP_ID         0x0008
#define CHIP_VER        0x0009
#define PORT_CONFIG     0x0000


class ISLA118P50Component
{
public:
    ISLA118P50Component(IApplicationCardInterface *pobj);

    void configureADCChip();
    unsigned short readChipVersion();
    unsigned short readChipID();

protected:
    IApplicationCardInterface *objAppcard;
    unsigned short int m_nSPIAppendBit;
};

#endif // ISLA118P50COMPONENT_H
