// PROJECT  :ParameterPassing
// PURPOSE  :Introduce the distinction between 
//          :'Call by Value' and 'Call by Reference' wrt Parameter passing 
// COURSE   :ICS3U
// AUTHOR   :C. D'Arcy
// DATE     :2020 11 01
// MCU      :*
// STATUS   :Working

uint8_t a;        //define some storage space
uint8_t b;        //for a sample set of three numbers
uint8_t c;        //

uint8_t minimum;  //simple stats for our sample
uint8_t maximum;  //
float average;    //

char buff[50];    //interesting way to obtain formatted output 

void setup() {
  Serial.begin(9600);
  while (!Serial);
  a=1;
  b=2;
  c=3;
  sprintf(buff, "Of the three numbers: %d, %d, and %d...", a, b, c);
  Serial.println(buff);
  // Standard 'CALL by VALUE' functions. A SINGLE result returned. 
  minimum = getMinimum(a, b, c);
  maximum = getMaximum(a, b, c);
  average = getAverage(a, b, c);
  Serial.println("The minimum is " + String(minimum));
  Serial.println("The maximum is " + String(maximum));
  Serial.println("The average is " + String(average));
  
  Serial.println();
  
  a=11;
  b=12;
  c=13;
  sprintf(buff, "Of the three numbers: %d, %d, and %d...", a, b, c);
  Serial.println(buff);
  // Atypical 'CALL by REFERENCE' function. Multiple values modified. 
  getStats(a, b, c, minimum, maximum, average);
  Serial.println("The minimum is " + String(minimum));
  Serial.println("The maximum is " + String(maximum));
  Serial.println("The average is " + String(average));
}

// Three Standard 'CALL by VALUE' functions. A SINGLE result returned. 
uint8_t getMinimum(uint8_t num1, uint8_t num2, uint8_t num3) {
  uint8_t smallest = min(min(num1, num2), num3);
  return smallest;
}
uint8_t getMaximum(uint8_t num1, uint8_t num2, uint8_t num3) {
  uint8_t largest = max(max(num1, num2), num3);
  return largest;
}
float getAverage(uint8_t num1, uint8_t num2, uint8_t num3) {
  float arithmeticMean = (num1 + num2 + num3) / 3.0;
  return arithmeticMean;
}

// Atypical 'CALL by REFERENCE' function. Multiple values modified. 
// Note the use of the 'address of' operator (&) in the final three parameters (aka. arguments)
void getStats(uint8_t num1, uint8_t num2, uint8_t num3, uint8_t &mi, uint8_t &ma, float &avg) {
  mi = min(min(num1, num2), num3);;
  ma = max(max(num1, num2), num3);
  avg = (num1+num2+num3)/3.0;
}

void loop() {}
