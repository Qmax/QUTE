/*
 * WaveDataClass.h
 *
 *  Created on: 20-Aug-2014
 *      Author: Ravivarman,Qmax
 */
#include <QDebug>

#ifndef WAVEDATACLASS_H_
#define WAVEDATACLASS_H_

class WaveDataClass{
public:
        int getSamples(int waveNo){
            return wd_Samples[waveNo];
	}
        void setSamples(int waveNo,int waveData){
            wd_Samples[waveNo]=waveData;
            qDebug()<<"Wave Number:"<<waveNo<<"Samples:"<<waveData;
	}
        int getStartTick(int waveNo){
            return wd_StartTick[waveNo];
	}
        void setStartTick(int waveNo,int waveData){
            wd_StartTick[waveNo]=waveData;
            qDebug()<<"Wave Number:"<<waveNo<<"Start Tick:"<<waveData;
	}
        int getStopTick(int waveNo){
            return wd_StopTick[waveNo];
	}
        void setStopTick(int waveNo,int waveData){
            wd_StopTick[waveNo]=waveData;
            qDebug()<<"Wave Number:"<<waveNo<<"Stop Tick:"<<waveData;
	}
        int getDutyCycles(int waveNo){
            return wd_DutyCycles[waveNo];
	}
        void setDutyCycles(int waveNo,int waveData){
            wd_DutyCycles[waveNo]=waveData;
            qDebug()<<"Wave Number:"<<waveNo<<"Duty Cycles:"<<waveData;
	}

protected:
        int wd_Samples[6],wd_StartTick[6],wd_StopTick[6],wd_DutyCycles[6];
};
#endif /* WAVEDATACLASS_H_ */
