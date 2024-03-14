#include <Arduino.h>

const int outputEnabled = 2;
const int S0 = 5;
const int S1 = 4;
const int S2 = 2;
const int S3 = 14;
const int sensorOut = 12;

int R_Min = 3;
int G_Min = 3;
int B_Min = 3;
int R_Max = 18;
int G_Max = 17;
int B_Max = 13;

int Red = 0;
int Green = 0;
int Blue = 0;

int redValue;
int greenValue;
int blueValue;
int Frequency;

void setup() {
  pinMode(S2, OUTPUT); /*Define S2 Pin as a OUTPUT*/
  pinMode(S3, OUTPUT); /*Define S3 Pin as a OUTPUT*/
  pinMode(sensorOut, INPUT); /*Define Sensor Output Pin as a INPUT*/
  Serial.begin(9600); /*Set the baudrate to 115200*/
  Serial.print("This is TCS3200 Calibration Code");
}

int getRed() {
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  Frequency = pulseIn(sensorOut, LOW); /*Get the Red Color Frequency*/
  return Frequency;
}

int getGreen() {
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  Frequency = pulseIn(sensorOut, LOW); /*Get the Green Color Frequency*/
  return Frequency;
}

int getBlue() {
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  Frequency = pulseIn(sensorOut, LOW); /*Get the Blue Color Frequency*/
  return Frequency;
}

void loop() {
  Red = getRed();
  redValue = map(Red, R_Min,R_Max,255,0); /*Map the Red Color Value*/
  delay(200);

  Green = getGreen();
  greenValue = map(Green, G_Min,G_Max,255,0); /*Map the Green Color Value*/
  delay(200);

  Blue = getBlue();
  blueValue = map(Blue, B_Min,B_Max,255,0);   /*Map the Blue Color Value*/
  delay(200);

  Serial.print("[");
  Serial.print(redValue);   /*Print Red Color Value*/
  Serial.print(",");
  Serial.print(greenValue); /*Print Green Color Value*/
  Serial.print(",");
  Serial.print(blueValue);  /*Print Blue Color Value*/
  Serial.println("]");
  delay(1000); 
}