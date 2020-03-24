// PROJECT  :SPIvsShiftOutV2
// PURPOSE  :Demonstrates the similarity between software SPI (shiftOut) and hardware SPI (transfer)
// COURSE   :ICS3U
// AUTHOR   :C. D'Arcy
// DATE     :2020 03 24
// MCU      :328P
// STATUS   :Working
// REFERENCE:Hardware prototype to be as depicted on the right side of this image:
//          :http://darcy.rsgc.on.ca/ACES/TEI3M/images/MorlandV3Versatility.png 

#define HARDWARE_SHIFT false
#if HARDWARE_SHIFT
#include <SPI.h>
#endif

#define DURATION  500
uint8_t i = 1;

void setup() {
  pinMode(SS, OUTPUT);

#if HARDWARE_SHIFT
  SPI.begin();
#else
  pinMode(SCK, OUTPUT);
  pinMode(MISO, OUTPUT);
  pinMode(MOSI, OUTPUT);
#endif
}

void loop() {
  digitalWrite(SS, LOW);

#if HARDWARE_SHIFT
  SPI.transfer(i);
#else
  shiftOut(MOSI, SCK, MSBFIRST, i);
#endif

  digitalWrite(SS, HIGH);
  delay(DURATION);
  i = i ? i << 1 : 1;
}
