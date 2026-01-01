// File: lib/control/control.h
// Description: Control helper prototypes for servos and GPIOs
//

// EXTERNAL LIBRARIES (Use <>)
#define CONTROLLIB

#ifndef ARDUINOLIB
#define ARDUINOLIB
#include <Arduino.h>
#endif

#ifndef SERVOLIB
#define SERVOLIB
#include <Servo.h>
#endif

// INTERNAL LIBRARIES (Use "")
#ifndef GLOBALLIB
#define GLOBALLIB
#include "global.h"
#endif


void SetLight(bool state, int pin); // Sets the LED on given to the state (on/off)
void MoveServo(Servo servo, double angle); // Moves the specified servo to an !RADIANS! (not degrees)
