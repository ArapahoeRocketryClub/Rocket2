// Header files are used to ensure that the files can communicate with each other
#pragma once  // Makes sure this file is included only once during compilation to avoid duplicates
#include <Arduino.h>

// You can define different functions here. They don't have to have ANY code just yet, just the return type and inputs

// Code to run at beginning
void createDataHolders();//Creates temporary variables to hold information, such as position and acceleration

// Code to run repeatedly
void filterData();//Takes data from sensors and uses the Kalman filter to improce the raw sensor data.
void calculateNewState();//Uses the filtered angular velocity to calculate new orientation and uses this orientation and acceleration to calulate new global position.
void formatData();//Converts the orientation to decoupled Euler angles so it can be put in the global variables.
void updateGlobalData();//Updates the global position and orientation with new data. 