#ifndef __SENSOR_H_
#define __SENSOR_H_

#include "infraredSensor.h"
#include "soundWavesSensor.h"

class Sensor
{
public:
    Sensor(){}
   
    
    void linkInfrared() {   //连接红外传感器
       L1.link(A0);
       L2.link(A1);
       R1.link(A2);
       R2.link(A3);
        
    }

    int readInfraredL1(){

        return L1.readValue();
      }
      
    int readInfraredL2(){

        return L2.readValue();
      }


     int readInfraredR1(){

        return R1.readValue();
      }

     int readInfraredR2(){

        return R2.readValue();
      }

    void linkSoundWavesSensor(){   //连接声波传感器
          soundWS.link();
      }

    long readSoundWavesDistance(){    // cm
          return soundWS.readDistance();
      }  

    
    
     
private:
    InfraredSensor L1;
    InfraredSensor L2;
    InfraredSensor R1;
    InfraredSensor R2;

    SoundWavesSensor soundWS;
};

#endif /*--------sensor.h--------*/
