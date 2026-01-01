// File: lib/init/init.h
// Description: Initialization function prototypes for subsystems

// EXTERNAL LIBRARIES (Use <>)
#ifndef ARDUINOLIB
#define ARDUINOLIB
#include <Arduino.h>
#endif

#ifndef GLOBALLIB
#define GLOBALLIB
#include "global.h"
#endif

#ifndef RF24LIB
#define RF24LIB
#include <RF24.h>
#endif

#ifndef SENSORSLIB
#define SENSORSLIB
#include "sensors.h"
#endif

#ifndef BNO08XLIB
#define BNO08XLIB
#include <Adafruit_BNO08x.h>
#endif

// Header files are used to ensure that the files can communicate with each other

// I know that initializing each component separately looks like a waste of space, but it will help us catch errors faster -Bora
void InitBoard(); // Begin serial communication, ensure power, whatever.
int InitIMU();   // BNO085
void InitBarometer(); // BME280
void InitRadio(); // NRF24
void TestSystems(); // Blink LED, move TVC mount within range of motion to see if anything blocks it, etc
void InitServo();
void InitLED();
void InitSerialPort();