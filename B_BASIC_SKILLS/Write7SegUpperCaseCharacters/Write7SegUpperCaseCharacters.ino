// PROJECT  :Write7SegUpperCaseCharacters
// PURPOSE  :Writes a lookup table (LUT) of
//          :  7-Segment Uppercase Letter Segment Maps to EEPROM
// COURSE   :ICS3U
// AUTHOR   :C. D'Arcy
// DATE     :2019 10 23
// MCU      :328p
// STATUS   :Working
// REFERENCE:https://www.arduino.cc/en/Reference/EEPROM
//          :http://darcy.rsgc.on.ca/ACES/images/7SegmentASCIILetters.gif
//          :https://www.arduino.cc/reference/en/language/variables/constants/integerconstants/

#include <EEPROM.h>       //requires the support of this Arduino library

// Define the 7-Segment Uppercase Letter LookUp Table...
uint8_t segmentMap[] = {   //Segment order: ABCDEFG.
  B11101110,  //A or 0xEE or O356
  B00111110,  //B or 0x3E or O076
  B10011100,  //C or 0x9C or O234
  B01111010,  //D or 0x7A or O172
  B10011110,  //E or 0x9E or O236
  B10001110,  //F or 0x8E or O216
  B10111100,  //G or 0xBC or O274
  B00101110,  //H or 0x2E or O056
  B01100000,  //I or 0x60 or O140
  B01111000,  //J or 0x78 or O170
  B00000000,  //K or 0x   or O        // you complete the rest...
  B00000000,  //L or 0x   or O
  B00000000,  //M or 0x   or O
  B00000000,  //N or 0x   or O
  B00000000,  //O or 0x   or O
  B00000000,  //P or 0x   or O
  B00000000,  //Q or 0x   or O
  B00000000,  //R or 0x   or O
  B00000000,  //S or 0x   or O
  B00000000,  //T or 0x   or O
  B00000000,  //U or 0x   or O
  B00000000,  //V or 0x   or O
  B00000000,  //W or 0x   or O
  B00000000,  //X or 0x   or O
  B00000000,  //Y or 0x   or O
  B00000000   //Z or 0x   or O
};
uint8_t sizeMap = sizeof(segmentMap);    //numner of entries in the LUT

//Compiler (preprocessor) directives (allows for readable case labels!)
#define newLine 10      // Serial input line terminator       
#define terminal '0'    // session terminator

char letter = 'A';      // initialization is seldom a bad idea
uint8_t segments;       // the LUT entry returned from the EEPROM read operation

void setup() {
  Serial.begin(9600);                     //requires the support of the Serial Monitor
  while(!Serial);                         //pause while the Serial monitor initializes itself
  Serial.println("Note: Highest accessible EEPROM Address: "+String(E2END,DEC));
  //flash the LUT to EEPROM...(once, since EEPROM is non-volatile!)
  //Note: The ASCII value is used as the EEPROM address for efficiency
  for (uint8_t i = 0; i <= sizeMap; i++)  //iterate through the LUT array
    EEPROM.write('A' + i, segmentMap[i]); //  writing the segment data to EEPROM
}

void loop() {
  //Request user input of an uppercase letter
  if (letter != newLine)                  // don't repeat the prompt for newLine
    Serial.println("\nEnter a single uppercase letter (0 to end)...");
  while (!Serial.available());            //wait for user input
  letter = Serial.read();                 //read the next character in the serial stream
  switch (letter) {                       //hmmm...what is it? Respond accordingly
    case terminal: Serial.println("Session terminated."); while (true);
    case newLine : break;
    default: letter = constrain(letter, 'A', 'Z');
      segments = EEPROM.read(letter);
      Serial.println("Letter\t\t:" + String(letter));
      Serial.println("Decimal\t\t:" + String(letter, DEC));
      Serial.println("Binary\t\t:" + String(letter, BIN));
      Serial.println("Octal\t\t:" + String(letter, OCT));
      Serial.println("Hexadecimal\t:" + String(letter, HEX));
      Serial.println("Segments\t:ABCDEFG.=" + String(segments, BIN));
  }
}
