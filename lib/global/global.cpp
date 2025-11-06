#include <global.h>
#include <Servo.h>

extern Servo ServoX;
extern Servo ServoY;
ServoX.attach(PIN_SERVO_X);
ServoY.attach(PIN_SERVO_Y);
Position globalPosition;
Acceleration globalAcceleration;
Orientation globalOrientation;
AngularVelocity globalAngularVelocity;