// Define the LED pin
int ledPin = 13;

// Setup function: runs once
void setup() {
  // Initialize the LED pin as an OUTPUT
  pinMode(ledPin, OUTPUT);
}

// Loop function: runs repeatedly
void loop() {
  // Turn the LED ON
  digitalWrite(ledPin, HIGH);
  // Wait for 1 second
  delay(1000);
  // Turn the LED OFF
  digitalWrite(ledPin, LOW);
  // Wait for another second
  delay(1000);
}