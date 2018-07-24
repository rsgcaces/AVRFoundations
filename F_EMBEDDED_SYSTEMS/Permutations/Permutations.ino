// PROJECT  :Permutations
// PURPOSE  :AVR Foundations Workbook
uint8_t n = 4;
uint8_t r = 4;
char buff[20];
void setup() {
  Serial.begin(9600);
  Serial.print("Enter the number of distinct objects...");
  while (!Serial.available());
  n = Serial.parseInt();
  Serial.readString();
  Serial.print(String(n)+"\nHow many at a time?(<=" + String(n) + ")...");
  while (!Serial.available());
  r = Serial.parseInt();
  sprintf(buff, "%d\nP(%d,%d)=%d", r, n, r, perms(n, r));
  Serial.println(buff);
}
void loop() {}
uint8_t perms(uint8_t n, uint8_t r) {
  return fact(n) / fact(n - r);
}
uint32_t fact(uint8_t n) {
  if (n > 0)
    return n * fact(n - 1);
  return 1;
}

