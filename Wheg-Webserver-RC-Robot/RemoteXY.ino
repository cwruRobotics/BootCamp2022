/*
   -- LED_DEMO --
   
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
#define REMOTEXY_WIFI_SSID "RemoteXYMichael"
#define REMOTEXY_WIFI_PASSWORD "hello"
#define REMOTEXY_SERVER_PORT 6377


// RemoteXY configurate  
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =   // 19 bytes
  { 255,2,0,0,0,12,0,16,31,1,5,0,10,25,43,43,2,26,31 };
  
// this structure defines all the variables and events of your control interface 
struct {

    // input variables
  int8_t joystick_1_x; // from -100 to 100  
  int8_t joystick_1_y; // from -100 to 100  

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0 

} RemoteXY;
#pragma pack(pop)

/////////////////////////////////////////////
//           END RemoteXY include          //
/////////////////////////////////////////////

int ain1=4;
int ain2=3;
int apwm=2;

int bin1=9;
int bin2=8;
int bpwm=7;


void setup() 
{
  RemoteXY_Init (); 
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

 //analogWrite(apwm, 100);
  //analogWrite(bpwm, 100);
  
  RemoteXY_Handler ();/*
  if(RemoteXY.joystick_1_x > 75) {
    //up
    digitalWrite(ain1, HIGH);
    digitalWrite(ain2, LOW);
    digitalWrite(bin1, LOW);
    digitalWrite(bin2, HIGH);
  }
  else if (RemoteXY.joystick_1_x < -75) {
    //down
    digitalWrite(ain1, LOW);
    digitalWrite(ain2, HIGH);
    digitalWrite(bin1, HIGH);
    digitalWrite(bin2, LOW);
  }
  else if (RemoteXY.joystick_1_y > 75) {
    //left
    digitalWrite(ain1, LOW);
    digitalWrite(ain2, HIGH);
    digitalWrite(bin1, LOW);
    digitalWrite(bin2, HIGH);
  }
  else if (RemoteXY.joystick_1_y < -75) {
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
  */
  
  
  // TODO you loop code
  // use the RemoteXY structure for data transfer
  // do not call delay() 


}