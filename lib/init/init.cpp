// File: lib/init/init.cpp
// Description: Initialization routines for hardware and subsystems
//
#include "init.h"


// Name: Init (Initialization)
// Description: Functions related to initializing systems
// Devices: Servos, BMP280 barometers, BNO085 IMU
// Skills: Failure-tolerant init, hardware bring-up

// Dibs: Jordan.T, Bora

void InitLED()
{
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
    if (!ServoX.attached() || !ServoY.attached())
    {
        ReportError("Servo failed to attach!");
        while (1)
            ;
    }
}

int InitIMU()
{
    if (!bno08x.begin_I2C())
    {
        ReportError("BNO085 IMU failed to Start!");
        while (1)
        {
            delay(1000);
        }
        return 0; // If the sensor doesn't connect then the function returns 0 and quits
    }
    if(!setReportsBno08x()) {
        ReportError("Failed to set BNO08x reports!");
        while(1) {
            delay(1000);
        }
    }
    Serial.println("BNO GOOD!!!");
    return 1; // Returns one if sensor connects
};

void InitSerialPort()
{
    Serial.begin(115200);
    while (!Serial) {
        delayMicroseconds(1000); // Waits for the serial to begin. Checks every 1000 microseconds until it connects.
    }
    Wire.begin(PIN_I2C_SDA, PIN_I2C_SCL);
    Wire.setClock(400000);
    delay(1000);
};

void InitBarometer()
{
    if (!barometer.begin(0x76))
    {
        Wire.setClock(100000);

        if (!barometer.begin(0x76))
        {
            ReportError("BME fail");
            while (1)
            {
                delay(1000);
            }
        }
        Serial.println("BME Success!");
    }
    ResetBarometer();
}