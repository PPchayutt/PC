// ขาที่ต่อกับ 7-segment A-G
const int segmentPins[] = { 2, 3, 4, 5, 6, 7, 8 };

// ขาที่ใช้ควบคุมการแสดงผลของแต่ละ 7-segment
const int digitPins[] = { 11, 12 };  // Pin 11 สำหรับซ้าย, Pin 12 สำหรับขวา

// สร้าง Pattern ตัวเลข
byte numberPatterns[10][7] = {
  { 1, 1, 1, 1, 1, 1, 0 },  // 0
  { 0, 1, 1, 0, 0, 0, 0 },  // 1
  { 1, 1, 0, 1, 1, 0, 1 },  // 2
  { 1, 1, 1, 1, 0, 0, 1 },  // 3
  { 0, 1, 1, 0, 0, 1, 1 },  // 4
  { 1, 0, 1, 1, 0, 1, 1 },  // 5
  { 1, 0, 1, 1, 1, 1, 1 },  // 6
  { 1, 1, 1, 0, 0, 0, 0 },  // 7
  { 1, 1, 1, 1, 1, 1, 1 },  // 8
  { 1, 1, 1, 1, 0, 1, 1 }   // 9
};

// สร้าง Array เก็บชุดตัวเลข
const int studentID[4][2] = {
  { 6, 7 },  // คู่ที่ 1
  { 0, 7 },  // คู่ที่ 2
  { 0, 1 },  // คู่ที่ 3
  { 1, 5 }   // คู่ที่ 4
};

// ตัวแปรสำหรับจัดการเวลาและลำดับ
int currentPairIndex = 0;          // ตัวนับว่ากำลังแสดงเลขคู่ไหน (เริ่มจากคู่ที่ 0)
unsigned long lastSwitchTime = 0;  // ตัวจับเวลาเพื่อสลับเลขทุก 1 วินาที

// ฟังก์ชันสำหรับแสดงผล
void setSegments(int number) {
  for (int i = 0; i < 7; i++) {
    digitalWrite(segmentPins[i], numberPatterns[number][i]);
  }
}

void setup() {
  // ตั้งค่าขา 7-segment ทั้ง 7 ขาให้เป็น OUTPUT
  for (int i = 0; i < 7; i++) {
    pinMode(segmentPins[i], OUTPUT);
  }

  // ตั้งค่าขาควบคุมการแสดงผลให้เป็น OUTPUT (ขา 11-12)
  for (int i = 0; i < 2; i++) {
    pinMode(digitPins[i], OUTPUT);
  }
}

void loop() {
  // ตรวจสอบเพื่อสลับชุดตัวเลขทุกๆ 1 วินาที
  if (millis() - lastSwitchTime >= 1000) {
    lastSwitchTime = millis();    // รีเซ็ตเวลา
    currentPairIndex++;           // เลื่อนไปแสดงเลขคู่ถัดไป
    if (currentPairIndex >= 4) {  // ถ้าแสดงครบ 4 คู่แล้ว
      currentPairIndex = 0;       // ให้วนกลับไปคู่แรก
    }
  }

  // แสดงผลเลข 2 หลักด้วยวิธี Multiplexing
  // ดึงเลขซ้าย-ขวาจากชุดปัจจุบัน
  int leftDigit = studentID[currentPairIndex][0];
  int rightDigit = studentID[currentPairIndex][1];

  // แสดงเลขบน 7- segment ซ้าย
  digitalWrite(digitPins[0], LOW);   // เปิดซ้าย
  digitalWrite(digitPins[1], HIGH);  // ปิดขวา
  setSegments(leftDigit);
  delay(5);  // หน่วงเวลาสั้นๆ

  // แสดงเลขบน 7- segment ขวา
  digitalWrite(digitPins[0], HIGH);  // ปิดซ้าย
  digitalWrite(digitPins[1], LOW);   // เปิดขวา
  setSegments(rightDigit);
  delay(5);  // หน่วงเวลาสั้นๆ
}