#include <Servo.h>


#include <ros.h>
#include <arduino/Carsrv.h>

#include "car.h"
#include <string.h>


Car car;

const char* readLine(const char *src, char *desc);
bool split(const char *src, char sp, char *name, char *value);


typedef arduino::Carsrv Carsrv;
void callback(const Carsrv::Request& req, Carsrv::Response& res) {
  const char *pHead = req.params;
  char dataBuffer[64];
  char paramName[32];
  char paramValue[64];
  if(strcmp(req.command, "Go")) {// Go command, drive the motor
    int direction = 0; // 0x00-stop, 0x01-front, 0x02-back, 0x04-left, 0x08-right
    int speed = 0; //0 - 255
    int duration = 0; // unit: ms, -1-> unlimited 
    while(pHead = readLine(pHead, dataBuffer)) {
      if(split(dataBuffer, ':', paramName, paramValue)) {
        if(strcmp(paramName, "direction")) {
          direction = atoi(paramValue);
        }
        if(strcmp(paramName, "speed")) {
          speed = atoi(paramValue);
        }
        if(strcmp(paramName, "duration")) {
          duration = atoi(paramValue);
        }
      }
      
    }
    
    if(direction & 0x01) { //front
      if(direction & 0x04) { //left-front
        car.leftForward(speed, duration);
      } else if(direction & 0x08) { //right-front
        car.rightForward(speed, duration);
      } else {
        car.forward(speed, duration);
      }
    } else if(direction & 0x02) { //back
      if(direction & 0x04) { //left-front
        car.leftBack(speed, duration);
      } else if(direction & 0x08) { //right-front
        car.rightBack(speed, duration);
      } else {
        car.back(speed, duration);
      }
    } else {
      if(direction & 0x04) { //left-front
        car.turnLeft(speed, duration);
      } else if(direction & 0x08) { //right-front
        car.turnRight(speed, duration);
      }
    }
    
  } else if(strcmp(req.command, "Get")) { //et command, get sensor parameters
    
  }
}

ros::NodeHandle nh;
ros::ServiceServer<Carsrv::Request, Carsrv::Response> server("carsrv", callback);


void setup() {

  car.linkMotor();
  car.linkSensors();

  nh.initNode();
  nh.advertiseService(server);
}


void loop() {

}


const char *readLine(const char *src, char *desc)
{
  const char *line = strstr(src, "\r\n");
  if(line) {
    int len = line - src;
    strncpy(desc, src, len);
    desc[len] = '\0';
  }
  
  return line ? line + 2 : 0;
}

bool split(const char *src, char sp, char *name, char *value)
{
  const char *found = strchr(src, sp);
  if(found) {
    int nameLength =  found - src;
    strncpy(name, src, nameLength);
    name[nameLength] = '\0';
    strcpy(value, found + 1);
  }
  
  return found;
}

