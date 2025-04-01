#include <Adafruit_NeoPixel.h>

#define PIN 8
#define numLEDs (16+12+12)


Adafruit_NeoPixel strip = Adafruit_NeoPixel(numLEDs, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
 strip.begin();
 strip.show();
}


int r;
int g;
int b;
int r3[] = {0, 1, 1};
int g3[] = {1, 0, 1};
int b3[] = {1, 1, 0};

float rwiggle;
float gwiggle;
float bwiggle;
float rbreath;
float gbreath;
float bbreath;
float cwiggle;
float mwiggle;
float ywiggle;
float cbreath;
float mbreath;
float ybreath;
float pi = 3.14159;

int tr = 0;
int tg = 0;
int tb = 0;
int t1 = 0;
int t2 = 0;
int t3 = 0;
int t = 0;

void tree_c0(){
  t += 1;
  for (int i = 0; i < 40; i++){
    int r = 255 * pow(sin(pi*(i/40.0 + t/377.0)), 30);
    int g = 255 * pow(sin(pi*(i/40.0 + t/377.0 + 1/3.0)), 30);
    int b = 255 * pow(sin(pi*(i/40.0 + t/377.0 + 2/3.0)), 30);
    strip.setPixelColor(i, r, g, b);
  }
}
void tree_cg(){
  t += 1;
  rwiggle = 20*(0.2*pow(sin(pi*t/610.0),4)+0.8)*random(0,1000)/1000.0;
  gbreath = 0.55 + 0.3 * pow(sin(pi*(t/610.0)), 16) + (0.13*pow(sin(pi*t/610.0),8)+0.02)*random(0,1000)/1000.0;
  bbreath = 0.5 + 0.35 * pow(sin(pi*(t/610.0)), 16) + (0.12*pow(sin(pi*t/610.0),8)+0.03)*random(0,1000)/1000.0;
  for (int i = 0; i < 40; i++){
    int r = 150 * pow(sin(pi*(i/40.0 - (2*t+rwiggle)/409.0) + 1/2.0), 30);
    int g = gbreath * 255 * (1-pow(sin(2*pi*(i/40.0 + t/610.0 + 1/4.0)), 20));
    int b = bbreath * 200 * pow(sin(4*pi*(i/40.0 + t/610.0)), 40);
    strip.setPixelColor(i, r, g, b);
  }
}
void tree_cr(){
  t += 1;
  rbreath = 0.7 + 0.1 * pow(sin(pi*(t/610.0)), 8) + (0.15*pow(sin(pi*t/610.0),8)+0.05)*random(0,1000)/1000.0;
  gwiggle = 10*(0.2*pow(sin(pi*t/610.0),4)+0.8)*random(0,1000)/1000.0;
  bbreath = 0.5 + 0.3 * pow(sin(pi*(t/311.0)), 16) + (0.15*pow(sin(pi*t/311.0),8)+0.05)*random(0,1000)/1000.0;
  for (int i = 0; i < 40; i++){
    int r = rbreath * 255;
    int g = 20*pow(sin(pi*t/610.0),8) + 20*pow(sin(4*pi*(i/40.0 - (t+gwiggle)/610.0)), 30);
    int b = bbreath * 50 * pow(sin(pi*(i/40.0 + t/610.0)), 40);
    strip.setPixelColor(i, r, g, b);
  }
}
void tree_cr2(){
  t += 1;
  rbreath = 0.8 + 0.1 * pow(sin(pi*(t/610.0)), 8) + (0.08*pow(sin(pi*t/610.0),8)+0.02)*random(0,1000)/1000.0;
  gwiggle = 5*(0.2*pow(sin(pi*t/610.0),4)+0.8)*random(0,1000)/1000.0;
  bbreath = 0.5 + 0.3 * pow(sin(pi*(t/311.0)), 16) + (0.08*pow(sin(pi*t/311.0),8)+0.02)*random(0,1000)/1000.0;
  for (int i = 0; i < 40; i++){
    int r = rbreath * 120;
    int g = 5*pow(sin(pi*t/233.0),12) + 20*pow(sin(2*pi*(i/40.0 - (t+gwiggle)/610.0)), 80);
    int b = bbreath * 30 * pow(sin(pi*(i/40.0 + t/610.0)), 40);
    strip.setPixelColor(i, r, g, b);
  }
}
void tree_cb(){
  t += 1;
  rwiggle = 10*(0.2*pow(sin(pi*t/610.0),4)+0.8)*random(0,1000)/1000.0;
  gbreath = 0.5 + 0.3 * pow(sin(pi*(t/311.0)), 16) + (0.15*pow(sin(pi*t/311.0),8)+0.05)*random(0,1000)/1000.0;
  bbreath = 0.55 + 0.25 * pow(sin(pi*(t/610.0)), 8) + (0.15*pow(sin(pi*t/610.0),8)+0.05)*random(0,1000)/1000.0;
  for (int i = 0; i < 40; i++){
    int r = 100 * pow(sin(pi*(i/40.0 - (t+rwiggle)/610.0)), 40);
    int g = gbreath * 100 * pow(sin(2*pi*(i/40.0 + t/1013.0)), 20);
    int b = bbreath * 255;
    strip.setPixelColor(i, r, g, b);
  }
}
void tree_cp(){
  t += 1;
  rwiggle = 8*(0.4*pow(sin(pi*t/420.0),4)+0.6)*random(0,1000)/1000.0;
  rbreath = 0.15 + 0.3 * pow(sin(pi*(t/311.0)), 16) + (0.03*pow(sin(pi*t/311.0),8)+0.02)*random(0,1000)/1000.0;
  gwiggle = 8*(0.4*pow(sin(pi*t/420.0),4)+0.6)*random(0,1000)/1000.0;
  bbreath = 0.15 + 0.3 * pow(sin(pi*(t/522.0)), 8) + (0.03*pow(sin(pi*t/522.0),8)+0.02)*random(0,1000)/1000.0;
  for (int i = 0; i < 40; i++){
    int r = 255 * (rbreath + 0.5*pow(sin(2*pi*(i/40.0 - t/420.0)), 60));
    int g = 100 * pow(sin(pi*(i/40.0 - (t+gwiggle)/513.0)), 30);
    int b = 255 * (bbreath + 0.5*pow(sin(2*pi*(i/40.0 - t/420.0 + 1/4.0)), 60));
    strip.setPixelColor(i, r, g, b);
  }
}
void tree_ct(){
  t += 1;
  // rwiggle = 4*(0.3*pow(sin(pi*t/610.0),4)+0.7)*random(0,1000)/1000.0;
  // gwiggle = 4*(0.3*pow(sin(pi*t/610.0),4)+0.7)*random(0,1000)/1000.0;
  // bwiggle = 4*(0.3*pow(sin(pi*t/610.0),4)+0.7)*random(0,1000)/1000.0;
  // rbreath = 0;//0.1 + 0.4 * pow(sin(pi*(t/419.0)), 16) + (0.02*pow(sin(pi*t/987.0),8)+0.02)*random(0,1000)/1000.0;
  // gbreath = 0;//0.5 + 0.5 * pow(sin(pi*(t/641.0)), 16) + (0.02*pow(sin(pi*t/987.0),8)+0.02)*random(0,1000)/1000.0;
  // bbreath = 0;//0.5 + 0.5 * pow(sin(pi*(t/641.0)), 16) + (0.02*pow(sin(pi*t/987.0),8)+0.02)*random(0,1000)/1000.0;
  for (int i = 0; i < 40; i++){
    // int r3 = 255 * r3 * (pow(sin(pi*(i/40.0 - (t)/377.0)), 60));// + 0.46*pow(sin(3*pi*(i/40.0 - (0.5*t+rwiggle)/377.0)), 60)));
    // int g3 = 0 * g3;
    // int b3 = 0 * b3;
    float r3[] = {0.0, 1.0, 1.0};
    float g3[] = {1.0, 0.0, 1.0};
    float b3[] = {1.0, 1.0, 0.0};
    r3[1] = (pow(sin(pi*(i/40.0 - (t)/377.0)), 60));
    r3[2] = (pow(sin(pi*(i/40.0 - (t)/377.0)), 60));
    g3[0] = 0.0;
    g3[2] = 0.0;
    b3[0] = 0.0;
    b3[1] = 0.0;
    int r = 255 * (1 - max(0,min(1,r3[0] + g3[0] + b3[0])));
    int g = 255 * (1 - max(0,min(1,r3[1] + g3[1] + b3[1])));
    int b = 255 * (1 - max(0,min(1,r3[2] + g3[2] + b3[2])));
    strip.setPixelColor(i, r, g, b);
  }
}
void tree_ct2(){
  t += 1;
  // float c[] = {0.0, 1.0, 1.0};
  // float m[] = {1.0, 0.0, 1.0};
  // float y[] = {1.0, 1.0, 0.0};
  rwiggle = 6*(0.2*pow(sin(pi*t/610.0),4)+0.8)*random(0,1000)/1000.0;
  gwiggle = 2*(0.2*pow(sin(pi*t/610.0),4)+0.8)*random(0,1000)/1000.0;
  bwiggle = 1*(0.2*pow(sin(pi*t/610.0),4)+0.8)*random(0,1000)/1000.0;
  // cwiggle = 2*(0.2*pow(sin(pi*t/610.0),4)+0.8)*random(0,1000)/1000.0;
  // mwiggle = 1*(0.2*pow(sin(pi*t/610.0),4)+0.8)*random(0,1000)/1000.0;
  // ywiggle = 0.5*(0.2*pow(sin(pi*t/610.0),4)+0.8)*random(0,1000)/1000.0;
  rbreath = 0.3 + 0.6 * pow(sin(pi*(t/754.0)), 16) + (0.05*pow(sin(pi*t/610.0),8)+0.05)*random(0,1000)/1000.0;
  gbreath = 0.3 + 0.6 * pow(sin(pi*(t/466.0)), 16) + (0.05*pow(sin(pi*t/610.0),8)+0.05)*random(0,1000)/1000.0;
  bbreath = 0.3 + 0.6 * pow(sin(pi*(t/288.0)), 16) + (0.05*pow(sin(pi*t/610.0),8)+0.05)*random(0,1000)/1000.0;
  for (int i = 0; i < 40; i++){
    int c = 40 * pow(sin(pi*((i+8)/40.0+(t+cwiggle)/89.0)), 60);
    int m = 40 * pow(sin(pi*((i+20)/40.0+(t+mwiggle)/55.0)), 60);
    int y = 40 * pow(sin(pi*((i)/40.0+(t+ywiggle)/34.0)), 60);

    int r = 175 * rbreath * pow(sin(pi*((i+16)/40.0+(t+rwiggle)/377.0)), 60) + m + y;
    int g = 175 * gbreath * pow(sin(pi*((i+28)/40.0+(t+gwiggle)/233.0)), 60) + c + y;
    int b = 175 * bbreath * pow(sin(pi*((i)/40.0+(t+bwiggle)/144.0)), 60) + c + m;
    // int r = m + y;
    // int g = c + y;
    // int b = c + m;
    strip.setPixelColor(i, r, g, b);
  }
}
void tree_cj(){
  t += 1;
  rwiggle = 5*(0.2*pow(sin(pi*t/610.0),4)+0.8)*random(0,1000)/1000.0;
  gwiggle = 5*(0.2*pow(sin(pi*t/610.0),4)+0.8)*random(0,1000)/1000.0;
  bwiggle = 5*(0.2*pow(sin(pi*t/610.0),4)+0.8)*random(0,1000)/1000.0;
  rbreath = 0.5 + 0.4 * pow(sin(pi*(t/610.0)), 16) + (0.05*pow(sin(pi*t/610.0),8)+0.05)*random(0,1000)/1000.0;
  gbreath = 0.5 + 0.4 * pow(sin(pi*(t/610.0)), 16) + (0.05*pow(sin(pi*t/610.0),8)+0.05)*random(0,1000)/1000.0;
  bbreath = 0.5 + 0.4 * pow(sin(pi*(t/610.0)), 16) + (0.05*pow(sin(pi*t/610.0),8)+0.05)*random(0,1000)/1000.0;
  for (int i = 0; i < 16; i++){
    int r = 255 * rbreath * pow(sin(pi*(i/16.0+(t+rwiggle)/377.0)), 30);
    int g = 255 * gbreath * pow(sin(pi*(i/16.0+(t+gwiggle)/233.0)), 30);
    int b = 255 * bbreath * pow(sin(pi*(i/16.0+(t+bwiggle)/144.0)), 30);
    strip.setPixelColor(i, r, g, b);
  }
  for (int i = 16; i < 28; i++){
    int r = 255 * rbreath * pow(sin(pi*((i-16)/12.0+(t+rwiggle)/377.0)), 30);
    int g = 255 * gbreath * pow(sin(pi*((i-16)/12.0+(t+gwiggle)/233.0)), 30);
    int b = 255 * bbreath * pow(sin(pi*((i-16)/12.0+(t+bwiggle)/144.0)), 30);
    strip.setPixelColor(i, r, g, b);
  }
  for (int i = 28; i < 40; i++){
    int r = 255 * rbreath * pow(sin(pi*((i-28)/12.0+(t+rwiggle)/377.0)), 30);
    int g = 255 * gbreath * pow(sin(pi*((i-28)/12.0+(t+gwiggle)/233.0)), 30);
    int b = 255 * bbreath * pow(sin(pi*((i-28)/12.0+(t+bwiggle)/144.0)), 30);
    strip.setPixelColor(i, r, g, b);
  }
}


void loop(){
  tree_ct2();
  strip.show();
  delay(10);
}