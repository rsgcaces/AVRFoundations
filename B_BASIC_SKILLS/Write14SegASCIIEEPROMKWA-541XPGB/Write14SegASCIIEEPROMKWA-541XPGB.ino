// PROJECT  :Write14SegASCIIEEPROMKWA-541XPGB
// PURPOSE  :Writes a lookup table of 14 segments (word) for the uppercase ASCII
//          :characters to EEPROM 
// COURSE   :ICS3U
// AUTHOR   :C. D'Arcy
// DATE     :2020 10 22
// MCU      :328p
// STATUS   :? Working (untested)
// REFERENCE:http://darcy.rsgc.on.ca/ACES/TEI3M/1920/Tasks.html#PoV
// REFERENCE:Segment Map:
//           http://darcy.rsgc.on.ca/ACES/TEI3M/images/16SegmentCharMap.png
#include <EEPROM.h>       //requires the support of this Arduino library

// Define the 14-Segment Uppercase Letter LookUp Table optimized for:
// https://mail.rsgc.on.ca/~cdarcy/Datasheets/KWA-541CPGB.pdf
uint16_t segmentMap[] = {
  //Pins:     18 17  -  15 14 13 12 - 10 | 1  2  3  4  5  6  7  8  9
  //Segments: F   H      J  K G1  A    B   E L  nc  M  N  G2 D dp  C
  //FHJKABELMNDC0000   // template
  0b1000111000010000,  //A or 0x8E10 or O107020
  0b0000000000000000,  //B or 0x? or O?
  0b0000000000000000,  //C or 0x? or O?
  0b0000000000000000,  //D or 0x? or O?
  0b0000000000000000,  //E or 0x? or O?
  0b0000000000000000,  //F or 0x? or O?
  0b0000000000000000,  //G or 0x? or O?
  0b0000000000000000,  //H or 0x or O
  0b0000000000000000,  //I or 0x or O
  0b0000000000000000,  //J or 0x or O
  0b0000000000000000,  //K or 0x or O        
  0b0000000000000000,  //L or 0x or O
  0b0000000000000000,  //M or 0x or O
  0b0000000000000000,  //N or 0x or O
  0b0000000000000000,  //O or 0x or O
  0b0000000000000000,  //P or 0x or O
  0b0000000000000000,  //Q or 0x or O
  0b0000000000000000,  //R or 0x or O
  0b0000000000000000,  //S or 0x or O
  0b0000000000000000,  //T or 0x or O
  0b0000000000000000,  //U or 0x or O
  0b0000000000000000,  //V or 0x or O
  0b0000000000000000,  //W or 0x or O
  0b0000000000000000,  //X or 0x or O
  0b0000000000000000,  //Y or 0x or O
  0b0000000000000000   //Z or 0x or O
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
