// PROJECT  :SerialEchoTest
// PURPOSE  :Explore the behaviour of Serial Communication (UART peripheral) through the use
//          :of the print, println, write, and read functions of the Serial Class
// DEVICE   :8-bit AVR
// AUTHOR   :C. D'Arcy
// DATE     :2019 01 12
// uC       :328/84/85
// COURSE   :Prepared for 2018-2019 ICS3U
// STATUS   :Working
// REFERENCE:https://www.arduino.cc/reference/en/language/functions/communication/serial/
//          :http://www.asciitable.com/
// NOTES    :The Arduino UNO (ATmega328p) has only ONE (hardware) Serial Channel (UART)
//          :The role of the Serial Monitor within the Arduino IDE is to give users the
//          :opportunity to interpret and interact (I/O) with the serial data stream
void setup() {
  // Request the support of the AVR microcontroller's UART subsystem and set
  // the FOUR serial comm. parameters: baud rate, #bits, parity, and #stop bits
  Serial.begin(9600, SERIAL_8N1);
  Serial.println();     // places the 8-bit value of 13 (carriage return) into the serial stream
  Serial.write(65);     // places the 8-bit value (65) in the serial stream
  Serial.write(605);    // places only the LOW byte of the number in the serial stream, discarding the rest
  Serial.print('A');    // places the ASCII value of the character into the serial stream
  Serial.println(1234);   // println parses the integer into as many decimal (default) digits as required
  // and places the ASCII value of each (48-57) into the the serial stream
  // followed by the 8-bit value of 13 (carriage return)
}

// Upload the code and launch the Serial Monitor
//  1. Confirm the contents displayed from the setup function, and,
//  2. Experiment with different inputs, examining the echoed response
void loop() {
  while (Serial.available() == 0);
    uint8_t data = Serial.read();
  //Serial.println(data);         //describe the action this function performs
  Serial.write(data);         //switch to this function and explain the difference
}
