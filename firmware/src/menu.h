#include <array>

#include <Adafruit_SSD1306.h>

#include "app.h"

class Menu : public App {
 public:
  Menu(Adafruit_SSD1306& display, App** const apps, size_t num_apps, App** active_app)
      : display_(display), apps_(apps), num_apps_(num_apps), active_app_(active_app) {}
  void Up() override;
  void Down() override;
  void Left() override {}
  void Right() override {}
  void Increment() override;
  void Decrement() override {Increment();}
  void Display() override;

  const char* GetName() const override {
    return "Menu";
  }

 private:
  Adafruit_SSD1306& display_;
  App** const apps_;
  const size_t num_apps_;
  App** active_app_;
  size_t selected_ = 0;
};
