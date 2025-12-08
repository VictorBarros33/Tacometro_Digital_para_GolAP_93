#ifndef RPM_READER_H
#define RPM_READER_H

#include <Arduino.h>

class RPMReader {
private:
	volatile unsigned int pulseCount;
	byte interruptPin;
public:
	RPMReader(byte pin);
	void begin();
	void handlePulse();
	unsigned int getPulses();
	void reset();
};
#endif
