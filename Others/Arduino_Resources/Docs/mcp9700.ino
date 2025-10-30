void setup(){
  Serial.begin(9600);
}

void loop(){
  int val = analogRead(A0); // A0 is INPUT from MCP700
  float voltage = val * (5.0 / 1023.0);
  float temperatureC = 100 * (voltage-1) + 50;
  Serial.println(temperatureC);
  delay(500);
}