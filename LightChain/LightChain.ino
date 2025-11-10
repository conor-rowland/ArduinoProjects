#include <Adafruit_NeoPixel.h>
#include <stdlib.h>
#include <time.h>

#define LED_PIN      4
#define LED_COUNT    44//126

// Total = 44
// 0-, 

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
  // RainbowCycle_1(et1, 0.05, 30);
  // RainbowCycleSymmetric(et1, 0.15, 17);
  // RainbowCycle_Comet(P, 0.2, et, 5);

  // RedCycle(P, 0.1, 5);
  // RedCycle_Comet(P, 0.1, et, 5);

  WashCycle(et1, et2, et3, et4, et5, et6, 0.05, 5);
  // FireCycle(et1, et2, et3, et4, et5, et6, 0.1, 5);

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

void UpdateWashColors(float *intensityr, float *intensityg, float *intensityb, float *intensityc, float *intensitym, float *intensityy, int *r, int *g, int *b, int *c, int *m, int *y, float etr, float etg, float etb, float etc, float etm, float ety, float ep, float B) {
  TriangleEnvelope(intensityr, ep, etr, 5.0);
  TriangleEnvelope(intensityg, ep, etg, 5.0);
  TriangleEnvelope(intensityb, ep, etb, 5.0);
  TriangleEnvelope(intensityc, ep, etc, 13.0);
  TriangleEnvelope(intensitym, ep, etm, 13.0);
  TriangleEnvelope(intensityy, ep, ety, 13.0);
  *r = 255 * B * (*intensityr);
  *g = 255 * B * (*intensityg);
  *b = 255 * B * (*intensityb);
  *c = 125 * B * (*intensityc);
  *m = 125 * B * (*intensitym);
  *y = 125 * B * (*intensityy);
}

void UpdateFireColors(float *intensity_r1, float *intensity_r2, float *intensity_m1, float *intensity_m2, float *intensity_y1, float *intensity_y2, int *r1, int *r2, int *m1r, int *m1b, int *m2r, int *m2b, int *y1r, int *y1g, int *y2r, int *y2g, float et_r1, float et_r2, float et_m1, float et_m2, float et_y1, float et_y2, float ep, float B) {
  TriangleEnvelope(intensity_r1, ep, et_r1, 5.0);
  TriangleEnvelope(intensity_r2, ep, et_r2, 5.0);
  TriangleEnvelope(intensity_m1, ep, et_m1, 13.0);
  TriangleEnvelope(intensity_m2, ep, et_m2, 13.0);
  TriangleEnvelope(intensity_y1, ep, et_y1, 11.0);
  TriangleEnvelope(intensity_y2, ep, et_y2, 11.0);
  *r1 = 255 * B * (*intensity_r1);
  *r2 = 255 * B * (*intensity_r2);
  *m1r = 125 * B * (*intensity_m1);
  *m1b = 75 * B * (*intensity_m1);
  *m2r = 125 * B * (*intensity_m2);
  *m2b = 75 * B * (*intensity_m2);
  *y1r = 125 * B * (*intensity_y1);
  *y1g = 75 * B * (*intensity_y1);
  *y2r = 125 * B * (*intensity_y2);
  *y2g = 75 * B * (*intensity_y2);
}

//----------Define Modes Below----------

//
// 17,0,18,34,1,16,35,19,33,2,15,36,20,32,3,14,37,21,31,4,13,38,22,30,5,12,39,23,29,6,11,40,24,28,7,10,41,25,27,8,9,42,26,43
// 17, 0,18,34, 1,
// 16,35,19,33, 2,
// 15,36,20,32, 3,
// 14,37,21,31, 4,
// 13,38,22,30, 5,
// 12,39,23,29, 6,
// 11,40,24,28, 7,
// 10,41,25,27, 8,
//  9,42,26,43

void RainbowCycle_1(float etP, float B, int wait) {
  static int rgb[3];

  int i = 17;
  float P = fmodf(0,44)*100/44.0;
  RainbowCycle(fmodf(P+100*etP,100),B,rgb);
  strip.setPixelColor(i, rgb[0], rgb[1], rgb[2]);
  i = 0;
  P = fmodf(1,44)*100/44.0;
  RainbowCycle(fmodf(P+100*etP,100),B,rgb);
  strip.setPixelColor(i, rgb[0], rgb[1], rgb[2]);
  i = 18;
  P = fmodf(2,44)*100/44.0;
  RainbowCycle(fmodf(P+100*etP,100),B,rgb);
  strip.setPixelColor(i, rgb[0], rgb[1], rgb[2]);
  i = 34;
  P = fmodf(3,44)*100/44.0;
  RainbowCycle(fmodf(P+100*etP,100),B,rgb);
  strip.setPixelColor(i, rgb[0], rgb[1], rgb[2]);
  i = 1;
  P = fmodf(4,44)*100/44.0;
  RainbowCycle(fmodf(P+100*etP,100),B,rgb);
  strip.setPixelColor(i, rgb[0], rgb[1], rgb[2]);

  for(int i=0; i<7; i++) {
    float P = fmodf(5*i+5,44)*100/44.0;
    RainbowCycle(fmodf(P+100*etP,100),B,rgb);
    strip.setPixelColor(16-i, rgb[0], rgb[1], rgb[2]);
    P = fmodf(5*i+6,44)*100/44.0;
    RainbowCycle(fmodf(P+100*etP,100),B,rgb);
    strip.setPixelColor(35+i, rgb[0], rgb[1], rgb[2]);
    P = fmodf(5*i+7,44)*100/44.0;
    RainbowCycle(fmodf(P+100*etP,100),B,rgb);
    strip.setPixelColor(19+i, rgb[0], rgb[1], rgb[2]);
    P = fmodf(5*i+8,44)*100/44.0;
    RainbowCycle(fmodf(P+100*etP,100),B,rgb);
    strip.setPixelColor(33-i, rgb[0], rgb[1], rgb[2]);
    P = fmodf(5*i+9,44)*100/44.0;
    RainbowCycle(fmodf(P+100*etP,100),B,rgb);
    strip.setPixelColor(2+i, rgb[0], rgb[1], rgb[2]);
  }

  i = 9;
  P = fmodf(40,44)*100/44.0;
  RainbowCycle(fmodf(P+100*etP,100),B,rgb);
  strip.setPixelColor(i, rgb[0], rgb[1], rgb[2]);
  i = 42;
  P = fmodf(41,44)*100/44.0;
  RainbowCycle(fmodf(P+100*etP,100),B,rgb);
  strip.setPixelColor(i, rgb[0], rgb[1], rgb[2]);
  i = 26;
  P = fmodf(42,44)*100/44.0;
  RainbowCycle(fmodf(P+100*etP,100),B,rgb);
  strip.setPixelColor(i, rgb[0], rgb[1], rgb[2]);
  i = 43;
  P = fmodf(43,44)*100/44.0;
  RainbowCycle(fmodf(P+100*etP,100),B,rgb);
  strip.setPixelColor(i, rgb[0], rgb[1], rgb[2]);

  strip.show();
  delay(wait);
}


void RainbowCycleSymmetric(float etP, float B, int wait) {
  static int rgb[3];

  for(int i=10; i<23; i++) {
    float P = fmodf((i-10.0),25)*100/25.0;
    RainbowCycle(fmodf(P+100*etP,100),B,rgb);
    strip.setPixelColor(i, rgb[0], rgb[1], rgb[2]);
    strip.setPixelColor(34-(i-10), rgb[0], rgb[1], rgb[2]);
  }
  for(int i=35; i<68; i++) {
    float P = fmodf((i-35.0),21.66666)*100/21.66666;
    RainbowCycle(fmodf(P+5+100*etP,100),B,rgb);
    strip.setPixelColor(i, rgb[0], rgb[1], rgb[2]);
    strip.setPixelColor(99-(i-35), rgb[0], rgb[1], rgb[2]);
  }
  for(int i=100; i<114; i++) {
    float P = fmodf((i-100.0),26)*100/26.0;
    RainbowCycle(fmodf(P+5+100*etP,100),B,rgb);
    strip.setPixelColor(i, rgb[0], rgb[1], rgb[2]);
    strip.setPixelColor(125-(i-100), rgb[0], rgb[1], rgb[2]);
  }
  for(int i=126; i<132; i++) {
    strip.setPixelColor(i, 0, 0, 0);
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

  int i = 17;
  float ep = fmodf(0,44)/44.0;
  UpdateWashColors(&intensityr, &intensityg, &intensityb, &intensityc, &intensitym, &intensityy, &r, &g, &b, &c, &m, &y, etr, etg, etb, etc, etm, ety, ep, B);
  strip.setPixelColor(i, r+m+y, g+c+y, b+c+m);
  i = 0;
  ep = fmodf(1,44)/44.0;
  UpdateWashColors(&intensityr, &intensityg, &intensityb, &intensityc, &intensitym, &intensityy, &r, &g, &b, &c, &m, &y, etr, etg, etb, etc, etm, ety, ep, B);
  strip.setPixelColor(i, r+m+y, g+c+y, b+c+m);
  i = 18;
  ep = fmodf(2,44)/44.0;
  UpdateWashColors(&intensityr, &intensityg, &intensityb, &intensityc, &intensitym, &intensityy, &r, &g, &b, &c, &m, &y, etr, etg, etb, etc, etm, ety, ep, B);
  strip.setPixelColor(i, r+m+y, g+c+y, b+c+m);
  i = 34;
  ep = fmodf(3,44)/44.0;
  UpdateWashColors(&intensityr, &intensityg, &intensityb, &intensityc, &intensitym, &intensityy, &r, &g, &b, &c, &m, &y, etr, etg, etb, etc, etm, ety, ep, B);
  strip.setPixelColor(i, r+m+y, g+c+y, b+c+m);
  i = 1;
  ep = fmodf(4,44)/44.0;
  UpdateWashColors(&intensityr, &intensityg, &intensityb, &intensityc, &intensitym, &intensityy, &r, &g, &b, &c, &m, &y, etr, etg, etb, etc, etm, ety, ep, B);
  strip.setPixelColor(i, r+m+y, g+c+y, b+c+m);

  for(int i=0; i<7; i++) {
    float ep = fmodf(5*i+5,44)/44.0;
    UpdateWashColors(&intensityr, &intensityg, &intensityb, &intensityc, &intensitym, &intensityy, &r, &g, &b, &c, &m, &y, etr, etg, etb, etc, etm, ety, ep, B);
    strip.setPixelColor(16-i, r+m+y, g+c+y, b+c+m);
    ep = fmodf(5*i+6,44)/44.0;
    UpdateWashColors(&intensityr, &intensityg, &intensityb, &intensityc, &intensitym, &intensityy, &r, &g, &b, &c, &m, &y, etr, etg, etb, etc, etm, ety, ep, B);
    strip.setPixelColor(35+i, r+m+y, g+c+y, b+c+m);
    ep = fmodf(5*i+7,44)/44.0;
    UpdateWashColors(&intensityr, &intensityg, &intensityb, &intensityc, &intensitym, &intensityy, &r, &g, &b, &c, &m, &y, etr, etg, etb, etc, etm, ety, ep, B);
    strip.setPixelColor(19+i, r+m+y, g+c+y, b+c+m);
    ep = fmodf(5*i+8,44)/44.0;
    UpdateWashColors(&intensityr, &intensityg, &intensityb, &intensityc, &intensitym, &intensityy, &r, &g, &b, &c, &m, &y, etr, etg, etb, etc, etm, ety, ep, B);
    strip.setPixelColor(33-i, r+m+y, g+c+y, b+c+m);
    ep = fmodf(5*i+9,44)/44.0;
    UpdateWashColors(&intensityr, &intensityg, &intensityb, &intensityc, &intensitym, &intensityy, &r, &g, &b, &c, &m, &y, etr, etg, etb, etc, etm, ety, ep, B);
    strip.setPixelColor(2+i, r+m+y, g+c+y, b+c+m);
  }

  i = 9;
  ep = fmodf(40,44)/44.0;
  UpdateWashColors(&intensityr, &intensityg, &intensityb, &intensityc, &intensitym, &intensityy, &r, &g, &b, &c, &m, &y, etr, etg, etb, etc, etm, ety, ep, B);
  strip.setPixelColor(i, r+m+y, g+c+y, b+c+m);
  i = 42;
  ep = fmodf(41,44)/44.0;
  UpdateWashColors(&intensityr, &intensityg, &intensityb, &intensityc, &intensitym, &intensityy, &r, &g, &b, &c, &m, &y, etr, etg, etb, etc, etm, ety, ep, B);
  strip.setPixelColor(i, r+m+y, g+c+y, b+c+m);
  i = 26;
  ep = fmodf(42,44)/44.0;
  UpdateWashColors(&intensityr, &intensityg, &intensityb, &intensityc, &intensitym, &intensityy, &r, &g, &b, &c, &m, &y, etr, etg, etb, etc, etm, ety, ep, B);
  strip.setPixelColor(i, r+m+y, g+c+y, b+c+m);
  i = 43;
  ep = fmodf(43,44)/44.0;
  UpdateWashColors(&intensityr, &intensityg, &intensityb, &intensityc, &intensitym, &intensityy, &r, &g, &b, &c, &m, &y, etr, etg, etb, etc, etm, ety, ep, B);
  strip.setPixelColor(i, r+m+y, g+c+y, b+c+m);

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

  int i = 17;
  float ep = fmodf(0,44)/44.0;
  UpdateFireColors(&intensity_r1, &intensity_r2, &intensity_m1, &intensity_m2, &intensity_y1, &intensity_y2, &r1, &r2, &m1r, &m1b, &m2r, &m2b, &y1r, &y1g, &y2r, &y2g, et_r1, et_r2, et_m1, et_m2, et_y1, et_y2, ep, B);
  strip.setPixelColor(i, r1+r2+m1r+m2r+y1r+y2r, y1g+y2g, m1b+m2b);
  i = 0;
  ep = fmodf(1,44)/44.0;
  UpdateFireColors(&intensity_r1, &intensity_r2, &intensity_m1, &intensity_m2, &intensity_y1, &intensity_y2, &r1, &r2, &m1r, &m1b, &m2r, &m2b, &y1r, &y1g, &y2r, &y2g, et_r1, et_r2, et_m1, et_m2, et_y1, et_y2, ep, B);
  strip.setPixelColor(i, r1+r2+m1r+m2r+y1r+y2r, y1g+y2g, m1b+m2b);
  i = 18;
  ep = fmodf(2,44)/44.0;
  UpdateFireColors(&intensity_r1, &intensity_r2, &intensity_m1, &intensity_m2, &intensity_y1, &intensity_y2, &r1, &r2, &m1r, &m1b, &m2r, &m2b, &y1r, &y1g, &y2r, &y2g, et_r1, et_r2, et_m1, et_m2, et_y1, et_y2, ep, B);
  strip.setPixelColor(i, r1+r2+m1r+m2r+y1r+y2r, y1g+y2g, m1b+m2b);
  i = 34;
  ep = fmodf(3,44)/44.0;
  UpdateFireColors(&intensity_r1, &intensity_r2, &intensity_m1, &intensity_m2, &intensity_y1, &intensity_y2, &r1, &r2, &m1r, &m1b, &m2r, &m2b, &y1r, &y1g, &y2r, &y2g, et_r1, et_r2, et_m1, et_m2, et_y1, et_y2, ep, B);
  strip.setPixelColor(i, r1+r2+m1r+m2r+y1r+y2r, y1g+y2g, m1b+m2b);
  i = 1;
  ep = fmodf(4,44)/44.0;
  UpdateFireColors(&intensity_r1, &intensity_r2, &intensity_m1, &intensity_m2, &intensity_y1, &intensity_y2, &r1, &r2, &m1r, &m1b, &m2r, &m2b, &y1r, &y1g, &y2r, &y2g, et_r1, et_r2, et_m1, et_m2, et_y1, et_y2, ep, B);
  strip.setPixelColor(i, r1+r2+m1r+m2r+y1r+y2r, y1g+y2g, m1b+m2b);

  for(int i=0; i<7; i++) {
    float ep = fmodf(5*i+5,44)/44.0;
    UpdateFireColors(&intensity_r1, &intensity_r2, &intensity_m1, &intensity_m2, &intensity_y1, &intensity_y2, &r1, &r2, &m1r, &m1b, &m2r, &m2b, &y1r, &y1g, &y2r, &y2g, et_r1, et_r2, et_m1, et_m2, et_y1, et_y2, ep, B);
    strip.setPixelColor(16-i, r1+r2+m1r+m2r+y1r+y2r, y1g+y2g, m1b+m2b);
    ep = fmodf(5*i+6,44)/44.0;
    UpdateFireColors(&intensity_r1, &intensity_r2, &intensity_m1, &intensity_m2, &intensity_y1, &intensity_y2, &r1, &r2, &m1r, &m1b, &m2r, &m2b, &y1r, &y1g, &y2r, &y2g, et_r1, et_r2, et_m1, et_m2, et_y1, et_y2, ep, B);
    strip.setPixelColor(35+i, r1+r2+m1r+m2r+y1r+y2r, y1g+y2g, m1b+m2b);
    ep = fmodf(5*i+7,44)/44.0;
    UpdateFireColors(&intensity_r1, &intensity_r2, &intensity_m1, &intensity_m2, &intensity_y1, &intensity_y2, &r1, &r2, &m1r, &m1b, &m2r, &m2b, &y1r, &y1g, &y2r, &y2g, et_r1, et_r2, et_m1, et_m2, et_y1, et_y2, ep, B);
    strip.setPixelColor(19+i, r1+r2+m1r+m2r+y1r+y2r, y1g+y2g, m1b+m2b);
    ep = fmodf(5*i+8,44)/44.0;
    UpdateFireColors(&intensity_r1, &intensity_r2, &intensity_m1, &intensity_m2, &intensity_y1, &intensity_y2, &r1, &r2, &m1r, &m1b, &m2r, &m2b, &y1r, &y1g, &y2r, &y2g, et_r1, et_r2, et_m1, et_m2, et_y1, et_y2, ep, B);
    strip.setPixelColor(33-i, r1+r2+m1r+m2r+y1r+y2r, y1g+y2g, m1b+m2b);
    ep = fmodf(5*i+9,44)/44.0;
    UpdateFireColors(&intensity_r1, &intensity_r2, &intensity_m1, &intensity_m2, &intensity_y1, &intensity_y2, &r1, &r2, &m1r, &m1b, &m2r, &m2b, &y1r, &y1g, &y2r, &y2g, et_r1, et_r2, et_m1, et_m2, et_y1, et_y2, ep, B);
    strip.setPixelColor(2+i, r1+r2+m1r+m2r+y1r+y2r, y1g+y2g, m1b+m2b);
  }

  i = 9;
  ep = fmodf(40,44)/44.0;
  UpdateFireColors(&intensity_r1, &intensity_r2, &intensity_m1, &intensity_m2, &intensity_y1, &intensity_y2, &r1, &r2, &m1r, &m1b, &m2r, &m2b, &y1r, &y1g, &y2r, &y2g, et_r1, et_r2, et_m1, et_m2, et_y1, et_y2, ep, B);
  strip.setPixelColor(i, r1+r2+m1r+m2r+y1r+y2r, y1g+y2g, m1b+m2b);
  i = 42;
  ep = fmodf(41,44)/44.0;
  UpdateFireColors(&intensity_r1, &intensity_r2, &intensity_m1, &intensity_m2, &intensity_y1, &intensity_y2, &r1, &r2, &m1r, &m1b, &m2r, &m2b, &y1r, &y1g, &y2r, &y2g, et_r1, et_r2, et_m1, et_m2, et_y1, et_y2, ep, B);
  strip.setPixelColor(i, r1+r2+m1r+m2r+y1r+y2r, y1g+y2g, m1b+m2b);
  i = 26;
  ep = fmodf(42,44)/44.0;
  UpdateFireColors(&intensity_r1, &intensity_r2, &intensity_m1, &intensity_m2, &intensity_y1, &intensity_y2, &r1, &r2, &m1r, &m1b, &m2r, &m2b, &y1r, &y1g, &y2r, &y2g, et_r1, et_r2, et_m1, et_m2, et_y1, et_y2, ep, B);
  strip.setPixelColor(i, r1+r2+m1r+m2r+y1r+y2r, y1g+y2g, m1b+m2b);
  i = 43;
  ep = fmodf(43,44)/44.0;
  UpdateFireColors(&intensity_r1, &intensity_r2, &intensity_m1, &intensity_m2, &intensity_y1, &intensity_y2, &r1, &r2, &m1r, &m1b, &m2r, &m2b, &y1r, &y1g, &y2r, &y2g, et_r1, et_r2, et_m1, et_m2, et_y1, et_y2, ep, B);
  strip.setPixelColor(i, r1+r2+m1r+m2r+y1r+y2r, y1g+y2g, m1b+m2b);

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