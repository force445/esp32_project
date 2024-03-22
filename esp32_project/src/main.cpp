#include <Arduino.h>
// #include <WiFi.h>

// #include <AsyncTCP.h>
// #include <ESPAsyncWebServer.h>

#include "logistic.h"

Eloquent::ML::Port::LogisticRegression classifier;

const char* ssid = "AUTOMATION_IOT_1";
const char* password = "admin12345";


const int S2 = 2;
const int S3 = 14;
const int sensorOut = 12;

int R_Min = 13;
int G_Min = 43;
int B_Min = 43;
int C_Min = 13;
int R_Max = 194;
int G_Max = 626;
int B_Max = 625;
int C_Max = 194;

int Red = 0;
int Green = 0;
int Blue = 0;
int Clear = 0;

int redValue, greenValue, blueValue, clearValue, Frequency;

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

int getClear(){
  digitalWrite(S2,HIGH);
  digitalWrite(S3,LOW);
  Frequency = pulseIn(sensorOut, LOW); /*Get the Clear Color Frequency*/
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

  Clear = getClear();
  clearValue = map(Clear, C_Min,C_Max,255,0); /*Map the Clear Color Value*/

  float x[] = {redValue, greenValue, blueValue, clearValue};
  int prediction = classifier.predict(x);
  
  // Serial.println(prediction);

  if(prediction==0){
    Serial.println("Red");
    r++;

    w = 0;
    y = 0;
    p = 0;
    o = 0;
    b = 0;
    bl = 0;
    m = 0;
    br = 0;
    pk = 0;

    Serial.println(r);
    if (r == 45) {
      red_count++;
      Serial.println("Red Count: ");
      Serial.println(red_count);
      prediction = 6;
    }
  }
  else if (prediction==1){
    // Serial.println("White");
    w++;

    r = 0;
    y = 0;
    p = 0;
    o = 0;
    b = 0;
    bl = 0;
    m = 0;
    br = 0;
    pk = 0;
    
    // Serial.println(w);
    if (w == 33) {
      white_count++;
      Serial.println("White Count: ");
      Serial.println(white_count);
      prediction = 6;
    }
  }
  else if (prediction==2){
    // Serial.println("Yellow");
    y++;

    w = 0;
    r = 0;
    p = 0;
    o = 0;
    b = 0;
    bl = 0;
    m = 0;
    br = 0;
    pk = 0;
    
    // Serial.println(y);
    if (y == 28) {
      yellow_count++;
      Serial.println("Yellow Count: ");
      Serial.println(yellow_count);
      prediction = 6;
    }
  }
  else if (prediction==3){
    // Serial.println("Purple");
    p++;

    w = 0;
    y = 0;
    r = 0;
    o = 0;
    b = 0;
    bl = 0;
    m = 0;
    br = 0;
    pk = 0;
    
    // Serial.println(p);
    if (p == 9) {
      purple_count++;
      Serial.println("Purple Count: ");
      Serial.println(purple_count);
      prediction = 6;
    }
  }
  // else if (prediction==4){
  //   Serial.println("Blue");
  //   b++;

  //   w = 0;
  //   y = 0;
  //   p = 0;
  //   o = 0;
  //   r = 0;
  //   bl = 0;
  //   m = 0;
  //   br = 0;
  //   pk = 0;

  //   Serial.println(b);
  //   if (b == 2) {
  //     blue_count++;
  //     Serial.println("Blue Count: ");
  //     Serial.println(blue_count);
  //     prediction = 7;
  //   }
  // }

  // else if (prediction==6){
  //   Serial.println("Black");
  //   bl++;

  //   w = 0;
  //   y = 0;
  //   p = 0;
  //   o = 0;
  //   b = 0;
  //   r = 0;
  //   m = 0;
  //   br = 0;
  //   pk = 0;

  //   Serial.println(bl);
  //   if (bl == 4) {
  //     black_count++;
  //     Serial.println("Black Count: ");
  //     Serial.println(black_count);
  //     prediction = 10;
  //   }
  //   }

  else if (prediction==4){
    // Serial.println("Brown");
    br++;

    w = 0;
    y = 0;
    p = 0;
    o = 0;
    b = 0;
    bl = 0;
    m = 0;
    r = 0;
    pk = 0;

    // Serial.println(br);
    if (br == 17) {
      brown_count++;
      Serial.println("Brown Count: ");
      Serial.println(brown_count);
    }
  }

  else if (prediction==5){
    r = 0;
    w = 0;
    // Serial.print(w);
    y = 0;
    p = 0;
    // Serial.print("purple:");
    // Serial.print(p);
    o = 0;
    // Serial.print("orange:");
    // Serial.print(o);
    b = 0;
    bl = 0;
    m = 0;
    br = 0;
    pk = 0;

  }  

  // Serial.print("[");
  // Serial.print(redValue);   /*Print Red Color Value*/
  // Serial.print(",");
  // Serial.print(greenValue); /*Print Green Color Value*/
  // Serial.print(",");
  // Serial.print(blueValue);  /*Print Blue Color Value*/
  // Serial.print(",");
  // Serial.print(clearValue); /*Print Clear Color Value*/
  // Serial.println("],"); // Close the array and print a newline
  // delay(200);

  // switch (prediction) {
  //   case 0:
  //     Serial.println("Red");
  //     break;
  //   case 1:
  //     Serial.println("White");
  //     break;
  //   case 2:
  //     Serial.println("Yellow");
  //     break;
  //   case 3:
  //     Serial.println("Purple");
  //     break;
  //   case 5:
  //     Serial.println("Brown");
  //     break;
  //   default:
  //     Serial.println("Unknown");
  //     break;
  // }
}
