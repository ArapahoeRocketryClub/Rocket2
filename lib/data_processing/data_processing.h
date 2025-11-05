// Header files are used to ensure that the files can communicate with each other
#pragma once  // Makes sure this file is included only once during compilation to avoid duplicates
#include <Arduino.h>

#define MeasVarAccel 2 //Measurement Variance for acceleration (will need to be calculated for the imu)
#define MeasVarAngVel 2 //Measurement Variance for angular velocity (will need to be calculated for the imu)
// You can define different functions here. They don't have to have ANY code just yet, just the return type and inputs

// Code to run at beginning
namespace dataTemps {//Temporary Variables to be used for data processing
    extern Acceleration accel;
    extern AngularVelocity angVel;
    extern Position position;
    extern Orientation formattedOrientation;
    
    extern kFilter filterAccelX(MeasVarAccel,0);
    extern kFilter filterAccelY(MeasVarAccel,0);
    extern kFilter filterAccelZ(MeasVarAccel,0);
    
    extern kFilter filterAngVelX(MeasVarAngVel,0);
    extern kFilter filterAngVelY(MeasVarAngVel,0);
    extern kFilter filterAngVelZ(MeasVarAngVel,0);
}

void initDataHolders();//Adds inital data to temporary variables such as position and acceleration

// Code to run repeatedly
void filterData();//Takes data from sensors and uses the Kalman filter to improce the raw sensor data.
void calculateNewState();//Uses the filtered angular velocity to calculate new orientation and uses this orientation and acceleration to calulate new global position.
void formatData();//Converts the orientation to decoupled Euler angles so it can be put in the global variables.
void updateGlobalData();//Updates the global position and orientation with new data. 