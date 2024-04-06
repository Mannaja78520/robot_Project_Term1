#ifndef Robot_h
#define Robot_h

#include <Arduino.h>
#include <Ultrasonic.h>
#include <ESP32Servo.h> 
#include <motor.h>

//MotorPin
#define motor0EnablePin 25
#define motor0Pin1      27
#define motor0Pin2      26
#define motor1EnablePin 19
#define motor1Pin1      22
#define motor1Pin2      23

Motor LM(20000, 8, 0, motor0EnablePin, motor0Pin1, motor0Pin2);
Motor RM(20000, 8, 0, motor1EnablePin, motor1Pin1, motor1Pin2);

// Servo
#define servoPin 14
Servo servo;

//SensorInfaratePin
#define leftSensorPin        14
#define centerLeftSensorPin  12
#define centerRightSensorPin 32
#define rightSensorPin       35

//UltraSonic
byte trigPin = 5;
byte echoPin = 18;

// Ultrasonic
Ultrasonic ultrasonic1(trigPin, echoPin);

class Robot{

  public:
    //SensorVariable
    float LLS;
    float LS;
    float RS;
    float RRS;
    float Distance;
    long Duration;

    void init(){
      pinMode(leftSensorPin, INPUT);
      pinMode(centerLeftSensorPin, INPUT);
      pinMode(centerRightSensorPin, INPUT);
      pinMode(rightSensorPin, INPUT);
      
      ultrasonic1.read();
      delay(100);
    }
    
    void MovePower(int motor0Speed, int motor1Speed){
      int maxSpeed = 220;
      motor0Speed = motor0Speed > maxSpeed ? maxSpeed : (motor0Speed < -maxSpeed ? -maxSpeed : motor0Speed);
      motor1Speed = motor1Speed > maxSpeed ? maxSpeed : (motor1Speed < -maxSpeed ? -maxSpeed : motor1Speed);
      LM.spin(motor0Speed);
      RM.spin(motor1Speed);
    }

    void MovePower(int Speed){
      LM.spin(Speed);
    }

    void InfarateSensor(){
      LLS = analogRead(leftSensorPin)/100.0;
      LS  = analogRead(centerLeftSensorPin)/1000.0;
      RS  = analogRead(centerRightSensorPin)/1000.0;
      RRS = analogRead(rightSensorPin)/100.0;
      Serial.print("LeftSensor:  ");
      Serial.println(LLS);
      Serial.print("centerLeftSensor: ");
      Serial.println(LS);
      Serial.print("centerRightSensor:  ");
      Serial.println(RS);
      Serial.print("rightSensor: ");
      Serial.println(RRS);
      Serial.println(" ");
      // delay(300);
    }

    float Ultrasonic(){
      return ultrasonic1.read();
    }
};
    
#endif