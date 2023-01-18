// PROJECT  :MBv3SPIBus4Peris
// PURPOSE  :Sample Demonstration L-to-R 1D Scrolling of an SPI Bus
//          :on a bank of 4 MBv3s ('595s)...
//          :Updated version of 2020 MBv3SPIBus.ino of 3 MBv3 Peripherals
// COURSE   :ICS3U
// DATE     :2022 12 27
// STATUS   :Working!
// PHOTO    :http://darcy.rsgc.on.ca/ACES/TEI3M/SPICommunication/images/MBV3SPIBus4.jpg
#include <SPI.h>                     //
#include <TimerOne.h>                //timed animation
#define FRAMEDELAY 50000             //

#define PER3 5                        // convenient for nano access to multiple MBv3s
#define PER2 4                        // "
#define PER1 3                        // "
#define PER0 2                        // "
uint8_t pers[] = {PER0, PER1, PER2, PER3};  // pack 'em in an array for ease of use
uint8_t numPers = sizeof(pers);       // how many perpiherals on the Bus?
uint64_t sprite = 0x3;                // image to be animated across multiple MBv3s
uint64_t n = 0;                       // current state of sprite data...
volatile boolean triggered = false;   //

void setup() {
  for (uint8_t i = 0; i < numPers; i++)
    pinMode(pers[i], OUTPUT);

  n = sprite << (numPers << 3);       // guarantee sprite placed out of view, stage left
  SPI.begin();                        // start the SPI session  ...
  Timer1.initialize(FRAMEDELAY);
  Timer1.attachInterrupt(ISR_UpdateSprite);
}

void ISR_UpdateSprite() {
  triggered = true;
}

void loop() {
  for (uint8_t i = 0; i < numPers; i++) {     // load the full Bus frame in this loop
    digitalWrite(pers[i], LOW);               // address the Bus peripheral ...
    SPI.transfer((uint8_t)(n >> (i << 3)));   // ... load with its byte segment ...
    digitalWrite(pers[i], HIGH);              // ... release the peripheral
  }

  if (triggered) {                            // does frame require updating?
    triggered = false;                        // prepare for the next timer interrupt
    n = n ? n >> 1 : sprite << (numPers << 3);// update/restore frame data
  }
}
