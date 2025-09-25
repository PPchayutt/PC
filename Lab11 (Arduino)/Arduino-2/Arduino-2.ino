// กำหนดพอร์ตสำหรับ LED RGB
const int RED_PIN = 9;    // ขา Red
const int GREEN_PIN = 10;  // ขา Green
const int BLUE_PIN = 11;   // ขา Blue

void setup() {
  // กำหนดพอร์ตให้เป็น OUTPUT
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
}

void loop() {
    // เปิด LED
  digitalWrite+(RED_PIN, HIGH);  // ตั้งค่าให้ LED ติด
  delay(1000);    
  digitalWrite(GREEN_PIN, HIGH);
  delay(1000);    
  digitalWrite(BLUE_PIN, HIGH);
  delay(1000);                  // หน่วงเวลา 1 วินาที (1000 มิลลิวินาที)

  // ปิด LED
  digitalWrite(RED_PIN, LOW);   // ตั้งค่าให้ LED ดับ
  delay(1000);    
  digitalWrite(GREEN_PIN, LOW);
  delay(1000);    
  digitalWrite(BLUE_PIN, LOW);
  delay(1000);                  // หน่วงเวลา 1 วินาที (1000 มิลลิวินาที)
}