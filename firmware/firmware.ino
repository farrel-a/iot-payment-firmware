// IoT Payment Firmware 
// 13520110 - Farrel Ahmad

#include <WiFi.h>
#include <PubSubClient.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Preferences.h>

// Macro
#define SCREEN_WIDTH 128 
#define SCREEN_HEIGHT 64
#define BUTTON_PIN 0
#define LED_PIN 2
#define CREDITS_KEY "credit"

// WiFi
const char *ssid = ""; 
const char *password = ""; 

// MQTT Broker
const char *mqtt_broker = "free.mqtt.iyoti.id";
const int mqtt_port = 1883;
const char *topic_payment_log = "/13520110/payment/log";
const char *topic_balance_check = "/13520110/balance/check";
const char *topic_balance_topup = "/13520110/balance/topup";
const char *client_id = "ESP32Client13520110IoTPayment";

// Global Variables
int credit = 210000;
int deduction = 20000;
WiFiClient espClient;
PubSubClient client(espClient);
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
bool deduct = false;
Preferences preferences;

bool isNumeric(const char* str) {
    if (*str == '\0') {
        return false;
    }
    while (*str != '\0') {
        if (!isdigit(*str)) {
            return false;
        }
        str++;
    }
    return true;
}

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
  client.subscribe(topic_balance_check);
  client.subscribe(topic_balance_topup);
  Serial.println("MQTT Broker connected");
}

void callback(char *topic_recv, byte *payload, unsigned int length) {
  String msg;
  for (int i = 0; i < length; i++) {
    msg += (char)payload[i];
  }
  String credit_str = String(credit);
  if (String(topic_recv) == String(topic_balance_check)) {
    if (msg == "check") {
      client.publish(topic_balance_check, credit_str.c_str()); 
      client.loop();
    }
  }
  else if (String(topic_recv) == String(topic_balance_topup)) {
    if (isNumeric(msg.c_str())) {
      int topup = atoi(msg.c_str());
      preferences.putInt(CREDITS_KEY, credit + topup);
      credit += topup;
      credit_str = String(credit);
      client.publish(topic_payment_log, msg.c_str());
      client.publish(topic_balance_check, credit_str.c_str());
      write_oled("Credit\nAdded"); digitalWrite(LED_PIN, HIGH); 
      delay(1000); 
      write_oled("E-Wallet\nReady"); digitalWrite(LED_PIN, LOW);
      client.loop();
    }
  }
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
  // Pin Settings
  pinMode(BUTTON_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  attachInterrupt(BUTTON_PIN, isr, FALLING);

  // OLED Setup
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }

  // Preferences
  preferences.begin("payment", false);
  if (!preferences.isKey(CREDITS_KEY)) {
    preferences.putInt(CREDITS_KEY, credit);
  }
  credit = preferences.getInt(CREDITS_KEY);

  // Connect to Wi-Fi
  write_oled("Connecting\nWiFi");
  connect_wifi();
  write_oled("WiFi\nConnected"); delay(1000);

  // Connect to MQTT Broker
  write_oled("Connecting\nBroker");
  connect_broker();
  write_oled("Broker\nConnected"); delay(1000);
  write_oled("E-Wallet\nReady");
}

void loop() {
  if (deduct) {
    unsigned long start_time = millis();
    if (credit - deduction >= 0) {
      preferences.putInt(CREDITS_KEY, credit - deduction);
      credit -= deduction;
      write_oled("Credit\nDeducted");
      String log = "-" + String(20000);
      client.publish(topic_payment_log, log.c_str());
      client.publish(topic_balance_check, String(credit).c_str());
      while(millis() - start_time < 5000){
        digitalWrite(LED_PIN, HIGH);
        client.loop();
      }
      digitalWrite(LED_PIN, LOW);
    }
    else {
      write_oled("Credit\nNot\nSufficient");
      client.publish(topic_payment_log, "0");
      while(millis() - start_time < 5000){
        digitalWrite(LED_PIN, HIGH);
        delay(250);
        digitalWrite(LED_PIN, LOW);
        delay(250);
        client.loop();
      }
    }
    write_oled("E-Wallet\nReady");
    deduct = false;
  }
  else {
    client.loop();
  }
  delay(20);
}
