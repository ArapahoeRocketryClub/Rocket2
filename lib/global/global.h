#include "header.h"
// The "global" file is like a community pile for data. It hosts our custom data types (vectors, usually in the form of structs)
// This should be used for things used by more than a single file. All other variables should be contained within their file.

#pragma once

// Constants --- PINS ARE PLACEHOLDERS FOR NOW
const int PIN_SERVO_X = 69;
const int PIN_SERVO_Y = 67;

const int PIN_LED = 420;

const int RADIO_PIN_CE = 42069;
const int RADIO_PIN_CSN = 777;
uint8_t address[][6] = {"1Node", "2Node"}; // For radio



struct Position
{
    double x; // x position in meters, relative to point at init
    double y; // y position in meters, relative to point at init
    double z; // z position in meters, relative to point at init
};

struct Acceleration
{
    double x; // x acceleration in meters/s^2
    double y; // y acceleration in meters/s^2
    double z; // z acceleration in meters/s^2
};

struct Orientation
{
    double x; // x orientation in !RADIANS!, relative to orientation at init
    double y; // y orientation in !RADIANS!, relative to orientation at init
    // No need for z orientation, we cannot control it with TVC, nor do we care about it
};

struct QuaternionRotation
{             // Quaternion. Can be used store position data.
    double w; // Real component

    // imaginary components
    double i;
    double j;
    double k;
};

struct AngularVelocity
{
    double x; // x angular velocity in !RADIANS/SECOND!
    double y; // y angular velocity in !RADIANS/SECOND!
    double z; // z angular velocity in !RADIANS/SECOND!
};

void ReportError(String error); // Publishes an error by sending it over radio and enabling led

extern Position globalPosition;
extern Acceleration globalAcceleration;
extern Orientation globalOrientation;
extern AngularVelocity globalAngularVelocity;
extern QuaternionRotation globalQuaternionOrientation;
extern float Temperature;
extern float Humidity;
extern float Pressure;
extern Servo ServoX;
extern Servo ServoY;
extern Adafruit_BNO08x bno08x; // This is the IMU sensor object.
RF24 radio(RADIO_PIN_CE, RADIO_PIN_CSN);