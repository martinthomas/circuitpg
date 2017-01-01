#include <Adafruit_CircuitPlayground.h>
#include <Adafruit_SleepyDog.h>
#include <Servo.h>
Servo servo;
int pos = 50;
int pause = 10;
void setup() {
  // put your setup code here, to run once:
  CircuitPlayground.begin(30); // pass in the initial brightness for the lights
      Serial.begin(9600);
      delay(50);
      servo.attach(6);
      servo.write(19);
}

void loop() {
 Serial.println(servo.read());
 delay(250);
}
