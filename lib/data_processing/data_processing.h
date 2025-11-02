// Header files are used to ensure that the files can communicate with each other
#pragma once  // Makes sure this file is included only once during compilation to avoid duplicates
#include <Arduino.h> // Since .h header files are associated with C++, not pure arduino, we have to include Arduino

// You can define different functions here. They don't have to have ANY code just yet, just the return type and inputs
//Define some functions below:


//Setup
void createDataHolders();

//Iterated code
void updateDataFromSensors();
void filterData();
void calculateNewState();
void formatData();
void pushDataToGlobal();
