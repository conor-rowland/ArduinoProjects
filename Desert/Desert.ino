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
int randP = 0;
int randt = 0;
float P = 0;
float P2 = 0;
float et = 0.0;
void loop() {
  // RainbowCycleSymmetric(P, 0.2, 17);
  // RainbowCycleSymmetric_Comet(P, 0.2, et, 5);
  // RainbowCycleRotate(P, 0.2, 25);
  // RainbowCycleRotate_Comet(P, 0.2, et, 5);
  // RainbowCycleOG(P, 0.2, 17);
  // RainbowCycleComplete(P, 0.2, 17);
  // RainbowCycleOG_Comet(P, 0.2, et, 17);

  // DoubleRainbowSymmetric(P, P2, 0.125, 17);

  // RedCycleSymmetric(P, 0.35, 5);
  RedCycleSymmetric_Comet(P, 0.35, et, 5);
  // RedCycleRotate(P, 0.35, 25);
  // RedCycleRotate_Comet(P, 0.35, et, 5);

  // SolidRainbowCycle(P, 0.2, 50);

  randt = randt + ((rand() % 21)-10);
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

  P = P-1*(0.7+0.2*randP/100.0);
  // P = P-1*(0.0+1.5*randP/100.0);
  if (P < 0) {
    P = 100;
  } else if (P > 100) {
    P = 0;
  }
  // P = P+1;
  // if (P > 99) {
  //   P = 0;
  // }
  // P2 = P2+1*(1.75+2.5*randP/100.0);
  // // P = P-1*(0.0+1.5*randP/100.0);
  // if (P2 < 0) {
  //   P2 = 100;
  // } else if (P2 > 100) {
  //   P2 = 0;
  // }

  et = et+0.007*(1.0+1.5*randt/100.0);
  // et = et+0.007*(1.0+2.0*randt/100.0);
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

void RainbowCycleOG(float P, float B, int wait) {
  static int rgb[3];

  // Spine 
  for(int i=22; i<36; i++) {
    RainbowCycle(fmodf(P+100.0/14*(i-22),100),B,rgb);
    strip.setPixelColor(i, rgb[0], rgb[1], rgb[2]);
  }

  // Hem total per side = 75
  // Top hem
  for(int i=36; i<53; i++) {
    RainbowCycle(fmodf(P+1.67*100.0/75*(i-36),100),B,rgb);
    strip.setPixelColor(i, rgb[0], rgb[1], rgb[2]);
    strip.setPixelColor(185-(i-36), rgb[0], rgb[1], rgb[2]);
  }

  // Side hem
  for(int i=53; i<85; i++) {
    RainbowCycle(fmodf(P+1.67*100.0/75*(i-36),100),B,rgb);
    strip.setPixelColor(i, rgb[0], rgb[1], rgb[2]);
    strip.setPixelColor(168-(i-53), rgb[0], rgb[1], rgb[2]);
  }

  // Bottom hem
  for(int i=85; i<111; i++) {
    RainbowCycle(fmodf(P+1.67*100.0/75*(i-36),100),B,rgb);
    strip.setPixelColor(i, rgb[0], rgb[1], rgb[2]);
    strip.setPixelColor(136-(i-85), rgb[0], rgb[1], rgb[2]);
  }

  // Outer diamond
  for(int i=189; i<216; i++) {
    RainbowCycle(fmodf(P+fmodf(100.0/14*10,100)+100.0/27*(i-189),100),B,rgb);
    strip.setPixelColor(i, rgb[0], rgb[1], rgb[2]);
    strip.setPixelColor(241-(i-189), rgb[0], rgb[1], rgb[2]);
  }
  strip.setPixelColor(189, 0, 0, 0);
  strip.setPixelColor(241, 0, 0, 0);

  strip.show();
  delay(wait);
}


void RainbowCycleComplete(float P, float B, int wait) {
  static int rgb[3];

  // Spine 
  for(int i=22; i<36; i++) {
    RainbowCycle(fmodf(P+100.0/14*(i-22),100),B,rgb);
    strip.setPixelColor(i, rgb[0], rgb[1], rgb[2]);
  }

  // Hem total per side = 75
  // Top hem
  for(int i=36; i<53; i++) {
    RainbowCycle(fmodf(P+1.67*100.0/75*(i-36),100),B,rgb);
    strip.setPixelColor(i, rgb[0], rgb[1], rgb[2]);
    strip.setPixelColor(185-(i-36), rgb[0], rgb[1], rgb[2]);
  }

  // Side hem
  for(int i=53; i<85; i++) {
    RainbowCycle(fmodf(P+1.67*100.0/75*(i-36),100),B,rgb);
    strip.setPixelColor(i, rgb[0], rgb[1], rgb[2]);
    strip.setPixelColor(168-(i-53), rgb[0], rgb[1], rgb[2]);
  }

  // Bottom hem
  for(int i=85; i<111; i++) {
    RainbowCycle(fmodf(P+1.67*100.0/75*(i-36),100),B,rgb);
    strip.setPixelColor(i, rgb[0], rgb[1], rgb[2]);
    strip.setPixelColor(136-(i-85), rgb[0], rgb[1], rgb[2]);
  }

  // Outer diamond
  for(int i=189; i<216; i++) {
    // RainbowCycle(fmodf(P+fmodf(100.0/14*10,100)+100.0/27*(i-189),100),B,rgb);
    RainbowCycle(fmodf(P+71.42867+3.704*(i-189),100),B,rgb);
    strip.setPixelColor(i, rgb[0], rgb[1], rgb[2]);
    strip.setPixelColor(241-(i-189), rgb[0], rgb[1], rgb[2]);
  }
  strip.setPixelColor(189, 0, 0, 0);
  strip.setPixelColor(241, 0, 0, 0);

  // Middle diamond
  for(int i=243; i<262; i++) {
    RainbowCycle(fmodf(P+39+7.0*(i-243),100),B,rgb);//+fmodf(100.0/14*10,100)
    strip.setPixelColor(i, rgb[0], rgb[1], rgb[2]);
    strip.setPixelColor(279-(i-243), rgb[0], rgb[1], rgb[2]);
  }
  strip.setPixelColor(243, 0, 0, 0);
  strip.setPixelColor(279, 0, 0, 0);

  // Inner diamond
  for(int i=281; i<292; i++) {
    RainbowCycle(fmodf(P+10+15.1*(i-281),100),B,rgb);
    strip.setPixelColor(i, rgb[0], rgb[1], rgb[2]);
    strip.setPixelColor(301-(i-281), rgb[0], rgb[1], rgb[2]);
  }
  strip.setPixelColor(281, 0, 0, 0);
  strip.setPixelColor(301, 0, 0, 0);

  strip.show();
  delay(wait);
}


void RainbowCycleOG_Comet(float P, float B, float et, int wait) {
  static int rgb[3];
  float intensity = 0.0; // modifier to the pixel brightness (0 to 1)

  // Spine 
  for(int i=22; i<36; i++) {
    float ep = 0.42*(i+24-22.0)/(36.0-22.0);
    CometEnvelope(&intensity,ep,et);
    float eB = B*intensity;
    RainbowCycle(fmodf(P+100.0/14*(i-22),100),eB,rgb);
    strip.setPixelColor(i, rgb[0], rgb[1], rgb[2]);
  }

  // Hem total per side = 75
  // Top hem
  for(int i=36; i<53; i++) {
    float ep = fmodf((i+3-36.0),25)/25.0;
    CometEnvelope(&intensity,ep,et);
    float eB = B*intensity;
    RainbowCycle(fmodf(P+1.67*100.0/75*(i-36),100),eB,rgb);
    strip.setPixelColor(i, rgb[0], rgb[1], rgb[2]);
    strip.setPixelColor(185-(i-36), rgb[0], rgb[1], rgb[2]);
  }

  // Side hem
  for(int i=53; i<85; i++) {
    float ep = fmodf(((i+3+17)-53.0),25)/25.0;
    CometEnvelope(&intensity,ep,et);
    float eB = B*intensity;
    RainbowCycle(fmodf(P+1.67*100.0/75*(i-36),100),eB,rgb);
    strip.setPixelColor(i, rgb[0], rgb[1], rgb[2]);
    strip.setPixelColor(168-(i-53), rgb[0], rgb[1], rgb[2]);
  }

  // Bottom hem
  for(int i=85; i<111; i++) {
    float ep = fmodf(((i+3+24)-85.0),25)/25.0;
    CometEnvelope(&intensity,ep,et);
    float eB = B*intensity;
    RainbowCycle(fmodf(P+1.67*100.0/75*(i-36),100),eB,rgb);
    strip.setPixelColor(i, rgb[0], rgb[1], rgb[2]);
    strip.setPixelColor(136-(i-85), rgb[0], rgb[1], rgb[2]);
  }

  // Outer diamond
  for(int i=189; i<216; i++) {
    float ep = (i-189.0)/(216.0-189.0);
    CometEnvelope(&intensity,ep,et);
    float eB = B*intensity;
    RainbowCycle(fmodf(P+fmodf(100.0/14*10,100)+100.0/27*(i-189),100),eB,rgb);
    strip.setPixelColor(i, rgb[0], rgb[1], rgb[2]);
    strip.setPixelColor(241-(i-189), rgb[0], rgb[1], rgb[2]);
  }
  strip.setPixelColor(189, 0, 0, 0);
  strip.setPixelColor(241, 0, 0, 0);

  strip.show();
  delay(wait);
}


void RainbowCycleSymmetric(float P, float B, int wait) {
  static int rgb[3];

  // Hem total per side = 75
  // Top hem
  for(int i=36; i<53; i++) {
    RainbowCycle(fmodf(P+2.0*100.0/75*(i-36),100),B,rgb);
    strip.setPixelColor(i, rgb[0], rgb[1], rgb[2]);
    strip.setPixelColor(185-(i-36), rgb[0], rgb[1], rgb[2]);
  }

  // Side hem
  for(int i=53; i<85; i++) {
    RainbowCycle(fmodf(P+2.0*100.0/75*(i-36),100),B,rgb);
    strip.setPixelColor(i, rgb[0], rgb[1], rgb[2]);
    strip.setPixelColor(168-(i-53), rgb[0], rgb[1], rgb[2]);
  }

  // Bottom hem
  for(int i=85; i<111; i++) {
    RainbowCycle(fmodf(P+2.0*100.0/75*(i-36),100),B,rgb);
    strip.setPixelColor(i, rgb[0], rgb[1], rgb[2]);
    strip.setPixelColor(136-(i-85), rgb[0], rgb[1], rgb[2]);
  }

  // Outer diamond
  for(int i=189; i<216; i++) {
    RainbowCycle(fmodf(P+100.0/27*(i-189),100),B,rgb);
    strip.setPixelColor(i, rgb[0], rgb[1], rgb[2]);
    strip.setPixelColor(241-(i-189), rgb[0], rgb[1], rgb[2]);
  }
  strip.setPixelColor(241, 0, 0, 0);

  // Middle diamond
  for(int i=243; i<262; i++) {
    RainbowCycle(fmodf(P+100.0/19*(i-243),100),B,rgb);
    strip.setPixelColor(i, rgb[0], rgb[1], rgb[2]);
    strip.setPixelColor(279-(i-243), rgb[0], rgb[1], rgb[2]);
  }
  strip.setPixelColor(279, 0, 0, 0);

  // Inner diamond
  for(int i=281; i<292; i++) {
    RainbowCycle(fmodf(P+100.0/11*(i-281),100),B,rgb);
    strip.setPixelColor(i, rgb[0], rgb[1], rgb[2]);
    strip.setPixelColor(301-(i-281), rgb[0], rgb[1], rgb[2]);
  }
  strip.setPixelColor(301, 0, 0, 0);

  strip.show();
  delay(wait);
}


void DoubleRainbowSymmetric(float P, float P2, float B, int wait) {
  static int rgb[3];
  static int rgb2[3];

  // Hem total per side = 75
  // Top hem
  for(int i=36; i<53; i++) {
    RainbowCycle(fmodf(P+2.0*100.0/75*(i-36),100),B,rgb);
    RainbowCycle(fmodf(P2+4.55*100.0/75*(i+16.5-36),100),B,rgb2);
    strip.setPixelColor(i, rgb[0]+rgb2[0], rgb[1]+rgb2[1], rgb[2]+rgb2[2]);
    strip.setPixelColor(185-(i-36), rgb[0]+rgb2[0], rgb[1]+rgb2[1], rgb[2]+rgb2[2]);
  }

  // Side hem
  for(int i=53; i<85; i++) {
    RainbowCycle(fmodf(P+2.0*100.0/75*(i-36),100),B,rgb);
    RainbowCycle(fmodf(P2+4.55*100.0/75*(i+16.5-36),100),B,rgb2);
    strip.setPixelColor(i, rgb[0]+rgb2[0], rgb[1]+rgb2[1], rgb[2]+rgb2[2]);
    strip.setPixelColor(168-(i-53), rgb[0]+rgb2[0], rgb[1]+rgb2[1], rgb[2]+rgb2[2]);
  }

  // Bottom hem
  for(int i=85; i<111; i++) {
    RainbowCycle(fmodf(P+2.0*100.0/75*(i-36),100),B,rgb);
    RainbowCycle(fmodf(P2+4.55*100.0/75*(i+16.5-36),100),B,rgb2);
    strip.setPixelColor(i, rgb[0]+rgb2[0], rgb[1]+rgb2[1], rgb[2]+rgb2[2]);
    strip.setPixelColor(136-(i-85), rgb[0]+rgb2[0], rgb[1]+rgb2[1], rgb[2]+rgb2[2]);
  }

  // Outer diamond
  for(int i=189; i<216; i++) {
    RainbowCycle(fmodf(P+100.0/27*(i-189),100),B,rgb);
    RainbowCycle(fmodf(P2+2.5*100.0/27*(i-189),100),B,rgb2);
    strip.setPixelColor(i, rgb[0]+rgb2[0], rgb[1]+rgb2[1], rgb[2]+rgb2[2]);
    strip.setPixelColor(241-(i-189), rgb[0]+rgb2[0], rgb[1]+rgb2[1], rgb[2]+rgb2[2]);
  }
  strip.setPixelColor(241, 0, 0, 0);

  // Middle diamond
  for(int i=243; i<262; i++) {
    RainbowCycle(fmodf(P+100.0/19*(i-243),100),B,rgb);
    RainbowCycle(fmodf(P2+2.5*100.0/19*(i-243),100),B,rgb2);
    strip.setPixelColor(i, rgb[0]+rgb2[0], rgb[1]+rgb2[1], rgb[2]+rgb2[2]);
    strip.setPixelColor(279-(i-243), rgb[0]+rgb2[0], rgb[1]+rgb2[1], rgb[2]+rgb2[2]);
  }
  strip.setPixelColor(279, 0, 0, 0);

  // Inner diamond
  for(int i=281; i<292; i++) {
    RainbowCycle(fmodf(P+100.0/11*(i-281),100),B,rgb);
    RainbowCycle(fmodf(P2+2.5*100.0/11*(i-281),100),B,rgb2);
    strip.setPixelColor(i, rgb[0]+rgb2[0], rgb[1]+rgb2[1], rgb[2]+rgb2[2]);
    strip.setPixelColor(301-(i-281), rgb[0]+rgb2[0], rgb[1]+rgb2[1], rgb[2]+rgb2[2]);
  }
  strip.setPixelColor(301, 0, 0, 0);

  strip.show();
  delay(wait);
}


void RainbowCycleSymmetric_Comet(float P, float B, float et, int wait) {
  static int rgb[3];
  float intensity = 0.0; // modifier to the pixel brightness (0 to 1)

  // Hem total per side = 75
  // Top hem
  for(int i=36; i<53; i++) {
    float ep = fmodf((i-36.0),25)/25.0;
    CometEnvelope(&intensity,ep,et);
    float eB = B*intensity;
    RainbowCycle(fmodf(P+2.0*100.0/75*(i-36),100),eB,rgb);
    strip.setPixelColor(i, rgb[0], rgb[1], rgb[2]);
    strip.setPixelColor(185-(i-36), rgb[0], rgb[1], rgb[2]);
  }

  // Side hem
  for(int i=53; i<85; i++) {
    float ep = fmodf(((i+17)-53.0),25)/25.0;
    CometEnvelope(&intensity,ep,et);
    float eB = B*intensity;
    RainbowCycle(fmodf(P+2.0*100.0/75*(i-36),100),eB,rgb);
    strip.setPixelColor(i, rgb[0], rgb[1], rgb[2]);
    strip.setPixelColor(168-(i-53), rgb[0], rgb[1], rgb[2]);
  }

  // Bottom hem
  for(int i=85; i<111; i++) {
    float ep = fmodf(((i+24)-85.0),25)/25.0;
    CometEnvelope(&intensity,ep,et);
    float eB = B*intensity;
    RainbowCycle(fmodf(P+2.0*100.0/75*(i-36),100),eB,rgb);
    strip.setPixelColor(i, rgb[0], rgb[1], rgb[2]);
    strip.setPixelColor(136-(i-85), rgb[0], rgb[1], rgb[2]);
  }

  // Outer diamond
  for(int i=189; i<216; i++) {
    float ep = (i-189.0)/(216.0-189.0);
    CometEnvelope(&intensity,ep,et);
    float eB = B*intensity;
    RainbowCycle(fmodf(P+100.0/27*(i-189),100),eB,rgb);
    strip.setPixelColor(i, rgb[0], rgb[1], rgb[2]);
    strip.setPixelColor(241-(i-189), rgb[0], rgb[1], rgb[2]);
  }
  strip.setPixelColor(241, 0, 0, 0);

  // Middle diamond
  for(int i=243; i<262; i++) {
    float ep = (i-243.0)/(262.0-243.0);
    CometEnvelope(&intensity,ep,et);
    float eB = B*intensity;
    RainbowCycle(fmodf(P+100.0/19*(i-243),100),eB,rgb);
    strip.setPixelColor(i, rgb[0], rgb[1], rgb[2]);
    strip.setPixelColor(279-(i-243), rgb[0], rgb[1], rgb[2]);
  }
  strip.setPixelColor(279, 0, 0, 0);

  // Inner diamond
  for(int i=281; i<292; i++) {
    float ep = (i-281.0)/(292.0-281.0);
    CometEnvelope(&intensity,ep,et);
    float eB = B*intensity;
    RainbowCycle(fmodf(P+100.0/11*(i-281),100),eB,rgb);
    strip.setPixelColor(i, rgb[0], rgb[1], rgb[2]);
    strip.setPixelColor(301-(i-281), rgb[0], rgb[1], rgb[2]);
  }
  strip.setPixelColor(301, 0, 0, 0);

  strip.show();
  delay(wait);
}


void RedCycleSymmetric(float P, float B, int wait) {
  static int rgb[3];

  // Hem total per side = 75
  // Top hem
  for(int i=36; i<53; i++) {
    RedCycle(fmodf(P+2*100.0/75*(i-36),100),B,rgb);
    strip.setPixelColor(i, rgb[0], rgb[1], rgb[2]);
    strip.setPixelColor(185-(i-36), rgb[0], rgb[1], rgb[2]);
  }

  // Side hem
  for(int i=53; i<85; i++) {
    RedCycle(fmodf(P+2*100.0/75*(i-36),100),B,rgb);
    strip.setPixelColor(i, rgb[0], rgb[1], rgb[2]);
    strip.setPixelColor(168-(i-53), rgb[0], rgb[1], rgb[2]);
  }

  // Bottom hem
  for(int i=85; i<111; i++) {
    RedCycle(fmodf(P+2*100.0/75*(i-36),100),B,rgb);
    strip.setPixelColor(i, rgb[0], rgb[1], rgb[2]);
    strip.setPixelColor(136-(i-85), rgb[0], rgb[1], rgb[2]);
  }

  // Outer diamond
  for(int i=189; i<216; i++) {
    RedCycle(fmodf(P+100.0/27*(i-189),100),B,rgb);
    strip.setPixelColor(i, rgb[0], rgb[1], rgb[2]);
    strip.setPixelColor(241-(i-189), rgb[0], rgb[1], rgb[2]);
  }
  strip.setPixelColor(241, 0, 0, 0);

  // Middle diamond
  for(int i=243; i<262; i++) {
    RedCycle(fmodf(P+100.0/19*(i-243),100),B,rgb);
    strip.setPixelColor(i, rgb[0], rgb[1], rgb[2]);
    strip.setPixelColor(279-(i-243), rgb[0], rgb[1], rgb[2]);
  }
  strip.setPixelColor(279, 0, 0, 0);

  // Inner diamond
  for(int i=281; i<292; i++) {
    RedCycle(fmodf(P+100.0/11*(i-281),100),B,rgb);
    strip.setPixelColor(i, rgb[0], rgb[1], rgb[2]);
    strip.setPixelColor(301-(i-281), rgb[0], rgb[1], rgb[2]);
  }
  strip.setPixelColor(301, 0, 0, 0);

  strip.show();
  delay(wait);
}


void RedCycleSymmetric_Comet(float P, float B, float et, int wait) {
  static int rgb[3];
  float intensity = 0.0; // modifier to the pixel brightness (0 to 1)
  // Serial.print(et);
  // Serial.print("\n");

  // Hem total per side = 75
  // Top hem
  for(int i=36; i<53; i++) {
    // float ep = fmodf((i-36.0),15)/15.0;
    float ep = fmodf((i-36.0),25)/25.0;
    CometEnvelope(&intensity,ep,et);
    float eB = B*intensity;
    RedCycle(fmodf(P+2*100.0/75*(i-36),100),eB,rgb);
    strip.setPixelColor(i, rgb[0], rgb[1], rgb[2]);
    strip.setPixelColor(185-(i-36), rgb[0], rgb[1], rgb[2]);
  }

  // Side hem
  for(int i=53; i<85; i++) {
    // float ep = fmodf(((i+2)-53.0),15)/15.0;
    float ep = fmodf(((i+17)-53.0),25)/25.0;
    CometEnvelope(&intensity,ep,et);
    float eB = B*intensity;
    RedCycle(fmodf(P+2*100.0/75*(i-36),100),eB,rgb);
    strip.setPixelColor(i, rgb[0], rgb[1], rgb[2]);
    strip.setPixelColor(168-(i-53), rgb[0], rgb[1], rgb[2]);
  }

  // Bottom hem
  for(int i=85; i<111; i++) {
    // float ep = fmodf(((i+4)-85.0),15)/15.0;
    float ep = fmodf(((i+24)-85.0),25)/25.0;
    CometEnvelope(&intensity,ep,et);
    float eB = B*intensity;
    RedCycle(fmodf(P+2*100.0/75*(i-36),100),eB,rgb);
    strip.setPixelColor(i, rgb[0], rgb[1], rgb[2]);
    strip.setPixelColor(136-(i-85), rgb[0], rgb[1], rgb[2]);
  }

  // Outer diamond
  for(int i=189; i<216; i++) {
    float ep = (i-189.0)/(216.0-189.0);
    CometEnvelope(&intensity,ep,et);
    float eB = B*intensity;
    RedCycle(fmodf(P+100.0/27*(i-189),100),eB,rgb);
    strip.setPixelColor(i, rgb[0], rgb[1], rgb[2]);
    strip.setPixelColor(241-(i-189), rgb[0], rgb[1], rgb[2]);
  }
  strip.setPixelColor(241, 0, 0, 0);

  // Middle diamond
  for(int i=243; i<262; i++) {
    float ep = (i-243.0)/(262.0-243.0);
    CometEnvelope(&intensity,ep,et);
    float eB = B*intensity;
    RedCycle(fmodf(P+100.0/19*(i-243),100),eB,rgb);
    strip.setPixelColor(i, rgb[0], rgb[1], rgb[2]);
    strip.setPixelColor(279-(i-243), rgb[0], rgb[1], rgb[2]);
  }
  strip.setPixelColor(279, 0, 0, 0);

  // Inner diamond
  for(int i=281; i<292; i++) {
    float ep = (i-281.0)/(292.0-281.0);
    CometEnvelope(&intensity,ep,et);
    float eB = B*intensity;
    RedCycle(fmodf(P+100.0/11*(i-281),100),eB,rgb);
    strip.setPixelColor(i, rgb[0], rgb[1], rgb[2]);
    strip.setPixelColor(301-(i-281), rgb[0], rgb[1], rgb[2]);
  }
  strip.setPixelColor(301, 0, 0, 0);

  strip.show();
  delay(wait);
}


void RainbowCycleRotate(float P, float B, int wait) {
  static int rgb[3];
  float intensity = 0.0; // modifier to the pixel brightness (0 to 1)

  // Hem total per side = 75
  // Top hem (left) & Bottom hem (right) [36-52 & 111-127]
  for(int i=36; i<53; i++) {
    RainbowCycle(fmodf(P+3*100.0/75*(i-36),100),B,rgb);
    strip.setPixelColor(i, rgb[0], rgb[1], rgb[2]);
    strip.setPixelColor(111+(i-36), rgb[0], rgb[1], rgb[2]);
  }

  // Side hem (left) & Bottom/Side hem (right) [53-84 & 128-159]
  for(int i=53; i<85; i++) {
    RainbowCycle(fmodf(P+3*100.0/75*(i-36),100),B,rgb);
    strip.setPixelColor(i, rgb[0], rgb[1], rgb[2]);
    strip.setPixelColor(128+(i-53), rgb[0], rgb[1], rgb[2]);
  }

  // Bottom hem (left) & Side/Top hem (right) [85-110 & 160-185]
  for(int i=85; i<111; i++) {
    RainbowCycle(fmodf(P+3*100.0/75*(i-36),100),B,rgb);
    strip.setPixelColor(i, rgb[0], rgb[1], rgb[2]);
    strip.setPixelColor(160+(i-85), rgb[0], rgb[1], rgb[2]);
  }

  // Outer diamond
  for(int i=189; i<241; i++) {
    RainbowCycle(fmodf(P+2*100.0/52*(i-189),100),B,rgb);
    strip.setPixelColor(i, rgb[0], rgb[1], rgb[2]);
  }
  strip.setPixelColor(241, 0, 0, 0);

  // Middle diamond
  for(int i=243; i<279; i++) {
    RainbowCycle(fmodf(P+2*100.0/36*(i-243),100),B,rgb);
    strip.setPixelColor(i, rgb[0], rgb[1], rgb[2]);
  }
  strip.setPixelColor(279, 0, 0, 0);

  // Inner diamond
  for(int i=281; i<301; i++) {
    RainbowCycle(fmodf(P+2*100.0/20*(i-281),100),B,rgb);
    strip.setPixelColor(i, rgb[0], rgb[1], rgb[2]);
  }
  strip.setPixelColor(301, 0, 0, 0);

  // Center dot
  strip.setPixelColor(22, int(255*B), 0, 0);

  strip.show();
  delay(wait);
}


void RainbowCycleRotate_Comet(float P, float B, float et, int wait) {
  static int rgb[3];
  float intensity = 0.0; // modifier to the pixel brightness (0 to 1)

  // Hem total per side = 75
  // Top hem (left) & Bottom hem (right) [36-52 & 111-127]
  for(int i=36; i<53; i++) {
    // float ep = fmodf((i-36.0),15)/15.0;
    float ep = fmodf((i-36.0),25)/25.0;
    CometEnvelope(&intensity,ep,et);
    float eB = B*intensity;
    RainbowCycle(fmodf(P+3*100.0/75*(i-36),100),eB,rgb);
    strip.setPixelColor(i, rgb[0], rgb[1], rgb[2]);
    strip.setPixelColor(111+(i-36), rgb[0], rgb[1], rgb[2]);
  }

  // Side hem (left) & Bottom/Side hem (right) [53-84 & 128-159]
  for(int i=53; i<85; i++) {
    // float ep = fmodf(((i+2)-53.0),15)/15.0;
    float ep = fmodf(((i+17)-53.0),25)/25.0;
    CometEnvelope(&intensity,ep,et);
    float eB = B*intensity;
    RainbowCycle(fmodf(P+3*100.0/75*(i-36),100),eB,rgb);
    strip.setPixelColor(i, rgb[0], rgb[1], rgb[2]);
    strip.setPixelColor(128+(i-53), rgb[0], rgb[1], rgb[2]);
  }

  // Bottom hem (left) & Side/Top hem (right) [85-110 & 160-185]
  for(int i=85; i<111; i++) {
    // float ep = fmodf(((i+4)-85.0),15)/15.0;
    float ep = fmodf(((i+24)-85.0),25)/25.0;
    CometEnvelope(&intensity,ep,et);
    float eB = B*intensity;
    RainbowCycle(fmodf(P+3*100.0/75*(i-36),100),eB,rgb);
    strip.setPixelColor(i, rgb[0], rgb[1], rgb[2]);
    strip.setPixelColor(160+(i-85), rgb[0], rgb[1], rgb[2]);
  }

  // Outer diamond
  for(int i=189; i<241; i++) {
    float ep = 2*(i-189.0)/(241.0-189.0);
    CometEnvelope(&intensity,ep,et);
    float eB = B*intensity;
    RainbowCycle(fmodf(P+2*100.0/52*(i-189),100),eB,rgb);
    strip.setPixelColor(i, rgb[0], rgb[1], rgb[2]);
  }
  strip.setPixelColor(241, 0, 0, 0);

  // Middle diamond
  for(int i=243; i<279; i++) {
    float ep = 2*(i-243.0)/(279.0-243.0);
    CometEnvelope(&intensity,ep,et);
    float eB = B*intensity;
    RainbowCycle(fmodf(P+2*100.0/36*(i-243),100),eB,rgb);
    strip.setPixelColor(i, rgb[0], rgb[1], rgb[2]);
  }
  strip.setPixelColor(279, 0, 0, 0);

  // Inner diamond
  for(int i=281; i<301; i++) {
    float ep = 2*(i-281.0)/(301.0-281.0);
    CometEnvelope(&intensity,ep,et);
    float eB = B*intensity;
    RainbowCycle(fmodf(P+2*100.0/20*(i-281),100),eB,rgb);
    strip.setPixelColor(i, rgb[0], rgb[1], rgb[2]);
  }
  strip.setPixelColor(301, 0, 0, 0);

  // Center dot
  RainbowCycle(fmodf(P+100*(1-et),100),B,rgb);
  strip.setPixelColor(22, rgb[0], rgb[1], rgb[2]);

  strip.show();
  delay(wait);
}


void RedCycleRotate(float P, float B, int wait) {
  static int rgb[3];
  float intensity = 0.0; // modifier to the pixel brightness (0 to 1)

  // Hem total per side = 75
  // Top hem (left) & Bottom hem (right) [36-52 & 111-127]
  for(int i=36; i<53; i++) {
    RedCycle(fmodf(P+3*100.0/75*(i-36),100),B,rgb);
    strip.setPixelColor(i, rgb[0], rgb[1], rgb[2]);
    strip.setPixelColor(111+(i-36), rgb[0], rgb[1], rgb[2]);
  }

  // Side hem (left) & Bottom/Side hem (right) [53-84 & 128-159]
  for(int i=53; i<85; i++) {
    RedCycle(fmodf(P+3*100.0/75*(i-36),100),B,rgb);
    strip.setPixelColor(i, rgb[0], rgb[1], rgb[2]);
    strip.setPixelColor(128+(i-53), rgb[0], rgb[1], rgb[2]);
  }

  // Bottom hem (left) & Side/Top hem (right) [85-110 & 160-185]
  for(int i=85; i<111; i++) {
    RedCycle(fmodf(P+3*100.0/75*(i-36),100),B,rgb);
    strip.setPixelColor(i, rgb[0], rgb[1], rgb[2]);
    strip.setPixelColor(160+(i-85), rgb[0], rgb[1], rgb[2]);
  }

  // Outer diamond
  for(int i=189; i<241; i++) {
    RedCycle(fmodf(P+2*100.0/52*(i-189),100),B,rgb);
    strip.setPixelColor(i, rgb[0], rgb[1], rgb[2]);
  }
  strip.setPixelColor(241, 0, 0, 0);

  // Middle diamond
  for(int i=243; i<279; i++) {
    RedCycle(fmodf(P+2*100.0/36*(i-243),100),B,rgb);
    strip.setPixelColor(i, rgb[0], rgb[1], rgb[2]);
  }
  strip.setPixelColor(279, 0, 0, 0);

  // Inner diamond
  for(int i=281; i<301; i++) {
    RedCycle(fmodf(P+2*100.0/20*(i-281),100),B,rgb);
    strip.setPixelColor(i, rgb[0], rgb[1], rgb[2]);
  }
  strip.setPixelColor(301, 0, 0, 0);

  // Center dot
  strip.setPixelColor(22, int(255*B), 0, 0);

  strip.show();
  delay(wait);
}


void RedCycleRotate_Comet(float P, float B, float et, int wait) {
  static int rgb[3];
  float intensity = 0.0; // modifier to the pixel brightness (0 to 1)

  // Hem total per side = 75
  // Top hem (left) & Bottom hem (right) [36-52 & 111-127]
  for(int i=36; i<53; i++) {
    // float ep = fmodf((i-36.0),15)/15.0;
    float ep = fmodf((i-36.0),25)/25.0;
    CometEnvelope(&intensity,ep,et);
    float eB = B*intensity;
    RedCycle(fmodf(P+3*100.0/75*(i-36),100),eB,rgb);
    strip.setPixelColor(i, rgb[0], rgb[1], rgb[2]);
    strip.setPixelColor(111+(i-36), rgb[0], rgb[1], rgb[2]);
  }

  // Side hem (left) & Bottom/Side hem (right) [53-84 & 128-159]
  for(int i=53; i<85; i++) {
    // float ep = fmodf(((i+2)-53.0),15)/15.0;
    float ep = fmodf(((i+17)-53.0),25)/25.0;
    CometEnvelope(&intensity,ep,et);
    float eB = B*intensity;
    RedCycle(fmodf(P+3*100.0/75*(i-36),100),eB,rgb);
    strip.setPixelColor(i, rgb[0], rgb[1], rgb[2]);
    strip.setPixelColor(128+(i-53), rgb[0], rgb[1], rgb[2]);
  }

  // Bottom hem (left) & Side/Top hem (right) [85-110 & 160-185]
  for(int i=85; i<111; i++) {
    // float ep = fmodf(((i+4)-85.0),15)/15.0;
    float ep = fmodf(((i+24)-85.0),25)/25.0;
    CometEnvelope(&intensity,ep,et);
    float eB = B*intensity;
    RedCycle(fmodf(P+3*100.0/75*(i-36),100),eB,rgb);
    strip.setPixelColor(i, rgb[0], rgb[1], rgb[2]);
    strip.setPixelColor(160+(i-85), rgb[0], rgb[1], rgb[2]);
  }

  // Outer diamond
  for(int i=189; i<241; i++) {
    float ep = 2*(i-189.0)/(241.0-189.0);
    CometEnvelope(&intensity,ep,et);
    float eB = B*intensity;
    RedCycle(fmodf(P+2*100.0/52*(i-189),100),eB,rgb);
    strip.setPixelColor(i, rgb[0], rgb[1], rgb[2]);
  }
  strip.setPixelColor(241, 0, 0, 0);

  // Middle diamond
  for(int i=243; i<279; i++) {
    float ep = 2*(i-243.0)/(279.0-243.0);
    CometEnvelope(&intensity,ep,et);
    float eB = B*intensity;
    RedCycle(fmodf(P+2*100.0/36*(i-243),100),eB,rgb);
    strip.setPixelColor(i, rgb[0], rgb[1], rgb[2]);
  }
  strip.setPixelColor(279, 0, 0, 0);

  // Inner diamond
  for(int i=281; i<301; i++) {
    float ep = 2*(i-281.0)/(301.0-281.0);
    CometEnvelope(&intensity,ep,et);
    float eB = B*intensity;
    RedCycle(fmodf(P+2*100.0/20*(i-281),100),eB,rgb);
    strip.setPixelColor(i, rgb[0], rgb[1], rgb[2]);
  }
  strip.setPixelColor(301, 0, 0, 0);

  // Center dot
  RedCycle(fmodf(P+100*(1-et),100),B,rgb);
  strip.setPixelColor(22, rgb[0], rgb[1], rgb[2]);

  strip.show();
  delay(wait);
}


void SolidRainbowCycle(float P, float B, int wait) {
  static int rgb[3];
  RainbowCycle(P,B,rgb);

  // Spine (bottom half)
  for(int i=0; i<22; i++) {
    strip.setPixelColor(i, rgb[0], rgb[1], rgb[2]);
  }
  // Spine (top half)
  for(int i=22; i<36; i++) {
    strip.setPixelColor(i, rgb[0], rgb[1], rgb[2]);
  }
  // Top hem (left side)
  for(int i=36; i<53; i++) {
    strip.setPixelColor(i, rgb[0], rgb[1], rgb[2]);
  }
  // Side hem (left side)
  for(int i=53; i<85; i++) {
    strip.setPixelColor(i, rgb[0], rgb[1], rgb[2]);
  }
  // Bottom hem
  for(int i=85; i<137; i++) {
    strip.setPixelColor(i, rgb[0], rgb[1], rgb[2]);
  }
  // Side hem (right side)
  for(int i=137; i<169; i++) {
    strip.setPixelColor(i, rgb[0], rgb[1], rgb[2]);
  }
  // Top hem (right side)
  for(int i=169; i<186; i++) {
    strip.setPixelColor(i, rgb[0], rgb[1], rgb[2]);
  }
  // Outer diamond
  for(int i=189; i<241; i++) {
    strip.setPixelColor(i, rgb[0], rgb[1], rgb[2]);
  }
  // Middle diamond
  for(int i=243; i<279; i++) {
    strip.setPixelColor(i, rgb[0], rgb[1], rgb[2]);
  }
  // Inner diamond
  for(int i=281; i<301; i++) {
    strip.setPixelColor(i, rgb[0], rgb[1], rgb[2]);
  }

  strip.show();
  delay(wait);
}