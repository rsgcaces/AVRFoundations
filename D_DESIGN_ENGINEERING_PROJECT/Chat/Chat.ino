// PROJECT  :Chat
// PURPOSE  :Utility to enable a conversation between ACES' Arduino users
// DEVICE   :2 Arduinos
// AUTHOR   :C. D'Arcy
// DATE     :2019 01 12
// uC       :328
// COURSE   :ICS3U
// STATUS   :Working
// REFERENCE:https://www.arduino.cc/en/Tutorial/SoftwareSerialExample
#include <SoftwareSerial.h>
SoftwareSerial mySerial(10, 11); // RX, TX
char ch;

void setup() {
  Serial.begin(9600);     //use the hardware UART for the Serial Monitor
  while (!Serial);        //wait for serial port to connect
  // set the data rate for the SoftwareSerial port
  mySerial.begin(4800);
  mySerial.println("Hello, world?");
  Serial.println("Ready to chat...");
}

void loop() {
  if (mySerial.available()) {       //anything incoming?
    Serial.write(mySerial.read());  //if so, display the oldest character in the incoming (queued) buffer
  }
  if (Serial.available())  {        //anything outgoing?
    Serial.print("Self:\t");        //if so, let's get started...
    while (Serial.available()) {    //transmit each of the outgoing characters... 
      ch = Serial.read();           //...to the software serial stream
      mySerial.write(ch);           //...
      Serial.write(ch);             //also, echo each character on my local Serial Monitor
    }
    mySerial.println();             //At end, transmit a newline (carriage return) character
    Serial.println();               //At end, also write a newline character to the local Serial Monitor
  }
}
