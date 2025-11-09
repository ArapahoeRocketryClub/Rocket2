// Header files are used to ensure that the files can communicate with each other
#pragma once  // Makes sure this file is included only once during compilation to avoid duplicates
#include <Arduino.h> // Since .h header files are associated with C++, not pure arduino, we have to include Arduino
#include <global.h> // For access to kinematic datatypes
#include <Adafruit_BNO08x.h>
// You can define different functions here. They don't have to have ANY code just yet, just the return type and inputs


/*
You should implement functions to grab data from the following sensors (TONS of documentation and examples are available online, just find one that you like!):

Adafruit BNO085 9-DOF Orientation IMU Fusion Breakout, which measures...
* Acceleration and gravity
* Angular velocity
* Magnetic field strength (for compass) ---- Implementing this is not necessary. It could be a fun challenge, though!

BME280
* Air Pressure
* Altitude above ground
*/

extern Adafruit_BNO08x bno08x;//This is the IMU sensor object.

double GetServoRotation(Servo servo){
    return servo.read();
}

int initializeBno08x();//Sets up communication with BNO08x IMU sensor.
int setReportsBno08x();//Tells the BNO08x what data to output needs to be updated every time sensor is reset.

QuaternionRotation GetOrientation();
Acceleration GetAcceleration(); // See global.h for Acceleration struct
AngularVelocity GetAngularVelocity(); // See global.h for AngularVelocity struct
void ResetBarometer(); // Sets current altitude to 0m height by setting reference air pressure to current air pressure