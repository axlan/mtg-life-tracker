#include <PubSubClient.h>
#include <Adafruit_SSD1306.h>
#include <AS1115.h>

#include "app.h"

class LifeCounter : public App {
 public:
  LifeCounter(AS1115& seven_seg, Adafruit_SSD1306& display,
              PubSubClient& mqtt_client, const char* topic)
      : seven_seg_(seven_seg), display_(display), mqtt_client_(mqtt_client), topic_(topic) {}
  void Up() override;
  void Down() override;
  void Left() override;
  void Right() override;
  void Increment() override;
  void Decrement() override;
  void Display() override;

 private:
  AS1115& seven_seg_;
  Adafruit_SSD1306& display_;
  PubSubClient& mqtt_client_;
  const char* topic_;

  void UpdateValue(bool increment);
  void SendMQTT();
};
