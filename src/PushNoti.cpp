/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "/Users/darwinwang/Documents/IoT/PushNoti/src/PushNoti.ino"
void show();
void setup();
void loop();
#line 1 "/Users/darwinwang/Documents/IoT/PushNoti/src/PushNoti.ino"
SYSTEM_THREAD(ENABLED);

#include "oled-wing-adafruit.h"
#include <blynk.h>

OledWingAdafruit display;
int position = 2;
// define pins
#define button D2
#define tempSensor A4
#define potentiometer A5
//create variables
//bool changeMode = false; 
//int component = 0;
//int timer_minutes = 0;
//int timer_seconds = 00;
//int minutes_in_seconds = 0;
//bool changeMinutes = false;
//bool changeSeconds = false;
bool temp = true;
bool gps = false;

BLYNK_WRITE(V1) {
  display.clearDisplay();
  display.setCursor(0,0);
  display.setTextSize(1);
  GpsParam gps(param);
  // Print 6 decimal places for Lat, Lon
  display.println("Darwin's iPhone:");

  display.print("Lat: ");
  display.println(gps.getLat(), 7);

  display.print("Lon: ");
  display.println(gps.getLon(), 7);

  // Print 2 decimal places for Alt, Speed
  display.print("Altitute: ");
  display.println(gps.getAltitude(), 2);
  display.println();
  display.display();
}


void show() {
  uint64_t reading = analogRead(tempSensor);
  double voltage = (reading * 3.3) / 4095.0;
  double temperature = (voltage - 0.5) * 100;
  display.clearDisplay();
  display.setCursor(0,0);
  display.setTextSize(2);
  int farenheit = temperature * 1.8 + 32;
  display.print(temperature);
  display.println("C");
  display.print(farenheit);
  display.print("F");
  display.display();
  delay(200);
}

void setup() {
  //pinMode(potentiometer, INPUT);
  //clear screen and set it up
  display.setup();
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.display();
  pinMode(button, INPUT);
  Blynk.begin("BMn02IDEt5GFmITWPNoVZAqnhkmwFHEG", IPAddress(167, 172, 234, 162), 8080);
  Serial.begin(9600);  
}

//show();

void loop() {
  display.loop();
  if (display.pressedA()) {
    String text = "{DEVICE_NAME} says: Hello There";
    Blynk.notify(text);
    display.clearDisplay();
    display.setCursor(0,0);
    display.println("Push Sent:");
    display.print(text);
    display.display();
    delay(5000);
  }
  
  if (display.pressedB()) {
    temp = true;
    gps =false;
    //if (changeMode == true) {
    //  changeMode == false;
    //} else if (changeMode == false) {
    //  changeMode == true;
    //}
    //if (changeMode == true) {
    //  Blynk.run();
    //} else if (changeMode == false) {
    //  show();
    //}
  }
  if (display.pressedC()) {
    temp = false;
    gps = true;
    //int bad_value = analogRead(potentiometer);
    //int value = map(bad_value, 0, 4095, 0, 60);
    //display.clearDisplay();
    //display.setTextSize(3);
    //display.setCursor(0,0);
    //display.print(timer_minutes);
    //display.print(":");
    //display.print(timer_seconds);
    //if (display.pressedA()) {
    //  minutes_in_seconds = timer_minutes * 60;
    //  
    //}
   // 
    //if (display.pressedB()) {
    //  changeMinutes = true;
    //  changeSeconds = false;
   // }
   // if (display.pressedC()){
    //  changeSeconds = true;
    //  changeMinutes = false;
    //}
   // if (changeMinutes == true) {
  //    timer_minutes = value;
  //  }
  //  if (changeSeconds == true) {
  //    timer_seconds = value;
  //  }
  }
  if (temp == true) {
    show();
  } else if (gps == true) {
    Blynk.run();
  }
  


}  