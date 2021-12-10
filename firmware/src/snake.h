#include <Adafruit_SSD1306.h>
#include <AS1115.h>

#include "app.h"

class Snake : public App {
 public:
  Snake(AS1115& seven_seg, Adafruit_SSD1306& display)
      : seven_seg_(seven_seg), display_(display) {}
  void Up() override;
  void Down() override;
  void Left() override;
  void Right() override;
  void Increment() override;
  void Decrement() override {Increment();}
  void Display() override;
  void Update() override;

  const char* GetName() const override {
    return "Snake";
  }

 private:
  AS1115& seven_seg_;
  Adafruit_SSD1306& display_;

};
