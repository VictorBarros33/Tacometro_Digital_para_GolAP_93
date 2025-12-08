#ifndef TACHOMETER_H
#define TACHOMETER_H
class Tachometer {
private:
const int pulsesPerRevolution;
public:
Tachometer(int pulsesPerRev = 2);
int calculateRPM(unsigned int pulses);
};
#endif
