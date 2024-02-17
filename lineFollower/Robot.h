#ifndef Robot_h
#define Robot_h

#include <Arduino.h>

class Robot{
  public:
    //MotorPin
    int motor1EnablePin = 25;
    int motor1Pin1      = 26;
    int motor1Pin2      = 27;
    int motor2EnablePin =  1;
    int motor2Pin1      = 22;
    int motor2Pin2      = 23;

    //SensorInfaratePin
    const int leftSensorPin   = 34;
    const int rightSensorPin  = 35;
    
    //UltraSonic
    const int trigPin = 5;
    const int echoPin = 18;

    //SensorVariable
    int LS = 0;
    int RS = 0;
    int Distance;
    long Duration;

    //define sound speed in cm/uS
    #define SOUND_SPEED 0.034
    
    void init();
    void motor(int, int);
    void MovePower(int, int);
    int InfarateSensor();
    float UltraSonic();
};
    
#endif
