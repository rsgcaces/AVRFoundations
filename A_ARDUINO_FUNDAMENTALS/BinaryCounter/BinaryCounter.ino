// PROJECT  :BinaryCounter
// PURPOSE  :Confirms Morland Bargraph Appliance in various Arduino pin positions
// COURSE   :ICS3U
// AUTHOR   :C. D'Arcy
// MCU      :328p
// DATE     :2019 10 17
// STATUS   :Working
uint8_t clockPin = 13;                          //to pin 11 of '595
uint8_t powerPin = 12;                          //provide 5V power to '595
uint8_t dataPin = 11;                           //to pin 14 of '595
uint8_t latchPin = 10;                          //to pin 12 of '595
uint8_t outputEnable = 9;                       //to pin 13 of '595
//uint8_t groundPin = 7;                        //optional

uint8_t DURATION = 100;                         //frame delay interval
uint8_t n = 0;                                  //declare and initialize counter

void setup() {
  pinMode(clockPin, OUTPUT);                    //declare pins for
  pinMode(latchPin, OUTPUT);                    //  shift register signal lines
  pinMode(dataPin, OUTPUT);                     //  as outputs
  pinMode(powerPin, OUTPUT);                    //provide 5V power source
  digitalWrite(powerPin, HIGH);                 //  to '595 (not the best)
  pinMode(outputEnable, OUTPUT);                //'595 output resgisters only 
  digitalWrite(outputEnable, LOW);              //  visible if pin 13 kept low
//  pinMode(groundPin, OUTPUT);                 //optional ground pin 
//  digitalWrite(groundPin, LOW);               //  to '595 (not the best)
}
void loop() {
  digitalWrite(latchPin, LOW);                  //suppress external presentation
  shiftOut(dataPin, clockPin, MSBFIRST, n++);   //8-bit serial in...
  digitalWrite(latchPin, HIGH);                 //present contents of 8 internal registers
  delay(DURATION);                              //pause to confirm
}
