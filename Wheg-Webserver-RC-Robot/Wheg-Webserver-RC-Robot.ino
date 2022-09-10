/*
 * CWRUbotix bootcamp robot control code
 * 
 * Zach Baldwin 2022
 */

// Libraries that we need
#include <ESPTelnet.h>
#include <WiFi.h>

// Other files that we wrote that we need
#include "Motor.h"

// Some parameters for our WiFi Access Point (AP)
const char* ssid = "YOUR_TEAM";
const char* password = "YOUR_PASSWORD";

// Pin numbers for the motors
#define MOTOR0_L 4
#define MOTOR0_R 15
#define MOTOR1_L 14
#define MOTOR1_R 12

// Create a config object for our web server
ESPTelnet serverFi;

// Create an instance of the Motor class for each motor
Motor motor0 = Motor(MOTOR0_L, MOTOR0_R);
Motor motor1 = Motor(MOTOR1_L, MOTOR1_R);

void setup() {
  // Setup our debug serial port to a common BAUD rate
  Serial.begin(115200);

  // We need to create an Access Point (AP)
  WiFi.mode(WIFI_AP);

  // Setup the credentials and start the AP
  WiFi.softAP(ssid, password);

  // Print some diagnostic data
  Serial.print("MY IP: ");
  Serial.println(WiFi.softAPIP());

  // Start the telnet server
  serverFi.onConnect(telnetConnect);
  serverFi.onConnectionAttempt(telnetAttemptConnection);
  serverFi.onDisconnect(telnetDisconnect);
  serverFi.onReconnect(telnetReconnect);
  serverFi.onInputReceived(telnetEvent);

  // Should do some error checking here...
  serverFi.begin();
}

void telnetConnect(String ip) {
  serverFi.println("\nWelcome to the telnet control!");
  serverFi.println("Escape character: ^] (q to disconnect)");
}

void telnetDisconnect(String ip) {
  // empty
}

void telnetAttemptConnection(String ip) {
  // empty
}

void telnetReconnect(String ip) {
  // empty
}

void loop() {
  serverFi.loop();
}

void telnetEvent(String txt)
{
 if(txt != "")
 {
   if (txt == "q")
   {
     serverFi.disconnectClient();
   }
//    // handle the websocket messages with direction and speed
//    // by parsing the parameters from a JSON string
//    String payload_str = String((char*) payload);
//    // using the ArduinoJson library
//    StaticJsonDocument<200> doc;
//    // deserialize the data
//    DeserializationError error = deserializeJson(doc, payload_str);
//    // parse the parameters we expect to receive (TO-DO: error handling)
//    String dir = doc["direction"];
// //    Serial.print("direction: ");
// //    Serial.println(dir);
//    if(dir == "STP") {
//      motor0.stopMotor();
//      motor1.stopMotor();
//      Serial.println("STOP");
//    } else {
//      int speed = doc["speed"];
//      // on the page speed goes from 0 to 100. scale it between 0 and 255:
//      speed = map(speed, 0, 100, -128, 127);
//      if(dir == "FWD") {
//        motor0.driveMotor(speed);
//        motor1.driveMotor(speed);
//        Serial.println("FORWARD");
//      } else if(dir == "BWD") {
//        motor0.driveMotor(-speed);
//        motor1.driveMotor(-speed);
//        Serial.println("BACKWARD");
//      } else if(dir == "RGT") {
//        motor0.driveMotor(speed);
//        motor1.driveMotor(-speed);
//        Serial.println("RIGHT");
//      } else if(dir == "LFT") {
//        motor0.driveMotor(-speed);
//        motor1.driveMotor(speed);
//        Serial.println("LEFT");
//      }
//    }
 }
}
