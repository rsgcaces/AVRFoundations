// PROJECT  :BTSlaveBiColor
// PURPOSE  :Utility to responds to Master's request to display a color on its Bicolor LED
// DEVICE   :2 Arduinos + 2 HC-05 Transceivers + Bicolor LED
// AUTHOR   :C. D'Arcy
// DATE     :2019 03 28
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
uint8_t red = 12;           //when this pin high, should show Red
uint8_t green = 13;         //when this pin high, should show Green

void setup() {
  Serial.begin(9600);     //use the hardware UART for the Serial Monitor
  while (!Serial);        //wait for serial port to connect
  // set the data rate for the SoftwareSerial port
  chat.begin(38400);      //HC-05 fixed
  delay(1000);            //
  Serial.println("Slave ready...");
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  showRed();              //confirm functionality
  delay(2000);
  showGreen();
  delay(2000);
  showOff();
}

void showRed() {
  digitalWrite(red, HIGH);
  digitalWrite(green, LOW);

}
void showGreen() {
  digitalWrite(red, LOW);
  digitalWrite(green, HIGH);
}
void showOff() {
  digitalWrite(red, LOW);
  digitalWrite(green, LOW);
}

void loop() {
  if (chat.available()) {           //anything incoming?
    ch = chat.read();               //get the character request
    if (ch == 'R')                  //filter through a decision ladder
      showRed();
    else if (ch == 'G')
      showGreen();
    else
      showOff();
  }
}
