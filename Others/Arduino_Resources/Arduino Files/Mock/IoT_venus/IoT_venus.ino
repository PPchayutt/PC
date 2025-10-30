#include <WiFiS3.h>
#include <MQTTClient.h>

const char WIFI_SSID[] = "Rattanamanee";
const char WIFI_PASSWORD[] = "0816868621";

const char MQTT_BROKER_ADRRESS[] = "phycom.it.kmitl.ac.th";
const int MQTT_PORT = 1883;
const char MQTT_CLIENT_ID[] = "WhyVenus";
const char MQTT_USERNAME[] = "";
const char MQTT_PASSWORD[] = "";

const char PUBLISH_TOPIC[] = "";
const char SUBSCRIBE_TOPIC[] = "67070115/venus";

const int PUBLISH_INTERVAL = 5000;

WiFiClient network;
MQTTClient mqtt = MQTTClient(256);

unsigned long lastPublishTime = 0;

// RGB LED pins (Common Anode)
const int RED_LED = 9;
const int  GREEN_LED= 10;
const int  BLUE_LED= 11;

void setup() {
  Serial.begin(9600);

  // Setup LED pins
  pinMode(RED_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  
  // ปิด LED ทั้งหมดตอนเริ่มต้น (Common Anode = HIGH เท่ากับปิด)
  digitalWrite(RED_LED, HIGH);
  digitalWrite(BLUE_LED, HIGH);
  digitalWrite(GREEN_LED, HIGH);

  int status = WL_IDLE_STATUS;
  while (status != WL_CONNECTED) {
    Serial.print("Arduino UNO R4 - Attempting to connect to SSID: ");
    Serial.println(WIFI_SSID);
    status = WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    delay(10000);
  }
  
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  connectToMQTT();
}

void loop() {
  mqtt.loop();
}

void connectToMQTT() {
  mqtt.begin(MQTT_BROKER_ADRRESS, MQTT_PORT, network);
  mqtt.onMessage(messageReceived);

  Serial.print("Arduino UNO R4 - Connecting to MQTT broker");

  while (!mqtt.connect(MQTT_CLIENT_ID, MQTT_USERNAME, MQTT_PASSWORD)) {
    Serial.print(".");
    delay(100);
  }
  Serial.println();

  if (!mqtt.connected()) {
    Serial.println("Arduino UNO R4 - MQTT broker Timeout!");
    return;
  }

  if (mqtt.subscribe(SUBSCRIBE_TOPIC))
    Serial.print("Arduino UNO R4 - Subscribed to the topic: ");
  else
    Serial.print("Arduino UNO R4 - Failed to subscribe to the topic: ");

  Serial.println(SUBSCRIBE_TOPIC);
  Serial.println("Arduino UNO R4 - MQTT broker Connected!");
}

void messageReceived(String &topic, String &payload) {
  Serial.println("Arduino UNO R4 - received from MQTT:");
  Serial.println("- topic: " + topic);
  Serial.println("- payload: " + payload);

  // แปลงค่าที่รับมาเป็นตัวเลข
  int value = payload.toInt();
  Serial.print("- Value: ");
  Serial.println(value);
  
// ปิด LED ทั้งหมดก่อน (Common Anode = HIGH เท่ากับปิด)
  digitalWrite(RED_LED, HIGH);
  digitalWrite(BLUE_LED, HIGH);
  digitalWrite(GREEN_LED, HIGH);
  
  // เปิด LED ตามช่วงค่าที่กำหนด (Common Anode = LOW เท่ากับเปิด)
  if (value >= 36 && value <= 50) {
    // หากค่าตั้งแต่ 36 - 50 ให้ LED เป็นสีแดง
    digitalWrite(RED_LED, LOW);   // เปิด LED แดง
    Serial.println("-> RED LED ON (36-50)");
  } 
  else if (value >= 26 && value <= 35) {
    // หากค่าตั้งแต่ 26 - 35 ให้ LED เป็นสีฟ้า
    digitalWrite(BLUE_LED, LOW);  // เปิด LED ฟ้า
    Serial.println("-> BLUE LED ON (26-35)");
  } 
  else if (value >= 10 && value <= 25) {
    // หากค่าตั้งแต่ 10 - 25 ให้ LED เป็นสีเขียว
    digitalWrite(GREEN_LED, LOW);  // เปิด LED เขียว
    Serial.println("-> GREEN LED ON (10-25)");
  }
  else {
    Serial.println("-> Value out of range - ALL LEDs OFF");
  }
}