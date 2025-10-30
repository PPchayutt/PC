// ลูกอมเขียว ๆ
const float T0 = 25.0 + 273.0;

void setup(){
  Serial.begin(9600);
}

void loop(){
  int raw = analogRead(A0);
  float V = raw * (5.0 / 1023.0);
  float Resis = 10000.0 * ( (5.0 / V) - 1 );
  
  float tempK = 4050.0 * T0 / ( 4050.0 + (T0 * log(Resis / 10000.0)) );
  float tempC = tempK - 273.15;
  Serial.println(tempC);
  delay(500);
}