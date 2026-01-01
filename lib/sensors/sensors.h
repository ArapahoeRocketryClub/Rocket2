// File: lib/sensors/sensors.h
// Description: Sensor interface prototypes for IMU, barometer and related helpers
// EXTERNAL LIBRARIES (Use <>)
#define SENSORSLIB

#ifndef ARDUINOLIB
#define ARDUINOLIB
#include <Arduino.h>
#endif

#ifndef SERVOLIB
#define SERVOLIB
#include <Servo.h>
#endif

#ifndef BNO08XLIB
#define BNO08XLIB
#include <Adafruit_BNO08x.h>
#endif

#ifndef BME280LIB
#define BME280LIB
#include <Adafruit_BME280.h>
#endif

// INTERNAL LIBRARIES (Use "")
#ifndef GLOBALLIB
#define GLOBALLIB
#include "global.h"
#endif

// Header files are used to ensure that the files can communicate with each other
// You can define different functions here. They don't have to have ANY code just yet, just the return type and inputs


/*
You should implement functions to grab data from the following sensors (TONS of documentation and examples are available online, just find one that you like!):

Adafruit BNO085 9-DOF Orientation IMU Fusion Breakout, which measures...
* Acceleration and gravity
* Angular orientation
* Magnetic field strength (for compass) ---- Implementing this is not necessary. It could be a fun challenge, though!

BME280
* Air Pressure
* Altitude above ground
*/

double GetServoRotation(Servo servo);
int setReportsBno08x();//Tells the BNO08x what data to output needs to be updated every time sensor is reset.
int checkImuForData();//Checks for new IMU data. If so, the function returns 1 and stores the data in the global variables.
int checkBarometerForData();//Gets new pressure data from barometer.
QuaternionRotation GetOrientation();//Returns quaternion orientation.
Acceleration GetAcceleration(); // See global.h for Acceleration struct.
AngularVelocity GetAngularVelocity(); // See global.h for AngularVelocity struct.
void ResetBarometer(); // Sets current altitude to 0m height by setting reference air pressure to current air pressure.