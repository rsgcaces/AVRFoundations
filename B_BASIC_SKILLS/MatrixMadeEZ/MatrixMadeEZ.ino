// PROJECT  :MatrixMadeEZ
// PURPOSE  :Demo program of the MatrixMadeEZ Device (original design by H. Reed)
// RESULT   :First four rows of the main diagonal should light up as bright as possible
// AUTHOR   :C. D'Arcy
// DATE     :2019 12 03
// uC       :328P
// STATUS   :Working
// REFERENCE:https://cdn-shop.adafruit.com/datasheets/1079datasheet.pdf
#define DMLEVEL 0           //since /G on TPIC:  bright:0, dim:250ish
#define LIMIT 0x08          //adjust for length of diagonal 
uint8_t dimmer = 3;         //PWM (or external voltage divider, eg pot, LDR)
uint8_t data = 11;          //avoid pins 9 and 10 for later use
uint8_t latch = 12;         //of the TimerOne library to control
uint8_t clk = 13;           //frame speed

uint8_t rowData = 0x01;     //let's light the main diagonal
uint8_t colData = rowData;  //equate the row and column coordinates

void setup() {
  pinMode(dimmer, OUTPUT);        //
  pinMode(data, OUTPUT);          //
  pinMode(clk, OUTPUT);           //
  pinMode(latch, OUTPUT);         //
  analogWrite(dimmer, DMLEVEL);   //brightness control on the /G pin of the TPIC
}

void loop() {
  shiftOut(data, clk, LSBFIRST, colData);   //note the shift order
  shiftOut(data, clk, LSBFIRST, rowData);   //and the column data first
  digitalWrite(latch, LOW);                 //create a rising edge on latch pin 
  digitalWrite(latch, HIGH);                //
  //control the length of the diagonal...
  rowData = rowData == LIMIT ? rowData = 0x01 : rowData << 1;
  colData = rowData;
}
