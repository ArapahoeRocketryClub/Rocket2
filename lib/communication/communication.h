// Header files are used to ensure that the files can communicate with each other
#pragma once  // Makes sure this file is included only once during compilation to avoid duplicates
#include <Arduino.h>

// You can define different functions here. They don't have to have ANY code just yet, just the return type and inputs

void SendSignal(byte data);
byte ReceiveSignal();