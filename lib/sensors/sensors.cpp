// Name: DataCollection
// Description: Functions related to the controlling motion (Example: servos for TVC, parachute deployment, etc)
// Devices: BME280 Barometer (used for sensing pressure and calculating height. See the docs on how to do that), BNO085 accelerometer
// Skills: Reading and implementing documentation (lots of resources are available, you just need to implment them!)
#include "sensors.h"
#include "global.cpp"
#include <Adafruit_BMP280.h>
#include <Adafruit_BNO08x.h>
// Dibs: Eli C.,Drew F

Adafruit_BMP280 barometer; // use I2C interface
Adafruit_Sensor *barometer_temp = barometer.getTemperatureSensor();
Adafruit_Sensor *barometer_pressure = barometer.getPressureSensor();



// Example:

// Acceleration GetAcceleration() {
//     Acceleration a;
//     a.x = accelerometer.getX;
//     a.y = accelerometer.getY;
//     a.z = accelerometer.getZ;
//     return a;
// };