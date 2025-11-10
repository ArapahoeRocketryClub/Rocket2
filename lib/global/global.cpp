#include "header.h"

Position globalPosition;
Acceleration globalAcceleration;
Orientation globalOrientation;
QuaternionRotation globalQuaternionOrientation;
AngularVelocity globalAngularVelocity;

void ReportError(String error) // Publishes an error by sending it over radio and enabling led
{
    Serial.print(F("!ERROR!: "));
    Serial.println(error);
    SetLight(true, PIN_LED)
}