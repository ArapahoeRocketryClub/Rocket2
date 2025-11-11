#include "header.h"
// Name: Control
// Description: Functions related to controlling motion (Example: servos for TVC, parachute deployment, etc)
// Devices: 9g Servo
// Skills: Redundant / safe coding habits (parachutes are important!), reading documentation

// Dibs: alex todd, Jacob B.

//checking that all wire are pluged in, so no errors?
//Power supply stability test
//Signal integrity check
//Fail-safe state test
//Error detection & logging
//Manual override, test mode

//vars to include
bool override = false;

// keep in mind, 0 is full speed in one directction
// 180 is full speed in the other
// 90 is no movement
void MoveServo(Servo servo, double rotation){
    if (!override){
    servo.write((rotation*PI)/180);
    }
}

void SetLight(bool state, int pin) {
    if(state == true) { 
        digitalWrite(LED_BUILTIN, HIGH);
    }
    if(state == false) {
        digitalWrite(LED_BUILTIN, LOW);
    }
}

void servoTestRotation(){
    // Move the servo to 0 degrees
    myServo.write(0);
    Serial.println("Moving to 0 degrees...");
    //if something
    delay(1000); // Wait for 1 second

    // Move the servo to 90 degrees
    myServo.write(90);
    Serial.println("Moving to 90 degrees...");
    //if something
    delay(1000);

    // Move the servo to 180 degrees
    myServo.write(180);
    Serial.println("Moving to 180 degrees...");
    //if something
    delay(1000);    
}