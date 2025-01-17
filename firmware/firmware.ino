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
#define BALANCE_KEY "balance"

// WiFi
const char *ssid = ""; 
const char *password = ""; 

// MQTT Broker
const char *mqtt_broker = "";
const int mqtt_port = 0;
const char *topic_payment_log = "/iot-payment/payment/log";
const char *topic_balance_check = "/iot-payment/balance/check";
const char *topic_balance_topup = "/iot-payment/balance/topup";
const char *client_id = "ESP32ClientMyEWallet";

// Global Variables
int balance = 210000;
int max_balance = 5000000;
int deduction = 20000;
int max_topup = 5000000;
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
  String balance_str = String(balance);
  if (String(topic_recv) == String(topic_balance_check)) {
    if (msg == "check") {
      client.publish(topic_balance_check, balance_str.c_str()); 
      client.loop();
    }
  }
  else if (String(topic_recv) == String(topic_balance_topup)) {
    if (isNumeric(msg.c_str())) {
      int topup = atoi(msg.c_str());
      topup = topup < max_topup ? topup : max_topup;
      balance = balance + topup < max_balance ? balance + topup : max_balance;
      preferences.putInt(BALANCE_KEY, balance);
      balance_str = String(balance);
      String log = msg + "," + balance_str;
      client.publish(topic_payment_log, log.c_str());
      write_oled("Balance\nAdded"); digitalWrite(LED_PIN, HIGH); 
      delay(1000); 
      write_oled("E-Wallet\nReady\nRp" + String(balance)); digitalWrite(LED_PIN, LOW);
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
  if (!preferences.isKey(BALANCE_KEY)) {
    preferences.putInt(BALANCE_KEY, balance);
  }
  balance = preferences.getInt(BALANCE_KEY);

  // Connect to Wi-Fi
  write_oled("Connecting\nWiFi");
  connect_wifi();
  write_oled("WiFi\nConnected"); delay(1000);

  // Connect to MQTT Broker
  write_oled("Connecting\nBroker");
  connect_broker();
  write_oled("Broker\nConnected"); delay(1000);
  write_oled("E-Wallet\nReady\nRp" + String(balance));
}

void loop() {
  if (deduct) {
    unsigned long start_time = millis();
    String log;
    if (balance - deduction >= 0) {
      preferences.putInt(BALANCE_KEY, balance - deduction);
      balance -= deduction;
      write_oled("Balance\nDeducted");
      log = "-" + String(20000) + "," + String(balance);
      client.publish(topic_payment_log, log.c_str());
      while(millis() - start_time < 5000){
        digitalWrite(LED_PIN, HIGH);
        client.loop();
      }
      digitalWrite(LED_PIN, LOW);
    }
    else {
      write_oled("Balance\nNot\nSufficient");
      log = "0," + String(balance);
      client.publish(topic_payment_log, log.c_str());
      while(millis() - start_time < 5000){
        digitalWrite(LED_PIN, HIGH);
        delay(250);
        digitalWrite(LED_PIN, LOW);
        delay(250);
        client.loop();
      }
    }
    write_oled("E-Wallet\nReady\nRp" + String(balance));
    deduct = false;
  }
  else {
    client.loop();
  }
  delay(20);
}
