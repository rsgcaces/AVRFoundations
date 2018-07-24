// PROJECT  :Recursive Factorial
// PURPOSE  :AVR Foundations Workbook
uint8_t n = 4;
char buff[20];
void setup() {
  Serial.begin(9600);
  Serial.println("Enter the a natural number less than 15...");
  while (!Serial.available());
  n = Serial.parseInt();
  sprintf(buff, "%d!=%lu", n, fact(n));
  Serial.println(buff);
}
void loop() {}
uint32_t fact(uint8_t n) {
  if (n > 0)
    return n * fact(n - 1);
  return 1;
}

