// PROJECT  :Dual7SegmentPOV
// PURPOSE  :Demonstrates PoV on ROHM's LB-602MK2 Dual 7 Segment Display
//          :by counting continuously
// COURSE   :ICS3U
// AUTHOR   :In class
// DATE     :2019 10 31
// MCU      :328p
// STATUS   :Not Working
// REFERENCE:https://www.youtube.com/watch?v=fQTR-yc7o8M

uint8_t clockPin = 13;    //best associated with SCK
uint8_t dataPin = 11;     //best associated with MOSI
uint8_t latchPin = 10;    //best associated with SS
uint8_t brightPin = 9;    //PWM for '595 brightness control on /OE pin

#define LEVEL 240;        //PWM: 0-full on, 255-full off (non-linear)
#define BASE 10           //decimal, for now..

uint8_t digitalMap[] = {
  //ABCDEFG.              //to be defined...
  0b00000000, //0
  0b00000000, //1
  0b00000000, //2
  0b00000000, //3
  0b00000000, //4
  0b00000000, //5
  0b00000000, //6
  0b00000000, //7
  0b00000000, //8
  0b00000000};//9

  void setup() {
    pinMode(clockPin, OUTPUT);
    pinMode(dataPin, OUTPUT);
    pinMode(latchPin, OUTPUT);
    pinMode(brightPin, OUTPUT);
  }

  void loop() {
  }
  
