#include "Robot.h"
#include "Controller.h"

/** Usage External Class */
Robot Robot;

//Variable
int LS, RS;

void LineFollower(int setpoint){
  while(LS <= setpoint && RS <= setpoint){
    LS, RS = Robot.InfarateSensor();
    double R = Controller(1.6, 0.01, 0.01, 0).Calculate(LS - RS);
    Robot.MovePower(200 - R, 200 + R);
  }
}

void Wait(float distance){
  while(Robot.UltraSonic() > distance) continue;
}

void setup(){
  Serial.begin(115200);
  Robot.init();
  Wait(14.00);
  LineFollower(200);
}

void loop(){
  LS, RS = Robot.InfarateSensor();
//  Serial.print("LeftSensor:  ");
//  Serial.println(Robot.LS);
//  Serial.print("rightSensor: ");
//  Serial.println(Robot.RS);
  
//  Robot.MovePower(255, 255);
}
