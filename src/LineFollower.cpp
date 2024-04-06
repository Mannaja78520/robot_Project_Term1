#include <Robot.h>
#include <Controller.h>

/** Usage External Class */
Robot r;

void LineFollower(int NormalSpeed,float CenterBlack, float OuterBlackLeft, int BlackReadTime, float P, float I, float D) {
  int blackCount = 0;
  float maxBlack = 2.3;
  float SetpointTime = millis()/1000.0;
  Controller c(P, I, D, 0);
  c.LastTime = millis()/1000.0;

  r.MovePower(255, 255);
  delay(20);
  while (1) {
    float CurrentTime = millis()/1000.0;
    r.InfarateSensor();
    
    if ((r.LLS > OuterBlackLeft && (r.LS > CenterBlack && r.LS < maxBlack) && (r.RS > CenterBlack && r.RS < maxBlack)) && (CurrentTime - SetpointTime) > BlackReadTime){
      SetpointTime = CurrentTime; 
      r.MovePower(180, 180);
      delay(120);
      r.MovePower(0, 0);
      delay(1000);
      break;
      // r.MovePower(200, 200);
    }
    
    float error = (r.LS - r.RS) + ((r.RRS - r.LLS) * 2);
    int R  = c.Calculate(error);

    int LSpeed = NormalSpeed + R;
    int RSpeed = NormalSpeed - R;

    Serial.print("Left  : ");
    Serial.println(LSpeed);
    Serial.print("Right : ");
    Serial.println(RSpeed);
    Serial.println(blackCount);
    Serial.println(error);
    Serial.println("");
    // delay(1000);

    r.MovePower(LSpeed, RSpeed);
  }
  r.MovePower(0, 0);
  delay(100);
}

void TurnLeft(float blackSetpoint,float centerBlack, int NormalSpeed){
r.MovePower(0, 255);
delay(300);
r.InfarateSensor();
while(r.LLS > blackSetpoint && r.LS > centerBlack) {
  r.InfarateSensor();
  r.MovePower(0, NormalSpeed);
  }
  r.MovePower(0, 0);
  delay(100);
}

void Wait() {
  while (1) {
    delay(300);
    float cm = r.Ultrasonic();
    Serial.println(cm);
    // LineFollower(0, 0, 0, 0);
    if (cm > 0 && cm < 12) break;
  }
}

void setup() {
  Serial.begin(115200);
  r.init();
  // Wait();
  LineFollower(180, 0.21, 1.43, 35, 15.4, 0.4, 0.7);
  LineFollower(180, 0.21, 1.43, 3, 15.4, 0.3, 0.7);
  TurnLeft(1.2, 0.135, 135);
  LineFollower(110, 0.21, 1.43, 3, 15.4, 0.3, 0.7);
  TurnLeft(1.2, 0.135, 135);
  LineFollower(180, 0.26, 1.68, 3, 16.5, 0.5, 1.3);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               

}

void loop() {
  r.InfarateSensor();
  delay(300);

}