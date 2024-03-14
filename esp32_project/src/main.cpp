#include <Arduino.h>

const int outputEnabled = 2;
const int s0 = 5;
const int s1 = 4;
const int s2 = 2;
const int s3 = 14;
const int out = 12;

int R_min = 3;
int G_min = 3;
int B_min = 3;
int R_max = 18;
int G_max = 17;
int B_max = 13;

int Red = 0;
int Green = 0;
int Blue = 0;

int redValue;
int greenValue;
int blueValue;
int Frequency;

void setup() {
  pinMode(s2, OUTPUT);
  pinMode(s3, OUTPUT);
  pinMode(out, INPUT); 
  Serial.begin(9600);
  delay(1000); 
}

int getRed() {
  digitalWrite(s2,LOW);
  digitalWrite(s3,LOW);
  Frequency = pulseIn(out, LOW);
}

int getGreen() {
  digitalWrite(s2,HIGH);
  digitalWrite(s3,HIGH);
  Frequency = pulseIn(out, LOW);
  return Frequency;
}

int getBlue() {
  digitalWrite(s2,LOW);
  digitalWrite(s3,HIGH);
  Frequency = pulseIn(out, LOW);
  return Frequency;
}

void loop() {
  Red = getRed();
  redValue = map(Red, R_min, R_max, 255, 0);
  delay(200);

  Green = getGreen();
  greenValue = map(Green, G_min, G_max, 255, 0);
  delay(200);

  Blue = getBlue();
  blueValue = map(Blue, B_min, B_max, 255, 0);
  delay(200);

  Serial.print("[");
  Serial.print(redValue);   
  Serial.print(",");
  Serial.print(greenValue); 
  Serial.print(",");
  Serial.print(blueValue);  
  Serial.println("]"); 
  delay(1000);
}