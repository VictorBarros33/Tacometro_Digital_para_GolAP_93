#include <Arduino.h>
#include "RPMReader.h"
#include "Tachometer.h"
#include "DisplayOLED.h"
#define INTERRUPT_PIN 2
RPMReader rpmReader(INTERRUPT_PIN);
Tachometer tachometer(2);
DisplayOLED oled;
unsigned long lastCalc = 0;
void IRAM_ATTR pulseInterrupt() {
rpmReader.handlePulse();
}
void setup() {
Serial.begin(9600);
rpmReader.begin();
oled.begin();
attachInterrupt(digitalPinToInterrupt(INTERRUPT_PIN), pulseInterrupt,
RISING);
}
void loop() {
unsigned long now = millis();
if (now - lastCalc >= 1000) {
unsigned int pulses = rpmReader.getPulses();
rpmReader.reset();
int rpm = tachometer.calculateRPM(pulses);
Serial.print("RPM: ");
Serial.println(rpm);
oled.showRPM(rpm);
5
lastCalc = now;
}
}
