#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

byte heart[8] = {
  B00000,
  B00000,
  B01010,
  B11111,
  B11111,
  B01110,
  B00100,
  B00000
};

byte degree[8] = {
  B01110,
  B01010,
  B01110,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};

void setup() {
  lcd.init();
  lcd.backlight();  // เปิดไฟแบ็คไลท์
  lcd.createChar(1, heart);
  lcd.createChar(2, degree);

  lcd.setCursor(6, 0);
  lcd.print("I");
  lcd.setCursor(7, 0);
  lcd.write(byte(1));
  lcd.setCursor(8, 0);
  lcd.print("IT");
  lcd.setCursor(0, 1);
  lcd.print("67070115");
}

void loop() {
  int sensorValue = analogRead(A0);              // อ่านค่าเซนเซอร์
  float voltage = sensorValue * (4  / 1023.0);  // แปลงค่า Analog เป็น Voltage
  float temperatureC = voltage * 100;            // แปลง Voltage เป็น อุณหภูมิ (Celsius)

  lcd.setCursor(9, 1);
  lcd.print(temperatureC, 2);
  lcd.write(byte(2));
  lcd.print("C");

  delay(1000);  // หน่วงเวลา 1 วินาที
}
