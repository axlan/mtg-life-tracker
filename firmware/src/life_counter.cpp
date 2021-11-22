#include "life_counter.h"

#include "icons.h"

constexpr size_t NUM_TOTALS = 10;
uint16_t totals[NUM_TOTALS] = {0};
int selected_total = 0;
int selected_digit = 0;

#define SCREEN_WIDTH 128  // OLED display width, in pixels
#define SCREEN_HEIGHT 64  // OLED display height, in pixels
#define YELLOW_HEIGHT 16  // OLED yellow portion height, in pixels

constexpr uint16_t ICON_WIDTH = 48;
constexpr uint16_t ICON_HEIGHT = 48;

static const unsigned char* ICONS[] = {
    heart_bmp,  poison_bmp, squirrel_bmp, cat_bmp, dog_bmp,
    energy_bmp, spirit_bmp, robot_bmp, knight_bmp, goblin_bmp};

void LifeCounter::Up() { selected_digit = min(selected_digit + 1, 3); }

void LifeCounter::Down() { selected_digit = max(selected_digit - 1, 0); }

void LifeCounter::Left() {
  if (selected_total == 0) {
    selected_total = NUM_TOTALS - 1;
  } else {
    selected_total--;
  }
}

void LifeCounter::Right() {
  selected_total++;
  selected_total %= NUM_TOTALS;
}

void LifeCounter::Increment() { UpdateValue(true); }

void LifeCounter::Decrement() { UpdateValue(false); }

void LifeCounter::Display() {
  seven_seg_.display(totals[selected_total], selected_digit);

  display_.clearDisplay();

  display_.setTextSize(2);               // Normal 1:1 pixel scale
  display_.setTextColor(SSD1306_WHITE);  // Draw white text
  display_.setCursor(6, 0);              // Start at top-left corner

  for (size_t i = 0; i < NUM_TOTALS; i++) {
    if (i == (size_t)selected_total) {
      display_.setTextColor(SSD1306_BLACK,
                            SSD1306_WHITE);  // Draw 'inverse' text
    } else {
      display_.setTextColor(SSD1306_WHITE);
    }
    display_.print(i);
  }

  display_.drawBitmap((display_.width() - ICON_WIDTH) / 2, YELLOW_HEIGHT,
                      ICONS[selected_total], ICON_WIDTH, ICON_HEIGHT, 1);

  display_.display();

  SendMQTT();
}

void LifeCounter::SendMQTT() {
  String msg = "[";
  for (size_t i = 0; i < NUM_TOTALS; i++) {
    msg += String(totals[i]);
    if (i != NUM_TOTALS - 1) {
      msg += ",";
    }
  }
  msg += "]";
  if (!mqtt_client_.publish(topic_, msg.c_str(), true)) {
    Serial.println("Json pub failed.");
  }
}

void LifeCounter::UpdateValue(bool increment) {
  int total;
  int change = pow(10, selected_digit);
  if (!increment) {
    change *= -1;
  }
  total = totals[selected_total] + change;
  total = min(total, 9999);
  total = max(total, 0);
  totals[selected_total] = total;
}
