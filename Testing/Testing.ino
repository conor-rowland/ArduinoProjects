void setup() {
 Serial.begin(9600);
}

float x = 0;
float noise;
float pi = 3.14159;

int t1 = 0;

void tree_0(){
  t1 += 1;
  // noise = random(0,100)/100.0;
  // Serial.println(noise);

  float r3[] = {0.0, 1.0, 1.0};
  float g3[] = {1.0, 0.0, 1.0};
  float b3[] = {1.0, 1.0, 0.0};
  r3[1] = (pow(sin((t1)/100.0), 4));
  r3[2] = (pow(sin((t1)/100.0), 4));
  g3[0] = 0.0;
  g3[2] = 0.0;
  b3[0] = 0.0;
  b3[1] = 0.0;
  int r = 255 * (1 - max(0,min(1,r3[0] + g3[0] + b3[0])));
  int g = 255 * (1 - max(0,min(1,r3[1] + g3[1] + b3[1])));
  int b = 255 * (1 - max(0,min(1,r3[2] + g3[2] + b3[2])));
  // Serial.println({0,r3[1],r3[2]});
  Serial.println(r);
  Serial.println(g);
  Serial.println(b);

  // for (float i = 0; i < 40; i++){
  //   x = pi*(i/40);
  // }
}

void loop(){
  tree_0();
  delay(50);
}