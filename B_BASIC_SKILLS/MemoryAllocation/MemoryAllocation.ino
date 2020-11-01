// PROJECT  :MemoryAllocation
// PURPOSE  :Introduce RAM Usage, Addresses and the &-operator
// COURSE   :ICS3U
// AUTHOR   :C. D'Arcy
// DATE     :2020 11 09
// MCU      :*
// STATUS   :Working
// REFERENCE:https://www.arduino.cc/reference/en/language/structure/pointer-access-operators/reference/
// Declare variables of various types (primitive and object)
uint8_t a;
int8_t b;
uint16_t c;
int16_t d;
uint32_t e;
int32_t f;
uint64_t g;
int64_t h;
boolean i;
float f1;
double d1;
char s1[] = "RSGC ACES";
char s2[] = "Royal St. George's College";
char s3[] = "Advanced Computer Engineering School";
String s4 = "AVR Foundations";

void setup() {
  Serial.begin(9600);
  while(!Serial);
  // Use C's address operator (&) to get a sense of how storage space in RAM
  //    is allocated by the (Compiler's) Memory Management Algorithm
  Serial.println("SRAM Addresses:");
  Serial.println("a(uint8_t)\t:"+String((uint16_t)&a,DEC));
  Serial.println("b(int8_t)\t:"+String((uint16_t)&b,DEC));
  Serial.println("c(uint16_t)\t:"+String((uint16_t)&c,DEC));
  Serial.println("d(int16_t)\t:"+String((uint16_t)&d,DEC));
  Serial.println("e(uint32_t)\t:"+String((uint16_t)&e,DEC));
  Serial.println("f(int32_t)\t:"+String((uint16_t)&f,DEC));
  Serial.println("g(uint64_t)\t:"+String((uint16_t)&g,DEC));
  Serial.println("h(int64_t)\t:"+String((uint16_t)&h,DEC));
  Serial.println("i(boolean)\t:"+String((uint16_t)&i,DEC));
  Serial.println("f1(float)\t:"+String((uint16_t)&f1,DEC));
  Serial.println("d1(double)\t:"+String((uint16_t)&d1,DEC));
  Serial.println("s1(char[])\t:"+String((uint16_t)&s1,DEC));
  Serial.println("s2(char[])\t:"+String((uint16_t)&s2,DEC));
  Serial.println("s3(char[])\t:"+String((uint16_t)&s3,DEC));
  Serial.println("s4(String)\t:"+String((uint16_t)&s4,DEC));
}

void loop() {}
