#include "Robot.h"
#include "Controller.h"

/** Usage External Class */
Robot Robot;

void LineFollower(int setpoint){
  while(Robot.LS >= setpoint && Robot.RS >= setpoint){
    Robot.InfarateSensor();
    int R = Controller(1.6, 0.01, 0.01, 0).Calculate(Robot.LS - Robot.RS);
    Robot.MovePower(200 - R, 200 + R);
  }
}

void Wait(float distance){
  while(Robot.UltraSonic() > distance) continue;
}

void setup(){
  Serial.begin(115200);
  Robot.init();
  // pinMode(trigPin, OUTPUT);
  // pinMode(echoPin, INPUT); 
  // Wait(14.00);
  LineFollower(1);
}

void loop(){
//  Robot.InfarateSensor();
//  Serial.print("LeftSensor:  ");
//  Serial.println(Robot.LS);
//  Serial.print("rightSensor: ");
//  Serial.println(Robot.RS);
//  delay(1000);
  
//  Robot.MovePower(255, 255);
//  delay(1000);
//  Robot.MovePower(-255, -255);
//  delay(1000);
}
