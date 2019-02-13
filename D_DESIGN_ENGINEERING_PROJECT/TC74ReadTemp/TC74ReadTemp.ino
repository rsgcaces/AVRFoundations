// PROJECT  :TC74ReadTemp 
// PURPOSE  :To illustrate support for I2C(TWI) devices through the use of Wire Library 
// DEVICE   :Arduino + TC74A0-5.0VAT
// AUTHOR   :C. D'Arcy
// DATE     :2019 02 08
// uC       :328p
// COURSE   :ICS3U
// STATUS   :Working
// REFERENCE:https://mail.rsgc.on.ca/~cdarcy/Datasheets/tC74.pdf
// REFERENCE:https://mail.rsgc.on.ca/~cdarcy/Datasheets/tC74.pdf

#include <Wire.h>         //request TWI(I2C) library support
#define TC74ADDRESS 0x48  //aka B01001000 
#define DURATION 1000     //(approximate) delay between readings 

void setup(){
  Serial.begin(9600);     //echo readings on the Serial Monitor 
  Wire.begin();           //configure the hardware SDA and SCL pins
}

void loop(){
  Wire.beginTransmission(TC74ADDRESS); //alert the device a request is imminent
  Wire.write(0);          //inform device that the master is interested in Register 0
  Wire.endTransmission(); //terminate transmission

  Wire.requestFrom(TC74ADDRESS, 1); //request 1 byte from the device with specified address
  while (Wire.available() == 0);    //wait for response
  int8_t celsius = Wire.read();     //read 1 byte from SDA buffer into a variable
  float fahrenheit = round(celsius * 1.8 + 32.0);  //convert from celsius to fahrenheit

  Serial.print(String(celsius)+"C,\t");           //echo data to the Serial Monitor
  Serial.print(String(fahrenheit,1)+"F\n");
  delay(DURATION);                                  //pause
}

