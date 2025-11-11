#include "header.h"

// Name: DataCollection
// Description: Functions related to the controlling motion (Example: servos for TVC, parachute deployment, etc)
// Devices: BME280 Barometer (used for sensing pressure and calculating height. See the docs on how to do that), BNO085 accelerometer
// Skills: Reading and implementing documentation (lots of resources are available, you just need to implment them!)

// Dibs: Eli C.,Drew F

Adafruit_BMP280 barometer; // use I2C interface
Adafruit_Sensor *barometer_temp = barometer.getTemperatureSensor();
Adafruit_Sensor *barometer_pressure = barometer.getPressureSensor();

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

int setReportsBno08x(){//Enables reports for specific types of data
    if(!bno08x.enableReport(SH2_ROTATION_VECTOR,50000)){//This asks the sensor to give orientation data every 50000 microseconds (This is 50 miliseconds).
        return 0; //Failure
    }
    return 1;//Success only happens if all of the report enabling is successful.
};

int checkImuForData(){
    if(bno08x.wasReset()){//Checks if the IMU was reset. If so, the reports are redone.
        setReportsBno08x();
    }

    if(bno08x.getSensorEvent(&sensorValue)){
        switch (sensorValue.sensorId){
            case SH2_ROTATION_VECTOR://Checks if sensor has rotation orientation data
                //Updates global quaternion orientation with sensor data if it is available.
                globalQuaternionOrientation.w = sensorValue.un.rotationVector.real;
                globalQuaternionOrientation.i = sensorValue.un.rotationVector.i;
                globalQuaternionOrientation.j = sensorValue.un.rotationVector.j;
                globalQuaternionOrientation.k = sensorValue.un.rotationVector.k;
                break;
        }
    }
};

QuaternionRotation GetOrientation(){
    return globalQuaternionOrientation;
};

Acceleration GetAcceleration(){
    return globalAcceleration;
};
    



