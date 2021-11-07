
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

#include <math.h>

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
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <AS1115.h>

#include "secrets.h"
#include "icons.h"

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define YELLOW_HEIGHT 16 // OLED yellow portion height, in pixels
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32

#define AS1115_ISR_PIN 2 ///< Interrupt pin connected to AS1115

constexpr size_t NUM_TOTALS = 10;
uint16_t totals[NUM_TOTALS] = {0};
int selected_total = 0;
int selected_digit = 0;

AS1115 as = AS1115(0x00);

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire);


const char* mqtt_server = "192.168.1.110";

WiFiClient espClient;
PubSubClient client(espClient);
unsigned long lastMsg = 0;
#define MSG_BUFFER_WORDS	(100)
#define MSG_BUFFER_SIZE	(MSG_BUFFER_WORDS * sizeof(uint16_t))
char msg[MSG_BUFFER_SIZE];
int value = 0;


volatile bool interrupted = false;
void IRAM_ATTR interrupt()
{
    interrupted = true;
}

void IncrementCursor(int16_t x, int16_t y)
{
    display.setCursor(x + display.getCursorX(), y + display.getCursorY());
}


constexpr uint16_t ICON_WIDTH = 48;
constexpr uint16_t ICON_HEIGHT = 48;


static const unsigned char* ICONS[] = {
    heart_bmp,
    poison_bmp,
    squirrel_bmp,
    cat_bmp,
    dog_bmp,
    energy_bmp,
    spirit_bmp,
    robot_bmp,
    knight_bmp,
    goblin_bmp
};

void DrawSelectedTotal(void) {
  display.clearDisplay();
  
  display.setTextSize(2);             // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE);        // Draw white text
  display.setCursor(6, 0);             // Start at top-left corner

  for (size_t i = 0; i < NUM_TOTALS; i++) {
      if (i == (size_t)selected_total) {
          display.setTextColor(SSD1306_BLACK, SSD1306_WHITE); // Draw 'inverse' text
      } else {
          display.setTextColor(SSD1306_WHITE);
      }
      display.print(i);
  }
    
  display.drawBitmap(
    (display.width()  - ICON_WIDTH ) / 2,
    YELLOW_HEIGHT,
    ICONS[selected_total], ICON_WIDTH, ICON_HEIGHT, 1);

  display.display();
} 


void setup_wifi() {

  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  randomSeed(micros());

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
    Serial.print("Attempting MQTT connection...1");
    // Create a random client ID
    String clientId = "ESP8266Client-";
    clientId += String(random(0xffff), HEX);
    // Attempt to connect
    if (client.connect(clientId.c_str())) {
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

    DrawSelectedTotal();

    setup_wifi();
    client.setServer(mqtt_server, 1883);
    client.setCallback(callback);
    //client.setSocketTimeout(0xFFFF);
    client.setKeepAlive(0xFFFF);
}

void loop()
{
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
    if (current & 0b1100000)
    {
        int total;
        int change = pow(10, selected_digit);
        if (bitRead(current, 6))
        {
            change *= -1;
        }
        total = totals[selected_total] + change;
        total = min(total, 9999);
        total = max(total, 0);
        totals[selected_total] = total;
    }
    // Up
    else if (bitRead(current, 3))
    {
        selected_digit = min(selected_digit + 1, 3);
    }
    // Down
    else if (bitRead(current, 1))
    {
        selected_digit = max(selected_digit - 1, 0);
    }
    // Right
    else if (bitRead(current, 0))
    {
        selected_total++;
        selected_total %= NUM_TOTALS;
    }
    // Left
    else if (bitRead(current, 4))
    {
        if (selected_total == 0)
        {
            selected_total = NUM_TOTALS - 1;
        }
        else
        {
            selected_total--;
        }
    }

    as.display(totals[selected_total], selected_digit);

    DrawSelectedTotal();
}
