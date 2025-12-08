#include "RPMReader.h"
RPMReader::RPMReader(byte pin) {
interruptPin = pin;
pulseCount = 0;
}
void RPMReader::begin() {
pinMode(interruptPin, INPUT);
}
void RPMReader::handlePulse() {
pulseCount++;
}
unsigned int RPMReader::getPulses() {
return pulseCount;
}
void RPMReader::reset() {
2
pulseCount = 0;
}
