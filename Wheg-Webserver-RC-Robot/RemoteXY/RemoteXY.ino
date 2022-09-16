/*
   -- New project --
   
   This source code of graphical user interface 
   has been generated automatically by RemoteXY editor.
   To compile this code using RemoteXY library 3.1.8 or later version 
   download by link http://remotexy.com/en/library/
   To connect using RemoteXY mobile app by link http://remotexy.com/en/download/                   
     - for ANDROID 4.11.1 or later version;
     - for iOS 1.9.1 or later version;
    
   This source code is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.    
*/

//////////////////////////////////////////////
//        RemoteXY include library          //
//////////////////////////////////////////////

// RemoteXY select connection mode and include library 
#define REMOTEXY_MODE__ESP32CORE_WIFI_POINT
#include <WiFi.h>

#include <RemoteXY.h>

// RemoteXY connection settings 
#define REMOTEXY_WIFI_SSID "RemoteXY"
#define REMOTEXY_WIFI_PASSWORD "12345678"
#define REMOTEXY_SERVER_PORT 6377


// RemoteXY configurate  
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =   // 46 bytes
  { 255,4,0,0,0,39,0,16,31,1,1,0,21,17,12,12,2,31,0,1,
  0,12,43,12,12,2,31,0,1,0,36,45,12,12,2,31,0,1,0,21,
  61,12,12,2,31,0 };
  
// this structure defines all the variables and events of your control interface 
struct {

    // input variables
  uint8_t button_1; // =1 if button pressed, else =0 
  uint8_t button_2; // =1 if button pressed, else =0 
  uint8_t button_3; // =1 if button pressed, else =0 
  uint8_t button_4; // =1 if button pressed, else =0 

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0 

} RemoteXY;
#pragma pack(pop)

/////////////////////////////////////////////
//           END RemoteXY include          //
/////////////////////////////////////////////




int ain1=12;
int ain2=14;
int apwm=27;

int bin1=25;
int bin2=33;
int bpwm=32;


void setup() 
{
  // DO NOT REMOVE DELAYS AT ALL COST OR IT WON'T MOVE!!!!!!!!!!!!!!!
  delay(100);
  RemoteXY_Init (); 
  delay(100);
  pinMode(ain1, OUTPUT);
  pinMode(ain2, OUTPUT);
  pinMode(apwm, OUTPUT);
  pinMode(bin1, OUTPUT);
  pinMode(bin2, OUTPUT);
  pinMode(bpwm, OUTPUT);
  
  // TODO you setup code
  

}

void loop() 
{ 
  
  analogWrite(apwm, 127);
  analogWrite(bpwm, 127);
  
  RemoteXY_Handler ();
  
  if(RemoteXY.button_1 == 1) {
    //up
    digitalWrite(ain1, HIGH);
    digitalWrite(ain2, LOW);
    digitalWrite(bin1, LOW);
    digitalWrite(bin2, HIGH);
  }
  else if(RemoteXY.button_2 == 1) {
    //down
    digitalWrite(ain1, LOW);
    digitalWrite(ain2, HIGH);
    digitalWrite(bin1, HIGH);
    digitalWrite(bin2, LOW);
  }
  else if(RemoteXY.button_3 == 1) {
    //left
    digitalWrite(ain1, LOW);
    digitalWrite(ain2, HIGH);
    digitalWrite(bin1, LOW);
    digitalWrite(bin2, HIGH);
  }
  else if(RemoteXY.button_4 == 1) {
    //right
    digitalWrite(ain1, HIGH);
    digitalWrite(ain2, LOW);
    digitalWrite(bin1, HIGH);
    digitalWrite(bin2, LOW);
  }
  else{
    //stop
    digitalWrite(ain1, LOW);
    digitalWrite(ain2, LOW);
    digitalWrite(bin1, LOW);
    digitalWrite(bin2, LOW);
  }
  
  
  
  // TODO you loop code
  // use the RemoteXY structure for data transfer
  // do not call delay() 

}
