#include <Adafruit_SSD1306.h>
#include <WifiManagerParamHelper.h>

#include "app.h"

class Settings : public App {
 public:
  Settings(Adafruit_SSD1306& display, const WifiManagerParamHelper& wm_helper)
      : display_(display),  wm_helper_(wm_helper) {}
  void Up() override;
  void Down() override;
  void Left() override {};
  void Right() override {};
  void Increment() override {Up();};
  void Decrement() override {Down();};
  void Display() override;

  const char* GetName() const override {
    return "Settings";
  }

 private:
  static constexpr size_t NUM_SPECIAL_SETTINGS = 2;
  Adafruit_SSD1306& display_;
  const WifiManagerParamHelper& wm_helper_;
  size_t scroll_ = 0;
};
