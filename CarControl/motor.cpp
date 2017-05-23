#include "motor.h"

Motor::Motor(): Motor(0, 0) {}
Motor::Motor(int l, int p)
: level(l), pwm(p) {
    
}

void Motor::link(int l, int p) {
    level = l;
    pinMode(level,OUTPUT);
    pwm = p;
    pinMode(pwm,OUTPUT);    
}

void Motor::forward(unsigned char speed) {   
    digitalWrite(level, LOW);
    analogWrite(pwm, speed);
}

void Motor::back(unsigned char speed) {
    digitalWrite(level, HIGH);
    analogWrite(pwm, 255 - speed);
}
