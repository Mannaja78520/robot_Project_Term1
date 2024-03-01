#ifndef Robot_h
#define Robot_h

#include <Arduino.h>
#include <motor.h>

//MotorPin
#define motor0EnablePin 25
#define motor0Pin1      26
#define motor0Pin2      27
#define motor1EnablePin 19
#define motor1Pin1      22
#define motor1Pin2      23

//define sound speed in cm/uS
#define SOUND_SPEED 0.034

//SensorInfaratePin
#define leftSensorPin  34
#define rightSensorPin 32

//UltraSonic
#define trigPin 5
#define echoPin 18

class Robot{
  public:
    //SensorVariable
    int LS = 0;
    int RS = 0;
    int Distance;
    long Duration;

    void init();
    void motor(int, int);
    void MovePower(int, int);
    void InfarateSensor();
    float UltraSonic();
};
    
#endif
