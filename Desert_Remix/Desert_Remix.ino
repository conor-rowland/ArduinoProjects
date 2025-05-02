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

int randt1 = 0;
int randt2 = 0;
int randt3 = 0;
int randt4 = 0;
int randt5 = 0;
int randt6 = 0;
float et1 = 0.0;
float et2 = 0.0;
float et3 = 0.0;
float et4 = 0.0;
float et5 = 0.0;
float et6 = 0.0;
void loop() {
  // RainbowCycle(P, 0.2, 17);
  // RainbowCycle_Comet(P, 0.2, et, 5);

  // RedCycle(P, 0.1, 5);
  // RedCycle_Comet(P, 0.1, et, 5);

  WashCycle(et1, et2, et3, et4, et5, et6, 0.1, 5);
  // FireCycle(et1, et2, et3, et4, et5, et6, 0.05, 5);

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

  randt1 = randt1 + ((rand() % 21)-10);
  if (randt1 > 100) {
    randt1 = 100;
  } else if (randt1 < 0) {
    randt1 = 0;
  }
  randt2 = randt2 + ((rand() % 21)-10);
  if (randt2 > 100) {
    randt2 = 100;
  } else if (randt2 < 0) {
    randt2 = 0;
  }
  randt3 = randt3 + ((rand() % 21)-10);
  if (randt3 > 100) {
    randt3 = 100;
  } else if (randt3 < 0) {
    randt3 = 0;
  }
  randt4 = randt4 + ((rand() % 21)-10);
  if (randt4 > 100) {
    randt4 = 100;
  } else if (randt4 < 0) {
    randt4 = 0;
  }
  randt5 = randt5 + ((rand() % 21)-10);
  if (randt5 > 100) {
    randt5 = 100;
  } else if (randt5 < 0) {
    randt5 = 0;
  }
  randt6 = randt6 + ((rand() % 21)-10);
  if (randt6 > 100) {
    randt6 = 100;
  } else if (randt6 < 0) {
    randt6 = 0;
  }
  
  // et1 = et1+0.013*(1.0+0.0*randt1/100.0);
  et1 = et1+0.007*(0.5+1.0*randt1/100.0);
  if (et1 > 0.99999999) {
    et1 = 0.0;
  } else if (et1 < 0.00000001) {
    et1 = 1.0;
  }
  // et2 = et2+0.007*(0.5+1.0*randt2/100.0);
  et2 = et2-0.007*(0.5+1.0*randt2/100.0);
  if (et2 > 0.99999999) {
    et2 = 0.0;
  } else if (et2 < 0.00000001) {
    et2 = 1.0;
  }
  // et3 = et3-0.013*(0.5+1.0*randt3/100.0);
  et3 = et3+0.007*(0.5+1.0*randt3/100.0);
  if (et3 > 0.99999999) {
    et3 = 0.0;
  } else if (et3 < 0.00000001) {
    et3 = 1.0;
  }
  // et4 = et4-0.013*(0.5+1.0*randt4/100.0);
  et4 = et4-0.007*(0.5+1.0*randt4/100.0);
  if (et4 > 0.99999999) {
    et4 = 0.0;
  } else if (et4 < 0.00000001) {
    et4 = 1.0;
  }
  // et5 = et5-0.013*(0.0+1.0*randt5/100.0);
  et5 = et5+0.007*(0.5+1.0*randt5/100.0);
  if (et5 > 0.99999999) {
    et5 = 0.0;
  } else if (et5 < 0.00000001) {
    et5 = 1.0;
  }
  // et6 = et6-0.013*(0.5+1.0*randt6/100.0);
  et6 = et6-0.007*(0.5+1.0*randt6/100.0);
  if (et6 > 0.99999999) {
    et6 = 0.0;
  } else if (et6 < 0.00000001) {
    et6 = 1.0;
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

void TriangleEnvelope(float *intensity, float ep, float et, float slope) {
  *intensity = abs(slope*(0.5 - fmodf(ep+et,1.0))) - (slope/2.0-1);
  if (*intensity < 0) {
    *intensity = 0.0;
  }
}

//----------Define Modes Below----------

void RainbowCycle(float P, float B, int wait) {
  static int rgb[3];

  for(int i=0; i<LED_COUNT; i++) {
    RainbowCycle(fmodf(P+100.0/LED_COUNT*i,100),B,rgb);
    strip.setPixelColor(i, rgb[0], rgb[1], rgb[2]);
  }

  strip.show();
  delay(wait);
}


void RainbowCycle_Comet(float P, float B, float et, int wait) {
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

void RedCycle(float P, float B, int wait) {
  static int rgb[3];

  for(int i=0; i<LED_COUNT; i++) {
    RedCycle(fmodf(P+100.0/LED_COUNT*i,100),B,rgb);
    strip.setPixelColor(i, rgb[0], rgb[1], rgb[2]);
  }

  strip.show();
  delay(wait);
}

void RedCycle_Comet(float P, float B, float et, int wait) {
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

void WashCycle(float etr, float etg, float etb, float etc, float etm, float ety, float B, int wait) {
  int r;
  int g;
  int b;
  int c;
  int m;
  int y;
  float intensityr = 0.0; // modifier to the pixel brightness (0 to 1)
  float intensityg = 0.0; // modifier to the pixel brightness (0 to 1)
  float intensityb = 0.0; // modifier to the pixel brightness (0 to 1)
  float intensityc = 0.0; // modifier to the pixel brightness (0 to 1)
  float intensitym = 0.0; // modifier to the pixel brightness (0 to 1)
  float intensityy = 0.0; // modifier to the pixel brightness (0 to 1)

  for(int i=0; i<LED_COUNT; i++) {
    float ep = fmodf(i,0.9*LED_COUNT)/(0.9*LED_COUNT);
    TriangleEnvelope(&intensityr,ep,etr,4.0);
    TriangleEnvelope(&intensityg,ep,etg,4.0);
    TriangleEnvelope(&intensityb,ep,etb,4.0);
    TriangleEnvelope(&intensityc,ep,etc,11.0);
    TriangleEnvelope(&intensitym,ep,etm,11.0);
    TriangleEnvelope(&intensityy,ep,ety,11.0);
    r = 255 * B * intensityr;
    g = 255 * B * intensityg;
    b = 255 * B * intensityb;
    c = 125 * B * intensityc;
    m = 125 * B * intensitym;
    y = 125 * B * intensityy;
    // r = 0;
    // g = 0;
    // b = 0;
    // c = 0;
    // m = 0;
    // y = 0;
    strip.setPixelColor(i, r+m+y, g+c+y, b+c+m);
  }

  strip.show();
  delay(wait);
}

void FireCycle(float et_r1, float et_r2, float et_m1, float et_m2, float et_y1, float et_y2, float B, int wait) {
  int r1;
  int r2;
  int m1r;
  int m1b;
  int m2r;
  int m2b;
  int y1r;
  int y1g;
  int y2r;
  int y2g;
  float intensity_r1 = 0.0; // modifier to the pixel brightness (0 to 1)
  float intensity_r2 = 0.0; // modifier to the pixel brightness (0 to 1)
  float intensity_m1 = 0.0; // modifier to the pixel brightness (0 to 1)
  float intensity_m2 = 0.0; // modifier to the pixel brightness (0 to 1)
  float intensity_y1 = 0.0; // modifier to the pixel brightness (0 to 1)
  float intensity_y2 = 0.0; // modifier to the pixel brightness (0 to 1)

  for(int i=0; i<LED_COUNT; i++) {
    float ep = fmodf(i,1.0*LED_COUNT)/(1.0*LED_COUNT);
    TriangleEnvelope(&intensity_r1, ep, et_r1, 2.0);
    TriangleEnvelope(&intensity_r2, ep, et_r2, 2.0);
    TriangleEnvelope(&intensity_m1, ep, et_m1, 11.0);
    TriangleEnvelope(&intensity_m2, ep, et_m2, 11.0);
    TriangleEnvelope(&intensity_y1, ep, et_y1, 5.0);
    TriangleEnvelope(&intensity_y2, ep, et_y2, 5.0);
    r1 = 255 * B * intensity_r1;
    r2 = 255 * B * intensity_r2;
    m1r = 125 * B * intensity_m1;
    m1b = 75 * B * intensity_m1;
    m2r = 125 * B * intensity_m2;
    m2b = 75 * B * intensity_m2;
    y1r = 125 * B * intensity_y1;
    y1g = 75 * B * intensity_y1;
    y2r = 125 * B * intensity_y2;
    y2g = 75 * B * intensity_y2;
    strip.setPixelColor(i, r1+r2+m1r+m2r+y1r+y2r, y1g+y2g, m1b+m2b);
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