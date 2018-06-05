// PROJECT  :Regster-Level Blink 
// PURPOSE  :Behind-the-scenes look at AVR port manipulation 
// AUTHOR   :C. D'Arcy
// DATE     :2018 06 05
// uC       :328
// STATUS   :Working
// REFERENCE:http://mail.rsgc.on.ca/~cdarcy/Datasheets/RegisterSummary.pdf
void setup() {
  DDRB = 1<<PB5;      //pinMode(13,OUTPUT); 
}
void loop() {
  PORTB ^= (1<<PB5);  //digitalWrite(13,alternating HIGH and LOW);
  delay(1000);        //pause for 1000 ms (1 s)                     
}
