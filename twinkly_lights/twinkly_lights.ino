#include <Adafruit_CircuitPlayground.h>
#include <Adafruit_SleepyDog.h>
#include <Servo.h>
Servo servo;
int pos = 15;
int pause = 200;
void setup() {
  // put your setup code here, to run once:
  CircuitPlayground.begin(30); // pass in the initial brightness for the lights
      servo.attach(6);
    servo.write(pos);
}

void loop() {
  while (!CircuitPlayground.slideSwitch()) {
    // Turn off the pixels, then go into deep sleep for a second.
    CircuitPlayground.clearPixels();
    Watchdog.sleep(1000);
    delay(100);
  }

  for(int idx =0; idx < 180; idx++)
  {
    servo.write(pos+idx);
    delay(pause);
  }
  for(int idx =180; idx >0 ; idx--)
  {
    servo.write(pos+idx);
    delay(pause);
  }
}
