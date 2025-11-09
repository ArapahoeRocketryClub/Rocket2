// Name: DataCollection
// Description: Functions related to the controlling motion (Example: servos for TVC, parachute deployment, etc)
// Devices: BME280 Barometer (used for sensing pressure and calculating height. See the docs on how to do that), BNO085 accelerometer
// Skills: Reading and implementing documentation (lots of resources are available, you just need to implment them!)
#include "sensors.h"
#include "global.cpp"
#include <Adafruit_BMP280.h>
#include <Adafruit_BNO08x.h>
#include <Wire.h>


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

int setReportsBno08x(){
    if(!bno08x.enableReport(SH2_ROTATION_VECTOR,50000)){
        return 0; //Failure
    }
    return 1;//Success only happens if all of the report enabling is successful.
};

int initializeBno08x(){
    Serial.begin(115200);
    
    while(!Serial) delayMicroseconds(1000);//Waits for the serial to begin. Checks every 1000 microseconds until it connects.
    
    Wire.begin();//Begins I2C protocol with the sensor.

    if(!bno08x.begin_I2C()){
        return 0;//If the sensor doesn't connect then the function returns 0 and quits
    }

    setReportsBno08x(); //Tells the sensor what data to output.
    return 1; //Returns one if sensor connects
};

/*QuaternionRotation GetOrientation(){
    if(bno08x.wasReset()){//checks if the sensor was reset
        setReportsBno08x();
    }
    
    if(bno08x.getSensorEvent(&sensorValue)){//Checks if the sensor value has a value
        if (sensorValue.sensorId == SH2_ROTATION_VECTOR){//Checks if the value is the same value that is needed.
            
            //If the value is of the right type then it is stored in a temporary variable and returned.
            QuaternionRotation temp;
            temp.w = sensorValue.un.rotationVector.real;
            temp.i = sensorValue.un.rotationVector.i;
            temp.j = sensorValue.un.rotationVector.j;
            temp.k = sensorValue.un.rotationVector.k;
        }
    }

    
};*/




