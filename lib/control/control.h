#include "header.h"
// Header files are used to ensure that the files can communicate with each other
#pragma once  // Makes sure this file is included only once during compilation to avoid duplicates

void SetLight(bool state, int pin); // Sets the LED on given to the state (on/off)
void MoveServo(Servo servo, double angle); // Moves the specified servo to an !RADIANS! (not degrees)

/*
void ifServoError(){};
void SignalIntegrityCheck(){};
void ServoFailsafe(){};
void ServoManualOverride(){};
*/