// Name: Init (Initialization)
// Description: Functions related to initializing systems
// Devices: Servos, BMP180 barometers, MPU6050 acceloremeter
// Skills: Ability to implement documentation, safe coding habits (failure-tolerant code)
#include <Arduino.h>
#include <RF24.h>
// Dibs: Jordan.T, Bora

uint8_t address[][6] = { "1Node", "2Node" };
RF24 radio(RADIO_PIN_CE, RADIO_PIN_CSN);
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


ServoX.attach(PIN_SERVO_X);
ServoY.attach(PIN_SERVO_Y);
