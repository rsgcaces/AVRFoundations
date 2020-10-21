// PROJECT  :MaskingExemplar
// PURPOSE  :Demonstration of masking techniques
// COURSE   :ICS3U
// AUTHOR   :C. D'Arcy
// DATE     :2020 10 20
// MCU      :*
// STATUS   :Working
uint8_t byteValue   = 0x01;       // randomly chosen data
uint16_t wordValue  = 0x0123;     // but easily confirmed if 
uint32_t longValue  = 0x01234567; // defines as hexadecimal constants 

uint32_t bitMask = 0x1;           // useful for masking bits
uint32_t nibbleMask = 0xF;        // useful for masking nibbles
uint32_t byteMask  = 0xFF;        //useful for masking bytes

void setup() {
  Serial.begin(9600);
  // Destructive approaches...
  // display masked BITS, one per line...
  Serial.println(byteValue,HEX);
  for (uint8_t i = 0; i < 8; i++) {
    Serial.println(byteValue & bitMask);
    byteValue >>= 1;
  }
  // display masked NIBBLES, one per line...
  Serial.println();
  Serial.println(wordValue,HEX);
  for (uint8_t i = 0; i < 4; i++) {
    Serial.println(wordValue & nibbleMask, HEX);
    wordValue >>= 4;
  }
  Serial.println();
  Serial.println(longValue,HEX);
  //Serial.println(highByte(longValue), HEX);
  Serial.println("highByte(" + String(longValue, HEX) + ")=" + String(highByte(longValue), HEX));
  // display masked BYTES, one per line...
  for (uint8_t i = 0; i < 4; i++) {
    Serial.println(longValue & byteMask, HEX);
    longValue >>= 8;
  }
}

void loop() {}
