// PROJECT  :Iterative Factorial
// PURPOSE  :AVR Foundations Workbook
uint8_t n = 4;
char buff[20];
void setup(){
  Serial.begin(9600);
  Serial.print("Enter a natural number less than 15...");
  while (!Serial.available());
  n = Serial.parseInt();
  sprintf(buff,"%d!=%lu",n,fact(n));
  Serial.println(buff);
}
void loop(){}
uint32_t fact(uint8_t n){
  uint32_t product = 1;
  while (n>0){
    product *= n;
    n--;
  }
  return product;
}

