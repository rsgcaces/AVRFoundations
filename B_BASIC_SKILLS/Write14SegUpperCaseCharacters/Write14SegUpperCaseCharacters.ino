// PROJECT  :Write14SegUpperCaseCharacters
// PURPOSE  :Writes a lookup table of 14 segments (word) for the uppercase ASCII
//          :characters to EEPROM 
// COURSE   :ICS3U
// AUTHOR   :C. D'Arcy
// DATE     :2019 10 19
// MCU      :328p
// STATUS   :Working
// REFERENCE:http://darcy.rsgc.on.ca/ACES/TEI3M/1920/Tasks.html#PoV

#include <EEPROM.h>       //requires the support of this Arduino library

// Define the 14-Segment Uppercase Letter LookUp Table...
uint16_t segmentMap[] = {
  //ABCDEFGHJKLMNP__ :Segment order
  0b0110000110010000,  //A or 0x6190 or O
  0b1111001010100000,  //B or 0xF2A0 or O
  0b1001110000000000,  //C or 0x9C00 or O
  0b1111001000100000,  //D or 0xF220 or O
  0b1001110010001000,  //E or 0x9C88 or O
  0b1000110010001000,  //F or 0x8C88 or O
  0b1011110010000000,  //G or 0xBC80 or O
  0b0110110010001000,  //H or 0x or O
  0b1001001000100000,  //I or 0x or O
  0b0111100000000000,  //J or 0x or O
  0b0000110101001000,  //K or 0x or O        
  0b0001110000000000,  //L or 0x   or O
  0b0110110100000100,  //M or 0x   or O
  0b0110110001000100,  //N or 0x   or O
  0b1111110000000000,  //O or 0x   or O
  0b1100110010001000,  //P or 0x   or O
  0b1111110001000000,  //Q or 0x   or O
  0b1100110011001000,  //R or 0x   or O
  0b1011010010001000,  //S or 0x   or O
  0b1000001000100000,  //T or 0x   or O
  0b0111110000000000,  //U or 0x   or O
  0b0000110100010000,  //V or 0x   or O
  0b0110110001010000,  //W or 0x   or O
  0b0000000101010100,  //X or 0x   or O
  0b0000000100100100,  //Y or 0x   or O
  0b1001000100010000   //Z or 0x   or O
};
uint8_t sizeMap = sizeof(segmentMap) >> 1;  //number of entries in the LUT

//Compiler (preprocessor) directives (allows for readable case labels!)
//#define DURATION 4
//uint16_t segments;       // the LUT entry returned from the EEPROM read operation
//uint8_t clockPin = 13;
//uint8_t dataPin = 12;
//uint8_t latchPin = 11;
//uint8_t selectPin = 14;

void setup() {
  Serial.begin(9600);       //requires the support of the Serial Monitor
  while (!Serial);          //pause while the Serial monitor initializes itself
  Serial.println("Note: Highest accessible EEPROM Address: " + String(E2END, DEC));

  //flash the LUT to EEPROM...(once, since EEPROM is non-volatile)
  //Note: The ASCII value is used as the EEPROM address for efficiency
  for (uint8_t i = 0; i <= sizeMap; i++) { //iterate through the LUT array
    EEPROM.write('A' + i << 1, lowByte(segmentMap[i])); //  writing the segment data to EEPROM
    EEPROM.write(('A' + i << 1) + 1, highByte(segmentMap[i]));
  }
  
  //Echo the first few to the Serial Monitor for confirmation...
  for (uint8_t ch = 'A'; ch <= 'C'; ch++) {
    Serial.print(EEPROM.read((ch << 1) + 1), BIN);
    Serial.println(EEPROM.read(ch << 1), BIN);
  }
}

void loop() {
}
