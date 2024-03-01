#include "Robot.h"
#include "Controller.h"

Motor LM(20000, 8, 0, motor0EnablePin, motor0Pin1, motor0Pin2);
Motor RM(20000, 8, 0, motor1EnablePin, motor1Pin1, motor1Pin2);

void Robot::init(){
  pinMode(leftSensorPin, INPUT);
  pinMode(rightSensorPin, INPUT);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
 }

 void Robot::MovePower(int motor1Speed, int motor2Speed){
  LM.spin(motor1Speed);
  RM.spin(motor2Speed);
 }

 void Robot::InfarateSensor(){
  LS = analogRead(leftSensorPin);
  RS = analogRead(rightSensorPin);
 }

 float Robot::UltraSonic(){
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  Duration = pulseIn(echoPin, HIGH);
  Distance = Duration * SOUND_SPEED/2;
  return Distance;
}
