#ifndef __INFRAREDSENSOR_H_
#define __INFRAREDSENSOR_H_

class InfraredSensor
{
public:
    InfraredSensor(){}
   
    void link(int a) {
        
        analog = a;
    }
    
   int readValue(){
      return analogRead(analog);
    }
     
private:
    int analog ;      //50~978  常态50左右  遇到障碍 978左右(目测检查距离十多厘米);
   
};

#endif /*--------infraredSensor.h--------*/
