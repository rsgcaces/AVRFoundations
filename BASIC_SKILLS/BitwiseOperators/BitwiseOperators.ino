// PROJECT  :Bitwise Operations
// PURPOSE  :Demonstration
// AUTHOR   :C. D'Arcy
// DATE     :2018 05 20
void setup() {
  Serial.begin(9600);
  Serial.println(15 << 1);
  Serial.println(23 >> 2);
  Serial.println(11 & 5);
  Serial.println(11 | 5);
  Serial.println(11 ^ 5);
  Serial.println(~1);
  Serial.println(~5<<2);
  Serial.println(100<<~1);
  Serial.println(15 & 7 << 1);
  Serial.println(0xAA & 036);
  Serial.println(254 | 1);
  Serial.println(~10 ^ 1 << 2);
}
void loop() {}

