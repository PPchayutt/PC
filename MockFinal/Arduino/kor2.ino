

#include <WiFiEspAT.h>
#include <PubSubClient.h>
#include <string.h>

// Emulate Serial1 on pins 6/7 if not present
#if defined(ARDUINO_ARCH_AVR) && !defined(HAVE_HWSERIAL1)
#include <SoftwareSerial.h>
SoftwareSerial Serial1(2, 3);  // RX, TX
#define AT_BAUD_RATE 9600
#else
#define AT_BAUD_RATE 115200
#endif

const char ssid[] = "YOUR_SSID";          // your network SSID (name)
const char pass[] = "YOUR_PASSWORD";  // your network password (use for WPA, or use as key for WEP)
const char* mqtt_server = "mqtt-dashboard.com";

WiFiClient espClient;
PubSubClient client(espClient);
unsigned long lastMsg = 0;
#define MSG_BUFFER_SIZE (50)
char msg[MSG_BUFFER_SIZE];
int value = 0;

void setup_wifi() {
  while (!Serial)
    ;
  Serial1.begin(9600);
  WiFi.init(Serial1);

  if (WiFi.status() == WL_NO_MODULE) {
    Serial.println();
    Serial.println("Communication with WiFi module failed!");
    // don't continue
    while (true)
      ;
  }

  WiFi.setPersistent();
  WiFi.endAP();
  Serial.println();
  Serial.print("Start AP with SSID: ");
  Serial.println(ssid);
  int status = WiFi.beginAP(ssid, pass);
  Serial.println("Waiting for connection to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print('.');
  }
  Serial.println();
  Serial.println("Connected to WiFi network.");
}


void callback(char* topic, byte* payload, unsigned int length) {
  String msg = "";
  for (int i = 0; i < length; i++) {
    msg += (char)payload[i];
  }
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    String clientId = "clientId-5txT8dA3Q4";
    if (client.connect(clientId.c_str())) {
      Serial.println("connected");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}

void setup() {
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
}

void loop() {

  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  delay(1000);
  unsigned long now = millis();
  if (now - lastMsg > 5000) {
    lastMsg = now;
    double temp = (750.0 / 7.0) * (analogRead(A1) * (5.0 / 1023.0) - 1) + 50;
    String temp_str = String(temp);
    char temp_char[10];
    temp_str.toCharArray(temp_char, 10);
    client.publish("aaapwn/temp", temp_char);
  }
}
