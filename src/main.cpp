// File: src/main.cpp
// Description: Main program; contains Arduino setup/loop and state machine
//
// EXTERNAL LIBRARIES (Use <>)
#include <Arduino.h>
#include <Servo.h>
#include <Adafruit_BNO08x.h>
#include <Adafruit_BME280.h>
#include <RF24.h>

// INTERNAL LIBRARIES (Use "")
#include "global.h"
#include "kalmanfilter.h"
#include "statistics.h"
#include "sensors.h"
#include "init.h"

void setup()
{
    InitSerialPort();
    Serial.println(F("Arduino is now online!"));
    InitIMU();
    InitServo();
}

void StateMachine()
{
    switch (state)
    {
    case DISARMED:
        // Function

        // Transition

        break;
    case ARMED:
        // Function

        // Transition

        break;
    case POWERED_ASCENT:
        // Function

        // Transition

        break;
    case BALLISTIC_ASCENT:
        // Function

        // Transition

        break;
    case BALLISTIC_DESCENT:
        // Function

        // Transition

        break;
    case PARACHUTE_DESCENT:
        // Function

        // Transition

        break;
    case TOUCHDOWN:
        // Function

        // Transition

        break;

    default:
        ReportError(F("Someone's gonna get the boot"));
    }
}

void loop()
{
    StateMachine();
    QuaternionRotation tempOrientation = GetOrientation();
    Serial.print("Orientation w: %f i: %f j: %f k: %f\n");
    Serial.print(tempOrientation.w);
    Serial.print(tempOrientation.i);
    Serial.print(tempOrientation.j);
    Serial.println(tempOrientation.k);
}