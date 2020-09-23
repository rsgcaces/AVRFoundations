// PROJECT  :DebounceTest
// PURPOSE  :Exploration of Mechanical Button Reading
// COURSE   :ICS3U
// AUTHOR   :C. D'Arcy
// DATE     :2020 09 23
// MCU      :328p
// STATUS   :Working
// REFERENCE:http://darcy.rsgc.on.ca/ACES/PCBs/images/DebounceSchematic.png
uint8_t buttonPin = 2;            // pin to read button activity
uint8_t lastState = LOW;          // define the initial state
uint8_t currentState = lastState; // track the previous button state

void setup() {
  Serial.begin(9600);
  Serial.print("Initial State: ");
  //ternary statement is a useful replacement for simple ifs
  Serial.println(currentState ? "HIGH" : "LOW");
}

void loop() {
  currentState = digitalRead(buttonPin);            //read the button state
  if (currentState != lastState) {                  //has it changed?
    Serial.println(currentState ? "HIGH" : "LOW");  //say so
    lastState = currentState;                       //preserve the new state
  }
}
