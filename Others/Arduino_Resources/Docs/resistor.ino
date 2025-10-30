// หันออก
// ช่องแรก 5V
// ช่องสอง INPUT
// ช่องสาม GND
// ตัวหมุน

const int potPin = A0; // Pin for Potentiometer (Analog input pin)
void setup() {
  Serial.begin(9600);
}

void loop() {
  int potValue = analogRead(potPin); // Read the value from the Potentiometer
  Serial.println(potValue);
}