#include "pid.h"

float outputSignalCalc(float integral, float derivative, float error, float kp, float ki, float kd) {
    return (kp * error) + (ki * integral) + (kd * derivative);
}