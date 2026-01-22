#ifndef ARDUINO
#define ARDUINO
#include <Arduino.h>
#endif

#ifndef PID
#define PID

float outputSignalCalc(float integral, float derivative, float error, float kp, float ki, float kd);
void moveServo(Servo servoToMove, float integral, float derivative, float error, float kp, float ki, float kd);
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
    float prevTime;
    float integralVal;
    float derivativeVal;
};
#endif