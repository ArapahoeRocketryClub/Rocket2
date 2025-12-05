#pragma once  // Makes sure this file is included only once during compilation to avoid duplicates
#include "header.h"

// Header files are used to ensure that the files can communicate with each other

// You can define different functions here. They don't have to have ANY code just yet, just the return type and inputs

void SendSignal(byte data);
void InterpretSignal(int signal);