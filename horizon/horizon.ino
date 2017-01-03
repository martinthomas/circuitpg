// Horizon - Light up neoPixels to show tilt on y axis
// something like artificial horizon in cockpit
 
#include <Adafruit_CircuitPlayground.h>
#define SPACES 12 // 10 leds with space at top centre, bottom centre
#define INTERVAL 75

float g = 9.81;
float band = g*2;
float gap = band/SPACES;

int getAngle()
{
  float accel = CircuitPlayground.motionY();
  //  Serial.print("Accel: ");
  //  Serial.println(accel);
  int pos = floor((g+accel)/gap);
  // Serial.println(pos);
  if (pos > SPACES)
    pos = pos - SPACES;
  return pos;
}
void lightPos(int pos, int r, int g, int b)
{ // cope with missing led at bottom and top.
  // led positions are counted from centre usb, counterclockwise
  
  int led = 0;
  if(pos >=0 && pos <6) //first band
    led = pos - 1;  // led 0 is at pos 1
    else 
    led = pos - 2;
  // Serial.println(led); // led 5 is at pos 7
  if (pos != 6 && pos != 0) 
    CircuitPlayground.setPixelColor(led, r,g,b);
}

void setup() {
  // Initialize serial port and circuit playground library.
  // Serial.begin(115200);
  // Serial.println("Artificial horizon indicator");
  CircuitPlayground.begin();
  CircuitPlayground.clearPixels();
}

void loop() {
  delay(INTERVAL);

  CircuitPlayground.clearPixels();
  int pos = getAngle();
  // red neighbors
  lightPos(pos-1, 255,0,0);
  lightPos(pos+1, 255,0,0);
  // blue central pos
  lightPos(pos,   0,0,255);
}
