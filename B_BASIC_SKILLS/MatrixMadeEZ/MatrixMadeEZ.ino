// PROJECT  :MatrixMadeEZ
// PURPOSE  :Demo program of the MatrixMadeEZ Device (original design by H. Reed)
// RESULT   :First four rows of the main diagonal should light
// AUTHOR   :C. D'Arcy
// DATE     :2018 09 16
// uC       :328P
// STATUS   :Working
// REFERENCE:https://cdn-shop.adafruit.com/datasheets/1079datasheet.pdf
#define LEVEL 0
uint8_t dimmer = 9;
uint8_t latch = 10;
uint8_t clk = 11;
uint8_t data = 12;
uint8_t colData = 0x80;
uint8_t rowData = 0x80;

void setup() {
  Serial.begin(9600);
  pinMode(dimmer,OUTPUT);
  pinMode(data, OUTPUT);
  pinMode(clk, OUTPUT);
  pinMode(latch, OUTPUT);
  analogWrite(dimmer,LEVEL);

}

void loop() {
  digitalWrite(latch, LOW);
  shiftOut(data, clk, MSBFIRST, colData);
  shiftOut(data, clk, MSBFIRST, rowData);
  digitalWrite(latch, HIGH);
  rowData = rowData == 0x08 ? rowData = 0x80 : rowData >> 1;
  colData = rowData;
}
