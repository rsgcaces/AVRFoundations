// PROJECT  :ImproveMe 
// PURPOSE  :Students are asked to exercise their great coding skills
//           by making changes to this code 
// AUTHOR   :C. D'Arcy
// DATE     :YYYY MM DD
// uC       :328p
int reading;
void setup() {
  Serial.begin(9600);
}

void loop() {
  reading = analogRead(0);
  digitalWrite(latch,LOW);
  shiftOut(data,clk,LSBFIRST,reading);
  digitalWrite(latch,HIGH);
}
