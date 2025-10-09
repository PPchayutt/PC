#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);
void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3c);  //สั่งให้จอ OLED เริ่มทำงานที่ Address 0x3C
  display.clearDisplay();                     // ลบภาพในหน้าจอทั้งหมด
  display.drawPixel(127, 63, WHITE);
  display.drawLine(0, 63, 127, 21, WHITE);
  display.drawCircle(110, 50, 12, WHITE);
  display.fillCircle(45, 50, 8, WHITE);
  display.drawTriangle(70, 60, 90, 60, 80, 46, WHITE);
  display.setTextSize(1);  // กำหนดขนาดตัวอักษร
  display.setTextColor(WHITE);
  display.setCursor(0, 0);  // กำหนดตำแหน่ง x,y ที่จะแสดงผล
  display.println(" OLED 0.96 TESTER ");
  display.setTextSize(1);
  display.println("Worachot");
  display.setTextColor(BLACK, WHITE);  //กำหนดข้อความสีขาว ฉากหลังสีดำ
  display.setTextSize(2);
  display.println("IS GAY");  // แสดงผลข้อความ www.Myarduino.net
  display.display();
}
void loop() {
}