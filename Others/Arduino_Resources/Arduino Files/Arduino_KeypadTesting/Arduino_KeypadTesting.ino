#include <Keypad.h>

const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  { '1', '2', '3', 'A' },
  { '4', '5', '6', 'B' },
  { '7', '8', '9', 'C' },
  { '*', '0', '#', 'D' }
};

byte rowPins[ROWS] = { 9, 8, 7, 6 };
byte colPins[COLS] = { 5, 4, 3, 2 };

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);


const int redPin = 12;
const int greenPin = 11;
const int bluePin = 10;


void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}


void loop() {
  char key = keypad.getKey();

  if (key) {
    Serial.print("Key Pressed: ");
    Serial.println(key);

    switch (key) {
      case '1':
        setColor(255, 0, 0);
        break;
      case '2':
        setColor(0, 255, 0);
        break;
      case '3':
        setColor(0, 0, 255);
        break;
      case '4':
        setColor(255, 255, 0);
        break;
      case '5':
        setColor(0, 255, 255);
        break;
      case '6':
        setColor(255, 0, 255);
        break;
      case '7':
        setColor(192, 192, 192);
        break;
      case '8':
        setColor(128, 128, 128);
        break;
      case '9':
        setColor(128, 0, 0);
        break;
      case 'A':
        setColor(128, 128, 0);
        break;
      case 'B':
        setColor(0, 128, 0);
        break;
      case 'C':
        setColor(128, 0, 128);
        break;
      case 'D':
        setColor(0, 128, 128);
        break;
      case '*':
        setColor(0, 0, 128);
        break;
      case '#':
        setColor(165, 42, 42);
        break;
      case '0':
        setColor(0, 0, 0);
        break;
      default:
        setColor(0, 0, 0);
        break;
    }
  }
}

void setColor(int red, int green, int blue) {
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}