#include <Adafruit_SSD1306.h>
#include <WifiManagerParamHelper.h>

#include "app.h"

class Settings : public App {
 public:
  Settings(Adafruit_SSD1306& display, const WifiManagerParamHelper& wm_helper)
      : display_(display),  wm_helper_(wm_helper) {}
  void Up() override {};
  void Down() override {};
  void Left() override {};
  void Right() override {};
  void Increment() override {};
  void Decrement() override {};
  void Display() override;

  const char* GetName() const override {
    return "Settings";
  }

 private:
  static constexpr size_t NUM_SPECIAL_SETTINGS = 1;
  Adafruit_SSD1306& display_;
  const WifiManagerParamHelper& wm_helper_;
};
