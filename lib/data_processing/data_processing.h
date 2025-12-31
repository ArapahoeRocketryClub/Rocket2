#pragma once  // Makes sure this file is included only once during compilation to avoid duplicates
#include "header.h"

// Header files are used to ensure that the files can communicate with each other

// Code to run at beginning
#ifndef DATATEMPS
#define DATATEMPS
namespace dataTemps {//Temporary Variables to be used for data processing.
    extern Acceleration accel;//Stores filtered acceleration data.
    extern QuaternionRotation angPos;//Stores filtered angular velocity data.
    extern Position position;
    extern Orientation formattedOrientation;
    extern QuaternionRotation initalReferenceRotation;//Stores the initial orientation of the rocket to be used as a reference point.
    
    kFilter filterAccelX(MeasVarAccel,0);
    kFilter filterAccelY(MeasVarAccel,0);
    kFilter filterAccelZ(MeasVarAccel,0);
}
#endif
void initDataHolders();//Adds inital data to temporary variables such as position and acceleration

// Code to run repeatedly
void filterData();//Takes data from sensors and uses the Kalman filter to improce the raw sensor data.
void calculateNewState();//Uses the filtered angular velocity to calculate new orientation and uses this orientation and acceleration to calulate new global position.
void formatData();//Converts the orientation to decoupled Euler angles so it can be put in the global variables.
void updateGlobalData();//Updates the global position and orientation with new data.
void initialRotation();//Sets the initial orientation of the rocket to be used as a reference point for all future orientation data.