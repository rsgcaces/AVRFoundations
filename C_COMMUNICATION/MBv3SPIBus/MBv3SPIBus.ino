// PROJECT  :MBv3SPIBus
// PURPOSE  :Sample Demonstration of an SPI Bus using multiple MBvS ('595s)...
// COURSE   :ICS3U
// DATE     :2020 12 28
// STATUS   :Working
// PHOTO    :http://darcy.rsgc.on.ca/ACES/TEI3M/2021/images/MBv3SPIBus.jpg
#include <SPI.h>
#define PER0 2                        // convenient for nano access to multiple MBv3s
#define PER1 3                        // "
#define PER2 4                        // "
uint8_t pers[] = {PER0, PER1, PER2};  // pack 'em
uint8_t numPers = sizeof(pers);       // how many perpiherals on the Bus?
uint64_t sprite;                      // value to be scrolled across multiple MBv3s
uint64_t n = 0;                       // current state of sprite data...
#define DURATION  50                  // frame delay

void setup() {
  for (uint8_t i = 0; i < numPers; i++)
    pinMode(pers[i], OUTPUT);
  sprite = (uint64_t) 0x3<<(numPers<<3);      // ensures initial data is just off-camera 
  SPI.begin();                                // start the SPI session  ...
}

void loop() {
  n = n ? n >> 1 : sprite;                    // update frame data
  for (uint8_t i = 0; i < numPers; i++) {     // load the full Bus frame in this loop
    digitalWrite(pers[i], LOW);               // address the Bus peripheral ...
    SPI.transfer((uint8_t)(n >> (i << 3)));   // ... load its shift register ...
    digitalWrite(pers[i], HIGH);              // ... release the preipheral.
  }
  delay(DURATION);                            // admire the Bus state for a moment
}
