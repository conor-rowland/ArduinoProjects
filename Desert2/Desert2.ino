#include <Adafruit_NeoPixel.h>
#include <stdlib.h>
#include <time.h>

#define LED_PIN    4
#define LED_COUNT  306

// Spine                 36 (0-35)
// Top hem               17 (36-52 & 169-185)
// Side hem              32 (53-84 & 137-168)
// Bottom hem            52 (85-136)
// Gap to Outer Diamond  3  (186-188)
// Outer Diamond         52 (189-240)
// Gap to Middle Diamond 2  (241-242)
// Middle Diamond        36 (243-278)
// Gap to Inner Diamond  2  (279-280)
// Inner Diamond         20 (281-300)
// Extra                 5  (301-305)

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_KHZ800 + NEO_GRB);

void setup() {
  strip.begin();
  strip.clear();
  // Serial.begin(9600);
  srand(time(NULL));
}

// float pi = 3.141592653;
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
  // WashCycleSymmetric(et1, et2, et3, et4, et5, et6, 0.15, 5);
  // WashCycleRotate(et1, et2, et3, et4, et5, et6, 0.15, 5);
  // WashCycleOG(et1, et2, et3, et4, et5, et6, 0.15, 5);
  FireCycleSymmetric(et1, et2, et3, et4, et5, et6, 0.1, 5);
  // FireCycleRotate(et1, et2, et3, et4, et5, et6, 0.15, 5);
  // FireCycleOG(et1, et2, et3, et4, et5, et6, 0.15, 5);

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
  et1 = et1+0.013*(0.5+1.0*randt1/100.0);
  if (et1 > 0.99999999) {
    et1 = 0.0;
  } else if (et1 < 0.00000001) {
    et1 = 1.0;
  }
  // et2 = et2+0.007*(0.5+1.0*randt2/100.0);
  et2 = et2-0.0013*(0.5+1.0*randt2/100.0);
  if (et2 > 0.99999999) {
    et2 = 0.0;
  } else if (et2 < 0.00000001) {
    et2 = 1.0;
  }
  // et3 = et3-0.013*(0.5+1.0*randt3/100.0);
  et3 = et3+0.013*(0.5+1.0*randt3/100.0);
  if (et3 > 0.99999999) {
    et3 = 0.0;
  } else if (et3 < 0.00000001) {
    et3 = 1.0;
  }
  // et4 = et4-0.013*(0.5+1.0*randt4/100.0);
  et4 = et4-0.013*(0.5+1.0*randt4/100.0);
  if (et4 > 0.99999999) {
    et4 = 0.0;
  } else if (et4 < 0.00000001) {
    et4 = 1.0;
  }
  // et5 = et5-0.013*(0.0+1.0*randt5/100.0);
  et5 = et5+0.013*(0.5+1.0*randt5/100.0);
  if (et5 > 0.99999999) {
    et5 = 0.0;
  } else if (et5 < 0.00000001) {
    et5 = 1.0;
  }
  // et6 = et6-0.013*(0.5+1.0*randt6/100.0);
  et6 = et6-0.013*(0.5+1.0*randt6/100.0);
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

void CroppedParabolicEnvelope(float *intensity, float ep, float et) {
  float halfwidth = 0.1;
  float temp = fmodf(ep+et,1.0);
  if (temp >= halfwidth && temp <= 1.0-halfwidth) {
    *intensity = 0.0;
  } else {
    *intensity = pow(2*temp - 1, 2);
  }
}

void TriangleEnvelope(float *intensity, float ep, float et, float slope) {
  *intensity = abs(slope*(0.5 - fmodf(ep+et,1.0))) - (slope/2.0-1);
  if (*intensity < 0) {
    *intensity = 0.0;
  }
}

//----------Define Modes Below----------

void WashCycleOG(float etr, float etg, float etb, float etc, float etm, float ety, float B, int wait) {
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

  // Spine 
  for(int i=22; i<36; i++) {
    // RainbowCycle(fmodf(P+100.0/14*(i-22),100),B,rgb);

    // float ep = fmodf((i-22.0),25)/25.0;
    float ep = fmodf(i+1-22.0,1.0*(36.0-22.0))/(1.0*(36.0-22.0));
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

  // Hem total per side = 75
  // Top hem
  for(int i=36; i<53; i++) {
    float ep = fmodf((i-36.0),50)/50.0;
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
    strip.setPixelColor(185-(i-36), r+m+y, g+c+y, b+c+m);
  }

  // Side hem
  for(int i=53; i<85; i++) {
    float ep = fmodf(((i+17)-53.0),50)/50.0;
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
    strip.setPixelColor(168-(i-53), r+m+y, g+c+y, b+c+m);
  }

  // Bottom hem
  for(int i=85; i<111; i++) {
    float ep = fmodf(((i+24)-85.0),50)/50.0;
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
    strip.setPixelColor(136-(i-85), r+m+y, g+c+y, b+c+m);
  }

  // Outer diamond
  for(int i=189; i<216; i++) {
    // float ep = (i-189.0)/(216.0-189.0);
    float ep = fmodf(i+17.5-189.0,0.83*(216.0-189.0))/(0.83*(216.0-189.0));
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
    strip.setPixelColor(241-(i-189), r+m+y, g+c+y, b+c+m);
  }
  strip.setPixelColor(189, 0, 0, 0);
  strip.setPixelColor(241, 0, 0, 0);

  strip.show();
  delay(wait);
}


void WashCycleSymmetric(float etr, float etg, float etb, float etc, float etm, float ety, float B, int wait) {
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

  // Hem total per side = 75
  // Top hem
  for(int i=36; i<53; i++) {
    float ep = fmodf((i-36.0),50)/50.0;
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
    strip.setPixelColor(185-(i-36), r+m+y, g+c+y, b+c+m);
  }

  // Side hem
  for(int i=53; i<85; i++) {
    float ep = fmodf(((i+17)-53.0),50)/50.0;
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
    strip.setPixelColor(168-(i-53), r+m+y, g+c+y, b+c+m);
  }

  // Bottom hem
  for(int i=85; i<111; i++) {
    float ep = fmodf(((i+24)-85.0),50)/50.0;
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
    strip.setPixelColor(136-(i-85), r+m+y, g+c+y, b+c+m);
  }

  // Outer diamond
  for(int i=189; i<216; i++) {
    // float ep = (i-189.0)/(216.0-189.0);
    float ep = fmodf(i-189.0,1.0*(216.0-189.0))/(1.0*(216.0-189.0));
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
    strip.setPixelColor(241-(i-189), r+m+y, g+c+y, b+c+m);
  }
  strip.setPixelColor(241, 0, 0, 0);

  // Middle diamond
  for(int i=243; i<262; i++) {
    // float ep = (i-243.0)/(262.0-243.0);
    float ep = fmodf(i-243.0,1.0*(262.0-243.0))/(1.0*(262.0-243.0));
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
    strip.setPixelColor(279-(i-243), r+m+y, g+c+y, b+c+m);
  }
  strip.setPixelColor(279, 0, 0, 0);

  // Inner diamond
  for(int i=281; i<292; i++) {
    // float ep = (i-281.0)/(292.0-281.0);
    float ep = fmodf(i-281.0,1.0*(292.0-281.0))/(1.0*(292.0-281.0));
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
    strip.setPixelColor(301-(i-281), r+m+y, g+c+y, b+c+m);
  }
  strip.setPixelColor(301, 0, 0, 0);

  strip.show();
  delay(wait);
}


void WashCycleRotate(float etr, float etg, float etb, float etc, float etm, float ety, float B, int wait) {
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

  // Hem total per side = 75
  // Top hem (left) & Bottom hem (right) [36-52 & 111-127]
  for(int i=36; i<53; i++) {
    float ep = fmodf(i-36.0,0.5*(75.0))/(0.5*(75.0));
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
    strip.setPixelColor(111+(i-36), r+m+y, g+c+y, b+c+m);
  }

  // Side hem (left) & Bottom/Side hem (right) [53-84 & 128-159]
  for(int i=53; i<85; i++) {
    float ep = fmodf(i-36.0,0.5*(75.0))/(0.5*(75.0));
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
    strip.setPixelColor(128+(i-53), r+m+y, g+c+y, b+c+m);
  }

  // Bottom hem (left) & Side/Top hem (right) [85-110 & 160-185]
  for(int i=85; i<111; i++) {
    float ep = fmodf(i-36.0,0.5*(75.0))/(0.5*(75.0));
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
    strip.setPixelColor(160+(i-85), r+m+y, g+c+y, b+c+m);
  }

  // Outer diamond
  for(int i=189; i<241; i++) {
    float ep = fmodf(i-189.0,0.5*(241.0-189.0))/(0.5*(241.0-189.0));
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
  strip.setPixelColor(241, 0, 0, 0);

  // Middle diamond
  for(int i=243; i<279; i++) {
    float ep = fmodf(i-243.0,0.5*(279.0-243.0))/(0.5*(279.0-243.0));
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
  strip.setPixelColor(279, 0, 0, 0);

  // Inner diamond
  for(int i=281; i<301; i++) {
    float ep = fmodf(i-281.0,0.5*(301.0-281.0))/(0.5*(301.0-281.0));
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
  strip.setPixelColor(301, 0, 0, 0);

  strip.show();
  delay(wait);
}


void FireCycleSymmetric(float et_r1, float et_r2, float et_m1, float et_m2, float et_y1, float et_y2, float B, int wait) {
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

  // Hem total per side = 75
  // Top hem
  for(int i=36; i<53; i++) {
    float ep = fmodf((i-36.0),50)/50.0;
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
    strip.setPixelColor(111-(i-36), r1+r2+m1r+m2r+y1r+y2r, y1g+y2g, m1b+m2b);
}

  // Side hem
  for(int i=53; i<85; i++) {
    float ep = fmodf(((i+17)-53.0),50)/50.0;
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
    strip.setPixelColor(168-(i-53), r1+r2+m1r+m2r+y1r+y2r, y1g+y2g, m1b+m2b);
  }

  // Bottom hem
  for(int i=85; i<111; i++) {
    float ep = fmodf(((i+24)-85.0),50)/50.0;
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
    strip.setPixelColor(136-(i-85), r1+r2+m1r+m2r+y1r+y2r, y1g+y2g, m1b+m2b);
  }

  // Outer diamond
  for(int i=189; i<216; i++) {
    float ep = fmodf(i-189.0,1.0*(216.0-189.0))/(1.0*(216.0-189.0));
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
    strip.setPixelColor(241-(i-189), r1+r2+m1r+m2r+y1r+y2r, y1g+y2g, m1b+m2b);
  }
  strip.setPixelColor(241, 0, 0, 0);

  // Middle diamond
  for(int i=243; i<262; i++) {
    float ep = fmodf(i-243.0,1.0*(262.0-243.0))/(1.0*(262.0-243.0));
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
    strip.setPixelColor(279-(i-243), r1+r2+m1r+m2r+y1r+y2r, y1g+y2g, m1b+m2b);
  }
  strip.setPixelColor(279, 0, 0, 0);

  // Inner diamond
  for(int i=281; i<292; i++) {
    float ep = fmodf(i-281.0,1.0*(292.0-281.0))/(1.0*(292.0-281.0));
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
    strip.setPixelColor(301-(i-281), r1+r2+m1r+m2r+y1r+y2r, y1g+y2g, m1b+m2b);
  }
  strip.setPixelColor(301, 0, 0, 0);

  strip.show();
  delay(wait);

}


void FireCycleRotate(float et_r1, float et_r2, float et_m1, float et_m2, float et_y1, float et_y2, float B, int wait) {
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

  // Hem total per side = 75
  // Top hem (left) & Bottom hem (right) [36-52 & 111-127]
  for(int i=36; i<53; i++) {
    // RainbowCycle(fmodf(P+3*100.0/75*(i-36),100),B,rgb);
    float ep = fmodf(i-36.0,0.5*(75.0))/(0.5*(75.0));
    TriangleEnvelope(&intensity_r1, ep, et_r1, 4.0);
    TriangleEnvelope(&intensity_r2, ep, et_r2, 4.0);
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
    strip.setPixelColor(111+(i-36), r1+r2+m1r+m2r+y1r+y2r, y1g+y2g, m1b+m2b);
  }

  // Side hem (left) & Bottom/Side hem (right) [53-84 & 128-159]
  for(int i=53; i<85; i++) {
    // RainbowCycle(fmodf(P+3*100.0/75*(i-36),100),B,rgb);
    float ep = fmodf(i-36.0,0.5*(75.0))/(0.5*(75.0));
    TriangleEnvelope(&intensity_r1, ep, et_r1, 4.0);
    TriangleEnvelope(&intensity_r2, ep, et_r2, 4.0);
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
    strip.setPixelColor(128+(i-53), r1+r2+m1r+m2r+y1r+y2r, y1g+y2g, m1b+m2b);
  }

  // Bottom hem (left) & Side/Top hem (right) [85-110 & 160-185]
  for(int i=85; i<111; i++) {
    // RainbowCycle(fmodf(P+3*100.0/75*(i-36),100),B,rgb);
    float ep = fmodf(i-36.0,0.5*(75.0))/(0.5*(75.0));
    TriangleEnvelope(&intensity_r1, ep, et_r1, 4.0);
    TriangleEnvelope(&intensity_r2, ep, et_r2, 4.0);
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
    strip.setPixelColor(160+(i-85), r1+r2+m1r+m2r+y1r+y2r, y1g+y2g, m1b+m2b);
  }

  // Outer diamond
  for(int i=189; i<241; i++) {
    float ep = fmodf(i-189.0,0.5*(241.0-189.0))/(0.5*(241.0-189.0));
    TriangleEnvelope(&intensity_r1, ep, et_r1, 4.0);
    TriangleEnvelope(&intensity_r2, ep, et_r2, 4.0);
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
  strip.setPixelColor(241, 0, 0, 0);

  // Middle diamond
  for(int i=243; i<279; i++) {
    float ep = fmodf(i-243.0,0.5*(279.0-243.0))/(0.5*(279.0-243.0));
    TriangleEnvelope(&intensity_r1, ep, et_r1, 4.0);
    TriangleEnvelope(&intensity_r2, ep, et_r2, 4.0);
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
  strip.setPixelColor(279, 0, 0, 0);

  // Inner diamond
  for(int i=281; i<301; i++) {
    float ep = fmodf(i-281.0,0.5*(301.0-281.0))/(0.5*(301.0-281.0));
    TriangleEnvelope(&intensity_r1, ep, et_r1, 4.0);
    TriangleEnvelope(&intensity_r2, ep, et_r2, 4.0);
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
  strip.setPixelColor(301, 0, 0, 0);

  // Center dot
  strip.setPixelColor(22, 0, 0, 0);

  strip.show();
  delay(wait);
}


void FireCycleOG(float et_r1, float et_r2, float et_m1, float et_m2, float et_y1, float et_y2, float B, int wait) {
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

  // Spine 
  for(int i=22; i<36; i++) {
    float ep = fmodf(i+1-22.0,1.0*(36.0-22.0))/(1.0*(36.0-22.0));
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

  // Hem total per side = 75
  // Top hem
  for(int i=36; i<53; i++) {
    float ep = fmodf((i-36.0),50)/50.0;
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
    strip.setPixelColor(111-(i-36), r1+r2+m1r+m2r+y1r+y2r, y1g+y2g, m1b+m2b);
}

  // Side hem
  for(int i=53; i<85; i++) {
    float ep = fmodf(((i+17)-53.0),50)/50.0;
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
    strip.setPixelColor(168-(i-53), r1+r2+m1r+m2r+y1r+y2r, y1g+y2g, m1b+m2b);
  }

  // Bottom hem
  for(int i=85; i<111; i++) {
    float ep = fmodf(((i+24)-85.0),50)/50.0;
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
    strip.setPixelColor(136-(i-85), r1+r2+m1r+m2r+y1r+y2r, y1g+y2g, m1b+m2b);
  }

  // Outer diamond
  for(int i=189; i<216; i++) {
    // float ep = fmodf(i-189.0,1.0*(216.0-189.0))/(1.0*(216.0-189.0));
    float ep = fmodf(i+17.5-189.0,0.83*(216.0-189.0))/(0.83*(216.0-189.0));
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
    strip.setPixelColor(241-(i-189), r1+r2+m1r+m2r+y1r+y2r, y1g+y2g, m1b+m2b);
  }
  strip.setPixelColor(241, 0, 0, 0);

  strip.show();
  delay(wait);
}