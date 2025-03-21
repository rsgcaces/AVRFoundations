// PROJECT  :TxTest
// PURPOSE  :To continually transmit a byte-scaled reading from a trim pot
// DEVICE   :2x(Arduino + nrF24L01)
// AUTHOR   :C. D'Arcy
// DATE     :2019 02 09. Confirmed: 2025 03 18.
// uC       :328p (Nano)
// COURSE   :ICS3U
// STATUS   :Working (with RxTest)
// REFERENCE:http://darcy.rsgc.on.ca/ACES/TEI3M/CommunicationProtocols.html#RF1
//          :https://tmrh20.github.io/RF24/classRF24.html
//          :http://darcy.rsgc.on.ca/ACES/Datasheets/nRF24L01.pdf

#include <SPI.h>        //not necessary
#include <RF24.h>
RF24 radio(9, 10);      //CE (Chip Enable/Disable), CSN(SS)
byte addresses[][6] = {"1Node", "2Node"};
#define CHANNEL 93      //Any value between 0 and 125 (2.400GHz to 2.525GHz)
//Trim pot details
uint8_t potVal;         //byte-scaled value read from the potentiometer
uint8_t APin = 14;      //aka A0
uint8_t CPin = 15;      //aka A1
uint8_t BPin = 16;      //aka A2

void setup() {
  Serial.begin(9600);             //log the activity
  configurePotentiometer();       //set the pot up as a voltage divider on PORT C
  
  radio.begin();                  //invoke the radio object
  radio.setPALevel(RF24_PA_LOW);  //close range so minimum power sufficient
  radio.setChannel(CHANNEL);      //Tx and Rx communication on same channel
  //https://nrf24.github.io/RF24/classRF24.html
  radio.openWritingPipe(addresses[0]);    //Transmit assumes these pipes
  radio.stopListening();
}

void loop() {
  potVal = analogRead(CPin) >> 2;         //obtain a pot reading [0,1023] and scale it to [0.255]
  radio.write(&potVal, sizeof(int8_t));   //transmit the scaled byte 
  Serial.println(potVal);                 //echo to serial monitor
}

//Our Tx data is acquired by reading a trim pot inserted into A0-A2 (PC0-2)
void configurePotentiometer() {
  pinMode(APin, OUTPUT);        //declare outerlegs for output
  pinMode(CPin, INPUT);         //reading from the voltage divider
  pinMode(BPin, OUTPUT);        //
  digitalWrite(APin, HIGH);     //establish full potential difference...
  digitalWrite(BPin, LOW);      //...on outer legs of the pot
}
