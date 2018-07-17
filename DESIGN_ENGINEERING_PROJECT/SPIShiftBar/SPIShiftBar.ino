// PROJECT  :SPI Shift Register Control (T. Morland's Shift-Bar Register
// PURPOSE  :Demonstration of hardware-level communication (more efficient) 
// AUTHOR   :C. D'Arcy
// DATE     :2018 07 16
// uC       :328
// STATUS   :Working
// REFERENCE:https://core-electronics.com.au/tutorials/spi-arduino-tutorial.html
#include <SPI.h>
#define DELAY 100
uint8_t shcp = 13;      //PB5
uint8_t stcp = 12;      //PB4
uint8_t ser = 11;       //PB3
uint8_t gnd = 10;       //PB2
uint8_t vcc = 9;        //PB1
uint8_t data = 1;
void setup() {
  Serial.begin(9600);
  SPI.begin();
  SPI.setBitOrder(LSBFIRST);
  DDRB = B00111110;
  PORTB = 1 << PB1;
}
void loop() {
  DDRB &= ~(1 << PB4);  //pull latch low
  SPI.transfer(data);   //
  DDRB |= 1 << PB4;
  delay(DELAY);
  data = data == 128 ? 1 : data << 1;
}

