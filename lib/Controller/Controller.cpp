#include "Controller.h"

Controller::Controller(float Kp, float Ki, float Kd, float Kf) {
  this->Kp = Kp;
  this->Ki = Ki;
  this->Kd = Kd;
  this->Kf = Kf;
  Setpoint = Dt = Error = Integral = LastTime = LastError = 0;        
}

void Controller::setPIDF(float Kp, float Ki, float Kd, float Kf) {
  this->Kp = Kp;
  this->Ki = Ki;
  this->Kd = Kd;
  this->Kf = Kf;
}

float Controller::Calculate(int setpoint, int measure){
  Setpoint = setpoint;
  return Calculate(setpoint - measure);
}

float Controller::Calculate(int error){
  CurrentTime = millis() / 1000.00;
  Dt = CurrentTime - LastTime;
  LastTime = CurrentTime;
  Error = error;
  Integral += Error * Dt;
  Integral = constrain(Integral, -150, 150);
 if (error == 0) Integral = 0;
  float Derivative = (Error - LastError) / Dt;
  LastError = Error;
  return Kp * Error + Ki * Integral + Kd * Derivative;
}
