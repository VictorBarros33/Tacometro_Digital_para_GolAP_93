#ifndef DISPLAY_OLED_H
#define DISPLAY_OLED_H
#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
class DisplayOLED {
3
private:
Adafruit_SSD1306 display;
public:
DisplayOLED();
void begin();
void showRPM(int rpm);
};
#endif
