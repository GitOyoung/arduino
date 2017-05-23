#include "car.h"

Car::Car() {
}

void Car::linkMotor() {
  L1.link(8,9);//第一个参数接黑线的引脚, 第二个参数接红线的脚
  L2.link(7,6);
  R1.link(2,3);
  R2.link(4,5);

}

void Car::linkSensors(){

  sensor.linkInfrared();
  sensor.linkSoundWavesSensor();
}

void Car::linkServo(){

  servo.attach(10);
}  

void Car::forward(unsigned char speed) {       
  L1.forward(speed);
  L2.forward(speed);
  R1.forward(speed);
  R2.forward(speed);        
}
void Car::back(unsigned char speed) {
  L1.back(speed);
  L2.back(speed);
  R1.back(speed);
  R2.back(speed);
}


void Car::turnLeft(unsigned char speed) {
  L1.back(speed);
  L2.back(speed);
  R1.forward(speed);
  R2.forward(speed);
}

void Car::turnRight(unsigned char speed) {
  L1.forward(speed);
  L2.forward(speed);
  R1.back(speed);
  R2.back(speed);
}

void Car::leftForward(unsigned char speed) {
  L1.forward(0);
  L2.forward(0);
  R1.forward(speed);
  R2.forward(speed);
}

void Car::rightForward(unsigned char speed) {
  L1.forward(speed);
  L2.forward(speed);
  R1.forward(0);
  R2.forward(0);
}

void Car::leftBack(unsigned char speed) {
  L1.back(0);
  L2.back(0);
  R1.back(speed);
  R2.back(speed);
}

void Car::rightBack(unsigned char speed) {
  L1.back(speed);
  L2.back(speed);
  R1.back(0);
  R2.back(0);
}


int Car::readInfraredL1(){
  return sensor.readInfraredL1();
}


int Car::readInfraredL2(){
  return sensor.readInfraredL2();
}

int Car::readInfraredR1() {      
  return sensor.readInfraredR1();
}

int Car::readInfraredR2()  {      
  return sensor.readInfraredR2();
} 

long Car::distance()  {    // cm
  return sensor.readSoundWavesDistance();
}

void Car::rotateServo(int degree) {   //0~179
  servo.write(degree);
} 





