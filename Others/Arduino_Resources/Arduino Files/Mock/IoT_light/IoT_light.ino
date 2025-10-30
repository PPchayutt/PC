#include <WiFiS3.h>
#include <MQTT.h>  // อย่าลืมติดตั้ง Library "MQTT" by Joel Gaehwiler

// --- 1. ตั้งค่า WiFi (ใส่ WiFi ของเธอตรงนี้นะ!) ---
const char WIFI_SSID[] = "Rattanamanee";
const char WIFI_PASSWORD[] = "0816868621";

// --- 2. ตั้งค่า MQTT (จากหน้าเว็บ Mock Exam) ---
const char MQTT_HOST[] = "phycom.it.kmitl.ac.th";
const int MQTT_PORT = 1883;
const char MQTT_CLIENT_ID[] = "whyarduino";
const char MQTT_USERNAME[] = "";
const char MQTT_PASSWORD[] = "";

// --- 3. ตั้งค่า Topic และ Pin ---
const char PUBLISH_TOPIC[] = "67070115/light";  // <-- แก้เป็น light
const int LIGHT_PIN = A0;

// --- 4. ตัวแปรสำหรับเชื่อมต่อ และจับเวลา ---
WiFiClient wifiClient;
MQTTClient mqttClient;

unsigned long lastPublishTime = 0;
const long PUBLISH_INTERVAL = 2000;  // ส่งข้อมูลทุก 2 วินาที

// --- 5. Setup (ทำงานครั้งเดียวตอนเปิดเครื่อง) ---
void setup() {
  Serial.begin(115200);
  connectWiFi();
  connectMQTT();
}

// --- 6. Loop (ทำงานวนไปเรื่อยๆ) ---
void loop() {
  mqttClient.loop();
  if (!mqttClient.connected()) {
    connectMQTT();
  }

  if (millis() - lastPublishTime > PUBLISH_INTERVAL) {
    sendToMQTT_Light();  // เรียกฟังก์ชันส่งค่าแสง
    lastPublishTime = millis();
  }
}

// --- 7. ฟังก์ชันเชื่อมต่อ WiFi ---
void connectWiFi() {
  Serial.print("Connecting to WiFi: ");
  Serial.println(WIFI_SSID);
  while (WiFi.begin(WIFI_SSID, WIFI_PASSWORD) != WL_CONNECTED) {
    Serial.print(".");
    delay(1000);
  }
  Serial.println("\nConnected!");
}

// --- 8. ฟังก์ชันเชื่อมต่อ MQTT ---
void connectMQTT() {
  Serial.print("Connecting to MQTT...");
  mqttClient.begin(MQTT_HOST, MQTT_PORT, wifiClient);
  mqttClient.onMessage(messageReceived);  // (ใส่ไว้เผื่อเฉยๆ)

  while (!mqttClient.connect(MQTT_CLIENT_ID, MQTT_USERNAME, MQTT_PASSWORD)) {
    Serial.print(".");
    delay(1000);
  }
  Serial.println("\nConnected!");
}

// --- 9. ฟังก์ชันส่งข้อมูลแสง (ส่งค่าดิบ 0-1023) ---
void sendToMQTT_Light() {

  // อ่านค่า Raw Value (0-1023) จากขา A0
  int val = analogRead(LIGHT_PIN);

  // แปลงตัวเลขเป็น String
  String val_str = String(val);
  char messageBuffer[10];
  val_str.toCharArray(messageBuffer, 10);

  // ส่งค่า 0-1023 ไปที่ Topic light
  mqttClient.publish(PUBLISH_TOPIC, messageBuffer);
  Serial.println("Published Light (0-1023): " + String(messageBuffer));
}

// --- 10. ฟังก์ชันรับข้อมูล (ว่างไว้) ---
void messageReceived(String &topic, String &payload) {
  // ไม่ได้ใช้ในข้อนี้
}