// File: lib/communication/communication.h
// Description: Radio and ground communication function prototypes
// EXTERNAL LIBRARIES (Use <>)
#ifndef COMMUNICATIONLIB
#define COMMUNICATIONLIB

#include <Arduino.h>

#ifndef RF24LIB
#define RF24LIB
#include <RF24.h>
#endif

// INTERNAL LIBRARIES (Use "")
#ifndef GLOBALLIB
#define GLOBALLIB
#include "global.h"
#endif


// Header files are used to ensure that the files can communicate with each other

// You can define different functions here. They don't have to have ANY code just yet, just the return type and inputs

void SendSignal(byte data);
void InterpretSignal(int signal);
#endif
