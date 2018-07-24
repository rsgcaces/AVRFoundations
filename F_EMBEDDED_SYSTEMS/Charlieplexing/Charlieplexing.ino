// PROJECT  :Charlieplexing Example with 3 pins
// PURPOSE  :AVR Foundations Workbook
struct state {
  uint8_t DDR;
  uint8_t PORT;
};
uint8_t pins [] = {8, 9, 10};
state L = {OUTPUT, LOW};
state H = {OUTPUT, HIGH};
state Z = {INPUT, HIGH};
state LEDs[6][3] = {{H, L, Z}, {H, Z, L}, {L, H, Z}, {Z, H, L}, {L, Z, H}, { Z, L, H}};
uint8_t led = 0;
void setup() {}
void loop() {
  pinMode(pins[0], LEDs[led][0].DDR);
  pinMode(pins[1], LEDs[led][1].DDR);
  pinMode(pins[2], LEDs[led][2].DDR);
  digitalWrite(pins[0], LEDs[led][0].PORT);
  digitalWrite(pins[1], LEDs[led][1].PORT);
  digitalWrite(pins[2], LEDs[led][2].PORT);
  led = (led + 1) % 6;
  delay(500);
}
