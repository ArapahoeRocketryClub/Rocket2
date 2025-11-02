// Name: DataProcessing
// Description: Functions related to manipulating data received from sensors
// Devices: N/A, just input from other code
// Skills: Strong foundations in math and physics. Must be comfortable and enjoy working with vectors, matrices, and numbers. Also requires a strong sense of analyzing inputs/outputs, as most of this deals with converting raw data into usable numbers 
// Dibs: Jordan T.,Drew F,Jacob B
#define MeasVarAccel 2
#define MeasVarAngrVel 2

#include "data_processing.h"
#include "kalmanfilter.h"
#include "global.h"

void createDataHolders(){
    static Acceleration unfilteredAccel;
    static AngularVelocity unfilteredAngVel;
    static Position position;
    static Orientation formattedOrientation;
    
    static kFilter filterAccelX(MeasVarAccel,0);
    static kFilter filterAccelY(MeasVarAccel,0);
    static kFilter filterAccelZ(MeasVarAccel,0);
};