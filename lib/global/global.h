// Makes sure this file is included only once during compilation to avoid duplicates
#ifndef GLOBALLIB
#define GLOBALLIB

// EXTERNAL LIBRARIES (Use <>)
#ifndef ARDUINOLIB
#define ARDUINOLIB
#include <Arduino.h>
#endif

#ifndef RF24LIB
#define RF24LIB
#include <RF24.h>
#endif

#ifndef BNO08XLIB
#define BNO08XLIB
#include <Adafruit_BNO08x.h>
#endif

#ifndef SERVOLIB
#define SERVOLIB
#include <Servo.h>
#endif

#define AGL 0
#define MSL 1

// INTERNAL LIBRARIES (Use "")
// The "global" file is like a community pile for data. It hosts our custom data types (vectors, usually in the form of structs)
// This should be used for things used by more than a single file. All other variables should be contained within their file.

// State machine magic

extern int state;
extern double reference_pressure;
extern bool ARM_STATUS;

extern double xIntegral;
extern double xDerivative;
extern double yIntegral;
extern double yDerivative;


enum STATE_MACHINE_STATES
{                      // Corresponds to state = 0, 1, 2, ...
    DISARMED = 0,      // No input, just activated
    ARMED,             // "ARM" signal received from ground control
    POWERED_ASCENT,    // Engine activated, flying up. Use TVC.
    BALLISTIC_ASCENT,  // Engine burnout, still flying up. Stop using TVC.
    BALLISTIC_DESCENT, // Descending below vertex, no parachute
    PARACHUTE_DESCENT, // Descending with parachute
    TOUCHDOWN,         // Pretty self explanatory
    num_states         // 7, if nothing changes
};

// Constants --- PINS ARE PLACEHOLDERS FOR NOW

const int PIN_SERVO_X = -1;
const int PIN_SERVO_Y = -1;

const int PIN_LED = -1;

const int RADIO_PIN_CE = -1;
const int RADIO_PIN_CSN = -1;

const double pGain = 1;
const double iGain = 1;
const double dGain = 1;

const double LAUNCH_ACCELERATION_THRESHOLD = 5.0;

const float MeasVarAccel = 2;  // Measurement Variance for acceleration (will need to be calculated for the imu)
const float MeasVarAngVel = 2; // Measurement Variance for angular velocity (will need to be calculated for the imu)

extern uint8_t address[][6]; // For radio

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

typedef struct AngularVelocity AngularPosition;

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
extern RF24 radio;
extern Adafruit_BNO08x bno08x; // This is the IMU sensor object.
#endif