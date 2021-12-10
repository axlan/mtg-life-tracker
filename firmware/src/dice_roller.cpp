#include "dice_roller.h"

#include <stdlib.h>

#define SCREEN_WIDTH 128  // OLED display width, in pixels
#define SCREEN_HEIGHT 64  // OLED display height, in pixels
#define YELLOW_HEIGHT 16  // OLED yellow portion height, in pixels

constexpr int DICE_SIZES[] = {
  4,
  6,
  8,
  12,
  20,
  100
};
constexpr size_t NUM_DICE_SIZES = sizeof(DICE_SIZES) / sizeof(DICE_SIZES[0]);

constexpr size_t NUM = 0;
constexpr size_t DIE = 1;
constexpr size_t CONST = 2;
constexpr size_t NUM_PORTIONS = 3;

size_t selected_portion = DIE;
int num_die = 1;
int die_index = 4;
int constant = 0;

int roll_value = 0;

void DiceRoller::Up() {
  switch(selected_portion) {
    case NUM:
      num_die++;
      break;
    case DIE:
      die_index++;
      die_index %= NUM_DICE_SIZES;
      break;
    case CONST:
      constant++;
      break;
  }
}

void DiceRoller::Down() { 
  switch(selected_portion) {
    case NUM:
      if (num_die > 1) {
        num_die--;
      }
      break;
    case DIE:
      if (die_index > 0) {
        die_index--;
      } else {
        die_index = NUM_DICE_SIZES - 1;
      }
      break;
    case CONST:
      constant--;
      break;
  }
}

void DiceRoller::Left() {
  if (selected_portion > 0) {
    selected_portion--;
  } else {
    selected_portion = NUM_PORTIONS - 1;
  }
}

void DiceRoller::Right() {
  selected_portion++;
  selected_portion %= NUM_PORTIONS;
}

void DiceRoller::roll() {
  roll_value = constant;
  for (int i = 0; i < num_die; i++) {
    roll_value += (rand() % DICE_SIZES[die_index]) + 1;
  }
}

void DiceRoller::Increment() { roll(); }

void DiceRoller::Display() {
  seven_seg_.display(roll_value);

  display_.clearDisplay();

  display_.setTextSize(2);               // Normal 1:1 pixel scale
  display_.setTextColor(SSD1306_WHITE);  // Draw white text
  display_.setCursor(0, SCREEN_HEIGHT/2);           

  if (selected_portion == NUM) {
    display_.setTextColor(SSD1306_BLACK,
                          SSD1306_WHITE);  // Draw 'inverse' text
  } else {
    display_.setTextColor(SSD1306_WHITE);
  }
  display_.print(num_die);

  if (selected_portion == DIE) {
    display_.setTextColor(SSD1306_BLACK,
                          SSD1306_WHITE);  // Draw 'inverse' text
  } else {
    display_.setTextColor(SSD1306_WHITE);
  }
  display_.print("d");
  display_.print(DICE_SIZES[die_index]);
  
  if (selected_portion == CONST) {
    display_.setTextColor(SSD1306_BLACK,
                          SSD1306_WHITE);  // Draw 'inverse' text
  } else {
    display_.setTextColor(SSD1306_WHITE);
  }
  if (constant >= 0) {
    display_.print("+");
  }
  display_.print(constant);
  
  display_.display();
}
