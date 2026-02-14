#include "sensors.h"

// Name: DataCollection
// Description: Functions related to the controlling motion (Example: servos for TVC, parachute deployment, etc)
// Devices: BMP280 Barometer (used for sensing pressure and calculating height. See the docs on how to do that), BNO085 accelerometer
// Skills: Reading and implementing documentation (lots of resources are available, you just need to implment them!)

// Dibs: Eli C.,Drew F

Adafruit_BMP280 barometer; // use I2C interface
Adafruit_BNO08x bno08x;

// Example:

// Acceleration GetAcceleration() {
//     Acceleration a;
//     a.x = accelerometer.getX;
//     a.y = accelerometer.getY;
//     a.z = accelerometer.getZ;
//     return a;
// };

sh2_SensorValue_t sensorValue;

bool setReportsBno08x() {
    bool status = true;
    status &= bno08x.enableReport(SH2_ROTATION_VECTOR, 20000);
    status &= bno08x.enableReport(SH2_ACCELEROMETER,   20000);
    return status;
}
double GetServoRotation(Servo &servo)
{
    return servo.read();
}

int checkImuForData()
{
    if (bno08x.wasReset())
    { // Checks if the IMU was reset. If so, the reports are redone.
        setReportsBno08x();
    }

    if (!bno08x.getSensorEvent(&sensorValue))
    {
        return 0;
    }

    if (sensorValue.sensorId == SH2_ROTATION_VECTOR)
    {
        // Updates global quaternion orientation with sensor data if it is available.
        globalQuaternionOrientation.w = sensorValue.un.rotationVector.real;
        globalQuaternionOrientation.i = sensorValue.un.rotationVector.i;
        globalQuaternionOrientation.j = sensorValue.un.rotationVector.j;
        globalQuaternionOrientation.k = sensorValue.un.rotationVector.k;
        return 1;
    }

    if (sensorValue.sensorId == SH2_ACCELEROMETER)
    {
        // Updates global acceleration data with sensor data if it's available.
        globalAcceleration.x = sensorValue.un.accelerometer.x;
        globalAcceleration.y = sensorValue.un.accelerometer.y;
        globalAcceleration.z = sensorValue.un.accelerometer.z;
        return 1;
    }

    return 0;
}
QuaternionRotation GetOrientation()
{
    return globalQuaternionOrientation;
}

Acceleration GetAcceleration()
{
    return globalAcceleration;
}

float GetAltitude(int type)
{
    if (type == AGL) // Above ground level (calibrated to 0m at launch)
    {
        return (barometer.readAltitude(reference_pressure));
    }
    else if (type == MSL) // Mean sea level (so Denver would be at around 1600m)
    {
        return (barometer.readAltitude(1013.25));
    }
    return 0;
}

void ResetBarometer()
{
    reference_pressure = barometer.readPressure() / 100.0; // Conversion from Pa to hPa
}

Orientation GetDecoupledOrientation()
{
    Orientation tempOrientation = globalOrientation;
    return tempOrientation;
}