// PROJECT  :Variable Scope
// PURPOSE  :
// AUTHOR   :C. D'Arcy
// DATE     :2018 06 20
// uC       :*
// STATUS   :Working
uint8_t n = 0;
void setup() {
  Serial.begin(9600);
  Serial.println(n);
}
void loop() {
  uint8_t n = 10;
  Serial.println(n);
  if (n > 0) {
    uint8_t n = 20;
    Serial.println(n);
  }
  Serial.println(n);
  while (true);
}
