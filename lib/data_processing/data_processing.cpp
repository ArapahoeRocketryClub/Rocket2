// Name: DataProcessing
// Description: Functions related to manipulating data received from sensors
// Devices: N/A, just input from other code
// Skills: Strong foundations in math and physics. Must be comfortable and enjoy working with vectors, matrices, and numbers. Also requires a strong sense of analyzing inputs/outputs, as most of this deals with converting raw data into usable numbers 

// Dibs: Jordan T.,Drew F,Jacob B
#define MeasVarAccel 2
#define MeasVarAngVel 2

#include "data_processing.h"
#include "kalmanfilter.h"
#include "global.h"

void createDataHolders(){
    namespace dataTemps {
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
    
};

//void filterData(){
//    Acceleration accelTemp = GetAcceleration();
//    dataTemps::accel.x = data:
//};

void updateGlobalData(){
    globalPosition = dataTemps::position;
    globalOrientation = dataTemps::formattedOrientation;
};