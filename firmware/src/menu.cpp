#include "menu.h"

#define SCREEN_WIDTH 128  // OLED display width, in pixels
#define SCREEN_HEIGHT 64  // OLED display height, in pixels
#define YELLOW_HEIGHT 16  // OLED yellow portion height, in pixels

void Menu::Up() {
  if (selected_ == 0) {
    selected_ = num_apps_-1;
  } else {
    selected_--;
  }
}

void Menu::Down() { 
  selected_ = (selected_ + 1) % num_apps_;
}


void Menu::Increment() { 
  *active_app_ = apps_[selected_];
}

void Menu::Display() {

  display_.clearDisplay();

  display_.setTextSize(1);               // Normal 1:1 pixel scale
  display_.setCursor(0, YELLOW_HEIGHT);

  for (size_t i = 0; i < num_apps_; i++) {
    if (selected_ == i) {
      display_.setTextColor(SSD1306_BLACK,
                            SSD1306_WHITE);  // Draw 'inverse' text
    } else {
      display_.setTextColor(SSD1306_WHITE);
    }
    display_.println(apps_[i]->GetName());
  }
  
  display_.display();
}
