// PROJECT  :MCP4231
// PURPOSE  :Demonstrate SPI Library manipulation of the MCP4231 Digital Pot/Rheostat
// DEVICE   :Arduino + MCP4231 Digital Pot + DMM set to Voltage
// AUTHOR   :C. D'Arcy
// DATE     :2019 02 06
// uC       :328p
// COURSE   :ICS3U/ICS4U
// STATUS   :Working
// REFERENCE:https://mail.rsgc.on.ca/~cdarcy/Datasheets/MCP4231.pdf
// REFERENCE:https://www.arduino.cc/en/Reference/SPISettings
// NOTES    :MCP4231 Datasheet: up to 10MHz SCK
//          :Connect a DMM to the P0W Pin to watch potential (DCV) change
#include <SPI.h>            // include the SPI library of course
SPISettings mySettings(10000000, MSBFIRST, SPI_MODE0);
//------------MCP4231 Parameters------------------------------
#define WRITE B00000000     //Set Command (MOSI)
#define INCR  B00000100     //Increment Command
#define DECR  B00001000     //Decrement Command
#define READ  B00001100     //Get Command (MISO)
#define REG0  B00000000     //Register 0 Write command
#define REG1  B00010000     //Register 1 Write command
#define LIMIT 127           //Maximum value for (7-bit) MCP4231
//------------Code Variables----------------------------------
uint8_t data;               //value written to the MCP4231
uint8_t res;                //value read back from the MCP4231
int8_t  delta = -1;         //amount to change the value written (up/down)

void setup() {
  Serial.begin(9600);       //Serial monitoring useful
  SPI.begin();              //Initialize SPI (sets SCK, MISO & MOSI for output)
  SPI.beginTransaction(mySettings);     //(optional) tailoring of SPI session settings
  pinMode(SS, OUTPUT);      //set the Slave Select pin (to /CS pin of MCP4231) as an output
}


void loop() {
  SPIWrite(SS, REG0 | WRITE, data);       //Each iteration sets and gets a new value
  Serial.print("SET:" + String(data));    //display the value written...
  res = SPIRead(SS, REG0 | READ);         //let's read it back to confirm... 
  Serial.println("\tGET:" + String(res)); //display it for confirmation
  delay(64);                              //hmmmm...not to good...
  delta = (data == 0 || data == LIMIT) ? -delta : delta;  //time to change direction?
  data += delta;                          //update value to be written
}

void SPIWrite(uint8_t slave, uint8_t command, uint8_t data) {
  digitalWrite(slave, LOW);   //Set the provided SS pin low
  SPI.transfer(command);      //Choose the register to write to
  SPI.transfer(data);         //Set the LED level [0,127]
  digitalWrite(slave, HIGH);  //Set the provided SS pin high again
}

uint8_t SPIRead(uint8_t slave, uint8_t command){
  digitalWrite(slave, LOW);       //Set the provided SS pin low
  SPI.transfer(command);          //Choose the register to write to
  uint8_t res = SPI.transfer(0);  //Send a dummy value to force a return
  digitalWrite(slave, HIGH);      //Set the provided SS pin high again
  return res;                     //Send the vlaue back to the caller
}

