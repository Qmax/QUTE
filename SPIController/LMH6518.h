#ifndef LMH6518_H
#define LMH6518_H

#include <appcardcomponents.h>
#include <ApplicationCardInterface.h>
#include <qmap.h>

using namespace APPCARD_DETAILS;
using namespace PT_APPCARD_FUNCTIONAL_MODULES;
struct LMH6518Data{
    double m_sOutput;
    double m_sFullScaleADC;
};

class LMH6518:public QObject
{
   Q_OBJECT
  // Q_INTERFACES(ILMH6518)
public:
   LMH6518(IApplicationCardInterface *IAppCard)
   {
       objAppcard=IAppCard;
       m_nVoltperDivisionarray[0] = 20/1000.0;
       m_nVoltperDivisionarray[1] = 50/1000.0;
       m_nVoltperDivisionarray[2] = 100/1000.0;
       m_nVoltperDivisionarray[3] = 200/1000.0;
       m_nVoltperDivisionarray[4] = 500/1000.0;
       m_nVoltperDivisionarray[5] = 1.0;
       m_nVoltperDivisionarray[6] = 2.0;
       m_nVoltperDivisionarray[7] = 5.0;
       m_nVoltperDivisionarray[8] = 10.0;

       m_mapLAD.insert(0,ZERO_ATTENUATION);
       m_mapLAD.insert(-2,MINUS2_ATTENUATION);
       m_mapLAD.insert(-4,MINUS4_ATTENUATION);
       m_mapLAD.insert(-6,MINUS6_ATTENUATION);
       m_mapLAD.insert(-8,MINUS8ATTENUATION);
       m_mapLAD.insert(-10,MINUS10_ATTENUATION);
       m_mapLAD.insert(-12,MINUS12_ATTENUATION);
       m_mapLAD.insert(-14,MINUS14_ATTENUATION);
       m_mapLAD.insert(-16,MINUS16_ATTENUATION);
       m_mapLAD.insert(-18,MINUS18_ATTENUATION);
       m_mapLAD.insert(-20,MINUS20_ATTENUATION);

       m_nFPAttenuation=1;

   }

   double getVoltPerDivision(int index) const
   {
	   return m_nVoltperDivisionarray[index];
   }
   bool getPreAmp() const
   {
	   return m_nHGorLG;
   }
   unsigned short getFPAttennation() const
   {
	   return m_nFPAttenuation;
   }
   LM6518_LADDER_ATTENUATION getLadderAtteunator()
   {
	   return m_mapLAD.value(m_nLadderAttuenator);
   }
   double getSignalGain() const
   {
	   return m_nGSignalGain;
   }

   double getLadderAtteunator(int) const
   {
	   return m_nLadderAttuenator;
   }
   void configureLMH6518CW(CHANNELS_SELECTION eCHSelect);
   void configureLMH6518DW(LMH6518_DataTemplate);
   unsigned int ReadLM6518(LMH6518_DataTemplate);
   void calculateSignalPathGain(VOLTAGEPERDIVISION pEVoltageSelect);
   LMH6518Data calculateGain();
protected:   
   IApplicationCardInterface *objAppcard;
   LMH6518Data Data;
   unsigned short m_nFPAttenuation;
   double m_nKSignalPathGain;
   double m_nGSignalGain;
   bool m_nHGorLG;
   double m_nLadderAttuenator;
   double m_nAttuenation;
   double m_nOutput;
   double m_nFSADC;
   double m_nVoltperDivisionarray[9];
   QMap<double,LM6518_LADDER_ATTENUATION> m_mapLAD;

};

#endif // LMH6518_H
