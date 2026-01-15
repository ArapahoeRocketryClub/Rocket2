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

#endif