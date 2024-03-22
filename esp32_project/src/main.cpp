#include <Arduino.h>
#include <WiFi.h>

#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>

#include "logistic.h"

Eloquent::ML::Port::LogisticRegression classifier;

const char* ssid = "AUTOMATION_IOT_1";
const char* password = "admin12345";


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

int redValue, greenValue, blueValue, Frequency;

int r, w, y, p, o, b, bl, m, br, pk, u;

int red_count, white_count, yellow_count, purple_count, orange_count, blue_count, black_count, metal_count, brown_count, pink_count, unknown_count;


void setup() {
  pinMode(S2, OUTPUT); /*Define S2 Pin as a OUTPUT*/
  pinMode(S3, OUTPUT); /*Define S3 Pin as a OUTPUT*/
  pinMode(sensorOut, INPUT); /*Define Sensor Output Pin as a INPUT*/
  Serial.begin(9600); /*Set the baudrate to 115200*/
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
  // delay(200);
  // Serial.println(Red);

  Green = getGreen();
  greenValue = map(Green, G_Min,G_Max,255,0); /*Map the Green Color Value*/
  // // delay(200);
  // Serial.println(Green);

  Blue = getBlue();
  blueValue = map(Blue, B_Min,B_Max,255,0);   /*Map the Blue Color Value*/
  // delay(200);

  float x[] = {redValue, greenValue, blueValue};
  int prediction = classifier.predict(x);
  
  // Serial.println(prediction);

  // if(prediction==0){
  //   Serial.println("Red");
  //   r++;
  //   Serial.println(r);
  //   if (r == 28) {
  //     red_count++;
  //     Serial.println("Red Count: ");
  //     Serial.println(red_count);
  //   }
  // }
  // else if (prediction==1){
  //   Serial.println("White");
  //   w++;
  //   Serial.println(w);
  //   if (w == 28) {
  //     white_count++;
  //     Serial.println("White Count: ");
  //     Serial.println(white_count);
  //   }
  // }
  // else if (prediction==2){
  //   Serial.println("Yellow");
  //   y++;
  //   Serial.println(y);
  //   if (y == 28) {
  //     yellow_count++;
  //     Serial.println("Yellow Count: ");
  //     Serial.println(yellow_count);
  //   }
  // }
  // else if (prediction==3){
  //   Serial.println("Purple");
  //   p++;
  //   Serial.println(p);
  //   if (p == 28) {
  //     purple_count++;
  //     Serial.println("Purple Count: ");
  //     Serial.println(purple_count);
  //   }
  // }
  // else if (prediction==4){
  //   Serial.println("Orange");
  //   o++;
  //   Serial.println(o);
  //   if (o == 28) {
  //     orange_count++;
  //     Serial.println("Orange Count: ");
  //     Serial.println(orange_count);
  //   }
  // }
  // else if (prediction==5){
  //   Serial.println("Blue");
  //   b++;
  //   Serial.println(b);
  //   if (b == 28) {
  //     blue_count++;
  //     Serial.println("Blue Count: ");
  //     Serial.println(blue_count);
  //   }
  // }
  // else if (prediction==6){
  //   Serial.println("Black");
  //   bl++;
  //   Serial.println(bl);
  //   if (bl == 28) {
  //     black_count++;
  //     Serial.println("Black Count: ");
  //     Serial.println(black_count);
  //   }
  // }
  // else if (prediction==7){
  //   Serial.println("Metal");
  //   m++;
  //   Serial.println(m);
  //   if (m == 28) {
  //     metal_count++;
  //     Serial.println("Metal Count: ");
  //     Serial.println(metal_count);
  //   }
  // }
  // else if (prediction==8){
  //   Serial.println("Brown");
  //   br++;
  //   Serial.println(br);
  //   if (br == 28) {
  //     brown_count++;
  //     Serial.println("Brown Count: ");
  //     Serial.println(brown_count);
  //   }
  // }
  // else if (prediction==9){
  //   Serial.println("Pink");
  //   pk++;
  //   Serial.println(pk);
  //   if (pk == 28) {
  //     pink_count++;
  //     Serial.println("Pink Count: ");
  //     Serial.println(pink_count);
  //   }
  // }
  // else if (prediction==10){
  //   Serial.println("Unknown");
  //   r = 0;
  //   w = 0;
  //   y = 0;
  //   p = 0;
  //   o = 0;
  //   b = 0;
  //   bl = 0;
  //   m = 0;
  //   br = 0;
  //   pk = 0;

  Serial.print("[");
  Serial.print(redValue);   /*Print Red Color Value*/
  Serial.print(",");
  Serial.print(greenValue); /*Print Green Color Value*/
  Serial.print(",");
  Serial.print(blueValue);  /*Print Blue Color Value*/
  Serial.println("],"); // Close the array and print a newline
  delay(200);

// }  
}
