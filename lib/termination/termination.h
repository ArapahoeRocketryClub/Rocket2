// File: lib/termination/termination.h
// Description: Termination and safe-shutdown function prototypes

// EXTERNAL LIBRARIES (Use <>)
#ifndef TERMINATIONLIB
#define TERMINATIONLIB
#endif

#ifndef ARDUINOLIB
#define ARDUINOLIB
#include <Arduino.h>
#endif

// INTERNAL LIBRARIES (Use "")
#ifndef GLOBALLIB
#define GLOBALLIB
#include "global.h"
#endif

#ifndef KALMANFILTERLIB
#define KALMANFILTERLIB
#include "kalmanfilter.h"
#endif

// Header files are used to ensure that the files can communicate with each other