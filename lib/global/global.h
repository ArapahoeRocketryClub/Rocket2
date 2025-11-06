// The "global" file is like a community pile for data. It hosts our custom data types (vectors, usually in the form of structs)
// This should be used for things used by more than a single file. All other variables should be contained within their file. 

#pragma once

const int PIN_SERVO_X = 1;
const int PIN_SERVO_Y = 2;
const int RADIO_PIN_CE = 3;
const int RADIO_PIN_CSN = 3;

struct Position {
    double x; // x position in meters, relative to point at init 
    double y; // y position in meters, relative to point at init
    double z; // z position in meters, relative to point at init
};

struct Acceleration {
    double x; // x acceleration in meters/s^2 
    double y; // y acceleration in meters/s^2 
    double z; // z acceleration in meters/s^2 
};

struct Orientation {
    double x; // x orientation in !RADIANS!, relative to orientation at init
    double y; // y orientation in !RADIANS!, relative to orientation at init
    // No need for z orientation, we cannot control it with TVC, nor do we care about it
};

struct AngularVelocity {
    double x; // x angular velocity in !RADIANS/SECOND!
    double y; // y angular velocity in !RADIANS/SECOND!
    double z; // z angular velocity in !RADIANS/SECOND!
};

void ReportError(); // Publishes an error by sending it over radio and

extern Position globalPosition;
extern Acceleration globalAcceleration;
extern Orientation globalOrientation;
extern AngularVelocity globalAngularVelocity;