#include <Adafruit_CircuitPlayground.h>
#include <Adafruit_SleepyDog.h>

#define NEIGH 25
#define NEXT 250
#define CLICKTHRESHHOLD 80

bool lights = false;
uint16_t lightLevel = 0;
void setup() {
  //while (!Serial);
    //Serial.begin(9600);    
  CircuitPlayground.begin();
  CircuitPlayground.setAccelRange(LIS3DH_RANGE_8_G); 
  CircuitPlayground.clearPixels();
  
  CircuitPlayground.setAccelTap(1, CLICKTHRESHHOLD);
  
  // have a procedure called when a tap is detected
  attachInterrupt(digitalPinToInterrupt(7), flipLight, FALLING);

}

void flipLight(void){
  lights=!lights;
}

void setbrightness(){
  lightLevel = CircuitPlayground.lightSensor();
  CircuitPlayground.setBrightness(10 + lightLevel/6); 
}

void loop() {
//  int sleepMS = Watchdog.sleep();

  while (!CircuitPlayground.slideSwitch()) {
    // Turn off the pixels, then go into deep sleep for a second.
    CircuitPlayground.clearPixels();
    Watchdog.sleep(1000);
  }
  
  for(uint8_t idx=0; idx < 10; idx++)
  {
    CircuitPlayground.clearPixels();
    if(lights)
    {
      setbrightness();
      for(uint8_t blue=0; blue < 5; blue++)
      {
        CircuitPlayground.setPixelColor(blue, 0, 0, 255);
        delay(NEIGH);      
      }
      delay(NEXT);
      CircuitPlayground.clearPixels();

      setbrightness();
      for(uint8_t red=5; red < 10; red++)
      {
        CircuitPlayground.setPixelColor(red, 255, 0, 0);
        delay(NEIGH);      
      }
      delay(NEXT);
    }
  }
}
