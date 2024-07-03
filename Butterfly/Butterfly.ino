#include <Adafruit_NeoPixel.h>
// #include <Array.h>

#define LED_PIN      4
#define LED_COUNT    548


Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_KHZ800 + NEO_GRB);

void setup() {
  strip.begin();
  strip.clear();
}

int th = 0;
void loop() {
  RainbowTest(10);
//  th = th - 2;
//  if (th <= 0) {
//    th = 360;
//  }
}

//----------Define General Use Functions Below----------



//----------Define Modes Below----------

void RainbowTest(int wait) {
  int numgroups = LED_COUNT/12;
  for(int g=0; g<numgroups; g++) {
    strip.setPixelColor(g*12+0, 11, 0, 0);
    strip.setPixelColor(g*12+1, 11, 0, 0);
    strip.setPixelColor(g*12+2, 11, 0, 11);
    strip.setPixelColor(g*12+3, 11, 0, 11);
    strip.setPixelColor(g*12+4, 0, 0, 11);
    strip.setPixelColor(g*12+5, 0, 0, 11);
    strip.setPixelColor(g*12+6, 0, 11, 11);
    strip.setPixelColor(g*12+7, 0, 11, 11);
    strip.setPixelColor(g*12+8, 0, 11, 0);
    strip.setPixelColor(g*12+9, 0, 11, 0);
    strip.setPixelColor(g*12+10, 11, 11, 0);
    strip.setPixelColor(g*12+11, 11, 11, 0);
  }

  strip.show();
  delay(wait);
}
