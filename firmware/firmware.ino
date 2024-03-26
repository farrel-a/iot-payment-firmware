// IoT Payment Firmware 
// 13520110 - Farrel Ahmad

#include <WiFi.h>
#include <PubSubClient.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Macro
#define SCREEN_WIDTH 128 
#define SCREEN_HEIGHT 64
#define LED_PIN 2
#define BUTTON_PIN 0

// WiFi
const char *ssid = "-"; 
const char *password = "-"; 

// MQTT Broker
const char *mqtt_broker = "free.mqtt.iyoti.id";
const int mqtt_port = 1883;
const char *topic_payment_pay = "/13520110/payment/pay";
const char *topic_payment_ack = "/13520110/payment/ack";
const char *client_id = "ESP32Client13520110";

// Global Variables
int credit = 210000;
int deduction = 20000;
WiFiClient espClient;
PubSubClient client(espClient);
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
bool deduct = false;

void connect_wifi() {
  WiFi.begin(ssid, password);
  Serial.println("Connecting to WiFi..");
  while (WiFi.status() != WL_CONNECTED) {
      delay(10);
  }
  Serial.println("WiFi connected");
  Serial.print("IP address: "); Serial.println(WiFi.localIP());
}

void connect_broker() {
  client.setServer(mqtt_broker, mqtt_port);
  client.setCallback(callback);
  Serial.println("Connecting to broker");
  while (!client.connected()) {
    client.connect(client_id);
    delay(10);
  }
  Serial.println("MQTT Broker connected");
  // client.subscribe(ir_topic);
}

void callback(char *topic_recv, byte *payload, unsigned int length) {
  String msg;
  // if (String(topic_recv) == String(ir_topic)) {
  //   for (int i = 0; i < length; i++) {
  //     msg += (char)payload[i];
  //   }
  //   Serial.println("Data received: " + msg);
  // }
}

void IRAM_ATTR isr() {
  deduct = !deduct ? true : false;
}

void write_oled(String text) {
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  display.println(text);
  display.display(); 
}

void setup() {
  pinMode(BUTTON_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);

  // OLED Setup
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  // Connect to Wi-Fi
  write_oled("Connecting\nWiFi");
  connect_wifi();
  write_oled("WiFi\nConnected"); delay(10);

  // Connect to MQTT Broker
  write_oled("Connecting\nBroker");
  connect_broker();
  write_oled("Broker\nConnected"); delay(10);
  write_oled("E-Wallet\nReady");

  attachInterrupt(BUTTON_PIN, isr, FALLING);
}

void loop() {
  if (deduct) {
    unsigned long start_time = millis();
    if (credit - deduction >= 0) {
      credit -= deduction;
      write_oled("Credit\nDeducted");
      while(millis() - start_time < 5000){
        digitalWrite(LED_PIN, HIGH);
      }
      digitalWrite(LED_PIN, LOW);
    }
    else {
      write_oled("Credit\nNot\nSufficient");
      while(millis() - start_time < 5000){
        digitalWrite(LED_PIN, HIGH);
        delay(250);
        digitalWrite(LED_PIN, LOW);
        delay(250);
      }
    }
    write_oled("E-Wallet\nReady");
    deduct = false;
  }
  delay(20);
}
