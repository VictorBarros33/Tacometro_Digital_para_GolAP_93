#include "DisplayOLED.h"
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
DisplayOLED::DisplayOLED()
: display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET) {}
void DisplayOLED::begin() {
if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
Serial.println("Erro ao iniciar OLED!");
while (true);
}
display.clearDisplay();
display.setTextColor(SSD1306_WHITE);
display.setTextSize(1);
display.setCursor(0, 0);
display.println("Tacometro AP - OLED OK");
display.display();
delay(800);
}
void DisplayOLED::showRPM(int rpm) {
display.clearDisplay();
display.setTextSize(1);
display.setCursor(0, 0);
display.println("RPM Atual:");
display.setTextSize(3);
display.setCursor(10, 25);
4
display.println(rpm);
display.display();
}
