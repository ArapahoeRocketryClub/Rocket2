// Name: Main
// Description: Main code. Includes the state machine.

// Do not sign up for this one right now. We will develop this once the rest are done.
#include "header.h"
#include "sensors.h"
#include "init.h"

void setup() {
    InitSerialPort();
    Serial.println(F("Arduino is now online!"));
    InitIMU();
    InitServo();

}

void loop() {
    QuaternionRotation tempOrientation = GetOrientation();
    Serial.print("Orientation w: %f i: %f j: %f k: %f\n");
    Serial.print(tempOrientation.w);
    Serial.print(tempOrientation.i);
    Serial.print(tempOrientation.j);
    Serial.println(tempOrientation.k);
}