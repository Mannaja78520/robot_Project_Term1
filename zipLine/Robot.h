#ifndef Robot_h
#define Robot_h

#include <Arduino.h>
#include <MobaTools.h>

class Robot{
  public:
    //MotorPin
    int motorEnablePin = 25;
    int motorPin1      = 26;
    int motorPin2      = 27;

    // Servo
    static const int servoPin = 4;
    MoToServo servo1;

    //UltraSonic
    const int trigPin = 5;
    const int echoPin = 18;

    //SensorVariable
    int Distance;
    long Duration;

    //define sound speed in cm/uS
    #define SOUND_SPEED 0.034
    
    void init();
    void MovePower(int);
    float UltraSonic();
};
    
#endif
