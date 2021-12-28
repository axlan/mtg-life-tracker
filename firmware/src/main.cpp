
// Directional Pad
// 1 left: SegC 4
// 2 up: SegD 3
// 3 middle: SegE 2
// 4 down: SegF 1
// 5 right: SegG 0

// Buttons
// top: SegB 5
// bottom: SegA 6

// Todo:
// Add Reset
// Add dice rolls
// Be able to display two totals < 100
// Make wifi more efficient
// Test other oled style

#include <Arduino.h>
#include <Wire.h>
#ifdef ESP32
#include <AsyncTCP.h>
#include <WiFi.h>
#elif defined(ESP8266)
#include <ESP8266WiFi.h>
#endif
#include <Wire.h>

#include <AS1115.h>
#include <Adafruit_SSD1306.h>
#include <PubSubClient.h>
#include <WiFiManager.h> // https://github.com/tzapu/WiFiManager
#include <WifiManagerParamHelper.h>

#include "dice_roller.h"
#include "life_counter.h"
#include "menu.h"
#include "snake.h"

#define SCREEN_WIDTH 128    // OLED display width, in pixels
#define SCREEN_HEIGHT 64    // OLED display height, in pixels
#define YELLOW_HEIGHT 16    // OLED yellow portion height, in pixels
#define SCREEN_ADDRESS 0x3C // See datasheet for Address

#define AS1115_ISR_PIN 2 ///< Interrupt pin connected to AS1115

WiFiManager wm;
WifiManagerParamHelper wm_helper(wm);
constexpr size_t CUSTOM_FIELD_LEN = 40;
constexpr std::array<ParamEntry, 2> PARAMS = {{
    {
      "devicenameid",
      "Device Name",
      CUSTOM_FIELD_LEN
    },
    {
      "mqttserverid",
      "MQTTServer",
      CUSTOM_FIELD_LEN
    }
}};

constexpr size_t SETTING_DEVICE_NAME = 0;
constexpr size_t SETTING_MQTT_SERVER = 1;

AS1115 as = AS1115(0x00);

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire);

WiFiClient espClient;
PubSubClient client(espClient);
long long next_reconnect = 0;

LifeCounter life_counter(as, display, client);
DiceRoller dice_roller(as, display);
Snake snake(as, display);

App *active_app = &life_counter;

App *apps[] = {&life_counter, &dice_roller, &snake};

Menu menu(display, apps, sizeof(apps) / sizeof(App *), &active_app);

volatile bool interrupted = false;
void IRAM_ATTR interrupt() { interrupted = true; }

void setup_wifi() {

  WiFi.mode(WIFI_STA);

  wm_helper.Init(0xBEEF, PARAMS.data(), PARAMS.size());
  life_counter.SetDeviceName(wm_helper.GetSetting(SETTING_DEVICE_NAME));

  // automatically connect using saved credentials if they exist
  // If connection fails it starts an access point with the specified name
  if (wm.autoConnect("LifeTrackerAP")) {
    Serial.println("connected...yeey :)");
    // Start the web portal even on successfully connections.
    wm.startWebPortal();
  } else {
    Serial.println("Configportal running");
  }
}

void callback(char *topic, byte *payload, unsigned int length) {}

bool reconnect() {
  const char* device_name = wm_helper.GetSetting(SETTING_DEVICE_NAME);
  const char* mqtt_server = wm_helper.GetSetting(SETTING_MQTT_SERVER);
  if (next_reconnect > millis() || !WiFi.isConnected() ||
      strlen(device_name) == 0 ||
      strlen(mqtt_server) == 0) {
    return false;
  }

  client.setServer(mqtt_server, 1883);
  Serial.print("Attempting MQTT connection...");
  // Attempt to connect
  if (client.connect(device_name)) {
    Serial.println("connected");
    return true;
  } else {
    Serial.print("failed, rc=");
    Serial.print(client.state());
    Serial.println(" try again in 5 seconds");
    // Wait 5 seconds before retrying
    next_reconnect = millis() + 5000;
  }
  
  return false;
}

void setup() {
  pinMode(AS1115_ISR_PIN, INPUT);
  attachInterrupt(digitalPinToInterrupt(AS1115_ISR_PIN), interrupt, FALLING);

  Wire.begin();
  as.init(4, 6);
  as.clear();
  as.read(); // reset any pending interrupt on the chip side

  as.display(0, 0);

  Serial.begin(9600);

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ; // Don't proceed, loop forever
  }

  setup_wifi();
  client.setCallback(callback);
  // client.setSocketTimeout(0xFFFF);
  client.setKeepAlive(0xFFFF);

  active_app->Display();
}

void loop() {
  if (!client.connected()) {
    if (reconnect()) {
      active_app->Display();
    }
  }
  client.loop();

  wm.process();

  active_app->Update();

  if (!interrupted) {
    delay(100);
    return;
  }

  interrupted = false;

  // active input are LOW, it's easier to invert the result
  uint16_t current = ~as.read();
  if (current == 0)
    return;

  Serial.println(String("Got press: ") + current);

  // Middle
  if (bitRead(current, 2)) {
    active_app = &menu;
  }
  // (In/De)crement
  else if (bitRead(current, 5)) {
    active_app->Increment();
  } else if (bitRead(current, 6)) {
    active_app->Decrement();
  }
  // Up
  else if (bitRead(current, 3)) {
    active_app->Up();
  }
  // Down
  else if (bitRead(current, 1)) {
    active_app->Down();
  }
  // Right
  else if (bitRead(current, 0)) {
    active_app->Right();
  }
  // Left
  else if (bitRead(current, 4)) {
    active_app->Left();
  }

  active_app->Display();
}