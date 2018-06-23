// PROJECT  :MatrixMadeEZ
// PURPOSE  :Shell sketch for Hugo Reed's (ACES' 18) PCB by the same name
//          :Draws the primary diagonal (top left to bottom right)
// AUTHOR   :C. D'Arcy
// DATE     :2018 06 21
// uC       :328
// STATUS   :Working
// REFERENCE:https://cdn-shop.adafruit.com/datasheets/1079datasheet.pdf
uint8_t dim = 9;          //
uint8_t data = 10;        //
uint8_t clk = 11;         //
uint8_t latch = 12;       //
#define LEVEL 0           //
uint8_t rowData = 0x80;   //
uint8_t colData = rowData;//

void setup() {
  pinMode(data, OUTPUT);  //
  pinMode(clk, OUTPUT);   //
  pinMode(latch, OUTPUT); //
  pinMode(dimmer,OUTPUT); //
  analogWrite(dim,LEVEL); //
}

void loop() {
  digitalWrite(latch, LOW);               //
  shiftOut(data, clk, LSBFIRST, colData); //
  shiftOut(data, clk, LSBFIRST, rowData); //
  digitalWrite(latch, HIGH);              //
  rowData = rowData == 1 ? rowData = 0x80 : rowData >> 1; //
  colData = rowData;                      //
}
