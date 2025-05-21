#include <Adafruit_NeoPixel.h>
#include <stdlib.h>
#include <time.h>

#define LED_PIN      4
#define LED_COUNT    206

// Hem:     0 - 79
// Spiral: 80 - 205

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_KHZ800 + NEO_GRB);

void setup() {
  strip.begin();
  strip.clear();
  // Serial.begin(9600);
  srand(time(NULL));
}

// float pi = 3.141592653;
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
int randt7 = 0;
float et1 = 0.0;
float et2 = 0.0;
float et3 = 0.0;
float et4 = 0.0;
float et5 = 0.0;
float et6 = 0.0;
float et7 = 0.0;
void loop() {
  // RainbowCycle(et1, 0.15, 17);
  // RainbowCycleSymmetric(et1, 0.15, 17);
  // RainbowCycle_Comet(P, 0.2, et, 5);

  WaterCycle(et1, et2, et3, et4, et5, et6, et7, 0.15, 5);
  
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
  randt7 = randt7 + ((rand() % 21)-10);
  if (randt7 > 100) {
    randt7 = 100;
  } else if (randt7 < 0) {
    randt7 = 0;
  }
  
  // et1 = et1+0.013*(1.0+0.0*randt1/100.0);
  et1 = et1+0.005*(0.5+1.0*randt1/100.0);
  if (et1 > 0.99999999) {
    et1 = 0.0;
  } else if (et1 < 0.00000001) {
    et1 = 1.0;
  }
  // et2 = et2+0.007*(0.5+1.0*randt2/100.0);
  et2 = et2+0.007*(0.2+1.0*randt2/100.0);
  if (et2 > 0.99999999) {
    et2 = 0.0;
  } else if (et2 < 0.00000001) {
    et2 = 1.0;
  }
  // et3 = et3-0.013*(0.5+1.0*randt3/100.0);
  et3 = et3+0.007*(0.3+1.7*randt3/100.0);
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
  et5 = et5+0.007*(0.75+1.0*randt5/100.0);
  if (et5 > 0.99999999) {
    et5 = 0.0;
  } else if (et5 < 0.00000001) {
    et5 = 1.0;
  }
  // et6 = et6-0.013*(0.5+1.0*randt6/100.0);
  et6 = et6+0.011*(0.75+1.0*randt6/100.0);
  if (et6 > 0.99999999) {
    et6 = 0.0;
  } else if (et6 < 0.00000001) {
    et6 = 1.0;
  }
  et7 = et7+0.005*(0.75+1.0*randt7/100.0);
  if (et7 > 0.99999999) {
    et7 = 0.0;
  } else if (et7 < 0.00000001) {
    et7 = 1.0;
  }

  // et1 = 0;
  // et2 = 0;
  // et3 = 0;
  // et4 = 0;
  // et5 = 0;
  // et6 = 0;
  // et7 = 0;
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

void WaterCycle(float etb, float etc1, float etc2, float etm, float etw1, float etw2, float etw3, float B, int wait) {
  int b;
  int c1;
  int c2;
  int m;
  int w1;
  int w2;
  int w3;
  float intensityb = 0.0; // modifier to the pixel brightness (0 to 1)
  float intensityc1 = 0.0;
  float intensityc2 = 0.0;
  float intensitym = 0.0;
  float intensityw1 = 0.0;
  float intensityw2 = 0.0;
  float intensityw3 = 0.0;
  float ts1 = 2.0;
  float ts2 = 5.0;
  float ts3 = 7.0;
  float ts4 = 5.0;
  float ts5 = 23.0;
  float ts6 = 29.0;
  float ts7 = 19.0;

  for(int i=0; i<40; i++) {
    float ep = fmodf(i,1.0*40)/(1.0*40);
    float epw = fmodf(i+15,1.0*40)/(1.0*40);
    TriangleEnvelope(&intensityb,ep,etb,ts1);
    TriangleEnvelope(&intensityc1,ep,etc1,ts2);
    TriangleEnvelope(&intensityc2,ep,etc2,ts3);
    TriangleEnvelope(&intensitym,ep,etm,ts4);
    TriangleEnvelope(&intensityw1,epw,etw1,ts5);
    TriangleEnvelope(&intensityw2,epw,etw2,ts6);
    TriangleEnvelope(&intensityw3,epw,etw3,ts7);
    b = 255 * B * intensityb;
    c1 = 133 * B * intensityc1;
    c2 = 100 * B * intensityc2;
    m = 255 * B * intensitym;
    w1 = 255 * B * intensityw1;
    w2 = 255 * B * intensityw2;
    w3 = 255 * B * intensityw3;
    strip.setPixelColor(i, m+w1+w2+w3, c1+c2+w1+w2+w3, b+c1+c2+m+w1+w2+w3);
    strip.setPixelColor(79-i, m+w1+w2+w3, c1+c2+w1+w2+w3, b+c1+c2+m+w1+w2+w3);
    // strip.setPixelColor(i, 0, c1+c2, c1+c2);
    // strip.setPixelColor(79-i, 0, c1+c2, c1+c2);
    // strip.setPixelColor(i, w1+w2+w3, w1+w2+w3, w1+w2+w3);
    // strip.setPixelColor(79-i, w1+w2+w3, w1+w2+w3, w1+w2+w3);
  }

  for(int i=80; i<104; i++) {
    // float ep = fmodf(i-80,104.0-80.0)/(104.0-80.0);
    float ep = fmodf(i+2-80,104.0-80.0)/(104.0-80.0);
    float epw = fmodf(i-80,1.0*(142.0-80.0))/(1.0*(142.0-80.0));
    TriangleEnvelope(&intensityb,ep,etb,ts1);
    TriangleEnvelope(&intensityc1,ep,etc1,ts2);
    TriangleEnvelope(&intensityc2,ep,etc2,ts3);
    TriangleEnvelope(&intensitym,ep,etm,ts4);
    TriangleEnvelope(&intensityw1,epw,etw1,ts5);
    TriangleEnvelope(&intensityw2,epw,etw2,ts6);
    TriangleEnvelope(&intensityw3,epw,etw3,ts7);
    b = 150 * B * intensityb;
    c1 = 80 * B * intensityc1;
    c2 = 60 * B * intensityc2;
    m = 150 * B * intensitym;
    w1 = 255 * B * intensityw1;
    w2 = 255 * B * intensityw2;
    w3 = 255 * B * intensityw3;
    strip.setPixelColor(103-(i-80), m+w1+w2+w3, c1+c2+w1+w2+w3, b+c1+c2+m+w1+w2+w3);
    // strip.setPixelColor(103-(i-80), 0, c1+c2, c1+c2);
    // strip.setPixelColor(103-(i-80), w1+w2+w3, w1+w2+w3, w1+w2+w3);
  }
  for(int i=104; i<119; i++) {
    // float ep = fmodf(i-104,119.0-104.0)/(119.0-104.0);
    float ep = fmodf(i+0.25-104,119.0-104.0)/(119.0-104.0);
    float epw = fmodf(i-57,1.0*(142.0-80.0))/(1.0*(142.0-80.0));
    TriangleEnvelope(&intensityb,ep,etb,ts1);
    TriangleEnvelope(&intensityc1,ep,etc1,ts2);
    TriangleEnvelope(&intensityc2,ep,etc2,ts3);
    TriangleEnvelope(&intensitym,ep,etm,ts4);
    TriangleEnvelope(&intensityw1,epw,etw1,ts5);
    TriangleEnvelope(&intensityw2,epw,etw2,ts6);
    TriangleEnvelope(&intensityw3,epw,etw3,ts7);
    b = 150 * B * intensityb;
    c1 = 80 * B * intensityc1;
    c2 = 60 * B * intensityc2;
    m = 150 * B * intensitym;
    w1 = 255 * B * intensityw1;
    w2 = 255 * B * intensityw2;
    w3 = 255 * B * intensityw3;
    strip.setPixelColor(118-(i-104), m+w1+w2+w3, c1+c2+w1+w2+w3, b+c1+c2+m+w1+w2+w3);
    strip.setPixelColor(165+(i-104), m+w1+w2+w3, c1+c2+w1+w2+w3, b+c1+c2+m+w1+w2+w3);
    // strip.setPixelColor(118-(i-104), 0, c1+c2, c1+c2);
    // strip.setPixelColor(165+(i-104), 0, c1+c2, c1+c2);
    // strip.setPixelColor(118-(i-104), w1+w2+w3, w1+w2+w3, w1+w2+w3);
    // strip.setPixelColor(165+(i-104), w1+w2+w3, w1+w2+w3, w1+w2+w3);
  }
  for(int i=119; i<129; i++) {
    // float ep = fmodf(i-119,129.0-119.0)/(129.0-119.0);
    float ep = fmodf(i+10.2-119,129.0-119.0)/(129.0-119.0);
    float epw = fmodf(i-82,1.0*(142.0-80.0))/(1.0*(142.0-80.0));
    TriangleEnvelope(&intensityb,ep,etb,ts1);
    TriangleEnvelope(&intensityc1,ep,etc1,ts2);
    TriangleEnvelope(&intensityc2,ep,etc2,ts3);
    TriangleEnvelope(&intensitym,ep,etm,ts4);
    TriangleEnvelope(&intensityw1,epw,etw1,ts5);
    TriangleEnvelope(&intensityw2,epw,etw2,ts6);
    TriangleEnvelope(&intensityw3,epw,etw3,ts7);
    b = 150 * B * intensityb;
    c1 = 80 * B * intensityc1;
    c2 = 60 * B * intensityc2;
    m = 150 * B * intensitym;
    w1 = 255 * B * intensityw1;
    w2 = 255 * B * intensityw2;
    w3 = 255 * B * intensityw3;
    strip.setPixelColor(128-(i-119), m+w1+w2+w3, c1+c2+w1+w2+w3, b+c1+c2+m+w1+w2+w3);
    strip.setPixelColor(155+(i-119), m+w1+w2+w3, c1+c2+w1+w2+w3, b+c1+c2+m+w1+w2+w3);
    // strip.setPixelColor(128-(i-119), 0, c1+c2, c1+c2);
    // strip.setPixelColor(155+(i-119), 0, c1+c2, c1+c2);
    // strip.setPixelColor(128-(i-119), w1+w2+w3, w1+w2+w3, w1+w2+w3);
    // strip.setPixelColor(155+(i-119), w1+w2+w3, w1+w2+w3, w1+w2+w3);
  }
  for(int i=129; i<136; i++) {
    // float ep = fmodf(i-129,136.0-129.0)/(136.0-129.0);
    float ep = fmodf(i+7.5-129,136.0-129.0)/(136.0-129.0);
    float epw = fmodf(i-99,1.0*(142.0-80.0))/(1.0*(142.0-80.0));
    TriangleEnvelope(&intensityb,ep,etb,ts1);
    TriangleEnvelope(&intensityc1,ep,etc1,ts2);
    TriangleEnvelope(&intensityc2,ep,etc2,ts3);
    TriangleEnvelope(&intensitym,ep,etm,ts4);
    TriangleEnvelope(&intensityw1,epw,etw1,ts5);
    TriangleEnvelope(&intensityw2,epw,etw2,ts6);
    TriangleEnvelope(&intensityw3,epw,etw3,ts7);
    b = 150 * B * intensityb;
    c1 = 80 * B * intensityc1;
    c2 = 60 * B * intensityc2;
    m = 150 * B * intensitym;
    w1 = 255 * B * intensityw1;
    w2 = 255 * B * intensityw2;
    w3 = 255 * B * intensityw3;
    strip.setPixelColor(135-(i-129), m+w1+w2+w3, c1+c2+w1+w2+w3, b+c1+c2+m+w1+w2+w3);
    // strip.setPixelColor(135-(i-129), 0, c1+c2, c1+c2);
    // strip.setPixelColor(135-(i-129), w1+w2+w3, w1+w2+w3, w1+w2+w3);
  }
  for(int i=136; i<141; i++) {
    // float ep = fmodf(i-136,141.0-136.0)/(141.0-136.0);
    float ep = fmodf(i+4.75-136,141.0-136.0)/(141.0-136.0);
    float epw = fmodf(i-49,1.0*(142.0-80.0))/(1.0*(142.0-80.0));
    TriangleEnvelope(&intensityb,ep,etb,ts1);
    TriangleEnvelope(&intensityc1,ep,etc1,ts2);
    TriangleEnvelope(&intensityc2,ep,etc2,ts3);
    TriangleEnvelope(&intensitym,ep,etm,ts4);
    TriangleEnvelope(&intensityw1,epw,etw1,ts5);
    TriangleEnvelope(&intensityw2,epw,etw2,ts6);
    TriangleEnvelope(&intensityw3,epw,etw3,ts7);
    b = 150 * B * intensityb;
    c1 = 80 * B * intensityc1;
    c2 = 60 * B * intensityc2;
    m = 150 * B * intensitym;
    w1 = 255 * B * intensityw1;
    w2 = 255 * B * intensityw2;
    w3 = 255 * B * intensityw3;
    strip.setPixelColor(140-(i-136), m+w1+w2+w3, c1+c2+w1+w2+w3, b+c1+c2+m+w1+w2+w3);
    strip.setPixelColor(142+(i-136), m+w1+w2+w3, c1+c2+w1+w2+w3, b+c1+c2+m+w1+w2+w3);
    // strip.setPixelColor(140-(i-136), 0, c1+c2, c1+c2);
    // strip.setPixelColor(142+(i-136), 0, c1+c2, c1+c2);
    // strip.setPixelColor(140-(i-136), w1+w2+w3, w1+w2+w3, w1+w2+w3);
    // strip.setPixelColor(142+(i-136), w1+w2+w3, w1+w2+w3, w1+w2+w3);
  }
  float ep = 0;
  float epw = 0.393;
  TriangleEnvelope(&intensityb,ep,etb,ts1);
  TriangleEnvelope(&intensityc1,ep,etc1,ts2);
  TriangleEnvelope(&intensityc2,ep,etc2,ts3);
  TriangleEnvelope(&intensitym,ep,etm,ts4);
  TriangleEnvelope(&intensityw1,epw,etw1,ts5);
  TriangleEnvelope(&intensityw2,epw,etw2,ts6);
  TriangleEnvelope(&intensityw3,epw,etw3,ts7);
  b = 150 * B * intensityb;
  c1 = 80 * B * intensityc1;
  c2 = 60 * B * intensityc2;
  m = 150 * B * intensitym;
  w1 = 255 * B * intensityw1;
  w2 = 255 * B * intensityw2;
  w3 = 255 * B * intensityw3;
  strip.setPixelColor(141, m+w1+w2+w3, c1+c2+w1+w2+w3, b+c1+c2+m+w1+w2+w3);
  // strip.setPixelColor(141, 0, c1+c2, c1+c2);
  // strip.setPixelColor(141, w1+w2+w3, w1+w2+w3, w1+w2+w3);

  for(int i=180; i<206; i++) {
    float ep = fmodf(i-180,206.0-180.0)/(206.0-180.0);
    float epw = fmodf(i-180,206.0-142.0)/(206.0-142.0);
    TriangleEnvelope(&intensityb,ep,etb,ts1);
    TriangleEnvelope(&intensityc1,ep,etc1,ts2);
    TriangleEnvelope(&intensityc2,ep,etc2,ts3);
    TriangleEnvelope(&intensitym,ep,etm,ts4);
    TriangleEnvelope(&intensityw1,epw,etw1,ts5);
    TriangleEnvelope(&intensityw2,epw,etw2,ts6);
    TriangleEnvelope(&intensityw3,epw,etw3,ts7);
    b = 150 * B * intensityb;
    c1 = 80 * B * intensityc1;
    c2 = 60 * B * intensityc2;
    m = 150 * B * intensitym;
    w1 = 255 * B * intensityw1;
    w2 = 255 * B * intensityw2;
    w3 = 255 * B * intensityw3;
    strip.setPixelColor(i, m+w1+w2+w3, c1+c2+w1+w2+w3, b+c1+c2+m+w1+w2+w3);
    // strip.setPixelColor(i, 0, c1+c2, c1+c2);
    // strip.setPixelColor(i, w1+w2+w3, w1+w2+w3, w1+w2+w3);
  }
  for(int i=147; i<155; i++) {
    // float ep = fmodf(i-147,155.0-147.0)/(155.0-147.0);
    float ep = fmodf(i+8.5-147,155.0-147.0)/(155.0-147.0);
    float epw = fmodf(i-117,206.0-142.0)/(206.0-142.0);
    TriangleEnvelope(&intensityb,ep,etb,ts1);
    TriangleEnvelope(&intensityc1,ep,etc1,ts2);
    TriangleEnvelope(&intensityc2,ep,etc2,ts3);
    TriangleEnvelope(&intensitym,ep,etm,ts4);
    TriangleEnvelope(&intensityw1,epw,etw1,ts5);
    TriangleEnvelope(&intensityw2,epw,etw2,ts6);
    TriangleEnvelope(&intensityw3,epw,etw3,ts7);
    b = 150 * B * intensityb;
    c1 = 80 * B * intensityc1;
    c2 = 60 * B * intensityc2;
    m = 150 * B * intensitym;
    w1 = 255 * B * intensityw1;
    w2 = 255 * B * intensityw2;
    w3 = 255 * B * intensityw3;
    strip.setPixelColor(i, m+w1+w2+w3, c1+c2+w1+w2+w3, b+c1+c2+m+w1+w2+w3);
    // strip.setPixelColor(i, 0, c1+c2, c1+c2);
    // strip.setPixelColor(i, w1+w2+w3, w1+w2+w3, w1+w2+w3);
  }

  strip.show();
  delay(wait);
}