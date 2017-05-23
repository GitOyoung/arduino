

#ifndef __CAR_H_
#define __CAR_H_

#include <Servo.h>
#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
//#include "pins_arduino.h"

#include <inttypes.h>

#include "motor.h"
#include "sensor.h"


class Car
{
public:
  Car();

  void linkMotor();

  void linkSensors();

  void linkServo();

  void forward(unsigned char speed);    

  void back(unsigned char speed);

  void turnLeft(unsigned char speed) ;

  void turnRight(unsigned char speed) ;
  
  void leftForward(unsigned char speed);
  
  void rightForward(unsigned char speed);
  
  void leftBack(unsigned char speed);
  
  void rightBack(unsigned char speed);
  
  int readInfraredL1();


  int readInfraredL2(); 


  int readInfraredR1();


  int readInfraredR2(); 


  long distance(); 

  void rotateServo(int degree);  


  void forward(unsigned char speed,int ms) {      //时间毫秒       
    forward(speed);
    if(ms > 0) delay(ms);       
  }

  void back(unsigned char speed, int ms) {
    back(speed);
    if(ms > 0) delay(ms);
  }

  void turnLeft(unsigned char speed, int ms) {
    turnLeft(speed);
    if(ms > 0) delay(ms);
  }
  void turnRight(unsigned char speed, int ms) {
    turnRight(speed);
    if(ms > 0) delay(ms);
  }
  
  void leftForward(unsigned char speed, int ms) {
    leftForward(speed);
    if(ms > 0) delay(ms);
  }
  
  void rightForward(unsigned char speed, int ms) {
    rightForward(speed);
    if(ms > 0) delay(ms);
  }
  
  void leftBack(unsigned char speed, int ms) {
    leftBack(speed);
    if(ms > 0) delay(ms);
  }
  
  void rightBack(unsigned char speed, int ms) {
    rightBack(speed);
    if(ms > 0) delay(ms);
  }



private:
  Motor L1;
  Motor L2;
  Motor R1;
  Motor R2;
  Sensor sensor;
  Servo servo;
};

#endif /*--------car.h--------*/

