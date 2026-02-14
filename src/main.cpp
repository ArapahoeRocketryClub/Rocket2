// File: src/main.cpp
// Description: Main program; contains Arduino setup/loop and state machine
//
// EXTERNAL LIBRARIES (Use <>)
#include <Arduino.h>
#include <Servo.h>
#include <Adafruit_BNO08x.h>
#include <Adafruit_BMP280.h>
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

pid pidServoX(1, 1, 1); // FIXME: Tune PID values
pid pidServoY(1, 1, 1); // FIXME: Tune PID values
void PrintDebug(); // Prints debug info to serial monitor

void setup()
{
    InitSerialPort();
    Serial.println(F("Arduino is now online!"));
    InitIMU();
    InitServo();
}

void ControlThrustVector()
{
    ServoX.write(pidServoX.compute(GetOrientation().i, 0)); //FIXME: Verify
    ServoY.write(pidServoY.compute(GetOrientation().j, 0)); //FIXME: Verify
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
            ResetBarometer();
        }
        break;
    case ARMED:
        // Function
        // Transition
        
        break;
    case POWERED_ASCENT:
        // Function
        ControlThrustVector();
        // Transition
        //if()
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
        if(GetAltitude(AGL) <= 5){
            state = TOUCHDOWN;
        }
        break;
    case TOUCHDOWN:
        // Function
        break;

    default: // Otherwise
        ReportError(F("Someone's gonna get the boot"));
    }
}

void loop()
{
    //StateMachine();
    PrintDebug();
}

void PrintDebug()
{
    Serial.print("=======");
    Serial.print(millis()/1000.00);
    Serial.println("sec =======");
    Serial.print("State: ");
    Serial.println(state);
    Serial.print("Orientation: ");
    Serial.print(GetOrientation().w);
    Serial.print(", ");
    Serial.print(GetOrientation().i);
    Serial.print(", ");
    Serial.print(GetOrientation().j);
    Serial.print(", ");
    Serial.println(GetOrientation().k);
    Serial.print("Acceleration: ");
    Serial.print(GetAcceleration().x);
    Serial.print(", ");
    Serial.print(GetAcceleration().y);
    Serial.print(", ");
    Serial.println(GetAcceleration().z);
    Serial.print("Altitude AGL: ");
    Serial.println(GetAltitude(AGL));
    Serial.print("Altitude MSL: ");
    Serial.println(GetAltitude(MSL));
    delay(300);
}