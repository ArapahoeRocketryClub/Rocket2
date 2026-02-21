#include "data_processing.h"
// Name: DataProcessing
// Description: Functions related to manipulating data received from sensors
// Devices: N/A, just input from other code
// Skills: Strong foundations in math and physics. Must be comfortable and enjoy working with vectors, matrices, and numbers. Also requires a strong sense of analyzing inputs/outputs, as most of this deals with converting raw data into usable numbers

// Dibs: Jordan T.,Drew F,Jacob B
namespace dataTemps
{                              // Temporary Variables to be used for data processing.
    Acceleration accel;        // Stores acceleration data.
    QuaternionRotation angPos; // Stores angular data.
    Position position;
    Orientation formattedOrientation;
    QuaternionRotation initialReferenceRotation; // Stores the initial orientation of the rocket to be used as a reference point.
    kFilter filterAccelX(1, 1);
    kFilter filterAccelY(1, 1);
    kFilter filterAccelZ(1, 1);
}

void initDataHolders()
{
    // Currently assumes that the rocket is stationary at 0,0,0 when starting
    dataTemps::accel.x = 0;
    dataTemps::accel.y = 0;
    dataTemps::accel.z = 0;

    dataTemps::angPos.w = 1;
    dataTemps::angPos.i = 0;
    dataTemps::angPos.j = 0;
    dataTemps::angPos.k = 0;

    dataTemps::position.x = 0;
    dataTemps::position.y = 0;
    dataTemps::position.z = 0;

    dataTemps::initialReferenceRotation.w = 1;
    dataTemps::initialReferenceRotation.i = 0;
    dataTemps::initialReferenceRotation.j = 0;
    dataTemps::initialReferenceRotation.k = 0;

    dataTemps::formattedOrientation.x = 0;
    dataTemps::formattedOrientation.y = 0;

    dataTemps::filterAccelX = kFilter(MeasVarAccel, 0);
    dataTemps::filterAccelY = kFilter(MeasVarAccel, 0);
    dataTemps::filterAccelZ = kFilter(MeasVarAccel, 0);
};

void filterAccelerationData()
{
    Acceleration accelTemp = GetAcceleration(); // Steps kalman filters for the accelertation measurements and stores the new estimates into the temporary acceleration variable
    dataTemps::accel.x = dataTemps::filterAccelX.step(accelTemp.x);
    dataTemps::accel.y = dataTemps::filterAccelY.step(accelTemp.y);
    dataTemps::accel.z = dataTemps::filterAccelZ.step(accelTemp.z);
};

void updateGlobalData()
{
    globalPosition = dataTemps::position;                // Updates global position variable
    globalOrientation = dataTemps::formattedOrientation; // Updates global orientation variable
};

void initialRotation()
{
    QuaternionRotation currentRotation = GetOrientation();
    dataTemps::initialReferenceRotation = currentRotation;
}

void updateLocalData()
{
    dataTemps::accel = GetAcceleration();
    dataTemps::angPos = GetOrientation();
    // Update translational accel here
}

void calculateNewState()
{
    QuaternionRotation rotateInitToCurrent; // Quaternion orientation relative to init quaternion orientation.
    QuaternionRotation twist;               // Quaternion rotation about servo 1 axis.
    QuaternionRotation swing;               // Quaternion rotation about servo 2 axis.
    rotateInitToCurrent = quaternionMultiply(dataTemps::angPos, quaternionInverse(dataTemps::initialReferenceRotation));

    Position servo1Axis;
    servo1Axis.x = SERVOAXISX1;
    servo1Axis.y = SERVOAXISY1;
    servo1Axis.z = SERVOAXISZ1;
    servo1Axis = rotateVecQuaternion(servo1Axis, rotateInitToCurrent); // Transform axis of servo 1 so that is relative to world.

    Position servo2Axis;
    servo2Axis.x = SERVOAXISX2;
    servo2Axis.y = SERVOAXISY2;
    servo2Axis.z = SERVOAXISZ2;
    servo2Axis = rotateVecQuaternion(servo2Axis, rotateInitToCurrent); // Transform axis of servo 2 so that is relative to world.

    twist = swingTwistDecompositionPartialT(servo1Axis, rotateInitToCurrent); // Take component of rocket's orientation about the servo 1 axis.
    swing = swingTwistDecompositionPartialS(twist, rotateInitToCurrent);      // Remainder rotation of the orientation.

    twist = normQuaternion(twist);                              // Normalize quaternion.
    swing = swingTwistDecompositionPartialT(servo2Axis, swing); // Take component of rocket's remainder orientation about the servo 2 axis.
    swing = normQuaternion(swing);                              // Normalize quaternion.

    dataTemps::formattedOrientation.x = 2 * acos(twist.w); // Angle of the quaternion rotation
    dataTemps::formattedOrientation.y = 2 * acos(swing.w); // Angle of the quaternion rotation
}

/*
AngularPosition eulerBody321AnglesFromQuaternion(QuaternionRotation q)
{
    AngularPosition angles;
    // Yaw (z-axis rotation)
    angles.z = atan2(2.0 * (q.w * q.j - q.i * q.k), 1.0 - 2.0 * (q.j * q.j + q.k * q.k));
    // Pitch (y-axis rotation)
    angles.y = asin(2.0 * (q.i * q.j + q.k * q.w));
    // Roll (x-axis rotation)
    angles.x = atan2(2.0 * (q.i * q.w - q.k * q.j), 1.0 - 2.0 * (q.i * q.i + q.k * q.k));
    return angles;
}*/
