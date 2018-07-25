// PROJECT  :Processing to RGB LED Display
// PURPOSE  :AVR Foundations: Black Boxes
// AUTHOR   :C. D'Arcy
// DATE     :2018 07 25
// uC       :328
uint8_t sequence[] = {B0000, B0001, B0100, B0101, B1000, B1001, B1100, B1101};
char index;
void setup() {
  Serial.begin(9600);
  DDRB = 0x0F;
}
void loop() {
  if (Serial.available()) { // If data is available to read,
    index = Serial.read();   // read and store it
    switch (index) {         //// use the input to index the RGB array
      case 'R': PORTB = sequence[1]; break;
      case 'G': PORTB = sequence[2]; break;
      case 'B': PORTB = sequence[4]; break;
      default: PORTB = sequence[0];
    }
  }
}
