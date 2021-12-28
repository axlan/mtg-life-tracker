#include "settings.h"

#include <stdlib.h>

#define SCREEN_WIDTH 128  // OLED display width, in pixels
#define SCREEN_HEIGHT 64  // OLED display height, in pixels
#define YELLOW_HEIGHT 16  // OLED yellow portion height, in pixels

void Settings::Display() {
  display_.clearDisplay();

  display_.setTextSize(1);               // Normal 1:1 pixel scale
  display_.setTextColor(SSD1306_WHITE);  // Draw white text
  display_.setCursor(0, 0);           

  display_.println(String("IP: ") + WiFi.localIP().toString());

  for (size_t i = 0; i < wm_helper_.GetNumSettings(); i++) {
    auto& setting = wm_helper_.GetSettingParam(i);
    display_.print(setting.getLabel());
    display_.print(F(": "));
    display_.println(setting.getValue());
  }
  
  display_.display();
}
