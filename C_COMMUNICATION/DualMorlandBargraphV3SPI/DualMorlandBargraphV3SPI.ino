// PROJECT  :DualMorlandBargraphV3SPI
// PURPOSE  :Simple demonstation of multiple SPI peripherals 
// COURSE   :ICS3U
// DATE     :2020 12 27
// STATUS   :Working
// PHOTO    :http://darcy.rsgc.on.ca/ACES/TEI3M/2021/images/MBv3SPIBus.jpg
#include <SPI.h>
#define PER1 3                  // convenient for nano access to two MBv3s
#define PER2 2                  //
uint8_t pers[] = {PER1, PER2};  // pack 'em 
uint8_t numPers = sizeof(pers); // how many perpiherals in the package?
#define DURATION  100           // pause interval
#define SPRITE    0xC000        // value to be scrolled across multiple MBv3s
uint16_t n = SPRITE;            // initialize it ...

void setup() {
  for (uint8_t i = 0; i < numPers; i++)
    pinMode(pers[i], OUTPUT);
  SPI.begin();                  // start the SPI session  ...
}

void loop() {
  digitalWrite(pers[0], LOW);     // acquire/select the (first) peripheral 
  SPI.transfer(highByte(n));      // load the shift register
  digitalWrite(pers[0], HIGH);    // release the preipheral 
  digitalWrite(pers[1], LOW);     // now the second ...
  SPI.transfer(lowByte(n));
  digitalWrite(pers[1], HIGH);
  delay(DURATION);                // admire the pair for a moment
  n = n ? n >> 1 : SPRITE;        // update frame
}
