#ifndef Controller_h
#define Controller_h

#include <Arduino.h>

class Controller {
  public:
    float CurrentTime;
    float Kp, Ki, Kd, Kf, Setpoint, Error, LastError;
    float Dt, Integral, LastTime;
    Controller(float, float, float, float);
    void setPIDF(float, float, float, float);
    float Calculate(int, int);
    float Calculate(int);
};

#endif
