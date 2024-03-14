// #include "logistic.h"
// #include "logistic_color.h"
// #include <Arduino.h>

// Eloquent::ML::Port::LogisticRegression clf;


// int color_num;
// String color_name;

// int R_min = 3;
// int R_max = 17;
// int G_min = 3;
// int G_max = 16;
// int B_min = 3;
// int B_max = 13;

// int red = 0;
// int green = 0;
// int blue = 0;

// int red_val;
// int green_val;
// int blue_val;
// int Rfreq;
// int Gfreq;
// int Bfreq;

// int getRed() {
//   digitalWrite(s2, LOW);
//   digitalWrite(s3, LOW);
//   Rfreq = pulseIn(out, LOW);
// }

// int getGreen() {
//   digitalWrite(s2, HIGH);
//   digitalWrite(s3, HIGH);
//   Gfreq = pulseIn(out, LOW);
//   return Gfreq;
// }

// int getBlue() {
//   digitalWrite(s2, LOW);
//   digitalWrite(s3, HIGH);
//   Bfreq = pulseIn(out, LOW);
//   return Bfreq;
// }
  

// void readcolor_loop(void *p){
//     while (true){
//       getRed();
//       red_val = map(red, R_min, R_max, 255, 0);
//       getGreen();
//       green_val = map(green, G_min, G_max, 255, 0);
//       getBlue();
//       blue_val = map(blue, B_min, B_max, 255, 0);
//       float x[] = {red_val, green_val, blue_val};
//       color_num = clf.predict(x);
//       if (color_num == 0) {
//         color_name = "Red";
//       }
//       else if (color_num == 1) {
//         color_name = "Green";
//       }
//       else if (color_num == 2) {
//         color_name = "Blue";
//       }
//       else if (color_num == 3) {
//         color_name = "Yellow";
//       }
//       else if (color_num == 4) {
//         color_name = "Orange";
//       }
//       else if (color_num == 5) {
//         color_name = "Purple";
//       }
//       else if (color_num == 6) {
//         color_name = "Brown";
//       }
//       else if (color_num == 7) {
//         color_name = "Pink";
//       }
//       else if (color_num == 8) {
//         color_name = "Gray";
//       }
//       else if (color_num == 9) {
//         color_name = "Black";
//       }
//       else if (color_num == 10) {
//         color_name = "White";
//       }
//       Serial.print("Color: ");
//       Serial.println(color_name);
//       vTaskDelay(1000 / portTICK_PERIOD_MS);
//     }
// }

// void readcolor_setup() {
//   Serial.begin(9600);
//   pinMode(outputEnabled, OUTPUT);
//   pinMode(s0, OUTPUT);
//   pinMode(s1, OUTPUT);
//   pinMode(s2, OUTPUT);
//   pinMode(s3, OUTPUT);
//   pinMode(out, INPUT);
//   xTaskCreatePinnedToCore(readcolor_loop, "readcolor_loop", 1024*8, NULL, 20, NULL, 1);
// }
