// PROJECT  :Serial Input/Output
// PURPOSE  :First look at writing and reading ASCII characters to the Serial Monitor
// AUTHOR   :C. D'Arcy
// DATE     :2018 06 05
// uC       :328
// STATUS   :Working
uint8_t ch = 150;
void setup() {
  Serial.begin(9600); // initialize the serial stream to 9600 baud (bits/s)
}
void loop() {
//  while (!Serial.available());    //wait for a character to be entered
//  ch = Serial.read();             //ok, grab it...
  Serial.println((char)ch);       //cast (force) the data to appear as an ASCII Character
  Serial.println(ch);             //unmodified, it appears in decimal form
  Serial.println(ch, DEC);        //explicitly request presentation as a base 10 number
  Serial.println(ch, BIN);        //explicitly request presentation as a base 2 number
  Serial.println(ch, OCT);        //explicitly request presentation as a base 8 number
  Serial.println(ch, HEX);        //explicitly request presentation as a base 16 number
  while (true);                   //wait here...
}
