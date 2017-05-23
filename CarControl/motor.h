#ifndef __MOTOR_H_
#define __MOTOR_H_

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif
//#include "pins_arduino.h"

#include <inttypes.h>

class Motor
{
public:
    Motor();
    Motor(int l, int p);
    
    void link(int l, int p);
    
    void forward(unsigned char speed);
    
    void back(unsigned char speed);
     
private:
    int level;
    int pwm; 
};

#endif /*--------motor.h--------*/
