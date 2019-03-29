// PROJECT  :BTMasterBiColorLED
// PURPOSE  :Utility to request Slace to show (R)ed, (G)reen or neither(X) on its Bicolor LED 
// DEVICE   :2 Arduinos + 2 HC-05 Transceivers
// AUTHOR   :C. D'Arcy
// DATE     :2019 03 29
// uC       :328
// COURSE   :ICS3U
// STATUS   :Not Working 
// REFERENCE:Be sure to have one HC-05 configure as master and one as slave. Great video...
//          :https://www.youtube.com/watch?v=BXXAcFOTnBo
//          :https://www.arduino.cc/en/Tutorial/SoftwareSerialExample
//          :https://www.instructables.com/id/Simple-Chat-Program-with-Arduino-Uno/
// NOTES    :Receives from the hardware serial, sends to hardware & software serial.
//          :Receives from software serial, sends to hardware serial

#include <SoftwareSerial.h>
SoftwareSerial chat(6, 7); // RX(Arduino D6 to BT TX), TX (Arduino D7 to BT RX through V.D.)
char ch;

void setup() {
  Serial.begin(9600);     //use the hardware UART for the Serial Monitor
  while (!Serial);        //wait for serial port to connect
  // set the data rate for the SoftwareSerial port
  chat.begin(38400);      //HC-05 fixed
  delay(1000);            //
  Serial.println("Master ready...");
}

void loop() {
  chat.write('R');
  delay(2000);
  chat.write('G');
  delay(2000);
  chat.write('X');
  delay(2000);
}
