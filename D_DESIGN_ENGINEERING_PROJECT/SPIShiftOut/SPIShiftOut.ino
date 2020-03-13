// PROJECT  :SPIShiftOut
// PURPOSE  :To highlight the overlap between the speed of hardware SPI and the flexibility
//          :of software shiftOut by transmitting a byte to a 595 Shift Register
// DEVICE   :Arduino UNO + Morland Bargraph V3 (insert appliance as shown)
// AUTHOR   :C. D'Arcy
// DATE     :2020 02 12
// uC       :328p
// COURSE   :ICS3U/ICS4U
// STATUS   :Working
// REFERENCE:http://darcy.rsgc.on.ca/ACES/TEI3M/images/SPIConcept.png
//          :http://darcy.rsgc.on.ca/ACES/TEI3M/SPICommunication/images/SPIvsShiftOut.png
// NOTES    :Hardware SPI (fast) and software shiftOut (flexible) are not identical but 
//          :strikingly similar in their digital waveform behaviour.
//          :This code highlights and contrasts the differences between their usage
//          :on familiar hardware. Explore which one serves each of your applications better.
#include <SPI.h>
#define OENABLE 9             //MBV3 pin for Output Enable
#define VALUE 0x18            //sample data to upload for confirmation and comparison

void setup() {
  pinMode(OENABLE, OUTPUT);   //595's output enable pin must be pulled
  digitalWrite(OENABLE, LOW); //LOW to display its storage registers
  pinMode(MISO, OUTPUT);      //No need for MISO(12) in this example...
  digitalWrite(MISO, HIGH);   //...instead, use as a temporary 5V source
  //comment out one or the other...
  softwareShiftOut();         //use flexible shiftOut function
  //hardwareShiftOut();       //use fast SPI
}

void softwareShiftOut() {     //Exploit predefines in pins_arduino.h
  pinMode(SCK, OUTPUT);       //System Clock (pin 13)
  pinMode(MOSI, OUTPUT);      //Master Out Slave In (pin 11)
  pinMode(SS, OUTPUT);        //Slave Select (pin 10)
  shiftOut(MOSI, SCK, MSBFIRST, VALUE); //No control over transfer parameters
  digitalWrite(SS, LOW);      //create a rising edge on the Slave Select pin
  digitalWrite(SS, HIGH);     //to transfer bits from shift to storage registers
}

void hardwareShiftOut() {
  //Initializes the SPI bus setting SCK, MOSI, and SS to outputs,
  SPI.begin();                //pulls SCK and MOSI low, and SS high. Default: MSBFIRST
  //digitalWrite(SS, LOW);    //true SPI requires Slave Select LOW to identify specfic target
  SPI.transfer(~VALUE);       //invert the output for ease of interpretation
  digitalWrite(SS, LOW);      //pull Slave Select LOW to identify target device
  digitalWrite(SS, HIGH);     //release target device
  SPI.end();                  //disables SPI Bus (leaving pin modes unchanged)
}

void loop() {}
