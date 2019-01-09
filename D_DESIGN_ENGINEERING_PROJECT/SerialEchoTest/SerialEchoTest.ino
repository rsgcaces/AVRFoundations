// PROJECT  :SerialTest
// PURPOSE  :Sample the behaviour of Serial Communication (UART peripheral) through the use
//          :of the print, println, write, and read functions of the Serial Class
// DEVICE   :AVR 8-bit
// AUTHOR   :C. D'Arcy
// DATE     :2019 01 09
// uC       :328/84/85
// COURSE   :Prepared for 2018-2019 ICS3U
// STATUS   :Working
// NOTE     :The Arduino UNO has only one Serial Channel (UART)
//          :The role of the Serial Monitor within the Arduino IDE is to give users the
//          :opportunity to interact (I/O) with the serial data
void setup() {
  Serial.begin(9600, SERIAL_8N1);  // set the communication speed and optional parameters
  Serial.println();     // put a carriage return (CR-13) in the channel
  Serial.write(65);     // displays the ASCII character equivalent of the number...
  Serial.write(605);    // displays the ASCII character equivalent of the low byte of the number...
  Serial.println(65);   // display the ASCII characters making up the number followed by a CR (13)
}

// Enter characters in the Serial Monitor and examine the different responses
void loop() {
  while (Serial.available() == 0);
  uint8_t data = Serial.read();
  //  Serial.println(data);       //describe the action this function performs
  Serial.write(data);             //switch to this function and explain the difference
}
