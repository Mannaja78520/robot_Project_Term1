#include "Robot.h"

/** Usage External Class */
Robot Robot;

boolean carCheck(float distance){
  return (Robot.UltraSonic() > distance); 
}

void drop(){
  Robot.servo1.write(100);
  delay(100);
}

void setup(){
  Serial.begin(115200);
  Robot.init();
  while(carCheck(35)){
    Robot.Move(255);
  }
  Robot.MovePower(0);
  drop();
}

void loop(){

}
