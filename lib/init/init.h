// File: lib/init/init.h
// Description: Initialization function prototypes for subsystems

#ifndef INITLIB
#define INITLIB

// EXTERNAL LIBRARIES (Use <>)
#include <Arduino.h>
#include <RF24.h>
#include <Adafruit_BNO08x.h>
#include <Wire.h>

// INTERNAL LIBRARIES (Use "")
#include "global.h"
#include "sensors.h"

// Header files are used to ensure that the files can communicate with each other

// I know that initializing each component separately looks like a waste of space, but it will help us catch errors faster -Bora
void InitBoard(); // Begin serial communication, ensure power, whatever.
int InitIMU();   // BNO085
void InitBarometer(); // BMP280
void InitRadio(); // NRF24
void TestSystems(); // Blink LED, move TVC mount within range of motion to see if anything blocks it, etc
void InitServo();
void InitLED();
void InitSerialPort();
#endif
