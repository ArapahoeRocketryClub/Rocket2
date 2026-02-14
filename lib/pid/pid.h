#include <Arduino.h>
#include <Servo.h>

#ifndef PID_H
#define PID_H

float outputSignalCalc(float integral, float derivative, float error, float kp, float ki, float kd);
//void moveServo(Servo servoToMove, float integral, float derivative, float error, float kp, float ki, float kd);
float discreteDerivative(float initialVal, float finalVal, float deltaTime);
void updateWithNewData();

class pid
{
public:
    float compute(float input, float target);
    pid(float KP, float KI, float KD);

private:
    float kP;
    float kI;
    float kD;
    float error;
    unsigned long now;
    float prevError;
    unsigned long prevTime;
    float integralVal;
    float derivativeVal;
};
#endif