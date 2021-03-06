#include <Wire.h>
#include "Adafruit_TCS34725.h"
#include <Servo.h>

//global variables
Servo base_servo; // Takes 0 to 359 degrees
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);
int base_pin = 9;
int base_stop =90; // stop
int base_speed= 0; // speed can be from 0 to 89 with 0 being fastest, add 90 to reverse directions
int deg_per_iteration= 10;
float color_threshold=100;
int COUNT=15;
int counter=0;

void setup() {
  Serial.begin(9600);
  base_servo.attach(base_pin);


    while (!tcs.begin()){
       Serial.println("No TCS34725 found ... check your connections");
       delay(1000);
    }

  
}
void loop() {

  
    //move
  base_servo.write(counter);
  counter = counter + COUNT;
  //base_servo.write(base_stop);

  float red, green, blue;


  tcs.setInterrupt(false);  // turn on LED

  //delay(60);  // takes 50ms to read

  tcs.getRGB(&red, &green, &blue);
  
  tcs.setInterrupt(true);  // turn off LED

  Serial.print("R:\t"); Serial.print(int(red)); 
  Serial.print("\tG:\t"); Serial.print(int(green)); 
  Serial.print("\tB:\t"); Serial.print(int(blue));
    Serial.print("\n");
  if(red>color_threshold){
      //move to red
  }
  else if(green>color_threshold){
        //move to green
    }
  else  if(blue>color_threshold){
      //move to blue
  }


}
