// PROJECT  :RxTest
// PURPOSE  :To display an incoming byte from TxTemp on a Morland Bargraph V3
// DEVICE   :Nano + ACES nRF Breakout Board + nRF24L01 + MBV3
// AUTHOR   :C. D'Arcy
// DATE     :Created: 2019 02 09. Updated: 2025 03 18.
// uC       :328p
// COURSE   :ICS3U-E
// STATUS   :Working (with TxTest)
// REFERENCE:http://darcy.rsgc.on.ca/ACES/TEI3M/CommunicationProtocols.html#RF1
//          :https://tmrh20.github.io/RF24/classRF24.html
//          :http://darcy.rsgc.on.ca/ACES/Datasheets/nRF24L01.pdf
#include <SPI.h>        //not necessary
#include <RF24.h>
#define CHANNEL 93      //value between 0 and 125 (2.400GHz to 2.525GHz)
uint8_t receivedData;   //for receiver to store the incoming byte
uint8_t clockPin = A1;  //aka D15 (PC1). MBV3(CLK)
uint8_t dataPin = A3;   //aka D17 (PC3). MBV3(DATA)
uint8_t latchPin = A4;  //aka D18 (PC4). MBV3(LATCH)

RF24 radio(9, 10);      //CE (Chip Enable/Disable), CSN(SS)
uint8_t addresses[][6] = {"1Node", "2Node"};  //pipe names (See Reference 2)

void setup() {
  Serial.begin(9600);   //invoke the local terminal window
  while (!Serial);      //wait for full activation
  configureBargraph();  //set up the Morland Bargraph V3

  radio.begin();        //invoke the radio
  radio.setPALevel(RF24_PA_LOW);//set low power amplification for close proximity
  radio.setChannel(CHANNEL);    //mutually agreeable frequency offset(2.400GHz to 2.525GHz)

  radio.openWritingPipe(addresses[1]);    //select ONE addresses to write to
  radio.openReadingPipe(1, addresses[0]); //receiver and transmit are reversed
  radio.startListening();                 //should be good to go...
}

void loop() {
  if (radio.available()) {                //anything to be read?
    radio.read(&receivedData, 1);         //grab the oldest data byte
    Serial.println(receivedData);         //local echo
    displayData(receivedData);            //display on the bargraph
  }
}

void displayData(uint8_t rec) {
  uint8_t data = (1 << ((rec >> 5)+1)) - 1;     //What do you think this does?
  digitalWrite(latchPin, LOW);                  //detach shift regs from storage registers
  shiftOut(dataPin, clockPin, LSBFIRST, data);  //next, shift bits in, serially....
  digitalWrite(latchPin, HIGH);                 //connect shift regs to storage registers
}

//Our Rx display device is a Morland Bargraph inserted into PC0-PC5
void configureBargraph() {
  pinMode(clockPin, OUTPUT);    //declare required Morland pins for output
  pinMode(latchPin, OUTPUT);    //wire GND, 5V and ENABLE to Supply Rails 
  pinMode(dataPin, OUTPUT);     //
}
