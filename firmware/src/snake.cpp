#include "snake.h"

#include <cstdlib>
#include <deque>

#define SCREEN_WIDTH 128  // OLED display width, in pixels
#define SCREEN_HEIGHT 64  // OLED display height, in pixels
#define YELLOW_HEIGHT 16  // OLED yellow portion height, in pixels

#define PIXEL_SIZE_X 4
#define PIXEL_SIZE_Y 4
#define MAX_X (SCREEN_WIDTH / PIXEL_SIZE_X)
#define MAX_Y (SCREEN_HEIGHT / PIXEL_SIZE_Y)
#define START_POINT Point{5, 5}


#define UPDATE_PERIOD_MS 200

enum class Direction {
  UP,
  DOWN,
  LEFT,
  RIGHT
};

struct Point {
  uint8_t x{0};
  uint8_t y{0};

  bool operator==(const Point& other) const {
    return other.x == x && other.y == y;
  }
};

std::deque<Point> body;
Direction direction = Direction::RIGHT;
unsigned long last_update = 0;
bool dead = false;

Point RandomPoint() {
  uint8_t x = rand() % MAX_X;
  uint8_t y = rand() % MAX_Y;
  return {x, y};
}

Point fruit = RandomPoint();

size_t score = 0;

void DrawPoint(const Point& point, Adafruit_SSD1306& display) {
  uint8_t x = point.x * PIXEL_SIZE_X;
  uint8_t y = point.y * PIXEL_SIZE_Y;
  display.fillRect(x, y, PIXEL_SIZE_X, PIXEL_SIZE_Y, SSD1306_WHITE);
}

void Snake::Up() {
  direction = Direction::UP;
}

void Snake::Down() { 
  direction = Direction::DOWN;
}

void Snake::Left() {
  direction = Direction::LEFT;
}

void Snake::Right() {
  direction = Direction::RIGHT;
}

void Snake::Increment() {
  body = std::deque<Point>();
  direction = Direction::RIGHT;
  score = 0;
  dead = false;
  srand(millis());
}

void Snake::Update() {

  if (dead) {
    return;
  }

  unsigned long time = millis();

  if (body.empty()){
    body.push_front(START_POINT);
  }

  if (time > last_update + UPDATE_PERIOD_MS) {

    Point head = body.front();

    switch (direction)
    {
    case Direction::UP:
      head.y--;
      break;
    case Direction::DOWN:
      head.y++;
      break;
    case Direction::LEFT:
      head.x--;
      break;
    case Direction::RIGHT:
      head.x++;
      break;
    }

    if (head.x > MAX_X || head.y > MAX_Y) {
      dead = true;
      Display();
      return;
    }

    body.push_front(head);

    if (head == fruit)
    {
      fruit = RandomPoint();
      score++;
    } else {
      body.pop_back();
    }

    Display();
    last_update = time;
  }
}


void Snake::Display() {
  seven_seg_.display(score);

  display_.clearDisplay();

  DrawPoint(fruit, display_);

  for (const auto& seg : body) {
    DrawPoint(seg, display_);
  }

  if (dead) {
    display_.setCursor(0, 0);
    display_.setTextColor(SSD1306_WHITE);
    display_.print(F("Dead"));
  }
  
  display_.display();
}
