#include <Adafruit_NeoPixel.h>
// #include <Array.h>

#define LED_PIN      4
#define LED_COUNT    138
#define slowmo       3

#define bottom       18 //   0 to  17
#define vhemline     8  //  18 to  25;  69 to  76; 124 to 131
#define hmidline     17 //  26 to  42;  52 to  68;  77 to  93
#define diamond      9  //  43 to  51;  94 to 102;
#define backtopline  7  // 103 to 109
#define shoulder     8  // 110 to 117
#define fronttopline 6  // 118 to 123
#define collar       6  // 132 to 137


Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_KHZ800 + NEO_GRB);

void setup() {
  strip.begin();
  strip.clear();
}

// float pi = 3.141592653;
int numblocks = 6;
float mew = LED_COUNT/numblocks;
float sigma = 6;
int th = 0;
// int ishift = 0;
// int i1shift = 0;
// int i2shift = 0;
// int i3shift = 0;
// int i4shift = 0;
// int i5shift = 0;
// int i6shift = 0;
void loop() {
  // RainbowCycleMirror(th,1.0,0.15,1,ishift,mew,sigma,numblocks);
  // RainbowCycleTest(th,1.0,0.1,1,ishift,mew,sigma,t1,t2,t3,i1shift,i2shift,i3shift,i4shift,i5shift,i6shift);
  PixelTesting(th,1.0,0.15,10);
  // ishift = ishift + 1;
  // if (ishift >= slowmo*LED_COUNT/6) {
  //   ishift = 0;
  // }
  // i1shift = i1shift + 2;
  // i2shift = i2shift + 5;
  // i3shift = i3shift + 13;
  // i4shift = i4shift + 8;
  // i5shift = i5shift + 3;
  // i6shift = i6shift + 1;
  // if (i1shift-(-mew-4*sigma) >= LED_COUNT+8*sigma) {
  //   i1shift = -mew-4*sigma;
  // }
  // if (i2shift-(5*sigma-mew-4*sigma) >= LED_COUNT+8*sigma) {
  //   i2shift = 5*sigma-mew-4*sigma;
  // }
  // if (i3shift-(10*sigma-mew-4*sigma) >= LED_COUNT+8*sigma) {
  //   i3shift = 10*sigma-mew-4*sigma;
  // }
  // if (i4shift-(-15*sigma-mew-4*sigma) >= LED_COUNT+8*sigma) {
  //   i4shift = -15*sigma-mew-4*sigma;
  // }
  // if (i5shift-(-10*sigma-mew-4*sigma) >= LED_COUNT+8*sigma) {
  //   i5shift = -10*sigma-mew-4*sigma;
  // }
  // if (i6shift-(-5*sigma-mew-4*sigma) >= LED_COUNT+8*sigma) {
  //   i6shift = -5*sigma-mew-4*sigma;
  // }
  th = th - 2;
  if (th <= 0) {
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


//----------Define Modes Below----------

void RainbowCycleMirror(int H, float S, float LorV, int wait, int ishift, float mew, float sigma, int numblocks) {
  static int rgb0[3];
  static int rgb1[3];
  static int rgb2[3];
  static int rgb3[3];
  static int rgb4[3];
  static int rgb5[3];
  // static int rgb6[3];
  // static int rgb7[3];
  
  int blockLEDs = int(LED_COUNT/numblocks);
  for(int i=0; i<blockLEDs; i++) {
    HSVtoRGB((H+int(360.0/LED_COUNT*i))%360,S,LorV,rgb0);
    HSVtoRGB((H+int(360.0/LED_COUNT*(1*blockLEDs+i)))%360,S,LorV,rgb1);
    HSVtoRGB((H+int(360.0/LED_COUNT*(2*blockLEDs+i)))%360,S,LorV,rgb2);
    HSVtoRGB((H+int(360.0/LED_COUNT*(3*blockLEDs+i)))%360,S,LorV,rgb3);
    HSVtoRGB((H+int(360.0/LED_COUNT*(4*blockLEDs+i)))%360,S,LorV,rgb4);
    HSVtoRGB((H+int(360.0/LED_COUNT*(5*blockLEDs+i)))%360,S,LorV,rgb5);
    // HSVtoRGB((H+int(360.0/LED_COUNT*(6*blockLEDs+i)))%360,S,LorV,rgb6);
    // HSVtoRGB((H+int(360.0/LED_COUNT*(7*blockLEDs+i)))%360,S,LorV,rgb7);
    float pixelfilt = 0;

    if ((i+ishift/slowmo)%blockLEDs <= 3.5*sigma) {
      pixelfilt = 0.96*exp(-abs((i+ishift/slowmo)%blockLEDs)/(0.6*sigma)) + 0.04;
    }
    strip.setPixelColor(i, rgb0[0]*pixelfilt, rgb0[1]*pixelfilt, rgb0[2]*pixelfilt);
    strip.setPixelColor((1)*blockLEDs+i, rgb1[0]*pixelfilt, rgb1[1]*pixelfilt, rgb1[2]*pixelfilt);
    strip.setPixelColor((2)*blockLEDs+i, rgb2[0]*pixelfilt, rgb2[1]*pixelfilt, rgb2[2]*pixelfilt);
    strip.setPixelColor((3)*blockLEDs+i, rgb3[0]*pixelfilt, rgb3[1]*pixelfilt, rgb3[2]*pixelfilt);
    strip.setPixelColor((4)*blockLEDs+i, rgb4[0]*pixelfilt, rgb4[1]*pixelfilt, rgb4[2]*pixelfilt);
    strip.setPixelColor((5)*blockLEDs+i, rgb5[0]*pixelfilt, rgb5[1]*pixelfilt, rgb5[2]*pixelfilt);
    // strip.setPixelColor((6)*blockLEDs+i, rgb6[0]*pixelfilt, rgb6[1]*pixelfilt, rgb6[2]*pixelfilt);
    // strip.setPixelColor((7)*blockLEDs+i, rgb7[0]*pixelfilt, rgb7[1]*pixelfilt, rgb7[2]*pixelfilt);
  }
  strip.show();
  delay(wait);
}

void RainbowCycleTest(int H, float S, float LorV, int wait, int ishift, float mew, float sigma, int t1, int t2, int t3, int i1shift, int i2shift, int i3shift, int i4shift, int i5shift, int i6shift) {
  static int rgb0[3];
  // HSLtoRGB(H,S,LorV,rgb);
  HSVtoRGB(H,S,LorV,rgb0);
  static int rgb1[3] = {25,0,0};
  static int rgb2[3] = {0,25,0};
  static int rgb3[3] = {0,0,25};
  static int rgb4[3] = {0,25,25};
  static int rgb5[3] = {25,0,25};
  static int rgb6[3] = {25,25,0};

  for(int i=0; i<LED_COUNT; i++) {
    float pixelfilt0 = 0;
    float pixelfilt1 = 0;
    float pixelfilt2 = 0;
    float pixelfilt3 = 0;
    float pixelfilt4 = 0;
    float pixelfilt5 = 0;
    float pixelfilt6 = 0;

    if (mew-4*sigma < i & i <= mew+4*sigma) {
      pixelfilt0 = 0.95*exp(-abs(i-mew)/sigma)+0.05;
    }
    if (mew-4*sigma < i-i1shift & i-i1shift <= mew+4*sigma) {
      pixelfilt1 = 0.95*exp(-abs(i-i1shift-mew)/sigma)+0.05;
    }
    if (mew-4*sigma < i-i2shift+5*sigma & i-i2shift+5*sigma <= mew+4*sigma) {
      pixelfilt2 = 0.95*exp(-abs(i-i2shift+5*sigma-mew)/sigma)+0.05;
    }
    if (mew-4*sigma < i-i3shift+10*sigma & i-i3shift+10*sigma <= mew+4*sigma) {
      pixelfilt3 = 0.95*exp(-abs(i-i3shift+10*sigma-mew)/sigma)+0.05;
    }
    if (mew-4*sigma < i-i4shift-15*sigma & i-i4shift-15*sigma <= mew+4*sigma) {
      pixelfilt4 = 0.95*exp(-abs(i-i4shift-15*sigma-mew)/sigma)+0.05;
    }
    if (mew-4*sigma < i-i5shift-10*sigma & i-i5shift-10*sigma <= mew+4*sigma) {
      pixelfilt5 = 0.95*exp(-abs(i-i5shift-10*sigma-mew)/sigma)+0.05;
    }
    if (mew-4*sigma < i-i6shift-5*sigma & i-i6shift-5*sigma <= mew+4*sigma) {
      pixelfilt6 = 0.95*exp(-abs(i-i6shift-5*sigma-mew)/sigma)+0.05;
    }

    int r = rgb0[0]*pixelfilt0 + rgb1[0]*pixelfilt1 + rgb2[0]*pixelfilt2 + rgb3[0]*pixelfilt3 + rgb4[0]*pixelfilt4 + rgb5[0]*pixelfilt5 + rgb6[0]*pixelfilt6;
    int g = rgb0[1]*pixelfilt0 + rgb1[1]*pixelfilt1 + rgb2[1]*pixelfilt2 + rgb3[1]*pixelfilt3 + rgb4[1]*pixelfilt4 + rgb5[1]*pixelfilt5 + rgb6[1]*pixelfilt6;;
    int b = rgb0[2]*pixelfilt0 + rgb1[2]*pixelfilt1 + rgb2[2]*pixelfilt2 + rgb3[2]*pixelfilt3 + rgb4[2]*pixelfilt4 + rgb5[2]*pixelfilt5 + rgb6[2]*pixelfilt6;;
    // int r = rgb1[0]*pixelfilt1;
    // int g = rgb1[1]*pixelfilt1;
    // int b = rgb1[2]*pixelfilt1;
    strip.setPixelColor(i, r, g, b);

  }

  strip.show();
  delay(wait);
}

// #define bottom       18 //   0 to  17
// #define vhemline     8  //  18 to  25;  69 to  76; 124 to 131
// #define hmidline     17 //  26 to  42;  52 to  68;  77 to  93
// #define diamond      9  //  43 to  51;  94 to 102;
// #define backtopline  7  // 103 to 109
// #define shoulder     8  // 110 to 117
// #define fronttopline 6  // 118 to 123
// #define collar       6  // 132 to 137
void PixelTesting(int H, float S, float LorV, int wait) {
  static int rgb[3];
  HSVtoRGB(H,S,LorV,rgb);

  // for(int i=0; i<LED_COUNT; i++) {
  //   strip.setPixelColor(i, 25, 25, 25);
  // }

  for(int i=0; i<18; i++) {
    strip.setPixelColor(i, 20, 0, 0);
  }
  for(int i=18; i<26; i++) {
    strip.setPixelColor(i, 0, 20, 0);
  }
  for(int i=26; i<43; i++) {
    strip.setPixelColor(i, 0, 0, 20);
  }
  for(int i=43; i<52; i++) {
    strip.setPixelColor(i, 0, 20, 20);
  }
  for(int i=52; i<69; i++) {
    strip.setPixelColor(i, 20, 0, 20);
  }
  for(int i=69; i<77; i++) {
    strip.setPixelColor(i, 20, 20, 0);
  }
  for(int i=77; i<94; i++) {
    strip.setPixelColor(i, 20, 0, 0);
  }
  for(int i=94; i<103; i++) {
    strip.setPixelColor(i, 0, 20, 0);
  }
  for(int i=103; i<110; i++) {
    strip.setPixelColor(i, 0, 0, 20);
  }
  for(int i=110; i<118; i++) {
    strip.setPixelColor(i, 0, 20, 20);
  }
  for(int i=118; i<124; i++) {
    strip.setPixelColor(i, 20, 0, 20);
  }
  for(int i=124; i<132; i++) {
    strip.setPixelColor(i, 20, 20, 0);
  }
  for(int i=132; i<138; i++) {
    strip.setPixelColor(i, 20, 20, 20);
  }

  strip.show();
  delay(wait);
}