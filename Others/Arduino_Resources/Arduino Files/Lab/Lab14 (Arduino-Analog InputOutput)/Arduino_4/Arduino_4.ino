#include <math.h>

const int THERMISTOR_PIN = A0;
// ตัวต้านทานคงที่ในวงจรแบ่งแรงดัน (จากภาพคือ 10k Ohm)
const float SERIES_RESISTOR = 10000.0;
// ค่าคงที่จาก datasheet ของ Thermistor (อาจต้องปรับค่าตาม Thermistor จริง)
const float NOMINAL_RESISTANCE = 10000.0;  // R0 ที่ 25 องศาเซลเซียส
const float NOMINAL_TEMPERATURE = 25.0;    // T0
const float B_COEFFICIENT = 3950.0;        // Beta Value (B)

void setup() {
  Serial.begin(9600);
}

void loop() {
  // 1. อ่านค่า ADC จากขา Analog
  int adc_value = analogRead(THERMISTOR_PIN);

  // 2. แปลงค่า ADC เป็นความต้านทานของ Thermistor (R_thermistor)
  // Vout = (adc_value / 1023.0) * 5.0 (เมื่อ Vcc = 5V)
  // R_thermistor = (SERIES_RESISTOR * Vout) / (Vcc - Vout)
  // หรือ R_thermistor = SERIES_RESISTOR * (1023.0 / adc_value - 1)

  float thermistor_resistance = SERIES_RESISTOR / (1023.0 / (float)adc_value - 1.0);

  // 3. แปลงค่าความต้านทานเป็นอุณหภูมิโดยใช้ Beta Parameter Equation
  // T = 1 / ( (1/T0) + (1/B) * ln(R/R0) )
  // อุณหภูมิทั้งหมดต้องอยู่ในหน่วย Kelvin

  // แปลง T0 (25 C) เป็น Kelvin
  float temp_kelvin = NOMINAL_TEMPERATURE + 273.15;

  // คำนวณ (1/T0)
  float one_over_t0 = 1.0 / temp_kelvin;

  // คำนวณ ln(R/R0) / B
  float ln_ratio_over_b = log(thermistor_resistance / NOMINAL_RESISTANCE) / B_COEFFICIENT;

  // T ใน Kelvin
  float temperature_k = 1.0 / (one_over_t0 + ln_ratio_over_b);

  // แปลงจาก Kelvin เป็น Celsius
  float temperature_c = temperature_k - 273.15;

  Serial.print(temperature_c);
  Serial.println(" C");

  delay(500);  // หน่วงเวลา 0.5 วินาทีก่อนอ่านค่าใหม่
}