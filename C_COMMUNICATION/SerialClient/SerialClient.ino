// PROJECT  :SerialClient
// PURPOSE  :Introduction to UART Serial Communication between two Arduinos
//          :This client sketch requests blink behaviour on the Server Arduino
// DEVICE   :2 UNOs
// AUTHOR   :C. D'Arcy
// DATE     :2019 01 21
// uC       :*
// COURSE   :ICS3U
// STATUS   :Working
// REFERENCE:https://robotic-controls.com/learn/arduino/arduino-arduino-serial-communication
// NOTES    :Upload Examples>Communication>PhysicalPixel sketch to 'Server' Arduino
//          :BEFORE uploading this sketch to the 'Client' Arduino using
//          :your Sparkfun Pocket Programmer (Programmer: USBtinyISP+Upload Using Programmer)
//          :(USB programming of the UNO exploits the bootloader's reliance on serial communication to receive new code
//          :Existing connections to the Rx/Tx pins and will cause the USB upload to fail
//          :Programming through ICSP header avoids the problem.
//          :The downside is that the bootloader must be reflashed prior to returning to USB programming

#define ONDURATION 1000   //Time the LED should remain on 

void setup() {
  Serial.begin(9600);     //activate the UART peripheral
}

void loop() {
  Serial.write('H');      //request the server turn on its LED
  delay(ONDURATION);      //admire...
  Serial.write('L');      //request the server turn off its LED
  delay(ONDURATION >> 2); //OFF for 1/4 of the time ON (80% duty cycle)
}
