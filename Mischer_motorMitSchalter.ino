#include "Grove_I2C_Motor_Driver.h"

#define I2C_ADDRESS 0x0f
#define TasterPin 5

void setup() {
Serial.begin(9600);
Motor.begin(I2C_ADDRESS);
pinMode(5, INPUT);
}

void loop() {
  int sig = digitalRead(TasterPin);
  Serial.println(sig);
  Serial.println(sig);

  if(sig = 1) {
    Serial.println("motor dreht");
    Motor.speed(MOTOR1, 1000);
    Motor.speed(MOTOR2, 1000);
    delay(2000);
    Motor.stop(MOTOR1);
    Motor.stop(MOTOR2);
    delay(2000);
  }
  delay(100);
}