#include <Adafruit_NeoPixel.h>
// #include <Array.h>

#define LED_PIN      4
// #define LED_COUNT    548
#define LED_COUNT    133
#define LED_START    117
#define LED_ADD      16
// #define LED_COUNT    133


Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_KHZ800 + NEO_GRB);

void setup() {
  strip.begin();
  strip.clear();
}

int t = 0;
void loop() {
  // RainbowTest(100);
  // RainbowTest(100,t);
  LineTest(100);
  // KillLine(10);
 t = (t + 1)%LED_COUNT;
//  if (th <= 0) {
//    th = 360;
//  }
}

//----------Define General Use Functions Below----------



//----------Define Modes Below----------

void KillLine(int wait) {
  for(int p=0; p<LED_COUNT; p++) {
    strip.setPixelColor(p, 0, 0, 0);
  }
  strip.show();
  delay(wait);
}

void RainbowTest(int wait, int t) {
  int val = 5;
  int numgroups = LED_COUNT/12;
  for(int g=0; g<numgroups; g++) {
    strip.setPixelColor((g*12+0+t)%LED_COUNT, val, 0, 0);
    strip.setPixelColor((g*12+1+t)%LED_COUNT, val, 0, 0);
    strip.setPixelColor((g*12+2+t)%LED_COUNT, val, 0, val);
    strip.setPixelColor((g*12+3+t)%LED_COUNT, val, 0, val);
    strip.setPixelColor((g*12+4+t)%LED_COUNT, 0, 0, val);
    strip.setPixelColor((g*12+5+t)%LED_COUNT, 0, 0, val);
    strip.setPixelColor((g*12+6+t)%LED_COUNT, 0, val, val);
    strip.setPixelColor((g*12+7+t)%LED_COUNT, 0, val, val);
    strip.setPixelColor((g*12+8+t)%LED_COUNT, 0, val, 0);
    strip.setPixelColor((g*12+9+t)%LED_COUNT, 0, val, 0);
    strip.setPixelColor((g*12+10+t)%LED_COUNT, val, val, 0);
    strip.setPixelColor((g*12+11+t)%LED_COUNT, val, val, 0);
  }

  strip.show();
  delay(wait);
}

void LineTest(int wait) {
  int val = 5;
  for(int i=LED_START; i<LED_START+LED_ADD; i++) {
    strip.setPixelColor(i, val, val, val);
  }

  strip.show();
  delay(wait);
}

// void RainbowTest(int wait) {
//   int val = 5;
//   int numgroups = LED_COUNT/12;
//   for(int g=0; g<numgroups; g++) {
//     strip.setPixelColor(g*12+0, val, 0, 0);
//     strip.setPixelColor(g*12+1, val, 0, 0);
//     strip.setPixelColor(g*12+2, val, 0, val);
//     strip.setPixelColor(g*12+3, val, 0, val);
//     strip.setPixelColor(g*12+4, 0, 0, val);
//     strip.setPixelColor(g*12+5, 0, 0, val);
//     strip.setPixelColor(g*12+6, 0, val, val);
//     strip.setPixelColor(g*12+7, 0, val, val);
//     strip.setPixelColor(g*12+8, 0, val, 0);
//     strip.setPixelColor(g*12+9, 0, val, 0);
//     strip.setPixelColor(g*12+10, val, val, 0);
//     strip.setPixelColor(g*12+11, val, val, 0);
//   }

//   strip.show();
//   delay(wait);
// }
