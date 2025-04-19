#include <Adafruit_NeoPixel.h>
#include <stdlib.h>
#include <time.h>

#define LED_PIN      4
#define LED_COUNT    133//138

// Total = 133
// Collar           7  //  0 to   6
// V Hemline        8  //  7 to  14;  60 to  67; 109 to 116
// Line to Shoulder 6  // 15 to  20;  29 to  34;
// Shoulder         8  // 21 to  28
// Diamond          9  // 35 to  43;  84 to  92
// H Line           16 // 44 to  59;  68 to  83;  93 to 108; 117 to 132

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_KHZ800 + NEO_GRB);

void setup() {
  strip.begin();
  strip.clear();
  // Serial.begin(9600);
  srand(time(NULL));
}

// float pi = 3.141592653;]
int randP = 0;
int randt = 0;
float P = 0;
float et = 0.0;
void loop() {
  // RainbowCycleSymmetric(P, 0.2, 17);
  RainbowCycleSymmetric_Comet(P, 0.2, et, 5);

  // RedCycleSymmetric(P, 0.1, 5);
  // RedCycleSymmetric_Comet(P, 0.1, et, 5);

  // SolidRainbowCycle(P, 0.2, 50);

  randt = randt + ((rand() % 11)-5);
  if (randt > 100) {
    randt = 100;
  } else if (randt < 0) {
    randt = 0;
  }
  randP = randP + ((rand() % 41)-20);
  if (randP > 100) {
    randP = 100;
  } else if (randP < -100) {
    randP = -100;
  }

  P = P-1*(0.1+randP/100.0);
  if (P < 0) {
    P = 100;
  } else if (P > 100) {
    P = 0;
  }
  // P = P+1;
  // if (P > 99) {
  //   P = 0;
  // }

  // et = et+0.014;
  et = et+0.007*(0.7+randt/100.0);
  if (et > 0.99999999) {
    et = 0.0;
  } else if (et < 0.00000001) {
    et = 1.0;
  }
}

//----------Define General Use Functions Below----------

void RainbowCycle(float P, float B, int rgb[3]) {
  // P = Percent [percent through the color cycle]
  // B = Brightness [LED brightness on a scale of 0 to 1]

  float Pregion = 100/6; // percent out of 100 that each local color change region takes
  float Pprime = fmodf(P,Pregion)/Pregion; // amount through the local color change region on a scale of 0 to 1
  float r;
  float g;
  float b;
  if (0<=P & P<Pregion) {
    r = 1.0;
    g = Pprime;
    b = 0.0;
  } else if (Pregion<=P & P<2*Pregion) {
    r = 1.0 - Pprime;
    g = 1.0;
    b = 0.0;
  } else if (2*Pregion<=P & P<3*Pregion) {
    r = 0.0;
    g = 1.0;
    b = Pprime;
  } else if (3*Pregion<=P & P<4*Pregion) {
    r = 0.0;
    g = 1.0 - Pprime;
    b = 1.0;
  } else if (4*Pregion<=P & P<5*Pregion) {
    r = Pprime;
    g = 0.0;
    b = 1.0;
  } else if (5*Pregion<=P & P<6*Pregion) {
    r = 1.0;
    g = 0.0;
    b = 1.0 - Pprime;
  } else {
    r = 1.0;
    g = 0.0;
    b = 0.0;
  }

  rgb[0] = 255 * B * r;
  rgb[1] = 255 * B * g;
  rgb[2] = 255 * B * b;
}

void RedCycle(float P, float B, int rgb[3]) {
  // P = Percent [percent through the color cycle]
  // B = Brightness [LED brightness on a scale of 0 to 1]

  float Pregion = 100/6; // percent out of 100 that each local color change region takes
  float Pprime = fmodf(P,Pregion)/Pregion; // amount through the local color change region on a scale of 0 to 1
  float r;
  float g;
  float b;
  if (0<=P & P<Pregion) {
    r = 1.0;
    g = 0.10 * Pprime;
    b = 0.0;
  } else if (Pregion<=P & P<2*Pregion) {
    r = 1.0;
    g = 0.10 + 0.4 * Pprime;
    b = 0.0;
  } else if (2*Pregion<=P & P<3*Pregion) {
    r = 1.0;
    g = 0.5 - 0.15 * Pprime;
    b = 0.0;
  } else if (3*Pregion<=P & P<4*Pregion) {
    r = 1.0;
    g = 0.35 - 0.35 * Pprime;
    b = Pprime;
  } else if (4*Pregion<=P & P<5*Pregion) {
    r = 1.0;
    g = 0.10 * Pprime;
    b = 1.0 - Pprime;
  } else if (5*Pregion<=P & P<6*Pregion) {
    r = 1.0;
    g = 0.10 - 0.10 * Pprime;
    b = 0.0;
  } else { 
    r = 1.0;
    g = 0.0;
    b = 0.0;
  }
  
  rgb[0] = 255 * B * r;
  rgb[1] = 255 * B * g;
  rgb[2] = 255 * B * b;
}

void CometEnvelope(float *intensity, float ep, float et) {
  *intensity = pow(1 - fmodf(ep+et,1.0),2);
}

//----------Define Modes Below----------

void RainbowCycleSymmetric(float P, float B, int wait) {
  static int rgb[3];

  for(int i=0; i<LED_COUNT; i++) {
    RainbowCycle(fmodf(P+100.0/LED_COUNT*i,100),B,rgb);
    strip.setPixelColor(i, rgb[0], rgb[1], rgb[2]);
  }

  strip.show();
  delay(wait);
}


void RainbowCycleSymmetric_Comet(float P, float B, float et, int wait) {
  static int rgb[3];
  float intensity = 0.0; // modifier to the pixel brightness (0 to 1)

  for(int i=0; i<LED_COUNT; i++) {
    float ep = fmodf(i,LED_COUNT/6.6)/(LED_COUNT/6.6);
    CometEnvelope(&intensity,ep,2*et);
    float eB = B*intensity;
    RainbowCycle(fmodf(P+100.0/LED_COUNT*i,100),eB,rgb);
    strip.setPixelColor(i, rgb[0], rgb[1], rgb[2]);
  }

  strip.show();
  delay(wait);
}

void RedCycleSymmetric(float P, float B, int wait) {
  static int rgb[3];

  for(int i=0; i<LED_COUNT; i++) {
    RedCycle(fmodf(P+100.0/LED_COUNT*i,100),B,rgb);
    strip.setPixelColor(i, rgb[0], rgb[1], rgb[2]);
  }

  strip.show();
  delay(wait);
}

void RedCycleSymmetric_Comet(float P, float B, float et, int wait) {
  static int rgb[3];
  float intensity = 0.0; // modifier to the pixel brightness (0 to 1)

  for(int i=0; i<LED_COUNT; i++) {
    float ep = fmodf(i,LED_COUNT/3.3)/(LED_COUNT/3.3);
    CometEnvelope(&intensity,ep,et);
    float eB = B*intensity;
    RedCycle(fmodf(P+100.0/LED_COUNT*i,100),eB,rgb);
    strip.setPixelColor(i, rgb[0], rgb[1], rgb[2]);
  }

  strip.show();
  delay(wait);
}

void SolidRainbowCycle(float P, float B, int wait) {
  static int rgb[3];
  RainbowCycle(P,B,rgb);

  for(int i=0; i<LED_COUNT; i++) {
    strip.setPixelColor(i, rgb[0], rgb[1], rgb[2]);
  }

  strip.show();
  delay(wait);
}