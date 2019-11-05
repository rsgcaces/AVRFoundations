// PROJECT  :ByteManipulations
// PURPOSE  :Support for 2019/2020 ICS3U PoVWord Project...
// COURSE   :ICS3U
// AUTHOR   :C. D'Arcy
// DATE     :2019 11 06
// MCU      :328p
// STATUS   :Working
// REFERENCE:https://www.arduino.cc/reference/en/#functions  (Bits 'n Bytes)
//          :https://en.cppreference.com/w/cpp/language/operator_precedence

uint8_t this8 = 0b10101011;     // sample unsigned byte (aka 0xAB)
uint8_t swapNibbles;            //
uint8_t that8 = 0b11001101;     // sample unsigned byte (aka 0xCD)
uint16_t this16;                // to be created on the fly...
uint16_t swapBytes;             //
uint16_t reverseNibbles;        // a task left for you at the end...

void setup() {
  Serial.begin(9600);
  while (!Serial);
  
  //display a sample byte...
  Serial.println("this8:\t\t" + String(this8, HEX));
  //interchange the high and low nibbles...(Q. Why is OR simpler than + here?)  
  swapNibbles = this8 << 4 | this8 >> 4;
  Serial.println("SwapNibbles:\t" + String(swapNibbles, HEX));

  //display another sample unsigned byte...
  Serial.println("\nthat8:\t\t" + String(that8, HEX));
  //create a 16-bit unsigned word from the two bytes values...
  this16 = this8 << 8 | that8;
  //display it...
  Serial.println("\nthis16:\t\t" + String(this16, HEX));
  //interchange the high and low bytes...
  //...this time through the use of the Arduino functions...
  swapBytes =  lowByte(this16) << 8 | highByte(this16);
  //display for confirmation...
  Serial.println("SwapBytes:\t" + String(swapBytes, HEX));
  //I'll leave this task to you...
  // In a single statement, uncommnet the following statement and
  // reverse the order of the nibbles on this16!
  // reverseNibbles = ?
  //The output should be: dcba
  Serial.println("\nReverseNibbles:\t"+String(reverseNibbles,HEX));
}

void loop() {
}
