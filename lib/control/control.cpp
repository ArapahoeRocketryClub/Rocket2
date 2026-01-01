// File: lib/control/control.cpp
// Description: Implementations for servo and GPIO control helpers

// INTERNAL LIBRARIES (Use "")
#include "control.h"

// Name: Control
// Description: Functions related to controlling motion (Example: servos for TVC, parachute deployment, etc)
// Devices: 9g Servo
// Skills: Redundant / safe coding habits (parachutes are important!), reading documentation

// Dibs: Alex todd, Jacob B.

void MoveServo(Servo servo, double rotation)
{
    servo.write((rotation * PI) / 180);
}

void SetLight(bool state, int pin)
{
    if (state == true)
    {
        digitalWrite(LED_BUILTIN, HIGH);
    }
    if (state == false)
    {
        digitalWrite(LED_BUILTIN, LOW);
    }
}

void servoTestRotation()
{
    // Move servox ands servoy within range
}