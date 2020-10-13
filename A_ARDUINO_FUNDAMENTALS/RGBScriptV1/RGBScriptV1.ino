// PROJECT  :RGBScriptV1
// PURPOSE  :Explore Serial Input feature and some decision-making constructs
// COURSE   :ICS3U
// AUTHOR   :C. D'Arcy
// DATE     :2020 10 13
// MCU      :328p
// STATUS   :Working
// REFERENCE:http://www.asciitable.com/
uint8_t red = 3;          //LED pin assignments
uint8_t gnd = 4;          // "
uint8_t grn = 5;          // "
uint8_t blu = 6;          // "
uint8_t seconds;          // integral number of seconds to pause
uint8_t level = 10;       // PWM value used for all On (White)
char ch;                  // storage for ASCII value of characters in the Serial input stream
const char newLine = 10;  // ASCII value for the end-of-line character

void setup() {
  Serial.begin(9600);
  while (!Serial);

  // condition the port pins for Output
  pinMode(red, OUTPUT);
  pinMode(gnd, OUTPUT);
  pinMode(grn, OUTPUT);
  pinMode(blu, OUTPUT);
  digitalWrite(gnd, LOW);
}

void loop() {
  while (!Serial.available());      // pause, until serial input available...
  ch = Serial.read();               //OK, grab it...
  //what is it?
  if (ch >= '0' && ch <= '9') {     // is it a digit?
    seconds = ch - '0';             //
    Serial.println("Pausing for " + String(seconds) + " second(s).");
    delay(seconds * 1000);
  } else
    switch (ch) {
      case 'R': analogWrite(red, level); break;
      case 'r': digitalWrite(red, LOW); break;
      case 'G': analogWrite(grn, level); break;
      case 'g': digitalWrite(grn, LOW); break;
      case 'B': analogWrite(blu, level); break;
      case 'b': digitalWrite(blu, LOW); break;
      case 'O': analogWrite(red, level);
        analogWrite(grn, level); analogWrite(blu, level); break;
      case 'o': digitalWrite(red, LOW);
        digitalWrite(grn, LOW); digitalWrite(blu, LOW); break;
      case newLine: break;
      default: Serial.println("Unrecognizable Character...");
    }
}
