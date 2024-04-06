#include <Robot.h>

/** Usage External Class */
Robot r;

int pingCount = 0;

boolean carCheck(float distance){
  float cm = r.Ultrasonic();
  Serial.println(cm);
  pingCount = (cm < distance && cm > 0) ? pingCount+1 : 0;
  return (pingCount < 30);
}

void drop(){
  servo.write(0);
  delay(1000);
}

void setup(){
  Serial.begin(115200);
  ultrasonic1.read();
  ESP32PWM::allocateTimer(0);
  ESP32PWM::allocateTimer(1);
  ESP32PWM::allocateTimer(2);
  ESP32PWM::allocateTimer(3);
  servo.setPeriodHertz(50);
  servo.attach(servoPin, 500, 2400);
  servo.write(42);
  delay(500);

  // while(1) Serial.println(r.Ultrasonic());
  
  while(carCheck(25)) r.MovePower(96);
  r.MovePower(96);
  delay(210);
  r.MovePower(0);
  delay(500);
  drop();
}

void loop(){
  r.MovePower(0);
  delay(1000);
}