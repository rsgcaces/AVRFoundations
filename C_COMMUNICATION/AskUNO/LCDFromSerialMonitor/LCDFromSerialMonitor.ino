// PROJECT  :LCDFromSerialMonitor
// PURPOSE  :Stage 1 of the 2020/2021 TEI3M Ask UNO project
// DEVICE   :Arduino + (Adafruit 1447) LCD Appliance + Potentiometer
// AUTHOR   :C. D'Arcy
// DATE     :2020 10 29
// uC       :*
// COURSE   :ICS3U
// STATUS   :To be developed in class
// REFERENCE:https://www.arduino.cc/en/Reference/LiquidCrystal
// REFERENCE:https://www.adafruit.com/product/1447 
#include <LiquidCrystal.h>        //LCD Library...
#define LCD_COLUMNS 16            //Number of columns in Character LCD screen
#define LCD_ROWS    2             //Number of rows on LCD screen
//Pin assignments below are LCD Appliance-compatible
//Control and Data lines are restricted to PORTD
//This is the regular/standard one...
uint8_t RS = 7, EN = 6, D4 = 5, D5 = 4, D6 = 3, D7 = 2;
LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);

void setup() {
  lcd.begin(LCD_COLUMNS, LCD_ROWS); //initialize LCD screen
  lcd.clear();                      //erase the LCD screen
  lcd.setCursor(0, 0);              //position display cursor at home
  lcd.print("NANO: Enter text");    //provide an instruction on the first line
  Serial.begin(9600);
  while (!Serial);
}

void loop() {}
