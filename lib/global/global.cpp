// File: lib/global/global.cpp
// Description: Definitions for global variables and helper utilities
//

#include "global.h"

int state = 0;
bool ARM_STATUS = false;

double xIntegral = 0.0;
double xDerivative = 0.0;
double yIntegral = 0.0;
double yDerivative = 0.0;

double reference_pressure = 1010.8; // Typical air pressure, in HPa, for Denver

uint8_t address[][6] = {"1Node", "2Node"}; // For radio

TVCServo ServoX = TVCServo(PIN_SERVO_X, 0);
TVCServo ServoY = TVCServo(PIN_SERVO_Y, 0);

TVCServo::TVCServo(int p, double zero)
{
    pin = p;
    zeroAngleRadians = zero;
}

void TVCServo::init()
{
    s.attach(pin);
}

void TVCServo::write(float targetAngleRadians)
{
    s.write(zeroAngleRadians * 180/PI + targetAngleRadians * 180/PI);
}

bool TVCServo::isAttached()
{
    return s.attached();
}

Position globalPosition;
Acceleration globalAcceleration;
Orientation globalOrientation;
QuaternionRotation globalQuaternionOrientation;
AngularVelocity globalAngularVelocity;

void ReportError(String error) // Publishes an error by sending it over radio and enabling led
{
    Serial.print(F("!ERROR!: "));
    Serial.println(error);
    // SetLight(true, PIN_LED);
}

RF24 radio(RADIO_PIN_CE, RADIO_PIN_CSN);