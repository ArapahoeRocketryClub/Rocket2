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
#include "data_processing.h"

pid pidServoX = pid(1, 0, 0); // FIXME: Tune PID values
pid pidServoY = pid(1, 0, 0); // FIXME: Tune PID values
void PrintDebug(); // Prints debug info to serial monitor

void setup()
{
    InitSerialPort();
    Serial.println(F("Arduino is now online!"));
    InitIMU();
    InitServo();
    InitBarometer();
    initDataHolders();
    ServoX.write(PI/6);
    ServoY.write(PI/6);
}

void ControlThrustVector()
{
    float xVal = pidServoX.compute(GetDecoupledOrientation().x, 0);
    float yVal = pidServoY.compute(GetDecoupledOrientation().y, 0);
    Serial.println(F("TVC Control:"));
    Serial.print("X Servo Angle (degrees): ");
    Serial.print(xVal * 180/PI);
    Serial.print(", Y Servo Angle (degrees): ");
    Serial.println(yVal * 180/PI);
    ServoX.write(xVal); //FIXME: Verify
    ServoY.write(yVal); //FIXME: Verify
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
            ARM_STATUS = false;
            ResetBarometer();
        }
        break;
    case ARMED:
        // Function
        // Transition
        if(GetAcceleration().z > 15 && GetAltitude(AGL) > 10) {
            state = POWERED_ASCENT;
        }
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
    ControlThrustVector();
    
}

void PrintDebug()
{
    checkImuForData();
    updateLocalData();
    calculateNewState();
    updateGlobalData();
    
    //Time and State information
    Serial.print("=======");
    Serial.print(millis()/1000.00);
    Serial.println("sec =======");
    Serial.print("State: ");
    Serial.println(state);

    //Quaternion Orientation
    Serial.print("Orientation Quaternion: ");
    Serial.print(GetOrientation().w);
    Serial.print(", ");
    Serial.print(GetOrientation().i);
    Serial.print(", ");
    Serial.print(GetOrientation().j);
    Serial.print(", ");
    Serial.println(GetOrientation().k);

    //Orientation Angles Relative to servos
    Serial.print("Orientation Servo Relative Angles: ");
    Serial.print(GetDecoupledOrientation().x * 180/PI);
    Serial.print(", ");
    Serial.println(GetDecoupledOrientation().y * 180/PI);
    delay(100);

    
}