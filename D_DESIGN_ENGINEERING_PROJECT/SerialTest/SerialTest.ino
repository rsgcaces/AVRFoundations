// PROJECT  :SerialTest 
// PURPOSE  :Simple sketch to expose the difference between the println and write functions...
// DEVICE   :AVR 8 bit
// AUTHOR   :C. D'Arcy
// DATE     :2019 01 08
// uC       :328/84/85
// COURSE   :Prepared for 2018-2019 ICS3U
// STATUS   :Working
void setup() {
  Serial.begin(9600);
  Serial.println();
  Serial.write(65);           // displays the ASCII character equivalent of the number... 
  Serial.write(605);          // displays the ASCII character equivalent of the number... 
  Serial.println(65);         // display the number 65 followed by a CR (13) 
}

// Enter a digit from the Serial Monitor and examine the different responses
void loop() {
  while (Serial.available() == 0);
  uint8_t data = Serial.read();
  Serial.println(data);       //Echoes the number entered ??? 
//  Serial.write(data);       //Peel off the //, enter 65 and see
}
