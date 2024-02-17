#include "Robot.h"
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

double Controller::Calculate(int setpoint, int measure){
  Setpoint = setpoint;
  return Calculate(setpoint - measure);
}

double Controller::Calculate(int error){
  float CurrentTime = millis() / 1000.00;
  Dt = CurrentTime - LastTime;
  LastTime = CurrentTime;
  Error = error;
  Integral += Error * Dt;
  Integral = constrain(Integral, -255, 255);
//  if (error == 0) integral = 0;
  double Derivative = (Error - LastError) / Dt;
  LastError = Error;
  return Kp * Error + Ki * Integral + Kd * Derivative;
}
