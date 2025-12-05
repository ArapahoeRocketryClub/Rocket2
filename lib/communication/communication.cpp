#include "communication.h"
// Name: Communication
// Description: Communicate with ground control device, receive and send data
// Devices: NRF24L01 Antenna Module
// Skills: Radio communication, basic variable manipulation, reading documentation

// Dibs: Bora A., Eli C.
void InterpretSignal(int signal)
{
    switch(signal)
    {
        case 0: // ACKNOWLEDGE ERROR
            //LED.set(off);
            //errors.clear();
            break;
        case -1: // Houston, we have a problem
            //LED.set(on);
            //error.add(errortype);
            // Engine.turnoff
            // Parachute.deploy
            // ExplosiveChargePayload.detonate();
            // Avengers.call();
            // CheckServoWireIntegrity();
            break;
    }
}