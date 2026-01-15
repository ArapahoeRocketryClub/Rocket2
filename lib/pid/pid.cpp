#include "pid.h"
#include "global.h"
#include "control.h"

#define KDX
#define KIX
#define KPX

#define KDY
#define KIY
#define KPY

namespace pidTemps {
    Orientation prevOrientation;
    // May add previous integral of orientation in the future.
}

float outputSignalCalc(float integral, float derivative, float error, float kp, float ki, float kd) {
    return (kp * error) + (ki * integral) + (kd * derivative);
}

void moveServo(Servo servoToMove, float integral, float derivative, float error, float kp, float ki, float kd){
    float outputSignal = (outputSignalCalc(integral,derivative,error,kp,ki,kd));
    MoveServo(servoToMove,outputSignal);
    return void;
}

float discreteDerivative(float initialVal, float finalVal, float deltaTime){
    return ((finalVal - initialVal) / deltaTime);
}

void updateWithGlobalData(float deltaTime){
    Orientation newOrientation = GetOrientation();
    Orientation derivative;
    derivate.x = derivative(pidTemps::prevOrientation.x,newOrientation.x,deltaTime);
    derivate.y = derivative(pidTemps::prevOrientation.y,newOrientation.y,deltaTime);

    dataTemps::prevOrientation.x = newOrientation.x;
    dataTemps::prevOrientation.y = newOrientation.y;

    MoveServo(ServoX,0,derivative.x,newOrientation.x,KPX,KIX,KDX);
    MoveServo(ServoX,0,derivative.y,newOrientation.y,KPY,KIY,KDY);
}