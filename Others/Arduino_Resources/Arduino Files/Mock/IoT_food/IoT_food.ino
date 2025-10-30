// อ่านค่าระยะทางจาก Ultrasonic หน่วยเป็น cm
#include <WiFiS3.h>
#include <MQTTClient.h>

const char WIFI_SSID[] = "Rattanamanee";
const char WIFI_PASSWORD[] = "0816868621";

const char MQTT_BROKER_ADRRESS[] = "phycom.it.kmitl.ac.th";
const int MQTT_PORT = 1883;

const char MQTT_CLIENT_ID[] = "WhyFood";
const char MQTT_USERNAME[] = "";
const char MQTT_PASSWORD[] = "";

// The MQTT topics that Arduino should publish
const char PUBLISH_TOPIC[] = "67070115/food";
const char SUBSCRIBE_TOPIC[] = "";  // ไม่ต้อง subscribe

const int PUBLISH_INTERVAL = 500;

WiFiClient network;
MQTTClient mqtt = MQTTClient(256);

unsigned long lastPublishTime = 0;

const int trigPin = 9;
const int echoPin = 10;
long duration;
int distanceCm, distanceInch;

void setup() {
  Serial.begin(9600);

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

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  mqtt.loop();

  if (millis() - lastPublishTime > PUBLISH_INTERVAL) {
    sendToMQTT();
    lastPublishTime = millis();
  }
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

  Serial.println("Arduino UNO R4 - MQTT broker Connected!");
}

void sendToMQTT() {
  // อ่านค่าจาก Ultrasonic
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  
  distanceCm = duration * 0.034 / 2;
  distanceInch = duration * 0.0133 / 2;

  Serial.print("Distance: ");
  Serial.print(distanceCm);
  Serial.println(" cm");

  String val_str = "";
  
  // ถ้ามากกว่า 20 cm ให้ส่ง "off"
  if (distanceCm > 20) {
    val_str = "off";
  }
  // ถ้าน้อยกว่าหรือเท่ากับ 20 cm (ใกล้) ให้ส่ง "on"
  else {
    val_str = "on";
  }

  char messageBuffer[10];
  val_str.toCharArray(messageBuffer, 10);
  mqtt.publish(PUBLISH_TOPIC, messageBuffer);
  
  Serial.println("Arduino UNO R4 - sent to MQTT:");
  Serial.print("- topic: ");
  Serial.println(PUBLISH_TOPIC);
  Serial.print("- payload: ");
  Serial.println(messageBuffer);
}

void messageReceived(String &topic, String &payload) {
  // ไม่ได้ใช้ในข้อนี้
}