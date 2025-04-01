#include <Adafruit_NeoPixel.h>
// #include <Array.h>

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
}

// float pi = 3.141592653;
int numblocks = 6;
// float mew = LED_COUNT/numblocks;
// float sigma = 6;
int th = 0;
// int ishift = 0;
void loop() {
  RainbowCycleSymmetric(th, 1.0, 0.1, 5);
  // RainbowCycleOG(th, 1.0, 0.1, 5);
  // RedCycleSymmetric(th, 1.0, 0.2, 5);

  // SolidRainbowCycle(th, 1.0, 0.1, 1);
  // th = (th + 2)%360;
  th = th-2;
  if (th < 0) {
    th = 360;
  }
}

//----------Define General Use Functions Below----------

void HSLtoRGB(float H, float S, float L, int rgb[3]) {
  // H = Hue and is given in degrees from 0 to 360
  // S = Saturation and is given as a number between 0 and 1
  // L = Lightness and is given as a number between 0 and 1

  float C = (1 - abs(2*L - 1)) * S;  // Chroma
  float Hprime = H/60;
  float X = C * (1 - abs(fmodf(Hprime,2) - 1));

  float r1;
  float g1;
  float b1;
  if (0<=Hprime & Hprime<=1) {
    r1 = C;
    g1 = X;
    b1 = 0;
  } else if (1<=Hprime & Hprime<=2) {
    r1 = X;
    g1 = C;
    b1 = 0;
  } else if (2<=Hprime & Hprime<=3) {
    r1 = 0;
    g1 = C;
    b1 = X;
  } else if (3<=Hprime & Hprime<=4) {
    r1 = 0;
    g1 = X;
    b1 = C;
  } else if (4<=Hprime & Hprime<=5) {
    r1 = X;
    g1 = 0;
    b1 = C;
  } else {
    r1 = C;
    g1 = 0;
    b1 = X;
  }
  
  float m = L - C/2;
  
  rgb[0] = 255 * (r1 + m);
  rgb[1] = 255 * (g1 + m);
  rgb[2] = 255 * (b1 + m);
}

void HSVtoRGB(float H, float S, float V, int rgb[3]) {
  // H = Hue and is given in degrees from 0 to 360
  // S = Saturation and is given as a number between 0 and 1
  // V = Value and is given as a number between 0 and 1

  float C = V * S;  // Chroma
  float Hprime = H/60;
  float X = C * (1 - abs(fmodf(Hprime,2) - 1));

  float r1;
  float g1;
  float b1;
  if (0<=Hprime & Hprime<=1) {
    r1 = C;
    g1 = X;
    b1 = 0;
  } else if (1<=Hprime & Hprime<=2) {
    r1 = X;
    g1 = C;
    b1 = 0;
  } else if (2<=Hprime & Hprime<=3) {
    r1 = 0;
    g1 = C;
    b1 = X;
  } else if (3<=Hprime & Hprime<=4) {
    r1 = 0;
    g1 = X;
    b1 = C;
  } else if (4<=Hprime & Hprime<=5) {
    r1 = X;
    g1 = 0;
    b1 = C;
  } else {
    r1 = C;
    g1 = 0;
    b1 = X;
  }
  
  float m = V - C;
  
  rgb[0] = 255 * (r1 + m);
  rgb[1] = 255 * (g1 + m);
  rgb[2] = 255 * (b1 + m);
}

void RedCycle(float P, float B, int rgb[3]) {
  // P = Percent [percent through the color cycle]
  // B = Brightness [LED brightness on a scale of 0 to 1]

  float Pprime = fmodf(P,60)/60; // amount through the local color change region on a scale of 0 to 1

  float r;
  float g;
  float b;
  if (0<=P & P<60) {
    r = 1.0;
    g = 0.10 * Pprime;
    b = 0.0;
  } else if (60<=P & P<120) {
    r = 1.0;
    g = 0.10 + 0.4 * Pprime;
    b = 0.0;
  } else if (120<=P & P<180) {
    r = 1.0;
    g = 0.5 - 0.15 * Pprime;
    b = 0.0;
  } else if (180<=P & P<240) {
    r = 1.0;
    g = 0.35 - 0.35 * Pprime;
    b = Pprime;
  } else if (240<=P & P<300) {
    r = 1.0;
    g = 0.10 * Pprime;
    b = 1.0 - Pprime;
  } else {
    r = 1.0;
    g = 0.10 - 0.10 * Pprime;
    b = 0.0;
  }
  
  rgb[0] = 255 * B * r;
  rgb[1] = 255 * B * g;
  rgb[2] = 255 * B * b;
}

//----------Define Modes Below----------

void RainbowCycleOG(int H, float S, float LorV, int wait) {
  static int rgb[3];

  // Spine 
  for(int i=22; i<36; i++) {
    // HSVtoRGB(H,S,LorV,rgb);
    HSVtoRGB((H+int(360.0/14*(i-22)))%360,S,LorV,rgb);
    strip.setPixelColor(i, rgb[0], rgb[1], rgb[2]);
    // strip.setPixelColor(35-i, rgb[0], rgb[1], rgb[2]);
  }

  // Hem total per side = 75
  // Top hem
  for(int i=36; i<53; i++) {
    HSVtoRGB((H+int(1.67*360.0/75*(i-36)))%360,S,LorV,rgb);
    strip.setPixelColor(i, rgb[0], rgb[1], rgb[2]);
    strip.setPixelColor(185-(i-36), rgb[0], rgb[1], rgb[2]);
  }

  // Side hem
  for(int i=53; i<85; i++) {
    HSVtoRGB((H+int(1.67*360.0/75*(i-36)))%360,S,LorV,rgb);
    strip.setPixelColor(i, rgb[0], rgb[1], rgb[2]);
    strip.setPixelColor(168-(i-53), rgb[0], rgb[1], rgb[2]);
  }

  // Bottom hem
  for(int i=85; i<111; i++) {
    HSVtoRGB((H+int(1.67*360.0/75*(i-36)))%360,S,LorV,rgb);
    strip.setPixelColor(i, rgb[0], rgb[1], rgb[2]);
    strip.setPixelColor(136-(i-85), rgb[0], rgb[1], rgb[2]);
  }

  // Outer diamond
  for(int i=189; i<216; i++) {
    HSVtoRGB((H+int(360.0/14*10)%360+int(360.0/27*(i-189)))%360,S,LorV,rgb);
    strip.setPixelColor(i, rgb[0], rgb[1], rgb[2]);
    strip.setPixelColor(241-(i-189), rgb[0], rgb[1], rgb[2]);
  }
  strip.setPixelColor(189, 0, 0, 0);
  strip.setPixelColor(241, 0, 0, 0);

  strip.show();
  delay(wait);
}


void RainbowCycleSymmetric(int H, float S, float LorV, int wait) {
  static int rgb[3];

  // Hem total per side = 75
  // Top hem
  for(int i=36; i<53; i++) {
    HSVtoRGB((H+int(2*360.0/75*(i-36)))%360,S,LorV,rgb);
    strip.setPixelColor(i, rgb[0], rgb[1], rgb[2]);
    strip.setPixelColor(185-(i-36), rgb[0], rgb[1], rgb[2]);
  }

  // Side hem
  for(int i=53; i<85; i++) {
    HSVtoRGB((H+int(2*360.0/75*(i-36)))%360,S,LorV,rgb);
    strip.setPixelColor(i, rgb[0], rgb[1], rgb[2]);
    strip.setPixelColor(168-(i-53), rgb[0], rgb[1], rgb[2]);
  }

  // Bottom hem
  for(int i=85; i<111; i++) {
    HSVtoRGB((H+int(2*360.0/75*(i-36)))%360,S,LorV,rgb);
    strip.setPixelColor(i, rgb[0], rgb[1], rgb[2]);
    strip.setPixelColor(136-(i-85), rgb[0], rgb[1], rgb[2]);
  }

  // Outer diamond
  for(int i=189; i<216; i++) {
    HSVtoRGB((H+int(360.0/27*(i-189)))%360,S,LorV,rgb);
    strip.setPixelColor(i, rgb[0], rgb[1], rgb[2]);
    strip.setPixelColor(241-(i-189), rgb[0], rgb[1], rgb[2]);
  }
  strip.setPixelColor(241, 0, 0, 0);

  // Middle diamond
  for(int i=243; i<263; i++) {
    // HSVtoRGB((H+360-int(360.0/19*(i-243)))%360,S,LorV,rgb);
    HSVtoRGB((H+int(360.0/19*(i-243)))%360,S,LorV,rgb);
    strip.setPixelColor(i, rgb[0], rgb[1], rgb[2]);
    strip.setPixelColor(279-(i-243), rgb[0], rgb[1], rgb[2]);
  }
  strip.setPixelColor(279, 0, 0, 0);

  // Inner diamond
  for(int i=281; i<292; i++) {
    HSVtoRGB((H+int(360.0/11*(i-281)))%360,S,LorV,rgb);
    strip.setPixelColor(i, rgb[0], rgb[1], rgb[2]);
    strip.setPixelColor(301-(i-281), rgb[0], rgb[1], rgb[2]);
  }
  strip.setPixelColor(301, 0, 0, 0);

  strip.show();
  delay(wait);
}


void RedCycleSymmetric(int H, float S, float LorV, int wait) {
  static int rgb[3];

  // Hem total per side = 75
  // Top hem
  for(int i=36; i<53; i++) {
    RedCycle((H+int(2*360.0/75*(i-36)))%360,LorV,rgb);
    strip.setPixelColor(i, rgb[0], rgb[1], rgb[2]);
    strip.setPixelColor(185-(i-36), rgb[0], rgb[1], rgb[2]);
  }

  // Side hem
  for(int i=53; i<85; i++) {
    RedCycle((H+int(2*360.0/75*(i-36)))%360,LorV,rgb);
    strip.setPixelColor(i, rgb[0], rgb[1], rgb[2]);
    strip.setPixelColor(168-(i-53), rgb[0], rgb[1], rgb[2]);
  }

  // Bottom hem
  for(int i=85; i<111; i++) {
    RedCycle((H+int(2*360.0/75*(i-36)))%360,LorV,rgb);
    strip.setPixelColor(i, rgb[0], rgb[1], rgb[2]);
    strip.setPixelColor(136-(i-85), rgb[0], rgb[1], rgb[2]);
  }

  // Outer diamond
  for(int i=189; i<216; i++) {
    RedCycle((H+int(360.0/27*(i-189)))%360,LorV,rgb);
    strip.setPixelColor(i, rgb[0], rgb[1], rgb[2]);
    strip.setPixelColor(241-(i-189), rgb[0], rgb[1], rgb[2]);
  }
  strip.setPixelColor(241, 0, 0, 0);

  // Middle diamond
  for(int i=243; i<263; i++) {
    RedCycle((H+int(360.0/19*(i-243)))%360,LorV,rgb);
    strip.setPixelColor(i, rgb[0], rgb[1], rgb[2]);
    strip.setPixelColor(279-(i-243), rgb[0], rgb[1], rgb[2]);
  }
  strip.setPixelColor(279, 0, 0, 0);

  // Inner diamond
  for(int i=281; i<292; i++) {
    RedCycle((H+int(360.0/11*(i-281)))%360,LorV,rgb);
    strip.setPixelColor(i, rgb[0], rgb[1], rgb[2]);
    strip.setPixelColor(301-(i-281), rgb[0], rgb[1], rgb[2]);
  }
  strip.setPixelColor(301, 0, 0, 0);

  strip.show();
  delay(wait);
}


void SolidRainbowCycle(int H, float S, float LorV, int wait) {
  static int rgb[3];
  HSVtoRGB(H,S,LorV,rgb);

  // Spine (bottom half)
  // for(int i=0; i<22; i++) {
  //   strip.setPixelColor(i, rgb[0], rgb[1], rgb[2]);
  // }
  // Spine (top half)
  // for(int i=22; i<36; i++) {
  //   strip.setPixelColor(i, rgb[0], rgb[1], rgb[2]);
  // }
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