#ifndef __SOUNDWAVESSENSOR_H_
#define __SOUNDWAVESSENSOR_H_

#include "SR04.h"
#define TRIG_PIN 12
#define ECHO_PIN 13


class SoundWavesSensor
{
public:
    SoundWavesSensor(): sr04(ECHO_PIN,TRIG_PIN) {}
   
    void link() {
        
//       sr04 = SR04(TRIG_PIN,ECHO_PIN);
    }
    
   long readDistance(){      // * cm      
      return sr04.Distance();
   }
     
private:
    SR04 sr04;
   
};

#endif /*--------soundWavesSensor.h--------*/
