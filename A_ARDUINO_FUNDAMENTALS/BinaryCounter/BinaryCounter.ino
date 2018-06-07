// PROJECT  :Binary Counter
// PURPOSE  :To confirm T. Morland's Shift-Bar Device
// DATE     :2018 06 04
// STATUS   :Working
#define clockPin 9                              //
#define latchPin 10                             //
#define dataPin 11                              //
#define DURATION 500                            //
uint8_t n = 0;                                  //
void setup() {
  pinMode(clockPin, OUTPUT);                    //
  pinMode(latchPin, OUTPUT);                    //
  pinMode(dataPin, OUTPUT);                     //
  Serial.begin(9600);                           //
  while (!Serial);                              //
}
void loop() {
  digitalWrite(latchPin, LOW);                  //
  shiftOut(dataPin, clockPin, LSBFIRST, n++);   //
  digitalWrite(latchPin, HIGH);                 //
  delay(DURATION);                              //
}
