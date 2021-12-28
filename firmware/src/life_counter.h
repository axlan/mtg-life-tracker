#include <PubSubClient.h>
#include <Adafruit_SSD1306.h>
#include <AS1115.h>
#include <WiFiManager.h>

#include "app.h"

class LifeCounter : public App {
 public:
  LifeCounter(AS1115& seven_seg, Adafruit_SSD1306& display,
              PubSubClient& mqtt_client)
      : seven_seg_(seven_seg), display_(display), mqtt_client_(mqtt_client) {}
  void Up() override;
  void Down() override;
  void Left() override;
  void Right() override;
  void Increment() override;
  void Decrement() override;
  void Display() override;

  const char* GetName() const override {
    return "Life Counter";
  }

  void SetDeviceName(const char* device_name);

 private:
  AS1115& seven_seg_;
  Adafruit_SSD1306& display_;
  PubSubClient& mqtt_client_;
  String topic_;

  void UpdateValue(bool increment);
  void SendMQTT();
};
