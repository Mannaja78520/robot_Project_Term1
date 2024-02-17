#ifndef Controller_h
#define Controller_h

class Controller {
  public:
    double Kp, Ki, Kd, Kf, Setpoint, Error, LastError;
    double Dt, Integral, LastTime;
    Controller(float, float, float, float);
    void setPIDF(float, float, float, float);
    double Calculate(int, int);
    double Calculate(int);
};

#endif
