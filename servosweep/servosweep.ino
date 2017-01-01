#include <Adafruit_CircuitPlayground.h>
#include <Adafruit_SleepyDog.h>
#include <Servo.h>
Servo servo;

int pos0 = 19; // pos0 is start
int pos180 = 170; // pos180 is end

int pause = 10;

void setup() {
  // put your setup code here, to run once:
  CircuitPlayground.begin(30); // pass in the initial brightness for the lights
      servo.attach(6);
    servo.write(pos0);
}

void loop() {
  while (!CircuitPlayground.slideSwitch()) {
    // Turn off the pixels, then go into deep sleep for a second.
    CircuitPlayground.clearPixels();
    Watchdog.sleep(1000);
    delay(100);
  }

  for(int idx =pos0; idx < pos180; idx++) // idx = idx +1
  {
    servo.write(idx);
    delay(pause);
  }
  for(int idx =pos180; idx >pos0 ; idx--)
  {
    servo.write(idx);
    delay(pause);
  }
}
