#ifndef AD5293_H
#define AD5293_H

#include <InterfaceFunctionalComponents.h>



class AD5293
{
    public:
    	AD5293(IApplicationCardInterface* pObj=0);
    	void configureADC5293CW(SPI1_CONFIGURATION);
        void resetDAC5293(bool bDCRReset);
        void calculateADC5293DATA(AD5293_Template pObjstAD5293);
        unsigned short readADC5293();
        void powerDownmode();
        void writeAD5293(SPI_SELECT peSelect);
        void setAD5293Voltage(double);
    protected:
        IApplicationCardInterface *objAppcard;
        unsigned short GAINVALUE;
        double m_nVoltage;
};
#endif // AD5293_H
