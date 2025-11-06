#include <Servo.h>
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
    servo.write(rotation);
    }
}

double GetServoRotation(Servo servo){
    return servo.read();
}



void checkServoWires(){};
void 