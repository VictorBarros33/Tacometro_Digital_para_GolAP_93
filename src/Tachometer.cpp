#include "Tachometer.h"
Tachometer::Tachometer(int pulsesPerRev)
: pulsesPerRevolution(pulsesPerRev) {}
int Tachometer::calculateRPM(unsigned int pulses) {
return (pulses / pulsesPerRevolution) * 60;
}
