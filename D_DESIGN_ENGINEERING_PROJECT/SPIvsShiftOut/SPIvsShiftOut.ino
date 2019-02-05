// PROJECT  :SPIvsShiftOut
// PURPOSE  :A slight code variation (for flexibility) from our previous SPIShiftOut sketch 
// DEVICE   :Arduino + Morland Bargraph
// AUTHOR   :C. D'Arcy
// DATE     :2019 02 02
// uC       :328/84/85
// COURSE   :ICS3U/ICS4U
// STATUS   :Working
// REFERENCE:https://shift-register.org/2017/spi-vs-shiftout-on-arduino-and-attiny
// NOTES    :Simple test program to shift out some bits to measure the difference between
//          :different Atmel chips and SPI vs. shiftOut()
#include <SPI.h>
#define RCLK_PIN SS // latching pin for the shift registers to show values at their outputs
#define DATA_PIN MOSI
#define CLK_PIN  SCK
/* for attiny85
  #define RCLK_PIN 4 // latching pin for the shift registers to show values at their outputs
  #define DATA_PIN 1
  #define CLK_PIN  2
*/
// pick one of these
//#define SHIFTMODE
#define SPIMODE

void setup() {
  pinMode(RCLK_PIN, OUTPUT);
#ifdef SHIFTMODE
  pinMode(DATA_PIN, OUTPUT);
  pinMode(CLK_PIN, OUTPUT);
  shiftOut(DATA_PIN, CLK_PIN, LSBFIRST, 0);
#endif
#ifdef SPIMODE
  SPI.begin();
  SPI.beginTransaction(SPISettings(16000000, LSBFIRST, SPI_MODE0));
#endif
}

uint8_t num = 0x00;
void loop() {
  digitalWrite(RCLK_PIN, LOW);
#ifdef SHIFTMODE
  shiftOut(DATA_PIN, CLK_PIN, LSBFIRST, num);
#endif
#ifdef SPIMODE
  SPI.transfer(num);
#endif
  digitalWrite(RCLK_PIN, HIGH);
  num++;
  delay(20);
}
