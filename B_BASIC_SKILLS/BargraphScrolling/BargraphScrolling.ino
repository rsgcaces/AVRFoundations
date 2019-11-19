// PROJECT  :BargraphScrolling
// PURPOSE  :Introduction to 1D bitshifting animation technique on the Morland Bargraph
// COURSE   :ICS3U
// AUTHOR   :C. D'Arcy
// DATE     :2019 11 19
// MCU      :328p/84/85/...
// STATUS   :? Working
// REFERENCE:http://darcy.rsgc.on.ca/ACES/TEI3M/BargraphScrolling.html
//predefines for Shift Register control...
#define clockPin
#define dataPin
#define latchPin
// animation variables...replace 0s with something meaningful
uint32_t buff  = 0;
uint16_t scrollSpeed = 0;
uint8_t count  = 0;

void setup() {
  // set pin states and any other ont-time initializations...
}

void loop() {
  //display the frame...
  //shiftOut(dataPin, clockPin, MSBFIRST, ? );
  // generate a rising edge on latch signal...
  // digitalWrite(latchPin, ? );
  // digitalWrite(latchPin, ? );

  // control animation speed...
  delay(scrollSpeed);

  // update frame...
  //  count = ;
  //  buff = ;

}
