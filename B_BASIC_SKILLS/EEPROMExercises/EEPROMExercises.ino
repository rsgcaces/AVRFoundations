// PROJECT  :EEPROMExercises
// PURPOSE  :ICS3U introductory walkthrough of some commom EEPROM usages
// COURSE   :ICS3U
// AUTHOR   :C. D'Arcy
// DATE     :2019 10 22
// MCU      :328p
// STATUS   :(Soon to be) Working

// Do not forget to add this library in all sketches
#include <EEPROM.h>

void setup() {
  Serial.begin(9600);
  while (!Serial);
  // 1. display the size of the 328p EEPROM (available number of bytes)
  // Hint: look for the definition in the iom328p.h file of predefined constants
  Serial.println("There are 0x" + String(E2END + 1, HEX) + " available byte addresses in EEPROM");
  // 2. Read and display the contents of EEPROM to the Serial Monitor in decimal
  // in the form: [ADDR]VALUE as in,
  //[0000]0
  //[0001]0
  // ...
  //[0214]123
  //...
  //[1023]0
  //showIt();
  // 3. Any observations made from the previous output?

  // 4. Move your previous loop solution in a function (call it showIt())
  //    because we'd like to reuse it without copying it every time we need it

  // 5. Confirm your function works by calling it!

  // 6. Dumping the ENTIRE contents of EEPROM to the Serial Monitor is not
  //    something we would normally do (typically we would just want a range)
  //    Modify your showIt() function to accept two parameters (from and to)
  //    and use these to define the lower and upper bounds (inclusive) of your loop

  // 7. Fill the EEPROM address from 300 to 500 with a value of 17 before calling
  //    your modified showIt() function to confirm...

  // 8. Fill the EEPROM address from 65 to 90 inclusive with 0x0F (15 decimal). Confirm.

  // 9. Using the segment order ABCDEFG. define an array of 10 binary constants representing
  //    the active segments of each of the decimal digits.

  //10. Write the elements of the previous array to EEPROM using the ASCII value
  //    of the digits as its address.
}

void loop() {
  //nothing to do
}
