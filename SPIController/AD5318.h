#ifndef AD5318_H
#define AD5318_H

#include <InterfaceFunctionalComponents.h>

class AD5318
{
public:
    AD5318(IApplicationCardInterface *pObjAppcard=0);
    void configureADC5318CW();
    void configureADC5318Data(AD5318_dataTemplate obj);
    void resetDAC5318(bool bDCRReset);
protected:
    void configureAD5318DACCW(AD5318_ctrlTemplate pDACAD5318CW);
    void configureAD5318DACData(AD5318_dataTemplate pDACAD5318Data);
    unsigned short convertToDecimalValue(double pVout,double pVref,bool bUnipolar,AD5318_DACSELECT p_eDACSelect);
    IApplicationCardInterface *objAppcard;
    unsigned short GAINVALUE;
};

#endif // AD5318_H
