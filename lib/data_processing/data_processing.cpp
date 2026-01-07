#include "data_processing.h"
// Name: DataProcessing
// Description: Functions related to manipulating data received from sensors
// Devices: N/A, just input from other code
// Skills: Strong foundations in math and physics. Must be comfortable and enjoy working with vectors, matrices, and numbers. Also requires a strong sense of analyzing inputs/outputs, as most of this deals with converting raw data into usable numbers 

// Dibs: Jordan T.,Drew F,Jacob B

void initDataHolders(){
    // Currently assumes that the rocket is stationary at 0,0,0 when starting
    dataTemps::accel.x = 0;
    dataTemps::accel.y = 0;
    dataTemps::accel.z = 0;

    dataTemps::angPos.w = 0;
    dataTemps::angPos.i = 0;
    dataTemps::angPos.j = 0;
    dataTemps::angPos.k = 0;

    dataTemps::position.x = 0;
    dataTemps::position.y = 0;
    dataTemps::position.z = 0;

    dataTemps::initalReferenceRotation.w = 0;
    dataTemps::initalReferenceRotation.i = 0;
    dataTemps::initalReferenceRotation.j = 0;
    dataTemps::initalReferenceRotation.k = 0;

    dataTemps::formattedOrientation.x = 0;
    dataTemps::formattedOrientation.y = 0;
};

void filterData(){
    Acceleration accelTemp = GetAcceleration();
    //Steps kalman filters for the accelertation measurements and stores the new estimates into the temporary acceleration variable
    dataTemps::accel.x = dataTemps::filterAccelX.step(accelTemp.x);
    dataTemps::accel.y = dataTemps::filterAccelY.step(accelTemp.y);
    dataTemps::accel.z = dataTemps::filterAccelZ.step(accelTemp.z);
};

void updateGlobalData(){
    globalPosition = dataTemps::position;//Updates global position variable
    globalOrientation = dataTemps::formattedOrientation;//Updates global orientation variable
};

void initialRotation(){
    QuaternionRotation currentRotation = GetOrientation();
    dataTemps::initalReferenceRotation = currentRotation;
}

AngularPosition eulerBody321AnglesFromQuaternion(QuaternionRotation q){
    AngularPosition angles;
    // Yaw (z-axis rotation)
    angles.z = atan2(2.0 * (q.w * q.j - q.i * q.k), 1.0 - 2.0 * (q.j * q.j + q.k * q.k));
    // Pitch (y-axis rotation)
    angles.y = asin(2.0 * (q.i * q.j + q.k * q.w));
    // Roll (x-axis rotation)
    angles.x = atan2(2.0 * (q.i * q.w - q.k * q.j), 1.0 - 2.0 * (q.i * q.i + q.k * q.k));
    return angles;
}
