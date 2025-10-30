#include <WiFiS3.h>
#include <MQTT.h>  // ใน Arduino IDE ต้องติดตั้ง Library ชื่อ "MQTT" by Joel Gaehwiler

// --- 1. ตั้งค่า WiFi (ใส่ WiFi ตรงนี้) ---
const char WIFI_SSID[] = "Rattanamanee";
const char WIFI_PASSWORD[] = "0816868621";

// --- 2. ตั้งค่า MQTT (จากหน้าเว็บ Mock Exam) ---
const char MQTT_HOST[] = "phycom.it.kmitl.ac.th";
const int MQTT_PORT = 1883;
const char MQTT_CLIENT_ID[] = "whyarduino";
const char MQTT_USERNAME[] = "";
const char MQTT_PASSWORD[] = "";

// --- 3. ตั้งค่า Topic และ Pin ---
const char PUBLISH_TOPIC[] = "67070115/temp";
const int TEMP_PIN = A0;  // LM35 ต่อที่ขา A0

// --- 4. ตัวแปรสำหรับเชื่อมต่อ และจับเวลา ---
WiFiClient wifiClient;
MQTTClient mqttClient;

unsigned long lastPublishTime = 0;
const long PUBLISH_INTERVAL = 2000;  // ส่งข้อมูลทุก 2 วินาที

// --- 5. Setup (ทำงานครั้งเดียวตอนเปิดเครื่อง) ---
void setup() {
  Serial.begin(115200);  // แนะนำให้ใช้ 115200 จะเร็วกว่า

  // (ขา Analog Input (A0) ไม่ต้อง pinMode)

  connectWiFi();
  connectMQTT();
}

// --- 6. Loop (ทำงานวนไปเรื่อยๆ) ---
void loop() {
  // คอยเช็คการเชื่อมต่อ MQTT
  mqttClient.loop();

  // ถ้าหลุด ให้ต่อใหม่
  if (!mqttClient.connected()) {
    connectMQTT();
  }

  // ใช้ millis() เพื่อส่งข้อมูลทุก 2 วินาที
  if (millis() - lastPublishTime > PUBLISH_INTERVAL) {
    sendToMQTT_Temp();  // เรียกฟังก์ชันส่งค่าอุณหภูมิ
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

  // *** ข้อนี้เรา "ส่ง" อย่างเดียว เลยไม่จำเป็นต้องมี onMessage หรือ subscribe ***

  while (!mqttClient.connect(MQTT_CLIENT_ID, MQTT_USERNAME, MQTT_PASSWORD)) {
    Serial.print(".");
    delay(1000);
  }
  Serial.println("\nConnected!");
}

// --- 9. ฟังก์ชันส่งข้อมูลอุณหภูมิ (แปลงเป็น Celsius) ---
void sendToMQTT_Temp() {

  // 1. อ่านค่าดิบ 0-1023 จากขา A0
  int rawValue = analogRead(TEMP_PIN);

  // 2. แปลงเป็น Voltage (บอร์ด R4 ใช้ Vref 5V และความละเอียด 10-bit คือ 1023.0)
  float voltage = rawValue * (4.0 / 1023.0);

  // 3. แปลงเป็น Celsius (สูตรของ LM35 คือ 10mV หรือ 0.01V ต่อ 1°C)
  float celsius = voltage * 100.0;

  // 4. แปลงค่า Celsius (เช่น 26.12) เป็น String
  String val_str = String(celsius);
  char messageBuffer[10];
  val_str.toCharArray(messageBuffer, 10);

  // 5. ส่งค่า "องศา" ไปที่ Topic temp
  mqttClient.publish(PUBLISH_TOPIC, messageBuffer);
  Serial.println("Published Temp (Celsius): " + String(messageBuffer));
}

// --- 10. ฟังก์ชันรับข้อมูล (ว่างไว้) ---
// (ถึงเราจะไม่ได้ใช้ แต่ MQTTClient library บางเวอร์ชันอาจจะเรียกหา)
void messageReceived(String &topic, String &payload) {
  // ไม่ได้ใช้ในข้อนี้
}