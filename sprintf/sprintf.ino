// PROJECT  :Serial Input/Output
// PURPOSE  :First look at writing and reading ASCII characters to the Serial Monitor
// AUTHOR   :C. D'Arcy
// DATE     :2018 06 05
// uC       :328
// STATUS   :Working
// REF      :http://www.cplusplus.com/reference/cstdio/printf/
uint8_t ch;
char buff[8] = "ABCDEFGH";
void setup() {
  Serial.begin(9600); // initialize the serial stream to 9600 baud (bits/s)
}
void loop() {
  String(15, BIN).toCharArray(buff,8);
  Serial.println(buff);
 // sprintf(buff, "%8s", );
//  Serial.println(buff);
//  String st = buff + '\0';
  // String(15,BIN).toCharArray(buff,9);
  // sprintf(buff,"%d.",st,st.length());
  Serial.println(":");
  for (int i = 0; i < 9; i++)
    Serial.println(buff[i]);
  while (!Serial.available());    //wait for a character to be entered
  ch = Serial.read();             //ok, grab it...
  Serial.println((char)ch);       //cast (force) the data to appear as an ASCII Character
  Serial.println(ch);             //unmodified, it appears in decimal form
  Serial.println(ch, DEC);        //explicitly request presentation as a base 10 number
  String binary = "    1111";//String(ch,BIN);
  binary.replace(" ", "0");
  Serial.println(binary);
  // binary.toCharArray(buff,8);
  //  sprintf(buff,"%08s",String(ch,BIN));
  //  String(ch,BIN).toCharArray(buff,8);
  // Serial.println(buff);        //explicitly request presentation as a base 2 number
  Serial.println(ch, OCT);        //explicitly request presentation as a base 8 number
  Serial.println(ch, HEX);        //explicitly request presentation as a base 16 number
  while (true);                   //wait here...
}
