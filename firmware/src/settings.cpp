#include "settings.h"

#include <stdlib.h>

#include "icons.h"

#define ARROW_WIDTH 8
#define ARROW_HEIGHT 4

void Settings::Up() { scroll_ = (scroll_ > 0) ? scroll_ - 1 : scroll_; }

void Settings::Down() {
  scroll_ = (scroll_ < wm_helper_.GetNumSettings() + NUM_SPECIAL_SETTINGS - 1)
                ? scroll_ + 1
                : scroll_;
}

void Settings::Display() {
  display_.clearDisplay();

  display_.setTextSize(1);              // Normal 1:1 pixel scale
  display_.setTextColor(SSD1306_WHITE); // Draw white text
  display_.setCursor(0, 0);

  if (scroll_ < 1) {
    display_.println(
        F("To configure WiFi, connect a phone to the SSID \"LifeTrackerAP\". "
          "Otherwise, point your browser at this IP."));
  }
  if (scroll_ < 2) {
    display_.println(String("IP: ") + WiFi.localIP().toString());
  }

  size_t i =
      (scroll_ > NUM_SPECIAL_SETTINGS) ? scroll_ - NUM_SPECIAL_SETTINGS : 0;
  for (; i < wm_helper_.GetNumSettings(); i++) {
    auto &setting = wm_helper_.GetSettingParam(i);
    display_.print(setting.getLabel());
    display_.print(F(": "));
    display_.println(setting.getValue());
  }

  display_.fillRect(display_.width() - ARROW_WIDTH,
                    display_.height() - ARROW_HEIGHT * 2 - 2, ARROW_WIDTH,
                    ARROW_HEIGHT * 2 + 2, 0);

  if (scroll_ > 0) {
    display_.drawBitmap(display_.width() - ARROW_WIDTH,
                        display_.height() - ARROW_HEIGHT * 2 - 1, up_arrow,
                        ARROW_WIDTH, ARROW_HEIGHT, 1);
  }
  if (scroll_ < wm_helper_.GetNumSettings() + NUM_SPECIAL_SETTINGS - 1) {
    display_.drawBitmap(display_.width() - ARROW_WIDTH,
                        display_.height() - ARROW_HEIGHT, down_arrow,
                        ARROW_WIDTH, ARROW_HEIGHT, 1);
  }

  display_.display();
}
