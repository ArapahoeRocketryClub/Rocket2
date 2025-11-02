#pragma once

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
    // No need for z orientation, we cannot control it nor do we care about it
};

struct AngularVelocity {
    double x; // x angular velocity in !RADIANS/SECOND!
    double y; // y angular velocity in !RADIANS/SECOND!
    double z; // z angular velocity in !RADIANS/SECOND!
};

extern Position globalPosition;
extern Acceleration globalAcceleration;
extern Orientation globalOrientation;
extern AngularVelocity globalAngularVelocity;
