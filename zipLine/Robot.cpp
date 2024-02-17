#include "Robot.h"

void Robot::init(){
  pinMode(motorEnablePin, OUTPUT); 
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);
  
  servo1.attach(servoPin);
  servo1.write(0);
  delay(100);
 }

 void Robot::MovePower(int sp){
  int enablePin = motorEnablePin;
  int motorPin1 = motorPin1; 
  int motorPin2 = motorPin2;
  int writeMotor1 = LOW, writeMotor2 = LOW; 
  if (sp > 0){
    writeMotor1 = HIGH;
    writeMotor2 = LOW;
  }
  if (sp < 0){
    writeMotor1 = LOW;
    writeMotor2 = HIGH;
  }
  digitalWrite(motorPin1, writeMotor1);
  digitalWrite(motorPin2, writeMotor2);
  analogWrite(enablePin, sp);
 }

 float Robot::UltraSonic(){
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  Duration = pulseIn(echoPin, HIGH);
  Distance = Duration * SOUND_SPEED/2;
  return Distance;
}
