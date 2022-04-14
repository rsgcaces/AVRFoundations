// PROJECT  :SPIvsShiftOutV2
// PURPOSE  :Demonstrates similarity between ShiftOut(software) vs SPI (hardware)
// COURSE   :ICS3U
// AUTHOR   :C. D'Arcy
// DATE     :2022 04 14
// MCU      :328P
// STATUS   :Working
// REFERENCE:Hardware prototype to be as depicted on the right side of this image:
//          :http://darcy.rsgc.on.ca/ACES/TEI3M/images/MorlandV3Versatility.png 
// NOTES    :Introduces additional compiler directives(#if, #else, #endif, etc.)
//          : to customize (minimize) code footprint

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
  digitalWrite(SS, LOW);              //select the target device
  
#if HARDWARE_SHIFT                    //apply the desired transfer protocol...
  SPI.transfer(i);                    // hardware? (faster)
 #else
  shiftOut(MOSI, SCK, MSBFIRST, i);   // software? (slower, but more flexible?)
#endif

  digitalWrite(SS, HIGH);             //complete the transfer by releasing the device
  delay(DURATION);                    //pause and admire....
  i = i ? i << 1 : 1;                 //continue
}
