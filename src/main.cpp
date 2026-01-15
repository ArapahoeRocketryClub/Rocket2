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
#include "control.h"
#include "termination.h"
#include "pid.h"

void setup()
{
    InitSerialPort();
    Serial.println(F("Arduino is now online!"));
    InitIMU();
    InitServo();
}

void ControlThrustVector()
{
    ServoX.write(outputSignalCalc(xIntegral, xDerivative, GetOrientation().i, pGain, iGain, dGain));
    ServoY.write(outputSignalCalc(yIntegral, yDerivative, GetOrientation().j, pGain, iGain, dGain));
}

void StateMachine()
{
    switch (state)
    {
    case DISARMED:
        // Function
        
        //EMPTY FOR DISARMED

        // Transition
        if (ARM_STATUS == true)
        {
            state = ARMED;
        }
        break;
    case ARMED:
        // Function
        ResetBarometer();
        // Transition
        
        break;
    case POWERED_ASCENT:
        // Function
        ControlThrustVector();
        // Transition
        if()
        break;
    case BALLISTIC_ASCENT:
        // Function
            //stop ControlThrustVector()
            
        // Transition
                //if not go up then go to BALLISTIC_DESCENT
        
        break;
    case BALLISTIC_DESCENT:
        // Function
            
        // Transition
            //if descent delta is greater then x then go to PARACHUTE_DESCENT
            //or if less then x alt.
        break;
    case PARACHUTE_DESCENT:
        // Function

        // Transition
        // when velocity is a very small value, the rocket has touched down
        if(GetAltitude() <= 5 || GetAcceleration() < 0.2f){
            state = TOUCHDOWN;
        }
        break;
    case TOUCHDOWN:
        // Function
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