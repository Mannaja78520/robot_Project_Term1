#include "Robot.h"
#include "Controller.h"

void Robot::init(){
  pinMode(motor1EnablePin, OUTPUT); 
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2EnablePin, OUTPUT);  
  pinMode(motor2Pin1, OUTPUT); 
  pinMode(motor2Pin2, OUTPUT);
  
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);
 }

 void Robot::motor(int m, int sp){
  int enablePin = m == 1 ? motor1EnablePin : m == 2 ? motor2EnablePin : 0;
  int motorPin1 = m == 1 ? motor1Pin1 : m == 2 ? motor2Pin1 : 0; 
  int motorPin2 = m == 1 ? motor1Pin2 : m == 2 ? motor2Pin2 : 0;
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

 void Robot::MovePower(int motor1Speed, int motor2Speed){
  motor(1, motor1Speed);
  motor(2, motor2Speed);
 }

 int Robot::InfarateSensor(){
  LS = analogRead(leftSensorPin);
  RS = analogRead(rightSensorPin);
  return LS, RS;
 }

 float Robot::UltraSonic(){
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  Duration = pulseIn(echoPin, HIGH);
  Distance = Duration * SOUND_SPEED/2;
  return Distance;
}
