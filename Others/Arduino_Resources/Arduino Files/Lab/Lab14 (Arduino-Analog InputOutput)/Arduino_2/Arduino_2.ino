void setup() {
  Serial.begin(9600);
  pinMode(9, OUTPUT);
}
void loop() {
  int adc_value = analogRead(A0);
  int brightness = map(adc_value, 0, 1023, 0, 255);
  analogWrite(9, brightness);
  Serial.print("Analog: ");
  Serial.print(adc_value);
  Serial.print(", Brightness: ");
  Serial.println(brightness);
  delay(100);
}