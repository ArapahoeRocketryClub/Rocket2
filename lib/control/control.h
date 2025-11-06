// Header files are used to ensure that the files can communicate with each other
#pragma once  // Makes sure this file is included only once during compilation to avoid duplicates
#include <Arduino.h>

void SetLight(bool state, int pin); // Sets the LED on given to the state (on/off)
void MoveServo(double xAngle, double yAngle); // Moves x and y servos to an !RADIANS! (not degrees)

