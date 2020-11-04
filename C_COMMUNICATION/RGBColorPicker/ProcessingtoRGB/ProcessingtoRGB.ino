// PROJECT  :Processing to RGB LED Display
// PURPOSE  :Responds to Processing RGBColorPicker characters 
//          : over hardware Serial Port to turn on a specific RGB LED
// AUTHOR   :C. D'Arcy
// DATE     :2020 11 04
// uC       :328p (UNO/Nano)
// GITHUB   :AVR Foundations/COMMUNICATIONS/RGBColorPicker/ProcessingtoRGB.ino
// NOTES    :Ensure the Processing application (RGBColorPicker.pde)
//          :is not running so this application has the use of the Serial port 
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
