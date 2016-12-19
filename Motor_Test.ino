// Adafruit Motor shield library
// copyright Adafruit Industries LLC, 2009
// this code is public domain, enjoy!

#include <AFMotor.h>

AF_DCMotor motor(3);
AF_DCMotor motor2(4);
AF_DCMotor motor3(1);
void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Motor test!");

  // turn on motor
  motor.setSpeed(200);
  motor3.setSpeed(200);
  motor2.setSpeed(200);
  motor2.run(RELEASE);
  motor.run(RELEASE);  
  motor3.run(RELEASE);
}

void loop() {
  uint8_t i;
  
  Serial.print("tick");
  /*
  motor.run(FORWARD);
  for (i=0; i<255; i++) {
    motor.setSpeed(i);  
    delay(10);
 }
 
  for (i=255; i!=0; i--) {
    motor.setSpeed(i);  
    delay(10);
 }
  
  Serial.print("tock");

  motor.run(BACKWARD);
  for (i=0; i<255; i++) {
    motor.setSpeed(i);  
    delay(10);
 }
 
  for (i=255; i!=0; i--) {
    motor.setSpeed(i);  
    delay(10);
 }
  */
motor.run(FORWARD);
motor2.run(FORWARD);
motor3.run(FORWARD);
motor.setSpeed(150);
motor2.setSpeed(150);
motor3.setSpeed(150);
delay(2000);
  Serial.print("tech");
  motor.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  delay(4000);
}
