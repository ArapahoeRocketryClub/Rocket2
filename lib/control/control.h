// File: lib/control/control.h
// Description: Control helper prototypes for servos and GPIOs
//

#ifndef CONTROLLIB
#define CONTROLLIB

// EXTERNAL LIBRARIES (Use <>)
#include <Arduino.h>
#include <Servo.h>
#include <Adafruit_BNO08x.h>

// INTERNAL LIBRARIES (Use "")
#include "global.h"

void SetLight(bool state, int pin);        // Sets the LED on given to the state (on/off)
void MoveServo(Servo& servo, double angle); // Moves the specified servo to an !RADIANS! (not degrees)

#endif