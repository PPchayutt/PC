// อ่านค่าระยะทางจาก Ultrasonic หน่วยเป็น cm
#include <WiFiS3.h>
#include <MQTTClient.h>

const char WIFI_SSID[] = "";     // CHANGE TO YOUR WIFI SSID
const char WIFI_PASSWORD[] = "";  // CHANGE TO YOUR WIFI PASSWORD

const char MQTT_BROKER_ADRRESS[] = "phycom.it.kmitl.ac.th";
const int MQTT_PORT = 1883; // 8883, 8884, 1884

const char MQTT_CLIENT_ID[] = "";  // CHANGE IT AS YOU DESIRE
const char MQTT_USERNAME[] = "";
const char MQTT_PASSWORD[] = "";

// The MQTT topics that Arduino should publish/subscribe
const char PUBLISH_TOPIC[] = "";       // CHANGE IT AS YOU DESIRE
const char SUBSCRIBE_TOPIC[] = "";  // CHANGE IT AS YOU DESIRE

const int PUBLISH_INTERVAL = 5000;

WiFiClient network;
MQTTClient mqtt = MQTTClient(256);

unsigned long lastPublishTime = 0;

const int trigPin = 9; // สีเขียว
const int echoPin = 10; // สีเหลือง
long duration;
int distanceCm, distanceInch;

void setup() {
  Serial.begin(9600);

  int status = WL_IDLE_STATUS;
  while (status != WL_CONNECTED) {
    Serial.print("Arduino UNO R4 - Attempting to connect to SSID: ");
    Serial.println(WIFI_SSID);
    // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
    status = WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

    // wait 10 seconds for connection:
    delay(10000);
  }
  // print your board's IP address:
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
  // Connect to the MQTT broker
  mqtt.begin(MQTT_BROKER_ADRRESS, MQTT_PORT, network);

  // Create a handler for incoming messages
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

  // Subscribe to a topic, the incoming messages are processed by messageHandler() function
  if (mqtt.subscribe(SUBSCRIBE_TOPIC))
    Serial.print("Arduino UNO R4 - Subscribed to the topic: ");
  else
    Serial.print("Arduino UNO R4 - Failed to subscribe to the topic: ");

  Serial.println(SUBSCRIBE_TOPIC);
  Serial.println("Arduino UNO R4 - MQTT broker Connected!");
}

// Publish
void sendToMQTT() {

  // แก้ตรงนี้ว่าจะให้ส่งค่าอะไรไปใช้ตัวแปรเป็น val
  // int val = millis()/1000;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  
  distanceCm = duration * 0.034 / 2;
  distanceInch = duration * 0.0133 / 2;

  String val_str = "";
  if (distanceCm > 20){
    val_str = "off";
  }

  char messageBuffer[10];
  val_str.toCharArray(messageBuffer, 10);
  mqtt.publish(PUBLISH_TOPIC, messageBuffer);
  
  Serial.println("Arduino UNO R4 - sent to MQTT:");
  Serial.print("- topic: ");
  Serial.println(PUBLISH_TOPIC);
  Serial.print("- payload:");
  Serial.println(messageBuffer);
}

// Subscription
void messageReceived(String &topic, String &payload) {
  Serial.println("Arduino UNO R4 - received from MQTT:");
  Serial.println("- topic: " + topic);
  Serial.println("- payload:");
  Serial.println(payload);

  // ตัวแปรที่รับเข้ามาจะเป็น strings
  // Example payload.toInt()
  }

