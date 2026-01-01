// File: lib/global/global.cpp
// Description: Definitions for global variables and helper utilities
//
#include "global.h"

Position globalPosition;
Acceleration globalAcceleration;
Orientation globalOrientation;
QuaternionRotation globalQuaternionOrientation;
AngularVelocity globalAngularVelocity;

void ReportError(String error) // Publishes an error by sending it over radio and enabling led
{
    Serial.print(F("!ERROR!: "));
    Serial.println(error);
    SetLight(true, PIN_LED);
}

RF24 radio(RADIO_PIN_CE, RADIO_PIN_CSN);