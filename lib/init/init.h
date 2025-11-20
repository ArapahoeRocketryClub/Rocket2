#include "header.h"
// Header files are used to ensure that the files can communicate with each other
#pragma once  // Makes sure this file is included only once during compilation to avoid duplicates

// I know that initializing each component separately looks like a waste of space, but it will help us catch errors faster -Bora
void InitBoard(); // Begin serial communcation, ensure power, whatever.
int InitIMU(); // BNO085
void InitBarometer(); // BMP180
void InitRadio(); // NRF24
void TestSystems(); // Blink LED, move TVC mount within range of motion to see if anything blocks it, etc
void InitServo();
void InitLED();
void InitSerialPort();