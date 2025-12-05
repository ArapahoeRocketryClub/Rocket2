#include "header.h"

#include "init.h"
#include "sensors.h"
// Name: Init (Initialization)
// Description: Functions related to initializing systems
// Devices: Servos, BME280 barometers, MPU6050 acceloremeter
// Skills: Ability to implement documentation, safe coding habits (failure-tolerant code)

// Dibs: Jordan.T, Bora

void InitLED(){
    pinMode(PIN_LED, OUTPUT);
}

void InitRadio()
{
    if (!radio.begin())
    {
        Serial.println(F("Error: Radio hardware failure!"));
    }
    radio.setPALevel(RF24_PA_LOW); // FIXME: Experiment with different power levels. External power might be necessary
    // radio.setPayloadSize(sizeof(Payload));
    radio.openReadingPipe(1, address[0]);
    radio.startListening();
    delay(1000); // Allow for radio to stabilize
}

void InitServo()
{
    ServoX.attach(PIN_SERVO_X);
    ServoY.attach(PIN_SERVO_Y);
}

int InitIMU() {
    if(!bno08x.begin_I2C()){
        ReportError("BNO085 IMU failed to Start!");
        return 0;//If the sensor doesn't connect then the function returns 0 and quits
    }

    setReportsBno08x(); //Tells the sensor what data to output.
    return 1; //Returns one if sensor connects
};

void InitSerialPort(){
    Serial.begin(115200);
    while(!Serial) delayMicroseconds(1000);//Waits for the serial to begin. Checks every 1000 microseconds until it connects.
    Wire.begin();//Begins I2C protocol with the sensor.
};




