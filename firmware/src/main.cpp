
// Directional Pad
// 1 left: SegC 4
// 2 up: SegD 3
// 3 middle: SegE 2
// 4 down: SegF 1
// 5 right: SegG 0

// Buttons
// top: SegB 5
// bottom: SegA 6

//Todo:
// Add Reset
// Add dice rolls
// Be able to display two totals < 100
// Make wifi more efficient
// Test other oled style

#include <Wire.h>
#include <Arduino.h>
#ifdef ESP32
#include <WiFi.h>
#include <AsyncTCP.h>
#elif defined(ESP8266)
#include <ESP8266WiFi.h>
#endif
#include <ArduinoOTA.h>
#include <Wire.h>

#include <PubSubClient.h>
#include <Adafruit_SSD1306.h>
#include <AS1115.h>

#include "life_counter.h"
#include "secrets.h"

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define YELLOW_HEIGHT 16 // OLED yellow portion height, in pixels
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32

#define AS1115_ISR_PIN 2 ///< Interrupt pin connected to AS1115

// Set uniquely for each device
#define CLIENT_ID "unit0"
#define TOPIC_PACKED "life_counters/" CLIENT_ID "/totals_packed"
#define TOPIC_JSON "life_counters/" CLIENT_ID "/totals_json"

AS1115 as = AS1115(0x00);

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire);

const char* mqtt_server = "192.168.1.110";

WiFiClient espClient;
PubSubClient client(espClient);

LifeCounter life_counter(as, display, client, TOPIC_JSON);

enum class Mode {
    LIFE_COUNT,
    DICE_ROLL
};
Mode mode = Mode::LIFE_COUNT;

App* active_app = &life_counter;

volatile bool interrupted = false;
void IRAM_ATTR interrupt()
{
    interrupted = true;
}

void setup_wifi() {

  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(SECRET_SSID);

  WiFi.mode(WIFI_STA);
  WiFi.begin(SECRET_SSID, SECRET_PASSWORD);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void callback(char* topic, byte* payload, unsigned int length) {

}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect(CLIENT_ID)) {
      Serial.println("connected");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void setup()
{
    pinMode(AS1115_ISR_PIN, INPUT);
    attachInterrupt(digitalPinToInterrupt(AS1115_ISR_PIN), interrupt, FALLING);

    Wire.begin();
    as.init(4, 6);
    as.clear();
    as.read(); // reset any pending interrupt on the chip side

    as.display(0, 0);

    Serial.begin(9600);

    // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
    if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
        Serial.println(F("SSD1306 allocation failed"));
        for(;;); // Don't proceed, loop forever
    }

    setup_wifi();
    client.setServer(mqtt_server, 1883);
    client.setCallback(callback);
    //client.setSocketTimeout(0xFFFF);
    client.setKeepAlive(0xFFFF);

    ArduinoOTA.begin();

    life_counter.Display();
}

void loop()
{
    if (!client.connected()) {
        reconnect();
    }
    client.loop();

    ArduinoOTA.handle();

    if (!interrupted)
    {
        delay(100);
        return;
    }

    interrupted = false;

    // active input are LOW, it's easier to invert the result
    uint16_t current = ~as.read();
    if (current == 0)
        return;

    Serial.println(String("Got press: ") + current);

    // (In/De)crement
    if (bitRead(current, 5))
    {
        active_app->Increment();
    }
    else if (bitRead(current, 6))
    {
        active_app->Decrement();
    }
    // Up
    else if (bitRead(current, 3))
    {
        active_app->Up();
    }
    // Down
    else if (bitRead(current, 1))
    {
        active_app->Down();
    }
    // Right
    else if (bitRead(current, 0))
    {
        active_app->Right();
    }
    // Left
    else if (bitRead(current, 4))
    {
        active_app->Left();
    }

    active_app->Display();
}